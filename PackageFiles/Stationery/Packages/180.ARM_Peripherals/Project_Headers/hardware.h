/**
 * @file      hardware.h (180.ARM_Peripherals/Project_Headers/hardware.h)
 *
 * This file is a convenient location for shared USBDM namespace information and
 * brings together header files for basic USBDM features
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */

#ifndef PROJECT_HEADERS_HARDWARE_H_
#define PROJECT_HEADERS_HARDWARE_H_

#include <stdint.h>
 /*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
namespace USBDM {

static constexpr float ns      = 1E-9f; //!< Scale factor for nanoseconds
static constexpr float us      = 1E-6f; //!< Scale factor for microseconds
static constexpr float ms      = 1E-3f; //!< Scale factor for milliseconds
static constexpr float seconds = 1.0f;  //!< Scale factor for seconds
static constexpr float percent = 1.0f;  //!< Scale factor for percentage as float
static constexpr float MHz     = 1E6f;  //!< Scale factor for MHz as float
static constexpr float kHz     = 1E3f;  //!< Scale factor for kHz as float
static constexpr float Hz      = 1.0f;  //!< Scale factor for Hz as float

/** MCGFFCLK - Fixed frequency clock (input to FLL) */
extern volatile uint32_t SystemMcgffClock;

/** MCGOUTCLK - Primary output from MCG, various sources */
extern volatile uint32_t SystemMcgOutClock;

/** MCGFLLCLK - Output of FLL */
extern volatile uint32_t SystemMcgFllClock;

/** MCGPLLCLK - Output of PLL */
extern volatile uint32_t SystemMcgPllClock;

/** Core/System clock (from MCGOUTCLK/CLKDIV) */
extern volatile uint32_t SystemCoreClock;

/** Bus clock (from MCGOUTCLK/CLKDIV) */
extern volatile uint32_t SystemBusClock;

/** LPO - Low power oscillator 1kHz clock available in LP modes */
extern volatile uint32_t SystemLpoClock;

enum ErrorCode {
   E_NO_ERROR = 0,                //!< No error
   E_ERROR,                       //!< General error
   E_TOO_SMALL,                   //!< Value too small
   E_TOO_LARGE,                   //!< Value too large
   E_ILLEGAL_PARAM,               //!< Parameter has illegal value
   E_NO_HANDLER,                  //!< No handler installed
   E_FLASH_INIT_FAILED,           //!< Flash initialisation failed
   E_TERMINATED,                  //!< The program has terminated
   E_CALIBRATE_FAIL,              //!< Failed ADC calibration
   E_ILLEGAL_POWER_TRANSITION,    //!< Can't transit to to power mode from current power mode

   E_CMSIS_ERR_OFFSET = 1<<20,    //!< Offset added to CMSIS error codes
};

/** Last error set by USBDM code */
extern volatile ErrorCode errorCode;

/**
 * Get USBDM error code
 *
 * @return  Error code
 */
ErrorCode getError();

/**
 * Get error message from error code or last error if not provided
 *
 * @param[in]   err Error code
 *
 * @return Pointer to static string
 */
const char *getErrorMessage(ErrorCode err = errorCode);

/**
 * Check for error code being set (drastically!)
 * This routine does not return if there is an error
 */
#ifndef DEBUG_BUILD
inline static ErrorCode checkError() {
   while (errorCode != E_NO_ERROR) {
   }
   return errorCode;
}
#else
extern ErrorCode checkError();
#endif

/**
 * Set error code
 *
 * @param[in]  err Error code to set
 *
 * @return Error code
 */
inline static ErrorCode setErrorCode(ErrorCode err) {
   errorCode = err;
   return errorCode;
}

/**
 * Set error code and check for error
 *
 * @param[in]  err Error code to set
 *
 * @return Error code
 */
inline static ErrorCode setAndCheckErrorCode(ErrorCode err) {
   errorCode = err;
   return checkError();
}

#ifdef __CMSIS_RTOS

/**
 * Set error code
 *
 * @param[in]  err Error code to set
 *
 * @return Error code
 */
inline static ErrorCode setCmsisErrorCode(int err) {
   if (err != 0) {
      // Bump error CMSIS error code to avoid conflict with USBDM error codes
      err |= E_CMSIS_ERR_OFFSET;
   }
   errorCode = (ErrorCode)err;
   return errorCode;
}

/**
 * Set error code and check for error
 *
 * @param[in]  err Error code to set
 *
 * @return Error code
 */
inline static ErrorCode setAndCheckCmsisErrorCode(int err) {
   if (err != 0) {
      // Bump error CMSIS error code to avoid conflict with USBDM error codes
      err |= E_CMSIS_ERR_OFFSET;
   }
   errorCode = (ErrorCode)(err);
   return checkError();
}
#endif

/**
 * Clear error code
 */
inline void clearError() {
   errorCode = E_NO_ERROR;
}

} // End namespace USBDM

// Use when in-lining makes the only makes the release build smaller
#ifdef DEBUG_BUILD
#define INLINE_RELEASE
#else
#define INLINE_RELEASE __attribute__((always_inline))
#endif

#include "pin_mapping.h"
#include "delay.h"
#include "console.h"

#endif /* PROJECT_HEADERS_HARDWARE_H_ */
