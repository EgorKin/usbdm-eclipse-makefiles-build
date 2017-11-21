/**
 * @file     gpio.h (180.ARM_Peripherals/Project_Headers/gpio-MKV.h)
 * @brief    General Purpose Input/Output
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */

#ifndef HEADER_GPIO_H
#define HEADER_GPIO_H

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
#ifdef RELEASE_BUILD
#include "bitband.h"
#endif

/*
 * Default port information
 */
#ifndef FIXED_PORT_CLOCK_REG
#define FIXED_PORT_CLOCK_REG SCGC5
#endif

namespace USBDM {

/**
 * @addtogroup GPIO_Group GPIO, Digital Input/Output
 * @brief General Purpose Input/Output
 * @{
 */

/**
 * @brief Template representing a pin with Digital I/O capability
 *
 * <b>Example</b>
 * @code
 * // Instantiate
 * using Pta3 = USBDM::Gpio_T<SIM_SCGC5_PORTA_MASK, PORTA_BasePtr, GPIOA_BasePtr, 3>;
 *
 * // Set as digital output
 * Pta3::setOutput();
 *
 * // Set pin high
 * Pta3::set();
 *
 * // Set pin low
 * Pta3::clear();
 *
 * // Toggle pin
 * Pta3::toggle();
 *
 * // Set pin to boolean value
 * Pta3::write(true);
 *
 * // Set pin to boolean value
 * Pta3::write(false);
 *
 * // Set as digital input
 * Pta3::setInput();
 *
 * // Read pin as boolean value
 * bool x = Pta3::read();
 *
 * @endcode
 *
 * @tparam clockMask       Clock mask for PORT (PCR register) associated with GPIO
 * @tparam portAddress     Address of PORT (PCR register array) associated with GPIO
 * @tparam gpioAddress     GPIO hardware address
 * @tparam bitNum          Bit number within PORT/GPIO
 * @tparam polarity        Polarity of pin. Either ActiveHigh or ActiveLow
 */
template<uint32_t clockMask, uint32_t portAddress, IRQn_Type irqNum, uint32_t gpioAddress, int bitNum, Polarity polarity>
class GpioBase_T {

private:
   /**
    * This class is not intended to be instantiated
    */
   GpioBase_T() = delete;
   GpioBase_T(const GpioBase_T&) = delete;
   GpioBase_T(GpioBase_T&&) = delete;

public:
   /** PCR associated with this GPIO pin */
   using Pcr = Pcr_T<clockMask, portAddress, irqNum, bitNum, GPIO_DEFAULT_PCR>;

   /** GPIO associated with this pin */
   static constexpr volatile GPIO_Type *gpio = reinterpret_cast<volatile GPIO_Type *>(gpioAddress);

   /** Bit number of accessed bit in port */
   static constexpr int BITNUM = bitNum;

   /** Mask for bit within port */
   static constexpr uint32_t MASK   = (1<<bitNum);

   /**
    * Set pin as digital I/O.
    * Pin is initially set as an input.
    * Use SetIn() and SetOut() to change direction.
    *
    * @note Resets the Pin Control Register value (PCR value).
    * @note Resets the pin output value to the inactive state
    *
    * @param[in] pcrValue PCR value to use in configuring pin (excluding MUX value). See pcrValue()
    */
   static void setInOut(PcrValue pcrValue=GPIO_DEFAULT_PCR) {
      // Make input initially
      setIn();
      // Set inactive pin state (if later made output)
      setInactive();
      Pcr::setPCR((pcrValue&~PORT_PCR_MUX_MASK)|PinMux_Gpio);
   }
   /**
    * Set pin as digital I/O.
    * Pin is initially set as an input.
    * Use SetIn() and SetOut() to change direction.
    * If open-drain then input function may meaningfully be used while set as output
    *
    * @note Resets the Pin Control Register value (PCR value).
    * @note Resets the pin output value to the inactive state
    *
    * @param[in] pinPull          One of PinPull_None, PinPull_Up, PinPull_Down
    * @param[in] pinDriveStrength One of PinDriveStrength_Low, PinDriveStrength_High (defaults to PinDriveLow)
    * @param[in] pinDriveMode     One of PinDriveMode_PushPull, PinDriveMode_OpenDrain (defaults to PinPushPull)
    * @param[in] pinIrq           One of PinIrq_None, etc (defaults to PinIrq_None)
    * @param[in] pinFilter        One of PinFilter_None, PinFilter_Passive (defaults to PinFilter_None)
    * @param[in] pinSlewRate      One of PinSlewRate_Slow, PinSlewRate_Fast (defaults to PinSlewRate_Fast)
    */
   static void setInOut(
         PinPull           pinPull,
         PinDriveStrength  pinDriveStrength  = PinDriveStrength_Low,
         PinDriveMode      pinDriveMode      = PinDriveMode_PushPull,
         PinIrq            pinIrq            = PinIrq_None,
         PinFilter         pinFilter         = PinFilter_None,
         PinSlewRate       pinSlewRate       = PinSlewRate_Fast
         ) {
      setInOut(pinPull|pinDriveStrength|pinDriveMode|pinIrq|pinFilter|pinSlewRate|PinMux_Gpio);
   }
   /**
    * Set pin as digital output
    *
    * @note Does not affect other pin settings
    */
   static void setOut() {
      // Make pin an output
#ifdef RELEASE_BUILD
      bitbandSet(gpio->PDDR, bitNum);
#else
      gpio->PDDR |= MASK;
#endif
   }
   /**
    * Enable pin as digital output with initial inactive level.\n
    * Configures all Pin Control Register (PCR) values
    *
    * @note Resets the Pin Control Register value (PCR value).
    * @note Resets the pin value to the inactive state
    * @note Use setOut() for a lightweight change of direction without affecting other pin settings.
    *
    * @param[in] pcrValue PCR value to use in configuring port (excluding MUX value). See pcrValue()
    */
   static void setOutput(PcrValue pcrValue=GPIO_DEFAULT_PCR) {
      // Set initial level before enabling pin drive
      setInactive();
      // Make pin an output
      setOut();
      // Configure pin
      Pcr::setPCR((pcrValue&~PORT_PCR_MUX_MASK)|PinMux_Gpio);
   }
   /**
    * @brief
    * Enable pin as digital output with initial inactive level.\n
    * Configures all Pin Control Register (PCR) values
    *
    * @note Resets the Pin Control Register value (PCR value).
    * @note Resets the pin value to the inactive state
    * @note Use setOut() for a lightweight change of direction without affecting other pin settings.
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
    * Set pin as digital input
    *
    * @note Does not affect other pin settings
    */
   static void setIn() {
      // Make pin an input
#ifdef RELEASE_BUILD
      bitbandClear(gpio->PDDR, bitNum);
#else
      gpio->PDDR &= ~MASK;
#endif
   }
   /**
    * @brief
    * Enable pin as digital input.\n
    * Configures all Pin Control Register (PCR) values
    *
    * @note Resets the Pin Control Register value (PCR value).
    * @note Use setIn() for a lightweight change of direction without affecting other pin settings.
    *
    * @param[in] pcrValue PCR value to use in configuring port (excluding MUX value)
    */
   static void setInput(PcrValue pcrValue=GPIO_DEFAULT_PCR) {
      // Make pin an input
      setIn();
      Pcr::setPCR((pcrValue&~PORT_PCR_MUX_MASK)|PinMux_Gpio);
   }
   /**
    * @brief
    * Enable pin as digital input.\n
    * Configures all Pin Control Register (PCR) values
    *
    * @note Reset the Pin Control Register value (PCR value).
    * @note Use setIn() for a lightweight change of direction without affecting other pin settings.
    *
    * @param[in] pinPull          One of PinPull_None, PinPull_Up, PinPull_Down
    * @param[in] pinIrq           One of PinIrq_None, etc (defaults to PinIrq_None)
    * @param[in] pinFilter        One of PinFilter_None, PinFilter_Passive (defaults to PinFilter_None)
    */
   static void setInput(
         PinPull           pinPull,
         PinIrq            pinIrq            = PinIrq_None,
         PinFilter         pinFilter         = PinFilter_None
         ) {
      setInput(pinPull|pinIrq|pinFilter|PinMux_Gpio);
   }
   /**
    * Set pin. Pin will be high if configured as an output.
    *
    * @note Polarity _is_ _not_ significant
    * @note Don't use this method unless dealing with very low-level I/O
    */
   static void high() {
      gpio->PSOR = MASK;
   }
   /**
    * Clear pin. Pin will be low if configured as an output.
    *
    * @note Polarity _is_ _not_ significant
    * @note Don't use this method unless dealing with very low-level I/O
    */
   static void low() {
      gpio->PCOR = MASK;
   }
   /**
    * Set pin. Pin will be high if configured as an output.
    *
    * @note Polarity _is_ _not_ significant
    * @note Don't use this method unless dealing with very low-level I/O
    */
   static void set() {
	   gpio->PSOR = MASK;
   }
   /**
    * Clear pin. Pin will be low if configured as an output.
    *
    * @note Polarity _is_ _not_ significant
    * @note Don't use this method unless dealing with very low-level I/O
    */
   static void clear() {
	   gpio->PCOR = MASK;
   }
   /**
    * Toggle pin (if output)
    */
   static void toggle() {
      gpio->PTOR = MASK;
   }
   /**
    * Set pin to active level (if configured as output)
    *
    * @note Polarity _is_ significant
    */
   static void setActive() {
      if (polarity) {
         set();
      }
      else {
         clear();
      }
   }
   /**
    * Set pin to inactive level (if configured as output)
    *
    * @note Polarity _is_ significant
    */
   static void setInactive() {
      if (polarity) {
         clear();
      }
      else {
         set();
      }
   }
   /**
    * Set pin to active level (if configured as output).
    * Convenience method for setActive()
    *
    * @note Polarity _is_ significant
    */
   static void __attribute__((always_inline)) on() {
      setActive();
   }
   /**
    * Set pin to inactive level (if configured as output).
    * Convenience method for setInactive()
    *
    * @note Polarity _is_ significant
    */
   static void __attribute__((always_inline)) off() {
      setInactive();
   }
   /**
    * Write boolean value to pin (if configured as output)
    *
    * @param[in] value true/false value
    *
    * @note Polarity _is_ significant
    */
   static void write(bool value) {
#ifdef RELEASE_BUILD
      if (polarity) {
         bitbandWrite(gpio->PDOR, bitNum, value);
      }
      else {
         bitbandWrite(gpio->PDOR, bitNum, !value);
      }
#else
      if (value) {
         setActive();
      }
      else {
         setInactive();
      }
#endif
   }
   /**
    * Checks if pin is high
    *
    * @return true/false reflecting value on pin
    *
    * @note This reads the PDIR
    * @note Polarity _is_ _not_ significant
    */
   static bool isHigh() {
      return (gpio->PDIR & MASK) != 0;
   }
   /**
    * Checks if pin is low
    *
    * @return true/false reflecting value on pin
    *
    * @note This reads the PDIR
    * @note Polarity _is_ _not_ significant
    */
   static bool isLow() {
      return (gpio->PDIR & MASK) == 0;
   }
   /**
    * Read pin value
    *
    * @return true/false reflecting pin value.
    *
    * @note This reads the PDIR
    * @note Polarity _is_ significant
    */
   static bool read() {
      if (polarity) {
         return isHigh();
      }
      else {
         return isLow();
      }
   }
   /**
    * Read pin value and return true if active level.
    * Equivalent to read()
    *
    * @return true/false reflecting if pin is active.
    *
    * @note This reads the PDIR
    * @note Polarity _is_ significant
    */
   static bool __attribute__((always_inline)) isActive() {
      return read();
   }
   /**
    * Read pin value and return true if inactive level
    * Equivalent to !read()
    *
    * @return true/false reflecting if pin is inactive.
    *
    * @note This reads the PDIR
    * @note Polarity _is_ significant
    */
   static bool __attribute__((always_inline)) isInactive() {
      return !read();
   }
   /**
    * Read pin value and return true if active level.\n
    * Convenience method equivalent to isActive()
    *
    * @return true/false reflecting if pin is active.
    *
    * @note This reads the PDIR
    * @note Polarity _is_ significant
    */
   static bool __attribute__((always_inline)) isPressed() {
      return isActive();
   }
   /**
    * Read pin value and return true if inactive level.\n
    * Convenience method equivalent to isInactive()
    *
    * @return true/false reflecting if pin is inactive.
    *
    * @note This reads the PDIR
    * @note Polarity _is_ significant
    */
   static bool __attribute__((always_inline)) isReleased() {
      return isInactive();
   }
   /**
    * Read value being driven to pin (if configured as output)
    *
    * @return true/false reflecting value in output register.
    *
    * @note This reads the PDOR
    * @note Polarity _is_ significant
    */
   static bool readState() {
      uint32_t t = gpio->PDOR & MASK;
      if (polarity) {
         return t;
      }
      else {
         return !t;
      }
   }
   /**
    * Sets pin interrupt mode
    *
    * @param[in] pinIrq Interrupt/DMA mode
    */
   static void setIrq(PinIrq pinIrq) {
      Pcr::setIrq(pinIrq);
   }

   /**
    * Clear interrupt flag for pin
    */
   static void clearInterruptFlag() {
      Pcr::clearInterruptFlag();
   }

   /**
    * Set pull device on pin
    *
    * @param[in] pinPull Pin pull control value (PinPull_None, PinPull_Up, PinPull_Down)
    */
   static void setPullDevice(PinPull pinPull) {
      Pcr::setPullDevice(pinPull);
   }

   /**
    * Set drive strength on pin
    *
    *  @param[in] pinDriveStrength Pin drive strength to set (PinDriveLow, PinDriveHigh)
    */
   static void setDriveStrength(PinDriveStrength pinDriveStrength) {
      Pcr::setDriveStrength(pinDriveStrength);
   }

   /**
    * Set drive mode on pin
    *
    *  @param[in] pinDriveMode Pin drive mode (PinPushPull, PinOpenDrain)
    */
   static void setDriveMode(PinDriveMode pinDriveMode) {
      Pcr::setDriveMode(pinDriveMode);
   }

   /**
    * Set slew rate on pin
    *
    *  @param[in] pinSlewRate Slew rate. Either PinSlewRate_Slow or PinSlewRate_Fast
    */
   static void setSlewRate(PinSlewRate  pinSlewRate) {
      Pcr::setSlewRate(pinSlewRate);
   }

   /**
    * Set filter on pin
    *
    *  @param[in] pinFilter Pin filter option. Either PinFilter_None or PinFilter_Passive
    */
   static void setFilter(PinFilter pinFilter) {
      Pcr::setFilter(pinFilter);
   }
   /**
    * Locks most of the pin properties e.g. drive strength, pull-device etc.
    * The pin properties remains locked until the next reset
    */
   static void lock() {
      Pcr::lock();
   }

#ifdef PORT_DFCR_CS_MASK
   /**
    * Configures Digital Pin Filter
    * Convenience wrapper for PCR function
    *
    * @param pinDigitalFilterClock  Clock source
    * @param filterLength           Filter length in clock ticks
    *
    * @note Not all ports support this feature
    * @note This affects the digital filter for all pins of this port
    */
   static void configureDigitalFilter(PinDigitalFilterClock pinDigitalFilterClock, int filterLength) {
      Pcr::configureDigitalFilter(pinDigitalFilterClock, filterLength);
   }

   /**
    * Enable/disable digital filter on the pin
    * Convenience wrapper for PCR function
    *
    * @param enable  True => enable, False => disable
    *
    * @note Not all ports support this feature
    */
   static void enableDigitalFilter(bool enable) {
      Pcr::enableDigitalFilter(enable);
   }
#endif

   /**
    * Enable/disable pin interrupts.\n
    * Any pending NVIC interrupts are first cleared.
    * Convenience wrapper for PCR function
    *
    * @param[in] enable        True => enable, False => disable
    * @param[in] nvicPriority  Interrupt priority
    */
   static void enableNvicInterrupts(bool enable=true, uint32_t nvicPriority=NvicPriority_Normal) {
      Pcr::enableNvicInterrupts(enable, nvicPriority);
   }

   /**
    * Set callback for ISR
    *
    * @note There is a single callback function for all pins on this port.
    *
    * @param[in] callback The function to call on pin interrupt. \n
    *                     nullptr to indicate none
    */
   static void setCallback(PinCallbackFunction callback) {
      Pcr::setCallback(callback);
   }

};

/**
 * Create GPIO from GpioInfo class
 *
 * @tparam Info          Gpio information class
 * @tparam bitNum        Bit number within PORT/GPIO
 * @tparam polarity      Polarity of pin. Either ActiveHigh or ActiveLow
 */
template<class Info, const int bitNum, Polarity polarity>
class  Gpio_T : public GpioBase_T<Info::pinInfo.clockMask, Info::pinInfo.portAddress, Info::pinInfo.irqNum, Info::pinInfo.gpioAddress, bitNum, polarity> {

   static_assert(((bitNum>=0)&&(bitNum<=31)), "Illegal bit number in Gpio");

public:
   static constexpr bool irqHandlerInstalled = Info::irqHandlerInstalled;
};

/**
 * Create GPIO from Peripheral Info class
 *
 * @tparam Info          Peripheral information class
 * @tparam index         Index of signal within the info table
 * @tparam polarity      Polarity of pin. Either ActiveHigh or ActiveLow
 */
template<class Info, const uint32_t index, Polarity polarity>
using  GpioTable_T = GpioBase_T<Info::info[index].clockMask, Info::info[index].portAddress, Info::info[index].irqNum, Info::info[index].gpioAddress, Info::info[index].gpioBit, polarity>;

/**
 * @brief Template representing a field within a port
 *
 * <b>Example</b>
 * @code
 * // Instantiate object representing Port A 6 down to 3
 * using Pta6_3 = Field_T<GpioAInfo, 6, 3>;
 *
 * // Set as digital output
 * Pta6_3::setOutput();
 *
 * // Write value to field
 * Pta6_3::write(0x53);
 *
 * // Clear all of field
 * Pta6_3::bitClear();
 *
 * // Clear lower two bits of field
 * Pta6_3::bitClear(0x3);
 *
 * // Set lower two bits of field
 * Pta6_3::bitSet(0x3);
 *
 * // Set as digital input
 * Pta6_3::setInput();
 *
 * // Read pin as int value
 * int x = Pta6_3::read();
 * @endcode
 *
 * @tparam Info           Class describing the GPIO and PORT
 * @tparam left           Bit number of leftmost bit in GPIO (inclusive)
 * @tparam right          Bit number of rightmost bit in GPIO (inclusive)
 * @tparam polarity       Polarity of all pins. Either ActiveHigh or ActiveLow
 */
template<class Info, const uint32_t left, const uint32_t right, Polarity polarity=ActiveHigh>
class Field_T {

   static_assert(((left<=31)&&(left>=right)&&(right>=0)), "Illegal bit number for left or right in GpioField");

private:
   static constexpr volatile GPIO_Type *gpio = reinterpret_cast<volatile GPIO_Type *>(Info::pinInfo.gpioAddress);

#ifdef PORT_DFCR_CS_MASK
   static constexpr volatile PORT_DFER_Type *port = reinterpret_cast<volatile PORT_DFER_Type *>(Info::pinInfo.portAddress);
#else
   static constexpr volatile PORT_Type *port = reinterpret_cast<volatile PORT_Type *>(Info::pinInfo.portAddress);
#endif
   /**
    * Mask for the bits being manipulated
    */
   static constexpr uint32_t MASK = ((1<<(left-right+1))-1)<<right;

public:
   /**
    * Utility function to set multiple PCRs using GPCLR & GPCHR
    *
    * @param[in] pcrValue PCR value to use in configuring port (excluding mux fn)
    */
   static void setPCRs(PcrValue pcrValue=GPIO_DEFAULT_PCR) {
      // Enable clock to GPCLR & GPCHR
      enablePortClocks(Info::pinInfo.clockMask);

      // Include the if's as I expect one branch to be removed by optimization unless the field spans the boundary
      if ((MASK&0xFFFFUL) != 0) {
         port->GPCLR = PORT_GPCLR_GPWE(MASK)|(pcrValue&~PORT_PCR_MUX_MASK)|PinMux_Gpio;
      }
      if ((MASK&~0xFFFFUL) != 0) {
         port->GPCHR = PORT_GPCHR_GPWE(MASK>>16)|(pcrValue&~PORT_PCR_MUX_MASK)|PinMux_Gpio;
      }
   }
   /**
    * Utility function to set multiple PCRs using GPCLR & GPCHR
    *
    * @param[in] pinPull          One of PinPull_None, PinPull_Up, PinPull_Down (defaults to PinPull_None)
    * @param[in] pinDriveStrength One of PinDriveStrength_Low, PinDriveStrength_High (defaults to PinDriveLow)
    * @param[in] pinDriveMode     One of PinDriveMode_PushPull, PinDriveMode_OpenDrain (defaults to PinPushPull)
    * @param[in] pinIrq           One of PinIrq_None, etc (defaults to PinIrq_None)
    * @param[in] pinFilter        One of PinFilter_None, PinFilter_Passive (defaults to PinFilter_None)
    * @param[in] pinSlewRate      One of PinSlewRate_Slow, PinSlewRate_Fast (defaults to PinSlewRate_Fast)
    */
   static void setPCRs(
         PinPull           pinPull           = PinPull_None,
         PinDriveStrength  pinDriveStrength  = PinDriveStrength_Low,
         PinDriveMode      pinDriveMode      = PinDriveMode_PushPull,
         PinIrq            pinIrq            = PinIrq_None,
         PinFilter         pinFilter         = PinFilter_None,
         PinSlewRate       pinSlewRate       = PinSlewRate_Fast
         ) {
      setPCRs(pinPull|pinDriveStrength|pinDriveMode|pinIrq|pinFilter|pinSlewRate);
   }
   /**
    * Set all pins as digital outputs.
    *
    * @note Does not affect other pin settings
    */
   static void setOut() {
      gpio->PDDR |= MASK;
   }
   /**
    * Sets all pin as digital outputs\n
    * Configures all Pin Control Register (PCR) values
    *
    * @note This will also reset the Pin Control Register value (PCR value).
    * @note Use setOut() or setDirection() for a lightweight change of direction without affecting other pin settings.
    *
    * @param[in] pcrValue PCR value to use in configuring port (excluding mux fn)
    */
   static void setOutput(PcrValue pcrValue=GPIO_DEFAULT_PCR) {
      setPCRs(pcrValue);
      gpio->PDDR |= MASK;
   }
   /**
    * Sets all pin as digital outputs\n
    * Configures all Pin Control Register (PCR) values
    *
    * @note This will also reset the Pin Control Register value (PCR value).
    * @note Use setOut() or setDirection() for a lightweight change of direction without affecting other pin settings.
    *
    * @param[in] pinDriveStrength One of PinDriveStrength_Low, PinDriveStrength_High (defaults to PinDriveLow)
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
    * Set all pins as digital inputs.
    *
    * @note Does not affect other pin settings
    */
   static void setIn() {
      gpio->PDDR &= ~MASK;
   }
   /**
    * Set all pins as digital inputs\n
	* Configures all Pin Control Register (PCR) values
    *
    * @note This will also reset the Pin Control Register value (PCR value).
    * @note Use setIn() or setDirection() for a lightweight change of direction without affecting other pin settings.
    *
    * @param[in] pcrValue PCR value to use in configuring port (excluding mux fn)
    */
   static void setInput(PcrValue pcrValue=GPIO_DEFAULT_PCR) {
      setPCRs(pcrValue);
      gpio->PDDR &= ~MASK;
   }
   /**
    * Set all pins as digital inputs\n
	* Configures all Pin Control Register (PCR) values
    *
    * @note This will also reset the Pin Control Register value (PCR value).
    * @note Use setIn() or setDirection() for a lightweight change of direction without affecting other pin settings.
    *
    * @param[in] pinPull          One of PinPull_None, PinPull_Up, PinPull_Down (defaults to PinPull_None)
    * @param[in] pinIrq           One of PinIrq_None, etc (defaults to PinIrq_None)
    * @param[in] pinFilter        One of PinFilter_None, PinFilter_Passive (defaults to PinFilter_None)
    */
   static void setInput(
         PinPull           pinPull,
         PinIrq            pinIrq            = PinIrq_None,
         PinFilter         pinFilter         = PinFilter_None
         ) {
      setInput(pinPull|pinIrq|pinFilter);
   }
   /**
    * Set individual pin directions
    *
    * @param[in] mask Mask for pin directions (1=>out, 0=>in)
    */
   static void setDirection(uint32_t mask) {
      gpio->PDDR = (gpio->PDDR&~MASK)|((mask<<right)&MASK);
   }
   /**
    * Set bits in field
    *
    * @param[in] mask Mask to apply to the field (1 => set bit, 0 => unchanged)
    *
    * @note Polarity _is_ _not_ significant
    */
   static void bitSet(const uint32_t mask) {
      gpio->PSOR = (mask<<right)&MASK;
   }
   /**
    * Clear bits in field
    *
    * @param[in] mask Mask to apply to the field (1 => clear bit, 0 => unchanged)
    *
    * @note Polarity _is_ _not_ significant
    */
   static void bitClear(const uint32_t mask) {
      gpio->PCOR = (mask<<right)&MASK;
   }
   /**
    * Toggle bits in field
    *
    * @param[in] mask Mask to apply to the field (1 => toggle bit, 0 => unchanged)
    */
   static void bitToggle(const uint32_t mask) {
      gpio->PTOR = (mask<<right)&MASK;
   }
   /**
    * Read field
    *
    * @return value from field
    *
    * @note Polarity _is_ significant
    */
   static uint32_t read() {
      uint32_t t;
      if (polarity) {
         t = gpio->PDIR;
      }
      else {
         t = ~gpio->PDIR;
      }
      return (t & MASK)>>right;
   }
   /**
    * Write field
    *
    * @param[in] value to insert as field
    *
    * @note Polarity _is_ significant
    */
   static void write(uint32_t value) {
      if (!polarity) {
         value = ~value;
      }
      gpio->PDOR = ((gpio->PDOR) & ~MASK) | ((value<<right)&MASK);
   }
};

#ifdef USBDM_GPIOA_IS_DEFINED
/**
 * @brief Convenience template for GpioA. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * using namespace USBDM;
 *
 * // Instantiate for bit 3 of GpioA
 * GpioA<3, ActiveHigh> GpioA3;
 *
 * // Set as digital output
 * GpioA3::setOutput();
 *
 * // Set pin high
 * GpioA3::set();
 *
 * // Set pin low
 * GpioA3::clear();
 *
 * // Toggle pin
 * GpioA3::toggle();
 *
 * // Set pin to boolean value
 * GpioA3::write(true);
 *
 * // Set pin to boolean value
 * GpioA3::write(false);
 *
 * // Set as digital input
 * GpioA3::setInput();
 *
 * // Read pin as boolean value
 * bool x = GpioA3::read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 * @tparam polarity      Polarity of pin. Either ActiveHigh or ActiveLow
 */
template<int bitNum, Polarity polarity=ActiveHigh> class GpioA : public Gpio_T<GpioAInfo, bitNum, polarity> {};
using PortA = PcrBase_T<GpioAInfo::pinInfo.portAddress>;

/**
 * @brief Convenience template for GpioA fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * using namespace USBDM;
 *
 * // Instantiate for bit 6 down to 3 of GpioA
 * using GpioA6_3 = GpioAField<6,3>;
 *
 * // Set as digital output
 * GpioA6_3::setOutput();
 *
 * // Write value to field
 * GpioA6_3::write(0x53);
 *
 * // Clear all of field
 * GpioA6_3::bitClear();
 *
 * // Clear lower two bits of field
 * GpioA6_3::bitClear(0x3);
 *
 * // Set lower two bits of field
 * GpioA6_3::bitSet(0x3);
 *
 * // Set as digital input
 * GpioA6_3::setInput();
 *
 * // Read pin as int value
 * int x = GpioA6_3::read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 * @tparam polarity      Polarity of all pins. Either ActiveHigh or ActiveLow
 */
template<int left, int right, Polarity polarity=ActiveHigh>
class GpioAField : public Field_T<GpioAInfo, left, right, polarity> {};
#endif

#ifdef USBDM_GPIOB_IS_DEFINED
/**
 * @brief Convenience template for GpioB. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * using namespace USBDM;
 *
 * // Instantiate for bit 3 of GpioB
 * using GpioB3 = GpioB<3, ActiveHigh>;
 *
 * // Set as digital output
 * GpioB3::setOutput();
 *
 * // Set pin high
 * GpioB3::set();
 *
 * // Set pin low
 * GpioB3::clear();
 *
 * // Toggle pin
 * GpioB3::toggle();
 *
 * // Set pin to boolean value
 * GpioB3::write(true);
 *
 * // Set pin to boolean value
 * GpioB3::write(false);
 *
 * // Set as digital input
 * GpioB3::setInput();
 *
 * // Read pin as boolean value
 * bool x = GpioB3::read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 * @tparam polarity      Polarity of pin. Either ActiveHigh or ActiveLow
 */
template<int bitNum, Polarity polarity=ActiveHigh> class GpioB : public Gpio_T<GpioBInfo, bitNum, polarity> {};
using PortB = PcrBase_T<GpioBInfo::pinInfo.portAddress>;

/**
 * @brief Convenience template for GpioB fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * using namespace USBDM;
 *
 * // Instantiate for bit 6 down to 3 of GpioB
 * using GpioB6_3 = GpioBField<6,3>;
 *
 * // Set as digital output
 * GpioB6_3::setOutput();
 *
 * // Write value to field
 * GpioB6_3::write(0x53);
 *
 * // Clear all of field
 * GpioB6_3::bitClear();
 *
 * // Clear lower two bits of field
 * GpioB6_3::bitClear(0x3);
 *
 * // Set lower two bits of field
 * GpioB6_3::bitSet(0x3);
 *
 * // Set as digital input
 * GpioB6_3::setInput();
 *
 * // Read pin as int value
 * int x = GpioB6_3::read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 * @tparam polarity      Polarity of all pins. Either ActiveHigh or ActiveLow
 */
template<int left, int right, Polarity polarity=ActiveHigh>
class GpioBField : public Field_T<GpioBInfo, left, right, polarity> {};
#endif

#ifdef USBDM_GPIOC_IS_DEFINED
/**
 * @brief Convenience template for GpioC. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * using namespace USBDM;
 *
 * // Instantiate for bit 3 of GpioC
 * using GpioC3 = GpioC<3, ActiveHigh>;
 *
 * // Set as digital output
 * GpioC3::setOutput();
 *
 * // Set pin high
 * GpioC3::set();
 *
 * // Set pin low
 * GpioC3::clear();
 *
 * // Toggle pin
 * GpioC3::toggle();
 *
 * // Set pin to boolean value
 * GpioC3::write(true);
 *
 * // Set pin to boolean value
 * GpioC3::write(false);
 *
 * // Set as digital input
 * GpioC3::setInput();
 *
 * // Read pin as boolean value
 * bool x = GpioC3::read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 * @tparam polarity      Polarity of pin. Either ActiveHigh or ActiveLow
 */
template<int bitNum, Polarity polarity=ActiveHigh> class GpioC : public Gpio_T<GpioCInfo, bitNum, polarity> {};
using PortC = PcrBase_T<GpioCInfo::pinInfo.portAddress>;

/**
 * @brief Convenience template for GpioC fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * using namespace USBDM;
 *
 * // Instantiate for bit 6 down to 3 of GpioC
 * using GpioC6_3 = GpioCField<6,3>;
 *
 * // Set as digital output
 * GpioC6_3::setOutput();
 *
 * // Write value to field
 * GpioC6_3::write(0x53);
 *
 * // Clear all of field
 * GpioC6_3::bitClear();
 *
 * // Clear lower two bits of field
 * GpioC6_3::bitClear(0x3);
 *
 * // Set lower two bits of field
 * GpioC6_3::bitSet(0x3);
 *
 * // Set as digital input
 * GpioC6_3::setInput();
 *
 * // Read pin as int value
 * int x = GpioC6_3::read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 * @tparam polarity      Polarity of all pins. Either ActiveHigh or ActiveLow
 */
template<int left, int right, Polarity polarity=ActiveHigh>
class GpioCField : public Field_T<GpioCInfo, left, right, polarity> {};
#endif

#ifdef USBDM_GPIOD_IS_DEFINED
/**
 * @brief Convenience template for GpioD. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * using namespace USBDM;
 *
 * // Instantiate for bit 3 of GpioD
 * using GpioD3 = GpioD<3, ActiveHigh>;
 *
 * // Set as digital output
 * GpioD3::setOutput();
 *
 * // Set pin high
 * GpioD3::set();
 *
 * // Set pin low
 * GpioD3::clear();
 *
 * // Toggle pin
 * GpioD3::toggle();
 *
 * // Set pin to boolean value
 * GpioD3::write(true);
 *
 * // Set pin to boolean value
 * GpioD3::write(false);
 *
 * // Set as digital input
 * GpioD3::setInput();
 *
 * // Read pin as boolean value
 * bool x = GpioD3::read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 * @tparam polarity      Polarity of pin. Either ActiveHigh or ActiveLow
 */
template<int bitNum, Polarity polarity=ActiveHigh> class GpioD : public Gpio_T<GpioDInfo, bitNum, polarity> {};
using PortD = PcrBase_T<GpioDInfo::pinInfo.portAddress>;

/**
 * @brief Convenience template for GpioD fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * using namespace USBDM;
 *
 * // Instantiate for bit 6 down to 3 of GpioD
 * using GpioD6_3 = GpioDField<6,3>;
 *
 * // Set as digital output
 * GpioD6_3::setOutput();
 *
 * // Write value to field
 * GpioD6_3::write(0x53);
 *
 * // Clear all of field
 * GpioD6_3::bitClear();
 *
 * // Clear lower two bits of field
 * GpioD6_3::bitClear(0x3);
 *
 * // Set lower two bits of field
 * GpioD6_3::bitSet(0x3);
 *
 * // Set as digital input
 * GpioD6_3::setInput();
 *
 * // Read pin as int value
 * int x = GpioD6_3::read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 * @tparam polarity      Polarity of all pins. Either ActiveHigh or ActiveLow
 */
template<int left, int right, Polarity polarity=ActiveHigh>
class GpioDField : public Field_T<GpioDInfo, left, right, polarity> {};
#endif

#ifdef USBDM_GPIOE_IS_DEFINED
/**
 * @brief Convenience template for GpioE. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * using namespace USBDM;
 *
 * // Instantiate for bit 3 of GpioE
 * using GpioE3 = GpioE<3, ActiveHigh>;
 *
 * // Set as digital output
 * GpioE3::setOutput();
 *
 * // Set pin high
 * GpioE3::set();
 *
 * // Set pin low
 * GpioE3::clear();
 *
 * // Toggle pin
 * GpioE3::toggle();
 *
 * // Set pin to boolean value
 * GpioE3::write(true);
 *
 * // Set pin to boolean value
 * GpioE3::write(false);
 *
 * // Set as digital input
 * GpioE3::setInput();
 *
 * // Read pin as boolean value
 * bool x = GpioE3::read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 * @tparam polarity      Polarity of pin. Either ActiveHigh or ActiveLow
 */
template<int bitNum, Polarity polarity=ActiveHigh> class GpioE : public Gpio_T<GpioEInfo, bitNum, polarity> {};
using PortE = PcrBase_T<GpioEInfo::pinInfo.portAddress>;

/**
 * @brief Convenience template for GpioE fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * using namespace USBDM;
 *
 * // Instantiate for bit 6 down to 3 of GpioE
 * using GpioE6_3 = GpioEField<6,3>;
 *
 * // Set as digital output
 * GpioE6_3::setOutput();
 *
 * // Write value to field
 * GpioE6_3::write(0x53);
 *
 * // Clear all of field
 * GpioE6_3::bitClear();
 *
 * // Clear lower two bits of field
 * GpioE6_3::bitClear(0x3);
 *
 * // Set lower two bits of field
 * GpioE6_3::bitSet(0x3);
 *
 * // Set as digital input
 * GpioE6_3::setInput();
 *
 * // Read pin as int value
 * int x = GpioE6_3::read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 * @tparam polarity      Polarity of all pins. Either ActiveHigh or ActiveLow
 */
template<int left, int right, Polarity polarity=ActiveHigh>
class GpioEField : public Field_T<GpioEInfo, left, right, polarity> {};
#endif

/**
 * End GPIO_Group
 * @}
 */
} // End namespace USBDM

#endif /* HEADER_GPIO_H */

