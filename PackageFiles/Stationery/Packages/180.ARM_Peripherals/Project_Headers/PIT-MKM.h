/**
 * @file      pit.h (derived from pit-MKM.h)
 * @version   1.1.0
 * @brief     Programmable Interrupt  Timer MKL
 */

#ifndef INCLUDE_USBDM_PIT_H_
#define INCLUDE_USBDM_PIT_H_

#include "derivative.h"
#include "system.h"
#include "gpio.h"

namespace USBDM {

/**
 * @addtogroup PIT_Group Programmable Interrupt Timer
 * @brief Abstraction for Programmable Interrupt Timer
 * @{
 */

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

//===================================
// Validators

// Convention
// name_V = field value
// name_M = field mask i.e. value in correct position for register

// PIT_MCR_FRZ ==============================
//
//   <q> PIT Freeze in debug mode
//   <i> When FRZ is set, the PIT will pause when in debug mode. - [PIT_MCR_FRZ]
//     <0=> Timers continue to run in debug mode.
//     <1=> Timers are stopped in Debug mode.
//! Default value for PIT_MCR_FRZ - Determines if PIT freezes in debug mode.
#define PIT_MCR_FRZ_M (1<<PIT_MCR_FRZ_SHIFT)

// PIT IRQ Level in NVIC ==============================
//
//   <o> PIT IRQ Level in NVIC <0-15>
//   <i> Configures the IRQ level set in the NVIC.
//! Default value for PIT interrupt level
#define PIT_IRQ_LEVEL_V (2)

// PIT_USES_NAKED_HANDLER ==============================
//
//   <q> Interrupt handler setup
//   <i> The interrupt handler may use an external function named PITx_IRQHandler() or
//   <i> may be set by use of the setCallback() function  - [PIT_USES_NAKED_HANDLER]
//     <0=> Interrupt handler is programmatically set.
//     <1=> PITx_IRQHandler() is externally provided.
//! Determines how PIT interrupt handler is specified
#define PIT_USES_NAKED_HANDLER 1

/**
 * Default PSR value for Timer
 */
#define PIT_MCR_DEFAULT_VALUE (PIT_MCR_FRZ_M)
/**
 * Default TCTRL value for Timer channel
 */
#define PIT_TCTRL_DEFAULT_VALUE (PIT_TCTRL_TEN_MASK|PIT_TCTRL_TIE_MASK)

#define PIT0_NUMBER_OF_CHANNELS (sizeof(PIT0->CHANNEL)/sizeof(PIT0->CHANNEL[0]))
#define PIT1_NUMBER_OF_CHANNELS (sizeof(PIT1->CHANNEL)/sizeof(PIT1->CHANNEL[0]))

#if PIT_USES_NAKED_HANDLER == 0
   /**
    * Type definition for PIT interrupt call back
    */
   typedef void (*PITCallbackFunction)(void);
#endif

   /*!
    * @brief struct representing a Programmable Interrupt  Timer
    *
    * <b>Example</b>
    * @code
    *
    * @endcode
    */
struct PIT_ {

volatile uint32_t 	*simscgc;
		 uint32_t 	 clockMask;
volatile PIT_Type 	*pit;

#if PIT_USES_NAKED_HANDLER == 0
static PITCallbackFunction callback[];

public:
   void setCallback(int channel, PITCallbackFunction callback) const {
      PIT_::callback[channel] = callback;
   }
#endif
            
   /**
    *  Configure the PIT
    *
    *  @param mcr       Module Control Register
    */
   void configure(uint32_t mcr=PIT_MCR_DEFAULT_VALUE) const {
      // Enable clock
	   *simscgc |= clockMask;

      // Enable timer
      pit->MCR = mcr;
   }
   /**
    *   Disable the PIT channel
    */
   void finalise(uint8_t channel) const {
	   *simscgc &= ~clockMask;
   }
   /**
    *  Configure the PIT channel
    *
    *  @param channel   Channel to configure
    *  @param interval  Interval in timer ticks (usually bus clock period)
    *  @param tctrl     Timer Control Register value
    */
   void configureChannel(uint8_t channel, uint32_t interval, uint32_t tctrl=PIT_TCTRL_DEFAULT_VALUE) const {

      pit->CHANNEL[channel].LDVAL = interval;
      pit->CHANNEL[channel].TCTRL = tctrl;
      pit->CHANNEL[channel].TFLG  = PIT_TFLG_TIF_MASK;
      
      if (tctrl & PIT_TCTRL_TIE_MASK) {
         // Enable timer interrupts
         NVIC_EnableIRQ((IRQn_Type)(PIT0_1_IRQn));

         // Set arbitrary priority level
         NVIC_SetPriority((IRQn_Type)(PIT0_1_IRQn), PIT_IRQ_LEVEL_V);
      }
   }
   /**
    *   Disable the PIT channel
    */
   void finaliseChannel(uint8_t channel) const {

      // Disable timer channel
      pit->CHANNEL[channel].TCTRL = 0;

      // Enable timer interrupts
      NVIC_EnableIRQ((IRQn_Type)(PIT0_1_IRQn));
   }
   /**
    *  Use a PIT channel to implement a busy-wait delay
    *
    *  @param channel   Channel to use
    *  @param interval  Interval to wait in timer ticks (usually bus clock period)
    *
    *  @note Function doesn't return until interval has expired
    */
   void delay(uint8_t channel, uint32_t interval) const {
      configureChannel(channel, interval, PIT_TCTRL_TEN_MASK);
      while (pit->CHANNEL[channel].TFLG == 0) {
         __NOP();
      }
      configureChannel(channel, 0, 0);
   }
};

#ifdef PIT0
/**
 * @brief struct representing PIT_0
 */
extern const PIT_ PIT_0;
#endif

#ifdef PIT1
/**
 * @brief struct representing PIT_0
 */
extern const PIT_ PIT_1;
#endif

/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_USBDM_PIT_H_ */
