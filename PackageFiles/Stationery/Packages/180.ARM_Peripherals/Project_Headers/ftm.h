/**
 * @file     ftm.h
 * @brief    Flexitimer Timer Module
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */
#ifndef HEADER_FTM_H
#define HEADER_FTM_H
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
#include <cmath>

/*
 * Default port information
 */

#ifndef FTM0_CLOCK_MASK
#ifdef SIM_SCGC6_FTM0_MASK
#define FTM0_CLOCK_MASK SIM_SCGC6_FTM0_MASK
#define FTM0_CLOCK_REG  SCGC6
#endif
#ifdef SIM_SCGC6_FTM1_MASK
#define FTM1_CLOCK_MASK SIM_SCGC6_FTM1_MASK
#define FTM1_CLOCK_REG  SCGC6
#endif
#ifdef SIM_SCGC6_FTM2_MASK
#define FTM2_CLOCK_MASK SIM_SCGC6_FTM2_MASK
#define FTM2_CLOCK_REG  SCGC6
#elif defined SIM_SCGC3_FTM2_MASK
#define FTM2_CLOCK_MASK SIM_SCGC3_FTM2_MASK
#define FTM2_CLOCK_REG  SCGC3
#endif
#ifdef SIM_SCGC6_FTM3_MASK
#define FTM3_CLOCK_MASK SIM_SCGC6_FTM3_MASK
#define FTM3_CLOCK_REG  SCGC6
#endif
#ifdef SIM_SCGC3_FTM3_MASK
#define FTM3_CLOCK_MASK SIM_SCGC3_FTM3_MASK
#define FTM3_CLOCK_REG  SCGC3
#endif
#ifdef SIM_SCGC3_FTM3_MASKC
#define FTM3_CLOCK_MASK SIM_SCGC3_FTM3_MASKC
#define FTM3_CLOCK_REG  SCGC3
#endif
#endif

namespace USBDM {

/**
 * @addtogroup FTM_Group FTM, PWM, Input capture and Output compare
 * @brief Pins used for PWM, Input capture and Output compare
 * @{
 */
/**
 * Controls basic operation of PWM/Input capture
 */
enum FtmChannelMode {
   //! Capture rising edge
   FtmInputCaptureRisingEdge                = FTM_CnSC_MS(0)|FTM_CnSC_ELS(1),
   //! Capture falling edge
   FtmInputCaptureFallingEdge               = FTM_CnSC_MS(0)|FTM_CnSC_ELS(2),
   //! Capture both rising and falling edges
   FtmInputCaptureEitherEdge                = FTM_CnSC_MS(0)|FTM_CnSC_ELS(3),
   //! Output compare operation
   FtmOutputCompare                         = FTM_CnSC_MS(1),
   //! Toggle pin on output compare
   FtmOutputCompareToggle                   = FTM_CnSC_MS(1)|FTM_CnSC_ELS(1),
   //! Clear pin on output compare
   FtmOutputCompareClear                    = FTM_CnSC_MS(1)|FTM_CnSC_ELS(2),
   //! Set pin on output compare
   FtmOutputCompareSet                      = FTM_CnSC_MS(1)|FTM_CnSC_ELS(3),
   //! PWM with high-true pulses
   FtmPwmHighTruePulses                     = FTM_CnSC_MS(2)|FTM_CnSC_ELS(2),
   //! PWM with low-true pulses
   FtmPwmLowTruePulses                      = FTM_CnSC_MS(2)|FTM_CnSC_ELS(1),
   //! Dual edge input capture one shot - CHn configuration
   FtmDualEdgeCaptureOneShotRisingEdge      = FTM_CnSC_MS(0)|FTM_CnSC_ELS(1),
   //! Dual edge input capture continuous - CHn configuration
   FtmDualEdgeCaptureContinuousRisingEdge   = FTM_CnSC_MS(1)|FTM_CnSC_ELS(1),
   //! Dual edge input capture one shot - CHn configuration
   FtmDualEdgeCaptureOneShotFallingEdge     = FTM_CnSC_MS(0)|FTM_CnSC_ELS(2),
   //! Dual edge input capture continuous - CHn configuration
   FtmDualEdgeCaptureContinuousFallingEdge  = FTM_CnSC_MS(1)|FTM_CnSC_ELS(2),
   //! Combine mode - CHn configuration
   FtmCombinePositivePulse                  = FTM_CnSC_MS(0)|FTM_CnSC_ELS(2),
   //! Combine mode - CHn configuration
   FtmCombineNegativePulse                  = FTM_CnSC_MS(0)|FTM_CnSC_ELS(1),
};

/**
 * Control alignment of PWM function
 */
enum FtmMode {
   //! Left-aligned PWM - also used for input capture and output compare modes
   FtmModeLeftAlign   = 0,
   //! Centre-aligned PWM
   FtmModeCentreAlign = FTM_SC_CPWMS_MASK,
   //! Dummy value for Quadrature encoder
   FtmModeQuadrature  = 0,
};

/**
 * Type definition for FTM timer overflow interrupt call back
 */
typedef void (*FTMCallbackFunction)(volatile FTM_Type *tmr);
/**
 * Type definition for FTM channel interrupt call back
 *
 * @param status Flags indicating interrupt source channels
 */
typedef void (*FTMChannelCallbackFunction)(volatile FTM_Type *tmr, int status);

/**
 * Base class representing an FTM
 *
 * Example
 * @code
 * // Instantiate the tmr (for FTM0)
 * const USBDM::FtmBase_T<FTM0_Info)> Ftm0;
 *
 * // Initialise PWM with initial period and alignment
 * Ftm0::setMode(200, USBDM::FtmModeLeftAlign);
 *
 * // Change timer period
 * Ftm0::setPeriod(500);
 * @endcode
 *
 * @tparam Info  Class describing FTM hardware instance
 */
template<class Info>
class FtmBase_T {

protected:
   static constexpr volatile FTM_Type* tmr      = Info::ftm;
   static constexpr volatile uint32_t *clockReg = Info::clockReg;

public:
   /**
    * Enable with default settings\n
    * Includes configuring all pins
    */
   static void enable() {
      // Configure pins
      Info::initPCRs();

      // Enable clock to timer
      *clockReg |= Info::clockMask;
      __DMB();

      // Common registers
      tmr->CNTIN   = 0;
      tmr->MOD     = Info::period;
      tmr->SC      = Info::sc;
	  //TODO Make configurable
      tmr->CONF    = FTM_CONF_BDMMODE(1);
	  //TODO Make configurable
      tmr->COMBINE = FTM_COMBINE_FAULTEN0_MASK|FTM_COMBINE_FAULTEN1_MASK|FTM_COMBINE_FAULTEN2_MASK|FTM_COMBINE_FAULTEN3_MASK;

      enableNvicInterrupts();
   }

   /**
    * Check if FTM is enabled\n
    * Just check for clock enable and clock sourtce selection
    *
    * @return True => enabled
    */
   static bool isEnabled() {
      return ((*clockReg & Info::clockMask) != 0) && ((tmr->SC & FTM_SC_CLKS_MASK) != 0);
   }

   /**
    * Configure Timer operation\n
    * Used to change configuration after enabling interface
    *
    * @param period  Period in ticks
    * @param mode    Mode of operation see USBDM::FtmMode
    *
    * @note Assumes prescale has been chosen as a appropriate value. Rudimentary range checking.
    */
   static void configure(uint32_t period /* ticks */, FtmMode mode=FtmModeLeftAlign) {

      tmr->SC      = mode;
      if (mode == FtmModeCentreAlign) {
         // Centre aligned PWM with CPWMS not selected
         tmr->SC   = Info::sc|FTM_SC_CPWMS_MASK;
      }
      else {
         // Left aligned PWM without CPWMS selected
         tmr->SC   = Info::sc;
      }
      setPeriodInTicks(period);

      enableNvicInterrupts();
   }

   /**
    * Enable/disable interrupts in NVIC
    *
    * @param enable true to enable, false to disable
    */
   static void enableNvicInterrupts(bool enable=true) {

      if (enable) {
         // Enable interrupts
         NVIC_EnableIRQ(Info::irqNums[0]);

         // Set priority level
         NVIC_SetPriority(Info::irqNums[0], Info::irqLevel);
      }
      else {
         // Disable interrupts
         NVIC_DisableIRQ(Info::irqNums[0]);
      }
   }

   /**
    * Enable/disable Timer Overflow interrupts
    *
    * @param enable true to enable, false to disable
    */
   static void enableTimerOverflowInterrupts(bool enable=true) {
      if (enable) {
         tmr->SC |= FTM_SC_TOIE_MASK;
      }
      else {
         tmr->SC &= ~FTM_SC_TOIE_MASK;
      }
   }

   /**
    * Set period
    *
    * @param period Period in seconds as a float
    *
    * @note Adjusts FTM pre-scaler to appropriate value.
    *       This will affect all channels
    *
    * @return true => success, false => failed to find suitable values
    */
   static ErrorCode setPeriod(float period) {
      float inputClock = Info::getInputClockFrequency();
      int prescaleFactor=1;
      int prescalerValue=0;
      while (prescalerValue<=7) {
         float    clock = inputClock/prescaleFactor;
         uint32_t mod   = round(period*clock);
         if (mod < Info::minimumResolution) {
            // Too short a period for 1% resolution
            return setErrorCode(E_TOO_SMALL);
         }
         if (mod <= 65535) {
            // Clear SC so immediate effect on prescale change
            uint32_t sc = tmr->SC&~FTM_SC_PS_MASK;
            tmr->SC     = 0;
            __DSB();
            tmr->MOD    = mod;
            tmr->SC     = sc|FTM_SC_PS(prescalerValue);
            return E_NO_ERROR;
         }
         prescalerValue++;
         prescaleFactor <<= 1;
      }
      // Too long a period
      return setErrorCode(E_TOO_LARGE);
   }

   /**
    * Set period
    *
    * @param period Period in ticks
    *
    * @return E_NO_ERROR on success
    *
    * @note Assumes prescale has been chosen as a appropriate value. Rudimentary range checking.
    */
   static ErrorCode setPeriodInTicks(uint32_t period) {

      // Check if CPWMS is set (affects period)
      bool centreAlign = (tmr->SC&FTM_SC_CPWMS_MASK) != 0;

      // Disable so register changes are immediate
      tmr->SC = FTM_SC_CLKS(0);

      if (centreAlign) {
#ifdef DEBUG_BUILD
         if (period > 2*0xFFFFUL) {
            // Attempt to set too long a period
            return setErrorCode(E_TOO_LARGE);
         }
#endif
         tmr->MOD = (uint32_t)(period/2);
         // Centre aligned PWM with CPWMS not selected
         tmr->SC  = Info::sc|FTM_SC_CPWMS_MASK;
      }
      else {
#ifdef DEBUG_BUILD
         if (period > 0x10000UL) {
            // Attempt to set too long a period
            return setErrorCode(E_TOO_LARGE);
         }
#endif
         tmr->MOD = (uint32_t)(period-1);
         // Left aligned PWM without CPWMS selected
         tmr->SC  = Info::sc;
      }
      // OK period
      return setErrorCode(E_NO_ERROR);
   }

   /**
    * Converts a time in microseconds to number of ticks
    *
    * @param time Time in microseconds
    * @return Time in ticks
    *
    * @note Assumes prescale has been chosen as a appropriate value. Rudimentary range checking.
    */
   static uint32_t convertMicrosecondsToTicks(int time) {

      // Calculate period
      uint32_t tickRate = Info::getClockFrequency();
      uint64_t rv       = ((uint64_t)time*tickRate)/1000000;
#ifdef DEBUG_BUILD
      if (rv > 0xFFFFUL) {
         // Attempt to set too long a period
         setErrorCode(E_TOO_LARGE);
      }
      if (rv == 0) {
         // Attempt to set too short a period
         setErrorCode(E_TOO_SMALL);
      }
#endif
      return rv;
   }

   /**
    * Converts a time in microseconds to number of ticks
    *
    * @param time Time in microseconds
    * @return Time in ticks
    *
    * @note Assumes prescale has been chosen as a appropriate value. Rudimentary range checking.
    */
   static uint32_t convertSecondsToTicks(float time) {

      // Calculate period
      float    tickRate = Info::getClockFrequencyF();
      uint64_t rv       = time*tickRate;
#ifdef DEBUG_BUILD
      if (rv > 0xFFFFUL) {
         // Attempt to set too long a period
         setErrorCode(E_TOO_LARGE);
      }
      if (rv == 0) {
         // Attempt to set too short a period
         setErrorCode(E_TOO_SMALL);
      }
#endif
      return rv;
   }

   /**
    * Converts ticks to time in microseconds
    *
    * @param time Time in ticks
    * @return Time in microseconds
    *
    * @note Assumes prescale has been chosen as a appropriate value. Rudimentary range checking.
    */
   static uint32_t convertTicksToMicroseconds(int time) {

      // Calculate period
      uint32_t tickRate = Info::getClockFrequency()/(1<<(tmr->SC&FTM_SC_PS_MASK));
      uint64_t rv       = ((uint64_t)time*1000000)/tickRate;
#ifdef DEBUG_BUILD
      if (rv > 0xFFFFUL) {
         // Attempt to set too long a period
         setErrorCode(E_TOO_LARGE);
      }
      if (rv == 0) {
         // Attempt to set too short a period
         setErrorCode(E_TOO_SMALL);
      }
#endif
      return rv;
   }

   /**
    *  Enables fault detection input
    *
    *  @tparam inputNum       Number of fault input to enable (0..3)
    *  @param  polarity       Polarity of fault input (true => active high))
    *  @param  filterEnable   Whether to enable filtering on the fault input
    *  @param  filterDelay    Delay used by the filter (1..15) - Applies to all channels
    *
    *  NOTE - the filter delay is shared by all inputs
    */
public:
   template<uint8_t inputNum>
   static void enableFault(bool polarity=true, bool filterEnable=false, uint32_t filterDelay=(1<<FTM_FLTCTRL_FFVAL_SHIFT)-1) {

#ifdef DEBUG_BUILD
   static_assert((inputNum<Info::InfoFAULT::numSignals), "FtmBase_T: Illegal fault channel");
   static_assert((inputNum>=Info::InfoFAULT::numSignals)||(Info::InfoFAULT::info[inputNum].gpioBit != UNMAPPED_PCR), "FtmBase_T: Fault signal is not mapped to a pin - Modify Configure.usbdm");
   static_assert((inputNum>=Info::InfoFAULT::numSignals)||(Info::InfoFAULT::info[inputNum].gpioBit != INVALID_PCR),  "FtmBase_T: Non-existent signal used for fault input");
   static_assert((inputNum>=Info::InfoFAULT::numSignals)||(Info::InfoFAULT::info[inputNum].gpioBit == UNMAPPED_PCR)||(Info::InfoFAULT::info[inputNum].gpioBit == INVALID_PCR)||(Info::InfoFAULT::info[inputNum].gpioBit >= 0), "Pcr_T: Illegal signal used for fault");
#endif

      PcrTable_T<typename Info::InfoFAULT, inputNum>::setPCR();

      if (polarity) {
         // Set active high
         tmr->FLTPOL &= ~(1<<inputNum);
      }
      else {
         // Set active low
         tmr->FLTPOL |= (1<<inputNum);
      }
      if (filterEnable) {
         // Enable filter & set filter delay
         tmr->FLTCTRL = ((tmr->FLTCTRL) & ~(FTM_FLTCTRL_FFVAL_MASK)) | (1<<(inputNum+FTM_FLTCTRL_FFLTR0EN_SHIFT)) | FTM_FLTCTRL_FFVAL(filterDelay);
      }
      else {
         // Disable filter
         tmr->FLTCTRL &= ~(1<<(inputNum+FTM_FLTCTRL_FFLTR0EN_SHIFT));
      }
      // Enable fault input
      tmr->FLTCTRL |= (1<<inputNum);
      // Enable fault mode (All channels, manual)
      tmr->MODE    |= FTM_MODE_FAULTM(2);
   }

   /**
    * Enable/disable fault interrupts
    *
    * @param enable True = >enabled, False => disabled
    */
   static void enableFaultInterrupt(bool enable=true) {
      if (enable) {
         tmr->MODE |= FTM_MODE_FAULTIE_MASK;
      }
      else {
         tmr->MODE &= ~FTM_MODE_FAULTIE_MASK;
      }
   }

   /**
    *  Disables fault detection input
    *
    *  @tparam inputNum        Number of fault input to enable (0..3)
    */
   template<int inputNum>
   static void disableFault() {
      static_assert(inputNum<=4, "Illegal fault channel");

      // Enable fault on channel
      tmr->FLTCTRL &= ~(1<<inputNum);
   }

   /**
    * Set PWM duty cycle
    *
    * @param dutyCycle  Duty-cycle as percentage
    * @param channel Timer channel
    */
   static void setDutyCycle(int dutyCycle, int channel) {
      if (tmr->SC&FTM_SC_CPWMS_MASK) {
         tmr->CONTROLS[channel].CnV  = (dutyCycle*tmr->MOD)/100;
      }
      else {
         tmr->CONTROLS[channel].CnV  = (dutyCycle*(tmr->MOD+1))/100;
      }
   }

   /**
    * Set PWM duty cycle\n
    * Higher precision float version
    *
    * @param dutyCycle  Duty-cycle as percentage (float)
    * @param channel Timer channel
    */
   static void setDutyCycle(float dutyCycle, int channel) {
      if (tmr->SC&FTM_SC_CPWMS_MASK) {
         tmr->CONTROLS[channel].CnV  = round((dutyCycle*tmr->MOD)/100.0f);
      }
      else {
         tmr->CONTROLS[channel].CnV  = round((dutyCycle*(tmr->MOD+1))/100.0f);
      }
   }

   /**
    * Set PWM high time in ticks
    * Assumes value is less than period
    *
    * @param highTime   PWM high time in ticks
    * @param channel    Timer channel
    *
    * @return E_NO_ERROR on success
    */
   static ErrorCode setHighTime(uint32_t highTime, int channel) {
#ifdef DEBUG_BUILD
      if (highTime > tmr->MOD) {
         return setErrorCode(E_TOO_LARGE);
      }
#endif
      tmr->CONTROLS[channel].CnV  = highTime;
      return E_NO_ERROR;
   }

   /**
    * Set PWM high time in seconds
    *
    * @param highTime   PWM high time in seconds
    * @param channel    Timer channel
    *
    * @return E_NO_ERROR on success
    */
   static ErrorCode setHighTime(float highTime, int channel) {
      return setHighTime(convertSecondsToTicks(highTime), channel);
   }

};

/**
 * Template class to provide FTM callback
 */
template<class Info>
class FtmIrq_T : public FtmBase_T<Info> {

protected:
   /** Callback function for TOI ISR */
   static FTMCallbackFunction toiCallback;
   /** Callback function for Channel ISR */
   static FTMChannelCallbackFunction callback;
   /** Callback function for Channel Fault */
   static FTMCallbackFunction faultCallback;

public:
   /**
    * IRQ handler
    */
   static void irqHandler() {
      if ((FtmBase_T<Info>::tmr->MODE&FTM_MODE_FAULTIE_MASK) && (FtmBase_T<Info>::tmr->FMS&FTM_FMS_FAULTF_MASK)) {
         FtmBase_T<Info>::tmr->FMS &= ~FTM_FMS_FAULTF_MASK;
         if (faultCallback != 0) {
            faultCallback(FtmBase_T<Info>::tmr);
         }
         else {
            setAndCheckErrorCode(E_NO_HANDLER);
         }
      }

      if ((FtmBase_T<Info>::tmr->SC&(FTM_SC_TOF_MASK|FTM_SC_TOIE_MASK)) == (FTM_SC_TOF_MASK|FTM_SC_TOIE_MASK)) {
         // Clear TOI flag
         FtmBase_T<Info>::tmr->SC &= ~FTM_SC_TOF_MASK;
         if (toiCallback != 0) {
            toiCallback(FtmBase_T<Info>::tmr);
         }
         else {
            setAndCheckErrorCode(E_NO_HANDLER);
         }
      }
      uint8_t status = FtmBase_T<Info>::tmr->STATUS;
      if (status) {
         // Clear channel event flags
         FtmBase_T<Info>::tmr->STATUS &= ~status;
         if (callback != 0) {
            callback(FtmBase_T<Info>::tmr, status);
         }
      }
   }

   /**
    * Set TOI Callback function
    *
    * @param theCallback Callback function to execute on interrupt
    */
   static void setTimerOverflowCallback(FTMCallbackFunction theCallback) {
      toiCallback = theCallback;
   }
   /**
    * Set channel Callback function
    *
    * @param theCallback Callback function to execute on interrupt
    */
   static void setChannelCallback(FTMChannelCallbackFunction theCallback) {
      callback = theCallback;
   }
   /**
    * Set fault Callback function
    *
    * @param theCallback Callback function to execute on interrupt
    */
   static void setFaultCallback(FTMCallbackFunction theCallback) {
      faultCallback = theCallback;
   }
};

template<class Info> FTMCallbackFunction           FtmIrq_T<Info>::toiCallback   = 0;
template<class Info> FTMCallbackFunction           FtmIrq_T<Info>::faultCallback = 0;
template<class Info> FTMChannelCallbackFunction    FtmIrq_T<Info>::callback      = 0;

/**
 * Template class representing a FTM timer channel
 *
 * Example
 * @code
 * // Instantiate the timer channel (for FTM0 channel 6)
 * using Ftm0_ch6 = USBDM::FtmChannel<FTM0Info, 6>;
 *
 * // Initialise PWM with initial period and alignment
 * Ftm0_ch6.setMode(200, PwmIO::FtmModeLeftAlign);
 *
 * // Change period (in ticks)
 * Ftm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * Ftm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam channel FTM timer channel
 */
template <class Info, int channel>
class FtmChannel_T : public FtmBase_T<Info>, CheckSignal<Info, channel> {

public:

   /**
    * Enable channel (and set mode)\n
    * Enables owning FTM if not already enabled\n
    * Also see /ref enableChannel()
    *
    * @param mode Mode of operation for FTM e.g.FtmPwmHighTruePulses
    *
    * @note Enables FTM as well
    */
   static void enable(FtmChannelMode mode = FtmPwmHighTruePulses) {
      if (!FtmBase_T<Info>::isEnabled()) {
         // Enable parent FTM if needed
         FtmBase_T<Info>::enable();
      }
      FtmBase_T<Info>::tmr->CONTROLS[channel].CnSC = mode;
   }

   /**
    * Enable channel (and set mode)\n
    * Doesn't affect shared settings of owning FTM
    *
    * @param mode Mode of operation for FTM e.g.FtmPwmHighTruePulses
    */
   static void enableChannel(FtmChannelMode mode = FtmPwmHighTruePulses) {
      FtmBase_T<Info>::tmr->CONTROLS[channel].CnSC = mode;
   }

   /**
    * Enable or disable interrupt from this channel\n
    * Note: It is necessary to enable interrupts in the FTM as well
    *
    * @param enable  True => enable, False => disable
    */
   static void enableChannelInterrupts(bool enable=true) {
      if (enable) {
         FtmBase_T<Info>::tmr->CONTROLS[channel].CnSC |= FTM_CnSC_CHIE_MASK;
      }
      else {
         FtmBase_T<Info>::tmr->CONTROLS[channel].CnSC &= ~FTM_CnSC_CHIE_MASK;
      }
   }

   /**
    * Set Pin Control Register Value (apart from mux)
    *
    * @param pcrValue PCR value to set
    */
   static void setPCR(PcrValue pcrValue) {
      PcrTable_T<Info,  channel>::setPCR((pcrValue&~PORT_PCR_MUX_MASK)|(Info::info[channel].pcrValue&PORT_PCR_MUX_MASK));
   }

   /**
    * Set PWM high time in ticks\n
    * Assumes value is less than period
    *
    * @param highTime   PWM high time in ticks
    *
    * @return E_NO_ERROR on success
    */
   static ErrorCode setHighTime(uint32_t highTime) {
      return FtmBase_T<Info>::setHighTime(highTime, channel);
   }

   /**
    * Set PWM high time in seconds\n
    * Higher precision float version
    *
    * @param highTime   PWM high time in seconds
    *
    * @return E_NO_ERROR on success
    */
   static ErrorCode setHighTime(float highTime) {
      return FtmBase_T<Info>::setHighTime(highTime, channel);
   }
   /**
    * Set PWM duty cycle
    *
    * @param dutyCycle  Duty-cycle as percentage
    */
   static void setDutyCycle(int dutyCycle) {
      FtmBase_T<Info>::setDutyCycle(dutyCycle, channel);
   }

   /**
    * Set PWM duty cycle
    *
    * @param dutyCycle  Duty-cycle as percentage
    */
   static void setDutyCycle(float dutyCycle) {

      FtmBase_T<Info>::setDutyCycle(dutyCycle, channel);
   }

   /**
    * Get channel number
    *
    * @return Channel number (0-7)
    */
   static constexpr int getChannelNumber(void) {
      return channel;
   }

   /**
    * Clear interrupt flag on channel
    */
   static void clearInterruptFlag(void) {
      FtmBase_T<Info>::tmr->CONTROLS[channel].CnSC &= ~FTM_CnSC_CHF_MASK;
   }
};

#ifdef USBDM_FTM0_IS_DEFINED
/**
 * Template class representing a FTM0 timer channel
 *
 * Example
 * @code
 * // Instantiate the timer channel (for FTM0 channel 6)
 * using Ftm0_ch6 = USBDM::Ftm0Channel<6>;
 *
 * // Initialise PWM with initial period and alignment
 * Ftm0_ch6.setMode(200, PwmIO::FtmModeLeftAlign);
 *
 * // Change period (in ticks)
 * Ftm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * Ftm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam channel FTM timer channel
 */
template <int channel>
class Ftm0Channel : public FtmChannel_T<Ftm0Info, channel> {};

/**
 * Class representing FTM0
 */
using Ftm0 = FtmIrq_T<Ftm0Info>;
#endif

#ifdef USBDM_FTM1_IS_DEFINED
/**
 * Template class representing a FTM1 timer channel
 *
 * Refer @ref Ftm0Channel
 *
 * @tparam channel FTM timer channel
 */
template <int channel>
class Ftm1Channel : public FtmChannel_T<Ftm1Info, channel> {};

/**
 * Class representing FTM1
 */
using Ftm1 = FtmIrq_T<Ftm1Info>;
#endif

#ifdef USBDM_FTM2_IS_DEFINED
/**
 * Template class representing a FTM2 timer channel
 *
 * Refer @ref Ftm0Channel
 *
 * @tparam channel FTM timer channel
 */
template <int channel>
class Ftm2Channel : public FtmChannel_T<Ftm2Info, channel> {};

/**
 * Class representing FTM2
 */
using Ftm2 = FtmIrq_T<Ftm2Info>;
#endif

#ifdef USBDM_FTM3_IS_DEFINED
/**
 * Template class representing a FTM3 timer channel
 *
 * Refer @ref Ftm0Channel
 *
 * @tparam channel FTM timer channel
 */
template <int channel>
class Ftm3Channel : public FtmChannel_T<Ftm3Info, channel> {};

/**
 * Class representing FTM0
 */
using Ftm3 = FtmIrq_T<Ftm3Info>;
#endif

/**
 * Template class representing a FTM configured as a Quadrature encoder
 *
 * @tparam info      Information class for FTM
 *
 * @code
 *  QuadEncoder_T<Ftm0Info> encoder0;
 *
 *  for(;;) {
 *     printf("Position = %d\n", encoder.getPosition());
 *  }
 * @endcode
 */
template <class Info>
class QuadEncoder_T : public FtmIrq_T<Info> {

#ifdef DEBUG_BUILD
   static_assert(Info::InfoQUAD::info[0].gpioBit != UNMAPPED_PCR, "QuadEncoder_T: FTM PHA is not mapped to a pin - Modify Configure.usbdm");
   static_assert(Info::InfoQUAD::info[1].gpioBit != UNMAPPED_PCR, "QuadEncoder_T: FTM PHB is not mapped to a pin - Modify Configure.usbdm");
#endif

private:
   static constexpr volatile FTM_Type *ftm      = Info::ftm;
   static constexpr volatile uint32_t *clockReg = Info::clockReg;

public:
   /**
    * Enable quadrature decoding
    */
   static void enable() {
      Info::InfoQUAD::initPCRs();

      // Enable clock to timer
      *clockReg |= Info::clockMask;
      __DMB();

      FtmBase_T<Info>::configure(0, FtmModeQuadrature);

      ftm->QDCTRL =
            FTM_QDCTRL_QUADEN_MASK|      // Enable Quadrature encoder
            FTM_QDCTRL_QUADMODE(0);      // Quadrature mode
      ftm->CONF   = FTM_CONF_BDMMODE(3);
   }
   /**
    * Enable/disables filtering of quadrature inputs
    *
    * @param filterValue 0=>disable, 1..15 filter length
    */
   static void enableFilter(int filterValue=7) {
      if (filterValue>0) {
         ftm->FILTER |= FTM_FILTER_CH0FVAL(filterValue)| FTM_FILTER_CH1FVAL(filterValue);
         ftm->QDCTRL |= FTM_QDCTRL_PHAFLTREN_MASK|FTM_QDCTRL_PHBFLTREN_MASK;
      }
      else {
         ftm->QDCTRL &= ~(FTM_QDCTRL_PHAFLTREN_MASK|FTM_QDCTRL_PHBFLTREN_MASK);
      }
   }

   /**
    * Reset position to zero
    */
   static void resetPosition() {
      // Note: writing ANY value clears CNT (cannot set value)
      ftm->CNT = 0;
   }
   /**
    * Get Quadrature encoder position
    *
    * @return Signed number representing position relative to reference location
    */
   static int16_t getPosition() {
      return (int16_t)(ftm->CNT);
   }
};


#ifdef USBDM_FTM0_IS_DEFINED
/**
 * Class representing FTM0 as Quadrature encoder
 * Not all FTMs support this mode
 */
using QuadEncoder0 = QuadEncoder_T<Ftm0Info>;
#endif

#ifdef USBDM_FTM1_IS_DEFINED
/**
 * Class representing FTM1 as Quadrature encoder
 * Not all FTMs support this mode
 */
using QuadEncoder1 = QuadEncoder_T<Ftm1Info>;
#endif

#ifdef USBDM_FTM2_IS_DEFINED
/**
 * Class representing FTM2 as Quadrature encoder
 * Not all FTMs support this mode
 */
using QuadEncoder2 = QuadEncoder_T<Ftm2Info>;
#endif

#ifdef USBDM_FTM3_IS_DEFINED
/**
 * Class representing FTM3 as Quadrature encoder
 * Not all FTMs support this mode
 */
using QuadEncoder3 = QuadEncoder_T<Ftm3Info>;
#endif

#ifdef USBDM_FTM4_IS_DEFINED
/**
 * Class representing FTM4 as Quadrature encoder
 * Not all FTMs support this mode
 */
using QuadEncoder4 = QuadEncoder_T<Ftm4Info>;
#endif

/**
 * @}
 */
 
} // End namespace USBDM

#endif /* HEADER_FTM_H */

