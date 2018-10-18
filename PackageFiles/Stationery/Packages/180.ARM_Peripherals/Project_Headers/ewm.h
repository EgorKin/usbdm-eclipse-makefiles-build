/**
 * @file     ewm.h (180.ARM_Peripherals/Project_Headers/ewm.h)
 * @brief    External Watchdog Monitor
 *
 * @version  V4.12.1.230
 * @date     13 April 2016
 */

#ifndef HEADER_EWM_H_
#define HEADER_EWM_H_
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
 * @addtogroup EWM_Group EWM, External Watchdog Monitor
 * @brief Abstraction for External Watchdog Monitor
 * @{
 */

/**
 *  Enables and selects polarity of EWM hardware input
 */
enum EwmInput {
   EwmInput_Disabled    = EWM_CTRL_INEN(0)|EWM_CTRL_ASSIN(0), //!< EWM_in Pin disabled
   EwmInput_ActiveLow   = EWM_CTRL_INEN(1)|EWM_CTRL_ASSIN(0), //!< EWM_in Pin activeLow
   EwmInput_ActiveHighe = EWM_CTRL_INEN(1)|EWM_CTRL_ASSIN(1), //!< EWM_in Pin activeHigh
};

/**
 * Controls EWM Interrupts
 */
enum EwmInterrupt {
   EwmInterrupt_Disabled = EWM_CTRL_INTEN(0), //!< Interrupts disabled
   EwmInterrupt_Enabled  = EWM_CTRL_INTEN(1), //!< Interrupts enabled
};

/** Watchdog key value 1 */
static constexpr uint8_t EwmKey1 = 0xB4;

/** Watchdog key value 2 */
static constexpr uint8_t EwmKey2 = 0x2C;

/**
 * Type definition for EWM interrupt call back
 *
 * @param[in]  status Struct indicating interrupt source and state
 */
typedef void (*EWMCallbackFunction)();

/**
 * Template class representing the External Watchdog Monitor
 *
 * External Watchdog Monitor (EWM), is designed to monitor external circuits, as well as the MCU software flow.
 * This provides a back-up mechanism to the internal watchdog that resets the MCU's CPU and peripherals.
 *
 * @tparam info      Information class for EWM
 */
template<class Info>
class EwmBase_T {

protected:
   /**
    * Callback to catch unhandled interrupt
    */
   static void unhandledCallback() {
      setAndCheckErrorCode(E_NO_HANDLER);
   }

   /** Callback function for ISR */
   static EWMCallbackFunction callback;

   /**
    * Clock register for peripheral
    *
    * @return Reference to clock register
    */
   static __attribute__((always_inline)) volatile uint32_t &clockReg() { return Info::clockReg(); }

public:
   /**
    * Hardware instance pointer
    *
    * @return Reference to EWM hardware
    */
   static __attribute__((always_inline)) volatile EWM_Type &ewm() { return Info::ewm(); }

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
   static void setCallback(EWMCallbackFunction theCallback) {
      if (theCallback == nullptr) {
         theCallback = unhandledCallback;
      }
      callback = theCallback;
   }

public:
   /**
    * Configures all mapped pins associated with this peripheral
    */
   static void __attribute__((always_inline)) configureAllPins() {
      // Configure pins
      Info::initPCRs();
   }

   /**
    * Basic enable EWM.
    *
    * Includes enabling clock and configuring all pins of mapPinsOnEnable is selected on configuration
    */
   static void enable() {
      if (Info::mapPinsOnEnable) {
         configureAllPins();
      }

      // Enable clock to CMP interface
      clockReg() |= Info::clockMask;
   }

   /**
    * Select watchdog window in LPO cycles.
    *
    * @param minimum The watchdog must be refreshed after this time
    * @param maximum The watchdog must be refreshed before this time
    *
    * @note This is a write-once operation.
    */
   static void setWindow(uint8_t minimum, uint8_t maximum) {
      usbdm_assert(minimum<maximum, "Minimum must be < maximum");

      ewm().CMPL = minimum;
      ewm().CMPH = maximum;
   }

   /**
    * Enable with default settings.
    * Includes configuring all pins
    */
   static void defaultConfigure() {
      enable();
      // Initialise hardware
   }

   /**
    * Write key values to service register.
    * The EWM service mechanism requires the CPU to write two values to the SERV register:
    * - a first data byte of 0xB4 (EwmKey1), followed by
    * - a second data byte of 0x2C (EwmKey2).
    *
    * The EWM service is illegal if either of the following conditions is true.
    * - The first or second data byte is not written correctly.
    * - The second data byte is not written within a fixed number of peripheral bus cycles of the first data byte.
    *   This fixed number of cycles is called EWM_service_time.
    *
    * @param ewmKey1 Key1 value to write (EwmKey1)
    * @param ewmKey2 Key2 value to write (EwmKey2)
    */
   static void writeKeys(uint8_t ewmKey1, uint8_t ewmKey2) {
      ewm().SERV = ewmKey1;
      ewm().SERV = ewmKey2;
   }

   /**
    * Enable EWM_in pin as input and connected to EWM.
    * Configures all Pin Control Register (PCR) values.
    */
   static void setInput(PcrValue pcrValue) {
      constexpr int PinNum = 0;
      using Pcr = PcrTable_T<Info, PinNum>;
      Pcr::setPCR((pcrValue&~PORT_PCR_MUX_MASK)|(Info::info[PinNum].pcrValue&PORT_PCR_MUX_MASK));
   }

   /**
    * Enable EWM_in pin as input and connected to EWM.
    * Configures all Pin Control Register (PCR) values.
    *
    * @param[in] pinPull          One of PinPull_None, PinPull_Up, PinPull_Down
    * @param[in] pinAction        One of PinAction_None, etc (defaults to PinAction_None)
    * @param[in] pinFilter        One of PinFilter_None, PinFilter_Passive (defaults to PinFilter_None)
    */
   static void setInput(
         PinPull           pinPull,
         PinAction         pinAction         = PinAction_None,
         PinFilter         pinFilter         = PinFilter_None
         ) {
      setInput(pinPull|pinAction|pinFilter);
   }

   /**
    * Enable EWM_out pin as output and connected to EWM.
    * Configures all Pin Control Register (PCR) values.
    *
    * @param[in] pcrValue PCR value to use in configuring port (excluding MUX value). See pcrValue()
    */
   static void setOutput(PcrValue pcrValue) {
      constexpr int PinNum = 1;
      using Pcr = PcrTable_T<Info, PinNum>;

      // Enable and map pin to CMP_OUT
      Pcr::setPCR((pcrValue&~PORT_PCR_MUX_MASK)|(Info::info[PinNum].pcrValue&PORT_PCR_MUX_MASK));
   }

   /**
    * Enable EWM_out pin as output and connected to EWM.
    * Configures all Pin Control Register (PCR) values.
    *
    * @param[in] pinDriveStrength One of PinDriveStrength_Low, PinDriveStrength_High
    * @param[in] pinDriveMode     One of PinDriveMode_PushPull, PinDriveMode_OpenDrain (defaults to PinPushPull)
    * @param[in] pinSlewRate      One of PinSlewRate_Slow, PinSlewRate_Fast (defaults to PinSlewRate_Fast)
    */
   static void setOutput(
         PinDriveStrength  pinDriveStrength,
         PinDriveMode      pinDriveMode      = PinDriveMode_PushPull,
         PinSlewRate       pinSlewRate       = PinSlewRate_Fast
         ) {
      setOutput(pinDriveStrength|pinDriveMode|pinSlewRate);
   }

   /**
    * Base configuration of EWM.
    *
    * @param ewmInput      Enables and selects polarity of EWM hardware input
    *
    * @note This is a write-once operation
    */
   static void configure(EwmInput  ewmInput) {
      enable();
      ewm().CTRL = EWM_CTRL_EWMEN(1)|ewmInput;
   }

   /**
    * Disable interface to EWM
    */
   static void disable() {
      clockReg() &= ~Info::clockMask;
   }

   /**
    * Enable/disable interrupts in NVIC
    *
    * @param[in]  enable        True => enable, False => disable
    * @param[in]  nvicPriority  Interrupt priority
    */
   static void enableNvicInterrupts(bool enable=true, uint32_t nvicPriority=NvicPriority_Normal) {

      if (enable) {
         enableNvicInterrupt(Info::irqNums[0], nvicPriority);
      }
      else {
         // Disable interrupts
         NVIC_DisableIRQ(Info::irqNums[0]);
      }
   }

   /**
    * Enable/disable interrupts
    *
    * @param[in]  enable        True => enable, False => disable
    */
   static void enableInterrupt(bool enable=true) {
      if (enable) {
         ewm().CTRL |= EWM_CTRL_INTEN_MASK;
      }
      else {
         ewm().CTRL &= ~EWM_CTRL_INTEN_MASK;
      }
   }
};

template<class Info> EWMCallbackFunction EwmBase_T<Info>::callback = EwmBase_T<Info>::unhandledCallback;

#if defined(USBDM_EWM_IS_DEFINED)
class Ewm : public EwmBase_T<EwmInfo> {};
#endif

/**
 * End EWM_Group
 * @}
 */
} // End namespace USBDM

#endif /* HEADER_EWM_H_ */
