/****************************************************************************************************//**
 * @file     MKL82Z7.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for MKL82Z7.
 *           Equivalent: 
 *
 * @version  V1.6
 * @date     2017/06
 *
 *******************************************************************************************************/

#ifndef MCU_MKL82Z7
#define MCU_MKL82Z7

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/**
* @addtogroup Interrupt_vector_numbers_GROUP Interrupt vector numbers
* @brief Vector numbers required for NVIC functions
* @{
*/
/* -------------------------  Interrupt Number Definition  ------------------------ */

/**
 * Interrupt vector numbers
 */
typedef enum {
/* ------------------------  Processor Exceptions Numbers  ------------------------- */
  Reset_IRQn                    = -15,   /**<   1 Reset Vector, invoked on Power up and warm reset                                 */
  NonMaskableInt_IRQn           = -14,   /**<   2 Non maskable Interrupt, cannot be stopped or preempted                           */
  HardFault_IRQn                = -13,   /**<   3 Hard Fault, all classes of Fault                                                 */
  SVCall_IRQn                   =  -5,   /**<  11 System Service Call via SVC instruction                                          */
  PendSV_IRQn                   =  -2,   /**<  14 Pendable request for system service                                              */
  SysTick_IRQn                  =  -1,   /**<  15 System Tick Timer                                                                */
/* ----------------------   MKL82Z7 VectorTable                      ---------------------- */
  DMA0_DMA4_IRQn                =   0,   /**<  16 Enhanced direct memory access controller                                         */
  DMA1_DMA5_IRQn                =   1,   /**<  17 Enhanced direct memory access controller                                         */
  DMA2_DMA6_IRQn                =   2,   /**<  18 Enhanced direct memory access controller                                         */
  DMA3_DMA7_IRQn                =   3,   /**<  19 Enhanced direct memory access controller                                         */
  DMA_Error_IRQn                =   4,   /**<  20 Enhanced direct memory access controller                                         */
  FLEXIO0_IRQn                  =   5,   /**<  21 The FLEXIO Memory Map/Register Definition can be found here                      */
  TPM0_IRQn                     =   6,   /**<  22 Timer/PWM Module                                                                 */
  TPM1_IRQn                     =   7,   /**<  23 Timer/PWM Module                                                                 */
  TPM2_IRQn                     =   8,   /**<  24 Timer/PWM Module                                                                 */
  PIT0_IRQn                     =   9,   /**<  25 Periodic Interrupt Timer                                                         */
  SPI0_IRQn                     =  10,   /**<  26 Serial Peripheral Interface                                                      */
  EMVSIM0_IRQn                  =  11,   /**<  27 EMVSIM                                                                           */
  LPUART0_IRQn                  =  12,   /**<  28 Universal Asynchronous Receiver/Transmitter                                      */
  LPUART1_IRQn                  =  13,   /**<  29 Universal Asynchronous Receiver/Transmitter                                      */
  I2C0_IRQn                     =  14,   /**<  30 Inter-Integrated Circuit                                                         */
  QSPI0_IRQn                    =  15,   /**<  31 QuadSPI                                                                          */
  PORTA_IRQn                    =  17,   /**<  33 General Purpose Input/Output                                                     */
  PORTB_IRQn                    =  18,   /**<  34 General Purpose Input/Output                                                     */
  PORTC_IRQn                    =  19,   /**<  35 General Purpose Input/Output                                                     */
  PORTD_IRQn                    =  20,   /**<  36 General Purpose Input/Output                                                     */
  PORTE_IRQn                    =  21,   /**<  37 General Purpose Input/Output                                                     */
  LLWU_IRQn                     =  22,   /**<  38 Low leakage wakeup unit                                                          */
  LTC0_IRQn                     =  23,   /**<  39 LTC                                                                              */
  USB0_IRQn                     =  24,   /**<  40 Universal Serial Bus, OTG Capable Controller                                     */
  ADC0_IRQn                     =  25,   /**<  41 Analog-to-Digital Converter                                                      */
  LPTMR0_IRQn                   =  26,   /**<  42 Low Power Timer                                                                  */
  RTC_Seconds_IRQn              =  27,   /**<  43 Secure Real Time Clock                                                           */
  INTMUX0_0_IRQn                =  28,   /**<  44 Interrupt Multiplexer                                                            */
  INTMUX0_1_IRQn                =  29,   /**<  45 Interrupt Multiplexer                                                            */
  INTMUX0_2_IRQn                =  30,   /**<  46 Interrupt Multiplexer                                                            */
  INTMUX0_3_IRQn                =  31,   /**<  47 Interrupt Multiplexer                                                            */
  LPTMR1_IRQn                   =  32,   /**<  48 Interrupt Multiplexer                                                            */
  SPI1_IRQn                     =  36,   /**<  52 Interrupt Multiplexer                                                            */
  LPUART2_IRQn                  =  37,   /**<  53 Interrupt Multiplexer                                                            */
  EMVSIM1_IRQn                  =  38,   /**<  54 EMVSIM                                                                           */
  I2C1_IRQn                     =  39,   /**<  55 Inter-Integrated Circuit                                                         */
  TSI0_IRQn                     =  40,   /**<  56 Interrupt Multiplexer                                                            */
  PMC_IRQn                      =  41,   /**<  57 Interrupt Multiplexer                                                            */
  FTFA_IRQn                     =  42,   /**<  58 Flash Memory Interface                                                           */
  MCG_IRQn                      =  43,   /**<  59 Interrupt Multiplexer                                                            */
  WDOG_EWM_IRQn                 =  44,   /**<  60 External Watchdog Monitor                                                        */
  DAC0_IRQn                     =  45,   /**<  61 12-Bit Digital-to-Analog Converter                                               */
  TRNG0_IRQn                    =  46,   /**<  62 Interrupt Multiplexer                                                            */
  CMP0_IRQn                     =  48,   /**<  64 High-Speed Comparator (CMP), Voltage Reference (VREF) Digital-to-Analog Converter (DAC), and Analog Mux */
  RTC_Alarm_IRQn                =  50,   /**<  66 Interrupt Multiplexer                                                            */
  DMA4_IRQn                     =  56,   /**<  72 Interrupt Multiplexer                                                            */
  DMA5_IRQn                     =  57,   /**<  73 Interrupt Multiplexer                                                            */
  DMA6_IRQn                     =  58,   /**<  74 Interrupt Multiplexer                                                            */
  DMA7_IRQn                     =  59,   /**<  75 Interrupt Multiplexer                                                            */
} IRQn_Type;

/**
 * @} */ /* End group Interrupt_vector_numbers_GROUP 
 */
/**
* @addtogroup Interrupt_handler_prototypes_GROUP Interrupt handler prototypes
* @brief Prototypes for interrupt handlers
* @{
*/
/* -------------------------  Exception Handlers  ------------------------ */
extern void NMI_Handler(void);                 /**< Non maskable Interrupt, cannot be stopped or preempted                           */
extern void HardFault_Handler(void);           /**< Hard Fault, all classes of Fault                                                 */
extern void SVC_Handler(void);                 /**< System Service Call via SVC instruction                                          */
extern void PendSV_Handler(void);              /**< Pendable request for system service                                              */
extern void SysTick_Handler(void);             /**< System Tick Timer                                                                */
extern void DMA0_DMA4_IRQHandler(void);        /**< Enhanced direct memory access controller                                         */
extern void DMA1_DMA5_IRQHandler(void);        /**< Enhanced direct memory access controller                                         */
extern void DMA2_DMA6_IRQHandler(void);        /**< Enhanced direct memory access controller                                         */
extern void DMA3_DMA7_IRQHandler(void);        /**< Enhanced direct memory access controller                                         */
extern void DMA_Error_IRQHandler(void);        /**< Enhanced direct memory access controller                                         */
extern void FLEXIO0_IRQHandler(void);          /**< The FLEXIO Memory Map/Register Definition can be found here                      */
extern void TPM0_IRQHandler(void);             /**< Timer/PWM Module                                                                 */
extern void TPM1_IRQHandler(void);             /**< Timer/PWM Module                                                                 */
extern void TPM2_IRQHandler(void);             /**< Timer/PWM Module                                                                 */
extern void PIT0_IRQHandler(void);             /**< Periodic Interrupt Timer                                                         */
extern void SPI0_IRQHandler(void);             /**< Serial Peripheral Interface                                                      */
extern void EMVSIM0_IRQHandler(void);          /**< EMVSIM                                                                           */
extern void LPUART0_IRQHandler(void);          /**< Universal Asynchronous Receiver/Transmitter                                      */
extern void LPUART1_IRQHandler(void);          /**< Universal Asynchronous Receiver/Transmitter                                      */
extern void I2C0_IRQHandler(void);             /**< Inter-Integrated Circuit                                                         */
extern void QSPI0_IRQHandler(void);            /**< QuadSPI                                                                          */
extern void PORTA_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTB_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTC_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTD_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTE_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void LLWU_IRQHandler(void);             /**< Low leakage wakeup unit                                                          */
extern void LTC0_IRQHandler(void);             /**< LTC                                                                              */
extern void USB0_IRQHandler(void);             /**< Universal Serial Bus, OTG Capable Controller                                     */
extern void ADC0_IRQHandler(void);             /**< Analog-to-Digital Converter                                                      */
extern void LPTMR0_IRQHandler(void);           /**< Low Power Timer                                                                  */
extern void RTC_Seconds_IRQHandler(void);      /**< Secure Real Time Clock                                                           */
extern void INTMUX0_0_IRQHandler(void);        /**< Interrupt Multiplexer                                                            */
extern void INTMUX0_1_IRQHandler(void);        /**< Interrupt Multiplexer                                                            */
extern void INTMUX0_2_IRQHandler(void);        /**< Interrupt Multiplexer                                                            */
extern void INTMUX0_3_IRQHandler(void);        /**< Interrupt Multiplexer                                                            */
extern void LPTMR1_IRQHandler(void);           /**< Interrupt Multiplexer                                                            */
extern void SPI1_IRQHandler(void);             /**< Interrupt Multiplexer                                                            */
extern void LPUART2_IRQHandler(void);          /**< Interrupt Multiplexer                                                            */
extern void EMVSIM1_IRQHandler(void);          /**< EMVSIM                                                                           */
extern void I2C1_IRQHandler(void);             /**< Inter-Integrated Circuit                                                         */
extern void TSI0_IRQHandler(void);             /**< Interrupt Multiplexer                                                            */
extern void PMC_IRQHandler(void);              /**< Interrupt Multiplexer                                                            */
extern void FTFA_IRQHandler(void);             /**< Flash Memory Interface                                                           */
extern void MCG_IRQHandler(void);              /**< Interrupt Multiplexer                                                            */
extern void WDOG_EWM_IRQHandler(void);         /**< External Watchdog Monitor                                                        */
extern void DAC0_IRQHandler(void);             /**< 12-Bit Digital-to-Analog Converter                                               */
extern void TRNG0_IRQHandler(void);            /**< Interrupt Multiplexer                                                            */
extern void CMP0_IRQHandler(void);             /**< High-Speed Comparator (CMP), Voltage Reference (VREF) Digital-to-Analog Converter (DAC), and Analog Mux */
extern void RTC_Alarm_IRQHandler(void);        /**< Interrupt Multiplexer                                                            */
extern void DMA4_IRQHandler(void);             /**< Interrupt Multiplexer                                                            */
extern void DMA5_IRQHandler(void);             /**< Interrupt Multiplexer                                                            */
extern void DMA6_IRQHandler(void);             /**< Interrupt Multiplexer                                                            */
extern void DMA7_IRQHandler(void);             /**< Interrupt Multiplexer                                                            */

/**
 * @} */ /* End group Interrupt_handler_prototypes_GROUP 
 */
/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/**
* @addtogroup Cortex_Core_Configuration_GROUP Cortex Core Configuration
* @brief Configuration of the cm4 Processor and Core Peripherals
* @{
*/
#define __CM0PLUS_REV             0x0000     /**< CPU Revision                                        */
#define __MPU_PRESENT             0          /**< Whether MPU is present                              */
#define __NVIC_PRIO_BITS          2          /**< Number of implemented bits in NVIC PRIO register    */
#define __Vendor_SysTickConfig    0          /**< Whether Vendor implemented SYSTICK timer is present */
#define __FPU_PRESENT             0          /**< Whether FPU is present                              */
#define __VTOR_PRESENT            1          /**< Whether VTOR register is present                    */

/**
 * @} */ /* End group Cortex_Core_Configuration_GROUP 
 */
#include "core_cm0plus.h"       /* Processor and core peripherals     */
#include "system.h"             /* Device specific configuration file */

#ifndef __IO
#define __IO volatile 
#endif

#ifndef __I
#define __I volatile const
#endif

#ifndef __O
#define __O volatile
#endif


/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */



/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif
/**
* @addtogroup Peripheral_access_layer_GROUP Device Peripheral Access Layer
* @brief C structs allowing access to peripheral registers
* @{
*/
/**
* @addtogroup ADC_Peripheral_access_layer_GROUP ADC Peripheral Access Layer
* @brief C Struct for ADC
* @{
*/

/* ================================================================================ */
/* ================           ADC0 (file:ADC0_MK82F25615)          ================ */
/* ================================================================================ */

/**
 * @brief Analog-to-Digital Converter
 */
/**
* @addtogroup ADC_structs_GROUP ADC struct
* @brief Struct for ADC
* @{
*/
typedef struct {                                /*       ADC0 Structure                                               */
   __IO uint32_t  SC1A;                         /**< 0000: ADC Status and Control Registers 1                           */
   __IO uint32_t  SC1B;                         /**< 0004: ADC Status and Control Registers 1                           */
   __IO uint32_t  CFG1;                         /**< 0008: ADC Configuration Register 1                                 */
   __IO uint32_t  CFG2;                         /**< 000C: ADC Configuration Register 2                                 */
   __I  uint32_t  RA;                           /**< 0010: ADC Data Result Register                                     */
   __I  uint32_t  RB;                           /**< 0014: ADC Data Result Register                                     */
   __IO uint32_t  CV1;                          /**< 0018: Compare Value                                                */
   __IO uint32_t  CV2;                          /**< 001C: Compare Value                                                */
   __IO uint32_t  SC2;                          /**< 0020: Status and Control Register 2                                */
   __IO uint32_t  SC3;                          /**< 0024: Status and Control Register 3                                */
   __IO uint32_t  OFS;                          /**< 0028: ADC Offset Correction Register                               */
   __IO uint32_t  PG;                           /**< 002C: ADC Plus-Side Gain Register                                  */
   __IO uint32_t  MG;                           /**< 0030: ADC Minus-Side Gain Register                                 */
   __IO uint32_t  CLPD;                         /**< 0034: ADC Plus-Side General Calibration Value Register             */
   __IO uint32_t  CLPS;                         /**< 0038: ADC Plus-Side General Calibration Value Register             */
   __IO uint32_t  CLP4;                         /**< 003C: ADC Plus-Side General Calibration Value Register             */
   __IO uint32_t  CLP3;                         /**< 0040: ADC Plus-Side General Calibration Value Register             */
   __IO uint32_t  CLP2;                         /**< 0044: ADC Plus-Side General Calibration Value Register             */
   __IO uint32_t  CLP1;                         /**< 0048: ADC Plus-Side General Calibration Value Register             */
   __IO uint32_t  CLP0;                         /**< 004C: ADC Plus-Side General Calibration Value Register             */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  CLMD;                         /**< 0054: ADC Minus-Side General Calibration Value Register            */
   __IO uint32_t  CLMS;                         /**< 0058: ADC Minus-Side General Calibration Value Register            */
   __IO uint32_t  CLM4;                         /**< 005C: ADC Minus-Side General Calibration Value Register            */
   __IO uint32_t  CLM3;                         /**< 0060: ADC Minus-Side General Calibration Value Register            */
   __IO uint32_t  CLM2;                         /**< 0064: ADC Minus-Side General Calibration Value Register            */
   __IO uint32_t  CLM1;                         /**< 0068: ADC Minus-Side General Calibration Value Register            */
   __IO uint32_t  CLM0;                         /**< 006C: ADC Minus-Side General Calibration Value Register            */
} ADC_Type;

/**
 * @} */ /* End group ADC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'ADC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup ADC_Register_Masks_GROUP ADC Register Masks
* @brief Register Masks for ADC
* @{
*/
/* ------- SC1 Bit Fields                           ------ */
#define ADC_SC1_ADCH_MASK                        (0x1FU)                                             /*!< ADC0_SC1.ADCH Mask                      */
#define ADC_SC1_ADCH_SHIFT                       (0U)                                                /*!< ADC0_SC1.ADCH Position                  */
#define ADC_SC1_ADCH(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1FUL)          /*!< ADC0_SC1.ADCH Field                     */
#define ADC_SC1_DIFF_MASK                        (0x20U)                                             /*!< ADC0_SC1.DIFF Mask                      */
#define ADC_SC1_DIFF_SHIFT                       (5U)                                                /*!< ADC0_SC1.DIFF Position                  */
#define ADC_SC1_DIFF(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< ADC0_SC1.DIFF Field                     */
#define ADC_SC1_AIEN_MASK                        (0x40U)                                             /*!< ADC0_SC1.AIEN Mask                      */
#define ADC_SC1_AIEN_SHIFT                       (6U)                                                /*!< ADC0_SC1.AIEN Position                  */
#define ADC_SC1_AIEN(x)                          (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< ADC0_SC1.AIEN Field                     */
#define ADC_SC1_COCO_MASK                        (0x80U)                                             /*!< ADC0_SC1.COCO Mask                      */
#define ADC_SC1_COCO_SHIFT                       (7U)                                                /*!< ADC0_SC1.COCO Position                  */
#define ADC_SC1_COCO(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< ADC0_SC1.COCO Field                     */
/* ------- CFG1 Bit Fields                          ------ */
#define ADC_CFG1_ADICLK_MASK                     (0x3U)                                              /*!< ADC0_CFG1.ADICLK Mask                   */
#define ADC_CFG1_ADICLK_SHIFT                    (0U)                                                /*!< ADC0_CFG1.ADICLK Position               */
#define ADC_CFG1_ADICLK(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< ADC0_CFG1.ADICLK Field                  */
#define ADC_CFG1_MODE_MASK                       (0xCU)                                              /*!< ADC0_CFG1.MODE Mask                     */
#define ADC_CFG1_MODE_SHIFT                      (2U)                                                /*!< ADC0_CFG1.MODE Position                 */
#define ADC_CFG1_MODE(x)                         (((uint32_t)(((uint32_t)(x))<<2U))&0xCUL)           /*!< ADC0_CFG1.MODE Field                    */
#define ADC_CFG1_ADLSMP_MASK                     (0x10U)                                             /*!< ADC0_CFG1.ADLSMP Mask                   */
#define ADC_CFG1_ADLSMP_SHIFT                    (4U)                                                /*!< ADC0_CFG1.ADLSMP Position               */
#define ADC_CFG1_ADLSMP(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< ADC0_CFG1.ADLSMP Field                  */
#define ADC_CFG1_ADIV_MASK                       (0x60U)                                             /*!< ADC0_CFG1.ADIV Mask                     */
#define ADC_CFG1_ADIV_SHIFT                      (5U)                                                /*!< ADC0_CFG1.ADIV Position                 */
#define ADC_CFG1_ADIV(x)                         (((uint32_t)(((uint32_t)(x))<<5U))&0x60UL)          /*!< ADC0_CFG1.ADIV Field                    */
#define ADC_CFG1_ADLPC_MASK                      (0x80U)                                             /*!< ADC0_CFG1.ADLPC Mask                    */
#define ADC_CFG1_ADLPC_SHIFT                     (7U)                                                /*!< ADC0_CFG1.ADLPC Position                */
#define ADC_CFG1_ADLPC(x)                        (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< ADC0_CFG1.ADLPC Field                   */
/* ------- CFG2 Bit Fields                          ------ */
#define ADC_CFG2_ADLSTS_MASK                     (0x3U)                                              /*!< ADC0_CFG2.ADLSTS Mask                   */
#define ADC_CFG2_ADLSTS_SHIFT                    (0U)                                                /*!< ADC0_CFG2.ADLSTS Position               */
#define ADC_CFG2_ADLSTS(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< ADC0_CFG2.ADLSTS Field                  */
#define ADC_CFG2_ADHSC_MASK                      (0x4U)                                              /*!< ADC0_CFG2.ADHSC Mask                    */
#define ADC_CFG2_ADHSC_SHIFT                     (2U)                                                /*!< ADC0_CFG2.ADHSC Position                */
#define ADC_CFG2_ADHSC(x)                        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< ADC0_CFG2.ADHSC Field                   */
#define ADC_CFG2_ADACKEN_MASK                    (0x8U)                                              /*!< ADC0_CFG2.ADACKEN Mask                  */
#define ADC_CFG2_ADACKEN_SHIFT                   (3U)                                                /*!< ADC0_CFG2.ADACKEN Position              */
#define ADC_CFG2_ADACKEN(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< ADC0_CFG2.ADACKEN Field                 */
#define ADC_CFG2_MUXSEL_MASK                     (0x10U)                                             /*!< ADC0_CFG2.MUXSEL Mask                   */
#define ADC_CFG2_MUXSEL_SHIFT                    (4U)                                                /*!< ADC0_CFG2.MUXSEL Position               */
#define ADC_CFG2_MUXSEL(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< ADC0_CFG2.MUXSEL Field                  */
/* ------- R Bit Fields                             ------ */
#define ADC_R_D_MASK                             (0xFFFFU)                                           /*!< ADC0_R.D Mask                           */
#define ADC_R_D_SHIFT                            (0U)                                                /*!< ADC0_R.D Position                       */
#define ADC_R_D(x)                               (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< ADC0_R.D Field                          */
/* ------- CV Bit Fields                            ------ */
#define ADC_CV_CV_MASK                           (0xFFFFU)                                           /*!< ADC0_CV.CV Mask                         */
#define ADC_CV_CV_SHIFT                          (0U)                                                /*!< ADC0_CV.CV Position                     */
#define ADC_CV_CV(x)                             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< ADC0_CV.CV Field                        */
/* ------- SC2 Bit Fields                           ------ */
#define ADC_SC2_REFSEL_MASK                      (0x3U)                                              /*!< ADC0_SC2.REFSEL Mask                    */
#define ADC_SC2_REFSEL_SHIFT                     (0U)                                                /*!< ADC0_SC2.REFSEL Position                */
#define ADC_SC2_REFSEL(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< ADC0_SC2.REFSEL Field                   */
#define ADC_SC2_DMAEN_MASK                       (0x4U)                                              /*!< ADC0_SC2.DMAEN Mask                     */
#define ADC_SC2_DMAEN_SHIFT                      (2U)                                                /*!< ADC0_SC2.DMAEN Position                 */
#define ADC_SC2_DMAEN(x)                         (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< ADC0_SC2.DMAEN Field                    */
#define ADC_SC2_ACREN_MASK                       (0x8U)                                              /*!< ADC0_SC2.ACREN Mask                     */
#define ADC_SC2_ACREN_SHIFT                      (3U)                                                /*!< ADC0_SC2.ACREN Position                 */
#define ADC_SC2_ACREN(x)                         (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< ADC0_SC2.ACREN Field                    */
#define ADC_SC2_ACFGT_MASK                       (0x10U)                                             /*!< ADC0_SC2.ACFGT Mask                     */
#define ADC_SC2_ACFGT_SHIFT                      (4U)                                                /*!< ADC0_SC2.ACFGT Position                 */
#define ADC_SC2_ACFGT(x)                         (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< ADC0_SC2.ACFGT Field                    */
#define ADC_SC2_ACFE_MASK                        (0x20U)                                             /*!< ADC0_SC2.ACFE Mask                      */
#define ADC_SC2_ACFE_SHIFT                       (5U)                                                /*!< ADC0_SC2.ACFE Position                  */
#define ADC_SC2_ACFE(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< ADC0_SC2.ACFE Field                     */
#define ADC_SC2_ADTRG_MASK                       (0x40U)                                             /*!< ADC0_SC2.ADTRG Mask                     */
#define ADC_SC2_ADTRG_SHIFT                      (6U)                                                /*!< ADC0_SC2.ADTRG Position                 */
#define ADC_SC2_ADTRG(x)                         (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< ADC0_SC2.ADTRG Field                    */
#define ADC_SC2_ADACT_MASK                       (0x80U)                                             /*!< ADC0_SC2.ADACT Mask                     */
#define ADC_SC2_ADACT_SHIFT                      (7U)                                                /*!< ADC0_SC2.ADACT Position                 */
#define ADC_SC2_ADACT(x)                         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< ADC0_SC2.ADACT Field                    */
/* ------- SC3 Bit Fields                           ------ */
#define ADC_SC3_AVGS_MASK                        (0x3U)                                              /*!< ADC0_SC3.AVGS Mask                      */
#define ADC_SC3_AVGS_SHIFT                       (0U)                                                /*!< ADC0_SC3.AVGS Position                  */
#define ADC_SC3_AVGS(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< ADC0_SC3.AVGS Field                     */
#define ADC_SC3_AVGE_MASK                        (0x4U)                                              /*!< ADC0_SC3.AVGE Mask                      */
#define ADC_SC3_AVGE_SHIFT                       (2U)                                                /*!< ADC0_SC3.AVGE Position                  */
#define ADC_SC3_AVGE(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< ADC0_SC3.AVGE Field                     */
#define ADC_SC3_ADCO_MASK                        (0x8U)                                              /*!< ADC0_SC3.ADCO Mask                      */
#define ADC_SC3_ADCO_SHIFT                       (3U)                                                /*!< ADC0_SC3.ADCO Position                  */
#define ADC_SC3_ADCO(x)                          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< ADC0_SC3.ADCO Field                     */
#define ADC_SC3_CALF_MASK                        (0x40U)                                             /*!< ADC0_SC3.CALF Mask                      */
#define ADC_SC3_CALF_SHIFT                       (6U)                                                /*!< ADC0_SC3.CALF Position                  */
#define ADC_SC3_CALF(x)                          (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< ADC0_SC3.CALF Field                     */
#define ADC_SC3_CAL_MASK                         (0x80U)                                             /*!< ADC0_SC3.CAL Mask                       */
#define ADC_SC3_CAL_SHIFT                        (7U)                                                /*!< ADC0_SC3.CAL Position                   */
#define ADC_SC3_CAL(x)                           (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< ADC0_SC3.CAL Field                      */
/* ------- OFS Bit Fields                           ------ */
#define ADC_OFS_OFS_MASK                         (0xFFFFU)                                           /*!< ADC0_OFS.OFS Mask                       */
#define ADC_OFS_OFS_SHIFT                        (0U)                                                /*!< ADC0_OFS.OFS Position                   */
#define ADC_OFS_OFS(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< ADC0_OFS.OFS Field                      */
/* ------- PG Bit Fields                            ------ */
#define ADC_PG_PG_MASK                           (0xFFFFU)                                           /*!< ADC0_PG.PG Mask                         */
#define ADC_PG_PG_SHIFT                          (0U)                                                /*!< ADC0_PG.PG Position                     */
#define ADC_PG_PG(x)                             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< ADC0_PG.PG Field                        */
/* ------- MG Bit Fields                            ------ */
#define ADC_MG_MG_MASK                           (0xFFFFU)                                           /*!< ADC0_MG.MG Mask                         */
#define ADC_MG_MG_SHIFT                          (0U)                                                /*!< ADC0_MG.MG Position                     */
#define ADC_MG_MG(x)                             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< ADC0_MG.MG Field                        */
/* ------- CLPD Bit Fields                          ------ */
#define ADC_CLPD_CLPD_MASK                       (0x3FU)                                             /*!< ADC0_CLPD.CLPD Mask                     */
#define ADC_CLPD_CLPD_SHIFT                      (0U)                                                /*!< ADC0_CLPD.CLPD Position                 */
#define ADC_CLPD_CLPD(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x3FUL)          /*!< ADC0_CLPD.CLPD Field                    */
/* ------- CLPS Bit Fields                          ------ */
#define ADC_CLPS_CLPS_MASK                       (0x3FU)                                             /*!< ADC0_CLPS.CLPS Mask                     */
#define ADC_CLPS_CLPS_SHIFT                      (0U)                                                /*!< ADC0_CLPS.CLPS Position                 */
#define ADC_CLPS_CLPS(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x3FUL)          /*!< ADC0_CLPS.CLPS Field                    */
/* ------- CLP4 Bit Fields                          ------ */
#define ADC_CLP4_CLP4_MASK                       (0x3FFU)                                            /*!< ADC0_CLP4.CLP4 Mask                     */
#define ADC_CLP4_CLP4_SHIFT                      (0U)                                                /*!< ADC0_CLP4.CLP4 Position                 */
#define ADC_CLP4_CLP4(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFUL)         /*!< ADC0_CLP4.CLP4 Field                    */
/* ------- CLP3 Bit Fields                          ------ */
#define ADC_CLP3_CLP3_MASK                       (0x1FFU)                                            /*!< ADC0_CLP3.CLP3 Mask                     */
#define ADC_CLP3_CLP3_SHIFT                      (0U)                                                /*!< ADC0_CLP3.CLP3 Position                 */
#define ADC_CLP3_CLP3(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFUL)         /*!< ADC0_CLP3.CLP3 Field                    */
/* ------- CLP2 Bit Fields                          ------ */
#define ADC_CLP2_CLP2_MASK                       (0xFFU)                                             /*!< ADC0_CLP2.CLP2 Mask                     */
#define ADC_CLP2_CLP2_SHIFT                      (0U)                                                /*!< ADC0_CLP2.CLP2 Position                 */
#define ADC_CLP2_CLP2(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< ADC0_CLP2.CLP2 Field                    */
/* ------- CLP1 Bit Fields                          ------ */
#define ADC_CLP1_CLP1_MASK                       (0x7FU)                                             /*!< ADC0_CLP1.CLP1 Mask                     */
#define ADC_CLP1_CLP1_SHIFT                      (0U)                                                /*!< ADC0_CLP1.CLP1 Position                 */
#define ADC_CLP1_CLP1(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x7FUL)          /*!< ADC0_CLP1.CLP1 Field                    */
/* ------- CLP0 Bit Fields                          ------ */
#define ADC_CLP0_CLP0_MASK                       (0x3FU)                                             /*!< ADC0_CLP0.CLP0 Mask                     */
#define ADC_CLP0_CLP0_SHIFT                      (0U)                                                /*!< ADC0_CLP0.CLP0 Position                 */
#define ADC_CLP0_CLP0(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x3FUL)          /*!< ADC0_CLP0.CLP0 Field                    */
/* ------- CLMD Bit Fields                          ------ */
#define ADC_CLMD_CLMD_MASK                       (0x3FU)                                             /*!< ADC0_CLMD.CLMD Mask                     */
#define ADC_CLMD_CLMD_SHIFT                      (0U)                                                /*!< ADC0_CLMD.CLMD Position                 */
#define ADC_CLMD_CLMD(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x3FUL)          /*!< ADC0_CLMD.CLMD Field                    */
/* ------- CLMS Bit Fields                          ------ */
#define ADC_CLMS_CLMS_MASK                       (0x3FU)                                             /*!< ADC0_CLMS.CLMS Mask                     */
#define ADC_CLMS_CLMS_SHIFT                      (0U)                                                /*!< ADC0_CLMS.CLMS Position                 */
#define ADC_CLMS_CLMS(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x3FUL)          /*!< ADC0_CLMS.CLMS Field                    */
/* ------- CLM4 Bit Fields                          ------ */
#define ADC_CLM4_CLM4_MASK                       (0x3FFU)                                            /*!< ADC0_CLM4.CLM4 Mask                     */
#define ADC_CLM4_CLM4_SHIFT                      (0U)                                                /*!< ADC0_CLM4.CLM4 Position                 */
#define ADC_CLM4_CLM4(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFUL)         /*!< ADC0_CLM4.CLM4 Field                    */
/* ------- CLM3 Bit Fields                          ------ */
#define ADC_CLM3_CLM3_MASK                       (0x1FFU)                                            /*!< ADC0_CLM3.CLM3 Mask                     */
#define ADC_CLM3_CLM3_SHIFT                      (0U)                                                /*!< ADC0_CLM3.CLM3 Position                 */
#define ADC_CLM3_CLM3(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFUL)         /*!< ADC0_CLM3.CLM3 Field                    */
/* ------- CLM2 Bit Fields                          ------ */
#define ADC_CLM2_CLM2_MASK                       (0xFFU)                                             /*!< ADC0_CLM2.CLM2 Mask                     */
#define ADC_CLM2_CLM2_SHIFT                      (0U)                                                /*!< ADC0_CLM2.CLM2 Position                 */
#define ADC_CLM2_CLM2(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< ADC0_CLM2.CLM2 Field                    */
/* ------- CLM1 Bit Fields                          ------ */
#define ADC_CLM1_CLM1_MASK                       (0x7FU)                                             /*!< ADC0_CLM1.CLM1 Mask                     */
#define ADC_CLM1_CLM1_SHIFT                      (0U)                                                /*!< ADC0_CLM1.CLM1 Position                 */
#define ADC_CLM1_CLM1(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x7FUL)          /*!< ADC0_CLM1.CLM1 Field                    */
/* ------- CLM0 Bit Fields                          ------ */
#define ADC_CLM0_CLM0_MASK                       (0x3FU)                                             /*!< ADC0_CLM0.CLM0 Mask                     */
#define ADC_CLM0_CLM0_SHIFT                      (0U)                                                /*!< ADC0_CLM0.CLM0 Position                 */
#define ADC_CLM0_CLM0(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x3FUL)          /*!< ADC0_CLM0.CLM0 Field                    */
/**
 * @} */ /* End group ADC_Register_Masks_GROUP 
 */

/* ADC0 - Peripheral instance base addresses */
#define ADC0_BasePtr                   0x4003B000UL //!< Peripheral base address
#define ADC0                           ((ADC_Type *) ADC0_BasePtr) //!< Freescale base pointer
#define ADC0_BASE_PTR                  (ADC0) //!< Freescale style base pointer
/**
 * @} */ /* End group ADC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer
* @brief C Struct for CMP
* @{
*/

/* ================================================================================ */
/* ================           CMP0 (file:CMP0_MKL82Z7)             ================ */
/* ================================================================================ */

/**
 * @brief High-Speed Comparator (CMP), Voltage Reference (VREF) Digital-to-Analog Converter (DAC), and Analog Mux
 */
/**
* @addtogroup CMP_structs_GROUP CMP struct
* @brief Struct for CMP
* @{
*/
typedef struct {                                /*       CMP0 Structure                                               */
   __IO uint8_t   CR0;                          /**< 0000: CMP Control Register 0                                       */
   __IO uint8_t   CR1;                          /**< 0001: CMP Control Register 1                                       */
   __IO uint8_t   FPR;                          /**< 0002: CMP Filter Period Register                                   */
   __IO uint8_t   SCR;                          /**< 0003: CMP Status and Control Register                              */
   __IO uint8_t   DACCR;                        /**< 0004: DAC Control Register                                         */
   __IO uint8_t   MUXCR;                        /**< 0005: MUX Control Register                                         */
} CMP_Type;

/**
 * @} */ /* End group CMP_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CMP0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CMP_Register_Masks_GROUP CMP Register Masks
* @brief Register Masks for CMP
* @{
*/
/* ------- CR0 Bit Fields                           ------ */
#define CMP_CR0_HYSTCTR_MASK                     (0x3U)                                              /*!< CMP0_CR0.HYSTCTR Mask                   */
#define CMP_CR0_HYSTCTR_SHIFT                    (0U)                                                /*!< CMP0_CR0.HYSTCTR Position               */
#define CMP_CR0_HYSTCTR(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< CMP0_CR0.HYSTCTR Field                  */
#define CMP_CR0_FILTER_CNT_MASK                  (0x70U)                                             /*!< CMP0_CR0.FILTER_CNT Mask                */
#define CMP_CR0_FILTER_CNT_SHIFT                 (4U)                                                /*!< CMP0_CR0.FILTER_CNT Position            */
#define CMP_CR0_FILTER_CNT(x)                    (((uint8_t)(((uint8_t)(x))<<4U))&0x70UL)            /*!< CMP0_CR0.FILTER_CNT Field               */
/* ------- CR1 Bit Fields                           ------ */
#define CMP_CR1_EN_MASK                          (0x1U)                                              /*!< CMP0_CR1.EN Mask                        */
#define CMP_CR1_EN_SHIFT                         (0U)                                                /*!< CMP0_CR1.EN Position                    */
#define CMP_CR1_EN(x)                            (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< CMP0_CR1.EN Field                       */
#define CMP_CR1_OPE_MASK                         (0x2U)                                              /*!< CMP0_CR1.OPE Mask                       */
#define CMP_CR1_OPE_SHIFT                        (1U)                                                /*!< CMP0_CR1.OPE Position                   */
#define CMP_CR1_OPE(x)                           (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< CMP0_CR1.OPE Field                      */
#define CMP_CR1_COS_MASK                         (0x4U)                                              /*!< CMP0_CR1.COS Mask                       */
#define CMP_CR1_COS_SHIFT                        (2U)                                                /*!< CMP0_CR1.COS Position                   */
#define CMP_CR1_COS(x)                           (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< CMP0_CR1.COS Field                      */
#define CMP_CR1_INV_MASK                         (0x8U)                                              /*!< CMP0_CR1.INV Mask                       */
#define CMP_CR1_INV_SHIFT                        (3U)                                                /*!< CMP0_CR1.INV Position                   */
#define CMP_CR1_INV(x)                           (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< CMP0_CR1.INV Field                      */
#define CMP_CR1_PMODE_MASK                       (0x10U)                                             /*!< CMP0_CR1.PMODE Mask                     */
#define CMP_CR1_PMODE_SHIFT                      (4U)                                                /*!< CMP0_CR1.PMODE Position                 */
#define CMP_CR1_PMODE(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< CMP0_CR1.PMODE Field                    */
#define CMP_CR1_TRIGM_MASK                       (0x20U)                                             /*!< CMP0_CR1.TRIGM Mask                     */
#define CMP_CR1_TRIGM_SHIFT                      (5U)                                                /*!< CMP0_CR1.TRIGM Position                 */
#define CMP_CR1_TRIGM(x)                         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< CMP0_CR1.TRIGM Field                    */
#define CMP_CR1_WE_MASK                          (0x40U)                                             /*!< CMP0_CR1.WE Mask                        */
#define CMP_CR1_WE_SHIFT                         (6U)                                                /*!< CMP0_CR1.WE Position                    */
#define CMP_CR1_WE(x)                            (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< CMP0_CR1.WE Field                       */
#define CMP_CR1_SE_MASK                          (0x80U)                                             /*!< CMP0_CR1.SE Mask                        */
#define CMP_CR1_SE_SHIFT                         (7U)                                                /*!< CMP0_CR1.SE Position                    */
#define CMP_CR1_SE(x)                            (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< CMP0_CR1.SE Field                       */
/* ------- FPR Bit Fields                           ------ */
#define CMP_FPR_FILT_PER_MASK                    (0xFFU)                                             /*!< CMP0_FPR.FILT_PER Mask                  */
#define CMP_FPR_FILT_PER_SHIFT                   (0U)                                                /*!< CMP0_FPR.FILT_PER Position              */
#define CMP_FPR_FILT_PER(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< CMP0_FPR.FILT_PER Field                 */
/* ------- SCR Bit Fields                           ------ */
#define CMP_SCR_COUT_MASK                        (0x1U)                                              /*!< CMP0_SCR.COUT Mask                      */
#define CMP_SCR_COUT_SHIFT                       (0U)                                                /*!< CMP0_SCR.COUT Position                  */
#define CMP_SCR_COUT(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< CMP0_SCR.COUT Field                     */
#define CMP_SCR_CFF_MASK                         (0x2U)                                              /*!< CMP0_SCR.CFF Mask                       */
#define CMP_SCR_CFF_SHIFT                        (1U)                                                /*!< CMP0_SCR.CFF Position                   */
#define CMP_SCR_CFF(x)                           (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< CMP0_SCR.CFF Field                      */
#define CMP_SCR_CFR_MASK                         (0x4U)                                              /*!< CMP0_SCR.CFR Mask                       */
#define CMP_SCR_CFR_SHIFT                        (2U)                                                /*!< CMP0_SCR.CFR Position                   */
#define CMP_SCR_CFR(x)                           (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< CMP0_SCR.CFR Field                      */
#define CMP_SCR_IEF_MASK                         (0x8U)                                              /*!< CMP0_SCR.IEF Mask                       */
#define CMP_SCR_IEF_SHIFT                        (3U)                                                /*!< CMP0_SCR.IEF Position                   */
#define CMP_SCR_IEF(x)                           (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< CMP0_SCR.IEF Field                      */
#define CMP_SCR_IER_MASK                         (0x10U)                                             /*!< CMP0_SCR.IER Mask                       */
#define CMP_SCR_IER_SHIFT                        (4U)                                                /*!< CMP0_SCR.IER Position                   */
#define CMP_SCR_IER(x)                           (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< CMP0_SCR.IER Field                      */
#define CMP_SCR_DMAEN_MASK                       (0x40U)                                             /*!< CMP0_SCR.DMAEN Mask                     */
#define CMP_SCR_DMAEN_SHIFT                      (6U)                                                /*!< CMP0_SCR.DMAEN Position                 */
#define CMP_SCR_DMAEN(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< CMP0_SCR.DMAEN Field                    */
/* ------- DACCR Bit Fields                         ------ */
#define CMP_DACCR_VOSEL_MASK                     (0x3FU)                                             /*!< CMP0_DACCR.VOSEL Mask                   */
#define CMP_DACCR_VOSEL_SHIFT                    (0U)                                                /*!< CMP0_DACCR.VOSEL Position               */
#define CMP_DACCR_VOSEL(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3FUL)            /*!< CMP0_DACCR.VOSEL Field                  */
#define CMP_DACCR_VRSEL_MASK                     (0x40U)                                             /*!< CMP0_DACCR.VRSEL Mask                   */
#define CMP_DACCR_VRSEL_SHIFT                    (6U)                                                /*!< CMP0_DACCR.VRSEL Position               */
#define CMP_DACCR_VRSEL(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< CMP0_DACCR.VRSEL Field                  */
#define CMP_DACCR_DACEN_MASK                     (0x80U)                                             /*!< CMP0_DACCR.DACEN Mask                   */
#define CMP_DACCR_DACEN_SHIFT                    (7U)                                                /*!< CMP0_DACCR.DACEN Position               */
#define CMP_DACCR_DACEN(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< CMP0_DACCR.DACEN Field                  */
/* ------- MUXCR Bit Fields                         ------ */
#define CMP_MUXCR_MSEL_MASK                      (0x7U)                                              /*!< CMP0_MUXCR.MSEL Mask                    */
#define CMP_MUXCR_MSEL_SHIFT                     (0U)                                                /*!< CMP0_MUXCR.MSEL Position                */
#define CMP_MUXCR_MSEL(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< CMP0_MUXCR.MSEL Field                   */
#define CMP_MUXCR_PSEL_MASK                      (0x38U)                                             /*!< CMP0_MUXCR.PSEL Mask                    */
#define CMP_MUXCR_PSEL_SHIFT                     (3U)                                                /*!< CMP0_MUXCR.PSEL Position                */
#define CMP_MUXCR_PSEL(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x38UL)            /*!< CMP0_MUXCR.PSEL Field                   */
/**
 * @} */ /* End group CMP_Register_Masks_GROUP 
 */

/* CMP0 - Peripheral instance base addresses */
#define CMP0_BasePtr                   0x40073000UL //!< Peripheral base address
#define CMP0                           ((CMP_Type *) CMP0_BasePtr) //!< Freescale base pointer
#define CMP0_BASE_PTR                  (CMP0) //!< Freescale style base pointer
/**
 * @} */ /* End group CMP_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CRC_Peripheral_access_layer_GROUP CRC Peripheral Access Layer
* @brief C Struct for CRC
* @{
*/

/* ================================================================================ */
/* ================           CRC0 (file:CRC0_0x40032000)          ================ */
/* ================================================================================ */

/**
 * @brief Cyclic Redundancy Check
 */
/**
* @addtogroup CRC_structs_GROUP CRC struct
* @brief Struct for CRC
* @{
*/
typedef struct {                                /*       CRC0 Structure                                               */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  DATA;                      /**< 0000: Data register                                                */
      struct {                                  /**< 0000: (size=0004)                                                  */
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  DATAL;               /**< 0000: DATAL register                                               */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   DATALL;           /**< 0000: DATALL register                                              */
               __IO uint8_t   DATALU;           /**< 0001: DATALU register                                              */
            };
         };
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  DATAH;               /**< 0002: DATAH register                                               */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   DATAHL;           /**< 0002: DATAHL register                                              */
               __IO uint8_t   DATAHU;           /**< 0003: DATAHU register                                              */
            };
         };
      };
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  GPOLY;                     /**< 0004: Polynomial register                                          */
      struct {                                  /**< 0000: (size=0004)                                                  */
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  GPOLYL;              /**< 0004: GPOLYL register                                              */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   GPOLYLL;          /**< 0004: GPOLYLL register                                             */
               __IO uint8_t   GPOLYLU;          /**< 0005: GPOLYLU register                                             */
            };
         };
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  GPOLYH;              /**< 0006: GPOLYH register                                              */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   GPOLYHL;          /**< 0006: GPOLYHL register                                             */
               __IO uint8_t   GPOLYHU;          /**< 0007: GPOLYHU register                                             */
            };
         };
      };
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  CTRL;                      /**< 0008: Control register                                             */
      struct {                                  /**< 0000: (size=0004)                                                  */
              uint8_t   RESERVED_6[3];         
         __IO uint8_t   CTRLHU;                 /**< 000B: Control register (byte access)                               */
      };
   };
} CRC_Type;

/**
 * @} */ /* End group CRC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CRC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CRC_Register_Masks_GROUP CRC Register Masks
* @brief Register Masks for CRC
* @{
*/
/* ------- DATA Bit Fields                          ------ */
#define CRC_DATA_LL_MASK                         (0xFFU)                                             /*!< CRC0_DATA.LL Mask                       */
#define CRC_DATA_LL_SHIFT                        (0U)                                                /*!< CRC0_DATA.LL Position                   */
#define CRC_DATA_LL(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< CRC0_DATA.LL Field                      */
#define CRC_DATA_LU_MASK                         (0xFF00U)                                           /*!< CRC0_DATA.LU Mask                       */
#define CRC_DATA_LU_SHIFT                        (8U)                                                /*!< CRC0_DATA.LU Position                   */
#define CRC_DATA_LU(x)                           (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< CRC0_DATA.LU Field                      */
#define CRC_DATA_HL_MASK                         (0xFF0000U)                                         /*!< CRC0_DATA.HL Mask                       */
#define CRC_DATA_HL_SHIFT                        (16U)                                               /*!< CRC0_DATA.HL Position                   */
#define CRC_DATA_HL(x)                           (((uint32_t)(((uint32_t)(x))<<16U))&0xFF0000UL)     /*!< CRC0_DATA.HL Field                      */
#define CRC_DATA_HU_MASK                         (0xFF000000U)                                       /*!< CRC0_DATA.HU Mask                       */
#define CRC_DATA_HU_SHIFT                        (24U)                                               /*!< CRC0_DATA.HU Position                   */
#define CRC_DATA_HU(x)                           (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< CRC0_DATA.HU Field                      */
/* ------- DATAL Bit Fields                         ------ */
#define CRC_DATAL_DATAL_MASK                     (0xFFFFU)                                           /*!< CRC0_DATAL.DATAL Mask                   */
#define CRC_DATAL_DATAL_SHIFT                    (0U)                                                /*!< CRC0_DATAL.DATAL Position               */
#define CRC_DATAL_DATAL(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< CRC0_DATAL.DATAL Field                  */
/* ------- DATALL Bit Fields                        ------ */
#define CRC_DATALL_DATALL_MASK                   (0xFFU)                                             /*!< CRC0_DATALL.DATALL Mask                 */
#define CRC_DATALL_DATALL_SHIFT                  (0U)                                                /*!< CRC0_DATALL.DATALL Position             */
#define CRC_DATALL_DATALL(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< CRC0_DATALL.DATALL Field                */
/* ------- DATALU Bit Fields                        ------ */
#define CRC_DATALU_DATALU_MASK                   (0xFFU)                                             /*!< CRC0_DATALU.DATALU Mask                 */
#define CRC_DATALU_DATALU_SHIFT                  (0U)                                                /*!< CRC0_DATALU.DATALU Position             */
#define CRC_DATALU_DATALU(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< CRC0_DATALU.DATALU Field                */
/* ------- DATAH Bit Fields                         ------ */
#define CRC_DATAH_DATAH_MASK                     (0xFFFFU)                                           /*!< CRC0_DATAH.DATAH Mask                   */
#define CRC_DATAH_DATAH_SHIFT                    (0U)                                                /*!< CRC0_DATAH.DATAH Position               */
#define CRC_DATAH_DATAH(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< CRC0_DATAH.DATAH Field                  */
/* ------- DATAHL Bit Fields                        ------ */
#define CRC_DATAHL_DATAHL_MASK                   (0xFFU)                                             /*!< CRC0_DATAHL.DATAHL Mask                 */
#define CRC_DATAHL_DATAHL_SHIFT                  (0U)                                                /*!< CRC0_DATAHL.DATAHL Position             */
#define CRC_DATAHL_DATAHL(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< CRC0_DATAHL.DATAHL Field                */
/* ------- DATAHU Bit Fields                        ------ */
#define CRC_DATAHU_DATAHU_MASK                   (0xFFU)                                             /*!< CRC0_DATAHU.DATAHU Mask                 */
#define CRC_DATAHU_DATAHU_SHIFT                  (0U)                                                /*!< CRC0_DATAHU.DATAHU Position             */
#define CRC_DATAHU_DATAHU(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< CRC0_DATAHU.DATAHU Field                */
/* ------- GPOLY Bit Fields                         ------ */
#define CRC_GPOLY_LOW_MASK                       (0xFFFFU)                                           /*!< CRC0_GPOLY.LOW Mask                     */
#define CRC_GPOLY_LOW_SHIFT                      (0U)                                                /*!< CRC0_GPOLY.LOW Position                 */
#define CRC_GPOLY_LOW(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< CRC0_GPOLY.LOW Field                    */
#define CRC_GPOLY_HIGH_MASK                      (0xFFFF0000U)                                       /*!< CRC0_GPOLY.HIGH Mask                    */
#define CRC_GPOLY_HIGH_SHIFT                     (16U)                                               /*!< CRC0_GPOLY.HIGH Position                */
#define CRC_GPOLY_HIGH(x)                        (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< CRC0_GPOLY.HIGH Field                   */
/* ------- GPOLYL Bit Fields                        ------ */
#define CRC_GPOLYL_GPOLYL_MASK                   (0xFFFFU)                                           /*!< CRC0_GPOLYL.GPOLYL Mask                 */
#define CRC_GPOLYL_GPOLYL_SHIFT                  (0U)                                                /*!< CRC0_GPOLYL.GPOLYL Position             */
#define CRC_GPOLYL_GPOLYL(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< CRC0_GPOLYL.GPOLYL Field                */
/* ------- GPOLYLL Bit Fields                       ------ */
#define CRC_GPOLYLL_GPOLYLL_MASK                 (0xFFU)                                             /*!< CRC0_GPOLYLL.GPOLYLL Mask               */
#define CRC_GPOLYLL_GPOLYLL_SHIFT                (0U)                                                /*!< CRC0_GPOLYLL.GPOLYLL Position           */
#define CRC_GPOLYLL_GPOLYLL(x)                   (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< CRC0_GPOLYLL.GPOLYLL Field              */
/* ------- GPOLYLU Bit Fields                       ------ */
#define CRC_GPOLYLU_GPOLYLU_MASK                 (0xFFU)                                             /*!< CRC0_GPOLYLU.GPOLYLU Mask               */
#define CRC_GPOLYLU_GPOLYLU_SHIFT                (0U)                                                /*!< CRC0_GPOLYLU.GPOLYLU Position           */
#define CRC_GPOLYLU_GPOLYLU(x)                   (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< CRC0_GPOLYLU.GPOLYLU Field              */
/* ------- GPOLYH Bit Fields                        ------ */
#define CRC_GPOLYH_GPOLYH_MASK                   (0xFFFFU)                                           /*!< CRC0_GPOLYH.GPOLYH Mask                 */
#define CRC_GPOLYH_GPOLYH_SHIFT                  (0U)                                                /*!< CRC0_GPOLYH.GPOLYH Position             */
#define CRC_GPOLYH_GPOLYH(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< CRC0_GPOLYH.GPOLYH Field                */
/* ------- GPOLYHL Bit Fields                       ------ */
#define CRC_GPOLYHL_GPOLYHL_MASK                 (0xFFU)                                             /*!< CRC0_GPOLYHL.GPOLYHL Mask               */
#define CRC_GPOLYHL_GPOLYHL_SHIFT                (0U)                                                /*!< CRC0_GPOLYHL.GPOLYHL Position           */
#define CRC_GPOLYHL_GPOLYHL(x)                   (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< CRC0_GPOLYHL.GPOLYHL Field              */
/* ------- GPOLYHU Bit Fields                       ------ */
#define CRC_GPOLYHU_GPOLYHU_MASK                 (0xFFU)                                             /*!< CRC0_GPOLYHU.GPOLYHU Mask               */
#define CRC_GPOLYHU_GPOLYHU_SHIFT                (0U)                                                /*!< CRC0_GPOLYHU.GPOLYHU Position           */
#define CRC_GPOLYHU_GPOLYHU(x)                   (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< CRC0_GPOLYHU.GPOLYHU Field              */
/* ------- CTRL Bit Fields                          ------ */
#define CRC_CTRL_TCRC_MASK                       (0x1000000U)                                        /*!< CRC0_CTRL.TCRC Mask                     */
#define CRC_CTRL_TCRC_SHIFT                      (24U)                                               /*!< CRC0_CTRL.TCRC Position                 */
#define CRC_CTRL_TCRC(x)                         (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< CRC0_CTRL.TCRC Field                    */
#define CRC_CTRL_WAS_MASK                        (0x2000000U)                                        /*!< CRC0_CTRL.WAS Mask                      */
#define CRC_CTRL_WAS_SHIFT                       (25U)                                               /*!< CRC0_CTRL.WAS Position                  */
#define CRC_CTRL_WAS(x)                          (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< CRC0_CTRL.WAS Field                     */
#define CRC_CTRL_FXOR_MASK                       (0x4000000U)                                        /*!< CRC0_CTRL.FXOR Mask                     */
#define CRC_CTRL_FXOR_SHIFT                      (26U)                                               /*!< CRC0_CTRL.FXOR Position                 */
#define CRC_CTRL_FXOR(x)                         (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< CRC0_CTRL.FXOR Field                    */
#define CRC_CTRL_TOTR_MASK                       (0x30000000U)                                       /*!< CRC0_CTRL.TOTR Mask                     */
#define CRC_CTRL_TOTR_SHIFT                      (28U)                                               /*!< CRC0_CTRL.TOTR Position                 */
#define CRC_CTRL_TOTR(x)                         (((uint32_t)(((uint32_t)(x))<<28U))&0x30000000UL)   /*!< CRC0_CTRL.TOTR Field                    */
#define CRC_CTRL_TOT_MASK                        (0xC0000000U)                                       /*!< CRC0_CTRL.TOT Mask                      */
#define CRC_CTRL_TOT_SHIFT                       (30U)                                               /*!< CRC0_CTRL.TOT Position                  */
#define CRC_CTRL_TOT(x)                          (((uint32_t)(((uint32_t)(x))<<30U))&0xC0000000UL)   /*!< CRC0_CTRL.TOT Field                     */
/* ------- CTRLHU Bit Fields                        ------ */
#define CRC_CTRLHU_TCRC_MASK                     (0x1U)                                              /*!< CRC0_CTRLHU.TCRC Mask                   */
#define CRC_CTRLHU_TCRC_SHIFT                    (0U)                                                /*!< CRC0_CTRLHU.TCRC Position               */
#define CRC_CTRLHU_TCRC(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< CRC0_CTRLHU.TCRC Field                  */
#define CRC_CTRLHU_WAS_MASK                      (0x2U)                                              /*!< CRC0_CTRLHU.WAS Mask                    */
#define CRC_CTRLHU_WAS_SHIFT                     (1U)                                                /*!< CRC0_CTRLHU.WAS Position                */
#define CRC_CTRLHU_WAS(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< CRC0_CTRLHU.WAS Field                   */
#define CRC_CTRLHU_FXOR_MASK                     (0x4U)                                              /*!< CRC0_CTRLHU.FXOR Mask                   */
#define CRC_CTRLHU_FXOR_SHIFT                    (2U)                                                /*!< CRC0_CTRLHU.FXOR Position               */
#define CRC_CTRLHU_FXOR(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< CRC0_CTRLHU.FXOR Field                  */
#define CRC_CTRLHU_TOTR_MASK                     (0x30U)                                             /*!< CRC0_CTRLHU.TOTR Mask                   */
#define CRC_CTRLHU_TOTR_SHIFT                    (4U)                                                /*!< CRC0_CTRLHU.TOTR Position               */
#define CRC_CTRLHU_TOTR(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< CRC0_CTRLHU.TOTR Field                  */
#define CRC_CTRLHU_TOT_MASK                      (0xC0U)                                             /*!< CRC0_CTRLHU.TOT Mask                    */
#define CRC_CTRLHU_TOT_SHIFT                     (6U)                                                /*!< CRC0_CTRLHU.TOT Position                */
#define CRC_CTRLHU_TOT(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< CRC0_CTRLHU.TOT Field                   */
/**
 * @} */ /* End group CRC_Register_Masks_GROUP 
 */

/* CRC0 - Peripheral instance base addresses */
#define CRC0_BasePtr                   0x40032000UL //!< Peripheral base address
#define CRC0                           ((CRC_Type *) CRC0_BasePtr) //!< Freescale base pointer
#define CRC0_BASE_PTR                  (CRC0) //!< Freescale style base pointer
/**
 * @} */ /* End group CRC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DAC_Peripheral_access_layer_GROUP DAC Peripheral Access Layer
* @brief C Struct for DAC
* @{
*/

/* ================================================================================ */
/* ================           DAC0 (file:DAC0_MKL82Z7)             ================ */
/* ================================================================================ */

/**
 * @brief 12-Bit Digital-to-Analog Converter
 */
/**
* @addtogroup DAC_structs_GROUP DAC struct
* @brief Struct for DAC
* @{
*/
typedef struct {                                /*       DAC0 Structure                                               */
   struct {
      __IO uint8_t   DATL;                      /**< 0000: DAC Data Low Register                                        */
      __IO uint8_t   DATH;                      /**< 0001: DAC Data High Register                                       */
   } DAT[16];                                   /**< 0000: (cluster: size=0x0020, 32)                                   */
   __IO uint8_t   SR;                           /**< 0020: DAC Status Register                                          */
   __IO uint8_t   C0;                           /**< 0021: DAC Control Register                                         */
   __IO uint8_t   C1;                           /**< 0022: DAC Control Register 1                                       */
   __IO uint8_t   C2;                           /**< 0023: DAC Control Register 2                                       */
} DAC_Type;

/**
 * @} */ /* End group DAC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DAC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DAC_Register_Masks_GROUP DAC Register Masks
* @brief Register Masks for DAC
* @{
*/
/* ------- DATL Bit Fields                          ------ */
#define DAC_DATL_DATA0_MASK                      (0xFFU)                                             /*!< DAC0_DATL.DATA0 Mask                    */
#define DAC_DATL_DATA0_SHIFT                     (0U)                                                /*!< DAC0_DATL.DATA0 Position                */
#define DAC_DATL_DATA0(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< DAC0_DATL.DATA0 Field                   */
/* ------- DATH Bit Fields                          ------ */
#define DAC_DATH_DATA1_MASK                      (0xFU)                                              /*!< DAC0_DATH.DATA1 Mask                    */
#define DAC_DATH_DATA1_SHIFT                     (0U)                                                /*!< DAC0_DATH.DATA1 Position                */
#define DAC_DATH_DATA1(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< DAC0_DATH.DATA1 Field                   */
/* ------- SR Bit Fields                            ------ */
#define DAC_SR_DACBFRPBF_MASK                    (0x1U)                                              /*!< DAC0_SR.DACBFRPBF Mask                  */
#define DAC_SR_DACBFRPBF_SHIFT                   (0U)                                                /*!< DAC0_SR.DACBFRPBF Position              */
#define DAC_SR_DACBFRPBF(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< DAC0_SR.DACBFRPBF Field                 */
#define DAC_SR_DACBFRPTF_MASK                    (0x2U)                                              /*!< DAC0_SR.DACBFRPTF Mask                  */
#define DAC_SR_DACBFRPTF_SHIFT                   (1U)                                                /*!< DAC0_SR.DACBFRPTF Position              */
#define DAC_SR_DACBFRPTF(x)                      (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< DAC0_SR.DACBFRPTF Field                 */
#define DAC_SR_DACBFWMF_MASK                     (0x4U)                                              /*!< DAC0_SR.DACBFWMF Mask                   */
#define DAC_SR_DACBFWMF_SHIFT                    (2U)                                                /*!< DAC0_SR.DACBFWMF Position               */
#define DAC_SR_DACBFWMF(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< DAC0_SR.DACBFWMF Field                  */
/* ------- C0 Bit Fields                            ------ */
#define DAC_C0_DACBBIEN_MASK                     (0x1U)                                              /*!< DAC0_C0.DACBBIEN Mask                   */
#define DAC_C0_DACBBIEN_SHIFT                    (0U)                                                /*!< DAC0_C0.DACBBIEN Position               */
#define DAC_C0_DACBBIEN(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< DAC0_C0.DACBBIEN Field                  */
#define DAC_C0_DACBTIEN_MASK                     (0x2U)                                              /*!< DAC0_C0.DACBTIEN Mask                   */
#define DAC_C0_DACBTIEN_SHIFT                    (1U)                                                /*!< DAC0_C0.DACBTIEN Position               */
#define DAC_C0_DACBTIEN(x)                       (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< DAC0_C0.DACBTIEN Field                  */
#define DAC_C0_DACBWIEN_MASK                     (0x4U)                                              /*!< DAC0_C0.DACBWIEN Mask                   */
#define DAC_C0_DACBWIEN_SHIFT                    (2U)                                                /*!< DAC0_C0.DACBWIEN Position               */
#define DAC_C0_DACBWIEN(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< DAC0_C0.DACBWIEN Field                  */
#define DAC_C0_LPEN_MASK                         (0x8U)                                              /*!< DAC0_C0.LPEN Mask                       */
#define DAC_C0_LPEN_SHIFT                        (3U)                                                /*!< DAC0_C0.LPEN Position                   */
#define DAC_C0_LPEN(x)                           (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< DAC0_C0.LPEN Field                      */
#define DAC_C0_DACSWTRG_MASK                     (0x10U)                                             /*!< DAC0_C0.DACSWTRG Mask                   */
#define DAC_C0_DACSWTRG_SHIFT                    (4U)                                                /*!< DAC0_C0.DACSWTRG Position               */
#define DAC_C0_DACSWTRG(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< DAC0_C0.DACSWTRG Field                  */
#define DAC_C0_DACTRGSEL_MASK                    (0x20U)                                             /*!< DAC0_C0.DACTRGSEL Mask                  */
#define DAC_C0_DACTRGSEL_SHIFT                   (5U)                                                /*!< DAC0_C0.DACTRGSEL Position              */
#define DAC_C0_DACTRGSEL(x)                      (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< DAC0_C0.DACTRGSEL Field                 */
#define DAC_C0_DACRFS_MASK                       (0x40U)                                             /*!< DAC0_C0.DACRFS Mask                     */
#define DAC_C0_DACRFS_SHIFT                      (6U)                                                /*!< DAC0_C0.DACRFS Position                 */
#define DAC_C0_DACRFS(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DAC0_C0.DACRFS Field                    */
#define DAC_C0_DACEN_MASK                        (0x80U)                                             /*!< DAC0_C0.DACEN Mask                      */
#define DAC_C0_DACEN_SHIFT                       (7U)                                                /*!< DAC0_C0.DACEN Position                  */
#define DAC_C0_DACEN(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DAC0_C0.DACEN Field                     */
/* ------- C1 Bit Fields                            ------ */
#define DAC_C1_DACBFEN_MASK                      (0x1U)                                              /*!< DAC0_C1.DACBFEN Mask                    */
#define DAC_C1_DACBFEN_SHIFT                     (0U)                                                /*!< DAC0_C1.DACBFEN Position                */
#define DAC_C1_DACBFEN(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< DAC0_C1.DACBFEN Field                   */
#define DAC_C1_DACBFMD_MASK                      (0x6U)                                              /*!< DAC0_C1.DACBFMD Mask                    */
#define DAC_C1_DACBFMD_SHIFT                     (1U)                                                /*!< DAC0_C1.DACBFMD Position                */
#define DAC_C1_DACBFMD(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x6UL)             /*!< DAC0_C1.DACBFMD Field                   */
#define DAC_C1_DACBFWM_MASK                      (0x18U)                                             /*!< DAC0_C1.DACBFWM Mask                    */
#define DAC_C1_DACBFWM_SHIFT                     (3U)                                                /*!< DAC0_C1.DACBFWM Position                */
#define DAC_C1_DACBFWM(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x18UL)            /*!< DAC0_C1.DACBFWM Field                   */
#define DAC_C1_DMAEN_MASK                        (0x80U)                                             /*!< DAC0_C1.DMAEN Mask                      */
#define DAC_C1_DMAEN_SHIFT                       (7U)                                                /*!< DAC0_C1.DMAEN Position                  */
#define DAC_C1_DMAEN(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DAC0_C1.DMAEN Field                     */
/* ------- C2 Bit Fields                            ------ */
#define DAC_C2_DACBFUP_MASK                      (0xFU)                                              /*!< DAC0_C2.DACBFUP Mask                    */
#define DAC_C2_DACBFUP_SHIFT                     (0U)                                                /*!< DAC0_C2.DACBFUP Position                */
#define DAC_C2_DACBFUP(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< DAC0_C2.DACBFUP Field                   */
#define DAC_C2_DACBFRP_MASK                      (0xF0U)                                             /*!< DAC0_C2.DACBFRP Mask                    */
#define DAC_C2_DACBFRP_SHIFT                     (4U)                                                /*!< DAC0_C2.DACBFRP Position                */
#define DAC_C2_DACBFRP(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0xF0UL)            /*!< DAC0_C2.DACBFRP Field                   */
/**
 * @} */ /* End group DAC_Register_Masks_GROUP 
 */

/* DAC0 - Peripheral instance base addresses */
#define DAC0_BasePtr                   0x4003F000UL //!< Peripheral base address
#define DAC0                           ((DAC_Type *) DAC0_BasePtr) //!< Freescale base pointer
#define DAC0_BASE_PTR                  (DAC0) //!< Freescale style base pointer
/**
 * @} */ /* End group DAC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMA_Peripheral_access_layer_GROUP DMA Peripheral Access Layer
* @brief C Struct for DMA
* @{
*/

/* ================================================================================ */
/* ================           DMA (file:DMA_MKE15Z7)               ================ */
/* ================================================================================ */

/**
 * @brief Enhanced direct memory access controller
 */
/**
* @addtogroup DMA_structs_GROUP DMA struct
* @brief Struct for DMA
* @{
*/
typedef struct {                                /*       DMA Structure                                                */
   __IO uint32_t  CR;                           /**< 0000: Control Register                                             */
   __I  uint32_t  ES;                           /**< 0004: Error Status Register                                        */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  ERQ;                          /**< 000C: Enable Request Register                                      */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  EEI;                          /**< 0014: Enable Error Interrupt Register                              */
   __O  uint8_t   CEEI;                         /**< 0018: Clear Enable Error Interrupt Register                        */
   __O  uint8_t   SEEI;                         /**< 0019: Set Enable Error Interrupt Register                          */
   __O  uint8_t   CERQ;                         /**< 001A: Clear Enable Request Register                                */
   __O  uint8_t   SERQ;                         /**< 001B: Set Enable Request Register                                  */
   __O  uint8_t   CDNE;                         /**< 001C: Clear DONE Status Bit Register                               */
   __O  uint8_t   SSRT;                         /**< 001D: Set START Bit Register                                       */
   __O  uint8_t   CERR;                         /**< 001E: Clear Error Register                                         */
   __O  uint8_t   CINT;                         /**< 001F: Clear Interrupt Request Register                             */
        uint8_t   RESERVED_2[4];               
   __IO uint32_t  INT;                          /**< 0024: Interrupt Request Register                                   */
        uint8_t   RESERVED_3[4];               
   __IO uint32_t  ERR;                          /**< 002C: Error Register                                               */
        uint8_t   RESERVED_4[4];               
   __I  uint32_t  HRS;                          /**< 0034: Hardware Request Status Register                             */
        uint8_t   RESERVED_5[12];              
   __IO uint32_t  EARS;                         /**< 0044: Enable Asynchronous Request in Stop Register                 */
        uint8_t   RESERVED_6[184];             
   __IO uint8_t   DCHPRI3;                      /**< 0100: Channel n Priority Register                                  */
   __IO uint8_t   DCHPRI2;                      /**< 0101: Channel n Priority Register                                  */
   __IO uint8_t   DCHPRI1;                      /**< 0102: Channel n Priority Register                                  */
   __IO uint8_t   DCHPRI0;                      /**< 0103: Channel n Priority Register                                  */
   __IO uint8_t   DCHPRI7;                      /**< 0104: Channel n Priority Register                                  */
   __IO uint8_t   DCHPRI6;                      /**< 0105: Channel n Priority Register                                  */
   __IO uint8_t   DCHPRI5;                      /**< 0106: Channel n Priority Register                                  */
   __IO uint8_t   DCHPRI4;                      /**< 0107: Channel n Priority Register                                  */
        uint8_t   RESERVED_7[3832];            
   struct {
      __IO uint32_t  SADDR;                     /**< 1000: TCD Source Address                                           */
      __IO uint16_t  SOFF;                      /**< 1004: TCD Signed Source Address Offset                             */
      __IO uint16_t  ATTR;                      /**< 1006: TCD Transfer Attributes                                      */
      union {                                   /**< 1000: (size=0004)                                                  */
         __IO uint32_t  NBYTES_MLNO;            /**< 1008: TCD Minor Byte Count (Minor Loop Mapping Disabled)           */
         __IO uint32_t  NBYTES_MLOFFNO;         /**< 1008: TCD Signed Minor Loop Offset (Minor Loop Mapping Enabled and Offset Disabled) */
         __IO uint32_t  NBYTES_MLOFFYES;        /**< 1008: TCD Signed Minor Loop Offset (Minor Loop Mapping and Offset Enabled) */
      };
      __IO uint32_t  SLAST;                     /**< 100C: TCD Last Source Address Adjustment                           */
      __IO uint32_t  DADDR;                     /**< 1010: TCD Destination Address                                      */
      __IO uint16_t  DOFF;                      /**< 1014: TCD Signed Destination Address Offset                        */
      union {                                   /**< 1000: (size=0002)                                                  */
         __IO uint16_t  CITER_ELINKNO;          /**< 1016: TCD Current Minor Loop Link, Major Loop Count (Channel Linking Disabled) */
         __IO uint16_t  CITER_ELINKYES;         /**< 1016: TCD Current Minor Loop Link, Major Loop Count (Channel Linking Enabled) */
      };
      __IO uint32_t  DLASTSGA;                  /**< 1018: TCD Last Destination Address Adjustment/Scatter Gather Address */
      __IO uint16_t  CSR;                       /**< 101C: TCD Control and Status                                       */
      union {                                   /**< 1000: (size=0002)                                                  */
         __IO uint16_t  BITER_ELINKNO;          /**< 101E: TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Disabled) */
         __IO uint16_t  BITER_ELINKYES;         /**< 101E: TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Enabled) */
      };
   } TCD[8];                                    /**< 1000: (cluster: size=0x0100, 256)                                  */
} DMA_Type;

/**
 * @} */ /* End group DMA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DMA' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DMA_Register_Masks_GROUP DMA Register Masks
* @brief Register Masks for DMA
* @{
*/
/* ------- CR Bit Fields                            ------ */
#define DMA_CR_EDBG_MASK                         (0x2U)                                              /*!< DMA_CR.EDBG Mask                        */
#define DMA_CR_EDBG_SHIFT                        (1U)                                                /*!< DMA_CR.EDBG Position                    */
#define DMA_CR_EDBG(x)                           (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< DMA_CR.EDBG Field                       */
#define DMA_CR_ERCA_MASK                         (0x4U)                                              /*!< DMA_CR.ERCA Mask                        */
#define DMA_CR_ERCA_SHIFT                        (2U)                                                /*!< DMA_CR.ERCA Position                    */
#define DMA_CR_ERCA(x)                           (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< DMA_CR.ERCA Field                       */
#define DMA_CR_HOE_MASK                          (0x10U)                                             /*!< DMA_CR.HOE Mask                         */
#define DMA_CR_HOE_SHIFT                         (4U)                                                /*!< DMA_CR.HOE Position                     */
#define DMA_CR_HOE(x)                            (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< DMA_CR.HOE Field                        */
#define DMA_CR_HALT_MASK                         (0x20U)                                             /*!< DMA_CR.HALT Mask                        */
#define DMA_CR_HALT_SHIFT                        (5U)                                                /*!< DMA_CR.HALT Position                    */
#define DMA_CR_HALT(x)                           (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< DMA_CR.HALT Field                       */
#define DMA_CR_CLM_MASK                          (0x40U)                                             /*!< DMA_CR.CLM Mask                         */
#define DMA_CR_CLM_SHIFT                         (6U)                                                /*!< DMA_CR.CLM Position                     */
#define DMA_CR_CLM(x)                            (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< DMA_CR.CLM Field                        */
#define DMA_CR_EMLM_MASK                         (0x80U)                                             /*!< DMA_CR.EMLM Mask                        */
#define DMA_CR_EMLM_SHIFT                        (7U)                                                /*!< DMA_CR.EMLM Position                    */
#define DMA_CR_EMLM(x)                           (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< DMA_CR.EMLM Field                       */
#define DMA_CR_ECX_MASK                          (0x10000U)                                          /*!< DMA_CR.ECX Mask                         */
#define DMA_CR_ECX_SHIFT                         (16U)                                               /*!< DMA_CR.ECX Position                     */
#define DMA_CR_ECX(x)                            (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< DMA_CR.ECX Field                        */
#define DMA_CR_CX_MASK                           (0x20000U)                                          /*!< DMA_CR.CX Mask                          */
#define DMA_CR_CX_SHIFT                          (17U)                                               /*!< DMA_CR.CX Position                      */
#define DMA_CR_CX(x)                             (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< DMA_CR.CX Field                         */
#define DMA_CR_ACTIVE_MASK                       (0x80000000U)                                       /*!< DMA_CR.ACTIVE Mask                      */
#define DMA_CR_ACTIVE_SHIFT                      (31U)                                               /*!< DMA_CR.ACTIVE Position                  */
#define DMA_CR_ACTIVE(x)                         (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< DMA_CR.ACTIVE Field                     */
/* ------- ES Bit Fields                            ------ */
#define DMA_ES_DBE_MASK                          (0x1U)                                              /*!< DMA_ES.DBE Mask                         */
#define DMA_ES_DBE_SHIFT                         (0U)                                                /*!< DMA_ES.DBE Position                     */
#define DMA_ES_DBE(x)                            (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< DMA_ES.DBE Field                        */
#define DMA_ES_SBE_MASK                          (0x2U)                                              /*!< DMA_ES.SBE Mask                         */
#define DMA_ES_SBE_SHIFT                         (1U)                                                /*!< DMA_ES.SBE Position                     */
#define DMA_ES_SBE(x)                            (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< DMA_ES.SBE Field                        */
#define DMA_ES_SGE_MASK                          (0x4U)                                              /*!< DMA_ES.SGE Mask                         */
#define DMA_ES_SGE_SHIFT                         (2U)                                                /*!< DMA_ES.SGE Position                     */
#define DMA_ES_SGE(x)                            (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< DMA_ES.SGE Field                        */
#define DMA_ES_NCE_MASK                          (0x8U)                                              /*!< DMA_ES.NCE Mask                         */
#define DMA_ES_NCE_SHIFT                         (3U)                                                /*!< DMA_ES.NCE Position                     */
#define DMA_ES_NCE(x)                            (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< DMA_ES.NCE Field                        */
#define DMA_ES_DOE_MASK                          (0x10U)                                             /*!< DMA_ES.DOE Mask                         */
#define DMA_ES_DOE_SHIFT                         (4U)                                                /*!< DMA_ES.DOE Position                     */
#define DMA_ES_DOE(x)                            (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< DMA_ES.DOE Field                        */
#define DMA_ES_DAE_MASK                          (0x20U)                                             /*!< DMA_ES.DAE Mask                         */
#define DMA_ES_DAE_SHIFT                         (5U)                                                /*!< DMA_ES.DAE Position                     */
#define DMA_ES_DAE(x)                            (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< DMA_ES.DAE Field                        */
#define DMA_ES_SOE_MASK                          (0x40U)                                             /*!< DMA_ES.SOE Mask                         */
#define DMA_ES_SOE_SHIFT                         (6U)                                                /*!< DMA_ES.SOE Position                     */
#define DMA_ES_SOE(x)                            (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< DMA_ES.SOE Field                        */
#define DMA_ES_SAE_MASK                          (0x80U)                                             /*!< DMA_ES.SAE Mask                         */
#define DMA_ES_SAE_SHIFT                         (7U)                                                /*!< DMA_ES.SAE Position                     */
#define DMA_ES_SAE(x)                            (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< DMA_ES.SAE Field                        */
#define DMA_ES_ERRCHN_MASK                       (0x700U)                                            /*!< DMA_ES.ERRCHN Mask                      */
#define DMA_ES_ERRCHN_SHIFT                      (8U)                                                /*!< DMA_ES.ERRCHN Position                  */
#define DMA_ES_ERRCHN(x)                         (((uint32_t)(((uint32_t)(x))<<8U))&0x700UL)         /*!< DMA_ES.ERRCHN Field                     */
#define DMA_ES_CPE_MASK                          (0x4000U)                                           /*!< DMA_ES.CPE Mask                         */
#define DMA_ES_CPE_SHIFT                         (14U)                                               /*!< DMA_ES.CPE Position                     */
#define DMA_ES_CPE(x)                            (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< DMA_ES.CPE Field                        */
#define DMA_ES_ECX_MASK                          (0x10000U)                                          /*!< DMA_ES.ECX Mask                         */
#define DMA_ES_ECX_SHIFT                         (16U)                                               /*!< DMA_ES.ECX Position                     */
#define DMA_ES_ECX(x)                            (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< DMA_ES.ECX Field                        */
#define DMA_ES_VLD_MASK                          (0x80000000U)                                       /*!< DMA_ES.VLD Mask                         */
#define DMA_ES_VLD_SHIFT                         (31U)                                               /*!< DMA_ES.VLD Position                     */
#define DMA_ES_VLD(x)                            (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< DMA_ES.VLD Field                        */
/* ------- ERQ Bit Fields                           ------ */
#define DMA_ERQ_ERQ0_MASK                        (0x1U)                                              /*!< DMA_ERQ.ERQ0 Mask                       */
#define DMA_ERQ_ERQ0_SHIFT                       (0U)                                                /*!< DMA_ERQ.ERQ0 Position                   */
#define DMA_ERQ_ERQ0(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< DMA_ERQ.ERQ0 Field                      */
#define DMA_ERQ_ERQ1_MASK                        (0x2U)                                              /*!< DMA_ERQ.ERQ1 Mask                       */
#define DMA_ERQ_ERQ1_SHIFT                       (1U)                                                /*!< DMA_ERQ.ERQ1 Position                   */
#define DMA_ERQ_ERQ1(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< DMA_ERQ.ERQ1 Field                      */
#define DMA_ERQ_ERQ2_MASK                        (0x4U)                                              /*!< DMA_ERQ.ERQ2 Mask                       */
#define DMA_ERQ_ERQ2_SHIFT                       (2U)                                                /*!< DMA_ERQ.ERQ2 Position                   */
#define DMA_ERQ_ERQ2(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< DMA_ERQ.ERQ2 Field                      */
#define DMA_ERQ_ERQ3_MASK                        (0x8U)                                              /*!< DMA_ERQ.ERQ3 Mask                       */
#define DMA_ERQ_ERQ3_SHIFT                       (3U)                                                /*!< DMA_ERQ.ERQ3 Position                   */
#define DMA_ERQ_ERQ3(x)                          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< DMA_ERQ.ERQ3 Field                      */
#define DMA_ERQ_ERQ4_MASK                        (0x10U)                                             /*!< DMA_ERQ.ERQ4 Mask                       */
#define DMA_ERQ_ERQ4_SHIFT                       (4U)                                                /*!< DMA_ERQ.ERQ4 Position                   */
#define DMA_ERQ_ERQ4(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< DMA_ERQ.ERQ4 Field                      */
#define DMA_ERQ_ERQ5_MASK                        (0x20U)                                             /*!< DMA_ERQ.ERQ5 Mask                       */
#define DMA_ERQ_ERQ5_SHIFT                       (5U)                                                /*!< DMA_ERQ.ERQ5 Position                   */
#define DMA_ERQ_ERQ5(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< DMA_ERQ.ERQ5 Field                      */
#define DMA_ERQ_ERQ6_MASK                        (0x40U)                                             /*!< DMA_ERQ.ERQ6 Mask                       */
#define DMA_ERQ_ERQ6_SHIFT                       (6U)                                                /*!< DMA_ERQ.ERQ6 Position                   */
#define DMA_ERQ_ERQ6(x)                          (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< DMA_ERQ.ERQ6 Field                      */
#define DMA_ERQ_ERQ7_MASK                        (0x80U)                                             /*!< DMA_ERQ.ERQ7 Mask                       */
#define DMA_ERQ_ERQ7_SHIFT                       (7U)                                                /*!< DMA_ERQ.ERQ7 Position                   */
#define DMA_ERQ_ERQ7(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< DMA_ERQ.ERQ7 Field                      */
/* ------- EEI Bit Fields                           ------ */
#define DMA_EEI_EEI0_MASK                        (0x1U)                                              /*!< DMA_EEI.EEI0 Mask                       */
#define DMA_EEI_EEI0_SHIFT                       (0U)                                                /*!< DMA_EEI.EEI0 Position                   */
#define DMA_EEI_EEI0(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< DMA_EEI.EEI0 Field                      */
#define DMA_EEI_EEI1_MASK                        (0x2U)                                              /*!< DMA_EEI.EEI1 Mask                       */
#define DMA_EEI_EEI1_SHIFT                       (1U)                                                /*!< DMA_EEI.EEI1 Position                   */
#define DMA_EEI_EEI1(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< DMA_EEI.EEI1 Field                      */
#define DMA_EEI_EEI2_MASK                        (0x4U)                                              /*!< DMA_EEI.EEI2 Mask                       */
#define DMA_EEI_EEI2_SHIFT                       (2U)                                                /*!< DMA_EEI.EEI2 Position                   */
#define DMA_EEI_EEI2(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< DMA_EEI.EEI2 Field                      */
#define DMA_EEI_EEI3_MASK                        (0x8U)                                              /*!< DMA_EEI.EEI3 Mask                       */
#define DMA_EEI_EEI3_SHIFT                       (3U)                                                /*!< DMA_EEI.EEI3 Position                   */
#define DMA_EEI_EEI3(x)                          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< DMA_EEI.EEI3 Field                      */
#define DMA_EEI_EEI4_MASK                        (0x10U)                                             /*!< DMA_EEI.EEI4 Mask                       */
#define DMA_EEI_EEI4_SHIFT                       (4U)                                                /*!< DMA_EEI.EEI4 Position                   */
#define DMA_EEI_EEI4(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< DMA_EEI.EEI4 Field                      */
#define DMA_EEI_EEI5_MASK                        (0x20U)                                             /*!< DMA_EEI.EEI5 Mask                       */
#define DMA_EEI_EEI5_SHIFT                       (5U)                                                /*!< DMA_EEI.EEI5 Position                   */
#define DMA_EEI_EEI5(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< DMA_EEI.EEI5 Field                      */
#define DMA_EEI_EEI6_MASK                        (0x40U)                                             /*!< DMA_EEI.EEI6 Mask                       */
#define DMA_EEI_EEI6_SHIFT                       (6U)                                                /*!< DMA_EEI.EEI6 Position                   */
#define DMA_EEI_EEI6(x)                          (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< DMA_EEI.EEI6 Field                      */
#define DMA_EEI_EEI7_MASK                        (0x80U)                                             /*!< DMA_EEI.EEI7 Mask                       */
#define DMA_EEI_EEI7_SHIFT                       (7U)                                                /*!< DMA_EEI.EEI7 Position                   */
#define DMA_EEI_EEI7(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< DMA_EEI.EEI7 Field                      */
/* ------- CEEI Bit Fields                          ------ */
#define DMA_CEEI_CEEI_MASK                       (0x7U)                                              /*!< DMA_CEEI.CEEI Mask                      */
#define DMA_CEEI_CEEI_SHIFT                      (0U)                                                /*!< DMA_CEEI.CEEI Position                  */
#define DMA_CEEI_CEEI(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< DMA_CEEI.CEEI Field                     */
#define DMA_CEEI_CAEE_MASK                       (0x40U)                                             /*!< DMA_CEEI.CAEE Mask                      */
#define DMA_CEEI_CAEE_SHIFT                      (6U)                                                /*!< DMA_CEEI.CAEE Position                  */
#define DMA_CEEI_CAEE(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA_CEEI.CAEE Field                     */
#define DMA_CEEI_NOP_MASK                        (0x80U)                                             /*!< DMA_CEEI.NOP Mask                       */
#define DMA_CEEI_NOP_SHIFT                       (7U)                                                /*!< DMA_CEEI.NOP Position                   */
#define DMA_CEEI_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMA_CEEI.NOP Field                      */
/* ------- SEEI Bit Fields                          ------ */
#define DMA_SEEI_SEEI_MASK                       (0x7U)                                              /*!< DMA_SEEI.SEEI Mask                      */
#define DMA_SEEI_SEEI_SHIFT                      (0U)                                                /*!< DMA_SEEI.SEEI Position                  */
#define DMA_SEEI_SEEI(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< DMA_SEEI.SEEI Field                     */
#define DMA_SEEI_SAEE_MASK                       (0x40U)                                             /*!< DMA_SEEI.SAEE Mask                      */
#define DMA_SEEI_SAEE_SHIFT                      (6U)                                                /*!< DMA_SEEI.SAEE Position                  */
#define DMA_SEEI_SAEE(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA_SEEI.SAEE Field                     */
#define DMA_SEEI_NOP_MASK                        (0x80U)                                             /*!< DMA_SEEI.NOP Mask                       */
#define DMA_SEEI_NOP_SHIFT                       (7U)                                                /*!< DMA_SEEI.NOP Position                   */
#define DMA_SEEI_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMA_SEEI.NOP Field                      */
/* ------- CERQ Bit Fields                          ------ */
#define DMA_CERQ_CERQ_MASK                       (0x7U)                                              /*!< DMA_CERQ.CERQ Mask                      */
#define DMA_CERQ_CERQ_SHIFT                      (0U)                                                /*!< DMA_CERQ.CERQ Position                  */
#define DMA_CERQ_CERQ(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< DMA_CERQ.CERQ Field                     */
#define DMA_CERQ_CAER_MASK                       (0x40U)                                             /*!< DMA_CERQ.CAER Mask                      */
#define DMA_CERQ_CAER_SHIFT                      (6U)                                                /*!< DMA_CERQ.CAER Position                  */
#define DMA_CERQ_CAER(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA_CERQ.CAER Field                     */
#define DMA_CERQ_NOP_MASK                        (0x80U)                                             /*!< DMA_CERQ.NOP Mask                       */
#define DMA_CERQ_NOP_SHIFT                       (7U)                                                /*!< DMA_CERQ.NOP Position                   */
#define DMA_CERQ_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMA_CERQ.NOP Field                      */
/* ------- SERQ Bit Fields                          ------ */
#define DMA_SERQ_SERQ_MASK                       (0x7U)                                              /*!< DMA_SERQ.SERQ Mask                      */
#define DMA_SERQ_SERQ_SHIFT                      (0U)                                                /*!< DMA_SERQ.SERQ Position                  */
#define DMA_SERQ_SERQ(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< DMA_SERQ.SERQ Field                     */
#define DMA_SERQ_SAER_MASK                       (0x40U)                                             /*!< DMA_SERQ.SAER Mask                      */
#define DMA_SERQ_SAER_SHIFT                      (6U)                                                /*!< DMA_SERQ.SAER Position                  */
#define DMA_SERQ_SAER(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA_SERQ.SAER Field                     */
#define DMA_SERQ_NOP_MASK                        (0x80U)                                             /*!< DMA_SERQ.NOP Mask                       */
#define DMA_SERQ_NOP_SHIFT                       (7U)                                                /*!< DMA_SERQ.NOP Position                   */
#define DMA_SERQ_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMA_SERQ.NOP Field                      */
/* ------- CDNE Bit Fields                          ------ */
#define DMA_CDNE_CDNE_MASK                       (0x7U)                                              /*!< DMA_CDNE.CDNE Mask                      */
#define DMA_CDNE_CDNE_SHIFT                      (0U)                                                /*!< DMA_CDNE.CDNE Position                  */
#define DMA_CDNE_CDNE(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< DMA_CDNE.CDNE Field                     */
#define DMA_CDNE_CADN_MASK                       (0x40U)                                             /*!< DMA_CDNE.CADN Mask                      */
#define DMA_CDNE_CADN_SHIFT                      (6U)                                                /*!< DMA_CDNE.CADN Position                  */
#define DMA_CDNE_CADN(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA_CDNE.CADN Field                     */
#define DMA_CDNE_NOP_MASK                        (0x80U)                                             /*!< DMA_CDNE.NOP Mask                       */
#define DMA_CDNE_NOP_SHIFT                       (7U)                                                /*!< DMA_CDNE.NOP Position                   */
#define DMA_CDNE_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMA_CDNE.NOP Field                      */
/* ------- SSRT Bit Fields                          ------ */
#define DMA_SSRT_SSRT_MASK                       (0x7U)                                              /*!< DMA_SSRT.SSRT Mask                      */
#define DMA_SSRT_SSRT_SHIFT                      (0U)                                                /*!< DMA_SSRT.SSRT Position                  */
#define DMA_SSRT_SSRT(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< DMA_SSRT.SSRT Field                     */
#define DMA_SSRT_SAST_MASK                       (0x40U)                                             /*!< DMA_SSRT.SAST Mask                      */
#define DMA_SSRT_SAST_SHIFT                      (6U)                                                /*!< DMA_SSRT.SAST Position                  */
#define DMA_SSRT_SAST(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA_SSRT.SAST Field                     */
#define DMA_SSRT_NOP_MASK                        (0x80U)                                             /*!< DMA_SSRT.NOP Mask                       */
#define DMA_SSRT_NOP_SHIFT                       (7U)                                                /*!< DMA_SSRT.NOP Position                   */
#define DMA_SSRT_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMA_SSRT.NOP Field                      */
/* ------- CERR Bit Fields                          ------ */
#define DMA_CERR_CERR_MASK                       (0x7U)                                              /*!< DMA_CERR.CERR Mask                      */
#define DMA_CERR_CERR_SHIFT                      (0U)                                                /*!< DMA_CERR.CERR Position                  */
#define DMA_CERR_CERR(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< DMA_CERR.CERR Field                     */
#define DMA_CERR_CAEI_MASK                       (0x40U)                                             /*!< DMA_CERR.CAEI Mask                      */
#define DMA_CERR_CAEI_SHIFT                      (6U)                                                /*!< DMA_CERR.CAEI Position                  */
#define DMA_CERR_CAEI(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA_CERR.CAEI Field                     */
#define DMA_CERR_NOP_MASK                        (0x80U)                                             /*!< DMA_CERR.NOP Mask                       */
#define DMA_CERR_NOP_SHIFT                       (7U)                                                /*!< DMA_CERR.NOP Position                   */
#define DMA_CERR_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMA_CERR.NOP Field                      */
/* ------- CINT Bit Fields                          ------ */
#define DMA_CINT_CINT_MASK                       (0x7U)                                              /*!< DMA_CINT.CINT Mask                      */
#define DMA_CINT_CINT_SHIFT                      (0U)                                                /*!< DMA_CINT.CINT Position                  */
#define DMA_CINT_CINT(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< DMA_CINT.CINT Field                     */
#define DMA_CINT_CAIR_MASK                       (0x40U)                                             /*!< DMA_CINT.CAIR Mask                      */
#define DMA_CINT_CAIR_SHIFT                      (6U)                                                /*!< DMA_CINT.CAIR Position                  */
#define DMA_CINT_CAIR(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA_CINT.CAIR Field                     */
#define DMA_CINT_NOP_MASK                        (0x80U)                                             /*!< DMA_CINT.NOP Mask                       */
#define DMA_CINT_NOP_SHIFT                       (7U)                                                /*!< DMA_CINT.NOP Position                   */
#define DMA_CINT_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMA_CINT.NOP Field                      */
/* ------- INT Bit Fields                           ------ */
#define DMA_INT_INT0_MASK                        (0x1U)                                              /*!< DMA_INT.INT0 Mask                       */
#define DMA_INT_INT0_SHIFT                       (0U)                                                /*!< DMA_INT.INT0 Position                   */
#define DMA_INT_INT0(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< DMA_INT.INT0 Field                      */
#define DMA_INT_INT1_MASK                        (0x2U)                                              /*!< DMA_INT.INT1 Mask                       */
#define DMA_INT_INT1_SHIFT                       (1U)                                                /*!< DMA_INT.INT1 Position                   */
#define DMA_INT_INT1(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< DMA_INT.INT1 Field                      */
#define DMA_INT_INT2_MASK                        (0x4U)                                              /*!< DMA_INT.INT2 Mask                       */
#define DMA_INT_INT2_SHIFT                       (2U)                                                /*!< DMA_INT.INT2 Position                   */
#define DMA_INT_INT2(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< DMA_INT.INT2 Field                      */
#define DMA_INT_INT3_MASK                        (0x8U)                                              /*!< DMA_INT.INT3 Mask                       */
#define DMA_INT_INT3_SHIFT                       (3U)                                                /*!< DMA_INT.INT3 Position                   */
#define DMA_INT_INT3(x)                          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< DMA_INT.INT3 Field                      */
#define DMA_INT_INT4_MASK                        (0x10U)                                             /*!< DMA_INT.INT4 Mask                       */
#define DMA_INT_INT4_SHIFT                       (4U)                                                /*!< DMA_INT.INT4 Position                   */
#define DMA_INT_INT4(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< DMA_INT.INT4 Field                      */
#define DMA_INT_INT5_MASK                        (0x20U)                                             /*!< DMA_INT.INT5 Mask                       */
#define DMA_INT_INT5_SHIFT                       (5U)                                                /*!< DMA_INT.INT5 Position                   */
#define DMA_INT_INT5(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< DMA_INT.INT5 Field                      */
#define DMA_INT_INT6_MASK                        (0x40U)                                             /*!< DMA_INT.INT6 Mask                       */
#define DMA_INT_INT6_SHIFT                       (6U)                                                /*!< DMA_INT.INT6 Position                   */
#define DMA_INT_INT6(x)                          (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< DMA_INT.INT6 Field                      */
#define DMA_INT_INT7_MASK                        (0x80U)                                             /*!< DMA_INT.INT7 Mask                       */
#define DMA_INT_INT7_SHIFT                       (7U)                                                /*!< DMA_INT.INT7 Position                   */
#define DMA_INT_INT7(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< DMA_INT.INT7 Field                      */
/* ------- ERR Bit Fields                           ------ */
#define DMA_ERR_ERR0_MASK                        (0x1U)                                              /*!< DMA_ERR.ERR0 Mask                       */
#define DMA_ERR_ERR0_SHIFT                       (0U)                                                /*!< DMA_ERR.ERR0 Position                   */
#define DMA_ERR_ERR0(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< DMA_ERR.ERR0 Field                      */
#define DMA_ERR_ERR1_MASK                        (0x2U)                                              /*!< DMA_ERR.ERR1 Mask                       */
#define DMA_ERR_ERR1_SHIFT                       (1U)                                                /*!< DMA_ERR.ERR1 Position                   */
#define DMA_ERR_ERR1(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< DMA_ERR.ERR1 Field                      */
#define DMA_ERR_ERR2_MASK                        (0x4U)                                              /*!< DMA_ERR.ERR2 Mask                       */
#define DMA_ERR_ERR2_SHIFT                       (2U)                                                /*!< DMA_ERR.ERR2 Position                   */
#define DMA_ERR_ERR2(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< DMA_ERR.ERR2 Field                      */
#define DMA_ERR_ERR3_MASK                        (0x8U)                                              /*!< DMA_ERR.ERR3 Mask                       */
#define DMA_ERR_ERR3_SHIFT                       (3U)                                                /*!< DMA_ERR.ERR3 Position                   */
#define DMA_ERR_ERR3(x)                          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< DMA_ERR.ERR3 Field                      */
#define DMA_ERR_ERR4_MASK                        (0x10U)                                             /*!< DMA_ERR.ERR4 Mask                       */
#define DMA_ERR_ERR4_SHIFT                       (4U)                                                /*!< DMA_ERR.ERR4 Position                   */
#define DMA_ERR_ERR4(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< DMA_ERR.ERR4 Field                      */
#define DMA_ERR_ERR5_MASK                        (0x20U)                                             /*!< DMA_ERR.ERR5 Mask                       */
#define DMA_ERR_ERR5_SHIFT                       (5U)                                                /*!< DMA_ERR.ERR5 Position                   */
#define DMA_ERR_ERR5(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< DMA_ERR.ERR5 Field                      */
#define DMA_ERR_ERR6_MASK                        (0x40U)                                             /*!< DMA_ERR.ERR6 Mask                       */
#define DMA_ERR_ERR6_SHIFT                       (6U)                                                /*!< DMA_ERR.ERR6 Position                   */
#define DMA_ERR_ERR6(x)                          (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< DMA_ERR.ERR6 Field                      */
#define DMA_ERR_ERR7_MASK                        (0x80U)                                             /*!< DMA_ERR.ERR7 Mask                       */
#define DMA_ERR_ERR7_SHIFT                       (7U)                                                /*!< DMA_ERR.ERR7 Position                   */
#define DMA_ERR_ERR7(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< DMA_ERR.ERR7 Field                      */
/* ------- HRS Bit Fields                           ------ */
#define DMA_HRS_HRS0_MASK                        (0x1U)                                              /*!< DMA_HRS.HRS0 Mask                       */
#define DMA_HRS_HRS0_SHIFT                       (0U)                                                /*!< DMA_HRS.HRS0 Position                   */
#define DMA_HRS_HRS0(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< DMA_HRS.HRS0 Field                      */
#define DMA_HRS_HRS1_MASK                        (0x2U)                                              /*!< DMA_HRS.HRS1 Mask                       */
#define DMA_HRS_HRS1_SHIFT                       (1U)                                                /*!< DMA_HRS.HRS1 Position                   */
#define DMA_HRS_HRS1(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< DMA_HRS.HRS1 Field                      */
#define DMA_HRS_HRS2_MASK                        (0x4U)                                              /*!< DMA_HRS.HRS2 Mask                       */
#define DMA_HRS_HRS2_SHIFT                       (2U)                                                /*!< DMA_HRS.HRS2 Position                   */
#define DMA_HRS_HRS2(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< DMA_HRS.HRS2 Field                      */
#define DMA_HRS_HRS3_MASK                        (0x8U)                                              /*!< DMA_HRS.HRS3 Mask                       */
#define DMA_HRS_HRS3_SHIFT                       (3U)                                                /*!< DMA_HRS.HRS3 Position                   */
#define DMA_HRS_HRS3(x)                          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< DMA_HRS.HRS3 Field                      */
#define DMA_HRS_HRS4_MASK                        (0x10U)                                             /*!< DMA_HRS.HRS4 Mask                       */
#define DMA_HRS_HRS4_SHIFT                       (4U)                                                /*!< DMA_HRS.HRS4 Position                   */
#define DMA_HRS_HRS4(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< DMA_HRS.HRS4 Field                      */
#define DMA_HRS_HRS5_MASK                        (0x20U)                                             /*!< DMA_HRS.HRS5 Mask                       */
#define DMA_HRS_HRS5_SHIFT                       (5U)                                                /*!< DMA_HRS.HRS5 Position                   */
#define DMA_HRS_HRS5(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< DMA_HRS.HRS5 Field                      */
#define DMA_HRS_HRS6_MASK                        (0x40U)                                             /*!< DMA_HRS.HRS6 Mask                       */
#define DMA_HRS_HRS6_SHIFT                       (6U)                                                /*!< DMA_HRS.HRS6 Position                   */
#define DMA_HRS_HRS6(x)                          (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< DMA_HRS.HRS6 Field                      */
#define DMA_HRS_HRS7_MASK                        (0x80U)                                             /*!< DMA_HRS.HRS7 Mask                       */
#define DMA_HRS_HRS7_SHIFT                       (7U)                                                /*!< DMA_HRS.HRS7 Position                   */
#define DMA_HRS_HRS7(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< DMA_HRS.HRS7 Field                      */
/* ------- EARS Bit Fields                          ------ */
#define DMA_EARS_EDREQ_0_MASK                    (0x1U)                                              /*!< DMA_EARS.EDREQ_0 Mask                   */
#define DMA_EARS_EDREQ_0_SHIFT                   (0U)                                                /*!< DMA_EARS.EDREQ_0 Position               */
#define DMA_EARS_EDREQ_0(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< DMA_EARS.EDREQ_0 Field                  */
#define DMA_EARS_EDREQ_1_MASK                    (0x2U)                                              /*!< DMA_EARS.EDREQ_1 Mask                   */
#define DMA_EARS_EDREQ_1_SHIFT                   (1U)                                                /*!< DMA_EARS.EDREQ_1 Position               */
#define DMA_EARS_EDREQ_1(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< DMA_EARS.EDREQ_1 Field                  */
#define DMA_EARS_EDREQ_2_MASK                    (0x4U)                                              /*!< DMA_EARS.EDREQ_2 Mask                   */
#define DMA_EARS_EDREQ_2_SHIFT                   (2U)                                                /*!< DMA_EARS.EDREQ_2 Position               */
#define DMA_EARS_EDREQ_2(x)                      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< DMA_EARS.EDREQ_2 Field                  */
#define DMA_EARS_EDREQ_3_MASK                    (0x8U)                                              /*!< DMA_EARS.EDREQ_3 Mask                   */
#define DMA_EARS_EDREQ_3_SHIFT                   (3U)                                                /*!< DMA_EARS.EDREQ_3 Position               */
#define DMA_EARS_EDREQ_3(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< DMA_EARS.EDREQ_3 Field                  */
#define DMA_EARS_EDREQ_4_MASK                    (0x10U)                                             /*!< DMA_EARS.EDREQ_4 Mask                   */
#define DMA_EARS_EDREQ_4_SHIFT                   (4U)                                                /*!< DMA_EARS.EDREQ_4 Position               */
#define DMA_EARS_EDREQ_4(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< DMA_EARS.EDREQ_4 Field                  */
#define DMA_EARS_EDREQ_5_MASK                    (0x20U)                                             /*!< DMA_EARS.EDREQ_5 Mask                   */
#define DMA_EARS_EDREQ_5_SHIFT                   (5U)                                                /*!< DMA_EARS.EDREQ_5 Position               */
#define DMA_EARS_EDREQ_5(x)                      (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< DMA_EARS.EDREQ_5 Field                  */
#define DMA_EARS_EDREQ_6_MASK                    (0x40U)                                             /*!< DMA_EARS.EDREQ_6 Mask                   */
#define DMA_EARS_EDREQ_6_SHIFT                   (6U)                                                /*!< DMA_EARS.EDREQ_6 Position               */
#define DMA_EARS_EDREQ_6(x)                      (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< DMA_EARS.EDREQ_6 Field                  */
#define DMA_EARS_EDREQ_7_MASK                    (0x80U)                                             /*!< DMA_EARS.EDREQ_7 Mask                   */
#define DMA_EARS_EDREQ_7_SHIFT                   (7U)                                                /*!< DMA_EARS.EDREQ_7 Position               */
#define DMA_EARS_EDREQ_7(x)                      (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< DMA_EARS.EDREQ_7 Field                  */
/* ------- DCHPRI Bit Fields                        ------ */
#define DMA_DCHPRI_CHPRI_MASK                    (0x7U)                                              /*!< DMA_DCHPRI.CHPRI Mask                   */
#define DMA_DCHPRI_CHPRI_SHIFT                   (0U)                                                /*!< DMA_DCHPRI.CHPRI Position               */
#define DMA_DCHPRI_CHPRI(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< DMA_DCHPRI.CHPRI Field                  */
#define DMA_DCHPRI_DPA_MASK                      (0x40U)                                             /*!< DMA_DCHPRI.DPA Mask                     */
#define DMA_DCHPRI_DPA_SHIFT                     (6U)                                                /*!< DMA_DCHPRI.DPA Position                 */
#define DMA_DCHPRI_DPA(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA_DCHPRI.DPA Field                    */
#define DMA_DCHPRI_ECP_MASK                      (0x80U)                                             /*!< DMA_DCHPRI.ECP Mask                     */
#define DMA_DCHPRI_ECP_SHIFT                     (7U)                                                /*!< DMA_DCHPRI.ECP Position                 */
#define DMA_DCHPRI_ECP(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMA_DCHPRI.ECP Field                    */
/* ------- SADDR Bit Fields                         ------ */
#define DMA_SADDR_SADDR_MASK                     (0xFFFFFFFFU)                                       /*!< DMA_SADDR.SADDR Mask                    */
#define DMA_SADDR_SADDR_SHIFT                    (0U)                                                /*!< DMA_SADDR.SADDR Position                */
#define DMA_SADDR_SADDR(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< DMA_SADDR.SADDR Field                   */
/* ------- SOFF Bit Fields                          ------ */
#define DMA_SOFF_SOFF_MASK                       (0xFFFFU)                                           /*!< DMA_SOFF.SOFF Mask                      */
#define DMA_SOFF_SOFF_SHIFT                      (0U)                                                /*!< DMA_SOFF.SOFF Position                  */
#define DMA_SOFF_SOFF(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< DMA_SOFF.SOFF Field                     */
/* ------- ATTR Bit Fields                          ------ */
#define DMA_ATTR_DSIZE_MASK                      (0x7U)                                              /*!< DMA_ATTR.DSIZE Mask                     */
#define DMA_ATTR_DSIZE_SHIFT                     (0U)                                                /*!< DMA_ATTR.DSIZE Position                 */
#define DMA_ATTR_DSIZE(x)                        (((uint16_t)(((uint16_t)(x))<<0U))&0x7UL)           /*!< DMA_ATTR.DSIZE Field                    */
#define DMA_ATTR_DMOD_MASK                       (0xF8U)                                             /*!< DMA_ATTR.DMOD Mask                      */
#define DMA_ATTR_DMOD_SHIFT                      (3U)                                                /*!< DMA_ATTR.DMOD Position                  */
#define DMA_ATTR_DMOD(x)                         (((uint16_t)(((uint16_t)(x))<<3U))&0xF8UL)          /*!< DMA_ATTR.DMOD Field                     */
#define DMA_ATTR_SSIZE_MASK                      (0x700U)                                            /*!< DMA_ATTR.SSIZE Mask                     */
#define DMA_ATTR_SSIZE_SHIFT                     (8U)                                                /*!< DMA_ATTR.SSIZE Position                 */
#define DMA_ATTR_SSIZE(x)                        (((uint16_t)(((uint16_t)(x))<<8U))&0x700UL)         /*!< DMA_ATTR.SSIZE Field                    */
#define DMA_ATTR_SMOD_MASK                       (0xF800U)                                           /*!< DMA_ATTR.SMOD Mask                      */
#define DMA_ATTR_SMOD_SHIFT                      (11U)                                               /*!< DMA_ATTR.SMOD Position                  */
#define DMA_ATTR_SMOD(x)                         (((uint16_t)(((uint16_t)(x))<<11U))&0xF800UL)       /*!< DMA_ATTR.SMOD Field                     */
/* ------- NBYTES_MLNO Bit Fields                   ------ */
#define DMA_NBYTES_MLNO_NBYTES_MASK              (0xFFFFFFFFU)                                       /*!< DMA_NBYTES_MLNO.NBYTES Mask             */
#define DMA_NBYTES_MLNO_NBYTES_SHIFT             (0U)                                                /*!< DMA_NBYTES_MLNO.NBYTES Position         */
#define DMA_NBYTES_MLNO_NBYTES(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< DMA_NBYTES_MLNO.NBYTES Field            */
/* ------- NBYTES_MLOFFNO Bit Fields                ------ */
#define DMA_NBYTES_MLOFFNO_NBYTES_MASK           (0x3FFFFFFFU)                                       /*!< DMA_NBYTES_MLOFFNO.NBYTES Mask          */
#define DMA_NBYTES_MLOFFNO_NBYTES_SHIFT          (0U)                                                /*!< DMA_NBYTES_MLOFFNO.NBYTES Position      */
#define DMA_NBYTES_MLOFFNO_NBYTES(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFFFFFFUL)    /*!< DMA_NBYTES_MLOFFNO.NBYTES Field         */
#define DMA_NBYTES_MLOFFNO_DMLOE_MASK            (0x40000000U)                                       /*!< DMA_NBYTES_MLOFFNO.DMLOE Mask           */
#define DMA_NBYTES_MLOFFNO_DMLOE_SHIFT           (30U)                                               /*!< DMA_NBYTES_MLOFFNO.DMLOE Position       */
#define DMA_NBYTES_MLOFFNO_DMLOE(x)              (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< DMA_NBYTES_MLOFFNO.DMLOE Field          */
#define DMA_NBYTES_MLOFFNO_SMLOE_MASK            (0x80000000U)                                       /*!< DMA_NBYTES_MLOFFNO.SMLOE Mask           */
#define DMA_NBYTES_MLOFFNO_SMLOE_SHIFT           (31U)                                               /*!< DMA_NBYTES_MLOFFNO.SMLOE Position       */
#define DMA_NBYTES_MLOFFNO_SMLOE(x)              (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< DMA_NBYTES_MLOFFNO.SMLOE Field          */
/* ------- NBYTES_MLOFFYES Bit Fields               ------ */
#define DMA_NBYTES_MLOFFYES_NBYTES_MASK          (0x3FFU)                                            /*!< DMA_NBYTES_MLOFFYES.NBYTES Mask         */
#define DMA_NBYTES_MLOFFYES_NBYTES_SHIFT         (0U)                                                /*!< DMA_NBYTES_MLOFFYES.NBYTES Position     */
#define DMA_NBYTES_MLOFFYES_NBYTES(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFUL)         /*!< DMA_NBYTES_MLOFFYES.NBYTES Field        */
#define DMA_NBYTES_MLOFFYES_MLOFF_MASK           (0x3FFFFC00U)                                       /*!< DMA_NBYTES_MLOFFYES.MLOFF Mask          */
#define DMA_NBYTES_MLOFFYES_MLOFF_SHIFT          (10U)                                               /*!< DMA_NBYTES_MLOFFYES.MLOFF Position      */
#define DMA_NBYTES_MLOFFYES_MLOFF(x)             (((uint32_t)(((uint32_t)(x))<<10U))&0x3FFFFC00UL)   /*!< DMA_NBYTES_MLOFFYES.MLOFF Field         */
#define DMA_NBYTES_MLOFFYES_DMLOE_MASK           (0x40000000U)                                       /*!< DMA_NBYTES_MLOFFYES.DMLOE Mask          */
#define DMA_NBYTES_MLOFFYES_DMLOE_SHIFT          (30U)                                               /*!< DMA_NBYTES_MLOFFYES.DMLOE Position      */
#define DMA_NBYTES_MLOFFYES_DMLOE(x)             (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< DMA_NBYTES_MLOFFYES.DMLOE Field         */
#define DMA_NBYTES_MLOFFYES_SMLOE_MASK           (0x80000000U)                                       /*!< DMA_NBYTES_MLOFFYES.SMLOE Mask          */
#define DMA_NBYTES_MLOFFYES_SMLOE_SHIFT          (31U)                                               /*!< DMA_NBYTES_MLOFFYES.SMLOE Position      */
#define DMA_NBYTES_MLOFFYES_SMLOE(x)             (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< DMA_NBYTES_MLOFFYES.SMLOE Field         */
/* ------- SLAST Bit Fields                         ------ */
#define DMA_SLAST_SLAST_MASK                     (0xFFFFFFFFU)                                       /*!< DMA_SLAST.SLAST Mask                    */
#define DMA_SLAST_SLAST_SHIFT                    (0U)                                                /*!< DMA_SLAST.SLAST Position                */
#define DMA_SLAST_SLAST(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< DMA_SLAST.SLAST Field                   */
/* ------- DADDR Bit Fields                         ------ */
#define DMA_DADDR_DADDR_MASK                     (0xFFFFFFFFU)                                       /*!< DMA_DADDR.DADDR Mask                    */
#define DMA_DADDR_DADDR_SHIFT                    (0U)                                                /*!< DMA_DADDR.DADDR Position                */
#define DMA_DADDR_DADDR(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< DMA_DADDR.DADDR Field                   */
/* ------- DOFF Bit Fields                          ------ */
#define DMA_DOFF_DOFF_MASK                       (0xFFFFU)                                           /*!< DMA_DOFF.DOFF Mask                      */
#define DMA_DOFF_DOFF_SHIFT                      (0U)                                                /*!< DMA_DOFF.DOFF Position                  */
#define DMA_DOFF_DOFF(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< DMA_DOFF.DOFF Field                     */
/* ------- CITER_ELINKNO Bit Fields                 ------ */
#define DMA_CITER_ELINKNO_CITER_MASK             (0x7FFFU)                                           /*!< DMA_CITER_ELINKNO.CITER Mask            */
#define DMA_CITER_ELINKNO_CITER_SHIFT            (0U)                                                /*!< DMA_CITER_ELINKNO.CITER Position        */
#define DMA_CITER_ELINKNO_CITER(x)               (((uint16_t)(((uint16_t)(x))<<0U))&0x7FFFUL)        /*!< DMA_CITER_ELINKNO.CITER Field           */
#define DMA_CITER_ELINKNO_ELINK_MASK             (0x8000U)                                           /*!< DMA_CITER_ELINKNO.ELINK Mask            */
#define DMA_CITER_ELINKNO_ELINK_SHIFT            (15U)                                               /*!< DMA_CITER_ELINKNO.ELINK Position        */
#define DMA_CITER_ELINKNO_ELINK(x)               (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< DMA_CITER_ELINKNO.ELINK Field           */
/* ------- CITER_ELINKYES Bit Fields                ------ */
#define DMA_CITER_ELINKYES_CITER_MASK            (0x1FFU)                                            /*!< DMA_CITER_ELINKYES.CITER Mask           */
#define DMA_CITER_ELINKYES_CITER_SHIFT           (0U)                                                /*!< DMA_CITER_ELINKYES.CITER Position       */
#define DMA_CITER_ELINKYES_CITER(x)              (((uint16_t)(((uint16_t)(x))<<0U))&0x1FFUL)         /*!< DMA_CITER_ELINKYES.CITER Field          */
#define DMA_CITER_ELINKYES_LINKCH_MASK           (0xE00U)                                            /*!< DMA_CITER_ELINKYES.LINKCH Mask          */
#define DMA_CITER_ELINKYES_LINKCH_SHIFT          (9U)                                                /*!< DMA_CITER_ELINKYES.LINKCH Position      */
#define DMA_CITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x))<<9U))&0xE00UL)         /*!< DMA_CITER_ELINKYES.LINKCH Field         */
#define DMA_CITER_ELINKYES_ELINK_MASK            (0x8000U)                                           /*!< DMA_CITER_ELINKYES.ELINK Mask           */
#define DMA_CITER_ELINKYES_ELINK_SHIFT           (15U)                                               /*!< DMA_CITER_ELINKYES.ELINK Position       */
#define DMA_CITER_ELINKYES_ELINK(x)              (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< DMA_CITER_ELINKYES.ELINK Field          */
/* ------- DLASTSGA Bit Fields                      ------ */
#define DMA_DLASTSGA_DLASTSGA_MASK               (0xFFFFFFFFU)                                       /*!< DMA_DLASTSGA.DLASTSGA Mask              */
#define DMA_DLASTSGA_DLASTSGA_SHIFT              (0U)                                                /*!< DMA_DLASTSGA.DLASTSGA Position          */
#define DMA_DLASTSGA_DLASTSGA(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< DMA_DLASTSGA.DLASTSGA Field             */
/* ------- CSR Bit Fields                           ------ */
#define DMA_CSR_START_MASK                       (0x1U)                                              /*!< DMA_CSR.START Mask                      */
#define DMA_CSR_START_SHIFT                      (0U)                                                /*!< DMA_CSR.START Position                  */
#define DMA_CSR_START(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< DMA_CSR.START Field                     */
#define DMA_CSR_INTMAJOR_MASK                    (0x2U)                                              /*!< DMA_CSR.INTMAJOR Mask                   */
#define DMA_CSR_INTMAJOR_SHIFT                   (1U)                                                /*!< DMA_CSR.INTMAJOR Position               */
#define DMA_CSR_INTMAJOR(x)                      (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< DMA_CSR.INTMAJOR Field                  */
#define DMA_CSR_INTHALF_MASK                     (0x4U)                                              /*!< DMA_CSR.INTHALF Mask                    */
#define DMA_CSR_INTHALF_SHIFT                    (2U)                                                /*!< DMA_CSR.INTHALF Position                */
#define DMA_CSR_INTHALF(x)                       (((uint16_t)(((uint16_t)(x))<<2U))&0x4UL)           /*!< DMA_CSR.INTHALF Field                   */
#define DMA_CSR_DREQ_MASK                        (0x8U)                                              /*!< DMA_CSR.DREQ Mask                       */
#define DMA_CSR_DREQ_SHIFT                       (3U)                                                /*!< DMA_CSR.DREQ Position                   */
#define DMA_CSR_DREQ(x)                          (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< DMA_CSR.DREQ Field                      */
#define DMA_CSR_ESG_MASK                         (0x10U)                                             /*!< DMA_CSR.ESG Mask                        */
#define DMA_CSR_ESG_SHIFT                        (4U)                                                /*!< DMA_CSR.ESG Position                    */
#define DMA_CSR_ESG(x)                           (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< DMA_CSR.ESG Field                       */
#define DMA_CSR_MAJORELINK_MASK                  (0x20U)                                             /*!< DMA_CSR.MAJORELINK Mask                 */
#define DMA_CSR_MAJORELINK_SHIFT                 (5U)                                                /*!< DMA_CSR.MAJORELINK Position             */
#define DMA_CSR_MAJORELINK(x)                    (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< DMA_CSR.MAJORELINK Field                */
#define DMA_CSR_ACTIVE_MASK                      (0x40U)                                             /*!< DMA_CSR.ACTIVE Mask                     */
#define DMA_CSR_ACTIVE_SHIFT                     (6U)                                                /*!< DMA_CSR.ACTIVE Position                 */
#define DMA_CSR_ACTIVE(x)                        (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< DMA_CSR.ACTIVE Field                    */
#define DMA_CSR_DONE_MASK                        (0x80U)                                             /*!< DMA_CSR.DONE Mask                       */
#define DMA_CSR_DONE_SHIFT                       (7U)                                                /*!< DMA_CSR.DONE Position                   */
#define DMA_CSR_DONE(x)                          (((uint16_t)(((uint16_t)(x))<<7U))&0x80UL)          /*!< DMA_CSR.DONE Field                      */
#define DMA_CSR_MAJORLINKCH_MASK                 (0x700U)                                            /*!< DMA_CSR.MAJORLINKCH Mask                */
#define DMA_CSR_MAJORLINKCH_SHIFT                (8U)                                                /*!< DMA_CSR.MAJORLINKCH Position            */
#define DMA_CSR_MAJORLINKCH(x)                   (((uint16_t)(((uint16_t)(x))<<8U))&0x700UL)         /*!< DMA_CSR.MAJORLINKCH Field               */
#define DMA_CSR_BWC_MASK                         (0xC000U)                                           /*!< DMA_CSR.BWC Mask                        */
#define DMA_CSR_BWC_SHIFT                        (14U)                                               /*!< DMA_CSR.BWC Position                    */
#define DMA_CSR_BWC(x)                           (((uint16_t)(((uint16_t)(x))<<14U))&0xC000UL)       /*!< DMA_CSR.BWC Field                       */
/* ------- BITER_ELINKNO Bit Fields                 ------ */
#define DMA_BITER_ELINKNO_BITER_MASK             (0x7FFFU)                                           /*!< DMA_BITER_ELINKNO.BITER Mask            */
#define DMA_BITER_ELINKNO_BITER_SHIFT            (0U)                                                /*!< DMA_BITER_ELINKNO.BITER Position        */
#define DMA_BITER_ELINKNO_BITER(x)               (((uint16_t)(((uint16_t)(x))<<0U))&0x7FFFUL)        /*!< DMA_BITER_ELINKNO.BITER Field           */
#define DMA_BITER_ELINKNO_ELINK_MASK             (0x8000U)                                           /*!< DMA_BITER_ELINKNO.ELINK Mask            */
#define DMA_BITER_ELINKNO_ELINK_SHIFT            (15U)                                               /*!< DMA_BITER_ELINKNO.ELINK Position        */
#define DMA_BITER_ELINKNO_ELINK(x)               (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< DMA_BITER_ELINKNO.ELINK Field           */
/* ------- BITER_ELINKYES Bit Fields                ------ */
#define DMA_BITER_ELINKYES_BITER_MASK            (0x1FFU)                                            /*!< DMA_BITER_ELINKYES.BITER Mask           */
#define DMA_BITER_ELINKYES_BITER_SHIFT           (0U)                                                /*!< DMA_BITER_ELINKYES.BITER Position       */
#define DMA_BITER_ELINKYES_BITER(x)              (((uint16_t)(((uint16_t)(x))<<0U))&0x1FFUL)         /*!< DMA_BITER_ELINKYES.BITER Field          */
#define DMA_BITER_ELINKYES_LINKCH_MASK           (0xE00U)                                            /*!< DMA_BITER_ELINKYES.LINKCH Mask          */
#define DMA_BITER_ELINKYES_LINKCH_SHIFT          (9U)                                                /*!< DMA_BITER_ELINKYES.LINKCH Position      */
#define DMA_BITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x))<<9U))&0xE00UL)         /*!< DMA_BITER_ELINKYES.LINKCH Field         */
#define DMA_BITER_ELINKYES_ELINK_MASK            (0x8000U)                                           /*!< DMA_BITER_ELINKYES.ELINK Mask           */
#define DMA_BITER_ELINKYES_ELINK_SHIFT           (15U)                                               /*!< DMA_BITER_ELINKYES.ELINK Position       */
#define DMA_BITER_ELINKYES_ELINK(x)              (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< DMA_BITER_ELINKYES.ELINK Field          */
/**
 * @} */ /* End group DMA_Register_Masks_GROUP 
 */

/* DMA - Peripheral instance base addresses */
#define DMA_BasePtr                    0x40008000UL //!< Peripheral base address
#define DMA                            ((DMA_Type *) DMA_BasePtr) //!< Freescale base pointer
#define DMA_BASE_PTR                   (DMA) //!< Freescale style base pointer
/**
 * @} */ /* End group DMA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMAMUX_Peripheral_access_layer_GROUP DMAMUX Peripheral Access Layer
* @brief C Struct for DMAMUX
* @{
*/

/* ================================================================================ */
/* ================           DMAMUX (file:DMAMUX_MKL82Z7)         ================ */
/* ================================================================================ */

/**
 * @brief DMA channel multiplexor
 */
/**
* @addtogroup DMAMUX_structs_GROUP DMAMUX struct
* @brief Struct for DMAMUX
* @{
*/
typedef struct {                                /*       DMAMUX Structure                                             */
   __IO uint8_t   CHCFG[8];                     /**< 0000: Channel Configuration register                               */
} DMAMUX_Type;

/**
 * @} */ /* End group DMAMUX_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DMAMUX' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DMAMUX_Register_Masks_GROUP DMAMUX Register Masks
* @brief Register Masks for DMAMUX
* @{
*/
/* ------- CHCFG Bit Fields                         ------ */
#define DMAMUX_CHCFG_SOURCE_MASK                 (0x3FU)                                             /*!< DMAMUX_CHCFG.SOURCE Mask                */
#define DMAMUX_CHCFG_SOURCE_SHIFT                (0U)                                                /*!< DMAMUX_CHCFG.SOURCE Position            */
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint8_t)(((uint8_t)(x))<<0U))&0x3FUL)            /*!< DMAMUX_CHCFG.SOURCE Field               */
#define DMAMUX_CHCFG_TRIG_MASK                   (0x40U)                                             /*!< DMAMUX_CHCFG.TRIG Mask                  */
#define DMAMUX_CHCFG_TRIG_SHIFT                  (6U)                                                /*!< DMAMUX_CHCFG.TRIG Position              */
#define DMAMUX_CHCFG_TRIG(x)                     (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMAMUX_CHCFG.TRIG Field                 */
#define DMAMUX_CHCFG_ENBL_MASK                   (0x80U)                                             /*!< DMAMUX_CHCFG.ENBL Mask                  */
#define DMAMUX_CHCFG_ENBL_SHIFT                  (7U)                                                /*!< DMAMUX_CHCFG.ENBL Position              */
#define DMAMUX_CHCFG_ENBL(x)                     (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMAMUX_CHCFG.ENBL Field                 */
/**
 * @} */ /* End group DMAMUX_Register_Masks_GROUP 
 */

/* DMAMUX - Peripheral instance base addresses */
#define DMAMUX_BasePtr                 0x40021000UL //!< Peripheral base address
#define DMAMUX                         ((DMAMUX_Type *) DMAMUX_BasePtr) //!< Freescale base pointer
#define DMAMUX_BASE_PTR                (DMAMUX) //!< Freescale style base pointer
/**
 * @} */ /* End group DMAMUX_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup EMVSIM_Peripheral_access_layer_GROUP EMVSIM Peripheral Access Layer
* @brief C Struct for EMVSIM
* @{
*/

/* ================================================================================ */
/* ================           EMVSIM0 (file:EMVSIM0_MKL82Z7)       ================ */
/* ================================================================================ */

/**
 * @brief EMVSIM
 */
/**
* @addtogroup EMVSIM_structs_GROUP EMVSIM struct
* @brief Struct for EMVSIM
* @{
*/
typedef struct {                                /*       EMVSIM0 Structure                                            */
   __I  uint32_t  VER_ID;                       /**< 0000: Version ID Register                                          */
   __I  uint32_t  PARAM;                        /**< 0004: Parameter Register                                           */
   __IO uint32_t  CLKCFG;                       /**< 0008: Clock Configuration Register                                 */
   __IO uint32_t  DIVISOR;                      /**< 000C: Baud Rate Divisor Register                                   */
   __IO uint32_t  CTRL;                         /**< 0010: Control Register                                             */
   __IO uint32_t  INT_MASK;                     /**< 0014: Interrupt Mask Register                                      */
   __IO uint32_t  RX_THD;                       /**< 0018: Receiver Threshold Register                                  */
   __IO uint32_t  TX_THD;                       /**< 001C: Transmitter Threshold Register                               */
   __IO uint32_t  RX_STATUS;                    /**< 0020: Receive Status Register                                      */
   __IO uint32_t  TX_STATUS;                    /**< 0024: Transmitter Status Register                                  */
   __IO uint32_t  PCSR;                         /**< 0028: Port Control and Status Register                             */
   __I  uint32_t  RX_BUF;                       /**< 002C: Receive Data Read Buffer                                     */
   __O  uint32_t  TX_BUF;                       /**< 0030: Transmit Data Buffer                                         */
   __IO uint32_t  TX_GETU;                      /**< 0034: Transmitter Guard ETU Value Register                         */
   __IO uint32_t  CWT_VAL;                      /**< 0038: Character Wait Time Value Register                           */
   __IO uint32_t  BWT_VAL;                      /**< 003C: Block Wait Time Value Register                               */
   __IO uint32_t  BGT_VAL;                      /**< 0040: Block Guard Time Value Register                              */
   __IO uint32_t  GPCNT0_VAL;                   /**< 0044: General Purpose Counter 0 Timeout Value Register             */
   __IO uint32_t  GPCNT1_VAL;                   /**< 0048: General Purpose Counter 1 Timeout Value                      */
} EMVSIM_Type;

/**
 * @} */ /* End group EMVSIM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'EMVSIM0' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup EMVSIM_Register_Masks_GROUP EMVSIM Register Masks
* @brief Register Masks for EMVSIM
* @{
*/
/* ------- VER_ID Bit Fields                        ------ */
#define EMVSIM_VER_ID_VER_MASK                   (0xFFFFFFFFU)                                       /*!< EMVSIM0_VER_ID.VER Mask                 */
#define EMVSIM_VER_ID_VER_SHIFT                  (0U)                                                /*!< EMVSIM0_VER_ID.VER Position             */
#define EMVSIM_VER_ID_VER(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< EMVSIM0_VER_ID.VER Field                */
/* ------- PARAM Bit Fields                         ------ */
#define EMVSIM_PARAM_RX_FIFO_DEPTH_MASK          (0xFFU)                                             /*!< EMVSIM0_PARAM.RX_FIFO_DEPTH Mask        */
#define EMVSIM_PARAM_RX_FIFO_DEPTH_SHIFT         (0U)                                                /*!< EMVSIM0_PARAM.RX_FIFO_DEPTH Position    */
#define EMVSIM_PARAM_RX_FIFO_DEPTH(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< EMVSIM0_PARAM.RX_FIFO_DEPTH Field       */
#define EMVSIM_PARAM_TX_FIFO_DEPTH_MASK          (0xFF00U)                                           /*!< EMVSIM0_PARAM.TX_FIFO_DEPTH Mask        */
#define EMVSIM_PARAM_TX_FIFO_DEPTH_SHIFT         (8U)                                                /*!< EMVSIM0_PARAM.TX_FIFO_DEPTH Position    */
#define EMVSIM_PARAM_TX_FIFO_DEPTH(x)            (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< EMVSIM0_PARAM.TX_FIFO_DEPTH Field       */
/* ------- CLKCFG Bit Fields                        ------ */
#define EMVSIM_CLKCFG_CLK_PRSC_MASK              (0xFFU)                                             /*!< EMVSIM0_CLKCFG.CLK_PRSC Mask            */
#define EMVSIM_CLKCFG_CLK_PRSC_SHIFT             (0U)                                                /*!< EMVSIM0_CLKCFG.CLK_PRSC Position        */
#define EMVSIM_CLKCFG_CLK_PRSC(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< EMVSIM0_CLKCFG.CLK_PRSC Field           */
#define EMVSIM_CLKCFG_GPCNT1_CLK_SEL_MASK        (0x300U)                                            /*!< EMVSIM0_CLKCFG.GPCNT1_CLK_SEL Mask      */
#define EMVSIM_CLKCFG_GPCNT1_CLK_SEL_SHIFT       (8U)                                                /*!< EMVSIM0_CLKCFG.GPCNT1_CLK_SEL Position  */
#define EMVSIM_CLKCFG_GPCNT1_CLK_SEL(x)          (((uint32_t)(((uint32_t)(x))<<8U))&0x300UL)         /*!< EMVSIM0_CLKCFG.GPCNT1_CLK_SEL Field     */
#define EMVSIM_CLKCFG_GPCNT0_CLK_SEL_MASK        (0xC00U)                                            /*!< EMVSIM0_CLKCFG.GPCNT0_CLK_SEL Mask      */
#define EMVSIM_CLKCFG_GPCNT0_CLK_SEL_SHIFT       (10U)                                               /*!< EMVSIM0_CLKCFG.GPCNT0_CLK_SEL Position  */
#define EMVSIM_CLKCFG_GPCNT0_CLK_SEL(x)          (((uint32_t)(((uint32_t)(x))<<10U))&0xC00UL)        /*!< EMVSIM0_CLKCFG.GPCNT0_CLK_SEL Field     */
/* ------- DIVISOR Bit Fields                       ------ */
#define EMVSIM_DIVISOR_DIVISOR_VALUE_MASK        (0x1FFU)                                            /*!< EMVSIM0_DIVISOR.DIVISOR_VALUE Mask      */
#define EMVSIM_DIVISOR_DIVISOR_VALUE_SHIFT       (0U)                                                /*!< EMVSIM0_DIVISOR.DIVISOR_VALUE Position  */
#define EMVSIM_DIVISOR_DIVISOR_VALUE(x)          (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFUL)         /*!< EMVSIM0_DIVISOR.DIVISOR_VALUE Field     */
/* ------- CTRL Bit Fields                          ------ */
#define EMVSIM_CTRL_IC_MASK                      (0x1U)                                              /*!< EMVSIM0_CTRL.IC Mask                    */
#define EMVSIM_CTRL_IC_SHIFT                     (0U)                                                /*!< EMVSIM0_CTRL.IC Position                */
#define EMVSIM_CTRL_IC(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< EMVSIM0_CTRL.IC Field                   */
#define EMVSIM_CTRL_ICM_MASK                     (0x2U)                                              /*!< EMVSIM0_CTRL.ICM Mask                   */
#define EMVSIM_CTRL_ICM_SHIFT                    (1U)                                                /*!< EMVSIM0_CTRL.ICM Position               */
#define EMVSIM_CTRL_ICM(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< EMVSIM0_CTRL.ICM Field                  */
#define EMVSIM_CTRL_ANACK_MASK                   (0x4U)                                              /*!< EMVSIM0_CTRL.ANACK Mask                 */
#define EMVSIM_CTRL_ANACK_SHIFT                  (2U)                                                /*!< EMVSIM0_CTRL.ANACK Position             */
#define EMVSIM_CTRL_ANACK(x)                     (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< EMVSIM0_CTRL.ANACK Field                */
#define EMVSIM_CTRL_ONACK_MASK                   (0x8U)                                              /*!< EMVSIM0_CTRL.ONACK Mask                 */
#define EMVSIM_CTRL_ONACK_SHIFT                  (3U)                                                /*!< EMVSIM0_CTRL.ONACK Position             */
#define EMVSIM_CTRL_ONACK(x)                     (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< EMVSIM0_CTRL.ONACK Field                */
#define EMVSIM_CTRL_FLSH_RX_MASK                 (0x100U)                                            /*!< EMVSIM0_CTRL.FLSH_RX Mask               */
#define EMVSIM_CTRL_FLSH_RX_SHIFT                (8U)                                                /*!< EMVSIM0_CTRL.FLSH_RX Position           */
#define EMVSIM_CTRL_FLSH_RX(x)                   (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< EMVSIM0_CTRL.FLSH_RX Field              */
#define EMVSIM_CTRL_FLSH_TX_MASK                 (0x200U)                                            /*!< EMVSIM0_CTRL.FLSH_TX Mask               */
#define EMVSIM_CTRL_FLSH_TX_SHIFT                (9U)                                                /*!< EMVSIM0_CTRL.FLSH_TX Position           */
#define EMVSIM_CTRL_FLSH_TX(x)                   (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< EMVSIM0_CTRL.FLSH_TX Field              */
#define EMVSIM_CTRL_SW_RST_MASK                  (0x400U)                                            /*!< EMVSIM0_CTRL.SW_RST Mask                */
#define EMVSIM_CTRL_SW_RST_SHIFT                 (10U)                                               /*!< EMVSIM0_CTRL.SW_RST Position            */
#define EMVSIM_CTRL_SW_RST(x)                    (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< EMVSIM0_CTRL.SW_RST Field               */
#define EMVSIM_CTRL_KILL_CLOCKS_MASK             (0x800U)                                            /*!< EMVSIM0_CTRL.KILL_CLOCKS Mask           */
#define EMVSIM_CTRL_KILL_CLOCKS_SHIFT            (11U)                                               /*!< EMVSIM0_CTRL.KILL_CLOCKS Position       */
#define EMVSIM_CTRL_KILL_CLOCKS(x)               (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< EMVSIM0_CTRL.KILL_CLOCKS Field          */
#define EMVSIM_CTRL_DOZE_EN_MASK                 (0x1000U)                                           /*!< EMVSIM0_CTRL.DOZE_EN Mask               */
#define EMVSIM_CTRL_DOZE_EN_SHIFT                (12U)                                               /*!< EMVSIM0_CTRL.DOZE_EN Position           */
#define EMVSIM_CTRL_DOZE_EN(x)                   (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< EMVSIM0_CTRL.DOZE_EN Field              */
#define EMVSIM_CTRL_STOP_EN_MASK                 (0x2000U)                                           /*!< EMVSIM0_CTRL.STOP_EN Mask               */
#define EMVSIM_CTRL_STOP_EN_SHIFT                (13U)                                               /*!< EMVSIM0_CTRL.STOP_EN Position           */
#define EMVSIM_CTRL_STOP_EN(x)                   (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< EMVSIM0_CTRL.STOP_EN Field              */
#define EMVSIM_CTRL_RCV_EN_MASK                  (0x10000U)                                          /*!< EMVSIM0_CTRL.RCV_EN Mask                */
#define EMVSIM_CTRL_RCV_EN_SHIFT                 (16U)                                               /*!< EMVSIM0_CTRL.RCV_EN Position            */
#define EMVSIM_CTRL_RCV_EN(x)                    (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< EMVSIM0_CTRL.RCV_EN Field               */
#define EMVSIM_CTRL_XMT_EN_MASK                  (0x20000U)                                          /*!< EMVSIM0_CTRL.XMT_EN Mask                */
#define EMVSIM_CTRL_XMT_EN_SHIFT                 (17U)                                               /*!< EMVSIM0_CTRL.XMT_EN Position            */
#define EMVSIM_CTRL_XMT_EN(x)                    (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< EMVSIM0_CTRL.XMT_EN Field               */
#define EMVSIM_CTRL_RCVR_11_MASK                 (0x40000U)                                          /*!< EMVSIM0_CTRL.RCVR_11 Mask               */
#define EMVSIM_CTRL_RCVR_11_SHIFT                (18U)                                               /*!< EMVSIM0_CTRL.RCVR_11 Position           */
#define EMVSIM_CTRL_RCVR_11(x)                   (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< EMVSIM0_CTRL.RCVR_11 Field              */
#define EMVSIM_CTRL_RX_DMA_EN_MASK               (0x80000U)                                          /*!< EMVSIM0_CTRL.RX_DMA_EN Mask             */
#define EMVSIM_CTRL_RX_DMA_EN_SHIFT              (19U)                                               /*!< EMVSIM0_CTRL.RX_DMA_EN Position         */
#define EMVSIM_CTRL_RX_DMA_EN(x)                 (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< EMVSIM0_CTRL.RX_DMA_EN Field            */
#define EMVSIM_CTRL_TX_DMA_EN_MASK               (0x100000U)                                         /*!< EMVSIM0_CTRL.TX_DMA_EN Mask             */
#define EMVSIM_CTRL_TX_DMA_EN_SHIFT              (20U)                                               /*!< EMVSIM0_CTRL.TX_DMA_EN Position         */
#define EMVSIM_CTRL_TX_DMA_EN(x)                 (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< EMVSIM0_CTRL.TX_DMA_EN Field            */
#define EMVSIM_CTRL_INV_CRC_VAL_MASK             (0x1000000U)                                        /*!< EMVSIM0_CTRL.INV_CRC_VAL Mask           */
#define EMVSIM_CTRL_INV_CRC_VAL_SHIFT            (24U)                                               /*!< EMVSIM0_CTRL.INV_CRC_VAL Position       */
#define EMVSIM_CTRL_INV_CRC_VAL(x)               (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< EMVSIM0_CTRL.INV_CRC_VAL Field          */
#define EMVSIM_CTRL_CRC_OUT_FLIP_MASK            (0x2000000U)                                        /*!< EMVSIM0_CTRL.CRC_OUT_FLIP Mask          */
#define EMVSIM_CTRL_CRC_OUT_FLIP_SHIFT           (25U)                                               /*!< EMVSIM0_CTRL.CRC_OUT_FLIP Position      */
#define EMVSIM_CTRL_CRC_OUT_FLIP(x)              (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< EMVSIM0_CTRL.CRC_OUT_FLIP Field         */
#define EMVSIM_CTRL_CRC_IN_FLIP_MASK             (0x4000000U)                                        /*!< EMVSIM0_CTRL.CRC_IN_FLIP Mask           */
#define EMVSIM_CTRL_CRC_IN_FLIP_SHIFT            (26U)                                               /*!< EMVSIM0_CTRL.CRC_IN_FLIP Position       */
#define EMVSIM_CTRL_CRC_IN_FLIP(x)               (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< EMVSIM0_CTRL.CRC_IN_FLIP Field          */
#define EMVSIM_CTRL_CWT_EN_MASK                  (0x8000000U)                                        /*!< EMVSIM0_CTRL.CWT_EN Mask                */
#define EMVSIM_CTRL_CWT_EN_SHIFT                 (27U)                                               /*!< EMVSIM0_CTRL.CWT_EN Position            */
#define EMVSIM_CTRL_CWT_EN(x)                    (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< EMVSIM0_CTRL.CWT_EN Field               */
#define EMVSIM_CTRL_LRC_EN_MASK                  (0x10000000U)                                       /*!< EMVSIM0_CTRL.LRC_EN Mask                */
#define EMVSIM_CTRL_LRC_EN_SHIFT                 (28U)                                               /*!< EMVSIM0_CTRL.LRC_EN Position            */
#define EMVSIM_CTRL_LRC_EN(x)                    (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< EMVSIM0_CTRL.LRC_EN Field               */
#define EMVSIM_CTRL_CRC_EN_MASK                  (0x20000000U)                                       /*!< EMVSIM0_CTRL.CRC_EN Mask                */
#define EMVSIM_CTRL_CRC_EN_SHIFT                 (29U)                                               /*!< EMVSIM0_CTRL.CRC_EN Position            */
#define EMVSIM_CTRL_CRC_EN(x)                    (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< EMVSIM0_CTRL.CRC_EN Field               */
#define EMVSIM_CTRL_XMT_CRC_LRC_MASK             (0x40000000U)                                       /*!< EMVSIM0_CTRL.XMT_CRC_LRC Mask           */
#define EMVSIM_CTRL_XMT_CRC_LRC_SHIFT            (30U)                                               /*!< EMVSIM0_CTRL.XMT_CRC_LRC Position       */
#define EMVSIM_CTRL_XMT_CRC_LRC(x)               (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< EMVSIM0_CTRL.XMT_CRC_LRC Field          */
#define EMVSIM_CTRL_BWT_EN_MASK                  (0x80000000U)                                       /*!< EMVSIM0_CTRL.BWT_EN Mask                */
#define EMVSIM_CTRL_BWT_EN_SHIFT                 (31U)                                               /*!< EMVSIM0_CTRL.BWT_EN Position            */
#define EMVSIM_CTRL_BWT_EN(x)                    (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< EMVSIM0_CTRL.BWT_EN Field               */
/* ------- INT_MASK Bit Fields                      ------ */
#define EMVSIM_INT_MASK_RDT_IM_MASK              (0x1U)                                              /*!< EMVSIM0_INT_MASK.RDT_IM Mask            */
#define EMVSIM_INT_MASK_RDT_IM_SHIFT             (0U)                                                /*!< EMVSIM0_INT_MASK.RDT_IM Position        */
#define EMVSIM_INT_MASK_RDT_IM(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< EMVSIM0_INT_MASK.RDT_IM Field           */
#define EMVSIM_INT_MASK_TC_IM_MASK               (0x2U)                                              /*!< EMVSIM0_INT_MASK.TC_IM Mask             */
#define EMVSIM_INT_MASK_TC_IM_SHIFT              (1U)                                                /*!< EMVSIM0_INT_MASK.TC_IM Position         */
#define EMVSIM_INT_MASK_TC_IM(x)                 (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< EMVSIM0_INT_MASK.TC_IM Field            */
#define EMVSIM_INT_MASK_RFO_IM_MASK              (0x4U)                                              /*!< EMVSIM0_INT_MASK.RFO_IM Mask            */
#define EMVSIM_INT_MASK_RFO_IM_SHIFT             (2U)                                                /*!< EMVSIM0_INT_MASK.RFO_IM Position        */
#define EMVSIM_INT_MASK_RFO_IM(x)                (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< EMVSIM0_INT_MASK.RFO_IM Field           */
#define EMVSIM_INT_MASK_ETC_IM_MASK              (0x8U)                                              /*!< EMVSIM0_INT_MASK.ETC_IM Mask            */
#define EMVSIM_INT_MASK_ETC_IM_SHIFT             (3U)                                                /*!< EMVSIM0_INT_MASK.ETC_IM Position        */
#define EMVSIM_INT_MASK_ETC_IM(x)                (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< EMVSIM0_INT_MASK.ETC_IM Field           */
#define EMVSIM_INT_MASK_TFE_IM_MASK              (0x10U)                                             /*!< EMVSIM0_INT_MASK.TFE_IM Mask            */
#define EMVSIM_INT_MASK_TFE_IM_SHIFT             (4U)                                                /*!< EMVSIM0_INT_MASK.TFE_IM Position        */
#define EMVSIM_INT_MASK_TFE_IM(x)                (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< EMVSIM0_INT_MASK.TFE_IM Field           */
#define EMVSIM_INT_MASK_TNACK_IM_MASK            (0x20U)                                             /*!< EMVSIM0_INT_MASK.TNACK_IM Mask          */
#define EMVSIM_INT_MASK_TNACK_IM_SHIFT           (5U)                                                /*!< EMVSIM0_INT_MASK.TNACK_IM Position      */
#define EMVSIM_INT_MASK_TNACK_IM(x)              (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< EMVSIM0_INT_MASK.TNACK_IM Field         */
#define EMVSIM_INT_MASK_TFF_IM_MASK              (0x40U)                                             /*!< EMVSIM0_INT_MASK.TFF_IM Mask            */
#define EMVSIM_INT_MASK_TFF_IM_SHIFT             (6U)                                                /*!< EMVSIM0_INT_MASK.TFF_IM Position        */
#define EMVSIM_INT_MASK_TFF_IM(x)                (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< EMVSIM0_INT_MASK.TFF_IM Field           */
#define EMVSIM_INT_MASK_TDT_IM_MASK              (0x80U)                                             /*!< EMVSIM0_INT_MASK.TDT_IM Mask            */
#define EMVSIM_INT_MASK_TDT_IM_SHIFT             (7U)                                                /*!< EMVSIM0_INT_MASK.TDT_IM Position        */
#define EMVSIM_INT_MASK_TDT_IM(x)                (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< EMVSIM0_INT_MASK.TDT_IM Field           */
#define EMVSIM_INT_MASK_GPCNT0_IM_MASK           (0x100U)                                            /*!< EMVSIM0_INT_MASK.GPCNT0_IM Mask         */
#define EMVSIM_INT_MASK_GPCNT0_IM_SHIFT          (8U)                                                /*!< EMVSIM0_INT_MASK.GPCNT0_IM Position     */
#define EMVSIM_INT_MASK_GPCNT0_IM(x)             (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< EMVSIM0_INT_MASK.GPCNT0_IM Field        */
#define EMVSIM_INT_MASK_CWT_ERR_IM_MASK          (0x200U)                                            /*!< EMVSIM0_INT_MASK.CWT_ERR_IM Mask        */
#define EMVSIM_INT_MASK_CWT_ERR_IM_SHIFT         (9U)                                                /*!< EMVSIM0_INT_MASK.CWT_ERR_IM Position    */
#define EMVSIM_INT_MASK_CWT_ERR_IM(x)            (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< EMVSIM0_INT_MASK.CWT_ERR_IM Field       */
#define EMVSIM_INT_MASK_RNACK_IM_MASK            (0x400U)                                            /*!< EMVSIM0_INT_MASK.RNACK_IM Mask          */
#define EMVSIM_INT_MASK_RNACK_IM_SHIFT           (10U)                                               /*!< EMVSIM0_INT_MASK.RNACK_IM Position      */
#define EMVSIM_INT_MASK_RNACK_IM(x)              (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< EMVSIM0_INT_MASK.RNACK_IM Field         */
#define EMVSIM_INT_MASK_BWT_ERR_IM_MASK          (0x800U)                                            /*!< EMVSIM0_INT_MASK.BWT_ERR_IM Mask        */
#define EMVSIM_INT_MASK_BWT_ERR_IM_SHIFT         (11U)                                               /*!< EMVSIM0_INT_MASK.BWT_ERR_IM Position    */
#define EMVSIM_INT_MASK_BWT_ERR_IM(x)            (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< EMVSIM0_INT_MASK.BWT_ERR_IM Field       */
#define EMVSIM_INT_MASK_BGT_ERR_IM_MASK          (0x1000U)                                           /*!< EMVSIM0_INT_MASK.BGT_ERR_IM Mask        */
#define EMVSIM_INT_MASK_BGT_ERR_IM_SHIFT         (12U)                                               /*!< EMVSIM0_INT_MASK.BGT_ERR_IM Position    */
#define EMVSIM_INT_MASK_BGT_ERR_IM(x)            (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< EMVSIM0_INT_MASK.BGT_ERR_IM Field       */
#define EMVSIM_INT_MASK_GPCNT1_IM_MASK           (0x2000U)                                           /*!< EMVSIM0_INT_MASK.GPCNT1_IM Mask         */
#define EMVSIM_INT_MASK_GPCNT1_IM_SHIFT          (13U)                                               /*!< EMVSIM0_INT_MASK.GPCNT1_IM Position     */
#define EMVSIM_INT_MASK_GPCNT1_IM(x)             (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< EMVSIM0_INT_MASK.GPCNT1_IM Field        */
#define EMVSIM_INT_MASK_RX_DATA_IM_MASK          (0x4000U)                                           /*!< EMVSIM0_INT_MASK.RX_DATA_IM Mask        */
#define EMVSIM_INT_MASK_RX_DATA_IM_SHIFT         (14U)                                               /*!< EMVSIM0_INT_MASK.RX_DATA_IM Position    */
#define EMVSIM_INT_MASK_RX_DATA_IM(x)            (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< EMVSIM0_INT_MASK.RX_DATA_IM Field       */
#define EMVSIM_INT_MASK_PEF_IM_MASK              (0x8000U)                                           /*!< EMVSIM0_INT_MASK.PEF_IM Mask            */
#define EMVSIM_INT_MASK_PEF_IM_SHIFT             (15U)                                               /*!< EMVSIM0_INT_MASK.PEF_IM Position        */
#define EMVSIM_INT_MASK_PEF_IM(x)                (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< EMVSIM0_INT_MASK.PEF_IM Field           */
/* ------- RX_THD Bit Fields                        ------ */
#define EMVSIM_RX_THD_RDT_MASK                   (0xFU)                                              /*!< EMVSIM0_RX_THD.RDT Mask                 */
#define EMVSIM_RX_THD_RDT_SHIFT                  (0U)                                                /*!< EMVSIM0_RX_THD.RDT Position             */
#define EMVSIM_RX_THD_RDT(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< EMVSIM0_RX_THD.RDT Field                */
#define EMVSIM_RX_THD_RNCK_THD_MASK              (0xF00U)                                            /*!< EMVSIM0_RX_THD.RNCK_THD Mask            */
#define EMVSIM_RX_THD_RNCK_THD_SHIFT             (8U)                                                /*!< EMVSIM0_RX_THD.RNCK_THD Position        */
#define EMVSIM_RX_THD_RNCK_THD(x)                (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< EMVSIM0_RX_THD.RNCK_THD Field           */
/* ------- TX_THD Bit Fields                        ------ */
#define EMVSIM_TX_THD_TDT_MASK                   (0xFU)                                              /*!< EMVSIM0_TX_THD.TDT Mask                 */
#define EMVSIM_TX_THD_TDT_SHIFT                  (0U)                                                /*!< EMVSIM0_TX_THD.TDT Position             */
#define EMVSIM_TX_THD_TDT(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< EMVSIM0_TX_THD.TDT Field                */
#define EMVSIM_TX_THD_TNCK_THD_MASK              (0xF00U)                                            /*!< EMVSIM0_TX_THD.TNCK_THD Mask            */
#define EMVSIM_TX_THD_TNCK_THD_SHIFT             (8U)                                                /*!< EMVSIM0_TX_THD.TNCK_THD Position        */
#define EMVSIM_TX_THD_TNCK_THD(x)                (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< EMVSIM0_TX_THD.TNCK_THD Field           */
/* ------- RX_STATUS Bit Fields                     ------ */
#define EMVSIM_RX_STATUS_RFO_MASK                (0x1U)                                              /*!< EMVSIM0_RX_STATUS.RFO Mask              */
#define EMVSIM_RX_STATUS_RFO_SHIFT               (0U)                                                /*!< EMVSIM0_RX_STATUS.RFO Position          */
#define EMVSIM_RX_STATUS_RFO(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< EMVSIM0_RX_STATUS.RFO Field             */
#define EMVSIM_RX_STATUS_RX_DATA_MASK            (0x10U)                                             /*!< EMVSIM0_RX_STATUS.RX_DATA Mask          */
#define EMVSIM_RX_STATUS_RX_DATA_SHIFT           (4U)                                                /*!< EMVSIM0_RX_STATUS.RX_DATA Position      */
#define EMVSIM_RX_STATUS_RX_DATA(x)              (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< EMVSIM0_RX_STATUS.RX_DATA Field         */
#define EMVSIM_RX_STATUS_RDTF_MASK               (0x20U)                                             /*!< EMVSIM0_RX_STATUS.RDTF Mask             */
#define EMVSIM_RX_STATUS_RDTF_SHIFT              (5U)                                                /*!< EMVSIM0_RX_STATUS.RDTF Position         */
#define EMVSIM_RX_STATUS_RDTF(x)                 (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< EMVSIM0_RX_STATUS.RDTF Field            */
#define EMVSIM_RX_STATUS_LRC_OK_MASK             (0x40U)                                             /*!< EMVSIM0_RX_STATUS.LRC_OK Mask           */
#define EMVSIM_RX_STATUS_LRC_OK_SHIFT            (6U)                                                /*!< EMVSIM0_RX_STATUS.LRC_OK Position       */
#define EMVSIM_RX_STATUS_LRC_OK(x)               (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< EMVSIM0_RX_STATUS.LRC_OK Field          */
#define EMVSIM_RX_STATUS_CRC_OK_MASK             (0x80U)                                             /*!< EMVSIM0_RX_STATUS.CRC_OK Mask           */
#define EMVSIM_RX_STATUS_CRC_OK_SHIFT            (7U)                                                /*!< EMVSIM0_RX_STATUS.CRC_OK Position       */
#define EMVSIM_RX_STATUS_CRC_OK(x)               (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< EMVSIM0_RX_STATUS.CRC_OK Field          */
#define EMVSIM_RX_STATUS_CWT_ERR_MASK            (0x100U)                                            /*!< EMVSIM0_RX_STATUS.CWT_ERR Mask          */
#define EMVSIM_RX_STATUS_CWT_ERR_SHIFT           (8U)                                                /*!< EMVSIM0_RX_STATUS.CWT_ERR Position      */
#define EMVSIM_RX_STATUS_CWT_ERR(x)              (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< EMVSIM0_RX_STATUS.CWT_ERR Field         */
#define EMVSIM_RX_STATUS_RTE_MASK                (0x200U)                                            /*!< EMVSIM0_RX_STATUS.RTE Mask              */
#define EMVSIM_RX_STATUS_RTE_SHIFT               (9U)                                                /*!< EMVSIM0_RX_STATUS.RTE Position          */
#define EMVSIM_RX_STATUS_RTE(x)                  (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< EMVSIM0_RX_STATUS.RTE Field             */
#define EMVSIM_RX_STATUS_BWT_ERR_MASK            (0x400U)                                            /*!< EMVSIM0_RX_STATUS.BWT_ERR Mask          */
#define EMVSIM_RX_STATUS_BWT_ERR_SHIFT           (10U)                                               /*!< EMVSIM0_RX_STATUS.BWT_ERR Position      */
#define EMVSIM_RX_STATUS_BWT_ERR(x)              (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< EMVSIM0_RX_STATUS.BWT_ERR Field         */
#define EMVSIM_RX_STATUS_BGT_ERR_MASK            (0x800U)                                            /*!< EMVSIM0_RX_STATUS.BGT_ERR Mask          */
#define EMVSIM_RX_STATUS_BGT_ERR_SHIFT           (11U)                                               /*!< EMVSIM0_RX_STATUS.BGT_ERR Position      */
#define EMVSIM_RX_STATUS_BGT_ERR(x)              (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< EMVSIM0_RX_STATUS.BGT_ERR Field         */
#define EMVSIM_RX_STATUS_PEF_MASK                (0x1000U)                                           /*!< EMVSIM0_RX_STATUS.PEF Mask              */
#define EMVSIM_RX_STATUS_PEF_SHIFT               (12U)                                               /*!< EMVSIM0_RX_STATUS.PEF Position          */
#define EMVSIM_RX_STATUS_PEF(x)                  (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< EMVSIM0_RX_STATUS.PEF Field             */
#define EMVSIM_RX_STATUS_FEF_MASK                (0x2000U)                                           /*!< EMVSIM0_RX_STATUS.FEF Mask              */
#define EMVSIM_RX_STATUS_FEF_SHIFT               (13U)                                               /*!< EMVSIM0_RX_STATUS.FEF Position          */
#define EMVSIM_RX_STATUS_FEF(x)                  (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< EMVSIM0_RX_STATUS.FEF Field             */
#define EMVSIM_RX_STATUS_RX_WPTR_MASK            (0xF0000U)                                          /*!< EMVSIM0_RX_STATUS.RX_WPTR Mask          */
#define EMVSIM_RX_STATUS_RX_WPTR_SHIFT           (16U)                                               /*!< EMVSIM0_RX_STATUS.RX_WPTR Position      */
#define EMVSIM_RX_STATUS_RX_WPTR(x)              (((uint32_t)(((uint32_t)(x))<<16U))&0xF0000UL)      /*!< EMVSIM0_RX_STATUS.RX_WPTR Field         */
#define EMVSIM_RX_STATUS_RX_CNT_MASK             (0xFF000000U)                                       /*!< EMVSIM0_RX_STATUS.RX_CNT Mask           */
#define EMVSIM_RX_STATUS_RX_CNT_SHIFT            (24U)                                               /*!< EMVSIM0_RX_STATUS.RX_CNT Position       */
#define EMVSIM_RX_STATUS_RX_CNT(x)               (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< EMVSIM0_RX_STATUS.RX_CNT Field          */
/* ------- TX_STATUS Bit Fields                     ------ */
#define EMVSIM_TX_STATUS_TNTE_MASK               (0x1U)                                              /*!< EMVSIM0_TX_STATUS.TNTE Mask             */
#define EMVSIM_TX_STATUS_TNTE_SHIFT              (0U)                                                /*!< EMVSIM0_TX_STATUS.TNTE Position         */
#define EMVSIM_TX_STATUS_TNTE(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< EMVSIM0_TX_STATUS.TNTE Field            */
#define EMVSIM_TX_STATUS_TFE_MASK                (0x8U)                                              /*!< EMVSIM0_TX_STATUS.TFE Mask              */
#define EMVSIM_TX_STATUS_TFE_SHIFT               (3U)                                                /*!< EMVSIM0_TX_STATUS.TFE Position          */
#define EMVSIM_TX_STATUS_TFE(x)                  (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< EMVSIM0_TX_STATUS.TFE Field             */
#define EMVSIM_TX_STATUS_ETCF_MASK               (0x10U)                                             /*!< EMVSIM0_TX_STATUS.ETCF Mask             */
#define EMVSIM_TX_STATUS_ETCF_SHIFT              (4U)                                                /*!< EMVSIM0_TX_STATUS.ETCF Position         */
#define EMVSIM_TX_STATUS_ETCF(x)                 (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< EMVSIM0_TX_STATUS.ETCF Field            */
#define EMVSIM_TX_STATUS_TCF_MASK                (0x20U)                                             /*!< EMVSIM0_TX_STATUS.TCF Mask              */
#define EMVSIM_TX_STATUS_TCF_SHIFT               (5U)                                                /*!< EMVSIM0_TX_STATUS.TCF Position          */
#define EMVSIM_TX_STATUS_TCF(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< EMVSIM0_TX_STATUS.TCF Field             */
#define EMVSIM_TX_STATUS_TFF_MASK                (0x40U)                                             /*!< EMVSIM0_TX_STATUS.TFF Mask              */
#define EMVSIM_TX_STATUS_TFF_SHIFT               (6U)                                                /*!< EMVSIM0_TX_STATUS.TFF Position          */
#define EMVSIM_TX_STATUS_TFF(x)                  (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< EMVSIM0_TX_STATUS.TFF Field             */
#define EMVSIM_TX_STATUS_TDTF_MASK               (0x80U)                                             /*!< EMVSIM0_TX_STATUS.TDTF Mask             */
#define EMVSIM_TX_STATUS_TDTF_SHIFT              (7U)                                                /*!< EMVSIM0_TX_STATUS.TDTF Position         */
#define EMVSIM_TX_STATUS_TDTF(x)                 (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< EMVSIM0_TX_STATUS.TDTF Field            */
#define EMVSIM_TX_STATUS_GPCNT0_TO_MASK          (0x100U)                                            /*!< EMVSIM0_TX_STATUS.GPCNT0_TO Mask        */
#define EMVSIM_TX_STATUS_GPCNT0_TO_SHIFT         (8U)                                                /*!< EMVSIM0_TX_STATUS.GPCNT0_TO Position    */
#define EMVSIM_TX_STATUS_GPCNT0_TO(x)            (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< EMVSIM0_TX_STATUS.GPCNT0_TO Field       */
#define EMVSIM_TX_STATUS_GPCNT1_TO_MASK          (0x200U)                                            /*!< EMVSIM0_TX_STATUS.GPCNT1_TO Mask        */
#define EMVSIM_TX_STATUS_GPCNT1_TO_SHIFT         (9U)                                                /*!< EMVSIM0_TX_STATUS.GPCNT1_TO Position    */
#define EMVSIM_TX_STATUS_GPCNT1_TO(x)            (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< EMVSIM0_TX_STATUS.GPCNT1_TO Field       */
#define EMVSIM_TX_STATUS_TX_RPTR_MASK            (0xF0000U)                                          /*!< EMVSIM0_TX_STATUS.TX_RPTR Mask          */
#define EMVSIM_TX_STATUS_TX_RPTR_SHIFT           (16U)                                               /*!< EMVSIM0_TX_STATUS.TX_RPTR Position      */
#define EMVSIM_TX_STATUS_TX_RPTR(x)              (((uint32_t)(((uint32_t)(x))<<16U))&0xF0000UL)      /*!< EMVSIM0_TX_STATUS.TX_RPTR Field         */
#define EMVSIM_TX_STATUS_TX_CNT_MASK             (0xFF000000U)                                       /*!< EMVSIM0_TX_STATUS.TX_CNT Mask           */
#define EMVSIM_TX_STATUS_TX_CNT_SHIFT            (24U)                                               /*!< EMVSIM0_TX_STATUS.TX_CNT Position       */
#define EMVSIM_TX_STATUS_TX_CNT(x)               (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< EMVSIM0_TX_STATUS.TX_CNT Field          */
/* ------- PCSR Bit Fields                          ------ */
#define EMVSIM_PCSR_SAPD_MASK                    (0x1U)                                              /*!< EMVSIM0_PCSR.SAPD Mask                  */
#define EMVSIM_PCSR_SAPD_SHIFT                   (0U)                                                /*!< EMVSIM0_PCSR.SAPD Position              */
#define EMVSIM_PCSR_SAPD(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< EMVSIM0_PCSR.SAPD Field                 */
#define EMVSIM_PCSR_SVCC_EN_MASK                 (0x2U)                                              /*!< EMVSIM0_PCSR.SVCC_EN Mask               */
#define EMVSIM_PCSR_SVCC_EN_SHIFT                (1U)                                                /*!< EMVSIM0_PCSR.SVCC_EN Position           */
#define EMVSIM_PCSR_SVCC_EN(x)                   (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< EMVSIM0_PCSR.SVCC_EN Field              */
#define EMVSIM_PCSR_VCCENP_MASK                  (0x4U)                                              /*!< EMVSIM0_PCSR.VCCENP Mask                */
#define EMVSIM_PCSR_VCCENP_SHIFT                 (2U)                                                /*!< EMVSIM0_PCSR.VCCENP Position            */
#define EMVSIM_PCSR_VCCENP(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< EMVSIM0_PCSR.VCCENP Field               */
#define EMVSIM_PCSR_SRST_MASK                    (0x8U)                                              /*!< EMVSIM0_PCSR.SRST Mask                  */
#define EMVSIM_PCSR_SRST_SHIFT                   (3U)                                                /*!< EMVSIM0_PCSR.SRST Position              */
#define EMVSIM_PCSR_SRST(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< EMVSIM0_PCSR.SRST Field                 */
#define EMVSIM_PCSR_SCEN_MASK                    (0x10U)                                             /*!< EMVSIM0_PCSR.SCEN Mask                  */
#define EMVSIM_PCSR_SCEN_SHIFT                   (4U)                                                /*!< EMVSIM0_PCSR.SCEN Position              */
#define EMVSIM_PCSR_SCEN(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< EMVSIM0_PCSR.SCEN Field                 */
#define EMVSIM_PCSR_SCSP_MASK                    (0x20U)                                             /*!< EMVSIM0_PCSR.SCSP Mask                  */
#define EMVSIM_PCSR_SCSP_SHIFT                   (5U)                                                /*!< EMVSIM0_PCSR.SCSP Position              */
#define EMVSIM_PCSR_SCSP(x)                      (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< EMVSIM0_PCSR.SCSP Field                 */
#define EMVSIM_PCSR_SPD_MASK                     (0x80U)                                             /*!< EMVSIM0_PCSR.SPD Mask                   */
#define EMVSIM_PCSR_SPD_SHIFT                    (7U)                                                /*!< EMVSIM0_PCSR.SPD Position               */
#define EMVSIM_PCSR_SPD(x)                       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< EMVSIM0_PCSR.SPD Field                  */
#define EMVSIM_PCSR_SPDIM_MASK                   (0x1000000U)                                        /*!< EMVSIM0_PCSR.SPDIM Mask                 */
#define EMVSIM_PCSR_SPDIM_SHIFT                  (24U)                                               /*!< EMVSIM0_PCSR.SPDIM Position             */
#define EMVSIM_PCSR_SPDIM(x)                     (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< EMVSIM0_PCSR.SPDIM Field                */
#define EMVSIM_PCSR_SPDIF_MASK                   (0x2000000U)                                        /*!< EMVSIM0_PCSR.SPDIF Mask                 */
#define EMVSIM_PCSR_SPDIF_SHIFT                  (25U)                                               /*!< EMVSIM0_PCSR.SPDIF Position             */
#define EMVSIM_PCSR_SPDIF(x)                     (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< EMVSIM0_PCSR.SPDIF Field                */
#define EMVSIM_PCSR_SPDP_MASK                    (0x4000000U)                                        /*!< EMVSIM0_PCSR.SPDP Mask                  */
#define EMVSIM_PCSR_SPDP_SHIFT                   (26U)                                               /*!< EMVSIM0_PCSR.SPDP Position              */
#define EMVSIM_PCSR_SPDP(x)                      (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< EMVSIM0_PCSR.SPDP Field                 */
#define EMVSIM_PCSR_SPDES_MASK                   (0x8000000U)                                        /*!< EMVSIM0_PCSR.SPDES Mask                 */
#define EMVSIM_PCSR_SPDES_SHIFT                  (27U)                                               /*!< EMVSIM0_PCSR.SPDES Position             */
#define EMVSIM_PCSR_SPDES(x)                     (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< EMVSIM0_PCSR.SPDES Field                */
/* ------- RX_BUF Bit Fields                        ------ */
#define EMVSIM_RX_BUF_RX_BYTE_MASK               (0xFFU)                                             /*!< EMVSIM0_RX_BUF.RX_BYTE Mask             */
#define EMVSIM_RX_BUF_RX_BYTE_SHIFT              (0U)                                                /*!< EMVSIM0_RX_BUF.RX_BYTE Position         */
#define EMVSIM_RX_BUF_RX_BYTE(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< EMVSIM0_RX_BUF.RX_BYTE Field            */
/* ------- TX_BUF Bit Fields                        ------ */
#define EMVSIM_TX_BUF_TX_BYTE_MASK               (0xFFU)                                             /*!< EMVSIM0_TX_BUF.TX_BYTE Mask             */
#define EMVSIM_TX_BUF_TX_BYTE_SHIFT              (0U)                                                /*!< EMVSIM0_TX_BUF.TX_BYTE Position         */
#define EMVSIM_TX_BUF_TX_BYTE(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< EMVSIM0_TX_BUF.TX_BYTE Field            */
/* ------- TX_GETU Bit Fields                       ------ */
#define EMVSIM_TX_GETU_GETU_MASK                 (0xFFU)                                             /*!< EMVSIM0_TX_GETU.GETU Mask               */
#define EMVSIM_TX_GETU_GETU_SHIFT                (0U)                                                /*!< EMVSIM0_TX_GETU.GETU Position           */
#define EMVSIM_TX_GETU_GETU(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< EMVSIM0_TX_GETU.GETU Field              */
/* ------- CWT_VAL Bit Fields                       ------ */
#define EMVSIM_CWT_VAL_CWT_MASK                  (0xFFFFU)                                           /*!< EMVSIM0_CWT_VAL.CWT Mask                */
#define EMVSIM_CWT_VAL_CWT_SHIFT                 (0U)                                                /*!< EMVSIM0_CWT_VAL.CWT Position            */
#define EMVSIM_CWT_VAL_CWT(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< EMVSIM0_CWT_VAL.CWT Field               */
/* ------- BWT_VAL Bit Fields                       ------ */
#define EMVSIM_BWT_VAL_BWT_MASK                  (0xFFFFFFFFU)                                       /*!< EMVSIM0_BWT_VAL.BWT Mask                */
#define EMVSIM_BWT_VAL_BWT_SHIFT                 (0U)                                                /*!< EMVSIM0_BWT_VAL.BWT Position            */
#define EMVSIM_BWT_VAL_BWT(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< EMVSIM0_BWT_VAL.BWT Field               */
/* ------- BGT_VAL Bit Fields                       ------ */
#define EMVSIM_BGT_VAL_BGT_MASK                  (0xFFFFU)                                           /*!< EMVSIM0_BGT_VAL.BGT Mask                */
#define EMVSIM_BGT_VAL_BGT_SHIFT                 (0U)                                                /*!< EMVSIM0_BGT_VAL.BGT Position            */
#define EMVSIM_BGT_VAL_BGT(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< EMVSIM0_BGT_VAL.BGT Field               */
/* ------- GPCNT0_VAL Bit Fields                    ------ */
#define EMVSIM_GPCNT0_VAL_GPCNT0_MASK            (0xFFFFU)                                           /*!< EMVSIM0_GPCNT0_VAL.GPCNT0 Mask          */
#define EMVSIM_GPCNT0_VAL_GPCNT0_SHIFT           (0U)                                                /*!< EMVSIM0_GPCNT0_VAL.GPCNT0 Position      */
#define EMVSIM_GPCNT0_VAL_GPCNT0(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< EMVSIM0_GPCNT0_VAL.GPCNT0 Field         */
/* ------- GPCNT1_VAL Bit Fields                    ------ */
#define EMVSIM_GPCNT1_VAL_GPCNT1_MASK            (0xFFFFU)                                           /*!< EMVSIM0_GPCNT1_VAL.GPCNT1 Mask          */
#define EMVSIM_GPCNT1_VAL_GPCNT1_SHIFT           (0U)                                                /*!< EMVSIM0_GPCNT1_VAL.GPCNT1 Position      */
#define EMVSIM_GPCNT1_VAL_GPCNT1(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< EMVSIM0_GPCNT1_VAL.GPCNT1 Field         */
/**
 * @} */ /* End group EMVSIM_Register_Masks_GROUP 
 */

/* EMVSIM0 - Peripheral instance base addresses */
#define EMVSIM0_BasePtr                0x4004E000UL //!< Peripheral base address
#define EMVSIM0                        ((EMVSIM_Type *) EMVSIM0_BasePtr) //!< Freescale base pointer
#define EMVSIM0_BASE_PTR               (EMVSIM0) //!< Freescale style base pointer
/**
 * @} */ /* End group EMVSIM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup EMVSIM_Peripheral_access_layer_GROUP EMVSIM Peripheral Access Layer
* @brief C Struct for EMVSIM
* @{
*/

/* ================================================================================ */
/* ================           EMVSIM1 (derived from EMVSIM0)       ================ */
/* ================================================================================ */

/**
 * @brief EMVSIM
 */

/* EMVSIM1 - Peripheral instance base addresses */
#define EMVSIM1_BasePtr                0x4004F000UL //!< Peripheral base address
#define EMVSIM1                        ((EMVSIM_Type *) EMVSIM1_BasePtr) //!< Freescale base pointer
#define EMVSIM1_BASE_PTR               (EMVSIM1) //!< Freescale style base pointer
/**
 * @} */ /* End group EMVSIM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup EWM_Peripheral_access_layer_GROUP EWM Peripheral Access Layer
* @brief C Struct for EWM
* @{
*/

/* ================================================================================ */
/* ================           EWM (file:EWM_MKE16F16)              ================ */
/* ================================================================================ */

/**
 * @brief External Watchdog Monitor
 */
/**
* @addtogroup EWM_structs_GROUP EWM struct
* @brief Struct for EWM
* @{
*/
typedef struct {                                /*       EWM Structure                                                */
   __IO uint8_t   CTRL;                         /**< 0000: Control Register                                             */
   __O  uint8_t   SERV;                         /**< 0001: Service Register                                             */
   __IO uint8_t   CMPL;                         /**< 0002: Compare Low Register                                         */
   __IO uint8_t   CMPH;                         /**< 0003: Compare High Register                                        */
        uint8_t   RESERVED_0;                  
   __IO uint8_t   CLKPRESCALER;                 /**< 0005: Clock Prescaler Register                                     */
} EWM_Type;

/**
 * @} */ /* End group EWM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'EWM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup EWM_Register_Masks_GROUP EWM Register Masks
* @brief Register Masks for EWM
* @{
*/
/* ------- CTRL Bit Fields                          ------ */
#define EWM_CTRL_EWMEN_MASK                      (0x1U)                                              /*!< EWM_CTRL.EWMEN Mask                     */
#define EWM_CTRL_EWMEN_SHIFT                     (0U)                                                /*!< EWM_CTRL.EWMEN Position                 */
#define EWM_CTRL_EWMEN(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< EWM_CTRL.EWMEN Field                    */
#define EWM_CTRL_ASSIN_MASK                      (0x2U)                                              /*!< EWM_CTRL.ASSIN Mask                     */
#define EWM_CTRL_ASSIN_SHIFT                     (1U)                                                /*!< EWM_CTRL.ASSIN Position                 */
#define EWM_CTRL_ASSIN(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< EWM_CTRL.ASSIN Field                    */
#define EWM_CTRL_INEN_MASK                       (0x4U)                                              /*!< EWM_CTRL.INEN Mask                      */
#define EWM_CTRL_INEN_SHIFT                      (2U)                                                /*!< EWM_CTRL.INEN Position                  */
#define EWM_CTRL_INEN(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< EWM_CTRL.INEN Field                     */
#define EWM_CTRL_INTEN_MASK                      (0x8U)                                              /*!< EWM_CTRL.INTEN Mask                     */
#define EWM_CTRL_INTEN_SHIFT                     (3U)                                                /*!< EWM_CTRL.INTEN Position                 */
#define EWM_CTRL_INTEN(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< EWM_CTRL.INTEN Field                    */
/* ------- SERV Bit Fields                          ------ */
#define EWM_SERV_SERVICE_MASK                    (0xFFU)                                             /*!< EWM_SERV.SERVICE Mask                   */
#define EWM_SERV_SERVICE_SHIFT                   (0U)                                                /*!< EWM_SERV.SERVICE Position               */
#define EWM_SERV_SERVICE(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< EWM_SERV.SERVICE Field                  */
/* ------- CMPL Bit Fields                          ------ */
#define EWM_CMPL_COMPAREL_MASK                   (0xFFU)                                             /*!< EWM_CMPL.COMPAREL Mask                  */
#define EWM_CMPL_COMPAREL_SHIFT                  (0U)                                                /*!< EWM_CMPL.COMPAREL Position              */
#define EWM_CMPL_COMPAREL(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< EWM_CMPL.COMPAREL Field                 */
/* ------- CMPH Bit Fields                          ------ */
#define EWM_CMPH_COMPAREH_MASK                   (0xFFU)                                             /*!< EWM_CMPH.COMPAREH Mask                  */
#define EWM_CMPH_COMPAREH_SHIFT                  (0U)                                                /*!< EWM_CMPH.COMPAREH Position              */
#define EWM_CMPH_COMPAREH(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< EWM_CMPH.COMPAREH Field                 */
/* ------- CLKPRESCALER Bit Fields                  ------ */
#define EWM_CLKPRESCALER_CLK_DIV_MASK            (0xFFU)                                             /*!< EWM_CLKPRESCALER.CLK_DIV Mask           */
#define EWM_CLKPRESCALER_CLK_DIV_SHIFT           (0U)                                                /*!< EWM_CLKPRESCALER.CLK_DIV Position       */
#define EWM_CLKPRESCALER_CLK_DIV(x)              (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< EWM_CLKPRESCALER.CLK_DIV Field          */
/**
 * @} */ /* End group EWM_Register_Masks_GROUP 
 */

/* EWM - Peripheral instance base addresses */
#define EWM_BasePtr                    0x40061000UL //!< Peripheral base address
#define EWM                            ((EWM_Type *) EWM_BasePtr) //!< Freescale base pointer
#define EWM_BASE_PTR                   (EWM) //!< Freescale style base pointer
/**
 * @} */ /* End group EWM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FGPIO_Peripheral_access_layer_GROUP FGPIO Peripheral Access Layer
* @brief C Struct for FGPIO
* @{
*/

/* ================================================================================ */
/* ================           FGPIOA (file:FGPIOA_0xF8000000)       ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
/**
* @addtogroup FGPIO_structs_GROUP FGPIO struct
* @brief Struct for FGPIO
* @{
*/
typedef struct {                                /*       FGPIOA Structure                                             */
   __IO uint32_t  PDOR;                         /**< 0000: Port Data Output Register                                    */
   __O  uint32_t  PSOR;                         /**< 0004: Port Set Output Register                                     */
   __O  uint32_t  PCOR;                         /**< 0008: Port Clear Output Register                                   */
   __O  uint32_t  PTOR;                         /**< 000C: Port Toggle Output Register                                  */
   __I  uint32_t  PDIR;                         /**< 0010: Port Data Input Register                                     */
   __IO uint32_t  PDDR;                         /**< 0014: Port Data Direction Register                                 */
} GPIO_Type;

/**
 * @} */ /* End group FGPIO_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FGPIOA' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FGPIO_Register_Masks_GROUP FGPIO Register Masks
* @brief Register Masks for FGPIO
* @{
*/
/* ------- PDOR Bit Fields                          ------ */
/* ------- PSOR Bit Fields                          ------ */
/* ------- PCOR Bit Fields                          ------ */
/* ------- PTOR Bit Fields                          ------ */
/* ------- PDIR Bit Fields                          ------ */
/* ------- PDDR Bit Fields                          ------ */
/**
 * @} */ /* End group FGPIO_Register_Masks_GROUP 
 */

/* FGPIOA - Peripheral instance base addresses */
#define FGPIOA_BasePtr                 0xF8000000UL //!< Peripheral base address
#define FGPIOA                         ((GPIO_Type *) FGPIOA_BasePtr) //!< Freescale base pointer
#define FGPIOA_BASE_PTR                (FGPIOA) //!< Freescale style base pointer
/**
 * @} */ /* End group FGPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FGPIO_Peripheral_access_layer_GROUP FGPIO Peripheral Access Layer
* @brief C Struct for FGPIO
* @{
*/

/* ================================================================================ */
/* ================           FGPIOB (derived from FGPIOA)         ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* FGPIOB - Peripheral instance base addresses */
#define FGPIOB_BasePtr                 0xF8000040UL //!< Peripheral base address
#define FGPIOB                         ((GPIO_Type *) FGPIOB_BasePtr) //!< Freescale base pointer
#define FGPIOB_BASE_PTR                (FGPIOB) //!< Freescale style base pointer
/**
 * @} */ /* End group FGPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FGPIO_Peripheral_access_layer_GROUP FGPIO Peripheral Access Layer
* @brief C Struct for FGPIO
* @{
*/

/* ================================================================================ */
/* ================           FGPIOC (derived from FGPIOA)         ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* FGPIOC - Peripheral instance base addresses */
#define FGPIOC_BasePtr                 0xF8000080UL //!< Peripheral base address
#define FGPIOC                         ((GPIO_Type *) FGPIOC_BasePtr) //!< Freescale base pointer
#define FGPIOC_BASE_PTR                (FGPIOC) //!< Freescale style base pointer
/**
 * @} */ /* End group FGPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FGPIO_Peripheral_access_layer_GROUP FGPIO Peripheral Access Layer
* @brief C Struct for FGPIO
* @{
*/

/* ================================================================================ */
/* ================           FGPIOD (derived from FGPIOA)         ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* FGPIOD - Peripheral instance base addresses */
#define FGPIOD_BasePtr                 0xF80000C0UL //!< Peripheral base address
#define FGPIOD                         ((GPIO_Type *) FGPIOD_BasePtr) //!< Freescale base pointer
#define FGPIOD_BASE_PTR                (FGPIOD) //!< Freescale style base pointer
/**
 * @} */ /* End group FGPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FGPIO_Peripheral_access_layer_GROUP FGPIO Peripheral Access Layer
* @brief C Struct for FGPIO
* @{
*/

/* ================================================================================ */
/* ================           FGPIOE (derived from FGPIOA)         ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* FGPIOE - Peripheral instance base addresses */
#define FGPIOE_BasePtr                 0xF8000100UL //!< Peripheral base address
#define FGPIOE                         ((GPIO_Type *) FGPIOE_BasePtr) //!< Freescale base pointer
#define FGPIOE_BASE_PTR                (FGPIOE) //!< Freescale style base pointer
/**
 * @} */ /* End group FGPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FLEXIO_Peripheral_access_layer_GROUP FLEXIO Peripheral Access Layer
* @brief C Struct for FLEXIO
* @{
*/

/* ================================================================================ */
/* ================           FLEXIO0 (file:FLEXIO0_MKL82Z7)       ================ */
/* ================================================================================ */

/**
 * @brief The FLEXIO Memory Map/Register Definition can be found here
 */
/**
* @addtogroup FLEXIO_structs_GROUP FLEXIO struct
* @brief Struct for FLEXIO
* @{
*/
typedef struct {                                /*       FLEXIO0 Structure                                            */
   __I  uint32_t  VERID;                        /**< 0000: Version ID Register                                          */
   __I  uint32_t  PARAM;                        /**< 0004: Parameter Register                                           */
   __IO uint32_t  CTRL;                         /**< 0008: FlexIO Control Register                                      */
   __I  uint32_t  PIN;                          /**< 000C: Pin State Register                                           */
   __IO uint32_t  SHIFTSTAT;                    /**< 0010: Shifter Status Register                                      */
   __IO uint32_t  SHIFTERR;                     /**< 0014: Shifter Error Register                                       */
   __IO uint32_t  TIMSTAT;                      /**< 0018: Timer Status Register                                        */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  SHIFTSIEN;                    /**< 0020: Shifter Status Interrupt Enable                              */
   __IO uint32_t  SHIFTEIEN;                    /**< 0024: Shifter Error Interrupt Enable                               */
   __IO uint32_t  TIMIEN;                       /**< 0028: Timer Interrupt Enable Register                              */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  SHIFTSDEN;                    /**< 0030: Shifter Status DMA Enable                                    */
        uint8_t   RESERVED_2[12];              
   __IO uint32_t  SHIFTSTATE;                   /**< 0040: Shifter State Register                                       */
        uint8_t   RESERVED_3[60];              
   __IO uint32_t  SHIFTCTL[8];                  /**< 0080: Shifter Control N Register                                   */
        uint8_t   RESERVED_4[96];              
   __IO uint32_t  SHIFTCFG[8];                  /**< 0100: Shifter Configuration N Register                             */
        uint8_t   RESERVED_5[224];             
   __IO uint32_t  SHIFTBUF[8];                  /**< 0200: Shifter Buffer N Register                                    */
        uint8_t   RESERVED_6[96];              
   __IO uint32_t  SHIFTBUFBIS[8];               /**< 0280: Shifter Buffer N Bit Swapped Register                        */
        uint8_t   RESERVED_7[96];              
   __IO uint32_t  SHIFTBUFBYS[8];               /**< 0300: Shifter Buffer N Byte Swapped Register                       */
        uint8_t   RESERVED_8[96];              
   __IO uint32_t  SHIFTBUFBBS[8];               /**< 0380: Shifter Buffer N Bit Byte Swapped Register                   */
        uint8_t   RESERVED_9[96];              
   __IO uint32_t  TIMCTL[8];                    /**< 0400: Timer Control N Register                                     */
        uint8_t   RESERVED_10[96];             
   __IO uint32_t  TIMCFG[8];                    /**< 0480: Timer Configuration N Register                               */
        uint8_t   RESERVED_11[96];             
   __IO uint32_t  TIMCMP[8];                    /**< 0500: Timer Compare N Register                                     */
        uint8_t   RESERVED_12[352];            
   __IO uint32_t  SHIFTBUFNBS[8];               /**< 0680: Shifter Buffer N Nibble Byte Swapped Register                */
        uint8_t   RESERVED_13[96];             
   __IO uint32_t  SHIFTBUFHWS[8];               /**< 0700: Shifter Buffer N Half Word Swapped Register                  */
        uint8_t   RESERVED_14[96];             
   __IO uint32_t  SHIFTBUFNIS[8];               /**< 0780: Shifter Buffer N Nibble Swapped Register                     */
} FLEXIO_Type;

/**
 * @} */ /* End group FLEXIO_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FLEXIO0' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FLEXIO_Register_Masks_GROUP FLEXIO Register Masks
* @brief Register Masks for FLEXIO
* @{
*/
/* ------- VERID Bit Fields                         ------ */
#define FLEXIO_VERID_FEATURE_MASK                (0xFFFFU)                                           /*!< FLEXIO0_VERID.FEATURE Mask              */
#define FLEXIO_VERID_FEATURE_SHIFT               (0U)                                                /*!< FLEXIO0_VERID.FEATURE Position          */
#define FLEXIO_VERID_FEATURE(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< FLEXIO0_VERID.FEATURE Field             */
#define FLEXIO_VERID_MINOR_MASK                  (0xFF0000U)                                         /*!< FLEXIO0_VERID.MINOR Mask                */
#define FLEXIO_VERID_MINOR_SHIFT                 (16U)                                               /*!< FLEXIO0_VERID.MINOR Position            */
#define FLEXIO_VERID_MINOR(x)                    (((uint32_t)(((uint32_t)(x))<<16U))&0xFF0000UL)     /*!< FLEXIO0_VERID.MINOR Field               */
#define FLEXIO_VERID_MAJOR_MASK                  (0xFF000000U)                                       /*!< FLEXIO0_VERID.MAJOR Mask                */
#define FLEXIO_VERID_MAJOR_SHIFT                 (24U)                                               /*!< FLEXIO0_VERID.MAJOR Position            */
#define FLEXIO_VERID_MAJOR(x)                    (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< FLEXIO0_VERID.MAJOR Field               */
/* ------- PARAM Bit Fields                         ------ */
#define FLEXIO_PARAM_SHIFTER_MASK                (0xFFU)                                             /*!< FLEXIO0_PARAM.SHIFTER Mask              */
#define FLEXIO_PARAM_SHIFTER_SHIFT               (0U)                                                /*!< FLEXIO0_PARAM.SHIFTER Position          */
#define FLEXIO_PARAM_SHIFTER(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< FLEXIO0_PARAM.SHIFTER Field             */
#define FLEXIO_PARAM_TIMER_MASK                  (0xFF00U)                                           /*!< FLEXIO0_PARAM.TIMER Mask                */
#define FLEXIO_PARAM_TIMER_SHIFT                 (8U)                                                /*!< FLEXIO0_PARAM.TIMER Position            */
#define FLEXIO_PARAM_TIMER(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< FLEXIO0_PARAM.TIMER Field               */
#define FLEXIO_PARAM_PIN_MASK                    (0xFF0000U)                                         /*!< FLEXIO0_PARAM.PIN Mask                  */
#define FLEXIO_PARAM_PIN_SHIFT                   (16U)                                               /*!< FLEXIO0_PARAM.PIN Position              */
#define FLEXIO_PARAM_PIN(x)                      (((uint32_t)(((uint32_t)(x))<<16U))&0xFF0000UL)     /*!< FLEXIO0_PARAM.PIN Field                 */
#define FLEXIO_PARAM_TRIGGER_MASK                (0xFF000000U)                                       /*!< FLEXIO0_PARAM.TRIGGER Mask              */
#define FLEXIO_PARAM_TRIGGER_SHIFT               (24U)                                               /*!< FLEXIO0_PARAM.TRIGGER Position          */
#define FLEXIO_PARAM_TRIGGER(x)                  (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< FLEXIO0_PARAM.TRIGGER Field             */
/* ------- CTRL Bit Fields                          ------ */
#define FLEXIO_CTRL_FLEXEN_MASK                  (0x1U)                                              /*!< FLEXIO0_CTRL.FLEXEN Mask                */
#define FLEXIO_CTRL_FLEXEN_SHIFT                 (0U)                                                /*!< FLEXIO0_CTRL.FLEXEN Position            */
#define FLEXIO_CTRL_FLEXEN(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FLEXIO0_CTRL.FLEXEN Field               */
#define FLEXIO_CTRL_SWRST_MASK                   (0x2U)                                              /*!< FLEXIO0_CTRL.SWRST Mask                 */
#define FLEXIO_CTRL_SWRST_SHIFT                  (1U)                                                /*!< FLEXIO0_CTRL.SWRST Position             */
#define FLEXIO_CTRL_SWRST(x)                     (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FLEXIO0_CTRL.SWRST Field                */
#define FLEXIO_CTRL_FASTACC_MASK                 (0x4U)                                              /*!< FLEXIO0_CTRL.FASTACC Mask               */
#define FLEXIO_CTRL_FASTACC_SHIFT                (2U)                                                /*!< FLEXIO0_CTRL.FASTACC Position           */
#define FLEXIO_CTRL_FASTACC(x)                   (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FLEXIO0_CTRL.FASTACC Field              */
#define FLEXIO_CTRL_DBGE_MASK                    (0x40000000U)                                       /*!< FLEXIO0_CTRL.DBGE Mask                  */
#define FLEXIO_CTRL_DBGE_SHIFT                   (30U)                                               /*!< FLEXIO0_CTRL.DBGE Position              */
#define FLEXIO_CTRL_DBGE(x)                      (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< FLEXIO0_CTRL.DBGE Field                 */
#define FLEXIO_CTRL_DOZEN_MASK                   (0x80000000U)                                       /*!< FLEXIO0_CTRL.DOZEN Mask                 */
#define FLEXIO_CTRL_DOZEN_SHIFT                  (31U)                                               /*!< FLEXIO0_CTRL.DOZEN Position             */
#define FLEXIO_CTRL_DOZEN(x)                     (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< FLEXIO0_CTRL.DOZEN Field                */
/* ------- PIN Bit Fields                           ------ */
#define FLEXIO_PIN_PDI_MASK                      (0xFFFFFFFFU)                                       /*!< FLEXIO0_PIN.PDI Mask                    */
#define FLEXIO_PIN_PDI_SHIFT                     (0U)                                                /*!< FLEXIO0_PIN.PDI Position                */
#define FLEXIO_PIN_PDI(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FLEXIO0_PIN.PDI Field                   */
/* ------- SHIFTSTAT Bit Fields                     ------ */
#define FLEXIO_SHIFTSTAT_SSF_MASK                (0xFFU)                                             /*!< FLEXIO0_SHIFTSTAT.SSF Mask              */
#define FLEXIO_SHIFTSTAT_SSF_SHIFT               (0U)                                                /*!< FLEXIO0_SHIFTSTAT.SSF Position          */
#define FLEXIO_SHIFTSTAT_SSF(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< FLEXIO0_SHIFTSTAT.SSF Field             */
/* ------- SHIFTERR Bit Fields                      ------ */
#define FLEXIO_SHIFTERR_SEF_MASK                 (0xFFU)                                             /*!< FLEXIO0_SHIFTERR.SEF Mask               */
#define FLEXIO_SHIFTERR_SEF_SHIFT                (0U)                                                /*!< FLEXIO0_SHIFTERR.SEF Position           */
#define FLEXIO_SHIFTERR_SEF(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< FLEXIO0_SHIFTERR.SEF Field              */
/* ------- TIMSTAT Bit Fields                       ------ */
#define FLEXIO_TIMSTAT_TSF_MASK                  (0xFFU)                                             /*!< FLEXIO0_TIMSTAT.TSF Mask                */
#define FLEXIO_TIMSTAT_TSF_SHIFT                 (0U)                                                /*!< FLEXIO0_TIMSTAT.TSF Position            */
#define FLEXIO_TIMSTAT_TSF(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< FLEXIO0_TIMSTAT.TSF Field               */
/* ------- SHIFTSIEN Bit Fields                     ------ */
#define FLEXIO_SHIFTSIEN_SSIE_MASK               (0xFFU)                                             /*!< FLEXIO0_SHIFTSIEN.SSIE Mask             */
#define FLEXIO_SHIFTSIEN_SSIE_SHIFT              (0U)                                                /*!< FLEXIO0_SHIFTSIEN.SSIE Position         */
#define FLEXIO_SHIFTSIEN_SSIE(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< FLEXIO0_SHIFTSIEN.SSIE Field            */
/* ------- SHIFTEIEN Bit Fields                     ------ */
#define FLEXIO_SHIFTEIEN_SEIE_MASK               (0xFFU)                                             /*!< FLEXIO0_SHIFTEIEN.SEIE Mask             */
#define FLEXIO_SHIFTEIEN_SEIE_SHIFT              (0U)                                                /*!< FLEXIO0_SHIFTEIEN.SEIE Position         */
#define FLEXIO_SHIFTEIEN_SEIE(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< FLEXIO0_SHIFTEIEN.SEIE Field            */
/* ------- TIMIEN Bit Fields                        ------ */
#define FLEXIO_TIMIEN_TEIE_MASK                  (0xFFU)                                             /*!< FLEXIO0_TIMIEN.TEIE Mask                */
#define FLEXIO_TIMIEN_TEIE_SHIFT                 (0U)                                                /*!< FLEXIO0_TIMIEN.TEIE Position            */
#define FLEXIO_TIMIEN_TEIE(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< FLEXIO0_TIMIEN.TEIE Field               */
/* ------- SHIFTSDEN Bit Fields                     ------ */
#define FLEXIO_SHIFTSDEN_SSDE_MASK               (0xFFU)                                             /*!< FLEXIO0_SHIFTSDEN.SSDE Mask             */
#define FLEXIO_SHIFTSDEN_SSDE_SHIFT              (0U)                                                /*!< FLEXIO0_SHIFTSDEN.SSDE Position         */
#define FLEXIO_SHIFTSDEN_SSDE(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< FLEXIO0_SHIFTSDEN.SSDE Field            */
/* ------- SHIFTSTATE Bit Fields                    ------ */
#define FLEXIO_SHIFTSTATE_STATE_MASK             (0x7U)                                              /*!< FLEXIO0_SHIFTSTATE.STATE Mask           */
#define FLEXIO_SHIFTSTATE_STATE_SHIFT            (0U)                                                /*!< FLEXIO0_SHIFTSTATE.STATE Position       */
#define FLEXIO_SHIFTSTATE_STATE(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< FLEXIO0_SHIFTSTATE.STATE Field          */
/* ------- SHIFTCTL Bit Fields                      ------ */
#define FLEXIO_SHIFTCTL_SMOD_MASK                (0x7U)                                              /*!< FLEXIO0_SHIFTCTL.SMOD Mask              */
#define FLEXIO_SHIFTCTL_SMOD_SHIFT               (0U)                                                /*!< FLEXIO0_SHIFTCTL.SMOD Position          */
#define FLEXIO_SHIFTCTL_SMOD(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< FLEXIO0_SHIFTCTL.SMOD Field             */
#define FLEXIO_SHIFTCTL_PINPOL_MASK              (0x80U)                                             /*!< FLEXIO0_SHIFTCTL.PINPOL Mask            */
#define FLEXIO_SHIFTCTL_PINPOL_SHIFT             (7U)                                                /*!< FLEXIO0_SHIFTCTL.PINPOL Position        */
#define FLEXIO_SHIFTCTL_PINPOL(x)                (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FLEXIO0_SHIFTCTL.PINPOL Field           */
#define FLEXIO_SHIFTCTL_PINSEL_MASK              (0x1F00U)                                           /*!< FLEXIO0_SHIFTCTL.PINSEL Mask            */
#define FLEXIO_SHIFTCTL_PINSEL_SHIFT             (8U)                                                /*!< FLEXIO0_SHIFTCTL.PINSEL Position        */
#define FLEXIO_SHIFTCTL_PINSEL(x)                (((uint32_t)(((uint32_t)(x))<<8U))&0x1F00UL)        /*!< FLEXIO0_SHIFTCTL.PINSEL Field           */
#define FLEXIO_SHIFTCTL_PINCFG_MASK              (0x30000U)                                          /*!< FLEXIO0_SHIFTCTL.PINCFG Mask            */
#define FLEXIO_SHIFTCTL_PINCFG_SHIFT             (16U)                                               /*!< FLEXIO0_SHIFTCTL.PINCFG Position        */
#define FLEXIO_SHIFTCTL_PINCFG(x)                (((uint32_t)(((uint32_t)(x))<<16U))&0x30000UL)      /*!< FLEXIO0_SHIFTCTL.PINCFG Field           */
#define FLEXIO_SHIFTCTL_TIMPOL_MASK              (0x800000U)                                         /*!< FLEXIO0_SHIFTCTL.TIMPOL Mask            */
#define FLEXIO_SHIFTCTL_TIMPOL_SHIFT             (23U)                                               /*!< FLEXIO0_SHIFTCTL.TIMPOL Position        */
#define FLEXIO_SHIFTCTL_TIMPOL(x)                (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< FLEXIO0_SHIFTCTL.TIMPOL Field           */
#define FLEXIO_SHIFTCTL_TIMSEL_MASK              (0x7000000U)                                        /*!< FLEXIO0_SHIFTCTL.TIMSEL Mask            */
#define FLEXIO_SHIFTCTL_TIMSEL_SHIFT             (24U)                                               /*!< FLEXIO0_SHIFTCTL.TIMSEL Position        */
#define FLEXIO_SHIFTCTL_TIMSEL(x)                (((uint32_t)(((uint32_t)(x))<<24U))&0x7000000UL)    /*!< FLEXIO0_SHIFTCTL.TIMSEL Field           */
/* ------- SHIFTCFG Bit Fields                      ------ */
#define FLEXIO_SHIFTCFG_SSTART_MASK              (0x3U)                                              /*!< FLEXIO0_SHIFTCFG.SSTART Mask            */
#define FLEXIO_SHIFTCFG_SSTART_SHIFT             (0U)                                                /*!< FLEXIO0_SHIFTCFG.SSTART Position        */
#define FLEXIO_SHIFTCFG_SSTART(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< FLEXIO0_SHIFTCFG.SSTART Field           */
#define FLEXIO_SHIFTCFG_SSTOP_MASK               (0x30U)                                             /*!< FLEXIO0_SHIFTCFG.SSTOP Mask             */
#define FLEXIO_SHIFTCFG_SSTOP_SHIFT              (4U)                                                /*!< FLEXIO0_SHIFTCFG.SSTOP Position         */
#define FLEXIO_SHIFTCFG_SSTOP(x)                 (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< FLEXIO0_SHIFTCFG.SSTOP Field            */
#define FLEXIO_SHIFTCFG_INSRC_MASK               (0x100U)                                            /*!< FLEXIO0_SHIFTCFG.INSRC Mask             */
#define FLEXIO_SHIFTCFG_INSRC_SHIFT              (8U)                                                /*!< FLEXIO0_SHIFTCFG.INSRC Position         */
#define FLEXIO_SHIFTCFG_INSRC(x)                 (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< FLEXIO0_SHIFTCFG.INSRC Field            */
#define FLEXIO_SHIFTCFG_PWIDTH_MASK              (0x1F0000U)                                         /*!< FLEXIO0_SHIFTCFG.PWIDTH Mask            */
#define FLEXIO_SHIFTCFG_PWIDTH_SHIFT             (16U)                                               /*!< FLEXIO0_SHIFTCFG.PWIDTH Position        */
#define FLEXIO_SHIFTCFG_PWIDTH(x)                (((uint32_t)(((uint32_t)(x))<<16U))&0x1F0000UL)     /*!< FLEXIO0_SHIFTCFG.PWIDTH Field           */
/* ------- SHIFTBUF Bit Fields                      ------ */
#define FLEXIO_SHIFTBUF_SHIFTBUF_MASK            (0xFFFFFFFFU)                                       /*!< FLEXIO0_SHIFTBUF.SHIFTBUF Mask          */
#define FLEXIO_SHIFTBUF_SHIFTBUF_SHIFT           (0U)                                                /*!< FLEXIO0_SHIFTBUF.SHIFTBUF Position      */
#define FLEXIO_SHIFTBUF_SHIFTBUF(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FLEXIO0_SHIFTBUF.SHIFTBUF Field         */
/* ------- SHIFTBUFBIS Bit Fields                   ------ */
#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_MASK      (0xFFFFFFFFU)                                       /*!< FLEXIO0_SHIFTBUFBIS.SHIFTBUFBIS Mask    */
#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_SHIFT     (0U)                                                /*!< FLEXIO0_SHIFTBUFBIS.SHIFTBUFBIS Position*/
#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS(x)        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FLEXIO0_SHIFTBUFBIS.SHIFTBUFBIS Field   */
/* ------- SHIFTBUFBYS Bit Fields                   ------ */
#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_MASK      (0xFFFFFFFFU)                                       /*!< FLEXIO0_SHIFTBUFBYS.SHIFTBUFBYS Mask    */
#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_SHIFT     (0U)                                                /*!< FLEXIO0_SHIFTBUFBYS.SHIFTBUFBYS Position*/
#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS(x)        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FLEXIO0_SHIFTBUFBYS.SHIFTBUFBYS Field   */
/* ------- SHIFTBUFBBS Bit Fields                   ------ */
#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_MASK      (0xFFFFFFFFU)                                       /*!< FLEXIO0_SHIFTBUFBBS.SHIFTBUFBBS Mask    */
#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_SHIFT     (0U)                                                /*!< FLEXIO0_SHIFTBUFBBS.SHIFTBUFBBS Position*/
#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS(x)        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FLEXIO0_SHIFTBUFBBS.SHIFTBUFBBS Field   */
/* ------- TIMCTL Bit Fields                        ------ */
#define FLEXIO_TIMCTL_TIMOD_MASK                 (0x3U)                                              /*!< FLEXIO0_TIMCTL.TIMOD Mask               */
#define FLEXIO_TIMCTL_TIMOD_SHIFT                (0U)                                                /*!< FLEXIO0_TIMCTL.TIMOD Position           */
#define FLEXIO_TIMCTL_TIMOD(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< FLEXIO0_TIMCTL.TIMOD Field              */
#define FLEXIO_TIMCTL_PINPOL_MASK                (0x80U)                                             /*!< FLEXIO0_TIMCTL.PINPOL Mask              */
#define FLEXIO_TIMCTL_PINPOL_SHIFT               (7U)                                                /*!< FLEXIO0_TIMCTL.PINPOL Position          */
#define FLEXIO_TIMCTL_PINPOL(x)                  (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FLEXIO0_TIMCTL.PINPOL Field             */
#define FLEXIO_TIMCTL_PINSEL_MASK                (0x1F00U)                                           /*!< FLEXIO0_TIMCTL.PINSEL Mask              */
#define FLEXIO_TIMCTL_PINSEL_SHIFT               (8U)                                                /*!< FLEXIO0_TIMCTL.PINSEL Position          */
#define FLEXIO_TIMCTL_PINSEL(x)                  (((uint32_t)(((uint32_t)(x))<<8U))&0x1F00UL)        /*!< FLEXIO0_TIMCTL.PINSEL Field             */
#define FLEXIO_TIMCTL_PINCFG_MASK                (0x30000U)                                          /*!< FLEXIO0_TIMCTL.PINCFG Mask              */
#define FLEXIO_TIMCTL_PINCFG_SHIFT               (16U)                                               /*!< FLEXIO0_TIMCTL.PINCFG Position          */
#define FLEXIO_TIMCTL_PINCFG(x)                  (((uint32_t)(((uint32_t)(x))<<16U))&0x30000UL)      /*!< FLEXIO0_TIMCTL.PINCFG Field             */
#define FLEXIO_TIMCTL_TRGSRC_MASK                (0x400000U)                                         /*!< FLEXIO0_TIMCTL.TRGSRC Mask              */
#define FLEXIO_TIMCTL_TRGSRC_SHIFT               (22U)                                               /*!< FLEXIO0_TIMCTL.TRGSRC Position          */
#define FLEXIO_TIMCTL_TRGSRC(x)                  (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< FLEXIO0_TIMCTL.TRGSRC Field             */
#define FLEXIO_TIMCTL_TRGPOL_MASK                (0x800000U)                                         /*!< FLEXIO0_TIMCTL.TRGPOL Mask              */
#define FLEXIO_TIMCTL_TRGPOL_SHIFT               (23U)                                               /*!< FLEXIO0_TIMCTL.TRGPOL Position          */
#define FLEXIO_TIMCTL_TRGPOL(x)                  (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< FLEXIO0_TIMCTL.TRGPOL Field             */
#define FLEXIO_TIMCTL_TRGSEL_MASK                (0x3F000000U)                                       /*!< FLEXIO0_TIMCTL.TRGSEL Mask              */
#define FLEXIO_TIMCTL_TRGSEL_SHIFT               (24U)                                               /*!< FLEXIO0_TIMCTL.TRGSEL Position          */
#define FLEXIO_TIMCTL_TRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<24U))&0x3F000000UL)   /*!< FLEXIO0_TIMCTL.TRGSEL Field             */
/* ------- TIMCFG Bit Fields                        ------ */
#define FLEXIO_TIMCFG_TSTART_MASK                (0x2U)                                              /*!< FLEXIO0_TIMCFG.TSTART Mask              */
#define FLEXIO_TIMCFG_TSTART_SHIFT               (1U)                                                /*!< FLEXIO0_TIMCFG.TSTART Position          */
#define FLEXIO_TIMCFG_TSTART(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FLEXIO0_TIMCFG.TSTART Field             */
#define FLEXIO_TIMCFG_TSTOP_MASK                 (0x30U)                                             /*!< FLEXIO0_TIMCFG.TSTOP Mask               */
#define FLEXIO_TIMCFG_TSTOP_SHIFT                (4U)                                                /*!< FLEXIO0_TIMCFG.TSTOP Position           */
#define FLEXIO_TIMCFG_TSTOP(x)                   (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< FLEXIO0_TIMCFG.TSTOP Field              */
#define FLEXIO_TIMCFG_TIMENA_MASK                (0x700U)                                            /*!< FLEXIO0_TIMCFG.TIMENA Mask              */
#define FLEXIO_TIMCFG_TIMENA_SHIFT               (8U)                                                /*!< FLEXIO0_TIMCFG.TIMENA Position          */
#define FLEXIO_TIMCFG_TIMENA(x)                  (((uint32_t)(((uint32_t)(x))<<8U))&0x700UL)         /*!< FLEXIO0_TIMCFG.TIMENA Field             */
#define FLEXIO_TIMCFG_TIMDIS_MASK                (0x7000U)                                           /*!< FLEXIO0_TIMCFG.TIMDIS Mask              */
#define FLEXIO_TIMCFG_TIMDIS_SHIFT               (12U)                                               /*!< FLEXIO0_TIMCFG.TIMDIS Position          */
#define FLEXIO_TIMCFG_TIMDIS(x)                  (((uint32_t)(((uint32_t)(x))<<12U))&0x7000UL)       /*!< FLEXIO0_TIMCFG.TIMDIS Field             */
#define FLEXIO_TIMCFG_TIMRST_MASK                (0x70000U)                                          /*!< FLEXIO0_TIMCFG.TIMRST Mask              */
#define FLEXIO_TIMCFG_TIMRST_SHIFT               (16U)                                               /*!< FLEXIO0_TIMCFG.TIMRST Position          */
#define FLEXIO_TIMCFG_TIMRST(x)                  (((uint32_t)(((uint32_t)(x))<<16U))&0x70000UL)      /*!< FLEXIO0_TIMCFG.TIMRST Field             */
#define FLEXIO_TIMCFG_TIMDEC_MASK                (0x300000U)                                         /*!< FLEXIO0_TIMCFG.TIMDEC Mask              */
#define FLEXIO_TIMCFG_TIMDEC_SHIFT               (20U)                                               /*!< FLEXIO0_TIMCFG.TIMDEC Position          */
#define FLEXIO_TIMCFG_TIMDEC(x)                  (((uint32_t)(((uint32_t)(x))<<20U))&0x300000UL)     /*!< FLEXIO0_TIMCFG.TIMDEC Field             */
#define FLEXIO_TIMCFG_TIMOUT_MASK                (0x3000000U)                                        /*!< FLEXIO0_TIMCFG.TIMOUT Mask              */
#define FLEXIO_TIMCFG_TIMOUT_SHIFT               (24U)                                               /*!< FLEXIO0_TIMCFG.TIMOUT Position          */
#define FLEXIO_TIMCFG_TIMOUT(x)                  (((uint32_t)(((uint32_t)(x))<<24U))&0x3000000UL)    /*!< FLEXIO0_TIMCFG.TIMOUT Field             */
/* ------- TIMCMP Bit Fields                        ------ */
#define FLEXIO_TIMCMP_CMP_MASK                   (0xFFFFU)                                           /*!< FLEXIO0_TIMCMP.CMP Mask                 */
#define FLEXIO_TIMCMP_CMP_SHIFT                  (0U)                                                /*!< FLEXIO0_TIMCMP.CMP Position             */
#define FLEXIO_TIMCMP_CMP(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< FLEXIO0_TIMCMP.CMP Field                */
/* ------- SHIFTBUFNBS Bit Fields                   ------ */
#define FLEXIO_SHIFTBUFNBS_SHIFTBUFNBS_MASK      (0xFFFFFFFFU)                                       /*!< FLEXIO0_SHIFTBUFNBS.SHIFTBUFNBS Mask    */
#define FLEXIO_SHIFTBUFNBS_SHIFTBUFNBS_SHIFT     (0U)                                                /*!< FLEXIO0_SHIFTBUFNBS.SHIFTBUFNBS Position*/
#define FLEXIO_SHIFTBUFNBS_SHIFTBUFNBS(x)        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FLEXIO0_SHIFTBUFNBS.SHIFTBUFNBS Field   */
/* ------- SHIFTBUFHWS Bit Fields                   ------ */
#define FLEXIO_SHIFTBUFHWS_SHIFTBUFHWS_MASK      (0xFFFFFFFFU)                                       /*!< FLEXIO0_SHIFTBUFHWS.SHIFTBUFHWS Mask    */
#define FLEXIO_SHIFTBUFHWS_SHIFTBUFHWS_SHIFT     (0U)                                                /*!< FLEXIO0_SHIFTBUFHWS.SHIFTBUFHWS Position*/
#define FLEXIO_SHIFTBUFHWS_SHIFTBUFHWS(x)        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FLEXIO0_SHIFTBUFHWS.SHIFTBUFHWS Field   */
/* ------- SHIFTBUFNIS Bit Fields                   ------ */
#define FLEXIO_SHIFTBUFNIS_SHIFTBUFNIS_MASK      (0xFFFFFFFFU)                                       /*!< FLEXIO0_SHIFTBUFNIS.SHIFTBUFNIS Mask    */
#define FLEXIO_SHIFTBUFNIS_SHIFTBUFNIS_SHIFT     (0U)                                                /*!< FLEXIO0_SHIFTBUFNIS.SHIFTBUFNIS Position*/
#define FLEXIO_SHIFTBUFNIS_SHIFTBUFNIS(x)        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FLEXIO0_SHIFTBUFNIS.SHIFTBUFNIS Field   */
/**
 * @} */ /* End group FLEXIO_Register_Masks_GROUP 
 */

/* FLEXIO0 - Peripheral instance base addresses */
#define FLEXIO0_BasePtr                0x4005F000UL //!< Peripheral base address
#define FLEXIO0                        ((FLEXIO_Type *) FLEXIO0_BasePtr) //!< Freescale base pointer
#define FLEXIO0_BASE_PTR               (FLEXIO0) //!< Freescale style base pointer
/**
 * @} */ /* End group FLEXIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTFA_Peripheral_access_layer_GROUP FTFA Peripheral Access Layer
* @brief C Struct for FTFA
* @{
*/

/* ================================================================================ */
/* ================           FTFA (file:FTFA_MKL82Z7)             ================ */
/* ================================================================================ */

/**
 * @brief Flash Memory Interface
 */
/**
* @addtogroup FTFA_structs_GROUP FTFA struct
* @brief Struct for FTFA
* @{
*/
typedef struct {                                /*       FTFA Structure                                               */
   __IO uint8_t   FSTAT;                        /**< 0000: Flash Status Register                                        */
   __IO uint8_t   FCNFG;                        /**< 0001: Flash Configuration Register                                 */
   __I  uint8_t   FSEC;                         /**< 0002: Flash Security Register                                      */
   __I  uint8_t   FOPT;                         /**< 0003: Flash Option Register                                        */
   __IO uint8_t   FCCOB3;                       /**< 0004: Flash Common Command Object                                  */
   __IO uint8_t   FCCOB2;                       /**< 0005: Flash Common Command Object                                  */
   __IO uint8_t   FCCOB1;                       /**< 0006: Flash Common Command Object                                  */
   __IO uint8_t   FCCOB0;                       /**< 0007: Flash Common Command Object                                  */
   __IO uint8_t   FCCOB7;                       /**< 0008: Flash Common Command Object                                  */
   __IO uint8_t   FCCOB6;                       /**< 0009: Flash Common Command Object                                  */
   __IO uint8_t   FCCOB5;                       /**< 000A: Flash Common Command Object                                  */
   __IO uint8_t   FCCOB4;                       /**< 000B: Flash Common Command Object                                  */
   __IO uint8_t   FCCOBB;                       /**< 000C: Flash Common Command Object                                  */
   __IO uint8_t   FCCOBA;                       /**< 000D: Flash Common Command Object                                  */
   __IO uint8_t   FCCOB9;                       /**< 000E: Flash Common Command Object                                  */
   __IO uint8_t   FCCOB8;                       /**< 000F: Flash Common Command Object                                  */
   __IO uint8_t   FPROT3;                       /**< 0010: Program Flash Protection                                     */
   __IO uint8_t   FPROT2;                       /**< 0011: Program Flash Protection                                     */
   __IO uint8_t   FPROT1;                       /**< 0012: Program Flash Protection                                     */
   __IO uint8_t   FPROT0;                       /**< 0013: Program Flash Protection                                     */
        uint8_t   RESERVED_0[4];               
   __I  uint8_t   XACCH3;                       /**< 0018: Execute-only Access                                          */
   __I  uint8_t   XACCH2;                       /**< 0019: Execute-only Access                                          */
   __I  uint8_t   XACCH1;                       /**< 001A: Execute-only Access                                          */
   __I  uint8_t   XACCH0;                       /**< 001B: Execute-only Access                                          */
   __I  uint8_t   XACCL3;                       /**< 001C: Execute-only Access                                          */
   __I  uint8_t   XACCL2;                       /**< 001D: Execute-only Access                                          */
   __I  uint8_t   XACCL1;                       /**< 001E: Execute-only Access                                          */
   __I  uint8_t   XACCL0;                       /**< 001F: Execute-only Access                                          */
   __I  uint8_t   SACCH3;                       /**< 0020: Supervisor-only Access                                       */
   __I  uint8_t   SACCH2;                       /**< 0021: Supervisor-only Access                                       */
   __I  uint8_t   SACCH1;                       /**< 0022: Supervisor-only Access                                       */
   __I  uint8_t   SACCH0;                       /**< 0023: Supervisor-only Access                                       */
   __I  uint8_t   SACCL3;                       /**< 0024: Supervisor-only Access                                       */
   __I  uint8_t   SACCL2;                       /**< 0025: Supervisor-only Access                                       */
   __I  uint8_t   SACCL1;                       /**< 0026: Supervisor-only Access                                       */
   __I  uint8_t   SACCL0;                       /**< 0027: Supervisor-only Access                                       */
   __I  uint8_t   FACSS;                        /**< 0028: Flash Access Segment Size Register                           */
        uint8_t   RESERVED_1[2];               
   __I  uint8_t   FACSN;                        /**< 002B: Flash Access Segment Number Register                         */
} FTFA_Type;

/**
 * @} */ /* End group FTFA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTFA' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FTFA_Register_Masks_GROUP FTFA Register Masks
* @brief Register Masks for FTFA
* @{
*/
/* ------- FSTAT Bit Fields                         ------ */
#define FTFA_FSTAT_MGSTAT0_MASK                  (0x1U)                                              /*!< FTFA_FSTAT.MGSTAT0 Mask                 */
#define FTFA_FSTAT_MGSTAT0_SHIFT                 (0U)                                                /*!< FTFA_FSTAT.MGSTAT0 Position             */
#define FTFA_FSTAT_MGSTAT0(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< FTFA_FSTAT.MGSTAT0 Field                */
#define FTFA_FSTAT_FPVIOL_MASK                   (0x10U)                                             /*!< FTFA_FSTAT.FPVIOL Mask                  */
#define FTFA_FSTAT_FPVIOL_SHIFT                  (4U)                                                /*!< FTFA_FSTAT.FPVIOL Position              */
#define FTFA_FSTAT_FPVIOL(x)                     (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< FTFA_FSTAT.FPVIOL Field                 */
#define FTFA_FSTAT_ACCERR_MASK                   (0x20U)                                             /*!< FTFA_FSTAT.ACCERR Mask                  */
#define FTFA_FSTAT_ACCERR_SHIFT                  (5U)                                                /*!< FTFA_FSTAT.ACCERR Position              */
#define FTFA_FSTAT_ACCERR(x)                     (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< FTFA_FSTAT.ACCERR Field                 */
#define FTFA_FSTAT_RDCOLERR_MASK                 (0x40U)                                             /*!< FTFA_FSTAT.RDCOLERR Mask                */
#define FTFA_FSTAT_RDCOLERR_SHIFT                (6U)                                                /*!< FTFA_FSTAT.RDCOLERR Position            */
#define FTFA_FSTAT_RDCOLERR(x)                   (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< FTFA_FSTAT.RDCOLERR Field               */
#define FTFA_FSTAT_CCIF_MASK                     (0x80U)                                             /*!< FTFA_FSTAT.CCIF Mask                    */
#define FTFA_FSTAT_CCIF_SHIFT                    (7U)                                                /*!< FTFA_FSTAT.CCIF Position                */
#define FTFA_FSTAT_CCIF(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< FTFA_FSTAT.CCIF Field                   */
/* ------- FCNFG Bit Fields                         ------ */
#define FTFA_FCNFG_ERSSUSP_MASK                  (0x10U)                                             /*!< FTFA_FCNFG.ERSSUSP Mask                 */
#define FTFA_FCNFG_ERSSUSP_SHIFT                 (4U)                                                /*!< FTFA_FCNFG.ERSSUSP Position             */
#define FTFA_FCNFG_ERSSUSP(x)                    (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< FTFA_FCNFG.ERSSUSP Field                */
#define FTFA_FCNFG_ERSAREQ_MASK                  (0x20U)                                             /*!< FTFA_FCNFG.ERSAREQ Mask                 */
#define FTFA_FCNFG_ERSAREQ_SHIFT                 (5U)                                                /*!< FTFA_FCNFG.ERSAREQ Position             */
#define FTFA_FCNFG_ERSAREQ(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< FTFA_FCNFG.ERSAREQ Field                */
#define FTFA_FCNFG_RDCOLLIE_MASK                 (0x40U)                                             /*!< FTFA_FCNFG.RDCOLLIE Mask                */
#define FTFA_FCNFG_RDCOLLIE_SHIFT                (6U)                                                /*!< FTFA_FCNFG.RDCOLLIE Position            */
#define FTFA_FCNFG_RDCOLLIE(x)                   (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< FTFA_FCNFG.RDCOLLIE Field               */
#define FTFA_FCNFG_CCIE_MASK                     (0x80U)                                             /*!< FTFA_FCNFG.CCIE Mask                    */
#define FTFA_FCNFG_CCIE_SHIFT                    (7U)                                                /*!< FTFA_FCNFG.CCIE Position                */
#define FTFA_FCNFG_CCIE(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< FTFA_FCNFG.CCIE Field                   */
/* ------- FSEC Bit Fields                          ------ */
#define FTFA_FSEC_SEC_MASK                       (0x3U)                                              /*!< FTFA_FSEC.SEC Mask                      */
#define FTFA_FSEC_SEC_SHIFT                      (0U)                                                /*!< FTFA_FSEC.SEC Position                  */
#define FTFA_FSEC_SEC(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< FTFA_FSEC.SEC Field                     */
#define FTFA_FSEC_FSLACC_MASK                    (0xCU)                                              /*!< FTFA_FSEC.FSLACC Mask                   */
#define FTFA_FSEC_FSLACC_SHIFT                   (2U)                                                /*!< FTFA_FSEC.FSLACC Position               */
#define FTFA_FSEC_FSLACC(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< FTFA_FSEC.FSLACC Field                  */
#define FTFA_FSEC_MEEN_MASK                      (0x30U)                                             /*!< FTFA_FSEC.MEEN Mask                     */
#define FTFA_FSEC_MEEN_SHIFT                     (4U)                                                /*!< FTFA_FSEC.MEEN Position                 */
#define FTFA_FSEC_MEEN(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< FTFA_FSEC.MEEN Field                    */
#define FTFA_FSEC_KEYEN_MASK                     (0xC0U)                                             /*!< FTFA_FSEC.KEYEN Mask                    */
#define FTFA_FSEC_KEYEN_SHIFT                    (6U)                                                /*!< FTFA_FSEC.KEYEN Position                */
#define FTFA_FSEC_KEYEN(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< FTFA_FSEC.KEYEN Field                   */
/* ------- FOPT Bit Fields                          ------ */
#define FTFA_FOPT_OPT_MASK                       (0xFFU)                                             /*!< FTFA_FOPT.OPT Mask                      */
#define FTFA_FOPT_OPT_SHIFT                      (0U)                                                /*!< FTFA_FOPT.OPT Position                  */
#define FTFA_FOPT_OPT(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< FTFA_FOPT.OPT Field                     */
/* ------- FCCOB Bit Fields                         ------ */
#define FTFA_FCCOB_CCOBn_MASK                    (0xFFU)                                             /*!< FTFA_FCCOB.CCOBn Mask                   */
#define FTFA_FCCOB_CCOBn_SHIFT                   (0U)                                                /*!< FTFA_FCCOB.CCOBn Position               */
#define FTFA_FCCOB_CCOBn(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< FTFA_FCCOB.CCOBn Field                  */
/* ------- FPROT Bit Fields                         ------ */
#define FTFA_FPROT_PROT_MASK                     (0xFFU)                                             /*!< FTFA_FPROT.PROT Mask                    */
#define FTFA_FPROT_PROT_SHIFT                    (0U)                                                /*!< FTFA_FPROT.PROT Position                */
#define FTFA_FPROT_PROT(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< FTFA_FPROT.PROT Field                   */
/* ------- XACCH Bit Fields                         ------ */
#define FTFA_XACCH_XA_MASK                       (0xFFU)                                             /*!< FTFA_XACCH.XA Mask                      */
#define FTFA_XACCH_XA_SHIFT                      (0U)                                                /*!< FTFA_XACCH.XA Position                  */
#define FTFA_XACCH_XA(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< FTFA_XACCH.XA Field                     */
/* ------- XACCL Bit Fields                         ------ */
#define FTFA_XACCL_XA_MASK                       (0xFFU)                                             /*!< FTFA_XACCL.XA Mask                      */
#define FTFA_XACCL_XA_SHIFT                      (0U)                                                /*!< FTFA_XACCL.XA Position                  */
#define FTFA_XACCL_XA(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< FTFA_XACCL.XA Field                     */
/* ------- SACCH Bit Fields                         ------ */
#define FTFA_SACCH_SA_MASK                       (0xFFU)                                             /*!< FTFA_SACCH.SA Mask                      */
#define FTFA_SACCH_SA_SHIFT                      (0U)                                                /*!< FTFA_SACCH.SA Position                  */
#define FTFA_SACCH_SA(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< FTFA_SACCH.SA Field                     */
/* ------- SACCL Bit Fields                         ------ */
#define FTFA_SACCL_SA_MASK                       (0xFFU)                                             /*!< FTFA_SACCL.SA Mask                      */
#define FTFA_SACCL_SA_SHIFT                      (0U)                                                /*!< FTFA_SACCL.SA Position                  */
#define FTFA_SACCL_SA(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< FTFA_SACCL.SA Field                     */
/* ------- FACSS Bit Fields                         ------ */
#define FTFA_FACSS_SGSIZE_MASK                   (0xFFU)                                             /*!< FTFA_FACSS.SGSIZE Mask                  */
#define FTFA_FACSS_SGSIZE_SHIFT                  (0U)                                                /*!< FTFA_FACSS.SGSIZE Position              */
#define FTFA_FACSS_SGSIZE(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< FTFA_FACSS.SGSIZE Field                 */
/* ------- FACSN Bit Fields                         ------ */
#define FTFA_FACSN_NUMSG_MASK                    (0xFFU)                                             /*!< FTFA_FACSN.NUMSG Mask                   */
#define FTFA_FACSN_NUMSG_SHIFT                   (0U)                                                /*!< FTFA_FACSN.NUMSG Position               */
#define FTFA_FACSN_NUMSG(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< FTFA_FACSN.NUMSG Field                  */
/**
 * @} */ /* End group FTFA_Register_Masks_GROUP 
 */

/* FTFA - Peripheral instance base addresses */
#define FTFA_BasePtr                   0x40020000UL //!< Peripheral base address
#define FTFA                           ((FTFA_Type *) FTFA_BasePtr) //!< Freescale base pointer
#define FTFA_BASE_PTR                  (FTFA) //!< Freescale style base pointer
/**
 * @} */ /* End group FTFA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           GPIOA (derived from FGPIOA)          ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOA - Peripheral instance base addresses */
#define GPIOA_BasePtr                  0x400FF000UL //!< Peripheral base address
#define GPIOA                          ((GPIO_Type *) GPIOA_BasePtr) //!< Freescale base pointer
#define GPIOA_BASE_PTR                 (GPIOA) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           GPIOB (derived from FGPIOA)          ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOB - Peripheral instance base addresses */
#define GPIOB_BasePtr                  0x400FF040UL //!< Peripheral base address
#define GPIOB                          ((GPIO_Type *) GPIOB_BasePtr) //!< Freescale base pointer
#define GPIOB_BASE_PTR                 (GPIOB) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           GPIOC (derived from FGPIOA)          ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOC - Peripheral instance base addresses */
#define GPIOC_BasePtr                  0x400FF080UL //!< Peripheral base address
#define GPIOC                          ((GPIO_Type *) GPIOC_BasePtr) //!< Freescale base pointer
#define GPIOC_BASE_PTR                 (GPIOC) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           GPIOD (derived from FGPIOA)          ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOD - Peripheral instance base addresses */
#define GPIOD_BasePtr                  0x400FF0C0UL //!< Peripheral base address
#define GPIOD                          ((GPIO_Type *) GPIOD_BasePtr) //!< Freescale base pointer
#define GPIOD_BASE_PTR                 (GPIOD) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           GPIOE (derived from FGPIOA)          ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOE - Peripheral instance base addresses */
#define GPIOE_BasePtr                  0x400FF100UL //!< Peripheral base address
#define GPIOE                          ((GPIO_Type *) GPIOE_BasePtr) //!< Freescale base pointer
#define GPIOE_BASE_PTR                 (GPIOE) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           I2C0 (file:I2C0_MKL82Z7)             ================ */
/* ================================================================================ */

/**
 * @brief Inter-Integrated Circuit
 */
/**
* @addtogroup I2C_structs_GROUP I2C struct
* @brief Struct for I2C
* @{
*/
typedef struct {                                /*       I2C0 Structure                                               */
   __IO uint8_t   A1;                           /**< 0000: I2C Address Register 1                                       */
   __IO uint8_t   F;                            /**< 0001: I2C Frequency Divider register                               */
   __IO uint8_t   C1;                           /**< 0002: I2C Control Register 1                                       */
   __IO uint8_t   S;                            /**< 0003: I2C Status register                                          */
   __IO uint8_t   D;                            /**< 0004: I2C Data I/O register                                        */
   __IO uint8_t   C2;                           /**< 0005: I2C Control Register 2                                       */
   __IO uint8_t   FLT;                          /**< 0006: I2C Programmable Input Glitch Filter Register                */
   __IO uint8_t   RA;                           /**< 0007: I2C Range Address register                                   */
   __IO uint8_t   SMB;                          /**< 0008: I2C SMBus Control and Status register                        */
   __IO uint8_t   A2;                           /**< 0009: I2C Address Register 2                                       */
   __IO uint8_t   SLTH;                         /**< 000A: I2C SCL Low Timeout Register High                            */
   __IO uint8_t   SLTL;                         /**< 000B: I2C SCL Low Timeout Register Low                             */
   __IO uint8_t   S2;                           /**< 000C: I2C Status register 2                                        */
} I2C_Type;

/**
 * @} */ /* End group I2C_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'I2C0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup I2C_Register_Masks_GROUP I2C Register Masks
* @brief Register Masks for I2C
* @{
*/
/* ------- A1 Bit Fields                            ------ */
#define I2C_A1_AD_MASK                           (0xFEU)                                             /*!< I2C0_A1.AD Mask                         */
#define I2C_A1_AD_SHIFT                          (1U)                                                /*!< I2C0_A1.AD Position                     */
#define I2C_A1_AD(x)                             (((uint8_t)(((uint8_t)(x))<<1U))&0xFEUL)            /*!< I2C0_A1.AD Field                        */
/* ------- F Bit Fields                             ------ */
#define I2C_F_ICR_MASK                           (0x3FU)                                             /*!< I2C0_F.ICR Mask                         */
#define I2C_F_ICR_SHIFT                          (0U)                                                /*!< I2C0_F.ICR Position                     */
#define I2C_F_ICR(x)                             (((uint8_t)(((uint8_t)(x))<<0U))&0x3FUL)            /*!< I2C0_F.ICR Field                        */
#define I2C_F_MULT_MASK                          (0xC0U)                                             /*!< I2C0_F.MULT Mask                        */
#define I2C_F_MULT_SHIFT                         (6U)                                                /*!< I2C0_F.MULT Position                    */
#define I2C_F_MULT(x)                            (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< I2C0_F.MULT Field                       */
/* ------- C1 Bit Fields                            ------ */
#define I2C_C1_DMAEN_MASK                        (0x1U)                                              /*!< I2C0_C1.DMAEN Mask                      */
#define I2C_C1_DMAEN_SHIFT                       (0U)                                                /*!< I2C0_C1.DMAEN Position                  */
#define I2C_C1_DMAEN(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< I2C0_C1.DMAEN Field                     */
#define I2C_C1_WUEN_MASK                         (0x2U)                                              /*!< I2C0_C1.WUEN Mask                       */
#define I2C_C1_WUEN_SHIFT                        (1U)                                                /*!< I2C0_C1.WUEN Position                   */
#define I2C_C1_WUEN(x)                           (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< I2C0_C1.WUEN Field                      */
#define I2C_C1_RSTA_MASK                         (0x4U)                                              /*!< I2C0_C1.RSTA Mask                       */
#define I2C_C1_RSTA_SHIFT                        (2U)                                                /*!< I2C0_C1.RSTA Position                   */
#define I2C_C1_RSTA(x)                           (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< I2C0_C1.RSTA Field                      */
#define I2C_C1_TXAK_MASK                         (0x8U)                                              /*!< I2C0_C1.TXAK Mask                       */
#define I2C_C1_TXAK_SHIFT                        (3U)                                                /*!< I2C0_C1.TXAK Position                   */
#define I2C_C1_TXAK(x)                           (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< I2C0_C1.TXAK Field                      */
#define I2C_C1_TX_MASK                           (0x10U)                                             /*!< I2C0_C1.TX Mask                         */
#define I2C_C1_TX_SHIFT                          (4U)                                                /*!< I2C0_C1.TX Position                     */
#define I2C_C1_TX(x)                             (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< I2C0_C1.TX Field                        */
#define I2C_C1_MST_MASK                          (0x20U)                                             /*!< I2C0_C1.MST Mask                        */
#define I2C_C1_MST_SHIFT                         (5U)                                                /*!< I2C0_C1.MST Position                    */
#define I2C_C1_MST(x)                            (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< I2C0_C1.MST Field                       */
#define I2C_C1_IICIE_MASK                        (0x40U)                                             /*!< I2C0_C1.IICIE Mask                      */
#define I2C_C1_IICIE_SHIFT                       (6U)                                                /*!< I2C0_C1.IICIE Position                  */
#define I2C_C1_IICIE(x)                          (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< I2C0_C1.IICIE Field                     */
#define I2C_C1_IICEN_MASK                        (0x80U)                                             /*!< I2C0_C1.IICEN Mask                      */
#define I2C_C1_IICEN_SHIFT                       (7U)                                                /*!< I2C0_C1.IICEN Position                  */
#define I2C_C1_IICEN(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< I2C0_C1.IICEN Field                     */
/* ------- S Bit Fields                             ------ */
#define I2C_S_RXAK_MASK                          (0x1U)                                              /*!< I2C0_S.RXAK Mask                        */
#define I2C_S_RXAK_SHIFT                         (0U)                                                /*!< I2C0_S.RXAK Position                    */
#define I2C_S_RXAK(x)                            (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< I2C0_S.RXAK Field                       */
#define I2C_S_IICIF_MASK                         (0x2U)                                              /*!< I2C0_S.IICIF Mask                       */
#define I2C_S_IICIF_SHIFT                        (1U)                                                /*!< I2C0_S.IICIF Position                   */
#define I2C_S_IICIF(x)                           (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< I2C0_S.IICIF Field                      */
#define I2C_S_SRW_MASK                           (0x4U)                                              /*!< I2C0_S.SRW Mask                         */
#define I2C_S_SRW_SHIFT                          (2U)                                                /*!< I2C0_S.SRW Position                     */
#define I2C_S_SRW(x)                             (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< I2C0_S.SRW Field                        */
#define I2C_S_RAM_MASK                           (0x8U)                                              /*!< I2C0_S.RAM Mask                         */
#define I2C_S_RAM_SHIFT                          (3U)                                                /*!< I2C0_S.RAM Position                     */
#define I2C_S_RAM(x)                             (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< I2C0_S.RAM Field                        */
#define I2C_S_ARBL_MASK                          (0x10U)                                             /*!< I2C0_S.ARBL Mask                        */
#define I2C_S_ARBL_SHIFT                         (4U)                                                /*!< I2C0_S.ARBL Position                    */
#define I2C_S_ARBL(x)                            (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< I2C0_S.ARBL Field                       */
#define I2C_S_BUSY_MASK                          (0x20U)                                             /*!< I2C0_S.BUSY Mask                        */
#define I2C_S_BUSY_SHIFT                         (5U)                                                /*!< I2C0_S.BUSY Position                    */
#define I2C_S_BUSY(x)                            (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< I2C0_S.BUSY Field                       */
#define I2C_S_IAAS_MASK                          (0x40U)                                             /*!< I2C0_S.IAAS Mask                        */
#define I2C_S_IAAS_SHIFT                         (6U)                                                /*!< I2C0_S.IAAS Position                    */
#define I2C_S_IAAS(x)                            (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< I2C0_S.IAAS Field                       */
#define I2C_S_TCF_MASK                           (0x80U)                                             /*!< I2C0_S.TCF Mask                         */
#define I2C_S_TCF_SHIFT                          (7U)                                                /*!< I2C0_S.TCF Position                     */
#define I2C_S_TCF(x)                             (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< I2C0_S.TCF Field                        */
/* ------- D Bit Fields                             ------ */
#define I2C_D_DATA_MASK                          (0xFFU)                                             /*!< I2C0_D.DATA Mask                        */
#define I2C_D_DATA_SHIFT                         (0U)                                                /*!< I2C0_D.DATA Position                    */
#define I2C_D_DATA(x)                            (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< I2C0_D.DATA Field                       */
/* ------- C2 Bit Fields                            ------ */
#define I2C_C2_AD_MASK                           (0x7U)                                              /*!< I2C0_C2.AD Mask                         */
#define I2C_C2_AD_SHIFT                          (0U)                                                /*!< I2C0_C2.AD Position                     */
#define I2C_C2_AD(x)                             (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< I2C0_C2.AD Field                        */
#define I2C_C2_RMEN_MASK                         (0x8U)                                              /*!< I2C0_C2.RMEN Mask                       */
#define I2C_C2_RMEN_SHIFT                        (3U)                                                /*!< I2C0_C2.RMEN Position                   */
#define I2C_C2_RMEN(x)                           (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< I2C0_C2.RMEN Field                      */
#define I2C_C2_SBRC_MASK                         (0x10U)                                             /*!< I2C0_C2.SBRC Mask                       */
#define I2C_C2_SBRC_SHIFT                        (4U)                                                /*!< I2C0_C2.SBRC Position                   */
#define I2C_C2_SBRC(x)                           (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< I2C0_C2.SBRC Field                      */
#define I2C_C2_HDRS_MASK                         (0x20U)                                             /*!< I2C0_C2.HDRS Mask                       */
#define I2C_C2_HDRS_SHIFT                        (5U)                                                /*!< I2C0_C2.HDRS Position                   */
#define I2C_C2_HDRS(x)                           (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< I2C0_C2.HDRS Field                      */
#define I2C_C2_ADEXT_MASK                        (0x40U)                                             /*!< I2C0_C2.ADEXT Mask                      */
#define I2C_C2_ADEXT_SHIFT                       (6U)                                                /*!< I2C0_C2.ADEXT Position                  */
#define I2C_C2_ADEXT(x)                          (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< I2C0_C2.ADEXT Field                     */
#define I2C_C2_GCAEN_MASK                        (0x80U)                                             /*!< I2C0_C2.GCAEN Mask                      */
#define I2C_C2_GCAEN_SHIFT                       (7U)                                                /*!< I2C0_C2.GCAEN Position                  */
#define I2C_C2_GCAEN(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< I2C0_C2.GCAEN Field                     */
/* ------- FLT Bit Fields                           ------ */
#define I2C_FLT_FLT_MASK                         (0xFU)                                              /*!< I2C0_FLT.FLT Mask                       */
#define I2C_FLT_FLT_SHIFT                        (0U)                                                /*!< I2C0_FLT.FLT Position                   */
#define I2C_FLT_FLT(x)                           (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< I2C0_FLT.FLT Field                      */
#define I2C_FLT_STARTF_MASK                      (0x10U)                                             /*!< I2C0_FLT.STARTF Mask                    */
#define I2C_FLT_STARTF_SHIFT                     (4U)                                                /*!< I2C0_FLT.STARTF Position                */
#define I2C_FLT_STARTF(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< I2C0_FLT.STARTF Field                   */
#define I2C_FLT_SSIE_MASK                        (0x20U)                                             /*!< I2C0_FLT.SSIE Mask                      */
#define I2C_FLT_SSIE_SHIFT                       (5U)                                                /*!< I2C0_FLT.SSIE Position                  */
#define I2C_FLT_SSIE(x)                          (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< I2C0_FLT.SSIE Field                     */
#define I2C_FLT_STOPF_MASK                       (0x40U)                                             /*!< I2C0_FLT.STOPF Mask                     */
#define I2C_FLT_STOPF_SHIFT                      (6U)                                                /*!< I2C0_FLT.STOPF Position                 */
#define I2C_FLT_STOPF(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< I2C0_FLT.STOPF Field                    */
#define I2C_FLT_SHEN_MASK                        (0x80U)                                             /*!< I2C0_FLT.SHEN Mask                      */
#define I2C_FLT_SHEN_SHIFT                       (7U)                                                /*!< I2C0_FLT.SHEN Position                  */
#define I2C_FLT_SHEN(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< I2C0_FLT.SHEN Field                     */
/* ------- RA Bit Fields                            ------ */
#define I2C_RA_RAD_MASK                          (0xFEU)                                             /*!< I2C0_RA.RAD Mask                        */
#define I2C_RA_RAD_SHIFT                         (1U)                                                /*!< I2C0_RA.RAD Position                    */
#define I2C_RA_RAD(x)                            (((uint8_t)(((uint8_t)(x))<<1U))&0xFEUL)            /*!< I2C0_RA.RAD Field                       */
/* ------- SMB Bit Fields                           ------ */
#define I2C_SMB_SHTF2IE_MASK                     (0x1U)                                              /*!< I2C0_SMB.SHTF2IE Mask                   */
#define I2C_SMB_SHTF2IE_SHIFT                    (0U)                                                /*!< I2C0_SMB.SHTF2IE Position               */
#define I2C_SMB_SHTF2IE(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< I2C0_SMB.SHTF2IE Field                  */
#define I2C_SMB_SHTF2_MASK                       (0x2U)                                              /*!< I2C0_SMB.SHTF2 Mask                     */
#define I2C_SMB_SHTF2_SHIFT                      (1U)                                                /*!< I2C0_SMB.SHTF2 Position                 */
#define I2C_SMB_SHTF2(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< I2C0_SMB.SHTF2 Field                    */
#define I2C_SMB_SHTF1_MASK                       (0x4U)                                              /*!< I2C0_SMB.SHTF1 Mask                     */
#define I2C_SMB_SHTF1_SHIFT                      (2U)                                                /*!< I2C0_SMB.SHTF1 Position                 */
#define I2C_SMB_SHTF1(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< I2C0_SMB.SHTF1 Field                    */
#define I2C_SMB_SLTF_MASK                        (0x8U)                                              /*!< I2C0_SMB.SLTF Mask                      */
#define I2C_SMB_SLTF_SHIFT                       (3U)                                                /*!< I2C0_SMB.SLTF Position                  */
#define I2C_SMB_SLTF(x)                          (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< I2C0_SMB.SLTF Field                     */
#define I2C_SMB_TCKSEL_MASK                      (0x10U)                                             /*!< I2C0_SMB.TCKSEL Mask                    */
#define I2C_SMB_TCKSEL_SHIFT                     (4U)                                                /*!< I2C0_SMB.TCKSEL Position                */
#define I2C_SMB_TCKSEL(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< I2C0_SMB.TCKSEL Field                   */
#define I2C_SMB_SIICAEN_MASK                     (0x20U)                                             /*!< I2C0_SMB.SIICAEN Mask                   */
#define I2C_SMB_SIICAEN_SHIFT                    (5U)                                                /*!< I2C0_SMB.SIICAEN Position               */
#define I2C_SMB_SIICAEN(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< I2C0_SMB.SIICAEN Field                  */
#define I2C_SMB_ALERTEN_MASK                     (0x40U)                                             /*!< I2C0_SMB.ALERTEN Mask                   */
#define I2C_SMB_ALERTEN_SHIFT                    (6U)                                                /*!< I2C0_SMB.ALERTEN Position               */
#define I2C_SMB_ALERTEN(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< I2C0_SMB.ALERTEN Field                  */
#define I2C_SMB_FACK_MASK                        (0x80U)                                             /*!< I2C0_SMB.FACK Mask                      */
#define I2C_SMB_FACK_SHIFT                       (7U)                                                /*!< I2C0_SMB.FACK Position                  */
#define I2C_SMB_FACK(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< I2C0_SMB.FACK Field                     */
/* ------- A2 Bit Fields                            ------ */
#define I2C_A2_SAD_MASK                          (0xFEU)                                             /*!< I2C0_A2.SAD Mask                        */
#define I2C_A2_SAD_SHIFT                         (1U)                                                /*!< I2C0_A2.SAD Position                    */
#define I2C_A2_SAD(x)                            (((uint8_t)(((uint8_t)(x))<<1U))&0xFEUL)            /*!< I2C0_A2.SAD Field                       */
/* ------- SLTH Bit Fields                          ------ */
#define I2C_SLTH_SSLT_MASK                       (0xFFU)                                             /*!< I2C0_SLTH.SSLT Mask                     */
#define I2C_SLTH_SSLT_SHIFT                      (0U)                                                /*!< I2C0_SLTH.SSLT Position                 */
#define I2C_SLTH_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< I2C0_SLTH.SSLT Field                    */
/* ------- SLTL Bit Fields                          ------ */
#define I2C_SLTL_SSLT_MASK                       (0xFFU)                                             /*!< I2C0_SLTL.SSLT Mask                     */
#define I2C_SLTL_SSLT_SHIFT                      (0U)                                                /*!< I2C0_SLTL.SSLT Position                 */
#define I2C_SLTL_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< I2C0_SLTL.SSLT Field                    */
/* ------- S2 Bit Fields                            ------ */
#define I2C_S2_EMPTY_MASK                        (0x1U)                                              /*!< I2C0_S2.EMPTY Mask                      */
#define I2C_S2_EMPTY_SHIFT                       (0U)                                                /*!< I2C0_S2.EMPTY Position                  */
#define I2C_S2_EMPTY(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< I2C0_S2.EMPTY Field                     */
#define I2C_S2_ERROR_MASK                        (0x2U)                                              /*!< I2C0_S2.ERROR Mask                      */
#define I2C_S2_ERROR_SHIFT                       (1U)                                                /*!< I2C0_S2.ERROR Position                  */
#define I2C_S2_ERROR(x)                          (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< I2C0_S2.ERROR Field                     */
#define I2C_S2_DFEN_MASK                         (0x4U)                                              /*!< I2C0_S2.DFEN Mask                       */
#define I2C_S2_DFEN_SHIFT                        (2U)                                                /*!< I2C0_S2.DFEN Position                   */
#define I2C_S2_DFEN(x)                           (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< I2C0_S2.DFEN Field                      */
/**
 * @} */ /* End group I2C_Register_Masks_GROUP 
 */

/* I2C0 - Peripheral instance base addresses */
#define I2C0_BasePtr                   0x40066000UL //!< Peripheral base address
#define I2C0                           ((I2C_Type *) I2C0_BasePtr) //!< Freescale base pointer
#define I2C0_BASE_PTR                  (I2C0) //!< Freescale style base pointer
/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           I2C1 (derived from I2C0)             ================ */
/* ================================================================================ */

/**
 * @brief Inter-Integrated Circuit
 */

/* I2C1 - Peripheral instance base addresses */
#define I2C1_BasePtr                   0x40067000UL //!< Peripheral base address
#define I2C1                           ((I2C_Type *) I2C1_BasePtr) //!< Freescale base pointer
#define I2C1_BASE_PTR                  (I2C1) //!< Freescale style base pointer
/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup INTMUX_Peripheral_access_layer_GROUP INTMUX Peripheral Access Layer
* @brief C Struct for INTMUX
* @{
*/

/* ================================================================================ */
/* ================           INTMUX0 (file:INTMUX0_MKL82Z7)       ================ */
/* ================================================================================ */

/**
 * @brief Interrupt Multiplexer
 */
/**
* @addtogroup INTMUX_structs_GROUP INTMUX struct
* @brief Struct for INTMUX
* @{
*/
typedef struct {                                /*       INTMUX0 Structure                                            */
   struct {
      __IO uint32_t  CSR;                       /**< 0000: Channel n Control Status Register                            */
      __I  uint32_t  VEC;                       /**< 0004: Channel n Vector Number Register                             */
           uint8_t   RESERVED_0[8];            
      __IO uint32_t  IER_31_0;                  /**< 0010: Channel n Interrupt Enable Register                          */
           uint8_t   RESERVED_1[12];           
      __I  uint32_t  IPR_31_0;                  /**< 0020: Channel n Interrupt Pending Register                         */
           uint8_t   RESERVED_2[28];           
   } CHANNEL[4];                                /**< 0000: (cluster: size=0x0100, 256)                                  */
} INTMUX_Type;

/**
 * @} */ /* End group INTMUX_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'INTMUX0' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup INTMUX_Register_Masks_GROUP INTMUX Register Masks
* @brief Register Masks for INTMUX
* @{
*/
/* ------- CSR Bit Fields                           ------ */
#define INTMUX_CSR_RST_MASK                      (0x1U)                                              /*!< INTMUX0_CSR.RST Mask                    */
#define INTMUX_CSR_RST_SHIFT                     (0U)                                                /*!< INTMUX0_CSR.RST Position                */
#define INTMUX_CSR_RST(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< INTMUX0_CSR.RST Field                   */
#define INTMUX_CSR_AND_MASK                      (0x2U)                                              /*!< INTMUX0_CSR.AND Mask                    */
#define INTMUX_CSR_AND_SHIFT                     (1U)                                                /*!< INTMUX0_CSR.AND Position                */
#define INTMUX_CSR_AND(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< INTMUX0_CSR.AND Field                   */
#define INTMUX_CSR_IRQN_MASK                     (0x30U)                                             /*!< INTMUX0_CSR.IRQN Mask                   */
#define INTMUX_CSR_IRQN_SHIFT                    (4U)                                                /*!< INTMUX0_CSR.IRQN Position               */
#define INTMUX_CSR_IRQN(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< INTMUX0_CSR.IRQN Field                  */
#define INTMUX_CSR_CHIN_MASK                     (0xF00U)                                            /*!< INTMUX0_CSR.CHIN Mask                   */
#define INTMUX_CSR_CHIN_SHIFT                    (8U)                                                /*!< INTMUX0_CSR.CHIN Position               */
#define INTMUX_CSR_CHIN(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< INTMUX0_CSR.CHIN Field                  */
#define INTMUX_CSR_IRQP_MASK                     (0x80000000U)                                       /*!< INTMUX0_CSR.IRQP Mask                   */
#define INTMUX_CSR_IRQP_SHIFT                    (31U)                                               /*!< INTMUX0_CSR.IRQP Position               */
#define INTMUX_CSR_IRQP(x)                       (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< INTMUX0_CSR.IRQP Field                  */
/* ------- VEC Bit Fields                           ------ */
#define INTMUX_VEC_VECN_MASK                     (0x3FFCU)                                           /*!< INTMUX0_VEC.VECN Mask                   */
#define INTMUX_VEC_VECN_SHIFT                    (2U)                                                /*!< INTMUX0_VEC.VECN Position               */
#define INTMUX_VEC_VECN(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x3FFCUL)        /*!< INTMUX0_VEC.VECN Field                  */
/* ------- IER_31_0 Bit Fields                      ------ */
#define INTMUX_IER_31_0_INTE_MASK                (0xFFFFFFFFU)                                       /*!< INTMUX0_IER_31_0.INTE Mask              */
#define INTMUX_IER_31_0_INTE_SHIFT               (0U)                                                /*!< INTMUX0_IER_31_0.INTE Position          */
#define INTMUX_IER_31_0_INTE(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< INTMUX0_IER_31_0.INTE Field             */
/* ------- IPR_31_0 Bit Fields                      ------ */
#define INTMUX_IPR_31_0_INTP_MASK                (0xFFFFFFFFU)                                       /*!< INTMUX0_IPR_31_0.INTP Mask              */
#define INTMUX_IPR_31_0_INTP_SHIFT               (0U)                                                /*!< INTMUX0_IPR_31_0.INTP Position          */
#define INTMUX_IPR_31_0_INTP(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< INTMUX0_IPR_31_0.INTP Field             */
/**
 * @} */ /* End group INTMUX_Register_Masks_GROUP 
 */

/* INTMUX0 - Peripheral instance base addresses */
#define INTMUX0_BasePtr                0x40024000UL //!< Peripheral base address
#define INTMUX0                        ((INTMUX_Type *) INTMUX0_BasePtr) //!< Freescale base pointer
#define INTMUX0_BASE_PTR               (INTMUX0) //!< Freescale style base pointer
/**
 * @} */ /* End group INTMUX_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LLWU_Peripheral_access_layer_GROUP LLWU Peripheral Access Layer
* @brief C Struct for LLWU
* @{
*/

/* ================================================================================ */
/* ================           LLWU (file:LLWU_MKL82Z7)             ================ */
/* ================================================================================ */

/**
 * @brief Low leakage wakeup unit
 */
/**
* @addtogroup LLWU_structs_GROUP LLWU struct
* @brief Struct for LLWU
* @{
*/
typedef struct {                                /*       LLWU Structure                                               */
   __IO uint8_t   PE1;                          /**< 0000: LLWU Pin Enable 1 register                                   */
   __IO uint8_t   PE2;                          /**< 0001: LLWU Pin Enable 2 register                                   */
   __IO uint8_t   PE3;                          /**< 0002: LLWU Pin Enable 3 register                                   */
   __IO uint8_t   PE4;                          /**< 0003: LLWU Pin Enable 4 register                                   */
   __IO uint8_t   PE5;                          /**< 0004: LLWU Pin Enable 5 register                                   */
   __IO uint8_t   PE6;                          /**< 0005: LLWU Pin Enable 6 register                                   */
   __IO uint8_t   PE7;                          /**< 0006: LLWU Pin Enable 7 register                                   */
   __IO uint8_t   PE8;                          /**< 0007: LLWU Pin Enable 8 register                                   */
   __IO uint8_t   ME;                           /**< 0008: LLWU Module Enable register                                  */
   __IO uint8_t   PF1;                          /**< 0009: LLWU Pin Flag 1 register                                     */
   __IO uint8_t   PF2;                          /**< 000A: LLWU Pin Flag 2 register                                     */
   __IO uint8_t   PF3;                          /**< 000B: LLWU Pin Flag 3 register                                     */
   __IO uint8_t   PF4;                          /**< 000C: LLWU Pin Flag 4 register                                     */
   __I  uint8_t   MF5;                          /**< 000D: LLWU Module Flag 5 register                                  */
   __IO uint8_t   FILT1;                        /**< 000E: LLWU Pin Filter 1 register                                   */
   __IO uint8_t   FILT2;                        /**< 000F: LLWU Pin Filter 2 register                                   */
   __IO uint8_t   FILT3;                        /**< 0010: LLWU Pin Filter 3 register                                   */
   __IO uint8_t   FILT4;                        /**< 0011: LLWU Pin Filter 4 register                                   */
} LLWU_Type;

/**
 * @} */ /* End group LLWU_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LLWU' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup LLWU_Register_Masks_GROUP LLWU Register Masks
* @brief Register Masks for LLWU
* @{
*/
/* ------- PE1 Bit Fields                           ------ */
#define LLWU_PE1_WUPE0_MASK                      (0x3U)                                              /*!< LLWU_PE1.WUPE0 Mask                     */
#define LLWU_PE1_WUPE0_SHIFT                     (0U)                                                /*!< LLWU_PE1.WUPE0 Position                 */
#define LLWU_PE1_WUPE0(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< LLWU_PE1.WUPE0 Field                    */
#define LLWU_PE1_WUPE1_MASK                      (0xCU)                                              /*!< LLWU_PE1.WUPE1 Mask                     */
#define LLWU_PE1_WUPE1_SHIFT                     (2U)                                                /*!< LLWU_PE1.WUPE1 Position                 */
#define LLWU_PE1_WUPE1(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< LLWU_PE1.WUPE1 Field                    */
#define LLWU_PE1_WUPE2_MASK                      (0x30U)                                             /*!< LLWU_PE1.WUPE2 Mask                     */
#define LLWU_PE1_WUPE2_SHIFT                     (4U)                                                /*!< LLWU_PE1.WUPE2 Position                 */
#define LLWU_PE1_WUPE2(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< LLWU_PE1.WUPE2 Field                    */
#define LLWU_PE1_WUPE3_MASK                      (0xC0U)                                             /*!< LLWU_PE1.WUPE3 Mask                     */
#define LLWU_PE1_WUPE3_SHIFT                     (6U)                                                /*!< LLWU_PE1.WUPE3 Position                 */
#define LLWU_PE1_WUPE3(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< LLWU_PE1.WUPE3 Field                    */
/* ------- PE2 Bit Fields                           ------ */
#define LLWU_PE2_WUPE4_MASK                      (0x3U)                                              /*!< LLWU_PE2.WUPE4 Mask                     */
#define LLWU_PE2_WUPE4_SHIFT                     (0U)                                                /*!< LLWU_PE2.WUPE4 Position                 */
#define LLWU_PE2_WUPE4(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< LLWU_PE2.WUPE4 Field                    */
#define LLWU_PE2_WUPE5_MASK                      (0xCU)                                              /*!< LLWU_PE2.WUPE5 Mask                     */
#define LLWU_PE2_WUPE5_SHIFT                     (2U)                                                /*!< LLWU_PE2.WUPE5 Position                 */
#define LLWU_PE2_WUPE5(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< LLWU_PE2.WUPE5 Field                    */
#define LLWU_PE2_WUPE6_MASK                      (0x30U)                                             /*!< LLWU_PE2.WUPE6 Mask                     */
#define LLWU_PE2_WUPE6_SHIFT                     (4U)                                                /*!< LLWU_PE2.WUPE6 Position                 */
#define LLWU_PE2_WUPE6(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< LLWU_PE2.WUPE6 Field                    */
#define LLWU_PE2_WUPE7_MASK                      (0xC0U)                                             /*!< LLWU_PE2.WUPE7 Mask                     */
#define LLWU_PE2_WUPE7_SHIFT                     (6U)                                                /*!< LLWU_PE2.WUPE7 Position                 */
#define LLWU_PE2_WUPE7(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< LLWU_PE2.WUPE7 Field                    */
/* ------- PE3 Bit Fields                           ------ */
#define LLWU_PE3_WUPE8_MASK                      (0x3U)                                              /*!< LLWU_PE3.WUPE8 Mask                     */
#define LLWU_PE3_WUPE8_SHIFT                     (0U)                                                /*!< LLWU_PE3.WUPE8 Position                 */
#define LLWU_PE3_WUPE8(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< LLWU_PE3.WUPE8 Field                    */
#define LLWU_PE3_WUPE9_MASK                      (0xCU)                                              /*!< LLWU_PE3.WUPE9 Mask                     */
#define LLWU_PE3_WUPE9_SHIFT                     (2U)                                                /*!< LLWU_PE3.WUPE9 Position                 */
#define LLWU_PE3_WUPE9(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< LLWU_PE3.WUPE9 Field                    */
#define LLWU_PE3_WUPE10_MASK                     (0x30U)                                             /*!< LLWU_PE3.WUPE10 Mask                    */
#define LLWU_PE3_WUPE10_SHIFT                    (4U)                                                /*!< LLWU_PE3.WUPE10 Position                */
#define LLWU_PE3_WUPE10(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< LLWU_PE3.WUPE10 Field                   */
#define LLWU_PE3_WUPE11_MASK                     (0xC0U)                                             /*!< LLWU_PE3.WUPE11 Mask                    */
#define LLWU_PE3_WUPE11_SHIFT                    (6U)                                                /*!< LLWU_PE3.WUPE11 Position                */
#define LLWU_PE3_WUPE11(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< LLWU_PE3.WUPE11 Field                   */
/* ------- PE4 Bit Fields                           ------ */
#define LLWU_PE4_WUPE12_MASK                     (0x3U)                                              /*!< LLWU_PE4.WUPE12 Mask                    */
#define LLWU_PE4_WUPE12_SHIFT                    (0U)                                                /*!< LLWU_PE4.WUPE12 Position                */
#define LLWU_PE4_WUPE12(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< LLWU_PE4.WUPE12 Field                   */
#define LLWU_PE4_WUPE13_MASK                     (0xCU)                                              /*!< LLWU_PE4.WUPE13 Mask                    */
#define LLWU_PE4_WUPE13_SHIFT                    (2U)                                                /*!< LLWU_PE4.WUPE13 Position                */
#define LLWU_PE4_WUPE13(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< LLWU_PE4.WUPE13 Field                   */
#define LLWU_PE4_WUPE14_MASK                     (0x30U)                                             /*!< LLWU_PE4.WUPE14 Mask                    */
#define LLWU_PE4_WUPE14_SHIFT                    (4U)                                                /*!< LLWU_PE4.WUPE14 Position                */
#define LLWU_PE4_WUPE14(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< LLWU_PE4.WUPE14 Field                   */
#define LLWU_PE4_WUPE15_MASK                     (0xC0U)                                             /*!< LLWU_PE4.WUPE15 Mask                    */
#define LLWU_PE4_WUPE15_SHIFT                    (6U)                                                /*!< LLWU_PE4.WUPE15 Position                */
#define LLWU_PE4_WUPE15(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< LLWU_PE4.WUPE15 Field                   */
/* ------- PE5 Bit Fields                           ------ */
#define LLWU_PE5_WUPE16_MASK                     (0x3U)                                              /*!< LLWU_PE5.WUPE16 Mask                    */
#define LLWU_PE5_WUPE16_SHIFT                    (0U)                                                /*!< LLWU_PE5.WUPE16 Position                */
#define LLWU_PE5_WUPE16(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< LLWU_PE5.WUPE16 Field                   */
#define LLWU_PE5_WUPE17_MASK                     (0xCU)                                              /*!< LLWU_PE5.WUPE17 Mask                    */
#define LLWU_PE5_WUPE17_SHIFT                    (2U)                                                /*!< LLWU_PE5.WUPE17 Position                */
#define LLWU_PE5_WUPE17(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< LLWU_PE5.WUPE17 Field                   */
#define LLWU_PE5_WUPE18_MASK                     (0x30U)                                             /*!< LLWU_PE5.WUPE18 Mask                    */
#define LLWU_PE5_WUPE18_SHIFT                    (4U)                                                /*!< LLWU_PE5.WUPE18 Position                */
#define LLWU_PE5_WUPE18(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< LLWU_PE5.WUPE18 Field                   */
#define LLWU_PE5_WUPE19_MASK                     (0xC0U)                                             /*!< LLWU_PE5.WUPE19 Mask                    */
#define LLWU_PE5_WUPE19_SHIFT                    (6U)                                                /*!< LLWU_PE5.WUPE19 Position                */
#define LLWU_PE5_WUPE19(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< LLWU_PE5.WUPE19 Field                   */
/* ------- PE6 Bit Fields                           ------ */
#define LLWU_PE6_WUPE20_MASK                     (0x3U)                                              /*!< LLWU_PE6.WUPE20 Mask                    */
#define LLWU_PE6_WUPE20_SHIFT                    (0U)                                                /*!< LLWU_PE6.WUPE20 Position                */
#define LLWU_PE6_WUPE20(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< LLWU_PE6.WUPE20 Field                   */
#define LLWU_PE6_WUPE21_MASK                     (0xCU)                                              /*!< LLWU_PE6.WUPE21 Mask                    */
#define LLWU_PE6_WUPE21_SHIFT                    (2U)                                                /*!< LLWU_PE6.WUPE21 Position                */
#define LLWU_PE6_WUPE21(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< LLWU_PE6.WUPE21 Field                   */
#define LLWU_PE6_WUPE22_MASK                     (0x30U)                                             /*!< LLWU_PE6.WUPE22 Mask                    */
#define LLWU_PE6_WUPE22_SHIFT                    (4U)                                                /*!< LLWU_PE6.WUPE22 Position                */
#define LLWU_PE6_WUPE22(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< LLWU_PE6.WUPE22 Field                   */
#define LLWU_PE6_WUPE23_MASK                     (0xC0U)                                             /*!< LLWU_PE6.WUPE23 Mask                    */
#define LLWU_PE6_WUPE23_SHIFT                    (6U)                                                /*!< LLWU_PE6.WUPE23 Position                */
#define LLWU_PE6_WUPE23(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< LLWU_PE6.WUPE23 Field                   */
/* ------- PE7 Bit Fields                           ------ */
#define LLWU_PE7_WUPE24_MASK                     (0x3U)                                              /*!< LLWU_PE7.WUPE24 Mask                    */
#define LLWU_PE7_WUPE24_SHIFT                    (0U)                                                /*!< LLWU_PE7.WUPE24 Position                */
#define LLWU_PE7_WUPE24(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< LLWU_PE7.WUPE24 Field                   */
#define LLWU_PE7_WUPE25_MASK                     (0xCU)                                              /*!< LLWU_PE7.WUPE25 Mask                    */
#define LLWU_PE7_WUPE25_SHIFT                    (2U)                                                /*!< LLWU_PE7.WUPE25 Position                */
#define LLWU_PE7_WUPE25(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< LLWU_PE7.WUPE25 Field                   */
#define LLWU_PE7_WUPE26_MASK                     (0x30U)                                             /*!< LLWU_PE7.WUPE26 Mask                    */
#define LLWU_PE7_WUPE26_SHIFT                    (4U)                                                /*!< LLWU_PE7.WUPE26 Position                */
#define LLWU_PE7_WUPE26(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< LLWU_PE7.WUPE26 Field                   */
#define LLWU_PE7_WUPE27_MASK                     (0xC0U)                                             /*!< LLWU_PE7.WUPE27 Mask                    */
#define LLWU_PE7_WUPE27_SHIFT                    (6U)                                                /*!< LLWU_PE7.WUPE27 Position                */
#define LLWU_PE7_WUPE27(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< LLWU_PE7.WUPE27 Field                   */
/* ------- PE8 Bit Fields                           ------ */
#define LLWU_PE8_WUPE28_MASK                     (0x3U)                                              /*!< LLWU_PE8.WUPE28 Mask                    */
#define LLWU_PE8_WUPE28_SHIFT                    (0U)                                                /*!< LLWU_PE8.WUPE28 Position                */
#define LLWU_PE8_WUPE28(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< LLWU_PE8.WUPE28 Field                   */
#define LLWU_PE8_WUPE29_MASK                     (0xCU)                                              /*!< LLWU_PE8.WUPE29 Mask                    */
#define LLWU_PE8_WUPE29_SHIFT                    (2U)                                                /*!< LLWU_PE8.WUPE29 Position                */
#define LLWU_PE8_WUPE29(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< LLWU_PE8.WUPE29 Field                   */
#define LLWU_PE8_WUPE30_MASK                     (0x30U)                                             /*!< LLWU_PE8.WUPE30 Mask                    */
#define LLWU_PE8_WUPE30_SHIFT                    (4U)                                                /*!< LLWU_PE8.WUPE30 Position                */
#define LLWU_PE8_WUPE30(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< LLWU_PE8.WUPE30 Field                   */
#define LLWU_PE8_WUPE31_MASK                     (0xC0U)                                             /*!< LLWU_PE8.WUPE31 Mask                    */
#define LLWU_PE8_WUPE31_SHIFT                    (6U)                                                /*!< LLWU_PE8.WUPE31 Position                */
#define LLWU_PE8_WUPE31(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< LLWU_PE8.WUPE31 Field                   */
/* ------- ME Bit Fields                            ------ */
#define LLWU_ME_WUME0_MASK                       (0x1U)                                              /*!< LLWU_ME.WUME0 Mask                      */
#define LLWU_ME_WUME0_SHIFT                      (0U)                                                /*!< LLWU_ME.WUME0 Position                  */
#define LLWU_ME_WUME0(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< LLWU_ME.WUME0 Field                     */
#define LLWU_ME_WUME1_MASK                       (0x2U)                                              /*!< LLWU_ME.WUME1 Mask                      */
#define LLWU_ME_WUME1_SHIFT                      (1U)                                                /*!< LLWU_ME.WUME1 Position                  */
#define LLWU_ME_WUME1(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< LLWU_ME.WUME1 Field                     */
#define LLWU_ME_WUME2_MASK                       (0x4U)                                              /*!< LLWU_ME.WUME2 Mask                      */
#define LLWU_ME_WUME2_SHIFT                      (2U)                                                /*!< LLWU_ME.WUME2 Position                  */
#define LLWU_ME_WUME2(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< LLWU_ME.WUME2 Field                     */
#define LLWU_ME_WUME3_MASK                       (0x8U)                                              /*!< LLWU_ME.WUME3 Mask                      */
#define LLWU_ME_WUME3_SHIFT                      (3U)                                                /*!< LLWU_ME.WUME3 Position                  */
#define LLWU_ME_WUME3(x)                         (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< LLWU_ME.WUME3 Field                     */
#define LLWU_ME_WUME4_MASK                       (0x10U)                                             /*!< LLWU_ME.WUME4 Mask                      */
#define LLWU_ME_WUME4_SHIFT                      (4U)                                                /*!< LLWU_ME.WUME4 Position                  */
#define LLWU_ME_WUME4(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< LLWU_ME.WUME4 Field                     */
#define LLWU_ME_WUME5_MASK                       (0x20U)                                             /*!< LLWU_ME.WUME5 Mask                      */
#define LLWU_ME_WUME5_SHIFT                      (5U)                                                /*!< LLWU_ME.WUME5 Position                  */
#define LLWU_ME_WUME5(x)                         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< LLWU_ME.WUME5 Field                     */
#define LLWU_ME_WUME6_MASK                       (0x40U)                                             /*!< LLWU_ME.WUME6 Mask                      */
#define LLWU_ME_WUME6_SHIFT                      (6U)                                                /*!< LLWU_ME.WUME6 Position                  */
#define LLWU_ME_WUME6(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< LLWU_ME.WUME6 Field                     */
#define LLWU_ME_WUME7_MASK                       (0x80U)                                             /*!< LLWU_ME.WUME7 Mask                      */
#define LLWU_ME_WUME7_SHIFT                      (7U)                                                /*!< LLWU_ME.WUME7 Position                  */
#define LLWU_ME_WUME7(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< LLWU_ME.WUME7 Field                     */
/* ------- PF1 Bit Fields                           ------ */
#define LLWU_PF1_WUF0_MASK                       (0x1U)                                              /*!< LLWU_PF1.WUF0 Mask                      */
#define LLWU_PF1_WUF0_SHIFT                      (0U)                                                /*!< LLWU_PF1.WUF0 Position                  */
#define LLWU_PF1_WUF0(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< LLWU_PF1.WUF0 Field                     */
#define LLWU_PF1_WUF1_MASK                       (0x2U)                                              /*!< LLWU_PF1.WUF1 Mask                      */
#define LLWU_PF1_WUF1_SHIFT                      (1U)                                                /*!< LLWU_PF1.WUF1 Position                  */
#define LLWU_PF1_WUF1(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< LLWU_PF1.WUF1 Field                     */
#define LLWU_PF1_WUF2_MASK                       (0x4U)                                              /*!< LLWU_PF1.WUF2 Mask                      */
#define LLWU_PF1_WUF2_SHIFT                      (2U)                                                /*!< LLWU_PF1.WUF2 Position                  */
#define LLWU_PF1_WUF2(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< LLWU_PF1.WUF2 Field                     */
#define LLWU_PF1_WUF3_MASK                       (0x8U)                                              /*!< LLWU_PF1.WUF3 Mask                      */
#define LLWU_PF1_WUF3_SHIFT                      (3U)                                                /*!< LLWU_PF1.WUF3 Position                  */
#define LLWU_PF1_WUF3(x)                         (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< LLWU_PF1.WUF3 Field                     */
#define LLWU_PF1_WUF4_MASK                       (0x10U)                                             /*!< LLWU_PF1.WUF4 Mask                      */
#define LLWU_PF1_WUF4_SHIFT                      (4U)                                                /*!< LLWU_PF1.WUF4 Position                  */
#define LLWU_PF1_WUF4(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< LLWU_PF1.WUF4 Field                     */
#define LLWU_PF1_WUF5_MASK                       (0x20U)                                             /*!< LLWU_PF1.WUF5 Mask                      */
#define LLWU_PF1_WUF5_SHIFT                      (5U)                                                /*!< LLWU_PF1.WUF5 Position                  */
#define LLWU_PF1_WUF5(x)                         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< LLWU_PF1.WUF5 Field                     */
#define LLWU_PF1_WUF6_MASK                       (0x40U)                                             /*!< LLWU_PF1.WUF6 Mask                      */
#define LLWU_PF1_WUF6_SHIFT                      (6U)                                                /*!< LLWU_PF1.WUF6 Position                  */
#define LLWU_PF1_WUF6(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< LLWU_PF1.WUF6 Field                     */
#define LLWU_PF1_WUF7_MASK                       (0x80U)                                             /*!< LLWU_PF1.WUF7 Mask                      */
#define LLWU_PF1_WUF7_SHIFT                      (7U)                                                /*!< LLWU_PF1.WUF7 Position                  */
#define LLWU_PF1_WUF7(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< LLWU_PF1.WUF7 Field                     */
/* ------- PF2 Bit Fields                           ------ */
#define LLWU_PF2_WUF8_MASK                       (0x1U)                                              /*!< LLWU_PF2.WUF8 Mask                      */
#define LLWU_PF2_WUF8_SHIFT                      (0U)                                                /*!< LLWU_PF2.WUF8 Position                  */
#define LLWU_PF2_WUF8(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< LLWU_PF2.WUF8 Field                     */
#define LLWU_PF2_WUF9_MASK                       (0x2U)                                              /*!< LLWU_PF2.WUF9 Mask                      */
#define LLWU_PF2_WUF9_SHIFT                      (1U)                                                /*!< LLWU_PF2.WUF9 Position                  */
#define LLWU_PF2_WUF9(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< LLWU_PF2.WUF9 Field                     */
#define LLWU_PF2_WUF10_MASK                      (0x4U)                                              /*!< LLWU_PF2.WUF10 Mask                     */
#define LLWU_PF2_WUF10_SHIFT                     (2U)                                                /*!< LLWU_PF2.WUF10 Position                 */
#define LLWU_PF2_WUF10(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< LLWU_PF2.WUF10 Field                    */
#define LLWU_PF2_WUF11_MASK                      (0x8U)                                              /*!< LLWU_PF2.WUF11 Mask                     */
#define LLWU_PF2_WUF11_SHIFT                     (3U)                                                /*!< LLWU_PF2.WUF11 Position                 */
#define LLWU_PF2_WUF11(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< LLWU_PF2.WUF11 Field                    */
#define LLWU_PF2_WUF12_MASK                      (0x10U)                                             /*!< LLWU_PF2.WUF12 Mask                     */
#define LLWU_PF2_WUF12_SHIFT                     (4U)                                                /*!< LLWU_PF2.WUF12 Position                 */
#define LLWU_PF2_WUF12(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< LLWU_PF2.WUF12 Field                    */
#define LLWU_PF2_WUF13_MASK                      (0x20U)                                             /*!< LLWU_PF2.WUF13 Mask                     */
#define LLWU_PF2_WUF13_SHIFT                     (5U)                                                /*!< LLWU_PF2.WUF13 Position                 */
#define LLWU_PF2_WUF13(x)                        (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< LLWU_PF2.WUF13 Field                    */
#define LLWU_PF2_WUF14_MASK                      (0x40U)                                             /*!< LLWU_PF2.WUF14 Mask                     */
#define LLWU_PF2_WUF14_SHIFT                     (6U)                                                /*!< LLWU_PF2.WUF14 Position                 */
#define LLWU_PF2_WUF14(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< LLWU_PF2.WUF14 Field                    */
#define LLWU_PF2_WUF15_MASK                      (0x80U)                                             /*!< LLWU_PF2.WUF15 Mask                     */
#define LLWU_PF2_WUF15_SHIFT                     (7U)                                                /*!< LLWU_PF2.WUF15 Position                 */
#define LLWU_PF2_WUF15(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< LLWU_PF2.WUF15 Field                    */
/* ------- PF3 Bit Fields                           ------ */
#define LLWU_PF3_WUF16_MASK                      (0x1U)                                              /*!< LLWU_PF3.WUF16 Mask                     */
#define LLWU_PF3_WUF16_SHIFT                     (0U)                                                /*!< LLWU_PF3.WUF16 Position                 */
#define LLWU_PF3_WUF16(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< LLWU_PF3.WUF16 Field                    */
#define LLWU_PF3_WUF17_MASK                      (0x2U)                                              /*!< LLWU_PF3.WUF17 Mask                     */
#define LLWU_PF3_WUF17_SHIFT                     (1U)                                                /*!< LLWU_PF3.WUF17 Position                 */
#define LLWU_PF3_WUF17(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< LLWU_PF3.WUF17 Field                    */
#define LLWU_PF3_WUF18_MASK                      (0x4U)                                              /*!< LLWU_PF3.WUF18 Mask                     */
#define LLWU_PF3_WUF18_SHIFT                     (2U)                                                /*!< LLWU_PF3.WUF18 Position                 */
#define LLWU_PF3_WUF18(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< LLWU_PF3.WUF18 Field                    */
#define LLWU_PF3_WUF19_MASK                      (0x8U)                                              /*!< LLWU_PF3.WUF19 Mask                     */
#define LLWU_PF3_WUF19_SHIFT                     (3U)                                                /*!< LLWU_PF3.WUF19 Position                 */
#define LLWU_PF3_WUF19(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< LLWU_PF3.WUF19 Field                    */
#define LLWU_PF3_WUF20_MASK                      (0x10U)                                             /*!< LLWU_PF3.WUF20 Mask                     */
#define LLWU_PF3_WUF20_SHIFT                     (4U)                                                /*!< LLWU_PF3.WUF20 Position                 */
#define LLWU_PF3_WUF20(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< LLWU_PF3.WUF20 Field                    */
#define LLWU_PF3_WUF21_MASK                      (0x20U)                                             /*!< LLWU_PF3.WUF21 Mask                     */
#define LLWU_PF3_WUF21_SHIFT                     (5U)                                                /*!< LLWU_PF3.WUF21 Position                 */
#define LLWU_PF3_WUF21(x)                        (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< LLWU_PF3.WUF21 Field                    */
#define LLWU_PF3_WUF22_MASK                      (0x40U)                                             /*!< LLWU_PF3.WUF22 Mask                     */
#define LLWU_PF3_WUF22_SHIFT                     (6U)                                                /*!< LLWU_PF3.WUF22 Position                 */
#define LLWU_PF3_WUF22(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< LLWU_PF3.WUF22 Field                    */
#define LLWU_PF3_WUF23_MASK                      (0x80U)                                             /*!< LLWU_PF3.WUF23 Mask                     */
#define LLWU_PF3_WUF23_SHIFT                     (7U)                                                /*!< LLWU_PF3.WUF23 Position                 */
#define LLWU_PF3_WUF23(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< LLWU_PF3.WUF23 Field                    */
/* ------- PF4 Bit Fields                           ------ */
#define LLWU_PF4_WUF24_MASK                      (0x1U)                                              /*!< LLWU_PF4.WUF24 Mask                     */
#define LLWU_PF4_WUF24_SHIFT                     (0U)                                                /*!< LLWU_PF4.WUF24 Position                 */
#define LLWU_PF4_WUF24(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< LLWU_PF4.WUF24 Field                    */
#define LLWU_PF4_WUF25_MASK                      (0x2U)                                              /*!< LLWU_PF4.WUF25 Mask                     */
#define LLWU_PF4_WUF25_SHIFT                     (1U)                                                /*!< LLWU_PF4.WUF25 Position                 */
#define LLWU_PF4_WUF25(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< LLWU_PF4.WUF25 Field                    */
#define LLWU_PF4_WUF26_MASK                      (0x4U)                                              /*!< LLWU_PF4.WUF26 Mask                     */
#define LLWU_PF4_WUF26_SHIFT                     (2U)                                                /*!< LLWU_PF4.WUF26 Position                 */
#define LLWU_PF4_WUF26(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< LLWU_PF4.WUF26 Field                    */
#define LLWU_PF4_WUF27_MASK                      (0x8U)                                              /*!< LLWU_PF4.WUF27 Mask                     */
#define LLWU_PF4_WUF27_SHIFT                     (3U)                                                /*!< LLWU_PF4.WUF27 Position                 */
#define LLWU_PF4_WUF27(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< LLWU_PF4.WUF27 Field                    */
#define LLWU_PF4_WUF28_MASK                      (0x10U)                                             /*!< LLWU_PF4.WUF28 Mask                     */
#define LLWU_PF4_WUF28_SHIFT                     (4U)                                                /*!< LLWU_PF4.WUF28 Position                 */
#define LLWU_PF4_WUF28(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< LLWU_PF4.WUF28 Field                    */
#define LLWU_PF4_WUF29_MASK                      (0x20U)                                             /*!< LLWU_PF4.WUF29 Mask                     */
#define LLWU_PF4_WUF29_SHIFT                     (5U)                                                /*!< LLWU_PF4.WUF29 Position                 */
#define LLWU_PF4_WUF29(x)                        (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< LLWU_PF4.WUF29 Field                    */
#define LLWU_PF4_WUF30_MASK                      (0x40U)                                             /*!< LLWU_PF4.WUF30 Mask                     */
#define LLWU_PF4_WUF30_SHIFT                     (6U)                                                /*!< LLWU_PF4.WUF30 Position                 */
#define LLWU_PF4_WUF30(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< LLWU_PF4.WUF30 Field                    */
#define LLWU_PF4_WUF31_MASK                      (0x80U)                                             /*!< LLWU_PF4.WUF31 Mask                     */
#define LLWU_PF4_WUF31_SHIFT                     (7U)                                                /*!< LLWU_PF4.WUF31 Position                 */
#define LLWU_PF4_WUF31(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< LLWU_PF4.WUF31 Field                    */
/* ------- MF5 Bit Fields                           ------ */
#define LLWU_MF5_MWUF0_MASK                      (0x1U)                                              /*!< LLWU_MF5.MWUF0 Mask                     */
#define LLWU_MF5_MWUF0_SHIFT                     (0U)                                                /*!< LLWU_MF5.MWUF0 Position                 */
#define LLWU_MF5_MWUF0(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< LLWU_MF5.MWUF0 Field                    */
#define LLWU_MF5_MWUF1_MASK                      (0x2U)                                              /*!< LLWU_MF5.MWUF1 Mask                     */
#define LLWU_MF5_MWUF1_SHIFT                     (1U)                                                /*!< LLWU_MF5.MWUF1 Position                 */
#define LLWU_MF5_MWUF1(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< LLWU_MF5.MWUF1 Field                    */
#define LLWU_MF5_MWUF2_MASK                      (0x4U)                                              /*!< LLWU_MF5.MWUF2 Mask                     */
#define LLWU_MF5_MWUF2_SHIFT                     (2U)                                                /*!< LLWU_MF5.MWUF2 Position                 */
#define LLWU_MF5_MWUF2(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< LLWU_MF5.MWUF2 Field                    */
#define LLWU_MF5_MWUF3_MASK                      (0x8U)                                              /*!< LLWU_MF5.MWUF3 Mask                     */
#define LLWU_MF5_MWUF3_SHIFT                     (3U)                                                /*!< LLWU_MF5.MWUF3 Position                 */
#define LLWU_MF5_MWUF3(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< LLWU_MF5.MWUF3 Field                    */
#define LLWU_MF5_MWUF4_MASK                      (0x10U)                                             /*!< LLWU_MF5.MWUF4 Mask                     */
#define LLWU_MF5_MWUF4_SHIFT                     (4U)                                                /*!< LLWU_MF5.MWUF4 Position                 */
#define LLWU_MF5_MWUF4(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< LLWU_MF5.MWUF4 Field                    */
#define LLWU_MF5_MWUF5_MASK                      (0x20U)                                             /*!< LLWU_MF5.MWUF5 Mask                     */
#define LLWU_MF5_MWUF5_SHIFT                     (5U)                                                /*!< LLWU_MF5.MWUF5 Position                 */
#define LLWU_MF5_MWUF5(x)                        (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< LLWU_MF5.MWUF5 Field                    */
#define LLWU_MF5_MWUF6_MASK                      (0x40U)                                             /*!< LLWU_MF5.MWUF6 Mask                     */
#define LLWU_MF5_MWUF6_SHIFT                     (6U)                                                /*!< LLWU_MF5.MWUF6 Position                 */
#define LLWU_MF5_MWUF6(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< LLWU_MF5.MWUF6 Field                    */
#define LLWU_MF5_MWUF7_MASK                      (0x80U)                                             /*!< LLWU_MF5.MWUF7 Mask                     */
#define LLWU_MF5_MWUF7_SHIFT                     (7U)                                                /*!< LLWU_MF5.MWUF7 Position                 */
#define LLWU_MF5_MWUF7(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< LLWU_MF5.MWUF7 Field                    */
/* ------- FILT Bit Fields                          ------ */
#define LLWU_FILT_FILTSEL_MASK                   (0x1FU)                                             /*!< LLWU_FILT.FILTSEL Mask                  */
#define LLWU_FILT_FILTSEL_SHIFT                  (0U)                                                /*!< LLWU_FILT.FILTSEL Position              */
#define LLWU_FILT_FILTSEL(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0x1FUL)            /*!< LLWU_FILT.FILTSEL Field                 */
#define LLWU_FILT_FILTE_MASK                     (0x60U)                                             /*!< LLWU_FILT.FILTE Mask                    */
#define LLWU_FILT_FILTE_SHIFT                    (5U)                                                /*!< LLWU_FILT.FILTE Position                */
#define LLWU_FILT_FILTE(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x60UL)            /*!< LLWU_FILT.FILTE Field                   */
#define LLWU_FILT_FILTF_MASK                     (0x80U)                                             /*!< LLWU_FILT.FILTF Mask                    */
#define LLWU_FILT_FILTF_SHIFT                    (7U)                                                /*!< LLWU_FILT.FILTF Position                */
#define LLWU_FILT_FILTF(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< LLWU_FILT.FILTF Field                   */
/**
 * @} */ /* End group LLWU_Register_Masks_GROUP 
 */

/* LLWU - Peripheral instance base addresses */
#define LLWU_BasePtr                   0x4007C000UL //!< Peripheral base address
#define LLWU                           ((LLWU_Type *) LLWU_BasePtr) //!< Freescale base pointer
#define LLWU_BASE_PTR                  (LLWU) //!< Freescale style base pointer
/**
 * @} */ /* End group LLWU_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LPTMR_Peripheral_access_layer_GROUP LPTMR Peripheral Access Layer
* @brief C Struct for LPTMR
* @{
*/

/* ================================================================================ */
/* ================           LPTMR0 (file:LPTMR0_MKL82Z7)         ================ */
/* ================================================================================ */

/**
 * @brief Low Power Timer
 */
/**
* @addtogroup LPTMR_structs_GROUP LPTMR struct
* @brief Struct for LPTMR
* @{
*/
typedef struct {                                /*       LPTMR0 Structure                                             */
   __IO uint32_t  CSR;                          /**< 0000: Low Power Timer Control Status Register                      */
   __IO uint32_t  PSR;                          /**< 0004: Low Power Timer Prescale Register                            */
   __IO uint32_t  CMR;                          /**< 0008: Low Power Timer Compare Register                             */
   __IO uint32_t  CNR;                          /**< 000C: Low Power Timer Counter Register                             */
} LPTMR_Type;

/**
 * @} */ /* End group LPTMR_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPTMR0' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup LPTMR_Register_Masks_GROUP LPTMR Register Masks
* @brief Register Masks for LPTMR
* @{
*/
/* ------- CSR Bit Fields                           ------ */
#define LPTMR_CSR_TEN_MASK                       (0x1U)                                              /*!< LPTMR0_CSR.TEN Mask                     */
#define LPTMR_CSR_TEN_SHIFT                      (0U)                                                /*!< LPTMR0_CSR.TEN Position                 */
#define LPTMR_CSR_TEN(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPTMR0_CSR.TEN Field                    */
#define LPTMR_CSR_TMS_MASK                       (0x2U)                                              /*!< LPTMR0_CSR.TMS Mask                     */
#define LPTMR_CSR_TMS_SHIFT                      (1U)                                                /*!< LPTMR0_CSR.TMS Position                 */
#define LPTMR_CSR_TMS(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPTMR0_CSR.TMS Field                    */
#define LPTMR_CSR_TFC_MASK                       (0x4U)                                              /*!< LPTMR0_CSR.TFC Mask                     */
#define LPTMR_CSR_TFC_SHIFT                      (2U)                                                /*!< LPTMR0_CSR.TFC Position                 */
#define LPTMR_CSR_TFC(x)                         (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPTMR0_CSR.TFC Field                    */
#define LPTMR_CSR_TPP_MASK                       (0x8U)                                              /*!< LPTMR0_CSR.TPP Mask                     */
#define LPTMR_CSR_TPP_SHIFT                      (3U)                                                /*!< LPTMR0_CSR.TPP Position                 */
#define LPTMR_CSR_TPP(x)                         (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPTMR0_CSR.TPP Field                    */
#define LPTMR_CSR_TPS_MASK                       (0x30U)                                             /*!< LPTMR0_CSR.TPS Mask                     */
#define LPTMR_CSR_TPS_SHIFT                      (4U)                                                /*!< LPTMR0_CSR.TPS Position                 */
#define LPTMR_CSR_TPS(x)                         (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< LPTMR0_CSR.TPS Field                    */
#define LPTMR_CSR_TIE_MASK                       (0x40U)                                             /*!< LPTMR0_CSR.TIE Mask                     */
#define LPTMR_CSR_TIE_SHIFT                      (6U)                                                /*!< LPTMR0_CSR.TIE Position                 */
#define LPTMR_CSR_TIE(x)                         (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPTMR0_CSR.TIE Field                    */
#define LPTMR_CSR_TCF_MASK                       (0x80U)                                             /*!< LPTMR0_CSR.TCF Mask                     */
#define LPTMR_CSR_TCF_SHIFT                      (7U)                                                /*!< LPTMR0_CSR.TCF Position                 */
#define LPTMR_CSR_TCF(x)                         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPTMR0_CSR.TCF Field                    */
/* ------- PSR Bit Fields                           ------ */
#define LPTMR_PSR_PCS_MASK                       (0x3U)                                              /*!< LPTMR0_PSR.PCS Mask                     */
#define LPTMR_PSR_PCS_SHIFT                      (0U)                                                /*!< LPTMR0_PSR.PCS Position                 */
#define LPTMR_PSR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< LPTMR0_PSR.PCS Field                    */
#define LPTMR_PSR_PBYP_MASK                      (0x4U)                                              /*!< LPTMR0_PSR.PBYP Mask                    */
#define LPTMR_PSR_PBYP_SHIFT                     (2U)                                                /*!< LPTMR0_PSR.PBYP Position                */
#define LPTMR_PSR_PBYP(x)                        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPTMR0_PSR.PBYP Field                   */
#define LPTMR_PSR_PRESCALE_MASK                  (0x78U)                                             /*!< LPTMR0_PSR.PRESCALE Mask                */
#define LPTMR_PSR_PRESCALE_SHIFT                 (3U)                                                /*!< LPTMR0_PSR.PRESCALE Position            */
#define LPTMR_PSR_PRESCALE(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x78UL)          /*!< LPTMR0_PSR.PRESCALE Field               */
/* ------- CMR Bit Fields                           ------ */
#define LPTMR_CMR_COMPARE_MASK                   (0xFFFFU)                                           /*!< LPTMR0_CMR.COMPARE Mask                 */
#define LPTMR_CMR_COMPARE_SHIFT                  (0U)                                                /*!< LPTMR0_CMR.COMPARE Position             */
#define LPTMR_CMR_COMPARE(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< LPTMR0_CMR.COMPARE Field                */
/* ------- CNR Bit Fields                           ------ */
#define LPTMR_CNR_COUNTER_MASK                   (0xFFFFU)                                           /*!< LPTMR0_CNR.COUNTER Mask                 */
#define LPTMR_CNR_COUNTER_SHIFT                  (0U)                                                /*!< LPTMR0_CNR.COUNTER Position             */
#define LPTMR_CNR_COUNTER(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< LPTMR0_CNR.COUNTER Field                */
/**
 * @} */ /* End group LPTMR_Register_Masks_GROUP 
 */

/* LPTMR0 - Peripheral instance base addresses */
#define LPTMR0_BasePtr                 0x40040000UL //!< Peripheral base address
#define LPTMR0                         ((LPTMR_Type *) LPTMR0_BasePtr) //!< Freescale base pointer
#define LPTMR0_BASE_PTR                (LPTMR0) //!< Freescale style base pointer
/**
 * @} */ /* End group LPTMR_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LPTMR_Peripheral_access_layer_GROUP LPTMR Peripheral Access Layer
* @brief C Struct for LPTMR
* @{
*/

/* ================================================================================ */
/* ================           LPTMR1 (derived from LPTMR0)         ================ */
/* ================================================================================ */

/**
 * @brief Low Power Timer
 */

/* LPTMR1 - Peripheral instance base addresses */
#define LPTMR1_BasePtr                 0x40044000UL //!< Peripheral base address
#define LPTMR1                         ((LPTMR_Type *) LPTMR1_BasePtr) //!< Freescale base pointer
#define LPTMR1_BASE_PTR                (LPTMR1) //!< Freescale style base pointer
/**
 * @} */ /* End group LPTMR_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LPUART_Peripheral_access_layer_GROUP LPUART Peripheral Access Layer
* @brief C Struct for LPUART
* @{
*/

/* ================================================================================ */
/* ================           LPUART0 (file:LPUART0_MKL82Z7)       ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */
/**
* @addtogroup LPUART_structs_GROUP LPUART struct
* @brief Struct for LPUART
* @{
*/
typedef struct {                                /*       LPUART0 Structure                                            */
   __IO uint32_t  BAUD;                         /**< 0000: LPUART Baud Rate Register                                    */
   __IO uint32_t  STAT;                         /**< 0004: LPUART Status Register                                       */
   __IO uint32_t  CTRL;                         /**< 0008: LPUART Control Register                                      */
   __IO uint32_t  DATA;                         /**< 000C: LPUART Data Register                                         */
   __IO uint32_t  MATCH;                        /**< 0010: LPUART Match Address Register                                */
   __IO uint32_t  MODIR;                        /**< 0014: LPUART Modem IrDA Register                                   */
   __IO uint32_t  FIFO;                         /**< 0018: LPUART FIFO Register                                         */
   __IO uint32_t  WATER;                        /**< 001C: LPUART Watermark Register                                    */
} LPUART_Type;

/**
 * @} */ /* End group LPUART_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPUART0' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup LPUART_Register_Masks_GROUP LPUART Register Masks
* @brief Register Masks for LPUART
* @{
*/
/* ------- BAUD Bit Fields                          ------ */
#define LPUART_BAUD_SBR_MASK                     (0x1FFFU)                                           /*!< LPUART0_BAUD.SBR Mask                   */
#define LPUART_BAUD_SBR_SHIFT                    (0U)                                                /*!< LPUART0_BAUD.SBR Position               */
#define LPUART_BAUD_SBR(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFFUL)        /*!< LPUART0_BAUD.SBR Field                  */
#define LPUART_BAUD_SBNS_MASK                    (0x2000U)                                           /*!< LPUART0_BAUD.SBNS Mask                  */
#define LPUART_BAUD_SBNS_SHIFT                   (13U)                                               /*!< LPUART0_BAUD.SBNS Position              */
#define LPUART_BAUD_SBNS(x)                      (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< LPUART0_BAUD.SBNS Field                 */
#define LPUART_BAUD_RXEDGIE_MASK                 (0x4000U)                                           /*!< LPUART0_BAUD.RXEDGIE Mask               */
#define LPUART_BAUD_RXEDGIE_SHIFT                (14U)                                               /*!< LPUART0_BAUD.RXEDGIE Position           */
#define LPUART_BAUD_RXEDGIE(x)                   (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< LPUART0_BAUD.RXEDGIE Field              */
#define LPUART_BAUD_LBKDIE_MASK                  (0x8000U)                                           /*!< LPUART0_BAUD.LBKDIE Mask                */
#define LPUART_BAUD_LBKDIE_SHIFT                 (15U)                                               /*!< LPUART0_BAUD.LBKDIE Position            */
#define LPUART_BAUD_LBKDIE(x)                    (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< LPUART0_BAUD.LBKDIE Field               */
#define LPUART_BAUD_RESYNCDIS_MASK               (0x10000U)                                          /*!< LPUART0_BAUD.RESYNCDIS Mask             */
#define LPUART_BAUD_RESYNCDIS_SHIFT              (16U)                                               /*!< LPUART0_BAUD.RESYNCDIS Position         */
#define LPUART_BAUD_RESYNCDIS(x)                 (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< LPUART0_BAUD.RESYNCDIS Field            */
#define LPUART_BAUD_BOTHEDGE_MASK                (0x20000U)                                          /*!< LPUART0_BAUD.BOTHEDGE Mask              */
#define LPUART_BAUD_BOTHEDGE_SHIFT               (17U)                                               /*!< LPUART0_BAUD.BOTHEDGE Position          */
#define LPUART_BAUD_BOTHEDGE(x)                  (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< LPUART0_BAUD.BOTHEDGE Field             */
#define LPUART_BAUD_MATCFG_MASK                  (0xC0000U)                                          /*!< LPUART0_BAUD.MATCFG Mask                */
#define LPUART_BAUD_MATCFG_SHIFT                 (18U)                                               /*!< LPUART0_BAUD.MATCFG Position            */
#define LPUART_BAUD_MATCFG(x)                    (((uint32_t)(((uint32_t)(x))<<18U))&0xC0000UL)      /*!< LPUART0_BAUD.MATCFG Field               */
#define LPUART_BAUD_RDMAE_MASK                   (0x200000U)                                         /*!< LPUART0_BAUD.RDMAE Mask                 */
#define LPUART_BAUD_RDMAE_SHIFT                  (21U)                                               /*!< LPUART0_BAUD.RDMAE Position             */
#define LPUART_BAUD_RDMAE(x)                     (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< LPUART0_BAUD.RDMAE Field                */
#define LPUART_BAUD_TDMAE_MASK                   (0x800000U)                                         /*!< LPUART0_BAUD.TDMAE Mask                 */
#define LPUART_BAUD_TDMAE_SHIFT                  (23U)                                               /*!< LPUART0_BAUD.TDMAE Position             */
#define LPUART_BAUD_TDMAE(x)                     (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< LPUART0_BAUD.TDMAE Field                */
#define LPUART_BAUD_OSR_MASK                     (0x1F000000U)                                       /*!< LPUART0_BAUD.OSR Mask                   */
#define LPUART_BAUD_OSR_SHIFT                    (24U)                                               /*!< LPUART0_BAUD.OSR Position               */
#define LPUART_BAUD_OSR(x)                       (((uint32_t)(((uint32_t)(x))<<24U))&0x1F000000UL)   /*!< LPUART0_BAUD.OSR Field                  */
#define LPUART_BAUD_M10_MASK                     (0x20000000U)                                       /*!< LPUART0_BAUD.M10 Mask                   */
#define LPUART_BAUD_M10_SHIFT                    (29U)                                               /*!< LPUART0_BAUD.M10 Position               */
#define LPUART_BAUD_M10(x)                       (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< LPUART0_BAUD.M10 Field                  */
#define LPUART_BAUD_MAEN2_MASK                   (0x40000000U)                                       /*!< LPUART0_BAUD.MAEN2 Mask                 */
#define LPUART_BAUD_MAEN2_SHIFT                  (30U)                                               /*!< LPUART0_BAUD.MAEN2 Position             */
#define LPUART_BAUD_MAEN2(x)                     (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< LPUART0_BAUD.MAEN2 Field                */
#define LPUART_BAUD_MAEN1_MASK                   (0x80000000U)                                       /*!< LPUART0_BAUD.MAEN1 Mask                 */
#define LPUART_BAUD_MAEN1_SHIFT                  (31U)                                               /*!< LPUART0_BAUD.MAEN1 Position             */
#define LPUART_BAUD_MAEN1(x)                     (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< LPUART0_BAUD.MAEN1 Field                */
/* ------- STAT Bit Fields                          ------ */
#define LPUART_STAT_MA2F_MASK                    (0x4000U)                                           /*!< LPUART0_STAT.MA2F Mask                  */
#define LPUART_STAT_MA2F_SHIFT                   (14U)                                               /*!< LPUART0_STAT.MA2F Position              */
#define LPUART_STAT_MA2F(x)                      (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< LPUART0_STAT.MA2F Field                 */
#define LPUART_STAT_MA1F_MASK                    (0x8000U)                                           /*!< LPUART0_STAT.MA1F Mask                  */
#define LPUART_STAT_MA1F_SHIFT                   (15U)                                               /*!< LPUART0_STAT.MA1F Position              */
#define LPUART_STAT_MA1F(x)                      (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< LPUART0_STAT.MA1F Field                 */
#define LPUART_STAT_PF_MASK                      (0x10000U)                                          /*!< LPUART0_STAT.PF Mask                    */
#define LPUART_STAT_PF_SHIFT                     (16U)                                               /*!< LPUART0_STAT.PF Position                */
#define LPUART_STAT_PF(x)                        (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< LPUART0_STAT.PF Field                   */
#define LPUART_STAT_FE_MASK                      (0x20000U)                                          /*!< LPUART0_STAT.FE Mask                    */
#define LPUART_STAT_FE_SHIFT                     (17U)                                               /*!< LPUART0_STAT.FE Position                */
#define LPUART_STAT_FE(x)                        (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< LPUART0_STAT.FE Field                   */
#define LPUART_STAT_NF_MASK                      (0x40000U)                                          /*!< LPUART0_STAT.NF Mask                    */
#define LPUART_STAT_NF_SHIFT                     (18U)                                               /*!< LPUART0_STAT.NF Position                */
#define LPUART_STAT_NF(x)                        (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< LPUART0_STAT.NF Field                   */
#define LPUART_STAT_OR_MASK                      (0x80000U)                                          /*!< LPUART0_STAT.OR Mask                    */
#define LPUART_STAT_OR_SHIFT                     (19U)                                               /*!< LPUART0_STAT.OR Position                */
#define LPUART_STAT_OR(x)                        (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< LPUART0_STAT.OR Field                   */
#define LPUART_STAT_IDLE_MASK                    (0x100000U)                                         /*!< LPUART0_STAT.IDLE Mask                  */
#define LPUART_STAT_IDLE_SHIFT                   (20U)                                               /*!< LPUART0_STAT.IDLE Position              */
#define LPUART_STAT_IDLE(x)                      (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< LPUART0_STAT.IDLE Field                 */
#define LPUART_STAT_RDRF_MASK                    (0x200000U)                                         /*!< LPUART0_STAT.RDRF Mask                  */
#define LPUART_STAT_RDRF_SHIFT                   (21U)                                               /*!< LPUART0_STAT.RDRF Position              */
#define LPUART_STAT_RDRF(x)                      (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< LPUART0_STAT.RDRF Field                 */
#define LPUART_STAT_TC_MASK                      (0x400000U)                                         /*!< LPUART0_STAT.TC Mask                    */
#define LPUART_STAT_TC_SHIFT                     (22U)                                               /*!< LPUART0_STAT.TC Position                */
#define LPUART_STAT_TC(x)                        (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< LPUART0_STAT.TC Field                   */
#define LPUART_STAT_TDRE_MASK                    (0x800000U)                                         /*!< LPUART0_STAT.TDRE Mask                  */
#define LPUART_STAT_TDRE_SHIFT                   (23U)                                               /*!< LPUART0_STAT.TDRE Position              */
#define LPUART_STAT_TDRE(x)                      (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< LPUART0_STAT.TDRE Field                 */
#define LPUART_STAT_RAF_MASK                     (0x1000000U)                                        /*!< LPUART0_STAT.RAF Mask                   */
#define LPUART_STAT_RAF_SHIFT                    (24U)                                               /*!< LPUART0_STAT.RAF Position               */
#define LPUART_STAT_RAF(x)                       (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< LPUART0_STAT.RAF Field                  */
#define LPUART_STAT_LBKDE_MASK                   (0x2000000U)                                        /*!< LPUART0_STAT.LBKDE Mask                 */
#define LPUART_STAT_LBKDE_SHIFT                  (25U)                                               /*!< LPUART0_STAT.LBKDE Position             */
#define LPUART_STAT_LBKDE(x)                     (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< LPUART0_STAT.LBKDE Field                */
#define LPUART_STAT_BRK13_MASK                   (0x4000000U)                                        /*!< LPUART0_STAT.BRK13 Mask                 */
#define LPUART_STAT_BRK13_SHIFT                  (26U)                                               /*!< LPUART0_STAT.BRK13 Position             */
#define LPUART_STAT_BRK13(x)                     (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< LPUART0_STAT.BRK13 Field                */
#define LPUART_STAT_RWUID_MASK                   (0x8000000U)                                        /*!< LPUART0_STAT.RWUID Mask                 */
#define LPUART_STAT_RWUID_SHIFT                  (27U)                                               /*!< LPUART0_STAT.RWUID Position             */
#define LPUART_STAT_RWUID(x)                     (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< LPUART0_STAT.RWUID Field                */
#define LPUART_STAT_RXINV_MASK                   (0x10000000U)                                       /*!< LPUART0_STAT.RXINV Mask                 */
#define LPUART_STAT_RXINV_SHIFT                  (28U)                                               /*!< LPUART0_STAT.RXINV Position             */
#define LPUART_STAT_RXINV(x)                     (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< LPUART0_STAT.RXINV Field                */
#define LPUART_STAT_MSBF_MASK                    (0x20000000U)                                       /*!< LPUART0_STAT.MSBF Mask                  */
#define LPUART_STAT_MSBF_SHIFT                   (29U)                                               /*!< LPUART0_STAT.MSBF Position              */
#define LPUART_STAT_MSBF(x)                      (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< LPUART0_STAT.MSBF Field                 */
#define LPUART_STAT_RXEDGIF_MASK                 (0x40000000U)                                       /*!< LPUART0_STAT.RXEDGIF Mask               */
#define LPUART_STAT_RXEDGIF_SHIFT                (30U)                                               /*!< LPUART0_STAT.RXEDGIF Position           */
#define LPUART_STAT_RXEDGIF(x)                   (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< LPUART0_STAT.RXEDGIF Field              */
#define LPUART_STAT_LBKDIF_MASK                  (0x80000000U)                                       /*!< LPUART0_STAT.LBKDIF Mask                */
#define LPUART_STAT_LBKDIF_SHIFT                 (31U)                                               /*!< LPUART0_STAT.LBKDIF Position            */
#define LPUART_STAT_LBKDIF(x)                    (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< LPUART0_STAT.LBKDIF Field               */
/* ------- CTRL Bit Fields                          ------ */
#define LPUART_CTRL_PT_MASK                      (0x1U)                                              /*!< LPUART0_CTRL.PT Mask                    */
#define LPUART_CTRL_PT_SHIFT                     (0U)                                                /*!< LPUART0_CTRL.PT Position                */
#define LPUART_CTRL_PT(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPUART0_CTRL.PT Field                   */
#define LPUART_CTRL_PE_MASK                      (0x2U)                                              /*!< LPUART0_CTRL.PE Mask                    */
#define LPUART_CTRL_PE_SHIFT                     (1U)                                                /*!< LPUART0_CTRL.PE Position                */
#define LPUART_CTRL_PE(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPUART0_CTRL.PE Field                   */
#define LPUART_CTRL_ILT_MASK                     (0x4U)                                              /*!< LPUART0_CTRL.ILT Mask                   */
#define LPUART_CTRL_ILT_SHIFT                    (2U)                                                /*!< LPUART0_CTRL.ILT Position               */
#define LPUART_CTRL_ILT(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPUART0_CTRL.ILT Field                  */
#define LPUART_CTRL_WAKE_MASK                    (0x8U)                                              /*!< LPUART0_CTRL.WAKE Mask                  */
#define LPUART_CTRL_WAKE_SHIFT                   (3U)                                                /*!< LPUART0_CTRL.WAKE Position              */
#define LPUART_CTRL_WAKE(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPUART0_CTRL.WAKE Field                 */
#define LPUART_CTRL_M_MASK                       (0x10U)                                             /*!< LPUART0_CTRL.M Mask                     */
#define LPUART_CTRL_M_SHIFT                      (4U)                                                /*!< LPUART0_CTRL.M Position                 */
#define LPUART_CTRL_M(x)                         (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPUART0_CTRL.M Field                    */
#define LPUART_CTRL_RSRC_MASK                    (0x20U)                                             /*!< LPUART0_CTRL.RSRC Mask                  */
#define LPUART_CTRL_RSRC_SHIFT                   (5U)                                                /*!< LPUART0_CTRL.RSRC Position              */
#define LPUART_CTRL_RSRC(x)                      (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPUART0_CTRL.RSRC Field                 */
#define LPUART_CTRL_DOZEEN_MASK                  (0x40U)                                             /*!< LPUART0_CTRL.DOZEEN Mask                */
#define LPUART_CTRL_DOZEEN_SHIFT                 (6U)                                                /*!< LPUART0_CTRL.DOZEEN Position            */
#define LPUART_CTRL_DOZEEN(x)                    (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPUART0_CTRL.DOZEEN Field               */
#define LPUART_CTRL_LOOPS_MASK                   (0x80U)                                             /*!< LPUART0_CTRL.LOOPS Mask                 */
#define LPUART_CTRL_LOOPS_SHIFT                  (7U)                                                /*!< LPUART0_CTRL.LOOPS Position             */
#define LPUART_CTRL_LOOPS(x)                     (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPUART0_CTRL.LOOPS Field                */
#define LPUART_CTRL_IDLECFG_MASK                 (0x700U)                                            /*!< LPUART0_CTRL.IDLECFG Mask               */
#define LPUART_CTRL_IDLECFG_SHIFT                (8U)                                                /*!< LPUART0_CTRL.IDLECFG Position           */
#define LPUART_CTRL_IDLECFG(x)                   (((uint32_t)(((uint32_t)(x))<<8U))&0x700UL)         /*!< LPUART0_CTRL.IDLECFG Field              */
#define LPUART_CTRL_MA2IE_MASK                   (0x4000U)                                           /*!< LPUART0_CTRL.MA2IE Mask                 */
#define LPUART_CTRL_MA2IE_SHIFT                  (14U)                                               /*!< LPUART0_CTRL.MA2IE Position             */
#define LPUART_CTRL_MA2IE(x)                     (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< LPUART0_CTRL.MA2IE Field                */
#define LPUART_CTRL_MA1IE_MASK                   (0x8000U)                                           /*!< LPUART0_CTRL.MA1IE Mask                 */
#define LPUART_CTRL_MA1IE_SHIFT                  (15U)                                               /*!< LPUART0_CTRL.MA1IE Position             */
#define LPUART_CTRL_MA1IE(x)                     (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< LPUART0_CTRL.MA1IE Field                */
#define LPUART_CTRL_SBK_MASK                     (0x10000U)                                          /*!< LPUART0_CTRL.SBK Mask                   */
#define LPUART_CTRL_SBK_SHIFT                    (16U)                                               /*!< LPUART0_CTRL.SBK Position               */
#define LPUART_CTRL_SBK(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< LPUART0_CTRL.SBK Field                  */
#define LPUART_CTRL_RWU_MASK                     (0x20000U)                                          /*!< LPUART0_CTRL.RWU Mask                   */
#define LPUART_CTRL_RWU_SHIFT                    (17U)                                               /*!< LPUART0_CTRL.RWU Position               */
#define LPUART_CTRL_RWU(x)                       (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< LPUART0_CTRL.RWU Field                  */
#define LPUART_CTRL_RE_MASK                      (0x40000U)                                          /*!< LPUART0_CTRL.RE Mask                    */
#define LPUART_CTRL_RE_SHIFT                     (18U)                                               /*!< LPUART0_CTRL.RE Position                */
#define LPUART_CTRL_RE(x)                        (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< LPUART0_CTRL.RE Field                   */
#define LPUART_CTRL_TE_MASK                      (0x80000U)                                          /*!< LPUART0_CTRL.TE Mask                    */
#define LPUART_CTRL_TE_SHIFT                     (19U)                                               /*!< LPUART0_CTRL.TE Position                */
#define LPUART_CTRL_TE(x)                        (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< LPUART0_CTRL.TE Field                   */
#define LPUART_CTRL_ILIE_MASK                    (0x100000U)                                         /*!< LPUART0_CTRL.ILIE Mask                  */
#define LPUART_CTRL_ILIE_SHIFT                   (20U)                                               /*!< LPUART0_CTRL.ILIE Position              */
#define LPUART_CTRL_ILIE(x)                      (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< LPUART0_CTRL.ILIE Field                 */
#define LPUART_CTRL_RIE_MASK                     (0x200000U)                                         /*!< LPUART0_CTRL.RIE Mask                   */
#define LPUART_CTRL_RIE_SHIFT                    (21U)                                               /*!< LPUART0_CTRL.RIE Position               */
#define LPUART_CTRL_RIE(x)                       (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< LPUART0_CTRL.RIE Field                  */
#define LPUART_CTRL_TCIE_MASK                    (0x400000U)                                         /*!< LPUART0_CTRL.TCIE Mask                  */
#define LPUART_CTRL_TCIE_SHIFT                   (22U)                                               /*!< LPUART0_CTRL.TCIE Position              */
#define LPUART_CTRL_TCIE(x)                      (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< LPUART0_CTRL.TCIE Field                 */
#define LPUART_CTRL_TIE_MASK                     (0x800000U)                                         /*!< LPUART0_CTRL.TIE Mask                   */
#define LPUART_CTRL_TIE_SHIFT                    (23U)                                               /*!< LPUART0_CTRL.TIE Position               */
#define LPUART_CTRL_TIE(x)                       (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< LPUART0_CTRL.TIE Field                  */
#define LPUART_CTRL_PEIE_MASK                    (0x1000000U)                                        /*!< LPUART0_CTRL.PEIE Mask                  */
#define LPUART_CTRL_PEIE_SHIFT                   (24U)                                               /*!< LPUART0_CTRL.PEIE Position              */
#define LPUART_CTRL_PEIE(x)                      (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< LPUART0_CTRL.PEIE Field                 */
#define LPUART_CTRL_FEIE_MASK                    (0x2000000U)                                        /*!< LPUART0_CTRL.FEIE Mask                  */
#define LPUART_CTRL_FEIE_SHIFT                   (25U)                                               /*!< LPUART0_CTRL.FEIE Position              */
#define LPUART_CTRL_FEIE(x)                      (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< LPUART0_CTRL.FEIE Field                 */
#define LPUART_CTRL_NEIE_MASK                    (0x4000000U)                                        /*!< LPUART0_CTRL.NEIE Mask                  */
#define LPUART_CTRL_NEIE_SHIFT                   (26U)                                               /*!< LPUART0_CTRL.NEIE Position              */
#define LPUART_CTRL_NEIE(x)                      (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< LPUART0_CTRL.NEIE Field                 */
#define LPUART_CTRL_ORIE_MASK                    (0x8000000U)                                        /*!< LPUART0_CTRL.ORIE Mask                  */
#define LPUART_CTRL_ORIE_SHIFT                   (27U)                                               /*!< LPUART0_CTRL.ORIE Position              */
#define LPUART_CTRL_ORIE(x)                      (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< LPUART0_CTRL.ORIE Field                 */
#define LPUART_CTRL_TXINV_MASK                   (0x10000000U)                                       /*!< LPUART0_CTRL.TXINV Mask                 */
#define LPUART_CTRL_TXINV_SHIFT                  (28U)                                               /*!< LPUART0_CTRL.TXINV Position             */
#define LPUART_CTRL_TXINV(x)                     (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< LPUART0_CTRL.TXINV Field                */
#define LPUART_CTRL_TXDIR_MASK                   (0x20000000U)                                       /*!< LPUART0_CTRL.TXDIR Mask                 */
#define LPUART_CTRL_TXDIR_SHIFT                  (29U)                                               /*!< LPUART0_CTRL.TXDIR Position             */
#define LPUART_CTRL_TXDIR(x)                     (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< LPUART0_CTRL.TXDIR Field                */
#define LPUART_CTRL_R9T8_MASK                    (0x40000000U)                                       /*!< LPUART0_CTRL.R9T8 Mask                  */
#define LPUART_CTRL_R9T8_SHIFT                   (30U)                                               /*!< LPUART0_CTRL.R9T8 Position              */
#define LPUART_CTRL_R9T8(x)                      (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< LPUART0_CTRL.R9T8 Field                 */
#define LPUART_CTRL_R8T9_MASK                    (0x80000000U)                                       /*!< LPUART0_CTRL.R8T9 Mask                  */
#define LPUART_CTRL_R8T9_SHIFT                   (31U)                                               /*!< LPUART0_CTRL.R8T9 Position              */
#define LPUART_CTRL_R8T9(x)                      (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< LPUART0_CTRL.R8T9 Field                 */
/* ------- DATA Bit Fields                          ------ */
#define LPUART_DATA_R0T0_MASK                    (0x1U)                                              /*!< LPUART0_DATA.R0T0 Mask                  */
#define LPUART_DATA_R0T0_SHIFT                   (0U)                                                /*!< LPUART0_DATA.R0T0 Position              */
#define LPUART_DATA_R0T0(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPUART0_DATA.R0T0 Field                 */
#define LPUART_DATA_R1T1_MASK                    (0x2U)                                              /*!< LPUART0_DATA.R1T1 Mask                  */
#define LPUART_DATA_R1T1_SHIFT                   (1U)                                                /*!< LPUART0_DATA.R1T1 Position              */
#define LPUART_DATA_R1T1(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPUART0_DATA.R1T1 Field                 */
#define LPUART_DATA_R2T2_MASK                    (0x4U)                                              /*!< LPUART0_DATA.R2T2 Mask                  */
#define LPUART_DATA_R2T2_SHIFT                   (2U)                                                /*!< LPUART0_DATA.R2T2 Position              */
#define LPUART_DATA_R2T2(x)                      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPUART0_DATA.R2T2 Field                 */
#define LPUART_DATA_R3T3_MASK                    (0x8U)                                              /*!< LPUART0_DATA.R3T3 Mask                  */
#define LPUART_DATA_R3T3_SHIFT                   (3U)                                                /*!< LPUART0_DATA.R3T3 Position              */
#define LPUART_DATA_R3T3(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPUART0_DATA.R3T3 Field                 */
#define LPUART_DATA_R4T4_MASK                    (0x10U)                                             /*!< LPUART0_DATA.R4T4 Mask                  */
#define LPUART_DATA_R4T4_SHIFT                   (4U)                                                /*!< LPUART0_DATA.R4T4 Position              */
#define LPUART_DATA_R4T4(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPUART0_DATA.R4T4 Field                 */
#define LPUART_DATA_R5T5_MASK                    (0x20U)                                             /*!< LPUART0_DATA.R5T5 Mask                  */
#define LPUART_DATA_R5T5_SHIFT                   (5U)                                                /*!< LPUART0_DATA.R5T5 Position              */
#define LPUART_DATA_R5T5(x)                      (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPUART0_DATA.R5T5 Field                 */
#define LPUART_DATA_R6T6_MASK                    (0x40U)                                             /*!< LPUART0_DATA.R6T6 Mask                  */
#define LPUART_DATA_R6T6_SHIFT                   (6U)                                                /*!< LPUART0_DATA.R6T6 Position              */
#define LPUART_DATA_R6T6(x)                      (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPUART0_DATA.R6T6 Field                 */
#define LPUART_DATA_R7T7_MASK                    (0x80U)                                             /*!< LPUART0_DATA.R7T7 Mask                  */
#define LPUART_DATA_R7T7_SHIFT                   (7U)                                                /*!< LPUART0_DATA.R7T7 Position              */
#define LPUART_DATA_R7T7(x)                      (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPUART0_DATA.R7T7 Field                 */
#define LPUART_DATA_R8T8_MASK                    (0x100U)                                            /*!< LPUART0_DATA.R8T8 Mask                  */
#define LPUART_DATA_R8T8_SHIFT                   (8U)                                                /*!< LPUART0_DATA.R8T8 Position              */
#define LPUART_DATA_R8T8(x)                      (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPUART0_DATA.R8T8 Field                 */
#define LPUART_DATA_R9T9_MASK                    (0x200U)                                            /*!< LPUART0_DATA.R9T9 Mask                  */
#define LPUART_DATA_R9T9_SHIFT                   (9U)                                                /*!< LPUART0_DATA.R9T9 Position              */
#define LPUART_DATA_R9T9(x)                      (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPUART0_DATA.R9T9 Field                 */
#define LPUART_DATA_IDLINE_MASK                  (0x800U)                                            /*!< LPUART0_DATA.IDLINE Mask                */
#define LPUART_DATA_IDLINE_SHIFT                 (11U)                                               /*!< LPUART0_DATA.IDLINE Position            */
#define LPUART_DATA_IDLINE(x)                    (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< LPUART0_DATA.IDLINE Field               */
#define LPUART_DATA_RXEMPT_MASK                  (0x1000U)                                           /*!< LPUART0_DATA.RXEMPT Mask                */
#define LPUART_DATA_RXEMPT_SHIFT                 (12U)                                               /*!< LPUART0_DATA.RXEMPT Position            */
#define LPUART_DATA_RXEMPT(x)                    (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< LPUART0_DATA.RXEMPT Field               */
#define LPUART_DATA_FRETSC_MASK                  (0x2000U)                                           /*!< LPUART0_DATA.FRETSC Mask                */
#define LPUART_DATA_FRETSC_SHIFT                 (13U)                                               /*!< LPUART0_DATA.FRETSC Position            */
#define LPUART_DATA_FRETSC(x)                    (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< LPUART0_DATA.FRETSC Field               */
#define LPUART_DATA_PARITYE_MASK                 (0x4000U)                                           /*!< LPUART0_DATA.PARITYE Mask               */
#define LPUART_DATA_PARITYE_SHIFT                (14U)                                               /*!< LPUART0_DATA.PARITYE Position           */
#define LPUART_DATA_PARITYE(x)                   (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< LPUART0_DATA.PARITYE Field              */
#define LPUART_DATA_NOISY_MASK                   (0x8000U)                                           /*!< LPUART0_DATA.NOISY Mask                 */
#define LPUART_DATA_NOISY_SHIFT                  (15U)                                               /*!< LPUART0_DATA.NOISY Position             */
#define LPUART_DATA_NOISY(x)                     (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< LPUART0_DATA.NOISY Field                */
/* ------- MATCH Bit Fields                         ------ */
#define LPUART_MATCH_MA1_MASK                    (0x3FFU)                                            /*!< LPUART0_MATCH.MA1 Mask                  */
#define LPUART_MATCH_MA1_SHIFT                   (0U)                                                /*!< LPUART0_MATCH.MA1 Position              */
#define LPUART_MATCH_MA1(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFUL)         /*!< LPUART0_MATCH.MA1 Field                 */
#define LPUART_MATCH_MA2_MASK                    (0x3FF0000U)                                        /*!< LPUART0_MATCH.MA2 Mask                  */
#define LPUART_MATCH_MA2_SHIFT                   (16U)                                               /*!< LPUART0_MATCH.MA2 Position              */
#define LPUART_MATCH_MA2(x)                      (((uint32_t)(((uint32_t)(x))<<16U))&0x3FF0000UL)    /*!< LPUART0_MATCH.MA2 Field                 */
/* ------- MODIR Bit Fields                         ------ */
#define LPUART_MODIR_TXCTSE_MASK                 (0x1U)                                              /*!< LPUART0_MODIR.TXCTSE Mask               */
#define LPUART_MODIR_TXCTSE_SHIFT                (0U)                                                /*!< LPUART0_MODIR.TXCTSE Position           */
#define LPUART_MODIR_TXCTSE(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPUART0_MODIR.TXCTSE Field              */
#define LPUART_MODIR_TXRTSE_MASK                 (0x2U)                                              /*!< LPUART0_MODIR.TXRTSE Mask               */
#define LPUART_MODIR_TXRTSE_SHIFT                (1U)                                                /*!< LPUART0_MODIR.TXRTSE Position           */
#define LPUART_MODIR_TXRTSE(x)                   (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPUART0_MODIR.TXRTSE Field              */
#define LPUART_MODIR_TXRTSPOL_MASK               (0x4U)                                              /*!< LPUART0_MODIR.TXRTSPOL Mask             */
#define LPUART_MODIR_TXRTSPOL_SHIFT              (2U)                                                /*!< LPUART0_MODIR.TXRTSPOL Position         */
#define LPUART_MODIR_TXRTSPOL(x)                 (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPUART0_MODIR.TXRTSPOL Field            */
#define LPUART_MODIR_RXRTSE_MASK                 (0x8U)                                              /*!< LPUART0_MODIR.RXRTSE Mask               */
#define LPUART_MODIR_RXRTSE_SHIFT                (3U)                                                /*!< LPUART0_MODIR.RXRTSE Position           */
#define LPUART_MODIR_RXRTSE(x)                   (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPUART0_MODIR.RXRTSE Field              */
#define LPUART_MODIR_TXCTSC_MASK                 (0x10U)                                             /*!< LPUART0_MODIR.TXCTSC Mask               */
#define LPUART_MODIR_TXCTSC_SHIFT                (4U)                                                /*!< LPUART0_MODIR.TXCTSC Position           */
#define LPUART_MODIR_TXCTSC(x)                   (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LPUART0_MODIR.TXCTSC Field              */
#define LPUART_MODIR_TXCTSSRC_MASK               (0x20U)                                             /*!< LPUART0_MODIR.TXCTSSRC Mask             */
#define LPUART_MODIR_TXCTSSRC_SHIFT              (5U)                                                /*!< LPUART0_MODIR.TXCTSSRC Position         */
#define LPUART_MODIR_TXCTSSRC(x)                 (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LPUART0_MODIR.TXCTSSRC Field            */
#define LPUART_MODIR_RTSWATER_MASK               (0xFF00U)                                           /*!< LPUART0_MODIR.RTSWATER Mask             */
#define LPUART_MODIR_RTSWATER_SHIFT              (8U)                                                /*!< LPUART0_MODIR.RTSWATER Position         */
#define LPUART_MODIR_RTSWATER(x)                 (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< LPUART0_MODIR.RTSWATER Field            */
#define LPUART_MODIR_TNP_MASK                    (0x30000U)                                          /*!< LPUART0_MODIR.TNP Mask                  */
#define LPUART_MODIR_TNP_SHIFT                   (16U)                                               /*!< LPUART0_MODIR.TNP Position              */
#define LPUART_MODIR_TNP(x)                      (((uint32_t)(((uint32_t)(x))<<16U))&0x30000UL)      /*!< LPUART0_MODIR.TNP Field                 */
#define LPUART_MODIR_IREN_MASK                   (0x40000U)                                          /*!< LPUART0_MODIR.IREN Mask                 */
#define LPUART_MODIR_IREN_SHIFT                  (18U)                                               /*!< LPUART0_MODIR.IREN Position             */
#define LPUART_MODIR_IREN(x)                     (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< LPUART0_MODIR.IREN Field                */
/* ------- FIFO Bit Fields                          ------ */
#define LPUART_FIFO_RXFIFOSIZE_MASK              (0x7U)                                              /*!< LPUART0_FIFO.RXFIFOSIZE Mask            */
#define LPUART_FIFO_RXFIFOSIZE_SHIFT             (0U)                                                /*!< LPUART0_FIFO.RXFIFOSIZE Position        */
#define LPUART_FIFO_RXFIFOSIZE(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< LPUART0_FIFO.RXFIFOSIZE Field           */
#define LPUART_FIFO_RXFE_MASK                    (0x8U)                                              /*!< LPUART0_FIFO.RXFE Mask                  */
#define LPUART_FIFO_RXFE_SHIFT                   (3U)                                                /*!< LPUART0_FIFO.RXFE Position              */
#define LPUART_FIFO_RXFE(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPUART0_FIFO.RXFE Field                 */
#define LPUART_FIFO_TXFIFOSIZE_MASK              (0x70U)                                             /*!< LPUART0_FIFO.TXFIFOSIZE Mask            */
#define LPUART_FIFO_TXFIFOSIZE_SHIFT             (4U)                                                /*!< LPUART0_FIFO.TXFIFOSIZE Position        */
#define LPUART_FIFO_TXFIFOSIZE(x)                (((uint32_t)(((uint32_t)(x))<<4U))&0x70UL)          /*!< LPUART0_FIFO.TXFIFOSIZE Field           */
#define LPUART_FIFO_TXFE_MASK                    (0x80U)                                             /*!< LPUART0_FIFO.TXFE Mask                  */
#define LPUART_FIFO_TXFE_SHIFT                   (7U)                                                /*!< LPUART0_FIFO.TXFE Position              */
#define LPUART_FIFO_TXFE(x)                      (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPUART0_FIFO.TXFE Field                 */
#define LPUART_FIFO_RXUFE_MASK                   (0x100U)                                            /*!< LPUART0_FIFO.RXUFE Mask                 */
#define LPUART_FIFO_RXUFE_SHIFT                  (8U)                                                /*!< LPUART0_FIFO.RXUFE Position             */
#define LPUART_FIFO_RXUFE(x)                     (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LPUART0_FIFO.RXUFE Field                */
#define LPUART_FIFO_TXOFE_MASK                   (0x200U)                                            /*!< LPUART0_FIFO.TXOFE Mask                 */
#define LPUART_FIFO_TXOFE_SHIFT                  (9U)                                                /*!< LPUART0_FIFO.TXOFE Position             */
#define LPUART_FIFO_TXOFE(x)                     (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LPUART0_FIFO.TXOFE Field                */
#define LPUART_FIFO_RXIDEN_MASK                  (0x1C00U)                                           /*!< LPUART0_FIFO.RXIDEN Mask                */
#define LPUART_FIFO_RXIDEN_SHIFT                 (10U)                                               /*!< LPUART0_FIFO.RXIDEN Position            */
#define LPUART_FIFO_RXIDEN(x)                    (((uint32_t)(((uint32_t)(x))<<10U))&0x1C00UL)       /*!< LPUART0_FIFO.RXIDEN Field               */
#define LPUART_FIFO_RXFLUSH_MASK                 (0x4000U)                                           /*!< LPUART0_FIFO.RXFLUSH Mask               */
#define LPUART_FIFO_RXFLUSH_SHIFT                (14U)                                               /*!< LPUART0_FIFO.RXFLUSH Position           */
#define LPUART_FIFO_RXFLUSH(x)                   (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< LPUART0_FIFO.RXFLUSH Field              */
#define LPUART_FIFO_TXFLUSH_MASK                 (0x8000U)                                           /*!< LPUART0_FIFO.TXFLUSH Mask               */
#define LPUART_FIFO_TXFLUSH_SHIFT                (15U)                                               /*!< LPUART0_FIFO.TXFLUSH Position           */
#define LPUART_FIFO_TXFLUSH(x)                   (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< LPUART0_FIFO.TXFLUSH Field              */
#define LPUART_FIFO_RXUF_MASK                    (0x10000U)                                          /*!< LPUART0_FIFO.RXUF Mask                  */
#define LPUART_FIFO_RXUF_SHIFT                   (16U)                                               /*!< LPUART0_FIFO.RXUF Position              */
#define LPUART_FIFO_RXUF(x)                      (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< LPUART0_FIFO.RXUF Field                 */
#define LPUART_FIFO_TXOF_MASK                    (0x20000U)                                          /*!< LPUART0_FIFO.TXOF Mask                  */
#define LPUART_FIFO_TXOF_SHIFT                   (17U)                                               /*!< LPUART0_FIFO.TXOF Position              */
#define LPUART_FIFO_TXOF(x)                      (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< LPUART0_FIFO.TXOF Field                 */
#define LPUART_FIFO_RXEMPT_MASK                  (0x400000U)                                         /*!< LPUART0_FIFO.RXEMPT Mask                */
#define LPUART_FIFO_RXEMPT_SHIFT                 (22U)                                               /*!< LPUART0_FIFO.RXEMPT Position            */
#define LPUART_FIFO_RXEMPT(x)                    (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< LPUART0_FIFO.RXEMPT Field               */
#define LPUART_FIFO_TXEMPT_MASK                  (0x800000U)                                         /*!< LPUART0_FIFO.TXEMPT Mask                */
#define LPUART_FIFO_TXEMPT_SHIFT                 (23U)                                               /*!< LPUART0_FIFO.TXEMPT Position            */
#define LPUART_FIFO_TXEMPT(x)                    (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< LPUART0_FIFO.TXEMPT Field               */
/* ------- WATER Bit Fields                         ------ */
#define LPUART_WATER_TXWATER_MASK                (0xFFU)                                             /*!< LPUART0_WATER.TXWATER Mask              */
#define LPUART_WATER_TXWATER_SHIFT               (0U)                                                /*!< LPUART0_WATER.TXWATER Position          */
#define LPUART_WATER_TXWATER(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LPUART0_WATER.TXWATER Field             */
#define LPUART_WATER_TXCOUNT_MASK                (0xFF00U)                                           /*!< LPUART0_WATER.TXCOUNT Mask              */
#define LPUART_WATER_TXCOUNT_SHIFT               (8U)                                                /*!< LPUART0_WATER.TXCOUNT Position          */
#define LPUART_WATER_TXCOUNT(x)                  (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< LPUART0_WATER.TXCOUNT Field             */
#define LPUART_WATER_RXWATER_MASK                (0xFF0000U)                                         /*!< LPUART0_WATER.RXWATER Mask              */
#define LPUART_WATER_RXWATER_SHIFT               (16U)                                               /*!< LPUART0_WATER.RXWATER Position          */
#define LPUART_WATER_RXWATER(x)                  (((uint32_t)(((uint32_t)(x))<<16U))&0xFF0000UL)     /*!< LPUART0_WATER.RXWATER Field             */
#define LPUART_WATER_RXCOUNT_MASK                (0xFF000000U)                                       /*!< LPUART0_WATER.RXCOUNT Mask              */
#define LPUART_WATER_RXCOUNT_SHIFT               (24U)                                               /*!< LPUART0_WATER.RXCOUNT Position          */
#define LPUART_WATER_RXCOUNT(x)                  (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< LPUART0_WATER.RXCOUNT Field             */
/**
 * @} */ /* End group LPUART_Register_Masks_GROUP 
 */

/* LPUART0 - Peripheral instance base addresses */
#define LPUART0_BasePtr                0x40054000UL //!< Peripheral base address
#define LPUART0                        ((LPUART_Type *) LPUART0_BasePtr) //!< Freescale base pointer
#define LPUART0_BASE_PTR               (LPUART0) //!< Freescale style base pointer
/**
 * @} */ /* End group LPUART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LPUART_Peripheral_access_layer_GROUP LPUART Peripheral Access Layer
* @brief C Struct for LPUART
* @{
*/

/* ================================================================================ */
/* ================           LPUART1 (derived from LPUART0)       ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */

/* LPUART1 - Peripheral instance base addresses */
#define LPUART1_BasePtr                0x40055000UL //!< Peripheral base address
#define LPUART1                        ((LPUART_Type *) LPUART1_BasePtr) //!< Freescale base pointer
#define LPUART1_BASE_PTR               (LPUART1) //!< Freescale style base pointer
/**
 * @} */ /* End group LPUART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LPUART_Peripheral_access_layer_GROUP LPUART Peripheral Access Layer
* @brief C Struct for LPUART
* @{
*/

/* ================================================================================ */
/* ================           LPUART2 (derived from LPUART0)       ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */

/* LPUART2 - Peripheral instance base addresses */
#define LPUART2_BasePtr                0x40056000UL //!< Peripheral base address
#define LPUART2                        ((LPUART_Type *) LPUART2_BasePtr) //!< Freescale base pointer
#define LPUART2_BASE_PTR               (LPUART2) //!< Freescale style base pointer
/**
 * @} */ /* End group LPUART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LTC_Peripheral_access_layer_GROUP LTC Peripheral Access Layer
* @brief C Struct for LTC
* @{
*/

/* ================================================================================ */
/* ================           LTC0 (file:LTC0_MKL82Z7)             ================ */
/* ================================================================================ */

/**
 * @brief LTC
 */
/**
* @addtogroup LTC_structs_GROUP LTC struct
* @brief Struct for LTC
* @{
*/
typedef struct {                                /*       LTC0 Structure                                               */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  MD;                        /**< 0000: LTC Mode Register (non-PKHA/non-RNG use)                     */
      __IO uint32_t  MDPK;                      /**< 0000: LTC Mode Register (PublicKey)                                */
   };
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  KS;                           /**< 0008: LTC Key Size Register                                        */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  DS;                           /**< 0010: LTC Data Size Register                                       */
        uint8_t   RESERVED_2[4];               
   __IO uint32_t  ICVS;                         /**< 0018: LTC ICV Size Register                                        */
        uint8_t   RESERVED_3[20];              
   __O  uint32_t  COM;                          /**< 0030: LTC Command Register                                         */
   __IO uint32_t  CTL;                          /**< 0034: LTC Control Register                                         */
        uint8_t   RESERVED_4[8];               
   __O  uint32_t  CW;                           /**< 0040: LTC Clear Written Register                                   */
        uint8_t   RESERVED_5[4];               
   __IO uint32_t  STA;                          /**< 0048: LTC Status Register                                          */
   __I  uint32_t  ESTA;                         /**< 004C: LTC Error Status Register                                    */
        uint8_t   RESERVED_6[8];               
   __IO uint32_t  AADSZ;                        /**< 0058: LTC AAD Size Register                                        */
        uint8_t   RESERVED_7[4];               
   __IO uint32_t  IVSZ;                         /**< 0060: LTC IV Size Register                                         */
        uint8_t   RESERVED_8[4];               
   __O  uint32_t  DPAMS;                        /**< 0068: LTC DPA Mask Seed Register                                   */
        uint8_t   RESERVED_9[20];              
   __IO uint32_t  PKASZ;                        /**< 0080: LTC PKHA A Size Register                                     */
        uint8_t   RESERVED_10[4];              
   __IO uint32_t  PKBSZ;                        /**< 0088: LTC PKHA B Size Register                                     */
        uint8_t   RESERVED_11[4];              
   __IO uint32_t  PKNSZ;                        /**< 0090: LTC PKHA N Size Register                                     */
        uint8_t   RESERVED_12[4];              
   __IO uint32_t  PKESZ;                        /**< 0098: LTC PKHA E Size Register                                     */
        uint8_t   RESERVED_13[100];            
   __IO uint32_t  CTX[16];                      /**< 0100: LTC Context Register                                         */
        uint8_t   RESERVED_14[192];            
   __IO uint32_t  KEY[8];                       /**< 0200: LTC Key                                                      */
        uint8_t   RESERVED_15[720];            
   __I  uint32_t  VID1;                         /**< 04F0: LTC Version ID Register                                      */
   __I  uint32_t  VID2;                         /**< 04F4: LTC Version ID 2 Register                                    */
   __I  uint32_t  CHAVID;                       /**< 04F8: LTC CHA Version ID Register                                  */
        uint8_t   RESERVED_16[708];            
   __I  uint32_t  FIFOSTA;                      /**< 07C0: LTC FIFO Status Register                                     */
        uint8_t   RESERVED_17[28];             
   __O  uint32_t  IFIFO;                        /**< 07E0: LTC Input Data FIFO                                          */
        uint8_t   RESERVED_18[12];             
   __I  uint32_t  OFIFO;                        /**< 07F0: LTC Output Data FIFO                                         */
        uint8_t   RESERVED_19[12];             
   union {                                      /**< 0000: (size=0100)                                                  */
      __IO uint32_t  PKA[64];                   /**< 0800: LTC PKHA A  Register                                         */
      struct {                                  /**< 0000: (size=0100)                                                  */
         __IO uint32_t  PKA0[16];               /**< 0800: LTC PKHA A 0 Register                                        */
         __IO uint32_t  PKA1[16];               /**< 0840: LTC PKHA A1  Register                                        */
         __IO uint32_t  PKA2[16];               /**< 0880: LTC PKHA A2  Register                                        */
         __IO uint32_t  PKA3[16];               /**< 08C0: LTC PKHA A3  Register                                        */
      };
   };
        uint8_t   RESERVED_21[256];            
   union {                                      /**< 0000: (size=0100)                                                  */
      __IO uint32_t  PKB[64];                   /**< 0A00: LTC PKHA B  Register                                         */
      struct {                                  /**< 0000: (size=0100)                                                  */
         __IO uint32_t  PKB0[16];               /**< 0A00: LTC PKHA B 0 Register                                        */
         __IO uint32_t  PKB1[16];               /**< 0A40: LTC PKHA B1  Register                                        */
         __IO uint32_t  PKB2[16];               /**< 0A80: LTC PKHA B2  Register                                        */
         __IO uint32_t  PKB3[16];               /**< 0AC0: LTC PKHA B3  Register                                        */
      };
   };
        uint8_t   RESERVED_23[256];            
   union {                                      /**< 0000: (size=0100)                                                  */
      __IO uint32_t  PKN[64];                   /**< 0C00: LTC PKHA N  Register                                         */
      struct {                                  /**< 0000: (size=0100)                                                  */
         __IO uint32_t  PKN0[16];               /**< 0C00: LTC PKHA N 0 Register                                        */
         __IO uint32_t  PKN1[16];               /**< 0C40: LTC PKHA N1  Register                                        */
         __IO uint32_t  PKN2[16];               /**< 0C80: LTC PKHA N2  Register                                        */
         __IO uint32_t  PKN3[16];               /**< 0CC0: LTC PKHA N3  Register                                        */
      };
   };
        uint8_t   RESERVED_25[256];            
   union {                                      /**< 0000: (size=0100)                                                  */
      __IO uint32_t  PKE[64];                   /**< 0E00: LTC PKHA E  Register                                         */
      struct {                                  /**< 0000: (size=0100)                                                  */
         __IO uint32_t  PKE0[16];               /**< 0E00: LTC PKHA E 0 Register                                        */
         __IO uint32_t  PKE1[16];               /**< 0E40: LTC PKHA E1  Register                                        */
         __IO uint32_t  PKE2[16];               /**< 0E80: LTC PKHA E2  Register                                        */
         __IO uint32_t  PKE3[16];               /**< 0EC0: LTC PKHA E3  Register                                        */
      };
   };
} LTC_Type;

/**
 * @} */ /* End group LTC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LTC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup LTC_Register_Masks_GROUP LTC Register Masks
* @brief Register Masks for LTC
* @{
*/
/* ------- MD Bit Fields                            ------ */
#define LTC_MD_ENC_MASK                          (0x1U)                                              /*!< LTC0_MD.ENC Mask                        */
#define LTC_MD_ENC_SHIFT                         (0U)                                                /*!< LTC0_MD.ENC Position                    */
#define LTC_MD_ENC(x)                            (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LTC0_MD.ENC Field                       */
#define LTC_MD_ICV_TEST_MASK                     (0x2U)                                              /*!< LTC0_MD.ICV_TEST Mask                   */
#define LTC_MD_ICV_TEST_SHIFT                    (1U)                                                /*!< LTC0_MD.ICV_TEST Position               */
#define LTC_MD_ICV_TEST(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LTC0_MD.ICV_TEST Field                  */
#define LTC_MD_AS_MASK                           (0xCU)                                              /*!< LTC0_MD.AS Mask                         */
#define LTC_MD_AS_SHIFT                          (2U)                                                /*!< LTC0_MD.AS Position                     */
#define LTC_MD_AS(x)                             (((uint32_t)(((uint32_t)(x))<<2U))&0xCUL)           /*!< LTC0_MD.AS Field                        */
#define LTC_MD_AAI_MASK                          (0x1FF0U)                                           /*!< LTC0_MD.AAI Mask                        */
#define LTC_MD_AAI_SHIFT                         (4U)                                                /*!< LTC0_MD.AAI Position                    */
#define LTC_MD_AAI(x)                            (((uint32_t)(((uint32_t)(x))<<4U))&0x1FF0UL)        /*!< LTC0_MD.AAI Field                       */
#define LTC_MD_ALG_MASK                          (0xFF0000U)                                         /*!< LTC0_MD.ALG Mask                        */
#define LTC_MD_ALG_SHIFT                         (16U)                                               /*!< LTC0_MD.ALG Position                    */
#define LTC_MD_ALG(x)                            (((uint32_t)(((uint32_t)(x))<<16U))&0xFF0000UL)     /*!< LTC0_MD.ALG Field                       */
/* ------- MDPK Bit Fields                          ------ */
#define LTC_MDPK_PKHA_MODE_LS_MASK               (0xFFFU)                                            /*!< LTC0_MDPK.PKHA_MODE_LS Mask             */
#define LTC_MDPK_PKHA_MODE_LS_SHIFT              (0U)                                                /*!< LTC0_MDPK.PKHA_MODE_LS Position         */
#define LTC_MDPK_PKHA_MODE_LS(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFUL)         /*!< LTC0_MDPK.PKHA_MODE_LS Field            */
#define LTC_MDPK_PKHA_MODE_MS_MASK               (0xF0000U)                                          /*!< LTC0_MDPK.PKHA_MODE_MS Mask             */
#define LTC_MDPK_PKHA_MODE_MS_SHIFT              (16U)                                               /*!< LTC0_MDPK.PKHA_MODE_MS Position         */
#define LTC_MDPK_PKHA_MODE_MS(x)                 (((uint32_t)(((uint32_t)(x))<<16U))&0xF0000UL)      /*!< LTC0_MDPK.PKHA_MODE_MS Field            */
#define LTC_MDPK_ALG_MASK                        (0xF00000U)                                         /*!< LTC0_MDPK.ALG Mask                      */
#define LTC_MDPK_ALG_SHIFT                       (20U)                                               /*!< LTC0_MDPK.ALG Position                  */
#define LTC_MDPK_ALG(x)                          (((uint32_t)(((uint32_t)(x))<<20U))&0xF00000UL)     /*!< LTC0_MDPK.ALG Field                     */
/* ------- KS Bit Fields                            ------ */
#define LTC_KS_KS_MASK                           (0x3FU)                                             /*!< LTC0_KS.KS Mask                         */
#define LTC_KS_KS_SHIFT                          (0U)                                                /*!< LTC0_KS.KS Position                     */
#define LTC_KS_KS(x)                             (((uint32_t)(((uint32_t)(x))<<0U))&0x3FUL)          /*!< LTC0_KS.KS Field                        */
/* ------- DS Bit Fields                            ------ */
#define LTC_DS_DS_MASK                           (0xFFFU)                                            /*!< LTC0_DS.DS Mask                         */
#define LTC_DS_DS_SHIFT                          (0U)                                                /*!< LTC0_DS.DS Position                     */
#define LTC_DS_DS(x)                             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFUL)         /*!< LTC0_DS.DS Field                        */
/* ------- ICVS Bit Fields                          ------ */
#define LTC_ICVS_ICVS_MASK                       (0x1FU)                                             /*!< LTC0_ICVS.ICVS Mask                     */
#define LTC_ICVS_ICVS_SHIFT                      (0U)                                                /*!< LTC0_ICVS.ICVS Position                 */
#define LTC_ICVS_ICVS(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1FUL)          /*!< LTC0_ICVS.ICVS Field                    */
/* ------- COM Bit Fields                           ------ */
#define LTC_COM_ALL_MASK                         (0x1U)                                              /*!< LTC0_COM.ALL Mask                       */
#define LTC_COM_ALL_SHIFT                        (0U)                                                /*!< LTC0_COM.ALL Position                   */
#define LTC_COM_ALL(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LTC0_COM.ALL Field                      */
#define LTC_COM_AES_MASK                         (0x2U)                                              /*!< LTC0_COM.AES Mask                       */
#define LTC_COM_AES_SHIFT                        (1U)                                                /*!< LTC0_COM.AES Position                   */
#define LTC_COM_AES(x)                           (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LTC0_COM.AES Field                      */
#define LTC_COM_DES_MASK                         (0x4U)                                              /*!< LTC0_COM.DES Mask                       */
#define LTC_COM_DES_SHIFT                        (2U)                                                /*!< LTC0_COM.DES Position                   */
#define LTC_COM_DES(x)                           (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LTC0_COM.DES Field                      */
#define LTC_COM_PK_MASK                          (0x40U)                                             /*!< LTC0_COM.PK Mask                        */
#define LTC_COM_PK_SHIFT                         (6U)                                                /*!< LTC0_COM.PK Position                    */
#define LTC_COM_PK(x)                            (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LTC0_COM.PK Field                       */
#define LTC_COM_MD_MASK                          (0x80U)                                             /*!< LTC0_COM.MD Mask                        */
#define LTC_COM_MD_SHIFT                         (7U)                                                /*!< LTC0_COM.MD Position                    */
#define LTC_COM_MD(x)                            (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LTC0_COM.MD Field                       */
/* ------- CTL Bit Fields                           ------ */
#define LTC_CTL_IM_MASK                          (0x1U)                                              /*!< LTC0_CTL.IM Mask                        */
#define LTC_CTL_IM_SHIFT                         (0U)                                                /*!< LTC0_CTL.IM Position                    */
#define LTC_CTL_IM(x)                            (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LTC0_CTL.IM Field                       */
#define LTC_CTL_PDE_MASK                         (0x10U)                                             /*!< LTC0_CTL.PDE Mask                       */
#define LTC_CTL_PDE_SHIFT                        (4U)                                                /*!< LTC0_CTL.PDE Position                   */
#define LTC_CTL_PDE(x)                           (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< LTC0_CTL.PDE Field                      */
#define LTC_CTL_IFE_MASK                         (0x100U)                                            /*!< LTC0_CTL.IFE Mask                       */
#define LTC_CTL_IFE_SHIFT                        (8U)                                                /*!< LTC0_CTL.IFE Position                   */
#define LTC_CTL_IFE(x)                           (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< LTC0_CTL.IFE Field                      */
#define LTC_CTL_IFR_MASK                         (0x200U)                                            /*!< LTC0_CTL.IFR Mask                       */
#define LTC_CTL_IFR_SHIFT                        (9U)                                                /*!< LTC0_CTL.IFR Position                   */
#define LTC_CTL_IFR(x)                           (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< LTC0_CTL.IFR Field                      */
#define LTC_CTL_OFE_MASK                         (0x1000U)                                           /*!< LTC0_CTL.OFE Mask                       */
#define LTC_CTL_OFE_SHIFT                        (12U)                                               /*!< LTC0_CTL.OFE Position                   */
#define LTC_CTL_OFE(x)                           (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< LTC0_CTL.OFE Field                      */
#define LTC_CTL_OFR_MASK                         (0x2000U)                                           /*!< LTC0_CTL.OFR Mask                       */
#define LTC_CTL_OFR_SHIFT                        (13U)                                               /*!< LTC0_CTL.OFR Position                   */
#define LTC_CTL_OFR(x)                           (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< LTC0_CTL.OFR Field                      */
#define LTC_CTL_IFS_MASK                         (0x10000U)                                          /*!< LTC0_CTL.IFS Mask                       */
#define LTC_CTL_IFS_SHIFT                        (16U)                                               /*!< LTC0_CTL.IFS Position                   */
#define LTC_CTL_IFS(x)                           (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< LTC0_CTL.IFS Field                      */
#define LTC_CTL_OFS_MASK                         (0x20000U)                                          /*!< LTC0_CTL.OFS Mask                       */
#define LTC_CTL_OFS_SHIFT                        (17U)                                               /*!< LTC0_CTL.OFS Position                   */
#define LTC_CTL_OFS(x)                           (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< LTC0_CTL.OFS Field                      */
#define LTC_CTL_KIS_MASK                         (0x100000U)                                         /*!< LTC0_CTL.KIS Mask                       */
#define LTC_CTL_KIS_SHIFT                        (20U)                                               /*!< LTC0_CTL.KIS Position                   */
#define LTC_CTL_KIS(x)                           (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< LTC0_CTL.KIS Field                      */
#define LTC_CTL_KOS_MASK                         (0x200000U)                                         /*!< LTC0_CTL.KOS Mask                       */
#define LTC_CTL_KOS_SHIFT                        (21U)                                               /*!< LTC0_CTL.KOS Position                   */
#define LTC_CTL_KOS(x)                           (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< LTC0_CTL.KOS Field                      */
#define LTC_CTL_CIS_MASK                         (0x400000U)                                         /*!< LTC0_CTL.CIS Mask                       */
#define LTC_CTL_CIS_SHIFT                        (22U)                                               /*!< LTC0_CTL.CIS Position                   */
#define LTC_CTL_CIS(x)                           (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< LTC0_CTL.CIS Field                      */
#define LTC_CTL_COS_MASK                         (0x800000U)                                         /*!< LTC0_CTL.COS Mask                       */
#define LTC_CTL_COS_SHIFT                        (23U)                                               /*!< LTC0_CTL.COS Position                   */
#define LTC_CTL_COS(x)                           (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< LTC0_CTL.COS Field                      */
#define LTC_CTL_KAL_MASK                         (0x80000000U)                                       /*!< LTC0_CTL.KAL Mask                       */
#define LTC_CTL_KAL_SHIFT                        (31U)                                               /*!< LTC0_CTL.KAL Position                   */
#define LTC_CTL_KAL(x)                           (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< LTC0_CTL.KAL Field                      */
/* ------- CW Bit Fields                            ------ */
#define LTC_CW_CM_MASK                           (0x1U)                                              /*!< LTC0_CW.CM Mask                         */
#define LTC_CW_CM_SHIFT                          (0U)                                                /*!< LTC0_CW.CM Position                     */
#define LTC_CW_CM(x)                             (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LTC0_CW.CM Field                        */
#define LTC_CW_CDS_MASK                          (0x4U)                                              /*!< LTC0_CW.CDS Mask                        */
#define LTC_CW_CDS_SHIFT                         (2U)                                                /*!< LTC0_CW.CDS Position                    */
#define LTC_CW_CDS(x)                            (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LTC0_CW.CDS Field                       */
#define LTC_CW_CICV_MASK                         (0x8U)                                              /*!< LTC0_CW.CICV Mask                       */
#define LTC_CW_CICV_SHIFT                        (3U)                                                /*!< LTC0_CW.CICV Position                   */
#define LTC_CW_CICV(x)                           (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LTC0_CW.CICV Field                      */
#define LTC_CW_CCR_MASK                          (0x20U)                                             /*!< LTC0_CW.CCR Mask                        */
#define LTC_CW_CCR_SHIFT                         (5U)                                                /*!< LTC0_CW.CCR Position                    */
#define LTC_CW_CCR(x)                            (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< LTC0_CW.CCR Field                       */
#define LTC_CW_CKR_MASK                          (0x40U)                                             /*!< LTC0_CW.CKR Mask                        */
#define LTC_CW_CKR_SHIFT                         (6U)                                                /*!< LTC0_CW.CKR Position                    */
#define LTC_CW_CKR(x)                            (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LTC0_CW.CKR Field                       */
#define LTC_CW_CPKA_MASK                         (0x1000U)                                           /*!< LTC0_CW.CPKA Mask                       */
#define LTC_CW_CPKA_SHIFT                        (12U)                                               /*!< LTC0_CW.CPKA Position                   */
#define LTC_CW_CPKA(x)                           (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< LTC0_CW.CPKA Field                      */
#define LTC_CW_CPKB_MASK                         (0x2000U)                                           /*!< LTC0_CW.CPKB Mask                       */
#define LTC_CW_CPKB_SHIFT                        (13U)                                               /*!< LTC0_CW.CPKB Position                   */
#define LTC_CW_CPKB(x)                           (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< LTC0_CW.CPKB Field                      */
#define LTC_CW_CPKN_MASK                         (0x4000U)                                           /*!< LTC0_CW.CPKN Mask                       */
#define LTC_CW_CPKN_SHIFT                        (14U)                                               /*!< LTC0_CW.CPKN Position                   */
#define LTC_CW_CPKN(x)                           (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< LTC0_CW.CPKN Field                      */
#define LTC_CW_CPKE_MASK                         (0x8000U)                                           /*!< LTC0_CW.CPKE Mask                       */
#define LTC_CW_CPKE_SHIFT                        (15U)                                               /*!< LTC0_CW.CPKE Position                   */
#define LTC_CW_CPKE(x)                           (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< LTC0_CW.CPKE Field                      */
#define LTC_CW_COF_MASK                          (0x40000000U)                                       /*!< LTC0_CW.COF Mask                        */
#define LTC_CW_COF_SHIFT                         (30U)                                               /*!< LTC0_CW.COF Position                    */
#define LTC_CW_COF(x)                            (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< LTC0_CW.COF Field                       */
#define LTC_CW_CIF_MASK                          (0x80000000U)                                       /*!< LTC0_CW.CIF Mask                        */
#define LTC_CW_CIF_SHIFT                         (31U)                                               /*!< LTC0_CW.CIF Position                    */
#define LTC_CW_CIF(x)                            (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< LTC0_CW.CIF Field                       */
/* ------- STA Bit Fields                           ------ */
#define LTC_STA_AB_MASK                          (0x2U)                                              /*!< LTC0_STA.AB Mask                        */
#define LTC_STA_AB_SHIFT                         (1U)                                                /*!< LTC0_STA.AB Position                    */
#define LTC_STA_AB(x)                            (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LTC0_STA.AB Field                       */
#define LTC_STA_DB_MASK                          (0x4U)                                              /*!< LTC0_STA.DB Mask                        */
#define LTC_STA_DB_SHIFT                         (2U)                                                /*!< LTC0_STA.DB Position                    */
#define LTC_STA_DB(x)                            (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LTC0_STA.DB Field                       */
#define LTC_STA_PB_MASK                          (0x40U)                                             /*!< LTC0_STA.PB Mask                        */
#define LTC_STA_PB_SHIFT                         (6U)                                                /*!< LTC0_STA.PB Position                    */
#define LTC_STA_PB(x)                            (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LTC0_STA.PB Field                       */
#define LTC_STA_MB_MASK                          (0x80U)                                             /*!< LTC0_STA.MB Mask                        */
#define LTC_STA_MB_SHIFT                         (7U)                                                /*!< LTC0_STA.MB Position                    */
#define LTC_STA_MB(x)                            (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LTC0_STA.MB Field                       */
#define LTC_STA_DI_MASK                          (0x10000U)                                          /*!< LTC0_STA.DI Mask                        */
#define LTC_STA_DI_SHIFT                         (16U)                                               /*!< LTC0_STA.DI Position                    */
#define LTC_STA_DI(x)                            (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< LTC0_STA.DI Field                       */
#define LTC_STA_EI_MASK                          (0x100000U)                                         /*!< LTC0_STA.EI Mask                        */
#define LTC_STA_EI_SHIFT                         (20U)                                               /*!< LTC0_STA.EI Position                    */
#define LTC_STA_EI(x)                            (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< LTC0_STA.EI Field                       */
#define LTC_STA_DPARRN_MASK                      (0x1000000U)                                        /*!< LTC0_STA.DPARRN Mask                    */
#define LTC_STA_DPARRN_SHIFT                     (24U)                                               /*!< LTC0_STA.DPARRN Position                */
#define LTC_STA_DPARRN(x)                        (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< LTC0_STA.DPARRN Field                   */
#define LTC_STA_PKP_MASK                         (0x10000000U)                                       /*!< LTC0_STA.PKP Mask                       */
#define LTC_STA_PKP_SHIFT                        (28U)                                               /*!< LTC0_STA.PKP Position                   */
#define LTC_STA_PKP(x)                           (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< LTC0_STA.PKP Field                      */
#define LTC_STA_PKO_MASK                         (0x20000000U)                                       /*!< LTC0_STA.PKO Mask                       */
#define LTC_STA_PKO_SHIFT                        (29U)                                               /*!< LTC0_STA.PKO Position                   */
#define LTC_STA_PKO(x)                           (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< LTC0_STA.PKO Field                      */
#define LTC_STA_PKZ_MASK                         (0x40000000U)                                       /*!< LTC0_STA.PKZ Mask                       */
#define LTC_STA_PKZ_SHIFT                        (30U)                                               /*!< LTC0_STA.PKZ Position                   */
#define LTC_STA_PKZ(x)                           (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< LTC0_STA.PKZ Field                      */
/* ------- ESTA Bit Fields                          ------ */
#define LTC_ESTA_ERRID1_MASK                     (0xFU)                                              /*!< LTC0_ESTA.ERRID1 Mask                   */
#define LTC_ESTA_ERRID1_SHIFT                    (0U)                                                /*!< LTC0_ESTA.ERRID1 Position               */
#define LTC_ESTA_ERRID1(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< LTC0_ESTA.ERRID1 Field                  */
#define LTC_ESTA_CL1_MASK                        (0xF00U)                                            /*!< LTC0_ESTA.CL1 Mask                      */
#define LTC_ESTA_CL1_SHIFT                       (8U)                                                /*!< LTC0_ESTA.CL1 Position                  */
#define LTC_ESTA_CL1(x)                          (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< LTC0_ESTA.CL1 Field                     */
/* ------- AADSZ Bit Fields                         ------ */
#define LTC_AADSZ_AADSZ_MASK                     (0xFU)                                              /*!< LTC0_AADSZ.AADSZ Mask                   */
#define LTC_AADSZ_AADSZ_SHIFT                    (0U)                                                /*!< LTC0_AADSZ.AADSZ Position               */
#define LTC_AADSZ_AADSZ(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< LTC0_AADSZ.AADSZ Field                  */
#define LTC_AADSZ_AL_MASK                        (0x80000000U)                                       /*!< LTC0_AADSZ.AL Mask                      */
#define LTC_AADSZ_AL_SHIFT                       (31U)                                               /*!< LTC0_AADSZ.AL Position                  */
#define LTC_AADSZ_AL(x)                          (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< LTC0_AADSZ.AL Field                     */
/* ------- IVSZ Bit Fields                          ------ */
#define LTC_IVSZ_IVSZ_MASK                       (0xFU)                                              /*!< LTC0_IVSZ.IVSZ Mask                     */
#define LTC_IVSZ_IVSZ_SHIFT                      (0U)                                                /*!< LTC0_IVSZ.IVSZ Position                 */
#define LTC_IVSZ_IVSZ(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< LTC0_IVSZ.IVSZ Field                    */
#define LTC_IVSZ_IL_MASK                         (0x80000000U)                                       /*!< LTC0_IVSZ.IL Mask                       */
#define LTC_IVSZ_IL_SHIFT                        (31U)                                               /*!< LTC0_IVSZ.IL Position                   */
#define LTC_IVSZ_IL(x)                           (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< LTC0_IVSZ.IL Field                      */
/* ------- DPAMS Bit Fields                         ------ */
#define LTC_DPAMS_DPAMS_MASK                     (0xFFFFFFFFU)                                       /*!< LTC0_DPAMS.DPAMS Mask                   */
#define LTC_DPAMS_DPAMS_SHIFT                    (0U)                                                /*!< LTC0_DPAMS.DPAMS Position               */
#define LTC_DPAMS_DPAMS(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_DPAMS.DPAMS Field                  */
/* ------- PKASZ Bit Fields                         ------ */
#define LTC_PKASZ_PKASZ_MASK                     (0x1FFU)                                            /*!< LTC0_PKASZ.PKASZ Mask                   */
#define LTC_PKASZ_PKASZ_SHIFT                    (0U)                                                /*!< LTC0_PKASZ.PKASZ Position               */
#define LTC_PKASZ_PKASZ(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFUL)         /*!< LTC0_PKASZ.PKASZ Field                  */
/* ------- PKBSZ Bit Fields                         ------ */
#define LTC_PKBSZ_PKBSZ_MASK                     (0x1FFU)                                            /*!< LTC0_PKBSZ.PKBSZ Mask                   */
#define LTC_PKBSZ_PKBSZ_SHIFT                    (0U)                                                /*!< LTC0_PKBSZ.PKBSZ Position               */
#define LTC_PKBSZ_PKBSZ(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFUL)         /*!< LTC0_PKBSZ.PKBSZ Field                  */
/* ------- PKNSZ Bit Fields                         ------ */
#define LTC_PKNSZ_PKNSZ_MASK                     (0x1FFU)                                            /*!< LTC0_PKNSZ.PKNSZ Mask                   */
#define LTC_PKNSZ_PKNSZ_SHIFT                    (0U)                                                /*!< LTC0_PKNSZ.PKNSZ Position               */
#define LTC_PKNSZ_PKNSZ(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFUL)         /*!< LTC0_PKNSZ.PKNSZ Field                  */
/* ------- PKESZ Bit Fields                         ------ */
#define LTC_PKESZ_PKESZ_MASK                     (0x1FFU)                                            /*!< LTC0_PKESZ.PKESZ Mask                   */
#define LTC_PKESZ_PKESZ_SHIFT                    (0U)                                                /*!< LTC0_PKESZ.PKESZ Position               */
#define LTC_PKESZ_PKESZ(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFUL)         /*!< LTC0_PKESZ.PKESZ Field                  */
/* ------- CTX Bit Fields                           ------ */
#define LTC_CTX_CTX_MASK                         (0xFFFFFFFFU)                                       /*!< LTC0_CTX.CTX Mask                       */
#define LTC_CTX_CTX_SHIFT                        (0U)                                                /*!< LTC0_CTX.CTX Position                   */
#define LTC_CTX_CTX(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_CTX.CTX Field                      */
/* ------- KEY Bit Fields                           ------ */
#define LTC_KEY_KEY_MASK                         (0xFFFFFFFFU)                                       /*!< LTC0_KEY.KEY Mask                       */
#define LTC_KEY_KEY_SHIFT                        (0U)                                                /*!< LTC0_KEY.KEY Position                   */
#define LTC_KEY_KEY(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_KEY.KEY Field                      */
/* ------- VID1 Bit Fields                          ------ */
#define LTC_VID1_MIN_REV_MASK                    (0xFFU)                                             /*!< LTC0_VID1.MIN_REV Mask                  */
#define LTC_VID1_MIN_REV_SHIFT                   (0U)                                                /*!< LTC0_VID1.MIN_REV Position              */
#define LTC_VID1_MIN_REV(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LTC0_VID1.MIN_REV Field                 */
#define LTC_VID1_MAJ_REV_MASK                    (0xFF00U)                                           /*!< LTC0_VID1.MAJ_REV Mask                  */
#define LTC_VID1_MAJ_REV_SHIFT                   (8U)                                                /*!< LTC0_VID1.MAJ_REV Position              */
#define LTC_VID1_MAJ_REV(x)                      (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< LTC0_VID1.MAJ_REV Field                 */
#define LTC_VID1_IP_ID_MASK                      (0xFFFF0000U)                                       /*!< LTC0_VID1.IP_ID Mask                    */
#define LTC_VID1_IP_ID_SHIFT                     (16U)                                               /*!< LTC0_VID1.IP_ID Position                */
#define LTC_VID1_IP_ID(x)                        (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< LTC0_VID1.IP_ID Field                   */
/* ------- VID2 Bit Fields                          ------ */
#define LTC_VID2_ECO_REV_MASK                    (0xFFU)                                             /*!< LTC0_VID2.ECO_REV Mask                  */
#define LTC_VID2_ECO_REV_SHIFT                   (0U)                                                /*!< LTC0_VID2.ECO_REV Position              */
#define LTC_VID2_ECO_REV(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< LTC0_VID2.ECO_REV Field                 */
#define LTC_VID2_ARCH_ERA_MASK                   (0xFF00U)                                           /*!< LTC0_VID2.ARCH_ERA Mask                 */
#define LTC_VID2_ARCH_ERA_SHIFT                  (8U)                                                /*!< LTC0_VID2.ARCH_ERA Position             */
#define LTC_VID2_ARCH_ERA(x)                     (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< LTC0_VID2.ARCH_ERA Field                */
/* ------- CHAVID Bit Fields                        ------ */
#define LTC_CHAVID_AESREV_MASK                   (0xFU)                                              /*!< LTC0_CHAVID.AESREV Mask                 */
#define LTC_CHAVID_AESREV_SHIFT                  (0U)                                                /*!< LTC0_CHAVID.AESREV Position             */
#define LTC_CHAVID_AESREV(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< LTC0_CHAVID.AESREV Field                */
#define LTC_CHAVID_AESVID_MASK                   (0xF0U)                                             /*!< LTC0_CHAVID.AESVID Mask                 */
#define LTC_CHAVID_AESVID_SHIFT                  (4U)                                                /*!< LTC0_CHAVID.AESVID Position             */
#define LTC_CHAVID_AESVID(x)                     (((uint32_t)(((uint32_t)(x))<<4U))&0xF0UL)          /*!< LTC0_CHAVID.AESVID Field                */
#define LTC_CHAVID_DESREV_MASK                   (0xF00U)                                            /*!< LTC0_CHAVID.DESREV Mask                 */
#define LTC_CHAVID_DESREV_SHIFT                  (8U)                                                /*!< LTC0_CHAVID.DESREV Position             */
#define LTC_CHAVID_DESREV(x)                     (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< LTC0_CHAVID.DESREV Field                */
#define LTC_CHAVID_DESVID_MASK                   (0xF000U)                                           /*!< LTC0_CHAVID.DESVID Mask                 */
#define LTC_CHAVID_DESVID_SHIFT                  (12U)                                               /*!< LTC0_CHAVID.DESVID Position             */
#define LTC_CHAVID_DESVID(x)                     (((uint32_t)(((uint32_t)(x))<<12U))&0xF000UL)       /*!< LTC0_CHAVID.DESVID Field                */
#define LTC_CHAVID_PKHAREV_MASK                  (0xF0000U)                                          /*!< LTC0_CHAVID.PKHAREV Mask                */
#define LTC_CHAVID_PKHAREV_SHIFT                 (16U)                                               /*!< LTC0_CHAVID.PKHAREV Position            */
#define LTC_CHAVID_PKHAREV(x)                    (((uint32_t)(((uint32_t)(x))<<16U))&0xF0000UL)      /*!< LTC0_CHAVID.PKHAREV Field               */
#define LTC_CHAVID_PKHAVID_MASK                  (0xF00000U)                                         /*!< LTC0_CHAVID.PKHAVID Mask                */
#define LTC_CHAVID_PKHAVID_SHIFT                 (20U)                                               /*!< LTC0_CHAVID.PKHAVID Position            */
#define LTC_CHAVID_PKHAVID(x)                    (((uint32_t)(((uint32_t)(x))<<20U))&0xF00000UL)     /*!< LTC0_CHAVID.PKHAVID Field               */
#define LTC_CHAVID_MDHAREV_MASK                  (0xF000000U)                                        /*!< LTC0_CHAVID.MDHAREV Mask                */
#define LTC_CHAVID_MDHAREV_SHIFT                 (24U)                                               /*!< LTC0_CHAVID.MDHAREV Position            */
#define LTC_CHAVID_MDHAREV(x)                    (((uint32_t)(((uint32_t)(x))<<24U))&0xF000000UL)    /*!< LTC0_CHAVID.MDHAREV Field               */
#define LTC_CHAVID_MDHAVID_MASK                  (0xF0000000U)                                       /*!< LTC0_CHAVID.MDHAVID Mask                */
#define LTC_CHAVID_MDHAVID_SHIFT                 (28U)                                               /*!< LTC0_CHAVID.MDHAVID Position            */
#define LTC_CHAVID_MDHAVID(x)                    (((uint32_t)(((uint32_t)(x))<<28U))&0xF0000000UL)   /*!< LTC0_CHAVID.MDHAVID Field               */
/* ------- FIFOSTA Bit Fields                       ------ */
#define LTC_FIFOSTA_IFL_MASK                     (0x7FU)                                             /*!< LTC0_FIFOSTA.IFL Mask                   */
#define LTC_FIFOSTA_IFL_SHIFT                    (0U)                                                /*!< LTC0_FIFOSTA.IFL Position               */
#define LTC_FIFOSTA_IFL(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x7FUL)          /*!< LTC0_FIFOSTA.IFL Field                  */
#define LTC_FIFOSTA_IFF_MASK                     (0x8000U)                                           /*!< LTC0_FIFOSTA.IFF Mask                   */
#define LTC_FIFOSTA_IFF_SHIFT                    (15U)                                               /*!< LTC0_FIFOSTA.IFF Position               */
#define LTC_FIFOSTA_IFF(x)                       (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< LTC0_FIFOSTA.IFF Field                  */
#define LTC_FIFOSTA_OFL_MASK                     (0x7F0000U)                                         /*!< LTC0_FIFOSTA.OFL Mask                   */
#define LTC_FIFOSTA_OFL_SHIFT                    (16U)                                               /*!< LTC0_FIFOSTA.OFL Position               */
#define LTC_FIFOSTA_OFL(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0x7F0000UL)     /*!< LTC0_FIFOSTA.OFL Field                  */
#define LTC_FIFOSTA_OFF_MASK                     (0x80000000U)                                       /*!< LTC0_FIFOSTA.OFF Mask                   */
#define LTC_FIFOSTA_OFF_SHIFT                    (31U)                                               /*!< LTC0_FIFOSTA.OFF Position               */
#define LTC_FIFOSTA_OFF(x)                       (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< LTC0_FIFOSTA.OFF Field                  */
/* ------- IFIFO Bit Fields                         ------ */
#define LTC_IFIFO_IFIFO_MASK                     (0xFFFFFFFFU)                                       /*!< LTC0_IFIFO.IFIFO Mask                   */
#define LTC_IFIFO_IFIFO_SHIFT                    (0U)                                                /*!< LTC0_IFIFO.IFIFO Position               */
#define LTC_IFIFO_IFIFO(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_IFIFO.IFIFO Field                  */
/* ------- OFIFO Bit Fields                         ------ */
#define LTC_OFIFO_OFIFO_MASK                     (0xFFFFFFFFU)                                       /*!< LTC0_OFIFO.OFIFO Mask                   */
#define LTC_OFIFO_OFIFO_SHIFT                    (0U)                                                /*!< LTC0_OFIFO.OFIFO Position               */
#define LTC_OFIFO_OFIFO(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_OFIFO.OFIFO Field                  */
/* ------- PKA Bit Fields                           ------ */
/* ------- PKA0 Bit Fields                          ------ */
#define LTC_PKA0_PKHA_A0_MASK                    (0xFFFFFFFFU)                                       /*!< LTC0_PKA0.PKHA_A0 Mask                  */
#define LTC_PKA0_PKHA_A0_SHIFT                   (0U)                                                /*!< LTC0_PKA0.PKHA_A0 Position              */
#define LTC_PKA0_PKHA_A0(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_PKA0.PKHA_A0 Field                 */
/* ------- PKA1 Bit Fields                          ------ */
#define LTC_PKA1_PKHA_A1_MASK                    (0xFFFFFFFFU)                                       /*!< LTC0_PKA1.PKHA_A1 Mask                  */
#define LTC_PKA1_PKHA_A1_SHIFT                   (0U)                                                /*!< LTC0_PKA1.PKHA_A1 Position              */
#define LTC_PKA1_PKHA_A1(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_PKA1.PKHA_A1 Field                 */
/* ------- PKA2 Bit Fields                          ------ */
#define LTC_PKA2_PKHA_A2_MASK                    (0xFFFFFFFFU)                                       /*!< LTC0_PKA2.PKHA_A2 Mask                  */
#define LTC_PKA2_PKHA_A2_SHIFT                   (0U)                                                /*!< LTC0_PKA2.PKHA_A2 Position              */
#define LTC_PKA2_PKHA_A2(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_PKA2.PKHA_A2 Field                 */
/* ------- PKA3 Bit Fields                          ------ */
#define LTC_PKA3_PKHA_A3_MASK                    (0xFFFFFFFFU)                                       /*!< LTC0_PKA3.PKHA_A3 Mask                  */
#define LTC_PKA3_PKHA_A3_SHIFT                   (0U)                                                /*!< LTC0_PKA3.PKHA_A3 Position              */
#define LTC_PKA3_PKHA_A3(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_PKA3.PKHA_A3 Field                 */
/* ------- PKB Bit Fields                           ------ */
/* ------- PKB0 Bit Fields                          ------ */
#define LTC_PKB0_PKHA_B0_MASK                    (0xFFFFFFFFU)                                       /*!< LTC0_PKB0.PKHA_B0 Mask                  */
#define LTC_PKB0_PKHA_B0_SHIFT                   (0U)                                                /*!< LTC0_PKB0.PKHA_B0 Position              */
#define LTC_PKB0_PKHA_B0(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_PKB0.PKHA_B0 Field                 */
/* ------- PKB1 Bit Fields                          ------ */
#define LTC_PKB1_PKHA_B1_MASK                    (0xFFFFFFFFU)                                       /*!< LTC0_PKB1.PKHA_B1 Mask                  */
#define LTC_PKB1_PKHA_B1_SHIFT                   (0U)                                                /*!< LTC0_PKB1.PKHA_B1 Position              */
#define LTC_PKB1_PKHA_B1(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_PKB1.PKHA_B1 Field                 */
/* ------- PKB2 Bit Fields                          ------ */
#define LTC_PKB2_PKHA_B2_MASK                    (0xFFFFFFFFU)                                       /*!< LTC0_PKB2.PKHA_B2 Mask                  */
#define LTC_PKB2_PKHA_B2_SHIFT                   (0U)                                                /*!< LTC0_PKB2.PKHA_B2 Position              */
#define LTC_PKB2_PKHA_B2(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_PKB2.PKHA_B2 Field                 */
/* ------- PKB3 Bit Fields                          ------ */
#define LTC_PKB3_PKHA_B3_MASK                    (0xFFFFFFFFU)                                       /*!< LTC0_PKB3.PKHA_B3 Mask                  */
#define LTC_PKB3_PKHA_B3_SHIFT                   (0U)                                                /*!< LTC0_PKB3.PKHA_B3 Position              */
#define LTC_PKB3_PKHA_B3(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_PKB3.PKHA_B3 Field                 */
/* ------- PKN Bit Fields                           ------ */
/* ------- PKN0 Bit Fields                          ------ */
#define LTC_PKN0_PKHA_N0_MASK                    (0xFFFFFFFFU)                                       /*!< LTC0_PKN0.PKHA_N0 Mask                  */
#define LTC_PKN0_PKHA_N0_SHIFT                   (0U)                                                /*!< LTC0_PKN0.PKHA_N0 Position              */
#define LTC_PKN0_PKHA_N0(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_PKN0.PKHA_N0 Field                 */
/* ------- PKN1 Bit Fields                          ------ */
#define LTC_PKN1_PKHA_N1_MASK                    (0xFFFFFFFFU)                                       /*!< LTC0_PKN1.PKHA_N1 Mask                  */
#define LTC_PKN1_PKHA_N1_SHIFT                   (0U)                                                /*!< LTC0_PKN1.PKHA_N1 Position              */
#define LTC_PKN1_PKHA_N1(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_PKN1.PKHA_N1 Field                 */
/* ------- PKN2 Bit Fields                          ------ */
#define LTC_PKN2_PKHA_N2_MASK                    (0xFFFFFFFFU)                                       /*!< LTC0_PKN2.PKHA_N2 Mask                  */
#define LTC_PKN2_PKHA_N2_SHIFT                   (0U)                                                /*!< LTC0_PKN2.PKHA_N2 Position              */
#define LTC_PKN2_PKHA_N2(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_PKN2.PKHA_N2 Field                 */
/* ------- PKN3 Bit Fields                          ------ */
#define LTC_PKN3_PKHA_N3_MASK                    (0xFFFFFFFFU)                                       /*!< LTC0_PKN3.PKHA_N3 Mask                  */
#define LTC_PKN3_PKHA_N3_SHIFT                   (0U)                                                /*!< LTC0_PKN3.PKHA_N3 Position              */
#define LTC_PKN3_PKHA_N3(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_PKN3.PKHA_N3 Field                 */
/* ------- PKE Bit Fields                           ------ */
/* ------- PKE0 Bit Fields                          ------ */
#define LTC_PKE0_PKHA_E0_MASK                    (0xFFFFFFFFU)                                       /*!< LTC0_PKE0.PKHA_E0 Mask                  */
#define LTC_PKE0_PKHA_E0_SHIFT                   (0U)                                                /*!< LTC0_PKE0.PKHA_E0 Position              */
#define LTC_PKE0_PKHA_E0(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_PKE0.PKHA_E0 Field                 */
/* ------- PKE1 Bit Fields                          ------ */
#define LTC_PKE1_PKHA_E1_MASK                    (0xFFFFFFFFU)                                       /*!< LTC0_PKE1.PKHA_E1 Mask                  */
#define LTC_PKE1_PKHA_E1_SHIFT                   (0U)                                                /*!< LTC0_PKE1.PKHA_E1 Position              */
#define LTC_PKE1_PKHA_E1(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_PKE1.PKHA_E1 Field                 */
/* ------- PKE2 Bit Fields                          ------ */
#define LTC_PKE2_PKHA_E2_MASK                    (0xFFFFFFFFU)                                       /*!< LTC0_PKE2.PKHA_E2 Mask                  */
#define LTC_PKE2_PKHA_E2_SHIFT                   (0U)                                                /*!< LTC0_PKE2.PKHA_E2 Position              */
#define LTC_PKE2_PKHA_E2(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_PKE2.PKHA_E2 Field                 */
/* ------- PKE3 Bit Fields                          ------ */
#define LTC_PKE3_PKHA_E3_MASK                    (0xFFFFFFFFU)                                       /*!< LTC0_PKE3.PKHA_E3 Mask                  */
#define LTC_PKE3_PKHA_E3_SHIFT                   (0U)                                                /*!< LTC0_PKE3.PKHA_E3 Position              */
#define LTC_PKE3_PKHA_E3(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< LTC0_PKE3.PKHA_E3 Field                 */
/**
 * @} */ /* End group LTC_Register_Masks_GROUP 
 */

/* LTC0 - Peripheral instance base addresses */
#define LTC0_BasePtr                   0x40051000UL //!< Peripheral base address
#define LTC0                           ((LTC_Type *) LTC0_BasePtr) //!< Freescale base pointer
#define LTC0_BASE_PTR                  (LTC0) //!< Freescale style base pointer
/**
 * @} */ /* End group LTC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MCG_Peripheral_access_layer_GROUP MCG Peripheral Access Layer
* @brief C Struct for MCG
* @{
*/

/* ================================================================================ */
/* ================           MCG (file:MCG_MKL82Z7)               ================ */
/* ================================================================================ */

/**
 * @brief Multipurpose Clock Generator module
 */
/**
* @addtogroup MCG_structs_GROUP MCG struct
* @brief Struct for MCG
* @{
*/
typedef struct {                                /*       MCG Structure                                                */
   __IO uint8_t   C1;                           /**< 0000: MCG Control 1 Register                                       */
   __IO uint8_t   C2;                           /**< 0001: MCG Control 2 Register                                       */
   __IO uint8_t   C3;                           /**< 0002: MCG Control 3 Register                                       */
   __IO uint8_t   C4;                           /**< 0003: MCG Control 4 Register                                       */
   __IO uint8_t   C5;                           /**< 0004: MCG Control 5 Register                                       */
   __IO uint8_t   C6;                           /**< 0005: MCG Control 6 Register                                       */
   __IO uint8_t   S;                            /**< 0006: MCG Status Register                                          */
        uint8_t   RESERVED_0;                  
   __IO uint8_t   SC;                           /**< 0008: MCG Status and Control Register                              */
        uint8_t   RESERVED_1;                  
   __IO uint8_t   ATCVH;                        /**< 000A: MCG Auto Trim Compare Value High Register                    */
   __IO uint8_t   ATCVL;                        /**< 000B: MCG Auto Trim Compare Value Low Register                     */
   __IO uint8_t   C7;                           /**< 000C: MCG Control 7 Register                                       */
   __IO uint8_t   C8;                           /**< 000D: MCG Control 8 Register                                       */
} MCG_Type;

/**
 * @} */ /* End group MCG_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MCG' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MCG_Register_Masks_GROUP MCG Register Masks
* @brief Register Masks for MCG
* @{
*/
/* ------- C1 Bit Fields                            ------ */
#define MCG_C1_IREFSTEN_MASK                     (0x1U)                                              /*!< MCG_C1.IREFSTEN Mask                    */
#define MCG_C1_IREFSTEN_SHIFT                    (0U)                                                /*!< MCG_C1.IREFSTEN Position                */
#define MCG_C1_IREFSTEN(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< MCG_C1.IREFSTEN Field                   */
#define MCG_C1_IRCLKEN_MASK                      (0x2U)                                              /*!< MCG_C1.IRCLKEN Mask                     */
#define MCG_C1_IRCLKEN_SHIFT                     (1U)                                                /*!< MCG_C1.IRCLKEN Position                 */
#define MCG_C1_IRCLKEN(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< MCG_C1.IRCLKEN Field                    */
#define MCG_C1_IREFS_MASK                        (0x4U)                                              /*!< MCG_C1.IREFS Mask                       */
#define MCG_C1_IREFS_SHIFT                       (2U)                                                /*!< MCG_C1.IREFS Position                   */
#define MCG_C1_IREFS(x)                          (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< MCG_C1.IREFS Field                      */
#define MCG_C1_FRDIV_MASK                        (0x38U)                                             /*!< MCG_C1.FRDIV Mask                       */
#define MCG_C1_FRDIV_SHIFT                       (3U)                                                /*!< MCG_C1.FRDIV Position                   */
#define MCG_C1_FRDIV(x)                          (((uint8_t)(((uint8_t)(x))<<3U))&0x38UL)            /*!< MCG_C1.FRDIV Field                      */
#define MCG_C1_CLKS_MASK                         (0xC0U)                                             /*!< MCG_C1.CLKS Mask                        */
#define MCG_C1_CLKS_SHIFT                        (6U)                                                /*!< MCG_C1.CLKS Position                    */
#define MCG_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< MCG_C1.CLKS Field                       */
/* ------- C2 Bit Fields                            ------ */
#define MCG_C2_IRCS_MASK                         (0x1U)                                              /*!< MCG_C2.IRCS Mask                        */
#define MCG_C2_IRCS_SHIFT                        (0U)                                                /*!< MCG_C2.IRCS Position                    */
#define MCG_C2_IRCS(x)                           (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< MCG_C2.IRCS Field                       */
#define MCG_C2_LP_MASK                           (0x2U)                                              /*!< MCG_C2.LP Mask                          */
#define MCG_C2_LP_SHIFT                          (1U)                                                /*!< MCG_C2.LP Position                      */
#define MCG_C2_LP(x)                             (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< MCG_C2.LP Field                         */
#define MCG_C2_EREFS_MASK                        (0x4U)                                              /*!< MCG_C2.EREFS Mask                       */
#define MCG_C2_EREFS_SHIFT                       (2U)                                                /*!< MCG_C2.EREFS Position                   */
#define MCG_C2_EREFS(x)                          (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< MCG_C2.EREFS Field                      */
#define MCG_C2_HGO_MASK                          (0x8U)                                              /*!< MCG_C2.HGO Mask                         */
#define MCG_C2_HGO_SHIFT                         (3U)                                                /*!< MCG_C2.HGO Position                     */
#define MCG_C2_HGO(x)                            (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< MCG_C2.HGO Field                        */
#define MCG_C2_RANGE_MASK                        (0x30U)                                             /*!< MCG_C2.RANGE Mask                       */
#define MCG_C2_RANGE_SHIFT                       (4U)                                                /*!< MCG_C2.RANGE Position                   */
#define MCG_C2_RANGE(x)                          (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< MCG_C2.RANGE Field                      */
#define MCG_C2_FCFTRIM_MASK                      (0x40U)                                             /*!< MCG_C2.FCFTRIM Mask                     */
#define MCG_C2_FCFTRIM_SHIFT                     (6U)                                                /*!< MCG_C2.FCFTRIM Position                 */
#define MCG_C2_FCFTRIM(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< MCG_C2.FCFTRIM Field                    */
#define MCG_C2_LOCRE0_MASK                       (0x80U)                                             /*!< MCG_C2.LOCRE0 Mask                      */
#define MCG_C2_LOCRE0_SHIFT                      (7U)                                                /*!< MCG_C2.LOCRE0 Position                  */
#define MCG_C2_LOCRE0(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< MCG_C2.LOCRE0 Field                     */
/* ------- C3 Bit Fields                            ------ */
#define MCG_C3_SCTRIM_MASK                       (0xFFU)                                             /*!< MCG_C3.SCTRIM Mask                      */
#define MCG_C3_SCTRIM_SHIFT                      (0U)                                                /*!< MCG_C3.SCTRIM Position                  */
#define MCG_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< MCG_C3.SCTRIM Field                     */
/* ------- C4 Bit Fields                            ------ */
#define MCG_C4_SCFTRIM_MASK                      (0x1U)                                              /*!< MCG_C4.SCFTRIM Mask                     */
#define MCG_C4_SCFTRIM_SHIFT                     (0U)                                                /*!< MCG_C4.SCFTRIM Position                 */
#define MCG_C4_SCFTRIM(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< MCG_C4.SCFTRIM Field                    */
#define MCG_C4_FCTRIM_MASK                       (0x1EU)                                             /*!< MCG_C4.FCTRIM Mask                      */
#define MCG_C4_FCTRIM_SHIFT                      (1U)                                                /*!< MCG_C4.FCTRIM Position                  */
#define MCG_C4_FCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0x1EUL)            /*!< MCG_C4.FCTRIM Field                     */
#define MCG_C4_DRST_DRS_MASK                     (0x60U)                                             /*!< MCG_C4.DRST_DRS Mask                    */
#define MCG_C4_DRST_DRS_SHIFT                    (5U)                                                /*!< MCG_C4.DRST_DRS Position                */
#define MCG_C4_DRST_DRS(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x60UL)            /*!< MCG_C4.DRST_DRS Field                   */
#define MCG_C4_DMX32_MASK                        (0x80U)                                             /*!< MCG_C4.DMX32 Mask                       */
#define MCG_C4_DMX32_SHIFT                       (7U)                                                /*!< MCG_C4.DMX32 Position                   */
#define MCG_C4_DMX32(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< MCG_C4.DMX32 Field                      */
/* ------- C5 Bit Fields                            ------ */
#define MCG_C5_PRDIV_MASK                        (0x7U)                                              /*!< MCG_C5.PRDIV Mask                       */
#define MCG_C5_PRDIV_SHIFT                       (0U)                                                /*!< MCG_C5.PRDIV Position                   */
#define MCG_C5_PRDIV(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< MCG_C5.PRDIV Field                      */
#define MCG_C5_PLLSTEN_MASK                      (0x20U)                                             /*!< MCG_C5.PLLSTEN Mask                     */
#define MCG_C5_PLLSTEN_SHIFT                     (5U)                                                /*!< MCG_C5.PLLSTEN Position                 */
#define MCG_C5_PLLSTEN(x)                        (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< MCG_C5.PLLSTEN Field                    */
#define MCG_C5_PLLCLKEN_MASK                     (0x40U)                                             /*!< MCG_C5.PLLCLKEN Mask                    */
#define MCG_C5_PLLCLKEN_SHIFT                    (6U)                                                /*!< MCG_C5.PLLCLKEN Position                */
#define MCG_C5_PLLCLKEN(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< MCG_C5.PLLCLKEN Field                   */
/* ------- C6 Bit Fields                            ------ */
#define MCG_C6_VDIV_MASK                         (0x1FU)                                             /*!< MCG_C6.VDIV Mask                        */
#define MCG_C6_VDIV_SHIFT                        (0U)                                                /*!< MCG_C6.VDIV Position                    */
#define MCG_C6_VDIV(x)                           (((uint8_t)(((uint8_t)(x))<<0U))&0x1FUL)            /*!< MCG_C6.VDIV Field                       */
#define MCG_C6_CME0_MASK                         (0x20U)                                             /*!< MCG_C6.CME0 Mask                        */
#define MCG_C6_CME0_SHIFT                        (5U)                                                /*!< MCG_C6.CME0 Position                    */
#define MCG_C6_CME0(x)                           (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< MCG_C6.CME0 Field                       */
#define MCG_C6_PLLS_MASK                         (0x40U)                                             /*!< MCG_C6.PLLS Mask                        */
#define MCG_C6_PLLS_SHIFT                        (6U)                                                /*!< MCG_C6.PLLS Position                    */
#define MCG_C6_PLLS(x)                           (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< MCG_C6.PLLS Field                       */
#define MCG_C6_LOLIE0_MASK                       (0x80U)                                             /*!< MCG_C6.LOLIE0 Mask                      */
#define MCG_C6_LOLIE0_SHIFT                      (7U)                                                /*!< MCG_C6.LOLIE0 Position                  */
#define MCG_C6_LOLIE0(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< MCG_C6.LOLIE0 Field                     */
/* ------- S Bit Fields                             ------ */
#define MCG_S_IRCST_MASK                         (0x1U)                                              /*!< MCG_S.IRCST Mask                        */
#define MCG_S_IRCST_SHIFT                        (0U)                                                /*!< MCG_S.IRCST Position                    */
#define MCG_S_IRCST(x)                           (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< MCG_S.IRCST Field                       */
#define MCG_S_OSCINIT0_MASK                      (0x2U)                                              /*!< MCG_S.OSCINIT0 Mask                     */
#define MCG_S_OSCINIT0_SHIFT                     (1U)                                                /*!< MCG_S.OSCINIT0 Position                 */
#define MCG_S_OSCINIT0(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< MCG_S.OSCINIT0 Field                    */
#define MCG_S_CLKST_MASK                         (0xCU)                                              /*!< MCG_S.CLKST Mask                        */
#define MCG_S_CLKST_SHIFT                        (2U)                                                /*!< MCG_S.CLKST Position                    */
#define MCG_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< MCG_S.CLKST Field                       */
#define MCG_S_IREFST_MASK                        (0x10U)                                             /*!< MCG_S.IREFST Mask                       */
#define MCG_S_IREFST_SHIFT                       (4U)                                                /*!< MCG_S.IREFST Position                   */
#define MCG_S_IREFST(x)                          (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< MCG_S.IREFST Field                      */
#define MCG_S_PLLST_MASK                         (0x20U)                                             /*!< MCG_S.PLLST Mask                        */
#define MCG_S_PLLST_SHIFT                        (5U)                                                /*!< MCG_S.PLLST Position                    */
#define MCG_S_PLLST(x)                           (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< MCG_S.PLLST Field                       */
#define MCG_S_LOCK0_MASK                         (0x40U)                                             /*!< MCG_S.LOCK0 Mask                        */
#define MCG_S_LOCK0_SHIFT                        (6U)                                                /*!< MCG_S.LOCK0 Position                    */
#define MCG_S_LOCK0(x)                           (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< MCG_S.LOCK0 Field                       */
#define MCG_S_LOLS0_MASK                         (0x80U)                                             /*!< MCG_S.LOLS0 Mask                        */
#define MCG_S_LOLS0_SHIFT                        (7U)                                                /*!< MCG_S.LOLS0 Position                    */
#define MCG_S_LOLS0(x)                           (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< MCG_S.LOLS0 Field                       */
/* ------- SC Bit Fields                            ------ */
#define MCG_SC_LOCS0_MASK                        (0x1U)                                              /*!< MCG_SC.LOCS0 Mask                       */
#define MCG_SC_LOCS0_SHIFT                       (0U)                                                /*!< MCG_SC.LOCS0 Position                   */
#define MCG_SC_LOCS0(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< MCG_SC.LOCS0 Field                      */
#define MCG_SC_FCRDIV_MASK                       (0xEU)                                              /*!< MCG_SC.FCRDIV Mask                      */
#define MCG_SC_FCRDIV_SHIFT                      (1U)                                                /*!< MCG_SC.FCRDIV Position                  */
#define MCG_SC_FCRDIV(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0xEUL)             /*!< MCG_SC.FCRDIV Field                     */
#define MCG_SC_FLTPRSRV_MASK                     (0x10U)                                             /*!< MCG_SC.FLTPRSRV Mask                    */
#define MCG_SC_FLTPRSRV_SHIFT                    (4U)                                                /*!< MCG_SC.FLTPRSRV Position                */
#define MCG_SC_FLTPRSRV(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< MCG_SC.FLTPRSRV Field                   */
#define MCG_SC_ATMF_MASK                         (0x20U)                                             /*!< MCG_SC.ATMF Mask                        */
#define MCG_SC_ATMF_SHIFT                        (5U)                                                /*!< MCG_SC.ATMF Position                    */
#define MCG_SC_ATMF(x)                           (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< MCG_SC.ATMF Field                       */
#define MCG_SC_ATMS_MASK                         (0x40U)                                             /*!< MCG_SC.ATMS Mask                        */
#define MCG_SC_ATMS_SHIFT                        (6U)                                                /*!< MCG_SC.ATMS Position                    */
#define MCG_SC_ATMS(x)                           (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< MCG_SC.ATMS Field                       */
#define MCG_SC_ATME_MASK                         (0x80U)                                             /*!< MCG_SC.ATME Mask                        */
#define MCG_SC_ATME_SHIFT                        (7U)                                                /*!< MCG_SC.ATME Position                    */
#define MCG_SC_ATME(x)                           (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< MCG_SC.ATME Field                       */
/* ------- ATCVH Bit Fields                         ------ */
#define MCG_ATCVH_ATCVH_MASK                     (0xFFU)                                             /*!< MCG_ATCVH.ATCVH Mask                    */
#define MCG_ATCVH_ATCVH_SHIFT                    (0U)                                                /*!< MCG_ATCVH.ATCVH Position                */
#define MCG_ATCVH_ATCVH(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< MCG_ATCVH.ATCVH Field                   */
/* ------- ATCVL Bit Fields                         ------ */
#define MCG_ATCVL_ATCVL_MASK                     (0xFFU)                                             /*!< MCG_ATCVL.ATCVL Mask                    */
#define MCG_ATCVL_ATCVL_SHIFT                    (0U)                                                /*!< MCG_ATCVL.ATCVL Position                */
#define MCG_ATCVL_ATCVL(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< MCG_ATCVL.ATCVL Field                   */
/* ------- C7 Bit Fields                            ------ */
#define MCG_C7_OSCSEL_MASK                       (0x3U)                                              /*!< MCG_C7.OSCSEL Mask                      */
#define MCG_C7_OSCSEL_SHIFT                      (0U)                                                /*!< MCG_C7.OSCSEL Position                  */
#define MCG_C7_OSCSEL(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< MCG_C7.OSCSEL Field                     */
/* ------- C8 Bit Fields                            ------ */
#define MCG_C8_LOCS1_MASK                        (0x1U)                                              /*!< MCG_C8.LOCS1 Mask                       */
#define MCG_C8_LOCS1_SHIFT                       (0U)                                                /*!< MCG_C8.LOCS1 Position                   */
#define MCG_C8_LOCS1(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< MCG_C8.LOCS1 Field                      */
#define MCG_C8_CME1_MASK                         (0x20U)                                             /*!< MCG_C8.CME1 Mask                        */
#define MCG_C8_CME1_SHIFT                        (5U)                                                /*!< MCG_C8.CME1 Position                    */
#define MCG_C8_CME1(x)                           (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< MCG_C8.CME1 Field                       */
#define MCG_C8_LOLRE_MASK                        (0x40U)                                             /*!< MCG_C8.LOLRE Mask                       */
#define MCG_C8_LOLRE_SHIFT                       (6U)                                                /*!< MCG_C8.LOLRE Position                   */
#define MCG_C8_LOLRE(x)                          (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< MCG_C8.LOLRE Field                      */
#define MCG_C8_LOCRE1_MASK                       (0x80U)                                             /*!< MCG_C8.LOCRE1 Mask                      */
#define MCG_C8_LOCRE1_SHIFT                      (7U)                                                /*!< MCG_C8.LOCRE1 Position                  */
#define MCG_C8_LOCRE1(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< MCG_C8.LOCRE1 Field                     */
/**
 * @} */ /* End group MCG_Register_Masks_GROUP 
 */

/* MCG - Peripheral instance base addresses */
#define MCG_BasePtr                    0x40064000UL //!< Peripheral base address
#define MCG                            ((MCG_Type *) MCG_BasePtr) //!< Freescale base pointer
#define MCG_BASE_PTR                   (MCG) //!< Freescale style base pointer
/**
 * @} */ /* End group MCG_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MCM_Peripheral_access_layer_GROUP MCM Peripheral Access Layer
* @brief C Struct for MCM
* @{
*/

/* ================================================================================ */
/* ================           MCM (file:MCM_MKL82Z7)               ================ */
/* ================================================================================ */

/**
 * @brief Core Platform Miscellaneous Control Module
 */
/**
* @addtogroup MCM_structs_GROUP MCM struct
* @brief Struct for MCM
* @{
*/
typedef struct {                                /*       MCM Structure                                                */
        uint8_t   RESERVED_0[8];               
   __I  uint16_t  PLASC;                        /**< 0008: Crossbar Switch (AXBS) Slave Configuration                   */
   __I  uint16_t  PLAMC;                        /**< 000A: Crossbar Switch (AXBS) Master Configuration                  */
   __IO uint32_t  PLACR;                        /**< 000C: Platform Control Register                                    */
        uint8_t   RESERVED_1[48];              
   __IO uint32_t  CPO;                          /**< 0040: Compute Operation Control Register                           */
} MCM_Type;

/**
 * @} */ /* End group MCM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MCM_Register_Masks_GROUP MCM Register Masks
* @brief Register Masks for MCM
* @{
*/
/* ------- PLASC Bit Fields                         ------ */
#define MCM_PLASC_ASC_MASK                       (0xFFU)                                             /*!< MCM_PLASC.ASC Mask                      */
#define MCM_PLASC_ASC_SHIFT                      (0U)                                                /*!< MCM_PLASC.ASC Position                  */
#define MCM_PLASC_ASC(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0xFFUL)          /*!< MCM_PLASC.ASC Field                     */
/* ------- PLAMC Bit Fields                         ------ */
#define MCM_PLAMC_AMC_MASK                       (0xFFU)                                             /*!< MCM_PLAMC.AMC Mask                      */
#define MCM_PLAMC_AMC_SHIFT                      (0U)                                                /*!< MCM_PLAMC.AMC Position                  */
#define MCM_PLAMC_AMC(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0xFFUL)          /*!< MCM_PLAMC.AMC Field                     */
/* ------- PLACR Bit Fields                         ------ */
#define MCM_PLACR_ARB_MASK                       (0x200U)                                            /*!< MCM_PLACR.ARB Mask                      */
#define MCM_PLACR_ARB_SHIFT                      (9U)                                                /*!< MCM_PLACR.ARB Position                  */
#define MCM_PLACR_ARB(x)                         (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< MCM_PLACR.ARB Field                     */
#define MCM_PLACR_CFCC_MASK                      (0x400U)                                            /*!< MCM_PLACR.CFCC Mask                     */
#define MCM_PLACR_CFCC_SHIFT                     (10U)                                               /*!< MCM_PLACR.CFCC Position                 */
#define MCM_PLACR_CFCC(x)                        (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< MCM_PLACR.CFCC Field                    */
#define MCM_PLACR_DFCDA_MASK                     (0x800U)                                            /*!< MCM_PLACR.DFCDA Mask                    */
#define MCM_PLACR_DFCDA_SHIFT                    (11U)                                               /*!< MCM_PLACR.DFCDA Position                */
#define MCM_PLACR_DFCDA(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< MCM_PLACR.DFCDA Field                   */
#define MCM_PLACR_DFCIC_MASK                     (0x1000U)                                           /*!< MCM_PLACR.DFCIC Mask                    */
#define MCM_PLACR_DFCIC_SHIFT                    (12U)                                               /*!< MCM_PLACR.DFCIC Position                */
#define MCM_PLACR_DFCIC(x)                       (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< MCM_PLACR.DFCIC Field                   */
#define MCM_PLACR_DFCC_MASK                      (0x2000U)                                           /*!< MCM_PLACR.DFCC Mask                     */
#define MCM_PLACR_DFCC_SHIFT                     (13U)                                               /*!< MCM_PLACR.DFCC Position                 */
#define MCM_PLACR_DFCC(x)                        (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< MCM_PLACR.DFCC Field                    */
#define MCM_PLACR_EFDS_MASK                      (0x4000U)                                           /*!< MCM_PLACR.EFDS Mask                     */
#define MCM_PLACR_EFDS_SHIFT                     (14U)                                               /*!< MCM_PLACR.EFDS Position                 */
#define MCM_PLACR_EFDS(x)                        (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< MCM_PLACR.EFDS Field                    */
#define MCM_PLACR_DFCS_MASK                      (0x8000U)                                           /*!< MCM_PLACR.DFCS Mask                     */
#define MCM_PLACR_DFCS_SHIFT                     (15U)                                               /*!< MCM_PLACR.DFCS Position                 */
#define MCM_PLACR_DFCS(x)                        (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< MCM_PLACR.DFCS Field                    */
#define MCM_PLACR_ESFC_MASK                      (0x10000U)                                          /*!< MCM_PLACR.ESFC Mask                     */
#define MCM_PLACR_ESFC_SHIFT                     (16U)                                               /*!< MCM_PLACR.ESFC Position                 */
#define MCM_PLACR_ESFC(x)                        (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< MCM_PLACR.ESFC Field                    */
/* ------- CPO Bit Fields                           ------ */
#define MCM_CPO_CPOREQ_MASK                      (0x1U)                                              /*!< MCM_CPO.CPOREQ Mask                     */
#define MCM_CPO_CPOREQ_SHIFT                     (0U)                                                /*!< MCM_CPO.CPOREQ Position                 */
#define MCM_CPO_CPOREQ(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< MCM_CPO.CPOREQ Field                    */
#define MCM_CPO_CPOACK_MASK                      (0x2U)                                              /*!< MCM_CPO.CPOACK Mask                     */
#define MCM_CPO_CPOACK_SHIFT                     (1U)                                                /*!< MCM_CPO.CPOACK Position                 */
#define MCM_CPO_CPOACK(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< MCM_CPO.CPOACK Field                    */
#define MCM_CPO_CPOWOI_MASK                      (0x4U)                                              /*!< MCM_CPO.CPOWOI Mask                     */
#define MCM_CPO_CPOWOI_SHIFT                     (2U)                                                /*!< MCM_CPO.CPOWOI Position                 */
#define MCM_CPO_CPOWOI(x)                        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< MCM_CPO.CPOWOI Field                    */
/**
 * @} */ /* End group MCM_Register_Masks_GROUP 
 */

/* MCM - Peripheral instance base addresses */
#define MCM_BasePtr                    0xF0003000UL //!< Peripheral base address
#define MCM                            ((MCM_Type *) MCM_BasePtr) //!< Freescale base pointer
#define MCM_BASE_PTR                   (MCM) //!< Freescale style base pointer
/**
 * @} */ /* End group MCM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MPU_Peripheral_access_layer_GROUP MPU Peripheral Access Layer
* @brief C Struct for MPU
* @{
*/

/* ================================================================================ */
/* ================           MPU (file:MPU_MKL82Z7)               ================ */
/* ================================================================================ */

/**
 * @brief Memory protection unit
 */
/**
* @addtogroup MPU_structs_GROUP MPU struct
* @brief Struct for MPU
* @{
*/
typedef struct {                                /*       MPU Structure                                                */
   __IO uint32_t  CESR;                         /**< 0000: Control/Error Status Register                                */
        uint8_t   RESERVED_0[12];              
   struct {
      __I  uint32_t  EAR;                       /**< 0010: Error Address Register, slave port n                         */
      __I  uint32_t  EDR;                       /**< 0014: Error Detail Register, slave port n                          */
   } SP[5];                                     /**< 0010: (cluster: size=0x0028, 40)                                   */
        uint8_t   RESERVED_2[968];             
   struct {
      __IO uint32_t  WORD0;                     /**< 0400: Region Descriptor n, Word 0                                  */
      __IO uint32_t  WORD1;                     /**< 0404: Region Descriptor n, Word 1                                  */
      __IO uint32_t  WORD2;                     /**< 0408: Region Descriptor n, Word 2                                  */
      __IO uint32_t  WORD3;                     /**< 040C: Region Descriptor n, Word 3                                  */
   } RGD[8];                                    /**< 0400: (cluster: size=0x0080, 128)                                  */
        uint8_t   RESERVED_4[896];             
   __IO uint32_t  RGDAAC[8];                    /**< 0800: Region Descriptor Alternate Access Control n                 */
} MPU_Type;

/**
 * @} */ /* End group MPU_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MPU' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MPU_Register_Masks_GROUP MPU Register Masks
* @brief Register Masks for MPU
* @{
*/
/* ------- CESR Bit Fields                          ------ */
#define MPU_CESR_VLD_MASK                        (0x1U)                                              /*!< MPU_CESR.VLD Mask                       */
#define MPU_CESR_VLD_SHIFT                       (0U)                                                /*!< MPU_CESR.VLD Position                   */
#define MPU_CESR_VLD(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< MPU_CESR.VLD Field                      */
#define MPU_CESR_NRGD_MASK                       (0xF00U)                                            /*!< MPU_CESR.NRGD Mask                      */
#define MPU_CESR_NRGD_SHIFT                      (8U)                                                /*!< MPU_CESR.NRGD Position                  */
#define MPU_CESR_NRGD(x)                         (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< MPU_CESR.NRGD Field                     */
#define MPU_CESR_NSP_MASK                        (0xF000U)                                           /*!< MPU_CESR.NSP Mask                       */
#define MPU_CESR_NSP_SHIFT                       (12U)                                               /*!< MPU_CESR.NSP Position                   */
#define MPU_CESR_NSP(x)                          (((uint32_t)(((uint32_t)(x))<<12U))&0xF000UL)       /*!< MPU_CESR.NSP Field                      */
#define MPU_CESR_HRL_MASK                        (0xF0000U)                                          /*!< MPU_CESR.HRL Mask                       */
#define MPU_CESR_HRL_SHIFT                       (16U)                                               /*!< MPU_CESR.HRL Position                   */
#define MPU_CESR_HRL(x)                          (((uint32_t)(((uint32_t)(x))<<16U))&0xF0000UL)      /*!< MPU_CESR.HRL Field                      */
#define MPU_CESR_SPERR_MASK                      (0xF8000000U)                                       /*!< MPU_CESR.SPERR Mask                     */
#define MPU_CESR_SPERR_SHIFT                     (27U)                                               /*!< MPU_CESR.SPERR Position                 */
#define MPU_CESR_SPERR(x)                        (((uint32_t)(((uint32_t)(x))<<27U))&0xF8000000UL)   /*!< MPU_CESR.SPERR Field                    */
/* ------- EAR Bit Fields                           ------ */
#define MPU_EAR_EADDR_MASK                       (0xFFFFFFFFU)                                       /*!< MPU_EAR.EADDR Mask                      */
#define MPU_EAR_EADDR_SHIFT                      (0U)                                                /*!< MPU_EAR.EADDR Position                  */
#define MPU_EAR_EADDR(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< MPU_EAR.EADDR Field                     */
/* ------- EDR Bit Fields                           ------ */
#define MPU_EDR_ERW_MASK                         (0x1U)                                              /*!< MPU_EDR.ERW Mask                        */
#define MPU_EDR_ERW_SHIFT                        (0U)                                                /*!< MPU_EDR.ERW Position                    */
#define MPU_EDR_ERW(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< MPU_EDR.ERW Field                       */
#define MPU_EDR_EATTR_MASK                       (0xEU)                                              /*!< MPU_EDR.EATTR Mask                      */
#define MPU_EDR_EATTR_SHIFT                      (1U)                                                /*!< MPU_EDR.EATTR Position                  */
#define MPU_EDR_EATTR(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0xEUL)           /*!< MPU_EDR.EATTR Field                     */
#define MPU_EDR_EMN_MASK                         (0xF0U)                                             /*!< MPU_EDR.EMN Mask                        */
#define MPU_EDR_EMN_SHIFT                        (4U)                                                /*!< MPU_EDR.EMN Position                    */
#define MPU_EDR_EMN(x)                           (((uint32_t)(((uint32_t)(x))<<4U))&0xF0UL)          /*!< MPU_EDR.EMN Field                       */
#define MPU_EDR_EPID_MASK                        (0xFF00U)                                           /*!< MPU_EDR.EPID Mask                       */
#define MPU_EDR_EPID_SHIFT                       (8U)                                                /*!< MPU_EDR.EPID Position                   */
#define MPU_EDR_EPID(x)                          (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< MPU_EDR.EPID Field                      */
#define MPU_EDR_EACD_MASK                        (0xFFFF0000U)                                       /*!< MPU_EDR.EACD Mask                       */
#define MPU_EDR_EACD_SHIFT                       (16U)                                               /*!< MPU_EDR.EACD Position                   */
#define MPU_EDR_EACD(x)                          (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< MPU_EDR.EACD Field                      */
/* ------- WORD0 Bit Fields                         ------ */
#define MPU_WORD0_SRTADDR_MASK                   (0xFFFFFFE0U)                                       /*!< MPU_WORD0.SRTADDR Mask                  */
#define MPU_WORD0_SRTADDR_SHIFT                  (5U)                                                /*!< MPU_WORD0.SRTADDR Position              */
#define MPU_WORD0_SRTADDR(x)                     (((uint32_t)(((uint32_t)(x))<<5U))&0xFFFFFFE0UL)    /*!< MPU_WORD0.SRTADDR Field                 */
/* ------- WORD1 Bit Fields                         ------ */
#define MPU_WORD1_ENDADDR_MASK                   (0xFFFFFFE0U)                                       /*!< MPU_WORD1.ENDADDR Mask                  */
#define MPU_WORD1_ENDADDR_SHIFT                  (5U)                                                /*!< MPU_WORD1.ENDADDR Position              */
#define MPU_WORD1_ENDADDR(x)                     (((uint32_t)(((uint32_t)(x))<<5U))&0xFFFFFFE0UL)    /*!< MPU_WORD1.ENDADDR Field                 */
/* ------- WORD2 Bit Fields                         ------ */
#define MPU_WORD2_M0UM_MASK                      (0x7U)                                              /*!< MPU_WORD2.M0UM Mask                     */
#define MPU_WORD2_M0UM_SHIFT                     (0U)                                                /*!< MPU_WORD2.M0UM Position                 */
#define MPU_WORD2_M0UM(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< MPU_WORD2.M0UM Field                    */
#define MPU_WORD2_M0SM_MASK                      (0x18U)                                             /*!< MPU_WORD2.M0SM Mask                     */
#define MPU_WORD2_M0SM_SHIFT                     (3U)                                                /*!< MPU_WORD2.M0SM Position                 */
#define MPU_WORD2_M0SM(x)                        (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< MPU_WORD2.M0SM Field                    */
#define MPU_WORD2_M0PE_MASK                      (0x20U)                                             /*!< MPU_WORD2.M0PE Mask                     */
#define MPU_WORD2_M0PE_SHIFT                     (5U)                                                /*!< MPU_WORD2.M0PE Position                 */
#define MPU_WORD2_M0PE(x)                        (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< MPU_WORD2.M0PE Field                    */
#define MPU_WORD2_M1UM_MASK                      (0x1C0U)                                            /*!< MPU_WORD2.M1UM Mask                     */
#define MPU_WORD2_M1UM_SHIFT                     (6U)                                                /*!< MPU_WORD2.M1UM Position                 */
#define MPU_WORD2_M1UM(x)                        (((uint32_t)(((uint32_t)(x))<<6U))&0x1C0UL)         /*!< MPU_WORD2.M1UM Field                    */
#define MPU_WORD2_M1SM_MASK                      (0x600U)                                            /*!< MPU_WORD2.M1SM Mask                     */
#define MPU_WORD2_M1SM_SHIFT                     (9U)                                                /*!< MPU_WORD2.M1SM Position                 */
#define MPU_WORD2_M1SM(x)                        (((uint32_t)(((uint32_t)(x))<<9U))&0x600UL)         /*!< MPU_WORD2.M1SM Field                    */
#define MPU_WORD2_M1PE_MASK                      (0x800U)                                            /*!< MPU_WORD2.M1PE Mask                     */
#define MPU_WORD2_M1PE_SHIFT                     (11U)                                               /*!< MPU_WORD2.M1PE Position                 */
#define MPU_WORD2_M1PE(x)                        (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< MPU_WORD2.M1PE Field                    */
#define MPU_WORD2_M2UM_MASK                      (0x7000U)                                           /*!< MPU_WORD2.M2UM Mask                     */
#define MPU_WORD2_M2UM_SHIFT                     (12U)                                               /*!< MPU_WORD2.M2UM Position                 */
#define MPU_WORD2_M2UM(x)                        (((uint32_t)(((uint32_t)(x))<<12U))&0x7000UL)       /*!< MPU_WORD2.M2UM Field                    */
#define MPU_WORD2_M2SM_MASK                      (0x18000U)                                          /*!< MPU_WORD2.M2SM Mask                     */
#define MPU_WORD2_M2SM_SHIFT                     (15U)                                               /*!< MPU_WORD2.M2SM Position                 */
#define MPU_WORD2_M2SM(x)                        (((uint32_t)(((uint32_t)(x))<<15U))&0x18000UL)      /*!< MPU_WORD2.M2SM Field                    */
#define MPU_WORD2_M2PE_MASK                      (0x20000U)                                          /*!< MPU_WORD2.M2PE Mask                     */
#define MPU_WORD2_M2PE_SHIFT                     (17U)                                               /*!< MPU_WORD2.M2PE Position                 */
#define MPU_WORD2_M2PE(x)                        (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< MPU_WORD2.M2PE Field                    */
#define MPU_WORD2_M3UM_MASK                      (0x1C0000U)                                         /*!< MPU_WORD2.M3UM Mask                     */
#define MPU_WORD2_M3UM_SHIFT                     (18U)                                               /*!< MPU_WORD2.M3UM Position                 */
#define MPU_WORD2_M3UM(x)                        (((uint32_t)(((uint32_t)(x))<<18U))&0x1C0000UL)     /*!< MPU_WORD2.M3UM Field                    */
#define MPU_WORD2_M3SM_MASK                      (0x600000U)                                         /*!< MPU_WORD2.M3SM Mask                     */
#define MPU_WORD2_M3SM_SHIFT                     (21U)                                               /*!< MPU_WORD2.M3SM Position                 */
#define MPU_WORD2_M3SM(x)                        (((uint32_t)(((uint32_t)(x))<<21U))&0x600000UL)     /*!< MPU_WORD2.M3SM Field                    */
#define MPU_WORD2_M3PE_MASK                      (0x800000U)                                         /*!< MPU_WORD2.M3PE Mask                     */
#define MPU_WORD2_M3PE_SHIFT                     (23U)                                               /*!< MPU_WORD2.M3PE Position                 */
#define MPU_WORD2_M3PE(x)                        (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< MPU_WORD2.M3PE Field                    */
#define MPU_WORD2_M4WE_MASK                      (0x1000000U)                                        /*!< MPU_WORD2.M4WE Mask                     */
#define MPU_WORD2_M4WE_SHIFT                     (24U)                                               /*!< MPU_WORD2.M4WE Position                 */
#define MPU_WORD2_M4WE(x)                        (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< MPU_WORD2.M4WE Field                    */
#define MPU_WORD2_M4RE_MASK                      (0x2000000U)                                        /*!< MPU_WORD2.M4RE Mask                     */
#define MPU_WORD2_M4RE_SHIFT                     (25U)                                               /*!< MPU_WORD2.M4RE Position                 */
#define MPU_WORD2_M4RE(x)                        (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< MPU_WORD2.M4RE Field                    */
#define MPU_WORD2_M5WE_MASK                      (0x4000000U)                                        /*!< MPU_WORD2.M5WE Mask                     */
#define MPU_WORD2_M5WE_SHIFT                     (26U)                                               /*!< MPU_WORD2.M5WE Position                 */
#define MPU_WORD2_M5WE(x)                        (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< MPU_WORD2.M5WE Field                    */
#define MPU_WORD2_M5RE_MASK                      (0x8000000U)                                        /*!< MPU_WORD2.M5RE Mask                     */
#define MPU_WORD2_M5RE_SHIFT                     (27U)                                               /*!< MPU_WORD2.M5RE Position                 */
#define MPU_WORD2_M5RE(x)                        (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< MPU_WORD2.M5RE Field                    */
#define MPU_WORD2_M6WE_MASK                      (0x10000000U)                                       /*!< MPU_WORD2.M6WE Mask                     */
#define MPU_WORD2_M6WE_SHIFT                     (28U)                                               /*!< MPU_WORD2.M6WE Position                 */
#define MPU_WORD2_M6WE(x)                        (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< MPU_WORD2.M6WE Field                    */
#define MPU_WORD2_M6RE_MASK                      (0x20000000U)                                       /*!< MPU_WORD2.M6RE Mask                     */
#define MPU_WORD2_M6RE_SHIFT                     (29U)                                               /*!< MPU_WORD2.M6RE Position                 */
#define MPU_WORD2_M6RE(x)                        (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< MPU_WORD2.M6RE Field                    */
#define MPU_WORD2_M7WE_MASK                      (0x40000000U)                                       /*!< MPU_WORD2.M7WE Mask                     */
#define MPU_WORD2_M7WE_SHIFT                     (30U)                                               /*!< MPU_WORD2.M7WE Position                 */
#define MPU_WORD2_M7WE(x)                        (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< MPU_WORD2.M7WE Field                    */
#define MPU_WORD2_M7RE_MASK                      (0x80000000U)                                       /*!< MPU_WORD2.M7RE Mask                     */
#define MPU_WORD2_M7RE_SHIFT                     (31U)                                               /*!< MPU_WORD2.M7RE Position                 */
#define MPU_WORD2_M7RE(x)                        (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< MPU_WORD2.M7RE Field                    */
/* ------- WORD3 Bit Fields                         ------ */
#define MPU_WORD3_VLD_MASK                       (0x1U)                                              /*!< MPU_WORD3.VLD Mask                      */
#define MPU_WORD3_VLD_SHIFT                      (0U)                                                /*!< MPU_WORD3.VLD Position                  */
#define MPU_WORD3_VLD(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< MPU_WORD3.VLD Field                     */
#define MPU_WORD3_PIDMASK_MASK                   (0xFF0000U)                                         /*!< MPU_WORD3.PIDMASK Mask                  */
#define MPU_WORD3_PIDMASK_SHIFT                  (16U)                                               /*!< MPU_WORD3.PIDMASK Position              */
#define MPU_WORD3_PIDMASK(x)                     (((uint32_t)(((uint32_t)(x))<<16U))&0xFF0000UL)     /*!< MPU_WORD3.PIDMASK Field                 */
#define MPU_WORD3_PID_MASK                       (0xFF000000U)                                       /*!< MPU_WORD3.PID Mask                      */
#define MPU_WORD3_PID_SHIFT                      (24U)                                               /*!< MPU_WORD3.PID Position                  */
#define MPU_WORD3_PID(x)                         (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< MPU_WORD3.PID Field                     */
/* ------- RGDAAC Bit Fields                        ------ */
#define MPU_RGDAAC_M0UM_MASK                     (0x7U)                                              /*!< MPU_RGDAAC.M0UM Mask                    */
#define MPU_RGDAAC_M0UM_SHIFT                    (0U)                                                /*!< MPU_RGDAAC.M0UM Position                */
#define MPU_RGDAAC_M0UM(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< MPU_RGDAAC.M0UM Field                   */
#define MPU_RGDAAC_M0SM_MASK                     (0x18U)                                             /*!< MPU_RGDAAC.M0SM Mask                    */
#define MPU_RGDAAC_M0SM_SHIFT                    (3U)                                                /*!< MPU_RGDAAC.M0SM Position                */
#define MPU_RGDAAC_M0SM(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< MPU_RGDAAC.M0SM Field                   */
#define MPU_RGDAAC_M0PE_MASK                     (0x20U)                                             /*!< MPU_RGDAAC.M0PE Mask                    */
#define MPU_RGDAAC_M0PE_SHIFT                    (5U)                                                /*!< MPU_RGDAAC.M0PE Position                */
#define MPU_RGDAAC_M0PE(x)                       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< MPU_RGDAAC.M0PE Field                   */
#define MPU_RGDAAC_M1UM_MASK                     (0x1C0U)                                            /*!< MPU_RGDAAC.M1UM Mask                    */
#define MPU_RGDAAC_M1UM_SHIFT                    (6U)                                                /*!< MPU_RGDAAC.M1UM Position                */
#define MPU_RGDAAC_M1UM(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0x1C0UL)         /*!< MPU_RGDAAC.M1UM Field                   */
#define MPU_RGDAAC_M1SM_MASK                     (0x600U)                                            /*!< MPU_RGDAAC.M1SM Mask                    */
#define MPU_RGDAAC_M1SM_SHIFT                    (9U)                                                /*!< MPU_RGDAAC.M1SM Position                */
#define MPU_RGDAAC_M1SM(x)                       (((uint32_t)(((uint32_t)(x))<<9U))&0x600UL)         /*!< MPU_RGDAAC.M1SM Field                   */
#define MPU_RGDAAC_M1PE_MASK                     (0x800U)                                            /*!< MPU_RGDAAC.M1PE Mask                    */
#define MPU_RGDAAC_M1PE_SHIFT                    (11U)                                               /*!< MPU_RGDAAC.M1PE Position                */
#define MPU_RGDAAC_M1PE(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< MPU_RGDAAC.M1PE Field                   */
#define MPU_RGDAAC_M2UM_MASK                     (0x7000U)                                           /*!< MPU_RGDAAC.M2UM Mask                    */
#define MPU_RGDAAC_M2UM_SHIFT                    (12U)                                               /*!< MPU_RGDAAC.M2UM Position                */
#define MPU_RGDAAC_M2UM(x)                       (((uint32_t)(((uint32_t)(x))<<12U))&0x7000UL)       /*!< MPU_RGDAAC.M2UM Field                   */
#define MPU_RGDAAC_M2SM_MASK                     (0x18000U)                                          /*!< MPU_RGDAAC.M2SM Mask                    */
#define MPU_RGDAAC_M2SM_SHIFT                    (15U)                                               /*!< MPU_RGDAAC.M2SM Position                */
#define MPU_RGDAAC_M2SM(x)                       (((uint32_t)(((uint32_t)(x))<<15U))&0x18000UL)      /*!< MPU_RGDAAC.M2SM Field                   */
#define MPU_RGDAAC_M2PE_MASK                     (0x20000U)                                          /*!< MPU_RGDAAC.M2PE Mask                    */
#define MPU_RGDAAC_M2PE_SHIFT                    (17U)                                               /*!< MPU_RGDAAC.M2PE Position                */
#define MPU_RGDAAC_M2PE(x)                       (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< MPU_RGDAAC.M2PE Field                   */
#define MPU_RGDAAC_M3UM_MASK                     (0x1C0000U)                                         /*!< MPU_RGDAAC.M3UM Mask                    */
#define MPU_RGDAAC_M3UM_SHIFT                    (18U)                                               /*!< MPU_RGDAAC.M3UM Position                */
#define MPU_RGDAAC_M3UM(x)                       (((uint32_t)(((uint32_t)(x))<<18U))&0x1C0000UL)     /*!< MPU_RGDAAC.M3UM Field                   */
#define MPU_RGDAAC_M3SM_MASK                     (0x600000U)                                         /*!< MPU_RGDAAC.M3SM Mask                    */
#define MPU_RGDAAC_M3SM_SHIFT                    (21U)                                               /*!< MPU_RGDAAC.M3SM Position                */
#define MPU_RGDAAC_M3SM(x)                       (((uint32_t)(((uint32_t)(x))<<21U))&0x600000UL)     /*!< MPU_RGDAAC.M3SM Field                   */
#define MPU_RGDAAC_M3PE_MASK                     (0x800000U)                                         /*!< MPU_RGDAAC.M3PE Mask                    */
#define MPU_RGDAAC_M3PE_SHIFT                    (23U)                                               /*!< MPU_RGDAAC.M3PE Position                */
#define MPU_RGDAAC_M3PE(x)                       (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< MPU_RGDAAC.M3PE Field                   */
#define MPU_RGDAAC_M4WE_MASK                     (0x1000000U)                                        /*!< MPU_RGDAAC.M4WE Mask                    */
#define MPU_RGDAAC_M4WE_SHIFT                    (24U)                                               /*!< MPU_RGDAAC.M4WE Position                */
#define MPU_RGDAAC_M4WE(x)                       (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< MPU_RGDAAC.M4WE Field                   */
#define MPU_RGDAAC_M4RE_MASK                     (0x2000000U)                                        /*!< MPU_RGDAAC.M4RE Mask                    */
#define MPU_RGDAAC_M4RE_SHIFT                    (25U)                                               /*!< MPU_RGDAAC.M4RE Position                */
#define MPU_RGDAAC_M4RE(x)                       (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< MPU_RGDAAC.M4RE Field                   */
#define MPU_RGDAAC_M5WE_MASK                     (0x4000000U)                                        /*!< MPU_RGDAAC.M5WE Mask                    */
#define MPU_RGDAAC_M5WE_SHIFT                    (26U)                                               /*!< MPU_RGDAAC.M5WE Position                */
#define MPU_RGDAAC_M5WE(x)                       (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< MPU_RGDAAC.M5WE Field                   */
#define MPU_RGDAAC_M5RE_MASK                     (0x8000000U)                                        /*!< MPU_RGDAAC.M5RE Mask                    */
#define MPU_RGDAAC_M5RE_SHIFT                    (27U)                                               /*!< MPU_RGDAAC.M5RE Position                */
#define MPU_RGDAAC_M5RE(x)                       (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< MPU_RGDAAC.M5RE Field                   */
#define MPU_RGDAAC_M6WE_MASK                     (0x10000000U)                                       /*!< MPU_RGDAAC.M6WE Mask                    */
#define MPU_RGDAAC_M6WE_SHIFT                    (28U)                                               /*!< MPU_RGDAAC.M6WE Position                */
#define MPU_RGDAAC_M6WE(x)                       (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< MPU_RGDAAC.M6WE Field                   */
#define MPU_RGDAAC_M6RE_MASK                     (0x20000000U)                                       /*!< MPU_RGDAAC.M6RE Mask                    */
#define MPU_RGDAAC_M6RE_SHIFT                    (29U)                                               /*!< MPU_RGDAAC.M6RE Position                */
#define MPU_RGDAAC_M6RE(x)                       (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< MPU_RGDAAC.M6RE Field                   */
#define MPU_RGDAAC_M7WE_MASK                     (0x40000000U)                                       /*!< MPU_RGDAAC.M7WE Mask                    */
#define MPU_RGDAAC_M7WE_SHIFT                    (30U)                                               /*!< MPU_RGDAAC.M7WE Position                */
#define MPU_RGDAAC_M7WE(x)                       (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< MPU_RGDAAC.M7WE Field                   */
#define MPU_RGDAAC_M7RE_MASK                     (0x80000000U)                                       /*!< MPU_RGDAAC.M7RE Mask                    */
#define MPU_RGDAAC_M7RE_SHIFT                    (31U)                                               /*!< MPU_RGDAAC.M7RE Position                */
#define MPU_RGDAAC_M7RE(x)                       (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< MPU_RGDAAC.M7RE Field                   */
/**
 * @} */ /* End group MPU_Register_Masks_GROUP 
 */

/* MPU - Peripheral instance base addresses */
#define MPU_BasePtr                    0x4000D000UL //!< Peripheral base address
#define MPU                            ((MPU_Type *) MPU_BasePtr) //!< Freescale base pointer
#define MPU_BASE_PTR                   (MPU) //!< Freescale style base pointer
/**
 * @} */ /* End group MPU_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MTB_Peripheral_access_layer_GROUP MTB Peripheral Access Layer
* @brief C Struct for MTB
* @{
*/

/* ================================================================================ */
/* ================           MTB (file:MTB_MKL82Z7)               ================ */
/* ================================================================================ */

/**
 * @brief Micro Trace Buffer
 */
/**
* @addtogroup MTB_structs_GROUP MTB struct
* @brief Struct for MTB
* @{
*/
typedef struct {                                /*       MTB Structure                                                */
   __IO uint32_t  POSITION;                     /**< 0000: MTB Position Register                                        */
   __IO uint32_t  MASTER;                       /**< 0004: MTB Master Register                                          */
   __IO uint32_t  FLOW;                         /**< 0008: MTB Flow Register                                            */
   __I  uint32_t  BASE;                         /**< 000C: MTB Base Register                                            */
        uint8_t   RESERVED_0[3824];            
   __I  uint32_t  MODECTRL;                     /**< 0F00: Integration Mode Control Register                            */
        uint8_t   RESERVED_1[156];             
   __I  uint32_t  TAGSET;                       /**< 0FA0: Claim TAG Set Register                                       */
   __I  uint32_t  TAGCLEAR;                     /**< 0FA4: Claim TAG Clear Register                                     */
        uint8_t   RESERVED_2[8];               
   __I  uint32_t  LOCKACCESS;                   /**< 0FB0: Lock Access Register                                         */
   __I  uint32_t  LOCKSTAT;                     /**< 0FB4: Lock Status Register                                         */
   __I  uint32_t  AUTHSTAT;                     /**< 0FB8: Authentication Status Register                               */
   __I  uint32_t  DEVICEARCH;                   /**< 0FBC: Device Architecture Register                                 */
        uint8_t   RESERVED_3[8];               
   __I  uint32_t  DEVICECFG;                    /**< 0FC8: Device Configuration Register                                */
   __I  uint32_t  DEVICETYPID;                  /**< 0FCC: Device Type Identifier Register                              */
   __I  uint32_t  PERIPHID4;                    /**< 0FD0: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID5;                    /**< 0FD4: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID6;                    /**< 0FD8: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID7;                    /**< 0FDC: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID0;                    /**< 0FE0: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID1;                    /**< 0FE4: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID2;                    /**< 0FE8: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID3;                    /**< 0FEC: Peripheral ID Register                                       */
   __I  uint32_t  COMPID[4];                    /**< 0FF0: Component ID Register                                        */
} MTB_Type;

/**
 * @} */ /* End group MTB_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MTB' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MTB_Register_Masks_GROUP MTB Register Masks
* @brief Register Masks for MTB
* @{
*/
/* ------- POSITION Bit Fields                      ------ */
#define MTB_POSITION_WRAP_MASK                   (0x4U)                                              /*!< MTB_POSITION.WRAP Mask                  */
#define MTB_POSITION_WRAP_SHIFT                  (2U)                                                /*!< MTB_POSITION.WRAP Position              */
#define MTB_POSITION_WRAP(x)                     (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< MTB_POSITION.WRAP Field                 */
#define MTB_POSITION_POINTER_MASK                (0xFFFFFFF8U)                                       /*!< MTB_POSITION.POINTER Mask               */
#define MTB_POSITION_POINTER_SHIFT               (3U)                                                /*!< MTB_POSITION.POINTER Position           */
#define MTB_POSITION_POINTER(x)                  (((uint32_t)(((uint32_t)(x))<<3U))&0xFFFFFFF8UL)    /*!< MTB_POSITION.POINTER Field              */
/* ------- MASTER Bit Fields                        ------ */
#define MTB_MASTER_MASK_MASK                     (0x1FU)                                             /*!< MTB_MASTER.MASK Mask                    */
#define MTB_MASTER_MASK_SHIFT                    (0U)                                                /*!< MTB_MASTER.MASK Position                */
#define MTB_MASTER_MASK(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1FUL)          /*!< MTB_MASTER.MASK Field                   */
#define MTB_MASTER_TSTARTEN_MASK                 (0x20U)                                             /*!< MTB_MASTER.TSTARTEN Mask                */
#define MTB_MASTER_TSTARTEN_SHIFT                (5U)                                                /*!< MTB_MASTER.TSTARTEN Position            */
#define MTB_MASTER_TSTARTEN(x)                   (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< MTB_MASTER.TSTARTEN Field               */
#define MTB_MASTER_TSTOPEN_MASK                  (0x40U)                                             /*!< MTB_MASTER.TSTOPEN Mask                 */
#define MTB_MASTER_TSTOPEN_SHIFT                 (6U)                                                /*!< MTB_MASTER.TSTOPEN Position             */
#define MTB_MASTER_TSTOPEN(x)                    (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< MTB_MASTER.TSTOPEN Field                */
#define MTB_MASTER_SFRWPRIV_MASK                 (0x80U)                                             /*!< MTB_MASTER.SFRWPRIV Mask                */
#define MTB_MASTER_SFRWPRIV_SHIFT                (7U)                                                /*!< MTB_MASTER.SFRWPRIV Position            */
#define MTB_MASTER_SFRWPRIV(x)                   (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< MTB_MASTER.SFRWPRIV Field               */
#define MTB_MASTER_RAMPRIV_MASK                  (0x100U)                                            /*!< MTB_MASTER.RAMPRIV Mask                 */
#define MTB_MASTER_RAMPRIV_SHIFT                 (8U)                                                /*!< MTB_MASTER.RAMPRIV Position             */
#define MTB_MASTER_RAMPRIV(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< MTB_MASTER.RAMPRIV Field                */
#define MTB_MASTER_HALTREQ_MASK                  (0x200U)                                            /*!< MTB_MASTER.HALTREQ Mask                 */
#define MTB_MASTER_HALTREQ_SHIFT                 (9U)                                                /*!< MTB_MASTER.HALTREQ Position             */
#define MTB_MASTER_HALTREQ(x)                    (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< MTB_MASTER.HALTREQ Field                */
#define MTB_MASTER_EN_MASK                       (0x80000000U)                                       /*!< MTB_MASTER.EN Mask                      */
#define MTB_MASTER_EN_SHIFT                      (31U)                                               /*!< MTB_MASTER.EN Position                  */
#define MTB_MASTER_EN(x)                         (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< MTB_MASTER.EN Field                     */
/* ------- FLOW Bit Fields                          ------ */
#define MTB_FLOW_AUTOSTOP_MASK                   (0x1U)                                              /*!< MTB_FLOW.AUTOSTOP Mask                  */
#define MTB_FLOW_AUTOSTOP_SHIFT                  (0U)                                                /*!< MTB_FLOW.AUTOSTOP Position              */
#define MTB_FLOW_AUTOSTOP(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< MTB_FLOW.AUTOSTOP Field                 */
#define MTB_FLOW_AUTOHALT_MASK                   (0x2U)                                              /*!< MTB_FLOW.AUTOHALT Mask                  */
#define MTB_FLOW_AUTOHALT_SHIFT                  (1U)                                                /*!< MTB_FLOW.AUTOHALT Position              */
#define MTB_FLOW_AUTOHALT(x)                     (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< MTB_FLOW.AUTOHALT Field                 */
#define MTB_FLOW_WATERMARK_MASK                  (0xFFFFFFF8U)                                       /*!< MTB_FLOW.WATERMARK Mask                 */
#define MTB_FLOW_WATERMARK_SHIFT                 (3U)                                                /*!< MTB_FLOW.WATERMARK Position             */
#define MTB_FLOW_WATERMARK(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0xFFFFFFF8UL)    /*!< MTB_FLOW.WATERMARK Field                */
/* ------- BASE Bit Fields                          ------ */
#define MTB_BASE_BASEADDR_MASK                   (0xFFFFFFFFU)                                       /*!< MTB_BASE.BASEADDR Mask                  */
#define MTB_BASE_BASEADDR_SHIFT                  (0U)                                                /*!< MTB_BASE.BASEADDR Position              */
#define MTB_BASE_BASEADDR(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< MTB_BASE.BASEADDR Field                 */
/* ------- MODECTRL Bit Fields                      ------ */
#define MTB_MODECTRL_MODECTRL_MASK               (0xFFFFFFFFU)                                       /*!< MTB_MODECTRL.MODECTRL Mask              */
#define MTB_MODECTRL_MODECTRL_SHIFT              (0U)                                                /*!< MTB_MODECTRL.MODECTRL Position          */
#define MTB_MODECTRL_MODECTRL(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< MTB_MODECTRL.MODECTRL Field             */
/* ------- TAGSET Bit Fields                        ------ */
#define MTB_TAGSET_TAGSET_MASK                   (0xFFFFFFFFU)                                       /*!< MTB_TAGSET.TAGSET Mask                  */
#define MTB_TAGSET_TAGSET_SHIFT                  (0U)                                                /*!< MTB_TAGSET.TAGSET Position              */
#define MTB_TAGSET_TAGSET(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< MTB_TAGSET.TAGSET Field                 */
/* ------- TAGCLEAR Bit Fields                      ------ */
#define MTB_TAGCLEAR_TAGCLEAR_MASK               (0xFFFFFFFFU)                                       /*!< MTB_TAGCLEAR.TAGCLEAR Mask              */
#define MTB_TAGCLEAR_TAGCLEAR_SHIFT              (0U)                                                /*!< MTB_TAGCLEAR.TAGCLEAR Position          */
#define MTB_TAGCLEAR_TAGCLEAR(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< MTB_TAGCLEAR.TAGCLEAR Field             */
/* ------- LOCKACCESS Bit Fields                    ------ */
#define MTB_LOCKACCESS_LOCKACCESS_MASK           (0xFFFFFFFFU)                                       /*!< MTB_LOCKACCESS.LOCKACCESS Mask          */
#define MTB_LOCKACCESS_LOCKACCESS_SHIFT          (0U)                                                /*!< MTB_LOCKACCESS.LOCKACCESS Position      */
#define MTB_LOCKACCESS_LOCKACCESS(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< MTB_LOCKACCESS.LOCKACCESS Field         */
/* ------- LOCKSTAT Bit Fields                      ------ */
#define MTB_LOCKSTAT_LOCKSTAT_MASK               (0xFFFFFFFFU)                                       /*!< MTB_LOCKSTAT.LOCKSTAT Mask              */
#define MTB_LOCKSTAT_LOCKSTAT_SHIFT              (0U)                                                /*!< MTB_LOCKSTAT.LOCKSTAT Position          */
#define MTB_LOCKSTAT_LOCKSTAT(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< MTB_LOCKSTAT.LOCKSTAT Field             */
/* ------- AUTHSTAT Bit Fields                      ------ */
#define MTB_AUTHSTAT_BIT0_MASK                   (0x1U)                                              /*!< MTB_AUTHSTAT.BIT0 Mask                  */
#define MTB_AUTHSTAT_BIT0_SHIFT                  (0U)                                                /*!< MTB_AUTHSTAT.BIT0 Position              */
#define MTB_AUTHSTAT_BIT0(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< MTB_AUTHSTAT.BIT0 Field                 */
#define MTB_AUTHSTAT_BIT2_MASK                   (0x4U)                                              /*!< MTB_AUTHSTAT.BIT2 Mask                  */
#define MTB_AUTHSTAT_BIT2_SHIFT                  (2U)                                                /*!< MTB_AUTHSTAT.BIT2 Position              */
#define MTB_AUTHSTAT_BIT2(x)                     (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< MTB_AUTHSTAT.BIT2 Field                 */
/* ------- DEVICEARCH Bit Fields                    ------ */
#define MTB_DEVICEARCH_DEVICEARCH_MASK           (0xFFFFFFFFU)                                       /*!< MTB_DEVICEARCH.DEVICEARCH Mask          */
#define MTB_DEVICEARCH_DEVICEARCH_SHIFT          (0U)                                                /*!< MTB_DEVICEARCH.DEVICEARCH Position      */
#define MTB_DEVICEARCH_DEVICEARCH(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< MTB_DEVICEARCH.DEVICEARCH Field         */
/* ------- DEVICECFG Bit Fields                     ------ */
#define MTB_DEVICECFG_DEVICECFG_MASK             (0xFFFFFFFFU)                                       /*!< MTB_DEVICECFG.DEVICECFG Mask            */
#define MTB_DEVICECFG_DEVICECFG_SHIFT            (0U)                                                /*!< MTB_DEVICECFG.DEVICECFG Position        */
#define MTB_DEVICECFG_DEVICECFG(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< MTB_DEVICECFG.DEVICECFG Field           */
/* ------- DEVICETYPID Bit Fields                   ------ */
#define MTB_DEVICETYPID_DEVICETYPID_MASK         (0xFFFFFFFFU)                                       /*!< MTB_DEVICETYPID.DEVICETYPID Mask        */
#define MTB_DEVICETYPID_DEVICETYPID_SHIFT        (0U)                                                /*!< MTB_DEVICETYPID.DEVICETYPID Position    */
#define MTB_DEVICETYPID_DEVICETYPID(x)           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< MTB_DEVICETYPID.DEVICETYPID Field       */
/* ------- PERIPHID Bit Fields                      ------ */
#define MTB_PERIPHID_PERIPHID_MASK               (0xFFFFFFFFU)                                       /*!< MTB_PERIPHID.PERIPHID Mask              */
#define MTB_PERIPHID_PERIPHID_SHIFT              (0U)                                                /*!< MTB_PERIPHID.PERIPHID Position          */
#define MTB_PERIPHID_PERIPHID(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< MTB_PERIPHID.PERIPHID Field             */
/* ------- COMPID Bit Fields                        ------ */
#define MTB_COMPID_COMPID_MASK                   (0xFFFFFFFFU)                                       /*!< MTB_COMPID.COMPID Mask                  */
#define MTB_COMPID_COMPID_SHIFT                  (0U)                                                /*!< MTB_COMPID.COMPID Position              */
#define MTB_COMPID_COMPID(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< MTB_COMPID.COMPID Field                 */
/**
 * @} */ /* End group MTB_Register_Masks_GROUP 
 */

/* MTB - Peripheral instance base addresses */
#define MTB_BasePtr                    0xF0000000UL //!< Peripheral base address
#define MTB                            ((MTB_Type *) MTB_BasePtr) //!< Freescale base pointer
#define MTB_BASE_PTR                   (MTB) //!< Freescale style base pointer
/**
 * @} */ /* End group MTB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MTBDWT_Peripheral_access_layer_GROUP MTBDWT Peripheral Access Layer
* @brief C Struct for MTBDWT
* @{
*/

/* ================================================================================ */
/* ================           MTBDWT (file:MTBDWT_MKE15Z7)         ================ */
/* ================================================================================ */

/**
 * @brief MTB data watchpoint and trace
 */
/**
* @addtogroup MTBDWT_structs_GROUP MTBDWT struct
* @brief Struct for MTBDWT
* @{
*/
typedef struct {                                /*       MTBDWT Structure                                             */
   __I  uint32_t  CTRL;                         /**< 0000: MTB DWT Control Register                                     */
        uint8_t   RESERVED_0[28];              
   struct {
      __IO uint32_t  COMP;                      /**< 0020: MTB_DWT Comparator Register                                  */
      __IO uint32_t  MASK;                      /**< 0024: MTB_DWT Comparator Mask Register                             */
      __IO uint32_t  FCT;                       /**< 0028: MTB_DWT Comparator Function Register 0                       */
           uint8_t   RESERVED_1[4];            
   } COMPARATOR[2];                             /**< 0020: (cluster: size=0x0020, 32)                                   */
        uint8_t   RESERVED_2[448];             
   __IO uint32_t  TBCTRL;                       /**< 0200: MTB_DWT Trace Buffer Control Register                        */
        uint8_t   RESERVED_3[3524];            
   __I  uint32_t  DEVICECFG;                    /**< 0FC8: Device Configuration Register                                */
   __I  uint32_t  DEVICETYPID;                  /**< 0FCC: Device Type Identifier Register                              */
   __I  uint32_t  PERIPHID4;                    /**< 0FD0: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID5;                    /**< 0FD4: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID6;                    /**< 0FD8: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID7;                    /**< 0FDC: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID0;                    /**< 0FE0: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID1;                    /**< 0FE4: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID2;                    /**< 0FE8: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID3;                    /**< 0FEC: Peripheral ID Register                                       */
   __I  uint32_t  COMPID[4];                    /**< 0FF0: Component ID Register                                        */
} MTBDWT_Type;

/**
 * @} */ /* End group MTBDWT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MTBDWT' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MTBDWT_Register_Masks_GROUP MTBDWT Register Masks
* @brief Register Masks for MTBDWT
* @{
*/
/* ------- CTRL Bit Fields                          ------ */
#define MTBDWT_CTRL_DWTCFGCTRL_MASK              (0xFFFFFFFU)                                        /*!< MTBDWT_CTRL.DWTCFGCTRL Mask             */
#define MTBDWT_CTRL_DWTCFGCTRL_SHIFT             (0U)                                                /*!< MTBDWT_CTRL.DWTCFGCTRL Position         */
#define MTBDWT_CTRL_DWTCFGCTRL(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFUL)     /*!< MTBDWT_CTRL.DWTCFGCTRL Field            */
#define MTBDWT_CTRL_NUMCMP_MASK                  (0xF0000000U)                                       /*!< MTBDWT_CTRL.NUMCMP Mask                 */
#define MTBDWT_CTRL_NUMCMP_SHIFT                 (28U)                                               /*!< MTBDWT_CTRL.NUMCMP Position             */
#define MTBDWT_CTRL_NUMCMP(x)                    (((uint32_t)(((uint32_t)(x))<<28U))&0xF0000000UL)   /*!< MTBDWT_CTRL.NUMCMP Field                */
/* ------- COMP Bit Fields                          ------ */
#define MTBDWT_COMP_COMP_MASK                    (0xFFFFFFFFU)                                       /*!< MTBDWT_COMP.COMP Mask                   */
#define MTBDWT_COMP_COMP_SHIFT                   (0U)                                                /*!< MTBDWT_COMP.COMP Position               */
#define MTBDWT_COMP_COMP(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< MTBDWT_COMP.COMP Field                  */
/* ------- MASK Bit Fields                          ------ */
#define MTBDWT_MASK_MASK_MASK                    (0x1FU)                                             /*!< MTBDWT_MASK.MASK Mask                   */
#define MTBDWT_MASK_MASK_SHIFT                   (0U)                                                /*!< MTBDWT_MASK.MASK Position               */
#define MTBDWT_MASK_MASK(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x1FUL)          /*!< MTBDWT_MASK.MASK Field                  */
/* ------- FCT Bit Fields                           ------ */
#define MTBDWT_FCT_FUNCTION_MASK                 (0xFU)                                              /*!< MTBDWT_FCT.FUNCTION Mask                */
#define MTBDWT_FCT_FUNCTION_SHIFT                (0U)                                                /*!< MTBDWT_FCT.FUNCTION Position            */
#define MTBDWT_FCT_FUNCTION(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< MTBDWT_FCT.FUNCTION Field               */
#define MTBDWT_FCT_DATAVMATCH_MASK               (0x100U)                                            /*!< MTBDWT_FCT.DATAVMATCH Mask              */
#define MTBDWT_FCT_DATAVMATCH_SHIFT              (8U)                                                /*!< MTBDWT_FCT.DATAVMATCH Position          */
#define MTBDWT_FCT_DATAVMATCH(x)                 (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< MTBDWT_FCT.DATAVMATCH Field             */
#define MTBDWT_FCT_DATAVSIZE_MASK                (0xC00U)                                            /*!< MTBDWT_FCT.DATAVSIZE Mask               */
#define MTBDWT_FCT_DATAVSIZE_SHIFT               (10U)                                               /*!< MTBDWT_FCT.DATAVSIZE Position           */
#define MTBDWT_FCT_DATAVSIZE(x)                  (((uint32_t)(((uint32_t)(x))<<10U))&0xC00UL)        /*!< MTBDWT_FCT.DATAVSIZE Field              */
#define MTBDWT_FCT_DATAVADDR0_MASK               (0xF000U)                                           /*!< MTBDWT_FCT.DATAVADDR0 Mask              */
#define MTBDWT_FCT_DATAVADDR0_SHIFT              (12U)                                               /*!< MTBDWT_FCT.DATAVADDR0 Position          */
#define MTBDWT_FCT_DATAVADDR0(x)                 (((uint32_t)(((uint32_t)(x))<<12U))&0xF000UL)       /*!< MTBDWT_FCT.DATAVADDR0 Field             */
#define MTBDWT_FCT_MATCHED_MASK                  (0x1000000U)                                        /*!< MTBDWT_FCT.MATCHED Mask                 */
#define MTBDWT_FCT_MATCHED_SHIFT                 (24U)                                               /*!< MTBDWT_FCT.MATCHED Position             */
#define MTBDWT_FCT_MATCHED(x)                    (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< MTBDWT_FCT.MATCHED Field                */
/* ------- TBCTRL Bit Fields                        ------ */
#define MTBDWT_TBCTRL_ACOMP0_MASK                (0x1U)                                              /*!< MTBDWT_TBCTRL.ACOMP0 Mask               */
#define MTBDWT_TBCTRL_ACOMP0_SHIFT               (0U)                                                /*!< MTBDWT_TBCTRL.ACOMP0 Position           */
#define MTBDWT_TBCTRL_ACOMP0(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< MTBDWT_TBCTRL.ACOMP0 Field              */
#define MTBDWT_TBCTRL_ACOMP1_MASK                (0x2U)                                              /*!< MTBDWT_TBCTRL.ACOMP1 Mask               */
#define MTBDWT_TBCTRL_ACOMP1_SHIFT               (1U)                                                /*!< MTBDWT_TBCTRL.ACOMP1 Position           */
#define MTBDWT_TBCTRL_ACOMP1(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< MTBDWT_TBCTRL.ACOMP1 Field              */
#define MTBDWT_TBCTRL_NUMCOMP_MASK               (0xF0000000U)                                       /*!< MTBDWT_TBCTRL.NUMCOMP Mask              */
#define MTBDWT_TBCTRL_NUMCOMP_SHIFT              (28U)                                               /*!< MTBDWT_TBCTRL.NUMCOMP Position          */
#define MTBDWT_TBCTRL_NUMCOMP(x)                 (((uint32_t)(((uint32_t)(x))<<28U))&0xF0000000UL)   /*!< MTBDWT_TBCTRL.NUMCOMP Field             */
/* ------- DEVICECFG Bit Fields                     ------ */
#define MTBDWT_DEVICECFG_DEVICECFG_MASK          (0xFFFFFFFFU)                                       /*!< MTBDWT_DEVICECFG.DEVICECFG Mask         */
#define MTBDWT_DEVICECFG_DEVICECFG_SHIFT         (0U)                                                /*!< MTBDWT_DEVICECFG.DEVICECFG Position     */
#define MTBDWT_DEVICECFG_DEVICECFG(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< MTBDWT_DEVICECFG.DEVICECFG Field        */
/* ------- DEVICETYPID Bit Fields                   ------ */
#define MTBDWT_DEVICETYPID_DEVICETYPID_MASK      (0xFFFFFFFFU)                                       /*!< MTBDWT_DEVICETYPID.DEVICETYPID Mask     */
#define MTBDWT_DEVICETYPID_DEVICETYPID_SHIFT     (0U)                                                /*!< MTBDWT_DEVICETYPID.DEVICETYPID Position */
#define MTBDWT_DEVICETYPID_DEVICETYPID(x)        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< MTBDWT_DEVICETYPID.DEVICETYPID Field    */
/* ------- PERIPHID Bit Fields                      ------ */
#define MTBDWT_PERIPHID_PERIPHID_MASK            (0xFFFFFFFFU)                                       /*!< MTBDWT_PERIPHID.PERIPHID Mask           */
#define MTBDWT_PERIPHID_PERIPHID_SHIFT           (0U)                                                /*!< MTBDWT_PERIPHID.PERIPHID Position       */
#define MTBDWT_PERIPHID_PERIPHID(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< MTBDWT_PERIPHID.PERIPHID Field          */
/* ------- COMPID Bit Fields                        ------ */
#define MTBDWT_COMPID_COMPID_MASK                (0xFFFFFFFFU)                                       /*!< MTBDWT_COMPID.COMPID Mask               */
#define MTBDWT_COMPID_COMPID_SHIFT               (0U)                                                /*!< MTBDWT_COMPID.COMPID Position           */
#define MTBDWT_COMPID_COMPID(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< MTBDWT_COMPID.COMPID Field              */
/**
 * @} */ /* End group MTBDWT_Register_Masks_GROUP 
 */

/* MTBDWT - Peripheral instance base addresses */
#define MTBDWT_BasePtr                 0xF0001000UL //!< Peripheral base address
#define MTBDWT                         ((MTBDWT_Type *) MTBDWT_BasePtr) //!< Freescale base pointer
#define MTBDWT_BASE_PTR                (MTBDWT) //!< Freescale style base pointer
/**
 * @} */ /* End group MTBDWT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup NV_Peripheral_access_layer_GROUP NV Peripheral Access Layer
* @brief C Struct for NV
* @{
*/

/* ================================================================================ */
/* ================           NV (file:NV_MKL82Z7)                 ================ */
/* ================================================================================ */

/**
 * @brief Flash configuration field
 */
/**
* @addtogroup NV_structs_GROUP NV struct
* @brief Struct for NV
* @{
*/
typedef struct {                                /*       NV Structure                                                 */
   __I  uint8_t   BACKKEY3;                     /**< 0000: Backdoor Comparison Key 3                                    */
   __I  uint8_t   BACKKEY2;                     /**< 0001: Backdoor Comparison Key 2                                    */
   __I  uint8_t   BACKKEY1;                     /**< 0002: Backdoor Comparison Key 1                                    */
   __I  uint8_t   BACKKEY0;                     /**< 0003: Backdoor Comparison Key 0                                    */
   __I  uint8_t   BACKKEY7;                     /**< 0004: Backdoor Comparison Key 7                                    */
   __I  uint8_t   BACKKEY6;                     /**< 0005: Backdoor Comparison Key 6                                    */
   __I  uint8_t   BACKKEY5;                     /**< 0006: Backdoor Comparison Key 5                                    */
   __I  uint8_t   BACKKEY4;                     /**< 0007: Backdoor Comparison Key 4                                    */
   __I  uint8_t   FPROT3;                       /**< 0008: Non-volatile P-Flash Protection 1 - Low Register             */
   __I  uint8_t   FPROT2;                       /**< 0009: Non-volatile P-Flash Protection 1 - High Register            */
   __I  uint8_t   FPROT1;                       /**< 000A: Non-volatile P-Flash Protection 0 - Low Register             */
   __I  uint8_t   FPROT0;                       /**< 000B: Non-volatile P-Flash Protection 0 - High Register            */
   __I  uint8_t   FSEC;                         /**< 000C: Non-volatile Flash Security Register                         */
   __I  uint8_t   FOPT;                         /**< 000D: Non-volatile Flash Option Register                           */
} NV_Type;

/**
 * @} */ /* End group NV_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'NV' Position & Mask macros                          ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup NV_Register_Masks_GROUP NV Register Masks
* @brief Register Masks for NV
* @{
*/
/* ------- BACKKEY Bit Fields                       ------ */
#define NV_BACKKEY_KEY_MASK                      (0xFFU)                                             /*!< NV_BACKKEY.KEY Mask                     */
#define NV_BACKKEY_KEY_SHIFT                     (0U)                                                /*!< NV_BACKKEY.KEY Position                 */
#define NV_BACKKEY_KEY(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< NV_BACKKEY.KEY Field                    */
/* ------- FPROT3 Bit Fields                        ------ */
#define NV_FPROT3_PROT_MASK                      (0xFFU)                                             /*!< NV_FPROT3.PROT Mask                     */
#define NV_FPROT3_PROT_SHIFT                     (0U)                                                /*!< NV_FPROT3.PROT Position                 */
#define NV_FPROT3_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< NV_FPROT3.PROT Field                    */
/* ------- FPROT2 Bit Fields                        ------ */
#define NV_FPROT2_PROT_MASK                      (0xFFU)                                             /*!< NV_FPROT2.PROT Mask                     */
#define NV_FPROT2_PROT_SHIFT                     (0U)                                                /*!< NV_FPROT2.PROT Position                 */
#define NV_FPROT2_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< NV_FPROT2.PROT Field                    */
/* ------- FPROT1 Bit Fields                        ------ */
#define NV_FPROT1_PROT_MASK                      (0xFFU)                                             /*!< NV_FPROT1.PROT Mask                     */
#define NV_FPROT1_PROT_SHIFT                     (0U)                                                /*!< NV_FPROT1.PROT Position                 */
#define NV_FPROT1_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< NV_FPROT1.PROT Field                    */
/* ------- FPROT0 Bit Fields                        ------ */
#define NV_FPROT0_PROT_MASK                      (0xFFU)                                             /*!< NV_FPROT0.PROT Mask                     */
#define NV_FPROT0_PROT_SHIFT                     (0U)                                                /*!< NV_FPROT0.PROT Position                 */
#define NV_FPROT0_PROT(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< NV_FPROT0.PROT Field                    */
/* ------- FSEC Bit Fields                          ------ */
#define NV_FSEC_SEC_MASK                         (0x3U)                                              /*!< NV_FSEC.SEC Mask                        */
#define NV_FSEC_SEC_SHIFT                        (0U)                                                /*!< NV_FSEC.SEC Position                    */
#define NV_FSEC_SEC(x)                           (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< NV_FSEC.SEC Field                       */
#define NV_FSEC_FSLACC_MASK                      (0xCU)                                              /*!< NV_FSEC.FSLACC Mask                     */
#define NV_FSEC_FSLACC_SHIFT                     (2U)                                                /*!< NV_FSEC.FSLACC Position                 */
#define NV_FSEC_FSLACC(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< NV_FSEC.FSLACC Field                    */
#define NV_FSEC_MEEN_MASK                        (0x30U)                                             /*!< NV_FSEC.MEEN Mask                       */
#define NV_FSEC_MEEN_SHIFT                       (4U)                                                /*!< NV_FSEC.MEEN Position                   */
#define NV_FSEC_MEEN(x)                          (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< NV_FSEC.MEEN Field                      */
#define NV_FSEC_KEYEN_MASK                       (0xC0U)                                             /*!< NV_FSEC.KEYEN Mask                      */
#define NV_FSEC_KEYEN_SHIFT                      (6U)                                                /*!< NV_FSEC.KEYEN Position                  */
#define NV_FSEC_KEYEN(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< NV_FSEC.KEYEN Field                     */
/* ------- FOPT Bit Fields                          ------ */
#define NV_FOPT_LPBOOT_MASK                      (0x1U)                                              /*!< NV_FOPT.LPBOOT Mask                     */
#define NV_FOPT_LPBOOT_SHIFT                     (0U)                                                /*!< NV_FOPT.LPBOOT Position                 */
#define NV_FOPT_LPBOOT(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< NV_FOPT.LPBOOT Field                    */
#define NV_FOPT_BOOTPIN_OPT_MASK                 (0x2U)                                              /*!< NV_FOPT.BOOTPIN_OPT Mask                */
#define NV_FOPT_BOOTPIN_OPT_SHIFT                (1U)                                                /*!< NV_FOPT.BOOTPIN_OPT Position            */
#define NV_FOPT_BOOTPIN_OPT(x)                   (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< NV_FOPT.BOOTPIN_OPT Field               */
#define NV_FOPT_NMI_DIS_MASK                     (0x4U)                                              /*!< NV_FOPT.NMI_DIS Mask                    */
#define NV_FOPT_NMI_DIS_SHIFT                    (2U)                                                /*!< NV_FOPT.NMI_DIS Position                */
#define NV_FOPT_NMI_DIS(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< NV_FOPT.NMI_DIS Field                   */
#define NV_FOPT_FAST_INIT_MASK                   (0x20U)                                             /*!< NV_FOPT.FAST_INIT Mask                  */
#define NV_FOPT_FAST_INIT_SHIFT                  (5U)                                                /*!< NV_FOPT.FAST_INIT Position              */
#define NV_FOPT_FAST_INIT(x)                     (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< NV_FOPT.FAST_INIT Field                 */
#define NV_FOPT_BOOTSRC_SEL_MASK                 (0xC0U)                                             /*!< NV_FOPT.BOOTSRC_SEL Mask                */
#define NV_FOPT_BOOTSRC_SEL_SHIFT                (6U)                                                /*!< NV_FOPT.BOOTSRC_SEL Position            */
#define NV_FOPT_BOOTSRC_SEL(x)                   (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< NV_FOPT.BOOTSRC_SEL Field               */
/**
 * @} */ /* End group NV_Register_Masks_GROUP 
 */

/* NV - Peripheral instance base addresses */
#define NV_BasePtr                     0x00000400UL //!< Peripheral base address
#define NV                             ((NV_Type *) NV_BasePtr) //!< Freescale base pointer
#define NV_BASE_PTR                    (NV) //!< Freescale style base pointer
/**
 * @} */ /* End group NV_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup OSC_Peripheral_access_layer_GROUP OSC Peripheral Access Layer
* @brief C Struct for OSC
* @{
*/

/* ================================================================================ */
/* ================           OSC (file:OSC_MKL82Z7)               ================ */
/* ================================================================================ */

/**
 * @brief Oscillator
 */
/**
* @addtogroup OSC_structs_GROUP OSC struct
* @brief Struct for OSC
* @{
*/
typedef struct {                                /*       OSC Structure                                                */
   __IO uint8_t   CR;                           /**< 0000: OSC Control Register                                         */
        uint8_t   RESERVED_0;                  
   __IO uint8_t   DIV;                          /**< 0002: OSC_DIV                                                      */
} OSC_Type;

/**
 * @} */ /* End group OSC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'OSC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup OSC_Register_Masks_GROUP OSC Register Masks
* @brief Register Masks for OSC
* @{
*/
/* ------- CR Bit Fields                            ------ */
#define OSC_CR_SC16P_MASK                        (0x1U)                                              /*!< OSC_CR.SC16P Mask                       */
#define OSC_CR_SC16P_SHIFT                       (0U)                                                /*!< OSC_CR.SC16P Position                   */
#define OSC_CR_SC16P(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< OSC_CR.SC16P Field                      */
#define OSC_CR_SC8P_MASK                         (0x2U)                                              /*!< OSC_CR.SC8P Mask                        */
#define OSC_CR_SC8P_SHIFT                        (1U)                                                /*!< OSC_CR.SC8P Position                    */
#define OSC_CR_SC8P(x)                           (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< OSC_CR.SC8P Field                       */
#define OSC_CR_SC4P_MASK                         (0x4U)                                              /*!< OSC_CR.SC4P Mask                        */
#define OSC_CR_SC4P_SHIFT                        (2U)                                                /*!< OSC_CR.SC4P Position                    */
#define OSC_CR_SC4P(x)                           (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< OSC_CR.SC4P Field                       */
#define OSC_CR_SC2P_MASK                         (0x8U)                                              /*!< OSC_CR.SC2P Mask                        */
#define OSC_CR_SC2P_SHIFT                        (3U)                                                /*!< OSC_CR.SC2P Position                    */
#define OSC_CR_SC2P(x)                           (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< OSC_CR.SC2P Field                       */
#define OSC_CR_EREFSTEN_MASK                     (0x20U)                                             /*!< OSC_CR.EREFSTEN Mask                    */
#define OSC_CR_EREFSTEN_SHIFT                    (5U)                                                /*!< OSC_CR.EREFSTEN Position                */
#define OSC_CR_EREFSTEN(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< OSC_CR.EREFSTEN Field                   */
#define OSC_CR_ERCLKEN_MASK                      (0x80U)                                             /*!< OSC_CR.ERCLKEN Mask                     */
#define OSC_CR_ERCLKEN_SHIFT                     (7U)                                                /*!< OSC_CR.ERCLKEN Position                 */
#define OSC_CR_ERCLKEN(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< OSC_CR.ERCLKEN Field                    */
/* ------- DIV Bit Fields                           ------ */
#define OSC_DIV_ERPS_MASK                        (0xC0U)                                             /*!< OSC_DIV.ERPS Mask                       */
#define OSC_DIV_ERPS_SHIFT                       (6U)                                                /*!< OSC_DIV.ERPS Position                   */
#define OSC_DIV_ERPS(x)                          (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< OSC_DIV.ERPS Field                      */
/**
 * @} */ /* End group OSC_Register_Masks_GROUP 
 */

/* OSC - Peripheral instance base addresses */
#define OSC_BasePtr                    0x40065000UL //!< Peripheral base address
#define OSC                            ((OSC_Type *) OSC_BasePtr) //!< Freescale base pointer
#define OSC_BASE_PTR                   (OSC) //!< Freescale style base pointer
/**
 * @} */ /* End group OSC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PIT_Peripheral_access_layer_GROUP PIT Peripheral Access Layer
* @brief C Struct for PIT
* @{
*/

/* ================================================================================ */
/* ================           PIT0 (file:PIT0_MKL82Z7)             ================ */
/* ================================================================================ */

/**
 * @brief Periodic Interrupt Timer
 */
/**
* @addtogroup PIT_structs_GROUP PIT struct
* @brief Struct for PIT
* @{
*/
typedef struct {                                /*       PIT0 Structure                                               */
   __IO uint32_t  MCR;                          /**< 0000: PIT Module Control Register                                  */
        uint8_t   RESERVED_0[220];             
   __I  uint32_t  LTMR64H;                      /**< 00E0: PIT Upper Lifetime Timer Register                            */
   __I  uint32_t  LTMR64L;                      /**< 00E4: PIT Lower Lifetime Timer Register                            */
        uint8_t   RESERVED_1[24];              
   struct {
      __IO uint32_t  LDVAL;                     /**< 0100: Timer Load Value Register                                    */
      __I  uint32_t  CVAL;                      /**< 0104: Current Timer Value Register                                 */
      __IO uint32_t  TCTRL;                     /**< 0108: Timer Control Register                                       */
      __IO uint32_t  TFLG;                      /**< 010C: Timer Flag Register                                          */
   } CHANNEL[4];                                /**< 0100: (cluster: size=0x0040, 64)                                   */
} PIT_Type;

/**
 * @} */ /* End group PIT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PIT0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PIT_Register_Masks_GROUP PIT Register Masks
* @brief Register Masks for PIT
* @{
*/
/* ------- MCR Bit Fields                           ------ */
#define PIT_MCR_FRZ_MASK                         (0x1U)                                              /*!< PIT0_MCR.FRZ Mask                       */
#define PIT_MCR_FRZ_SHIFT                        (0U)                                                /*!< PIT0_MCR.FRZ Position                   */
#define PIT_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< PIT0_MCR.FRZ Field                      */
#define PIT_MCR_MDIS_MASK                        (0x2U)                                              /*!< PIT0_MCR.MDIS Mask                      */
#define PIT_MCR_MDIS_SHIFT                       (1U)                                                /*!< PIT0_MCR.MDIS Position                  */
#define PIT_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< PIT0_MCR.MDIS Field                     */
/* ------- LTMR64H Bit Fields                       ------ */
#define PIT_LTMR64H_LTH_MASK                     (0xFFFFFFFFU)                                       /*!< PIT0_LTMR64H.LTH Mask                   */
#define PIT_LTMR64H_LTH_SHIFT                    (0U)                                                /*!< PIT0_LTMR64H.LTH Position               */
#define PIT_LTMR64H_LTH(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< PIT0_LTMR64H.LTH Field                  */
/* ------- LTMR64L Bit Fields                       ------ */
#define PIT_LTMR64L_LTL_MASK                     (0xFFFFFFFFU)                                       /*!< PIT0_LTMR64L.LTL Mask                   */
#define PIT_LTMR64L_LTL_SHIFT                    (0U)                                                /*!< PIT0_LTMR64L.LTL Position               */
#define PIT_LTMR64L_LTL(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< PIT0_LTMR64L.LTL Field                  */
/* ------- LDVAL Bit Fields                         ------ */
#define PIT_LDVAL_TSV_MASK                       (0xFFFFFFFFU)                                       /*!< PIT0_LDVAL.TSV Mask                     */
#define PIT_LDVAL_TSV_SHIFT                      (0U)                                                /*!< PIT0_LDVAL.TSV Position                 */
#define PIT_LDVAL_TSV(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< PIT0_LDVAL.TSV Field                    */
/* ------- CVAL Bit Fields                          ------ */
#define PIT_CVAL_TVL_MASK                        (0xFFFFFFFFU)                                       /*!< PIT0_CVAL.TVL Mask                      */
#define PIT_CVAL_TVL_SHIFT                       (0U)                                                /*!< PIT0_CVAL.TVL Position                  */
#define PIT_CVAL_TVL(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< PIT0_CVAL.TVL Field                     */
/* ------- TCTRL Bit Fields                         ------ */
#define PIT_TCTRL_TEN_MASK                       (0x1U)                                              /*!< PIT0_TCTRL.TEN Mask                     */
#define PIT_TCTRL_TEN_SHIFT                      (0U)                                                /*!< PIT0_TCTRL.TEN Position                 */
#define PIT_TCTRL_TEN(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< PIT0_TCTRL.TEN Field                    */
#define PIT_TCTRL_TIE_MASK                       (0x2U)                                              /*!< PIT0_TCTRL.TIE Mask                     */
#define PIT_TCTRL_TIE_SHIFT                      (1U)                                                /*!< PIT0_TCTRL.TIE Position                 */
#define PIT_TCTRL_TIE(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< PIT0_TCTRL.TIE Field                    */
#define PIT_TCTRL_CHN_MASK                       (0x4U)                                              /*!< PIT0_TCTRL.CHN Mask                     */
#define PIT_TCTRL_CHN_SHIFT                      (2U)                                                /*!< PIT0_TCTRL.CHN Position                 */
#define PIT_TCTRL_CHN(x)                         (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< PIT0_TCTRL.CHN Field                    */
/* ------- TFLG Bit Fields                          ------ */
#define PIT_TFLG_TIF_MASK                        (0x1U)                                              /*!< PIT0_TFLG.TIF Mask                      */
#define PIT_TFLG_TIF_SHIFT                       (0U)                                                /*!< PIT0_TFLG.TIF Position                  */
#define PIT_TFLG_TIF(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< PIT0_TFLG.TIF Field                     */
/**
 * @} */ /* End group PIT_Register_Masks_GROUP 
 */

/* PIT0 - Peripheral instance base addresses */
#define PIT0_BasePtr                   0x40037000UL //!< Peripheral base address
#define PIT0                           ((PIT_Type *) PIT0_BasePtr) //!< Freescale base pointer
#define PIT0_BASE_PTR                  (PIT0) //!< Freescale style base pointer
/**
 * @} */ /* End group PIT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PMC_Peripheral_access_layer_GROUP PMC Peripheral Access Layer
* @brief C Struct for PMC
* @{
*/

/* ================================================================================ */
/* ================           PMC (file:PMC_MKL82Z7)               ================ */
/* ================================================================================ */

/**
 * @brief Power Management Controller
 */
/**
* @addtogroup PMC_structs_GROUP PMC struct
* @brief Struct for PMC
* @{
*/
typedef struct {                                /*       PMC Structure                                                */
   __IO uint8_t   LVDSC1;                       /**< 0000: Low Voltage Detect Status And Control 1 register             */
   __IO uint8_t   LVDSC2;                       /**< 0001: Low Voltage Detect Status And Control 2 register             */
   __IO uint8_t   REGSC;                        /**< 0002: Regulator Status And Control register                        */
        uint8_t   RESERVED_0[8];               
   __IO uint8_t   HVDSC1;                       /**< 000B: High Voltage Detect Status And Control 1 register            */
} PMC_Type;

/**
 * @} */ /* End group PMC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PMC_Register_Masks_GROUP PMC Register Masks
* @brief Register Masks for PMC
* @{
*/
/* ------- LVDSC1 Bit Fields                        ------ */
#define PMC_LVDSC1_LVDV_MASK                     (0x3U)                                              /*!< PMC_LVDSC1.LVDV Mask                    */
#define PMC_LVDSC1_LVDV_SHIFT                    (0U)                                                /*!< PMC_LVDSC1.LVDV Position                */
#define PMC_LVDSC1_LVDV(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< PMC_LVDSC1.LVDV Field                   */
#define PMC_LVDSC1_LVDRE_MASK                    (0x10U)                                             /*!< PMC_LVDSC1.LVDRE Mask                   */
#define PMC_LVDSC1_LVDRE_SHIFT                   (4U)                                                /*!< PMC_LVDSC1.LVDRE Position               */
#define PMC_LVDSC1_LVDRE(x)                      (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< PMC_LVDSC1.LVDRE Field                  */
#define PMC_LVDSC1_LVDIE_MASK                    (0x20U)                                             /*!< PMC_LVDSC1.LVDIE Mask                   */
#define PMC_LVDSC1_LVDIE_SHIFT                   (5U)                                                /*!< PMC_LVDSC1.LVDIE Position               */
#define PMC_LVDSC1_LVDIE(x)                      (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< PMC_LVDSC1.LVDIE Field                  */
#define PMC_LVDSC1_LVDACK_MASK                   (0x40U)                                             /*!< PMC_LVDSC1.LVDACK Mask                  */
#define PMC_LVDSC1_LVDACK_SHIFT                  (6U)                                                /*!< PMC_LVDSC1.LVDACK Position              */
#define PMC_LVDSC1_LVDACK(x)                     (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< PMC_LVDSC1.LVDACK Field                 */
#define PMC_LVDSC1_LVDF_MASK                     (0x80U)                                             /*!< PMC_LVDSC1.LVDF Mask                    */
#define PMC_LVDSC1_LVDF_SHIFT                    (7U)                                                /*!< PMC_LVDSC1.LVDF Position                */
#define PMC_LVDSC1_LVDF(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< PMC_LVDSC1.LVDF Field                   */
/* ------- LVDSC2 Bit Fields                        ------ */
#define PMC_LVDSC2_LVWV_MASK                     (0x3U)                                              /*!< PMC_LVDSC2.LVWV Mask                    */
#define PMC_LVDSC2_LVWV_SHIFT                    (0U)                                                /*!< PMC_LVDSC2.LVWV Position                */
#define PMC_LVDSC2_LVWV(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< PMC_LVDSC2.LVWV Field                   */
#define PMC_LVDSC2_LVWIE_MASK                    (0x20U)                                             /*!< PMC_LVDSC2.LVWIE Mask                   */
#define PMC_LVDSC2_LVWIE_SHIFT                   (5U)                                                /*!< PMC_LVDSC2.LVWIE Position               */
#define PMC_LVDSC2_LVWIE(x)                      (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< PMC_LVDSC2.LVWIE Field                  */
#define PMC_LVDSC2_LVWACK_MASK                   (0x40U)                                             /*!< PMC_LVDSC2.LVWACK Mask                  */
#define PMC_LVDSC2_LVWACK_SHIFT                  (6U)                                                /*!< PMC_LVDSC2.LVWACK Position              */
#define PMC_LVDSC2_LVWACK(x)                     (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< PMC_LVDSC2.LVWACK Field                 */
#define PMC_LVDSC2_LVWF_MASK                     (0x80U)                                             /*!< PMC_LVDSC2.LVWF Mask                    */
#define PMC_LVDSC2_LVWF_SHIFT                    (7U)                                                /*!< PMC_LVDSC2.LVWF Position                */
#define PMC_LVDSC2_LVWF(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< PMC_LVDSC2.LVWF Field                   */
/* ------- REGSC Bit Fields                         ------ */
#define PMC_REGSC_BGBE_MASK                      (0x1U)                                              /*!< PMC_REGSC.BGBE Mask                     */
#define PMC_REGSC_BGBE_SHIFT                     (0U)                                                /*!< PMC_REGSC.BGBE Position                 */
#define PMC_REGSC_BGBE(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< PMC_REGSC.BGBE Field                    */
#define PMC_REGSC_REGONS_MASK                    (0x4U)                                              /*!< PMC_REGSC.REGONS Mask                   */
#define PMC_REGSC_REGONS_SHIFT                   (2U)                                                /*!< PMC_REGSC.REGONS Position               */
#define PMC_REGSC_REGONS(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< PMC_REGSC.REGONS Field                  */
#define PMC_REGSC_ACKISO_MASK                    (0x8U)                                              /*!< PMC_REGSC.ACKISO Mask                   */
#define PMC_REGSC_ACKISO_SHIFT                   (3U)                                                /*!< PMC_REGSC.ACKISO Position               */
#define PMC_REGSC_ACKISO(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< PMC_REGSC.ACKISO Field                  */
#define PMC_REGSC_BGEN_MASK                      (0x10U)                                             /*!< PMC_REGSC.BGEN Mask                     */
#define PMC_REGSC_BGEN_SHIFT                     (4U)                                                /*!< PMC_REGSC.BGEN Position                 */
#define PMC_REGSC_BGEN(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< PMC_REGSC.BGEN Field                    */
#define PMC_REGSC_VLPO_MASK                      (0x40U)                                             /*!< PMC_REGSC.VLPO Mask                     */
#define PMC_REGSC_VLPO_SHIFT                     (6U)                                                /*!< PMC_REGSC.VLPO Position                 */
#define PMC_REGSC_VLPO(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< PMC_REGSC.VLPO Field                    */
/* ------- HVDSC1 Bit Fields                        ------ */
#define PMC_HVDSC1_HVDV_MASK                     (0x1U)                                              /*!< PMC_HVDSC1.HVDV Mask                    */
#define PMC_HVDSC1_HVDV_SHIFT                    (0U)                                                /*!< PMC_HVDSC1.HVDV Position                */
#define PMC_HVDSC1_HVDV(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< PMC_HVDSC1.HVDV Field                   */
#define PMC_HVDSC1_HVDRE_MASK                    (0x10U)                                             /*!< PMC_HVDSC1.HVDRE Mask                   */
#define PMC_HVDSC1_HVDRE_SHIFT                   (4U)                                                /*!< PMC_HVDSC1.HVDRE Position               */
#define PMC_HVDSC1_HVDRE(x)                      (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< PMC_HVDSC1.HVDRE Field                  */
#define PMC_HVDSC1_HVDIE_MASK                    (0x20U)                                             /*!< PMC_HVDSC1.HVDIE Mask                   */
#define PMC_HVDSC1_HVDIE_SHIFT                   (5U)                                                /*!< PMC_HVDSC1.HVDIE Position               */
#define PMC_HVDSC1_HVDIE(x)                      (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< PMC_HVDSC1.HVDIE Field                  */
#define PMC_HVDSC1_HVDACK_MASK                   (0x40U)                                             /*!< PMC_HVDSC1.HVDACK Mask                  */
#define PMC_HVDSC1_HVDACK_SHIFT                  (6U)                                                /*!< PMC_HVDSC1.HVDACK Position              */
#define PMC_HVDSC1_HVDACK(x)                     (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< PMC_HVDSC1.HVDACK Field                 */
#define PMC_HVDSC1_HVDF_MASK                     (0x80U)                                             /*!< PMC_HVDSC1.HVDF Mask                    */
#define PMC_HVDSC1_HVDF_SHIFT                    (7U)                                                /*!< PMC_HVDSC1.HVDF Position                */
#define PMC_HVDSC1_HVDF(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< PMC_HVDSC1.HVDF Field                   */
/**
 * @} */ /* End group PMC_Register_Masks_GROUP 
 */

/* PMC - Peripheral instance base addresses */
#define PMC_BasePtr                    0x4007D000UL //!< Peripheral base address
#define PMC                            ((PMC_Type *) PMC_BasePtr) //!< Freescale base pointer
#define PMC_BASE_PTR                   (PMC) //!< Freescale style base pointer
/**
 * @} */ /* End group PMC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTA (file:PORTA_MKL82Z7)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */
/**
* @addtogroup PORT_structs_GROUP PORT struct
* @brief Struct for PORT
* @{
*/
typedef struct {                                /*       PORTA Structure                                              */
   __IO uint32_t  PCR[32];                      /**< 0000: Pin Control Register                                         */
   __O  uint32_t  GPCLR;                        /**< 0080: Global Pin Control Low Register                              */
   __O  uint32_t  GPCHR;                        /**< 0084: Global Pin Control High Register                             */
   __O  uint32_t  GICLR;                        /**< 0088: Global Interrupt Control Low Register                        */
   __O  uint32_t  GICHR;                        /**< 008C: Global Interrupt Control High Register                       */
        uint8_t   RESERVED_0[16];              
   __IO uint32_t  ISFR;                         /**< 00A0: Interrupt Status Flag Register                               */
} PORT_Type;

/**
 * @} */ /* End group PORT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PORTA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PORT_Register_Masks_GROUP PORT Register Masks
* @brief Register Masks for PORT
* @{
*/
/* ------- PCR Bit Fields                           ------ */
#define PORT_PCR_PS_MASK                         (0x1U)                                              /*!< PORTA_PCR.PS Mask                       */
#define PORT_PCR_PS_SHIFT                        (0U)                                                /*!< PORTA_PCR.PS Position                   */
#define PORT_PCR_PS(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< PORTA_PCR.PS Field                      */
#define PORT_PCR_PE_MASK                         (0x2U)                                              /*!< PORTA_PCR.PE Mask                       */
#define PORT_PCR_PE_SHIFT                        (1U)                                                /*!< PORTA_PCR.PE Position                   */
#define PORT_PCR_PE(x)                           (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< PORTA_PCR.PE Field                      */
#define PORT_PCR_SRE_MASK                        (0x4U)                                              /*!< PORTA_PCR.SRE Mask                      */
#define PORT_PCR_SRE_SHIFT                       (2U)                                                /*!< PORTA_PCR.SRE Position                  */
#define PORT_PCR_SRE(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< PORTA_PCR.SRE Field                     */
#define PORT_PCR_PFE_MASK                        (0x10U)                                             /*!< PORTA_PCR.PFE Mask                      */
#define PORT_PCR_PFE_SHIFT                       (4U)                                                /*!< PORTA_PCR.PFE Position                  */
#define PORT_PCR_PFE(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< PORTA_PCR.PFE Field                     */
#define PORT_PCR_ODE_MASK                        (0x20U)                                             /*!< PORTA_PCR.ODE Mask                      */
#define PORT_PCR_ODE_SHIFT                       (5U)                                                /*!< PORTA_PCR.ODE Position                  */
#define PORT_PCR_ODE(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< PORTA_PCR.ODE Field                     */
#define PORT_PCR_MUX_MASK                        (0x700U)                                            /*!< PORTA_PCR.MUX Mask                      */
#define PORT_PCR_MUX_SHIFT                       (8U)                                                /*!< PORTA_PCR.MUX Position                  */
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x))<<8U))&0x700UL)         /*!< PORTA_PCR.MUX Field                     */
#define PORT_PCR_LK_MASK                         (0x8000U)                                           /*!< PORTA_PCR.LK Mask                       */
#define PORT_PCR_LK_SHIFT                        (15U)                                               /*!< PORTA_PCR.LK Position                   */
#define PORT_PCR_LK(x)                           (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< PORTA_PCR.LK Field                      */
#define PORT_PCR_IRQC_MASK                       (0xF0000U)                                          /*!< PORTA_PCR.IRQC Mask                     */
#define PORT_PCR_IRQC_SHIFT                      (16U)                                               /*!< PORTA_PCR.IRQC Position                 */
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x))<<16U))&0xF0000UL)      /*!< PORTA_PCR.IRQC Field                    */
#define PORT_PCR_ISF_MASK                        (0x1000000U)                                        /*!< PORTA_PCR.ISF Mask                      */
#define PORT_PCR_ISF_SHIFT                       (24U)                                               /*!< PORTA_PCR.ISF Position                  */
#define PORT_PCR_ISF(x)                          (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< PORTA_PCR.ISF Field                     */
/* ------- GPCLR Bit Fields                         ------ */
#define PORT_GPCLR_GPWD_MASK                     (0xFFFFU)                                           /*!< PORTA_GPCLR.GPWD Mask                   */
#define PORT_GPCLR_GPWD_SHIFT                    (0U)                                                /*!< PORTA_GPCLR.GPWD Position               */
#define PORT_GPCLR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< PORTA_GPCLR.GPWD Field                  */
#define PORT_GPCLR_GPWE_MASK                     (0xFFFF0000U)                                       /*!< PORTA_GPCLR.GPWE Mask                   */
#define PORT_GPCLR_GPWE_SHIFT                    (16U)                                               /*!< PORTA_GPCLR.GPWE Position               */
#define PORT_GPCLR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< PORTA_GPCLR.GPWE Field                  */
/* ------- GPCHR Bit Fields                         ------ */
#define PORT_GPCHR_GPWD_MASK                     (0xFFFFU)                                           /*!< PORTA_GPCHR.GPWD Mask                   */
#define PORT_GPCHR_GPWD_SHIFT                    (0U)                                                /*!< PORTA_GPCHR.GPWD Position               */
#define PORT_GPCHR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< PORTA_GPCHR.GPWD Field                  */
#define PORT_GPCHR_GPWE_MASK                     (0xFFFF0000U)                                       /*!< PORTA_GPCHR.GPWE Mask                   */
#define PORT_GPCHR_GPWE_SHIFT                    (16U)                                               /*!< PORTA_GPCHR.GPWE Position               */
#define PORT_GPCHR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< PORTA_GPCHR.GPWE Field                  */
/* ------- GICLR Bit Fields                         ------ */
#define PORT_GICLR_GIWE_MASK                     (0xFFFFU)                                           /*!< PORTA_GICLR.GIWE Mask                   */
#define PORT_GICLR_GIWE_SHIFT                    (0U)                                                /*!< PORTA_GICLR.GIWE Position               */
#define PORT_GICLR_GIWE(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< PORTA_GICLR.GIWE Field                  */
#define PORT_GICLR_GIWD_MASK                     (0xFFFF0000U)                                       /*!< PORTA_GICLR.GIWD Mask                   */
#define PORT_GICLR_GIWD_SHIFT                    (16U)                                               /*!< PORTA_GICLR.GIWD Position               */
#define PORT_GICLR_GIWD(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< PORTA_GICLR.GIWD Field                  */
/* ------- GICHR Bit Fields                         ------ */
#define PORT_GICHR_GIWE_MASK                     (0xFFFFU)                                           /*!< PORTA_GICHR.GIWE Mask                   */
#define PORT_GICHR_GIWE_SHIFT                    (0U)                                                /*!< PORTA_GICHR.GIWE Position               */
#define PORT_GICHR_GIWE(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< PORTA_GICHR.GIWE Field                  */
#define PORT_GICHR_GIWD_MASK                     (0xFFFF0000U)                                       /*!< PORTA_GICHR.GIWD Mask                   */
#define PORT_GICHR_GIWD_SHIFT                    (16U)                                               /*!< PORTA_GICHR.GIWD Position               */
#define PORT_GICHR_GIWD(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< PORTA_GICHR.GIWD Field                  */
/* ------- ISFR Bit Fields                          ------ */
/**
 * @} */ /* End group PORT_Register_Masks_GROUP 
 */

/* PORTA - Peripheral instance base addresses */
#define PORTA_BasePtr                  0x40049000UL //!< Peripheral base address
#define PORTA                          ((PORT_Type *) PORTA_BasePtr) //!< Freescale base pointer
#define PORTA_BASE_PTR                 (PORTA) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTB (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTB - Peripheral instance base addresses */
#define PORTB_BasePtr                  0x4004A000UL //!< Peripheral base address
#define PORTB                          ((PORT_Type *) PORTB_BasePtr) //!< Freescale base pointer
#define PORTB_BASE_PTR                 (PORTB) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTC (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTC - Peripheral instance base addresses */
#define PORTC_BasePtr                  0x4004B000UL //!< Peripheral base address
#define PORTC                          ((PORT_Type *) PORTC_BasePtr) //!< Freescale base pointer
#define PORTC_BASE_PTR                 (PORTC) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTD (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTD - Peripheral instance base addresses */
#define PORTD_BasePtr                  0x4004C000UL //!< Peripheral base address
#define PORTD                          ((PORT_Type *) PORTD_BasePtr) //!< Freescale base pointer
#define PORTD_BASE_PTR                 (PORTD) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTE (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTE - Peripheral instance base addresses */
#define PORTE_BasePtr                  0x4004D000UL //!< Peripheral base address
#define PORTE                          ((PORT_Type *) PORTE_BasePtr) //!< Freescale base pointer
#define PORTE_BASE_PTR                 (PORTE) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup QSPI_Peripheral_access_layer_GROUP QSPI Peripheral Access Layer
* @brief C Struct for QSPI
* @{
*/

/* ================================================================================ */
/* ================           QSPI0 (file:QSPI0_0x4005A000)        ================ */
/* ================================================================================ */

/**
 * @brief QSPI
 */
/**
* @addtogroup QSPI_structs_GROUP QSPI struct
* @brief Struct for QSPI
* @{
*/
typedef struct {                                /*       QSPI0 Structure                                              */
   __IO uint32_t  MCR;                          /**< 0000: Module Configuration Register                                */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  IPCR;                         /**< 0008: IP Configuration Register                                    */
   __IO uint32_t  FLSHCR;                       /**< 000C: Flash Configuration Register                                 */
   __IO uint32_t  BUF0CR;                       /**< 0010: Buffer0 Configuration Register                               */
   __IO uint32_t  BUF1CR;                       /**< 0014: Buffer1 Configuration Register                               */
   __IO uint32_t  BUF2CR;                       /**< 0018: Buffer2 Configuration Register                               */
   __IO uint32_t  BUF3CR;                       /**< 001C: Buffer3 Configuration Register                               */
   __IO uint32_t  BFGENCR;                      /**< 0020: Buffer Generic Configuration Register                        */
   __IO uint32_t  SOCCR;                        /**< 0024: SOC Configuration Register                                   */
        uint8_t   RESERVED_1[8];               
   __IO uint32_t  BUF0IND;                      /**< 0030: Buffer0 Top Index Register                                   */
   __IO uint32_t  BUF1IND;                      /**< 0034: Buffer1 Top Index Register                                   */
   __IO uint32_t  BUF2IND;                      /**< 0038: Buffer2 Top Index Register                                   */
        uint8_t   RESERVED_2[196];             
   __IO uint32_t  SFAR;                         /**< 0100: Serial Flash Address Register                                */
   __IO uint32_t  SFACR;                        /**< 0104: Serial Flash Address Configuration Register                  */
   __IO uint32_t  SMPR;                         /**< 0108: Sampling Register                                            */
   __I  uint32_t  RBSR;                         /**< 010C: RX Buffer Status Register                                    */
   __IO uint32_t  RBCT;                         /**< 0110: RX Buffer Control Register                                   */
        uint8_t   RESERVED_3[60];              
   __I  uint32_t  TBSR;                         /**< 0150: TX Buffer Status Register                                    */
   __IO uint32_t  TBDR;                         /**< 0154: TX Buffer Data Register                                      */
   __IO uint32_t  TBCT;                         /**< 0158: Tx Buffer Control Register                                   */
   __I  uint32_t  SR;                           /**< 015C: Status Register                                              */
   __IO uint32_t  FR;                           /**< 0160: Flag Register                                                */
   __IO uint32_t  RSER;                         /**< 0164: Interrupt and DMA Request Select and Enable Register         */
   __I  uint32_t  SPNDST;                       /**< 0168: Sequence Suspend Status Register                             */
   __O  uint32_t  SPTRCLR;                      /**< 016C: Sequence Pointer Clear Register                              */
        uint8_t   RESERVED_4[16];              
   __IO uint32_t  SFA1AD;                       /**< 0180: Serial Flash A1 Top Address                                  */
   __IO uint32_t  SFA2AD;                       /**< 0184: Serial Flash A2 Top Address                                  */
   __IO uint32_t  SFB1AD;                       /**< 0188: Serial Flash B1Top Address                                   */
   __IO uint32_t  SFB2AD;                       /**< 018C: Serial Flash B2Top Address                                   */
   __IO uint32_t  DLPR;                         /**< 0190: Data Learn Pattern Register                                  */
        uint8_t   RESERVED_5[108];             
   __I  uint32_t  RBDR[16];                     /**< 0200: RX Buffer Data Register                                      */
        uint8_t   RESERVED_6[192];             
   __IO uint32_t  LUTKEY;                       /**< 0300: LUT Key Register                                             */
   __IO uint32_t  LCKCR;                        /**< 0304: LUT Lock Configuration Register                              */
        uint8_t   RESERVED_7[8];               
   __IO uint32_t  LUT[64];                      /**< 0310: Look-up Table register                                       */
} QSPI_Type;

/**
 * @} */ /* End group QSPI_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'QSPI0' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup QSPI_Register_Masks_GROUP QSPI Register Masks
* @brief Register Masks for QSPI
* @{
*/
/* ------- MCR Bit Fields                           ------ */
#define QSPI_MCR_SWRSTSD_MASK                    (0x1U)                                              /*!< QSPI0_MCR.SWRSTSD Mask                  */
#define QSPI_MCR_SWRSTSD_SHIFT                   (0U)                                                /*!< QSPI0_MCR.SWRSTSD Position              */
#define QSPI_MCR_SWRSTSD(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< QSPI0_MCR.SWRSTSD Field                 */
#define QSPI_MCR_SWRSTHD_MASK                    (0x2U)                                              /*!< QSPI0_MCR.SWRSTHD Mask                  */
#define QSPI_MCR_SWRSTHD_SHIFT                   (1U)                                                /*!< QSPI0_MCR.SWRSTHD Position              */
#define QSPI_MCR_SWRSTHD(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< QSPI0_MCR.SWRSTHD Field                 */
#define QSPI_MCR_END_CFG_MASK                    (0xCU)                                              /*!< QSPI0_MCR.END_CFG Mask                  */
#define QSPI_MCR_END_CFG_SHIFT                   (2U)                                                /*!< QSPI0_MCR.END_CFG Position              */
#define QSPI_MCR_END_CFG(x)                      (((uint32_t)(((uint32_t)(x))<<2U))&0xCUL)           /*!< QSPI0_MCR.END_CFG Field                 */
#define QSPI_MCR_DQS_LAT_EN_MASK                 (0x20U)                                             /*!< QSPI0_MCR.DQS_LAT_EN Mask               */
#define QSPI_MCR_DQS_LAT_EN_SHIFT                (5U)                                                /*!< QSPI0_MCR.DQS_LAT_EN Position           */
#define QSPI_MCR_DQS_LAT_EN(x)                   (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< QSPI0_MCR.DQS_LAT_EN Field              */
#define QSPI_MCR_DQS_EN_MASK                     (0x40U)                                             /*!< QSPI0_MCR.DQS_EN Mask                   */
#define QSPI_MCR_DQS_EN_SHIFT                    (6U)                                                /*!< QSPI0_MCR.DQS_EN Position               */
#define QSPI_MCR_DQS_EN(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< QSPI0_MCR.DQS_EN Field                  */
#define QSPI_MCR_DDR_EN_MASK                     (0x80U)                                             /*!< QSPI0_MCR.DDR_EN Mask                   */
#define QSPI_MCR_DDR_EN_SHIFT                    (7U)                                                /*!< QSPI0_MCR.DDR_EN Position               */
#define QSPI_MCR_DDR_EN(x)                       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< QSPI0_MCR.DDR_EN Field                  */
#define QSPI_MCR_CLR_RXF_MASK                    (0x400U)                                            /*!< QSPI0_MCR.CLR_RXF Mask                  */
#define QSPI_MCR_CLR_RXF_SHIFT                   (10U)                                               /*!< QSPI0_MCR.CLR_RXF Position              */
#define QSPI_MCR_CLR_RXF(x)                      (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< QSPI0_MCR.CLR_RXF Field                 */
#define QSPI_MCR_CLR_TXF_MASK                    (0x800U)                                            /*!< QSPI0_MCR.CLR_TXF Mask                  */
#define QSPI_MCR_CLR_TXF_SHIFT                   (11U)                                               /*!< QSPI0_MCR.CLR_TXF Position              */
#define QSPI_MCR_CLR_TXF(x)                      (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< QSPI0_MCR.CLR_TXF Field                 */
#define QSPI_MCR_MDIS_MASK                       (0x4000U)                                           /*!< QSPI0_MCR.MDIS Mask                     */
#define QSPI_MCR_MDIS_SHIFT                      (14U)                                               /*!< QSPI0_MCR.MDIS Position                 */
#define QSPI_MCR_MDIS(x)                         (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< QSPI0_MCR.MDIS Field                    */
#define QSPI_MCR_SCLKCFG_MASK                    (0xFF000000U)                                       /*!< QSPI0_MCR.SCLKCFG Mask                  */
#define QSPI_MCR_SCLKCFG_SHIFT                   (24U)                                               /*!< QSPI0_MCR.SCLKCFG Position              */
#define QSPI_MCR_SCLKCFG(x)                      (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< QSPI0_MCR.SCLKCFG Field                 */
/* ------- IPCR Bit Fields                          ------ */
#define QSPI_IPCR_IDATSZ_MASK                    (0xFFFFU)                                           /*!< QSPI0_IPCR.IDATSZ Mask                  */
#define QSPI_IPCR_IDATSZ_SHIFT                   (0U)                                                /*!< QSPI0_IPCR.IDATSZ Position              */
#define QSPI_IPCR_IDATSZ(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< QSPI0_IPCR.IDATSZ Field                 */
#define QSPI_IPCR_PAR_EN_MASK                    (0x10000U)                                          /*!< QSPI0_IPCR.PAR_EN Mask                  */
#define QSPI_IPCR_PAR_EN_SHIFT                   (16U)                                               /*!< QSPI0_IPCR.PAR_EN Position              */
#define QSPI_IPCR_PAR_EN(x)                      (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< QSPI0_IPCR.PAR_EN Field                 */
#define QSPI_IPCR_SEQID_MASK                     (0xF000000U)                                        /*!< QSPI0_IPCR.SEQID Mask                   */
#define QSPI_IPCR_SEQID_SHIFT                    (24U)                                               /*!< QSPI0_IPCR.SEQID Position               */
#define QSPI_IPCR_SEQID(x)                       (((uint32_t)(((uint32_t)(x))<<24U))&0xF000000UL)    /*!< QSPI0_IPCR.SEQID Field                  */
/* ------- FLSHCR Bit Fields                        ------ */
#define QSPI_FLSHCR_TCSS_MASK                    (0xFU)                                              /*!< QSPI0_FLSHCR.TCSS Mask                  */
#define QSPI_FLSHCR_TCSS_SHIFT                   (0U)                                                /*!< QSPI0_FLSHCR.TCSS Position              */
#define QSPI_FLSHCR_TCSS(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< QSPI0_FLSHCR.TCSS Field                 */
#define QSPI_FLSHCR_TCSH_MASK                    (0xF00U)                                            /*!< QSPI0_FLSHCR.TCSH Mask                  */
#define QSPI_FLSHCR_TCSH_SHIFT                   (8U)                                                /*!< QSPI0_FLSHCR.TCSH Position              */
#define QSPI_FLSHCR_TCSH(x)                      (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< QSPI0_FLSHCR.TCSH Field                 */
#define QSPI_FLSHCR_TDH_MASK                     (0x30000U)                                          /*!< QSPI0_FLSHCR.TDH Mask                   */
#define QSPI_FLSHCR_TDH_SHIFT                    (16U)                                               /*!< QSPI0_FLSHCR.TDH Position               */
#define QSPI_FLSHCR_TDH(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0x30000UL)      /*!< QSPI0_FLSHCR.TDH Field                  */
/* ------- BUF0CR Bit Fields                        ------ */
#define QSPI_BUF0CR_MSTRID_MASK                  (0xFU)                                              /*!< QSPI0_BUF0CR.MSTRID Mask                */
#define QSPI_BUF0CR_MSTRID_SHIFT                 (0U)                                                /*!< QSPI0_BUF0CR.MSTRID Position            */
#define QSPI_BUF0CR_MSTRID(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< QSPI0_BUF0CR.MSTRID Field               */
#define QSPI_BUF0CR_ADATSZ_MASK                  (0x7F00U)                                           /*!< QSPI0_BUF0CR.ADATSZ Mask                */
#define QSPI_BUF0CR_ADATSZ_SHIFT                 (8U)                                                /*!< QSPI0_BUF0CR.ADATSZ Position            */
#define QSPI_BUF0CR_ADATSZ(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0x7F00UL)        /*!< QSPI0_BUF0CR.ADATSZ Field               */
#define QSPI_BUF0CR_HP_EN_MASK                   (0x80000000U)                                       /*!< QSPI0_BUF0CR.HP_EN Mask                 */
#define QSPI_BUF0CR_HP_EN_SHIFT                  (31U)                                               /*!< QSPI0_BUF0CR.HP_EN Position             */
#define QSPI_BUF0CR_HP_EN(x)                     (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< QSPI0_BUF0CR.HP_EN Field                */
/* ------- BUF1CR Bit Fields                        ------ */
#define QSPI_BUF1CR_MSTRID_MASK                  (0xFU)                                              /*!< QSPI0_BUF1CR.MSTRID Mask                */
#define QSPI_BUF1CR_MSTRID_SHIFT                 (0U)                                                /*!< QSPI0_BUF1CR.MSTRID Position            */
#define QSPI_BUF1CR_MSTRID(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< QSPI0_BUF1CR.MSTRID Field               */
#define QSPI_BUF1CR_ADATSZ_MASK                  (0x7F00U)                                           /*!< QSPI0_BUF1CR.ADATSZ Mask                */
#define QSPI_BUF1CR_ADATSZ_SHIFT                 (8U)                                                /*!< QSPI0_BUF1CR.ADATSZ Position            */
#define QSPI_BUF1CR_ADATSZ(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0x7F00UL)        /*!< QSPI0_BUF1CR.ADATSZ Field               */
/* ------- BUF2CR Bit Fields                        ------ */
#define QSPI_BUF2CR_MSTRID_MASK                  (0xFU)                                              /*!< QSPI0_BUF2CR.MSTRID Mask                */
#define QSPI_BUF2CR_MSTRID_SHIFT                 (0U)                                                /*!< QSPI0_BUF2CR.MSTRID Position            */
#define QSPI_BUF2CR_MSTRID(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< QSPI0_BUF2CR.MSTRID Field               */
#define QSPI_BUF2CR_ADATSZ_MASK                  (0x7F00U)                                           /*!< QSPI0_BUF2CR.ADATSZ Mask                */
#define QSPI_BUF2CR_ADATSZ_SHIFT                 (8U)                                                /*!< QSPI0_BUF2CR.ADATSZ Position            */
#define QSPI_BUF2CR_ADATSZ(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0x7F00UL)        /*!< QSPI0_BUF2CR.ADATSZ Field               */
/* ------- BUF3CR Bit Fields                        ------ */
#define QSPI_BUF3CR_MSTRID_MASK                  (0xFU)                                              /*!< QSPI0_BUF3CR.MSTRID Mask                */
#define QSPI_BUF3CR_MSTRID_SHIFT                 (0U)                                                /*!< QSPI0_BUF3CR.MSTRID Position            */
#define QSPI_BUF3CR_MSTRID(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< QSPI0_BUF3CR.MSTRID Field               */
#define QSPI_BUF3CR_ADATSZ_MASK                  (0x7F00U)                                           /*!< QSPI0_BUF3CR.ADATSZ Mask                */
#define QSPI_BUF3CR_ADATSZ_SHIFT                 (8U)                                                /*!< QSPI0_BUF3CR.ADATSZ Position            */
#define QSPI_BUF3CR_ADATSZ(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0x7F00UL)        /*!< QSPI0_BUF3CR.ADATSZ Field               */
#define QSPI_BUF3CR_ALLMST_MASK                  (0x80000000U)                                       /*!< QSPI0_BUF3CR.ALLMST Mask                */
#define QSPI_BUF3CR_ALLMST_SHIFT                 (31U)                                               /*!< QSPI0_BUF3CR.ALLMST Position            */
#define QSPI_BUF3CR_ALLMST(x)                    (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< QSPI0_BUF3CR.ALLMST Field               */
/* ------- BFGENCR Bit Fields                       ------ */
#define QSPI_BFGENCR_SEQID_MASK                  (0xF000U)                                           /*!< QSPI0_BFGENCR.SEQID Mask                */
#define QSPI_BFGENCR_SEQID_SHIFT                 (12U)                                               /*!< QSPI0_BFGENCR.SEQID Position            */
#define QSPI_BFGENCR_SEQID(x)                    (((uint32_t)(((uint32_t)(x))<<12U))&0xF000UL)       /*!< QSPI0_BFGENCR.SEQID Field               */
#define QSPI_BFGENCR_PAR_EN_MASK                 (0x10000U)                                          /*!< QSPI0_BFGENCR.PAR_EN Mask               */
#define QSPI_BFGENCR_PAR_EN_SHIFT                (16U)                                               /*!< QSPI0_BFGENCR.PAR_EN Position           */
#define QSPI_BFGENCR_PAR_EN(x)                   (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< QSPI0_BFGENCR.PAR_EN Field              */
/* ------- SOCCR Bit Fields                         ------ */
#define QSPI_SOCCR_QSPISRC_MASK                  (0x7U)                                              /*!< QSPI0_SOCCR.QSPISRC Mask                */
#define QSPI_SOCCR_QSPISRC_SHIFT                 (0U)                                                /*!< QSPI0_SOCCR.QSPISRC Position            */
#define QSPI_SOCCR_QSPISRC(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< QSPI0_SOCCR.QSPISRC Field               */
#define QSPI_SOCCR_DQSLPEN_MASK                  (0x100U)                                            /*!< QSPI0_SOCCR.DQSLPEN Mask                */
#define QSPI_SOCCR_DQSLPEN_SHIFT                 (8U)                                                /*!< QSPI0_SOCCR.DQSLPEN Position            */
#define QSPI_SOCCR_DQSLPEN(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< QSPI0_SOCCR.DQSLPEN Field               */
#define QSPI_SOCCR_DQSPADLPEN_MASK               (0x200U)                                            /*!< QSPI0_SOCCR.DQSPADLPEN Mask             */
#define QSPI_SOCCR_DQSPADLPEN_SHIFT              (9U)                                                /*!< QSPI0_SOCCR.DQSPADLPEN Position         */
#define QSPI_SOCCR_DQSPADLPEN(x)                 (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< QSPI0_SOCCR.DQSPADLPEN Field            */
#define QSPI_SOCCR_DQSPHASEL_MASK                (0xC00U)                                            /*!< QSPI0_SOCCR.DQSPHASEL Mask              */
#define QSPI_SOCCR_DQSPHASEL_SHIFT               (10U)                                               /*!< QSPI0_SOCCR.DQSPHASEL Position          */
#define QSPI_SOCCR_DQSPHASEL(x)                  (((uint32_t)(((uint32_t)(x))<<10U))&0xC00UL)        /*!< QSPI0_SOCCR.DQSPHASEL Field             */
#define QSPI_SOCCR_DQSINVSEL_MASK                (0x1000U)                                           /*!< QSPI0_SOCCR.DQSINVSEL Mask              */
#define QSPI_SOCCR_DQSINVSEL_SHIFT               (12U)                                               /*!< QSPI0_SOCCR.DQSINVSEL Position          */
#define QSPI_SOCCR_DQSINVSEL(x)                  (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< QSPI0_SOCCR.DQSINVSEL Field             */
#define QSPI_SOCCR_CK2EN_MASK                    (0x2000U)                                           /*!< QSPI0_SOCCR.CK2EN Mask                  */
#define QSPI_SOCCR_CK2EN_SHIFT                   (13U)                                               /*!< QSPI0_SOCCR.CK2EN Position              */
#define QSPI_SOCCR_CK2EN(x)                      (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< QSPI0_SOCCR.CK2EN Field                 */
#define QSPI_SOCCR_DIFFCKEN_MASK                 (0x4000U)                                           /*!< QSPI0_SOCCR.DIFFCKEN Mask               */
#define QSPI_SOCCR_DIFFCKEN_SHIFT                (14U)                                               /*!< QSPI0_SOCCR.DIFFCKEN Position           */
#define QSPI_SOCCR_DIFFCKEN(x)                   (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< QSPI0_SOCCR.DIFFCKEN Field              */
#define QSPI_SOCCR_OCTEN_MASK                    (0x8000U)                                           /*!< QSPI0_SOCCR.OCTEN Mask                  */
#define QSPI_SOCCR_OCTEN_SHIFT                   (15U)                                               /*!< QSPI0_SOCCR.OCTEN Position              */
#define QSPI_SOCCR_OCTEN(x)                      (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< QSPI0_SOCCR.OCTEN Field                 */
#define QSPI_SOCCR_DLYTAPSELA_MASK               (0x3F0000U)                                         /*!< QSPI0_SOCCR.DLYTAPSELA Mask             */
#define QSPI_SOCCR_DLYTAPSELA_SHIFT              (16U)                                               /*!< QSPI0_SOCCR.DLYTAPSELA Position         */
#define QSPI_SOCCR_DLYTAPSELA(x)                 (((uint32_t)(((uint32_t)(x))<<16U))&0x3F0000UL)     /*!< QSPI0_SOCCR.DLYTAPSELA Field            */
#define QSPI_SOCCR_DLYTAPSELB_MASK               (0x3F000000U)                                       /*!< QSPI0_SOCCR.DLYTAPSELB Mask             */
#define QSPI_SOCCR_DLYTAPSELB_SHIFT              (24U)                                               /*!< QSPI0_SOCCR.DLYTAPSELB Position         */
#define QSPI_SOCCR_DLYTAPSELB(x)                 (((uint32_t)(((uint32_t)(x))<<24U))&0x3F000000UL)   /*!< QSPI0_SOCCR.DLYTAPSELB Field            */
/* ------- BUF0IND Bit Fields                       ------ */
#define QSPI_BUF0IND_TPINDX0_MASK                (0xFFFFFFF8U)                                       /*!< QSPI0_BUF0IND.TPINDX0 Mask              */
#define QSPI_BUF0IND_TPINDX0_SHIFT               (3U)                                                /*!< QSPI0_BUF0IND.TPINDX0 Position          */
#define QSPI_BUF0IND_TPINDX0(x)                  (((uint32_t)(((uint32_t)(x))<<3U))&0xFFFFFFF8UL)    /*!< QSPI0_BUF0IND.TPINDX0 Field             */
/* ------- BUF1IND Bit Fields                       ------ */
#define QSPI_BUF1IND_TPINDX1_MASK                (0xFFFFFFF8U)                                       /*!< QSPI0_BUF1IND.TPINDX1 Mask              */
#define QSPI_BUF1IND_TPINDX1_SHIFT               (3U)                                                /*!< QSPI0_BUF1IND.TPINDX1 Position          */
#define QSPI_BUF1IND_TPINDX1(x)                  (((uint32_t)(((uint32_t)(x))<<3U))&0xFFFFFFF8UL)    /*!< QSPI0_BUF1IND.TPINDX1 Field             */
/* ------- BUF2IND Bit Fields                       ------ */
#define QSPI_BUF2IND_TPINDX2_MASK                (0xFFFFFFF8U)                                       /*!< QSPI0_BUF2IND.TPINDX2 Mask              */
#define QSPI_BUF2IND_TPINDX2_SHIFT               (3U)                                                /*!< QSPI0_BUF2IND.TPINDX2 Position          */
#define QSPI_BUF2IND_TPINDX2(x)                  (((uint32_t)(((uint32_t)(x))<<3U))&0xFFFFFFF8UL)    /*!< QSPI0_BUF2IND.TPINDX2 Field             */
/* ------- SFAR Bit Fields                          ------ */
#define QSPI_SFAR_SFADR_MASK                     (0xFFFFFFFFU)                                       /*!< QSPI0_SFAR.SFADR Mask                   */
#define QSPI_SFAR_SFADR_SHIFT                    (0U)                                                /*!< QSPI0_SFAR.SFADR Position               */
#define QSPI_SFAR_SFADR(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< QSPI0_SFAR.SFADR Field                  */
/* ------- SFACR Bit Fields                         ------ */
#define QSPI_SFACR_CAS_MASK                      (0xFU)                                              /*!< QSPI0_SFACR.CAS Mask                    */
#define QSPI_SFACR_CAS_SHIFT                     (0U)                                                /*!< QSPI0_SFACR.CAS Position                */
#define QSPI_SFACR_CAS(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< QSPI0_SFACR.CAS Field                   */
#define QSPI_SFACR_WA_MASK                       (0x10000U)                                          /*!< QSPI0_SFACR.WA Mask                     */
#define QSPI_SFACR_WA_SHIFT                      (16U)                                               /*!< QSPI0_SFACR.WA Position                 */
#define QSPI_SFACR_WA(x)                         (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< QSPI0_SFACR.WA Field                    */
/* ------- SMPR Bit Fields                          ------ */
#define QSPI_SMPR_HSENA_MASK                     (0x1U)                                              /*!< QSPI0_SMPR.HSENA Mask                   */
#define QSPI_SMPR_HSENA_SHIFT                    (0U)                                                /*!< QSPI0_SMPR.HSENA Position               */
#define QSPI_SMPR_HSENA(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< QSPI0_SMPR.HSENA Field                  */
#define QSPI_SMPR_HSPHS_MASK                     (0x2U)                                              /*!< QSPI0_SMPR.HSPHS Mask                   */
#define QSPI_SMPR_HSPHS_SHIFT                    (1U)                                                /*!< QSPI0_SMPR.HSPHS Position               */
#define QSPI_SMPR_HSPHS(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< QSPI0_SMPR.HSPHS Field                  */
#define QSPI_SMPR_HSDLY_MASK                     (0x4U)                                              /*!< QSPI0_SMPR.HSDLY Mask                   */
#define QSPI_SMPR_HSDLY_SHIFT                    (2U)                                                /*!< QSPI0_SMPR.HSDLY Position               */
#define QSPI_SMPR_HSDLY(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< QSPI0_SMPR.HSDLY Field                  */
#define QSPI_SMPR_FSPHS_MASK                     (0x20U)                                             /*!< QSPI0_SMPR.FSPHS Mask                   */
#define QSPI_SMPR_FSPHS_SHIFT                    (5U)                                                /*!< QSPI0_SMPR.FSPHS Position               */
#define QSPI_SMPR_FSPHS(x)                       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< QSPI0_SMPR.FSPHS Field                  */
#define QSPI_SMPR_FSDLY_MASK                     (0x40U)                                             /*!< QSPI0_SMPR.FSDLY Mask                   */
#define QSPI_SMPR_FSDLY_SHIFT                    (6U)                                                /*!< QSPI0_SMPR.FSDLY Position               */
#define QSPI_SMPR_FSDLY(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< QSPI0_SMPR.FSDLY Field                  */
#define QSPI_SMPR_DDRSMP_MASK                    (0x70000U)                                          /*!< QSPI0_SMPR.DDRSMP Mask                  */
#define QSPI_SMPR_DDRSMP_SHIFT                   (16U)                                               /*!< QSPI0_SMPR.DDRSMP Position              */
#define QSPI_SMPR_DDRSMP(x)                      (((uint32_t)(((uint32_t)(x))<<16U))&0x70000UL)      /*!< QSPI0_SMPR.DDRSMP Field                 */
/* ------- RBSR Bit Fields                          ------ */
#define QSPI_RBSR_RDBFL_MASK                     (0x1F00U)                                           /*!< QSPI0_RBSR.RDBFL Mask                   */
#define QSPI_RBSR_RDBFL_SHIFT                    (8U)                                                /*!< QSPI0_RBSR.RDBFL Position               */
#define QSPI_RBSR_RDBFL(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0x1F00UL)        /*!< QSPI0_RBSR.RDBFL Field                  */
#define QSPI_RBSR_RDCTR_MASK                     (0xFFFF0000U)                                       /*!< QSPI0_RBSR.RDCTR Mask                   */
#define QSPI_RBSR_RDCTR_SHIFT                    (16U)                                               /*!< QSPI0_RBSR.RDCTR Position               */
#define QSPI_RBSR_RDCTR(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< QSPI0_RBSR.RDCTR Field                  */
/* ------- RBCT Bit Fields                          ------ */
#define QSPI_RBCT_WMRK_MASK                      (0xFU)                                              /*!< QSPI0_RBCT.WMRK Mask                    */
#define QSPI_RBCT_WMRK_SHIFT                     (0U)                                                /*!< QSPI0_RBCT.WMRK Position                */
#define QSPI_RBCT_WMRK(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< QSPI0_RBCT.WMRK Field                   */
#define QSPI_RBCT_RXBRD_MASK                     (0x100U)                                            /*!< QSPI0_RBCT.RXBRD Mask                   */
#define QSPI_RBCT_RXBRD_SHIFT                    (8U)                                                /*!< QSPI0_RBCT.RXBRD Position               */
#define QSPI_RBCT_RXBRD(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< QSPI0_RBCT.RXBRD Field                  */
/* ------- TBSR Bit Fields                          ------ */
#define QSPI_TBSR_TRBFL_MASK                     (0x1F00U)                                           /*!< QSPI0_TBSR.TRBFL Mask                   */
#define QSPI_TBSR_TRBFL_SHIFT                    (8U)                                                /*!< QSPI0_TBSR.TRBFL Position               */
#define QSPI_TBSR_TRBFL(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0x1F00UL)        /*!< QSPI0_TBSR.TRBFL Field                  */
#define QSPI_TBSR_TRCTR_MASK                     (0xFFFF0000U)                                       /*!< QSPI0_TBSR.TRCTR Mask                   */
#define QSPI_TBSR_TRCTR_SHIFT                    (16U)                                               /*!< QSPI0_TBSR.TRCTR Position               */
#define QSPI_TBSR_TRCTR(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< QSPI0_TBSR.TRCTR Field                  */
/* ------- TBDR Bit Fields                          ------ */
#define QSPI_TBDR_TXDATA_MASK                    (0xFFFFFFFFU)                                       /*!< QSPI0_TBDR.TXDATA Mask                  */
#define QSPI_TBDR_TXDATA_SHIFT                   (0U)                                                /*!< QSPI0_TBDR.TXDATA Position              */
#define QSPI_TBDR_TXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< QSPI0_TBDR.TXDATA Field                 */
/* ------- TBCT Bit Fields                          ------ */
#define QSPI_TBCT_WMRK_MASK                      (0xFU)                                              /*!< QSPI0_TBCT.WMRK Mask                    */
#define QSPI_TBCT_WMRK_SHIFT                     (0U)                                                /*!< QSPI0_TBCT.WMRK Position                */
#define QSPI_TBCT_WMRK(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< QSPI0_TBCT.WMRK Field                   */
/* ------- SR Bit Fields                            ------ */
#define QSPI_SR_BUSY_MASK                        (0x1U)                                              /*!< QSPI0_SR.BUSY Mask                      */
#define QSPI_SR_BUSY_SHIFT                       (0U)                                                /*!< QSPI0_SR.BUSY Position                  */
#define QSPI_SR_BUSY(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< QSPI0_SR.BUSY Field                     */
#define QSPI_SR_IP_ACC_MASK                      (0x2U)                                              /*!< QSPI0_SR.IP_ACC Mask                    */
#define QSPI_SR_IP_ACC_SHIFT                     (1U)                                                /*!< QSPI0_SR.IP_ACC Position                */
#define QSPI_SR_IP_ACC(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< QSPI0_SR.IP_ACC Field                   */
#define QSPI_SR_AHB_ACC_MASK                     (0x4U)                                              /*!< QSPI0_SR.AHB_ACC Mask                   */
#define QSPI_SR_AHB_ACC_SHIFT                    (2U)                                                /*!< QSPI0_SR.AHB_ACC Position               */
#define QSPI_SR_AHB_ACC(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< QSPI0_SR.AHB_ACC Field                  */
#define QSPI_SR_AHBGNT_MASK                      (0x20U)                                             /*!< QSPI0_SR.AHBGNT Mask                    */
#define QSPI_SR_AHBGNT_SHIFT                     (5U)                                                /*!< QSPI0_SR.AHBGNT Position                */
#define QSPI_SR_AHBGNT(x)                        (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< QSPI0_SR.AHBGNT Field                   */
#define QSPI_SR_AHBTRN_MASK                      (0x40U)                                             /*!< QSPI0_SR.AHBTRN Mask                    */
#define QSPI_SR_AHBTRN_SHIFT                     (6U)                                                /*!< QSPI0_SR.AHBTRN Position                */
#define QSPI_SR_AHBTRN(x)                        (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< QSPI0_SR.AHBTRN Field                   */
#define QSPI_SR_AHB0NE_MASK                      (0x80U)                                             /*!< QSPI0_SR.AHB0NE Mask                    */
#define QSPI_SR_AHB0NE_SHIFT                     (7U)                                                /*!< QSPI0_SR.AHB0NE Position                */
#define QSPI_SR_AHB0NE(x)                        (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< QSPI0_SR.AHB0NE Field                   */
#define QSPI_SR_AHB1NE_MASK                      (0x100U)                                            /*!< QSPI0_SR.AHB1NE Mask                    */
#define QSPI_SR_AHB1NE_SHIFT                     (8U)                                                /*!< QSPI0_SR.AHB1NE Position                */
#define QSPI_SR_AHB1NE(x)                        (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< QSPI0_SR.AHB1NE Field                   */
#define QSPI_SR_AHB2NE_MASK                      (0x200U)                                            /*!< QSPI0_SR.AHB2NE Mask                    */
#define QSPI_SR_AHB2NE_SHIFT                     (9U)                                                /*!< QSPI0_SR.AHB2NE Position                */
#define QSPI_SR_AHB2NE(x)                        (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< QSPI0_SR.AHB2NE Field                   */
#define QSPI_SR_AHB3NE_MASK                      (0x400U)                                            /*!< QSPI0_SR.AHB3NE Mask                    */
#define QSPI_SR_AHB3NE_SHIFT                     (10U)                                               /*!< QSPI0_SR.AHB3NE Position                */
#define QSPI_SR_AHB3NE(x)                        (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< QSPI0_SR.AHB3NE Field                   */
#define QSPI_SR_AHB0FUL_MASK                     (0x800U)                                            /*!< QSPI0_SR.AHB0FUL Mask                   */
#define QSPI_SR_AHB0FUL_SHIFT                    (11U)                                               /*!< QSPI0_SR.AHB0FUL Position               */
#define QSPI_SR_AHB0FUL(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< QSPI0_SR.AHB0FUL Field                  */
#define QSPI_SR_AHB1FUL_MASK                     (0x1000U)                                           /*!< QSPI0_SR.AHB1FUL Mask                   */
#define QSPI_SR_AHB1FUL_SHIFT                    (12U)                                               /*!< QSPI0_SR.AHB1FUL Position               */
#define QSPI_SR_AHB1FUL(x)                       (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< QSPI0_SR.AHB1FUL Field                  */
#define QSPI_SR_AHB2FUL_MASK                     (0x2000U)                                           /*!< QSPI0_SR.AHB2FUL Mask                   */
#define QSPI_SR_AHB2FUL_SHIFT                    (13U)                                               /*!< QSPI0_SR.AHB2FUL Position               */
#define QSPI_SR_AHB2FUL(x)                       (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< QSPI0_SR.AHB2FUL Field                  */
#define QSPI_SR_AHB3FUL_MASK                     (0x4000U)                                           /*!< QSPI0_SR.AHB3FUL Mask                   */
#define QSPI_SR_AHB3FUL_SHIFT                    (14U)                                               /*!< QSPI0_SR.AHB3FUL Position               */
#define QSPI_SR_AHB3FUL(x)                       (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< QSPI0_SR.AHB3FUL Field                  */
#define QSPI_SR_RXWE_MASK                        (0x10000U)                                          /*!< QSPI0_SR.RXWE Mask                      */
#define QSPI_SR_RXWE_SHIFT                       (16U)                                               /*!< QSPI0_SR.RXWE Position                  */
#define QSPI_SR_RXWE(x)                          (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< QSPI0_SR.RXWE Field                     */
#define QSPI_SR_RXFULL_MASK                      (0x80000U)                                          /*!< QSPI0_SR.RXFULL Mask                    */
#define QSPI_SR_RXFULL_SHIFT                     (19U)                                               /*!< QSPI0_SR.RXFULL Position                */
#define QSPI_SR_RXFULL(x)                        (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< QSPI0_SR.RXFULL Field                   */
#define QSPI_SR_RXDMA_MASK                       (0x800000U)                                         /*!< QSPI0_SR.RXDMA Mask                     */
#define QSPI_SR_RXDMA_SHIFT                      (23U)                                               /*!< QSPI0_SR.RXDMA Position                 */
#define QSPI_SR_RXDMA(x)                         (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< QSPI0_SR.RXDMA Field                    */
#define QSPI_SR_TXEDA_MASK                       (0x1000000U)                                        /*!< QSPI0_SR.TXEDA Mask                     */
#define QSPI_SR_TXEDA_SHIFT                      (24U)                                               /*!< QSPI0_SR.TXEDA Position                 */
#define QSPI_SR_TXEDA(x)                         (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< QSPI0_SR.TXEDA Field                    */
#define QSPI_SR_TXWA_MASK                        (0x2000000U)                                        /*!< QSPI0_SR.TXWA Mask                      */
#define QSPI_SR_TXWA_SHIFT                       (25U)                                               /*!< QSPI0_SR.TXWA Position                  */
#define QSPI_SR_TXWA(x)                          (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< QSPI0_SR.TXWA Field                     */
#define QSPI_SR_TXDMA_MASK                       (0x4000000U)                                        /*!< QSPI0_SR.TXDMA Mask                     */
#define QSPI_SR_TXDMA_SHIFT                      (26U)                                               /*!< QSPI0_SR.TXDMA Position                 */
#define QSPI_SR_TXDMA(x)                         (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< QSPI0_SR.TXDMA Field                    */
#define QSPI_SR_TXFULL_MASK                      (0x8000000U)                                        /*!< QSPI0_SR.TXFULL Mask                    */
#define QSPI_SR_TXFULL_SHIFT                     (27U)                                               /*!< QSPI0_SR.TXFULL Position                */
#define QSPI_SR_TXFULL(x)                        (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< QSPI0_SR.TXFULL Field                   */
#define QSPI_SR_DLPSMP_MASK                      (0xE0000000U)                                       /*!< QSPI0_SR.DLPSMP Mask                    */
#define QSPI_SR_DLPSMP_SHIFT                     (29U)                                               /*!< QSPI0_SR.DLPSMP Position                */
#define QSPI_SR_DLPSMP(x)                        (((uint32_t)(((uint32_t)(x))<<29U))&0xE0000000UL)   /*!< QSPI0_SR.DLPSMP Field                   */
/* ------- FR Bit Fields                            ------ */
#define QSPI_FR_TFF_MASK                         (0x1U)                                              /*!< QSPI0_FR.TFF Mask                       */
#define QSPI_FR_TFF_SHIFT                        (0U)                                                /*!< QSPI0_FR.TFF Position                   */
#define QSPI_FR_TFF(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< QSPI0_FR.TFF Field                      */
#define QSPI_FR_IPGEF_MASK                       (0x10U)                                             /*!< QSPI0_FR.IPGEF Mask                     */
#define QSPI_FR_IPGEF_SHIFT                      (4U)                                                /*!< QSPI0_FR.IPGEF Position                 */
#define QSPI_FR_IPGEF(x)                         (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< QSPI0_FR.IPGEF Field                    */
#define QSPI_FR_IPIEF_MASK                       (0x40U)                                             /*!< QSPI0_FR.IPIEF Mask                     */
#define QSPI_FR_IPIEF_SHIFT                      (6U)                                                /*!< QSPI0_FR.IPIEF Position                 */
#define QSPI_FR_IPIEF(x)                         (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< QSPI0_FR.IPIEF Field                    */
#define QSPI_FR_IPAEF_MASK                       (0x80U)                                             /*!< QSPI0_FR.IPAEF Mask                     */
#define QSPI_FR_IPAEF_SHIFT                      (7U)                                                /*!< QSPI0_FR.IPAEF Position                 */
#define QSPI_FR_IPAEF(x)                         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< QSPI0_FR.IPAEF Field                    */
#define QSPI_FR_IUEF_MASK                        (0x800U)                                            /*!< QSPI0_FR.IUEF Mask                      */
#define QSPI_FR_IUEF_SHIFT                       (11U)                                               /*!< QSPI0_FR.IUEF Position                  */
#define QSPI_FR_IUEF(x)                          (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< QSPI0_FR.IUEF Field                     */
#define QSPI_FR_ABOF_MASK                        (0x1000U)                                           /*!< QSPI0_FR.ABOF Mask                      */
#define QSPI_FR_ABOF_SHIFT                       (12U)                                               /*!< QSPI0_FR.ABOF Position                  */
#define QSPI_FR_ABOF(x)                          (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< QSPI0_FR.ABOF Field                     */
#define QSPI_FR_AIBSEF_MASK                      (0x2000U)                                           /*!< QSPI0_FR.AIBSEF Mask                    */
#define QSPI_FR_AIBSEF_SHIFT                     (13U)                                               /*!< QSPI0_FR.AIBSEF Position                */
#define QSPI_FR_AIBSEF(x)                        (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< QSPI0_FR.AIBSEF Field                   */
#define QSPI_FR_AITEF_MASK                       (0x4000U)                                           /*!< QSPI0_FR.AITEF Mask                     */
#define QSPI_FR_AITEF_SHIFT                      (14U)                                               /*!< QSPI0_FR.AITEF Position                 */
#define QSPI_FR_AITEF(x)                         (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< QSPI0_FR.AITEF Field                    */
#define QSPI_FR_ABSEF_MASK                       (0x8000U)                                           /*!< QSPI0_FR.ABSEF Mask                     */
#define QSPI_FR_ABSEF_SHIFT                      (15U)                                               /*!< QSPI0_FR.ABSEF Position                 */
#define QSPI_FR_ABSEF(x)                         (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< QSPI0_FR.ABSEF Field                    */
#define QSPI_FR_RBDF_MASK                        (0x10000U)                                          /*!< QSPI0_FR.RBDF Mask                      */
#define QSPI_FR_RBDF_SHIFT                       (16U)                                               /*!< QSPI0_FR.RBDF Position                  */
#define QSPI_FR_RBDF(x)                          (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< QSPI0_FR.RBDF Field                     */
#define QSPI_FR_RBOF_MASK                        (0x20000U)                                          /*!< QSPI0_FR.RBOF Mask                      */
#define QSPI_FR_RBOF_SHIFT                       (17U)                                               /*!< QSPI0_FR.RBOF Position                  */
#define QSPI_FR_RBOF(x)                          (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< QSPI0_FR.RBOF Field                     */
#define QSPI_FR_ILLINE_MASK                      (0x800000U)                                         /*!< QSPI0_FR.ILLINE Mask                    */
#define QSPI_FR_ILLINE_SHIFT                     (23U)                                               /*!< QSPI0_FR.ILLINE Position                */
#define QSPI_FR_ILLINE(x)                        (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< QSPI0_FR.ILLINE Field                   */
#define QSPI_FR_TBUF_MASK                        (0x4000000U)                                        /*!< QSPI0_FR.TBUF Mask                      */
#define QSPI_FR_TBUF_SHIFT                       (26U)                                               /*!< QSPI0_FR.TBUF Position                  */
#define QSPI_FR_TBUF(x)                          (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< QSPI0_FR.TBUF Field                     */
#define QSPI_FR_TBFF_MASK                        (0x8000000U)                                        /*!< QSPI0_FR.TBFF Mask                      */
#define QSPI_FR_TBFF_SHIFT                       (27U)                                               /*!< QSPI0_FR.TBFF Position                  */
#define QSPI_FR_TBFF(x)                          (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< QSPI0_FR.TBFF Field                     */
#define QSPI_FR_DLPFF_MASK                       (0x80000000U)                                       /*!< QSPI0_FR.DLPFF Mask                     */
#define QSPI_FR_DLPFF_SHIFT                      (31U)                                               /*!< QSPI0_FR.DLPFF Position                 */
#define QSPI_FR_DLPFF(x)                         (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< QSPI0_FR.DLPFF Field                    */
/* ------- RSER Bit Fields                          ------ */
#define QSPI_RSER_TFIE_MASK                      (0x1U)                                              /*!< QSPI0_RSER.TFIE Mask                    */
#define QSPI_RSER_TFIE_SHIFT                     (0U)                                                /*!< QSPI0_RSER.TFIE Position                */
#define QSPI_RSER_TFIE(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< QSPI0_RSER.TFIE Field                   */
#define QSPI_RSER_IPGEIE_MASK                    (0x10U)                                             /*!< QSPI0_RSER.IPGEIE Mask                  */
#define QSPI_RSER_IPGEIE_SHIFT                   (4U)                                                /*!< QSPI0_RSER.IPGEIE Position              */
#define QSPI_RSER_IPGEIE(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< QSPI0_RSER.IPGEIE Field                 */
#define QSPI_RSER_IPIEIE_MASK                    (0x40U)                                             /*!< QSPI0_RSER.IPIEIE Mask                  */
#define QSPI_RSER_IPIEIE_SHIFT                   (6U)                                                /*!< QSPI0_RSER.IPIEIE Position              */
#define QSPI_RSER_IPIEIE(x)                      (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< QSPI0_RSER.IPIEIE Field                 */
#define QSPI_RSER_IPAEIE_MASK                    (0x80U)                                             /*!< QSPI0_RSER.IPAEIE Mask                  */
#define QSPI_RSER_IPAEIE_SHIFT                   (7U)                                                /*!< QSPI0_RSER.IPAEIE Position              */
#define QSPI_RSER_IPAEIE(x)                      (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< QSPI0_RSER.IPAEIE Field                 */
#define QSPI_RSER_IUEIE_MASK                     (0x800U)                                            /*!< QSPI0_RSER.IUEIE Mask                   */
#define QSPI_RSER_IUEIE_SHIFT                    (11U)                                               /*!< QSPI0_RSER.IUEIE Position               */
#define QSPI_RSER_IUEIE(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< QSPI0_RSER.IUEIE Field                  */
#define QSPI_RSER_ABOIE_MASK                     (0x1000U)                                           /*!< QSPI0_RSER.ABOIE Mask                   */
#define QSPI_RSER_ABOIE_SHIFT                    (12U)                                               /*!< QSPI0_RSER.ABOIE Position               */
#define QSPI_RSER_ABOIE(x)                       (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< QSPI0_RSER.ABOIE Field                  */
#define QSPI_RSER_AIBSIE_MASK                    (0x2000U)                                           /*!< QSPI0_RSER.AIBSIE Mask                  */
#define QSPI_RSER_AIBSIE_SHIFT                   (13U)                                               /*!< QSPI0_RSER.AIBSIE Position              */
#define QSPI_RSER_AIBSIE(x)                      (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< QSPI0_RSER.AIBSIE Field                 */
#define QSPI_RSER_AITIE_MASK                     (0x4000U)                                           /*!< QSPI0_RSER.AITIE Mask                   */
#define QSPI_RSER_AITIE_SHIFT                    (14U)                                               /*!< QSPI0_RSER.AITIE Position               */
#define QSPI_RSER_AITIE(x)                       (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< QSPI0_RSER.AITIE Field                  */
#define QSPI_RSER_ABSEIE_MASK                    (0x8000U)                                           /*!< QSPI0_RSER.ABSEIE Mask                  */
#define QSPI_RSER_ABSEIE_SHIFT                   (15U)                                               /*!< QSPI0_RSER.ABSEIE Position              */
#define QSPI_RSER_ABSEIE(x)                      (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< QSPI0_RSER.ABSEIE Field                 */
#define QSPI_RSER_RBDIE_MASK                     (0x10000U)                                          /*!< QSPI0_RSER.RBDIE Mask                   */
#define QSPI_RSER_RBDIE_SHIFT                    (16U)                                               /*!< QSPI0_RSER.RBDIE Position               */
#define QSPI_RSER_RBDIE(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< QSPI0_RSER.RBDIE Field                  */
#define QSPI_RSER_RBOIE_MASK                     (0x20000U)                                          /*!< QSPI0_RSER.RBOIE Mask                   */
#define QSPI_RSER_RBOIE_SHIFT                    (17U)                                               /*!< QSPI0_RSER.RBOIE Position               */
#define QSPI_RSER_RBOIE(x)                       (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< QSPI0_RSER.RBOIE Field                  */
#define QSPI_RSER_RBDDE_MASK                     (0x200000U)                                         /*!< QSPI0_RSER.RBDDE Mask                   */
#define QSPI_RSER_RBDDE_SHIFT                    (21U)                                               /*!< QSPI0_RSER.RBDDE Position               */
#define QSPI_RSER_RBDDE(x)                       (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< QSPI0_RSER.RBDDE Field                  */
#define QSPI_RSER_ILLINIE_MASK                   (0x800000U)                                         /*!< QSPI0_RSER.ILLINIE Mask                 */
#define QSPI_RSER_ILLINIE_SHIFT                  (23U)                                               /*!< QSPI0_RSER.ILLINIE Position             */
#define QSPI_RSER_ILLINIE(x)                     (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< QSPI0_RSER.ILLINIE Field                */
#define QSPI_RSER_TBFDE_MASK                     (0x2000000U)                                        /*!< QSPI0_RSER.TBFDE Mask                   */
#define QSPI_RSER_TBFDE_SHIFT                    (25U)                                               /*!< QSPI0_RSER.TBFDE Position               */
#define QSPI_RSER_TBFDE(x)                       (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< QSPI0_RSER.TBFDE Field                  */
#define QSPI_RSER_TBUIE_MASK                     (0x4000000U)                                        /*!< QSPI0_RSER.TBUIE Mask                   */
#define QSPI_RSER_TBUIE_SHIFT                    (26U)                                               /*!< QSPI0_RSER.TBUIE Position               */
#define QSPI_RSER_TBUIE(x)                       (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< QSPI0_RSER.TBUIE Field                  */
#define QSPI_RSER_TBFIE_MASK                     (0x8000000U)                                        /*!< QSPI0_RSER.TBFIE Mask                   */
#define QSPI_RSER_TBFIE_SHIFT                    (27U)                                               /*!< QSPI0_RSER.TBFIE Position               */
#define QSPI_RSER_TBFIE(x)                       (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< QSPI0_RSER.TBFIE Field                  */
#define QSPI_RSER_DLPFIE_MASK                    (0x80000000U)                                       /*!< QSPI0_RSER.DLPFIE Mask                  */
#define QSPI_RSER_DLPFIE_SHIFT                   (31U)                                               /*!< QSPI0_RSER.DLPFIE Position              */
#define QSPI_RSER_DLPFIE(x)                      (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< QSPI0_RSER.DLPFIE Field                 */
/* ------- SPNDST Bit Fields                        ------ */
#define QSPI_SPNDST_SUSPND_MASK                  (0x1U)                                              /*!< QSPI0_SPNDST.SUSPND Mask                */
#define QSPI_SPNDST_SUSPND_SHIFT                 (0U)                                                /*!< QSPI0_SPNDST.SUSPND Position            */
#define QSPI_SPNDST_SUSPND(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< QSPI0_SPNDST.SUSPND Field               */
#define QSPI_SPNDST_SPDBUF_MASK                  (0xC0U)                                             /*!< QSPI0_SPNDST.SPDBUF Mask                */
#define QSPI_SPNDST_SPDBUF_SHIFT                 (6U)                                                /*!< QSPI0_SPNDST.SPDBUF Position            */
#define QSPI_SPNDST_SPDBUF(x)                    (((uint32_t)(((uint32_t)(x))<<6U))&0xC0UL)          /*!< QSPI0_SPNDST.SPDBUF Field               */
#define QSPI_SPNDST_DATLFT_MASK                  (0x7E00U)                                           /*!< QSPI0_SPNDST.DATLFT Mask                */
#define QSPI_SPNDST_DATLFT_SHIFT                 (9U)                                                /*!< QSPI0_SPNDST.DATLFT Position            */
#define QSPI_SPNDST_DATLFT(x)                    (((uint32_t)(((uint32_t)(x))<<9U))&0x7E00UL)        /*!< QSPI0_SPNDST.DATLFT Field               */
/* ------- SPTRCLR Bit Fields                       ------ */
#define QSPI_SPTRCLR_BFPTRC_MASK                 (0x1U)                                              /*!< QSPI0_SPTRCLR.BFPTRC Mask               */
#define QSPI_SPTRCLR_BFPTRC_SHIFT                (0U)                                                /*!< QSPI0_SPTRCLR.BFPTRC Position           */
#define QSPI_SPTRCLR_BFPTRC(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< QSPI0_SPTRCLR.BFPTRC Field              */
#define QSPI_SPTRCLR_IPPTRC_MASK                 (0x100U)                                            /*!< QSPI0_SPTRCLR.IPPTRC Mask               */
#define QSPI_SPTRCLR_IPPTRC_SHIFT                (8U)                                                /*!< QSPI0_SPTRCLR.IPPTRC Position           */
#define QSPI_SPTRCLR_IPPTRC(x)                   (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< QSPI0_SPTRCLR.IPPTRC Field              */
/* ------- SFA1AD Bit Fields                        ------ */
#define QSPI_SFA1AD_TPADA1_MASK                  (0xFFFFFC00U)                                       /*!< QSPI0_SFA1AD.TPADA1 Mask                */
#define QSPI_SFA1AD_TPADA1_SHIFT                 (10U)                                               /*!< QSPI0_SFA1AD.TPADA1 Position            */
#define QSPI_SFA1AD_TPADA1(x)                    (((uint32_t)(((uint32_t)(x))<<10U))&0xFFFFFC00UL)   /*!< QSPI0_SFA1AD.TPADA1 Field               */
/* ------- SFA2AD Bit Fields                        ------ */
#define QSPI_SFA2AD_TPADA2_MASK                  (0xFFFFFC00U)                                       /*!< QSPI0_SFA2AD.TPADA2 Mask                */
#define QSPI_SFA2AD_TPADA2_SHIFT                 (10U)                                               /*!< QSPI0_SFA2AD.TPADA2 Position            */
#define QSPI_SFA2AD_TPADA2(x)                    (((uint32_t)(((uint32_t)(x))<<10U))&0xFFFFFC00UL)   /*!< QSPI0_SFA2AD.TPADA2 Field               */
/* ------- SFB1AD Bit Fields                        ------ */
#define QSPI_SFB1AD_TPADB1_MASK                  (0xFFFFFC00U)                                       /*!< QSPI0_SFB1AD.TPADB1 Mask                */
#define QSPI_SFB1AD_TPADB1_SHIFT                 (10U)                                               /*!< QSPI0_SFB1AD.TPADB1 Position            */
#define QSPI_SFB1AD_TPADB1(x)                    (((uint32_t)(((uint32_t)(x))<<10U))&0xFFFFFC00UL)   /*!< QSPI0_SFB1AD.TPADB1 Field               */
/* ------- SFB2AD Bit Fields                        ------ */
#define QSPI_SFB2AD_TPADB2_MASK                  (0xFFFFFC00U)                                       /*!< QSPI0_SFB2AD.TPADB2 Mask                */
#define QSPI_SFB2AD_TPADB2_SHIFT                 (10U)                                               /*!< QSPI0_SFB2AD.TPADB2 Position            */
#define QSPI_SFB2AD_TPADB2(x)                    (((uint32_t)(((uint32_t)(x))<<10U))&0xFFFFFC00UL)   /*!< QSPI0_SFB2AD.TPADB2 Field               */
/* ------- DLPR Bit Fields                          ------ */
#define QSPI_DLPR_DLPV_MASK                      (0xFFFFFFFFU)                                       /*!< QSPI0_DLPR.DLPV Mask                    */
#define QSPI_DLPR_DLPV_SHIFT                     (0U)                                                /*!< QSPI0_DLPR.DLPV Position                */
#define QSPI_DLPR_DLPV(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< QSPI0_DLPR.DLPV Field                   */
/* ------- RBDR Bit Fields                          ------ */
#define QSPI_RBDR_RXDATA_MASK                    (0xFFFFFFFFU)                                       /*!< QSPI0_RBDR.RXDATA Mask                  */
#define QSPI_RBDR_RXDATA_SHIFT                   (0U)                                                /*!< QSPI0_RBDR.RXDATA Position              */
#define QSPI_RBDR_RXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< QSPI0_RBDR.RXDATA Field                 */
/* ------- LUTKEY Bit Fields                        ------ */
#define QSPI_LUTKEY_KEY_MASK                     (0xFFFFFFFFU)                                       /*!< QSPI0_LUTKEY.KEY Mask                   */
#define QSPI_LUTKEY_KEY_SHIFT                    (0U)                                                /*!< QSPI0_LUTKEY.KEY Position               */
#define QSPI_LUTKEY_KEY(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< QSPI0_LUTKEY.KEY Field                  */
/* ------- LCKCR Bit Fields                         ------ */
#define QSPI_LCKCR_LOCK_MASK                     (0x1U)                                              /*!< QSPI0_LCKCR.LOCK Mask                   */
#define QSPI_LCKCR_LOCK_SHIFT                    (0U)                                                /*!< QSPI0_LCKCR.LOCK Position               */
#define QSPI_LCKCR_LOCK(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< QSPI0_LCKCR.LOCK Field                  */
#define QSPI_LCKCR_UNLOCK_MASK                   (0x2U)                                              /*!< QSPI0_LCKCR.UNLOCK Mask                 */
#define QSPI_LCKCR_UNLOCK_SHIFT                  (1U)                                                /*!< QSPI0_LCKCR.UNLOCK Position             */
#define QSPI_LCKCR_UNLOCK(x)                     (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< QSPI0_LCKCR.UNLOCK Field                */
/* ------- LUT Bit Fields                           ------ */
#define QSPI_LUT_OPRND0_MASK                     (0xFFU)                                             /*!< QSPI0_LUT.OPRND0 Mask                   */
#define QSPI_LUT_OPRND0_SHIFT                    (0U)                                                /*!< QSPI0_LUT.OPRND0 Position               */
#define QSPI_LUT_OPRND0(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< QSPI0_LUT.OPRND0 Field                  */
#define QSPI_LUT_PAD0_MASK                       (0x300U)                                            /*!< QSPI0_LUT.PAD0 Mask                     */
#define QSPI_LUT_PAD0_SHIFT                      (8U)                                                /*!< QSPI0_LUT.PAD0 Position                 */
#define QSPI_LUT_PAD0(x)                         (((uint32_t)(((uint32_t)(x))<<8U))&0x300UL)         /*!< QSPI0_LUT.PAD0 Field                    */
#define QSPI_LUT_INSTR0_MASK                     (0xFC00U)                                           /*!< QSPI0_LUT.INSTR0 Mask                   */
#define QSPI_LUT_INSTR0_SHIFT                    (10U)                                               /*!< QSPI0_LUT.INSTR0 Position               */
#define QSPI_LUT_INSTR0(x)                       (((uint32_t)(((uint32_t)(x))<<10U))&0xFC00UL)       /*!< QSPI0_LUT.INSTR0 Field                  */
#define QSPI_LUT_OPRND1_MASK                     (0xFF0000U)                                         /*!< QSPI0_LUT.OPRND1 Mask                   */
#define QSPI_LUT_OPRND1_SHIFT                    (16U)                                               /*!< QSPI0_LUT.OPRND1 Position               */
#define QSPI_LUT_OPRND1(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0xFF0000UL)     /*!< QSPI0_LUT.OPRND1 Field                  */
#define QSPI_LUT_PAD1_MASK                       (0x3000000U)                                        /*!< QSPI0_LUT.PAD1 Mask                     */
#define QSPI_LUT_PAD1_SHIFT                      (24U)                                               /*!< QSPI0_LUT.PAD1 Position                 */
#define QSPI_LUT_PAD1(x)                         (((uint32_t)(((uint32_t)(x))<<24U))&0x3000000UL)    /*!< QSPI0_LUT.PAD1 Field                    */
#define QSPI_LUT_INSTR1_MASK                     (0xFC000000U)                                       /*!< QSPI0_LUT.INSTR1 Mask                   */
#define QSPI_LUT_INSTR1_SHIFT                    (26U)                                               /*!< QSPI0_LUT.INSTR1 Position               */
#define QSPI_LUT_INSTR1(x)                       (((uint32_t)(((uint32_t)(x))<<26U))&0xFC000000UL)   /*!< QSPI0_LUT.INSTR1 Field                  */
/**
 * @} */ /* End group QSPI_Register_Masks_GROUP 
 */

/* QSPI0 - Peripheral instance base addresses */
#define QSPI0_BasePtr                  0x4005A000UL //!< Peripheral base address
#define QSPI0                          ((QSPI_Type *) QSPI0_BasePtr) //!< Freescale base pointer
#define QSPI0_BASE_PTR                 (QSPI0) //!< Freescale style base pointer
/**
 * @} */ /* End group QSPI_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RCM_Peripheral_access_layer_GROUP RCM Peripheral Access Layer
* @brief C Struct for RCM
* @{
*/

/* ================================================================================ */
/* ================           RCM (file:RCM_MKL82Z7)               ================ */
/* ================================================================================ */

/**
 * @brief Reset Control Module
 */
/**
* @addtogroup RCM_structs_GROUP RCM struct
* @brief Struct for RCM
* @{
*/
typedef struct {                                /*       RCM Structure                                                */
   __I  uint8_t   SRS0;                         /**< 0000: System Reset Status Register 0                               */
   __I  uint8_t   SRS1;                         /**< 0001: System Reset Status Register 1                               */
        uint8_t   RESERVED_0[2];               
   __IO uint8_t   RPFC;                         /**< 0004: Reset Pin Filter Control register                            */
   __IO uint8_t   RPFW;                         /**< 0005: Reset Pin Filter Width register                              */
   __IO uint8_t   FM;                           /**< 0006: Force Mode Register                                          */
   __IO uint8_t   MR;                           /**< 0007: Mode Register                                                */
   __IO uint8_t   SSRS0;                        /**< 0008: Sticky System Reset Status Register 0                        */
   __IO uint8_t   SSRS1;                        /**< 0009: Sticky System Reset Status Register 1                        */
} RCM_Type;

/**
 * @} */ /* End group RCM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RCM_Register_Masks_GROUP RCM Register Masks
* @brief Register Masks for RCM
* @{
*/
/* ------- SRS0 Bit Fields                          ------ */
#define RCM_SRS0_WAKEUP_MASK                     (0x1U)                                              /*!< RCM_SRS0.WAKEUP Mask                    */
#define RCM_SRS0_WAKEUP_SHIFT                    (0U)                                                /*!< RCM_SRS0.WAKEUP Position                */
#define RCM_SRS0_WAKEUP(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< RCM_SRS0.WAKEUP Field                   */
#define RCM_SRS0_LVD_MASK                        (0x2U)                                              /*!< RCM_SRS0.LVD Mask                       */
#define RCM_SRS0_LVD_SHIFT                       (1U)                                                /*!< RCM_SRS0.LVD Position                   */
#define RCM_SRS0_LVD(x)                          (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< RCM_SRS0.LVD Field                      */
#define RCM_SRS0_LOC_MASK                        (0x4U)                                              /*!< RCM_SRS0.LOC Mask                       */
#define RCM_SRS0_LOC_SHIFT                       (2U)                                                /*!< RCM_SRS0.LOC Position                   */
#define RCM_SRS0_LOC(x)                          (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< RCM_SRS0.LOC Field                      */
#define RCM_SRS0_LOL_MASK                        (0x8U)                                              /*!< RCM_SRS0.LOL Mask                       */
#define RCM_SRS0_LOL_SHIFT                       (3U)                                                /*!< RCM_SRS0.LOL Position                   */
#define RCM_SRS0_LOL(x)                          (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< RCM_SRS0.LOL Field                      */
#define RCM_SRS0_WDOG_MASK                       (0x20U)                                             /*!< RCM_SRS0.WDOG Mask                      */
#define RCM_SRS0_WDOG_SHIFT                      (5U)                                                /*!< RCM_SRS0.WDOG Position                  */
#define RCM_SRS0_WDOG(x)                         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< RCM_SRS0.WDOG Field                     */
#define RCM_SRS0_PIN_MASK                        (0x40U)                                             /*!< RCM_SRS0.PIN Mask                       */
#define RCM_SRS0_PIN_SHIFT                       (6U)                                                /*!< RCM_SRS0.PIN Position                   */
#define RCM_SRS0_PIN(x)                          (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< RCM_SRS0.PIN Field                      */
#define RCM_SRS0_POR_MASK                        (0x80U)                                             /*!< RCM_SRS0.POR Mask                       */
#define RCM_SRS0_POR_SHIFT                       (7U)                                                /*!< RCM_SRS0.POR Position                   */
#define RCM_SRS0_POR(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< RCM_SRS0.POR Field                      */
/* ------- SRS1 Bit Fields                          ------ */
#define RCM_SRS1_LOCKUP_MASK                     (0x2U)                                              /*!< RCM_SRS1.LOCKUP Mask                    */
#define RCM_SRS1_LOCKUP_SHIFT                    (1U)                                                /*!< RCM_SRS1.LOCKUP Position                */
#define RCM_SRS1_LOCKUP(x)                       (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< RCM_SRS1.LOCKUP Field                   */
#define RCM_SRS1_SW_MASK                         (0x4U)                                              /*!< RCM_SRS1.SW Mask                        */
#define RCM_SRS1_SW_SHIFT                        (2U)                                                /*!< RCM_SRS1.SW Position                    */
#define RCM_SRS1_SW(x)                           (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< RCM_SRS1.SW Field                       */
#define RCM_SRS1_MDM_AP_MASK                     (0x8U)                                              /*!< RCM_SRS1.MDM_AP Mask                    */
#define RCM_SRS1_MDM_AP_SHIFT                    (3U)                                                /*!< RCM_SRS1.MDM_AP Position                */
#define RCM_SRS1_MDM_AP(x)                       (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< RCM_SRS1.MDM_AP Field                   */
#define RCM_SRS1_SACKERR_MASK                    (0x20U)                                             /*!< RCM_SRS1.SACKERR Mask                   */
#define RCM_SRS1_SACKERR_SHIFT                   (5U)                                                /*!< RCM_SRS1.SACKERR Position               */
#define RCM_SRS1_SACKERR(x)                      (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< RCM_SRS1.SACKERR Field                  */
/* ------- RPFC Bit Fields                          ------ */
#define RCM_RPFC_RSTFLTSRW_MASK                  (0x3U)                                              /*!< RCM_RPFC.RSTFLTSRW Mask                 */
#define RCM_RPFC_RSTFLTSRW_SHIFT                 (0U)                                                /*!< RCM_RPFC.RSTFLTSRW Position             */
#define RCM_RPFC_RSTFLTSRW(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< RCM_RPFC.RSTFLTSRW Field                */
#define RCM_RPFC_RSTFLTSS_MASK                   (0x4U)                                              /*!< RCM_RPFC.RSTFLTSS Mask                  */
#define RCM_RPFC_RSTFLTSS_SHIFT                  (2U)                                                /*!< RCM_RPFC.RSTFLTSS Position              */
#define RCM_RPFC_RSTFLTSS(x)                     (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< RCM_RPFC.RSTFLTSS Field                 */
/* ------- RPFW Bit Fields                          ------ */
#define RCM_RPFW_RSTFLTSEL_MASK                  (0x1FU)                                             /*!< RCM_RPFW.RSTFLTSEL Mask                 */
#define RCM_RPFW_RSTFLTSEL_SHIFT                 (0U)                                                /*!< RCM_RPFW.RSTFLTSEL Position             */
#define RCM_RPFW_RSTFLTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1FUL)            /*!< RCM_RPFW.RSTFLTSEL Field                */
/* ------- FM Bit Fields                            ------ */
#define RCM_FM_FORCEROM_MASK                     (0x6U)                                              /*!< RCM_FM.FORCEROM Mask                    */
#define RCM_FM_FORCEROM_SHIFT                    (1U)                                                /*!< RCM_FM.FORCEROM Position                */
#define RCM_FM_FORCEROM(x)                       (((uint8_t)(((uint8_t)(x))<<1U))&0x6UL)             /*!< RCM_FM.FORCEROM Field                   */
/* ------- MR Bit Fields                            ------ */
#define RCM_MR_BOOTROM_MASK                      (0x6U)                                              /*!< RCM_MR.BOOTROM Mask                     */
#define RCM_MR_BOOTROM_SHIFT                     (1U)                                                /*!< RCM_MR.BOOTROM Position                 */
#define RCM_MR_BOOTROM(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x6UL)             /*!< RCM_MR.BOOTROM Field                    */
/* ------- SSRS0 Bit Fields                         ------ */
#define RCM_SSRS0_SWAKEUP_MASK                   (0x1U)                                              /*!< RCM_SSRS0.SWAKEUP Mask                  */
#define RCM_SSRS0_SWAKEUP_SHIFT                  (0U)                                                /*!< RCM_SSRS0.SWAKEUP Position              */
#define RCM_SSRS0_SWAKEUP(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< RCM_SSRS0.SWAKEUP Field                 */
#define RCM_SSRS0_SLVD_MASK                      (0x2U)                                              /*!< RCM_SSRS0.SLVD Mask                     */
#define RCM_SSRS0_SLVD_SHIFT                     (1U)                                                /*!< RCM_SSRS0.SLVD Position                 */
#define RCM_SSRS0_SLVD(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< RCM_SSRS0.SLVD Field                    */
#define RCM_SSRS0_SLOC_MASK                      (0x4U)                                              /*!< RCM_SSRS0.SLOC Mask                     */
#define RCM_SSRS0_SLOC_SHIFT                     (2U)                                                /*!< RCM_SSRS0.SLOC Position                 */
#define RCM_SSRS0_SLOC(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< RCM_SSRS0.SLOC Field                    */
#define RCM_SSRS0_SLOL_MASK                      (0x8U)                                              /*!< RCM_SSRS0.SLOL Mask                     */
#define RCM_SSRS0_SLOL_SHIFT                     (3U)                                                /*!< RCM_SSRS0.SLOL Position                 */
#define RCM_SSRS0_SLOL(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< RCM_SSRS0.SLOL Field                    */
#define RCM_SSRS0_SWDOG_MASK                     (0x20U)                                             /*!< RCM_SSRS0.SWDOG Mask                    */
#define RCM_SSRS0_SWDOG_SHIFT                    (5U)                                                /*!< RCM_SSRS0.SWDOG Position                */
#define RCM_SSRS0_SWDOG(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< RCM_SSRS0.SWDOG Field                   */
#define RCM_SSRS0_SPIN_MASK                      (0x40U)                                             /*!< RCM_SSRS0.SPIN Mask                     */
#define RCM_SSRS0_SPIN_SHIFT                     (6U)                                                /*!< RCM_SSRS0.SPIN Position                 */
#define RCM_SSRS0_SPIN(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< RCM_SSRS0.SPIN Field                    */
#define RCM_SSRS0_SPOR_MASK                      (0x80U)                                             /*!< RCM_SSRS0.SPOR Mask                     */
#define RCM_SSRS0_SPOR_SHIFT                     (7U)                                                /*!< RCM_SSRS0.SPOR Position                 */
#define RCM_SSRS0_SPOR(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< RCM_SSRS0.SPOR Field                    */
/* ------- SSRS1 Bit Fields                         ------ */
#define RCM_SSRS1_SLOCKUP_MASK                   (0x2U)                                              /*!< RCM_SSRS1.SLOCKUP Mask                  */
#define RCM_SSRS1_SLOCKUP_SHIFT                  (1U)                                                /*!< RCM_SSRS1.SLOCKUP Position              */
#define RCM_SSRS1_SLOCKUP(x)                     (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< RCM_SSRS1.SLOCKUP Field                 */
#define RCM_SSRS1_SSW_MASK                       (0x4U)                                              /*!< RCM_SSRS1.SSW Mask                      */
#define RCM_SSRS1_SSW_SHIFT                      (2U)                                                /*!< RCM_SSRS1.SSW Position                  */
#define RCM_SSRS1_SSW(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< RCM_SSRS1.SSW Field                     */
#define RCM_SSRS1_SMDM_AP_MASK                   (0x8U)                                              /*!< RCM_SSRS1.SMDM_AP Mask                  */
#define RCM_SSRS1_SMDM_AP_SHIFT                  (3U)                                                /*!< RCM_SSRS1.SMDM_AP Position              */
#define RCM_SSRS1_SMDM_AP(x)                     (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< RCM_SSRS1.SMDM_AP Field                 */
#define RCM_SSRS1_SSACKERR_MASK                  (0x20U)                                             /*!< RCM_SSRS1.SSACKERR Mask                 */
#define RCM_SSRS1_SSACKERR_SHIFT                 (5U)                                                /*!< RCM_SSRS1.SSACKERR Position             */
#define RCM_SSRS1_SSACKERR(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< RCM_SSRS1.SSACKERR Field                */
/**
 * @} */ /* End group RCM_Register_Masks_GROUP 
 */

/* RCM - Peripheral instance base addresses */
#define RCM_BasePtr                    0x4007F000UL //!< Peripheral base address
#define RCM                            ((RCM_Type *) RCM_BasePtr) //!< Freescale base pointer
#define RCM_BASE_PTR                   (RCM) //!< Freescale style base pointer
/**
 * @} */ /* End group RCM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RFSYS_Peripheral_access_layer_GROUP RFSYS Peripheral Access Layer
* @brief C Struct for RFSYS
* @{
*/

/* ================================================================================ */
/* ================           RFSYS (file:RFSYS_MKL82Z7)           ================ */
/* ================================================================================ */

/**
 * @brief System register file
 */
/**
* @addtogroup RFSYS_structs_GROUP RFSYS struct
* @brief Struct for RFSYS
* @{
*/
typedef struct {                                /*       RFSYS Structure                                              */
   __IO uint32_t  REG[8];                       /**< 0000: Register file register                                       */
} RFSYS_Type;

/**
 * @} */ /* End group RFSYS_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RFSYS' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RFSYS_Register_Masks_GROUP RFSYS Register Masks
* @brief Register Masks for RFSYS
* @{
*/
/* ------- REG Bit Fields                           ------ */
#define RFSYS_REG_LL_MASK                        (0xFFU)                                             /*!< RFSYS_REG.LL Mask                       */
#define RFSYS_REG_LL_SHIFT                       (0U)                                                /*!< RFSYS_REG.LL Position                   */
#define RFSYS_REG_LL(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< RFSYS_REG.LL Field                      */
#define RFSYS_REG_LH_MASK                        (0xFF00U)                                           /*!< RFSYS_REG.LH Mask                       */
#define RFSYS_REG_LH_SHIFT                       (8U)                                                /*!< RFSYS_REG.LH Position                   */
#define RFSYS_REG_LH(x)                          (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< RFSYS_REG.LH Field                      */
#define RFSYS_REG_HL_MASK                        (0xFF0000U)                                         /*!< RFSYS_REG.HL Mask                       */
#define RFSYS_REG_HL_SHIFT                       (16U)                                               /*!< RFSYS_REG.HL Position                   */
#define RFSYS_REG_HL(x)                          (((uint32_t)(((uint32_t)(x))<<16U))&0xFF0000UL)     /*!< RFSYS_REG.HL Field                      */
#define RFSYS_REG_HH_MASK                        (0xFF000000U)                                       /*!< RFSYS_REG.HH Mask                       */
#define RFSYS_REG_HH_SHIFT                       (24U)                                               /*!< RFSYS_REG.HH Position                   */
#define RFSYS_REG_HH(x)                          (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< RFSYS_REG.HH Field                      */
/**
 * @} */ /* End group RFSYS_Register_Masks_GROUP 
 */

/* RFSYS - Peripheral instance base addresses */
#define RFSYS_BasePtr                  0x40041000UL //!< Peripheral base address
#define RFSYS                          ((RFSYS_Type *) RFSYS_BasePtr) //!< Freescale base pointer
#define RFSYS_BASE_PTR                 (RFSYS) //!< Freescale style base pointer
/**
 * @} */ /* End group RFSYS_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RFVBAT_Peripheral_access_layer_GROUP RFVBAT Peripheral Access Layer
* @brief C Struct for RFVBAT
* @{
*/

/* ================================================================================ */
/* ================           RFVBAT (file:RFVBAT_MKL82Z7)         ================ */
/* ================================================================================ */

/**
 * @brief VBAT register file
 */
/**
* @addtogroup RFVBAT_structs_GROUP RFVBAT struct
* @brief Struct for RFVBAT
* @{
*/
typedef struct {                                /*       RFVBAT Structure                                             */
   __IO uint32_t  REG[8];                       /**< 0000: VBAT register file register                                  */
} RFVBAT_Type;

/**
 * @} */ /* End group RFVBAT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RFVBAT' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RFVBAT_Register_Masks_GROUP RFVBAT Register Masks
* @brief Register Masks for RFVBAT
* @{
*/
/* ------- REG Bit Fields                           ------ */
#define RFVBAT_REG_LL_MASK                       (0xFFU)                                             /*!< RFVBAT_REG.LL Mask                      */
#define RFVBAT_REG_LL_SHIFT                      (0U)                                                /*!< RFVBAT_REG.LL Position                  */
#define RFVBAT_REG_LL(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< RFVBAT_REG.LL Field                     */
#define RFVBAT_REG_LH_MASK                       (0xFF00U)                                           /*!< RFVBAT_REG.LH Mask                      */
#define RFVBAT_REG_LH_SHIFT                      (8U)                                                /*!< RFVBAT_REG.LH Position                  */
#define RFVBAT_REG_LH(x)                         (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< RFVBAT_REG.LH Field                     */
#define RFVBAT_REG_HL_MASK                       (0xFF0000U)                                         /*!< RFVBAT_REG.HL Mask                      */
#define RFVBAT_REG_HL_SHIFT                      (16U)                                               /*!< RFVBAT_REG.HL Position                  */
#define RFVBAT_REG_HL(x)                         (((uint32_t)(((uint32_t)(x))<<16U))&0xFF0000UL)     /*!< RFVBAT_REG.HL Field                     */
#define RFVBAT_REG_HH_MASK                       (0xFF000000U)                                       /*!< RFVBAT_REG.HH Mask                      */
#define RFVBAT_REG_HH_SHIFT                      (24U)                                               /*!< RFVBAT_REG.HH Position                  */
#define RFVBAT_REG_HH(x)                         (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< RFVBAT_REG.HH Field                     */
/**
 * @} */ /* End group RFVBAT_Register_Masks_GROUP 
 */

/* RFVBAT - Peripheral instance base addresses */
#define RFVBAT_BasePtr                 0x4003E000UL //!< Peripheral base address
#define RFVBAT                         ((RFVBAT_Type *) RFVBAT_BasePtr) //!< Freescale base pointer
#define RFVBAT_BASE_PTR                (RFVBAT) //!< Freescale style base pointer
/**
 * @} */ /* End group RFVBAT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup ROM_Peripheral_access_layer_GROUP ROM Peripheral Access Layer
* @brief C Struct for ROM
* @{
*/

/* ================================================================================ */
/* ================           ROM (file:ROM_MKE15Z7)               ================ */
/* ================================================================================ */

/**
 * @brief System ROM
 */
/**
* @addtogroup ROM_structs_GROUP ROM struct
* @brief Struct for ROM
* @{
*/
typedef struct {                                /*       ROM Structure                                                */
   __I  uint32_t  ENTRY[3];                     /**< 0000: Entry                                                        */
   __I  uint32_t  TABLEMARK;                    /**< 000C: End of Table Marker Register                                 */
        uint8_t   RESERVED_0[4028];            
   __I  uint32_t  SYSACCESS;                    /**< 0FCC: System Access Register                                       */
   __I  uint32_t  PERIPHID4;                    /**< 0FD0: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID5;                    /**< 0FD4: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID6;                    /**< 0FD8: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID7;                    /**< 0FDC: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID0;                    /**< 0FE0: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID1;                    /**< 0FE4: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID2;                    /**< 0FE8: Peripheral ID Register                                       */
   __I  uint32_t  PERIPHID3;                    /**< 0FEC: Peripheral ID Register                                       */
   __I  uint32_t  COMPID[4];                    /**< 0FF0: Component ID Register                                        */
} ROM_Type;

/**
 * @} */ /* End group ROM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'ROM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup ROM_Register_Masks_GROUP ROM Register Masks
* @brief Register Masks for ROM
* @{
*/
/* ------- ENTRY Bit Fields                         ------ */
#define ROM_ENTRY_ENTRY_MASK                     (0xFFFFFFFFU)                                       /*!< ROM_ENTRY.ENTRY Mask                    */
#define ROM_ENTRY_ENTRY_SHIFT                    (0U)                                                /*!< ROM_ENTRY.ENTRY Position                */
#define ROM_ENTRY_ENTRY(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< ROM_ENTRY.ENTRY Field                   */
/* ------- TABLEMARK Bit Fields                     ------ */
#define ROM_TABLEMARK_MARK_MASK                  (0xFFFFFFFFU)                                       /*!< ROM_TABLEMARK.MARK Mask                 */
#define ROM_TABLEMARK_MARK_SHIFT                 (0U)                                                /*!< ROM_TABLEMARK.MARK Position             */
#define ROM_TABLEMARK_MARK(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< ROM_TABLEMARK.MARK Field                */
/* ------- SYSACCESS Bit Fields                     ------ */
#define ROM_SYSACCESS_SYSACCESS_MASK             (0xFFFFFFFFU)                                       /*!< ROM_SYSACCESS.SYSACCESS Mask            */
#define ROM_SYSACCESS_SYSACCESS_SHIFT            (0U)                                                /*!< ROM_SYSACCESS.SYSACCESS Position        */
#define ROM_SYSACCESS_SYSACCESS(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< ROM_SYSACCESS.SYSACCESS Field           */
/* ------- PERIPHID Bit Fields                      ------ */
#define ROM_PERIPHID_PERIPHID_MASK               (0xFFFFFFFFU)                                       /*!< ROM_PERIPHID.PERIPHID Mask              */
#define ROM_PERIPHID_PERIPHID_SHIFT              (0U)                                                /*!< ROM_PERIPHID.PERIPHID Position          */
#define ROM_PERIPHID_PERIPHID(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< ROM_PERIPHID.PERIPHID Field             */
/* ------- COMPID Bit Fields                        ------ */
#define ROM_COMPID_COMPID_MASK                   (0xFFFFFFFFU)                                       /*!< ROM_COMPID.COMPID Mask                  */
#define ROM_COMPID_COMPID_SHIFT                  (0U)                                                /*!< ROM_COMPID.COMPID Position              */
#define ROM_COMPID_COMPID(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< ROM_COMPID.COMPID Field                 */
/**
 * @} */ /* End group ROM_Register_Masks_GROUP 
 */

/* ROM - Peripheral instance base addresses */
#define ROM_BasePtr                    0xF0002000UL //!< Peripheral base address
#define ROM                            ((ROM_Type *) ROM_BasePtr) //!< Freescale base pointer
#define ROM_BASE_PTR                   (ROM) //!< Freescale style base pointer
/**
 * @} */ /* End group ROM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RTC_Peripheral_access_layer_GROUP RTC Peripheral Access Layer
* @brief C Struct for RTC
* @{
*/

/* ================================================================================ */
/* ================           RTC (file:RTC_MK82F25615)            ================ */
/* ================================================================================ */

/**
 * @brief Secure Real Time Clock
 */
/**
* @addtogroup RTC_structs_GROUP RTC struct
* @brief Struct for RTC
* @{
*/
typedef struct {                                /*       RTC Structure                                                */
   __IO uint32_t  TSR;                          /**< 0000: Time Seconds Register                                        */
   __IO uint32_t  TPR;                          /**< 0004: Time Prescaler Register                                      */
   __IO uint32_t  TAR;                          /**< 0008: Time Alarm Register                                          */
   __IO uint32_t  TCR;                          /**< 000C: Time Compensation Register                                   */
   __IO uint32_t  CR;                           /**< 0010: Control Register                                             */
   __IO uint32_t  SR;                           /**< 0014: Status Register                                              */
   __IO uint32_t  LR;                           /**< 0018: Lock Register                                                */
   __IO uint32_t  IER;                          /**< 001C: Interrupt Enable Register                                    */
        uint8_t   RESERVED_0[2016];            
   __IO uint32_t  WAR;                          /**< 0800: Write Access Register                                        */
   __IO uint32_t  RAR;                          /**< 0804: Read Access Register                                         */
} RTC_Type;

/**
 * @} */ /* End group RTC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RTC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RTC_Register_Masks_GROUP RTC Register Masks
* @brief Register Masks for RTC
* @{
*/
/* ------- TSR Bit Fields                           ------ */
#define RTC_TSR_TSR_MASK                         (0xFFFFFFFFU)                                       /*!< RTC_TSR.TSR Mask                        */
#define RTC_TSR_TSR_SHIFT                        (0U)                                                /*!< RTC_TSR.TSR Position                    */
#define RTC_TSR_TSR(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< RTC_TSR.TSR Field                       */
/* ------- TPR Bit Fields                           ------ */
#define RTC_TPR_TPR_MASK                         (0xFFFFU)                                           /*!< RTC_TPR.TPR Mask                        */
#define RTC_TPR_TPR_SHIFT                        (0U)                                                /*!< RTC_TPR.TPR Position                    */
#define RTC_TPR_TPR(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< RTC_TPR.TPR Field                       */
/* ------- TAR Bit Fields                           ------ */
#define RTC_TAR_TAR_MASK                         (0xFFFFFFFFU)                                       /*!< RTC_TAR.TAR Mask                        */
#define RTC_TAR_TAR_SHIFT                        (0U)                                                /*!< RTC_TAR.TAR Position                    */
#define RTC_TAR_TAR(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< RTC_TAR.TAR Field                       */
/* ------- TCR Bit Fields                           ------ */
#define RTC_TCR_TCR_MASK                         (0xFFU)                                             /*!< RTC_TCR.TCR Mask                        */
#define RTC_TCR_TCR_SHIFT                        (0U)                                                /*!< RTC_TCR.TCR Position                    */
#define RTC_TCR_TCR(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< RTC_TCR.TCR Field                       */
#define RTC_TCR_CIR_MASK                         (0xFF00U)                                           /*!< RTC_TCR.CIR Mask                        */
#define RTC_TCR_CIR_SHIFT                        (8U)                                                /*!< RTC_TCR.CIR Position                    */
#define RTC_TCR_CIR(x)                           (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< RTC_TCR.CIR Field                       */
#define RTC_TCR_TCV_MASK                         (0xFF0000U)                                         /*!< RTC_TCR.TCV Mask                        */
#define RTC_TCR_TCV_SHIFT                        (16U)                                               /*!< RTC_TCR.TCV Position                    */
#define RTC_TCR_TCV(x)                           (((uint32_t)(((uint32_t)(x))<<16U))&0xFF0000UL)     /*!< RTC_TCR.TCV Field                       */
#define RTC_TCR_CIC_MASK                         (0xFF000000U)                                       /*!< RTC_TCR.CIC Mask                        */
#define RTC_TCR_CIC_SHIFT                        (24U)                                               /*!< RTC_TCR.CIC Position                    */
#define RTC_TCR_CIC(x)                           (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< RTC_TCR.CIC Field                       */
/* ------- CR Bit Fields                            ------ */
#define RTC_CR_SWR_MASK                          (0x1U)                                              /*!< RTC_CR.SWR Mask                         */
#define RTC_CR_SWR_SHIFT                         (0U)                                                /*!< RTC_CR.SWR Position                     */
#define RTC_CR_SWR(x)                            (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< RTC_CR.SWR Field                        */
#define RTC_CR_WPE_MASK                          (0x2U)                                              /*!< RTC_CR.WPE Mask                         */
#define RTC_CR_WPE_SHIFT                         (1U)                                                /*!< RTC_CR.WPE Position                     */
#define RTC_CR_WPE(x)                            (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< RTC_CR.WPE Field                        */
#define RTC_CR_SUP_MASK                          (0x4U)                                              /*!< RTC_CR.SUP Mask                         */
#define RTC_CR_SUP_SHIFT                         (2U)                                                /*!< RTC_CR.SUP Position                     */
#define RTC_CR_SUP(x)                            (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< RTC_CR.SUP Field                        */
#define RTC_CR_UM_MASK                           (0x8U)                                              /*!< RTC_CR.UM Mask                          */
#define RTC_CR_UM_SHIFT                          (3U)                                                /*!< RTC_CR.UM Position                      */
#define RTC_CR_UM(x)                             (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< RTC_CR.UM Field                         */
#define RTC_CR_WPS_MASK                          (0x10U)                                             /*!< RTC_CR.WPS Mask                         */
#define RTC_CR_WPS_SHIFT                         (4U)                                                /*!< RTC_CR.WPS Position                     */
#define RTC_CR_WPS(x)                            (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< RTC_CR.WPS Field                        */
#define RTC_CR_OSCE_MASK                         (0x100U)                                            /*!< RTC_CR.OSCE Mask                        */
#define RTC_CR_OSCE_SHIFT                        (8U)                                                /*!< RTC_CR.OSCE Position                    */
#define RTC_CR_OSCE(x)                           (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< RTC_CR.OSCE Field                       */
#define RTC_CR_CLKO_MASK                         (0x200U)                                            /*!< RTC_CR.CLKO Mask                        */
#define RTC_CR_CLKO_SHIFT                        (9U)                                                /*!< RTC_CR.CLKO Position                    */
#define RTC_CR_CLKO(x)                           (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< RTC_CR.CLKO Field                       */
#define RTC_CR_SCP_MASK                          (0x3C00U)                                           /*!< RTC_CR.SCP Mask                         */
#define RTC_CR_SCP_SHIFT                         (10U)                                               /*!< RTC_CR.SCP Position                     */
#define RTC_CR_SCP(x)                            (((uint32_t)(((uint32_t)(x))<<10U))&0x3C00UL)       /*!< RTC_CR.SCP Field                        */
#define RTC_CR_SC16P_MASK                        (0x400U)                                            /*!< RTC_CR.SC16P Mask                       */
#define RTC_CR_SC16P_SHIFT                       (10U)                                               /*!< RTC_CR.SC16P Position                   */
#define RTC_CR_SC16P(x)                          (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< RTC_CR.SC16P Field                      */
#define RTC_CR_SC8P_MASK                         (0x800U)                                            /*!< RTC_CR.SC8P Mask                        */
#define RTC_CR_SC8P_SHIFT                        (11U)                                               /*!< RTC_CR.SC8P Position                    */
#define RTC_CR_SC8P(x)                           (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< RTC_CR.SC8P Field                       */
#define RTC_CR_SC4P_MASK                         (0x1000U)                                           /*!< RTC_CR.SC4P Mask                        */
#define RTC_CR_SC4P_SHIFT                        (12U)                                               /*!< RTC_CR.SC4P Position                    */
#define RTC_CR_SC4P(x)                           (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< RTC_CR.SC4P Field                       */
#define RTC_CR_SC2P_MASK                         (0x2000U)                                           /*!< RTC_CR.SC2P Mask                        */
#define RTC_CR_SC2P_SHIFT                        (13U)                                               /*!< RTC_CR.SC2P Position                    */
#define RTC_CR_SC2P(x)                           (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< RTC_CR.SC2P Field                       */
/* ------- SR Bit Fields                            ------ */
#define RTC_SR_TIF_MASK                          (0x1U)                                              /*!< RTC_SR.TIF Mask                         */
#define RTC_SR_TIF_SHIFT                         (0U)                                                /*!< RTC_SR.TIF Position                     */
#define RTC_SR_TIF(x)                            (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< RTC_SR.TIF Field                        */
#define RTC_SR_TOF_MASK                          (0x2U)                                              /*!< RTC_SR.TOF Mask                         */
#define RTC_SR_TOF_SHIFT                         (1U)                                                /*!< RTC_SR.TOF Position                     */
#define RTC_SR_TOF(x)                            (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< RTC_SR.TOF Field                        */
#define RTC_SR_TAF_MASK                          (0x4U)                                              /*!< RTC_SR.TAF Mask                         */
#define RTC_SR_TAF_SHIFT                         (2U)                                                /*!< RTC_SR.TAF Position                     */
#define RTC_SR_TAF(x)                            (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< RTC_SR.TAF Field                        */
#define RTC_SR_TCE_MASK                          (0x10U)                                             /*!< RTC_SR.TCE Mask                         */
#define RTC_SR_TCE_SHIFT                         (4U)                                                /*!< RTC_SR.TCE Position                     */
#define RTC_SR_TCE(x)                            (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< RTC_SR.TCE Field                        */
/* ------- LR Bit Fields                            ------ */
#define RTC_LR_TCL_MASK                          (0x8U)                                              /*!< RTC_LR.TCL Mask                         */
#define RTC_LR_TCL_SHIFT                         (3U)                                                /*!< RTC_LR.TCL Position                     */
#define RTC_LR_TCL(x)                            (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< RTC_LR.TCL Field                        */
#define RTC_LR_CRL_MASK                          (0x10U)                                             /*!< RTC_LR.CRL Mask                         */
#define RTC_LR_CRL_SHIFT                         (4U)                                                /*!< RTC_LR.CRL Position                     */
#define RTC_LR_CRL(x)                            (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< RTC_LR.CRL Field                        */
#define RTC_LR_SRL_MASK                          (0x20U)                                             /*!< RTC_LR.SRL Mask                         */
#define RTC_LR_SRL_SHIFT                         (5U)                                                /*!< RTC_LR.SRL Position                     */
#define RTC_LR_SRL(x)                            (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< RTC_LR.SRL Field                        */
#define RTC_LR_LRL_MASK                          (0x40U)                                             /*!< RTC_LR.LRL Mask                         */
#define RTC_LR_LRL_SHIFT                         (6U)                                                /*!< RTC_LR.LRL Position                     */
#define RTC_LR_LRL(x)                            (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< RTC_LR.LRL Field                        */
/* ------- IER Bit Fields                           ------ */
#define RTC_IER_TIIE_MASK                        (0x1U)                                              /*!< RTC_IER.TIIE Mask                       */
#define RTC_IER_TIIE_SHIFT                       (0U)                                                /*!< RTC_IER.TIIE Position                   */
#define RTC_IER_TIIE(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< RTC_IER.TIIE Field                      */
#define RTC_IER_TOIE_MASK                        (0x2U)                                              /*!< RTC_IER.TOIE Mask                       */
#define RTC_IER_TOIE_SHIFT                       (1U)                                                /*!< RTC_IER.TOIE Position                   */
#define RTC_IER_TOIE(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< RTC_IER.TOIE Field                      */
#define RTC_IER_TAIE_MASK                        (0x4U)                                              /*!< RTC_IER.TAIE Mask                       */
#define RTC_IER_TAIE_SHIFT                       (2U)                                                /*!< RTC_IER.TAIE Position                   */
#define RTC_IER_TAIE(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< RTC_IER.TAIE Field                      */
#define RTC_IER_TSIE_MASK                        (0x10U)                                             /*!< RTC_IER.TSIE Mask                       */
#define RTC_IER_TSIE_SHIFT                       (4U)                                                /*!< RTC_IER.TSIE Position                   */
#define RTC_IER_TSIE(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< RTC_IER.TSIE Field                      */
#define RTC_IER_WPON_MASK                        (0x80U)                                             /*!< RTC_IER.WPON Mask                       */
#define RTC_IER_WPON_SHIFT                       (7U)                                                /*!< RTC_IER.WPON Position                   */
#define RTC_IER_WPON(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< RTC_IER.WPON Field                      */
/* ------- WAR Bit Fields                           ------ */
#define RTC_WAR_TSRW_MASK                        (0x1U)                                              /*!< RTC_WAR.TSRW Mask                       */
#define RTC_WAR_TSRW_SHIFT                       (0U)                                                /*!< RTC_WAR.TSRW Position                   */
#define RTC_WAR_TSRW(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< RTC_WAR.TSRW Field                      */
#define RTC_WAR_TPRW_MASK                        (0x2U)                                              /*!< RTC_WAR.TPRW Mask                       */
#define RTC_WAR_TPRW_SHIFT                       (1U)                                                /*!< RTC_WAR.TPRW Position                   */
#define RTC_WAR_TPRW(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< RTC_WAR.TPRW Field                      */
#define RTC_WAR_TARW_MASK                        (0x4U)                                              /*!< RTC_WAR.TARW Mask                       */
#define RTC_WAR_TARW_SHIFT                       (2U)                                                /*!< RTC_WAR.TARW Position                   */
#define RTC_WAR_TARW(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< RTC_WAR.TARW Field                      */
#define RTC_WAR_TCRW_MASK                        (0x8U)                                              /*!< RTC_WAR.TCRW Mask                       */
#define RTC_WAR_TCRW_SHIFT                       (3U)                                                /*!< RTC_WAR.TCRW Position                   */
#define RTC_WAR_TCRW(x)                          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< RTC_WAR.TCRW Field                      */
#define RTC_WAR_CRW_MASK                         (0x10U)                                             /*!< RTC_WAR.CRW Mask                        */
#define RTC_WAR_CRW_SHIFT                        (4U)                                                /*!< RTC_WAR.CRW Position                    */
#define RTC_WAR_CRW(x)                           (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< RTC_WAR.CRW Field                       */
#define RTC_WAR_SRW_MASK                         (0x20U)                                             /*!< RTC_WAR.SRW Mask                        */
#define RTC_WAR_SRW_SHIFT                        (5U)                                                /*!< RTC_WAR.SRW Position                    */
#define RTC_WAR_SRW(x)                           (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< RTC_WAR.SRW Field                       */
#define RTC_WAR_LRW_MASK                         (0x40U)                                             /*!< RTC_WAR.LRW Mask                        */
#define RTC_WAR_LRW_SHIFT                        (6U)                                                /*!< RTC_WAR.LRW Position                    */
#define RTC_WAR_LRW(x)                           (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< RTC_WAR.LRW Field                       */
#define RTC_WAR_IERW_MASK                        (0x80U)                                             /*!< RTC_WAR.IERW Mask                       */
#define RTC_WAR_IERW_SHIFT                       (7U)                                                /*!< RTC_WAR.IERW Position                   */
#define RTC_WAR_IERW(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< RTC_WAR.IERW Field                      */
/* ------- RAR Bit Fields                           ------ */
#define RTC_RAR_TSRR_MASK                        (0x1U)                                              /*!< RTC_RAR.TSRR Mask                       */
#define RTC_RAR_TSRR_SHIFT                       (0U)                                                /*!< RTC_RAR.TSRR Position                   */
#define RTC_RAR_TSRR(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< RTC_RAR.TSRR Field                      */
#define RTC_RAR_TPRR_MASK                        (0x2U)                                              /*!< RTC_RAR.TPRR Mask                       */
#define RTC_RAR_TPRR_SHIFT                       (1U)                                                /*!< RTC_RAR.TPRR Position                   */
#define RTC_RAR_TPRR(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< RTC_RAR.TPRR Field                      */
#define RTC_RAR_TARR_MASK                        (0x4U)                                              /*!< RTC_RAR.TARR Mask                       */
#define RTC_RAR_TARR_SHIFT                       (2U)                                                /*!< RTC_RAR.TARR Position                   */
#define RTC_RAR_TARR(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< RTC_RAR.TARR Field                      */
#define RTC_RAR_TCRR_MASK                        (0x8U)                                              /*!< RTC_RAR.TCRR Mask                       */
#define RTC_RAR_TCRR_SHIFT                       (3U)                                                /*!< RTC_RAR.TCRR Position                   */
#define RTC_RAR_TCRR(x)                          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< RTC_RAR.TCRR Field                      */
#define RTC_RAR_CRR_MASK                         (0x10U)                                             /*!< RTC_RAR.CRR Mask                        */
#define RTC_RAR_CRR_SHIFT                        (4U)                                                /*!< RTC_RAR.CRR Position                    */
#define RTC_RAR_CRR(x)                           (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< RTC_RAR.CRR Field                       */
#define RTC_RAR_SRR_MASK                         (0x20U)                                             /*!< RTC_RAR.SRR Mask                        */
#define RTC_RAR_SRR_SHIFT                        (5U)                                                /*!< RTC_RAR.SRR Position                    */
#define RTC_RAR_SRR(x)                           (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< RTC_RAR.SRR Field                       */
#define RTC_RAR_LRR_MASK                         (0x40U)                                             /*!< RTC_RAR.LRR Mask                        */
#define RTC_RAR_LRR_SHIFT                        (6U)                                                /*!< RTC_RAR.LRR Position                    */
#define RTC_RAR_LRR(x)                           (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< RTC_RAR.LRR Field                       */
#define RTC_RAR_IERR_MASK                        (0x80U)                                             /*!< RTC_RAR.IERR Mask                       */
#define RTC_RAR_IERR_SHIFT                       (7U)                                                /*!< RTC_RAR.IERR Position                   */
#define RTC_RAR_IERR(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< RTC_RAR.IERR Field                      */
/**
 * @} */ /* End group RTC_Register_Masks_GROUP 
 */

/* RTC - Peripheral instance base addresses */
#define RTC_BasePtr                    0x4003D000UL //!< Peripheral base address
#define RTC                            ((RTC_Type *) RTC_BasePtr) //!< Freescale base pointer
#define RTC_BASE_PTR                   (RTC) //!< Freescale style base pointer
/**
 * @} */ /* End group RTC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SIM_Peripheral_access_layer_GROUP SIM Peripheral Access Layer
* @brief C Struct for SIM
* @{
*/

/* ================================================================================ */
/* ================           SIM (file:SIM_MKL82Z7)               ================ */
/* ================================================================================ */

/**
 * @brief System Integration Module
 */
/**
* @addtogroup SIM_structs_GROUP SIM struct
* @brief Struct for SIM
* @{
*/
typedef struct {                                /*       SIM Structure                                                */
   __IO uint32_t  SOPT1;                        /**< 0000: System Options Register 1                                    */
        uint8_t   RESERVED_0[4096];            
   __IO uint32_t  SOPT2;                        /**< 1004: System Options Register 2                                    */
        uint8_t   RESERVED_1[8];               
   __IO uint32_t  SOPT5;                        /**< 1010: System Options Register 5                                    */
        uint8_t   RESERVED_2[4];               
   __IO uint32_t  SOPT7;                        /**< 1018: System Options Register 7                                    */
        uint8_t   RESERVED_3[4];               
   __IO uint32_t  SOPT9;                        /**< 1020: System Options Register 9                                    */
   __I  uint32_t  SDID;                         /**< 1024: System Device Identification Register                        */
        uint8_t   RESERVED_4[12];              
   __IO uint32_t  SCGC4;                        /**< 1034: System Clock Gating Control Register 4                       */
   __IO uint32_t  SCGC5;                        /**< 1038: System Clock Gating Control Register 5                       */
   __IO uint32_t  SCGC6;                        /**< 103C: System Clock Gating Control Register 6                       */
   __IO uint32_t  SCGC7;                        /**< 1040: System Clock Gating Control Register 7                       */
   __IO uint32_t  CLKDIV1;                      /**< 1044: System Clock Divider Register 1                              */
   __IO uint32_t  CLKDIV2;                      /**< 1048: System Clock Divider Register 2                              */
   __IO uint32_t  FCFG1;                        /**< 104C: Flash Configuration Register 1                               */
   __I  uint32_t  FCFG2;                        /**< 1050: Flash Configuration Register 2                               */
   __I  uint32_t  UIDH;                         /**< 1054: Unique Identification Register High                          */
   __I  uint32_t  UIDMH;                        /**< 1058: Unique Identification Register Mid-High                      */
   __I  uint32_t  UIDML;                        /**< 105C: Unique Identification Register Mid Low                       */
   __I  uint32_t  UIDL;                         /**< 1060: Unique Identification Register Low                           */
   __IO uint32_t  CLKDIV3;                      /**< 1064: System Clock Divider Register 3                              */
        uint8_t   RESERVED_5[4];               
   __IO uint32_t  MISCCTRL;                     /**< 106C: Misc Control Register                                        */
        uint8_t   RESERVED_6[32];              
   __I  uint32_t  SECKEY[4];                    /**< 1090: Secure Key Register                                          */
} SIM_Type;

/**
 * @} */ /* End group SIM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SIM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SIM_Register_Masks_GROUP SIM Register Masks
* @brief Register Masks for SIM
* @{
*/
/* ------- SOPT1 Bit Fields                         ------ */
#define SIM_SOPT1_RAMSIZE_MASK                   (0xF000U)                                           /*!< SIM_SOPT1.RAMSIZE Mask                  */
#define SIM_SOPT1_RAMSIZE_SHIFT                  (12U)                                               /*!< SIM_SOPT1.RAMSIZE Position              */
#define SIM_SOPT1_RAMSIZE(x)                     (((uint32_t)(((uint32_t)(x))<<12U))&0xF000UL)       /*!< SIM_SOPT1.RAMSIZE Field                 */
#define SIM_SOPT1_OSC32KSEL_MASK                 (0xC0000U)                                          /*!< SIM_SOPT1.OSC32KSEL Mask                */
#define SIM_SOPT1_OSC32KSEL_SHIFT                (18U)                                               /*!< SIM_SOPT1.OSC32KSEL Position            */
#define SIM_SOPT1_OSC32KSEL(x)                   (((uint32_t)(((uint32_t)(x))<<18U))&0xC0000UL)      /*!< SIM_SOPT1.OSC32KSEL Field               */
/* ------- SOPT2 Bit Fields                         ------ */
#define SIM_SOPT2_RTCCLKOUTS_MASK                (0x10U)                                             /*!< SIM_SOPT2.RTCCLKOUTS Mask               */
#define SIM_SOPT2_RTCCLKOUTS_SHIFT               (4U)                                                /*!< SIM_SOPT2.RTCCLKOUTS Position           */
#define SIM_SOPT2_RTCCLKOUTS(x)                  (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SIM_SOPT2.RTCCLKOUTS Field              */
#define SIM_SOPT2_CLKOUT_MASK                    (0xE0U)                                             /*!< SIM_SOPT2.CLKOUT Mask                   */
#define SIM_SOPT2_CLKOUT_SHIFT                   (5U)                                                /*!< SIM_SOPT2.CLKOUT Position               */
#define SIM_SOPT2_CLKOUT(x)                      (((uint32_t)(((uint32_t)(x))<<5U))&0xE0UL)          /*!< SIM_SOPT2.CLKOUT Field                  */
#define SIM_SOPT2_PLLFLLSEL_MASK                 (0x30000U)                                          /*!< SIM_SOPT2.PLLFLLSEL Mask                */
#define SIM_SOPT2_PLLFLLSEL_SHIFT                (16U)                                               /*!< SIM_SOPT2.PLLFLLSEL Position            */
#define SIM_SOPT2_PLLFLLSEL(x)                   (((uint32_t)(((uint32_t)(x))<<16U))&0x30000UL)      /*!< SIM_SOPT2.PLLFLLSEL Field               */
#define SIM_SOPT2_USBSRC_MASK                    (0x40000U)                                          /*!< SIM_SOPT2.USBSRC Mask                   */
#define SIM_SOPT2_USBSRC_SHIFT                   (18U)                                               /*!< SIM_SOPT2.USBSRC Position               */
#define SIM_SOPT2_USBSRC(x)                      (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< SIM_SOPT2.USBSRC Field                  */
#define SIM_SOPT2_FLEXIOSRC_MASK                 (0xC00000U)                                         /*!< SIM_SOPT2.FLEXIOSRC Mask                */
#define SIM_SOPT2_FLEXIOSRC_SHIFT                (22U)                                               /*!< SIM_SOPT2.FLEXIOSRC Position            */
#define SIM_SOPT2_FLEXIOSRC(x)                   (((uint32_t)(((uint32_t)(x))<<22U))&0xC00000UL)     /*!< SIM_SOPT2.FLEXIOSRC Field               */
#define SIM_SOPT2_TPMSRC_MASK                    (0x3000000U)                                        /*!< SIM_SOPT2.TPMSRC Mask                   */
#define SIM_SOPT2_TPMSRC_SHIFT                   (24U)                                               /*!< SIM_SOPT2.TPMSRC Position               */
#define SIM_SOPT2_TPMSRC(x)                      (((uint32_t)(((uint32_t)(x))<<24U))&0x3000000UL)    /*!< SIM_SOPT2.TPMSRC Field                  */
#define SIM_SOPT2_LPUARTSRC_MASK                 (0xC000000U)                                        /*!< SIM_SOPT2.LPUARTSRC Mask                */
#define SIM_SOPT2_LPUARTSRC_SHIFT                (26U)                                               /*!< SIM_SOPT2.LPUARTSRC Position            */
#define SIM_SOPT2_LPUARTSRC(x)                   (((uint32_t)(((uint32_t)(x))<<26U))&0xC000000UL)    /*!< SIM_SOPT2.LPUARTSRC Field               */
#define SIM_SOPT2_EMVSIMSRC_MASK                 (0xC0000000U)                                       /*!< SIM_SOPT2.EMVSIMSRC Mask                */
#define SIM_SOPT2_EMVSIMSRC_SHIFT                (30U)                                               /*!< SIM_SOPT2.EMVSIMSRC Position            */
#define SIM_SOPT2_EMVSIMSRC(x)                   (((uint32_t)(((uint32_t)(x))<<30U))&0xC0000000UL)   /*!< SIM_SOPT2.EMVSIMSRC Field               */
/* ------- SOPT5 Bit Fields                         ------ */
#define SIM_SOPT5_LPUART0TXSRC_MASK              (0x30000U)                                          /*!< SIM_SOPT5.LPUART0TXSRC Mask             */
#define SIM_SOPT5_LPUART0TXSRC_SHIFT             (16U)                                               /*!< SIM_SOPT5.LPUART0TXSRC Position         */
#define SIM_SOPT5_LPUART0TXSRC(x)                (((uint32_t)(((uint32_t)(x))<<16U))&0x30000UL)      /*!< SIM_SOPT5.LPUART0TXSRC Field            */
#define SIM_SOPT5_LPUART0RXSRC_MASK              (0xC0000U)                                          /*!< SIM_SOPT5.LPUART0RXSRC Mask             */
#define SIM_SOPT5_LPUART0RXSRC_SHIFT             (18U)                                               /*!< SIM_SOPT5.LPUART0RXSRC Position         */
#define SIM_SOPT5_LPUART0RXSRC(x)                (((uint32_t)(((uint32_t)(x))<<18U))&0xC0000UL)      /*!< SIM_SOPT5.LPUART0RXSRC Field            */
#define SIM_SOPT5_LPUART1TXSRC_MASK              (0x300000U)                                         /*!< SIM_SOPT5.LPUART1TXSRC Mask             */
#define SIM_SOPT5_LPUART1TXSRC_SHIFT             (20U)                                               /*!< SIM_SOPT5.LPUART1TXSRC Position         */
#define SIM_SOPT5_LPUART1TXSRC(x)                (((uint32_t)(((uint32_t)(x))<<20U))&0x300000UL)     /*!< SIM_SOPT5.LPUART1TXSRC Field            */
#define SIM_SOPT5_LPUART1RXSRC_MASK              (0xC00000U)                                         /*!< SIM_SOPT5.LPUART1RXSRC Mask             */
#define SIM_SOPT5_LPUART1RXSRC_SHIFT             (22U)                                               /*!< SIM_SOPT5.LPUART1RXSRC Position         */
#define SIM_SOPT5_LPUART1RXSRC(x)                (((uint32_t)(((uint32_t)(x))<<22U))&0xC00000UL)     /*!< SIM_SOPT5.LPUART1RXSRC Field            */
/* ------- SOPT7 Bit Fields                         ------ */
#define SIM_SOPT7_ADC0TRGSEL_MASK                (0xFU)                                              /*!< SIM_SOPT7.ADC0TRGSEL Mask               */
#define SIM_SOPT7_ADC0TRGSEL_SHIFT               (0U)                                                /*!< SIM_SOPT7.ADC0TRGSEL Position           */
#define SIM_SOPT7_ADC0TRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< SIM_SOPT7.ADC0TRGSEL Field              */
#define SIM_SOPT7_ADC0PRETRGSEL_MASK             (0x10U)                                             /*!< SIM_SOPT7.ADC0PRETRGSEL Mask            */
#define SIM_SOPT7_ADC0PRETRGSEL_SHIFT            (4U)                                                /*!< SIM_SOPT7.ADC0PRETRGSEL Position        */
#define SIM_SOPT7_ADC0PRETRGSEL(x)               (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SIM_SOPT7.ADC0PRETRGSEL Field           */
/* ------- SOPT9 Bit Fields                         ------ */
#define SIM_SOPT9_TPM1CH0SRC_MASK                (0xC0000U)                                          /*!< SIM_SOPT9.TPM1CH0SRC Mask               */
#define SIM_SOPT9_TPM1CH0SRC_SHIFT               (18U)                                               /*!< SIM_SOPT9.TPM1CH0SRC Position           */
#define SIM_SOPT9_TPM1CH0SRC(x)                  (((uint32_t)(((uint32_t)(x))<<18U))&0xC0000UL)      /*!< SIM_SOPT9.TPM1CH0SRC Field              */
#define SIM_SOPT9_TPM2CH0SRC_MASK                (0x300000U)                                         /*!< SIM_SOPT9.TPM2CH0SRC Mask               */
#define SIM_SOPT9_TPM2CH0SRC_SHIFT               (20U)                                               /*!< SIM_SOPT9.TPM2CH0SRC Position           */
#define SIM_SOPT9_TPM2CH0SRC(x)                  (((uint32_t)(((uint32_t)(x))<<20U))&0x300000UL)     /*!< SIM_SOPT9.TPM2CH0SRC Field              */
#define SIM_SOPT9_TPM0CLKSEL_MASK                (0x1000000U)                                        /*!< SIM_SOPT9.TPM0CLKSEL Mask               */
#define SIM_SOPT9_TPM0CLKSEL_SHIFT               (24U)                                               /*!< SIM_SOPT9.TPM0CLKSEL Position           */
#define SIM_SOPT9_TPM0CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< SIM_SOPT9.TPM0CLKSEL Field              */
#define SIM_SOPT9_TPM1CLKSEL_MASK                (0x2000000U)                                        /*!< SIM_SOPT9.TPM1CLKSEL Mask               */
#define SIM_SOPT9_TPM1CLKSEL_SHIFT               (25U)                                               /*!< SIM_SOPT9.TPM1CLKSEL Position           */
#define SIM_SOPT9_TPM1CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< SIM_SOPT9.TPM1CLKSEL Field              */
#define SIM_SOPT9_TPM2CLKSEL_MASK                (0x4000000U)                                        /*!< SIM_SOPT9.TPM2CLKSEL Mask               */
#define SIM_SOPT9_TPM2CLKSEL_SHIFT               (26U)                                               /*!< SIM_SOPT9.TPM2CLKSEL Position           */
#define SIM_SOPT9_TPM2CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< SIM_SOPT9.TPM2CLKSEL Field              */
/* ------- SDID Bit Fields                          ------ */
#define SIM_SDID_PINID_MASK                      (0xFU)                                              /*!< SIM_SDID.PINID Mask                     */
#define SIM_SDID_PINID_SHIFT                     (0U)                                                /*!< SIM_SDID.PINID Position                 */
#define SIM_SDID_PINID(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< SIM_SDID.PINID Field                    */
#define SIM_SDID_FAMID_MASK                      (0x70U)                                             /*!< SIM_SDID.FAMID Mask                     */
#define SIM_SDID_FAMID_SHIFT                     (4U)                                                /*!< SIM_SDID.FAMID Position                 */
#define SIM_SDID_FAMID(x)                        (((uint32_t)(((uint32_t)(x))<<4U))&0x70UL)          /*!< SIM_SDID.FAMID Field                    */
#define SIM_SDID_DIEID_MASK                      (0xF80U)                                            /*!< SIM_SDID.DIEID Mask                     */
#define SIM_SDID_DIEID_SHIFT                     (7U)                                                /*!< SIM_SDID.DIEID Position                 */
#define SIM_SDID_DIEID(x)                        (((uint32_t)(((uint32_t)(x))<<7U))&0xF80UL)         /*!< SIM_SDID.DIEID Field                    */
#define SIM_SDID_REVID_MASK                      (0xF000U)                                           /*!< SIM_SDID.REVID Mask                     */
#define SIM_SDID_REVID_SHIFT                     (12U)                                               /*!< SIM_SDID.REVID Position                 */
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x))<<12U))&0xF000UL)       /*!< SIM_SDID.REVID Field                    */
#define SIM_SDID_SUBFAMID_MASK                   (0xF000000U)                                        /*!< SIM_SDID.SUBFAMID Mask                  */
#define SIM_SDID_SUBFAMID_SHIFT                  (24U)                                               /*!< SIM_SDID.SUBFAMID Position              */
#define SIM_SDID_SUBFAMID(x)                     (((uint32_t)(((uint32_t)(x))<<24U))&0xF000000UL)    /*!< SIM_SDID.SUBFAMID Field                 */
#define SIM_SDID_FAMILYID_MASK                   (0xF0000000U)                                       /*!< SIM_SDID.FAMILYID Mask                  */
#define SIM_SDID_FAMILYID_SHIFT                  (28U)                                               /*!< SIM_SDID.FAMILYID Position              */
#define SIM_SDID_FAMILYID(x)                     (((uint32_t)(((uint32_t)(x))<<28U))&0xF0000000UL)   /*!< SIM_SDID.FAMILYID Field                 */
/* ------- SCGC4 Bit Fields                         ------ */
#define SIM_SCGC4_EWM_MASK                       (0x2U)                                              /*!< SIM_SCGC4.EWM Mask                      */
#define SIM_SCGC4_EWM_SHIFT                      (1U)                                                /*!< SIM_SCGC4.EWM Position                  */
#define SIM_SCGC4_EWM(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SIM_SCGC4.EWM Field                     */
#define SIM_SCGC4_I2C0_MASK                      (0x40U)                                             /*!< SIM_SCGC4.I2C0 Mask                     */
#define SIM_SCGC4_I2C0_SHIFT                     (6U)                                                /*!< SIM_SCGC4.I2C0 Position                 */
#define SIM_SCGC4_I2C0(x)                        (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< SIM_SCGC4.I2C0 Field                    */
#define SIM_SCGC4_I2C1_MASK                      (0x80U)                                             /*!< SIM_SCGC4.I2C1 Mask                     */
#define SIM_SCGC4_I2C1_SHIFT                     (7U)                                                /*!< SIM_SCGC4.I2C1 Position                 */
#define SIM_SCGC4_I2C1(x)                        (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< SIM_SCGC4.I2C1 Field                    */
#define SIM_SCGC4_USBOTG_MASK                    (0x40000U)                                          /*!< SIM_SCGC4.USBOTG Mask                   */
#define SIM_SCGC4_USBOTG_SHIFT                   (18U)                                               /*!< SIM_SCGC4.USBOTG Position               */
#define SIM_SCGC4_USBOTG(x)                      (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< SIM_SCGC4.USBOTG Field                  */
#define SIM_SCGC4_CMP_MASK                       (0x80000U)                                          /*!< SIM_SCGC4.CMP Mask                      */
#define SIM_SCGC4_CMP_SHIFT                      (19U)                                               /*!< SIM_SCGC4.CMP Position                  */
#define SIM_SCGC4_CMP(x)                         (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< SIM_SCGC4.CMP Field                     */
#define SIM_SCGC4_VREF_MASK                      (0x100000U)                                         /*!< SIM_SCGC4.VREF Mask                     */
#define SIM_SCGC4_VREF_SHIFT                     (20U)                                               /*!< SIM_SCGC4.VREF Position                 */
#define SIM_SCGC4_VREF(x)                        (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< SIM_SCGC4.VREF Field                    */
/* ------- SCGC5 Bit Fields                         ------ */
#define SIM_SCGC5_LPTMR0_MASK                    (0x1U)                                              /*!< SIM_SCGC5.LPTMR0 Mask                   */
#define SIM_SCGC5_LPTMR0_SHIFT                   (0U)                                                /*!< SIM_SCGC5.LPTMR0 Position               */
#define SIM_SCGC5_LPTMR0(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SIM_SCGC5.LPTMR0 Field                  */
#define SIM_SCGC5_SECREG_MASK                    (0x8U)                                              /*!< SIM_SCGC5.SECREG Mask                   */
#define SIM_SCGC5_SECREG_SHIFT                   (3U)                                                /*!< SIM_SCGC5.SECREG Position               */
#define SIM_SCGC5_SECREG(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SIM_SCGC5.SECREG Field                  */
#define SIM_SCGC5_LPTMR1_MASK                    (0x10U)                                             /*!< SIM_SCGC5.LPTMR1 Mask                   */
#define SIM_SCGC5_LPTMR1_SHIFT                   (4U)                                                /*!< SIM_SCGC5.LPTMR1 Position               */
#define SIM_SCGC5_LPTMR1(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SIM_SCGC5.LPTMR1 Field                  */
#define SIM_SCGC5_TSI_MASK                       (0x20U)                                             /*!< SIM_SCGC5.TSI Mask                      */
#define SIM_SCGC5_TSI_SHIFT                      (5U)                                                /*!< SIM_SCGC5.TSI Position                  */
#define SIM_SCGC5_TSI(x)                         (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< SIM_SCGC5.TSI Field                     */
#define SIM_SCGC5_PORTA_MASK                     (0x200U)                                            /*!< SIM_SCGC5.PORTA Mask                    */
#define SIM_SCGC5_PORTA_SHIFT                    (9U)                                                /*!< SIM_SCGC5.PORTA Position                */
#define SIM_SCGC5_PORTA(x)                       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< SIM_SCGC5.PORTA Field                   */
#define SIM_SCGC5_PORTB_MASK                     (0x400U)                                            /*!< SIM_SCGC5.PORTB Mask                    */
#define SIM_SCGC5_PORTB_SHIFT                    (10U)                                               /*!< SIM_SCGC5.PORTB Position                */
#define SIM_SCGC5_PORTB(x)                       (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< SIM_SCGC5.PORTB Field                   */
#define SIM_SCGC5_PORTC_MASK                     (0x800U)                                            /*!< SIM_SCGC5.PORTC Mask                    */
#define SIM_SCGC5_PORTC_SHIFT                    (11U)                                               /*!< SIM_SCGC5.PORTC Position                */
#define SIM_SCGC5_PORTC(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< SIM_SCGC5.PORTC Field                   */
#define SIM_SCGC5_PORTD_MASK                     (0x1000U)                                           /*!< SIM_SCGC5.PORTD Mask                    */
#define SIM_SCGC5_PORTD_SHIFT                    (12U)                                               /*!< SIM_SCGC5.PORTD Position                */
#define SIM_SCGC5_PORTD(x)                       (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< SIM_SCGC5.PORTD Field                   */
#define SIM_SCGC5_PORTE_MASK                     (0x2000U)                                           /*!< SIM_SCGC5.PORTE Mask                    */
#define SIM_SCGC5_PORTE_SHIFT                    (13U)                                               /*!< SIM_SCGC5.PORTE Position                */
#define SIM_SCGC5_PORTE(x)                       (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< SIM_SCGC5.PORTE Field                   */
#define SIM_SCGC5_EMVSIM0_MASK                   (0x4000U)                                           /*!< SIM_SCGC5.EMVSIM0 Mask                  */
#define SIM_SCGC5_EMVSIM0_SHIFT                  (14U)                                               /*!< SIM_SCGC5.EMVSIM0 Position              */
#define SIM_SCGC5_EMVSIM0(x)                     (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< SIM_SCGC5.EMVSIM0 Field                 */
#define SIM_SCGC5_EMVSIM1_MASK                   (0x8000U)                                           /*!< SIM_SCGC5.EMVSIM1 Mask                  */
#define SIM_SCGC5_EMVSIM1_SHIFT                  (15U)                                               /*!< SIM_SCGC5.EMVSIM1 Position              */
#define SIM_SCGC5_EMVSIM1(x)                     (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< SIM_SCGC5.EMVSIM1 Field                 */
#define SIM_SCGC5_LTC_MASK                       (0x20000U)                                          /*!< SIM_SCGC5.LTC Mask                      */
#define SIM_SCGC5_LTC_SHIFT                      (17U)                                               /*!< SIM_SCGC5.LTC Position                  */
#define SIM_SCGC5_LTC(x)                         (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< SIM_SCGC5.LTC Field                     */
#define SIM_SCGC5_LPUART0_MASK                   (0x100000U)                                         /*!< SIM_SCGC5.LPUART0 Mask                  */
#define SIM_SCGC5_LPUART0_SHIFT                  (20U)                                               /*!< SIM_SCGC5.LPUART0 Position              */
#define SIM_SCGC5_LPUART0(x)                     (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< SIM_SCGC5.LPUART0 Field                 */
#define SIM_SCGC5_LPUART1_MASK                   (0x200000U)                                         /*!< SIM_SCGC5.LPUART1 Mask                  */
#define SIM_SCGC5_LPUART1_SHIFT                  (21U)                                               /*!< SIM_SCGC5.LPUART1 Position              */
#define SIM_SCGC5_LPUART1(x)                     (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< SIM_SCGC5.LPUART1 Field                 */
#define SIM_SCGC5_LPUART2_MASK                   (0x400000U)                                         /*!< SIM_SCGC5.LPUART2 Mask                  */
#define SIM_SCGC5_LPUART2_SHIFT                  (22U)                                               /*!< SIM_SCGC5.LPUART2 Position              */
#define SIM_SCGC5_LPUART2(x)                     (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< SIM_SCGC5.LPUART2 Field                 */
#define SIM_SCGC5_QSPI0_MASK                     (0x4000000U)                                        /*!< SIM_SCGC5.QSPI0 Mask                    */
#define SIM_SCGC5_QSPI0_SHIFT                    (26U)                                               /*!< SIM_SCGC5.QSPI0 Position                */
#define SIM_SCGC5_QSPI0(x)                       (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< SIM_SCGC5.QSPI0 Field                   */
#define SIM_SCGC5_FLEXIO0_MASK                   (0x80000000U)                                       /*!< SIM_SCGC5.FLEXIO0 Mask                  */
#define SIM_SCGC5_FLEXIO0_SHIFT                  (31U)                                               /*!< SIM_SCGC5.FLEXIO0 Position              */
#define SIM_SCGC5_FLEXIO0(x)                     (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< SIM_SCGC5.FLEXIO0 Field                 */
/* ------- SCGC6 Bit Fields                         ------ */
#define SIM_SCGC6_NVM_MASK                       (0x1U)                                              /*!< SIM_SCGC6.NVM Mask                      */
#define SIM_SCGC6_NVM_SHIFT                      (0U)                                                /*!< SIM_SCGC6.NVM Position                  */
#define SIM_SCGC6_NVM(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SIM_SCGC6.NVM Field                     */
#define SIM_SCGC6_DMACHMUX_MASK                  (0x2U)                                              /*!< SIM_SCGC6.DMACHMUX Mask                 */
#define SIM_SCGC6_DMACHMUX_SHIFT                 (1U)                                                /*!< SIM_SCGC6.DMACHMUX Position             */
#define SIM_SCGC6_DMACHMUX(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SIM_SCGC6.DMACHMUX Field                */
#define SIM_SCGC6_INTMUX0_MASK                   (0x10U)                                             /*!< SIM_SCGC6.INTMUX0 Mask                  */
#define SIM_SCGC6_INTMUX0_SHIFT                  (4U)                                                /*!< SIM_SCGC6.INTMUX0 Position              */
#define SIM_SCGC6_INTMUX0(x)                     (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SIM_SCGC6.INTMUX0 Field                 */
#define SIM_SCGC6_TRNG_MASK                      (0x20U)                                             /*!< SIM_SCGC6.TRNG Mask                     */
#define SIM_SCGC6_TRNG_SHIFT                     (5U)                                                /*!< SIM_SCGC6.TRNG Position                 */
#define SIM_SCGC6_TRNG(x)                        (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< SIM_SCGC6.TRNG Field                    */
#define SIM_SCGC6_SPI0_MASK                      (0x1000U)                                           /*!< SIM_SCGC6.SPI0 Mask                     */
#define SIM_SCGC6_SPI0_SHIFT                     (12U)                                               /*!< SIM_SCGC6.SPI0 Position                 */
#define SIM_SCGC6_SPI0(x)                        (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< SIM_SCGC6.SPI0 Field                    */
#define SIM_SCGC6_SPI1_MASK                      (0x2000U)                                           /*!< SIM_SCGC6.SPI1 Mask                     */
#define SIM_SCGC6_SPI1_SHIFT                     (13U)                                               /*!< SIM_SCGC6.SPI1 Position                 */
#define SIM_SCGC6_SPI1(x)                        (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< SIM_SCGC6.SPI1 Field                    */
#define SIM_SCGC6_CRC_MASK                       (0x40000U)                                          /*!< SIM_SCGC6.CRC Mask                      */
#define SIM_SCGC6_CRC_SHIFT                      (18U)                                               /*!< SIM_SCGC6.CRC Position                  */
#define SIM_SCGC6_CRC(x)                         (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< SIM_SCGC6.CRC Field                     */
#define SIM_SCGC6_PIT0_MASK                      (0x800000U)                                         /*!< SIM_SCGC6.PIT0 Mask                     */
#define SIM_SCGC6_PIT0_SHIFT                     (23U)                                               /*!< SIM_SCGC6.PIT0 Position                 */
#define SIM_SCGC6_PIT0(x)                        (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< SIM_SCGC6.PIT0 Field                    */
#define SIM_SCGC6_TPM0_MASK                      (0x1000000U)                                        /*!< SIM_SCGC6.TPM0 Mask                     */
#define SIM_SCGC6_TPM0_SHIFT                     (24U)                                               /*!< SIM_SCGC6.TPM0 Position                 */
#define SIM_SCGC6_TPM0(x)                        (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< SIM_SCGC6.TPM0 Field                    */
#define SIM_SCGC6_TPM1_MASK                      (0x2000000U)                                        /*!< SIM_SCGC6.TPM1 Mask                     */
#define SIM_SCGC6_TPM1_SHIFT                     (25U)                                               /*!< SIM_SCGC6.TPM1 Position                 */
#define SIM_SCGC6_TPM1(x)                        (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< SIM_SCGC6.TPM1 Field                    */
#define SIM_SCGC6_TPM2_MASK                      (0x4000000U)                                        /*!< SIM_SCGC6.TPM2 Mask                     */
#define SIM_SCGC6_TPM2_SHIFT                     (26U)                                               /*!< SIM_SCGC6.TPM2 Position                 */
#define SIM_SCGC6_TPM2(x)                        (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< SIM_SCGC6.TPM2 Field                    */
#define SIM_SCGC6_ADC0_MASK                      (0x8000000U)                                        /*!< SIM_SCGC6.ADC0 Mask                     */
#define SIM_SCGC6_ADC0_SHIFT                     (27U)                                               /*!< SIM_SCGC6.ADC0 Position                 */
#define SIM_SCGC6_ADC0(x)                        (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< SIM_SCGC6.ADC0 Field                    */
#define SIM_SCGC6_RTC_MASK                       (0x20000000U)                                       /*!< SIM_SCGC6.RTC Mask                      */
#define SIM_SCGC6_RTC_SHIFT                      (29U)                                               /*!< SIM_SCGC6.RTC Position                  */
#define SIM_SCGC6_RTC(x)                         (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< SIM_SCGC6.RTC Field                     */
#define SIM_SCGC6_RTC_RF_MASK                    (0x40000000U)                                       /*!< SIM_SCGC6.RTC_RF Mask                   */
#define SIM_SCGC6_RTC_RF_SHIFT                   (30U)                                               /*!< SIM_SCGC6.RTC_RF Position               */
#define SIM_SCGC6_RTC_RF(x)                      (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< SIM_SCGC6.RTC_RF Field                  */
#define SIM_SCGC6_DAC0_MASK                      (0x80000000U)                                       /*!< SIM_SCGC6.DAC0 Mask                     */
#define SIM_SCGC6_DAC0_SHIFT                     (31U)                                               /*!< SIM_SCGC6.DAC0 Position                 */
#define SIM_SCGC6_DAC0(x)                        (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< SIM_SCGC6.DAC0 Field                    */
/* ------- SCGC7 Bit Fields                         ------ */
#define SIM_SCGC7_DMA_MASK                       (0x2U)                                              /*!< SIM_SCGC7.DMA Mask                      */
#define SIM_SCGC7_DMA_SHIFT                      (1U)                                                /*!< SIM_SCGC7.DMA Position                  */
#define SIM_SCGC7_DMA(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SIM_SCGC7.DMA Field                     */
#define SIM_SCGC7_MPU_MASK                       (0x4U)                                              /*!< SIM_SCGC7.MPU Mask                      */
#define SIM_SCGC7_MPU_SHIFT                      (2U)                                                /*!< SIM_SCGC7.MPU Position                  */
#define SIM_SCGC7_MPU(x)                         (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SIM_SCGC7.MPU Field                     */
/* ------- CLKDIV1 Bit Fields                       ------ */
#define SIM_CLKDIV1_OUTDIV5_MASK                 (0xF000U)                                           /*!< SIM_CLKDIV1.OUTDIV5 Mask                */
#define SIM_CLKDIV1_OUTDIV5_SHIFT                (12U)                                               /*!< SIM_CLKDIV1.OUTDIV5 Position            */
#define SIM_CLKDIV1_OUTDIV5(x)                   (((uint32_t)(((uint32_t)(x))<<12U))&0xF000UL)       /*!< SIM_CLKDIV1.OUTDIV5 Field               */
#define SIM_CLKDIV1_OUTDIV4_MASK                 (0xF0000U)                                          /*!< SIM_CLKDIV1.OUTDIV4 Mask                */
#define SIM_CLKDIV1_OUTDIV4_SHIFT                (16U)                                               /*!< SIM_CLKDIV1.OUTDIV4 Position            */
#define SIM_CLKDIV1_OUTDIV4(x)                   (((uint32_t)(((uint32_t)(x))<<16U))&0xF0000UL)      /*!< SIM_CLKDIV1.OUTDIV4 Field               */
#define SIM_CLKDIV1_OUTDIV2_MASK                 (0xF000000U)                                        /*!< SIM_CLKDIV1.OUTDIV2 Mask                */
#define SIM_CLKDIV1_OUTDIV2_SHIFT                (24U)                                               /*!< SIM_CLKDIV1.OUTDIV2 Position            */
#define SIM_CLKDIV1_OUTDIV2(x)                   (((uint32_t)(((uint32_t)(x))<<24U))&0xF000000UL)    /*!< SIM_CLKDIV1.OUTDIV2 Field               */
#define SIM_CLKDIV1_OUTDIV1_MASK                 (0xF0000000U)                                       /*!< SIM_CLKDIV1.OUTDIV1 Mask                */
#define SIM_CLKDIV1_OUTDIV1_SHIFT                (28U)                                               /*!< SIM_CLKDIV1.OUTDIV1 Position            */
#define SIM_CLKDIV1_OUTDIV1(x)                   (((uint32_t)(((uint32_t)(x))<<28U))&0xF0000000UL)   /*!< SIM_CLKDIV1.OUTDIV1 Field               */
/* ------- CLKDIV2 Bit Fields                       ------ */
#define SIM_CLKDIV2_USBFRAC_MASK                 (0x1U)                                              /*!< SIM_CLKDIV2.USBFRAC Mask                */
#define SIM_CLKDIV2_USBFRAC_SHIFT                (0U)                                                /*!< SIM_CLKDIV2.USBFRAC Position            */
#define SIM_CLKDIV2_USBFRAC(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SIM_CLKDIV2.USBFRAC Field               */
#define SIM_CLKDIV2_USBDIV_MASK                  (0xEU)                                              /*!< SIM_CLKDIV2.USBDIV Mask                 */
#define SIM_CLKDIV2_USBDIV_SHIFT                 (1U)                                                /*!< SIM_CLKDIV2.USBDIV Position             */
#define SIM_CLKDIV2_USBDIV(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0xEUL)           /*!< SIM_CLKDIV2.USBDIV Field                */
/* ------- FCFG1 Bit Fields                         ------ */
#define SIM_FCFG1_FLASHDIS_MASK                  (0x1U)                                              /*!< SIM_FCFG1.FLASHDIS Mask                 */
#define SIM_FCFG1_FLASHDIS_SHIFT                 (0U)                                                /*!< SIM_FCFG1.FLASHDIS Position             */
#define SIM_FCFG1_FLASHDIS(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SIM_FCFG1.FLASHDIS Field                */
#define SIM_FCFG1_FLASHDOZE_MASK                 (0x2U)                                              /*!< SIM_FCFG1.FLASHDOZE Mask                */
#define SIM_FCFG1_FLASHDOZE_SHIFT                (1U)                                                /*!< SIM_FCFG1.FLASHDOZE Position            */
#define SIM_FCFG1_FLASHDOZE(x)                   (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SIM_FCFG1.FLASHDOZE Field               */
#define SIM_FCFG1_PFSIZE_MASK                    (0xF000000U)                                        /*!< SIM_FCFG1.PFSIZE Mask                   */
#define SIM_FCFG1_PFSIZE_SHIFT                   (24U)                                               /*!< SIM_FCFG1.PFSIZE Position               */
#define SIM_FCFG1_PFSIZE(x)                      (((uint32_t)(((uint32_t)(x))<<24U))&0xF000000UL)    /*!< SIM_FCFG1.PFSIZE Field                  */
/* ------- FCFG2 Bit Fields                         ------ */
#define SIM_FCFG2_MAXADDR0_MASK                  (0x7F000000U)                                       /*!< SIM_FCFG2.MAXADDR0 Mask                 */
#define SIM_FCFG2_MAXADDR0_SHIFT                 (24U)                                               /*!< SIM_FCFG2.MAXADDR0 Position             */
#define SIM_FCFG2_MAXADDR0(x)                    (((uint32_t)(((uint32_t)(x))<<24U))&0x7F000000UL)   /*!< SIM_FCFG2.MAXADDR0 Field                */
/* ------- UIDH Bit Fields                          ------ */
#define SIM_UIDH_UID_MASK                        (0xFFFFFFFFU)                                       /*!< SIM_UIDH.UID Mask                       */
#define SIM_UIDH_UID_SHIFT                       (0U)                                                /*!< SIM_UIDH.UID Position                   */
#define SIM_UIDH_UID(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< SIM_UIDH.UID Field                      */
/* ------- UIDMH Bit Fields                         ------ */
#define SIM_UIDMH_UID_MASK                       (0xFFFFFFFFU)                                       /*!< SIM_UIDMH.UID Mask                      */
#define SIM_UIDMH_UID_SHIFT                      (0U)                                                /*!< SIM_UIDMH.UID Position                  */
#define SIM_UIDMH_UID(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< SIM_UIDMH.UID Field                     */
/* ------- UIDML Bit Fields                         ------ */
#define SIM_UIDML_UID_MASK                       (0xFFFFFFFFU)                                       /*!< SIM_UIDML.UID Mask                      */
#define SIM_UIDML_UID_SHIFT                      (0U)                                                /*!< SIM_UIDML.UID Position                  */
#define SIM_UIDML_UID(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< SIM_UIDML.UID Field                     */
/* ------- UIDL Bit Fields                          ------ */
#define SIM_UIDL_UID_MASK                        (0xFFFFFFFFU)                                       /*!< SIM_UIDL.UID Mask                       */
#define SIM_UIDL_UID_SHIFT                       (0U)                                                /*!< SIM_UIDL.UID Position                   */
#define SIM_UIDL_UID(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< SIM_UIDL.UID Field                      */
/* ------- CLKDIV3 Bit Fields                       ------ */
#define SIM_CLKDIV3_PLLFLLFRAC_MASK              (0x1U)                                              /*!< SIM_CLKDIV3.PLLFLLFRAC Mask             */
#define SIM_CLKDIV3_PLLFLLFRAC_SHIFT             (0U)                                                /*!< SIM_CLKDIV3.PLLFLLFRAC Position         */
#define SIM_CLKDIV3_PLLFLLFRAC(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SIM_CLKDIV3.PLLFLLFRAC Field            */
#define SIM_CLKDIV3_PLLFLLDIV_MASK               (0xEU)                                              /*!< SIM_CLKDIV3.PLLFLLDIV Mask              */
#define SIM_CLKDIV3_PLLFLLDIV_SHIFT              (1U)                                                /*!< SIM_CLKDIV3.PLLFLLDIV Position          */
#define SIM_CLKDIV3_PLLFLLDIV(x)                 (((uint32_t)(((uint32_t)(x))<<1U))&0xEUL)           /*!< SIM_CLKDIV3.PLLFLLDIV Field             */
/* ------- MISCCTRL Bit Fields                      ------ */
#define SIM_MISCCTRL_DMAINTSEL0_MASK             (0x1U)                                              /*!< SIM_MISCCTRL.DMAINTSEL0 Mask            */
#define SIM_MISCCTRL_DMAINTSEL0_SHIFT            (0U)                                                /*!< SIM_MISCCTRL.DMAINTSEL0 Position        */
#define SIM_MISCCTRL_DMAINTSEL0(x)               (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SIM_MISCCTRL.DMAINTSEL0 Field           */
#define SIM_MISCCTRL_DMAINTSEL1_MASK             (0x2U)                                              /*!< SIM_MISCCTRL.DMAINTSEL1 Mask            */
#define SIM_MISCCTRL_DMAINTSEL1_SHIFT            (1U)                                                /*!< SIM_MISCCTRL.DMAINTSEL1 Position        */
#define SIM_MISCCTRL_DMAINTSEL1(x)               (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SIM_MISCCTRL.DMAINTSEL1 Field           */
#define SIM_MISCCTRL_DMAINTSEL2_MASK             (0x4U)                                              /*!< SIM_MISCCTRL.DMAINTSEL2 Mask            */
#define SIM_MISCCTRL_DMAINTSEL2_SHIFT            (2U)                                                /*!< SIM_MISCCTRL.DMAINTSEL2 Position        */
#define SIM_MISCCTRL_DMAINTSEL2(x)               (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SIM_MISCCTRL.DMAINTSEL2 Field           */
#define SIM_MISCCTRL_DMAINTSEL3_MASK             (0x8U)                                              /*!< SIM_MISCCTRL.DMAINTSEL3 Mask            */
#define SIM_MISCCTRL_DMAINTSEL3_SHIFT            (3U)                                                /*!< SIM_MISCCTRL.DMAINTSEL3 Position        */
#define SIM_MISCCTRL_DMAINTSEL3(x)               (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SIM_MISCCTRL.DMAINTSEL3 Field           */
#define SIM_MISCCTRL_LTCEN_MASK                  (0x10000U)                                          /*!< SIM_MISCCTRL.LTCEN Mask                 */
#define SIM_MISCCTRL_LTCEN_SHIFT                 (16U)                                               /*!< SIM_MISCCTRL.LTCEN Position             */
#define SIM_MISCCTRL_LTCEN(x)                    (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< SIM_MISCCTRL.LTCEN Field                */
/* ------- SECKEY Bit Fields                        ------ */
#define SIM_SECKEY_SECKEY_MASK                   (0xFFFFFFFFU)                                       /*!< SIM_SECKEY.SECKEY Mask                  */
#define SIM_SECKEY_SECKEY_SHIFT                  (0U)                                                /*!< SIM_SECKEY.SECKEY Position              */
#define SIM_SECKEY_SECKEY(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< SIM_SECKEY.SECKEY Field                 */
/**
 * @} */ /* End group SIM_Register_Masks_GROUP 
 */

/* SIM - Peripheral instance base addresses */
#define SIM_BasePtr                    0x40047000UL //!< Peripheral base address
#define SIM                            ((SIM_Type *) SIM_BasePtr) //!< Freescale base pointer
#define SIM_BASE_PTR                   (SIM) //!< Freescale style base pointer
/**
 * @} */ /* End group SIM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SMC_Peripheral_access_layer_GROUP SMC Peripheral Access Layer
* @brief C Struct for SMC
* @{
*/

/* ================================================================================ */
/* ================           SMC (file:SMC_MKL82Z7)               ================ */
/* ================================================================================ */

/**
 * @brief System Mode Controller
 */
/**
* @addtogroup SMC_structs_GROUP SMC struct
* @brief Struct for SMC
* @{
*/
typedef struct {                                /*       SMC Structure                                                */
   __IO uint8_t   PMPROT;                       /**< 0000: Power Mode Protection register                               */
   __IO uint8_t   PMCTRL;                       /**< 0001: Power Mode Control register                                  */
   __IO uint8_t   STOPCTRL;                     /**< 0002: Stop Control Register                                        */
   __I  uint8_t   PMSTAT;                       /**< 0003: Power Mode Status register                                   */
} SMC_Type;

/**
 * @} */ /* End group SMC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SMC_Register_Masks_GROUP SMC Register Masks
* @brief Register Masks for SMC
* @{
*/
/* ------- PMPROT Bit Fields                        ------ */
#define SMC_PMPROT_AVLLS_MASK                    (0x2U)                                              /*!< SMC_PMPROT.AVLLS Mask                   */
#define SMC_PMPROT_AVLLS_SHIFT                   (1U)                                                /*!< SMC_PMPROT.AVLLS Position               */
#define SMC_PMPROT_AVLLS(x)                      (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< SMC_PMPROT.AVLLS Field                  */
#define SMC_PMPROT_ALLS_MASK                     (0x8U)                                              /*!< SMC_PMPROT.ALLS Mask                    */
#define SMC_PMPROT_ALLS_SHIFT                    (3U)                                                /*!< SMC_PMPROT.ALLS Position                */
#define SMC_PMPROT_ALLS(x)                       (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< SMC_PMPROT.ALLS Field                   */
#define SMC_PMPROT_AVLP_MASK                     (0x20U)                                             /*!< SMC_PMPROT.AVLP Mask                    */
#define SMC_PMPROT_AVLP_SHIFT                    (5U)                                                /*!< SMC_PMPROT.AVLP Position                */
#define SMC_PMPROT_AVLP(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< SMC_PMPROT.AVLP Field                   */
#define SMC_PMPROT_AHSRUN_MASK                   (0x80U)                                             /*!< SMC_PMPROT.AHSRUN Mask                  */
#define SMC_PMPROT_AHSRUN_SHIFT                  (7U)                                                /*!< SMC_PMPROT.AHSRUN Position              */
#define SMC_PMPROT_AHSRUN(x)                     (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< SMC_PMPROT.AHSRUN Field                 */
/* ------- PMCTRL Bit Fields                        ------ */
#define SMC_PMCTRL_STOPM_MASK                    (0x7U)                                              /*!< SMC_PMCTRL.STOPM Mask                   */
#define SMC_PMCTRL_STOPM_SHIFT                   (0U)                                                /*!< SMC_PMCTRL.STOPM Position               */
#define SMC_PMCTRL_STOPM(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< SMC_PMCTRL.STOPM Field                  */
#define SMC_PMCTRL_STOPA_MASK                    (0x8U)                                              /*!< SMC_PMCTRL.STOPA Mask                   */
#define SMC_PMCTRL_STOPA_SHIFT                   (3U)                                                /*!< SMC_PMCTRL.STOPA Position               */
#define SMC_PMCTRL_STOPA(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< SMC_PMCTRL.STOPA Field                  */
#define SMC_PMCTRL_RUNM_MASK                     (0x60U)                                             /*!< SMC_PMCTRL.RUNM Mask                    */
#define SMC_PMCTRL_RUNM_SHIFT                    (5U)                                                /*!< SMC_PMCTRL.RUNM Position                */
#define SMC_PMCTRL_RUNM(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x60UL)            /*!< SMC_PMCTRL.RUNM Field                   */
/* ------- STOPCTRL Bit Fields                      ------ */
#define SMC_STOPCTRL_LLSM_MASK                   (0x7U)                                              /*!< SMC_STOPCTRL.LLSM Mask                  */
#define SMC_STOPCTRL_LLSM_SHIFT                  (0U)                                                /*!< SMC_STOPCTRL.LLSM Position              */
#define SMC_STOPCTRL_LLSM(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< SMC_STOPCTRL.LLSM Field                 */
#define SMC_STOPCTRL_LPOPO_MASK                  (0x8U)                                              /*!< SMC_STOPCTRL.LPOPO Mask                 */
#define SMC_STOPCTRL_LPOPO_SHIFT                 (3U)                                                /*!< SMC_STOPCTRL.LPOPO Position             */
#define SMC_STOPCTRL_LPOPO(x)                    (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< SMC_STOPCTRL.LPOPO Field                */
#define SMC_STOPCTRL_PORPO_MASK                  (0x20U)                                             /*!< SMC_STOPCTRL.PORPO Mask                 */
#define SMC_STOPCTRL_PORPO_SHIFT                 (5U)                                                /*!< SMC_STOPCTRL.PORPO Position             */
#define SMC_STOPCTRL_PORPO(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< SMC_STOPCTRL.PORPO Field                */
#define SMC_STOPCTRL_PSTOPO_MASK                 (0xC0U)                                             /*!< SMC_STOPCTRL.PSTOPO Mask                */
#define SMC_STOPCTRL_PSTOPO_SHIFT                (6U)                                                /*!< SMC_STOPCTRL.PSTOPO Position            */
#define SMC_STOPCTRL_PSTOPO(x)                   (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< SMC_STOPCTRL.PSTOPO Field               */
/* ------- PMSTAT Bit Fields                        ------ */
#define SMC_PMSTAT_PMSTAT_MASK                   (0xFFU)                                             /*!< SMC_PMSTAT.PMSTAT Mask                  */
#define SMC_PMSTAT_PMSTAT_SHIFT                  (0U)                                                /*!< SMC_PMSTAT.PMSTAT Position              */
#define SMC_PMSTAT_PMSTAT(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< SMC_PMSTAT.PMSTAT Field                 */
/**
 * @} */ /* End group SMC_Register_Masks_GROUP 
 */

/* SMC - Peripheral instance base addresses */
#define SMC_BasePtr                    0x4007E000UL //!< Peripheral base address
#define SMC                            ((SMC_Type *) SMC_BasePtr) //!< Freescale base pointer
#define SMC_BASE_PTR                   (SMC) //!< Freescale style base pointer
/**
 * @} */ /* End group SMC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SPI_Peripheral_access_layer_GROUP SPI Peripheral Access Layer
* @brief C Struct for SPI
* @{
*/

/* ================================================================================ */
/* ================           SPI0 (file:SPI0_MKL82Z7)             ================ */
/* ================================================================================ */

/**
 * @brief Serial Peripheral Interface
 */
/**
* @addtogroup SPI_structs_GROUP SPI struct
* @brief Struct for SPI
* @{
*/
typedef struct {                                /*       SPI0 Structure                                               */
   __IO uint32_t  MCR;                          /**< 0000: Module Configuration Register                                */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  TCR;                          /**< 0008: Transfer Count Register                                      */
   union {                                      /**< 0000: (size=0008)                                                  */
      __IO uint32_t  CTAR[2];                   /**< 000C: Clock and Transfer Attributes Register (In Master Mode)      */
      __IO uint32_t  CTAR_SLAVE;                /**< 000C: Clock and Transfer Attributes Register (In Slave Mode)       */
   };
        uint8_t   RESERVED_1[24];              
   __IO uint32_t  SR;                           /**< 002C: Status Register                                              */
   __IO uint32_t  RSER;                         /**< 0030: DMA/Interrupt Request Select and Enable Register             */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  PUSHR;                     /**< 0034: PUSH TX FIFO Register In Master Mode                         */
      __IO uint32_t  PUSHR_SLAVE;               /**< 0034: PUSH TX FIFO Register In Slave Mode                          */
   };
   __I  uint32_t  POPR;                         /**< 0038: POP RX FIFO Register                                         */
   __I  uint32_t  TXFR[4];                      /**< 003C: Transmit FIFO                                                */
        uint8_t   RESERVED_2[48];              
   __I  uint32_t  RXFR[4];                      /**< 007C: Receive FIFO                                                 */
} SPI_Type;

/**
 * @} */ /* End group SPI_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SPI0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SPI_Register_Masks_GROUP SPI Register Masks
* @brief Register Masks for SPI
* @{
*/
/* ------- MCR Bit Fields                           ------ */
#define SPI_MCR_HALT_MASK                        (0x1U)                                              /*!< SPI0_MCR.HALT Mask                      */
#define SPI_MCR_HALT_SHIFT                       (0U)                                                /*!< SPI0_MCR.HALT Position                  */
#define SPI_MCR_HALT(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SPI0_MCR.HALT Field                     */
#define SPI_MCR_SMPL_PT_MASK                     (0x300U)                                            /*!< SPI0_MCR.SMPL_PT Mask                   */
#define SPI_MCR_SMPL_PT_SHIFT                    (8U)                                                /*!< SPI0_MCR.SMPL_PT Position               */
#define SPI_MCR_SMPL_PT(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0x300UL)         /*!< SPI0_MCR.SMPL_PT Field                  */
#define SPI_MCR_CLR_RXF_MASK                     (0x400U)                                            /*!< SPI0_MCR.CLR_RXF Mask                   */
#define SPI_MCR_CLR_RXF_SHIFT                    (10U)                                               /*!< SPI0_MCR.CLR_RXF Position               */
#define SPI_MCR_CLR_RXF(x)                       (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< SPI0_MCR.CLR_RXF Field                  */
#define SPI_MCR_CLR_TXF_MASK                     (0x800U)                                            /*!< SPI0_MCR.CLR_TXF Mask                   */
#define SPI_MCR_CLR_TXF_SHIFT                    (11U)                                               /*!< SPI0_MCR.CLR_TXF Position               */
#define SPI_MCR_CLR_TXF(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< SPI0_MCR.CLR_TXF Field                  */
#define SPI_MCR_DIS_RXF_MASK                     (0x1000U)                                           /*!< SPI0_MCR.DIS_RXF Mask                   */
#define SPI_MCR_DIS_RXF_SHIFT                    (12U)                                               /*!< SPI0_MCR.DIS_RXF Position               */
#define SPI_MCR_DIS_RXF(x)                       (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< SPI0_MCR.DIS_RXF Field                  */
#define SPI_MCR_DIS_TXF_MASK                     (0x2000U)                                           /*!< SPI0_MCR.DIS_TXF Mask                   */
#define SPI_MCR_DIS_TXF_SHIFT                    (13U)                                               /*!< SPI0_MCR.DIS_TXF Position               */
#define SPI_MCR_DIS_TXF(x)                       (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< SPI0_MCR.DIS_TXF Field                  */
#define SPI_MCR_MDIS_MASK                        (0x4000U)                                           /*!< SPI0_MCR.MDIS Mask                      */
#define SPI_MCR_MDIS_SHIFT                       (14U)                                               /*!< SPI0_MCR.MDIS Position                  */
#define SPI_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< SPI0_MCR.MDIS Field                     */
#define SPI_MCR_DOZE_MASK                        (0x8000U)                                           /*!< SPI0_MCR.DOZE Mask                      */
#define SPI_MCR_DOZE_SHIFT                       (15U)                                               /*!< SPI0_MCR.DOZE Position                  */
#define SPI_MCR_DOZE(x)                          (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< SPI0_MCR.DOZE Field                     */
#define SPI_MCR_PCSIS_MASK                       (0x3F0000U)                                         /*!< SPI0_MCR.PCSIS Mask                     */
#define SPI_MCR_PCSIS_SHIFT                      (16U)                                               /*!< SPI0_MCR.PCSIS Position                 */
#define SPI_MCR_PCSIS(x)                         (((uint32_t)(((uint32_t)(x))<<16U))&0x3F0000UL)     /*!< SPI0_MCR.PCSIS Field                    */
#define SPI_MCR_ROOE_MASK                        (0x1000000U)                                        /*!< SPI0_MCR.ROOE Mask                      */
#define SPI_MCR_ROOE_SHIFT                       (24U)                                               /*!< SPI0_MCR.ROOE Position                  */
#define SPI_MCR_ROOE(x)                          (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< SPI0_MCR.ROOE Field                     */
#define SPI_MCR_PCSSE_MASK                       (0x2000000U)                                        /*!< SPI0_MCR.PCSSE Mask                     */
#define SPI_MCR_PCSSE_SHIFT                      (25U)                                               /*!< SPI0_MCR.PCSSE Position                 */
#define SPI_MCR_PCSSE(x)                         (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< SPI0_MCR.PCSSE Field                    */
#define SPI_MCR_MTFE_MASK                        (0x4000000U)                                        /*!< SPI0_MCR.MTFE Mask                      */
#define SPI_MCR_MTFE_SHIFT                       (26U)                                               /*!< SPI0_MCR.MTFE Position                  */
#define SPI_MCR_MTFE(x)                          (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< SPI0_MCR.MTFE Field                     */
#define SPI_MCR_FRZ_MASK                         (0x8000000U)                                        /*!< SPI0_MCR.FRZ Mask                       */
#define SPI_MCR_FRZ_SHIFT                        (27U)                                               /*!< SPI0_MCR.FRZ Position                   */
#define SPI_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< SPI0_MCR.FRZ Field                      */
#define SPI_MCR_DCONF_MASK                       (0x30000000U)                                       /*!< SPI0_MCR.DCONF Mask                     */
#define SPI_MCR_DCONF_SHIFT                      (28U)                                               /*!< SPI0_MCR.DCONF Position                 */
#define SPI_MCR_DCONF(x)                         (((uint32_t)(((uint32_t)(x))<<28U))&0x30000000UL)   /*!< SPI0_MCR.DCONF Field                    */
#define SPI_MCR_CONT_SCKE_MASK                   (0x40000000U)                                       /*!< SPI0_MCR.CONT_SCKE Mask                 */
#define SPI_MCR_CONT_SCKE_SHIFT                  (30U)                                               /*!< SPI0_MCR.CONT_SCKE Position             */
#define SPI_MCR_CONT_SCKE(x)                     (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< SPI0_MCR.CONT_SCKE Field                */
#define SPI_MCR_MSTR_MASK                        (0x80000000U)                                       /*!< SPI0_MCR.MSTR Mask                      */
#define SPI_MCR_MSTR_SHIFT                       (31U)                                               /*!< SPI0_MCR.MSTR Position                  */
#define SPI_MCR_MSTR(x)                          (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< SPI0_MCR.MSTR Field                     */
/* ------- TCR Bit Fields                           ------ */
#define SPI_TCR_SPI_TCNT_MASK                    (0xFFFF0000U)                                       /*!< SPI0_TCR.SPI_TCNT Mask                  */
#define SPI_TCR_SPI_TCNT_SHIFT                   (16U)                                               /*!< SPI0_TCR.SPI_TCNT Position              */
#define SPI_TCR_SPI_TCNT(x)                      (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< SPI0_TCR.SPI_TCNT Field                 */
/* ------- CTAR Bit Fields                          ------ */
#define SPI_CTAR_BR_MASK                         (0xFU)                                              /*!< SPI0_CTAR.BR Mask                       */
#define SPI_CTAR_BR_SHIFT                        (0U)                                                /*!< SPI0_CTAR.BR Position                   */
#define SPI_CTAR_BR(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< SPI0_CTAR.BR Field                      */
#define SPI_CTAR_DT_MASK                         (0xF0U)                                             /*!< SPI0_CTAR.DT Mask                       */
#define SPI_CTAR_DT_SHIFT                        (4U)                                                /*!< SPI0_CTAR.DT Position                   */
#define SPI_CTAR_DT(x)                           (((uint32_t)(((uint32_t)(x))<<4U))&0xF0UL)          /*!< SPI0_CTAR.DT Field                      */
#define SPI_CTAR_ASC_MASK                        (0xF00U)                                            /*!< SPI0_CTAR.ASC Mask                      */
#define SPI_CTAR_ASC_SHIFT                       (8U)                                                /*!< SPI0_CTAR.ASC Position                  */
#define SPI_CTAR_ASC(x)                          (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< SPI0_CTAR.ASC Field                     */
#define SPI_CTAR_CSSCK_MASK                      (0xF000U)                                           /*!< SPI0_CTAR.CSSCK Mask                    */
#define SPI_CTAR_CSSCK_SHIFT                     (12U)                                               /*!< SPI0_CTAR.CSSCK Position                */
#define SPI_CTAR_CSSCK(x)                        (((uint32_t)(((uint32_t)(x))<<12U))&0xF000UL)       /*!< SPI0_CTAR.CSSCK Field                   */
#define SPI_CTAR_PBR_MASK                        (0x30000U)                                          /*!< SPI0_CTAR.PBR Mask                      */
#define SPI_CTAR_PBR_SHIFT                       (16U)                                               /*!< SPI0_CTAR.PBR Position                  */
#define SPI_CTAR_PBR(x)                          (((uint32_t)(((uint32_t)(x))<<16U))&0x30000UL)      /*!< SPI0_CTAR.PBR Field                     */
#define SPI_CTAR_PDT_MASK                        (0xC0000U)                                          /*!< SPI0_CTAR.PDT Mask                      */
#define SPI_CTAR_PDT_SHIFT                       (18U)                                               /*!< SPI0_CTAR.PDT Position                  */
#define SPI_CTAR_PDT(x)                          (((uint32_t)(((uint32_t)(x))<<18U))&0xC0000UL)      /*!< SPI0_CTAR.PDT Field                     */
#define SPI_CTAR_PASC_MASK                       (0x300000U)                                         /*!< SPI0_CTAR.PASC Mask                     */
#define SPI_CTAR_PASC_SHIFT                      (20U)                                               /*!< SPI0_CTAR.PASC Position                 */
#define SPI_CTAR_PASC(x)                         (((uint32_t)(((uint32_t)(x))<<20U))&0x300000UL)     /*!< SPI0_CTAR.PASC Field                    */
#define SPI_CTAR_PCSSCK_MASK                     (0xC00000U)                                         /*!< SPI0_CTAR.PCSSCK Mask                   */
#define SPI_CTAR_PCSSCK_SHIFT                    (22U)                                               /*!< SPI0_CTAR.PCSSCK Position               */
#define SPI_CTAR_PCSSCK(x)                       (((uint32_t)(((uint32_t)(x))<<22U))&0xC00000UL)     /*!< SPI0_CTAR.PCSSCK Field                  */
#define SPI_CTAR_LSBFE_MASK                      (0x1000000U)                                        /*!< SPI0_CTAR.LSBFE Mask                    */
#define SPI_CTAR_LSBFE_SHIFT                     (24U)                                               /*!< SPI0_CTAR.LSBFE Position                */
#define SPI_CTAR_LSBFE(x)                        (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< SPI0_CTAR.LSBFE Field                   */
#define SPI_CTAR_CPHA_MASK                       (0x2000000U)                                        /*!< SPI0_CTAR.CPHA Mask                     */
#define SPI_CTAR_CPHA_SHIFT                      (25U)                                               /*!< SPI0_CTAR.CPHA Position                 */
#define SPI_CTAR_CPHA(x)                         (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< SPI0_CTAR.CPHA Field                    */
#define SPI_CTAR_CPOL_MASK                       (0x4000000U)                                        /*!< SPI0_CTAR.CPOL Mask                     */
#define SPI_CTAR_CPOL_SHIFT                      (26U)                                               /*!< SPI0_CTAR.CPOL Position                 */
#define SPI_CTAR_CPOL(x)                         (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< SPI0_CTAR.CPOL Field                    */
#define SPI_CTAR_FMSZ_MASK                       (0x78000000U)                                       /*!< SPI0_CTAR.FMSZ Mask                     */
#define SPI_CTAR_FMSZ_SHIFT                      (27U)                                               /*!< SPI0_CTAR.FMSZ Position                 */
#define SPI_CTAR_FMSZ(x)                         (((uint32_t)(((uint32_t)(x))<<27U))&0x78000000UL)   /*!< SPI0_CTAR.FMSZ Field                    */
#define SPI_CTAR_DBR_MASK                        (0x80000000U)                                       /*!< SPI0_CTAR.DBR Mask                      */
#define SPI_CTAR_DBR_SHIFT                       (31U)                                               /*!< SPI0_CTAR.DBR Position                  */
#define SPI_CTAR_DBR(x)                          (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< SPI0_CTAR.DBR Field                     */
/* ------- CTAR_SLAVE Bit Fields                    ------ */
#define SPI_CTAR_SLAVE_CPHA_MASK                 (0x2000000U)                                        /*!< SPI0_CTAR_SLAVE.CPHA Mask               */
#define SPI_CTAR_SLAVE_CPHA_SHIFT                (25U)                                               /*!< SPI0_CTAR_SLAVE.CPHA Position           */
#define SPI_CTAR_SLAVE_CPHA(x)                   (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< SPI0_CTAR_SLAVE.CPHA Field              */
#define SPI_CTAR_SLAVE_CPOL_MASK                 (0x4000000U)                                        /*!< SPI0_CTAR_SLAVE.CPOL Mask               */
#define SPI_CTAR_SLAVE_CPOL_SHIFT                (26U)                                               /*!< SPI0_CTAR_SLAVE.CPOL Position           */
#define SPI_CTAR_SLAVE_CPOL(x)                   (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< SPI0_CTAR_SLAVE.CPOL Field              */
#define SPI_CTAR_SLAVE_FMSZ_MASK                 (0x78000000U)                                       /*!< SPI0_CTAR_SLAVE.FMSZ Mask               */
#define SPI_CTAR_SLAVE_FMSZ_SHIFT                (27U)                                               /*!< SPI0_CTAR_SLAVE.FMSZ Position           */
#define SPI_CTAR_SLAVE_FMSZ(x)                   (((uint32_t)(((uint32_t)(x))<<27U))&0x78000000UL)   /*!< SPI0_CTAR_SLAVE.FMSZ Field              */
/* ------- SR Bit Fields                            ------ */
#define SPI_SR_POPNXTPTR_MASK                    (0xFU)                                              /*!< SPI0_SR.POPNXTPTR Mask                  */
#define SPI_SR_POPNXTPTR_SHIFT                   (0U)                                                /*!< SPI0_SR.POPNXTPTR Position              */
#define SPI_SR_POPNXTPTR(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< SPI0_SR.POPNXTPTR Field                 */
#define SPI_SR_RXCTR_MASK                        (0xF0U)                                             /*!< SPI0_SR.RXCTR Mask                      */
#define SPI_SR_RXCTR_SHIFT                       (4U)                                                /*!< SPI0_SR.RXCTR Position                  */
#define SPI_SR_RXCTR(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0xF0UL)          /*!< SPI0_SR.RXCTR Field                     */
#define SPI_SR_TXNXTPTR_MASK                     (0xF00U)                                            /*!< SPI0_SR.TXNXTPTR Mask                   */
#define SPI_SR_TXNXTPTR_SHIFT                    (8U)                                                /*!< SPI0_SR.TXNXTPTR Position               */
#define SPI_SR_TXNXTPTR(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< SPI0_SR.TXNXTPTR Field                  */
#define SPI_SR_TXCTR_MASK                        (0xF000U)                                           /*!< SPI0_SR.TXCTR Mask                      */
#define SPI_SR_TXCTR_SHIFT                       (12U)                                               /*!< SPI0_SR.TXCTR Position                  */
#define SPI_SR_TXCTR(x)                          (((uint32_t)(((uint32_t)(x))<<12U))&0xF000UL)       /*!< SPI0_SR.TXCTR Field                     */
#define SPI_SR_RFDF_MASK                         (0x20000U)                                          /*!< SPI0_SR.RFDF Mask                       */
#define SPI_SR_RFDF_SHIFT                        (17U)                                               /*!< SPI0_SR.RFDF Position                   */
#define SPI_SR_RFDF(x)                           (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< SPI0_SR.RFDF Field                      */
#define SPI_SR_RFOF_MASK                         (0x80000U)                                          /*!< SPI0_SR.RFOF Mask                       */
#define SPI_SR_RFOF_SHIFT                        (19U)                                               /*!< SPI0_SR.RFOF Position                   */
#define SPI_SR_RFOF(x)                           (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< SPI0_SR.RFOF Field                      */
#define SPI_SR_TFFF_MASK                         (0x2000000U)                                        /*!< SPI0_SR.TFFF Mask                       */
#define SPI_SR_TFFF_SHIFT                        (25U)                                               /*!< SPI0_SR.TFFF Position                   */
#define SPI_SR_TFFF(x)                           (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< SPI0_SR.TFFF Field                      */
#define SPI_SR_TFUF_MASK                         (0x8000000U)                                        /*!< SPI0_SR.TFUF Mask                       */
#define SPI_SR_TFUF_SHIFT                        (27U)                                               /*!< SPI0_SR.TFUF Position                   */
#define SPI_SR_TFUF(x)                           (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< SPI0_SR.TFUF Field                      */
#define SPI_SR_EOQF_MASK                         (0x10000000U)                                       /*!< SPI0_SR.EOQF Mask                       */
#define SPI_SR_EOQF_SHIFT                        (28U)                                               /*!< SPI0_SR.EOQF Position                   */
#define SPI_SR_EOQF(x)                           (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< SPI0_SR.EOQF Field                      */
#define SPI_SR_TXRXS_MASK                        (0x40000000U)                                       /*!< SPI0_SR.TXRXS Mask                      */
#define SPI_SR_TXRXS_SHIFT                       (30U)                                               /*!< SPI0_SR.TXRXS Position                  */
#define SPI_SR_TXRXS(x)                          (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< SPI0_SR.TXRXS Field                     */
#define SPI_SR_TCF_MASK                          (0x80000000U)                                       /*!< SPI0_SR.TCF Mask                        */
#define SPI_SR_TCF_SHIFT                         (31U)                                               /*!< SPI0_SR.TCF Position                    */
#define SPI_SR_TCF(x)                            (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< SPI0_SR.TCF Field                       */
/* ------- RSER Bit Fields                          ------ */
#define SPI_RSER_RFDF_DIRS_MASK                  (0x10000U)                                          /*!< SPI0_RSER.RFDF_DIRS Mask                */
#define SPI_RSER_RFDF_DIRS_SHIFT                 (16U)                                               /*!< SPI0_RSER.RFDF_DIRS Position            */
#define SPI_RSER_RFDF_DIRS(x)                    (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< SPI0_RSER.RFDF_DIRS Field               */
#define SPI_RSER_RFDF_RE_MASK                    (0x20000U)                                          /*!< SPI0_RSER.RFDF_RE Mask                  */
#define SPI_RSER_RFDF_RE_SHIFT                   (17U)                                               /*!< SPI0_RSER.RFDF_RE Position              */
#define SPI_RSER_RFDF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< SPI0_RSER.RFDF_RE Field                 */
#define SPI_RSER_RFOF_RE_MASK                    (0x80000U)                                          /*!< SPI0_RSER.RFOF_RE Mask                  */
#define SPI_RSER_RFOF_RE_SHIFT                   (19U)                                               /*!< SPI0_RSER.RFOF_RE Position              */
#define SPI_RSER_RFOF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< SPI0_RSER.RFOF_RE Field                 */
#define SPI_RSER_TFFF_DIRS_MASK                  (0x1000000U)                                        /*!< SPI0_RSER.TFFF_DIRS Mask                */
#define SPI_RSER_TFFF_DIRS_SHIFT                 (24U)                                               /*!< SPI0_RSER.TFFF_DIRS Position            */
#define SPI_RSER_TFFF_DIRS(x)                    (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< SPI0_RSER.TFFF_DIRS Field               */
#define SPI_RSER_TFFF_RE_MASK                    (0x2000000U)                                        /*!< SPI0_RSER.TFFF_RE Mask                  */
#define SPI_RSER_TFFF_RE_SHIFT                   (25U)                                               /*!< SPI0_RSER.TFFF_RE Position              */
#define SPI_RSER_TFFF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< SPI0_RSER.TFFF_RE Field                 */
#define SPI_RSER_TFUF_RE_MASK                    (0x8000000U)                                        /*!< SPI0_RSER.TFUF_RE Mask                  */
#define SPI_RSER_TFUF_RE_SHIFT                   (27U)                                               /*!< SPI0_RSER.TFUF_RE Position              */
#define SPI_RSER_TFUF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< SPI0_RSER.TFUF_RE Field                 */
#define SPI_RSER_EOQF_RE_MASK                    (0x10000000U)                                       /*!< SPI0_RSER.EOQF_RE Mask                  */
#define SPI_RSER_EOQF_RE_SHIFT                   (28U)                                               /*!< SPI0_RSER.EOQF_RE Position              */
#define SPI_RSER_EOQF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< SPI0_RSER.EOQF_RE Field                 */
#define SPI_RSER_TCF_RE_MASK                     (0x80000000U)                                       /*!< SPI0_RSER.TCF_RE Mask                   */
#define SPI_RSER_TCF_RE_SHIFT                    (31U)                                               /*!< SPI0_RSER.TCF_RE Position               */
#define SPI_RSER_TCF_RE(x)                       (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< SPI0_RSER.TCF_RE Field                  */
/* ------- PUSHR Bit Fields                         ------ */
#define SPI_PUSHR_TXDATA_MASK                    (0xFFFFU)                                           /*!< SPI0_PUSHR.TXDATA Mask                  */
#define SPI_PUSHR_TXDATA_SHIFT                   (0U)                                                /*!< SPI0_PUSHR.TXDATA Position              */
#define SPI_PUSHR_TXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< SPI0_PUSHR.TXDATA Field                 */
#define SPI_PUSHR_PCS_MASK                       (0x3F0000U)                                         /*!< SPI0_PUSHR.PCS Mask                     */
#define SPI_PUSHR_PCS_SHIFT                      (16U)                                               /*!< SPI0_PUSHR.PCS Position                 */
#define SPI_PUSHR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<16U))&0x3F0000UL)     /*!< SPI0_PUSHR.PCS Field                    */
#define SPI_PUSHR_CTCNT_MASK                     (0x4000000U)                                        /*!< SPI0_PUSHR.CTCNT Mask                   */
#define SPI_PUSHR_CTCNT_SHIFT                    (26U)                                               /*!< SPI0_PUSHR.CTCNT Position               */
#define SPI_PUSHR_CTCNT(x)                       (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< SPI0_PUSHR.CTCNT Field                  */
#define SPI_PUSHR_EOQ_MASK                       (0x8000000U)                                        /*!< SPI0_PUSHR.EOQ Mask                     */
#define SPI_PUSHR_EOQ_SHIFT                      (27U)                                               /*!< SPI0_PUSHR.EOQ Position                 */
#define SPI_PUSHR_EOQ(x)                         (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< SPI0_PUSHR.EOQ Field                    */
#define SPI_PUSHR_CTAS_MASK                      (0x70000000U)                                       /*!< SPI0_PUSHR.CTAS Mask                    */
#define SPI_PUSHR_CTAS_SHIFT                     (28U)                                               /*!< SPI0_PUSHR.CTAS Position                */
#define SPI_PUSHR_CTAS(x)                        (((uint32_t)(((uint32_t)(x))<<28U))&0x70000000UL)   /*!< SPI0_PUSHR.CTAS Field                   */
#define SPI_PUSHR_CONT_MASK                      (0x80000000U)                                       /*!< SPI0_PUSHR.CONT Mask                    */
#define SPI_PUSHR_CONT_SHIFT                     (31U)                                               /*!< SPI0_PUSHR.CONT Position                */
#define SPI_PUSHR_CONT(x)                        (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< SPI0_PUSHR.CONT Field                   */
/* ------- PUSHR_SLAVE Bit Fields                   ------ */
#define SPI_PUSHR_SLAVE_TXDATA_MASK              (0xFFFFU)                                           /*!< SPI0_PUSHR_SLAVE.TXDATA Mask            */
#define SPI_PUSHR_SLAVE_TXDATA_SHIFT             (0U)                                                /*!< SPI0_PUSHR_SLAVE.TXDATA Position        */
#define SPI_PUSHR_SLAVE_TXDATA(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< SPI0_PUSHR_SLAVE.TXDATA Field           */
/* ------- POPR Bit Fields                          ------ */
#define SPI_POPR_RXDATA_MASK                     (0xFFFFFFFFU)                                       /*!< SPI0_POPR.RXDATA Mask                   */
#define SPI_POPR_RXDATA_SHIFT                    (0U)                                                /*!< SPI0_POPR.RXDATA Position               */
#define SPI_POPR_RXDATA(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< SPI0_POPR.RXDATA Field                  */
/* ------- TXFR Bit Fields                          ------ */
#define SPI_TXFR_TXDATA_MASK                     (0xFFFFU)                                           /*!< SPI0_TXFR.TXDATA Mask                   */
#define SPI_TXFR_TXDATA_SHIFT                    (0U)                                                /*!< SPI0_TXFR.TXDATA Position               */
#define SPI_TXFR_TXDATA(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< SPI0_TXFR.TXDATA Field                  */
#define SPI_TXFR_TXCMD_TXDATA_MASK               (0xFFFF0000U)                                       /*!< SPI0_TXFR.TXCMD_TXDATA Mask             */
#define SPI_TXFR_TXCMD_TXDATA_SHIFT              (16U)                                               /*!< SPI0_TXFR.TXCMD_TXDATA Position         */
#define SPI_TXFR_TXCMD_TXDATA(x)                 (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< SPI0_TXFR.TXCMD_TXDATA Field            */
/* ------- RXFR Bit Fields                          ------ */
#define SPI_RXFR_RXDATA_MASK                     (0xFFFFFFFFU)                                       /*!< SPI0_RXFR.RXDATA Mask                   */
#define SPI_RXFR_RXDATA_SHIFT                    (0U)                                                /*!< SPI0_RXFR.RXDATA Position               */
#define SPI_RXFR_RXDATA(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< SPI0_RXFR.RXDATA Field                  */
/**
 * @} */ /* End group SPI_Register_Masks_GROUP 
 */

/* SPI0 - Peripheral instance base addresses */
#define SPI0_BasePtr                   0x4002C000UL //!< Peripheral base address
#define SPI0                           ((SPI_Type *) SPI0_BasePtr) //!< Freescale base pointer
#define SPI0_BASE_PTR                  (SPI0) //!< Freescale style base pointer
/**
 * @} */ /* End group SPI_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SPI_Peripheral_access_layer_GROUP SPI Peripheral Access Layer
* @brief C Struct for SPI
* @{
*/

/* ================================================================================ */
/* ================           SPI1 (derived from SPI0)             ================ */
/* ================================================================================ */

/**
 * @brief Serial Peripheral Interface
 */

/* SPI1 - Peripheral instance base addresses */
#define SPI1_BasePtr                   0x4002D000UL //!< Peripheral base address
#define SPI1                           ((SPI_Type *) SPI1_BasePtr) //!< Freescale base pointer
#define SPI1_BASE_PTR                  (SPI1) //!< Freescale style base pointer
/**
 * @} */ /* End group SPI_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SYST_Peripheral_access_layer_GROUP SYST Peripheral Access Layer
* @brief C Struct for SYST
* @{
*/

/* ================================================================================ */
/* ================           SYST (file:SYST)                     ================ */
/* ================================================================================ */

/**
 * @brief System timer
 */
/**
* @addtogroup SYST_structs_GROUP SYST struct
* @brief Struct for SYST
* @{
*/
typedef struct {                                /*       SYST Structure                                               */
   __IO uint32_t  CSR;                          /**< 0000: Control and Status Register                                  */
   __IO uint32_t  RVR;                          /**< 0004: Reload Value Register                                        */
   __IO uint32_t  CVR;                          /**< 0008: Current Value Register                                       */
   __I  uint32_t  CALIB;                        /**< 000C: Calibration Value Register                                   */
} SYST_Type;

/**
 * @} */ /* End group SYST_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SYST' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SYST_Register_Masks_GROUP SYST Register Masks
* @brief Register Masks for SYST
* @{
*/
/* ------- CSR Bit Fields                           ------ */
#define SYST_CSR_ENABLE_MASK                     (0x1U)                                              /*!< SYST_CSR.ENABLE Mask                    */
#define SYST_CSR_ENABLE_SHIFT                    (0U)                                                /*!< SYST_CSR.ENABLE Position                */
#define SYST_CSR_ENABLE(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SYST_CSR.ENABLE Field                   */
#define SYST_CSR_TICKINT_MASK                    (0x2U)                                              /*!< SYST_CSR.TICKINT Mask                   */
#define SYST_CSR_TICKINT_SHIFT                   (1U)                                                /*!< SYST_CSR.TICKINT Position               */
#define SYST_CSR_TICKINT(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SYST_CSR.TICKINT Field                  */
#define SYST_CSR_CLKSOURCE_MASK                  (0x4U)                                              /*!< SYST_CSR.CLKSOURCE Mask                 */
#define SYST_CSR_CLKSOURCE_SHIFT                 (2U)                                                /*!< SYST_CSR.CLKSOURCE Position             */
#define SYST_CSR_CLKSOURCE(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SYST_CSR.CLKSOURCE Field                */
#define SYST_CSR_COUNTFLAG_MASK                  (0x10000U)                                          /*!< SYST_CSR.COUNTFLAG Mask                 */
#define SYST_CSR_COUNTFLAG_SHIFT                 (16U)                                               /*!< SYST_CSR.COUNTFLAG Position             */
#define SYST_CSR_COUNTFLAG(x)                    (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< SYST_CSR.COUNTFLAG Field                */
/* ------- RVR Bit Fields                           ------ */
#define SYST_RVR_RELOAD_MASK                     (0xFFFFFFU)                                         /*!< SYST_RVR.RELOAD Mask                    */
#define SYST_RVR_RELOAD_SHIFT                    (0U)                                                /*!< SYST_RVR.RELOAD Position                */
#define SYST_RVR_RELOAD(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFUL)      /*!< SYST_RVR.RELOAD Field                   */
/* ------- CVR Bit Fields                           ------ */
#define SYST_CVR_CURRENT_MASK                    (0xFFFFFFU)                                         /*!< SYST_CVR.CURRENT Mask                   */
#define SYST_CVR_CURRENT_SHIFT                   (0U)                                                /*!< SYST_CVR.CURRENT Position               */
#define SYST_CVR_CURRENT(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFUL)      /*!< SYST_CVR.CURRENT Field                  */
/* ------- CALIB Bit Fields                         ------ */
#define SYST_CALIB_TENMS_MASK                    (0xFFFFFFU)                                         /*!< SYST_CALIB.TENMS Mask                   */
#define SYST_CALIB_TENMS_SHIFT                   (0U)                                                /*!< SYST_CALIB.TENMS Position               */
#define SYST_CALIB_TENMS(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFUL)      /*!< SYST_CALIB.TENMS Field                  */
#define SYST_CALIB_SKEW_MASK                     (0x40000000U)                                       /*!< SYST_CALIB.SKEW Mask                    */
#define SYST_CALIB_SKEW_SHIFT                    (30U)                                               /*!< SYST_CALIB.SKEW Position                */
#define SYST_CALIB_SKEW(x)                       (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< SYST_CALIB.SKEW Field                   */
#define SYST_CALIB_NOREF_MASK                    (0x80000000U)                                       /*!< SYST_CALIB.NOREF Mask                   */
#define SYST_CALIB_NOREF_SHIFT                   (31U)                                               /*!< SYST_CALIB.NOREF Position               */
#define SYST_CALIB_NOREF(x)                      (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< SYST_CALIB.NOREF Field                  */
/**
 * @} */ /* End group SYST_Register_Masks_GROUP 
 */

/* SYST - Peripheral instance base addresses */
#define SYST_BasePtr                   0xE000E010UL //!< Peripheral base address
#define SYST                           ((SYST_Type *) SYST_BasePtr) //!< Freescale base pointer
#define SYST_BASE_PTR                  (SYST) //!< Freescale style base pointer
/**
 * @} */ /* End group SYST_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup TPM_Peripheral_access_layer_GROUP TPM Peripheral Access Layer
* @brief C Struct for TPM
* @{
*/

/* ================================================================================ */
/* ================           TPM0 (file:TPM0_MKL82Z7)             ================ */
/* ================================================================================ */

/**
 * @brief Timer/PWM Module
 */
/**
* @addtogroup TPM_structs_GROUP TPM struct
* @brief Struct for TPM
* @{
*/
typedef struct {                                /*       TPM0 Structure                                               */
   __IO uint32_t  SC;                           /**< 0000: Status and Control                                           */
   __IO uint32_t  CNT;                          /**< 0004: Counter                                                      */
   __IO uint32_t  MOD;                          /**< 0008: Modulo                                                       */
   struct {
      __IO uint32_t  CnSC;                      /**< 000C: Channel (n) Status and Control                               */
      __IO uint32_t  CnV;                       /**< 0010: Channel (n) Value                                            */
   } CONTROLS[6];                               /**< 000C: (cluster: size=0x0030, 48)                                   */
        uint8_t   RESERVED_1[20];              
   __IO uint32_t  STATUS;                       /**< 0050: Capture and Compare Status                                   */
        uint8_t   RESERVED_2[16];              
   __IO uint32_t  COMBINE;                      /**< 0064: Combine Channel Register                                     */
        uint8_t   RESERVED_3[8];               
   __IO uint32_t  POL;                          /**< 0070: Channel Polarity                                             */
        uint8_t   RESERVED_4[4];               
   __IO uint32_t  FILTER;                       /**< 0078: Filter Control                                               */
        uint8_t   RESERVED_5[8];               
   __IO uint32_t  CONF;                         /**< 0084: Configuration                                                */
} TPM0_Type;

/**
 * @} */ /* End group TPM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'TPM0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup TPM_Register_Masks_GROUP TPM Register Masks
* @brief Register Masks for TPM
* @{
*/
/* ------- SC Bit Fields                            ------ */
#define TPM_SC_PS_MASK                           (0x7U)                                              /*!< TPM0_SC.PS Mask                         */
#define TPM_SC_PS_SHIFT                          (0U)                                                /*!< TPM0_SC.PS Position                     */
#define TPM_SC_PS(x)                             (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< TPM0_SC.PS Field                        */
#define TPM_SC_CMOD_MASK                         (0x18U)                                             /*!< TPM0_SC.CMOD Mask                       */
#define TPM_SC_CMOD_SHIFT                        (3U)                                                /*!< TPM0_SC.CMOD Position                   */
#define TPM_SC_CMOD(x)                           (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< TPM0_SC.CMOD Field                      */
#define TPM_SC_CPWMS_MASK                        (0x20U)                                             /*!< TPM0_SC.CPWMS Mask                      */
#define TPM_SC_CPWMS_SHIFT                       (5U)                                                /*!< TPM0_SC.CPWMS Position                  */
#define TPM_SC_CPWMS(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< TPM0_SC.CPWMS Field                     */
#define TPM_SC_TOIE_MASK                         (0x40U)                                             /*!< TPM0_SC.TOIE Mask                       */
#define TPM_SC_TOIE_SHIFT                        (6U)                                                /*!< TPM0_SC.TOIE Position                   */
#define TPM_SC_TOIE(x)                           (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< TPM0_SC.TOIE Field                      */
#define TPM_SC_TOF_MASK                          (0x80U)                                             /*!< TPM0_SC.TOF Mask                        */
#define TPM_SC_TOF_SHIFT                         (7U)                                                /*!< TPM0_SC.TOF Position                    */
#define TPM_SC_TOF(x)                            (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< TPM0_SC.TOF Field                       */
#define TPM_SC_DMA_MASK                          (0x100U)                                            /*!< TPM0_SC.DMA Mask                        */
#define TPM_SC_DMA_SHIFT                         (8U)                                                /*!< TPM0_SC.DMA Position                    */
#define TPM_SC_DMA(x)                            (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< TPM0_SC.DMA Field                       */
/* ------- CNT Bit Fields                           ------ */
#define TPM_CNT_COUNT_MASK                       (0xFFFFU)                                           /*!< TPM0_CNT.COUNT Mask                     */
#define TPM_CNT_COUNT_SHIFT                      (0U)                                                /*!< TPM0_CNT.COUNT Position                 */
#define TPM_CNT_COUNT(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< TPM0_CNT.COUNT Field                    */
/* ------- MOD Bit Fields                           ------ */
#define TPM_MOD_MOD_MASK                         (0xFFFFU)                                           /*!< TPM0_MOD.MOD Mask                       */
#define TPM_MOD_MOD_SHIFT                        (0U)                                                /*!< TPM0_MOD.MOD Position                   */
#define TPM_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< TPM0_MOD.MOD Field                      */
/* ------- CnSC Bit Fields                          ------ */
#define TPM_CnSC_DMA_MASK                        (0x1U)                                              /*!< TPM0_CnSC.DMA Mask                      */
#define TPM_CnSC_DMA_SHIFT                       (0U)                                                /*!< TPM0_CnSC.DMA Position                  */
#define TPM_CnSC_DMA(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< TPM0_CnSC.DMA Field                     */
#define TPM_CnSC_ELSA_MASK                       (0x4U)                                              /*!< TPM0_CnSC.ELSA Mask                     */
#define TPM_CnSC_ELSA_SHIFT                      (2U)                                                /*!< TPM0_CnSC.ELSA Position                 */
#define TPM_CnSC_ELSA(x)                         (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< TPM0_CnSC.ELSA Field                    */
#define TPM_CnSC_ELSB_MASK                       (0x8U)                                              /*!< TPM0_CnSC.ELSB Mask                     */
#define TPM_CnSC_ELSB_SHIFT                      (3U)                                                /*!< TPM0_CnSC.ELSB Position                 */
#define TPM_CnSC_ELSB(x)                         (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< TPM0_CnSC.ELSB Field                    */
#define TPM_CnSC_MSA_MASK                        (0x10U)                                             /*!< TPM0_CnSC.MSA Mask                      */
#define TPM_CnSC_MSA_SHIFT                       (4U)                                                /*!< TPM0_CnSC.MSA Position                  */
#define TPM_CnSC_MSA(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< TPM0_CnSC.MSA Field                     */
#define TPM_CnSC_MSB_MASK                        (0x20U)                                             /*!< TPM0_CnSC.MSB Mask                      */
#define TPM_CnSC_MSB_SHIFT                       (5U)                                                /*!< TPM0_CnSC.MSB Position                  */
#define TPM_CnSC_MSB(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< TPM0_CnSC.MSB Field                     */
#define TPM_CnSC_CHIE_MASK                       (0x40U)                                             /*!< TPM0_CnSC.CHIE Mask                     */
#define TPM_CnSC_CHIE_SHIFT                      (6U)                                                /*!< TPM0_CnSC.CHIE Position                 */
#define TPM_CnSC_CHIE(x)                         (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< TPM0_CnSC.CHIE Field                    */
#define TPM_CnSC_CHF_MASK                        (0x80U)                                             /*!< TPM0_CnSC.CHF Mask                      */
#define TPM_CnSC_CHF_SHIFT                       (7U)                                                /*!< TPM0_CnSC.CHF Position                  */
#define TPM_CnSC_CHF(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< TPM0_CnSC.CHF Field                     */
/* ------- CnV Bit Fields                           ------ */
#define TPM_CnV_VAL_MASK                         (0xFFFFU)                                           /*!< TPM0_CnV.VAL Mask                       */
#define TPM_CnV_VAL_SHIFT                        (0U)                                                /*!< TPM0_CnV.VAL Position                   */
#define TPM_CnV_VAL(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< TPM0_CnV.VAL Field                      */
/* ------- STATUS Bit Fields                        ------ */
#define TPM_STATUS_CH0F_MASK                     (0x1U)                                              /*!< TPM0_STATUS.CH0F Mask                   */
#define TPM_STATUS_CH0F_SHIFT                    (0U)                                                /*!< TPM0_STATUS.CH0F Position               */
#define TPM_STATUS_CH0F(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< TPM0_STATUS.CH0F Field                  */
#define TPM_STATUS_CH1F_MASK                     (0x2U)                                              /*!< TPM0_STATUS.CH1F Mask                   */
#define TPM_STATUS_CH1F_SHIFT                    (1U)                                                /*!< TPM0_STATUS.CH1F Position               */
#define TPM_STATUS_CH1F(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< TPM0_STATUS.CH1F Field                  */
#define TPM_STATUS_CH2F_MASK                     (0x4U)                                              /*!< TPM0_STATUS.CH2F Mask                   */
#define TPM_STATUS_CH2F_SHIFT                    (2U)                                                /*!< TPM0_STATUS.CH2F Position               */
#define TPM_STATUS_CH2F(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< TPM0_STATUS.CH2F Field                  */
#define TPM_STATUS_CH3F_MASK                     (0x8U)                                              /*!< TPM0_STATUS.CH3F Mask                   */
#define TPM_STATUS_CH3F_SHIFT                    (3U)                                                /*!< TPM0_STATUS.CH3F Position               */
#define TPM_STATUS_CH3F(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< TPM0_STATUS.CH3F Field                  */
#define TPM_STATUS_CH4F_MASK                     (0x10U)                                             /*!< TPM0_STATUS.CH4F Mask                   */
#define TPM_STATUS_CH4F_SHIFT                    (4U)                                                /*!< TPM0_STATUS.CH4F Position               */
#define TPM_STATUS_CH4F(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< TPM0_STATUS.CH4F Field                  */
#define TPM_STATUS_CH5F_MASK                     (0x20U)                                             /*!< TPM0_STATUS.CH5F Mask                   */
#define TPM_STATUS_CH5F_SHIFT                    (5U)                                                /*!< TPM0_STATUS.CH5F Position               */
#define TPM_STATUS_CH5F(x)                       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< TPM0_STATUS.CH5F Field                  */
#define TPM_STATUS_TOF_MASK                      (0x100U)                                            /*!< TPM0_STATUS.TOF Mask                    */
#define TPM_STATUS_TOF_SHIFT                     (8U)                                                /*!< TPM0_STATUS.TOF Position                */
#define TPM_STATUS_TOF(x)                        (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< TPM0_STATUS.TOF Field                   */
/* ------- COMBINE Bit Fields                       ------ */
#define TPM_COMBINE_COMBINE0_MASK                (0x1U)                                              /*!< TPM0_COMBINE.COMBINE0 Mask              */
#define TPM_COMBINE_COMBINE0_SHIFT               (0U)                                                /*!< TPM0_COMBINE.COMBINE0 Position          */
#define TPM_COMBINE_COMBINE0(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< TPM0_COMBINE.COMBINE0 Field             */
#define TPM_COMBINE_COMSWAP0_MASK                (0x2U)                                              /*!< TPM0_COMBINE.COMSWAP0 Mask              */
#define TPM_COMBINE_COMSWAP0_SHIFT               (1U)                                                /*!< TPM0_COMBINE.COMSWAP0 Position          */
#define TPM_COMBINE_COMSWAP0(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< TPM0_COMBINE.COMSWAP0 Field             */
#define TPM_COMBINE_COMBINE1_MASK                (0x100U)                                            /*!< TPM0_COMBINE.COMBINE1 Mask              */
#define TPM_COMBINE_COMBINE1_SHIFT               (8U)                                                /*!< TPM0_COMBINE.COMBINE1 Position          */
#define TPM_COMBINE_COMBINE1(x)                  (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< TPM0_COMBINE.COMBINE1 Field             */
#define TPM_COMBINE_COMSWAP1_MASK                (0x200U)                                            /*!< TPM0_COMBINE.COMSWAP1 Mask              */
#define TPM_COMBINE_COMSWAP1_SHIFT               (9U)                                                /*!< TPM0_COMBINE.COMSWAP1 Position          */
#define TPM_COMBINE_COMSWAP1(x)                  (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< TPM0_COMBINE.COMSWAP1 Field             */
#define TPM_COMBINE_COMBINE2_MASK                (0x10000U)                                          /*!< TPM0_COMBINE.COMBINE2 Mask              */
#define TPM_COMBINE_COMBINE2_SHIFT               (16U)                                               /*!< TPM0_COMBINE.COMBINE2 Position          */
#define TPM_COMBINE_COMBINE2(x)                  (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< TPM0_COMBINE.COMBINE2 Field             */
#define TPM_COMBINE_COMSWAP2_MASK                (0x20000U)                                          /*!< TPM0_COMBINE.COMSWAP2 Mask              */
#define TPM_COMBINE_COMSWAP2_SHIFT               (17U)                                               /*!< TPM0_COMBINE.COMSWAP2 Position          */
#define TPM_COMBINE_COMSWAP2(x)                  (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< TPM0_COMBINE.COMSWAP2 Field             */
/* ------- POL Bit Fields                           ------ */
#define TPM_POL_POL0_MASK                        (0x1U)                                              /*!< TPM0_POL.POL0 Mask                      */
#define TPM_POL_POL0_SHIFT                       (0U)                                                /*!< TPM0_POL.POL0 Position                  */
#define TPM_POL_POL0(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< TPM0_POL.POL0 Field                     */
#define TPM_POL_POL1_MASK                        (0x2U)                                              /*!< TPM0_POL.POL1 Mask                      */
#define TPM_POL_POL1_SHIFT                       (1U)                                                /*!< TPM0_POL.POL1 Position                  */
#define TPM_POL_POL1(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< TPM0_POL.POL1 Field                     */
#define TPM_POL_POL2_MASK                        (0x4U)                                              /*!< TPM0_POL.POL2 Mask                      */
#define TPM_POL_POL2_SHIFT                       (2U)                                                /*!< TPM0_POL.POL2 Position                  */
#define TPM_POL_POL2(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< TPM0_POL.POL2 Field                     */
#define TPM_POL_POL3_MASK                        (0x8U)                                              /*!< TPM0_POL.POL3 Mask                      */
#define TPM_POL_POL3_SHIFT                       (3U)                                                /*!< TPM0_POL.POL3 Position                  */
#define TPM_POL_POL3(x)                          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< TPM0_POL.POL3 Field                     */
#define TPM_POL_POL4_MASK                        (0x10U)                                             /*!< TPM0_POL.POL4 Mask                      */
#define TPM_POL_POL4_SHIFT                       (4U)                                                /*!< TPM0_POL.POL4 Position                  */
#define TPM_POL_POL4(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< TPM0_POL.POL4 Field                     */
#define TPM_POL_POL5_MASK                        (0x20U)                                             /*!< TPM0_POL.POL5 Mask                      */
#define TPM_POL_POL5_SHIFT                       (5U)                                                /*!< TPM0_POL.POL5 Position                  */
#define TPM_POL_POL5(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< TPM0_POL.POL5 Field                     */
/* ------- FILTER Bit Fields                        ------ */
#define TPM_FILTER_CH0FVAL_MASK                  (0xFU)                                              /*!< TPM0_FILTER.CH0FVAL Mask                */
#define TPM_FILTER_CH0FVAL_SHIFT                 (0U)                                                /*!< TPM0_FILTER.CH0FVAL Position            */
#define TPM_FILTER_CH0FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< TPM0_FILTER.CH0FVAL Field               */
#define TPM_FILTER_CH1FVAL_MASK                  (0xF0U)                                             /*!< TPM0_FILTER.CH1FVAL Mask                */
#define TPM_FILTER_CH1FVAL_SHIFT                 (4U)                                                /*!< TPM0_FILTER.CH1FVAL Position            */
#define TPM_FILTER_CH1FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<4U))&0xF0UL)          /*!< TPM0_FILTER.CH1FVAL Field               */
#define TPM_FILTER_CH2FVAL_MASK                  (0xF00U)                                            /*!< TPM0_FILTER.CH2FVAL Mask                */
#define TPM_FILTER_CH2FVAL_SHIFT                 (8U)                                                /*!< TPM0_FILTER.CH2FVAL Position            */
#define TPM_FILTER_CH2FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< TPM0_FILTER.CH2FVAL Field               */
#define TPM_FILTER_CH3FVAL_MASK                  (0xF000U)                                           /*!< TPM0_FILTER.CH3FVAL Mask                */
#define TPM_FILTER_CH3FVAL_SHIFT                 (12U)                                               /*!< TPM0_FILTER.CH3FVAL Position            */
#define TPM_FILTER_CH3FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<12U))&0xF000UL)       /*!< TPM0_FILTER.CH3FVAL Field               */
#define TPM_FILTER_CH4FVAL_MASK                  (0xF0000U)                                          /*!< TPM0_FILTER.CH4FVAL Mask                */
#define TPM_FILTER_CH4FVAL_SHIFT                 (16U)                                               /*!< TPM0_FILTER.CH4FVAL Position            */
#define TPM_FILTER_CH4FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<16U))&0xF0000UL)      /*!< TPM0_FILTER.CH4FVAL Field               */
#define TPM_FILTER_CH5FVAL_MASK                  (0xF00000U)                                         /*!< TPM0_FILTER.CH5FVAL Mask                */
#define TPM_FILTER_CH5FVAL_SHIFT                 (20U)                                               /*!< TPM0_FILTER.CH5FVAL Position            */
#define TPM_FILTER_CH5FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<20U))&0xF00000UL)     /*!< TPM0_FILTER.CH5FVAL Field               */
/* ------- CONF Bit Fields                          ------ */
#define TPM_CONF_DOZEEN_MASK                     (0x20U)                                             /*!< TPM0_CONF.DOZEEN Mask                   */
#define TPM_CONF_DOZEEN_SHIFT                    (5U)                                                /*!< TPM0_CONF.DOZEEN Position               */
#define TPM_CONF_DOZEEN(x)                       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< TPM0_CONF.DOZEEN Field                  */
#define TPM_CONF_DBGMODE_MASK                    (0xC0U)                                             /*!< TPM0_CONF.DBGMODE Mask                  */
#define TPM_CONF_DBGMODE_SHIFT                   (6U)                                                /*!< TPM0_CONF.DBGMODE Position              */
#define TPM_CONF_DBGMODE(x)                      (((uint32_t)(((uint32_t)(x))<<6U))&0xC0UL)          /*!< TPM0_CONF.DBGMODE Field                 */
#define TPM_CONF_GTBSYNC_MASK                    (0x100U)                                            /*!< TPM0_CONF.GTBSYNC Mask                  */
#define TPM_CONF_GTBSYNC_SHIFT                   (8U)                                                /*!< TPM0_CONF.GTBSYNC Position              */
#define TPM_CONF_GTBSYNC(x)                      (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< TPM0_CONF.GTBSYNC Field                 */
#define TPM_CONF_GTBEEN_MASK                     (0x200U)                                            /*!< TPM0_CONF.GTBEEN Mask                   */
#define TPM_CONF_GTBEEN_SHIFT                    (9U)                                                /*!< TPM0_CONF.GTBEEN Position               */
#define TPM_CONF_GTBEEN(x)                       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< TPM0_CONF.GTBEEN Field                  */
#define TPM_CONF_CSOT_MASK                       (0x10000U)                                          /*!< TPM0_CONF.CSOT Mask                     */
#define TPM_CONF_CSOT_SHIFT                      (16U)                                               /*!< TPM0_CONF.CSOT Position                 */
#define TPM_CONF_CSOT(x)                         (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< TPM0_CONF.CSOT Field                    */
#define TPM_CONF_CSOO_MASK                       (0x20000U)                                          /*!< TPM0_CONF.CSOO Mask                     */
#define TPM_CONF_CSOO_SHIFT                      (17U)                                               /*!< TPM0_CONF.CSOO Position                 */
#define TPM_CONF_CSOO(x)                         (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< TPM0_CONF.CSOO Field                    */
#define TPM_CONF_CROT_MASK                       (0x40000U)                                          /*!< TPM0_CONF.CROT Mask                     */
#define TPM_CONF_CROT_SHIFT                      (18U)                                               /*!< TPM0_CONF.CROT Position                 */
#define TPM_CONF_CROT(x)                         (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< TPM0_CONF.CROT Field                    */
#define TPM_CONF_CPOT_MASK                       (0x80000U)                                          /*!< TPM0_CONF.CPOT Mask                     */
#define TPM_CONF_CPOT_SHIFT                      (19U)                                               /*!< TPM0_CONF.CPOT Position                 */
#define TPM_CONF_CPOT(x)                         (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< TPM0_CONF.CPOT Field                    */
#define TPM_CONF_TRGPOL_MASK                     (0x400000U)                                         /*!< TPM0_CONF.TRGPOL Mask                   */
#define TPM_CONF_TRGPOL_SHIFT                    (22U)                                               /*!< TPM0_CONF.TRGPOL Position               */
#define TPM_CONF_TRGPOL(x)                       (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< TPM0_CONF.TRGPOL Field                  */
#define TPM_CONF_TRGSRC_MASK                     (0x800000U)                                         /*!< TPM0_CONF.TRGSRC Mask                   */
#define TPM_CONF_TRGSRC_SHIFT                    (23U)                                               /*!< TPM0_CONF.TRGSRC Position               */
#define TPM_CONF_TRGSRC(x)                       (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< TPM0_CONF.TRGSRC Field                  */
#define TPM_CONF_TRGSEL_MASK                     (0xF000000U)                                        /*!< TPM0_CONF.TRGSEL Mask                   */
#define TPM_CONF_TRGSEL_SHIFT                    (24U)                                               /*!< TPM0_CONF.TRGSEL Position               */
#define TPM_CONF_TRGSEL(x)                       (((uint32_t)(((uint32_t)(x))<<24U))&0xF000000UL)    /*!< TPM0_CONF.TRGSEL Field                  */
/**
 * @} */ /* End group TPM_Register_Masks_GROUP 
 */

/* TPM0 - Peripheral instance base addresses */
#define TPM0_BasePtr                   0x40038000UL //!< Peripheral base address
#define TPM0                           ((TPM0_Type *) TPM0_BasePtr) //!< Freescale base pointer
#define TPM0_BASE_PTR                  (TPM0) //!< Freescale style base pointer
/**
 * @} */ /* End group TPM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup TPM_Peripheral_access_layer_GROUP TPM Peripheral Access Layer
* @brief C Struct for TPM
* @{
*/

/* ================================================================================ */
/* ================           TPM1 (file:TPM1_MKL82Z7)             ================ */
/* ================================================================================ */

/**
 * @brief Timer/PWM Module
 */
/**
* @addtogroup TPM_structs_GROUP TPM struct
* @brief Struct for TPM
* @{
*/
typedef struct {                                /*       TPM1 Structure                                               */
   __IO uint32_t  SC;                           /**< 0000: Status and Control                                           */
   __IO uint32_t  CNT;                          /**< 0004: Counter                                                      */
   __IO uint32_t  MOD;                          /**< 0008: Modulo                                                       */
   struct {
      __IO uint32_t  CnSC;                      /**< 000C: Channel (n) Status and Control                               */
      __IO uint32_t  CnV;                       /**< 0010: Channel (n) Value                                            */
   } CONTROLS[2];                               /**< 000C: (cluster: size=0x0010, 16)                                   */
        uint8_t   RESERVED_1[52];              
   __IO uint32_t  STATUS;                       /**< 0050: Capture and Compare Status                                   */
        uint8_t   RESERVED_2[16];              
   __IO uint32_t  COMBINE;                      /**< 0064: Combine Channel Register                                     */
        uint8_t   RESERVED_3[8];               
   __IO uint32_t  POL;                          /**< 0070: Channel Polarity                                             */
        uint8_t   RESERVED_4[4];               
   __IO uint32_t  FILTER;                       /**< 0078: Filter Control                                               */
        uint8_t   RESERVED_5[8];               
   __IO uint32_t  CONF;                         /**< 0084: Configuration                                                */
} TPM1_Type;

/**
 * @} */ /* End group TPM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'TPM1' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup TPM_Register_Masks_GROUP TPM Register Masks
* @brief Register Masks for TPM
* @{
*/
/* ------- SC Bit Fields                            ------ */
/* ------- CNT Bit Fields                           ------ */
/* ------- MOD Bit Fields                           ------ */
/* ------- CnSC Bit Fields                          ------ */
/* ------- CnV Bit Fields                           ------ */
/* ------- STATUS Bit Fields                        ------ */
/* ------- COMBINE Bit Fields                       ------ */
/* ------- POL Bit Fields                           ------ */
/* ------- FILTER Bit Fields                        ------ */
/* ------- CONF Bit Fields                          ------ */
/**
 * @} */ /* End group TPM_Register_Masks_GROUP 
 */

/* TPM1 - Peripheral instance base addresses */
#define TPM1_BasePtr                   0x40039000UL //!< Peripheral base address
#define TPM1                           ((TPM1_Type *) TPM1_BasePtr) //!< Freescale base pointer
#define TPM1_BASE_PTR                  (TPM1) //!< Freescale style base pointer
/**
 * @} */ /* End group TPM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup TPM_Peripheral_access_layer_GROUP TPM Peripheral Access Layer
* @brief C Struct for TPM
* @{
*/

/* ================================================================================ */
/* ================           TPM2 (derived from TPM1)             ================ */
/* ================================================================================ */

/**
 * @brief Timer/PWM Module
 */

/* TPM2 - Peripheral instance base addresses */
#define TPM2_BasePtr                   0x4003A000UL //!< Peripheral base address
#define TPM2                           ((TPM1_Type *) TPM2_BasePtr) //!< Freescale base pointer
#define TPM2_BASE_PTR                  (TPM2) //!< Freescale style base pointer
/**
 * @} */ /* End group TPM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup TRNG_Peripheral_access_layer_GROUP TRNG Peripheral Access Layer
* @brief C Struct for TRNG
* @{
*/

/* ================================================================================ */
/* ================           TRNG0 (file:TRNG0_0x40025000)        ================ */
/* ================================================================================ */

/**
 * @brief RNG
 */
/**
* @addtogroup TRNG_structs_GROUP TRNG struct
* @brief Struct for TRNG
* @{
*/
typedef struct {                                /*       TRNG0 Structure                                              */
   __IO uint32_t  MCTL;                         /**< 0000: RNGMiscellaneous Control Register                            */
   __IO uint32_t  SCMISC;                       /**< 0004: RNGStatistical Check Miscellaneous Register                  */
   __IO uint32_t  PKRRNG;                       /**< 0008: RNGPoker Range Register                                      */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  PKRMAX;                    /**< 000C: RNGPoker Maximum Limit Register                              */
      __I  uint32_t  PKRSQ;                     /**< 000C: RNGPoker Square Calculation Result Register                  */
   };
   __IO uint32_t  SDCTL;                        /**< 0010: RNGSeed Control Register                                     */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  SBLIM;                     /**< 0014: RNGSparse Bit Limit Register                                 */
      __I  uint32_t  TOTSAM;                    /**< 0014: RNGTotal Samples Register                                    */
   };
   __IO uint32_t  FRQMIN;                       /**< 0018: RNGFrequency Count Minimum Limit Register                    */
   union {                                      /**< 0000: (size=0004)                                                  */
      __I  uint32_t  FRQCNT;                    /**< 001C: RNGFrequency Count Register                                  */
      __IO uint32_t  FRQMAX;                    /**< 001C: RNGFrequency Count Maximum Limit Register                    */
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __I  uint32_t  SCMC;                      /**< 0020: RNGStatistical Check Monobit Count Register                  */
      __IO uint32_t  SCML;                      /**< 0020: RNGStatistical Check Monobit Limit Register                  */
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __I  uint32_t  SCR1C;                     /**< 0024: RNGStatistical Check Run Length 1 Count Register             */
      __IO uint32_t  SCR1L;                     /**< 0024: RNGStatistical Check Run Length 1 Limit Register             */
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __I  uint32_t  SCR2C;                     /**< 0028: RNGStatistical Check Run Length 2 Count Register             */
      __IO uint32_t  SCR2L;                     /**< 0028: RNGStatistical Check Run Length 2 Limit Register             */
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __I  uint32_t  SCR3C;                     /**< 002C: RNGStatistical Check Run Length 3 Count Register             */
      __IO uint32_t  SCR3L;                     /**< 002C: RNGStatistical Check Run Length 3 Limit Register             */
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __I  uint32_t  SCR4C;                     /**< 0030: RNGStatistical Check Run Length 4 Count Register             */
      __IO uint32_t  SCR4L;                     /**< 0030: RNGStatistical Check Run Length 4 Limit Register             */
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __I  uint32_t  SCR5C;                     /**< 0034: RNGStatistical Check Run Length 5 Count Register             */
      __IO uint32_t  SCR5L;                     /**< 0034: RNGStatistical Check Run Length 5 Limit Register             */
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __I  uint32_t  SCR6PC;                    /**< 0038: RNGStatistical Check Run Length 6+ Count Register            */
      __IO uint32_t  SCR6PL;                    /**< 0038: RNGStatistical Check Run Length 6+ Limit Register            */
   };
   __I  uint32_t  STATUS;                       /**< 003C: RNGStatus Register                                           */
   __I  uint32_t  ENT[16];                      /**< 0040: RNG TRNG Entropy Read Register                               */
   __I  uint32_t  PKRCNT10;                     /**< 0080: RNGStatistical Check Poker Count 1 and 0 Register            */
   __I  uint32_t  PKRCNT32;                     /**< 0084: RNGStatistical Check Poker Count 3 and 2 Register            */
   __I  uint32_t  PKRCNT54;                     /**< 0088: RNGStatistical Check Poker Count 5 and 4 Register            */
   __I  uint32_t  PKRCNT76;                     /**< 008C: RNGStatistical Check Poker Count 7 and 6 Register            */
   __I  uint32_t  PKRCNT98;                     /**< 0090: RNGStatistical Check Poker Count 9 and 8 Register            */
   __I  uint32_t  PKRCNTBA;                     /**< 0094: RNGStatistical Check Poker Count B and A Register            */
   __I  uint32_t  PKRCNTDC;                     /**< 0098: RNGStatistical Check Poker Count D and C Register            */
   __I  uint32_t  PKRCNTFE;                     /**< 009C: RNGStatistical Check Poker Count F and E Register            */
   __IO uint32_t  SEC_CFG;                      /**< 00A0: RNGSecurity Configuration Register                           */
   __IO uint32_t  INT_CTRL;                     /**< 00A4: RNGInterrupt Control Register                                */
   __IO uint32_t  INT_MASK;                     /**< 00A8: RNGMask Register                                             */
   __IO uint32_t  INT_STATUS;                   /**< 00AC: RNGInterrupt Status Register                                 */
        uint8_t   RESERVED_0[64];              
   __I  uint32_t  VID1;                         /**< 00F0: RNGVersion ID Register (MS)                                  */
   __I  uint32_t  VID2;                         /**< 00F4: RNGVersion ID Register (LS)                                  */
} TRNG_Type;

/**
 * @} */ /* End group TRNG_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'TRNG0' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup TRNG_Register_Masks_GROUP TRNG Register Masks
* @brief Register Masks for TRNG
* @{
*/
/* ------- MCTL Bit Fields                          ------ */
#define TRNG_MCTL_SAMP_MODE_MASK                 (0x3U)                                              /*!< TRNG0_MCTL.SAMP_MODE Mask               */
#define TRNG_MCTL_SAMP_MODE_SHIFT                (0U)                                                /*!< TRNG0_MCTL.SAMP_MODE Position           */
#define TRNG_MCTL_SAMP_MODE(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< TRNG0_MCTL.SAMP_MODE Field              */
#define TRNG_MCTL_OSC_DIV_MASK                   (0xCU)                                              /*!< TRNG0_MCTL.OSC_DIV Mask                 */
#define TRNG_MCTL_OSC_DIV_SHIFT                  (2U)                                                /*!< TRNG0_MCTL.OSC_DIV Position             */
#define TRNG_MCTL_OSC_DIV(x)                     (((uint32_t)(((uint32_t)(x))<<2U))&0xCUL)           /*!< TRNG0_MCTL.OSC_DIV Field                */
#define TRNG_MCTL_UNUSED_MASK                    (0x10U)                                             /*!< TRNG0_MCTL.UNUSED Mask                  */
#define TRNG_MCTL_UNUSED_SHIFT                   (4U)                                                /*!< TRNG0_MCTL.UNUSED Position              */
#define TRNG_MCTL_UNUSED(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< TRNG0_MCTL.UNUSED Field                 */
#define TRNG_MCTL_TRNG_ACC_MASK                  (0x20U)                                             /*!< TRNG0_MCTL.TRNG_ACC Mask                */
#define TRNG_MCTL_TRNG_ACC_SHIFT                 (5U)                                                /*!< TRNG0_MCTL.TRNG_ACC Position            */
#define TRNG_MCTL_TRNG_ACC(x)                    (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< TRNG0_MCTL.TRNG_ACC Field               */
#define TRNG_MCTL_RST_DEF_MASK                   (0x40U)                                             /*!< TRNG0_MCTL.RST_DEF Mask                 */
#define TRNG_MCTL_RST_DEF_SHIFT                  (6U)                                                /*!< TRNG0_MCTL.RST_DEF Position             */
#define TRNG_MCTL_RST_DEF(x)                     (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< TRNG0_MCTL.RST_DEF Field                */
#define TRNG_MCTL_FOR_SCLK_MASK                  (0x80U)                                             /*!< TRNG0_MCTL.FOR_SCLK Mask                */
#define TRNG_MCTL_FOR_SCLK_SHIFT                 (7U)                                                /*!< TRNG0_MCTL.FOR_SCLK Position            */
#define TRNG_MCTL_FOR_SCLK(x)                    (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< TRNG0_MCTL.FOR_SCLK Field               */
#define TRNG_MCTL_FCT_FAIL_MASK                  (0x100U)                                            /*!< TRNG0_MCTL.FCT_FAIL Mask                */
#define TRNG_MCTL_FCT_FAIL_SHIFT                 (8U)                                                /*!< TRNG0_MCTL.FCT_FAIL Position            */
#define TRNG_MCTL_FCT_FAIL(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< TRNG0_MCTL.FCT_FAIL Field               */
#define TRNG_MCTL_FCT_VAL_MASK                   (0x200U)                                            /*!< TRNG0_MCTL.FCT_VAL Mask                 */
#define TRNG_MCTL_FCT_VAL_SHIFT                  (9U)                                                /*!< TRNG0_MCTL.FCT_VAL Position             */
#define TRNG_MCTL_FCT_VAL(x)                     (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< TRNG0_MCTL.FCT_VAL Field                */
#define TRNG_MCTL_ENT_VAL_MASK                   (0x400U)                                            /*!< TRNG0_MCTL.ENT_VAL Mask                 */
#define TRNG_MCTL_ENT_VAL_SHIFT                  (10U)                                               /*!< TRNG0_MCTL.ENT_VAL Position             */
#define TRNG_MCTL_ENT_VAL(x)                     (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< TRNG0_MCTL.ENT_VAL Field                */
#define TRNG_MCTL_TST_OUT_MASK                   (0x800U)                                            /*!< TRNG0_MCTL.TST_OUT Mask                 */
#define TRNG_MCTL_TST_OUT_SHIFT                  (11U)                                               /*!< TRNG0_MCTL.TST_OUT Position             */
#define TRNG_MCTL_TST_OUT(x)                     (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< TRNG0_MCTL.TST_OUT Field                */
#define TRNG_MCTL_ERR_MASK                       (0x1000U)                                           /*!< TRNG0_MCTL.ERR Mask                     */
#define TRNG_MCTL_ERR_SHIFT                      (12U)                                               /*!< TRNG0_MCTL.ERR Position                 */
#define TRNG_MCTL_ERR(x)                         (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< TRNG0_MCTL.ERR Field                    */
#define TRNG_MCTL_TSTOP_OK_MASK                  (0x2000U)                                           /*!< TRNG0_MCTL.TSTOP_OK Mask                */
#define TRNG_MCTL_TSTOP_OK_SHIFT                 (13U)                                               /*!< TRNG0_MCTL.TSTOP_OK Position            */
#define TRNG_MCTL_TSTOP_OK(x)                    (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< TRNG0_MCTL.TSTOP_OK Field               */
#define TRNG_MCTL_PRGM_MASK                      (0x10000U)                                          /*!< TRNG0_MCTL.PRGM Mask                    */
#define TRNG_MCTL_PRGM_SHIFT                     (16U)                                               /*!< TRNG0_MCTL.PRGM Position                */
#define TRNG_MCTL_PRGM(x)                        (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< TRNG0_MCTL.PRGM Field                   */
/* ------- SCMISC Bit Fields                        ------ */
#define TRNG_SCMISC_LRUN_MAX_MASK                (0xFFU)                                             /*!< TRNG0_SCMISC.LRUN_MAX Mask              */
#define TRNG_SCMISC_LRUN_MAX_SHIFT               (0U)                                                /*!< TRNG0_SCMISC.LRUN_MAX Position          */
#define TRNG_SCMISC_LRUN_MAX(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< TRNG0_SCMISC.LRUN_MAX Field             */
#define TRNG_SCMISC_RTY_CT_MASK                  (0xF0000U)                                          /*!< TRNG0_SCMISC.RTY_CT Mask                */
#define TRNG_SCMISC_RTY_CT_SHIFT                 (16U)                                               /*!< TRNG0_SCMISC.RTY_CT Position            */
#define TRNG_SCMISC_RTY_CT(x)                    (((uint32_t)(((uint32_t)(x))<<16U))&0xF0000UL)      /*!< TRNG0_SCMISC.RTY_CT Field               */
/* ------- PKRRNG Bit Fields                        ------ */
#define TRNG_PKRRNG_PKR_RNG_MASK                 (0xFFFFU)                                           /*!< TRNG0_PKRRNG.PKR_RNG Mask               */
#define TRNG_PKRRNG_PKR_RNG_SHIFT                (0U)                                                /*!< TRNG0_PKRRNG.PKR_RNG Position           */
#define TRNG_PKRRNG_PKR_RNG(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< TRNG0_PKRRNG.PKR_RNG Field              */
/* ------- PKRMAX Bit Fields                        ------ */
#define TRNG_PKRMAX_PKR_MAX_MASK                 (0xFFFFFFU)                                         /*!< TRNG0_PKRMAX.PKR_MAX Mask               */
#define TRNG_PKRMAX_PKR_MAX_SHIFT                (0U)                                                /*!< TRNG0_PKRMAX.PKR_MAX Position           */
#define TRNG_PKRMAX_PKR_MAX(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFUL)      /*!< TRNG0_PKRMAX.PKR_MAX Field              */
/* ------- PKRSQ Bit Fields                         ------ */
#define TRNG_PKRSQ_PKR_SQ_MASK                   (0xFFFFFFU)                                         /*!< TRNG0_PKRSQ.PKR_SQ Mask                 */
#define TRNG_PKRSQ_PKR_SQ_SHIFT                  (0U)                                                /*!< TRNG0_PKRSQ.PKR_SQ Position             */
#define TRNG_PKRSQ_PKR_SQ(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFUL)      /*!< TRNG0_PKRSQ.PKR_SQ Field                */
/* ------- SDCTL Bit Fields                         ------ */
#define TRNG_SDCTL_SAMP_SIZE_MASK                (0xFFFFU)                                           /*!< TRNG0_SDCTL.SAMP_SIZE Mask              */
#define TRNG_SDCTL_SAMP_SIZE_SHIFT               (0U)                                                /*!< TRNG0_SDCTL.SAMP_SIZE Position          */
#define TRNG_SDCTL_SAMP_SIZE(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< TRNG0_SDCTL.SAMP_SIZE Field             */
#define TRNG_SDCTL_ENT_DLY_MASK                  (0xFFFF0000U)                                       /*!< TRNG0_SDCTL.ENT_DLY Mask                */
#define TRNG_SDCTL_ENT_DLY_SHIFT                 (16U)                                               /*!< TRNG0_SDCTL.ENT_DLY Position            */
#define TRNG_SDCTL_ENT_DLY(x)                    (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< TRNG0_SDCTL.ENT_DLY Field               */
/* ------- SBLIM Bit Fields                         ------ */
#define TRNG_SBLIM_SB_LIM_MASK                   (0x3FFU)                                            /*!< TRNG0_SBLIM.SB_LIM Mask                 */
#define TRNG_SBLIM_SB_LIM_SHIFT                  (0U)                                                /*!< TRNG0_SBLIM.SB_LIM Position             */
#define TRNG_SBLIM_SB_LIM(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFUL)         /*!< TRNG0_SBLIM.SB_LIM Field                */
/* ------- TOTSAM Bit Fields                        ------ */
#define TRNG_TOTSAM_TOT_SAM_MASK                 (0xFFFFFU)                                          /*!< TRNG0_TOTSAM.TOT_SAM Mask               */
#define TRNG_TOTSAM_TOT_SAM_SHIFT                (0U)                                                /*!< TRNG0_TOTSAM.TOT_SAM Position           */
#define TRNG_TOTSAM_TOT_SAM(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFUL)       /*!< TRNG0_TOTSAM.TOT_SAM Field              */
/* ------- FRQMIN Bit Fields                        ------ */
#define TRNG_FRQMIN_FRQ_MIN_MASK                 (0x3FFFFFU)                                         /*!< TRNG0_FRQMIN.FRQ_MIN Mask               */
#define TRNG_FRQMIN_FRQ_MIN_SHIFT                (0U)                                                /*!< TRNG0_FRQMIN.FRQ_MIN Position           */
#define TRNG_FRQMIN_FRQ_MIN(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFFFFUL)      /*!< TRNG0_FRQMIN.FRQ_MIN Field              */
/* ------- FRQCNT Bit Fields                        ------ */
#define TRNG_FRQCNT_FRQ_CT_MASK                  (0x3FFFFFU)                                         /*!< TRNG0_FRQCNT.FRQ_CT Mask                */
#define TRNG_FRQCNT_FRQ_CT_SHIFT                 (0U)                                                /*!< TRNG0_FRQCNT.FRQ_CT Position            */
#define TRNG_FRQCNT_FRQ_CT(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFFFFUL)      /*!< TRNG0_FRQCNT.FRQ_CT Field               */
/* ------- FRQMAX Bit Fields                        ------ */
#define TRNG_FRQMAX_FRQ_MAX_MASK                 (0x3FFFFFU)                                         /*!< TRNG0_FRQMAX.FRQ_MAX Mask               */
#define TRNG_FRQMAX_FRQ_MAX_SHIFT                (0U)                                                /*!< TRNG0_FRQMAX.FRQ_MAX Position           */
#define TRNG_FRQMAX_FRQ_MAX(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFFFFUL)      /*!< TRNG0_FRQMAX.FRQ_MAX Field              */
/* ------- SCMC Bit Fields                          ------ */
#define TRNG_SCMC_MONO_CT_MASK                   (0xFFFFU)                                           /*!< TRNG0_SCMC.MONO_CT Mask                 */
#define TRNG_SCMC_MONO_CT_SHIFT                  (0U)                                                /*!< TRNG0_SCMC.MONO_CT Position             */
#define TRNG_SCMC_MONO_CT(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< TRNG0_SCMC.MONO_CT Field                */
/* ------- SCML Bit Fields                          ------ */
#define TRNG_SCML_MONO_MAX_MASK                  (0xFFFFU)                                           /*!< TRNG0_SCML.MONO_MAX Mask                */
#define TRNG_SCML_MONO_MAX_SHIFT                 (0U)                                                /*!< TRNG0_SCML.MONO_MAX Position            */
#define TRNG_SCML_MONO_MAX(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< TRNG0_SCML.MONO_MAX Field               */
#define TRNG_SCML_MONO_RNG_MASK                  (0xFFFF0000U)                                       /*!< TRNG0_SCML.MONO_RNG Mask                */
#define TRNG_SCML_MONO_RNG_SHIFT                 (16U)                                               /*!< TRNG0_SCML.MONO_RNG Position            */
#define TRNG_SCML_MONO_RNG(x)                    (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< TRNG0_SCML.MONO_RNG Field               */
/* ------- SCR1C Bit Fields                         ------ */
#define TRNG_SCR1C_R1_0_CT_MASK                  (0x7FFFU)                                           /*!< TRNG0_SCR1C.R1_0_CT Mask                */
#define TRNG_SCR1C_R1_0_CT_SHIFT                 (0U)                                                /*!< TRNG0_SCR1C.R1_0_CT Position            */
#define TRNG_SCR1C_R1_0_CT(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x7FFFUL)        /*!< TRNG0_SCR1C.R1_0_CT Field               */
#define TRNG_SCR1C_R1_1_CT_MASK                  (0x7FFF0000U)                                       /*!< TRNG0_SCR1C.R1_1_CT Mask                */
#define TRNG_SCR1C_R1_1_CT_SHIFT                 (16U)                                               /*!< TRNG0_SCR1C.R1_1_CT Position            */
#define TRNG_SCR1C_R1_1_CT(x)                    (((uint32_t)(((uint32_t)(x))<<16U))&0x7FFF0000UL)   /*!< TRNG0_SCR1C.R1_1_CT Field               */
/* ------- SCR1L Bit Fields                         ------ */
#define TRNG_SCR1L_RUN1_MAX_MASK                 (0x7FFFU)                                           /*!< TRNG0_SCR1L.RUN1_MAX Mask               */
#define TRNG_SCR1L_RUN1_MAX_SHIFT                (0U)                                                /*!< TRNG0_SCR1L.RUN1_MAX Position           */
#define TRNG_SCR1L_RUN1_MAX(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x7FFFUL)        /*!< TRNG0_SCR1L.RUN1_MAX Field              */
#define TRNG_SCR1L_RUN1_RNG_MASK                 (0x7FFF0000U)                                       /*!< TRNG0_SCR1L.RUN1_RNG Mask               */
#define TRNG_SCR1L_RUN1_RNG_SHIFT                (16U)                                               /*!< TRNG0_SCR1L.RUN1_RNG Position           */
#define TRNG_SCR1L_RUN1_RNG(x)                   (((uint32_t)(((uint32_t)(x))<<16U))&0x7FFF0000UL)   /*!< TRNG0_SCR1L.RUN1_RNG Field              */
/* ------- SCR2C Bit Fields                         ------ */
#define TRNG_SCR2C_R2_0_CT_MASK                  (0x3FFFU)                                           /*!< TRNG0_SCR2C.R2_0_CT Mask                */
#define TRNG_SCR2C_R2_0_CT_SHIFT                 (0U)                                                /*!< TRNG0_SCR2C.R2_0_CT Position            */
#define TRNG_SCR2C_R2_0_CT(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFFUL)        /*!< TRNG0_SCR2C.R2_0_CT Field               */
#define TRNG_SCR2C_R2_1_CT_MASK                  (0x3FFF0000U)                                       /*!< TRNG0_SCR2C.R2_1_CT Mask                */
#define TRNG_SCR2C_R2_1_CT_SHIFT                 (16U)                                               /*!< TRNG0_SCR2C.R2_1_CT Position            */
#define TRNG_SCR2C_R2_1_CT(x)                    (((uint32_t)(((uint32_t)(x))<<16U))&0x3FFF0000UL)   /*!< TRNG0_SCR2C.R2_1_CT Field               */
/* ------- SCR2L Bit Fields                         ------ */
#define TRNG_SCR2L_RUN2_MAX_MASK                 (0x3FFFU)                                           /*!< TRNG0_SCR2L.RUN2_MAX Mask               */
#define TRNG_SCR2L_RUN2_MAX_SHIFT                (0U)                                                /*!< TRNG0_SCR2L.RUN2_MAX Position           */
#define TRNG_SCR2L_RUN2_MAX(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFFUL)        /*!< TRNG0_SCR2L.RUN2_MAX Field              */
#define TRNG_SCR2L_RUN2_RNG_MASK                 (0x3FFF0000U)                                       /*!< TRNG0_SCR2L.RUN2_RNG Mask               */
#define TRNG_SCR2L_RUN2_RNG_SHIFT                (16U)                                               /*!< TRNG0_SCR2L.RUN2_RNG Position           */
#define TRNG_SCR2L_RUN2_RNG(x)                   (((uint32_t)(((uint32_t)(x))<<16U))&0x3FFF0000UL)   /*!< TRNG0_SCR2L.RUN2_RNG Field              */
/* ------- SCR3C Bit Fields                         ------ */
#define TRNG_SCR3C_R3_0_CT_MASK                  (0x1FFFU)                                           /*!< TRNG0_SCR3C.R3_0_CT Mask                */
#define TRNG_SCR3C_R3_0_CT_SHIFT                 (0U)                                                /*!< TRNG0_SCR3C.R3_0_CT Position            */
#define TRNG_SCR3C_R3_0_CT(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFFUL)        /*!< TRNG0_SCR3C.R3_0_CT Field               */
#define TRNG_SCR3C_R3_1_CT_MASK                  (0x1FFF0000U)                                       /*!< TRNG0_SCR3C.R3_1_CT Mask                */
#define TRNG_SCR3C_R3_1_CT_SHIFT                 (16U)                                               /*!< TRNG0_SCR3C.R3_1_CT Position            */
#define TRNG_SCR3C_R3_1_CT(x)                    (((uint32_t)(((uint32_t)(x))<<16U))&0x1FFF0000UL)   /*!< TRNG0_SCR3C.R3_1_CT Field               */
/* ------- SCR3L Bit Fields                         ------ */
#define TRNG_SCR3L_RUN3_MAX_MASK                 (0x1FFFU)                                           /*!< TRNG0_SCR3L.RUN3_MAX Mask               */
#define TRNG_SCR3L_RUN3_MAX_SHIFT                (0U)                                                /*!< TRNG0_SCR3L.RUN3_MAX Position           */
#define TRNG_SCR3L_RUN3_MAX(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFFUL)        /*!< TRNG0_SCR3L.RUN3_MAX Field              */
#define TRNG_SCR3L_RUN3_RNG_MASK                 (0x1FFF0000U)                                       /*!< TRNG0_SCR3L.RUN3_RNG Mask               */
#define TRNG_SCR3L_RUN3_RNG_SHIFT                (16U)                                               /*!< TRNG0_SCR3L.RUN3_RNG Position           */
#define TRNG_SCR3L_RUN3_RNG(x)                   (((uint32_t)(((uint32_t)(x))<<16U))&0x1FFF0000UL)   /*!< TRNG0_SCR3L.RUN3_RNG Field              */
/* ------- SCR4C Bit Fields                         ------ */
#define TRNG_SCR4C_R4_0_CT_MASK                  (0xFFFU)                                            /*!< TRNG0_SCR4C.R4_0_CT Mask                */
#define TRNG_SCR4C_R4_0_CT_SHIFT                 (0U)                                                /*!< TRNG0_SCR4C.R4_0_CT Position            */
#define TRNG_SCR4C_R4_0_CT(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFUL)         /*!< TRNG0_SCR4C.R4_0_CT Field               */
#define TRNG_SCR4C_R4_1_CT_MASK                  (0xFFF0000U)                                        /*!< TRNG0_SCR4C.R4_1_CT Mask                */
#define TRNG_SCR4C_R4_1_CT_SHIFT                 (16U)                                               /*!< TRNG0_SCR4C.R4_1_CT Position            */
#define TRNG_SCR4C_R4_1_CT(x)                    (((uint32_t)(((uint32_t)(x))<<16U))&0xFFF0000UL)    /*!< TRNG0_SCR4C.R4_1_CT Field               */
/* ------- SCR4L Bit Fields                         ------ */
#define TRNG_SCR4L_RUN4_MAX_MASK                 (0xFFFU)                                            /*!< TRNG0_SCR4L.RUN4_MAX Mask               */
#define TRNG_SCR4L_RUN4_MAX_SHIFT                (0U)                                                /*!< TRNG0_SCR4L.RUN4_MAX Position           */
#define TRNG_SCR4L_RUN4_MAX(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFUL)         /*!< TRNG0_SCR4L.RUN4_MAX Field              */
#define TRNG_SCR4L_RUN4_RNG_MASK                 (0xFFF0000U)                                        /*!< TRNG0_SCR4L.RUN4_RNG Mask               */
#define TRNG_SCR4L_RUN4_RNG_SHIFT                (16U)                                               /*!< TRNG0_SCR4L.RUN4_RNG Position           */
#define TRNG_SCR4L_RUN4_RNG(x)                   (((uint32_t)(((uint32_t)(x))<<16U))&0xFFF0000UL)    /*!< TRNG0_SCR4L.RUN4_RNG Field              */
/* ------- SCR5C Bit Fields                         ------ */
#define TRNG_SCR5C_R5_0_CT_MASK                  (0x7FFU)                                            /*!< TRNG0_SCR5C.R5_0_CT Mask                */
#define TRNG_SCR5C_R5_0_CT_SHIFT                 (0U)                                                /*!< TRNG0_SCR5C.R5_0_CT Position            */
#define TRNG_SCR5C_R5_0_CT(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x7FFUL)         /*!< TRNG0_SCR5C.R5_0_CT Field               */
#define TRNG_SCR5C_R5_1_CT_MASK                  (0x7FF0000U)                                        /*!< TRNG0_SCR5C.R5_1_CT Mask                */
#define TRNG_SCR5C_R5_1_CT_SHIFT                 (16U)                                               /*!< TRNG0_SCR5C.R5_1_CT Position            */
#define TRNG_SCR5C_R5_1_CT(x)                    (((uint32_t)(((uint32_t)(x))<<16U))&0x7FF0000UL)    /*!< TRNG0_SCR5C.R5_1_CT Field               */
/* ------- SCR5L Bit Fields                         ------ */
#define TRNG_SCR5L_RUN5_MAX_MASK                 (0x7FFU)                                            /*!< TRNG0_SCR5L.RUN5_MAX Mask               */
#define TRNG_SCR5L_RUN5_MAX_SHIFT                (0U)                                                /*!< TRNG0_SCR5L.RUN5_MAX Position           */
#define TRNG_SCR5L_RUN5_MAX(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x7FFUL)         /*!< TRNG0_SCR5L.RUN5_MAX Field              */
#define TRNG_SCR5L_RUN5_RNG_MASK                 (0x7FF0000U)                                        /*!< TRNG0_SCR5L.RUN5_RNG Mask               */
#define TRNG_SCR5L_RUN5_RNG_SHIFT                (16U)                                               /*!< TRNG0_SCR5L.RUN5_RNG Position           */
#define TRNG_SCR5L_RUN5_RNG(x)                   (((uint32_t)(((uint32_t)(x))<<16U))&0x7FF0000UL)    /*!< TRNG0_SCR5L.RUN5_RNG Field              */
/* ------- SCR6PC Bit Fields                        ------ */
#define TRNG_SCR6PC_R6P_0_CT_MASK                (0x7FFU)                                            /*!< TRNG0_SCR6PC.R6P_0_CT Mask              */
#define TRNG_SCR6PC_R6P_0_CT_SHIFT               (0U)                                                /*!< TRNG0_SCR6PC.R6P_0_CT Position          */
#define TRNG_SCR6PC_R6P_0_CT(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x7FFUL)         /*!< TRNG0_SCR6PC.R6P_0_CT Field             */
#define TRNG_SCR6PC_R6P_1_CT_MASK                (0x7FF0000U)                                        /*!< TRNG0_SCR6PC.R6P_1_CT Mask              */
#define TRNG_SCR6PC_R6P_1_CT_SHIFT               (16U)                                               /*!< TRNG0_SCR6PC.R6P_1_CT Position          */
#define TRNG_SCR6PC_R6P_1_CT(x)                  (((uint32_t)(((uint32_t)(x))<<16U))&0x7FF0000UL)    /*!< TRNG0_SCR6PC.R6P_1_CT Field             */
/* ------- SCR6PL Bit Fields                        ------ */
#define TRNG_SCR6PL_RUN6P_MAX_MASK               (0x7FFU)                                            /*!< TRNG0_SCR6PL.RUN6P_MAX Mask             */
#define TRNG_SCR6PL_RUN6P_MAX_SHIFT              (0U)                                                /*!< TRNG0_SCR6PL.RUN6P_MAX Position         */
#define TRNG_SCR6PL_RUN6P_MAX(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7FFUL)         /*!< TRNG0_SCR6PL.RUN6P_MAX Field            */
#define TRNG_SCR6PL_RUN6P_RNG_MASK               (0x7FF0000U)                                        /*!< TRNG0_SCR6PL.RUN6P_RNG Mask             */
#define TRNG_SCR6PL_RUN6P_RNG_SHIFT              (16U)                                               /*!< TRNG0_SCR6PL.RUN6P_RNG Position         */
#define TRNG_SCR6PL_RUN6P_RNG(x)                 (((uint32_t)(((uint32_t)(x))<<16U))&0x7FF0000UL)    /*!< TRNG0_SCR6PL.RUN6P_RNG Field            */
/* ------- STATUS Bit Fields                        ------ */
#define TRNG_STATUS_TF1BR0_MASK                  (0x1U)                                              /*!< TRNG0_STATUS.TF1BR0 Mask                */
#define TRNG_STATUS_TF1BR0_SHIFT                 (0U)                                                /*!< TRNG0_STATUS.TF1BR0 Position            */
#define TRNG_STATUS_TF1BR0(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< TRNG0_STATUS.TF1BR0 Field               */
#define TRNG_STATUS_TF1BR1_MASK                  (0x2U)                                              /*!< TRNG0_STATUS.TF1BR1 Mask                */
#define TRNG_STATUS_TF1BR1_SHIFT                 (1U)                                                /*!< TRNG0_STATUS.TF1BR1 Position            */
#define TRNG_STATUS_TF1BR1(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< TRNG0_STATUS.TF1BR1 Field               */
#define TRNG_STATUS_TF2BR0_MASK                  (0x4U)                                              /*!< TRNG0_STATUS.TF2BR0 Mask                */
#define TRNG_STATUS_TF2BR0_SHIFT                 (2U)                                                /*!< TRNG0_STATUS.TF2BR0 Position            */
#define TRNG_STATUS_TF2BR0(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< TRNG0_STATUS.TF2BR0 Field               */
#define TRNG_STATUS_TF2BR1_MASK                  (0x8U)                                              /*!< TRNG0_STATUS.TF2BR1 Mask                */
#define TRNG_STATUS_TF2BR1_SHIFT                 (3U)                                                /*!< TRNG0_STATUS.TF2BR1 Position            */
#define TRNG_STATUS_TF2BR1(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< TRNG0_STATUS.TF2BR1 Field               */
#define TRNG_STATUS_TF3BR0_MASK                  (0x10U)                                             /*!< TRNG0_STATUS.TF3BR0 Mask                */
#define TRNG_STATUS_TF3BR0_SHIFT                 (4U)                                                /*!< TRNG0_STATUS.TF3BR0 Position            */
#define TRNG_STATUS_TF3BR0(x)                    (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< TRNG0_STATUS.TF3BR0 Field               */
#define TRNG_STATUS_TF3BR1_MASK                  (0x20U)                                             /*!< TRNG0_STATUS.TF3BR1 Mask                */
#define TRNG_STATUS_TF3BR1_SHIFT                 (5U)                                                /*!< TRNG0_STATUS.TF3BR1 Position            */
#define TRNG_STATUS_TF3BR1(x)                    (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< TRNG0_STATUS.TF3BR1 Field               */
#define TRNG_STATUS_TF4BR0_MASK                  (0x40U)                                             /*!< TRNG0_STATUS.TF4BR0 Mask                */
#define TRNG_STATUS_TF4BR0_SHIFT                 (6U)                                                /*!< TRNG0_STATUS.TF4BR0 Position            */
#define TRNG_STATUS_TF4BR0(x)                    (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< TRNG0_STATUS.TF4BR0 Field               */
#define TRNG_STATUS_TF4BR1_MASK                  (0x80U)                                             /*!< TRNG0_STATUS.TF4BR1 Mask                */
#define TRNG_STATUS_TF4BR1_SHIFT                 (7U)                                                /*!< TRNG0_STATUS.TF4BR1 Position            */
#define TRNG_STATUS_TF4BR1(x)                    (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< TRNG0_STATUS.TF4BR1 Field               */
#define TRNG_STATUS_TF5BR0_MASK                  (0x100U)                                            /*!< TRNG0_STATUS.TF5BR0 Mask                */
#define TRNG_STATUS_TF5BR0_SHIFT                 (8U)                                                /*!< TRNG0_STATUS.TF5BR0 Position            */
#define TRNG_STATUS_TF5BR0(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< TRNG0_STATUS.TF5BR0 Field               */
#define TRNG_STATUS_TF5BR1_MASK                  (0x200U)                                            /*!< TRNG0_STATUS.TF5BR1 Mask                */
#define TRNG_STATUS_TF5BR1_SHIFT                 (9U)                                                /*!< TRNG0_STATUS.TF5BR1 Position            */
#define TRNG_STATUS_TF5BR1(x)                    (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< TRNG0_STATUS.TF5BR1 Field               */
#define TRNG_STATUS_TF6PBR0_MASK                 (0x400U)                                            /*!< TRNG0_STATUS.TF6PBR0 Mask               */
#define TRNG_STATUS_TF6PBR0_SHIFT                (10U)                                               /*!< TRNG0_STATUS.TF6PBR0 Position           */
#define TRNG_STATUS_TF6PBR0(x)                   (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< TRNG0_STATUS.TF6PBR0 Field              */
#define TRNG_STATUS_TF6PBR1_MASK                 (0x800U)                                            /*!< TRNG0_STATUS.TF6PBR1 Mask               */
#define TRNG_STATUS_TF6PBR1_SHIFT                (11U)                                               /*!< TRNG0_STATUS.TF6PBR1 Position           */
#define TRNG_STATUS_TF6PBR1(x)                   (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< TRNG0_STATUS.TF6PBR1 Field              */
#define TRNG_STATUS_TFSB_MASK                    (0x1000U)                                           /*!< TRNG0_STATUS.TFSB Mask                  */
#define TRNG_STATUS_TFSB_SHIFT                   (12U)                                               /*!< TRNG0_STATUS.TFSB Position              */
#define TRNG_STATUS_TFSB(x)                      (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< TRNG0_STATUS.TFSB Field                 */
#define TRNG_STATUS_TFLR_MASK                    (0x2000U)                                           /*!< TRNG0_STATUS.TFLR Mask                  */
#define TRNG_STATUS_TFLR_SHIFT                   (13U)                                               /*!< TRNG0_STATUS.TFLR Position              */
#define TRNG_STATUS_TFLR(x)                      (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< TRNG0_STATUS.TFLR Field                 */
#define TRNG_STATUS_TFP_MASK                     (0x4000U)                                           /*!< TRNG0_STATUS.TFP Mask                   */
#define TRNG_STATUS_TFP_SHIFT                    (14U)                                               /*!< TRNG0_STATUS.TFP Position               */
#define TRNG_STATUS_TFP(x)                       (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< TRNG0_STATUS.TFP Field                  */
#define TRNG_STATUS_TFMB_MASK                    (0x8000U)                                           /*!< TRNG0_STATUS.TFMB Mask                  */
#define TRNG_STATUS_TFMB_SHIFT                   (15U)                                               /*!< TRNG0_STATUS.TFMB Position              */
#define TRNG_STATUS_TFMB(x)                      (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< TRNG0_STATUS.TFMB Field                 */
#define TRNG_STATUS_RETRY_CT_MASK                (0xF0000U)                                          /*!< TRNG0_STATUS.RETRY_CT Mask              */
#define TRNG_STATUS_RETRY_CT_SHIFT               (16U)                                               /*!< TRNG0_STATUS.RETRY_CT Position          */
#define TRNG_STATUS_RETRY_CT(x)                  (((uint32_t)(((uint32_t)(x))<<16U))&0xF0000UL)      /*!< TRNG0_STATUS.RETRY_CT Field             */
/* ------- ENT Bit Fields                           ------ */
#define TRNG_ENT_ENT_MASK                        (0xFFFFFFFFU)                                       /*!< TRNG0_ENT.ENT Mask                      */
#define TRNG_ENT_ENT_SHIFT                       (0U)                                                /*!< TRNG0_ENT.ENT Position                  */
#define TRNG_ENT_ENT(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< TRNG0_ENT.ENT Field                     */
/* ------- PKRCNT10 Bit Fields                      ------ */
#define TRNG_PKRCNT10_PKR_0_CT_MASK              (0xFFFFU)                                           /*!< TRNG0_PKRCNT10.PKR_0_CT Mask            */
#define TRNG_PKRCNT10_PKR_0_CT_SHIFT             (0U)                                                /*!< TRNG0_PKRCNT10.PKR_0_CT Position        */
#define TRNG_PKRCNT10_PKR_0_CT(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< TRNG0_PKRCNT10.PKR_0_CT Field           */
#define TRNG_PKRCNT10_PKR_1_CT_MASK              (0xFFFF0000U)                                       /*!< TRNG0_PKRCNT10.PKR_1_CT Mask            */
#define TRNG_PKRCNT10_PKR_1_CT_SHIFT             (16U)                                               /*!< TRNG0_PKRCNT10.PKR_1_CT Position        */
#define TRNG_PKRCNT10_PKR_1_CT(x)                (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< TRNG0_PKRCNT10.PKR_1_CT Field           */
/* ------- PKRCNT32 Bit Fields                      ------ */
#define TRNG_PKRCNT32_PKR_2_CT_MASK              (0xFFFFU)                                           /*!< TRNG0_PKRCNT32.PKR_2_CT Mask            */
#define TRNG_PKRCNT32_PKR_2_CT_SHIFT             (0U)                                                /*!< TRNG0_PKRCNT32.PKR_2_CT Position        */
#define TRNG_PKRCNT32_PKR_2_CT(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< TRNG0_PKRCNT32.PKR_2_CT Field           */
#define TRNG_PKRCNT32_PKR_3_CT_MASK              (0xFFFF0000U)                                       /*!< TRNG0_PKRCNT32.PKR_3_CT Mask            */
#define TRNG_PKRCNT32_PKR_3_CT_SHIFT             (16U)                                               /*!< TRNG0_PKRCNT32.PKR_3_CT Position        */
#define TRNG_PKRCNT32_PKR_3_CT(x)                (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< TRNG0_PKRCNT32.PKR_3_CT Field           */
/* ------- PKRCNT54 Bit Fields                      ------ */
#define TRNG_PKRCNT54_PKR_4_CT_MASK              (0xFFFFU)                                           /*!< TRNG0_PKRCNT54.PKR_4_CT Mask            */
#define TRNG_PKRCNT54_PKR_4_CT_SHIFT             (0U)                                                /*!< TRNG0_PKRCNT54.PKR_4_CT Position        */
#define TRNG_PKRCNT54_PKR_4_CT(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< TRNG0_PKRCNT54.PKR_4_CT Field           */
#define TRNG_PKRCNT54_PKR_5_CT_MASK              (0xFFFF0000U)                                       /*!< TRNG0_PKRCNT54.PKR_5_CT Mask            */
#define TRNG_PKRCNT54_PKR_5_CT_SHIFT             (16U)                                               /*!< TRNG0_PKRCNT54.PKR_5_CT Position        */
#define TRNG_PKRCNT54_PKR_5_CT(x)                (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< TRNG0_PKRCNT54.PKR_5_CT Field           */
/* ------- PKRCNT76 Bit Fields                      ------ */
#define TRNG_PKRCNT76_PKR_6_CT_MASK              (0xFFFFU)                                           /*!< TRNG0_PKRCNT76.PKR_6_CT Mask            */
#define TRNG_PKRCNT76_PKR_6_CT_SHIFT             (0U)                                                /*!< TRNG0_PKRCNT76.PKR_6_CT Position        */
#define TRNG_PKRCNT76_PKR_6_CT(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< TRNG0_PKRCNT76.PKR_6_CT Field           */
#define TRNG_PKRCNT76_PKR_7_CT_MASK              (0xFFFF0000U)                                       /*!< TRNG0_PKRCNT76.PKR_7_CT Mask            */
#define TRNG_PKRCNT76_PKR_7_CT_SHIFT             (16U)                                               /*!< TRNG0_PKRCNT76.PKR_7_CT Position        */
#define TRNG_PKRCNT76_PKR_7_CT(x)                (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< TRNG0_PKRCNT76.PKR_7_CT Field           */
/* ------- PKRCNT98 Bit Fields                      ------ */
#define TRNG_PKRCNT98_PKR_8_CT_MASK              (0xFFFFU)                                           /*!< TRNG0_PKRCNT98.PKR_8_CT Mask            */
#define TRNG_PKRCNT98_PKR_8_CT_SHIFT             (0U)                                                /*!< TRNG0_PKRCNT98.PKR_8_CT Position        */
#define TRNG_PKRCNT98_PKR_8_CT(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< TRNG0_PKRCNT98.PKR_8_CT Field           */
#define TRNG_PKRCNT98_PKR_9_CT_MASK              (0xFFFF0000U)                                       /*!< TRNG0_PKRCNT98.PKR_9_CT Mask            */
#define TRNG_PKRCNT98_PKR_9_CT_SHIFT             (16U)                                               /*!< TRNG0_PKRCNT98.PKR_9_CT Position        */
#define TRNG_PKRCNT98_PKR_9_CT(x)                (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< TRNG0_PKRCNT98.PKR_9_CT Field           */
/* ------- PKRCNTBA Bit Fields                      ------ */
#define TRNG_PKRCNTBA_PKR_A_CT_MASK              (0xFFFFU)                                           /*!< TRNG0_PKRCNTBA.PKR_A_CT Mask            */
#define TRNG_PKRCNTBA_PKR_A_CT_SHIFT             (0U)                                                /*!< TRNG0_PKRCNTBA.PKR_A_CT Position        */
#define TRNG_PKRCNTBA_PKR_A_CT(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< TRNG0_PKRCNTBA.PKR_A_CT Field           */
#define TRNG_PKRCNTBA_PKR_B_CT_MASK              (0xFFFF0000U)                                       /*!< TRNG0_PKRCNTBA.PKR_B_CT Mask            */
#define TRNG_PKRCNTBA_PKR_B_CT_SHIFT             (16U)                                               /*!< TRNG0_PKRCNTBA.PKR_B_CT Position        */
#define TRNG_PKRCNTBA_PKR_B_CT(x)                (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< TRNG0_PKRCNTBA.PKR_B_CT Field           */
/* ------- PKRCNTDC Bit Fields                      ------ */
#define TRNG_PKRCNTDC_PKR_C_CT_MASK              (0xFFFFU)                                           /*!< TRNG0_PKRCNTDC.PKR_C_CT Mask            */
#define TRNG_PKRCNTDC_PKR_C_CT_SHIFT             (0U)                                                /*!< TRNG0_PKRCNTDC.PKR_C_CT Position        */
#define TRNG_PKRCNTDC_PKR_C_CT(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< TRNG0_PKRCNTDC.PKR_C_CT Field           */
#define TRNG_PKRCNTDC_PKR_D_CT_MASK              (0xFFFF0000U)                                       /*!< TRNG0_PKRCNTDC.PKR_D_CT Mask            */
#define TRNG_PKRCNTDC_PKR_D_CT_SHIFT             (16U)                                               /*!< TRNG0_PKRCNTDC.PKR_D_CT Position        */
#define TRNG_PKRCNTDC_PKR_D_CT(x)                (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< TRNG0_PKRCNTDC.PKR_D_CT Field           */
/* ------- PKRCNTFE Bit Fields                      ------ */
#define TRNG_PKRCNTFE_PKR_E_CT_MASK              (0xFFFFU)                                           /*!< TRNG0_PKRCNTFE.PKR_E_CT Mask            */
#define TRNG_PKRCNTFE_PKR_E_CT_SHIFT             (0U)                                                /*!< TRNG0_PKRCNTFE.PKR_E_CT Position        */
#define TRNG_PKRCNTFE_PKR_E_CT(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< TRNG0_PKRCNTFE.PKR_E_CT Field           */
#define TRNG_PKRCNTFE_PKR_F_CT_MASK              (0xFFFF0000U)                                       /*!< TRNG0_PKRCNTFE.PKR_F_CT Mask            */
#define TRNG_PKRCNTFE_PKR_F_CT_SHIFT             (16U)                                               /*!< TRNG0_PKRCNTFE.PKR_F_CT Position        */
#define TRNG_PKRCNTFE_PKR_F_CT(x)                (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< TRNG0_PKRCNTFE.PKR_F_CT Field           */
/* ------- SEC_CFG Bit Fields                       ------ */
#define TRNG_SEC_CFG_SH0_MASK                    (0x1U)                                              /*!< TRNG0_SEC_CFG.SH0 Mask                  */
#define TRNG_SEC_CFG_SH0_SHIFT                   (0U)                                                /*!< TRNG0_SEC_CFG.SH0 Position              */
#define TRNG_SEC_CFG_SH0(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< TRNG0_SEC_CFG.SH0 Field                 */
#define TRNG_SEC_CFG_NO_PRGM_MASK                (0x2U)                                              /*!< TRNG0_SEC_CFG.NO_PRGM Mask              */
#define TRNG_SEC_CFG_NO_PRGM_SHIFT               (1U)                                                /*!< TRNG0_SEC_CFG.NO_PRGM Position          */
#define TRNG_SEC_CFG_NO_PRGM(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< TRNG0_SEC_CFG.NO_PRGM Field             */
#define TRNG_SEC_CFG_SK_VAL_MASK                 (0x4U)                                              /*!< TRNG0_SEC_CFG.SK_VAL Mask               */
#define TRNG_SEC_CFG_SK_VAL_SHIFT                (2U)                                                /*!< TRNG0_SEC_CFG.SK_VAL Position           */
#define TRNG_SEC_CFG_SK_VAL(x)                   (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< TRNG0_SEC_CFG.SK_VAL Field              */
/* ------- INT_CTRL Bit Fields                      ------ */
#define TRNG_INT_CTRL_HW_ERR_MASK                (0x1U)                                              /*!< TRNG0_INT_CTRL.HW_ERR Mask              */
#define TRNG_INT_CTRL_HW_ERR_SHIFT               (0U)                                                /*!< TRNG0_INT_CTRL.HW_ERR Position          */
#define TRNG_INT_CTRL_HW_ERR(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< TRNG0_INT_CTRL.HW_ERR Field             */
#define TRNG_INT_CTRL_ENT_VAL_MASK               (0x2U)                                              /*!< TRNG0_INT_CTRL.ENT_VAL Mask             */
#define TRNG_INT_CTRL_ENT_VAL_SHIFT              (1U)                                                /*!< TRNG0_INT_CTRL.ENT_VAL Position         */
#define TRNG_INT_CTRL_ENT_VAL(x)                 (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< TRNG0_INT_CTRL.ENT_VAL Field            */
#define TRNG_INT_CTRL_FRQ_CT_FAIL_MASK           (0x4U)                                              /*!< TRNG0_INT_CTRL.FRQ_CT_FAIL Mask         */
#define TRNG_INT_CTRL_FRQ_CT_FAIL_SHIFT          (2U)                                                /*!< TRNG0_INT_CTRL.FRQ_CT_FAIL Position     */
#define TRNG_INT_CTRL_FRQ_CT_FAIL(x)             (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< TRNG0_INT_CTRL.FRQ_CT_FAIL Field        */
#define TRNG_INT_CTRL_UNUSED_MASK                (0xFFFFFFF8U)                                       /*!< TRNG0_INT_CTRL.UNUSED Mask              */
#define TRNG_INT_CTRL_UNUSED_SHIFT               (3U)                                                /*!< TRNG0_INT_CTRL.UNUSED Position          */
#define TRNG_INT_CTRL_UNUSED(x)                  (((uint32_t)(((uint32_t)(x))<<3U))&0xFFFFFFF8UL)    /*!< TRNG0_INT_CTRL.UNUSED Field             */
/* ------- INT_MASK Bit Fields                      ------ */
#define TRNG_INT_MASK_HW_ERR_MASK                (0x1U)                                              /*!< TRNG0_INT_MASK.HW_ERR Mask              */
#define TRNG_INT_MASK_HW_ERR_SHIFT               (0U)                                                /*!< TRNG0_INT_MASK.HW_ERR Position          */
#define TRNG_INT_MASK_HW_ERR(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< TRNG0_INT_MASK.HW_ERR Field             */
#define TRNG_INT_MASK_ENT_VAL_MASK               (0x2U)                                              /*!< TRNG0_INT_MASK.ENT_VAL Mask             */
#define TRNG_INT_MASK_ENT_VAL_SHIFT              (1U)                                                /*!< TRNG0_INT_MASK.ENT_VAL Position         */
#define TRNG_INT_MASK_ENT_VAL(x)                 (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< TRNG0_INT_MASK.ENT_VAL Field            */
#define TRNG_INT_MASK_FRQ_CT_FAIL_MASK           (0x4U)                                              /*!< TRNG0_INT_MASK.FRQ_CT_FAIL Mask         */
#define TRNG_INT_MASK_FRQ_CT_FAIL_SHIFT          (2U)                                                /*!< TRNG0_INT_MASK.FRQ_CT_FAIL Position     */
#define TRNG_INT_MASK_FRQ_CT_FAIL(x)             (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< TRNG0_INT_MASK.FRQ_CT_FAIL Field        */
/* ------- INT_STATUS Bit Fields                    ------ */
#define TRNG_INT_STATUS_HW_ERR_MASK              (0x1U)                                              /*!< TRNG0_INT_STATUS.HW_ERR Mask            */
#define TRNG_INT_STATUS_HW_ERR_SHIFT             (0U)                                                /*!< TRNG0_INT_STATUS.HW_ERR Position        */
#define TRNG_INT_STATUS_HW_ERR(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< TRNG0_INT_STATUS.HW_ERR Field           */
#define TRNG_INT_STATUS_ENT_VAL_MASK             (0x2U)                                              /*!< TRNG0_INT_STATUS.ENT_VAL Mask           */
#define TRNG_INT_STATUS_ENT_VAL_SHIFT            (1U)                                                /*!< TRNG0_INT_STATUS.ENT_VAL Position       */
#define TRNG_INT_STATUS_ENT_VAL(x)               (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< TRNG0_INT_STATUS.ENT_VAL Field          */
#define TRNG_INT_STATUS_FRQ_CT_FAIL_MASK         (0x4U)                                              /*!< TRNG0_INT_STATUS.FRQ_CT_FAIL Mask       */
#define TRNG_INT_STATUS_FRQ_CT_FAIL_SHIFT        (2U)                                                /*!< TRNG0_INT_STATUS.FRQ_CT_FAIL Position   */
#define TRNG_INT_STATUS_FRQ_CT_FAIL(x)           (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< TRNG0_INT_STATUS.FRQ_CT_FAIL Field      */
/* ------- VID1 Bit Fields                          ------ */
#define TRNG_VID1_RNG_MIN_REV_MASK               (0xFFU)                                             /*!< TRNG0_VID1.RNG_MIN_REV Mask             */
#define TRNG_VID1_RNG_MIN_REV_SHIFT              (0U)                                                /*!< TRNG0_VID1.RNG_MIN_REV Position         */
#define TRNG_VID1_RNG_MIN_REV(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< TRNG0_VID1.RNG_MIN_REV Field            */
#define TRNG_VID1_RNG_MAJ_REV_MASK               (0xFF00U)                                           /*!< TRNG0_VID1.RNG_MAJ_REV Mask             */
#define TRNG_VID1_RNG_MAJ_REV_SHIFT              (8U)                                                /*!< TRNG0_VID1.RNG_MAJ_REV Position         */
#define TRNG_VID1_RNG_MAJ_REV(x)                 (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< TRNG0_VID1.RNG_MAJ_REV Field            */
#define TRNG_VID1_RNG_IP_ID_MASK                 (0xFFFF0000U)                                       /*!< TRNG0_VID1.RNG_IP_ID Mask               */
#define TRNG_VID1_RNG_IP_ID_SHIFT                (16U)                                               /*!< TRNG0_VID1.RNG_IP_ID Position           */
#define TRNG_VID1_RNG_IP_ID(x)                   (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< TRNG0_VID1.RNG_IP_ID Field              */
/* ------- VID2 Bit Fields                          ------ */
#define TRNG_VID2_RNG_CONFIG_OPT_MASK            (0xFFU)                                             /*!< TRNG0_VID2.RNG_CONFIG_OPT Mask          */
#define TRNG_VID2_RNG_CONFIG_OPT_SHIFT           (0U)                                                /*!< TRNG0_VID2.RNG_CONFIG_OPT Position      */
#define TRNG_VID2_RNG_CONFIG_OPT(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< TRNG0_VID2.RNG_CONFIG_OPT Field         */
#define TRNG_VID2_RNG_ECO_REV_MASK               (0xFF00U)                                           /*!< TRNG0_VID2.RNG_ECO_REV Mask             */
#define TRNG_VID2_RNG_ECO_REV_SHIFT              (8U)                                                /*!< TRNG0_VID2.RNG_ECO_REV Position         */
#define TRNG_VID2_RNG_ECO_REV(x)                 (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< TRNG0_VID2.RNG_ECO_REV Field            */
#define TRNG_VID2_RNG_INTG_OPT_MASK              (0xFF0000U)                                         /*!< TRNG0_VID2.RNG_INTG_OPT Mask            */
#define TRNG_VID2_RNG_INTG_OPT_SHIFT             (16U)                                               /*!< TRNG0_VID2.RNG_INTG_OPT Position        */
#define TRNG_VID2_RNG_INTG_OPT(x)                (((uint32_t)(((uint32_t)(x))<<16U))&0xFF0000UL)     /*!< TRNG0_VID2.RNG_INTG_OPT Field           */
#define TRNG_VID2_RNG_ERA_MASK                   (0xFF000000U)                                       /*!< TRNG0_VID2.RNG_ERA Mask                 */
#define TRNG_VID2_RNG_ERA_SHIFT                  (24U)                                               /*!< TRNG0_VID2.RNG_ERA Position             */
#define TRNG_VID2_RNG_ERA(x)                     (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< TRNG0_VID2.RNG_ERA Field                */
/**
 * @} */ /* End group TRNG_Register_Masks_GROUP 
 */

/* TRNG0 - Peripheral instance base addresses */
#define TRNG0_BasePtr                  0x40025000UL //!< Peripheral base address
#define TRNG0                          ((TRNG_Type *) TRNG0_BasePtr) //!< Freescale base pointer
#define TRNG0_BASE_PTR                 (TRNG0) //!< Freescale style base pointer
/**
 * @} */ /* End group TRNG_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup TSI_Peripheral_access_layer_GROUP TSI Peripheral Access Layer
* @brief C Struct for TSI
* @{
*/

/* ================================================================================ */
/* ================           TSI0 (file:TSI0_MK65)                ================ */
/* ================================================================================ */

/**
 * @brief Touch Sensing Input
 */
/**
* @addtogroup TSI_structs_GROUP TSI struct
* @brief Struct for TSI
* @{
*/
typedef struct {                                /*       TSI0 Structure                                               */
   __IO uint32_t  GENCS;                        /**< 0000: TSI General Control and Status Register                      */
   __IO uint32_t  DATA;                         /**< 0004: TSI DATA Register                                            */
   __IO uint32_t  TSHD;                         /**< 0008: TSI Threshold Register                                       */
} TSI_Type;

/**
 * @} */ /* End group TSI_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'TSI0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup TSI_Register_Masks_GROUP TSI Register Masks
* @brief Register Masks for TSI
* @{
*/
/* ------- GENCS Bit Fields                         ------ */
#define TSI_GENCS_EOSDMEO_MASK                   (0x1U)                                              /*!< TSI0_GENCS.EOSDMEO Mask                 */
#define TSI_GENCS_EOSDMEO_SHIFT                  (0U)                                                /*!< TSI0_GENCS.EOSDMEO Position             */
#define TSI_GENCS_EOSDMEO(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< TSI0_GENCS.EOSDMEO Field                */
#define TSI_GENCS_CURSW_MASK                     (0x2U)                                              /*!< TSI0_GENCS.CURSW Mask                   */
#define TSI_GENCS_CURSW_SHIFT                    (1U)                                                /*!< TSI0_GENCS.CURSW Position               */
#define TSI_GENCS_CURSW(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< TSI0_GENCS.CURSW Field                  */
#define TSI_GENCS_EOSF_MASK                      (0x4U)                                              /*!< TSI0_GENCS.EOSF Mask                    */
#define TSI_GENCS_EOSF_SHIFT                     (2U)                                                /*!< TSI0_GENCS.EOSF Position                */
#define TSI_GENCS_EOSF(x)                        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< TSI0_GENCS.EOSF Field                   */
#define TSI_GENCS_SCNIP_MASK                     (0x8U)                                              /*!< TSI0_GENCS.SCNIP Mask                   */
#define TSI_GENCS_SCNIP_SHIFT                    (3U)                                                /*!< TSI0_GENCS.SCNIP Position               */
#define TSI_GENCS_SCNIP(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< TSI0_GENCS.SCNIP Field                  */
#define TSI_GENCS_STM_MASK                       (0x10U)                                             /*!< TSI0_GENCS.STM Mask                     */
#define TSI_GENCS_STM_SHIFT                      (4U)                                                /*!< TSI0_GENCS.STM Position                 */
#define TSI_GENCS_STM(x)                         (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< TSI0_GENCS.STM Field                    */
#define TSI_GENCS_STPE_MASK                      (0x20U)                                             /*!< TSI0_GENCS.STPE Mask                    */
#define TSI_GENCS_STPE_SHIFT                     (5U)                                                /*!< TSI0_GENCS.STPE Position                */
#define TSI_GENCS_STPE(x)                        (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< TSI0_GENCS.STPE Field                   */
#define TSI_GENCS_TSIIEN_MASK                    (0x40U)                                             /*!< TSI0_GENCS.TSIIEN Mask                  */
#define TSI_GENCS_TSIIEN_SHIFT                   (6U)                                                /*!< TSI0_GENCS.TSIIEN Position              */
#define TSI_GENCS_TSIIEN(x)                      (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< TSI0_GENCS.TSIIEN Field                 */
#define TSI_GENCS_TSIEN_MASK                     (0x80U)                                             /*!< TSI0_GENCS.TSIEN Mask                   */
#define TSI_GENCS_TSIEN_SHIFT                    (7U)                                                /*!< TSI0_GENCS.TSIEN Position               */
#define TSI_GENCS_TSIEN(x)                       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< TSI0_GENCS.TSIEN Field                  */
#define TSI_GENCS_NSCN_MASK                      (0x1F00U)                                           /*!< TSI0_GENCS.NSCN Mask                    */
#define TSI_GENCS_NSCN_SHIFT                     (8U)                                                /*!< TSI0_GENCS.NSCN Position                */
#define TSI_GENCS_NSCN(x)                        (((uint32_t)(((uint32_t)(x))<<8U))&0x1F00UL)        /*!< TSI0_GENCS.NSCN Field                   */
#define TSI_GENCS_PS_MASK                        (0xE000U)                                           /*!< TSI0_GENCS.PS Mask                      */
#define TSI_GENCS_PS_SHIFT                       (13U)                                               /*!< TSI0_GENCS.PS Position                  */
#define TSI_GENCS_PS(x)                          (((uint32_t)(((uint32_t)(x))<<13U))&0xE000UL)       /*!< TSI0_GENCS.PS Field                     */
#define TSI_GENCS_EXTCHRG_MASK                   (0x70000U)                                          /*!< TSI0_GENCS.EXTCHRG Mask                 */
#define TSI_GENCS_EXTCHRG_SHIFT                  (16U)                                               /*!< TSI0_GENCS.EXTCHRG Position             */
#define TSI_GENCS_EXTCHRG(x)                     (((uint32_t)(((uint32_t)(x))<<16U))&0x70000UL)      /*!< TSI0_GENCS.EXTCHRG Field                */
#define TSI_GENCS_DVOLT_MASK                     (0x180000U)                                         /*!< TSI0_GENCS.DVOLT Mask                   */
#define TSI_GENCS_DVOLT_SHIFT                    (19U)                                               /*!< TSI0_GENCS.DVOLT Position               */
#define TSI_GENCS_DVOLT(x)                       (((uint32_t)(((uint32_t)(x))<<19U))&0x180000UL)     /*!< TSI0_GENCS.DVOLT Field                  */
#define TSI_GENCS_REFCHRG_MASK                   (0xE00000U)                                         /*!< TSI0_GENCS.REFCHRG Mask                 */
#define TSI_GENCS_REFCHRG_SHIFT                  (21U)                                               /*!< TSI0_GENCS.REFCHRG Position             */
#define TSI_GENCS_REFCHRG(x)                     (((uint32_t)(((uint32_t)(x))<<21U))&0xE00000UL)     /*!< TSI0_GENCS.REFCHRG Field                */
#define TSI_GENCS_MODE_MASK                      (0xF000000U)                                        /*!< TSI0_GENCS.MODE Mask                    */
#define TSI_GENCS_MODE_SHIFT                     (24U)                                               /*!< TSI0_GENCS.MODE Position                */
#define TSI_GENCS_MODE(x)                        (((uint32_t)(((uint32_t)(x))<<24U))&0xF000000UL)    /*!< TSI0_GENCS.MODE Field                   */
#define TSI_GENCS_ESOR_MASK                      (0x10000000U)                                       /*!< TSI0_GENCS.ESOR Mask                    */
#define TSI_GENCS_ESOR_SHIFT                     (28U)                                               /*!< TSI0_GENCS.ESOR Position                */
#define TSI_GENCS_ESOR(x)                        (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< TSI0_GENCS.ESOR Field                   */
#define TSI_GENCS_OUTRGF_MASK                    (0x80000000U)                                       /*!< TSI0_GENCS.OUTRGF Mask                  */
#define TSI_GENCS_OUTRGF_SHIFT                   (31U)                                               /*!< TSI0_GENCS.OUTRGF Position              */
#define TSI_GENCS_OUTRGF(x)                      (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< TSI0_GENCS.OUTRGF Field                 */
/* ------- DATA Bit Fields                          ------ */
#define TSI_DATA_TSICNT_MASK                     (0xFFFFU)                                           /*!< TSI0_DATA.TSICNT Mask                   */
#define TSI_DATA_TSICNT_SHIFT                    (0U)                                                /*!< TSI0_DATA.TSICNT Position               */
#define TSI_DATA_TSICNT(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< TSI0_DATA.TSICNT Field                  */
#define TSI_DATA_SWTS_MASK                       (0x400000U)                                         /*!< TSI0_DATA.SWTS Mask                     */
#define TSI_DATA_SWTS_SHIFT                      (22U)                                               /*!< TSI0_DATA.SWTS Position                 */
#define TSI_DATA_SWTS(x)                         (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< TSI0_DATA.SWTS Field                    */
#define TSI_DATA_DMAEN_MASK                      (0x800000U)                                         /*!< TSI0_DATA.DMAEN Mask                    */
#define TSI_DATA_DMAEN_SHIFT                     (23U)                                               /*!< TSI0_DATA.DMAEN Position                */
#define TSI_DATA_DMAEN(x)                        (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< TSI0_DATA.DMAEN Field                   */
#define TSI_DATA_TSICH_MASK                      (0xF0000000U)                                       /*!< TSI0_DATA.TSICH Mask                    */
#define TSI_DATA_TSICH_SHIFT                     (28U)                                               /*!< TSI0_DATA.TSICH Position                */
#define TSI_DATA_TSICH(x)                        (((uint32_t)(((uint32_t)(x))<<28U))&0xF0000000UL)   /*!< TSI0_DATA.TSICH Field                   */
/* ------- TSHD Bit Fields                          ------ */
#define TSI_TSHD_THRESL_MASK                     (0xFFFFU)                                           /*!< TSI0_TSHD.THRESL Mask                   */
#define TSI_TSHD_THRESL_SHIFT                    (0U)                                                /*!< TSI0_TSHD.THRESL Position               */
#define TSI_TSHD_THRESL(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< TSI0_TSHD.THRESL Field                  */
#define TSI_TSHD_THRESH_MASK                     (0xFFFF0000U)                                       /*!< TSI0_TSHD.THRESH Mask                   */
#define TSI_TSHD_THRESH_SHIFT                    (16U)                                               /*!< TSI0_TSHD.THRESH Position               */
#define TSI_TSHD_THRESH(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< TSI0_TSHD.THRESH Field                  */
/**
 * @} */ /* End group TSI_Register_Masks_GROUP 
 */

/* TSI0 - Peripheral instance base addresses */
#define TSI0_BasePtr                   0x40045000UL //!< Peripheral base address
#define TSI0                           ((TSI_Type *) TSI0_BasePtr) //!< Freescale base pointer
#define TSI0_BASE_PTR                  (TSI0) //!< Freescale style base pointer
/**
 * @} */ /* End group TSI_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup USB_Peripheral_access_layer_GROUP USB Peripheral Access Layer
* @brief C Struct for USB
* @{
*/

/* ================================================================================ */
/* ================           USB0 (file:USB0_MKL82Z7)             ================ */
/* ================================================================================ */

/**
 * @brief Universal Serial Bus, OTG Capable Controller
 */
/**
* @addtogroup USB_structs_GROUP USB struct
* @brief Struct for USB
* @{
*/
typedef struct {                                /*       USB0 Structure                                               */
   __I  uint8_t   PERID;                        /**< 0000: Peripheral ID register                                       */
        uint8_t   RESERVED_0[3];               
   __I  uint8_t   IDCOMP;                       /**< 0004: Peripheral ID Complement register                            */
        uint8_t   RESERVED_1[3];               
   __I  uint8_t   REV;                          /**< 0008: Peripheral Revision register                                 */
        uint8_t   RESERVED_2[3];               
   __I  uint8_t   ADDINFO;                      /**< 000C: Peripheral Additional Info register                          */
        uint8_t   RESERVED_3[3];               
   __IO uint8_t   OTGISTAT;                     /**< 0010: OTG Interrupt Status Register                                */
        uint8_t   RESERVED_4[3];               
   __IO uint8_t   OTGICR;                       /**< 0014: OTG Interrupt Control Register                               */
        uint8_t   RESERVED_5[3];               
   __IO uint8_t   OTGSTAT;                      /**< 0018: OTG Status register                                          */
        uint8_t   RESERVED_6[3];               
   __IO uint8_t   OTGCTL;                       /**< 001C: OTG Control register                                         */
        uint8_t   RESERVED_7[99];              
   __IO uint8_t   ISTAT;                        /**< 0080: Interrupt Status Register                                    */
        uint8_t   RESERVED_8[3];               
   __IO uint8_t   INTEN;                        /**< 0084: Interrupt Enable Register                                    */
        uint8_t   RESERVED_9[3];               
   __IO uint8_t   ERRSTAT;                      /**< 0088: Error Interrupt Status Register                              */
        uint8_t   RESERVED_10[3];              
   __IO uint8_t   ERREN;                        /**< 008C: Error Interrupt Enable register                              */
        uint8_t   RESERVED_11[3];              
   __I  uint8_t   STAT;                         /**< 0090: Status register                                              */
        uint8_t   RESERVED_12[3];              
   __IO uint8_t   CTL;                          /**< 0094: Control Register                                             */
        uint8_t   RESERVED_13[3];              
   __IO uint8_t   ADDR;                         /**< 0098: Address register                                             */
        uint8_t   RESERVED_14[3];              
   __IO uint8_t   BDTPAGE1;                     /**< 009C: BDT Page Register 1                                          */
        uint8_t   RESERVED_15[3];              
   __IO uint8_t   FRMNUML;                      /**< 00A0: Frame Number register Low                                    */
        uint8_t   RESERVED_16[3];              
   __IO uint8_t   FRMNUMH;                      /**< 00A4: Frame Number register High                                   */
        uint8_t   RESERVED_17[3];              
   __IO uint8_t   TOKEN;                        /**< 00A8: Token Register                                               */
        uint8_t   RESERVED_18[3];              
   __IO uint8_t   SOFTHLD;                      /**< 00AC: SOF Threshold register                                       */
        uint8_t   RESERVED_19[3];              
   __IO uint8_t   BDTPAGE2;                     /**< 00B0: BDT Page Register 2                                          */
        uint8_t   RESERVED_20[3];              
   __IO uint8_t   BDTPAGE3;                     /**< 00B4: BDT Page Register 3                                          */
        uint8_t   RESERVED_21[11];             
   struct {
      __IO uint8_t   ENDPT;                     /**< 00C0: Endpoint Control register                                    */
           uint8_t   RESERVED_22[3];           
   } ENDPOINT[16];                              /**< 00C0: (cluster: size=0x0040, 64)                                   */
   __IO uint8_t   USBCTRL;                      /**< 0100: USB Control register                                         */
        uint8_t   RESERVED_23[3];              
   __I  uint8_t   OBSERVE;                      /**< 0104: USB OTG Observe Register                                     */
        uint8_t   RESERVED_24[3];              
   __IO uint8_t   CONTROL;                      /**< 0108: USB OTG Control register                                     */
        uint8_t   RESERVED_25[3];              
   __IO uint8_t   USBTRC0;                      /**< 010C: USB Transceiver Control Register 0                           */
        uint8_t   RESERVED_26[7];              
   __IO uint8_t   USBFRMADJUST;                 /**< 0114: Frame Adjust Register                                        */
        uint8_t   RESERVED_27[15];             
   __IO uint8_t   KEEP_ALIVE_CTRL;              /**< 0124: Keep Alive mode control                                      */
        uint8_t   RESERVED_28[3];              
   __IO uint8_t   KEEP_ALIVE_WKCTRL;            /**< 0128: Keep Alive mode wakeup control                               */
        uint8_t   RESERVED_29[3];              
   __IO uint8_t   MISCCTRL;                     /**< 012C: Miscellaneous Control register                               */
        uint8_t   RESERVED_30[3];              
   __IO uint8_t   STALL_IL_DIS;                 /**< 0130: Peripheral mode stall disable for endpoints 7 to 0 in IN direction */
        uint8_t   RESERVED_31[3];              
   __IO uint8_t   STALL_IH_DIS;                 /**< 0134: Peripheral mode stall disable for endpoints 15 to 8 in IN direction */
        uint8_t   RESERVED_32[3];              
   __IO uint8_t   STALL_OL_DIS;                 /**< 0138: Peripheral mode stall disable for endpoints 7 to 0 in OUT direction */
        uint8_t   RESERVED_33[3];              
   __IO uint8_t   STALL_OH_DIS;                 /**< 013C: Peripheral mode stall disable for endpoints 15 to 8 in OUT direction */
        uint8_t   RESERVED_34[3];              
   __IO uint8_t   CLK_RECOVER_CTRL;             /**< 0140: USB Clock recovery control                                   */
        uint8_t   RESERVED_35[3];              
   __IO uint8_t   CLK_RECOVER_IRC_EN;           /**< 0144: IRC48M oscillator enable register                            */
        uint8_t   RESERVED_36[15];             
   __IO uint8_t   CLK_RECOVER_INT_EN;           /**< 0154: Clock recovery combined interrupt enable                     */
        uint8_t   RESERVED_37[7];              
   __IO uint8_t   CLK_RECOVER_INT_STATUS;       /**< 015C: Clock recovery separated interrupt status                    */
} USB_Type;

/**
 * @} */ /* End group USB_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'USB0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup USB_Register_Masks_GROUP USB Register Masks
* @brief Register Masks for USB
* @{
*/
/* ------- PERID Bit Fields                         ------ */
#define USB_PERID_ID_MASK                        (0x3FU)                                             /*!< USB0_PERID.ID Mask                      */
#define USB_PERID_ID_SHIFT                       (0U)                                                /*!< USB0_PERID.ID Position                  */
#define USB_PERID_ID(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x3FUL)            /*!< USB0_PERID.ID Field                     */
/* ------- IDCOMP Bit Fields                        ------ */
#define USB_IDCOMP_NID_MASK                      (0x3FU)                                             /*!< USB0_IDCOMP.NID Mask                    */
#define USB_IDCOMP_NID_SHIFT                     (0U)                                                /*!< USB0_IDCOMP.NID Position                */
#define USB_IDCOMP_NID(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x3FUL)            /*!< USB0_IDCOMP.NID Field                   */
/* ------- REV Bit Fields                           ------ */
#define USB_REV_REV_MASK                         (0xFFU)                                             /*!< USB0_REV.REV Mask                       */
#define USB_REV_REV_SHIFT                        (0U)                                                /*!< USB0_REV.REV Position                   */
#define USB_REV_REV(x)                           (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< USB0_REV.REV Field                      */
/* ------- ADDINFO Bit Fields                       ------ */
#define USB_ADDINFO_IEHOST_MASK                  (0x1U)                                              /*!< USB0_ADDINFO.IEHOST Mask                */
#define USB_ADDINFO_IEHOST_SHIFT                 (0U)                                                /*!< USB0_ADDINFO.IEHOST Position            */
#define USB_ADDINFO_IEHOST(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_ADDINFO.IEHOST Field               */
/* ------- OTGISTAT Bit Fields                      ------ */
#define USB_OTGISTAT_LINE_STATE_CHG_MASK         (0x20U)                                             /*!< USB0_OTGISTAT.LINE_STATE_CHG Mask       */
#define USB_OTGISTAT_LINE_STATE_CHG_SHIFT        (5U)                                                /*!< USB0_OTGISTAT.LINE_STATE_CHG Position   */
#define USB_OTGISTAT_LINE_STATE_CHG(x)           (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_OTGISTAT.LINE_STATE_CHG Field      */
#define USB_OTGISTAT_ONEMSEC_MASK                (0x40U)                                             /*!< USB0_OTGISTAT.ONEMSEC Mask              */
#define USB_OTGISTAT_ONEMSEC_SHIFT               (6U)                                                /*!< USB0_OTGISTAT.ONEMSEC Position          */
#define USB_OTGISTAT_ONEMSEC(x)                  (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_OTGISTAT.ONEMSEC Field             */
/* ------- OTGICR Bit Fields                        ------ */
#define USB_OTGICR_LINESTATEEN_MASK              (0x20U)                                             /*!< USB0_OTGICR.LINESTATEEN Mask            */
#define USB_OTGICR_LINESTATEEN_SHIFT             (5U)                                                /*!< USB0_OTGICR.LINESTATEEN Position        */
#define USB_OTGICR_LINESTATEEN(x)                (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_OTGICR.LINESTATEEN Field           */
#define USB_OTGICR_ONEMSECEN_MASK                (0x40U)                                             /*!< USB0_OTGICR.ONEMSECEN Mask              */
#define USB_OTGICR_ONEMSECEN_SHIFT               (6U)                                                /*!< USB0_OTGICR.ONEMSECEN Position          */
#define USB_OTGICR_ONEMSECEN(x)                  (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_OTGICR.ONEMSECEN Field             */
/* ------- OTGSTAT Bit Fields                       ------ */
#define USB_OTGSTAT_LINESTATESTABLE_MASK         (0x20U)                                             /*!< USB0_OTGSTAT.LINESTATESTABLE Mask       */
#define USB_OTGSTAT_LINESTATESTABLE_SHIFT        (5U)                                                /*!< USB0_OTGSTAT.LINESTATESTABLE Position   */
#define USB_OTGSTAT_LINESTATESTABLE(x)           (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_OTGSTAT.LINESTATESTABLE Field      */
#define USB_OTGSTAT_ONEMSECEN_MASK               (0x40U)                                             /*!< USB0_OTGSTAT.ONEMSECEN Mask             */
#define USB_OTGSTAT_ONEMSECEN_SHIFT              (6U)                                                /*!< USB0_OTGSTAT.ONEMSECEN Position         */
#define USB_OTGSTAT_ONEMSECEN(x)                 (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_OTGSTAT.ONEMSECEN Field            */
/* ------- OTGCTL Bit Fields                        ------ */
#define USB_OTGCTL_OTGEN_MASK                    (0x4U)                                              /*!< USB0_OTGCTL.OTGEN Mask                  */
#define USB_OTGCTL_OTGEN_SHIFT                   (2U)                                                /*!< USB0_OTGCTL.OTGEN Position              */
#define USB_OTGCTL_OTGEN(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_OTGCTL.OTGEN Field                 */
#define USB_OTGCTL_DMLOW_MASK                    (0x10U)                                             /*!< USB0_OTGCTL.DMLOW Mask                  */
#define USB_OTGCTL_DMLOW_SHIFT                   (4U)                                                /*!< USB0_OTGCTL.DMLOW Position              */
#define USB_OTGCTL_DMLOW(x)                      (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_OTGCTL.DMLOW Field                 */
#define USB_OTGCTL_DPLOW_MASK                    (0x20U)                                             /*!< USB0_OTGCTL.DPLOW Mask                  */
#define USB_OTGCTL_DPLOW_SHIFT                   (5U)                                                /*!< USB0_OTGCTL.DPLOW Position              */
#define USB_OTGCTL_DPLOW(x)                      (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_OTGCTL.DPLOW Field                 */
#define USB_OTGCTL_DPHIGH_MASK                   (0x80U)                                             /*!< USB0_OTGCTL.DPHIGH Mask                 */
#define USB_OTGCTL_DPHIGH_SHIFT                  (7U)                                                /*!< USB0_OTGCTL.DPHIGH Position             */
#define USB_OTGCTL_DPHIGH(x)                     (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_OTGCTL.DPHIGH Field                */
/* ------- ISTAT Bit Fields                         ------ */
#define USB_ISTAT_USBRST_MASK                    (0x1U)                                              /*!< USB0_ISTAT.USBRST Mask                  */
#define USB_ISTAT_USBRST_SHIFT                   (0U)                                                /*!< USB0_ISTAT.USBRST Position              */
#define USB_ISTAT_USBRST(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_ISTAT.USBRST Field                 */
#define USB_ISTAT_ERROR_MASK                     (0x2U)                                              /*!< USB0_ISTAT.ERROR Mask                   */
#define USB_ISTAT_ERROR_SHIFT                    (1U)                                                /*!< USB0_ISTAT.ERROR Position               */
#define USB_ISTAT_ERROR(x)                       (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_ISTAT.ERROR Field                  */
#define USB_ISTAT_SOFTOK_MASK                    (0x4U)                                              /*!< USB0_ISTAT.SOFTOK Mask                  */
#define USB_ISTAT_SOFTOK_SHIFT                   (2U)                                                /*!< USB0_ISTAT.SOFTOK Position              */
#define USB_ISTAT_SOFTOK(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_ISTAT.SOFTOK Field                 */
#define USB_ISTAT_TOKDNE_MASK                    (0x8U)                                              /*!< USB0_ISTAT.TOKDNE Mask                  */
#define USB_ISTAT_TOKDNE_SHIFT                   (3U)                                                /*!< USB0_ISTAT.TOKDNE Position              */
#define USB_ISTAT_TOKDNE(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_ISTAT.TOKDNE Field                 */
#define USB_ISTAT_SLEEP_MASK                     (0x10U)                                             /*!< USB0_ISTAT.SLEEP Mask                   */
#define USB_ISTAT_SLEEP_SHIFT                    (4U)                                                /*!< USB0_ISTAT.SLEEP Position               */
#define USB_ISTAT_SLEEP(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_ISTAT.SLEEP Field                  */
#define USB_ISTAT_RESUME_MASK                    (0x20U)                                             /*!< USB0_ISTAT.RESUME Mask                  */
#define USB_ISTAT_RESUME_SHIFT                   (5U)                                                /*!< USB0_ISTAT.RESUME Position              */
#define USB_ISTAT_RESUME(x)                      (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_ISTAT.RESUME Field                 */
#define USB_ISTAT_ATTACH_MASK                    (0x40U)                                             /*!< USB0_ISTAT.ATTACH Mask                  */
#define USB_ISTAT_ATTACH_SHIFT                   (6U)                                                /*!< USB0_ISTAT.ATTACH Position              */
#define USB_ISTAT_ATTACH(x)                      (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_ISTAT.ATTACH Field                 */
#define USB_ISTAT_STALL_MASK                     (0x80U)                                             /*!< USB0_ISTAT.STALL Mask                   */
#define USB_ISTAT_STALL_SHIFT                    (7U)                                                /*!< USB0_ISTAT.STALL Position               */
#define USB_ISTAT_STALL(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_ISTAT.STALL Field                  */
/* ------- INTEN Bit Fields                         ------ */
#define USB_INTEN_USBRSTEN_MASK                  (0x1U)                                              /*!< USB0_INTEN.USBRSTEN Mask                */
#define USB_INTEN_USBRSTEN_SHIFT                 (0U)                                                /*!< USB0_INTEN.USBRSTEN Position            */
#define USB_INTEN_USBRSTEN(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_INTEN.USBRSTEN Field               */
#define USB_INTEN_ERROREN_MASK                   (0x2U)                                              /*!< USB0_INTEN.ERROREN Mask                 */
#define USB_INTEN_ERROREN_SHIFT                  (1U)                                                /*!< USB0_INTEN.ERROREN Position             */
#define USB_INTEN_ERROREN(x)                     (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_INTEN.ERROREN Field                */
#define USB_INTEN_SOFTOKEN_MASK                  (0x4U)                                              /*!< USB0_INTEN.SOFTOKEN Mask                */
#define USB_INTEN_SOFTOKEN_SHIFT                 (2U)                                                /*!< USB0_INTEN.SOFTOKEN Position            */
#define USB_INTEN_SOFTOKEN(x)                    (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_INTEN.SOFTOKEN Field               */
#define USB_INTEN_TOKDNEEN_MASK                  (0x8U)                                              /*!< USB0_INTEN.TOKDNEEN Mask                */
#define USB_INTEN_TOKDNEEN_SHIFT                 (3U)                                                /*!< USB0_INTEN.TOKDNEEN Position            */
#define USB_INTEN_TOKDNEEN(x)                    (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_INTEN.TOKDNEEN Field               */
#define USB_INTEN_SLEEPEN_MASK                   (0x10U)                                             /*!< USB0_INTEN.SLEEPEN Mask                 */
#define USB_INTEN_SLEEPEN_SHIFT                  (4U)                                                /*!< USB0_INTEN.SLEEPEN Position             */
#define USB_INTEN_SLEEPEN(x)                     (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_INTEN.SLEEPEN Field                */
#define USB_INTEN_RESUMEEN_MASK                  (0x20U)                                             /*!< USB0_INTEN.RESUMEEN Mask                */
#define USB_INTEN_RESUMEEN_SHIFT                 (5U)                                                /*!< USB0_INTEN.RESUMEEN Position            */
#define USB_INTEN_RESUMEEN(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_INTEN.RESUMEEN Field               */
#define USB_INTEN_ATTACHEN_MASK                  (0x40U)                                             /*!< USB0_INTEN.ATTACHEN Mask                */
#define USB_INTEN_ATTACHEN_SHIFT                 (6U)                                                /*!< USB0_INTEN.ATTACHEN Position            */
#define USB_INTEN_ATTACHEN(x)                    (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_INTEN.ATTACHEN Field               */
#define USB_INTEN_STALLEN_MASK                   (0x80U)                                             /*!< USB0_INTEN.STALLEN Mask                 */
#define USB_INTEN_STALLEN_SHIFT                  (7U)                                                /*!< USB0_INTEN.STALLEN Position             */
#define USB_INTEN_STALLEN(x)                     (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_INTEN.STALLEN Field                */
/* ------- ERRSTAT Bit Fields                       ------ */
#define USB_ERRSTAT_PIDERR_MASK                  (0x1U)                                              /*!< USB0_ERRSTAT.PIDERR Mask                */
#define USB_ERRSTAT_PIDERR_SHIFT                 (0U)                                                /*!< USB0_ERRSTAT.PIDERR Position            */
#define USB_ERRSTAT_PIDERR(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_ERRSTAT.PIDERR Field               */
#define USB_ERRSTAT_CRC5EOF_MASK                 (0x2U)                                              /*!< USB0_ERRSTAT.CRC5EOF Mask               */
#define USB_ERRSTAT_CRC5EOF_SHIFT                (1U)                                                /*!< USB0_ERRSTAT.CRC5EOF Position           */
#define USB_ERRSTAT_CRC5EOF(x)                   (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_ERRSTAT.CRC5EOF Field              */
#define USB_ERRSTAT_CRC16_MASK                   (0x4U)                                              /*!< USB0_ERRSTAT.CRC16 Mask                 */
#define USB_ERRSTAT_CRC16_SHIFT                  (2U)                                                /*!< USB0_ERRSTAT.CRC16 Position             */
#define USB_ERRSTAT_CRC16(x)                     (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_ERRSTAT.CRC16 Field                */
#define USB_ERRSTAT_DFN8_MASK                    (0x8U)                                              /*!< USB0_ERRSTAT.DFN8 Mask                  */
#define USB_ERRSTAT_DFN8_SHIFT                   (3U)                                                /*!< USB0_ERRSTAT.DFN8 Position              */
#define USB_ERRSTAT_DFN8(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_ERRSTAT.DFN8 Field                 */
#define USB_ERRSTAT_BTOERR_MASK                  (0x10U)                                             /*!< USB0_ERRSTAT.BTOERR Mask                */
#define USB_ERRSTAT_BTOERR_SHIFT                 (4U)                                                /*!< USB0_ERRSTAT.BTOERR Position            */
#define USB_ERRSTAT_BTOERR(x)                    (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_ERRSTAT.BTOERR Field               */
#define USB_ERRSTAT_DMAERR_MASK                  (0x20U)                                             /*!< USB0_ERRSTAT.DMAERR Mask                */
#define USB_ERRSTAT_DMAERR_SHIFT                 (5U)                                                /*!< USB0_ERRSTAT.DMAERR Position            */
#define USB_ERRSTAT_DMAERR(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_ERRSTAT.DMAERR Field               */
#define USB_ERRSTAT_OWNERR_MASK                  (0x40U)                                             /*!< USB0_ERRSTAT.OWNERR Mask                */
#define USB_ERRSTAT_OWNERR_SHIFT                 (6U)                                                /*!< USB0_ERRSTAT.OWNERR Position            */
#define USB_ERRSTAT_OWNERR(x)                    (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_ERRSTAT.OWNERR Field               */
#define USB_ERRSTAT_BTSERR_MASK                  (0x80U)                                             /*!< USB0_ERRSTAT.BTSERR Mask                */
#define USB_ERRSTAT_BTSERR_SHIFT                 (7U)                                                /*!< USB0_ERRSTAT.BTSERR Position            */
#define USB_ERRSTAT_BTSERR(x)                    (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_ERRSTAT.BTSERR Field               */
/* ------- ERREN Bit Fields                         ------ */
#define USB_ERREN_PIDERREN_MASK                  (0x1U)                                              /*!< USB0_ERREN.PIDERREN Mask                */
#define USB_ERREN_PIDERREN_SHIFT                 (0U)                                                /*!< USB0_ERREN.PIDERREN Position            */
#define USB_ERREN_PIDERREN(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_ERREN.PIDERREN Field               */
#define USB_ERREN_CRC5EOFEN_MASK                 (0x2U)                                              /*!< USB0_ERREN.CRC5EOFEN Mask               */
#define USB_ERREN_CRC5EOFEN_SHIFT                (1U)                                                /*!< USB0_ERREN.CRC5EOFEN Position           */
#define USB_ERREN_CRC5EOFEN(x)                   (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_ERREN.CRC5EOFEN Field              */
#define USB_ERREN_CRC16EN_MASK                   (0x4U)                                              /*!< USB0_ERREN.CRC16EN Mask                 */
#define USB_ERREN_CRC16EN_SHIFT                  (2U)                                                /*!< USB0_ERREN.CRC16EN Position             */
#define USB_ERREN_CRC16EN(x)                     (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_ERREN.CRC16EN Field                */
#define USB_ERREN_DFN8EN_MASK                    (0x8U)                                              /*!< USB0_ERREN.DFN8EN Mask                  */
#define USB_ERREN_DFN8EN_SHIFT                   (3U)                                                /*!< USB0_ERREN.DFN8EN Position              */
#define USB_ERREN_DFN8EN(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_ERREN.DFN8EN Field                 */
#define USB_ERREN_BTOERREN_MASK                  (0x10U)                                             /*!< USB0_ERREN.BTOERREN Mask                */
#define USB_ERREN_BTOERREN_SHIFT                 (4U)                                                /*!< USB0_ERREN.BTOERREN Position            */
#define USB_ERREN_BTOERREN(x)                    (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_ERREN.BTOERREN Field               */
#define USB_ERREN_DMAERREN_MASK                  (0x20U)                                             /*!< USB0_ERREN.DMAERREN Mask                */
#define USB_ERREN_DMAERREN_SHIFT                 (5U)                                                /*!< USB0_ERREN.DMAERREN Position            */
#define USB_ERREN_DMAERREN(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_ERREN.DMAERREN Field               */
#define USB_ERREN_OWNERREN_MASK                  (0x40U)                                             /*!< USB0_ERREN.OWNERREN Mask                */
#define USB_ERREN_OWNERREN_SHIFT                 (6U)                                                /*!< USB0_ERREN.OWNERREN Position            */
#define USB_ERREN_OWNERREN(x)                    (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_ERREN.OWNERREN Field               */
#define USB_ERREN_BTSERREN_MASK                  (0x80U)                                             /*!< USB0_ERREN.BTSERREN Mask                */
#define USB_ERREN_BTSERREN_SHIFT                 (7U)                                                /*!< USB0_ERREN.BTSERREN Position            */
#define USB_ERREN_BTSERREN(x)                    (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_ERREN.BTSERREN Field               */
/* ------- STAT Bit Fields                          ------ */
#define USB_STAT_ODD_MASK                        (0x4U)                                              /*!< USB0_STAT.ODD Mask                      */
#define USB_STAT_ODD_SHIFT                       (2U)                                                /*!< USB0_STAT.ODD Position                  */
#define USB_STAT_ODD(x)                          (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_STAT.ODD Field                     */
#define USB_STAT_TX_MASK                         (0x8U)                                              /*!< USB0_STAT.TX Mask                       */
#define USB_STAT_TX_SHIFT                        (3U)                                                /*!< USB0_STAT.TX Position                   */
#define USB_STAT_TX(x)                           (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_STAT.TX Field                      */
#define USB_STAT_ENDP_MASK                       (0xF0U)                                             /*!< USB0_STAT.ENDP Mask                     */
#define USB_STAT_ENDP_SHIFT                      (4U)                                                /*!< USB0_STAT.ENDP Position                 */
#define USB_STAT_ENDP(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0xF0UL)            /*!< USB0_STAT.ENDP Field                    */
/* ------- CTL Bit Fields                           ------ */
#define USB_CTL_USBENSOFEN_MASK                  (0x1U)                                              /*!< USB0_CTL.USBENSOFEN Mask                */
#define USB_CTL_USBENSOFEN_SHIFT                 (0U)                                                /*!< USB0_CTL.USBENSOFEN Position            */
#define USB_CTL_USBENSOFEN(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_CTL.USBENSOFEN Field               */
#define USB_CTL_ODDRST_MASK                      (0x2U)                                              /*!< USB0_CTL.ODDRST Mask                    */
#define USB_CTL_ODDRST_SHIFT                     (1U)                                                /*!< USB0_CTL.ODDRST Position                */
#define USB_CTL_ODDRST(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_CTL.ODDRST Field                   */
#define USB_CTL_RESUME_MASK                      (0x4U)                                              /*!< USB0_CTL.RESUME Mask                    */
#define USB_CTL_RESUME_SHIFT                     (2U)                                                /*!< USB0_CTL.RESUME Position                */
#define USB_CTL_RESUME(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_CTL.RESUME Field                   */
#define USB_CTL_HOSTMODEEN_MASK                  (0x8U)                                              /*!< USB0_CTL.HOSTMODEEN Mask                */
#define USB_CTL_HOSTMODEEN_SHIFT                 (3U)                                                /*!< USB0_CTL.HOSTMODEEN Position            */
#define USB_CTL_HOSTMODEEN(x)                    (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_CTL.HOSTMODEEN Field               */
#define USB_CTL_RESET_MASK                       (0x10U)                                             /*!< USB0_CTL.RESET Mask                     */
#define USB_CTL_RESET_SHIFT                      (4U)                                                /*!< USB0_CTL.RESET Position                 */
#define USB_CTL_RESET(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_CTL.RESET Field                    */
#define USB_CTL_TXSUSPENDTOKENBUSY_MASK          (0x20U)                                             /*!< USB0_CTL.TXSUSPENDTOKENBUSY Mask        */
#define USB_CTL_TXSUSPENDTOKENBUSY_SHIFT         (5U)                                                /*!< USB0_CTL.TXSUSPENDTOKENBUSY Position    */
#define USB_CTL_TXSUSPENDTOKENBUSY(x)            (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_CTL.TXSUSPENDTOKENBUSY Field       */
#define USB_CTL_SE0_MASK                         (0x40U)                                             /*!< USB0_CTL.SE0 Mask                       */
#define USB_CTL_SE0_SHIFT                        (6U)                                                /*!< USB0_CTL.SE0 Position                   */
#define USB_CTL_SE0(x)                           (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_CTL.SE0 Field                      */
#define USB_CTL_JSTATE_MASK                      (0x80U)                                             /*!< USB0_CTL.JSTATE Mask                    */
#define USB_CTL_JSTATE_SHIFT                     (7U)                                                /*!< USB0_CTL.JSTATE Position                */
#define USB_CTL_JSTATE(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_CTL.JSTATE Field                   */
/* ------- ADDR Bit Fields                          ------ */
#define USB_ADDR_ADDR_MASK                       (0x7FU)                                             /*!< USB0_ADDR.ADDR Mask                     */
#define USB_ADDR_ADDR_SHIFT                      (0U)                                                /*!< USB0_ADDR.ADDR Position                 */
#define USB_ADDR_ADDR(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x7FUL)            /*!< USB0_ADDR.ADDR Field                    */
#define USB_ADDR_LSEN_MASK                       (0x80U)                                             /*!< USB0_ADDR.LSEN Mask                     */
#define USB_ADDR_LSEN_SHIFT                      (7U)                                                /*!< USB0_ADDR.LSEN Position                 */
#define USB_ADDR_LSEN(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_ADDR.LSEN Field                    */
/* ------- BDTPAGE1 Bit Fields                      ------ */
#define USB_BDTPAGE1_BDTBA_MASK                  (0xFEU)                                             /*!< USB0_BDTPAGE1.BDTBA Mask                */
#define USB_BDTPAGE1_BDTBA_SHIFT                 (1U)                                                /*!< USB0_BDTPAGE1.BDTBA Position            */
#define USB_BDTPAGE1_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<1U))&0xFEUL)            /*!< USB0_BDTPAGE1.BDTBA Field               */
/* ------- FRMNUML Bit Fields                       ------ */
#define USB_FRMNUML_FRM_MASK                     (0xFFU)                                             /*!< USB0_FRMNUML.FRM Mask                   */
#define USB_FRMNUML_FRM_SHIFT                    (0U)                                                /*!< USB0_FRMNUML.FRM Position               */
#define USB_FRMNUML_FRM(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< USB0_FRMNUML.FRM Field                  */
/* ------- FRMNUMH Bit Fields                       ------ */
#define USB_FRMNUMH_FRM_MASK                     (0x7U)                                              /*!< USB0_FRMNUMH.FRM Mask                   */
#define USB_FRMNUMH_FRM_SHIFT                    (0U)                                                /*!< USB0_FRMNUMH.FRM Position               */
#define USB_FRMNUMH_FRM(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< USB0_FRMNUMH.FRM Field                  */
/* ------- TOKEN Bit Fields                         ------ */
#define USB_TOKEN_TOKENENDPT_MASK                (0xFU)                                              /*!< USB0_TOKEN.TOKENENDPT Mask              */
#define USB_TOKEN_TOKENENDPT_SHIFT               (0U)                                                /*!< USB0_TOKEN.TOKENENDPT Position          */
#define USB_TOKEN_TOKENENDPT(x)                  (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< USB0_TOKEN.TOKENENDPT Field             */
#define USB_TOKEN_TOKENPID_MASK                  (0xF0U)                                             /*!< USB0_TOKEN.TOKENPID Mask                */
#define USB_TOKEN_TOKENPID_SHIFT                 (4U)                                                /*!< USB0_TOKEN.TOKENPID Position            */
#define USB_TOKEN_TOKENPID(x)                    (((uint8_t)(((uint8_t)(x))<<4U))&0xF0UL)            /*!< USB0_TOKEN.TOKENPID Field               */
/* ------- SOFTHLD Bit Fields                       ------ */
#define USB_SOFTHLD_CNT_MASK                     (0xFFU)                                             /*!< USB0_SOFTHLD.CNT Mask                   */
#define USB_SOFTHLD_CNT_SHIFT                    (0U)                                                /*!< USB0_SOFTHLD.CNT Position               */
#define USB_SOFTHLD_CNT(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< USB0_SOFTHLD.CNT Field                  */
/* ------- BDTPAGE2 Bit Fields                      ------ */
#define USB_BDTPAGE2_BDTBA_MASK                  (0xFFU)                                             /*!< USB0_BDTPAGE2.BDTBA Mask                */
#define USB_BDTPAGE2_BDTBA_SHIFT                 (0U)                                                /*!< USB0_BDTPAGE2.BDTBA Position            */
#define USB_BDTPAGE2_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< USB0_BDTPAGE2.BDTBA Field               */
/* ------- BDTPAGE3 Bit Fields                      ------ */
#define USB_BDTPAGE3_BDTBA_MASK                  (0xFFU)                                             /*!< USB0_BDTPAGE3.BDTBA Mask                */
#define USB_BDTPAGE3_BDTBA_SHIFT                 (0U)                                                /*!< USB0_BDTPAGE3.BDTBA Position            */
#define USB_BDTPAGE3_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< USB0_BDTPAGE3.BDTBA Field               */
/* ------- ENDPT Bit Fields                         ------ */
#define USB_ENDPT_EPHSHK_MASK                    (0x1U)                                              /*!< USB0_ENDPT.EPHSHK Mask                  */
#define USB_ENDPT_EPHSHK_SHIFT                   (0U)                                                /*!< USB0_ENDPT.EPHSHK Position              */
#define USB_ENDPT_EPHSHK(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_ENDPT.EPHSHK Field                 */
#define USB_ENDPT_EPSTALL_MASK                   (0x2U)                                              /*!< USB0_ENDPT.EPSTALL Mask                 */
#define USB_ENDPT_EPSTALL_SHIFT                  (1U)                                                /*!< USB0_ENDPT.EPSTALL Position             */
#define USB_ENDPT_EPSTALL(x)                     (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_ENDPT.EPSTALL Field                */
#define USB_ENDPT_EPTXEN_MASK                    (0x4U)                                              /*!< USB0_ENDPT.EPTXEN Mask                  */
#define USB_ENDPT_EPTXEN_SHIFT                   (2U)                                                /*!< USB0_ENDPT.EPTXEN Position              */
#define USB_ENDPT_EPTXEN(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_ENDPT.EPTXEN Field                 */
#define USB_ENDPT_EPRXEN_MASK                    (0x8U)                                              /*!< USB0_ENDPT.EPRXEN Mask                  */
#define USB_ENDPT_EPRXEN_SHIFT                   (3U)                                                /*!< USB0_ENDPT.EPRXEN Position              */
#define USB_ENDPT_EPRXEN(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_ENDPT.EPRXEN Field                 */
#define USB_ENDPT_EPCTLDIS_MASK                  (0x10U)                                             /*!< USB0_ENDPT.EPCTLDIS Mask                */
#define USB_ENDPT_EPCTLDIS_SHIFT                 (4U)                                                /*!< USB0_ENDPT.EPCTLDIS Position            */
#define USB_ENDPT_EPCTLDIS(x)                    (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_ENDPT.EPCTLDIS Field               */
#define USB_ENDPT_RETRYDIS_MASK                  (0x40U)                                             /*!< USB0_ENDPT.RETRYDIS Mask                */
#define USB_ENDPT_RETRYDIS_SHIFT                 (6U)                                                /*!< USB0_ENDPT.RETRYDIS Position            */
#define USB_ENDPT_RETRYDIS(x)                    (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_ENDPT.RETRYDIS Field               */
#define USB_ENDPT_HOSTWOHUB_MASK                 (0x80U)                                             /*!< USB0_ENDPT.HOSTWOHUB Mask               */
#define USB_ENDPT_HOSTWOHUB_SHIFT                (7U)                                                /*!< USB0_ENDPT.HOSTWOHUB Position           */
#define USB_ENDPT_HOSTWOHUB(x)                   (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_ENDPT.HOSTWOHUB Field              */
/* ------- USBCTRL Bit Fields                       ------ */
#define USB_USBCTRL_UARTSEL_MASK                 (0x10U)                                             /*!< USB0_USBCTRL.UARTSEL Mask               */
#define USB_USBCTRL_UARTSEL_SHIFT                (4U)                                                /*!< USB0_USBCTRL.UARTSEL Position           */
#define USB_USBCTRL_UARTSEL(x)                   (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_USBCTRL.UARTSEL Field              */
#define USB_USBCTRL_UARTCHLS_MASK                (0x20U)                                             /*!< USB0_USBCTRL.UARTCHLS Mask              */
#define USB_USBCTRL_UARTCHLS_SHIFT               (5U)                                                /*!< USB0_USBCTRL.UARTCHLS Position          */
#define USB_USBCTRL_UARTCHLS(x)                  (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_USBCTRL.UARTCHLS Field             */
#define USB_USBCTRL_PDE_MASK                     (0x40U)                                             /*!< USB0_USBCTRL.PDE Mask                   */
#define USB_USBCTRL_PDE_SHIFT                    (6U)                                                /*!< USB0_USBCTRL.PDE Position               */
#define USB_USBCTRL_PDE(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_USBCTRL.PDE Field                  */
#define USB_USBCTRL_SUSP_MASK                    (0x80U)                                             /*!< USB0_USBCTRL.SUSP Mask                  */
#define USB_USBCTRL_SUSP_SHIFT                   (7U)                                                /*!< USB0_USBCTRL.SUSP Position              */
#define USB_USBCTRL_SUSP(x)                      (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_USBCTRL.SUSP Field                 */
/* ------- OBSERVE Bit Fields                       ------ */
#define USB_OBSERVE_DMPD_MASK                    (0x10U)                                             /*!< USB0_OBSERVE.DMPD Mask                  */
#define USB_OBSERVE_DMPD_SHIFT                   (4U)                                                /*!< USB0_OBSERVE.DMPD Position              */
#define USB_OBSERVE_DMPD(x)                      (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_OBSERVE.DMPD Field                 */
#define USB_OBSERVE_DPPD_MASK                    (0x40U)                                             /*!< USB0_OBSERVE.DPPD Mask                  */
#define USB_OBSERVE_DPPD_SHIFT                   (6U)                                                /*!< USB0_OBSERVE.DPPD Position              */
#define USB_OBSERVE_DPPD(x)                      (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_OBSERVE.DPPD Field                 */
#define USB_OBSERVE_DPPU_MASK                    (0x80U)                                             /*!< USB0_OBSERVE.DPPU Mask                  */
#define USB_OBSERVE_DPPU_SHIFT                   (7U)                                                /*!< USB0_OBSERVE.DPPU Position              */
#define USB_OBSERVE_DPPU(x)                      (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_OBSERVE.DPPU Field                 */
/* ------- CONTROL Bit Fields                       ------ */
#define USB_CONTROL_DPPULLUPNONOTG_MASK          (0x10U)                                             /*!< USB0_CONTROL.DPPULLUPNONOTG Mask        */
#define USB_CONTROL_DPPULLUPNONOTG_SHIFT         (4U)                                                /*!< USB0_CONTROL.DPPULLUPNONOTG Position    */
#define USB_CONTROL_DPPULLUPNONOTG(x)            (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_CONTROL.DPPULLUPNONOTG Field       */
/* ------- USBTRC0 Bit Fields                       ------ */
#define USB_USBTRC0_USB_RESUME_INT_MASK          (0x1U)                                              /*!< USB0_USBTRC0.USB_RESUME_INT Mask        */
#define USB_USBTRC0_USB_RESUME_INT_SHIFT         (0U)                                                /*!< USB0_USBTRC0.USB_RESUME_INT Position    */
#define USB_USBTRC0_USB_RESUME_INT(x)            (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_USBTRC0.USB_RESUME_INT Field       */
#define USB_USBTRC0_SYNC_DET_MASK                (0x2U)                                              /*!< USB0_USBTRC0.SYNC_DET Mask              */
#define USB_USBTRC0_SYNC_DET_SHIFT               (1U)                                                /*!< USB0_USBTRC0.SYNC_DET Position          */
#define USB_USBTRC0_SYNC_DET(x)                  (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_USBTRC0.SYNC_DET Field             */
#define USB_USBTRC0_USB_CLK_RECOVERY_INT_MASK    (0x4U)                                              /*!< USB0_USBTRC0.USB_CLK_RECOVERY_INT Mask  */
#define USB_USBTRC0_USB_CLK_RECOVERY_INT_SHIFT   (2U)                                                /*!< USB0_USBTRC0.USB_CLK_RECOVERY_INT Position*/
#define USB_USBTRC0_USB_CLK_RECOVERY_INT(x)      (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_USBTRC0.USB_CLK_RECOVERY_INT Field */
#define USB_USBTRC0_VREDG_DET_MASK               (0x8U)                                              /*!< USB0_USBTRC0.VREDG_DET Mask             */
#define USB_USBTRC0_VREDG_DET_SHIFT              (3U)                                                /*!< USB0_USBTRC0.VREDG_DET Position         */
#define USB_USBTRC0_VREDG_DET(x)                 (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_USBTRC0.VREDG_DET Field            */
#define USB_USBTRC0_VFEDG_DET_MASK               (0x10U)                                             /*!< USB0_USBTRC0.VFEDG_DET Mask             */
#define USB_USBTRC0_VFEDG_DET_SHIFT              (4U)                                                /*!< USB0_USBTRC0.VFEDG_DET Position         */
#define USB_USBTRC0_VFEDG_DET(x)                 (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_USBTRC0.VFEDG_DET Field            */
#define USB_USBTRC0_USBRESMEN_MASK               (0x20U)                                             /*!< USB0_USBTRC0.USBRESMEN Mask             */
#define USB_USBTRC0_USBRESMEN_SHIFT              (5U)                                                /*!< USB0_USBTRC0.USBRESMEN Position         */
#define USB_USBTRC0_USBRESMEN(x)                 (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_USBTRC0.USBRESMEN Field            */
#define USB_USBTRC0_USBRESET_MASK                (0x80U)                                             /*!< USB0_USBTRC0.USBRESET Mask              */
#define USB_USBTRC0_USBRESET_SHIFT               (7U)                                                /*!< USB0_USBTRC0.USBRESET Position          */
#define USB_USBTRC0_USBRESET(x)                  (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_USBTRC0.USBRESET Field             */
/* ------- USBFRMADJUST Bit Fields                  ------ */
#define USB_USBFRMADJUST_ADJ_MASK                (0xFFU)                                             /*!< USB0_USBFRMADJUST.ADJ Mask              */
#define USB_USBFRMADJUST_ADJ_SHIFT               (0U)                                                /*!< USB0_USBFRMADJUST.ADJ Position          */
#define USB_USBFRMADJUST_ADJ(x)                  (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< USB0_USBFRMADJUST.ADJ Field             */
/* ------- KEEP_ALIVE_CTRL Bit Fields               ------ */
#define USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN_MASK   (0x1U)                                              /*!< USB0_KEEP_ALIVE_CTRL.KEEP_ALIVE_EN Mask */
#define USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN_SHIFT  (0U)                                                /*!< USB0_KEEP_ALIVE_CTRL.KEEP_ALIVE_EN Position*/
#define USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN(x)     (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_KEEP_ALIVE_CTRL.KEEP_ALIVE_EN Field*/
#define USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN_MASK   (0x2U)                                              /*!< USB0_KEEP_ALIVE_CTRL.OWN_OVERRD_EN Mask */
#define USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN_SHIFT  (1U)                                                /*!< USB0_KEEP_ALIVE_CTRL.OWN_OVERRD_EN Position*/
#define USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN(x)     (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_KEEP_ALIVE_CTRL.OWN_OVERRD_EN Field*/
#define USB_KEEP_ALIVE_CTRL_WAKE_REQ_EN_MASK     (0x8U)                                              /*!< USB0_KEEP_ALIVE_CTRL.WAKE_REQ_EN Mask   */
#define USB_KEEP_ALIVE_CTRL_WAKE_REQ_EN_SHIFT    (3U)                                                /*!< USB0_KEEP_ALIVE_CTRL.WAKE_REQ_EN Position*/
#define USB_KEEP_ALIVE_CTRL_WAKE_REQ_EN(x)       (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_KEEP_ALIVE_CTRL.WAKE_REQ_EN Field  */
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_EN_MASK     (0x10U)                                             /*!< USB0_KEEP_ALIVE_CTRL.WAKE_INT_EN Mask   */
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_EN_SHIFT    (4U)                                                /*!< USB0_KEEP_ALIVE_CTRL.WAKE_INT_EN Position*/
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_EN(x)       (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_KEEP_ALIVE_CTRL.WAKE_INT_EN Field  */
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_STS_MASK    (0x80U)                                             /*!< USB0_KEEP_ALIVE_CTRL.WAKE_INT_STS Mask  */
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_STS_SHIFT   (7U)                                                /*!< USB0_KEEP_ALIVE_CTRL.WAKE_INT_STS Position*/
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_STS(x)      (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_KEEP_ALIVE_CTRL.WAKE_INT_STS Field */
/* ------- KEEP_ALIVE_WKCTRL Bit Fields             ------ */
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS_MASK  (0xFU)                                              /*!< USB0_KEEP_ALIVE_WKCTRL.WAKE_ON_THIS Mask*/
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS_SHIFT (0U)                                                /*!< USB0_KEEP_ALIVE_WKCTRL.WAKE_ON_THIS Position*/
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS(x)    (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< USB0_KEEP_ALIVE_WKCTRL.WAKE_ON_THIS Field*/
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT_MASK    (0xF0U)                                             /*!< USB0_KEEP_ALIVE_WKCTRL.WAKE_ENDPT Mask  */
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT_SHIFT   (4U)                                                /*!< USB0_KEEP_ALIVE_WKCTRL.WAKE_ENDPT Position*/
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT(x)      (((uint8_t)(((uint8_t)(x))<<4U))&0xF0UL)            /*!< USB0_KEEP_ALIVE_WKCTRL.WAKE_ENDPT Field */
/* ------- MISCCTRL Bit Fields                      ------ */
#define USB_MISCCTRL_SOFDYNTHLD_MASK             (0x1U)                                              /*!< USB0_MISCCTRL.SOFDYNTHLD Mask           */
#define USB_MISCCTRL_SOFDYNTHLD_SHIFT            (0U)                                                /*!< USB0_MISCCTRL.SOFDYNTHLD Position       */
#define USB_MISCCTRL_SOFDYNTHLD(x)               (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_MISCCTRL.SOFDYNTHLD Field          */
#define USB_MISCCTRL_SOFBUSSET_MASK              (0x2U)                                              /*!< USB0_MISCCTRL.SOFBUSSET Mask            */
#define USB_MISCCTRL_SOFBUSSET_SHIFT             (1U)                                                /*!< USB0_MISCCTRL.SOFBUSSET Position        */
#define USB_MISCCTRL_SOFBUSSET(x)                (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_MISCCTRL.SOFBUSSET Field           */
#define USB_MISCCTRL_OWNERRISODIS_MASK           (0x4U)                                              /*!< USB0_MISCCTRL.OWNERRISODIS Mask         */
#define USB_MISCCTRL_OWNERRISODIS_SHIFT          (2U)                                                /*!< USB0_MISCCTRL.OWNERRISODIS Position     */
#define USB_MISCCTRL_OWNERRISODIS(x)             (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_MISCCTRL.OWNERRISODIS Field        */
#define USB_MISCCTRL_VREDG_EN_MASK               (0x8U)                                              /*!< USB0_MISCCTRL.VREDG_EN Mask             */
#define USB_MISCCTRL_VREDG_EN_SHIFT              (3U)                                                /*!< USB0_MISCCTRL.VREDG_EN Position         */
#define USB_MISCCTRL_VREDG_EN(x)                 (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_MISCCTRL.VREDG_EN Field            */
#define USB_MISCCTRL_VFEDG_EN_MASK               (0x10U)                                             /*!< USB0_MISCCTRL.VFEDG_EN Mask             */
#define USB_MISCCTRL_VFEDG_EN_SHIFT              (4U)                                                /*!< USB0_MISCCTRL.VFEDG_EN Position         */
#define USB_MISCCTRL_VFEDG_EN(x)                 (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_MISCCTRL.VFEDG_EN Field            */
#define USB_MISCCTRL_STL_ADJ_EN_MASK             (0x80U)                                             /*!< USB0_MISCCTRL.STL_ADJ_EN Mask           */
#define USB_MISCCTRL_STL_ADJ_EN_SHIFT            (7U)                                                /*!< USB0_MISCCTRL.STL_ADJ_EN Position       */
#define USB_MISCCTRL_STL_ADJ_EN(x)               (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_MISCCTRL.STL_ADJ_EN Field          */
/* ------- STALL_IL_DIS Bit Fields                  ------ */
#define USB_STALL_IL_DIS_STALL_I_DIS0_MASK       (0x1U)                                              /*!< USB0_STALL_IL_DIS.STALL_I_DIS0 Mask     */
#define USB_STALL_IL_DIS_STALL_I_DIS0_SHIFT      (0U)                                                /*!< USB0_STALL_IL_DIS.STALL_I_DIS0 Position */
#define USB_STALL_IL_DIS_STALL_I_DIS0(x)         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_STALL_IL_DIS.STALL_I_DIS0 Field    */
#define USB_STALL_IL_DIS_STALL_I_DIS1_MASK       (0x2U)                                              /*!< USB0_STALL_IL_DIS.STALL_I_DIS1 Mask     */
#define USB_STALL_IL_DIS_STALL_I_DIS1_SHIFT      (1U)                                                /*!< USB0_STALL_IL_DIS.STALL_I_DIS1 Position */
#define USB_STALL_IL_DIS_STALL_I_DIS1(x)         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_STALL_IL_DIS.STALL_I_DIS1 Field    */
#define USB_STALL_IL_DIS_STALL_I_DIS2_MASK       (0x4U)                                              /*!< USB0_STALL_IL_DIS.STALL_I_DIS2 Mask     */
#define USB_STALL_IL_DIS_STALL_I_DIS2_SHIFT      (2U)                                                /*!< USB0_STALL_IL_DIS.STALL_I_DIS2 Position */
#define USB_STALL_IL_DIS_STALL_I_DIS2(x)         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_STALL_IL_DIS.STALL_I_DIS2 Field    */
#define USB_STALL_IL_DIS_STALL_I_DIS3_MASK       (0x8U)                                              /*!< USB0_STALL_IL_DIS.STALL_I_DIS3 Mask     */
#define USB_STALL_IL_DIS_STALL_I_DIS3_SHIFT      (3U)                                                /*!< USB0_STALL_IL_DIS.STALL_I_DIS3 Position */
#define USB_STALL_IL_DIS_STALL_I_DIS3(x)         (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_STALL_IL_DIS.STALL_I_DIS3 Field    */
#define USB_STALL_IL_DIS_STALL_I_DIS4_MASK       (0x10U)                                             /*!< USB0_STALL_IL_DIS.STALL_I_DIS4 Mask     */
#define USB_STALL_IL_DIS_STALL_I_DIS4_SHIFT      (4U)                                                /*!< USB0_STALL_IL_DIS.STALL_I_DIS4 Position */
#define USB_STALL_IL_DIS_STALL_I_DIS4(x)         (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_STALL_IL_DIS.STALL_I_DIS4 Field    */
#define USB_STALL_IL_DIS_STALL_I_DIS5_MASK       (0x20U)                                             /*!< USB0_STALL_IL_DIS.STALL_I_DIS5 Mask     */
#define USB_STALL_IL_DIS_STALL_I_DIS5_SHIFT      (5U)                                                /*!< USB0_STALL_IL_DIS.STALL_I_DIS5 Position */
#define USB_STALL_IL_DIS_STALL_I_DIS5(x)         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_STALL_IL_DIS.STALL_I_DIS5 Field    */
#define USB_STALL_IL_DIS_STALL_I_DIS6_MASK       (0x40U)                                             /*!< USB0_STALL_IL_DIS.STALL_I_DIS6 Mask     */
#define USB_STALL_IL_DIS_STALL_I_DIS6_SHIFT      (6U)                                                /*!< USB0_STALL_IL_DIS.STALL_I_DIS6 Position */
#define USB_STALL_IL_DIS_STALL_I_DIS6(x)         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_STALL_IL_DIS.STALL_I_DIS6 Field    */
#define USB_STALL_IL_DIS_STALL_I_DIS7_MASK       (0x80U)                                             /*!< USB0_STALL_IL_DIS.STALL_I_DIS7 Mask     */
#define USB_STALL_IL_DIS_STALL_I_DIS7_SHIFT      (7U)                                                /*!< USB0_STALL_IL_DIS.STALL_I_DIS7 Position */
#define USB_STALL_IL_DIS_STALL_I_DIS7(x)         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_STALL_IL_DIS.STALL_I_DIS7 Field    */
/* ------- STALL_IH_DIS Bit Fields                  ------ */
#define USB_STALL_IH_DIS_STALL_I_DIS8_MASK       (0x1U)                                              /*!< USB0_STALL_IH_DIS.STALL_I_DIS8 Mask     */
#define USB_STALL_IH_DIS_STALL_I_DIS8_SHIFT      (0U)                                                /*!< USB0_STALL_IH_DIS.STALL_I_DIS8 Position */
#define USB_STALL_IH_DIS_STALL_I_DIS8(x)         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_STALL_IH_DIS.STALL_I_DIS8 Field    */
#define USB_STALL_IH_DIS_STALL_I_DIS9_MASK       (0x2U)                                              /*!< USB0_STALL_IH_DIS.STALL_I_DIS9 Mask     */
#define USB_STALL_IH_DIS_STALL_I_DIS9_SHIFT      (1U)                                                /*!< USB0_STALL_IH_DIS.STALL_I_DIS9 Position */
#define USB_STALL_IH_DIS_STALL_I_DIS9(x)         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_STALL_IH_DIS.STALL_I_DIS9 Field    */
#define USB_STALL_IH_DIS_STALL_I_DIS10_MASK      (0x4U)                                              /*!< USB0_STALL_IH_DIS.STALL_I_DIS10 Mask    */
#define USB_STALL_IH_DIS_STALL_I_DIS10_SHIFT     (2U)                                                /*!< USB0_STALL_IH_DIS.STALL_I_DIS10 Position*/
#define USB_STALL_IH_DIS_STALL_I_DIS10(x)        (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_STALL_IH_DIS.STALL_I_DIS10 Field   */
#define USB_STALL_IH_DIS_STALL_I_DIS11_MASK      (0x8U)                                              /*!< USB0_STALL_IH_DIS.STALL_I_DIS11 Mask    */
#define USB_STALL_IH_DIS_STALL_I_DIS11_SHIFT     (3U)                                                /*!< USB0_STALL_IH_DIS.STALL_I_DIS11 Position*/
#define USB_STALL_IH_DIS_STALL_I_DIS11(x)        (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_STALL_IH_DIS.STALL_I_DIS11 Field   */
#define USB_STALL_IH_DIS_STALL_I_DIS12_MASK      (0x10U)                                             /*!< USB0_STALL_IH_DIS.STALL_I_DIS12 Mask    */
#define USB_STALL_IH_DIS_STALL_I_DIS12_SHIFT     (4U)                                                /*!< USB0_STALL_IH_DIS.STALL_I_DIS12 Position*/
#define USB_STALL_IH_DIS_STALL_I_DIS12(x)        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_STALL_IH_DIS.STALL_I_DIS12 Field   */
#define USB_STALL_IH_DIS_STALL_I_DIS13_MASK      (0x20U)                                             /*!< USB0_STALL_IH_DIS.STALL_I_DIS13 Mask    */
#define USB_STALL_IH_DIS_STALL_I_DIS13_SHIFT     (5U)                                                /*!< USB0_STALL_IH_DIS.STALL_I_DIS13 Position*/
#define USB_STALL_IH_DIS_STALL_I_DIS13(x)        (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_STALL_IH_DIS.STALL_I_DIS13 Field   */
#define USB_STALL_IH_DIS_STALL_I_DIS14_MASK      (0x40U)                                             /*!< USB0_STALL_IH_DIS.STALL_I_DIS14 Mask    */
#define USB_STALL_IH_DIS_STALL_I_DIS14_SHIFT     (6U)                                                /*!< USB0_STALL_IH_DIS.STALL_I_DIS14 Position*/
#define USB_STALL_IH_DIS_STALL_I_DIS14(x)        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_STALL_IH_DIS.STALL_I_DIS14 Field   */
#define USB_STALL_IH_DIS_STALL_I_DIS15_MASK      (0x80U)                                             /*!< USB0_STALL_IH_DIS.STALL_I_DIS15 Mask    */
#define USB_STALL_IH_DIS_STALL_I_DIS15_SHIFT     (7U)                                                /*!< USB0_STALL_IH_DIS.STALL_I_DIS15 Position*/
#define USB_STALL_IH_DIS_STALL_I_DIS15(x)        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_STALL_IH_DIS.STALL_I_DIS15 Field   */
/* ------- STALL_OL_DIS Bit Fields                  ------ */
#define USB_STALL_OL_DIS_STALL_O_DIS0_MASK       (0x1U)                                              /*!< USB0_STALL_OL_DIS.STALL_O_DIS0 Mask     */
#define USB_STALL_OL_DIS_STALL_O_DIS0_SHIFT      (0U)                                                /*!< USB0_STALL_OL_DIS.STALL_O_DIS0 Position */
#define USB_STALL_OL_DIS_STALL_O_DIS0(x)         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_STALL_OL_DIS.STALL_O_DIS0 Field    */
#define USB_STALL_OL_DIS_STALL_O_DIS1_MASK       (0x2U)                                              /*!< USB0_STALL_OL_DIS.STALL_O_DIS1 Mask     */
#define USB_STALL_OL_DIS_STALL_O_DIS1_SHIFT      (1U)                                                /*!< USB0_STALL_OL_DIS.STALL_O_DIS1 Position */
#define USB_STALL_OL_DIS_STALL_O_DIS1(x)         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_STALL_OL_DIS.STALL_O_DIS1 Field    */
#define USB_STALL_OL_DIS_STALL_O_DIS2_MASK       (0x4U)                                              /*!< USB0_STALL_OL_DIS.STALL_O_DIS2 Mask     */
#define USB_STALL_OL_DIS_STALL_O_DIS2_SHIFT      (2U)                                                /*!< USB0_STALL_OL_DIS.STALL_O_DIS2 Position */
#define USB_STALL_OL_DIS_STALL_O_DIS2(x)         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_STALL_OL_DIS.STALL_O_DIS2 Field    */
#define USB_STALL_OL_DIS_STALL_O_DIS3_MASK       (0x8U)                                              /*!< USB0_STALL_OL_DIS.STALL_O_DIS3 Mask     */
#define USB_STALL_OL_DIS_STALL_O_DIS3_SHIFT      (3U)                                                /*!< USB0_STALL_OL_DIS.STALL_O_DIS3 Position */
#define USB_STALL_OL_DIS_STALL_O_DIS3(x)         (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_STALL_OL_DIS.STALL_O_DIS3 Field    */
#define USB_STALL_OL_DIS_STALL_O_DIS4_MASK       (0x10U)                                             /*!< USB0_STALL_OL_DIS.STALL_O_DIS4 Mask     */
#define USB_STALL_OL_DIS_STALL_O_DIS4_SHIFT      (4U)                                                /*!< USB0_STALL_OL_DIS.STALL_O_DIS4 Position */
#define USB_STALL_OL_DIS_STALL_O_DIS4(x)         (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_STALL_OL_DIS.STALL_O_DIS4 Field    */
#define USB_STALL_OL_DIS_STALL_O_DIS5_MASK       (0x20U)                                             /*!< USB0_STALL_OL_DIS.STALL_O_DIS5 Mask     */
#define USB_STALL_OL_DIS_STALL_O_DIS5_SHIFT      (5U)                                                /*!< USB0_STALL_OL_DIS.STALL_O_DIS5 Position */
#define USB_STALL_OL_DIS_STALL_O_DIS5(x)         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_STALL_OL_DIS.STALL_O_DIS5 Field    */
#define USB_STALL_OL_DIS_STALL_O_DIS6_MASK       (0x40U)                                             /*!< USB0_STALL_OL_DIS.STALL_O_DIS6 Mask     */
#define USB_STALL_OL_DIS_STALL_O_DIS6_SHIFT      (6U)                                                /*!< USB0_STALL_OL_DIS.STALL_O_DIS6 Position */
#define USB_STALL_OL_DIS_STALL_O_DIS6(x)         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_STALL_OL_DIS.STALL_O_DIS6 Field    */
#define USB_STALL_OL_DIS_STALL_O_DIS7_MASK       (0x80U)                                             /*!< USB0_STALL_OL_DIS.STALL_O_DIS7 Mask     */
#define USB_STALL_OL_DIS_STALL_O_DIS7_SHIFT      (7U)                                                /*!< USB0_STALL_OL_DIS.STALL_O_DIS7 Position */
#define USB_STALL_OL_DIS_STALL_O_DIS7(x)         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_STALL_OL_DIS.STALL_O_DIS7 Field    */
/* ------- STALL_OH_DIS Bit Fields                  ------ */
#define USB_STALL_OH_DIS_STALL_O_DIS8_MASK       (0x1U)                                              /*!< USB0_STALL_OH_DIS.STALL_O_DIS8 Mask     */
#define USB_STALL_OH_DIS_STALL_O_DIS8_SHIFT      (0U)                                                /*!< USB0_STALL_OH_DIS.STALL_O_DIS8 Position */
#define USB_STALL_OH_DIS_STALL_O_DIS8(x)         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_STALL_OH_DIS.STALL_O_DIS8 Field    */
#define USB_STALL_OH_DIS_STALL_O_DIS9_MASK       (0x2U)                                              /*!< USB0_STALL_OH_DIS.STALL_O_DIS9 Mask     */
#define USB_STALL_OH_DIS_STALL_O_DIS9_SHIFT      (1U)                                                /*!< USB0_STALL_OH_DIS.STALL_O_DIS9 Position */
#define USB_STALL_OH_DIS_STALL_O_DIS9(x)         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_STALL_OH_DIS.STALL_O_DIS9 Field    */
#define USB_STALL_OH_DIS_STALL_O_DIS10_MASK      (0x4U)                                              /*!< USB0_STALL_OH_DIS.STALL_O_DIS10 Mask    */
#define USB_STALL_OH_DIS_STALL_O_DIS10_SHIFT     (2U)                                                /*!< USB0_STALL_OH_DIS.STALL_O_DIS10 Position*/
#define USB_STALL_OH_DIS_STALL_O_DIS10(x)        (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< USB0_STALL_OH_DIS.STALL_O_DIS10 Field   */
#define USB_STALL_OH_DIS_STALL_O_DIS11_MASK      (0x8U)                                              /*!< USB0_STALL_OH_DIS.STALL_O_DIS11 Mask    */
#define USB_STALL_OH_DIS_STALL_O_DIS11_SHIFT     (3U)                                                /*!< USB0_STALL_OH_DIS.STALL_O_DIS11 Position*/
#define USB_STALL_OH_DIS_STALL_O_DIS11(x)        (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< USB0_STALL_OH_DIS.STALL_O_DIS11 Field   */
#define USB_STALL_OH_DIS_STALL_O_DIS12_MASK      (0x10U)                                             /*!< USB0_STALL_OH_DIS.STALL_O_DIS12 Mask    */
#define USB_STALL_OH_DIS_STALL_O_DIS12_SHIFT     (4U)                                                /*!< USB0_STALL_OH_DIS.STALL_O_DIS12 Position*/
#define USB_STALL_OH_DIS_STALL_O_DIS12(x)        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_STALL_OH_DIS.STALL_O_DIS12 Field   */
#define USB_STALL_OH_DIS_STALL_O_DIS13_MASK      (0x20U)                                             /*!< USB0_STALL_OH_DIS.STALL_O_DIS13 Mask    */
#define USB_STALL_OH_DIS_STALL_O_DIS13_SHIFT     (5U)                                                /*!< USB0_STALL_OH_DIS.STALL_O_DIS13 Position*/
#define USB_STALL_OH_DIS_STALL_O_DIS13(x)        (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< USB0_STALL_OH_DIS.STALL_O_DIS13 Field   */
#define USB_STALL_OH_DIS_STALL_O_DIS14_MASK      (0x40U)                                             /*!< USB0_STALL_OH_DIS.STALL_O_DIS14 Mask    */
#define USB_STALL_OH_DIS_STALL_O_DIS14_SHIFT     (6U)                                                /*!< USB0_STALL_OH_DIS.STALL_O_DIS14 Position*/
#define USB_STALL_OH_DIS_STALL_O_DIS14(x)        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< USB0_STALL_OH_DIS.STALL_O_DIS14 Field   */
#define USB_STALL_OH_DIS_STALL_O_DIS15_MASK      (0x80U)                                             /*!< USB0_STALL_OH_DIS.STALL_O_DIS15 Mask    */
#define USB_STALL_OH_DIS_STALL_O_DIS15_SHIFT     (7U)                                                /*!< USB0_STALL_OH_DIS.STALL_O_DIS15 Position*/
#define USB_STALL_OH_DIS_STALL_O_DIS15(x)        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_STALL_OH_DIS.STALL_O_DIS15 Field   */
/* ------- CLK_RECOVER_CTRL Bit Fields              ------ */
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_MASK (0x20U)                                         /*!< USB0_CLK_RECOVER_CTRL.RESTART_IFRTRIM_EN Mask*/
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_SHIFT (5U)                                           /*!< USB0_CLK_RECOVER_CTRL.RESTART_IFRTRIM_EN Position*/
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN(x) (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)          /*!< USB0_CLK_RECOVER_CTRL.RESTART_IFRTRIM_EN Field*/
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_MASK (0x40U)                                      /*!< USB0_CLK_RECOVER_CTRL.RESET_RESUME_ROUGH_EN Mask*/
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_SHIFT (6U)                                        /*!< USB0_CLK_RECOVER_CTRL.RESET_RESUME_ROUGH_EN Position*/
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN(x) (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)       /*!< USB0_CLK_RECOVER_CTRL.RESET_RESUME_ROUGH_EN Field*/
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_MASK (0x80U)                                           /*!< USB0_CLK_RECOVER_CTRL.CLOCK_RECOVER_EN Mask*/
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_SHIFT (7U)                                             /*!< USB0_CLK_RECOVER_CTRL.CLOCK_RECOVER_EN Position*/
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN(x) (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< USB0_CLK_RECOVER_CTRL.CLOCK_RECOVER_EN Field*/
/* ------- CLK_RECOVER_IRC_EN Bit Fields            ------ */
#define USB_CLK_RECOVER_IRC_EN_REG_EN_MASK       (0x1U)                                              /*!< USB0_CLK_RECOVER_IRC_EN.REG_EN Mask     */
#define USB_CLK_RECOVER_IRC_EN_REG_EN_SHIFT      (0U)                                                /*!< USB0_CLK_RECOVER_IRC_EN.REG_EN Position */
#define USB_CLK_RECOVER_IRC_EN_REG_EN(x)         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< USB0_CLK_RECOVER_IRC_EN.REG_EN Field    */
#define USB_CLK_RECOVER_IRC_EN_IRC_EN_MASK       (0x2U)                                              /*!< USB0_CLK_RECOVER_IRC_EN.IRC_EN Mask     */
#define USB_CLK_RECOVER_IRC_EN_IRC_EN_SHIFT      (1U)                                                /*!< USB0_CLK_RECOVER_IRC_EN.IRC_EN Position */
#define USB_CLK_RECOVER_IRC_EN_IRC_EN(x)         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< USB0_CLK_RECOVER_IRC_EN.IRC_EN Field    */
/* ------- CLK_RECOVER_INT_EN Bit Fields            ------ */
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_MASK (0x10U)                                             /*!< USB0_CLK_RECOVER_INT_EN.OVF_ERROR_EN Mask*/
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_SHIFT (4U)                                               /*!< USB0_CLK_RECOVER_INT_EN.OVF_ERROR_EN Position*/
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN(x)   (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_CLK_RECOVER_INT_EN.OVF_ERROR_EN Field*/
/* ------- CLK_RECOVER_INT_STATUS Bit Fields        ------ */
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_MASK (0x10U)                                            /*!< USB0_CLK_RECOVER_INT_STATUS.OVF_ERROR Mask*/
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_SHIFT (4U)                                              /*!< USB0_CLK_RECOVER_INT_STATUS.OVF_ERROR Position*/
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR(x)  (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< USB0_CLK_RECOVER_INT_STATUS.OVF_ERROR Field*/
/**
 * @} */ /* End group USB_Register_Masks_GROUP 
 */

/* USB0 - Peripheral instance base addresses */
#define USB0_BasePtr                   0x40072000UL //!< Peripheral base address
#define USB0                           ((USB_Type *) USB0_BasePtr) //!< Freescale base pointer
#define USB0_BASE_PTR                  (USB0) //!< Freescale style base pointer
/**
 * @} */ /* End group USB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup VREF_Peripheral_access_layer_GROUP VREF Peripheral Access Layer
* @brief C Struct for VREF
* @{
*/

/* ================================================================================ */
/* ================           VREF (file:VREF_MK82F25615)          ================ */
/* ================================================================================ */

/**
 * @brief Voltage Reference
 */
/**
* @addtogroup VREF_structs_GROUP VREF struct
* @brief Struct for VREF
* @{
*/
typedef struct {                                /*       VREF Structure                                               */
   __IO uint8_t   TRM;                          /**< 0000: Trim Register                                                */
   __IO uint8_t   SC;                           /**< 0001: Status and Control Register                                  */
} VREF_Type;

/**
 * @} */ /* End group VREF_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'VREF' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup VREF_Register_Masks_GROUP VREF Register Masks
* @brief Register Masks for VREF
* @{
*/
/* ------- TRM Bit Fields                           ------ */
#define VREF_TRM_TRIM_MASK                       (0x3FU)                                             /*!< VREF_TRM.TRIM Mask                      */
#define VREF_TRM_TRIM_SHIFT                      (0U)                                                /*!< VREF_TRM.TRIM Position                  */
#define VREF_TRM_TRIM(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x3FUL)            /*!< VREF_TRM.TRIM Field                     */
#define VREF_TRM_CHOPEN_MASK                     (0x40U)                                             /*!< VREF_TRM.CHOPEN Mask                    */
#define VREF_TRM_CHOPEN_SHIFT                    (6U)                                                /*!< VREF_TRM.CHOPEN Position                */
#define VREF_TRM_CHOPEN(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< VREF_TRM.CHOPEN Field                   */
/* ------- SC Bit Fields                            ------ */
#define VREF_SC_MODE_LV_MASK                     (0x3U)                                              /*!< VREF_SC.MODE_LV Mask                    */
#define VREF_SC_MODE_LV_SHIFT                    (0U)                                                /*!< VREF_SC.MODE_LV Position                */
#define VREF_SC_MODE_LV(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< VREF_SC.MODE_LV Field                   */
#define VREF_SC_VREFST_MASK                      (0x4U)                                              /*!< VREF_SC.VREFST Mask                     */
#define VREF_SC_VREFST_SHIFT                     (2U)                                                /*!< VREF_SC.VREFST Position                 */
#define VREF_SC_VREFST(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< VREF_SC.VREFST Field                    */
#define VREF_SC_ICOMPEN_MASK                     (0x20U)                                             /*!< VREF_SC.ICOMPEN Mask                    */
#define VREF_SC_ICOMPEN_SHIFT                    (5U)                                                /*!< VREF_SC.ICOMPEN Position                */
#define VREF_SC_ICOMPEN(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< VREF_SC.ICOMPEN Field                   */
#define VREF_SC_REGEN_MASK                       (0x40U)                                             /*!< VREF_SC.REGEN Mask                      */
#define VREF_SC_REGEN_SHIFT                      (6U)                                                /*!< VREF_SC.REGEN Position                  */
#define VREF_SC_REGEN(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< VREF_SC.REGEN Field                     */
#define VREF_SC_VREFEN_MASK                      (0x80U)                                             /*!< VREF_SC.VREFEN Mask                     */
#define VREF_SC_VREFEN_SHIFT                     (7U)                                                /*!< VREF_SC.VREFEN Position                 */
#define VREF_SC_VREFEN(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< VREF_SC.VREFEN Field                    */
/**
 * @} */ /* End group VREF_Register_Masks_GROUP 
 */

/* VREF - Peripheral instance base addresses */
#define VREF_BasePtr                   0x40074000UL //!< Peripheral base address
#define VREF                           ((VREF_Type *) VREF_BasePtr) //!< Freescale base pointer
#define VREF_BASE_PTR                  (VREF) //!< Freescale style base pointer
/**
 * @} */ /* End group VREF_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup WDOG_Peripheral_access_layer_GROUP WDOG Peripheral Access Layer
* @brief C Struct for WDOG
* @{
*/

/* ================================================================================ */
/* ================           WDOG (file:WDOG_MK)                  ================ */
/* ================================================================================ */

/**
 * @brief Watchdog Timer
 */
/**
* @addtogroup WDOG_structs_GROUP WDOG struct
* @brief Struct for WDOG
* @{
*/
typedef struct {                                /*       WDOG Structure                                               */
   __IO uint16_t  STCTRLH;                      /**< 0000: Status and Control Register High                             */
   __IO uint16_t  STCTRLL;                      /**< 0002: Status and Control Register Low                              */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  TOVAL;                     /**< 0004: Time-out Value Register High TOVALL:TOVALH                   */
      struct {                                  /**< 0000: (size=0004)                                                  */
         __IO uint16_t  TOVALH;                 /**< 0004: Time-out Value Register High                                 */
         __IO uint16_t  TOVALL;                 /**< 0006: Time-out Value Register Low                                  */
      };
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  WIN;                       /**< 0008: Window Register (WINL:WINH)                                  */
      struct {                                  /**< 0000: (size=0004)                                                  */
         __IO uint16_t  WINH;                   /**< 0008: Window Register High                                         */
         __IO uint16_t  WINL;                   /**< 000A: Window Register Low                                          */
      };
   };
   __IO uint16_t  REFRESH;                      /**< 000C: Refresh Register                                             */
   __IO uint16_t  UNLOCK;                       /**< 000E: Unlock Register                                              */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  TMROUT;                    /**< 0010: Timer Output Register (TMROUTL:TMROUTH)                      */
      struct {                                  /**< 0000: (size=0004)                                                  */
         __IO uint16_t  TMROUTH;                /**< 0010: Timer Output Register High                                   */
         __IO uint16_t  TMROUTL;                /**< 0012: Timer Output Register Low                                    */
      };
   };
   __IO uint16_t  RSTCNT;                       /**< 0014: Reset Count Register                                         */
   __IO uint16_t  PRESC;                        /**< 0016: Prescaler Register                                           */
} WDOG_Type;

/**
 * @} */ /* End group WDOG_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'WDOG' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup WDOG_Register_Masks_GROUP WDOG Register Masks
* @brief Register Masks for WDOG
* @{
*/
/* ------- STCTRLH Bit Fields                       ------ */
#define WDOG_STCTRLH_WDOGEN_MASK                 (0x1U)                                              /*!< WDOG_STCTRLH.WDOGEN Mask                */
#define WDOG_STCTRLH_WDOGEN_SHIFT                (0U)                                                /*!< WDOG_STCTRLH.WDOGEN Position            */
#define WDOG_STCTRLH_WDOGEN(x)                   (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< WDOG_STCTRLH.WDOGEN Field               */
#define WDOG_STCTRLH_CLKSRC_MASK                 (0x2U)                                              /*!< WDOG_STCTRLH.CLKSRC Mask                */
#define WDOG_STCTRLH_CLKSRC_SHIFT                (1U)                                                /*!< WDOG_STCTRLH.CLKSRC Position            */
#define WDOG_STCTRLH_CLKSRC(x)                   (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< WDOG_STCTRLH.CLKSRC Field               */
#define WDOG_STCTRLH_IRQRSTEN_MASK               (0x4U)                                              /*!< WDOG_STCTRLH.IRQRSTEN Mask              */
#define WDOG_STCTRLH_IRQRSTEN_SHIFT              (2U)                                                /*!< WDOG_STCTRLH.IRQRSTEN Position          */
#define WDOG_STCTRLH_IRQRSTEN(x)                 (((uint16_t)(((uint16_t)(x))<<2U))&0x4UL)           /*!< WDOG_STCTRLH.IRQRSTEN Field             */
#define WDOG_STCTRLH_WINEN_MASK                  (0x8U)                                              /*!< WDOG_STCTRLH.WINEN Mask                 */
#define WDOG_STCTRLH_WINEN_SHIFT                 (3U)                                                /*!< WDOG_STCTRLH.WINEN Position             */
#define WDOG_STCTRLH_WINEN(x)                    (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< WDOG_STCTRLH.WINEN Field                */
#define WDOG_STCTRLH_ALLOWUPDATE_MASK            (0x10U)                                             /*!< WDOG_STCTRLH.ALLOWUPDATE Mask           */
#define WDOG_STCTRLH_ALLOWUPDATE_SHIFT           (4U)                                                /*!< WDOG_STCTRLH.ALLOWUPDATE Position       */
#define WDOG_STCTRLH_ALLOWUPDATE(x)              (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< WDOG_STCTRLH.ALLOWUPDATE Field          */
#define WDOG_STCTRLH_DBGEN_MASK                  (0x20U)                                             /*!< WDOG_STCTRLH.DBGEN Mask                 */
#define WDOG_STCTRLH_DBGEN_SHIFT                 (5U)                                                /*!< WDOG_STCTRLH.DBGEN Position             */
#define WDOG_STCTRLH_DBGEN(x)                    (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< WDOG_STCTRLH.DBGEN Field                */
#define WDOG_STCTRLH_STOPEN_MASK                 (0x40U)                                             /*!< WDOG_STCTRLH.STOPEN Mask                */
#define WDOG_STCTRLH_STOPEN_SHIFT                (6U)                                                /*!< WDOG_STCTRLH.STOPEN Position            */
#define WDOG_STCTRLH_STOPEN(x)                   (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< WDOG_STCTRLH.STOPEN Field               */
#define WDOG_STCTRLH_WAITEN_MASK                 (0x80U)                                             /*!< WDOG_STCTRLH.WAITEN Mask                */
#define WDOG_STCTRLH_WAITEN_SHIFT                (7U)                                                /*!< WDOG_STCTRLH.WAITEN Position            */
#define WDOG_STCTRLH_WAITEN(x)                   (((uint16_t)(((uint16_t)(x))<<7U))&0x80UL)          /*!< WDOG_STCTRLH.WAITEN Field               */
#define WDOG_STCTRLH_TESTWDOG_MASK               (0x400U)                                            /*!< WDOG_STCTRLH.TESTWDOG Mask              */
#define WDOG_STCTRLH_TESTWDOG_SHIFT              (10U)                                               /*!< WDOG_STCTRLH.TESTWDOG Position          */
#define WDOG_STCTRLH_TESTWDOG(x)                 (((uint16_t)(((uint16_t)(x))<<10U))&0x400UL)        /*!< WDOG_STCTRLH.TESTWDOG Field             */
#define WDOG_STCTRLH_TESTSEL_MASK                (0x800U)                                            /*!< WDOG_STCTRLH.TESTSEL Mask               */
#define WDOG_STCTRLH_TESTSEL_SHIFT               (11U)                                               /*!< WDOG_STCTRLH.TESTSEL Position           */
#define WDOG_STCTRLH_TESTSEL(x)                  (((uint16_t)(((uint16_t)(x))<<11U))&0x800UL)        /*!< WDOG_STCTRLH.TESTSEL Field              */
#define WDOG_STCTRLH_BYTESEL_MASK                (0x3000U)                                           /*!< WDOG_STCTRLH.BYTESEL Mask               */
#define WDOG_STCTRLH_BYTESEL_SHIFT               (12U)                                               /*!< WDOG_STCTRLH.BYTESEL Position           */
#define WDOG_STCTRLH_BYTESEL(x)                  (((uint16_t)(((uint16_t)(x))<<12U))&0x3000UL)       /*!< WDOG_STCTRLH.BYTESEL Field              */
#define WDOG_STCTRLH_DISTESTWDOG_MASK            (0x4000U)                                           /*!< WDOG_STCTRLH.DISTESTWDOG Mask           */
#define WDOG_STCTRLH_DISTESTWDOG_SHIFT           (14U)                                               /*!< WDOG_STCTRLH.DISTESTWDOG Position       */
#define WDOG_STCTRLH_DISTESTWDOG(x)              (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< WDOG_STCTRLH.DISTESTWDOG Field          */
/* ------- STCTRLL Bit Fields                       ------ */
#define WDOG_STCTRLL_INTFLG_MASK                 (0x8000U)                                           /*!< WDOG_STCTRLL.INTFLG Mask                */
#define WDOG_STCTRLL_INTFLG_SHIFT                (15U)                                               /*!< WDOG_STCTRLL.INTFLG Position            */
#define WDOG_STCTRLL_INTFLG(x)                   (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< WDOG_STCTRLL.INTFLG Field               */
/* ------- TOVAL Bit Fields                         ------ */
#define WDOG_TOVAL_TOVAL_MASK                    (0xFFFFFFFFU)                                       /*!< WDOG_TOVAL.TOVAL Mask                   */
#define WDOG_TOVAL_TOVAL_SHIFT                   (0U)                                                /*!< WDOG_TOVAL.TOVAL Position               */
#define WDOG_TOVAL_TOVAL(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< WDOG_TOVAL.TOVAL Field                  */
/* ------- TOVALH Bit Fields                        ------ */
#define WDOG_TOVALH_TOVALHIGH_MASK               (0xFFFFU)                                           /*!< WDOG_TOVALH.TOVALHIGH Mask              */
#define WDOG_TOVALH_TOVALHIGH_SHIFT              (0U)                                                /*!< WDOG_TOVALH.TOVALHIGH Position          */
#define WDOG_TOVALH_TOVALHIGH(x)                 (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< WDOG_TOVALH.TOVALHIGH Field             */
/* ------- TOVALL Bit Fields                        ------ */
#define WDOG_TOVALL_TOVALLOW_MASK                (0xFFFFU)                                           /*!< WDOG_TOVALL.TOVALLOW Mask               */
#define WDOG_TOVALL_TOVALLOW_SHIFT               (0U)                                                /*!< WDOG_TOVALL.TOVALLOW Position           */
#define WDOG_TOVALL_TOVALLOW(x)                  (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< WDOG_TOVALL.TOVALLOW Field              */
/* ------- WIN Bit Fields                           ------ */
#define WDOG_WIN_WIN_MASK                        (0xFFFFFFFFU)                                       /*!< WDOG_WIN.WIN Mask                       */
#define WDOG_WIN_WIN_SHIFT                       (0U)                                                /*!< WDOG_WIN.WIN Position                   */
#define WDOG_WIN_WIN(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< WDOG_WIN.WIN Field                      */
/* ------- WINH Bit Fields                          ------ */
#define WDOG_WINH_WINHIGH_MASK                   (0xFFFFU)                                           /*!< WDOG_WINH.WINHIGH Mask                  */
#define WDOG_WINH_WINHIGH_SHIFT                  (0U)                                                /*!< WDOG_WINH.WINHIGH Position              */
#define WDOG_WINH_WINHIGH(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< WDOG_WINH.WINHIGH Field                 */
/* ------- WINL Bit Fields                          ------ */
#define WDOG_WINL_WINLOW_MASK                    (0xFFFFU)                                           /*!< WDOG_WINL.WINLOW Mask                   */
#define WDOG_WINL_WINLOW_SHIFT                   (0U)                                                /*!< WDOG_WINL.WINLOW Position               */
#define WDOG_WINL_WINLOW(x)                      (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< WDOG_WINL.WINLOW Field                  */
/* ------- REFRESH Bit Fields                       ------ */
#define WDOG_REFRESH_WDOGREFRESH_MASK            (0xFFFFU)                                           /*!< WDOG_REFRESH.WDOGREFRESH Mask           */
#define WDOG_REFRESH_WDOGREFRESH_SHIFT           (0U)                                                /*!< WDOG_REFRESH.WDOGREFRESH Position       */
#define WDOG_REFRESH_WDOGREFRESH(x)              (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< WDOG_REFRESH.WDOGREFRESH Field          */
/* ------- UNLOCK Bit Fields                        ------ */
#define WDOG_UNLOCK_WDOGUNLOCK_MASK              (0xFFFFU)                                           /*!< WDOG_UNLOCK.WDOGUNLOCK Mask             */
#define WDOG_UNLOCK_WDOGUNLOCK_SHIFT             (0U)                                                /*!< WDOG_UNLOCK.WDOGUNLOCK Position         */
#define WDOG_UNLOCK_WDOGUNLOCK(x)                (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< WDOG_UNLOCK.WDOGUNLOCK Field            */
/* ------- TMROUT Bit Fields                        ------ */
#define WDOG_TMROUT_TIMEROUTHIGH_MASK            (0xFFFFFFFFU)                                       /*!< WDOG_TMROUT.TIMEROUTHIGH Mask           */
#define WDOG_TMROUT_TIMEROUTHIGH_SHIFT           (0U)                                                /*!< WDOG_TMROUT.TIMEROUTHIGH Position       */
#define WDOG_TMROUT_TIMEROUTHIGH(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< WDOG_TMROUT.TIMEROUTHIGH Field          */
/* ------- TMROUTH Bit Fields                       ------ */
#define WDOG_TMROUTH_TIMEROUTHIGH_MASK           (0xFFFFU)                                           /*!< WDOG_TMROUTH.TIMEROUTHIGH Mask          */
#define WDOG_TMROUTH_TIMEROUTHIGH_SHIFT          (0U)                                                /*!< WDOG_TMROUTH.TIMEROUTHIGH Position      */
#define WDOG_TMROUTH_TIMEROUTHIGH(x)             (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< WDOG_TMROUTH.TIMEROUTHIGH Field         */
/* ------- TMROUTL Bit Fields                       ------ */
#define WDOG_TMROUTL_TIMEROUTLOW_MASK            (0xFFFFU)                                           /*!< WDOG_TMROUTL.TIMEROUTLOW Mask           */
#define WDOG_TMROUTL_TIMEROUTLOW_SHIFT           (0U)                                                /*!< WDOG_TMROUTL.TIMEROUTLOW Position       */
#define WDOG_TMROUTL_TIMEROUTLOW(x)              (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< WDOG_TMROUTL.TIMEROUTLOW Field          */
/* ------- RSTCNT Bit Fields                        ------ */
#define WDOG_RSTCNT_RSTCNT_MASK                  (0xFFFFU)                                           /*!< WDOG_RSTCNT.RSTCNT Mask                 */
#define WDOG_RSTCNT_RSTCNT_SHIFT                 (0U)                                                /*!< WDOG_RSTCNT.RSTCNT Position             */
#define WDOG_RSTCNT_RSTCNT(x)                    (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< WDOG_RSTCNT.RSTCNT Field                */
/* ------- PRESC Bit Fields                         ------ */
#define WDOG_PRESC_PRESCVAL_MASK                 (0x700U)                                            /*!< WDOG_PRESC.PRESCVAL Mask                */
#define WDOG_PRESC_PRESCVAL_SHIFT                (8U)                                                /*!< WDOG_PRESC.PRESCVAL Position            */
#define WDOG_PRESC_PRESCVAL(x)                   (((uint16_t)(((uint16_t)(x))<<8U))&0x700UL)         /*!< WDOG_PRESC.PRESCVAL Field               */
/**
 * @} */ /* End group WDOG_Register_Masks_GROUP 
 */

/* WDOG - Peripheral instance base addresses */
#define WDOG_BasePtr                   0x40052000UL //!< Peripheral base address
#define WDOG                           ((WDOG_Type *) WDOG_BasePtr) //!< Freescale base pointer
#define WDOG_BASE_PTR                  (WDOG) //!< Freescale style base pointer
/**
 * @} */ /* End group WDOG_Peripheral_access_layer_GROUP 
 */
/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif
/**
 * @} */ /* End group Peripheral_access_layer_GROUP 
 */

#ifdef __cplusplus
}
#endif


#endif  /* MCU_MKL82Z7 */

