/**
 * @file     trng.h (180.ARM_Peripherals/Project_Headers/trng.h)
 * @brief    Flexible I/O
 *
 * @version  V4.12.1.230
 * @date     13 April 2016
 */

#ifndef HEADER_FLEXIO_H_
#define HEADER_FLEXIO_H_
 /*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include "derivative.h"
#include "hardware.h"

namespace USBDM {

/**
 * @addtogroup FLEXIO_Group FLEXIO, Flexible I/O
 * @brief Abstraction for Flexible I/O
 * @{
 */
 
/**
 * Type definition for FLEXIO interrupt call back
 *
 * @param[in]  status Struct indicating interrupt source and state
 */
typedef void (*FLEXIOCallbackFunction)();

/**
 * Template class representing the Random Number Generator Accelerator.
 *
 *
 * @tparam info      Information class for FLEXIO
 */
template<class Info>
class FlexioBase_T {

protected:
   /**
    * Callback to catch unhandled interrupt
    */
   static void unhandledCallback() {
      setAndCheckErrorCode(E_NO_HANDLER);
   }

   /** Callback function for ISR */
   static FLEXIOCallbackFunction callback;

public:
   /**
    * Hardware instance pointer
    *
    * @return Reference to FLEXIO hardware
    */
   static __attribute__((always_inline)) volatile FLEXIO_Type &trng() { return Info::trng(); }

   /**
    * IRQ handler
    */
   static void irqHandler() {
      // Call handler
      callback();
   }

   /**
    * Set callback function
    *
    * @param[in]  theCallback Callback function to execute on interrupt
    */
   static void setCallback(FLEXIOCallbackFunction theCallback) {
      if (theCallback == nullptr) {
         theCallback = unhandledCallback;
      }
      callback = theCallback;
   }

public:

   /**
    * Basic enable FLEXIO.
    *
    * Includes enabling clock
    */
   static void enable() {

      // Enable clock to FLEXIO interface
      Info::enableClock();
   }

   /**
    * Enable with default settings.
    */
   static void defaultConfigure() {
      enable();
   }

   /**
    * Configure FLEXIO.
    *
    * @param[in] trngHighAssurance  Controls High Assurance mode
    * @param[in] trngMode           Controls Sleep mode
    * @param[in] trngInterrupt      Controls Interrupt Mask
    */
   static __attribute__((always_inline)) void configure() {
   }


   /**
    * Disable interface to FLEXIO.
    */
   static void disable() {
      Info::disableClock();
   }

   /**
    * Clear interrupt flag.
    */
   static void clearInterruptFlag() {
   }
   
   /**
    * Enable interrupts in NVIC
    */
   static void enableNvicInterrupts() {
      NVIC_EnableIRQ(Info::irqNums[0]);
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

template<class Info> FLEXIOCallbackFunction FlexioBase_T<Info>::callback = FlexioBase_T<Info>::unhandledCallback;

#if defined(USBDM_FLEXIO_IS_DEFINED)
class Flexio : public FlexioBase_T<FlexioInfo> {};
#endif

#if defined(USBDM_FLEXIO0_IS_DEFINED)
class Flexio0 : public FlexioBase_T<Flexio0Info> {};
#endif

/**
 * End FLEXIO_Group
 * @}
 */
} // End namespace USBDM

#endif /* HEADER_FLEXIO_H_ */