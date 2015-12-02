/*
 * @file i2c.cpp
 *
 *  Created on: 27 Nov 2015
 *      Author: podonoghue
 */
#include "i2c.h"

using namespace USBDM;

#if defined(I2C0)
#if !defined(I2C0_SCL_GPIO) || !defined(I2C0_SDA_GPIO)
#warning "I2C0 unavailable - Please check pin mapping for I2C0_SCL and I2C0_SDA"
#else

template<> I2c *I2c0::thisPtr = 0;

/*
 * I2C state-machine based interrupt handler
 */
extern "C"
void I2C0_IRQHandler() {
   I2c0::thisPtr->poll();
}
#endif
#endif

#if defined(I2C1)
#if !defined(I2C1_SCL_GPIO) || !defined(I2C1_SDA_GPIO)
#warning "I2C1 unavailable - Please check pin mapping for I2C1_SCL and I2C1_SDA"
#else

template<> I2c *I2c1::thisPtr = 0;

/*
 * I2C state-machine based interrupt handler
 */
extern "C"
void I2C1_IRQHandler() {
   I2c1::thisPtr->poll();
}
#endif
#endif

#if defined(I2C2)
#if !defined(I2C2_SCL_GPIO) || !defined(I2C2_SDA_GPIO)
#warning "I2C2 unavailable - Please check pin mapping for I2C2_SCL and I2C2_SDA"
#else

template<> I2c *I2c2::thisPtr = 0;

/*
 * I2C state-machine based interrupt handler
 */
extern "C"
void I2C2_IRQHandler() {
   I2c2::thisPtr->poll();
}
#endif
#endif

// I2C baud rate divisor table
const uint16_t I2c::I2C_DIVISORS[] = {
// Divider assuming MULT == 0
   20,   22,  24,   26,   28,   30,   34,   40,   28,   32,   36,   40,   44,   48,   56,   68,
   48,   56,  64,   72,   80,   88,  104,  128,   80,   96,  112,  128,  144,  160,  192,  240,
   160, 192, 224,  256,  288,  320,  384,  480,  320,  384,  448,  512,  576,  640,  768,  960,
   640, 768, 896, 1024, 1152, 1280, 1536, 1920, 1280, 1536, 1792, 2048, 2304, 2560, 3072, 3840,
};

/**
 * Set baud factor value for interface
 * This is calculated from processor bus frequency and given bps
 *
 * @param bps - Interface speed in bits-per-second
*/
uint8_t I2c::getBPSValue(uint32_t bps) {
   uint8_t  best_mul   = 0;
   uint8_t  best_icr   = (uint8_t)-1u;
   uint16_t best_error = (uint16_t)-1u;

#if defined(MCU_MKL27Z4) || defined(MCU_MKL27Z644)
   const uint32_t I2C_CLOCK_FREQ = SystemCoreClock;
#else
   const uint32_t I2C_CLOCK_FREQ = SystemBusClock;
#endif

   for (uint8_t mul=0; mul<=2; mul++) {
      uint32_t divisor = (I2C_CLOCK_FREQ>>mul)/bps;
      for(uint8_t icr=0; icr<(sizeof(I2C_DIVISORS)/sizeof(I2C_DIVISORS[0])); icr++) {
         if (divisor>I2C_DIVISORS[icr]) {
            // Not suitable - try next
            continue;
         }
         uint16_t error=(uint16_t)(I2C_DIVISORS[icr]-divisor);
         if ((error<best_error) || (error==0)) {
            best_error=error;
            best_icr=icr;
            best_mul=mul;
         }
      }
   }
   if (best_icr == (uint8_t)-1u) {
      return I2C_F_MULT(1)|I2C_F_ICR(5);
   }
   else {
      return I2C_F_MULT(best_mul)|I2C_F_ICR(best_icr);
   }
}

/**
 * Start Rx/Tx sequence by sending address byte
 *
 * @param address - address of slave to access
 */
void I2c::sendAddress(uint8_t address) {
   // Wait for bus idle
   while ((i2c->S & I2C_S_BUSY_MASK) != 0) {
      __asm("nop");
   }

   addressedDevice = address;

   // Configure for Tx of address
   i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_TX_MASK;

   // Generate START
   i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_TX_MASK|I2C_C1_MST_MASK;

   // Tx address (starts interrupt process)
   i2c->D  = I2C_D_DATA(address);
}

/**
 * I2C state-machine based interrupt handler
 */
void I2c::poll(void) {

   if ((i2c->S & I2C_S_ARBL_MASK) != 0) {
      i2c->S = I2C_S_ARBL_MASK|I2C_S_IICIF_MASK;
      errorCode = 1;
      state = i2c_idle;
      return;
   }
   if ((i2c->S & I2C_S_IICIF_MASK) == 0) {
      return;
   }
   // Clear interrupt flag
   i2c->S = I2C_S_IICIF_MASK;

   // i2c_txData* +-> i2c_idle
   //             +-> i2c_rxAddress -> i2c_rxData* +-> i2c_idle
   //                                              *-> i2c_txData

   switch (state) {
      case i2c_idle:
      default:
         state = i2c_idle;
         break;

      case i2c_txData:
         // Just send data bytes until none left
         if (txBytesRemaining-- == 0) {
            if (rxBytesRemaining > 0) {
               // Reception after transmission
               state = i2c_rxAddress;

#if defined(MCU_MKL25Z4)
               {
                  // Temporarily clear MULT - see KL25 errata e6070
                  uint8_t temp = i2c->F;
                  i2c->F&=~I2C_F_MULT(3);
#endif
                  // Generate REPEATED-START
                  i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_MST_MASK|I2C_C1_TX_MASK|I2C_C1_RSTA_MASK;
#if defined(MCU_MKL25Z4)
                  // Restore MULT
                  i2c->F = temp;
               }
#endif
#if defined(MCU_MKL27Z4) || defined(MCU_MKL27Z644) || defined(MCU_MKL43Z4)
               // This is a nasty hack
               // It seems these chips need a delay after asserting repeated start
               for (int i=0; i<20; i++) {
                  __asm__ volatile("nop");
               }
#endif
               // Send device address again with READ bit set
               i2c->D = addressedDevice|1;
            }
            else {
               // Complete
               state = i2c_idle;

               // Generate stop signal
               i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_TXAK_MASK;
               return;
            }
         }
         else {
            // Transmit next byte
            i2c->D = *txDataPtr++;
         }
         break;

      case i2c_rxAddress:
         // Just sent address for reception phase
         // Switch to data reception & trigger reception
         state = i2c_rxData;
         // Change to reception
         if (rxBytesRemaining == 1) {
            // Receiving only single byte (don't acknowledge the byte)
            i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_MST_MASK|I2C_C1_TXAK_MASK;
         }
         else {
            // Switch to Rx mode
            i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_MST_MASK;
         }
         // Dummy read of data to start Rx of 1st data byte
         (void)i2c->D;
         break;

      case i2c_rxData:
         // Just receive data bytes until complete
         if (--rxBytesRemaining == 0) {
            // Received last byte - complete
            state = i2c_idle;
            // Generate STOP
            i2c->C1 = mode|I2C_C1_IICEN_MASK;
         }
         else if (rxBytesRemaining == 1) {
            // Received 2nd last byte (don't acknowledge the last byte to follow)
            i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_MST_MASK|I2C_C1_TXAK_MASK;
         }
         else {
            i2c->C1 = mode|I2C_C1_IICEN_MASK|I2C_C1_MST_MASK;
         }
         // Save receive data
         *rxDataPtr++ = i2c->D;
         break;
   }
}

/**
 * Transmit message
 *
 * @param address  Address of slave to communicate with
 * @param data     Data to transmit, 0th byte is often register address
 * @param size     Size of transmission data
 */
int I2c::transmit(uint8_t address, const uint8_t data[], uint16_t size) {
   errorCode = 0;

   rxBytesRemaining = 0;

   // Send address byte at start and move to data transmission
   state = i2c_txData;

   // Set up transmit data
   txDataPtr        = data;
   txBytesRemaining = size;

   sendAddress(address);
   waitWhileBusy();

   return errorCode;
}

/**
 * Receive message
 *
 * @param address  Address of slave to communicate with
 * @param data     Data buffer for reception
 * @param size     Size of reception data
 */
int I2c::receive(uint8_t address,  uint8_t data[], uint16_t size) {
   errorCode = 0;

   txBytesRemaining = 0;

   // Send address byte at start and move to data reception
   state = i2c_rxAddress;

   // Set up receive data
   rxDataPtr        = data;
   rxBytesRemaining = size;

   sendAddress(address|1);
   waitWhileBusy();

   return errorCode;
}

/**
 * Transmit message followed by receive message.
 * Uses repeated-start.
 *
 * @param address  Address of slave to communicate with
 * @param txData   Data for transmission
 * @param txSize   Size of transmission data
 * @param rxData   Date buffer for reception
 * @param rxSize   Size of reception data
 */
int I2c::txRx(uint8_t address, const uint8_t txData[], uint16_t txSize, uint8_t rxData[], uint16_t rxSize ) {
   errorCode = 0;

   // Send address byte at start and move to data transmission
   state = i2c_txData;

   // Set up transmit and receive data
   rxDataPtr        = rxData;
   rxBytesRemaining = rxSize;
   txDataPtr        = txData;
   txBytesRemaining = txSize;

   sendAddress(address);
   waitWhileBusy();
   return errorCode;
}

/**
 * Transmit message followed by receive message.
 * Uses repeated-start.
 * Uses shared transmit and receive buffer
 *
 * @param address  Address of slave to communicate with
 * @param data     Data for transmission and reception
 * @param txSize   Size of transmission data
 * @param rxSize   Size of reception data
 */
int I2c::txRx(uint8_t address, uint8_t data[], uint16_t txSize, uint16_t rxSize ) {
   return txRx(address, data, txSize, data, rxSize);
}

