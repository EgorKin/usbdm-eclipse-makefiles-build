/**
 * @file     spi.h (180.ARM_Peripherals/Project_Headers/spi-MKL.h)
 * @brief    Serial Peripheral Interface
 *
 * @version  V4.12.1.210
 * @date     13 April 2016
 *      Author: podonoghue
 */

#ifndef INCLUDE_USBDM_SPI_H_
#define INCLUDE_USBDM_SPI_H_
/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include <stdint.h>
#include "derivative.h"
#include "hardware.h"
#ifdef __CMSIS_RTOS
#include "cmsis.h"
#endif

namespace USBDM {

/**
 * @addtogroup SPI_Group SPI, Serial Peripheral Interface
 * @brief C++ Class allowing access to SPI interface
 * @{
 */

/**
 * Type definition for completion call back
 *
 * @param status E_NOERROR on success else error code
 */
typedef void (*SpiCallbackFunction)(ErrorCode status);

/**
 * SPI mode - Controls clock polarity and the timing relationship between clock and data
 */
enum SpiMode {
   SpiMode_0 = SPI_C1_CPOL(0)|SPI_C1_CPHA(0), //!< Active-high clock (idles low), Data is captured on leading edge of SCK and changes on the following edge.
   SpiMode_1 = SPI_C1_CPOL(0)|SPI_C1_CPHA(1), //!< Active-high clock (idles low), Data is changes on leading edge of SCK and captured on the following edge.
   SpiMode_2 = SPI_C1_CPOL(1)|SPI_C1_CPHA(0), //!< Active-low clock (idles high), Data is captured on leading edge of SCK and changes on the following edge.
   SpiMode_3 = SPI_C1_CPOL(1)|SPI_C1_CPHA(1), //!< Active-low clock (idles high), Data is changes on leading edge of SCK and captured on the following edge.
};

/**
 * Bit transmission order (LSB/MSB first)
 */
enum SpiOrder {
   SpiOrder_MsbFirst = SPI_C1_LSBFE(0), //!< MSB First
   SpiOrder_LsbFirst = SPI_C1_LSBFE(1), //!< LSB First
};

/**
 * Note on MODFEN/SSOE use
 *  SSOE  MODFEN     MASTER      SLAVE
 *   0     0         GPIO        SS-in
 *   0     1         FAULT-in    SS-in
 *   1     0         GPIO        SS-in
 *   1     1         SS-out      SS-in
 */

/**
 * Slave Select pin function in master mode
 */
enum SpiPinSelect {
   SpiPinSelect_Disabled    = SPI_C1_SSOE(0)|SPI_C2_MODFEN(0),  //!< SS pin acts as GPIO when Master
   SpiPinSelect_FaultIn     = SPI_C1_SSOE(0)|SPI_C2_MODFEN(1),  //!< SS pin acts as FAULT in when Master
   SpiPinSelect_SlaveSelect = SPI_C1_SSOE(1)|SPI_C2_MODFEN(1),  //!< SS pin acts as SlaveSelect when Master
};

/**
 * Controls operation in Low Power mode
 */
enum SpiLowPower {
   SpiLowPower_Disabled = SPI_C2_SPISWAI(0), //!< SPI disabled in Low Power mode
   SpiLowPower_Enabled  = SPI_C2_SPISWAI(1), //!< SPI enabled in Low Power mode
};

/**
 * Used to hold SPI configuration that may commonly be modified for different target peripherals
 */
struct SpiConfig {
   SpiCallbackFunction callback; //!< Callback on error or completion
   uint8_t             br;       //!< Baud rate dividers
   uint8_t             c1;       //!< CPOL, CPHA, SSOE, LSBFE
   uint8_t             c2;       //!< BIDIROE, SPC0
};

/**
 * @brief Base class for representing an SPI interface
 */
class Spi {

protected:
   volatile  SPI_Type * const spi; //!< SPI hardware

   /** Callback function for ISR */
   SpiCallbackFunction callback;

   volatile uint32_t bytesRemaining;
            uint8_t  *rxDataPtr;
   const    uint8_t  *txDataPtr;

   /** Callback for unhandled interrupt */
   static void unhandledCallback(ErrorCode) {
   }

   /**
    * Constructor
    *
    * @param[in]  baseAddress    Base address of SPI
    */
   constexpr Spi(volatile SPI_Type *baseAddress) :
      spi(baseAddress), callback(unhandledCallback), bytesRemaining(0), rxDataPtr(nullptr), txDataPtr(nullptr) {
   }

   /**
    * Destructor
    */
   virtual ~Spi() {
   }

   /**
    * Get SPI input clock frequency
    *
    * @return Clock frequency in Hz
    */
   virtual uint32_t getClockFrequency() = 0;

   /**
    * Calculate communication BR value for SPI
    *
    * @param[in]  clockFrequency => Clock frequency of SPI in Hz
    * @param[in]  frequency      => Communication frequency in Hz
    *
    * @return BR register value
    *
    * Note: Chooses the highest speed that is not greater than frequency.
    */
   static uint8_t calculateBr(uint32_t clockFrequency, uint32_t frequency);

   /**
    * Calculates speed from SPI clock frequency and SPI clock factors
    *
    * @param[in] clockFrequency   SPI input clock frequency
    * @param[in] clockFactors     SPI clock factors
    *
    * @return SPI frequency
    */
   static uint32_t calculateSpeed(uint32_t clockFrequency, uint32_t clockFactors);

#if defined(__CMSIS_RTOS)
   /**
    * Obtain SPI mutex
    *
    * @param[in]  milliseconds   How long to wait in milliseconds. Use osWaitForever for indefinite wait
    *
    * @return osOK: The mutex has been obtain.
    * @return osErrorTimeoutResource: The mutex could not be obtained in the given time.
    * @return osErrorResource: The mutex could not be obtained when no timeout was specified.
    * @return osErrorParameter: The parameter mutex_id is incorrect.
    * @return osErrorISR: osMutexWait cannot be called from interrupt service routines.
    */
   virtual osStatus getMutex(int milliseconds=osWaitForever) = 0;

   /**
    * Release SPI mutex
    *
    * @return osOK: the mutex has been correctly released.
    * @return osErrorResource: the mutex was not obtained before.
    * @return osErrorISR: osMutexRelease cannot be called from interrupt service routines.
    */
   virtual osStatus releaseMutex() = 0;
#endif

   /**
    * Send 1st byte in a transmission
    */
   void sendFirstByte() {
      // Dummy status read
      (void)spi->S;
      if (bytesRemaining>0) {
         // Transmit byte
         if (txDataPtr != nullptr) {
            spi->D = *txDataPtr++;
         }
         else {
            spi->D = 0xFF;
         }
      }
   }

   /**
    * Stop transmission
    */
   void stopTransaction() {
      spi->C1 &= ~SPI_C1_SPIE(1);
      rxDataPtr = nullptr;
      txDataPtr = nullptr;
   }

   /**
    * class private IRQ handler\n
    * Handles receiving/transmitting a value
    */
   void _irqHandler() {
      if (spi->S&SPI_S_MODF_MASK) {
         stopTransaction();
         callback(E_LOST_ARBITRATION);
         return;
      }
      // Receive byte
      if (rxDataPtr != nullptr) {
         *rxDataPtr++ = spi->D;
      }
      else {
         (void)spi->D;
      }
      bytesRemaining--;
      if (bytesRemaining>0) {
         // Transmit byte
         if (txDataPtr != nullptr) {
            spi->D = *txDataPtr++;
         }
         else {
            spi->D = 0xFF;
         }
      }
      else {
         stopTransaction();
         callback(E_NO_ERROR);
         return;
      }
   }

public:

#if defined(__CMSIS_RTOS)
   /**
    * Obtain SPI mutex and set SPI configuration
    *
    * @param[in]  configuration  The configuration to set for the transaction
    * @param[in]  milliseconds   How long to wait in milliseconds. Use osWaitForever for indefinite wait
    *
    * @return osOK: The mutex has been obtain.
    * @return osErrorTimeoutResource: The mutex could not be obtained in the given time.
    * @return osErrorResource: The mutex could not be obtained when no timeout was specified.
    * @return osErrorParameter: The parameter mutex_id is incorrect.
    * @return osErrorISR: osMutexWait cannot be called from interrupt service routines.
    */
   osStatus startTransaction(SpiConfig &configuration, int milliseconds=osWaitForever) {
      // Obtain mutex
      osStatus status = getMutex(milliseconds);
      if (status == osOK) {
         // Change configuration for this transaction
         setConfiguration(configuration);
      }
      return status;
   }

   /**
    * Obtain SPI mutex (SPI configuration unchanged)
    *
    * @param[in]  milliseconds How long to wait in milliseconds. Use osWaitForever for indefinite wait
    *
    * @return osOK: The mutex has been obtain.
    * @return osErrorTimeoutResource: The mutex could not be obtained in the given time.
    * @return osErrorResource: The mutex could not be obtained when no timeout was specified.
    * @return osErrorParameter: The parameter mutex_id is incorrect.
    * @return osErrorISR: osMutexWait cannot be called from interrupt service routines.
    */
   osStatus startTransaction(int milliseconds=osWaitForever) {
      // Obtain mutex
      return getMutex(milliseconds);
   }

   /**
    * Release SPI mutex
    *
    * @return osOK: the mutex has been correctly released.
    * @return osErrorResource: the mutex was not obtained before.
    * @return osErrorISR: osMutexRelease cannot be called from interrupt service routines.
    */
   osStatus endTransaction() {
      // Release mutex
      return releaseMutex();
   }
#else
   /**
    * Obtain SPI and set SPI configuration
    *
    * @param[in] configuration The configuration values to set for the transaction.
    */
   int startTransaction(SpiConfig &configuration, int =0) {
      setConfiguration(configuration);
      return 0;
   }
   /**
    * Obtain SPI
    */
   int startTransaction(int =0) {
      return 0;
   }
   /**
    * Release SPI - dummy routine (non RTOS)
    */
   int endTransaction() {
      return 0;
   }
#endif

   /**
    * Enable pins used by SPI
    */
   virtual void enablePins(bool enable=true) = 0;

   /**
    * Sets Communication speed for SPI
    *
    * @param[in]  frequency      => Communication frequency in Hz
    *
    * Note: Chooses the highest speed that is not greater than frequency.
    */
   void setSpeed(uint32_t frequency) {
      spi->BR = calculateBr(getClockFrequency(), frequency);
   }

   /**
    * Get communication speed of SPI
    *
    * @return Frequency in Hz
    */
   uint32_t getSpeed() {
      return calculateSpeed(getClockFrequency(), spi->BR);
   }

   /**
    * Sets Communication mode for SPI
    *
    * @param[in] spiMode   Controls clock polarity and the timing relationship between clock and data
    * @param[in] spiOrder  Bit transmission order (LSB/MSB first)
    */
   void setMode(SpiMode spiMode=SpiMode_0, SpiOrder spiOrder=SpiOrder_MsbFirst) {
      // Note: always master mode
      spi->C1 =
         (spiMode|spiOrder)|
         (spi->C1&~(SPI_C1_MODE_MASK|SPI_C1_LSBFE_MASK))|
         SPI_C1_SSOE_MASK|SPI_C1_SPE_MASK|SPI_C1_MSTR_MASK;
   }

   /**
    *  Set Configuration\n
    *  This includes timing settings, word length and transmit order\n
    *  Assumes the interface is already acquired through startTransaction
    *
    *  @note The SPI is left disabled.
    *
    * @param[in]  configuration Configuration value
    */
   void setConfiguration(const SpiConfig &configuration) {
      callback = configuration.callback;
      spi->C1  = configuration.c1|SPI_C1_SPE_MASK;
      spi->C2  = configuration.c2;
      spi->BR  = configuration.br;
   }

   /**
    *  Get SPI configuration\n
    *  This includes timing settings, word length and transmit order
    *
    * @return Configuration value
    *
    * @note Typically used with startTransaction()
    */
   SpiConfig getConfiguration() {
      return SpiConfig{callback, spi->BR, spi->C1, spi->C2};
   }

   /**
    *  Set SS Pin function
    *
    *  @param spiPinSelect Slave Select pin function in master mode
    */
   void setSlaveSelect(SpiPinSelect spiPinSelect) {
      spi->C1 = (spi->C1&~SPI_C1_SSOE_MASK)  |(spiPinSelect&SPI_C1_SSOE_MASK);
      spi->C2 = (spi->C2&~SPI_C2_MODFEN_MASK)|(spiPinSelect&SPI_C2_MODFEN_MASK);
   }

   /**
    * Controls operation in Low Power mode
    *
    * @param spiLowPower Options for low power mode
    */
   void setLowPowerMode(SpiLowPower spiLowPower) {
      spi->C2 = (spi->C2&~SPI_C2_SPISWAI_MASK)|(spiLowPower&SPI_C2_SPISWAI_MASK);
   }

   /**
    * Gets and clears status flags.
    *
    * @return status valkue (SPI->SR)
    */
   uint32_t getStatus() {
      // Capture interrupt status
      uint32_t status = spi->S;
      // Clear captured flags
      spi->S = status;
      // Return status
      return status;
   }

   /**
    *  Transmit and receive a series of bytes
    *
    *  @param[in]  dataSize  Number of values to transfer
    *  @param[in]  txData    Transmit bytes (may be nullptr for Receive only)
    *  @param[out] rxData    Receive byte buffer (may be nullptr for Transmit only)
    *
    *  @note: rxData may use same buffer as txData
    *  @note: Size of txData and rxData should be appropriate for transmission size.
    */
   void txRx(uint32_t dataSize, const uint8_t *txData, uint8_t *rxData=nullptr) {
//      assert((txData != nullptr)||(rxData != nullptr));

      bytesRemaining = dataSize;
      txDataPtr      = txData;
      rxDataPtr      = rxData;
      spi->C1 |=  SPI_C1_SPE_MASK|SPI_C1_SPIE_MASK;
      sendFirstByte();
      if (callback == unhandledCallback) {
         // If call-back not set then wait for completion
         while (bytesRemaining != 0) {
            __asm__("nop");
         }
      }
   }

   /**
    * Transmit and receive a value over SPI
    *
    * @param[in] data - Data to send (8/16 bits)
    *
    * @return Data received
    */
   uint32_t txRx(uint32_t data) {
      while ((spi->S & SPI_S_SPTEF_MASK)==0) {
         __asm__("nop");
      }
      spi->D  = data;
      while ((spi->S & SPI_S_SPRF_MASK)==0) {
         __asm__("nop");
      }
      return spi->D; // Return read data
   }

   /**
    * Set Callback function\n
    *
    * @param[in] theCallback Callback function to execute on completion.\n
    *                        nullptr to indicate none (SPI operations will be blocking)
    */
   __attribute__((always_inline)) void setCallback(SpiCallbackFunction theCallback) {
      if (theCallback == nullptr) {
         callback = unhandledCallback;
         return;
      }
      callback = theCallback;
   }

};

/**
 * @brief Template class representing a SPI interface
 *
 * @tparam  Info  Class describing SPI hardware
 */
template<class Info>
class SpiBase_T : public Spi {

private:
   static SpiBase_T<Info> *thisPtr;
#ifdef __CMSIS_RTOS
   static CMSIS::Mutex mutex;
#endif

public:

   /**
    * IRQ handler
    */
   static void irqHandler() {
      thisPtr->_irqHandler();
   }

#ifdef __CMSIS_RTOS
protected:
   /**
    * Obtain SPI mutex
    *
    * @param[in]  milliseconds   How long to wait in milliseconds. Use osWaitForever for indefinite wait
    *
    * @return osOK: The mutex has been obtain.
    * @return osErrorTimeoutResource: The mutex could not be obtained in the given time.
    * @return osErrorResource: The mutex could not be obtained when no timeout was specified.
    * @return osErrorParameter: The parameter mutex_id is incorrect.
    * @return osErrorISR: osMutexWait cannot be called from interrupt service routines.
    */
   virtual osStatus getMutex(int milliseconds=osWaitForever) override {
      return mutex.wait(milliseconds);
   }

   /**
    * Release SPI mutex
    *
    * @return osOK: the mutex has been correctly released.
    * @return osErrorResource: the mutex was not obtained before.
    * @return osErrorISR: osMutexRelease cannot be called from interrupt service routines.
    */
   virtual osStatus releaseMutex() override {
      return mutex.release();
   }
#endif

   /**
    * Get SPI input clock frequency
    *
    * @return Clock frequency in Hz
    */
   uint32_t getClockFrequency() override {
      return Info::getClockFrequency();
   }

public:
   // SPI SCK (clock) Pin
   using sckGpio  = GpioTable_T<Info, 0, ActiveHigh>;

   // SPI SIN (data in = usually MISO) Pin
   using sinGpio  = GpioTable_T<Info, 1, ActiveHigh>;

   // SPI SOUT (data out = usually MOSI) Pin
   using soutGpio = GpioTable_T<Info, 2, ActiveHigh>;

   /**
    * Configures all mapped pins associated with this peripheral
    */
   static void __attribute__((always_inline)) configureAllPins() {
      // Configure pins
      Info::initPCRs();
   }

   /**
    * Map/Unmap pins for peripheral
    *
    * @param enable
    */
   virtual void enablePins(bool enable) override {
      if (enable) {
         // Configure pins
         Info::initPCRs();
      }
      else {
         // Configure SPI pins to mux=0
         Info::clearPCRs();
      }
   }

   /**
    * Constructor
    */
   SpiBase_T() : Spi(reinterpret_cast<volatile SPI_Type*>(&Info::spi())) {

#ifdef DEBUG_BUILD
      // Check pin assignments
      static_assert(Info::info[0].gpioBit != UNMAPPED_PCR, "SPIx_SCK has not been assigned to a pin - change in Configure.usbdmProject");
      static_assert(Info::info[1].gpioBit != UNMAPPED_PCR, "SPIx_SIN has not been assigned to a pin - change in Configure.usbdmProject");
      static_assert(Info::info[2].gpioBit != UNMAPPED_PCR, "SPIx_SOUT has not been assigned to a pin - change in Configure.usbdmProject");

      // Requires interrupt handler
      static_assert(Info::irqHandlerInstalled, "IRQ handler must be enabled for SPI - change in Configure.usbdmProject");
#endif

      if (Info::mapPinsOnEnable) {
         configureAllPins();
      }

      // Enable SPI module clock
      Info::clockReg() |= Info::clockMask;
      __DMB();

      spi->C1 =
            Info::modeValue| // Use default LSBFE, MODE
            SPI_C1_MSTR(1)|
            SPI_C1_SPIE(0)|
            SPI_C1_SPE(0)|
            SPI_C1_SPTIE(0)|
            SPI_C1_SSOE(0);

      setSpeed(Info::speed); // Use default speed

      // Record this pointer for IRQ handler
      thisPtr = this;

      // Enable and configure interrupts
      enableNvicInterrupts();
   }

   /**
    * Destructor
    */
   ~SpiBase_T() override {
   }

   /**
    * Enable interrupts in NVIC
    * Any pending NVIC interrupts are first cleared.
    */
   static void enableNvicInterrupts() {
      enableNvicInterrupt(Info::irqNums[0]);
   }

   /**
    * Enable and set priority of interrupts in NVIC
    * Any pending NVIC interrupts are first cleared.
    *
    * @param[in]  nvicPriority  Interrupt priority
    */
   static void enableNvicInterrupts(uint32_t nvicPriority) {
      enableNvicInterrupt(Info::irqNums[0], nvicPriority);
   }

   /**
    * Disable interrupts in NVIC
    */
   static void disableNvicInterrupts() {
      NVIC_DisableIRQ(Info::irqNums[0]);
   }

};

template<class Info> SpiBase_T<Info> *SpiBase_T<Info>::thisPtr = nullptr;
#ifdef __CMSIS_RTOS
template<class Info> CMSIS::Mutex     SpiBase_T<Info>::mutex;
#endif

#if defined(USBDM_SPI0_IS_DEFINED)
/**
 * @brief Template class representing a SPI0 interface
 *
 * <b>Example</b>
 * @code
 * USBDM::Spi *spi = new USBDM::Spi0();
 *
 * uint8_t txData[] = {1,2,3};
 * uint8_t rxData[10];
 * spi->txRxBytes(sizeof(txData), txData, rxData);
 * @endcode
 *
 */
using Spi0 = SpiBase_T<Spi0Info>;
#endif

#if defined(USBDM_SPI1_IS_DEFINED)
/**
 * @brief Template class representing a SPI1 interface
 *
 * <b>Example</b>
 * @code
 * USBDM::Spi *spi = new USBDM::Spi1();
 *
 * uint8_t txData[] = {1,2,3};
 * uint8_t rxData[10];
 * spi->txRxBytes(sizeof(txData), txData, rxData);
 * @endcode
 *
 */
using Spi1 = SpiBase_T<Spi1Info>;

#endif
/**
 * End SPI_Group
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_USBDM_SPI_H_ */
