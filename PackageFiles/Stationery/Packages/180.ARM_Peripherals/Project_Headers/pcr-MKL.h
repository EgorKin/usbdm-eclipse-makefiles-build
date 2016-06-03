/**
 * @file     pcr.h (from pcr-MKL.h)
 * @brief    Port Control Register interface
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */
#ifndef HEADER_PCR_H
#define HEADER_PCR_H
 /*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include <stddef.h>
#include <assert.h>
#include "derivative.h"
#include "bme.h"

/*
 * Default port information
 */
#ifndef FIXED_PORT_CLOCK_REG
#define FIXED_PORT_CLOCK_REG SCGC5
#endif

#ifndef FIXED_GPIO_FN
#define FIXED_GPIO_FN   (1)
#endif

#ifndef FIXED_ADC_FN
#define FIXED_ADC_FN    (0)
#endif

#ifndef PORTA_CLOCK_MASK
#ifdef SIM_SCGC5_PORTA_MASK
#define PORTA_CLOCK_MASK  SIM_SCGC5_PORTA_MASK
#define PORTA_CLOCK_REG   SCGC5
#endif
#ifdef SIM_SCGC5_PORTB_MASK
#define PORTB_CLOCK_MASK  SIM_SCGC5_PORTB_MASK
#define PORTB_CLOCK_REG   SCGC5
#endif
#ifdef SIM_SCGC5_PORTC_MASK
#define PORTC_CLOCK_MASK  SIM_SCGC5_PORTC_MASK
#define PORTC_CLOCK_REG   SCGC5
#endif
#ifdef SIM_SCGC5_PORTD_MASK
#define PORTD_CLOCK_MASK  SIM_SCGC5_PORTD_MASK
#define PORTD_CLOCK_REG   SCGC5
#endif
#ifdef SIM_SCGC5_PORTE_MASK
#define PORTE_CLOCK_MASK  SIM_SCGC5_PORTE_MASK
#define PORTE_CLOCK_REG   SCGC5
#endif
#ifdef SIM_SCGC5_PORTF_MASK
#define PORTF_CLOCK_MASK  SIM_SCGC5_PORTF_MASK
#define PORTF_CLOCK_REG   SCGC5
#endif
#endif

namespace USBDM {

extern volatile uint32_t SystemMcgirClock;
extern volatile uint32_t SystemMcgffClock;
extern volatile uint32_t SystemMcgFllClock;
extern volatile uint32_t SystemMcgPllClock;
extern volatile uint32_t SystemMcgOutClock;
extern volatile uint32_t SystemCoreClock;
extern volatile uint32_t SystemBusClock;
extern volatile uint32_t SystemPeripheralClock;
extern volatile uint32_t SystemOscerClock;
extern volatile uint32_t SystemErclk32kClock;
extern volatile uint32_t SystemLpoClock;
extern volatile uint32_t SystemRtcClock;

/**
 * @addtogroup PeripheralPinTables Peripheral Information Classes
 * @brief Provides information about pins used by a peripheral
 * @{
 */

/** Indicates the function has a fixed mapping to a pin */
constexpr   int8_t FIXED_NO_PCR         = 0x00;

/** Indicates the function doesn't exist */
constexpr   int8_t INVALID_PCR          = 0xA5;

/** Indicates the function is not currently mapped to a pin */
constexpr   int8_t UNMAPPED_PCR         = 0xA4;

/**
 * Struct for Pin Control Register information\n
 * Information required to configure the PCR for a particular function
 */
struct PcrInfo {
   uint32_t clockMask;   //!< Clock mask for PORT
   uint32_t pcrAddress;  //!< PCR register array address
   uint32_t gpioAddress; //!< Address of GPIO hardware associated with pin
   int8_t   gpioBit;     //!< Bit number of pin in GPIO
   uint32_t pcrValue;    //!< PCR value including MUX value to select this function
};

/**
 * Default PCR setting for pins (excluding multiplexor value)
 * High drive strength + Pull-up
 */
static constexpr uint32_t    DEFAULT_PCR      = (PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
/**
 * Default PCR value for pins used as GPIO (including multiplexor value)
 */
static constexpr uint32_t    GPIO_DEFAULT_PCR = DEFAULT_PCR|PORT_PCR_MUX(FIXED_GPIO_FN);

#ifndef PORT_PCR_ODE_MASK
/**
 * Some devices don't have ODE function on pin
 * The open-drain mode is automatically selected when I2C function is selected for the pin
 */
#define PORT_PCR_ODE_MASK 0
#endif
/**
 * Default PCR setting for I2C pins (excluding multiplexor value)
 * High drive strength + Pull-up + Open-drain (if available)
 */
static constexpr uint32_t  I2C_DEFAULT_PCR = DEFAULT_PCR|PORT_PCR_ODE_MASK;

/**
 * @brief Template representing a Pin Control Register (PCR)
 *
 * Code examples:
 * @code
 * // Create PCR type
 * Pcr_T<PORTC_CLOCK_MASK, PORTC_BasePtr, 3> PortC_3;
 *
 * // Configure PCR
 * PortC_3.setPCR(PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK|PORT_PCR_MUX(3));
 *
 * // Disable clock to associated PORT
 * pcr.disableClock();
 *
 * // Alternatively the PCR may be manipulated directly
 * Pcr_T<PORTC_CLOCK_MASK, PORTC_BasePtr, 3>.setPCR(PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK|PORT_PCR_MUX(3));
 * @endcode
 *
 * @tparam clockMask       Mask for SIM clock register associated with this PCR
 * @tparam pcrAddress      PORT to be manipulated e.g. PORTA (PCR array)
 * @tparam bitNum          Bit number e.g. 3
 * @tparam defPcrValue     Default value for PCR (including MUX value)
 */
template<uint32_t clockMask, uint32_t pcrAddress, int32_t bitNum, uint32_t defPcrValue>
class Pcr_T {

private:

#ifdef DEBUG_BUILD
   static_assert((bitNum != UNMAPPED_PCR), "Pcr_T: Signal is not mapped to a pin - Modify Configure.usbdm");
   static_assert((bitNum != INVALID_PCR),  "Pcr_T: Non-existent signal");
   static_assert((bitNum == UNMAPPED_PCR)||(bitNum == INVALID_PCR)||(bitNum >= 0), "Pcr_T: Illegal bit number");
#endif

public:
   /**
    * Set pin PCR value\n
    * The clock to the port will be enabled before changing the PCR
    *
    * @param pcrValue PCR value made up of PORT_PCR_x masks including MUX value
    */
   static void setPCR(uint32_t pcrValue=defPcrValue) {
      if ((pcrAddress != 0) && (bitNum >= 0)) {
         enableClock();

         // Pointer to PCR register for pin
         constexpr volatile uint32_t *pcrReg = reinterpret_cast<volatile uint32_t *>(pcrAddress+offsetof(PORT_Type,PCR[bitNum]));
         *pcrReg = pcrValue;
      }
   }
   /**
    * Set pin PCR.MUX value\n
    * Assumes clock to the port has already been enabled\n
    * Other PCR bits are taken from default value in template
    *
    * @param muxValue PCR MUX value [0..7]
    */
   static void setMUX(uint32_t muxValue) {
      if ((pcrAddress != 0) && (bitNum >= 0)) {
         // Pointer to PCR register for pin
         constexpr volatile uint32_t *pcrReg = reinterpret_cast<volatile uint32_t *>(pcrAddress+offsetof(PORT_Type,PCR[bitNum]));
         *pcrReg = (defPcrValue&~PORT_PCR_MUX_MASK)|PORT_PCR_MUX(muxValue);
      }
   }
   /**
    * Enable clock to port
    */
   static void enableClock() {
      bmeOr(SIM->FIXED_PORT_CLOCK_REG, clockMask);
//      SIM->FIXED_PORT_CLOCK_REG |= clockMask;
      __DMB();
   }
   /**
    * Disable clock to port
    */
   static void disableClock() {
      bmeAnd(SIM->FIXED_PORT_CLOCK_REG, ~clockMask);
//      SIM->FIXED_PORT_CLOCK_REG &= ~clockMask;
   }
};

/**
 * @brief Template function to set a PCR to the default value
 *
 * @tparam  Last PCR to modify
 */
template<typename Last>
void processPcrs() {
   Last::setPCR();
}
/**
 * @brief Template function to set a collection of PCRs to the default value
 *
 * @tparam  Pcr1 PCR to modify
 * @tparam  Pcr2 PCR to modify
 * @tparam  Rest Remaining PCRs to modify
 */
template<typename Pcr1, typename  Pcr2, typename  ... Rest>
void processPcrs() {
   processPcrs<Pcr1>();
   processPcrs<Pcr2, Rest...>();
}
/**
 * @brief Template function to set a PCR to a given value
 *
 * @param   pcrValue PCR value to set
 *
 * @tparam  Last PCR to modify
 */
template<typename Last>
void processPcrs(uint32_t pcrValue) {
   Last::setPCR(pcrValue);
}

/**
 * @brief Template function to set a collection of PCRs to a given value
 *
 * @param pcrValue PCR value to set
 *
 * @tparam  Pcr1 PCR to modify
 * @tparam  Pcr2 PCR to modify
 * @tparam  Rest Remaining PCRs to modify
 */
template<typename Pcr1, typename  Pcr2, typename  ... Rest>
void processPcrs(uint32_t pcrValue) {
   processPcrs<Pcr1>(pcrValue);
   processPcrs<Pcr2, Rest...>(pcrValue);
}

/**
 * @brief Template representing a Pin Control Register (PCR)\n
 * Makes use of a configuration class
 *
 * Code examples:
 * @code
 * // Create PCR type
 * Pcr_T<spiInfo, 3> SpiMOSI;
 *
 * // Configure PCR
 * SpiMOSI.setPCR(PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK|PORT_PCR_MUX(3));
 *
 * // Disable clock to associated PORT
 * SpiMOSI.disableClock();
 *
 * // Alternatively the PCR may be manipulated directly
 * Pcr_T<spiInfo, 3>::setPCR(PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
 * @endcode
 *
 * @tparam info          Configuration class
 * @tparam index         Index of pin in configuration table
 */
template<class Info, uint8_t index> using PcrTable_T =
      Pcr_T<Info::info[index].clockMask, Info::info[index].pcrAddress, Info::info[index].gpioBit, Info::info[index].pcrValue>;

/**
 * @}
 ** PeripheralPinTables
 */
} // End namespace USBDM

#endif /* HEADER_PCR_H */

