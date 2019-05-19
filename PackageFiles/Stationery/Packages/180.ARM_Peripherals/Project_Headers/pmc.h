/**
 * @file     pmc.h (180.ARM_Peripherals/Project_Headers/pmc.h)
 * @brief    Power Management Controller
 *
 * @version  V4.12.1.210
 * @date     30 September 2017
 */

#ifndef HEADER_PMC_H
#define HEADER_PMC_H
 /*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include "hardware.h"

namespace USBDM {

/**
 * @addtogroup PMC_Group PMC, Power Management Controller
 * @brief Peripheral information for Power Management Controller
 * @{
 */

/**
 * Indicates reason for execution of call-back
 */
enum PmcInterruptReason {
   PmcInterruptReason_LowVoltageDetect,//!< Low Voltage Detect
   PmcInterruptReason_LowVoltageWarning//!< Low Voltage Warning
};

/**
 * Type definition for PDB interrupt call back
 *
 * @param pmcInterruptReason Reason for interrupt leading to call-back
 */
typedef void (*PMCCallbackFunction)(PmcInterruptReason pmcInterruptReason);

/**
 * Action to take on Low Voltage Detect
 */
enum PmcLowVoltageDetectAction {
   PmcLowVoltageDetectAction_None      = PMC_LVDSC1_LVDRE(0)|PMC_LVDSC1_LVDIE(0),//!< No action on Low Voltage Detect
   PmcLowVoltageDetectAction_Interrupt = PMC_LVDSC1_LVDRE(1)|PMC_LVDSC1_LVDIE(1),//!< Interrupt on Low Voltage Detect
   PmcLowVoltageDetectAction_Reset     = PMC_LVDSC1_LVDRE(0)|PMC_LVDSC1_LVDIE(0),//!< Reset on Low Voltage Detect
};

#ifdef PMC_LVDSC1_LVDV
/**
 * Level at which Low Voltage Detect operates
 */
enum PmcLowVoltageDetectLevel {
   PmcLowVoltageDetectLevel_Low        = PMC_LVDSC1_LVDV(0),//!< Lowest level - Vlvdl
   PmcLowVoltageDetectLevel_High       = PMC_LVDSC1_LVDV(1),//!< Lowest level - Vlvdh
//   PmcLowVoltageDetectLevel_Reserved1  = PMC_LVDSC1_LVDV(2),//!< Reserved
//   PmcLowVoltageDetectLevel_Reserved2  = PMC_LVDSC1_LVDV(3),//!< Reserved
};
#endif

/**
 * Action to take on Low Voltage Warning
 */
enum PmcLowVoltageWarningAction {
   PmcLowVoltageWarningAction_None      = PMC_LVDSC2_LVWIE(0),//!< No action on Low Voltage Warning
   PmcLowVoltageWarningAction_Interrupt = PMC_LVDSC2_LVWIE(1),//!< Interrupt on Low Voltage Warning
};

#ifdef PMC_LVDSC2_LVWV
/**
 * Level at which Low Voltage Warning operates
 */
enum PmcLowVoltageWarningLevel {
   PmcLowVoltageWarningLevel_low    = PMC_LVDSC2_LVWV(0), //!< Lowest level - Vlvw1
   PmcLowVoltageWarningLevel_Mid1   = PMC_LVDSC2_LVWV(1), //!< Low middle - Vlvw2
   PmcLowVoltageWarningLevel_Mid2   = PMC_LVDSC2_LVWV(2), //!< High middle - Vlvw3
   PmcLowVoltageWarningLevel_High   = PMC_LVDSC2_LVWV(3), //!< Highest level - Vlvw4
};
#endif

#ifdef PMC_REGSC_BGBE
/**
 * Controls whether the band-gap reference is available to internal devices e.g. CMP etc
 */
enum PmcBandgapBuffer {
   PmcBandgapBuffer_Off   = PMC_REGSC_BGBE(0),  //!< Buffer off, band-gap unavailable to peripherals
   PmcBandgapBuffer_On    = PMC_REGSC_BGBE(1),  //!< Buffer on, band-gap available to peripherals
};
#endif

#ifdef PMC_REGSC_BGEN
/**
 * Controls operation of the band-gap in low power modes
 */
enum PmcBandgapLowPowerEnable {
   PmcBandgapLowPowerEnable_Off       = PMC_REGSC_BGEN(0),                    //!< Band-gap off in VLPx, LLSx and VLLSx
   PmcBandgapLowPowerEnable_On        = PMC_REGSC_BGEN(1),                    //!< Band-gap on, in VLPx, LLSx and VLLSx
#ifdef PMC_REGSC_VLPO_MASK
   PmcBandgapLowPowerEnable_HighSpeed = PMC_REGSC_BGEN(1)|PMC_REGSC_VLPO(1),  //!< High-speed operation with band-gap on in VLPx, LLSx and VLLSx
#endif
};
#endif

/**
 * Template class providing interface to Power Management Controller
 *
 * @tparam info      Information class for PMC
 *
 * @code
 * using pmc = PmcBase_T<PmcInfo>;
 *
 *  pmc::defaultConfigure();
 *
 * @endcode
 */
template <class Info>
class PmcBase_T {

protected:
   /** Callback function for ISR */
   static PMCCallbackFunction sCallback;

   /** Handler for unexpected interrupts */
   static void unhandledCallback(PmcInterruptReason) {
      setAndCheckErrorCode(E_NO_HANDLER);
   }
public:
   /**
    * IRQ handler
    */
   static void irqHandler(void) {

      if ((PmcBase_T<Info>::pmc().LVDSC1 & (PMC_LVDSC1_LVDF_MASK|PMC_LVDSC1_LVDIE_MASK)) ==
            (PMC_LVDSC1_LVDF_MASK|PMC_LVDSC1_LVDIE_MASK)) {

         // LVDF enabled and detected
         PmcBase_T<Info>::pmc().LVDSC1 |= PMC_LVDSC1_LVDF_MASK;
         sCallback(PmcInterruptReason_LowVoltageDetect);
         return;
      }
      if ((PmcBase_T<Info>::pmc().LVDSC2 & (PMC_LVDSC2_LVWF_MASK|PMC_LVDSC2_LVWIE_MASK)) ==
            (PMC_LVDSC2_LVWF_MASK|PMC_LVDSC2_LVWIE_MASK)) {

         // LVWF enabled and detected
         PmcBase_T<Info>::pmc().LVDSC2 |= PMC_LVDSC2_LVWF_MASK;
         sCallback(PmcInterruptReason_LowVoltageWarning);
         return;
      }
#ifdef DEBUG_BUILD
      // Should be impossible
      __BKPT();
#endif
   }

   /**
    * Set Callback function
    *
    *  @param[in]  callback  Callback function to be executed on interrupt.\n
    *                        Use nullptr to remove callback.
    */
   static void setCallback(PMCCallbackFunction callback) {
      usbdm_assert(Info::irqHandlerInstalled, "PMC not configure for interrupts");
      if (callback == nullptr) {
         callback = unhandledCallback;
      }
      sCallback = callback;
   }


protected:
   /** Hardware instance */
   static __attribute__((always_inline)) volatile PMC_Type &pmc() { return Info::pmc(); }

public:
   /**
    * Enable clock to the PMC
    */
   static void  __attribute__((always_inline)) enable() {
   }

   /**
    * Enables PMC and sets to default configuration.
    *
    * Includes enabling clock and any pins used.\n
    * Sets PMC to default configuration.
    */
   static void defaultConfigure() {
      enable();

      pmc().LVDSC1 = Info::pmc_lvdsc1;
      pmc().LVDSC2 = Info::pmc_lvdsc2;
      pmc().REGSC  = Info::pmc_regsc;

      enableNvicInterrupts(Info::irqLevel);
   }

#ifdef PMC_LVDSC1_LVDV
   /**
    * Set action and level for Low Voltage Detect
    *
    * @param[in] pmcLowVoltageDetectAction Action to take on Low Voltage Detect
    * @param[in] pmcLowVoltageDetectLevel  Level at which Low Voltage Detect operates
    */
   static void setLowVoltageReset (
         PmcLowVoltageDetectAction pmcLowVoltageDetectAction = PmcLowVoltageDetectAction_None,
         PmcLowVoltageDetectLevel  pmcLowVoltageDetectLevel  = PmcLowVoltageDetectLevel_High
         ) {
      pmc().LVDSC1 = pmcLowVoltageDetectAction|pmcLowVoltageDetectLevel;
   }

#else
   /**
    * Set action and level for Low Voltage Detect
    *
    * @param[in] pmcLowVoltageDetectAction Action to take on Low Voltage Detect
    */
   static void setLowVoltageReset (PmcLowVoltageDetectAction pmcLowVoltageDetectAction = PmcLowVoltageDetectAction_None) {
      pmc().LVDSC1 = pmcLowVoltageDetectAction;
   }

#endif

#ifdef PMC_LVDSC2_LVWV
   /**
    * Set action and level for Low Voltage Warning
    *
    * @param[in] pmcLowVoltageWarningAction   Action to take on Low Voltage Warning
    * @param[in] pmcLowVoltageWarningLevel    Level at which Low Voltage Warning operates
    */
   static void setLowVoltageWarning (
         PmcLowVoltageWarningAction pmcLowVoltageWarningAction = PmcLowVoltageWarningAction_None,
         PmcLowVoltageWarningLevel  pmcLowVoltageWarningLevel  = PmcLowVoltageWarningLevel_High
         ) {
      pmc().LVDSC2 = pmcLowVoltageWarningAction|pmcLowVoltageWarningLevel;
   }

#else
   /**
    * Set action and level for Low Voltage Warning
    *
    * @param[in] pmcLowVoltageWarningAction   Action to take on Low Voltage Warning
    */
   static void setLowVoltageWarning (
         PmcLowVoltageWarningAction pmcLowVoltageWarningAction = PmcLowVoltageWarningAction_None
         ) {
      pmc().LVDSC2 = pmcLowVoltageWarningAction;
   }

#endif

#ifdef PMC_REGSC_ACKISO_MASK
   /**
    * Release pins after VLLSx exit
    */
   static void releasePins () {
      pmc().REGSC |= PMC_REGSC_ACKISO_MASK;
   }
#endif

#ifdef PMC_REGSC_BGEN
   /**
    * Determines availability of Band-gap reference
    *
    * @param[in] pmcBandgapBuffer         Controls whether the band-gap reference is available to internal devices e.g. CMP etc
    * @param[in] pmcBandgapLowPowerEnable Controls operation of the band-gap in low power modes
    */
   static void setBandgapOperation(
         PmcBandgapBuffer           pmcBandgapBuffer,
         PmcBandgapLowPowerEnable   pmcBandgapLowPowerEnable=PmcBandgapLowPowerEnable_Off) {
      pmc().REGSC = pmcBandgapBuffer|pmcBandgapLowPowerEnable;
   }
#endif

#ifdef PMC_REGSC_BIASEN
   /**
    * Enables source and well biasing for the core logic in low power mode.
    *
    * In full performance mode this option has no effect.
    * This is useful to further reduce MCU power consumption in low power mode.
    * This bit must be enabled when using VLP* modes.
    *
    * Biasing enabled => Core logic is slower and there are restrictions in allowed system clock speed
    */
   static void enableCoreBias() {
      pmc().REGSC |= PMC_REGSC_BIASEN_MASK;
   }

   /**
    * Disables source and well biasing for the core logic in low power mode.
    *
    * Biasing disabled => Core logic can run in full performance
    */
   static void disableCoreBias() {
      pmc().REGSC &= ~PMC_REGSC_BIASEN_MASK;
   }
#endif

#ifdef PMC_REGSC_CLKBIASDIS
   /**
    * Enables the bias currents and reference voltages for some clock modules.
    *
    * Disabling clock bias reduces power consumption in VLPS mode.
    *
    * Enabled  - No effect
    */
   static void enableClockBias() {
      pmc().REGSC &= ~PMC_REGSC_CLKBIASDIS_MASK;
   }

   /**
    * Disables the bias currents and reference voltages for some clock modules.
    *
    * Disabling clock bias further reduce power consumption in VLPS mode.
    * While using this option, it must be ensured that respective clock modules are
    * disabled in VLPS mode otherwise severe malfunction of clock modules will occur.
    *
    * Disabled - In VLPS mode, the bias currents and reference voltages for the 
    *            following clock modules are disabled: SIRC, FIRC, PLL.
    */
   static void disableClockBias() {
      pmc().REGSC |= PMC_REGSC_CLKBIASDIS_MASK;
   }
#endif

#ifdef PMC_REGSC_LPODIS
   /**
    * Enable low power oscillator (LPO)
    *
    * Controls operation of the low power oscillator.
    *
    * @note After disabling the LPO a time of 2 LPO clock cycles is required before 
    *       it is allowed to enable it again. Violating this waiting time of 2 cycles
    *       can result in malfunction of the LPO.
    */
   static void enableLowPowerOscillator() {
      pmc().REGSC &= ~PMC_REGSC_LPODIS_MASK;
   }

   /**
    * Disable low power oscillator (LPO)
    *
    * Controls operation of the low power oscillator.
    *
    * @note After disabling the LPO a time of 2 LPO clock cycles is required before
    *       it is allowed to enable it again. Violating this waiting time of 2 cycles
    *       can result in malfunction of the LPO.
    */
   static void disableLowPowerOscillator() {
      pmc().REGSC |= PMC_REGSC_LPODIS_MASK;
   }
#endif

#ifdef PMC_REGSC_LPOSTAT
   /**
    * Get Low Power Oscillator (LPO) state
    *
    * @return true  => LPO is currently in high state
    * @return false => LPO is currently in low state
    */
   static bool getLowpowerOscillatorStatus() {
      return (pmc().REGSC & PMC_REGSC_LPOSTAT_MASK)?true:false;
   }
#endif

#ifdef PMC_LPOTRIM_LPOTRIM
   static void setLowpowerOscillatorTrim(int trimValue) {
      pmc().LPOTRIM = PMC_LPOTRIM_LPOTRIM(trimValue);
   }
   static int getLowpowerOscillatorTrim() {
      int trim = pmc().LPOTRIM&PMC_LPOTRIM_LPOTRIM_MASK;
      if (((unsigned)trim)>(PMC_LPOTRIM_LPOTRIM_MASK>>1)) {
         // Sign extend -ve values
         trim -= PMC_LPOTRIM_LPOTRIM_MASK+1;
      }
      return trim;
   }
#endif

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

#ifdef PMC_SRAMCTL_VLLS2PD_MASK
   /**
    * Sets which SRAM blocks are powered during LLS2 mode and VLLS2 modes.
    *
    * @param blocks Bit mask for the 8 SRAM blocks, 1=> retain, 0=> not powered during LLS2 mode and VLLS2 modes.
    */
   static void setVlpRamRetention(uint8_t blocks) {
      pmc().SRAMCTL = (uint8_t)~blocks;
   }
#endif
};

template<class Info> PMCCallbackFunction PmcBase_T<Info>::sCallback = PmcBase_T<Info>::unhandledCallback;

#ifdef USBDM_PMC_IS_DEFINED
/**
 * Class representing PMC
 */
class Pmc : public PmcBase_T<PmcInfo> {};

#endif

#ifdef USBDM_PMC0_IS_DEFINED
/**
 * Class representing PMC
 */
class Pmc : public PmcBase_T<PmcInfo> {};

#endif

/**
 * End PMC_Group
 * @}
 */
} // End namespace USBDM

#endif /* HEADER_PMC_H */
