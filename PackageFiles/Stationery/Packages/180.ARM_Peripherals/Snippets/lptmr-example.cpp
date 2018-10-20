/*
 ============================================================================
 * @file lptmr-example.cpp (180.ARM_Peripherals/Snippets/)
 * @brief   Basic C++ LPTMR demo
 *
 *  Created on: 25/09/2017
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "lptmr.h"
#include "smc.h"

using namespace USBDM;

/*
 * Low power timer (LPTMR) example
 *
 * Demonstrates use of timer call-back
 */

// Comment out the following line to use static interrupt handlers
#define SET_HANDLERS_PROGRAMMATICALLY

// Connection mapping - change as required
using RED_LED   = USBDM::GpioC<3>;

using Lptmr = Lptmr0;

/*
 * This handler is set programmatically
 */
void flash(void) {
   RED_LED::toggle();
}

#ifndef SET_HANDLERS_PROGRAMMATICALLY
/**
 * Example showing how to install a custom IRQ handler for the Lptmr.
 * This will avoid the overhead of the USBDM call-back mechanism.
 */
namespace USBDM {

template<>
void Lptmr::irqHandler() {
   // Clear interrupt flag
   lptmr().CSR |= LPTMR_CSR_TCF_MASK;
   RED_LED::toggle();
}

}
#endif

int main() {
   RED_LED::setOutput();

   // Enable LPTMR in time counting mode
   Lptmr::configureTimeCountingMode(
         LptmrResetOn_Compare,
         LptmrInterrupt_Enabled,
         LptmrClockSel_Lpoclk);

   // Set period of timer event
   Lptmr::setPeriod(5*seconds);

#ifdef SET_HANDLERS_PROGRAMMATICALLY
   // This handler is set programmatically
   Lptmr::setCallback(flash);
#endif

   Lptmr::enableNvicInterrupts();

   // Check for errors so far
   checkError();

   for(;;) {
      // Sleep between interrupts
      Smc::enterWaitMode();
      console.writeln("Awake!");
   }
}
