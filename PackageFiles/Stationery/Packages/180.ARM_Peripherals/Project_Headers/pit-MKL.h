/**
 * @file      pit.h  (180.ARM_Peripherals/Project_Headers/pit-MKL.h)
 *
 * @brief    Programmable Interrupt Timer interface
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */

#ifndef INCLUDE_USBDM_PIT_H_
#define INCLUDE_USBDM_PIT_H_
/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include "derivative.h"
#include "system.h"
#include "hardware.h"

namespace USBDM {

enum DmaChannelNum : unsigned;

/**
 * @addtogroup PIT_Group PIT, Programmable Interrupt Timer
 * @brief Abstraction for Programmable Interrupt Timer
 * @{
 */
/**
 * Type definition for PIT interrupt call back
 */
typedef void (*PitCallbackFunction)(void);

/**
 * Control PIT operation in debug mode (suspended for debugging)
 */
enum PitDebugMode {
   PitDebugMode_Run  = PIT_MCR_FRZ(0),  //!< PIT continues to run in debug mode
   PitDebugMode_Stop = PIT_MCR_FRZ(1),  //!< PIT stops in debug mode
};

/**
 * Enable the PIT interrupts
 */
enum PitChannelIrq {
   PitChannelIrq_Disabled  = PIT_TCTRL_TIE(0),  //!< PIT channel interrupt disabled
   PitChannelIrq_Enabled   = PIT_TCTRL_TIE(1),  //!< PIT channel interrupt disabled
};

/**
 * Enable the PIT channel
 */
enum PitChannelEnable {
   PitChannelEnable_Disabled  = PIT_TCTRL_TEN(0),  //!< PIT channel disabled
   PitChannelEnable_Enabled   = PIT_TCTRL_TEN(1),  //!< PIT channel enabled
};

/**
 * Channel numbers.
 */
enum PitChannelNum : unsigned {
   PitChannelNum_0,      //!< Channel  0
   PitChannelNum_1,      //!< Channel  1
   PitChannelNum_2,      //!< Channel  2
   PitChannelNum_3,      //!< Channel  3

   PitChannelNum_None = (1<<7),  //!< Used to indicate failed channel allocation
};

/**
 * Calculate a PIT channel number using an offset from an existing number
 *
 * @param channel Base channel to use
 * @param offset  Offset from base channel
 *
 * @return  PIT channel number calculated from channel+offset
 */
constexpr PitChannelNum inline operator+(PitChannelNum channel, unsigned offset) {
   return (PitChannelNum)((unsigned)channel + offset);
}

/**
 * Calculate a PIT channel number using an offset from an existing number
 *
 * @param channel Base channel to use
 * @param offset  Offset from base channel
 *
 * @return  PIT channel number calculated from channel+offset
 */
constexpr PitChannelNum inline operator+(PitChannelNum channel, int offset) {
   return channel + (unsigned)offset;
}

/**
 * @brief Class representing a Programmable Interrupt  Timer
 *
 * <b>Example</b>
 * @code
 *
 * @endcode
 */
template<class Info>
class PitBase_T {

private:
   /**
    * This class is not intended to be instantiated
    */
   PitBase_T() = delete;
   PitBase_T(const PitBase_T&) = delete;
   PitBase_T(PitBase_T&&) = delete;

   /** Bit-mask of allocated channels */
   static uint32_t allocatedChannels;

protected:
   /** Default TCTRL value for timer channel */
   static constexpr uint32_t PIT_TCTRL_DEFAULT_VALUE = (PIT_TCTRL_TEN_MASK);

   /** Callback to catch unhandled interrupt */
   static void unhandledCallback() {
      setAndCheckErrorCode(E_NO_HANDLER);
   }

public:
   /**
    * Allocate PIT channel.
    *
    * @return PitChannelNum_None - No suitable channel available.  Error code set.
    * @return Channel number     - Number of allocated channel
    */
   static PitChannelNum allocateChannel() {
      unsigned channelNum = __builtin_ffs(allocatedChannels);
      if ((channelNum == 0)||(--channelNum>=Info::NumChannels)) {
         setErrorCode(E_NO_RESOURCE);
         return PitChannelNum_None;
      }
      allocatedChannels &= ~(1<<channelNum);
      return (PitChannelNum) channelNum;
   }

   /**
    * Allocate PIT channel associated with DMA channel.
    * This is a channel that may be used to throttle the associated DMA channel.
    *
    * @param dmaChannelNum DMA channel being used.
    *
    * @return PitChannelNum_None - No suitable channel available.  Error code set.
    * @return Channel number     - Number of allocated channel
    */
   static PitChannelNum allocateDmaAssociatedChannel(DmaChannelNum dmaChannelNum) {
      const uint32_t channelMask = (1<<dmaChannelNum);
      usbdm_assert(dmaChannelNum<Info::NumChannels, "No PIT channel associated with DMA channel");
      usbdm_assert((allocatedChannels & channelMask) != 0, "PIT channel already allocated");
      if ((allocatedChannels & channelMask) == 0) {
         setErrorCode(E_NO_RESOURCE);
         return PitChannelNum_None;
      }
      allocatedChannels &= ~channelMask;
      return (PitChannelNum) dmaChannelNum;
   }

   /**
    * Free PIT channel.
    *
    * @param pitChannelNum Channel to release
    */
   static void freeChannel(PitChannelNum pitChannelNum) {
      const uint32_t channelMask = (1<<pitChannelNum);
      usbdm_assert(pitChannelNum<Info::NumChannels, "Illegal PIT channel");
      usbdm_assert((allocatedChannels & channelMask) == 0, "Freeing unallocated PIT channel");
      allocatedChannels |= channelMask;
   }

   /**
    * Enable/disable channel interrupts
    *
    * @param[in]  channel Channel being modified
    * @param[in]  enable  True => enable, False => disable
    */
   static void enableInterrupts(PitChannelNum channel, bool enable=true) {
      if (enable) {
         pit().CHANNEL[channel].TCTRL |= PIT_TCTRL_TIE_MASK;
      }
      else {
         pit().CHANNEL[channel].TCTRL &= ~PIT_TCTRL_TIE_MASK;
      }
   }

   /** PIT interrupt handler -  Calls PIT callback */
   static void irqHandler() {
      for (unsigned channel=0; channel<Info::numChannels; channel++) {
         if (pit().CHANNEL[channel].TFLG & PIT_TFLG_TIF_MASK) {
            // Clear interrupt flag
            pit().CHANNEL[channel].TFLG = PIT_TFLG_TIF_MASK;
            // Do call-back
            sCallbacks[channel]();
         }
      }
   }

   /**
    * Set interrupt callback
    *
    *  @param[in]  channel   Channel to configure
    *  @param[in]  callback  Callback function to be executed on interrupt.\n
    *                        Use nullptr to remove callback.
    */
   static void setCallback(PitChannelNum channel, PitCallbackFunction callback) {
      usbdm_assert(Info::irqHandlerInstalled, "PIT not configure for interrupts");
      if (callback == nullptr) {
         callback = unhandledCallback;
      }
      sCallbacks[channel] = callback;
   }

protected:
   /** Pointer to hardware */
   static __attribute__((always_inline)) volatile PIT_Type &pit()      { return Info::pit(); }

   /** Pointer to clock register */
   static __attribute__((always_inline)) volatile uint32_t &clockReg() { return Info::clockReg(); }

public:
   /**
    * Basic enable of PIT
    */
   static void enable() {
      // Enable clock
      clockReg() |= Info::clockMask;
      __DMB();
   }

   /**
    *  Enable the PIT with default settings.
    *  All channels are enabled with default settings.
    */
   static void defaultConfigure() {
      enable();

      // Enable timer
      pit().MCR = Info::mcr;
      for (unsigned i=0; i<Info::irqCount; i++) {
         configureChannelInTicks(i, Info::pit_ldval);
      }
      enableNvicInterrupts(Info::irqLevel);
   }

   /**
    *  Enables and configures the PIT.
    *  This also clears all channels and channel reservations.
    *
    *  @param[in]  pitDebugMode  Determined whether the PIT halts when suspended during debug
    */
   static void configure(PitDebugMode pitDebugMode=PitDebugMode_Stop) {
      enable();
      for (PitChannelNum channel = PitChannelNum_0; channel < PitInfo::NumChannels; channel = channel+1) {
         disableChannel(channel);
      }
      pit().MCR = pitDebugMode|PIT_MCR_MDIS(0); // MDIS cleared => enabled!
      allocatedChannels = -1;
   }

   /**
    *   Disable the PIT (all channels)
    */
   static void disable() {
      pit().MCR = PIT_MCR_MDIS(1);
      clockReg() &= ~Info::clockMask;
   }

   /**
    * Enable interrupts in NVIC
    * Any pending NVIC interrupts are first cleared.
    */
   static void enableNvicInterrupts() {
      enableNvicInterrupt(irqNums[0]);
   }

   /**
    * Enable and set priority of interrupts in NVIC
    * Any pending NVIC interrupts are first cleared.
    *
    * @param[in]  nvicPriority  Interrupt priority
    */
   static void enableNvicInterrupts(uint32_t nvicPriority) {
      enableNvicInterrupt(irqNums[0], nvicPriority);
   }

   /**
    * Disable interrupts in NVIC
    */
   static void disableNvicInterrupts() {
      NVIC_DisableIRQ(irqNums[0]);
   }
   
   /**
    *  Enable the PIT channel
    *
    *  @param[in]  channel   Channel to enable
    */
   static void enableChannel(const PitChannelNum channel) {
      pit().CHANNEL[channel].TCTRL |= PIT_TCTRL_TEN_MASK;
   }

   /**
    *   Disable the PIT channel
    *
    *   @param[in]  channel Channel to disable
    */
   static void disableChannel(PitChannelNum channel) {

      // Disable timer channel
      pit().CHANNEL[channel].TCTRL &= ~PIT_TCTRL_TEN_MASK;
   }

   /**
    *  Configure the PIT channel
    *
    *  @param[in]  channel           Channel to configure
    *  @param[in]  tickInterval      Interval in timer ticks (usually bus clock period)
    *  @param[in]  pitChannelIrq     Whether to enable interrupts
    *
    *  @note The timer channel is disabled before configuring so that period changes have
    *        immediate effect.
    */
   static void configureChannelInTicks(
         PitChannelNum     channel,
         uint32_t          tickInterval,
         PitChannelIrq     pitChannelIrq=PitChannelIrq_Disabled) {

      usbdm_assert(tickInterval>0, "Interval too short");

      pit().CHANNEL[channel].TCTRL = 0;
      pit().CHANNEL[channel].LDVAL = tickInterval-1;
      pit().CHANNEL[channel].TFLG  = PIT_TFLG_TIF_MASK;
      pit().CHANNEL[channel].TCTRL = pitChannelIrq|PIT_TCTRL_TEN(1);
   }

   /**
    *  Configure the PIT channel
    *
    *  @param[in]  channel           Channel to configure
    *  @param[in]  intervalInSeconds Interval in seconds
    *  @param[in]  pitChannelIrq     Whether to enable interrupts
    *
    *  @note The timer channel is disabled before configuring so that period changes have
    *        immediate effect.
    */
   static void configureChannel(
         PitChannelNum     channel,
         float             intervalInSeconds,
         PitChannelIrq     pitChannelIrq=PitChannelIrq_Disabled) {

      configureChannelInTicks(channel, convertSecondsToTicks(intervalInSeconds), pitChannelIrq);
   }

   /**
    * Convert time in ticks to time in seconds
    *
    * @param[in] timeInTicks Time interval in ticks
    *
    * @return Time interval in seconds
    */
   static float convertTicksToSeconds(uint32_t timeInTicks) {
      return ((float)timeInTicks)/Info::getClockFrequency();
   }

   /**
    * Converts time in seconds to time in ticks
    *
    * @param[in] seconds Time interval in seconds
    *
    * @return Time interval in ticks
    *
    * @note Will set error code if calculated value is unsuitable
    */
   static int convertSecondsToTicks(float seconds) {
      float intervalInTicks = rintf(seconds*Info::getClockFrequency());
      usbdm_assert(intervalInTicks <= 0xFFFFFFFFUL, "Interval is too long");
      usbdm_assert(intervalInTicks > 0, "Interval is too short");
      if (intervalInTicks > 0xFFFFFFFFUL) {
         setErrorCode(E_TOO_LARGE);
      }
      if (intervalInTicks <= 0) {
         setErrorCode(E_TOO_SMALL);
      }
      return rintf((uint32_t)intervalInTicks);
   }

   /**
    * Set period in seconds
    *
    * @param[in]  channel Channel being modified
    * @param[in]  interval Interval in ticks
    *
    * @note If the timer is currently enabled this value will be loaded on the next expiration.
    *       To have immediate effect it is necessary to use configureChannel().
    */
   static void setPeriodInTicks(PitChannelNum channel, uint32_t interval) {
      pit().CHANNEL[channel].LDVAL = interval-1;
   }

   /**
    * Set period in seconds
    *
    * @param[in]  channel Channel being modified
    * @param[in]  interval Interval in seconds
    *
    * @note If the timer is currently enabled this value will be loaded on the next expiration.
    *       To have immediate effect it is necessary to use configureChannel().
    */
   static void setPeriod(PitChannelNum channel, float interval) {
      setPeriodInTicks(channel, rintf(interval*Info::getClockFrequency()));
   }

   /**
    *  Use a PIT channel to implement a busy-wait delay
    *
    *  @param[in]  channel   Channel to use
    *  @param[in]  interval  Interval to wait in timer ticks (usually bus clock period)
    *
    *  @note Function doesn't return until interval has expired
    */
   static void delayInTicks(PitChannelNum channel, uint32_t interval) {
      configureChannelInTicks(channel, interval);
      while (pit().CHANNEL[channel].TFLG == 0) {
         __NOP();
      }
      disableChannel(channel);
   }

   /**
    *  Use a PIT channel to implement a busy-wait delay
    *
    *  @param[in]  channel   Channel to use
    *  @param[in]  interval  Interval to wait as a float
    *
    *  @note Function doesn't return until interval has expired
    */
   static void delay(PitChannelNum channel, float interval) {
      configureChannel(channel, interval);
      while (pit().CHANNEL[channel].TFLG == 0) {
         __NOP();
      }
      disableChannel(channel);
   }

protected:
   /** Callback functions for ISRs */
   static PitCallbackFunction sCallbacks[Info::NumChannels];

   /**
    * Class representing a PIT channel
    *
    * @tparam channel Timer channel number
    */
   template <int channel>
   class Channel {

   public:
      /** Timer channel number */
      static constexpr PitChannelNum CHANNEL = (PitChannelNum)channel;

      /**
       * Set interrupt callback
       *
       * @param[in]  callbackFunction  Function to call from stub ISR
       */
      static void setCallback(PitCallbackFunction callbackFunction) {
         PitBase_T<Info>::setCallback(CHANNEL, callbackFunction);
      }

      /** PIT interrupt handler - Calls PIT callback */
      static void irqHandler() {
         // Clear interrupt flag
         PitBase_T<Info>::pit().CHANNEL[channel].TFLG = PIT_TFLG_TIF_MASK;
         sCallbacks[channel]();
      }

      /**
       *  Configure the PIT channel
       *
       *  @param[in]  interval          Interval in timer ticks (usually bus clock)
       *  @param[in]  pitChannelIrq     Whether to enable interrupts
       *
       *  @note The timer channel is disabled before configuring so that period changes
       *        have immediate effect.
       */
      static void __attribute__((always_inline)) configureInTicks(
            uint32_t          interval,
            PitChannelIrq     pitChannelIrq=PitChannelIrq_Disabled) {

         PitBase_T<Info>::configureChannelInTicks(CHANNEL, interval, pitChannelIrq);
      }

      /**
       *  Configure the PIT channel
       *
       *  @param[in]  interval          Interval in seconds
       *  @param[in]  pitChannelIrq     Whether to enable interrupts
       *
       *  @note The timer channel is disabled before configuring so that period changes
       *        have immediate effect.
       */
      static void __attribute__((always_inline)) configure(
            float             interval,
            PitChannelIrq     pitChannelIrq=PitChannelIrq_Disabled) {

         PitBase_T<Info>::configureChannel(CHANNEL, interval, pitChannelIrq);
      }

      /**
       * Set period in seconds
       *
       * @param[in]  interval Interval in seconds
       *
       * @note If the timer is currently enabled this value will be loaded on the next expiration.
       *       To have immediate effect it is necessary to use configure().
       */
      static void __attribute__((always_inline)) setPeriod(float interval) {
         PitBase_T<Info>::setPeriod(CHANNEL, interval);
      }

      /**
       * Set period in ticks
       *
       * @param[in]  interval Interval in ticks
       *
       * @note If the timer is currently enabled this value will be loaded on the next expiration.
       *       To have immediate effect it is necessary to use configure().
       */
      static void __attribute__((always_inline)) setPeriodInTicks(uint32_t interval) {
         PitBase_T<Info>::setPeriodInTicks(CHANNEL, interval);
      }

      /**
       *   Enable the PIT channel
       */
      static void __attribute__((always_inline)) enable() {
         PitBase_T<Info>::enableChannel(CHANNEL);
      }

      /**
       *   Disable the PIT channel
       */
      static void __attribute__((always_inline)) disable() {
         PitBase_T<Info>::disableChannel(CHANNEL);
      }

      /**
       * Enable/disable channel interrupts.
       *
       * @param[in]  enable  True => enable, False => disable
       *
       * @note It is also necessary to modify NVIC using enableNvicInterrupts().
       */
      static void __attribute__((always_inline)) enableInterrupts(bool enable=true) {
         PitBase_T<Info>::enableInterrupts(CHANNEL, enable);
      }

      /**
       *  Use a PIT channel to implement a busy-wait delay
       *
       *  @param[in]  interval  Interval to wait in timer ticks (usually bus clock period)
       *
       *  @note Function doesn't return until interval has expired
       */
      static void __attribute__((always_inline)) delayInTicks(uint32_t interval) {
         PitBase_T<Info>::delayInTicks(CHANNEL, interval);
      }

      /**
       *  Use a PIT channel to implement a busy-wait delay
       *
       *  @param[in]  interval  Interval to wait as a float
       *
       *  @note Function doesn't return until interval has expired
       */
      static void __attribute__((always_inline)) delay(float interval) {
         PitBase_T<Info>::delay(CHANNEL, interval);
      }
   };
};

/** Bit-mask of allocated channels */
template<class Info> uint32_t PitBase_T<Info>::allocatedChannels = -1;

/**
 * Callback table for programmatically set handlers
 */
template<class Info>
PitCallbackFunction PitBase_T<Info>::sCallbacks[] = {
      PitBase_T<Info>::unhandledCallback,
      PitBase_T<Info>::unhandledCallback,
};

#ifdef PIT
/**
 * @brief class representing the PIT
 */
using Pit = PitBase_T<PitInfo>;

/**
 * @brief Class representing a PIT channel
 *
 * @tparam channel Channel number
 */
template <int channel>
using PitChannel = Pit::Channel<channel>;

#endif

/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_USBDM_PIT_H_ */
