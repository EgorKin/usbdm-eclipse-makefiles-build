/*
 * @file mcg.cpp (Derived from mcg-MK66M18.cpp)
 *
 * Based on K66P144M180SF5RMV2
 *   3 Oscillators (OSC0, RTC, IRC48M)
 *   1 FLL (OSC0, RTC, IRC48M), (FRDIV=/1-/128, /32-/1024, /1280, 1536)
 *   2 PLL (OSC0, RTC, IRC48M), (VCO PRDIV=/1-/7, VDIV=x16-x47)
 *
 *  Created on: 04/03/2012
 *      Author: podonoghue
 */
#include "string.h"
#include "derivative.h" /* include peripheral declarations */
#include "system.h"
#include "utilities.h"
#include "stdbool.h"
#include "pin_mapping.h"
#include "rtc.h"
#include "mcg.h"
#include "osc.h"
 /*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
extern "C" uint32_t SystemCoreClock;
extern "C" uint32_t SystemBusClock;

namespace USBDM {

volatile uint32_t SystemMcgirClock;
volatile uint32_t SystemMcgffClock;
volatile uint32_t SystemMcgFllClock;
volatile uint32_t SystemMcgPllClock;
volatile uint32_t SystemMcgOutClock;
volatile uint32_t SystemCoreClock;
volatile uint32_t SystemBusClock;
volatile uint32_t SystemPeripheralClock;
volatile uint32_t SystemOscerClock;
volatile uint32_t SystemErclk32kClock;
volatile uint32_t SystemLpoClock;
volatile uint32_t SystemRtcClock;

typedef void (*set_sys_dividers_asm_t)(uint32_t simClkDiv1);

//! Change SIM->CLKDIV1 value
//!
//! @param simClkDiv1 - new SIM->CLKDIV1 value
//!
//! @note This routine must be copied to RAM. It is a workaround for errata e2448.
//! Flash prefetch must be disabled when the flash clock divider is changed.
//! This cannot be performed while executing out of flash.
//! There must be a short delay after the clock dividers are changed before prefetch
//! can be re-enabled.
//!
//! @note This routine must be placed in ROM immediately before setSysDividersStub()
//!
static void setSysDividers_asm(uint32_t simClkDiv1) {
   (void) simClkDiv1;
   __asm__ volatile (
       "    .equ   FMC_PFAPR_VALUE,0xffFF0000   \n"
       "    .equ   FMC_PFAPR_ADDR,0x4001F000    \n"
       "    .equ   SIM_CLKDIV1_ADDR,0x40048044  \n"
       "     movw  r1,#FMC_PFAPR_ADDR&0xFFFF    \n" // Point R1 @FMC_PFAPR
       "     movt  r1,#FMC_PFAPR_ADDR/65536     \n"
       "     ldr   r2,[r1,#0]                   \n" // R2 = original FMC_PFAPR
       "     movw  r3,#FMC_PFAPR_VALUE&0xFFFF   \n" // R3 = mask for new FMC_PFAPR
       "     movt  r3,#FMC_PFAPR_VALUE>>16      \n"
       "     orr   r3,r3,r2                     \n" // Merge with existing (Disable Flash pre-fetch)
       "     str   r3,[r1,#0]                   \n" // Write back to FMC_PFAPR

       "     movw  r0,#SIM_CLKDIV1_ADDR&0xFFFF  \n" // Point R0 @SIM->CLKDIV1
       "     movt  r0,#SIM_CLKDIV1_ADDR/65536   \n"
       "     str   %[value],[r0,#0]             \n" // SIM->CLKDIV1 = simClkDiv
       "     movw  r3,#100                      \n" // Wait a while
       "loop:                                   \n"
       "     subs  r3,r3,#1                     \n"
       "     bhi   loop                         \n"
       "                                        \n"
       "     str   r2,[r1,#0]                   \n" // Restore original FMC_PFAPR
         :: [value] "r" (simClkDiv1) : "r0", "r1", "r2", "r3"
      );
}

/**
 *  Change SIM->CLKDIV1 value
 *
 * @param simClkDiv1 - Value to write to SIM->CLKDIV1 register
 *
 * @note This routine must be placed in ROM immediately following setSysDividers_asm()
 */
void setSysDividersStub(uint32_t simClkDiv1) {
   uint8_t space[100]; // Space for RAM copy of setSysDividers_asm()
   set_sys_dividers_asm_t fp = (set_sys_dividers_asm_t)((uint32_t)space|1);

   // Copy routine to RAM (stack)
   memcpy(space, (void*)((uint32_t)setSysDividers_asm&~1), ((uint32_t)setSysDividersStub)-((uint32_t)setSysDividers_asm));

   // Call the function on the stack
   (*fp)(simClkDiv1);
}

/** Callback for programmatically set handler */
MCGCallbackFunction Mcg::callback = {0};

/** Current clock mode (FEI out of reset) */
McgInfo::ClockMode Mcg::currentClockMode = McgInfo::ClockMode::ClockMode_FEI;

#ifdef SMC_PMPROT_AHSRUN_MASK
/**
 * Switch to/from high speed run mode
 * Changes the CPU clock frequency/1, and bus clock frequency /2
 * If the clock is set up for 120 MHz this will be the highest performance possible.
 *
 * This routine assumes that the clock preferences have been set up for the usual RUN mode and only
 * the Core clock divider needs to be changed.
 */
void Mcg::hsRunMode(bool enable) {
   SMC->PMPROT = SMC_PMPROT_AHSRUN_MASK;

   if (enable) {
      SMC->PMCTRL = SMC_PMCTRL_RUNM(3);
      while ((SMC->PMSTAT & 0x80) == 0) {
         // Wait for mode change
         __asm__("nop");
      }
      // Set the SIM _CLKDIV dividers (CPU /1, Bus /2)
      SIM->CLKDIV1 = (SIM_CLKDIV1_OUTDIV1(0))|(SIM_CLKDIV1_OUTDIV2(1))|(SimInfo::clkdiv1 & (SIM_CLKDIV1_OUTDIV3_MASK|SIM_CLKDIV1_OUTDIV4_MASK));
   }
   else {
      // Set the SIM _CLKDIV dividers (CPU normal)
      SIM->CLKDIV1 = SimInfo::clkdiv1;
      SMC->PMCTRL = SMC_PMCTRL_RUNM(0);
   }
   SystemCoreClockUpdate();
}
#endif

/**
 * Do default clock gating
 */
void Mcg::doClockGating() {

   // SOPT1 Clock multiplexing
   SIM->SOPT1 = SimInfo::sopt1;

   // SOPT2 Clock multiplexing
   SIM->SOPT2 = SimInfo::sopt2;

#ifdef SIM_CLKDIV2_USBDIV_MASK
   SIM->CLKDIV2 = SimInfo::clkdiv2;
#endif

#ifdef SIM_CLKDIV3_PLLFLLDIV_MASK
   SIM->CLKDIV3 = SimInfo::clkdiv3;
#endif

#ifdef SIM_SCGC4_USBOTG_MASK
   // !! WARNING !! The USB interface must be disabled for clock changes to have effect !! WARNING !!
   SIM->SCGC4 &= ~SIM_SCGC4_USBOTG_MASK;
#endif

#if defined(SIM_SOPT2_SDHCSRC_MASK) && defined(SIM_SOPT2_SDHCSRC_M) // SDHC clock
   SIM->SOPT2 = (SIM->SOPT2&~SIM_SOPT2_SDHCSRC_MASK)|SIM_SOPT2_SDHCSRC_M;
#endif

#if defined(SIM_SOPT2_RMIISRC_MASK) && defined(SIM_SOPT2_RMIISRC_M) // RMII clock
   SIM->SOPT2 = (SIM->SOPT2&~SIM_SOPT2_RMIISRC_MASK)|SIM_SOPT2_RMIISRC_M;
#endif

#if defined(SIM_SOPT2_CLKOUTSEL_MASK) && defined(SIM_SOPT2_CLKOUTSEL_M)
   SIM->SOPT2 = (SIM->SOPT2&~SIM_SOPT2_CLKOUTSEL_MASK)|SIM_SOPT2_CLKOUTSEL_M;
#endif

#if defined(SIM_CLKDIV2_USBDIV_MASK) && defined(SIM_CLKDIV2_USBFRAC_MASK) && defined(SIM_CLKDIV2_USB_M)
   SIM->CLKDIV2 = (SIM->CLKDIV2&~(SIM_CLKDIV2_USBDIV_MASK|SIM_CLKDIV2_USBFRAC_MASK)) | SIM_CLKDIV2_USB_M;
#endif

   SystemCoreClockUpdate();
}

constexpr uint8_t clockTransitionTable[8][8] = {
         /*  from                 to =>   ClockMode_FEI,           ClockMode_FEE,           ClockMode_FBI,           ClockMode_BLPI,          ClockMode_FBE,           ClockMode_BLPE,          ClockMode_PBE,           ClockMode_PEE */
         /* ClockMode_FEI,  */ { McgInfo::ClockMode_FEI,  McgInfo::ClockMode_FEE,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE, },
         /* ClockMode_FEE,  */ { McgInfo::ClockMode_FEI,  McgInfo::ClockMode_FEE,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE, },
         /* ClockMode_FBI,  */ { McgInfo::ClockMode_FEI,  McgInfo::ClockMode_FEE,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_BLPI, McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE, },
         /* ClockMode_BLPI, */ { McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI, },
         /* ClockMode_FBE,  */ { McgInfo::ClockMode_FEI,  McgInfo::ClockMode_FEE,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_BLPE, McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE, },
         /* ClockMode_BLPE, */ { McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_BLPE, McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE, },
         /* ClockMode_PBE,  */ { McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_BLPE, McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PEE, },
         /* ClockMode_PEE,  */ { McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PEE, },
   };

#ifndef SIM_CLKDIV1_OUTDIV3
#define SIM_CLKDIV1_OUTDIV3(x) 0
#endif

/**
 * Transition from current clock mode to mode given
 *
 * @param to Clock mode to transition to
 */
int Mcg::clockTransition(McgInfo::ClockMode to) {
   constexpr volatile MCG_Type* mcg = (volatile MCG_Type*)McgInfo::basePtr;

   // Set conservative clock dividers
   setSysDividers(SIM_CLKDIV1_OUTDIV4(5)|SIM_CLKDIV1_OUTDIV3(5)|SIM_CLKDIV1_OUTDIV2(5)|SIM_CLKDIV1_OUTDIV1(5));

   if (to != McgInfo::ClockMode_None) {
      int transitionCount = 0;
      do {
         // Used to indicate that clock stabilization wait is needed
         bool externalClockInUse = false;

         McgInfo::ClockMode next;
         if (currentClockMode == McgInfo::ClockMode_None) {
            next = McgInfo::ClockMode_FEI;
         }
         else {
            next = (McgInfo::ClockMode)clockTransitionTable[currentClockMode][to];
         }
         switch (next) {

         case McgInfo::ClockMode_None:
         case McgInfo::ClockMode_FEI: // From FEE, FBI, FBE or reset(FEI)

            mcg->C2 = McgInfo::c2;

            mcg->C1 =
                  MCG_C1_CLKS(0)           | // CLKS     = 0     -> Output of FLL is selected
                  MCG_C1_IREFS(1)          | // IREFS    = 1     -> Slow IRC for FLL source
                  McgInfo::c1;               // FRDIV, IRCLKEN, IREFSTEN

            // Wait for S_IREFST to indicate FLL Reference has switched to IRC
            do {
               __asm__("nop");
            } while ((mcg->S & MCG_S_IREFST_MASK) != (MCG_S_IREFST(1)));

            // Wait for S_CLKST to indicating that OUTCLK has switched to FLL
            do {
               __asm__("nop");
            } while ((mcg->S & MCG_S_CLKST_MASK) != MCG_S_CLKST(0));

            // Set FLL Parameters
            mcg->C4 = (mcg->C4&(MCG_C4_FCTRIM_MASK|MCG_C4_SCFTRIM_MASK))|McgInfo::c4;
            break;

         case McgInfo::ClockMode_FEE: // from FEI, FBI or FBE
            mcg->C1 =
                  MCG_C1_CLKS(0)           | // CLKS     = 0     -> Output of FLL is selected
                  MCG_C1_IREFS(0)          | // IREFS    = 0     -> External reference clock is FLL source
                  McgInfo::c1;           // FRDIV, IRCLKEN, IREFSTEN

            // Wait for S_IREFST to indicate FLL Reference has switched to ERC
            do {
               __asm__("nop");
            } while ((mcg->S & MCG_S_IREFST_MASK) != (MCG_S_IREFST(0)));

            // Wait for S_CLKST to indicating that OUTCLK has switched to FLL
            do {
               __asm__("nop");
            } while ((mcg->S & MCG_S_CLKST_MASK) != MCG_S_CLKST(0));
            externalClockInUse = true;
            break;

         case McgInfo::ClockMode_FBI: // from BLPI, FEI, FEE, FBE
            mcg->C1 =
                  MCG_C1_CLKS(1)           | // CLKS     = 1     -> Internal reference clock is selected
                  MCG_C1_IREFS(1)          | // IREFS    = 1     -> Slow IRC for FLL source
                  McgInfo::c1;           // FRDIV, IRCLKEN, IREFSTEN

            // Clear LP
            mcg->C2 = McgInfo::c2;

            // Wait for S_CLKST to indicating that OUTCLK has switched to IRC
            do {
               __asm__("nop");
            } while ((mcg->S & MCG_S_CLKST_MASK) != MCG_S_CLKST(1));
            break;

         case McgInfo::ClockMode_FBE: // from FEI, FEE, FBI, PBE, BLPE
            // Clear LP
            mcg->C2 = McgInfo::c2;

            mcg->C1 =
                  MCG_C1_CLKS(2)           | // CLKS     = 2     -> External reference clock is selected
                  MCG_C1_IREFS(0)          | // IREFS    = 1     -> Slow IRC for FLL source
                  McgInfo::c1;           // FRDIV, IRCLKEN, IREFSTEN

            // Select FLL as MCG clock source
            mcg->C6  = McgInfo::c6;

            // Wait for S_IREFST to indicate FLL Reference has switched to ERC
            do {
               __asm__("nop");
            } while ((mcg->S & MCG_S_IREFST_MASK) != (MCG_S_IREFST(0)));

            // Wait for S_CLKST to indicating that OUTCLK has switched to IRC
            do {
               __asm__("nop");
            } while ((mcg->S & MCG_S_CLKST_MASK) != MCG_S_CLKST(2));

            externalClockInUse = true;
            break;

         case McgInfo::ClockMode_PBE: // from FBE, BLPE, PEE
            // Clear LP
            mcg->C2 = McgInfo::c2;

            mcg->C1 =
                  MCG_C1_CLKS(2)           | // CLKS     = 2     -> External reference clock is selected
                  MCG_C1_IREFS(0)          | // IREFS    = 1     -> Slow IRC for FLL source
                  McgInfo::c1;           // FRDIV, IRCLKEN, IREFSTEN

            // Select PLL as MCG clock source
            mcg->C6  = McgInfo::c6|MCG_C6_PLLS_MASK;
            externalClockInUse = true;
            break;

         case McgInfo::ClockMode_PEE: // from PBE
            mcg->C1 =
                  MCG_C1_CLKS(0)           | // CLKS     = 0     -> Output of PLLCS is selected
                  MCG_C1_IREFS(0)          | // IREFS    = 1     -> Slow IRC for FLL source
                  McgInfo::c1;           // FRDIV, IRCLKEN, IREFSTEN
            externalClockInUse = true;
            break;

         case McgInfo::ClockMode_BLPE: // from FBE, PBE (registers differ depending on transition)
            externalClockInUse = true;
         case McgInfo::ClockMode_BLPI: // from FBI
            // Set LP
            mcg->C2 = McgInfo::c2|MCG_C2_LP_MASK;
            break;
         }
         // Wait for oscillator stable (if used)
         if (externalClockInUse && (McgInfo::c2&MCG_C2_EREFS0_MASK)) {
            do {
               __asm__("nop");
            } while ((MCG->S & MCG_S_OSCINIT0_MASK) == 0);
         }
         currentClockMode = next;
         if (transitionCount++>5) {
            return -1;
         }
      } while (currentClockMode != to);

      setSysDividers(SimInfo::clkdiv1);
   }

   SystemCoreClockUpdate();
   return 0;
}

/**
 * Update SystemCoreClock variable
 *
 * Updates the SystemCoreClock variable with current core Clock retrieved from CPU registers.
 */
void Mcg::SystemCoreClockUpdate(void) {

   uint32_t SystemMcgirClockUngated = (mcg->C2&MCG_C2_IRCS_MASK)?McgInfo::system_fast_irc_clock:McgInfo::system_slow_irc_clock;

   SystemMcgirClock = (mcg->C1&MCG_C1_IRCLKEN_MASK)?SystemMcgirClockUngated:0;

   uint32_t mcg_erc_clock = 0;
   switch((MCG->C7&MCG_C7_OSCSEL_MASK)) {
      case MCG_C7_OSCSEL(0) : mcg_erc_clock = Osc0::oscclkUndivided; break;
      case MCG_C7_OSCSEL(1) : mcg_erc_clock = Rtc::rtcclk; break;
      case MCG_C7_OSCSEL(2) : mcg_erc_clock = McgInfo::irc48m_clock; break;
   }
   if ((MCG->C1&MCG_C1_IREFS_MASK) == 0) {
      // External reference clock is selected
      SystemMcgffClock = mcg_erc_clock/(1<<((MCG->C1&MCG_C1_FRDIV_MASK)>>MCG_C1_FRDIV_SHIFT));

      if (((MCG->C2&MCG_C2_RANGE0_MASK) != 0) && ((MCG->C7&MCG_C7_OSCSEL_MASK) !=  1)) {
         // High divisors - extra division
         if ((MCG->C1&MCG_C1_FRDIV_MASK) == MCG_C1_FRDIV(6)) {
            SystemMcgffClock /= 20;
         }
         else if ((MCG->C1&MCG_C1_FRDIV_MASK) == MCG_C1_FRDIV(7)) {
            SystemMcgffClock /= 12;
         }
         else {
            SystemMcgffClock /= 32;
         }
      }
   }
   else {
      // External reference clock is selected
      SystemMcgffClock = McgInfo::system_slow_irc_clock;
   }

   uint32_t systemFllClock = SystemMcgffClock * ((MCG->C4&MCG_C4_DMX32_MASK)?732:640) * (((MCG->C4&MCG_C4_DRST_DRS_MASK)>>MCG_C4_DRST_DRS_SHIFT)+1);

   uint32_t systemPllClock = 0;
   systemPllClock  = (mcg_erc_clock/10)*(((MCG->C6&MCG_C6_VDIV0_MASK)>>MCG_C6_VDIV0_SHIFT)+16);
   systemPllClock /= ((MCG->C5&MCG_C5_PRDIV0_MASK)>>MCG_C5_PRDIV0_SHIFT)+1;
   systemPllClock *= 5;

   SystemMcgPllClock = 0;
   SystemMcgFllClock = 0;
   switch (MCG->S&MCG_S_CLKST_MASK) {
      case MCG_S_CLKST(0) : // FLL
         SystemMcgOutClock = systemFllClock;
         SystemMcgFllClock = systemFllClock;
         break;
      case MCG_S_CLKST(1) : // Internal Reference Clock
         SystemMcgOutClock = SystemMcgirClockUngated;
         break;
      case MCG_S_CLKST(2) : // External Reference Clock
         SystemMcgOutClock = mcg_erc_clock;
         break;
      case MCG_S_CLKST(3) : // PLL
         SystemMcgOutClock = systemPllClock;
         SystemMcgPllClock = systemPllClock;
         break;
   }
   if (mcg->C5&MCG_C5_PLLCLKEN0_MASK) {
      SystemMcgPllClock = systemPllClock;
   }
   SystemBusClock    = SystemMcgOutClock/(((SIM->CLKDIV1&SIM_CLKDIV1_OUTDIV2_MASK)>>SIM_CLKDIV1_OUTDIV2_SHIFT)+1);
   SystemCoreClock   = SystemMcgOutClock/(((SIM->CLKDIV1&SIM_CLKDIV1_OUTDIV1_MASK)>>SIM_CLKDIV1_OUTDIV1_SHIFT)+1);

   SystemPeripheralClock = (SIM->SOPT2&SIM_SOPT2_PLLFLLSEL_MASK)?SystemMcgPllClock:SystemMcgFllClock;
   SystemOscerClock      = Osc0::oscclkUndivided;

   switch (SIM->SOPT1&SIM_SOPT1_OSC32KSEL_MASK) {
   case SIM_SOPT1_OSC32KSEL(0): SystemErclk32kClock = Osc0::osc32kclk; break;
   case SIM_SOPT1_OSC32KSEL(2): SystemErclk32kClock = Rtc::rtcclk; break;
   case SIM_SOPT1_OSC32KSEL(3): SystemErclk32kClock = 1000; break;
   }
   SystemRtcClock        = (SIM->SOPT2&SIM_SOPT2_RTCCLKOUTSEL_MASK)?Rtc::rtcclk:((Rtc::rtcclkUngated>0)?1:0);

   SystemLpoClock    = 1000;

   ::SystemBusClock  = SystemBusClock;
   ::SystemCoreClock = SystemCoreClock;
}

/**
 * Sets up the clock out of RESET
 */
void Mcg::initialise(void) {

   currentClockMode = McgInfo::ClockMode::ClockMode_None;

   if (McgInfo::clockMode == McgInfo::ClockMode::ClockMode_None) {
      // No clock setup
      doClockGating();
      return;
   }

#ifdef USB_CLK_RECOVER_IRC_EN_IRC_EN_MASK
   if (McgInfo::c7&&MCG_C7_OSCSEL_MASK) {
      // Note IRC48M Internal Oscillator automatically enable if MCG_C7_OSCSEL = 2
      SIM->SCGC4 |= SIM_SCGC4_USBOTG_MASK;
      USB0->CLK_RECOVER_IRC_EN = USB_CLK_RECOVER_IRC_EN_IRC_EN_MASK|USB_CLK_RECOVER_IRC_EN_REG_EN_MASK;
   }
#endif

   // Set PLL PRDIV0 etc
   MCG->C5  = McgInfo::c5;

   // Set PLL VDIV0 etc
   MCG->C6  = McgInfo::c6;

   // Select OSCCLK Source
   MCG->C7 = McgInfo::c7; // OSCSEL = 0,1,2 -> XTAL/XTAL32/IRC48M

   // Set Fast Internal Clock divider
   MCG->SC = McgInfo::sc;

   // Transition to desired clock mode
   clockTransition(McgInfo::clockMode);

   doClockGating();
}

} // end namespace USBDM

/**
 * Sets up the clock out of RESET
 */
extern "C"
void clock_initialise(void) {

#ifdef USBDM_OSC0_IS_DEFINED
   USBDM::Osc0::initialise();
#endif

#ifdef USBDM_RTC_IS_DEFINED
   USBDM::Rtc::initialise();
#endif

#ifdef USBDM_MCG_IS_DEFINED
   USBDM::Mcg::initialise();
   USBDM::Mcg::SystemCoreClockUpdate();
#endif

}

