/****************************************************************************************************//**
 * @file     MK30D7.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for MK30D7.
 *           Equivalent: 
 *
 * @version  V1.6
 * @date     2016/06
 *
 *******************************************************************************************************/

#ifndef MCU_MK30D7
#define MCU_MK30D7

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
  MemoryManagement_IRQn         = -12,   /**<   4 Memory Management, MPU mismatch, including Access Violation and No Match         */
  BusFault_IRQn                 = -11,   /**<   5 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault   */
  UsageFault_IRQn               = -10,   /**<   6 Usage Fault, i.e. Undef Instruction, Illegal State Transition                    */
  SVCall_IRQn                   =  -5,   /**<  11 System Service Call via SVC instruction                                          */
  DebugMonitor_IRQn             =  -4,   /**<  12 Debug Monitor                                                                    */
  PendSV_IRQn                   =  -2,   /**<  14 Pendable request for system service                                              */
  SysTick_IRQn                  =  -1,   /**<  15 System Tick Timer                                                                */
/* ----------------------   MK30D7 VectorTable                       ---------------------- */
  DMA0_IRQn                     =   0,   /**<  16 Direct memory access controller                                                  */
  DMA1_IRQn                     =   1,   /**<  17 Direct memory access controller                                                  */
  DMA2_IRQn                     =   2,   /**<  18 Direct memory access controller                                                  */
  DMA3_IRQn                     =   3,   /**<  19 Direct memory access controller                                                  */
  DMA4_IRQn                     =   4,   /**<  20 Direct memory access controller                                                  */
  DMA5_IRQn                     =   5,   /**<  21 Direct memory access controller                                                  */
  DMA6_IRQn                     =   6,   /**<  22 Direct memory access controller                                                  */
  DMA7_IRQn                     =   7,   /**<  23 Direct memory access controller                                                  */
  DMA8_IRQn                     =   8,   /**<  24 Direct memory access controller                                                  */
  DMA9_IRQn                     =   9,   /**<  25 Direct memory access controller                                                  */
  DMA10_IRQn                    =  10,   /**<  26 Direct memory access controller                                                  */
  DMA11_IRQn                    =  11,   /**<  27 Direct memory access controller                                                  */
  DMA12_IRQn                    =  12,   /**<  28 Direct memory access controller                                                  */
  DMA13_IRQn                    =  13,   /**<  29 Direct memory access controller                                                  */
  DMA14_IRQn                    =  14,   /**<  30 Direct memory access controller                                                  */
  DMA15_IRQn                    =  15,   /**<  31 Direct memory access controller                                                  */
  DMA_Error_IRQn                =  16,   /**<  32 DMA error interrupt all channels                                                 */
  FTF_Command_IRQn              =  18,   /**<  34 Flash Memory Interface                                                           */
  FTF_ReadCollision_IRQn        =  19,   /**<  35 Flash Memory Interface                                                           */
  PMC_IRQn                      =  20,   /**<  36 Power Management Controller                                                      */
  LLWU_IRQn                     =  21,   /**<  37 Low Leakage Wakeup                                                               */
  WDOG_IRQn                     =  22,   /**<  38 External Watchdog Monitor                                                        */
  I2C0_IRQn                     =  24,   /**<  40 Inter-Integrated Circuit                                                         */
  I2C1_IRQn                     =  25,   /**<  41 Inter-Integrated Circuit                                                         */
  SPI0_IRQn                     =  26,   /**<  42 Serial Peripheral Interface                                                      */
  SPI1_IRQn                     =  27,   /**<  43 Serial Peripheral Interface                                                      */
  CAN0_Message_IRQn             =  29,   /**<  45 Flex Controller Area Network module                                              */
  CAN0_BusOff_IRQn              =  30,   /**<  46 Flex Controller Area Network module                                              */
  CAN0_Error_IRQn               =  31,   /**<  47 Flex Controller Area Network module                                              */
  CAN0_Tx_IRQn                  =  32,   /**<  48 Flex Controller Area Network module                                              */
  CAN0_Rx_IRQn                  =  33,   /**<  49 Flex Controller Area Network module                                              */
  CAN0_WakeUp_IRQn              =  34,   /**<  50 Flex Controller Area Network module                                              */
  I2S0_Tx_IRQn                  =  35,   /**<  51 Synchronous Serial Interface                                                     */
  I2S0_Rx_IRQn                  =  36,   /**<  52 Synchronous Serial Interface                                                     */
  UART0_LON_IRQn                =  44,   /**<  60 Serial Communication Interface                                                   */
  UART0_RX_TX_IRQn              =  45,   /**<  61 Serial Communication Interface                                                   */
  UART0_ERR_IRQn                =  46,   /**<  62 Serial Communication Interface                                                   */
  UART1_RX_TX_IRQn              =  47,   /**<  63 Serial Communication Interface                                                   */
  UART1_ERR_IRQn                =  48,   /**<  64 Serial Communication Interface                                                   */
  UART2_RX_TX_IRQn              =  49,   /**<  65 Serial Communication Interface                                                   */
  UART2_ERR_IRQn                =  50,   /**<  66 Serial Communication Interface                                                   */
  UART3_RX_TX_IRQn              =  51,   /**<  67 Serial Communication Interface                                                   */
  UART3_ERR_IRQn                =  52,   /**<  68 Serial Communication Interface                                                   */
  UART4_RX_TX_IRQn              =  53,   /**<  69 Serial Communication Interface                                                   */
  UART4_ERR_IRQn                =  54,   /**<  70 Serial Communication Interface                                                   */
  ADC0_IRQn                     =  57,   /**<  73 Analogue to Digital Converter                                                    */
  ADC1_IRQn                     =  58,   /**<  74 Analogue to Digital Converter                                                    */
  CMP0_IRQn                     =  59,   /**<  75 High-Speed Comparator                                                            */
  CMP1_IRQn                     =  60,   /**<  76 High-Speed Comparator                                                            */
  CMP2_IRQn                     =  61,   /**<  77 High-Speed Comparator                                                            */
  FTM0_IRQn                     =  62,   /**<  78 FlexTimer Module                                                                 */
  FTM1_IRQn                     =  63,   /**<  79 FlexTimer Module                                                                 */
  FTM2_IRQn                     =  64,   /**<  80 FlexTimer Module                                                                 */
  CMT_IRQn                      =  65,   /**<  81 Carrier Modulator Transmitter                                                    */
  RTC_Alarm_IRQn                =  66,   /**<  82 Real Time Clock                                                                  */
  RTC_Seconds_IRQn              =  67,   /**<  83 Real Time Clock                                                                  */
  PIT0_IRQn                     =  68,   /**<  84 Periodic Interrupt Timer                                                         */
  PIT1_IRQn                     =  69,   /**<  85 Periodic Interrupt Timer                                                         */
  PIT2_IRQn                     =  70,   /**<  86 Periodic Interrupt Timer                                                         */
  PIT3_IRQn                     =  71,   /**<  87 Periodic Interrupt Timer                                                         */
  PDB0_IRQn                     =  72,   /**<  88 Programmable Delay Block                                                         */
  DAC0_IRQn                     =  81,   /**<  97 Digital to Analogue Converter                                                    */
  TSI0_IRQn                     =  83,   /**<  99 Touch Sense Interface                                                            */
  MCG_IRQn                      =  84,   /**< 100 Multipurpose Clock Generator                                                     */
  LPTMR0_IRQn                   =  85,   /**< 101 Low Power Timer                                                                  */
  LCD_IRQn                      =  86,   /**< 102 Segment Liquid Crystal Display                                                   */
  PORTA_IRQn                    =  87,   /**< 103 General Purpose Input/Output                                                     */
  PORTB_IRQn                    =  88,   /**< 104 General Purpose Input/Output                                                     */
  PORTC_IRQn                    =  89,   /**< 105 General Purpose Input/Output                                                     */
  PORTD_IRQn                    =  90,   /**< 106 General Purpose Input/Output                                                     */
  PORTE_IRQn                    =  91,   /**< 107 General Purpose Input/Output                                                     */
  SWI_IRQn                      =  94,   /**< 110 Software interrupt                                                               */
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
extern void MemManage_Handler(void);           /**< Memory Management, MPU mismatch, including Access Violation and No Match         */
extern void BusFault_Handler(void);            /**< Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault   */
extern void UsageFault_Handler(void);          /**< Usage Fault, i.e. Undef Instruction, Illegal State Transition                    */
extern void SVC_Handler(void);                 /**< System Service Call via SVC instruction                                          */
extern void DebugMon_Handler(void);            /**< Debug Monitor                                                                    */
extern void PendSV_Handler(void);              /**< Pendable request for system service                                              */
extern void SysTick_Handler(void);             /**< System Tick Timer                                                                */
extern void DMA0_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA1_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA2_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA3_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA4_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA5_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA6_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA7_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA8_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA9_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA10_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA11_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA12_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA13_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA14_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA15_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA_Error_IRQHandler(void);        /**< DMA error interrupt all channels                                                 */
extern void FTF_Command_IRQHandler(void);      /**< Flash Memory Interface                                                           */
extern void FTF_ReadCollision_IRQHandler(void);   /**< Flash Memory Interface                                                           */
extern void PMC_IRQHandler(void);              /**< Power Management Controller                                                      */
extern void LLWU_IRQHandler(void);             /**< Low Leakage Wakeup                                                               */
extern void WDOG_IRQHandler(void);             /**< External Watchdog Monitor                                                        */
extern void I2C0_IRQHandler(void);             /**< Inter-Integrated Circuit                                                         */
extern void I2C1_IRQHandler(void);             /**< Inter-Integrated Circuit                                                         */
extern void SPI0_IRQHandler(void);             /**< Serial Peripheral Interface                                                      */
extern void SPI1_IRQHandler(void);             /**< Serial Peripheral Interface                                                      */
extern void CAN0_Message_IRQHandler(void);     /**< Flex Controller Area Network module                                              */
extern void CAN0_BusOff_IRQHandler(void);      /**< Flex Controller Area Network module                                              */
extern void CAN0_Error_IRQHandler(void);       /**< Flex Controller Area Network module                                              */
extern void CAN0_Tx_IRQHandler(void);          /**< Flex Controller Area Network module                                              */
extern void CAN0_Rx_IRQHandler(void);          /**< Flex Controller Area Network module                                              */
extern void CAN0_WakeUp_IRQHandler(void);      /**< Flex Controller Area Network module                                              */
extern void I2S0_Tx_IRQHandler(void);          /**< Synchronous Serial Interface                                                     */
extern void I2S0_Rx_IRQHandler(void);          /**< Synchronous Serial Interface                                                     */
extern void UART0_LON_IRQHandler(void);        /**< Serial Communication Interface                                                   */
extern void UART0_RX_TX_IRQHandler(void);      /**< Serial Communication Interface                                                   */
extern void UART0_ERR_IRQHandler(void);        /**< Serial Communication Interface                                                   */
extern void UART1_RX_TX_IRQHandler(void);      /**< Serial Communication Interface                                                   */
extern void UART1_ERR_IRQHandler(void);        /**< Serial Communication Interface                                                   */
extern void UART2_RX_TX_IRQHandler(void);      /**< Serial Communication Interface                                                   */
extern void UART2_ERR_IRQHandler(void);        /**< Serial Communication Interface                                                   */
extern void UART3_RX_TX_IRQHandler(void);      /**< Serial Communication Interface                                                   */
extern void UART3_ERR_IRQHandler(void);        /**< Serial Communication Interface                                                   */
extern void UART4_RX_TX_IRQHandler(void);      /**< Serial Communication Interface                                                   */
extern void UART4_ERR_IRQHandler(void);        /**< Serial Communication Interface                                                   */
extern void ADC0_IRQHandler(void);             /**< Analogue to Digital Converter                                                    */
extern void ADC1_IRQHandler(void);             /**< Analogue to Digital Converter                                                    */
extern void CMP0_IRQHandler(void);             /**< High-Speed Comparator                                                            */
extern void CMP1_IRQHandler(void);             /**< High-Speed Comparator                                                            */
extern void CMP2_IRQHandler(void);             /**< High-Speed Comparator                                                            */
extern void FTM0_IRQHandler(void);             /**< FlexTimer Module                                                                 */
extern void FTM1_IRQHandler(void);             /**< FlexTimer Module                                                                 */
extern void FTM2_IRQHandler(void);             /**< FlexTimer Module                                                                 */
extern void CMT_IRQHandler(void);              /**< Carrier Modulator Transmitter                                                    */
extern void RTC_Alarm_IRQHandler(void);        /**< Real Time Clock                                                                  */
extern void RTC_Seconds_IRQHandler(void);      /**< Real Time Clock                                                                  */
extern void PIT0_IRQHandler(void);             /**< Periodic Interrupt Timer                                                         */
extern void PIT1_IRQHandler(void);             /**< Periodic Interrupt Timer                                                         */
extern void PIT2_IRQHandler(void);             /**< Periodic Interrupt Timer                                                         */
extern void PIT3_IRQHandler(void);             /**< Periodic Interrupt Timer                                                         */
extern void PDB0_IRQHandler(void);             /**< Programmable Delay Block                                                         */
extern void DAC0_IRQHandler(void);             /**< Digital to Analogue Converter                                                    */
extern void TSI0_IRQHandler(void);             /**< Touch Sense Interface                                                            */
extern void MCG_IRQHandler(void);              /**< Multipurpose Clock Generator                                                     */
extern void LPTMR0_IRQHandler(void);           /**< Low Power Timer                                                                  */
extern void LCD_IRQHandler(void);              /**< Segment Liquid Crystal Display                                                   */
extern void PORTA_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTB_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTC_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTD_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTE_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void SWI_IRQHandler(void);              /**< Software interrupt                                                               */

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
#define __CM4_REV                 0x0100     /**< CPU Revision                                        */
#define __MPU_PRESENT             0          /**< Whether MPU is present                              */
#define __NVIC_PRIO_BITS          4          /**< Number of implemented bits in NVIC PRIO register    */
#define __Vendor_SysTickConfig    0          /**< Whether Vendor implemented SYSTICK timer is present */
#define __FPU_PRESENT             0          /**< Whether FPU is present                              */
#define __VTOR_PRESENT            1          /**< Whether VTOR register is present                    */

/**
 * @} */ /* End group Cortex_Core_Configuration_GROUP 
 */
#include "core_cm4.h"           /* Processor and core peripherals     */
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
/* ================           ADC0 (file:ADC0_DIFF_PGA_A)          ================ */
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
   __IO uint32_t  SC1[2];                       /**< 0000: Status and Control Register 1                                */
   __IO uint32_t  CFG1;                         /**< 0008: Configuration Register 1                                     */
   __IO uint32_t  CFG2;                         /**< 000C: Configuration Register 2                                     */
   __I  uint32_t  R[2];                         /**< 0010: Data Result Register                                         */
   __IO uint32_t  CV1;                          /**< 0018: Compare Value                                                */
   __IO uint32_t  CV2;                          /**< 001C: Compare Value                                                */
   __IO uint32_t  SC2;                          /**< 0020: Status and Control Register 2                                */
   __IO uint32_t  SC3;                          /**< 0024: Status and Control Register 3                                */
   __IO uint32_t  OFS;                          /**< 0028: Offset Correction Register                                   */
   __IO uint32_t  PG;                           /**< 002C: Plus-Side Gain Register                                      */
   __IO uint32_t  MG;                           /**< 0030: Minus-Side Gain Register                                     */
   __IO uint32_t  CLPD;                         /**< 0034: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLPS;                         /**< 0038: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP4;                         /**< 003C: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP3;                         /**< 0040: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP2;                         /**< 0044: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP1;                         /**< 0048: Plus-Side General Calibration Value                          */
   __IO uint32_t  CLP0;                         /**< 004C: Plus-Side General Calibration Value                          */
   __IO uint32_t  PGA;                          /**< 0050: PGA Register                                                 */
   __IO uint32_t  CLMD;                         /**< 0054: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLMS;                         /**< 0058: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM4;                         /**< 005C: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM3;                         /**< 0060: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM2;                         /**< 0064: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM1;                         /**< 0068: Minus-Side General Calibration Value                         */
   __IO uint32_t  CLM0;                         /**< 006C: Minus-Side General Calibration Value                         */
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
#define ADC_SC1_ADCH_MASK                        (0x1FUL << ADC_SC1_ADCH_SHIFT)                      /*!< ADC0_SC1: ADCH Mask                     */
#define ADC_SC1_ADCH_SHIFT                       0                                                   /*!< ADC0_SC1: ADCH Position                 */
#define ADC_SC1_ADCH(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_ADCH_SHIFT))&ADC_SC1_ADCH_MASK) /*!< ADC0_SC1                                */
#define ADC_SC1_DIFF_MASK                        (0x01UL << ADC_SC1_DIFF_SHIFT)                      /*!< ADC0_SC1: DIFF Mask                     */
#define ADC_SC1_DIFF_SHIFT                       5                                                   /*!< ADC0_SC1: DIFF Position                 */
#define ADC_SC1_DIFF(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_DIFF_SHIFT))&ADC_SC1_DIFF_MASK) /*!< ADC0_SC1                                */
#define ADC_SC1_AIEN_MASK                        (0x01UL << ADC_SC1_AIEN_SHIFT)                      /*!< ADC0_SC1: AIEN Mask                     */
#define ADC_SC1_AIEN_SHIFT                       6                                                   /*!< ADC0_SC1: AIEN Position                 */
#define ADC_SC1_AIEN(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_AIEN_SHIFT))&ADC_SC1_AIEN_MASK) /*!< ADC0_SC1                                */
#define ADC_SC1_COCO_MASK                        (0x01UL << ADC_SC1_COCO_SHIFT)                      /*!< ADC0_SC1: COCO Mask                     */
#define ADC_SC1_COCO_SHIFT                       7                                                   /*!< ADC0_SC1: COCO Position                 */
#define ADC_SC1_COCO(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_COCO_SHIFT))&ADC_SC1_COCO_MASK) /*!< ADC0_SC1                                */
/* ------- CFG1 Bit Fields                          ------ */
#define ADC_CFG1_ADICLK_MASK                     (0x03UL << ADC_CFG1_ADICLK_SHIFT)                   /*!< ADC0_CFG1: ADICLK Mask                  */
#define ADC_CFG1_ADICLK_SHIFT                    0                                                   /*!< ADC0_CFG1: ADICLK Position              */
#define ADC_CFG1_ADICLK(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADICLK_SHIFT))&ADC_CFG1_ADICLK_MASK) /*!< ADC0_CFG1                               */
#define ADC_CFG1_MODE_MASK                       (0x03UL << ADC_CFG1_MODE_SHIFT)                     /*!< ADC0_CFG1: MODE Mask                    */
#define ADC_CFG1_MODE_SHIFT                      2                                                   /*!< ADC0_CFG1: MODE Position                */
#define ADC_CFG1_MODE(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_MODE_SHIFT))&ADC_CFG1_MODE_MASK) /*!< ADC0_CFG1                               */
#define ADC_CFG1_ADLSMP_MASK                     (0x01UL << ADC_CFG1_ADLSMP_SHIFT)                   /*!< ADC0_CFG1: ADLSMP Mask                  */
#define ADC_CFG1_ADLSMP_SHIFT                    4                                                   /*!< ADC0_CFG1: ADLSMP Position              */
#define ADC_CFG1_ADLSMP(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADLSMP_SHIFT))&ADC_CFG1_ADLSMP_MASK) /*!< ADC0_CFG1                               */
#define ADC_CFG1_ADIV_MASK                       (0x03UL << ADC_CFG1_ADIV_SHIFT)                     /*!< ADC0_CFG1: ADIV Mask                    */
#define ADC_CFG1_ADIV_SHIFT                      5                                                   /*!< ADC0_CFG1: ADIV Position                */
#define ADC_CFG1_ADIV(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADIV_SHIFT))&ADC_CFG1_ADIV_MASK) /*!< ADC0_CFG1                               */
#define ADC_CFG1_ADLPC_MASK                      (0x01UL << ADC_CFG1_ADLPC_SHIFT)                    /*!< ADC0_CFG1: ADLPC Mask                   */
#define ADC_CFG1_ADLPC_SHIFT                     7                                                   /*!< ADC0_CFG1: ADLPC Position               */
#define ADC_CFG1_ADLPC(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ADLPC_SHIFT))&ADC_CFG1_ADLPC_MASK) /*!< ADC0_CFG1                               */
/* ------- CFG2 Bit Fields                          ------ */
#define ADC_CFG2_ADLSTS_MASK                     (0x03UL << ADC_CFG2_ADLSTS_SHIFT)                   /*!< ADC0_CFG2: ADLSTS Mask                  */
#define ADC_CFG2_ADLSTS_SHIFT                    0                                                   /*!< ADC0_CFG2: ADLSTS Position              */
#define ADC_CFG2_ADLSTS(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADLSTS_SHIFT))&ADC_CFG2_ADLSTS_MASK) /*!< ADC0_CFG2                               */
#define ADC_CFG2_ADHSC_MASK                      (0x01UL << ADC_CFG2_ADHSC_SHIFT)                    /*!< ADC0_CFG2: ADHSC Mask                   */
#define ADC_CFG2_ADHSC_SHIFT                     2                                                   /*!< ADC0_CFG2: ADHSC Position               */
#define ADC_CFG2_ADHSC(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADHSC_SHIFT))&ADC_CFG2_ADHSC_MASK) /*!< ADC0_CFG2                               */
#define ADC_CFG2_ADACKEN_MASK                    (0x01UL << ADC_CFG2_ADACKEN_SHIFT)                  /*!< ADC0_CFG2: ADACKEN Mask                 */
#define ADC_CFG2_ADACKEN_SHIFT                   3                                                   /*!< ADC0_CFG2: ADACKEN Position             */
#define ADC_CFG2_ADACKEN(x)                      (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_ADACKEN_SHIFT))&ADC_CFG2_ADACKEN_MASK) /*!< ADC0_CFG2                               */
#define ADC_CFG2_MUXSEL_MASK                     (0x01UL << ADC_CFG2_MUXSEL_SHIFT)                   /*!< ADC0_CFG2: MUXSEL Mask                  */
#define ADC_CFG2_MUXSEL_SHIFT                    4                                                   /*!< ADC0_CFG2: MUXSEL Position              */
#define ADC_CFG2_MUXSEL(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_MUXSEL_SHIFT))&ADC_CFG2_MUXSEL_MASK) /*!< ADC0_CFG2                               */
/* ------- R Bit Fields                             ------ */
#define ADC_R_D_MASK                             (0xFFFFUL << ADC_R_D_SHIFT)                         /*!< ADC0_R: D Mask                          */
#define ADC_R_D_SHIFT                            0                                                   /*!< ADC0_R: D Position                      */
#define ADC_R_D(x)                               (((uint32_t)(((uint32_t)(x))<<ADC_R_D_SHIFT))&ADC_R_D_MASK) /*!< ADC0_R                                  */
/* ------- CV Bit Fields                            ------ */
#define ADC_CV_CV_MASK                           (0xFFFFUL << ADC_CV_CV_SHIFT)                       /*!< ADC0_CV: CV Mask                        */
#define ADC_CV_CV_SHIFT                          0                                                   /*!< ADC0_CV: CV Position                    */
#define ADC_CV_CV(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_CV_CV_SHIFT))&ADC_CV_CV_MASK) /*!< ADC0_CV                                 */
/* ------- SC2 Bit Fields                           ------ */
#define ADC_SC2_REFSEL_MASK                      (0x03UL << ADC_SC2_REFSEL_SHIFT)                    /*!< ADC0_SC2: REFSEL Mask                   */
#define ADC_SC2_REFSEL_SHIFT                     0                                                   /*!< ADC0_SC2: REFSEL Position               */
#define ADC_SC2_REFSEL(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_SC2_REFSEL_SHIFT))&ADC_SC2_REFSEL_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_DMAEN_MASK                       (0x01UL << ADC_SC2_DMAEN_SHIFT)                     /*!< ADC0_SC2: DMAEN Mask                    */
#define ADC_SC2_DMAEN_SHIFT                      2                                                   /*!< ADC0_SC2: DMAEN Position                */
#define ADC_SC2_DMAEN(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_DMAEN_SHIFT))&ADC_SC2_DMAEN_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ACREN_MASK                       (0x01UL << ADC_SC2_ACREN_SHIFT)                     /*!< ADC0_SC2: ACREN Mask                    */
#define ADC_SC2_ACREN_SHIFT                      3                                                   /*!< ADC0_SC2: ACREN Position                */
#define ADC_SC2_ACREN(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ACREN_SHIFT))&ADC_SC2_ACREN_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ACFGT_MASK                       (0x01UL << ADC_SC2_ACFGT_SHIFT)                     /*!< ADC0_SC2: ACFGT Mask                    */
#define ADC_SC2_ACFGT_SHIFT                      4                                                   /*!< ADC0_SC2: ACFGT Position                */
#define ADC_SC2_ACFGT(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ACFGT_SHIFT))&ADC_SC2_ACFGT_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ACFE_MASK                        (0x01UL << ADC_SC2_ACFE_SHIFT)                      /*!< ADC0_SC2: ACFE Mask                     */
#define ADC_SC2_ACFE_SHIFT                       5                                                   /*!< ADC0_SC2: ACFE Position                 */
#define ADC_SC2_ACFE(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ACFE_SHIFT))&ADC_SC2_ACFE_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ADTRG_MASK                       (0x01UL << ADC_SC2_ADTRG_SHIFT)                     /*!< ADC0_SC2: ADTRG Mask                    */
#define ADC_SC2_ADTRG_SHIFT                      6                                                   /*!< ADC0_SC2: ADTRG Position                */
#define ADC_SC2_ADTRG(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ADTRG_SHIFT))&ADC_SC2_ADTRG_MASK) /*!< ADC0_SC2                                */
#define ADC_SC2_ADACT_MASK                       (0x01UL << ADC_SC2_ADACT_SHIFT)                     /*!< ADC0_SC2: ADACT Mask                    */
#define ADC_SC2_ADACT_SHIFT                      7                                                   /*!< ADC0_SC2: ADACT Position                */
#define ADC_SC2_ADACT(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC2_ADACT_SHIFT))&ADC_SC2_ADACT_MASK) /*!< ADC0_SC2                                */
/* ------- SC3 Bit Fields                           ------ */
#define ADC_SC3_AVGS_MASK                        (0x03UL << ADC_SC3_AVGS_SHIFT)                      /*!< ADC0_SC3: AVGS Mask                     */
#define ADC_SC3_AVGS_SHIFT                       0                                                   /*!< ADC0_SC3: AVGS Position                 */
#define ADC_SC3_AVGS(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_AVGS_SHIFT))&ADC_SC3_AVGS_MASK) /*!< ADC0_SC3                                */
#define ADC_SC3_AVGE_MASK                        (0x01UL << ADC_SC3_AVGE_SHIFT)                      /*!< ADC0_SC3: AVGE Mask                     */
#define ADC_SC3_AVGE_SHIFT                       2                                                   /*!< ADC0_SC3: AVGE Position                 */
#define ADC_SC3_AVGE(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_AVGE_SHIFT))&ADC_SC3_AVGE_MASK) /*!< ADC0_SC3                                */
#define ADC_SC3_ADCO_MASK                        (0x01UL << ADC_SC3_ADCO_SHIFT)                      /*!< ADC0_SC3: ADCO Mask                     */
#define ADC_SC3_ADCO_SHIFT                       3                                                   /*!< ADC0_SC3: ADCO Position                 */
#define ADC_SC3_ADCO(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_ADCO_SHIFT))&ADC_SC3_ADCO_MASK) /*!< ADC0_SC3                                */
#define ADC_SC3_CALF_MASK                        (0x01UL << ADC_SC3_CALF_SHIFT)                      /*!< ADC0_SC3: CALF Mask                     */
#define ADC_SC3_CALF_SHIFT                       6                                                   /*!< ADC0_SC3: CALF Position                 */
#define ADC_SC3_CALF(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_CALF_SHIFT))&ADC_SC3_CALF_MASK) /*!< ADC0_SC3                                */
#define ADC_SC3_CAL_MASK                         (0x01UL << ADC_SC3_CAL_SHIFT)                       /*!< ADC0_SC3: CAL Mask                      */
#define ADC_SC3_CAL_SHIFT                        7                                                   /*!< ADC0_SC3: CAL Position                  */
#define ADC_SC3_CAL(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_SC3_CAL_SHIFT))&ADC_SC3_CAL_MASK) /*!< ADC0_SC3                                */
/* ------- OFS Bit Fields                           ------ */
#define ADC_OFS_OFS_MASK                         (0xFFFFUL << ADC_OFS_OFS_SHIFT)                     /*!< ADC0_OFS: OFS Mask                      */
#define ADC_OFS_OFS_SHIFT                        0                                                   /*!< ADC0_OFS: OFS Position                  */
#define ADC_OFS_OFS(x)                           (((uint32_t)(((uint32_t)(x))<<ADC_OFS_OFS_SHIFT))&ADC_OFS_OFS_MASK) /*!< ADC0_OFS                                */
/* ------- PG Bit Fields                            ------ */
#define ADC_PG_PG_MASK                           (0xFFFFUL << ADC_PG_PG_SHIFT)                       /*!< ADC0_PG: PG Mask                        */
#define ADC_PG_PG_SHIFT                          0                                                   /*!< ADC0_PG: PG Position                    */
#define ADC_PG_PG(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_PG_PG_SHIFT))&ADC_PG_PG_MASK) /*!< ADC0_PG                                 */
/* ------- MG Bit Fields                            ------ */
#define ADC_MG_MG_MASK                           (0xFFFFUL << ADC_MG_MG_SHIFT)                       /*!< ADC0_MG: MG Mask                        */
#define ADC_MG_MG_SHIFT                          0                                                   /*!< ADC0_MG: MG Position                    */
#define ADC_MG_MG(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_MG_MG_SHIFT))&ADC_MG_MG_MASK) /*!< ADC0_MG                                 */
/* ------- CLPD Bit Fields                          ------ */
#define ADC_CLPD_CLPD_MASK                       (0x3FUL << ADC_CLPD_CLPD_SHIFT)                     /*!< ADC0_CLPD: CLPD Mask                    */
#define ADC_CLPD_CLPD_SHIFT                      0                                                   /*!< ADC0_CLPD: CLPD Position                */
#define ADC_CLPD_CLPD(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPD_CLPD_SHIFT))&ADC_CLPD_CLPD_MASK) /*!< ADC0_CLPD                               */
/* ------- CLPS Bit Fields                          ------ */
#define ADC_CLPS_CLPS_MASK                       (0x3FUL << ADC_CLPS_CLPS_SHIFT)                     /*!< ADC0_CLPS: CLPS Mask                    */
#define ADC_CLPS_CLPS_SHIFT                      0                                                   /*!< ADC0_CLPS: CLPS Position                */
#define ADC_CLPS_CLPS(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLPS_CLPS_SHIFT))&ADC_CLPS_CLPS_MASK) /*!< ADC0_CLPS                               */
/* ------- CLP4 Bit Fields                          ------ */
#define ADC_CLP4_CLP4_MASK                       (0x3FFUL << ADC_CLP4_CLP4_SHIFT)                    /*!< ADC0_CLP4: CLP4 Mask                    */
#define ADC_CLP4_CLP4_SHIFT                      0                                                   /*!< ADC0_CLP4: CLP4 Position                */
#define ADC_CLP4_CLP4(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP4_CLP4_SHIFT))&ADC_CLP4_CLP4_MASK) /*!< ADC0_CLP4                               */
/* ------- CLP3 Bit Fields                          ------ */
#define ADC_CLP3_CLP3_MASK                       (0x1FFUL << ADC_CLP3_CLP3_SHIFT)                    /*!< ADC0_CLP3: CLP3 Mask                    */
#define ADC_CLP3_CLP3_SHIFT                      0                                                   /*!< ADC0_CLP3: CLP3 Position                */
#define ADC_CLP3_CLP3(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP3_CLP3_SHIFT))&ADC_CLP3_CLP3_MASK) /*!< ADC0_CLP3                               */
/* ------- CLP2 Bit Fields                          ------ */
#define ADC_CLP2_CLP2_MASK                       (0xFFUL << ADC_CLP2_CLP2_SHIFT)                     /*!< ADC0_CLP2: CLP2 Mask                    */
#define ADC_CLP2_CLP2_SHIFT                      0                                                   /*!< ADC0_CLP2: CLP2 Position                */
#define ADC_CLP2_CLP2(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP2_CLP2_SHIFT))&ADC_CLP2_CLP2_MASK) /*!< ADC0_CLP2                               */
/* ------- CLP1 Bit Fields                          ------ */
#define ADC_CLP1_CLP1_MASK                       (0x7FUL << ADC_CLP1_CLP1_SHIFT)                     /*!< ADC0_CLP1: CLP1 Mask                    */
#define ADC_CLP1_CLP1_SHIFT                      0                                                   /*!< ADC0_CLP1: CLP1 Position                */
#define ADC_CLP1_CLP1(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP1_CLP1_SHIFT))&ADC_CLP1_CLP1_MASK) /*!< ADC0_CLP1                               */
/* ------- CLP0 Bit Fields                          ------ */
#define ADC_CLP0_CLP0_MASK                       (0x3FUL << ADC_CLP0_CLP0_SHIFT)                     /*!< ADC0_CLP0: CLP0 Mask                    */
#define ADC_CLP0_CLP0_SHIFT                      0                                                   /*!< ADC0_CLP0: CLP0 Position                */
#define ADC_CLP0_CLP0(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLP0_CLP0_SHIFT))&ADC_CLP0_CLP0_MASK) /*!< ADC0_CLP0                               */
/* ------- PGA Bit Fields                           ------ */
#define ADC_PGA_PGAG_MASK                        (0x0FUL << ADC_PGA_PGAG_SHIFT)                      /*!< ADC0_PGA: PGAG Mask                     */
#define ADC_PGA_PGAG_SHIFT                       16                                                  /*!< ADC0_PGA: PGAG Position                 */
#define ADC_PGA_PGAG(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_PGA_PGAG_SHIFT))&ADC_PGA_PGAG_MASK) /*!< ADC0_PGA                                */
#define ADC_PGA_PGALPb_MASK                      (0x01UL << ADC_PGA_PGALPb_SHIFT)                    /*!< ADC0_PGA: PGALPb Mask                   */
#define ADC_PGA_PGALPb_SHIFT                     20                                                  /*!< ADC0_PGA: PGALPb Position               */
#define ADC_PGA_PGALPb(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_PGA_PGALPb_SHIFT))&ADC_PGA_PGALPb_MASK) /*!< ADC0_PGA                                */
#define ADC_PGA_PGAEN_MASK                       (0x01UL << ADC_PGA_PGAEN_SHIFT)                     /*!< ADC0_PGA: PGAEN Mask                    */
#define ADC_PGA_PGAEN_SHIFT                      23                                                  /*!< ADC0_PGA: PGAEN Position                */
#define ADC_PGA_PGAEN(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_PGA_PGAEN_SHIFT))&ADC_PGA_PGAEN_MASK) /*!< ADC0_PGA                                */
/* ------- CLMD Bit Fields                          ------ */
#define ADC_CLMD_CLMD_MASK                       (0x3FUL << ADC_CLMD_CLMD_SHIFT)                     /*!< ADC0_CLMD: CLMD Mask                    */
#define ADC_CLMD_CLMD_SHIFT                      0                                                   /*!< ADC0_CLMD: CLMD Position                */
#define ADC_CLMD_CLMD(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLMD_CLMD_SHIFT))&ADC_CLMD_CLMD_MASK) /*!< ADC0_CLMD                               */
/* ------- CLMS Bit Fields                          ------ */
#define ADC_CLMS_CLMS_MASK                       (0x3FUL << ADC_CLMS_CLMS_SHIFT)                     /*!< ADC0_CLMS: CLMS Mask                    */
#define ADC_CLMS_CLMS_SHIFT                      0                                                   /*!< ADC0_CLMS: CLMS Position                */
#define ADC_CLMS_CLMS(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLMS_CLMS_SHIFT))&ADC_CLMS_CLMS_MASK) /*!< ADC0_CLMS                               */
/* ------- CLM4 Bit Fields                          ------ */
#define ADC_CLM4_CLM4_MASK                       (0x3FFUL << ADC_CLM4_CLM4_SHIFT)                    /*!< ADC0_CLM4: CLM4 Mask                    */
#define ADC_CLM4_CLM4_SHIFT                      0                                                   /*!< ADC0_CLM4: CLM4 Position                */
#define ADC_CLM4_CLM4(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM4_CLM4_SHIFT))&ADC_CLM4_CLM4_MASK) /*!< ADC0_CLM4                               */
/* ------- CLM3 Bit Fields                          ------ */
#define ADC_CLM3_CLM3_MASK                       (0x1FFUL << ADC_CLM3_CLM3_SHIFT)                    /*!< ADC0_CLM3: CLM3 Mask                    */
#define ADC_CLM3_CLM3_SHIFT                      0                                                   /*!< ADC0_CLM3: CLM3 Position                */
#define ADC_CLM3_CLM3(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM3_CLM3_SHIFT))&ADC_CLM3_CLM3_MASK) /*!< ADC0_CLM3                               */
/* ------- CLM2 Bit Fields                          ------ */
#define ADC_CLM2_CLM2_MASK                       (0xFFUL << ADC_CLM2_CLM2_SHIFT)                     /*!< ADC0_CLM2: CLM2 Mask                    */
#define ADC_CLM2_CLM2_SHIFT                      0                                                   /*!< ADC0_CLM2: CLM2 Position                */
#define ADC_CLM2_CLM2(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM2_CLM2_SHIFT))&ADC_CLM2_CLM2_MASK) /*!< ADC0_CLM2                               */
/* ------- CLM1 Bit Fields                          ------ */
#define ADC_CLM1_CLM1_MASK                       (0x7FUL << ADC_CLM1_CLM1_SHIFT)                     /*!< ADC0_CLM1: CLM1 Mask                    */
#define ADC_CLM1_CLM1_SHIFT                      0                                                   /*!< ADC0_CLM1: CLM1 Position                */
#define ADC_CLM1_CLM1(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM1_CLM1_SHIFT))&ADC_CLM1_CLM1_MASK) /*!< ADC0_CLM1                               */
/* ------- CLM0 Bit Fields                          ------ */
#define ADC_CLM0_CLM0_MASK                       (0x3FUL << ADC_CLM0_CLM0_SHIFT)                     /*!< ADC0_CLM0: CLM0 Mask                    */
#define ADC_CLM0_CLM0_SHIFT                      0                                                   /*!< ADC0_CLM0: CLM0 Position                */
#define ADC_CLM0_CLM0(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_CLM0_CLM0_SHIFT))&ADC_CLM0_CLM0_MASK) /*!< ADC0_CLM0                               */
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
* @addtogroup ADC_Peripheral_access_layer_GROUP ADC Peripheral Access Layer
* @brief C Struct for ADC
* @{
*/

/* ================================================================================ */
/* ================           ADC1 (derived from ADC0)             ================ */
/* ================================================================================ */

/**
 * @brief Analog-to-Digital Converter
 */

/* ADC1 - Peripheral instance base addresses */
#define ADC1_BasePtr                   0x400BB000UL //!< Peripheral base address
#define ADC1                           ((ADC_Type *) ADC1_BasePtr) //!< Freescale base pointer
#define ADC1_BASE_PTR                  (ADC1) //!< Freescale style base pointer
/**
 * @} */ /* End group ADC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup AXBS_Peripheral_access_layer_GROUP AXBS Peripheral Access Layer
* @brief C Struct for AXBS
* @{
*/

/* ================================================================================ */
/* ================           AXBS (file:AXBS_3M_4S)               ================ */
/* ================================================================================ */

/**
 * @brief Crossbar switch
 */
/**
* @addtogroup AXBS_structs_GROUP AXBS struct
* @brief Struct for AXBS
* @{
*/
typedef struct {                                /*       AXBS Structure                                               */
   struct {
      __IO uint32_t  PRS;                       /**< 0000: Priority Registers Slave                                     */
      __I  uint32_t  RESERVED0[3];             
      __IO uint32_t  CRS;                       /**< 0010: Control Register                                             */
      __I  uint32_t  RESERVED1[59];            
   } SLAVE[4];                                  /**< 0000: (cluster: size=0x0400, 1024)                                 */
   __I  uint32_t  RESERVED0[256];              
   __IO uint32_t  MGPCR0;                       /**< 0800: Master General Purpose Control Register                      */
   __I  uint32_t  RESERVED1[63];               
   __IO uint32_t  MGPCR1;                       /**< 0900: Master General Purpose Control Register                      */
   __I  uint32_t  RESERVED2[63];               
   __IO uint32_t  MGPCR2;                       /**< 0A00: Master General Purpose Control Register                      */
} AXBS_Type;

/**
 * @} */ /* End group AXBS_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'AXBS' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup AXBS_Register_Masks_GROUP AXBS Register Masks
* @brief Register Masks for AXBS
* @{
*/
/* ------- PRS Bit Fields                           ------ */
#define AXBS_PRS_M0_MASK                         (0x07UL << AXBS_PRS_M0_SHIFT)                       /*!< AXBS_PRS: M0 Mask                       */
#define AXBS_PRS_M0_SHIFT                        0                                                   /*!< AXBS_PRS: M0 Position                   */
#define AXBS_PRS_M0(x)                           (((uint32_t)(((uint32_t)(x))<<AXBS_PRS_M0_SHIFT))&AXBS_PRS_M0_MASK) /*!< AXBS_PRS                                */
#define AXBS_PRS_M1_MASK                         (0x07UL << AXBS_PRS_M1_SHIFT)                       /*!< AXBS_PRS: M1 Mask                       */
#define AXBS_PRS_M1_SHIFT                        4                                                   /*!< AXBS_PRS: M1 Position                   */
#define AXBS_PRS_M1(x)                           (((uint32_t)(((uint32_t)(x))<<AXBS_PRS_M1_SHIFT))&AXBS_PRS_M1_MASK) /*!< AXBS_PRS                                */
#define AXBS_PRS_M2_MASK                         (0x07UL << AXBS_PRS_M2_SHIFT)                       /*!< AXBS_PRS: M2 Mask                       */
#define AXBS_PRS_M2_SHIFT                        8                                                   /*!< AXBS_PRS: M2 Position                   */
#define AXBS_PRS_M2(x)                           (((uint32_t)(((uint32_t)(x))<<AXBS_PRS_M2_SHIFT))&AXBS_PRS_M2_MASK) /*!< AXBS_PRS                                */
/* ------- CRS Bit Fields                           ------ */
#define AXBS_CRS_PARK_MASK                       (0x07UL << AXBS_CRS_PARK_SHIFT)                     /*!< AXBS_CRS: PARK Mask                     */
#define AXBS_CRS_PARK_SHIFT                      0                                                   /*!< AXBS_CRS: PARK Position                 */
#define AXBS_CRS_PARK(x)                         (((uint32_t)(((uint32_t)(x))<<AXBS_CRS_PARK_SHIFT))&AXBS_CRS_PARK_MASK) /*!< AXBS_CRS                                */
#define AXBS_CRS_PCTL_MASK                       (0x03UL << AXBS_CRS_PCTL_SHIFT)                     /*!< AXBS_CRS: PCTL Mask                     */
#define AXBS_CRS_PCTL_SHIFT                      4                                                   /*!< AXBS_CRS: PCTL Position                 */
#define AXBS_CRS_PCTL(x)                         (((uint32_t)(((uint32_t)(x))<<AXBS_CRS_PCTL_SHIFT))&AXBS_CRS_PCTL_MASK) /*!< AXBS_CRS                                */
#define AXBS_CRS_ARB_MASK                        (0x03UL << AXBS_CRS_ARB_SHIFT)                      /*!< AXBS_CRS: ARB Mask                      */
#define AXBS_CRS_ARB_SHIFT                       8                                                   /*!< AXBS_CRS: ARB Position                  */
#define AXBS_CRS_ARB(x)                          (((uint32_t)(((uint32_t)(x))<<AXBS_CRS_ARB_SHIFT))&AXBS_CRS_ARB_MASK) /*!< AXBS_CRS                                */
#define AXBS_CRS_HLP_MASK                        (0x01UL << AXBS_CRS_HLP_SHIFT)                      /*!< AXBS_CRS: HLP Mask                      */
#define AXBS_CRS_HLP_SHIFT                       30                                                  /*!< AXBS_CRS: HLP Position                  */
#define AXBS_CRS_HLP(x)                          (((uint32_t)(((uint32_t)(x))<<AXBS_CRS_HLP_SHIFT))&AXBS_CRS_HLP_MASK) /*!< AXBS_CRS                                */
#define AXBS_CRS_RO_MASK                         (0x01UL << AXBS_CRS_RO_SHIFT)                       /*!< AXBS_CRS: RO Mask                       */
#define AXBS_CRS_RO_SHIFT                        31                                                  /*!< AXBS_CRS: RO Position                   */
#define AXBS_CRS_RO(x)                           (((uint32_t)(((uint32_t)(x))<<AXBS_CRS_RO_SHIFT))&AXBS_CRS_RO_MASK) /*!< AXBS_CRS                                */
/* ------- MGPCR0 Bit Fields                        ------ */
#define AXBS_MGPCR0_AULB_MASK                    (0x07UL << AXBS_MGPCR0_AULB_SHIFT)                  /*!< AXBS_MGPCR0: AULB Mask                  */
#define AXBS_MGPCR0_AULB_SHIFT                   0                                                   /*!< AXBS_MGPCR0: AULB Position              */
#define AXBS_MGPCR0_AULB(x)                      (((uint32_t)(((uint32_t)(x))<<AXBS_MGPCR0_AULB_SHIFT))&AXBS_MGPCR0_AULB_MASK) /*!< AXBS_MGPCR0                             */
/**
 * @} */ /* End group AXBS_Register_Masks_GROUP 
 */

/* AXBS - Peripheral instance base addresses */
#define AXBS_BasePtr                   0x40004000UL //!< Peripheral base address
#define AXBS                           ((AXBS_Type *) AXBS_BasePtr) //!< Freescale base pointer
#define AXBS_BASE_PTR                  (AXBS) //!< Freescale style base pointer
/**
 * @} */ /* End group AXBS_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CAN_Peripheral_access_layer_GROUP CAN Peripheral Access Layer
* @brief C Struct for CAN
* @{
*/

/* ================================================================================ */
/* ================           CAN0 (file:CAN0_2MASK)               ================ */
/* ================================================================================ */

/**
 * @brief Flex Controller Area Network module
 */
/**
* @addtogroup CAN_structs_GROUP CAN struct
* @brief Struct for CAN
* @{
*/
typedef struct {                                /*       CAN0 Structure                                               */
   __IO uint32_t  MCR;                          /**< 0000: Module Configuration Register                                */
   __IO uint32_t  CTRL1;                        /**< 0004: Control 1 Register                                           */
   __IO uint32_t  TIMER;                        /**< 0008: Free Running Timer                                           */
   __I  uint32_t  RESERVED0;                   
   __IO uint32_t  RXMGMASK;                     /**< 0010: Rx Mailboxes Global Mask Register                            */
   __IO uint32_t  RX14MASK;                     /**< 0014: Rx 14 Mask register                                          */
   __IO uint32_t  RX15MASK;                     /**< 0018: Rx 15 Mask register                                          */
   __IO uint32_t  ECR;                          /**< 001C: Error Counter                                                */
   __IO uint32_t  ESR1;                         /**< 0020: Error and Status 1 register                                  */
   __IO uint32_t  IMASK2;                       /**< 0024: Interrupt Masks 2 Register                                   */
   __IO uint32_t  IMASK1;                       /**< 0028: Interrupt Masks 1 register                                   */
   __IO uint32_t  IFLAG2;                       /**< 002C: Interrupt Flags 2 Register                                   */
   __IO uint32_t  IFLAG1;                       /**< 0030: Interrupt Flags 1 register                                   */
   __IO uint32_t  CTRL2;                        /**< 0034: Control 2 Register                                           */
   __I  uint32_t  ESR2;                         /**< 0038: Error and Status 2 register                                  */
   __I  uint32_t  RESERVED1[2];                
   __I  uint32_t  CRCR;                         /**< 0044: CRC Register                                                 */
   __IO uint32_t  RXFGMASK;                     /**< 0048: Rx FIFO Global Mask register                                 */
   __I  uint32_t  RXFIR;                        /**< 004C: Rx FIFO Information Register                                 */
   __I  uint32_t  RESERVED2[12];               
   struct {
      __IO uint32_t  CS;                        /**< 0080: Message Buffer 0 CS Register                                 */
      __IO uint32_t  ID;                        /**< 0084: Message Buffer 0 ID Register                                 */
      __IO uint32_t  WORD0;                     /**< 0088: Message Buffer 0 WORD0 Register                              */
      __IO uint32_t  WORD1;                     /**< 008C: Message Buffer 0 WORD1 Register                              */
   } MB[16];                                    /**< 0080: (cluster: size=0x0100, 256)                                  */
   __I  uint32_t  RESERVED3[448];              
   __IO uint32_t  RXIMR[16];                    /**< 0880: Rx Individual Mask                                           */
} CAN_Type;

/**
 * @} */ /* End group CAN_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CAN0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CAN_Register_Masks_GROUP CAN Register Masks
* @brief Register Masks for CAN
* @{
*/
/* ------- MCR Bit Fields                           ------ */
#define CAN_MCR_MAXMB_MASK                       (0x7FUL << CAN_MCR_MAXMB_SHIFT)                     /*!< CAN0_MCR: MAXMB Mask                    */
#define CAN_MCR_MAXMB_SHIFT                      0                                                   /*!< CAN0_MCR: MAXMB Position                */
#define CAN_MCR_MAXMB(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_MCR_MAXMB_SHIFT))&CAN_MCR_MAXMB_MASK) /*!< CAN0_MCR                                */
#define CAN_MCR_IDAM_MASK                        (0x03UL << CAN_MCR_IDAM_SHIFT)                      /*!< CAN0_MCR: IDAM Mask                     */
#define CAN_MCR_IDAM_SHIFT                       8                                                   /*!< CAN0_MCR: IDAM Position                 */
#define CAN_MCR_IDAM(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_MCR_IDAM_SHIFT))&CAN_MCR_IDAM_MASK) /*!< CAN0_MCR                                */
#define CAN_MCR_AEN_MASK                         (0x01UL << CAN_MCR_AEN_SHIFT)                       /*!< CAN0_MCR: AEN Mask                      */
#define CAN_MCR_AEN_SHIFT                        12                                                  /*!< CAN0_MCR: AEN Position                  */
#define CAN_MCR_AEN(x)                           (((uint32_t)(((uint32_t)(x))<<CAN_MCR_AEN_SHIFT))&CAN_MCR_AEN_MASK) /*!< CAN0_MCR                                */
#define CAN_MCR_LPRIOEN_MASK                     (0x01UL << CAN_MCR_LPRIOEN_SHIFT)                   /*!< CAN0_MCR: LPRIOEN Mask                  */
#define CAN_MCR_LPRIOEN_SHIFT                    13                                                  /*!< CAN0_MCR: LPRIOEN Position              */
#define CAN_MCR_LPRIOEN(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_MCR_LPRIOEN_SHIFT))&CAN_MCR_LPRIOEN_MASK) /*!< CAN0_MCR                                */
#define CAN_MCR_IRMQ_MASK                        (0x01UL << CAN_MCR_IRMQ_SHIFT)                      /*!< CAN0_MCR: IRMQ Mask                     */
#define CAN_MCR_IRMQ_SHIFT                       16                                                  /*!< CAN0_MCR: IRMQ Position                 */
#define CAN_MCR_IRMQ(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_MCR_IRMQ_SHIFT))&CAN_MCR_IRMQ_MASK) /*!< CAN0_MCR                                */
#define CAN_MCR_SRXDIS_MASK                      (0x01UL << CAN_MCR_SRXDIS_SHIFT)                    /*!< CAN0_MCR: SRXDIS Mask                   */
#define CAN_MCR_SRXDIS_SHIFT                     17                                                  /*!< CAN0_MCR: SRXDIS Position               */
#define CAN_MCR_SRXDIS(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_MCR_SRXDIS_SHIFT))&CAN_MCR_SRXDIS_MASK) /*!< CAN0_MCR                                */
#define CAN_MCR_WAKSRC_MASK                      (0x01UL << CAN_MCR_WAKSRC_SHIFT)                    /*!< CAN0_MCR: WAKSRC Mask                   */
#define CAN_MCR_WAKSRC_SHIFT                     19                                                  /*!< CAN0_MCR: WAKSRC Position               */
#define CAN_MCR_WAKSRC(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_MCR_WAKSRC_SHIFT))&CAN_MCR_WAKSRC_MASK) /*!< CAN0_MCR                                */
#define CAN_MCR_LPMACK_MASK                      (0x01UL << CAN_MCR_LPMACK_SHIFT)                    /*!< CAN0_MCR: LPMACK Mask                   */
#define CAN_MCR_LPMACK_SHIFT                     20                                                  /*!< CAN0_MCR: LPMACK Position               */
#define CAN_MCR_LPMACK(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_MCR_LPMACK_SHIFT))&CAN_MCR_LPMACK_MASK) /*!< CAN0_MCR                                */
#define CAN_MCR_WRNEN_MASK                       (0x01UL << CAN_MCR_WRNEN_SHIFT)                     /*!< CAN0_MCR: WRNEN Mask                    */
#define CAN_MCR_WRNEN_SHIFT                      21                                                  /*!< CAN0_MCR: WRNEN Position                */
#define CAN_MCR_WRNEN(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_MCR_WRNEN_SHIFT))&CAN_MCR_WRNEN_MASK) /*!< CAN0_MCR                                */
#define CAN_MCR_SLFWAK_MASK                      (0x01UL << CAN_MCR_SLFWAK_SHIFT)                    /*!< CAN0_MCR: SLFWAK Mask                   */
#define CAN_MCR_SLFWAK_SHIFT                     22                                                  /*!< CAN0_MCR: SLFWAK Position               */
#define CAN_MCR_SLFWAK(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_MCR_SLFWAK_SHIFT))&CAN_MCR_SLFWAK_MASK) /*!< CAN0_MCR                                */
#define CAN_MCR_SUPV_MASK                        (0x01UL << CAN_MCR_SUPV_SHIFT)                      /*!< CAN0_MCR: SUPV Mask                     */
#define CAN_MCR_SUPV_SHIFT                       23                                                  /*!< CAN0_MCR: SUPV Position                 */
#define CAN_MCR_SUPV(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_MCR_SUPV_SHIFT))&CAN_MCR_SUPV_MASK) /*!< CAN0_MCR                                */
#define CAN_MCR_FRZACK_MASK                      (0x01UL << CAN_MCR_FRZACK_SHIFT)                    /*!< CAN0_MCR: FRZACK Mask                   */
#define CAN_MCR_FRZACK_SHIFT                     24                                                  /*!< CAN0_MCR: FRZACK Position               */
#define CAN_MCR_FRZACK(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_MCR_FRZACK_SHIFT))&CAN_MCR_FRZACK_MASK) /*!< CAN0_MCR                                */
#define CAN_MCR_SOFTRST_MASK                     (0x01UL << CAN_MCR_SOFTRST_SHIFT)                   /*!< CAN0_MCR: SOFTRST Mask                  */
#define CAN_MCR_SOFTRST_SHIFT                    25                                                  /*!< CAN0_MCR: SOFTRST Position              */
#define CAN_MCR_SOFTRST(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_MCR_SOFTRST_SHIFT))&CAN_MCR_SOFTRST_MASK) /*!< CAN0_MCR                                */
#define CAN_MCR_WAKMSK_MASK                      (0x01UL << CAN_MCR_WAKMSK_SHIFT)                    /*!< CAN0_MCR: WAKMSK Mask                   */
#define CAN_MCR_WAKMSK_SHIFT                     26                                                  /*!< CAN0_MCR: WAKMSK Position               */
#define CAN_MCR_WAKMSK(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_MCR_WAKMSK_SHIFT))&CAN_MCR_WAKMSK_MASK) /*!< CAN0_MCR                                */
#define CAN_MCR_NOTRDY_MASK                      (0x01UL << CAN_MCR_NOTRDY_SHIFT)                    /*!< CAN0_MCR: NOTRDY Mask                   */
#define CAN_MCR_NOTRDY_SHIFT                     27                                                  /*!< CAN0_MCR: NOTRDY Position               */
#define CAN_MCR_NOTRDY(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_MCR_NOTRDY_SHIFT))&CAN_MCR_NOTRDY_MASK) /*!< CAN0_MCR                                */
#define CAN_MCR_HALT_MASK                        (0x01UL << CAN_MCR_HALT_SHIFT)                      /*!< CAN0_MCR: HALT Mask                     */
#define CAN_MCR_HALT_SHIFT                       28                                                  /*!< CAN0_MCR: HALT Position                 */
#define CAN_MCR_HALT(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_MCR_HALT_SHIFT))&CAN_MCR_HALT_MASK) /*!< CAN0_MCR                                */
#define CAN_MCR_RFEN_MASK                        (0x01UL << CAN_MCR_RFEN_SHIFT)                      /*!< CAN0_MCR: RFEN Mask                     */
#define CAN_MCR_RFEN_SHIFT                       29                                                  /*!< CAN0_MCR: RFEN Position                 */
#define CAN_MCR_RFEN(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_MCR_RFEN_SHIFT))&CAN_MCR_RFEN_MASK) /*!< CAN0_MCR                                */
#define CAN_MCR_FRZ_MASK                         (0x01UL << CAN_MCR_FRZ_SHIFT)                       /*!< CAN0_MCR: FRZ Mask                      */
#define CAN_MCR_FRZ_SHIFT                        30                                                  /*!< CAN0_MCR: FRZ Position                  */
#define CAN_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x))<<CAN_MCR_FRZ_SHIFT))&CAN_MCR_FRZ_MASK) /*!< CAN0_MCR                                */
#define CAN_MCR_MDIS_MASK                        (0x01UL << CAN_MCR_MDIS_SHIFT)                      /*!< CAN0_MCR: MDIS Mask                     */
#define CAN_MCR_MDIS_SHIFT                       31                                                  /*!< CAN0_MCR: MDIS Position                 */
#define CAN_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_MCR_MDIS_SHIFT))&CAN_MCR_MDIS_MASK) /*!< CAN0_MCR                                */
/* ------- CTRL1 Bit Fields                         ------ */
#define CAN_CTRL1_PROPSEG_MASK                   (0x07UL << CAN_CTRL1_PROPSEG_SHIFT)                 /*!< CAN0_CTRL1: PROPSEG Mask                */
#define CAN_CTRL1_PROPSEG_SHIFT                  0                                                   /*!< CAN0_CTRL1: PROPSEG Position            */
#define CAN_CTRL1_PROPSEG(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_PROPSEG_SHIFT))&CAN_CTRL1_PROPSEG_MASK) /*!< CAN0_CTRL1                              */
#define CAN_CTRL1_LOM_MASK                       (0x01UL << CAN_CTRL1_LOM_SHIFT)                     /*!< CAN0_CTRL1: LOM Mask                    */
#define CAN_CTRL1_LOM_SHIFT                      3                                                   /*!< CAN0_CTRL1: LOM Position                */
#define CAN_CTRL1_LOM(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_LOM_SHIFT))&CAN_CTRL1_LOM_MASK) /*!< CAN0_CTRL1                              */
#define CAN_CTRL1_LBUF_MASK                      (0x01UL << CAN_CTRL1_LBUF_SHIFT)                    /*!< CAN0_CTRL1: LBUF Mask                   */
#define CAN_CTRL1_LBUF_SHIFT                     4                                                   /*!< CAN0_CTRL1: LBUF Position               */
#define CAN_CTRL1_LBUF(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_LBUF_SHIFT))&CAN_CTRL1_LBUF_MASK) /*!< CAN0_CTRL1                              */
#define CAN_CTRL1_TSYN_MASK                      (0x01UL << CAN_CTRL1_TSYN_SHIFT)                    /*!< CAN0_CTRL1: TSYN Mask                   */
#define CAN_CTRL1_TSYN_SHIFT                     5                                                   /*!< CAN0_CTRL1: TSYN Position               */
#define CAN_CTRL1_TSYN(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_TSYN_SHIFT))&CAN_CTRL1_TSYN_MASK) /*!< CAN0_CTRL1                              */
#define CAN_CTRL1_BOFFREC_MASK                   (0x01UL << CAN_CTRL1_BOFFREC_SHIFT)                 /*!< CAN0_CTRL1: BOFFREC Mask                */
#define CAN_CTRL1_BOFFREC_SHIFT                  6                                                   /*!< CAN0_CTRL1: BOFFREC Position            */
#define CAN_CTRL1_BOFFREC(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_BOFFREC_SHIFT))&CAN_CTRL1_BOFFREC_MASK) /*!< CAN0_CTRL1                              */
#define CAN_CTRL1_SMP_MASK                       (0x01UL << CAN_CTRL1_SMP_SHIFT)                     /*!< CAN0_CTRL1: SMP Mask                    */
#define CAN_CTRL1_SMP_SHIFT                      7                                                   /*!< CAN0_CTRL1: SMP Position                */
#define CAN_CTRL1_SMP(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_SMP_SHIFT))&CAN_CTRL1_SMP_MASK) /*!< CAN0_CTRL1                              */
#define CAN_CTRL1_RWRNMSK_MASK                   (0x01UL << CAN_CTRL1_RWRNMSK_SHIFT)                 /*!< CAN0_CTRL1: RWRNMSK Mask                */
#define CAN_CTRL1_RWRNMSK_SHIFT                  10                                                  /*!< CAN0_CTRL1: RWRNMSK Position            */
#define CAN_CTRL1_RWRNMSK(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_RWRNMSK_SHIFT))&CAN_CTRL1_RWRNMSK_MASK) /*!< CAN0_CTRL1                              */
#define CAN_CTRL1_TWRNMSK_MASK                   (0x01UL << CAN_CTRL1_TWRNMSK_SHIFT)                 /*!< CAN0_CTRL1: TWRNMSK Mask                */
#define CAN_CTRL1_TWRNMSK_SHIFT                  11                                                  /*!< CAN0_CTRL1: TWRNMSK Position            */
#define CAN_CTRL1_TWRNMSK(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_TWRNMSK_SHIFT))&CAN_CTRL1_TWRNMSK_MASK) /*!< CAN0_CTRL1                              */
#define CAN_CTRL1_LPB_MASK                       (0x01UL << CAN_CTRL1_LPB_SHIFT)                     /*!< CAN0_CTRL1: LPB Mask                    */
#define CAN_CTRL1_LPB_SHIFT                      12                                                  /*!< CAN0_CTRL1: LPB Position                */
#define CAN_CTRL1_LPB(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_LPB_SHIFT))&CAN_CTRL1_LPB_MASK) /*!< CAN0_CTRL1                              */
#define CAN_CTRL1_CLKSRC_MASK                    (0x01UL << CAN_CTRL1_CLKSRC_SHIFT)                  /*!< CAN0_CTRL1: CLKSRC Mask                 */
#define CAN_CTRL1_CLKSRC_SHIFT                   13                                                  /*!< CAN0_CTRL1: CLKSRC Position             */
#define CAN_CTRL1_CLKSRC(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_CLKSRC_SHIFT))&CAN_CTRL1_CLKSRC_MASK) /*!< CAN0_CTRL1                              */
#define CAN_CTRL1_ERRMSK_MASK                    (0x01UL << CAN_CTRL1_ERRMSK_SHIFT)                  /*!< CAN0_CTRL1: ERRMSK Mask                 */
#define CAN_CTRL1_ERRMSK_SHIFT                   14                                                  /*!< CAN0_CTRL1: ERRMSK Position             */
#define CAN_CTRL1_ERRMSK(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_ERRMSK_SHIFT))&CAN_CTRL1_ERRMSK_MASK) /*!< CAN0_CTRL1                              */
#define CAN_CTRL1_BOFFMSK_MASK                   (0x01UL << CAN_CTRL1_BOFFMSK_SHIFT)                 /*!< CAN0_CTRL1: BOFFMSK Mask                */
#define CAN_CTRL1_BOFFMSK_SHIFT                  15                                                  /*!< CAN0_CTRL1: BOFFMSK Position            */
#define CAN_CTRL1_BOFFMSK(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_BOFFMSK_SHIFT))&CAN_CTRL1_BOFFMSK_MASK) /*!< CAN0_CTRL1                              */
#define CAN_CTRL1_PSEG2_MASK                     (0x07UL << CAN_CTRL1_PSEG2_SHIFT)                   /*!< CAN0_CTRL1: PSEG2 Mask                  */
#define CAN_CTRL1_PSEG2_SHIFT                    16                                                  /*!< CAN0_CTRL1: PSEG2 Position              */
#define CAN_CTRL1_PSEG2(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_PSEG2_SHIFT))&CAN_CTRL1_PSEG2_MASK) /*!< CAN0_CTRL1                              */
#define CAN_CTRL1_PSEG1_MASK                     (0x07UL << CAN_CTRL1_PSEG1_SHIFT)                   /*!< CAN0_CTRL1: PSEG1 Mask                  */
#define CAN_CTRL1_PSEG1_SHIFT                    19                                                  /*!< CAN0_CTRL1: PSEG1 Position              */
#define CAN_CTRL1_PSEG1(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_PSEG1_SHIFT))&CAN_CTRL1_PSEG1_MASK) /*!< CAN0_CTRL1                              */
#define CAN_CTRL1_RJW_MASK                       (0x03UL << CAN_CTRL1_RJW_SHIFT)                     /*!< CAN0_CTRL1: RJW Mask                    */
#define CAN_CTRL1_RJW_SHIFT                      22                                                  /*!< CAN0_CTRL1: RJW Position                */
#define CAN_CTRL1_RJW(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_RJW_SHIFT))&CAN_CTRL1_RJW_MASK) /*!< CAN0_CTRL1                              */
#define CAN_CTRL1_PRESDIV_MASK                   (0xFFUL << CAN_CTRL1_PRESDIV_SHIFT)                 /*!< CAN0_CTRL1: PRESDIV Mask                */
#define CAN_CTRL1_PRESDIV_SHIFT                  24                                                  /*!< CAN0_CTRL1: PRESDIV Position            */
#define CAN_CTRL1_PRESDIV(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_PRESDIV_SHIFT))&CAN_CTRL1_PRESDIV_MASK) /*!< CAN0_CTRL1                              */
/* ------- TIMER Bit Fields                         ------ */
#define CAN_TIMER_TIMER_MASK                     (0xFFFFUL << CAN_TIMER_TIMER_SHIFT)                 /*!< CAN0_TIMER: TIMER Mask                  */
#define CAN_TIMER_TIMER_SHIFT                    0                                                   /*!< CAN0_TIMER: TIMER Position              */
#define CAN_TIMER_TIMER(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_TIMER_TIMER_SHIFT))&CAN_TIMER_TIMER_MASK) /*!< CAN0_TIMER                              */
/* ------- RXMGMASK Bit Fields                      ------ */
#define CAN_RXMGMASK_MG_MASK                     (0xFFFFFFFFUL << CAN_RXMGMASK_MG_SHIFT)             /*!< CAN0_RXMGMASK: MG Mask                  */
#define CAN_RXMGMASK_MG_SHIFT                    0                                                   /*!< CAN0_RXMGMASK: MG Position              */
#define CAN_RXMGMASK_MG(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_RXMGMASK_MG_SHIFT))&CAN_RXMGMASK_MG_MASK) /*!< CAN0_RXMGMASK                           */
/* ------- RX14MASK Bit Fields                      ------ */
#define CAN_RX14MASK_RX14M_MASK                  (0xFFFFFFFFUL << CAN_RX14MASK_RX14M_SHIFT)          /*!< CAN0_RX14MASK: RX14M Mask               */
#define CAN_RX14MASK_RX14M_SHIFT                 0                                                   /*!< CAN0_RX14MASK: RX14M Position           */
#define CAN_RX14MASK_RX14M(x)                    (((uint32_t)(((uint32_t)(x))<<CAN_RX14MASK_RX14M_SHIFT))&CAN_RX14MASK_RX14M_MASK) /*!< CAN0_RX14MASK                           */
/* ------- RX15MASK Bit Fields                      ------ */
#define CAN_RX15MASK_RX15M_MASK                  (0xFFFFFFFFUL << CAN_RX15MASK_RX15M_SHIFT)          /*!< CAN0_RX15MASK: RX15M Mask               */
#define CAN_RX15MASK_RX15M_SHIFT                 0                                                   /*!< CAN0_RX15MASK: RX15M Position           */
#define CAN_RX15MASK_RX15M(x)                    (((uint32_t)(((uint32_t)(x))<<CAN_RX15MASK_RX15M_SHIFT))&CAN_RX15MASK_RX15M_MASK) /*!< CAN0_RX15MASK                           */
/* ------- ECR Bit Fields                           ------ */
#define CAN_ECR_TXERRCNT_MASK                    (0xFFUL << CAN_ECR_TXERRCNT_SHIFT)                  /*!< CAN0_ECR: TXERRCNT Mask                 */
#define CAN_ECR_TXERRCNT_SHIFT                   0                                                   /*!< CAN0_ECR: TXERRCNT Position             */
#define CAN_ECR_TXERRCNT(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ECR_TXERRCNT_SHIFT))&CAN_ECR_TXERRCNT_MASK) /*!< CAN0_ECR                                */
#define CAN_ECR_RXERRCNT_MASK                    (0xFFUL << CAN_ECR_RXERRCNT_SHIFT)                  /*!< CAN0_ECR: RXERRCNT Mask                 */
#define CAN_ECR_RXERRCNT_SHIFT                   8                                                   /*!< CAN0_ECR: RXERRCNT Position             */
#define CAN_ECR_RXERRCNT(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ECR_RXERRCNT_SHIFT))&CAN_ECR_RXERRCNT_MASK) /*!< CAN0_ECR                                */
/* ------- ESR1 Bit Fields                          ------ */
#define CAN_ESR1_WAKINT_MASK                     (0x01UL << CAN_ESR1_WAKINT_SHIFT)                   /*!< CAN0_ESR1: WAKINT Mask                  */
#define CAN_ESR1_WAKINT_SHIFT                    0                                                   /*!< CAN0_ESR1: WAKINT Position              */
#define CAN_ESR1_WAKINT(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_WAKINT_SHIFT))&CAN_ESR1_WAKINT_MASK) /*!< CAN0_ESR1                               */
#define CAN_ESR1_ERRINT_MASK                     (0x01UL << CAN_ESR1_ERRINT_SHIFT)                   /*!< CAN0_ESR1: ERRINT Mask                  */
#define CAN_ESR1_ERRINT_SHIFT                    1                                                   /*!< CAN0_ESR1: ERRINT Position              */
#define CAN_ESR1_ERRINT(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_ERRINT_SHIFT))&CAN_ESR1_ERRINT_MASK) /*!< CAN0_ESR1                               */
#define CAN_ESR1_BOFFINT_MASK                    (0x01UL << CAN_ESR1_BOFFINT_SHIFT)                  /*!< CAN0_ESR1: BOFFINT Mask                 */
#define CAN_ESR1_BOFFINT_SHIFT                   2                                                   /*!< CAN0_ESR1: BOFFINT Position             */
#define CAN_ESR1_BOFFINT(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_BOFFINT_SHIFT))&CAN_ESR1_BOFFINT_MASK) /*!< CAN0_ESR1                               */
#define CAN_ESR1_RX_MASK                         (0x01UL << CAN_ESR1_RX_SHIFT)                       /*!< CAN0_ESR1: RX Mask                      */
#define CAN_ESR1_RX_SHIFT                        3                                                   /*!< CAN0_ESR1: RX Position                  */
#define CAN_ESR1_RX(x)                           (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_RX_SHIFT))&CAN_ESR1_RX_MASK) /*!< CAN0_ESR1                               */
#define CAN_ESR1_FLTCONF_MASK                    (0x03UL << CAN_ESR1_FLTCONF_SHIFT)                  /*!< CAN0_ESR1: FLTCONF Mask                 */
#define CAN_ESR1_FLTCONF_SHIFT                   4                                                   /*!< CAN0_ESR1: FLTCONF Position             */
#define CAN_ESR1_FLTCONF(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_FLTCONF_SHIFT))&CAN_ESR1_FLTCONF_MASK) /*!< CAN0_ESR1                               */
#define CAN_ESR1_TX_MASK                         (0x01UL << CAN_ESR1_TX_SHIFT)                       /*!< CAN0_ESR1: TX Mask                      */
#define CAN_ESR1_TX_SHIFT                        6                                                   /*!< CAN0_ESR1: TX Position                  */
#define CAN_ESR1_TX(x)                           (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_TX_SHIFT))&CAN_ESR1_TX_MASK) /*!< CAN0_ESR1                               */
#define CAN_ESR1_IDLE_MASK                       (0x01UL << CAN_ESR1_IDLE_SHIFT)                     /*!< CAN0_ESR1: IDLE Mask                    */
#define CAN_ESR1_IDLE_SHIFT                      7                                                   /*!< CAN0_ESR1: IDLE Position                */
#define CAN_ESR1_IDLE(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_IDLE_SHIFT))&CAN_ESR1_IDLE_MASK) /*!< CAN0_ESR1                               */
#define CAN_ESR1_RXWRN_MASK                      (0x01UL << CAN_ESR1_RXWRN_SHIFT)                    /*!< CAN0_ESR1: RXWRN Mask                   */
#define CAN_ESR1_RXWRN_SHIFT                     8                                                   /*!< CAN0_ESR1: RXWRN Position               */
#define CAN_ESR1_RXWRN(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_RXWRN_SHIFT))&CAN_ESR1_RXWRN_MASK) /*!< CAN0_ESR1                               */
#define CAN_ESR1_TXWRN_MASK                      (0x01UL << CAN_ESR1_TXWRN_SHIFT)                    /*!< CAN0_ESR1: TXWRN Mask                   */
#define CAN_ESR1_TXWRN_SHIFT                     9                                                   /*!< CAN0_ESR1: TXWRN Position               */
#define CAN_ESR1_TXWRN(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_TXWRN_SHIFT))&CAN_ESR1_TXWRN_MASK) /*!< CAN0_ESR1                               */
#define CAN_ESR1_STFERR_MASK                     (0x01UL << CAN_ESR1_STFERR_SHIFT)                   /*!< CAN0_ESR1: STFERR Mask                  */
#define CAN_ESR1_STFERR_SHIFT                    10                                                  /*!< CAN0_ESR1: STFERR Position              */
#define CAN_ESR1_STFERR(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_STFERR_SHIFT))&CAN_ESR1_STFERR_MASK) /*!< CAN0_ESR1                               */
#define CAN_ESR1_FRMERR_MASK                     (0x01UL << CAN_ESR1_FRMERR_SHIFT)                   /*!< CAN0_ESR1: FRMERR Mask                  */
#define CAN_ESR1_FRMERR_SHIFT                    11                                                  /*!< CAN0_ESR1: FRMERR Position              */
#define CAN_ESR1_FRMERR(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_FRMERR_SHIFT))&CAN_ESR1_FRMERR_MASK) /*!< CAN0_ESR1                               */
#define CAN_ESR1_CRCERR_MASK                     (0x01UL << CAN_ESR1_CRCERR_SHIFT)                   /*!< CAN0_ESR1: CRCERR Mask                  */
#define CAN_ESR1_CRCERR_SHIFT                    12                                                  /*!< CAN0_ESR1: CRCERR Position              */
#define CAN_ESR1_CRCERR(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_CRCERR_SHIFT))&CAN_ESR1_CRCERR_MASK) /*!< CAN0_ESR1                               */
#define CAN_ESR1_ACKERR_MASK                     (0x01UL << CAN_ESR1_ACKERR_SHIFT)                   /*!< CAN0_ESR1: ACKERR Mask                  */
#define CAN_ESR1_ACKERR_SHIFT                    13                                                  /*!< CAN0_ESR1: ACKERR Position              */
#define CAN_ESR1_ACKERR(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_ACKERR_SHIFT))&CAN_ESR1_ACKERR_MASK) /*!< CAN0_ESR1                               */
#define CAN_ESR1_BIT0ERR_MASK                    (0x01UL << CAN_ESR1_BIT0ERR_SHIFT)                  /*!< CAN0_ESR1: BIT0ERR Mask                 */
#define CAN_ESR1_BIT0ERR_SHIFT                   14                                                  /*!< CAN0_ESR1: BIT0ERR Position             */
#define CAN_ESR1_BIT0ERR(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_BIT0ERR_SHIFT))&CAN_ESR1_BIT0ERR_MASK) /*!< CAN0_ESR1                               */
#define CAN_ESR1_BIT1ERR_MASK                    (0x01UL << CAN_ESR1_BIT1ERR_SHIFT)                  /*!< CAN0_ESR1: BIT1ERR Mask                 */
#define CAN_ESR1_BIT1ERR_SHIFT                   15                                                  /*!< CAN0_ESR1: BIT1ERR Position             */
#define CAN_ESR1_BIT1ERR(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_BIT1ERR_SHIFT))&CAN_ESR1_BIT1ERR_MASK) /*!< CAN0_ESR1                               */
#define CAN_ESR1_RWRNINT_MASK                    (0x01UL << CAN_ESR1_RWRNINT_SHIFT)                  /*!< CAN0_ESR1: RWRNINT Mask                 */
#define CAN_ESR1_RWRNINT_SHIFT                   16                                                  /*!< CAN0_ESR1: RWRNINT Position             */
#define CAN_ESR1_RWRNINT(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_RWRNINT_SHIFT))&CAN_ESR1_RWRNINT_MASK) /*!< CAN0_ESR1                               */
#define CAN_ESR1_TWRNINT_MASK                    (0x01UL << CAN_ESR1_TWRNINT_SHIFT)                  /*!< CAN0_ESR1: TWRNINT Mask                 */
#define CAN_ESR1_TWRNINT_SHIFT                   17                                                  /*!< CAN0_ESR1: TWRNINT Position             */
#define CAN_ESR1_TWRNINT(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_TWRNINT_SHIFT))&CAN_ESR1_TWRNINT_MASK) /*!< CAN0_ESR1                               */
#define CAN_ESR1_SYNCH_MASK                      (0x01UL << CAN_ESR1_SYNCH_SHIFT)                    /*!< CAN0_ESR1: SYNCH Mask                   */
#define CAN_ESR1_SYNCH_SHIFT                     18                                                  /*!< CAN0_ESR1: SYNCH Position               */
#define CAN_ESR1_SYNCH(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_SYNCH_SHIFT))&CAN_ESR1_SYNCH_MASK) /*!< CAN0_ESR1                               */
/* ------- IMASK2 Bit Fields                        ------ */
#define CAN_IMASK2_BUFHM_MASK                    (0xFFFFFFFFUL << CAN_IMASK2_BUFHM_SHIFT)            /*!< CAN0_IMASK2: BUFHM Mask                 */
#define CAN_IMASK2_BUFHM_SHIFT                   0                                                   /*!< CAN0_IMASK2: BUFHM Position             */
#define CAN_IMASK2_BUFHM(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_IMASK2_BUFHM_SHIFT))&CAN_IMASK2_BUFHM_MASK) /*!< CAN0_IMASK2                             */
/* ------- IMASK1 Bit Fields                        ------ */
#define CAN_IMASK1_BUFLM_MASK                    (0xFFFFFFFFUL << CAN_IMASK1_BUFLM_SHIFT)            /*!< CAN0_IMASK1: BUFLM Mask                 */
#define CAN_IMASK1_BUFLM_SHIFT                   0                                                   /*!< CAN0_IMASK1: BUFLM Position             */
#define CAN_IMASK1_BUFLM(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_IMASK1_BUFLM_SHIFT))&CAN_IMASK1_BUFLM_MASK) /*!< CAN0_IMASK1                             */
/* ------- IFLAG2 Bit Fields                        ------ */
#define CAN_IFLAG2_BUFHI_MASK                    (0xFFFFFFFFUL << CAN_IFLAG2_BUFHI_SHIFT)            /*!< CAN0_IFLAG2: BUFHI Mask                 */
#define CAN_IFLAG2_BUFHI_SHIFT                   0                                                   /*!< CAN0_IFLAG2: BUFHI Position             */
#define CAN_IFLAG2_BUFHI(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_IFLAG2_BUFHI_SHIFT))&CAN_IFLAG2_BUFHI_MASK) /*!< CAN0_IFLAG2                             */
/* ------- IFLAG1 Bit Fields                        ------ */
#define CAN_IFLAG1_BUF4TO0I_MASK                 (0x1FUL << CAN_IFLAG1_BUF4TO0I_SHIFT)               /*!< CAN0_IFLAG1: BUF4TO0I Mask              */
#define CAN_IFLAG1_BUF4TO0I_SHIFT                0                                                   /*!< CAN0_IFLAG1: BUF4TO0I Position          */
#define CAN_IFLAG1_BUF4TO0I(x)                   (((uint32_t)(((uint32_t)(x))<<CAN_IFLAG1_BUF4TO0I_SHIFT))&CAN_IFLAG1_BUF4TO0I_MASK) /*!< CAN0_IFLAG1                             */
#define CAN_IFLAG1_BUF5I_MASK                    (0x01UL << CAN_IFLAG1_BUF5I_SHIFT)                  /*!< CAN0_IFLAG1: BUF5I Mask                 */
#define CAN_IFLAG1_BUF5I_SHIFT                   5                                                   /*!< CAN0_IFLAG1: BUF5I Position             */
#define CAN_IFLAG1_BUF5I(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_IFLAG1_BUF5I_SHIFT))&CAN_IFLAG1_BUF5I_MASK) /*!< CAN0_IFLAG1                             */
#define CAN_IFLAG1_BUF6I_MASK                    (0x01UL << CAN_IFLAG1_BUF6I_SHIFT)                  /*!< CAN0_IFLAG1: BUF6I Mask                 */
#define CAN_IFLAG1_BUF6I_SHIFT                   6                                                   /*!< CAN0_IFLAG1: BUF6I Position             */
#define CAN_IFLAG1_BUF6I(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_IFLAG1_BUF6I_SHIFT))&CAN_IFLAG1_BUF6I_MASK) /*!< CAN0_IFLAG1                             */
#define CAN_IFLAG1_BUF7I_MASK                    (0x01UL << CAN_IFLAG1_BUF7I_SHIFT)                  /*!< CAN0_IFLAG1: BUF7I Mask                 */
#define CAN_IFLAG1_BUF7I_SHIFT                   7                                                   /*!< CAN0_IFLAG1: BUF7I Position             */
#define CAN_IFLAG1_BUF7I(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_IFLAG1_BUF7I_SHIFT))&CAN_IFLAG1_BUF7I_MASK) /*!< CAN0_IFLAG1                             */
#define CAN_IFLAG1_BUF31TO8I_MASK                (0xFFFFFFUL << CAN_IFLAG1_BUF31TO8I_SHIFT)          /*!< CAN0_IFLAG1: BUF31TO8I Mask             */
#define CAN_IFLAG1_BUF31TO8I_SHIFT               8                                                   /*!< CAN0_IFLAG1: BUF31TO8I Position         */
#define CAN_IFLAG1_BUF31TO8I(x)                  (((uint32_t)(((uint32_t)(x))<<CAN_IFLAG1_BUF31TO8I_SHIFT))&CAN_IFLAG1_BUF31TO8I_MASK) /*!< CAN0_IFLAG1                             */
/* ------- CTRL2 Bit Fields                         ------ */
#define CAN_CTRL2_EACEN_MASK                     (0x01UL << CAN_CTRL2_EACEN_SHIFT)                   /*!< CAN0_CTRL2: EACEN Mask                  */
#define CAN_CTRL2_EACEN_SHIFT                    16                                                  /*!< CAN0_CTRL2: EACEN Position              */
#define CAN_CTRL2_EACEN(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_CTRL2_EACEN_SHIFT))&CAN_CTRL2_EACEN_MASK) /*!< CAN0_CTRL2                              */
#define CAN_CTRL2_RRS_MASK                       (0x01UL << CAN_CTRL2_RRS_SHIFT)                     /*!< CAN0_CTRL2: RRS Mask                    */
#define CAN_CTRL2_RRS_SHIFT                      17                                                  /*!< CAN0_CTRL2: RRS Position                */
#define CAN_CTRL2_RRS(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_CTRL2_RRS_SHIFT))&CAN_CTRL2_RRS_MASK) /*!< CAN0_CTRL2                              */
#define CAN_CTRL2_MRP_MASK                       (0x01UL << CAN_CTRL2_MRP_SHIFT)                     /*!< CAN0_CTRL2: MRP Mask                    */
#define CAN_CTRL2_MRP_SHIFT                      18                                                  /*!< CAN0_CTRL2: MRP Position                */
#define CAN_CTRL2_MRP(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_CTRL2_MRP_SHIFT))&CAN_CTRL2_MRP_MASK) /*!< CAN0_CTRL2                              */
#define CAN_CTRL2_TASD_MASK                      (0x1FUL << CAN_CTRL2_TASD_SHIFT)                    /*!< CAN0_CTRL2: TASD Mask                   */
#define CAN_CTRL2_TASD_SHIFT                     19                                                  /*!< CAN0_CTRL2: TASD Position               */
#define CAN_CTRL2_TASD(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CTRL2_TASD_SHIFT))&CAN_CTRL2_TASD_MASK) /*!< CAN0_CTRL2                              */
#define CAN_CTRL2_RFFN_MASK                      (0x0FUL << CAN_CTRL2_RFFN_SHIFT)                    /*!< CAN0_CTRL2: RFFN Mask                   */
#define CAN_CTRL2_RFFN_SHIFT                     24                                                  /*!< CAN0_CTRL2: RFFN Position               */
#define CAN_CTRL2_RFFN(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CTRL2_RFFN_SHIFT))&CAN_CTRL2_RFFN_MASK) /*!< CAN0_CTRL2                              */
#define CAN_CTRL2_WRMFRZ_MASK                    (0x01UL << CAN_CTRL2_WRMFRZ_SHIFT)                  /*!< CAN0_CTRL2: WRMFRZ Mask                 */
#define CAN_CTRL2_WRMFRZ_SHIFT                   28                                                  /*!< CAN0_CTRL2: WRMFRZ Position             */
#define CAN_CTRL2_WRMFRZ(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_CTRL2_WRMFRZ_SHIFT))&CAN_CTRL2_WRMFRZ_MASK) /*!< CAN0_CTRL2                              */
/* ------- ESR2 Bit Fields                          ------ */
#define CAN_ESR2_IMB_MASK                        (0x01UL << CAN_ESR2_IMB_SHIFT)                      /*!< CAN0_ESR2: IMB Mask                     */
#define CAN_ESR2_IMB_SHIFT                       13                                                  /*!< CAN0_ESR2: IMB Position                 */
#define CAN_ESR2_IMB(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_ESR2_IMB_SHIFT))&CAN_ESR2_IMB_MASK) /*!< CAN0_ESR2                               */
#define CAN_ESR2_VPS_MASK                        (0x01UL << CAN_ESR2_VPS_SHIFT)                      /*!< CAN0_ESR2: VPS Mask                     */
#define CAN_ESR2_VPS_SHIFT                       14                                                  /*!< CAN0_ESR2: VPS Position                 */
#define CAN_ESR2_VPS(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_ESR2_VPS_SHIFT))&CAN_ESR2_VPS_MASK) /*!< CAN0_ESR2                               */
#define CAN_ESR2_LPTM_MASK                       (0x7FUL << CAN_ESR2_LPTM_SHIFT)                     /*!< CAN0_ESR2: LPTM Mask                    */
#define CAN_ESR2_LPTM_SHIFT                      16                                                  /*!< CAN0_ESR2: LPTM Position                */
#define CAN_ESR2_LPTM(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_ESR2_LPTM_SHIFT))&CAN_ESR2_LPTM_MASK) /*!< CAN0_ESR2                               */
/* ------- CRCR Bit Fields                          ------ */
#define CAN_CRCR_TXCRC_MASK                      (0x7FFFUL << CAN_CRCR_TXCRC_SHIFT)                  /*!< CAN0_CRCR: TXCRC Mask                   */
#define CAN_CRCR_TXCRC_SHIFT                     0                                                   /*!< CAN0_CRCR: TXCRC Position               */
#define CAN_CRCR_TXCRC(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CRCR_TXCRC_SHIFT))&CAN_CRCR_TXCRC_MASK) /*!< CAN0_CRCR                               */
#define CAN_CRCR_MBCRC_MASK                      (0x7FUL << CAN_CRCR_MBCRC_SHIFT)                    /*!< CAN0_CRCR: MBCRC Mask                   */
#define CAN_CRCR_MBCRC_SHIFT                     16                                                  /*!< CAN0_CRCR: MBCRC Position               */
#define CAN_CRCR_MBCRC(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CRCR_MBCRC_SHIFT))&CAN_CRCR_MBCRC_MASK) /*!< CAN0_CRCR                               */
/* ------- RXFGMASK Bit Fields                      ------ */
#define CAN_RXFGMASK_FGM_MASK                    (0xFFFFFFFFUL << CAN_RXFGMASK_FGM_SHIFT)            /*!< CAN0_RXFGMASK: FGM Mask                 */
#define CAN_RXFGMASK_FGM_SHIFT                   0                                                   /*!< CAN0_RXFGMASK: FGM Position             */
#define CAN_RXFGMASK_FGM(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_RXFGMASK_FGM_SHIFT))&CAN_RXFGMASK_FGM_MASK) /*!< CAN0_RXFGMASK                           */
/* ------- RXFIR Bit Fields                         ------ */
#define CAN_RXFIR_IDHIT_MASK                     (0x1FFUL << CAN_RXFIR_IDHIT_SHIFT)                  /*!< CAN0_RXFIR: IDHIT Mask                  */
#define CAN_RXFIR_IDHIT_SHIFT                    0                                                   /*!< CAN0_RXFIR: IDHIT Position              */
#define CAN_RXFIR_IDHIT(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_RXFIR_IDHIT_SHIFT))&CAN_RXFIR_IDHIT_MASK) /*!< CAN0_RXFIR                              */
/* ------- CS Bit Fields                            ------ */
#define CAN_CS_TIME_STAMP_MASK                   (0xFFFFUL << CAN_CS_TIME_STAMP_SHIFT)               /*!< CAN0_CS: TIME_STAMP Mask                */
#define CAN_CS_TIME_STAMP_SHIFT                  0                                                   /*!< CAN0_CS: TIME_STAMP Position            */
#define CAN_CS_TIME_STAMP(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CS_TIME_STAMP_SHIFT))&CAN_CS_TIME_STAMP_MASK) /*!< CAN0_CS                                 */
#define CAN_CS_DLC_MASK                          (0x0FUL << CAN_CS_DLC_SHIFT)                        /*!< CAN0_CS: DLC Mask                       */
#define CAN_CS_DLC_SHIFT                         16                                                  /*!< CAN0_CS: DLC Position                   */
#define CAN_CS_DLC(x)                            (((uint32_t)(((uint32_t)(x))<<CAN_CS_DLC_SHIFT))&CAN_CS_DLC_MASK) /*!< CAN0_CS                                 */
#define CAN_CS_RTR_MASK                          (0x01UL << CAN_CS_RTR_SHIFT)                        /*!< CAN0_CS: RTR Mask                       */
#define CAN_CS_RTR_SHIFT                         20                                                  /*!< CAN0_CS: RTR Position                   */
#define CAN_CS_RTR(x)                            (((uint32_t)(((uint32_t)(x))<<CAN_CS_RTR_SHIFT))&CAN_CS_RTR_MASK) /*!< CAN0_CS                                 */
#define CAN_CS_IDE_MASK                          (0x01UL << CAN_CS_IDE_SHIFT)                        /*!< CAN0_CS: IDE Mask                       */
#define CAN_CS_IDE_SHIFT                         21                                                  /*!< CAN0_CS: IDE Position                   */
#define CAN_CS_IDE(x)                            (((uint32_t)(((uint32_t)(x))<<CAN_CS_IDE_SHIFT))&CAN_CS_IDE_MASK) /*!< CAN0_CS                                 */
#define CAN_CS_SRR_MASK                          (0x01UL << CAN_CS_SRR_SHIFT)                        /*!< CAN0_CS: SRR Mask                       */
#define CAN_CS_SRR_SHIFT                         22                                                  /*!< CAN0_CS: SRR Position                   */
#define CAN_CS_SRR(x)                            (((uint32_t)(((uint32_t)(x))<<CAN_CS_SRR_SHIFT))&CAN_CS_SRR_MASK) /*!< CAN0_CS                                 */
#define CAN_CS_CODE_MASK                         (0x0FUL << CAN_CS_CODE_SHIFT)                       /*!< CAN0_CS: CODE Mask                      */
#define CAN_CS_CODE_SHIFT                        24                                                  /*!< CAN0_CS: CODE Position                  */
#define CAN_CS_CODE(x)                           (((uint32_t)(((uint32_t)(x))<<CAN_CS_CODE_SHIFT))&CAN_CS_CODE_MASK) /*!< CAN0_CS                                 */
/* ------- ID Bit Fields                            ------ */
#define CAN_ID_EXT_MASK                          (0x3FFFFUL << CAN_ID_EXT_SHIFT)                     /*!< CAN0_ID: EXT Mask                       */
#define CAN_ID_EXT_SHIFT                         0                                                   /*!< CAN0_ID: EXT Position                   */
#define CAN_ID_EXT(x)                            (((uint32_t)(((uint32_t)(x))<<CAN_ID_EXT_SHIFT))&CAN_ID_EXT_MASK) /*!< CAN0_ID                                 */
#define CAN_ID_STD_MASK                          (0x7FFUL << CAN_ID_STD_SHIFT)                       /*!< CAN0_ID: STD Mask                       */
#define CAN_ID_STD_SHIFT                         18                                                  /*!< CAN0_ID: STD Position                   */
#define CAN_ID_STD(x)                            (((uint32_t)(((uint32_t)(x))<<CAN_ID_STD_SHIFT))&CAN_ID_STD_MASK) /*!< CAN0_ID                                 */
#define CAN_ID_PRIO_MASK                         (0x07UL << CAN_ID_PRIO_SHIFT)                       /*!< CAN0_ID: PRIO Mask                      */
#define CAN_ID_PRIO_SHIFT                        29                                                  /*!< CAN0_ID: PRIO Position                  */
#define CAN_ID_PRIO(x)                           (((uint32_t)(((uint32_t)(x))<<CAN_ID_PRIO_SHIFT))&CAN_ID_PRIO_MASK) /*!< CAN0_ID                                 */
/* ------- WORD0 Bit Fields                         ------ */
#define CAN_WORD0_DATA_BYTE_3_MASK               (0xFFUL << CAN_WORD0_DATA_BYTE_3_SHIFT)             /*!< CAN0_WORD0: DATA_BYTE_3 Mask            */
#define CAN_WORD0_DATA_BYTE_3_SHIFT              0                                                   /*!< CAN0_WORD0: DATA_BYTE_3 Position        */
#define CAN_WORD0_DATA_BYTE_3(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD0_DATA_BYTE_3_SHIFT))&CAN_WORD0_DATA_BYTE_3_MASK) /*!< CAN0_WORD0                              */
#define CAN_WORD0_DATA_BYTE_2_MASK               (0xFFUL << CAN_WORD0_DATA_BYTE_2_SHIFT)             /*!< CAN0_WORD0: DATA_BYTE_2 Mask            */
#define CAN_WORD0_DATA_BYTE_2_SHIFT              8                                                   /*!< CAN0_WORD0: DATA_BYTE_2 Position        */
#define CAN_WORD0_DATA_BYTE_2(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD0_DATA_BYTE_2_SHIFT))&CAN_WORD0_DATA_BYTE_2_MASK) /*!< CAN0_WORD0                              */
#define CAN_WORD0_DATA_BYTE_1_MASK               (0xFFUL << CAN_WORD0_DATA_BYTE_1_SHIFT)             /*!< CAN0_WORD0: DATA_BYTE_1 Mask            */
#define CAN_WORD0_DATA_BYTE_1_SHIFT              16                                                  /*!< CAN0_WORD0: DATA_BYTE_1 Position        */
#define CAN_WORD0_DATA_BYTE_1(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD0_DATA_BYTE_1_SHIFT))&CAN_WORD0_DATA_BYTE_1_MASK) /*!< CAN0_WORD0                              */
#define CAN_WORD0_DATA_BYTE_0_MASK               (0xFFUL << CAN_WORD0_DATA_BYTE_0_SHIFT)             /*!< CAN0_WORD0: DATA_BYTE_0 Mask            */
#define CAN_WORD0_DATA_BYTE_0_SHIFT              24                                                  /*!< CAN0_WORD0: DATA_BYTE_0 Position        */
#define CAN_WORD0_DATA_BYTE_0(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD0_DATA_BYTE_0_SHIFT))&CAN_WORD0_DATA_BYTE_0_MASK) /*!< CAN0_WORD0                              */
/* ------- WORD1 Bit Fields                         ------ */
#define CAN_WORD1_DATA_BYTE_7_MASK               (0xFFUL << CAN_WORD1_DATA_BYTE_7_SHIFT)             /*!< CAN0_WORD1: DATA_BYTE_7 Mask            */
#define CAN_WORD1_DATA_BYTE_7_SHIFT              0                                                   /*!< CAN0_WORD1: DATA_BYTE_7 Position        */
#define CAN_WORD1_DATA_BYTE_7(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD1_DATA_BYTE_7_SHIFT))&CAN_WORD1_DATA_BYTE_7_MASK) /*!< CAN0_WORD1                              */
#define CAN_WORD1_DATA_BYTE_6_MASK               (0xFFUL << CAN_WORD1_DATA_BYTE_6_SHIFT)             /*!< CAN0_WORD1: DATA_BYTE_6 Mask            */
#define CAN_WORD1_DATA_BYTE_6_SHIFT              8                                                   /*!< CAN0_WORD1: DATA_BYTE_6 Position        */
#define CAN_WORD1_DATA_BYTE_6(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD1_DATA_BYTE_6_SHIFT))&CAN_WORD1_DATA_BYTE_6_MASK) /*!< CAN0_WORD1                              */
#define CAN_WORD1_DATA_BYTE_5_MASK               (0xFFUL << CAN_WORD1_DATA_BYTE_5_SHIFT)             /*!< CAN0_WORD1: DATA_BYTE_5 Mask            */
#define CAN_WORD1_DATA_BYTE_5_SHIFT              16                                                  /*!< CAN0_WORD1: DATA_BYTE_5 Position        */
#define CAN_WORD1_DATA_BYTE_5(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD1_DATA_BYTE_5_SHIFT))&CAN_WORD1_DATA_BYTE_5_MASK) /*!< CAN0_WORD1                              */
#define CAN_WORD1_DATA_BYTE_4_MASK               (0xFFUL << CAN_WORD1_DATA_BYTE_4_SHIFT)             /*!< CAN0_WORD1: DATA_BYTE_4 Mask            */
#define CAN_WORD1_DATA_BYTE_4_SHIFT              24                                                  /*!< CAN0_WORD1: DATA_BYTE_4 Position        */
#define CAN_WORD1_DATA_BYTE_4(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD1_DATA_BYTE_4_SHIFT))&CAN_WORD1_DATA_BYTE_4_MASK) /*!< CAN0_WORD1                              */
/* ------- RXIMR Bit Fields                         ------ */
#define CAN_RXIMR_MI_MASK                        (0xFFFFFFFFUL << CAN_RXIMR_MI_SHIFT)                /*!< CAN0_RXIMR: MI Mask                     */
#define CAN_RXIMR_MI_SHIFT                       0                                                   /*!< CAN0_RXIMR: MI Position                 */
#define CAN_RXIMR_MI(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_RXIMR_MI_SHIFT))&CAN_RXIMR_MI_MASK) /*!< CAN0_RXIMR                              */
/**
 * @} */ /* End group CAN_Register_Masks_GROUP 
 */

/* CAN0 - Peripheral instance base addresses */
#define CAN0_BasePtr                   0x40024000UL //!< Peripheral base address
#define CAN0                           ((CAN_Type *) CAN0_BasePtr) //!< Freescale base pointer
#define CAN0_BASE_PTR                  (CAN0) //!< Freescale style base pointer
/**
 * @} */ /* End group CAN_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer
* @brief C Struct for CMP
* @{
*/

/* ================================================================================ */
/* ================           CMP0 (file:CMP0)                     ================ */
/* ================================================================================ */

/**
 * @brief Comparator, Voltage Ref, D-to-A Converter and Analog Mux
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
#define CMP_CR0_HYSTCTR_MASK                     (0x03UL << CMP_CR0_HYSTCTR_SHIFT)                   /*!< CMP0_CR0: HYSTCTR Mask                  */
#define CMP_CR0_HYSTCTR_SHIFT                    0                                                   /*!< CMP0_CR0: HYSTCTR Position              */
#define CMP_CR0_HYSTCTR(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_CR0_HYSTCTR_SHIFT))&CMP_CR0_HYSTCTR_MASK) /*!< CMP0_CR0                                */
#define CMP_CR0_FILTER_CNT_MASK                  (0x07UL << CMP_CR0_FILTER_CNT_SHIFT)                /*!< CMP0_CR0: FILTER_CNT Mask               */
#define CMP_CR0_FILTER_CNT_SHIFT                 4                                                   /*!< CMP0_CR0: FILTER_CNT Position           */
#define CMP_CR0_FILTER_CNT(x)                    (((uint8_t)(((uint8_t)(x))<<CMP_CR0_FILTER_CNT_SHIFT))&CMP_CR0_FILTER_CNT_MASK) /*!< CMP0_CR0                                */
/* ------- CR1 Bit Fields                           ------ */
#define CMP_CR1_EN_MASK                          (0x01UL << CMP_CR1_EN_SHIFT)                        /*!< CMP0_CR1: EN Mask                       */
#define CMP_CR1_EN_SHIFT                         0                                                   /*!< CMP0_CR1: EN Position                   */
#define CMP_CR1_EN(x)                            (((uint8_t)(((uint8_t)(x))<<CMP_CR1_EN_SHIFT))&CMP_CR1_EN_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_OPE_MASK                         (0x01UL << CMP_CR1_OPE_SHIFT)                       /*!< CMP0_CR1: OPE Mask                      */
#define CMP_CR1_OPE_SHIFT                        1                                                   /*!< CMP0_CR1: OPE Position                  */
#define CMP_CR1_OPE(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_CR1_OPE_SHIFT))&CMP_CR1_OPE_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_COS_MASK                         (0x01UL << CMP_CR1_COS_SHIFT)                       /*!< CMP0_CR1: COS Mask                      */
#define CMP_CR1_COS_SHIFT                        2                                                   /*!< CMP0_CR1: COS Position                  */
#define CMP_CR1_COS(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_CR1_COS_SHIFT))&CMP_CR1_COS_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_INV_MASK                         (0x01UL << CMP_CR1_INV_SHIFT)                       /*!< CMP0_CR1: INV Mask                      */
#define CMP_CR1_INV_SHIFT                        3                                                   /*!< CMP0_CR1: INV Position                  */
#define CMP_CR1_INV(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_CR1_INV_SHIFT))&CMP_CR1_INV_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_PMODE_MASK                       (0x01UL << CMP_CR1_PMODE_SHIFT)                     /*!< CMP0_CR1: PMODE Mask                    */
#define CMP_CR1_PMODE_SHIFT                      4                                                   /*!< CMP0_CR1: PMODE Position                */
#define CMP_CR1_PMODE(x)                         (((uint8_t)(((uint8_t)(x))<<CMP_CR1_PMODE_SHIFT))&CMP_CR1_PMODE_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_WE_MASK                          (0x01UL << CMP_CR1_WE_SHIFT)                        /*!< CMP0_CR1: WE Mask                       */
#define CMP_CR1_WE_SHIFT                         6                                                   /*!< CMP0_CR1: WE Position                   */
#define CMP_CR1_WE(x)                            (((uint8_t)(((uint8_t)(x))<<CMP_CR1_WE_SHIFT))&CMP_CR1_WE_MASK) /*!< CMP0_CR1                                */
#define CMP_CR1_SE_MASK                          (0x01UL << CMP_CR1_SE_SHIFT)                        /*!< CMP0_CR1: SE Mask                       */
#define CMP_CR1_SE_SHIFT                         7                                                   /*!< CMP0_CR1: SE Position                   */
#define CMP_CR1_SE(x)                            (((uint8_t)(((uint8_t)(x))<<CMP_CR1_SE_SHIFT))&CMP_CR1_SE_MASK) /*!< CMP0_CR1                                */
/* ------- FPR Bit Fields                           ------ */
#define CMP_FPR_FILT_PER_MASK                    (0xFFUL << CMP_FPR_FILT_PER_SHIFT)                  /*!< CMP0_FPR: FILT_PER Mask                 */
#define CMP_FPR_FILT_PER_SHIFT                   0                                                   /*!< CMP0_FPR: FILT_PER Position             */
#define CMP_FPR_FILT_PER(x)                      (((uint8_t)(((uint8_t)(x))<<CMP_FPR_FILT_PER_SHIFT))&CMP_FPR_FILT_PER_MASK) /*!< CMP0_FPR                                */
/* ------- SCR Bit Fields                           ------ */
#define CMP_SCR_COUT_MASK                        (0x01UL << CMP_SCR_COUT_SHIFT)                      /*!< CMP0_SCR: COUT Mask                     */
#define CMP_SCR_COUT_SHIFT                       0                                                   /*!< CMP0_SCR: COUT Position                 */
#define CMP_SCR_COUT(x)                          (((uint8_t)(((uint8_t)(x))<<CMP_SCR_COUT_SHIFT))&CMP_SCR_COUT_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_CFF_MASK                         (0x01UL << CMP_SCR_CFF_SHIFT)                       /*!< CMP0_SCR: CFF Mask                      */
#define CMP_SCR_CFF_SHIFT                        1                                                   /*!< CMP0_SCR: CFF Position                  */
#define CMP_SCR_CFF(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_CFF_SHIFT))&CMP_SCR_CFF_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_CFR_MASK                         (0x01UL << CMP_SCR_CFR_SHIFT)                       /*!< CMP0_SCR: CFR Mask                      */
#define CMP_SCR_CFR_SHIFT                        2                                                   /*!< CMP0_SCR: CFR Position                  */
#define CMP_SCR_CFR(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_CFR_SHIFT))&CMP_SCR_CFR_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_IEF_MASK                         (0x01UL << CMP_SCR_IEF_SHIFT)                       /*!< CMP0_SCR: IEF Mask                      */
#define CMP_SCR_IEF_SHIFT                        3                                                   /*!< CMP0_SCR: IEF Position                  */
#define CMP_SCR_IEF(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_IEF_SHIFT))&CMP_SCR_IEF_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_IER_MASK                         (0x01UL << CMP_SCR_IER_SHIFT)                       /*!< CMP0_SCR: IER Mask                      */
#define CMP_SCR_IER_SHIFT                        4                                                   /*!< CMP0_SCR: IER Position                  */
#define CMP_SCR_IER(x)                           (((uint8_t)(((uint8_t)(x))<<CMP_SCR_IER_SHIFT))&CMP_SCR_IER_MASK) /*!< CMP0_SCR                                */
#define CMP_SCR_DMAEN_MASK                       (0x01UL << CMP_SCR_DMAEN_SHIFT)                     /*!< CMP0_SCR: DMAEN Mask                    */
#define CMP_SCR_DMAEN_SHIFT                      6                                                   /*!< CMP0_SCR: DMAEN Position                */
#define CMP_SCR_DMAEN(x)                         (((uint8_t)(((uint8_t)(x))<<CMP_SCR_DMAEN_SHIFT))&CMP_SCR_DMAEN_MASK) /*!< CMP0_SCR                                */
/* ------- DACCR Bit Fields                         ------ */
#define CMP_DACCR_VOSEL_MASK                     (0x3FUL << CMP_DACCR_VOSEL_SHIFT)                   /*!< CMP0_DACCR: VOSEL Mask                  */
#define CMP_DACCR_VOSEL_SHIFT                    0                                                   /*!< CMP0_DACCR: VOSEL Position              */
#define CMP_DACCR_VOSEL(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_VOSEL_SHIFT))&CMP_DACCR_VOSEL_MASK) /*!< CMP0_DACCR                              */
#define CMP_DACCR_VRSEL_MASK                     (0x01UL << CMP_DACCR_VRSEL_SHIFT)                   /*!< CMP0_DACCR: VRSEL Mask                  */
#define CMP_DACCR_VRSEL_SHIFT                    6                                                   /*!< CMP0_DACCR: VRSEL Position              */
#define CMP_DACCR_VRSEL(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_VRSEL_SHIFT))&CMP_DACCR_VRSEL_MASK) /*!< CMP0_DACCR                              */
#define CMP_DACCR_DACEN_MASK                     (0x01UL << CMP_DACCR_DACEN_SHIFT)                   /*!< CMP0_DACCR: DACEN Mask                  */
#define CMP_DACCR_DACEN_SHIFT                    7                                                   /*!< CMP0_DACCR: DACEN Position              */
#define CMP_DACCR_DACEN(x)                       (((uint8_t)(((uint8_t)(x))<<CMP_DACCR_DACEN_SHIFT))&CMP_DACCR_DACEN_MASK) /*!< CMP0_DACCR                              */
/* ------- MUXCR Bit Fields                         ------ */
#define CMP_MUXCR_MSEL_MASK                      (0x07UL << CMP_MUXCR_MSEL_SHIFT)                    /*!< CMP0_MUXCR: MSEL Mask                   */
#define CMP_MUXCR_MSEL_SHIFT                     0                                                   /*!< CMP0_MUXCR: MSEL Position               */
#define CMP_MUXCR_MSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_MSEL_SHIFT))&CMP_MUXCR_MSEL_MASK) /*!< CMP0_MUXCR                              */
#define CMP_MUXCR_PSEL_MASK                      (0x07UL << CMP_MUXCR_PSEL_SHIFT)                    /*!< CMP0_MUXCR: PSEL Mask                   */
#define CMP_MUXCR_PSEL_SHIFT                     3                                                   /*!< CMP0_MUXCR: PSEL Position               */
#define CMP_MUXCR_PSEL(x)                        (((uint8_t)(((uint8_t)(x))<<CMP_MUXCR_PSEL_SHIFT))&CMP_MUXCR_PSEL_MASK) /*!< CMP0_MUXCR                              */
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
* @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer
* @brief C Struct for CMP
* @{
*/

/* ================================================================================ */
/* ================           CMP1 (derived from CMP0)             ================ */
/* ================================================================================ */

/**
 * @brief Comparator, Voltage Ref, D-to-A Converter and Analog Mux
 */

/* CMP1 - Peripheral instance base addresses */
#define CMP1_BasePtr                   0x40073008UL //!< Peripheral base address
#define CMP1                           ((CMP_Type *) CMP1_BasePtr) //!< Freescale base pointer
#define CMP1_BASE_PTR                  (CMP1) //!< Freescale style base pointer
/**
 * @} */ /* End group CMP_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer
* @brief C Struct for CMP
* @{
*/

/* ================================================================================ */
/* ================           CMP2 (derived from CMP0)             ================ */
/* ================================================================================ */

/**
 * @brief Comparator, Voltage Ref, D-to-A Converter and Analog Mux
 */

/* CMP2 - Peripheral instance base addresses */
#define CMP2_BasePtr                   0x40073010UL //!< Peripheral base address
#define CMP2                           ((CMP_Type *) CMP2_BasePtr) //!< Freescale base pointer
#define CMP2_BASE_PTR                  (CMP2) //!< Freescale style base pointer
/**
 * @} */ /* End group CMP_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMT_Peripheral_access_layer_GROUP CMT Peripheral Access Layer
* @brief C Struct for CMT
* @{
*/

/* ================================================================================ */
/* ================           CMT (file:CMT_0)                     ================ */
/* ================================================================================ */

/**
 * @brief Carrier Modulator Transmitter
 */
/**
* @addtogroup CMT_structs_GROUP CMT struct
* @brief Struct for CMT
* @{
*/
typedef struct {                                /*       CMT Structure                                                */
   __IO uint8_t   CGH1;                         /**< 0000: Carrier Generator High Data Register 1                       */
   __IO uint8_t   CGL1;                         /**< 0001: Carrier Generator Low Data Register 1                        */
   __IO uint8_t   CGH2;                         /**< 0002: Carrier Generator High Data Register 2                       */
   __IO uint8_t   CGL2;                         /**< 0003: Carrier Generator Low Data Register 2                        */
   __IO uint8_t   OC;                           /**< 0004: Output Control Register                                      */
   __IO uint8_t   MSC;                          /**< 0005: Modulator Status and Control Register                        */
   __IO uint8_t   CMD1;                         /**< 0006: Modulator Data Register Mark High                            */
   __IO uint8_t   CMD2;                         /**< 0007: Modulator Data Register Mark Low                             */
   __IO uint8_t   CMD3;                         /**< 0008: Modulator Data Register Space High                           */
   __IO uint8_t   CMD4;                         /**< 0009: Modulator Data Register Space Low                            */
   __IO uint8_t   PPS;                          /**< 000A: Primary Prescaler Register                                   */
   __IO uint8_t   DMA;                          /**< 000B: Direct Memory Access                                         */
} CMT_Type;

/**
 * @} */ /* End group CMT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CMT' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CMT_Register_Masks_GROUP CMT Register Masks
* @brief Register Masks for CMT
* @{
*/
/* ------- CGH1 Bit Fields                          ------ */
#define CMT_CGH1_PH_MASK                         (0xFFUL << CMT_CGH1_PH_SHIFT)                       /*!< CMT_CGH1: PH Mask                       */
#define CMT_CGH1_PH_SHIFT                        0                                                   /*!< CMT_CGH1: PH Position                   */
#define CMT_CGH1_PH(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGH1_PH_SHIFT))&CMT_CGH1_PH_MASK) /*!< CMT_CGH1                                */
/* ------- CGL1 Bit Fields                          ------ */
#define CMT_CGL1_PL_MASK                         (0xFFUL << CMT_CGL1_PL_SHIFT)                       /*!< CMT_CGL1: PL Mask                       */
#define CMT_CGL1_PL_SHIFT                        0                                                   /*!< CMT_CGL1: PL Position                   */
#define CMT_CGL1_PL(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGL1_PL_SHIFT))&CMT_CGL1_PL_MASK) /*!< CMT_CGL1                                */
/* ------- CGH2 Bit Fields                          ------ */
#define CMT_CGH2_SH_MASK                         (0xFFUL << CMT_CGH2_SH_SHIFT)                       /*!< CMT_CGH2: SH Mask                       */
#define CMT_CGH2_SH_SHIFT                        0                                                   /*!< CMT_CGH2: SH Position                   */
#define CMT_CGH2_SH(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGH2_SH_SHIFT))&CMT_CGH2_SH_MASK) /*!< CMT_CGH2                                */
/* ------- CGL2 Bit Fields                          ------ */
#define CMT_CGL2_SL_MASK                         (0xFFUL << CMT_CGL2_SL_SHIFT)                       /*!< CMT_CGL2: SL Mask                       */
#define CMT_CGL2_SL_SHIFT                        0                                                   /*!< CMT_CGL2: SL Position                   */
#define CMT_CGL2_SL(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CGL2_SL_SHIFT))&CMT_CGL2_SL_MASK) /*!< CMT_CGL2                                */
/* ------- OC Bit Fields                            ------ */
#define CMT_OC_IROPEN_MASK                       (0x01UL << CMT_OC_IROPEN_SHIFT)                     /*!< CMT_OC: IROPEN Mask                     */
#define CMT_OC_IROPEN_SHIFT                      5                                                   /*!< CMT_OC: IROPEN Position                 */
#define CMT_OC_IROPEN(x)                         (((uint8_t)(((uint8_t)(x))<<CMT_OC_IROPEN_SHIFT))&CMT_OC_IROPEN_MASK) /*!< CMT_OC                                  */
#define CMT_OC_CMTPOL_MASK                       (0x01UL << CMT_OC_CMTPOL_SHIFT)                     /*!< CMT_OC: CMTPOL Mask                     */
#define CMT_OC_CMTPOL_SHIFT                      6                                                   /*!< CMT_OC: CMTPOL Position                 */
#define CMT_OC_CMTPOL(x)                         (((uint8_t)(((uint8_t)(x))<<CMT_OC_CMTPOL_SHIFT))&CMT_OC_CMTPOL_MASK) /*!< CMT_OC                                  */
#define CMT_OC_IROL_MASK                         (0x01UL << CMT_OC_IROL_SHIFT)                       /*!< CMT_OC: IROL Mask                       */
#define CMT_OC_IROL_SHIFT                        7                                                   /*!< CMT_OC: IROL Position                   */
#define CMT_OC_IROL(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_OC_IROL_SHIFT))&CMT_OC_IROL_MASK) /*!< CMT_OC                                  */
/* ------- MSC Bit Fields                           ------ */
#define CMT_MSC_MCGEN_MASK                       (0x01UL << CMT_MSC_MCGEN_SHIFT)                     /*!< CMT_MSC: MCGEN Mask                     */
#define CMT_MSC_MCGEN_SHIFT                      0                                                   /*!< CMT_MSC: MCGEN Position                 */
#define CMT_MSC_MCGEN(x)                         (((uint8_t)(((uint8_t)(x))<<CMT_MSC_MCGEN_SHIFT))&CMT_MSC_MCGEN_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_EOCIE_MASK                       (0x01UL << CMT_MSC_EOCIE_SHIFT)                     /*!< CMT_MSC: EOCIE Mask                     */
#define CMT_MSC_EOCIE_SHIFT                      1                                                   /*!< CMT_MSC: EOCIE Position                 */
#define CMT_MSC_EOCIE(x)                         (((uint8_t)(((uint8_t)(x))<<CMT_MSC_EOCIE_SHIFT))&CMT_MSC_EOCIE_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_FSK_MASK                         (0x01UL << CMT_MSC_FSK_SHIFT)                       /*!< CMT_MSC: FSK Mask                       */
#define CMT_MSC_FSK_SHIFT                        2                                                   /*!< CMT_MSC: FSK Position                   */
#define CMT_MSC_FSK(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_MSC_FSK_SHIFT))&CMT_MSC_FSK_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_BASE_MASK                        (0x01UL << CMT_MSC_BASE_SHIFT)                      /*!< CMT_MSC: BASE Mask                      */
#define CMT_MSC_BASE_SHIFT                       3                                                   /*!< CMT_MSC: BASE Position                  */
#define CMT_MSC_BASE(x)                          (((uint8_t)(((uint8_t)(x))<<CMT_MSC_BASE_SHIFT))&CMT_MSC_BASE_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_EXSPC_MASK                       (0x01UL << CMT_MSC_EXSPC_SHIFT)                     /*!< CMT_MSC: EXSPC Mask                     */
#define CMT_MSC_EXSPC_SHIFT                      4                                                   /*!< CMT_MSC: EXSPC Position                 */
#define CMT_MSC_EXSPC(x)                         (((uint8_t)(((uint8_t)(x))<<CMT_MSC_EXSPC_SHIFT))&CMT_MSC_EXSPC_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_CMTDIV_MASK                      (0x03UL << CMT_MSC_CMTDIV_SHIFT)                    /*!< CMT_MSC: CMTDIV Mask                    */
#define CMT_MSC_CMTDIV_SHIFT                     5                                                   /*!< CMT_MSC: CMTDIV Position                */
#define CMT_MSC_CMTDIV(x)                        (((uint8_t)(((uint8_t)(x))<<CMT_MSC_CMTDIV_SHIFT))&CMT_MSC_CMTDIV_MASK) /*!< CMT_MSC                                 */
#define CMT_MSC_EOCF_MASK                        (0x01UL << CMT_MSC_EOCF_SHIFT)                      /*!< CMT_MSC: EOCF Mask                      */
#define CMT_MSC_EOCF_SHIFT                       7                                                   /*!< CMT_MSC: EOCF Position                  */
#define CMT_MSC_EOCF(x)                          (((uint8_t)(((uint8_t)(x))<<CMT_MSC_EOCF_SHIFT))&CMT_MSC_EOCF_MASK) /*!< CMT_MSC                                 */
/* ------- CMD1 Bit Fields                          ------ */
#define CMT_CMD1_MB_MASK                         (0xFFUL << CMT_CMD1_MB_SHIFT)                       /*!< CMT_CMD1: MB Mask                       */
#define CMT_CMD1_MB_SHIFT                        0                                                   /*!< CMT_CMD1: MB Position                   */
#define CMT_CMD1_MB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD1_MB_SHIFT))&CMT_CMD1_MB_MASK) /*!< CMT_CMD1                                */
/* ------- CMD2 Bit Fields                          ------ */
#define CMT_CMD2_MB_MASK                         (0xFFUL << CMT_CMD2_MB_SHIFT)                       /*!< CMT_CMD2: MB Mask                       */
#define CMT_CMD2_MB_SHIFT                        0                                                   /*!< CMT_CMD2: MB Position                   */
#define CMT_CMD2_MB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD2_MB_SHIFT))&CMT_CMD2_MB_MASK) /*!< CMT_CMD2                                */
/* ------- CMD3 Bit Fields                          ------ */
#define CMT_CMD3_SB_MASK                         (0xFFUL << CMT_CMD3_SB_SHIFT)                       /*!< CMT_CMD3: SB Mask                       */
#define CMT_CMD3_SB_SHIFT                        0                                                   /*!< CMT_CMD3: SB Position                   */
#define CMT_CMD3_SB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD3_SB_SHIFT))&CMT_CMD3_SB_MASK) /*!< CMT_CMD3                                */
/* ------- CMD4 Bit Fields                          ------ */
#define CMT_CMD4_SB_MASK                         (0xFFUL << CMT_CMD4_SB_SHIFT)                       /*!< CMT_CMD4: SB Mask                       */
#define CMT_CMD4_SB_SHIFT                        0                                                   /*!< CMT_CMD4: SB Position                   */
#define CMT_CMD4_SB(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_CMD4_SB_SHIFT))&CMT_CMD4_SB_MASK) /*!< CMT_CMD4                                */
/* ------- PPS Bit Fields                           ------ */
#define CMT_PPS_PPSDIV_MASK                      (0x0FUL << CMT_PPS_PPSDIV_SHIFT)                    /*!< CMT_PPS: PPSDIV Mask                    */
#define CMT_PPS_PPSDIV_SHIFT                     0                                                   /*!< CMT_PPS: PPSDIV Position                */
#define CMT_PPS_PPSDIV(x)                        (((uint8_t)(((uint8_t)(x))<<CMT_PPS_PPSDIV_SHIFT))&CMT_PPS_PPSDIV_MASK) /*!< CMT_PPS                                 */
/* ------- DMA Bit Fields                           ------ */
#define CMT_DMA_DMA_MASK                         (0x01UL << CMT_DMA_DMA_SHIFT)                       /*!< CMT_DMA: DMA Mask                       */
#define CMT_DMA_DMA_SHIFT                        0                                                   /*!< CMT_DMA: DMA Position                   */
#define CMT_DMA_DMA(x)                           (((uint8_t)(((uint8_t)(x))<<CMT_DMA_DMA_SHIFT))&CMT_DMA_DMA_MASK) /*!< CMT_DMA                                 */
/**
 * @} */ /* End group CMT_Register_Masks_GROUP 
 */

/* CMT - Peripheral instance base addresses */
#define CMT_BasePtr                    0x40062000UL //!< Peripheral base address
#define CMT                            ((CMT_Type *) CMT_BasePtr) //!< Freescale base pointer
#define CMT_BASE_PTR                   (CMT) //!< Freescale style base pointer
/**
 * @} */ /* End group CMT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CRC_Peripheral_access_layer_GROUP CRC Peripheral Access Layer
* @brief C Struct for CRC
* @{
*/

/* ================================================================================ */
/* ================           CRC (file:CRC_0x40032000)            ================ */
/* ================================================================================ */

/**
 * @brief Cyclic Redundancy Check
 */
/**
* @addtogroup CRC_structs_GROUP CRC struct
* @brief Struct for CRC
* @{
*/
typedef struct {                                /*       CRC Structure                                                */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  CRC;                       /**< 0000: Data register                                                */
      struct {                                  /**< 0000: (size=0004)                                                  */
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  CRCL;                /**< 0000: CRCL register                                                */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   CRCLL;            /**< 0000: CRCLL register                                               */
               __IO uint8_t   CRCLU;            /**< 0001: CRCLU register                                               */
            };
         };
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  CRCH;                /**< 0002: CRCH register                                                */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   CRCHL;            /**< 0002: CRCHL register                                               */
               __IO uint8_t   CRCHU;            /**< 0003: CRCHU register                                               */
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
         __I  uint8_t   RESERVED0[3];          
         __IO uint8_t   CTRLHU;                 /**< 000B: Control register (byte access)                               */
      };
   };
} CRC_Type;

/**
 * @} */ /* End group CRC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CRC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CRC_Register_Masks_GROUP CRC Register Masks
* @brief Register Masks for CRC
* @{
*/
/* ------- CRC Bit Fields                           ------ */
#define CRC_CRC_LL_MASK                          (0xFFUL << CRC_CRC_LL_SHIFT)                        /*!< CRC_CRC: LL Mask                        */
#define CRC_CRC_LL_SHIFT                         0                                                   /*!< CRC_CRC: LL Position                    */
#define CRC_CRC_LL(x)                            (((uint32_t)(((uint32_t)(x))<<CRC_CRC_LL_SHIFT))&CRC_CRC_LL_MASK) /*!< CRC_CRC                                 */
#define CRC_CRC_LU_MASK                          (0xFFUL << CRC_CRC_LU_SHIFT)                        /*!< CRC_CRC: LU Mask                        */
#define CRC_CRC_LU_SHIFT                         8                                                   /*!< CRC_CRC: LU Position                    */
#define CRC_CRC_LU(x)                            (((uint32_t)(((uint32_t)(x))<<CRC_CRC_LU_SHIFT))&CRC_CRC_LU_MASK) /*!< CRC_CRC                                 */
#define CRC_CRC_HL_MASK                          (0xFFUL << CRC_CRC_HL_SHIFT)                        /*!< CRC_CRC: HL Mask                        */
#define CRC_CRC_HL_SHIFT                         16                                                  /*!< CRC_CRC: HL Position                    */
#define CRC_CRC_HL(x)                            (((uint32_t)(((uint32_t)(x))<<CRC_CRC_HL_SHIFT))&CRC_CRC_HL_MASK) /*!< CRC_CRC                                 */
#define CRC_CRC_HU_MASK                          (0xFFUL << CRC_CRC_HU_SHIFT)                        /*!< CRC_CRC: HU Mask                        */
#define CRC_CRC_HU_SHIFT                         24                                                  /*!< CRC_CRC: HU Position                    */
#define CRC_CRC_HU(x)                            (((uint32_t)(((uint32_t)(x))<<CRC_CRC_HU_SHIFT))&CRC_CRC_HU_MASK) /*!< CRC_CRC                                 */
/* ------- CRCL Bit Fields                          ------ */
#define CRC_CRCL_CRCL_MASK                       (0xFFFFUL << CRC_CRCL_CRCL_SHIFT)                   /*!< CRC_CRCL: CRCL Mask                     */
#define CRC_CRCL_CRCL_SHIFT                      0                                                   /*!< CRC_CRCL: CRCL Position                 */
#define CRC_CRCL_CRCL(x)                         (((uint16_t)(((uint16_t)(x))<<CRC_CRCL_CRCL_SHIFT))&CRC_CRCL_CRCL_MASK) /*!< CRC_CRCL                                */
/* ------- CRCLL Bit Fields                         ------ */
#define CRC_CRCLL_CRCLL_MASK                     (0xFFUL << CRC_CRCLL_CRCLL_SHIFT)                   /*!< CRC_CRCLL: CRCLL Mask                   */
#define CRC_CRCLL_CRCLL_SHIFT                    0                                                   /*!< CRC_CRCLL: CRCLL Position               */
#define CRC_CRCLL_CRCLL(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CRCLL_CRCLL_SHIFT))&CRC_CRCLL_CRCLL_MASK) /*!< CRC_CRCLL                               */
/* ------- CRCLU Bit Fields                         ------ */
#define CRC_CRCLU_CRCLU_MASK                     (0xFFUL << CRC_CRCLU_CRCLU_SHIFT)                   /*!< CRC_CRCLU: CRCLU Mask                   */
#define CRC_CRCLU_CRCLU_SHIFT                    0                                                   /*!< CRC_CRCLU: CRCLU Position               */
#define CRC_CRCLU_CRCLU(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CRCLU_CRCLU_SHIFT))&CRC_CRCLU_CRCLU_MASK) /*!< CRC_CRCLU                               */
/* ------- CRCH Bit Fields                          ------ */
#define CRC_CRCH_CRCH_MASK                       (0xFFFFUL << CRC_CRCH_CRCH_SHIFT)                   /*!< CRC_CRCH: CRCH Mask                     */
#define CRC_CRCH_CRCH_SHIFT                      0                                                   /*!< CRC_CRCH: CRCH Position                 */
#define CRC_CRCH_CRCH(x)                         (((uint16_t)(((uint16_t)(x))<<CRC_CRCH_CRCH_SHIFT))&CRC_CRCH_CRCH_MASK) /*!< CRC_CRCH                                */
/* ------- CRCHL Bit Fields                         ------ */
#define CRC_CRCHL_CRCHL_MASK                     (0xFFUL << CRC_CRCHL_CRCHL_SHIFT)                   /*!< CRC_CRCHL: CRCHL Mask                   */
#define CRC_CRCHL_CRCHL_SHIFT                    0                                                   /*!< CRC_CRCHL: CRCHL Position               */
#define CRC_CRCHL_CRCHL(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CRCHL_CRCHL_SHIFT))&CRC_CRCHL_CRCHL_MASK) /*!< CRC_CRCHL                               */
/* ------- CRCHU Bit Fields                         ------ */
#define CRC_CRCHU_CRCHU_MASK                     (0xFFUL << CRC_CRCHU_CRCHU_SHIFT)                   /*!< CRC_CRCHU: CRCHU Mask                   */
#define CRC_CRCHU_CRCHU_SHIFT                    0                                                   /*!< CRC_CRCHU: CRCHU Position               */
#define CRC_CRCHU_CRCHU(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CRCHU_CRCHU_SHIFT))&CRC_CRCHU_CRCHU_MASK) /*!< CRC_CRCHU                               */
/* ------- GPOLY Bit Fields                         ------ */
#define CRC_GPOLY_LOW_MASK                       (0xFFFFUL << CRC_GPOLY_LOW_SHIFT)                   /*!< CRC_GPOLY: LOW Mask                     */
#define CRC_GPOLY_LOW_SHIFT                      0                                                   /*!< CRC_GPOLY: LOW Position                 */
#define CRC_GPOLY_LOW(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_LOW_SHIFT))&CRC_GPOLY_LOW_MASK) /*!< CRC_GPOLY                               */
#define CRC_GPOLY_HIGH_MASK                      (0xFFFFUL << CRC_GPOLY_HIGH_SHIFT)                  /*!< CRC_GPOLY: HIGH Mask                    */
#define CRC_GPOLY_HIGH_SHIFT                     16                                                  /*!< CRC_GPOLY: HIGH Position                */
#define CRC_GPOLY_HIGH(x)                        (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_HIGH_SHIFT))&CRC_GPOLY_HIGH_MASK) /*!< CRC_GPOLY                               */
/* ------- GPOLYL Bit Fields                        ------ */
#define CRC_GPOLYL_GPOLYL_MASK                   (0xFFFFUL << CRC_GPOLYL_GPOLYL_SHIFT)               /*!< CRC_GPOLYL: GPOLYL Mask                 */
#define CRC_GPOLYL_GPOLYL_SHIFT                  0                                                   /*!< CRC_GPOLYL: GPOLYL Position             */
#define CRC_GPOLYL_GPOLYL(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYL_GPOLYL_SHIFT))&CRC_GPOLYL_GPOLYL_MASK) /*!< CRC_GPOLYL                              */
/* ------- GPOLYLL Bit Fields                       ------ */
#define CRC_GPOLYLL_GPOLYLL_MASK                 (0xFFUL << CRC_GPOLYLL_GPOLYLL_SHIFT)               /*!< CRC_GPOLYLL: GPOLYLL Mask               */
#define CRC_GPOLYLL_GPOLYLL_SHIFT                0                                                   /*!< CRC_GPOLYLL: GPOLYLL Position           */
#define CRC_GPOLYLL_GPOLYLL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLL_GPOLYLL_SHIFT))&CRC_GPOLYLL_GPOLYLL_MASK) /*!< CRC_GPOLYLL                             */
/* ------- GPOLYLU Bit Fields                       ------ */
#define CRC_GPOLYLU_GPOLYLU_MASK                 (0xFFUL << CRC_GPOLYLU_GPOLYLU_SHIFT)               /*!< CRC_GPOLYLU: GPOLYLU Mask               */
#define CRC_GPOLYLU_GPOLYLU_SHIFT                0                                                   /*!< CRC_GPOLYLU: GPOLYLU Position           */
#define CRC_GPOLYLU_GPOLYLU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLU_GPOLYLU_SHIFT))&CRC_GPOLYLU_GPOLYLU_MASK) /*!< CRC_GPOLYLU                             */
/* ------- GPOLYH Bit Fields                        ------ */
#define CRC_GPOLYH_GPOLYH_MASK                   (0xFFFFUL << CRC_GPOLYH_GPOLYH_SHIFT)               /*!< CRC_GPOLYH: GPOLYH Mask                 */
#define CRC_GPOLYH_GPOLYH_SHIFT                  0                                                   /*!< CRC_GPOLYH: GPOLYH Position             */
#define CRC_GPOLYH_GPOLYH(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYH_GPOLYH_SHIFT))&CRC_GPOLYH_GPOLYH_MASK) /*!< CRC_GPOLYH                              */
/* ------- GPOLYHL Bit Fields                       ------ */
#define CRC_GPOLYHL_GPOLYHL_MASK                 (0xFFUL << CRC_GPOLYHL_GPOLYHL_SHIFT)               /*!< CRC_GPOLYHL: GPOLYHL Mask               */
#define CRC_GPOLYHL_GPOLYHL_SHIFT                0                                                   /*!< CRC_GPOLYHL: GPOLYHL Position           */
#define CRC_GPOLYHL_GPOLYHL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHL_GPOLYHL_SHIFT))&CRC_GPOLYHL_GPOLYHL_MASK) /*!< CRC_GPOLYHL                             */
/* ------- GPOLYHU Bit Fields                       ------ */
#define CRC_GPOLYHU_GPOLYHU_MASK                 (0xFFUL << CRC_GPOLYHU_GPOLYHU_SHIFT)               /*!< CRC_GPOLYHU: GPOLYHU Mask               */
#define CRC_GPOLYHU_GPOLYHU_SHIFT                0                                                   /*!< CRC_GPOLYHU: GPOLYHU Position           */
#define CRC_GPOLYHU_GPOLYHU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHU_GPOLYHU_SHIFT))&CRC_GPOLYHU_GPOLYHU_MASK) /*!< CRC_GPOLYHU                             */
/* ------- CTRL Bit Fields                          ------ */
#define CRC_CTRL_TCRC_MASK                       (0x01UL << CRC_CTRL_TCRC_SHIFT)                     /*!< CRC_CTRL: TCRC Mask                     */
#define CRC_CTRL_TCRC_SHIFT                      24                                                  /*!< CRC_CTRL: TCRC Position                 */
#define CRC_CTRL_TCRC(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TCRC_SHIFT))&CRC_CTRL_TCRC_MASK) /*!< CRC_CTRL                                */
#define CRC_CTRL_WAS_MASK                        (0x01UL << CRC_CTRL_WAS_SHIFT)                      /*!< CRC_CTRL: WAS Mask                      */
#define CRC_CTRL_WAS_SHIFT                       25                                                  /*!< CRC_CTRL: WAS Position                  */
#define CRC_CTRL_WAS(x)                          (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_WAS_SHIFT))&CRC_CTRL_WAS_MASK) /*!< CRC_CTRL                                */
#define CRC_CTRL_FXOR_MASK                       (0x01UL << CRC_CTRL_FXOR_SHIFT)                     /*!< CRC_CTRL: FXOR Mask                     */
#define CRC_CTRL_FXOR_SHIFT                      26                                                  /*!< CRC_CTRL: FXOR Position                 */
#define CRC_CTRL_FXOR(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_FXOR_SHIFT))&CRC_CTRL_FXOR_MASK) /*!< CRC_CTRL                                */
#define CRC_CTRL_TOTR_MASK                       (0x03UL << CRC_CTRL_TOTR_SHIFT)                     /*!< CRC_CTRL: TOTR Mask                     */
#define CRC_CTRL_TOTR_SHIFT                      28                                                  /*!< CRC_CTRL: TOTR Position                 */
#define CRC_CTRL_TOTR(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOTR_SHIFT))&CRC_CTRL_TOTR_MASK) /*!< CRC_CTRL                                */
#define CRC_CTRL_TOT_MASK                        (0x03UL << CRC_CTRL_TOT_SHIFT)                      /*!< CRC_CTRL: TOT Mask                      */
#define CRC_CTRL_TOT_SHIFT                       30                                                  /*!< CRC_CTRL: TOT Position                  */
#define CRC_CTRL_TOT(x)                          (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOT_SHIFT))&CRC_CTRL_TOT_MASK) /*!< CRC_CTRL                                */
/* ------- CTRLHU Bit Fields                        ------ */
#define CRC_CTRLHU_TCRC_MASK                     (0x01UL << CRC_CTRLHU_TCRC_SHIFT)                   /*!< CRC_CTRLHU: TCRC Mask                   */
#define CRC_CTRLHU_TCRC_SHIFT                    0                                                   /*!< CRC_CTRLHU: TCRC Position               */
#define CRC_CTRLHU_TCRC(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TCRC_SHIFT))&CRC_CTRLHU_TCRC_MASK) /*!< CRC_CTRLHU                              */
#define CRC_CTRLHU_WAS_MASK                      (0x01UL << CRC_CTRLHU_WAS_SHIFT)                    /*!< CRC_CTRLHU: WAS Mask                    */
#define CRC_CTRLHU_WAS_SHIFT                     1                                                   /*!< CRC_CTRLHU: WAS Position                */
#define CRC_CTRLHU_WAS(x)                        (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_WAS_SHIFT))&CRC_CTRLHU_WAS_MASK) /*!< CRC_CTRLHU                              */
#define CRC_CTRLHU_FXOR_MASK                     (0x01UL << CRC_CTRLHU_FXOR_SHIFT)                   /*!< CRC_CTRLHU: FXOR Mask                   */
#define CRC_CTRLHU_FXOR_SHIFT                    2                                                   /*!< CRC_CTRLHU: FXOR Position               */
#define CRC_CTRLHU_FXOR(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_FXOR_SHIFT))&CRC_CTRLHU_FXOR_MASK) /*!< CRC_CTRLHU                              */
#define CRC_CTRLHU_TOTR_MASK                     (0x03UL << CRC_CTRLHU_TOTR_SHIFT)                   /*!< CRC_CTRLHU: TOTR Mask                   */
#define CRC_CTRLHU_TOTR_SHIFT                    4                                                   /*!< CRC_CTRLHU: TOTR Position               */
#define CRC_CTRLHU_TOTR(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOTR_SHIFT))&CRC_CTRLHU_TOTR_MASK) /*!< CRC_CTRLHU                              */
#define CRC_CTRLHU_TOT_MASK                      (0x03UL << CRC_CTRLHU_TOT_SHIFT)                    /*!< CRC_CTRLHU: TOT Mask                    */
#define CRC_CTRLHU_TOT_SHIFT                     6                                                   /*!< CRC_CTRLHU: TOT Position                */
#define CRC_CTRLHU_TOT(x)                        (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOT_SHIFT))&CRC_CTRLHU_TOT_MASK) /*!< CRC_CTRLHU                              */
/**
 * @} */ /* End group CRC_Register_Masks_GROUP 
 */

/* CRC - Peripheral instance base addresses */
#define CRC_BasePtr                    0x40032000UL //!< Peripheral base address
#define CRC                            ((CRC_Type *) CRC_BasePtr) //!< Freescale base pointer
#define CRC_BASE_PTR                   (CRC) //!< Freescale style base pointer
/**
 * @} */ /* End group CRC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DAC_Peripheral_access_layer_GROUP DAC Peripheral Access Layer
* @brief C Struct for DAC
* @{
*/

/* ================================================================================ */
/* ================           DAC0 (file:DAC0_16CH_0x400CC000)       ================ */
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
   union {                                      /**< 0000: (size=0020)                                                  */
      struct {
         __IO uint8_t   DATL;                   /**< 0000: Data Low Register                                            */
         __IO uint8_t   DATH;                   /**< 0001: Data High Register                                           */
      } DAT[16];                                /**< 0000: (cluster: size=0x0020, 32)                                   */
      __IO uint16_t  DATA[16];                  /**< 0000: Data Register                                                */
   };
   __IO uint8_t   SR;                           /**< 0020: Status Register                                              */
   __IO uint8_t   C0;                           /**< 0021: Control Register 0                                           */
   __IO uint8_t   C1;                           /**< 0022: Control Register 1                                           */
   __IO uint8_t   C2;                           /**< 0023: Control Register 2                                           */
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
#define DAC_DATL_DATA_MASK                       (0xFFUL << DAC_DATL_DATA_SHIFT)                     /*!< DAC0_DATL: DATA Mask                    */
#define DAC_DATL_DATA_SHIFT                      0                                                   /*!< DAC0_DATL: DATA Position                */
#define DAC_DATL_DATA(x)                         (((uint8_t)(((uint8_t)(x))<<DAC_DATL_DATA_SHIFT))&DAC_DATL_DATA_MASK) /*!< DAC0_DATL                               */
/* ------- DATH Bit Fields                          ------ */
#define DAC_DATH_DATA_MASK                       (0x0FUL << DAC_DATH_DATA_SHIFT)                     /*!< DAC0_DATH: DATA Mask                    */
#define DAC_DATH_DATA_SHIFT                      0                                                   /*!< DAC0_DATH: DATA Position                */
#define DAC_DATH_DATA(x)                         (((uint8_t)(((uint8_t)(x))<<DAC_DATH_DATA_SHIFT))&DAC_DATH_DATA_MASK) /*!< DAC0_DATH                               */
/* ------- DATA Bit Fields                          ------ */
#define DAC_DATA_DATA_MASK                       (0xFFFUL << DAC_DATA_DATA_SHIFT)                    /*!< DAC0_DATA: DATA Mask                    */
#define DAC_DATA_DATA_SHIFT                      0                                                   /*!< DAC0_DATA: DATA Position                */
#define DAC_DATA_DATA(x)                         (((uint16_t)(((uint16_t)(x))<<DAC_DATA_DATA_SHIFT))&DAC_DATA_DATA_MASK) /*!< DAC0_DATA                               */
/* ------- SR Bit Fields                            ------ */
#define DAC_SR_DACBFRPBF_MASK                    (0x01UL << DAC_SR_DACBFRPBF_SHIFT)                  /*!< DAC0_SR: DACBFRPBF Mask                 */
#define DAC_SR_DACBFRPBF_SHIFT                   0                                                   /*!< DAC0_SR: DACBFRPBF Position             */
#define DAC_SR_DACBFRPBF(x)                      (((uint8_t)(((uint8_t)(x))<<DAC_SR_DACBFRPBF_SHIFT))&DAC_SR_DACBFRPBF_MASK) /*!< DAC0_SR                                 */
#define DAC_SR_DACBFRPTF_MASK                    (0x01UL << DAC_SR_DACBFRPTF_SHIFT)                  /*!< DAC0_SR: DACBFRPTF Mask                 */
#define DAC_SR_DACBFRPTF_SHIFT                   1                                                   /*!< DAC0_SR: DACBFRPTF Position             */
#define DAC_SR_DACBFRPTF(x)                      (((uint8_t)(((uint8_t)(x))<<DAC_SR_DACBFRPTF_SHIFT))&DAC_SR_DACBFRPTF_MASK) /*!< DAC0_SR                                 */
#define DAC_SR_DACBFWMF_MASK                     (0x01UL << DAC_SR_DACBFWMF_SHIFT)                   /*!< DAC0_SR: DACBFWMF Mask                  */
#define DAC_SR_DACBFWMF_SHIFT                    2                                                   /*!< DAC0_SR: DACBFWMF Position              */
#define DAC_SR_DACBFWMF(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_SR_DACBFWMF_SHIFT))&DAC_SR_DACBFWMF_MASK) /*!< DAC0_SR                                 */
/* ------- C0 Bit Fields                            ------ */
#define DAC_C0_DACBBIEN_MASK                     (0x01UL << DAC_C0_DACBBIEN_SHIFT)                   /*!< DAC0_C0: DACBBIEN Mask                  */
#define DAC_C0_DACBBIEN_SHIFT                    0                                                   /*!< DAC0_C0: DACBBIEN Position              */
#define DAC_C0_DACBBIEN(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACBBIEN_SHIFT))&DAC_C0_DACBBIEN_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_DACBTIEN_MASK                     (0x01UL << DAC_C0_DACBTIEN_SHIFT)                   /*!< DAC0_C0: DACBTIEN Mask                  */
#define DAC_C0_DACBTIEN_SHIFT                    1                                                   /*!< DAC0_C0: DACBTIEN Position              */
#define DAC_C0_DACBTIEN(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACBTIEN_SHIFT))&DAC_C0_DACBTIEN_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_DACBWIEN_MASK                     (0x01UL << DAC_C0_DACBWIEN_SHIFT)                   /*!< DAC0_C0: DACBWIEN Mask                  */
#define DAC_C0_DACBWIEN_SHIFT                    2                                                   /*!< DAC0_C0: DACBWIEN Position              */
#define DAC_C0_DACBWIEN(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACBWIEN_SHIFT))&DAC_C0_DACBWIEN_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_LPEN_MASK                         (0x01UL << DAC_C0_LPEN_SHIFT)                       /*!< DAC0_C0: LPEN Mask                      */
#define DAC_C0_LPEN_SHIFT                        3                                                   /*!< DAC0_C0: LPEN Position                  */
#define DAC_C0_LPEN(x)                           (((uint8_t)(((uint8_t)(x))<<DAC_C0_LPEN_SHIFT))&DAC_C0_LPEN_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_DACSWTRG_MASK                     (0x01UL << DAC_C0_DACSWTRG_SHIFT)                   /*!< DAC0_C0: DACSWTRG Mask                  */
#define DAC_C0_DACSWTRG_SHIFT                    4                                                   /*!< DAC0_C0: DACSWTRG Position              */
#define DAC_C0_DACSWTRG(x)                       (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACSWTRG_SHIFT))&DAC_C0_DACSWTRG_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_DACTRGSEL_MASK                    (0x01UL << DAC_C0_DACTRGSEL_SHIFT)                  /*!< DAC0_C0: DACTRGSEL Mask                 */
#define DAC_C0_DACTRGSEL_SHIFT                   5                                                   /*!< DAC0_C0: DACTRGSEL Position             */
#define DAC_C0_DACTRGSEL(x)                      (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACTRGSEL_SHIFT))&DAC_C0_DACTRGSEL_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_DACRFS_MASK                       (0x01UL << DAC_C0_DACRFS_SHIFT)                     /*!< DAC0_C0: DACRFS Mask                    */
#define DAC_C0_DACRFS_SHIFT                      6                                                   /*!< DAC0_C0: DACRFS Position                */
#define DAC_C0_DACRFS(x)                         (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACRFS_SHIFT))&DAC_C0_DACRFS_MASK) /*!< DAC0_C0                                 */
#define DAC_C0_DACEN_MASK                        (0x01UL << DAC_C0_DACEN_SHIFT)                      /*!< DAC0_C0: DACEN Mask                     */
#define DAC_C0_DACEN_SHIFT                       7                                                   /*!< DAC0_C0: DACEN Position                 */
#define DAC_C0_DACEN(x)                          (((uint8_t)(((uint8_t)(x))<<DAC_C0_DACEN_SHIFT))&DAC_C0_DACEN_MASK) /*!< DAC0_C0                                 */
/* ------- C1 Bit Fields                            ------ */
#define DAC_C1_DACBFEN_MASK                      (0x01UL << DAC_C1_DACBFEN_SHIFT)                    /*!< DAC0_C1: DACBFEN Mask                   */
#define DAC_C1_DACBFEN_SHIFT                     0                                                   /*!< DAC0_C1: DACBFEN Position               */
#define DAC_C1_DACBFEN(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFEN_SHIFT))&DAC_C1_DACBFEN_MASK) /*!< DAC0_C1                                 */
#define DAC_C1_DACBFMD_MASK                      (0x03UL << DAC_C1_DACBFMD_SHIFT)                    /*!< DAC0_C1: DACBFMD Mask                   */
#define DAC_C1_DACBFMD_SHIFT                     1                                                   /*!< DAC0_C1: DACBFMD Position               */
#define DAC_C1_DACBFMD(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFMD_SHIFT))&DAC_C1_DACBFMD_MASK) /*!< DAC0_C1                                 */
#define DAC_C1_DACBFWM_MASK                      (0x03UL << DAC_C1_DACBFWM_SHIFT)                    /*!< DAC0_C1: DACBFWM Mask                   */
#define DAC_C1_DACBFWM_SHIFT                     3                                                   /*!< DAC0_C1: DACBFWM Position               */
#define DAC_C1_DACBFWM(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C1_DACBFWM_SHIFT))&DAC_C1_DACBFWM_MASK) /*!< DAC0_C1                                 */
#define DAC_C1_DMAEN_MASK                        (0x01UL << DAC_C1_DMAEN_SHIFT)                      /*!< DAC0_C1: DMAEN Mask                     */
#define DAC_C1_DMAEN_SHIFT                       7                                                   /*!< DAC0_C1: DMAEN Position                 */
#define DAC_C1_DMAEN(x)                          (((uint8_t)(((uint8_t)(x))<<DAC_C1_DMAEN_SHIFT))&DAC_C1_DMAEN_MASK) /*!< DAC0_C1                                 */
/* ------- C2 Bit Fields                            ------ */
#define DAC_C2_DACBFUP_MASK                      (0x0FUL << DAC_C2_DACBFUP_SHIFT)                    /*!< DAC0_C2: DACBFUP Mask                   */
#define DAC_C2_DACBFUP_SHIFT                     0                                                   /*!< DAC0_C2: DACBFUP Position               */
#define DAC_C2_DACBFUP(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFUP_SHIFT))&DAC_C2_DACBFUP_MASK) /*!< DAC0_C2                                 */
#define DAC_C2_DACBFRP_MASK                      (0x0FUL << DAC_C2_DACBFRP_SHIFT)                    /*!< DAC0_C2: DACBFRP Mask                   */
#define DAC_C2_DACBFRP_SHIFT                     4                                                   /*!< DAC0_C2: DACBFRP Position               */
#define DAC_C2_DACBFRP(x)                        (((uint8_t)(((uint8_t)(x))<<DAC_C2_DACBFRP_SHIFT))&DAC_C2_DACBFRP_MASK) /*!< DAC0_C2                                 */
/**
 * @} */ /* End group DAC_Register_Masks_GROUP 
 */

/* DAC0 - Peripheral instance base addresses */
#define DAC0_BasePtr                   0x400CC000UL //!< Peripheral base address
#define DAC0                           ((DAC_Type *) DAC0_BasePtr) //!< Freescale base pointer
#define DAC0_BASE_PTR                  (DAC0) //!< Freescale style base pointer
/**
 * @} */ /* End group DAC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMA0_Peripheral_access_layer_GROUP DMA0 Peripheral Access Layer
* @brief C Struct for DMA0
* @{
*/

/* ================================================================================ */
/* ================           DMA0 (file:DMA0_16CH)                ================ */
/* ================================================================================ */

/**
 * @brief Enhanced direct memory access controller
 */
/**
* @addtogroup DMA0_structs_GROUP DMA0 struct
* @brief Struct for DMA0
* @{
*/
typedef struct {                                /*       DMA0 Structure                                               */
   __IO uint32_t  CR;                           /**< 0000: Control Register                                             */
   __I  uint32_t  ES;                           /**< 0004: Error Status Register                                        */
   __I  uint32_t  RESERVED0;                   
   __IO uint32_t  ERQ;                          /**< 000C: Enable Request Register                                      */
   __I  uint32_t  RESERVED1;                   
   __IO uint32_t  EEI;                          /**< 0014: Enable Error Interrupt Register                              */
   __O  uint8_t   CEEI;                         /**< 0018: Clear Enable Error Interrupt Register                        */
   __O  uint8_t   SEEI;                         /**< 0019: Set Enable Error Interrupt Register                          */
   __O  uint8_t   CERQ;                         /**< 001A: Clear Enable Request Register                                */
   __O  uint8_t   SERQ;                         /**< 001B: Set Enable Request Register                                  */
   __O  uint8_t   CDNE;                         /**< 001C: Clear DONE Status Bit Register                               */
   __O  uint8_t   SSRT;                         /**< 001D: Set START Bit Register                                       */
   __O  uint8_t   CERR;                         /**< 001E: Clear Error Register                                         */
   __O  uint8_t   CINT;                         /**< 001F: Clear Interrupt Request Register                             */
   __I  uint32_t  RESERVED2;                   
   __IO uint32_t  INT;                          /**< 0024: Interrupt Request Register                                   */
   __I  uint32_t  RESERVED3;                   
   __IO uint32_t  ERR;                          /**< 002C: Error Register                                               */
   __I  uint32_t  RESERVED4;                   
   __I  uint32_t  HRS;                          /**< 0034: Hardware Request Status Register                             */
   __I  uint32_t  RESERVED5[50];               
   __IO uint8_t   DCHPRI3;                      /**< 0100: Channel 3 Priority Register                                  */
   __IO uint8_t   DCHPRI2;                      /**< 0101: Channel 2 Priority Register                                  */
   __IO uint8_t   DCHPRI1;                      /**< 0102: Channel 1 Priority Register                                  */
   __IO uint8_t   DCHPRI0;                      /**< 0103: Channel 0 Priority Register                                  */
   __IO uint8_t   DCHPRI7;                      /**< 0104: Channel 7 Priority Register                                  */
   __IO uint8_t   DCHPRI6;                      /**< 0105: Channel 6 Priority Register                                  */
   __IO uint8_t   DCHPRI5;                      /**< 0106: Channel 5 Priority Register                                  */
   __IO uint8_t   DCHPRI4;                      /**< 0107: Channel 4 Priority Register                                  */
   __IO uint8_t   DCHPRI11;                     /**< 0108: Channel 11 Priority Register                                 */
   __IO uint8_t   DCHPRI10;                     /**< 0109: Channel 10 Priority Register                                 */
   __IO uint8_t   DCHPRI9;                      /**< 010A: Channel 9 Priority Register                                  */
   __IO uint8_t   DCHPRI8;                      /**< 010B: Channel 8 Priority Register                                  */
   __IO uint8_t   DCHPRI15;                     /**< 010C: Channel 15 Priority Register                                 */
   __IO uint8_t   DCHPRI14;                     /**< 010D: Channel 14 Priority Register                                 */
   __IO uint8_t   DCHPRI13;                     /**< 010E: Channel 13 Priority Register                                 */
   __IO uint8_t   DCHPRI12;                     /**< 010F: Channel 12 Priority Register                                 */
   __I  uint32_t  RESERVED6[956];              
   struct {
      __IO uint32_t  SADDR;                     /**< 1000: Source Address                                               */
      __IO uint16_t  SOFF;                      /**< 1004: Signed Source Address Offset                                 */
      __IO uint16_t  ATTR;                      /**< 1006: Transfer Attributes                                          */
      union {                                   /**< 1000: (size=0004)                                                  */
         __IO uint32_t  NBYTES_MLNO;            /**< 1008: Minor Byte Count (Minor Loop Disabled)                       */
         __IO uint32_t  NBYTES_MLOFFNO;         /**< 1008: Signed Minor Loop Offset (Minor Loop Enabled and Offset Disabled) */
         __IO uint32_t  NBYTES_MLOFFYES;        /**< 1008: Signed Minor Loop Offset (Minor Loop and Offset Enabled)     */
      };
      __IO uint32_t  SLAST;                     /**< 100C: Last Source Address Adjustment                               */
      __IO uint32_t  DADDR;                     /**< 1010: Destination Address                                          */
      __IO uint16_t  DOFF;                      /**< 1014: Signed Destination Address Offset                            */
      union {                                   /**< 1000: (size=0002)                                                  */
         __IO uint16_t  CITER_ELINKNO;          /**< 1016: Current Minor Loop Link, Major Loop Count (Channel Linking Disabled) */
         __IO uint16_t  CITER_ELINKYES;         /**< 1016: Current Minor Loop Link, Major Loop Count (Channel Linking Enabled) */
      };
      __IO uint32_t  DLASTSGA;                  /**< 1018: Last Destination Address Adjustment/Scatter Gather Address   */
      __IO uint16_t  CSR;                       /**< 101C: Control and Status                                           */
      union {                                   /**< 1000: (size=0002)                                                  */
         __IO uint16_t  BITER_ELINKNO;          /**< 101E: Beginning Minor Loop Link, Major Loop Count (Channel Linking Disabled) */
         __IO uint16_t  BITER_ELINKYES;         /**< 101E: Beginning Minor Loop Link, Major Loop Count (Channel Linking Enabled) */
      };
   } TCD[16];                                   /**< 1000: (cluster: size=0x0200, 512)                                  */
} DMA_Type;

/**
 * @} */ /* End group DMA0_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DMA0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DMA0_Register_Masks_GROUP DMA0 Register Masks
* @brief Register Masks for DMA0
* @{
*/
/* ------- CR Bit Fields                            ------ */
#define DMA_CR_EDBG_MASK                         (0x01UL << DMA_CR_EDBG_SHIFT)                       /*!< DMA0_CR: EDBG Mask                      */
#define DMA_CR_EDBG_SHIFT                        1                                                   /*!< DMA0_CR: EDBG Position                  */
#define DMA_CR_EDBG(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CR_EDBG_SHIFT))&DMA_CR_EDBG_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_ERCA_MASK                         (0x01UL << DMA_CR_ERCA_SHIFT)                       /*!< DMA0_CR: ERCA Mask                      */
#define DMA_CR_ERCA_SHIFT                        2                                                   /*!< DMA0_CR: ERCA Position                  */
#define DMA_CR_ERCA(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CR_ERCA_SHIFT))&DMA_CR_ERCA_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_HOE_MASK                          (0x01UL << DMA_CR_HOE_SHIFT)                        /*!< DMA0_CR: HOE Mask                       */
#define DMA_CR_HOE_SHIFT                         4                                                   /*!< DMA0_CR: HOE Position                   */
#define DMA_CR_HOE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_CR_HOE_SHIFT))&DMA_CR_HOE_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_HALT_MASK                         (0x01UL << DMA_CR_HALT_SHIFT)                       /*!< DMA0_CR: HALT Mask                      */
#define DMA_CR_HALT_SHIFT                        5                                                   /*!< DMA0_CR: HALT Position                  */
#define DMA_CR_HALT(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CR_HALT_SHIFT))&DMA_CR_HALT_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_CLM_MASK                          (0x01UL << DMA_CR_CLM_SHIFT)                        /*!< DMA0_CR: CLM Mask                       */
#define DMA_CR_CLM_SHIFT                         6                                                   /*!< DMA0_CR: CLM Position                   */
#define DMA_CR_CLM(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_CR_CLM_SHIFT))&DMA_CR_CLM_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_EMLM_MASK                         (0x01UL << DMA_CR_EMLM_SHIFT)                       /*!< DMA0_CR: EMLM Mask                      */
#define DMA_CR_EMLM_SHIFT                        7                                                   /*!< DMA0_CR: EMLM Position                  */
#define DMA_CR_EMLM(x)                           (((uint32_t)(((uint32_t)(x))<<DMA_CR_EMLM_SHIFT))&DMA_CR_EMLM_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_ECX_MASK                          (0x01UL << DMA_CR_ECX_SHIFT)                        /*!< DMA0_CR: ECX Mask                       */
#define DMA_CR_ECX_SHIFT                         16                                                  /*!< DMA0_CR: ECX Position                   */
#define DMA_CR_ECX(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_CR_ECX_SHIFT))&DMA_CR_ECX_MASK) /*!< DMA0_CR                                 */
#define DMA_CR_CX_MASK                           (0x01UL << DMA_CR_CX_SHIFT)                         /*!< DMA0_CR: CX Mask                        */
#define DMA_CR_CX_SHIFT                          17                                                  /*!< DMA0_CR: CX Position                    */
#define DMA_CR_CX(x)                             (((uint32_t)(((uint32_t)(x))<<DMA_CR_CX_SHIFT))&DMA_CR_CX_MASK) /*!< DMA0_CR                                 */
/* ------- ES Bit Fields                            ------ */
#define DMA_ES_DBE_MASK                          (0x01UL << DMA_ES_DBE_SHIFT)                        /*!< DMA0_ES: DBE Mask                       */
#define DMA_ES_DBE_SHIFT                         0                                                   /*!< DMA0_ES: DBE Position                   */
#define DMA_ES_DBE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_DBE_SHIFT))&DMA_ES_DBE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_SBE_MASK                          (0x01UL << DMA_ES_SBE_SHIFT)                        /*!< DMA0_ES: SBE Mask                       */
#define DMA_ES_SBE_SHIFT                         1                                                   /*!< DMA0_ES: SBE Position                   */
#define DMA_ES_SBE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_SBE_SHIFT))&DMA_ES_SBE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_SGE_MASK                          (0x01UL << DMA_ES_SGE_SHIFT)                        /*!< DMA0_ES: SGE Mask                       */
#define DMA_ES_SGE_SHIFT                         2                                                   /*!< DMA0_ES: SGE Position                   */
#define DMA_ES_SGE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_SGE_SHIFT))&DMA_ES_SGE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_NCE_MASK                          (0x01UL << DMA_ES_NCE_SHIFT)                        /*!< DMA0_ES: NCE Mask                       */
#define DMA_ES_NCE_SHIFT                         3                                                   /*!< DMA0_ES: NCE Position                   */
#define DMA_ES_NCE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_NCE_SHIFT))&DMA_ES_NCE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_DOE_MASK                          (0x01UL << DMA_ES_DOE_SHIFT)                        /*!< DMA0_ES: DOE Mask                       */
#define DMA_ES_DOE_SHIFT                         4                                                   /*!< DMA0_ES: DOE Position                   */
#define DMA_ES_DOE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_DOE_SHIFT))&DMA_ES_DOE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_DAE_MASK                          (0x01UL << DMA_ES_DAE_SHIFT)                        /*!< DMA0_ES: DAE Mask                       */
#define DMA_ES_DAE_SHIFT                         5                                                   /*!< DMA0_ES: DAE Position                   */
#define DMA_ES_DAE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_DAE_SHIFT))&DMA_ES_DAE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_SOE_MASK                          (0x01UL << DMA_ES_SOE_SHIFT)                        /*!< DMA0_ES: SOE Mask                       */
#define DMA_ES_SOE_SHIFT                         6                                                   /*!< DMA0_ES: SOE Position                   */
#define DMA_ES_SOE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_SOE_SHIFT))&DMA_ES_SOE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_SAE_MASK                          (0x01UL << DMA_ES_SAE_SHIFT)                        /*!< DMA0_ES: SAE Mask                       */
#define DMA_ES_SAE_SHIFT                         7                                                   /*!< DMA0_ES: SAE Position                   */
#define DMA_ES_SAE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_SAE_SHIFT))&DMA_ES_SAE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_ERRCHN_MASK                       (0x0FUL << DMA_ES_ERRCHN_SHIFT)                     /*!< DMA0_ES: ERRCHN Mask                    */
#define DMA_ES_ERRCHN_SHIFT                      8                                                   /*!< DMA0_ES: ERRCHN Position                */
#define DMA_ES_ERRCHN(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ES_ERRCHN_SHIFT))&DMA_ES_ERRCHN_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_CPE_MASK                          (0x01UL << DMA_ES_CPE_SHIFT)                        /*!< DMA0_ES: CPE Mask                       */
#define DMA_ES_CPE_SHIFT                         14                                                  /*!< DMA0_ES: CPE Position                   */
#define DMA_ES_CPE(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_CPE_SHIFT))&DMA_ES_CPE_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_ECX_MASK                          (0x01UL << DMA_ES_ECX_SHIFT)                        /*!< DMA0_ES: ECX Mask                       */
#define DMA_ES_ECX_SHIFT                         16                                                  /*!< DMA0_ES: ECX Position                   */
#define DMA_ES_ECX(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_ECX_SHIFT))&DMA_ES_ECX_MASK) /*!< DMA0_ES                                 */
#define DMA_ES_VLD_MASK                          (0x01UL << DMA_ES_VLD_SHIFT)                        /*!< DMA0_ES: VLD Mask                       */
#define DMA_ES_VLD_SHIFT                         31                                                  /*!< DMA0_ES: VLD Position                   */
#define DMA_ES_VLD(x)                            (((uint32_t)(((uint32_t)(x))<<DMA_ES_VLD_SHIFT))&DMA_ES_VLD_MASK) /*!< DMA0_ES                                 */
/* ------- ERQ Bit Fields                           ------ */
#define DMA_ERQ_ERQ0_MASK                        (0x01UL << DMA_ERQ_ERQ0_SHIFT)                      /*!< DMA0_ERQ: ERQ0 Mask                     */
#define DMA_ERQ_ERQ0_SHIFT                       0                                                   /*!< DMA0_ERQ: ERQ0 Position                 */
#define DMA_ERQ_ERQ0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ0_SHIFT))&DMA_ERQ_ERQ0_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ1_MASK                        (0x01UL << DMA_ERQ_ERQ1_SHIFT)                      /*!< DMA0_ERQ: ERQ1 Mask                     */
#define DMA_ERQ_ERQ1_SHIFT                       1                                                   /*!< DMA0_ERQ: ERQ1 Position                 */
#define DMA_ERQ_ERQ1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ1_SHIFT))&DMA_ERQ_ERQ1_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ2_MASK                        (0x01UL << DMA_ERQ_ERQ2_SHIFT)                      /*!< DMA0_ERQ: ERQ2 Mask                     */
#define DMA_ERQ_ERQ2_SHIFT                       2                                                   /*!< DMA0_ERQ: ERQ2 Position                 */
#define DMA_ERQ_ERQ2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ2_SHIFT))&DMA_ERQ_ERQ2_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ3_MASK                        (0x01UL << DMA_ERQ_ERQ3_SHIFT)                      /*!< DMA0_ERQ: ERQ3 Mask                     */
#define DMA_ERQ_ERQ3_SHIFT                       3                                                   /*!< DMA0_ERQ: ERQ3 Position                 */
#define DMA_ERQ_ERQ3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ3_SHIFT))&DMA_ERQ_ERQ3_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ4_MASK                        (0x01UL << DMA_ERQ_ERQ4_SHIFT)                      /*!< DMA0_ERQ: ERQ4 Mask                     */
#define DMA_ERQ_ERQ4_SHIFT                       4                                                   /*!< DMA0_ERQ: ERQ4 Position                 */
#define DMA_ERQ_ERQ4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ4_SHIFT))&DMA_ERQ_ERQ4_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ5_MASK                        (0x01UL << DMA_ERQ_ERQ5_SHIFT)                      /*!< DMA0_ERQ: ERQ5 Mask                     */
#define DMA_ERQ_ERQ5_SHIFT                       5                                                   /*!< DMA0_ERQ: ERQ5 Position                 */
#define DMA_ERQ_ERQ5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ5_SHIFT))&DMA_ERQ_ERQ5_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ6_MASK                        (0x01UL << DMA_ERQ_ERQ6_SHIFT)                      /*!< DMA0_ERQ: ERQ6 Mask                     */
#define DMA_ERQ_ERQ6_SHIFT                       6                                                   /*!< DMA0_ERQ: ERQ6 Position                 */
#define DMA_ERQ_ERQ6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ6_SHIFT))&DMA_ERQ_ERQ6_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ7_MASK                        (0x01UL << DMA_ERQ_ERQ7_SHIFT)                      /*!< DMA0_ERQ: ERQ7 Mask                     */
#define DMA_ERQ_ERQ7_SHIFT                       7                                                   /*!< DMA0_ERQ: ERQ7 Position                 */
#define DMA_ERQ_ERQ7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ7_SHIFT))&DMA_ERQ_ERQ7_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ8_MASK                        (0x01UL << DMA_ERQ_ERQ8_SHIFT)                      /*!< DMA0_ERQ: ERQ8 Mask                     */
#define DMA_ERQ_ERQ8_SHIFT                       8                                                   /*!< DMA0_ERQ: ERQ8 Position                 */
#define DMA_ERQ_ERQ8(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ8_SHIFT))&DMA_ERQ_ERQ8_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ9_MASK                        (0x01UL << DMA_ERQ_ERQ9_SHIFT)                      /*!< DMA0_ERQ: ERQ9 Mask                     */
#define DMA_ERQ_ERQ9_SHIFT                       9                                                   /*!< DMA0_ERQ: ERQ9 Position                 */
#define DMA_ERQ_ERQ9(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ9_SHIFT))&DMA_ERQ_ERQ9_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ10_MASK                       (0x01UL << DMA_ERQ_ERQ10_SHIFT)                     /*!< DMA0_ERQ: ERQ10 Mask                    */
#define DMA_ERQ_ERQ10_SHIFT                      10                                                  /*!< DMA0_ERQ: ERQ10 Position                */
#define DMA_ERQ_ERQ10(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ10_SHIFT))&DMA_ERQ_ERQ10_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ11_MASK                       (0x01UL << DMA_ERQ_ERQ11_SHIFT)                     /*!< DMA0_ERQ: ERQ11 Mask                    */
#define DMA_ERQ_ERQ11_SHIFT                      11                                                  /*!< DMA0_ERQ: ERQ11 Position                */
#define DMA_ERQ_ERQ11(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ11_SHIFT))&DMA_ERQ_ERQ11_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ12_MASK                       (0x01UL << DMA_ERQ_ERQ12_SHIFT)                     /*!< DMA0_ERQ: ERQ12 Mask                    */
#define DMA_ERQ_ERQ12_SHIFT                      12                                                  /*!< DMA0_ERQ: ERQ12 Position                */
#define DMA_ERQ_ERQ12(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ12_SHIFT))&DMA_ERQ_ERQ12_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ13_MASK                       (0x01UL << DMA_ERQ_ERQ13_SHIFT)                     /*!< DMA0_ERQ: ERQ13 Mask                    */
#define DMA_ERQ_ERQ13_SHIFT                      13                                                  /*!< DMA0_ERQ: ERQ13 Position                */
#define DMA_ERQ_ERQ13(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ13_SHIFT))&DMA_ERQ_ERQ13_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ14_MASK                       (0x01UL << DMA_ERQ_ERQ14_SHIFT)                     /*!< DMA0_ERQ: ERQ14 Mask                    */
#define DMA_ERQ_ERQ14_SHIFT                      14                                                  /*!< DMA0_ERQ: ERQ14 Position                */
#define DMA_ERQ_ERQ14(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ14_SHIFT))&DMA_ERQ_ERQ14_MASK) /*!< DMA0_ERQ                                */
#define DMA_ERQ_ERQ15_MASK                       (0x01UL << DMA_ERQ_ERQ15_SHIFT)                     /*!< DMA0_ERQ: ERQ15 Mask                    */
#define DMA_ERQ_ERQ15_SHIFT                      15                                                  /*!< DMA0_ERQ: ERQ15 Position                */
#define DMA_ERQ_ERQ15(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ15_SHIFT))&DMA_ERQ_ERQ15_MASK) /*!< DMA0_ERQ                                */
/* ------- EEI Bit Fields                           ------ */
#define DMA_EEI_EEI0_MASK                        (0x01UL << DMA_EEI_EEI0_SHIFT)                      /*!< DMA0_EEI: EEI0 Mask                     */
#define DMA_EEI_EEI0_SHIFT                       0                                                   /*!< DMA0_EEI: EEI0 Position                 */
#define DMA_EEI_EEI0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI0_SHIFT))&DMA_EEI_EEI0_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI1_MASK                        (0x01UL << DMA_EEI_EEI1_SHIFT)                      /*!< DMA0_EEI: EEI1 Mask                     */
#define DMA_EEI_EEI1_SHIFT                       1                                                   /*!< DMA0_EEI: EEI1 Position                 */
#define DMA_EEI_EEI1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI1_SHIFT))&DMA_EEI_EEI1_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI2_MASK                        (0x01UL << DMA_EEI_EEI2_SHIFT)                      /*!< DMA0_EEI: EEI2 Mask                     */
#define DMA_EEI_EEI2_SHIFT                       2                                                   /*!< DMA0_EEI: EEI2 Position                 */
#define DMA_EEI_EEI2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI2_SHIFT))&DMA_EEI_EEI2_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI3_MASK                        (0x01UL << DMA_EEI_EEI3_SHIFT)                      /*!< DMA0_EEI: EEI3 Mask                     */
#define DMA_EEI_EEI3_SHIFT                       3                                                   /*!< DMA0_EEI: EEI3 Position                 */
#define DMA_EEI_EEI3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI3_SHIFT))&DMA_EEI_EEI3_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI4_MASK                        (0x01UL << DMA_EEI_EEI4_SHIFT)                      /*!< DMA0_EEI: EEI4 Mask                     */
#define DMA_EEI_EEI4_SHIFT                       4                                                   /*!< DMA0_EEI: EEI4 Position                 */
#define DMA_EEI_EEI4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI4_SHIFT))&DMA_EEI_EEI4_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI5_MASK                        (0x01UL << DMA_EEI_EEI5_SHIFT)                      /*!< DMA0_EEI: EEI5 Mask                     */
#define DMA_EEI_EEI5_SHIFT                       5                                                   /*!< DMA0_EEI: EEI5 Position                 */
#define DMA_EEI_EEI5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI5_SHIFT))&DMA_EEI_EEI5_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI6_MASK                        (0x01UL << DMA_EEI_EEI6_SHIFT)                      /*!< DMA0_EEI: EEI6 Mask                     */
#define DMA_EEI_EEI6_SHIFT                       6                                                   /*!< DMA0_EEI: EEI6 Position                 */
#define DMA_EEI_EEI6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI6_SHIFT))&DMA_EEI_EEI6_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI7_MASK                        (0x01UL << DMA_EEI_EEI7_SHIFT)                      /*!< DMA0_EEI: EEI7 Mask                     */
#define DMA_EEI_EEI7_SHIFT                       7                                                   /*!< DMA0_EEI: EEI7 Position                 */
#define DMA_EEI_EEI7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI7_SHIFT))&DMA_EEI_EEI7_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI8_MASK                        (0x01UL << DMA_EEI_EEI8_SHIFT)                      /*!< DMA0_EEI: EEI8 Mask                     */
#define DMA_EEI_EEI8_SHIFT                       8                                                   /*!< DMA0_EEI: EEI8 Position                 */
#define DMA_EEI_EEI8(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI8_SHIFT))&DMA_EEI_EEI8_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI9_MASK                        (0x01UL << DMA_EEI_EEI9_SHIFT)                      /*!< DMA0_EEI: EEI9 Mask                     */
#define DMA_EEI_EEI9_SHIFT                       9                                                   /*!< DMA0_EEI: EEI9 Position                 */
#define DMA_EEI_EEI9(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI9_SHIFT))&DMA_EEI_EEI9_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI10_MASK                       (0x01UL << DMA_EEI_EEI10_SHIFT)                     /*!< DMA0_EEI: EEI10 Mask                    */
#define DMA_EEI_EEI10_SHIFT                      10                                                  /*!< DMA0_EEI: EEI10 Position                */
#define DMA_EEI_EEI10(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI10_SHIFT))&DMA_EEI_EEI10_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI11_MASK                       (0x01UL << DMA_EEI_EEI11_SHIFT)                     /*!< DMA0_EEI: EEI11 Mask                    */
#define DMA_EEI_EEI11_SHIFT                      11                                                  /*!< DMA0_EEI: EEI11 Position                */
#define DMA_EEI_EEI11(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI11_SHIFT))&DMA_EEI_EEI11_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI12_MASK                       (0x01UL << DMA_EEI_EEI12_SHIFT)                     /*!< DMA0_EEI: EEI12 Mask                    */
#define DMA_EEI_EEI12_SHIFT                      12                                                  /*!< DMA0_EEI: EEI12 Position                */
#define DMA_EEI_EEI12(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI12_SHIFT))&DMA_EEI_EEI12_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI13_MASK                       (0x01UL << DMA_EEI_EEI13_SHIFT)                     /*!< DMA0_EEI: EEI13 Mask                    */
#define DMA_EEI_EEI13_SHIFT                      13                                                  /*!< DMA0_EEI: EEI13 Position                */
#define DMA_EEI_EEI13(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI13_SHIFT))&DMA_EEI_EEI13_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI14_MASK                       (0x01UL << DMA_EEI_EEI14_SHIFT)                     /*!< DMA0_EEI: EEI14 Mask                    */
#define DMA_EEI_EEI14_SHIFT                      14                                                  /*!< DMA0_EEI: EEI14 Position                */
#define DMA_EEI_EEI14(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI14_SHIFT))&DMA_EEI_EEI14_MASK) /*!< DMA0_EEI                                */
#define DMA_EEI_EEI15_MASK                       (0x01UL << DMA_EEI_EEI15_SHIFT)                     /*!< DMA0_EEI: EEI15 Mask                    */
#define DMA_EEI_EEI15_SHIFT                      15                                                  /*!< DMA0_EEI: EEI15 Position                */
#define DMA_EEI_EEI15(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI15_SHIFT))&DMA_EEI_EEI15_MASK) /*!< DMA0_EEI                                */
/* ------- CEEI Bit Fields                          ------ */
#define DMA_CEEI_CEEI_MASK                       (0x0FUL << DMA_CEEI_CEEI_SHIFT)                     /*!< DMA0_CEEI: CEEI Mask                    */
#define DMA_CEEI_CEEI_SHIFT                      0                                                   /*!< DMA0_CEEI: CEEI Position                */
#define DMA_CEEI_CEEI(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CEEI_CEEI_SHIFT))&DMA_CEEI_CEEI_MASK) /*!< DMA0_CEEI                               */
#define DMA_CEEI_CAEE_MASK                       (0x01UL << DMA_CEEI_CAEE_SHIFT)                     /*!< DMA0_CEEI: CAEE Mask                    */
#define DMA_CEEI_CAEE_SHIFT                      6                                                   /*!< DMA0_CEEI: CAEE Position                */
#define DMA_CEEI_CAEE(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CEEI_CAEE_SHIFT))&DMA_CEEI_CAEE_MASK) /*!< DMA0_CEEI                               */
#define DMA_CEEI_NOP_MASK                        (0x01UL << DMA_CEEI_NOP_SHIFT)                      /*!< DMA0_CEEI: NOP Mask                     */
#define DMA_CEEI_NOP_SHIFT                       7                                                   /*!< DMA0_CEEI: NOP Position                 */
#define DMA_CEEI_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CEEI_NOP_SHIFT))&DMA_CEEI_NOP_MASK) /*!< DMA0_CEEI                               */
/* ------- SEEI Bit Fields                          ------ */
#define DMA_SEEI_SEEI_MASK                       (0x0FUL << DMA_SEEI_SEEI_SHIFT)                     /*!< DMA0_SEEI: SEEI Mask                    */
#define DMA_SEEI_SEEI_SHIFT                      0                                                   /*!< DMA0_SEEI: SEEI Position                */
#define DMA_SEEI_SEEI(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SEEI_SEEI_SHIFT))&DMA_SEEI_SEEI_MASK) /*!< DMA0_SEEI                               */
#define DMA_SEEI_SAEE_MASK                       (0x01UL << DMA_SEEI_SAEE_SHIFT)                     /*!< DMA0_SEEI: SAEE Mask                    */
#define DMA_SEEI_SAEE_SHIFT                      6                                                   /*!< DMA0_SEEI: SAEE Position                */
#define DMA_SEEI_SAEE(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SEEI_SAEE_SHIFT))&DMA_SEEI_SAEE_MASK) /*!< DMA0_SEEI                               */
#define DMA_SEEI_NOP_MASK                        (0x01UL << DMA_SEEI_NOP_SHIFT)                      /*!< DMA0_SEEI: NOP Mask                     */
#define DMA_SEEI_NOP_SHIFT                       7                                                   /*!< DMA0_SEEI: NOP Position                 */
#define DMA_SEEI_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_SEEI_NOP_SHIFT))&DMA_SEEI_NOP_MASK) /*!< DMA0_SEEI                               */
/* ------- CERQ Bit Fields                          ------ */
#define DMA_CERQ_CERQ_MASK                       (0x0FUL << DMA_CERQ_CERQ_SHIFT)                     /*!< DMA0_CERQ: CERQ Mask                    */
#define DMA_CERQ_CERQ_SHIFT                      0                                                   /*!< DMA0_CERQ: CERQ Position                */
#define DMA_CERQ_CERQ(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERQ_CERQ_SHIFT))&DMA_CERQ_CERQ_MASK) /*!< DMA0_CERQ                               */
#define DMA_CERQ_CAER_MASK                       (0x01UL << DMA_CERQ_CAER_SHIFT)                     /*!< DMA0_CERQ: CAER Mask                    */
#define DMA_CERQ_CAER_SHIFT                      6                                                   /*!< DMA0_CERQ: CAER Position                */
#define DMA_CERQ_CAER(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERQ_CAER_SHIFT))&DMA_CERQ_CAER_MASK) /*!< DMA0_CERQ                               */
#define DMA_CERQ_NOP_MASK                        (0x01UL << DMA_CERQ_NOP_SHIFT)                      /*!< DMA0_CERQ: NOP Mask                     */
#define DMA_CERQ_NOP_SHIFT                       7                                                   /*!< DMA0_CERQ: NOP Position                 */
#define DMA_CERQ_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CERQ_NOP_SHIFT))&DMA_CERQ_NOP_MASK) /*!< DMA0_CERQ                               */
/* ------- SERQ Bit Fields                          ------ */
#define DMA_SERQ_SERQ_MASK                       (0x0FUL << DMA_SERQ_SERQ_SHIFT)                     /*!< DMA0_SERQ: SERQ Mask                    */
#define DMA_SERQ_SERQ_SHIFT                      0                                                   /*!< DMA0_SERQ: SERQ Position                */
#define DMA_SERQ_SERQ(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SERQ_SERQ_SHIFT))&DMA_SERQ_SERQ_MASK) /*!< DMA0_SERQ                               */
#define DMA_SERQ_SAER_MASK                       (0x01UL << DMA_SERQ_SAER_SHIFT)                     /*!< DMA0_SERQ: SAER Mask                    */
#define DMA_SERQ_SAER_SHIFT                      6                                                   /*!< DMA0_SERQ: SAER Position                */
#define DMA_SERQ_SAER(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SERQ_SAER_SHIFT))&DMA_SERQ_SAER_MASK) /*!< DMA0_SERQ                               */
#define DMA_SERQ_NOP_MASK                        (0x01UL << DMA_SERQ_NOP_SHIFT)                      /*!< DMA0_SERQ: NOP Mask                     */
#define DMA_SERQ_NOP_SHIFT                       7                                                   /*!< DMA0_SERQ: NOP Position                 */
#define DMA_SERQ_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_SERQ_NOP_SHIFT))&DMA_SERQ_NOP_MASK) /*!< DMA0_SERQ                               */
/* ------- CDNE Bit Fields                          ------ */
#define DMA_CDNE_CDNE_MASK                       (0x0FUL << DMA_CDNE_CDNE_SHIFT)                     /*!< DMA0_CDNE: CDNE Mask                    */
#define DMA_CDNE_CDNE_SHIFT                      0                                                   /*!< DMA0_CDNE: CDNE Position                */
#define DMA_CDNE_CDNE(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CDNE_CDNE_SHIFT))&DMA_CDNE_CDNE_MASK) /*!< DMA0_CDNE                               */
#define DMA_CDNE_CADN_MASK                       (0x01UL << DMA_CDNE_CADN_SHIFT)                     /*!< DMA0_CDNE: CADN Mask                    */
#define DMA_CDNE_CADN_SHIFT                      6                                                   /*!< DMA0_CDNE: CADN Position                */
#define DMA_CDNE_CADN(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CDNE_CADN_SHIFT))&DMA_CDNE_CADN_MASK) /*!< DMA0_CDNE                               */
#define DMA_CDNE_NOP_MASK                        (0x01UL << DMA_CDNE_NOP_SHIFT)                      /*!< DMA0_CDNE: NOP Mask                     */
#define DMA_CDNE_NOP_SHIFT                       7                                                   /*!< DMA0_CDNE: NOP Position                 */
#define DMA_CDNE_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CDNE_NOP_SHIFT))&DMA_CDNE_NOP_MASK) /*!< DMA0_CDNE                               */
/* ------- SSRT Bit Fields                          ------ */
#define DMA_SSRT_SSRT_MASK                       (0x0FUL << DMA_SSRT_SSRT_SHIFT)                     /*!< DMA0_SSRT: SSRT Mask                    */
#define DMA_SSRT_SSRT_SHIFT                      0                                                   /*!< DMA0_SSRT: SSRT Position                */
#define DMA_SSRT_SSRT(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SSRT_SSRT_SHIFT))&DMA_SSRT_SSRT_MASK) /*!< DMA0_SSRT                               */
#define DMA_SSRT_SAST_MASK                       (0x01UL << DMA_SSRT_SAST_SHIFT)                     /*!< DMA0_SSRT: SAST Mask                    */
#define DMA_SSRT_SAST_SHIFT                      6                                                   /*!< DMA0_SSRT: SAST Position                */
#define DMA_SSRT_SAST(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_SSRT_SAST_SHIFT))&DMA_SSRT_SAST_MASK) /*!< DMA0_SSRT                               */
#define DMA_SSRT_NOP_MASK                        (0x01UL << DMA_SSRT_NOP_SHIFT)                      /*!< DMA0_SSRT: NOP Mask                     */
#define DMA_SSRT_NOP_SHIFT                       7                                                   /*!< DMA0_SSRT: NOP Position                 */
#define DMA_SSRT_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_SSRT_NOP_SHIFT))&DMA_SSRT_NOP_MASK) /*!< DMA0_SSRT                               */
/* ------- CERR Bit Fields                          ------ */
#define DMA_CERR_CERR_MASK                       (0x0FUL << DMA_CERR_CERR_SHIFT)                     /*!< DMA0_CERR: CERR Mask                    */
#define DMA_CERR_CERR_SHIFT                      0                                                   /*!< DMA0_CERR: CERR Position                */
#define DMA_CERR_CERR(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERR_CERR_SHIFT))&DMA_CERR_CERR_MASK) /*!< DMA0_CERR                               */
#define DMA_CERR_CAEI_MASK                       (0x01UL << DMA_CERR_CAEI_SHIFT)                     /*!< DMA0_CERR: CAEI Mask                    */
#define DMA_CERR_CAEI_SHIFT                      6                                                   /*!< DMA0_CERR: CAEI Position                */
#define DMA_CERR_CAEI(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CERR_CAEI_SHIFT))&DMA_CERR_CAEI_MASK) /*!< DMA0_CERR                               */
#define DMA_CERR_NOP_MASK                        (0x01UL << DMA_CERR_NOP_SHIFT)                      /*!< DMA0_CERR: NOP Mask                     */
#define DMA_CERR_NOP_SHIFT                       7                                                   /*!< DMA0_CERR: NOP Position                 */
#define DMA_CERR_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CERR_NOP_SHIFT))&DMA_CERR_NOP_MASK) /*!< DMA0_CERR                               */
/* ------- CINT Bit Fields                          ------ */
#define DMA_CINT_CINT_MASK                       (0x0FUL << DMA_CINT_CINT_SHIFT)                     /*!< DMA0_CINT: CINT Mask                    */
#define DMA_CINT_CINT_SHIFT                      0                                                   /*!< DMA0_CINT: CINT Position                */
#define DMA_CINT_CINT(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CINT_CINT_SHIFT))&DMA_CINT_CINT_MASK) /*!< DMA0_CINT                               */
#define DMA_CINT_CAIR_MASK                       (0x01UL << DMA_CINT_CAIR_SHIFT)                     /*!< DMA0_CINT: CAIR Mask                    */
#define DMA_CINT_CAIR_SHIFT                      6                                                   /*!< DMA0_CINT: CAIR Position                */
#define DMA_CINT_CAIR(x)                         (((uint8_t)(((uint8_t)(x))<<DMA_CINT_CAIR_SHIFT))&DMA_CINT_CAIR_MASK) /*!< DMA0_CINT                               */
#define DMA_CINT_NOP_MASK                        (0x01UL << DMA_CINT_NOP_SHIFT)                      /*!< DMA0_CINT: NOP Mask                     */
#define DMA_CINT_NOP_SHIFT                       7                                                   /*!< DMA0_CINT: NOP Position                 */
#define DMA_CINT_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<DMA_CINT_NOP_SHIFT))&DMA_CINT_NOP_MASK) /*!< DMA0_CINT                               */
/* ------- INT Bit Fields                           ------ */
#define DMA_INT_INT0_MASK                        (0x01UL << DMA_INT_INT0_SHIFT)                      /*!< DMA0_INT: INT0 Mask                     */
#define DMA_INT_INT0_SHIFT                       0                                                   /*!< DMA0_INT: INT0 Position                 */
#define DMA_INT_INT0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT0_SHIFT))&DMA_INT_INT0_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT1_MASK                        (0x01UL << DMA_INT_INT1_SHIFT)                      /*!< DMA0_INT: INT1 Mask                     */
#define DMA_INT_INT1_SHIFT                       1                                                   /*!< DMA0_INT: INT1 Position                 */
#define DMA_INT_INT1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT1_SHIFT))&DMA_INT_INT1_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT2_MASK                        (0x01UL << DMA_INT_INT2_SHIFT)                      /*!< DMA0_INT: INT2 Mask                     */
#define DMA_INT_INT2_SHIFT                       2                                                   /*!< DMA0_INT: INT2 Position                 */
#define DMA_INT_INT2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT2_SHIFT))&DMA_INT_INT2_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT3_MASK                        (0x01UL << DMA_INT_INT3_SHIFT)                      /*!< DMA0_INT: INT3 Mask                     */
#define DMA_INT_INT3_SHIFT                       3                                                   /*!< DMA0_INT: INT3 Position                 */
#define DMA_INT_INT3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT3_SHIFT))&DMA_INT_INT3_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT4_MASK                        (0x01UL << DMA_INT_INT4_SHIFT)                      /*!< DMA0_INT: INT4 Mask                     */
#define DMA_INT_INT4_SHIFT                       4                                                   /*!< DMA0_INT: INT4 Position                 */
#define DMA_INT_INT4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT4_SHIFT))&DMA_INT_INT4_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT5_MASK                        (0x01UL << DMA_INT_INT5_SHIFT)                      /*!< DMA0_INT: INT5 Mask                     */
#define DMA_INT_INT5_SHIFT                       5                                                   /*!< DMA0_INT: INT5 Position                 */
#define DMA_INT_INT5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT5_SHIFT))&DMA_INT_INT5_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT6_MASK                        (0x01UL << DMA_INT_INT6_SHIFT)                      /*!< DMA0_INT: INT6 Mask                     */
#define DMA_INT_INT6_SHIFT                       6                                                   /*!< DMA0_INT: INT6 Position                 */
#define DMA_INT_INT6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT6_SHIFT))&DMA_INT_INT6_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT7_MASK                        (0x01UL << DMA_INT_INT7_SHIFT)                      /*!< DMA0_INT: INT7 Mask                     */
#define DMA_INT_INT7_SHIFT                       7                                                   /*!< DMA0_INT: INT7 Position                 */
#define DMA_INT_INT7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT7_SHIFT))&DMA_INT_INT7_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT8_MASK                        (0x01UL << DMA_INT_INT8_SHIFT)                      /*!< DMA0_INT: INT8 Mask                     */
#define DMA_INT_INT8_SHIFT                       8                                                   /*!< DMA0_INT: INT8 Position                 */
#define DMA_INT_INT8(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT8_SHIFT))&DMA_INT_INT8_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT9_MASK                        (0x01UL << DMA_INT_INT9_SHIFT)                      /*!< DMA0_INT: INT9 Mask                     */
#define DMA_INT_INT9_SHIFT                       9                                                   /*!< DMA0_INT: INT9 Position                 */
#define DMA_INT_INT9(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT9_SHIFT))&DMA_INT_INT9_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT10_MASK                       (0x01UL << DMA_INT_INT10_SHIFT)                     /*!< DMA0_INT: INT10 Mask                    */
#define DMA_INT_INT10_SHIFT                      10                                                  /*!< DMA0_INT: INT10 Position                */
#define DMA_INT_INT10(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT10_SHIFT))&DMA_INT_INT10_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT11_MASK                       (0x01UL << DMA_INT_INT11_SHIFT)                     /*!< DMA0_INT: INT11 Mask                    */
#define DMA_INT_INT11_SHIFT                      11                                                  /*!< DMA0_INT: INT11 Position                */
#define DMA_INT_INT11(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT11_SHIFT))&DMA_INT_INT11_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT12_MASK                       (0x01UL << DMA_INT_INT12_SHIFT)                     /*!< DMA0_INT: INT12 Mask                    */
#define DMA_INT_INT12_SHIFT                      12                                                  /*!< DMA0_INT: INT12 Position                */
#define DMA_INT_INT12(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT12_SHIFT))&DMA_INT_INT12_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT13_MASK                       (0x01UL << DMA_INT_INT13_SHIFT)                     /*!< DMA0_INT: INT13 Mask                    */
#define DMA_INT_INT13_SHIFT                      13                                                  /*!< DMA0_INT: INT13 Position                */
#define DMA_INT_INT13(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT13_SHIFT))&DMA_INT_INT13_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT14_MASK                       (0x01UL << DMA_INT_INT14_SHIFT)                     /*!< DMA0_INT: INT14 Mask                    */
#define DMA_INT_INT14_SHIFT                      14                                                  /*!< DMA0_INT: INT14 Position                */
#define DMA_INT_INT14(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT14_SHIFT))&DMA_INT_INT14_MASK) /*!< DMA0_INT                                */
#define DMA_INT_INT15_MASK                       (0x01UL << DMA_INT_INT15_SHIFT)                     /*!< DMA0_INT: INT15 Mask                    */
#define DMA_INT_INT15_SHIFT                      15                                                  /*!< DMA0_INT: INT15 Position                */
#define DMA_INT_INT15(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT15_SHIFT))&DMA_INT_INT15_MASK) /*!< DMA0_INT                                */
/* ------- ERR Bit Fields                           ------ */
#define DMA_ERR_ERR0_MASK                        (0x01UL << DMA_ERR_ERR0_SHIFT)                      /*!< DMA0_ERR: ERR0 Mask                     */
#define DMA_ERR_ERR0_SHIFT                       0                                                   /*!< DMA0_ERR: ERR0 Position                 */
#define DMA_ERR_ERR0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR0_SHIFT))&DMA_ERR_ERR0_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR1_MASK                        (0x01UL << DMA_ERR_ERR1_SHIFT)                      /*!< DMA0_ERR: ERR1 Mask                     */
#define DMA_ERR_ERR1_SHIFT                       1                                                   /*!< DMA0_ERR: ERR1 Position                 */
#define DMA_ERR_ERR1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR1_SHIFT))&DMA_ERR_ERR1_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR2_MASK                        (0x01UL << DMA_ERR_ERR2_SHIFT)                      /*!< DMA0_ERR: ERR2 Mask                     */
#define DMA_ERR_ERR2_SHIFT                       2                                                   /*!< DMA0_ERR: ERR2 Position                 */
#define DMA_ERR_ERR2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR2_SHIFT))&DMA_ERR_ERR2_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR3_MASK                        (0x01UL << DMA_ERR_ERR3_SHIFT)                      /*!< DMA0_ERR: ERR3 Mask                     */
#define DMA_ERR_ERR3_SHIFT                       3                                                   /*!< DMA0_ERR: ERR3 Position                 */
#define DMA_ERR_ERR3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR3_SHIFT))&DMA_ERR_ERR3_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR4_MASK                        (0x01UL << DMA_ERR_ERR4_SHIFT)                      /*!< DMA0_ERR: ERR4 Mask                     */
#define DMA_ERR_ERR4_SHIFT                       4                                                   /*!< DMA0_ERR: ERR4 Position                 */
#define DMA_ERR_ERR4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR4_SHIFT))&DMA_ERR_ERR4_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR5_MASK                        (0x01UL << DMA_ERR_ERR5_SHIFT)                      /*!< DMA0_ERR: ERR5 Mask                     */
#define DMA_ERR_ERR5_SHIFT                       5                                                   /*!< DMA0_ERR: ERR5 Position                 */
#define DMA_ERR_ERR5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR5_SHIFT))&DMA_ERR_ERR5_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR6_MASK                        (0x01UL << DMA_ERR_ERR6_SHIFT)                      /*!< DMA0_ERR: ERR6 Mask                     */
#define DMA_ERR_ERR6_SHIFT                       6                                                   /*!< DMA0_ERR: ERR6 Position                 */
#define DMA_ERR_ERR6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR6_SHIFT))&DMA_ERR_ERR6_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR7_MASK                        (0x01UL << DMA_ERR_ERR7_SHIFT)                      /*!< DMA0_ERR: ERR7 Mask                     */
#define DMA_ERR_ERR7_SHIFT                       7                                                   /*!< DMA0_ERR: ERR7 Position                 */
#define DMA_ERR_ERR7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR7_SHIFT))&DMA_ERR_ERR7_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR8_MASK                        (0x01UL << DMA_ERR_ERR8_SHIFT)                      /*!< DMA0_ERR: ERR8 Mask                     */
#define DMA_ERR_ERR8_SHIFT                       8                                                   /*!< DMA0_ERR: ERR8 Position                 */
#define DMA_ERR_ERR8(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR8_SHIFT))&DMA_ERR_ERR8_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR9_MASK                        (0x01UL << DMA_ERR_ERR9_SHIFT)                      /*!< DMA0_ERR: ERR9 Mask                     */
#define DMA_ERR_ERR9_SHIFT                       9                                                   /*!< DMA0_ERR: ERR9 Position                 */
#define DMA_ERR_ERR9(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR9_SHIFT))&DMA_ERR_ERR9_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR10_MASK                       (0x01UL << DMA_ERR_ERR10_SHIFT)                     /*!< DMA0_ERR: ERR10 Mask                    */
#define DMA_ERR_ERR10_SHIFT                      10                                                  /*!< DMA0_ERR: ERR10 Position                */
#define DMA_ERR_ERR10(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR10_SHIFT))&DMA_ERR_ERR10_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR11_MASK                       (0x01UL << DMA_ERR_ERR11_SHIFT)                     /*!< DMA0_ERR: ERR11 Mask                    */
#define DMA_ERR_ERR11_SHIFT                      11                                                  /*!< DMA0_ERR: ERR11 Position                */
#define DMA_ERR_ERR11(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR11_SHIFT))&DMA_ERR_ERR11_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR12_MASK                       (0x01UL << DMA_ERR_ERR12_SHIFT)                     /*!< DMA0_ERR: ERR12 Mask                    */
#define DMA_ERR_ERR12_SHIFT                      12                                                  /*!< DMA0_ERR: ERR12 Position                */
#define DMA_ERR_ERR12(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR12_SHIFT))&DMA_ERR_ERR12_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR13_MASK                       (0x01UL << DMA_ERR_ERR13_SHIFT)                     /*!< DMA0_ERR: ERR13 Mask                    */
#define DMA_ERR_ERR13_SHIFT                      13                                                  /*!< DMA0_ERR: ERR13 Position                */
#define DMA_ERR_ERR13(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR13_SHIFT))&DMA_ERR_ERR13_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR14_MASK                       (0x01UL << DMA_ERR_ERR14_SHIFT)                     /*!< DMA0_ERR: ERR14 Mask                    */
#define DMA_ERR_ERR14_SHIFT                      14                                                  /*!< DMA0_ERR: ERR14 Position                */
#define DMA_ERR_ERR14(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR14_SHIFT))&DMA_ERR_ERR14_MASK) /*!< DMA0_ERR                                */
#define DMA_ERR_ERR15_MASK                       (0x01UL << DMA_ERR_ERR15_SHIFT)                     /*!< DMA0_ERR: ERR15 Mask                    */
#define DMA_ERR_ERR15_SHIFT                      15                                                  /*!< DMA0_ERR: ERR15 Position                */
#define DMA_ERR_ERR15(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR15_SHIFT))&DMA_ERR_ERR15_MASK) /*!< DMA0_ERR                                */
/* ------- HRS Bit Fields                           ------ */
#define DMA_HRS_HRS0_MASK                        (0x01UL << DMA_HRS_HRS0_SHIFT)                      /*!< DMA0_HRS: HRS0 Mask                     */
#define DMA_HRS_HRS0_SHIFT                       0                                                   /*!< DMA0_HRS: HRS0 Position                 */
#define DMA_HRS_HRS0(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS0_SHIFT))&DMA_HRS_HRS0_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS1_MASK                        (0x01UL << DMA_HRS_HRS1_SHIFT)                      /*!< DMA0_HRS: HRS1 Mask                     */
#define DMA_HRS_HRS1_SHIFT                       1                                                   /*!< DMA0_HRS: HRS1 Position                 */
#define DMA_HRS_HRS1(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS1_SHIFT))&DMA_HRS_HRS1_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS2_MASK                        (0x01UL << DMA_HRS_HRS2_SHIFT)                      /*!< DMA0_HRS: HRS2 Mask                     */
#define DMA_HRS_HRS2_SHIFT                       2                                                   /*!< DMA0_HRS: HRS2 Position                 */
#define DMA_HRS_HRS2(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS2_SHIFT))&DMA_HRS_HRS2_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS3_MASK                        (0x01UL << DMA_HRS_HRS3_SHIFT)                      /*!< DMA0_HRS: HRS3 Mask                     */
#define DMA_HRS_HRS3_SHIFT                       3                                                   /*!< DMA0_HRS: HRS3 Position                 */
#define DMA_HRS_HRS3(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS3_SHIFT))&DMA_HRS_HRS3_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS4_MASK                        (0x01UL << DMA_HRS_HRS4_SHIFT)                      /*!< DMA0_HRS: HRS4 Mask                     */
#define DMA_HRS_HRS4_SHIFT                       4                                                   /*!< DMA0_HRS: HRS4 Position                 */
#define DMA_HRS_HRS4(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS4_SHIFT))&DMA_HRS_HRS4_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS5_MASK                        (0x01UL << DMA_HRS_HRS5_SHIFT)                      /*!< DMA0_HRS: HRS5 Mask                     */
#define DMA_HRS_HRS5_SHIFT                       5                                                   /*!< DMA0_HRS: HRS5 Position                 */
#define DMA_HRS_HRS5(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS5_SHIFT))&DMA_HRS_HRS5_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS6_MASK                        (0x01UL << DMA_HRS_HRS6_SHIFT)                      /*!< DMA0_HRS: HRS6 Mask                     */
#define DMA_HRS_HRS6_SHIFT                       6                                                   /*!< DMA0_HRS: HRS6 Position                 */
#define DMA_HRS_HRS6(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS6_SHIFT))&DMA_HRS_HRS6_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS7_MASK                        (0x01UL << DMA_HRS_HRS7_SHIFT)                      /*!< DMA0_HRS: HRS7 Mask                     */
#define DMA_HRS_HRS7_SHIFT                       7                                                   /*!< DMA0_HRS: HRS7 Position                 */
#define DMA_HRS_HRS7(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS7_SHIFT))&DMA_HRS_HRS7_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS8_MASK                        (0x01UL << DMA_HRS_HRS8_SHIFT)                      /*!< DMA0_HRS: HRS8 Mask                     */
#define DMA_HRS_HRS8_SHIFT                       8                                                   /*!< DMA0_HRS: HRS8 Position                 */
#define DMA_HRS_HRS8(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS8_SHIFT))&DMA_HRS_HRS8_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS9_MASK                        (0x01UL << DMA_HRS_HRS9_SHIFT)                      /*!< DMA0_HRS: HRS9 Mask                     */
#define DMA_HRS_HRS9_SHIFT                       9                                                   /*!< DMA0_HRS: HRS9 Position                 */
#define DMA_HRS_HRS9(x)                          (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS9_SHIFT))&DMA_HRS_HRS9_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS10_MASK                       (0x01UL << DMA_HRS_HRS10_SHIFT)                     /*!< DMA0_HRS: HRS10 Mask                    */
#define DMA_HRS_HRS10_SHIFT                      10                                                  /*!< DMA0_HRS: HRS10 Position                */
#define DMA_HRS_HRS10(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS10_SHIFT))&DMA_HRS_HRS10_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS11_MASK                       (0x01UL << DMA_HRS_HRS11_SHIFT)                     /*!< DMA0_HRS: HRS11 Mask                    */
#define DMA_HRS_HRS11_SHIFT                      11                                                  /*!< DMA0_HRS: HRS11 Position                */
#define DMA_HRS_HRS11(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS11_SHIFT))&DMA_HRS_HRS11_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS12_MASK                       (0x01UL << DMA_HRS_HRS12_SHIFT)                     /*!< DMA0_HRS: HRS12 Mask                    */
#define DMA_HRS_HRS12_SHIFT                      12                                                  /*!< DMA0_HRS: HRS12 Position                */
#define DMA_HRS_HRS12(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS12_SHIFT))&DMA_HRS_HRS12_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS13_MASK                       (0x01UL << DMA_HRS_HRS13_SHIFT)                     /*!< DMA0_HRS: HRS13 Mask                    */
#define DMA_HRS_HRS13_SHIFT                      13                                                  /*!< DMA0_HRS: HRS13 Position                */
#define DMA_HRS_HRS13(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS13_SHIFT))&DMA_HRS_HRS13_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS14_MASK                       (0x01UL << DMA_HRS_HRS14_SHIFT)                     /*!< DMA0_HRS: HRS14 Mask                    */
#define DMA_HRS_HRS14_SHIFT                      14                                                  /*!< DMA0_HRS: HRS14 Position                */
#define DMA_HRS_HRS14(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS14_SHIFT))&DMA_HRS_HRS14_MASK) /*!< DMA0_HRS                                */
#define DMA_HRS_HRS15_MASK                       (0x01UL << DMA_HRS_HRS15_SHIFT)                     /*!< DMA0_HRS: HRS15 Mask                    */
#define DMA_HRS_HRS15_SHIFT                      15                                                  /*!< DMA0_HRS: HRS15 Position                */
#define DMA_HRS_HRS15(x)                         (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS15_SHIFT))&DMA_HRS_HRS15_MASK) /*!< DMA0_HRS                                */
/* ------- DCHPRI Bit Fields                        ------ */
#define DMA_DCHPRI_CHPRI_MASK                    (0x0FUL << DMA_DCHPRI_CHPRI_SHIFT)                  /*!< DMA0_DCHPRI: CHPRI Mask                 */
#define DMA_DCHPRI_CHPRI_SHIFT                   0                                                   /*!< DMA0_DCHPRI: CHPRI Position             */
#define DMA_DCHPRI_CHPRI(x)                      (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI_CHPRI_SHIFT))&DMA_DCHPRI_CHPRI_MASK) /*!< DMA0_DCHPRI                             */
#define DMA_DCHPRI_DPA_MASK                      (0x01UL << DMA_DCHPRI_DPA_SHIFT)                    /*!< DMA0_DCHPRI: DPA Mask                   */
#define DMA_DCHPRI_DPA_SHIFT                     6                                                   /*!< DMA0_DCHPRI: DPA Position               */
#define DMA_DCHPRI_DPA(x)                        (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI_DPA_SHIFT))&DMA_DCHPRI_DPA_MASK) /*!< DMA0_DCHPRI                             */
#define DMA_DCHPRI_ECP_MASK                      (0x01UL << DMA_DCHPRI_ECP_SHIFT)                    /*!< DMA0_DCHPRI: ECP Mask                   */
#define DMA_DCHPRI_ECP_SHIFT                     7                                                   /*!< DMA0_DCHPRI: ECP Position               */
#define DMA_DCHPRI_ECP(x)                        (((uint8_t)(((uint8_t)(x))<<DMA_DCHPRI_ECP_SHIFT))&DMA_DCHPRI_ECP_MASK) /*!< DMA0_DCHPRI                             */
/* ------- SADDR Bit Fields                         ------ */
#define DMA_SADDR_SADDR_MASK                     (0xFFFFFFFFUL << DMA_SADDR_SADDR_SHIFT)             /*!< DMA0_SADDR: SADDR Mask                  */
#define DMA_SADDR_SADDR_SHIFT                    0                                                   /*!< DMA0_SADDR: SADDR Position              */
#define DMA_SADDR_SADDR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_SADDR_SADDR_SHIFT))&DMA_SADDR_SADDR_MASK) /*!< DMA0_SADDR                              */
/* ------- SOFF Bit Fields                          ------ */
#define DMA_SOFF_SOFF_MASK                       (0xFFFFUL << DMA_SOFF_SOFF_SHIFT)                   /*!< DMA0_SOFF: SOFF Mask                    */
#define DMA_SOFF_SOFF_SHIFT                      0                                                   /*!< DMA0_SOFF: SOFF Position                */
#define DMA_SOFF_SOFF(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_SOFF_SOFF_SHIFT))&DMA_SOFF_SOFF_MASK) /*!< DMA0_SOFF                               */
/* ------- ATTR Bit Fields                          ------ */
#define DMA_ATTR_DSIZE_MASK                      (0x07UL << DMA_ATTR_DSIZE_SHIFT)                    /*!< DMA0_ATTR: DSIZE Mask                   */
#define DMA_ATTR_DSIZE_SHIFT                     0                                                   /*!< DMA0_ATTR: DSIZE Position               */
#define DMA_ATTR_DSIZE(x)                        (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_DSIZE_SHIFT))&DMA_ATTR_DSIZE_MASK) /*!< DMA0_ATTR                               */
#define DMA_ATTR_DMOD_MASK                       (0x1FUL << DMA_ATTR_DMOD_SHIFT)                     /*!< DMA0_ATTR: DMOD Mask                    */
#define DMA_ATTR_DMOD_SHIFT                      3                                                   /*!< DMA0_ATTR: DMOD Position                */
#define DMA_ATTR_DMOD(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_DMOD_SHIFT))&DMA_ATTR_DMOD_MASK) /*!< DMA0_ATTR                               */
#define DMA_ATTR_SSIZE_MASK                      (0x07UL << DMA_ATTR_SSIZE_SHIFT)                    /*!< DMA0_ATTR: SSIZE Mask                   */
#define DMA_ATTR_SSIZE_SHIFT                     8                                                   /*!< DMA0_ATTR: SSIZE Position               */
#define DMA_ATTR_SSIZE(x)                        (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_SSIZE_SHIFT))&DMA_ATTR_SSIZE_MASK) /*!< DMA0_ATTR                               */
#define DMA_ATTR_SMOD_MASK                       (0x1FUL << DMA_ATTR_SMOD_SHIFT)                     /*!< DMA0_ATTR: SMOD Mask                    */
#define DMA_ATTR_SMOD_SHIFT                      11                                                  /*!< DMA0_ATTR: SMOD Position                */
#define DMA_ATTR_SMOD(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_ATTR_SMOD_SHIFT))&DMA_ATTR_SMOD_MASK) /*!< DMA0_ATTR                               */
/* ------- NBYTES_MLNO Bit Fields                   ------ */
#define DMA_NBYTES_MLNO_NBYTES_MASK              (0xFFFFFFFFUL << DMA_NBYTES_MLNO_NBYTES_SHIFT)      /*!< DMA0_NBYTES_MLNO: NBYTES Mask           */
#define DMA_NBYTES_MLNO_NBYTES_SHIFT             0                                                   /*!< DMA0_NBYTES_MLNO: NBYTES Position       */
#define DMA_NBYTES_MLNO_NBYTES(x)                (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLNO_NBYTES_SHIFT))&DMA_NBYTES_MLNO_NBYTES_MASK) /*!< DMA0_NBYTES_MLNO                        */
/* ------- NBYTES_MLOFFNO Bit Fields                ------ */
#define DMA_NBYTES_MLOFFNO_NBYTES_MASK           (0x3FFFFFFFUL << DMA_NBYTES_MLOFFNO_NBYTES_SHIFT)   /*!< DMA0_NBYTES_MLOFFNO: NBYTES Mask        */
#define DMA_NBYTES_MLOFFNO_NBYTES_SHIFT          0                                                   /*!< DMA0_NBYTES_MLOFFNO: NBYTES Position    */
#define DMA_NBYTES_MLOFFNO_NBYTES(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFNO_NBYTES_SHIFT))&DMA_NBYTES_MLOFFNO_NBYTES_MASK) /*!< DMA0_NBYTES_MLOFFNO                     */
#define DMA_NBYTES_MLOFFNO_DMLOE_MASK            (0x01UL << DMA_NBYTES_MLOFFNO_DMLOE_SHIFT)          /*!< DMA0_NBYTES_MLOFFNO: DMLOE Mask         */
#define DMA_NBYTES_MLOFFNO_DMLOE_SHIFT           30                                                  /*!< DMA0_NBYTES_MLOFFNO: DMLOE Position     */
#define DMA_NBYTES_MLOFFNO_DMLOE(x)              (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFNO_DMLOE_SHIFT))&DMA_NBYTES_MLOFFNO_DMLOE_MASK) /*!< DMA0_NBYTES_MLOFFNO                     */
#define DMA_NBYTES_MLOFFNO_SMLOE_MASK            (0x01UL << DMA_NBYTES_MLOFFNO_SMLOE_SHIFT)          /*!< DMA0_NBYTES_MLOFFNO: SMLOE Mask         */
#define DMA_NBYTES_MLOFFNO_SMLOE_SHIFT           31                                                  /*!< DMA0_NBYTES_MLOFFNO: SMLOE Position     */
#define DMA_NBYTES_MLOFFNO_SMLOE(x)              (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFNO_SMLOE_SHIFT))&DMA_NBYTES_MLOFFNO_SMLOE_MASK) /*!< DMA0_NBYTES_MLOFFNO                     */
/* ------- NBYTES_MLOFFYES Bit Fields               ------ */
#define DMA_NBYTES_MLOFFYES_NBYTES_MASK          (0x3FFUL << DMA_NBYTES_MLOFFYES_NBYTES_SHIFT)       /*!< DMA0_NBYTES_MLOFFYES: NBYTES Mask       */
#define DMA_NBYTES_MLOFFYES_NBYTES_SHIFT         0                                                   /*!< DMA0_NBYTES_MLOFFYES: NBYTES Position   */
#define DMA_NBYTES_MLOFFYES_NBYTES(x)            (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_NBYTES_SHIFT))&DMA_NBYTES_MLOFFYES_NBYTES_MASK) /*!< DMA0_NBYTES_MLOFFYES                    */
#define DMA_NBYTES_MLOFFYES_MLOFF_MASK           (0xFFFFFUL << DMA_NBYTES_MLOFFYES_MLOFF_SHIFT)      /*!< DMA0_NBYTES_MLOFFYES: MLOFF Mask        */
#define DMA_NBYTES_MLOFFYES_MLOFF_SHIFT          10                                                  /*!< DMA0_NBYTES_MLOFFYES: MLOFF Position    */
#define DMA_NBYTES_MLOFFYES_MLOFF(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_MLOFF_SHIFT))&DMA_NBYTES_MLOFFYES_MLOFF_MASK) /*!< DMA0_NBYTES_MLOFFYES                    */
#define DMA_NBYTES_MLOFFYES_DMLOE_MASK           (0x01UL << DMA_NBYTES_MLOFFYES_DMLOE_SHIFT)         /*!< DMA0_NBYTES_MLOFFYES: DMLOE Mask        */
#define DMA_NBYTES_MLOFFYES_DMLOE_SHIFT          30                                                  /*!< DMA0_NBYTES_MLOFFYES: DMLOE Position    */
#define DMA_NBYTES_MLOFFYES_DMLOE(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_DMLOE_SHIFT))&DMA_NBYTES_MLOFFYES_DMLOE_MASK) /*!< DMA0_NBYTES_MLOFFYES                    */
#define DMA_NBYTES_MLOFFYES_SMLOE_MASK           (0x01UL << DMA_NBYTES_MLOFFYES_SMLOE_SHIFT)         /*!< DMA0_NBYTES_MLOFFYES: SMLOE Mask        */
#define DMA_NBYTES_MLOFFYES_SMLOE_SHIFT          31                                                  /*!< DMA0_NBYTES_MLOFFYES: SMLOE Position    */
#define DMA_NBYTES_MLOFFYES_SMLOE(x)             (((uint32_t)(((uint32_t)(x))<<DMA_NBYTES_MLOFFYES_SMLOE_SHIFT))&DMA_NBYTES_MLOFFYES_SMLOE_MASK) /*!< DMA0_NBYTES_MLOFFYES                    */
/* ------- SLAST Bit Fields                         ------ */
#define DMA_SLAST_SLAST_MASK                     (0xFFFFFFFFUL << DMA_SLAST_SLAST_SHIFT)             /*!< DMA0_SLAST: SLAST Mask                  */
#define DMA_SLAST_SLAST_SHIFT                    0                                                   /*!< DMA0_SLAST: SLAST Position              */
#define DMA_SLAST_SLAST(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_SLAST_SLAST_SHIFT))&DMA_SLAST_SLAST_MASK) /*!< DMA0_SLAST                              */
/* ------- DADDR Bit Fields                         ------ */
#define DMA_DADDR_DADDR_MASK                     (0xFFFFFFFFUL << DMA_DADDR_DADDR_SHIFT)             /*!< DMA0_DADDR: DADDR Mask                  */
#define DMA_DADDR_DADDR_SHIFT                    0                                                   /*!< DMA0_DADDR: DADDR Position              */
#define DMA_DADDR_DADDR(x)                       (((uint32_t)(((uint32_t)(x))<<DMA_DADDR_DADDR_SHIFT))&DMA_DADDR_DADDR_MASK) /*!< DMA0_DADDR                              */
/* ------- DOFF Bit Fields                          ------ */
#define DMA_DOFF_DOFF_MASK                       (0xFFFFUL << DMA_DOFF_DOFF_SHIFT)                   /*!< DMA0_DOFF: DOFF Mask                    */
#define DMA_DOFF_DOFF_SHIFT                      0                                                   /*!< DMA0_DOFF: DOFF Position                */
#define DMA_DOFF_DOFF(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_DOFF_DOFF_SHIFT))&DMA_DOFF_DOFF_MASK) /*!< DMA0_DOFF                               */
/* ------- CITER_ELINKNO Bit Fields                 ------ */
#define DMA_CITER_ELINKNO_CITER_MASK             (0x7FFFUL << DMA_CITER_ELINKNO_CITER_SHIFT)         /*!< DMA0_CITER_ELINKNO: CITER Mask          */
#define DMA_CITER_ELINKNO_CITER_SHIFT            0                                                   /*!< DMA0_CITER_ELINKNO: CITER Position      */
#define DMA_CITER_ELINKNO_CITER(x)               (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKNO_CITER_SHIFT))&DMA_CITER_ELINKNO_CITER_MASK) /*!< DMA0_CITER_ELINKNO                      */
#define DMA_CITER_ELINKNO_ELINK_MASK             (0x01UL << DMA_CITER_ELINKNO_ELINK_SHIFT)           /*!< DMA0_CITER_ELINKNO: ELINK Mask          */
#define DMA_CITER_ELINKNO_ELINK_SHIFT            15                                                  /*!< DMA0_CITER_ELINKNO: ELINK Position      */
#define DMA_CITER_ELINKNO_ELINK(x)               (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKNO_ELINK_SHIFT))&DMA_CITER_ELINKNO_ELINK_MASK) /*!< DMA0_CITER_ELINKNO                      */
/* ------- CITER_ELINKYES Bit Fields                ------ */
#define DMA_CITER_ELINKYES_CITER_MASK            (0x1FFUL << DMA_CITER_ELINKYES_CITER_SHIFT)         /*!< DMA0_CITER_ELINKYES: CITER Mask         */
#define DMA_CITER_ELINKYES_CITER_SHIFT           0                                                   /*!< DMA0_CITER_ELINKYES: CITER Position     */
#define DMA_CITER_ELINKYES_CITER(x)              (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKYES_CITER_SHIFT))&DMA_CITER_ELINKYES_CITER_MASK) /*!< DMA0_CITER_ELINKYES                     */
#define DMA_CITER_ELINKYES_LINKCH_MASK           (0x0FUL << DMA_CITER_ELINKYES_LINKCH_SHIFT)         /*!< DMA0_CITER_ELINKYES: LINKCH Mask        */
#define DMA_CITER_ELINKYES_LINKCH_SHIFT          9                                                   /*!< DMA0_CITER_ELINKYES: LINKCH Position    */
#define DMA_CITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKYES_LINKCH_SHIFT))&DMA_CITER_ELINKYES_LINKCH_MASK) /*!< DMA0_CITER_ELINKYES                     */
#define DMA_CITER_ELINKYES_ELINK_MASK            (0x01UL << DMA_CITER_ELINKYES_ELINK_SHIFT)          /*!< DMA0_CITER_ELINKYES: ELINK Mask         */
#define DMA_CITER_ELINKYES_ELINK_SHIFT           15                                                  /*!< DMA0_CITER_ELINKYES: ELINK Position     */
#define DMA_CITER_ELINKYES_ELINK(x)              (((uint16_t)(((uint16_t)(x))<<DMA_CITER_ELINKYES_ELINK_SHIFT))&DMA_CITER_ELINKYES_ELINK_MASK) /*!< DMA0_CITER_ELINKYES                     */
/* ------- DLASTSGA Bit Fields                      ------ */
#define DMA_DLASTSGA_DLASTSGA_MASK               (0xFFFFFFFFUL << DMA_DLASTSGA_DLASTSGA_SHIFT)       /*!< DMA0_DLASTSGA: DLASTSGA Mask            */
#define DMA_DLASTSGA_DLASTSGA_SHIFT              0                                                   /*!< DMA0_DLASTSGA: DLASTSGA Position        */
#define DMA_DLASTSGA_DLASTSGA(x)                 (((uint32_t)(((uint32_t)(x))<<DMA_DLASTSGA_DLASTSGA_SHIFT))&DMA_DLASTSGA_DLASTSGA_MASK) /*!< DMA0_DLASTSGA                           */
/* ------- CSR Bit Fields                           ------ */
#define DMA_CSR_START_MASK                       (0x01UL << DMA_CSR_START_SHIFT)                     /*!< DMA0_CSR: START Mask                    */
#define DMA_CSR_START_SHIFT                      0                                                   /*!< DMA0_CSR: START Position                */
#define DMA_CSR_START(x)                         (((uint16_t)(((uint16_t)(x))<<DMA_CSR_START_SHIFT))&DMA_CSR_START_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_INTMAJOR_MASK                    (0x01UL << DMA_CSR_INTMAJOR_SHIFT)                  /*!< DMA0_CSR: INTMAJOR Mask                 */
#define DMA_CSR_INTMAJOR_SHIFT                   1                                                   /*!< DMA0_CSR: INTMAJOR Position             */
#define DMA_CSR_INTMAJOR(x)                      (((uint16_t)(((uint16_t)(x))<<DMA_CSR_INTMAJOR_SHIFT))&DMA_CSR_INTMAJOR_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_INTHALF_MASK                     (0x01UL << DMA_CSR_INTHALF_SHIFT)                   /*!< DMA0_CSR: INTHALF Mask                  */
#define DMA_CSR_INTHALF_SHIFT                    2                                                   /*!< DMA0_CSR: INTHALF Position              */
#define DMA_CSR_INTHALF(x)                       (((uint16_t)(((uint16_t)(x))<<DMA_CSR_INTHALF_SHIFT))&DMA_CSR_INTHALF_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_DREQ_MASK                        (0x01UL << DMA_CSR_DREQ_SHIFT)                      /*!< DMA0_CSR: DREQ Mask                     */
#define DMA_CSR_DREQ_SHIFT                       3                                                   /*!< DMA0_CSR: DREQ Position                 */
#define DMA_CSR_DREQ(x)                          (((uint16_t)(((uint16_t)(x))<<DMA_CSR_DREQ_SHIFT))&DMA_CSR_DREQ_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_ESG_MASK                         (0x01UL << DMA_CSR_ESG_SHIFT)                       /*!< DMA0_CSR: ESG Mask                      */
#define DMA_CSR_ESG_SHIFT                        4                                                   /*!< DMA0_CSR: ESG Position                  */
#define DMA_CSR_ESG(x)                           (((uint16_t)(((uint16_t)(x))<<DMA_CSR_ESG_SHIFT))&DMA_CSR_ESG_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_MAJORELINK_MASK                  (0x01UL << DMA_CSR_MAJORELINK_SHIFT)                /*!< DMA0_CSR: MAJORELINK Mask               */
#define DMA_CSR_MAJORELINK_SHIFT                 5                                                   /*!< DMA0_CSR: MAJORELINK Position           */
#define DMA_CSR_MAJORELINK(x)                    (((uint16_t)(((uint16_t)(x))<<DMA_CSR_MAJORELINK_SHIFT))&DMA_CSR_MAJORELINK_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_ACTIVE_MASK                      (0x01UL << DMA_CSR_ACTIVE_SHIFT)                    /*!< DMA0_CSR: ACTIVE Mask                   */
#define DMA_CSR_ACTIVE_SHIFT                     6                                                   /*!< DMA0_CSR: ACTIVE Position               */
#define DMA_CSR_ACTIVE(x)                        (((uint16_t)(((uint16_t)(x))<<DMA_CSR_ACTIVE_SHIFT))&DMA_CSR_ACTIVE_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_DONE_MASK                        (0x01UL << DMA_CSR_DONE_SHIFT)                      /*!< DMA0_CSR: DONE Mask                     */
#define DMA_CSR_DONE_SHIFT                       7                                                   /*!< DMA0_CSR: DONE Position                 */
#define DMA_CSR_DONE(x)                          (((uint16_t)(((uint16_t)(x))<<DMA_CSR_DONE_SHIFT))&DMA_CSR_DONE_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_MAJORLINKCH_MASK                 (0x0FUL << DMA_CSR_MAJORLINKCH_SHIFT)               /*!< DMA0_CSR: MAJORLINKCH Mask              */
#define DMA_CSR_MAJORLINKCH_SHIFT                8                                                   /*!< DMA0_CSR: MAJORLINKCH Position          */
#define DMA_CSR_MAJORLINKCH(x)                   (((uint16_t)(((uint16_t)(x))<<DMA_CSR_MAJORLINKCH_SHIFT))&DMA_CSR_MAJORLINKCH_MASK) /*!< DMA0_CSR                                */
#define DMA_CSR_BWC_MASK                         (0x03UL << DMA_CSR_BWC_SHIFT)                       /*!< DMA0_CSR: BWC Mask                      */
#define DMA_CSR_BWC_SHIFT                        14                                                  /*!< DMA0_CSR: BWC Position                  */
#define DMA_CSR_BWC(x)                           (((uint16_t)(((uint16_t)(x))<<DMA_CSR_BWC_SHIFT))&DMA_CSR_BWC_MASK) /*!< DMA0_CSR                                */
/* ------- BITER_ELINKNO Bit Fields                 ------ */
#define DMA_BITER_ELINKNO_BITER_MASK             (0x7FFFUL << DMA_BITER_ELINKNO_BITER_SHIFT)         /*!< DMA0_BITER_ELINKNO: BITER Mask          */
#define DMA_BITER_ELINKNO_BITER_SHIFT            0                                                   /*!< DMA0_BITER_ELINKNO: BITER Position      */
#define DMA_BITER_ELINKNO_BITER(x)               (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKNO_BITER_SHIFT))&DMA_BITER_ELINKNO_BITER_MASK) /*!< DMA0_BITER_ELINKNO                      */
#define DMA_BITER_ELINKNO_ELINK_MASK             (0x01UL << DMA_BITER_ELINKNO_ELINK_SHIFT)           /*!< DMA0_BITER_ELINKNO: ELINK Mask          */
#define DMA_BITER_ELINKNO_ELINK_SHIFT            15                                                  /*!< DMA0_BITER_ELINKNO: ELINK Position      */
#define DMA_BITER_ELINKNO_ELINK(x)               (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKNO_ELINK_SHIFT))&DMA_BITER_ELINKNO_ELINK_MASK) /*!< DMA0_BITER_ELINKNO                      */
/* ------- BITER_ELINKYES Bit Fields                ------ */
#define DMA_BITER_ELINKYES_BITER_MASK            (0x1FFUL << DMA_BITER_ELINKYES_BITER_SHIFT)         /*!< DMA0_BITER_ELINKYES: BITER Mask         */
#define DMA_BITER_ELINKYES_BITER_SHIFT           0                                                   /*!< DMA0_BITER_ELINKYES: BITER Position     */
#define DMA_BITER_ELINKYES_BITER(x)              (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKYES_BITER_SHIFT))&DMA_BITER_ELINKYES_BITER_MASK) /*!< DMA0_BITER_ELINKYES                     */
#define DMA_BITER_ELINKYES_LINKCH_MASK           (0x0FUL << DMA_BITER_ELINKYES_LINKCH_SHIFT)         /*!< DMA0_BITER_ELINKYES: LINKCH Mask        */
#define DMA_BITER_ELINKYES_LINKCH_SHIFT          9                                                   /*!< DMA0_BITER_ELINKYES: LINKCH Position    */
#define DMA_BITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKYES_LINKCH_SHIFT))&DMA_BITER_ELINKYES_LINKCH_MASK) /*!< DMA0_BITER_ELINKYES                     */
#define DMA_BITER_ELINKYES_ELINK_MASK            (0x01UL << DMA_BITER_ELINKYES_ELINK_SHIFT)          /*!< DMA0_BITER_ELINKYES: ELINK Mask         */
#define DMA_BITER_ELINKYES_ELINK_SHIFT           15                                                  /*!< DMA0_BITER_ELINKYES: ELINK Position     */
#define DMA_BITER_ELINKYES_ELINK(x)              (((uint16_t)(((uint16_t)(x))<<DMA_BITER_ELINKYES_ELINK_SHIFT))&DMA_BITER_ELINKYES_ELINK_MASK) /*!< DMA0_BITER_ELINKYES                     */
/**
 * @} */ /* End group DMA0_Register_Masks_GROUP 
 */

/* DMA0 - Peripheral instance base addresses */
#define DMA0_BasePtr                   0x40008000UL //!< Peripheral base address
#define DMA0                           ((DMA_Type *) DMA0_BasePtr) //!< Freescale base pointer
#define DMA0_BASE_PTR                  (DMA0) //!< Freescale style base pointer
/**
 * @} */ /* End group DMA0_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMAMUX_Peripheral_access_layer_GROUP DMAMUX Peripheral Access Layer
* @brief C Struct for DMAMUX
* @{
*/

/* ================================================================================ */
/* ================           DMAMUX0 (file:DMAMUX0_16CH_TRIG)       ================ */
/* ================================================================================ */

/**
 * @brief DMA channel multiplexor
 */
/**
* @addtogroup DMAMUX_structs_GROUP DMAMUX struct
* @brief Struct for DMAMUX
* @{
*/
typedef struct {                                /*       DMAMUX0 Structure                                            */
   __IO uint8_t   CHCFG[16];                    /**< 0000: Channel Configuration Register                               */
} DMAMUX_Type;

/**
 * @} */ /* End group DMAMUX_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DMAMUX0' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DMAMUX_Register_Masks_GROUP DMAMUX Register Masks
* @brief Register Masks for DMAMUX
* @{
*/
/* ------- CHCFG Bit Fields                         ------ */
#define DMAMUX_CHCFG_SOURCE_MASK                 (0x3FUL << DMAMUX_CHCFG_SOURCE_SHIFT)               /*!< DMAMUX0_CHCFG: SOURCE Mask              */
#define DMAMUX_CHCFG_SOURCE_SHIFT                0                                                   /*!< DMAMUX0_CHCFG: SOURCE Position          */
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_SOURCE_SHIFT))&DMAMUX_CHCFG_SOURCE_MASK) /*!< DMAMUX0_CHCFG                           */
#define DMAMUX_CHCFG_TRIG_MASK                   (0x01UL << DMAMUX_CHCFG_TRIG_SHIFT)                 /*!< DMAMUX0_CHCFG: TRIG Mask                */
#define DMAMUX_CHCFG_TRIG_SHIFT                  6                                                   /*!< DMAMUX0_CHCFG: TRIG Position            */
#define DMAMUX_CHCFG_TRIG(x)                     (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_TRIG_SHIFT))&DMAMUX_CHCFG_TRIG_MASK) /*!< DMAMUX0_CHCFG                           */
#define DMAMUX_CHCFG_ENBL_MASK                   (0x01UL << DMAMUX_CHCFG_ENBL_SHIFT)                 /*!< DMAMUX0_CHCFG: ENBL Mask                */
#define DMAMUX_CHCFG_ENBL_SHIFT                  7                                                   /*!< DMAMUX0_CHCFG: ENBL Position            */
#define DMAMUX_CHCFG_ENBL(x)                     (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_ENBL_SHIFT))&DMAMUX_CHCFG_ENBL_MASK) /*!< DMAMUX0_CHCFG                           */
/**
 * @} */ /* End group DMAMUX_Register_Masks_GROUP 
 */

/* DMAMUX0 - Peripheral instance base addresses */
#define DMAMUX0_BasePtr                0x40021000UL //!< Peripheral base address
#define DMAMUX0                        ((DMAMUX_Type *) DMAMUX0_BasePtr) //!< Freescale base pointer
#define DMAMUX0_BASE_PTR               (DMAMUX0) //!< Freescale style base pointer
/**
 * @} */ /* End group DMAMUX_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup ETF_Peripheral_access_layer_GROUP ETF Peripheral Access Layer
* @brief C Struct for ETF
* @{
*/

/* ================================================================================ */
/* ================           ETF (file:ETF_0)                     ================ */
/* ================================================================================ */

/**
 * @brief Embedded Trace Funnel
 */
/**
* @addtogroup ETF_structs_GROUP ETF struct
* @brief Struct for ETF
* @{
*/
typedef struct {                                /*       ETF Structure                                                */
   __IO uint32_t  FCR;                          /**< 0000: Funnel Control Register                                      */
   __IO uint32_t  PCR;                          /**< 0004: Priority Control Register                                    */
   __I  uint32_t  RESERVED0[953];              
   __IO uint32_t  ITATBDATA0;                   /**< 0EEC: Integration Register, ITATBDATA0                             */
   __IO uint32_t  ITATBCTR2;                    /**< 0EF0: Integration Register, ITATBCTR2                              */
   __IO uint32_t  ITATBCTR1;                    /**< 0EF4: Integration Register, ITATBCTR1                              */
   __IO uint32_t  ITATBCTR0;                    /**< 0EF8: Integration Register, ITATBCTR0                              */
   __I  uint32_t  RESERVED1;                   
   __IO uint32_t  ITCTRL;                       /**< 0F00: Integration Mode Control Register                            */
   __I  uint32_t  RESERVED2[39];               
   __IO uint32_t  CLAIMSET;                     /**< 0FA0: Claim Tag Set Register                                       */
   __IO uint32_t  CLAIMCLR;                     /**< 0FA4: Claim Tag Clear Register                                     */
   __I  uint32_t  RESERVED3[2];                
   __O  uint32_t  LAR;                          /**< 0FB0: Lock Access Register                                         */
   __I  uint32_t  LSR;                          /**< 0FB4: Lock Status Register                                         */
   __I  uint32_t  AUTHSTATUS;                   /**< 0FB8: Authentication Status Register                               */
   __I  uint32_t  RESERVED4[3];                
   __I  uint32_t  DEVID;                        /**< 0FC8: Device ID Register                                           */
   __I  uint32_t  DEVTYPE;                      /**< 0FCC: Device Type Identifier Register                              */
   __I  uint32_t  PIDR4;                        /**< 0FD0: Peripheral Identification Register 4                         */
   __I  uint32_t  PIDR5;                        /**< 0FD4: Peripheral Identification Register 5                         */
   __I  uint32_t  PIDR6;                        /**< 0FD8: Peripheral Identification Register 6                         */
   __I  uint32_t  PIDR7;                        /**< 0FDC: Peripheral Identification Register 7                         */
   __I  uint32_t  PIDR0;                        /**< 0FE0: Peripheral Identification Register 0                         */
   __I  uint32_t  PIDR1;                        /**< 0FE4: Peripheral Identification Register 1                         */
   __I  uint32_t  PIDR2;                        /**< 0FE8: Peripheral Identification Register 2                         */
   __I  uint32_t  PIDR3;                        /**< 0FEC: Peripheral Identification Register 3                         */
   __I  uint32_t  CIDR0;                        /**< 0FF0: Component Identification Register 0                          */
   __I  uint32_t  CIDR1;                        /**< 0FF4: Component Identification Register 1                          */
   __I  uint32_t  CIDR2;                        /**< 0FF8: Component Identification Register 2                          */
   __I  uint32_t  CIDR3;                        /**< 0FFC: Component Identification Register 3                          */
} ETF_Type;

/**
 * @} */ /* End group ETF_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'ETF' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup ETF_Register_Masks_GROUP ETF Register Masks
* @brief Register Masks for ETF
* @{
*/
/* ------- FCR Bit Fields                           ------ */
#define ETF_FCR_EnS0_MASK                        (0x01UL << ETF_FCR_EnS0_SHIFT)                      /*!< ETF_FCR: EnS0 Mask                      */
#define ETF_FCR_EnS0_SHIFT                       0                                                   /*!< ETF_FCR: EnS0 Position                  */
#define ETF_FCR_EnS0(x)                          (((uint32_t)(((uint32_t)(x))<<ETF_FCR_EnS0_SHIFT))&ETF_FCR_EnS0_MASK) /*!< ETF_FCR                                 */
#define ETF_FCR_EnS1_MASK                        (0x01UL << ETF_FCR_EnS1_SHIFT)                      /*!< ETF_FCR: EnS1 Mask                      */
#define ETF_FCR_EnS1_SHIFT                       1                                                   /*!< ETF_FCR: EnS1 Position                  */
#define ETF_FCR_EnS1(x)                          (((uint32_t)(((uint32_t)(x))<<ETF_FCR_EnS1_SHIFT))&ETF_FCR_EnS1_MASK) /*!< ETF_FCR                                 */
#define ETF_FCR_EnS2_MASK                        (0x01UL << ETF_FCR_EnS2_SHIFT)                      /*!< ETF_FCR: EnS2 Mask                      */
#define ETF_FCR_EnS2_SHIFT                       2                                                   /*!< ETF_FCR: EnS2 Position                  */
#define ETF_FCR_EnS2(x)                          (((uint32_t)(((uint32_t)(x))<<ETF_FCR_EnS2_SHIFT))&ETF_FCR_EnS2_MASK) /*!< ETF_FCR                                 */
#define ETF_FCR_EnS3_MASK                        (0x01UL << ETF_FCR_EnS3_SHIFT)                      /*!< ETF_FCR: EnS3 Mask                      */
#define ETF_FCR_EnS3_SHIFT                       3                                                   /*!< ETF_FCR: EnS3 Position                  */
#define ETF_FCR_EnS3(x)                          (((uint32_t)(((uint32_t)(x))<<ETF_FCR_EnS3_SHIFT))&ETF_FCR_EnS3_MASK) /*!< ETF_FCR                                 */
#define ETF_FCR_EnS4_MASK                        (0x01UL << ETF_FCR_EnS4_SHIFT)                      /*!< ETF_FCR: EnS4 Mask                      */
#define ETF_FCR_EnS4_SHIFT                       4                                                   /*!< ETF_FCR: EnS4 Position                  */
#define ETF_FCR_EnS4(x)                          (((uint32_t)(((uint32_t)(x))<<ETF_FCR_EnS4_SHIFT))&ETF_FCR_EnS4_MASK) /*!< ETF_FCR                                 */
#define ETF_FCR_EnS5_MASK                        (0x01UL << ETF_FCR_EnS5_SHIFT)                      /*!< ETF_FCR: EnS5 Mask                      */
#define ETF_FCR_EnS5_SHIFT                       5                                                   /*!< ETF_FCR: EnS5 Position                  */
#define ETF_FCR_EnS5(x)                          (((uint32_t)(((uint32_t)(x))<<ETF_FCR_EnS5_SHIFT))&ETF_FCR_EnS5_MASK) /*!< ETF_FCR                                 */
#define ETF_FCR_EnS6_MASK                        (0x01UL << ETF_FCR_EnS6_SHIFT)                      /*!< ETF_FCR: EnS6 Mask                      */
#define ETF_FCR_EnS6_SHIFT                       6                                                   /*!< ETF_FCR: EnS6 Position                  */
#define ETF_FCR_EnS6(x)                          (((uint32_t)(((uint32_t)(x))<<ETF_FCR_EnS6_SHIFT))&ETF_FCR_EnS6_MASK) /*!< ETF_FCR                                 */
#define ETF_FCR_EnS7_MASK                        (0x01UL << ETF_FCR_EnS7_SHIFT)                      /*!< ETF_FCR: EnS7 Mask                      */
#define ETF_FCR_EnS7_SHIFT                       7                                                   /*!< ETF_FCR: EnS7 Position                  */
#define ETF_FCR_EnS7(x)                          (((uint32_t)(((uint32_t)(x))<<ETF_FCR_EnS7_SHIFT))&ETF_FCR_EnS7_MASK) /*!< ETF_FCR                                 */
#define ETF_FCR_HT_MASK                          (0x0FUL << ETF_FCR_HT_SHIFT)                        /*!< ETF_FCR: HT Mask                        */
#define ETF_FCR_HT_SHIFT                         8                                                   /*!< ETF_FCR: HT Position                    */
#define ETF_FCR_HT(x)                            (((uint32_t)(((uint32_t)(x))<<ETF_FCR_HT_SHIFT))&ETF_FCR_HT_MASK) /*!< ETF_FCR                                 */
/* ------- PCR Bit Fields                           ------ */
#define ETF_PCR_PriPort0_MASK                    (0x07UL << ETF_PCR_PriPort0_SHIFT)                  /*!< ETF_PCR: PriPort0 Mask                  */
#define ETF_PCR_PriPort0_SHIFT                   0                                                   /*!< ETF_PCR: PriPort0 Position              */
#define ETF_PCR_PriPort0(x)                      (((uint32_t)(((uint32_t)(x))<<ETF_PCR_PriPort0_SHIFT))&ETF_PCR_PriPort0_MASK) /*!< ETF_PCR                                 */
#define ETF_PCR_PriPort1_MASK                    (0x07UL << ETF_PCR_PriPort1_SHIFT)                  /*!< ETF_PCR: PriPort1 Mask                  */
#define ETF_PCR_PriPort1_SHIFT                   3                                                   /*!< ETF_PCR: PriPort1 Position              */
#define ETF_PCR_PriPort1(x)                      (((uint32_t)(((uint32_t)(x))<<ETF_PCR_PriPort1_SHIFT))&ETF_PCR_PriPort1_MASK) /*!< ETF_PCR                                 */
#define ETF_PCR_PriPort2_MASK                    (0x07UL << ETF_PCR_PriPort2_SHIFT)                  /*!< ETF_PCR: PriPort2 Mask                  */
#define ETF_PCR_PriPort2_SHIFT                   6                                                   /*!< ETF_PCR: PriPort2 Position              */
#define ETF_PCR_PriPort2(x)                      (((uint32_t)(((uint32_t)(x))<<ETF_PCR_PriPort2_SHIFT))&ETF_PCR_PriPort2_MASK) /*!< ETF_PCR                                 */
#define ETF_PCR_PriPort3_MASK                    (0x07UL << ETF_PCR_PriPort3_SHIFT)                  /*!< ETF_PCR: PriPort3 Mask                  */
#define ETF_PCR_PriPort3_SHIFT                   9                                                   /*!< ETF_PCR: PriPort3 Position              */
#define ETF_PCR_PriPort3(x)                      (((uint32_t)(((uint32_t)(x))<<ETF_PCR_PriPort3_SHIFT))&ETF_PCR_PriPort3_MASK) /*!< ETF_PCR                                 */
#define ETF_PCR_PriPort4_MASK                    (0x07UL << ETF_PCR_PriPort4_SHIFT)                  /*!< ETF_PCR: PriPort4 Mask                  */
#define ETF_PCR_PriPort4_SHIFT                   12                                                  /*!< ETF_PCR: PriPort4 Position              */
#define ETF_PCR_PriPort4(x)                      (((uint32_t)(((uint32_t)(x))<<ETF_PCR_PriPort4_SHIFT))&ETF_PCR_PriPort4_MASK) /*!< ETF_PCR                                 */
#define ETF_PCR_PriPort5_MASK                    (0x07UL << ETF_PCR_PriPort5_SHIFT)                  /*!< ETF_PCR: PriPort5 Mask                  */
#define ETF_PCR_PriPort5_SHIFT                   15                                                  /*!< ETF_PCR: PriPort5 Position              */
#define ETF_PCR_PriPort5(x)                      (((uint32_t)(((uint32_t)(x))<<ETF_PCR_PriPort5_SHIFT))&ETF_PCR_PriPort5_MASK) /*!< ETF_PCR                                 */
#define ETF_PCR_PriPort6_MASK                    (0x07UL << ETF_PCR_PriPort6_SHIFT)                  /*!< ETF_PCR: PriPort6 Mask                  */
#define ETF_PCR_PriPort6_SHIFT                   18                                                  /*!< ETF_PCR: PriPort6 Position              */
#define ETF_PCR_PriPort6(x)                      (((uint32_t)(((uint32_t)(x))<<ETF_PCR_PriPort6_SHIFT))&ETF_PCR_PriPort6_MASK) /*!< ETF_PCR                                 */
#define ETF_PCR_PriPort7_MASK                    (0x07UL << ETF_PCR_PriPort7_SHIFT)                  /*!< ETF_PCR: PriPort7 Mask                  */
#define ETF_PCR_PriPort7_SHIFT                   21                                                  /*!< ETF_PCR: PriPort7 Position              */
#define ETF_PCR_PriPort7(x)                      (((uint32_t)(((uint32_t)(x))<<ETF_PCR_PriPort7_SHIFT))&ETF_PCR_PriPort7_MASK) /*!< ETF_PCR                                 */
/* ------- ITATBDATA0 Bit Fields                    ------ */
#define ETF_ITATBDATA0_ATDATA0_MASK              (0x01UL << ETF_ITATBDATA0_ATDATA0_SHIFT)            /*!< ETF_ITATBDATA0: ATDATA0 Mask            */
#define ETF_ITATBDATA0_ATDATA0_SHIFT             0                                                   /*!< ETF_ITATBDATA0: ATDATA0 Position        */
#define ETF_ITATBDATA0_ATDATA0(x)                (((uint32_t)(((uint32_t)(x))<<ETF_ITATBDATA0_ATDATA0_SHIFT))&ETF_ITATBDATA0_ATDATA0_MASK) /*!< ETF_ITATBDATA0                          */
#define ETF_ITATBDATA0_ATDATA7_MASK              (0x01UL << ETF_ITATBDATA0_ATDATA7_SHIFT)            /*!< ETF_ITATBDATA0: ATDATA7 Mask            */
#define ETF_ITATBDATA0_ATDATA7_SHIFT             1                                                   /*!< ETF_ITATBDATA0: ATDATA7 Position        */
#define ETF_ITATBDATA0_ATDATA7(x)                (((uint32_t)(((uint32_t)(x))<<ETF_ITATBDATA0_ATDATA7_SHIFT))&ETF_ITATBDATA0_ATDATA7_MASK) /*!< ETF_ITATBDATA0                          */
#define ETF_ITATBDATA0_ATDATA15_MASK             (0x01UL << ETF_ITATBDATA0_ATDATA15_SHIFT)           /*!< ETF_ITATBDATA0: ATDATA15 Mask           */
#define ETF_ITATBDATA0_ATDATA15_SHIFT            2                                                   /*!< ETF_ITATBDATA0: ATDATA15 Position       */
#define ETF_ITATBDATA0_ATDATA15(x)               (((uint32_t)(((uint32_t)(x))<<ETF_ITATBDATA0_ATDATA15_SHIFT))&ETF_ITATBDATA0_ATDATA15_MASK) /*!< ETF_ITATBDATA0                          */
#define ETF_ITATBDATA0_ATDATA23_MASK             (0x01UL << ETF_ITATBDATA0_ATDATA23_SHIFT)           /*!< ETF_ITATBDATA0: ATDATA23 Mask           */
#define ETF_ITATBDATA0_ATDATA23_SHIFT            3                                                   /*!< ETF_ITATBDATA0: ATDATA23 Position       */
#define ETF_ITATBDATA0_ATDATA23(x)               (((uint32_t)(((uint32_t)(x))<<ETF_ITATBDATA0_ATDATA23_SHIFT))&ETF_ITATBDATA0_ATDATA23_MASK) /*!< ETF_ITATBDATA0                          */
#define ETF_ITATBDATA0_ATDATA31_MASK             (0x01UL << ETF_ITATBDATA0_ATDATA31_SHIFT)           /*!< ETF_ITATBDATA0: ATDATA31 Mask           */
#define ETF_ITATBDATA0_ATDATA31_SHIFT            4                                                   /*!< ETF_ITATBDATA0: ATDATA31 Position       */
#define ETF_ITATBDATA0_ATDATA31(x)               (((uint32_t)(((uint32_t)(x))<<ETF_ITATBDATA0_ATDATA31_SHIFT))&ETF_ITATBDATA0_ATDATA31_MASK) /*!< ETF_ITATBDATA0                          */
/* ------- ITATBCTR2 Bit Fields                     ------ */
#define ETF_ITATBCTR2_ATREADY_MASK               (0x01UL << ETF_ITATBCTR2_ATREADY_SHIFT)             /*!< ETF_ITATBCTR2: ATREADY Mask             */
#define ETF_ITATBCTR2_ATREADY_SHIFT              0                                                   /*!< ETF_ITATBCTR2: ATREADY Position         */
#define ETF_ITATBCTR2_ATREADY(x)                 (((uint32_t)(((uint32_t)(x))<<ETF_ITATBCTR2_ATREADY_SHIFT))&ETF_ITATBCTR2_ATREADY_MASK) /*!< ETF_ITATBCTR2                           */
#define ETF_ITATBCTR2_AFVALID_MASK               (0x01UL << ETF_ITATBCTR2_AFVALID_SHIFT)             /*!< ETF_ITATBCTR2: AFVALID Mask             */
#define ETF_ITATBCTR2_AFVALID_SHIFT              1                                                   /*!< ETF_ITATBCTR2: AFVALID Position         */
#define ETF_ITATBCTR2_AFVALID(x)                 (((uint32_t)(((uint32_t)(x))<<ETF_ITATBCTR2_AFVALID_SHIFT))&ETF_ITATBCTR2_AFVALID_MASK) /*!< ETF_ITATBCTR2                           */
/* ------- ITATBCTR1 Bit Fields                     ------ */
#define ETF_ITATBCTR1_ATID_MASK                  (0x7FUL << ETF_ITATBCTR1_ATID_SHIFT)                /*!< ETF_ITATBCTR1: ATID Mask                */
#define ETF_ITATBCTR1_ATID_SHIFT                 0                                                   /*!< ETF_ITATBCTR1: ATID Position            */
#define ETF_ITATBCTR1_ATID(x)                    (((uint32_t)(((uint32_t)(x))<<ETF_ITATBCTR1_ATID_SHIFT))&ETF_ITATBCTR1_ATID_MASK) /*!< ETF_ITATBCTR1                           */
/* ------- ITATBCTR0 Bit Fields                     ------ */
#define ETF_ITATBCTR0_ATVALID_MASK               (0x01UL << ETF_ITATBCTR0_ATVALID_SHIFT)             /*!< ETF_ITATBCTR0: ATVALID Mask             */
#define ETF_ITATBCTR0_ATVALID_SHIFT              0                                                   /*!< ETF_ITATBCTR0: ATVALID Position         */
#define ETF_ITATBCTR0_ATVALID(x)                 (((uint32_t)(((uint32_t)(x))<<ETF_ITATBCTR0_ATVALID_SHIFT))&ETF_ITATBCTR0_ATVALID_MASK) /*!< ETF_ITATBCTR0                           */
#define ETF_ITATBCTR0_AFREADY_MASK               (0x01UL << ETF_ITATBCTR0_AFREADY_SHIFT)             /*!< ETF_ITATBCTR0: AFREADY Mask             */
#define ETF_ITATBCTR0_AFREADY_SHIFT              1                                                   /*!< ETF_ITATBCTR0: AFREADY Position         */
#define ETF_ITATBCTR0_AFREADY(x)                 (((uint32_t)(((uint32_t)(x))<<ETF_ITATBCTR0_AFREADY_SHIFT))&ETF_ITATBCTR0_AFREADY_MASK) /*!< ETF_ITATBCTR0                           */
#define ETF_ITATBCTR0_ATBYTES_MASK               (0x03UL << ETF_ITATBCTR0_ATBYTES_SHIFT)             /*!< ETF_ITATBCTR0: ATBYTES Mask             */
#define ETF_ITATBCTR0_ATBYTES_SHIFT              8                                                   /*!< ETF_ITATBCTR0: ATBYTES Position         */
#define ETF_ITATBCTR0_ATBYTES(x)                 (((uint32_t)(((uint32_t)(x))<<ETF_ITATBCTR0_ATBYTES_SHIFT))&ETF_ITATBCTR0_ATBYTES_MASK) /*!< ETF_ITATBCTR0                           */
/* ------- ITCTRL Bit Fields                        ------ */
#define ETF_ITCTRL_IntegrationMode_MASK          (0x01UL << ETF_ITCTRL_IntegrationMode_SHIFT)        /*!< ETF_ITCTRL: IntegrationMode Mask        */
#define ETF_ITCTRL_IntegrationMode_SHIFT         0                                                   /*!< ETF_ITCTRL: IntegrationMode Position    */
#define ETF_ITCTRL_IntegrationMode(x)            (((uint32_t)(((uint32_t)(x))<<ETF_ITCTRL_IntegrationMode_SHIFT))&ETF_ITCTRL_IntegrationMode_MASK) /*!< ETF_ITCTRL                              */
/* ------- CLAIMSET Bit Fields                      ------ */
#define ETF_CLAIMSET_CLAIMSET_MASK               (0x0FUL << ETF_CLAIMSET_CLAIMSET_SHIFT)             /*!< ETF_CLAIMSET: CLAIMSET Mask             */
#define ETF_CLAIMSET_CLAIMSET_SHIFT              0                                                   /*!< ETF_CLAIMSET: CLAIMSET Position         */
#define ETF_CLAIMSET_CLAIMSET(x)                 (((uint32_t)(((uint32_t)(x))<<ETF_CLAIMSET_CLAIMSET_SHIFT))&ETF_CLAIMSET_CLAIMSET_MASK) /*!< ETF_CLAIMSET                            */
/* ------- CLAIMCLR Bit Fields                      ------ */
#define ETF_CLAIMCLR_CLAIMCLR_MASK               (0x0FUL << ETF_CLAIMCLR_CLAIMCLR_SHIFT)             /*!< ETF_CLAIMCLR: CLAIMCLR Mask             */
#define ETF_CLAIMCLR_CLAIMCLR_SHIFT              0                                                   /*!< ETF_CLAIMCLR: CLAIMCLR Position         */
#define ETF_CLAIMCLR_CLAIMCLR(x)                 (((uint32_t)(((uint32_t)(x))<<ETF_CLAIMCLR_CLAIMCLR_SHIFT))&ETF_CLAIMCLR_CLAIMCLR_MASK) /*!< ETF_CLAIMCLR                            */
/* ------- LAR Bit Fields                           ------ */
#define ETF_LAR_WriteAccessCode_MASK             (0xFFFFFFFFUL << ETF_LAR_WriteAccessCode_SHIFT)     /*!< ETF_LAR: WriteAccessCode Mask           */
#define ETF_LAR_WriteAccessCode_SHIFT            0                                                   /*!< ETF_LAR: WriteAccessCode Position       */
#define ETF_LAR_WriteAccessCode(x)               (((uint32_t)(((uint32_t)(x))<<ETF_LAR_WriteAccessCode_SHIFT))&ETF_LAR_WriteAccessCode_MASK) /*!< ETF_LAR                                 */
/* ------- LSR Bit Fields                           ------ */
#define ETF_LSR_IMP_MASK                         (0x01UL << ETF_LSR_IMP_SHIFT)                       /*!< ETF_LSR: IMP Mask                       */
#define ETF_LSR_IMP_SHIFT                        0                                                   /*!< ETF_LSR: IMP Position                   */
#define ETF_LSR_IMP(x)                           (((uint32_t)(((uint32_t)(x))<<ETF_LSR_IMP_SHIFT))&ETF_LSR_IMP_MASK) /*!< ETF_LSR                                 */
#define ETF_LSR_STATUS_MASK                      (0x01UL << ETF_LSR_STATUS_SHIFT)                    /*!< ETF_LSR: STATUS Mask                    */
#define ETF_LSR_STATUS_SHIFT                     1                                                   /*!< ETF_LSR: STATUS Position                */
#define ETF_LSR_STATUS(x)                        (((uint32_t)(((uint32_t)(x))<<ETF_LSR_STATUS_SHIFT))&ETF_LSR_STATUS_MASK) /*!< ETF_LSR                                 */
#define ETF_LSR_s8BIT_MASK                       (0x01UL << ETF_LSR_s8BIT_SHIFT)                     /*!< ETF_LSR: s8BIT Mask                     */
#define ETF_LSR_s8BIT_SHIFT                      2                                                   /*!< ETF_LSR: s8BIT Position                 */
#define ETF_LSR_s8BIT(x)                         (((uint32_t)(((uint32_t)(x))<<ETF_LSR_s8BIT_SHIFT))&ETF_LSR_s8BIT_MASK) /*!< ETF_LSR                                 */
/* ------- AUTHSTATUS Bit Fields                    ------ */
#define ETF_AUTHSTATUS_AuthenticationStatus_MASK (0xFFUL << ETF_AUTHSTATUS_AuthenticationStatus_SHIFT) /*!< ETF_AUTHSTATUS: AuthenticationStatus Mask*/
#define ETF_AUTHSTATUS_AuthenticationStatus_SHIFT 0                                                  /*!< ETF_AUTHSTATUS: AuthenticationStatus Position*/
#define ETF_AUTHSTATUS_AuthenticationStatus(x)   (((uint32_t)(((uint32_t)(x))<<ETF_AUTHSTATUS_AuthenticationStatus_SHIFT))&ETF_AUTHSTATUS_AuthenticationStatus_MASK) /*!< ETF_AUTHSTATUS                          */
/* ------- DEVID Bit Fields                         ------ */
#define ETF_DEVID_PORTCOUNT_MASK                 (0x0FUL << ETF_DEVID_PORTCOUNT_SHIFT)               /*!< ETF_DEVID: PORTCOUNT Mask               */
#define ETF_DEVID_PORTCOUNT_SHIFT                0                                                   /*!< ETF_DEVID: PORTCOUNT Position           */
#define ETF_DEVID_PORTCOUNT(x)                   (((uint32_t)(((uint32_t)(x))<<ETF_DEVID_PORTCOUNT_SHIFT))&ETF_DEVID_PORTCOUNT_MASK) /*!< ETF_DEVID                               */
#define ETF_DEVID_PriorityScheme_MASK            (0x0FUL << ETF_DEVID_PriorityScheme_SHIFT)          /*!< ETF_DEVID: PriorityScheme Mask          */
#define ETF_DEVID_PriorityScheme_SHIFT           4                                                   /*!< ETF_DEVID: PriorityScheme Position      */
#define ETF_DEVID_PriorityScheme(x)              (((uint32_t)(((uint32_t)(x))<<ETF_DEVID_PriorityScheme_SHIFT))&ETF_DEVID_PriorityScheme_MASK) /*!< ETF_DEVID                               */
/* ------- DEVTYPE Bit Fields                       ------ */
#define ETF_DEVTYPE_MajorType_MASK               (0x0FUL << ETF_DEVTYPE_MajorType_SHIFT)             /*!< ETF_DEVTYPE: MajorType Mask             */
#define ETF_DEVTYPE_MajorType_SHIFT              0                                                   /*!< ETF_DEVTYPE: MajorType Position         */
#define ETF_DEVTYPE_MajorType(x)                 (((uint32_t)(((uint32_t)(x))<<ETF_DEVTYPE_MajorType_SHIFT))&ETF_DEVTYPE_MajorType_MASK) /*!< ETF_DEVTYPE                             */
#define ETF_DEVTYPE_SubType_MASK                 (0x0FUL << ETF_DEVTYPE_SubType_SHIFT)               /*!< ETF_DEVTYPE: SubType Mask               */
#define ETF_DEVTYPE_SubType_SHIFT                4                                                   /*!< ETF_DEVTYPE: SubType Position           */
#define ETF_DEVTYPE_SubType(x)                   (((uint32_t)(((uint32_t)(x))<<ETF_DEVTYPE_SubType_SHIFT))&ETF_DEVTYPE_SubType_MASK) /*!< ETF_DEVTYPE                             */
/* ------- PIDR4 Bit Fields                         ------ */
#define ETF_PIDR4_JEP106_MASK                    (0x0FUL << ETF_PIDR4_JEP106_SHIFT)                  /*!< ETF_PIDR4: JEP106 Mask                  */
#define ETF_PIDR4_JEP106_SHIFT                   0                                                   /*!< ETF_PIDR4: JEP106 Position              */
#define ETF_PIDR4_JEP106(x)                      (((uint32_t)(((uint32_t)(x))<<ETF_PIDR4_JEP106_SHIFT))&ETF_PIDR4_JEP106_MASK) /*!< ETF_PIDR4                               */
#define ETF_PIDR4_c4KB_MASK                      (0x0FUL << ETF_PIDR4_c4KB_SHIFT)                    /*!< ETF_PIDR4: c4KB Mask                    */
#define ETF_PIDR4_c4KB_SHIFT                     4                                                   /*!< ETF_PIDR4: c4KB Position                */
#define ETF_PIDR4_c4KB(x)                        (((uint32_t)(((uint32_t)(x))<<ETF_PIDR4_c4KB_SHIFT))&ETF_PIDR4_c4KB_MASK) /*!< ETF_PIDR4                               */
/* ------- PIDR5 Bit Fields                         ------ */
/* ------- PIDR6 Bit Fields                         ------ */
/* ------- PIDR7 Bit Fields                         ------ */
/* ------- PIDR0 Bit Fields                         ------ */
#define ETF_PIDR0_PartNumber_MASK                (0xFFUL << ETF_PIDR0_PartNumber_SHIFT)              /*!< ETF_PIDR0: PartNumber Mask              */
#define ETF_PIDR0_PartNumber_SHIFT               0                                                   /*!< ETF_PIDR0: PartNumber Position          */
#define ETF_PIDR0_PartNumber(x)                  (((uint32_t)(((uint32_t)(x))<<ETF_PIDR0_PartNumber_SHIFT))&ETF_PIDR0_PartNumber_MASK) /*!< ETF_PIDR0                               */
/* ------- PIDR1 Bit Fields                         ------ */
#define ETF_PIDR1_PartNumber_MASK                (0x0FUL << ETF_PIDR1_PartNumber_SHIFT)              /*!< ETF_PIDR1: PartNumber Mask              */
#define ETF_PIDR1_PartNumber_SHIFT               0                                                   /*!< ETF_PIDR1: PartNumber Position          */
#define ETF_PIDR1_PartNumber(x)                  (((uint32_t)(((uint32_t)(x))<<ETF_PIDR1_PartNumber_SHIFT))&ETF_PIDR1_PartNumber_MASK) /*!< ETF_PIDR1                               */
#define ETF_PIDR1_JEP106_identity_code_MASK      (0x0FUL << ETF_PIDR1_JEP106_identity_code_SHIFT)    /*!< ETF_PIDR1: JEP106_identity_code Mask    */
#define ETF_PIDR1_JEP106_identity_code_SHIFT     4                                                   /*!< ETF_PIDR1: JEP106_identity_code Position*/
#define ETF_PIDR1_JEP106_identity_code(x)        (((uint32_t)(((uint32_t)(x))<<ETF_PIDR1_JEP106_identity_code_SHIFT))&ETF_PIDR1_JEP106_identity_code_MASK) /*!< ETF_PIDR1                               */
/* ------- PIDR2 Bit Fields                         ------ */
#define ETF_PIDR2_JEP106_identity_code_MASK      (0x07UL << ETF_PIDR2_JEP106_identity_code_SHIFT)    /*!< ETF_PIDR2: JEP106_identity_code Mask    */
#define ETF_PIDR2_JEP106_identity_code_SHIFT     0                                                   /*!< ETF_PIDR2: JEP106_identity_code Position*/
#define ETF_PIDR2_JEP106_identity_code(x)        (((uint32_t)(((uint32_t)(x))<<ETF_PIDR2_JEP106_identity_code_SHIFT))&ETF_PIDR2_JEP106_identity_code_MASK) /*!< ETF_PIDR2                               */
#define ETF_PIDR2_Revision_MASK                  (0x0FUL << ETF_PIDR2_Revision_SHIFT)                /*!< ETF_PIDR2: Revision Mask                */
#define ETF_PIDR2_Revision_SHIFT                 4                                                   /*!< ETF_PIDR2: Revision Position            */
#define ETF_PIDR2_Revision(x)                    (((uint32_t)(((uint32_t)(x))<<ETF_PIDR2_Revision_SHIFT))&ETF_PIDR2_Revision_MASK) /*!< ETF_PIDR2                               */
/* ------- PIDR3 Bit Fields                         ------ */
#define ETF_PIDR3_CustomerModified_MASK          (0x0FUL << ETF_PIDR3_CustomerModified_SHIFT)        /*!< ETF_PIDR3: CustomerModified Mask        */
#define ETF_PIDR3_CustomerModified_SHIFT         0                                                   /*!< ETF_PIDR3: CustomerModified Position    */
#define ETF_PIDR3_CustomerModified(x)            (((uint32_t)(((uint32_t)(x))<<ETF_PIDR3_CustomerModified_SHIFT))&ETF_PIDR3_CustomerModified_MASK) /*!< ETF_PIDR3                               */
#define ETF_PIDR3_RevAnd_MASK                    (0x0FUL << ETF_PIDR3_RevAnd_SHIFT)                  /*!< ETF_PIDR3: RevAnd Mask                  */
#define ETF_PIDR3_RevAnd_SHIFT                   4                                                   /*!< ETF_PIDR3: RevAnd Position              */
#define ETF_PIDR3_RevAnd(x)                      (((uint32_t)(((uint32_t)(x))<<ETF_PIDR3_RevAnd_SHIFT))&ETF_PIDR3_RevAnd_MASK) /*!< ETF_PIDR3                               */
/* ------- CIDR0 Bit Fields                         ------ */
#define ETF_CIDR0_Preamble_MASK                  (0xFFUL << ETF_CIDR0_Preamble_SHIFT)                /*!< ETF_CIDR0: Preamble Mask                */
#define ETF_CIDR0_Preamble_SHIFT                 0                                                   /*!< ETF_CIDR0: Preamble Position            */
#define ETF_CIDR0_Preamble(x)                    (((uint32_t)(((uint32_t)(x))<<ETF_CIDR0_Preamble_SHIFT))&ETF_CIDR0_Preamble_MASK) /*!< ETF_CIDR0                               */
/* ------- CIDR1 Bit Fields                         ------ */
#define ETF_CIDR1_Preamble_MASK                  (0x0FUL << ETF_CIDR1_Preamble_SHIFT)                /*!< ETF_CIDR1: Preamble Mask                */
#define ETF_CIDR1_Preamble_SHIFT                 0                                                   /*!< ETF_CIDR1: Preamble Position            */
#define ETF_CIDR1_Preamble(x)                    (((uint32_t)(((uint32_t)(x))<<ETF_CIDR1_Preamble_SHIFT))&ETF_CIDR1_Preamble_MASK) /*!< ETF_CIDR1                               */
#define ETF_CIDR1_ComponentClass_MASK            (0x0FUL << ETF_CIDR1_ComponentClass_SHIFT)          /*!< ETF_CIDR1: ComponentClass Mask          */
#define ETF_CIDR1_ComponentClass_SHIFT           4                                                   /*!< ETF_CIDR1: ComponentClass Position      */
#define ETF_CIDR1_ComponentClass(x)              (((uint32_t)(((uint32_t)(x))<<ETF_CIDR1_ComponentClass_SHIFT))&ETF_CIDR1_ComponentClass_MASK) /*!< ETF_CIDR1                               */
/* ------- CIDR2 Bit Fields                         ------ */
#define ETF_CIDR2_Preamble_MASK                  (0xFFUL << ETF_CIDR2_Preamble_SHIFT)                /*!< ETF_CIDR2: Preamble Mask                */
#define ETF_CIDR2_Preamble_SHIFT                 0                                                   /*!< ETF_CIDR2: Preamble Position            */
#define ETF_CIDR2_Preamble(x)                    (((uint32_t)(((uint32_t)(x))<<ETF_CIDR2_Preamble_SHIFT))&ETF_CIDR2_Preamble_MASK) /*!< ETF_CIDR2                               */
/* ------- CIDR3 Bit Fields                         ------ */
#define ETF_CIDR3_Preamble_MASK                  (0xFFUL << ETF_CIDR3_Preamble_SHIFT)                /*!< ETF_CIDR3: Preamble Mask                */
#define ETF_CIDR3_Preamble_SHIFT                 0                                                   /*!< ETF_CIDR3: Preamble Position            */
#define ETF_CIDR3_Preamble(x)                    (((uint32_t)(((uint32_t)(x))<<ETF_CIDR3_Preamble_SHIFT))&ETF_CIDR3_Preamble_MASK) /*!< ETF_CIDR3                               */
/**
 * @} */ /* End group ETF_Register_Masks_GROUP 
 */

/* ETF - Peripheral instance base addresses */
#define ETF_BasePtr                    0xE0043000UL //!< Peripheral base address
#define ETF                            ((ETF_Type *) ETF_BasePtr) //!< Freescale base pointer
#define ETF_BASE_PTR                   (ETF) //!< Freescale style base pointer
/**
 * @} */ /* End group ETF_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup EWM_Peripheral_access_layer_GROUP EWM Peripheral Access Layer
* @brief C Struct for EWM
* @{
*/

/* ================================================================================ */
/* ================           EWM (file:EWM_2)                     ================ */
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
#define EWM_CTRL_EWMEN_MASK                      (0x01UL << EWM_CTRL_EWMEN_SHIFT)                    /*!< EWM_CTRL: EWMEN Mask                    */
#define EWM_CTRL_EWMEN_SHIFT                     0                                                   /*!< EWM_CTRL: EWMEN Position                */
#define EWM_CTRL_EWMEN(x)                        (((uint8_t)(((uint8_t)(x))<<EWM_CTRL_EWMEN_SHIFT))&EWM_CTRL_EWMEN_MASK) /*!< EWM_CTRL                                */
#define EWM_CTRL_ASSIN_MASK                      (0x01UL << EWM_CTRL_ASSIN_SHIFT)                    /*!< EWM_CTRL: ASSIN Mask                    */
#define EWM_CTRL_ASSIN_SHIFT                     1                                                   /*!< EWM_CTRL: ASSIN Position                */
#define EWM_CTRL_ASSIN(x)                        (((uint8_t)(((uint8_t)(x))<<EWM_CTRL_ASSIN_SHIFT))&EWM_CTRL_ASSIN_MASK) /*!< EWM_CTRL                                */
#define EWM_CTRL_INEN_MASK                       (0x01UL << EWM_CTRL_INEN_SHIFT)                     /*!< EWM_CTRL: INEN Mask                     */
#define EWM_CTRL_INEN_SHIFT                      2                                                   /*!< EWM_CTRL: INEN Position                 */
#define EWM_CTRL_INEN(x)                         (((uint8_t)(((uint8_t)(x))<<EWM_CTRL_INEN_SHIFT))&EWM_CTRL_INEN_MASK) /*!< EWM_CTRL                                */
#define EWM_CTRL_INTEN_MASK                      (0x01UL << EWM_CTRL_INTEN_SHIFT)                    /*!< EWM_CTRL: INTEN Mask                    */
#define EWM_CTRL_INTEN_SHIFT                     3                                                   /*!< EWM_CTRL: INTEN Position                */
#define EWM_CTRL_INTEN(x)                        (((uint8_t)(((uint8_t)(x))<<EWM_CTRL_INTEN_SHIFT))&EWM_CTRL_INTEN_MASK) /*!< EWM_CTRL                                */
/* ------- SERV Bit Fields                          ------ */
#define EWM_SERV_SERVICE_MASK                    (0xFFUL << EWM_SERV_SERVICE_SHIFT)                  /*!< EWM_SERV: SERVICE Mask                  */
#define EWM_SERV_SERVICE_SHIFT                   0                                                   /*!< EWM_SERV: SERVICE Position              */
#define EWM_SERV_SERVICE(x)                      (((uint8_t)(((uint8_t)(x))<<EWM_SERV_SERVICE_SHIFT))&EWM_SERV_SERVICE_MASK) /*!< EWM_SERV                                */
/* ------- CMPL Bit Fields                          ------ */
#define EWM_CMPL_COMPAREL_MASK                   (0xFFUL << EWM_CMPL_COMPAREL_SHIFT)                 /*!< EWM_CMPL: COMPAREL Mask                 */
#define EWM_CMPL_COMPAREL_SHIFT                  0                                                   /*!< EWM_CMPL: COMPAREL Position             */
#define EWM_CMPL_COMPAREL(x)                     (((uint8_t)(((uint8_t)(x))<<EWM_CMPL_COMPAREL_SHIFT))&EWM_CMPL_COMPAREL_MASK) /*!< EWM_CMPL                                */
/* ------- CMPH Bit Fields                          ------ */
#define EWM_CMPH_COMPAREH_MASK                   (0xFFUL << EWM_CMPH_COMPAREH_SHIFT)                 /*!< EWM_CMPH: COMPAREH Mask                 */
#define EWM_CMPH_COMPAREH_SHIFT                  0                                                   /*!< EWM_CMPH: COMPAREH Position             */
#define EWM_CMPH_COMPAREH(x)                     (((uint8_t)(((uint8_t)(x))<<EWM_CMPH_COMPAREH_SHIFT))&EWM_CMPH_COMPAREH_MASK) /*!< EWM_CMPH                                */
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
* @addtogroup FMC_Peripheral_access_layer_GROUP FMC Peripheral Access Layer
* @brief C Struct for FMC
* @{
*/

/* ================================================================================ */
/* ================           FMC (file:FMC_MK10D7)                ================ */
/* ================================================================================ */

/**
 * @brief Flash Memory Controller
 */
/**
* @addtogroup FMC_structs_GROUP FMC struct
* @brief Struct for FMC
* @{
*/
typedef struct {                                /*       FMC Structure                                                */
   __IO uint32_t  PFAPR;                        /**< 0000: Flash Access Protection Register                             */
   __IO uint32_t  PFB0CR;                       /**< 0004: Flash Bank 0 Control Register                                */
   __IO uint32_t  PFB1CR;                       /**< 0008: Flash Bank 1 Control Register                                */
   __I  uint32_t  RESERVED0[61];               
   struct {
      __IO uint32_t  S0;                        /**< 0100: Cache Tag Storage                                            */
      __IO uint32_t  S1;                        /**< 0104: Cache Tag Storage                                            */
      __IO uint32_t  S2;                        /**< 0108: Cache Tag Storage                                            */
      __IO uint32_t  S3;                        /**< 010C: Cache Tag Storage                                            */
      __IO uint32_t  S4;                        /**< 0110: Cache Tag Storage                                            */
      __IO uint32_t  S5;                        /**< 0114: Cache Tag Storage                                            */
      __IO uint32_t  S6;                        /**< 0118: Cache Tag Storage                                            */
      __IO uint32_t  S7;                        /**< 011C: Cache Tag Storage                                            */
   } TAGVDW[4];                                 /**< 0100: (cluster: size=0x0080, 128)                                  */
   __I  uint32_t  RESERVED1[32];               
   struct {
      __IO uint32_t  S0U;                       /**< 0200: Cache Data Storage (upper word)                              */
      __IO uint32_t  S0L;                       /**< 0204: Cache Data Storage (lower word)                              */
      __IO uint32_t  S1U;                       /**< 0208: Cache Data Storage (upper word)                              */
      __IO uint32_t  S1L;                       /**< 020C: Cache Data Storage (lower word)                              */
      __IO uint32_t  S2U;                       /**< 0210: Cache Data Storage (upper word)                              */
      __IO uint32_t  S2L;                       /**< 0214: Cache Data Storage (lower word)                              */
      __IO uint32_t  S3U;                       /**< 0218: Cache Data Storage (upper word)                              */
      __IO uint32_t  S3L;                       /**< 021C: Cache Data Storage (lower word)                              */
      __IO uint32_t  S4U;                       /**< 0220: Cache Data Storage (upper word)                              */
      __IO uint32_t  S4L;                       /**< 0224: Cache Data Storage (lower word)                              */
      __IO uint32_t  S5U;                       /**< 0228: Cache Data Storage (upper word)                              */
      __IO uint32_t  S5L;                       /**< 022C: Cache Data Storage (lower word)                              */
      __IO uint32_t  S6U;                       /**< 0230: Cache Data Storage (upper word)                              */
      __IO uint32_t  S6L;                       /**< 0234: Cache Data Storage (lower word)                              */
      __IO uint32_t  S7U;                       /**< 0238: Cache Data Storage (upper word)                              */
      __IO uint32_t  S7L;                       /**< 023C: Cache Data Storage (lower word)                              */
   } DATAW[4];                                  /**< 0200: (cluster: size=0x0100, 256)                                  */
} FMC_Type;

/**
 * @} */ /* End group FMC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FMC_Register_Masks_GROUP FMC Register Masks
* @brief Register Masks for FMC
* @{
*/
/* ------- PFAPR Bit Fields                         ------ */
#define FMC_PFAPR_M0AP_MASK                      (0x03UL << FMC_PFAPR_M0AP_SHIFT)                    /*!< FMC_PFAPR: M0AP Mask                    */
#define FMC_PFAPR_M0AP_SHIFT                     0                                                   /*!< FMC_PFAPR: M0AP Position                */
#define FMC_PFAPR_M0AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M0AP_SHIFT))&FMC_PFAPR_M0AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M1AP_MASK                      (0x03UL << FMC_PFAPR_M1AP_SHIFT)                    /*!< FMC_PFAPR: M1AP Mask                    */
#define FMC_PFAPR_M1AP_SHIFT                     2                                                   /*!< FMC_PFAPR: M1AP Position                */
#define FMC_PFAPR_M1AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M1AP_SHIFT))&FMC_PFAPR_M1AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M2AP_MASK                      (0x03UL << FMC_PFAPR_M2AP_SHIFT)                    /*!< FMC_PFAPR: M2AP Mask                    */
#define FMC_PFAPR_M2AP_SHIFT                     4                                                   /*!< FMC_PFAPR: M2AP Position                */
#define FMC_PFAPR_M2AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M2AP_SHIFT))&FMC_PFAPR_M2AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M3AP_MASK                      (0x03UL << FMC_PFAPR_M3AP_SHIFT)                    /*!< FMC_PFAPR: M3AP Mask                    */
#define FMC_PFAPR_M3AP_SHIFT                     6                                                   /*!< FMC_PFAPR: M3AP Position                */
#define FMC_PFAPR_M3AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M3AP_SHIFT))&FMC_PFAPR_M3AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M4AP_MASK                      (0x03UL << FMC_PFAPR_M4AP_SHIFT)                    /*!< FMC_PFAPR: M4AP Mask                    */
#define FMC_PFAPR_M4AP_SHIFT                     8                                                   /*!< FMC_PFAPR: M4AP Position                */
#define FMC_PFAPR_M4AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M4AP_SHIFT))&FMC_PFAPR_M4AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M5AP_MASK                      (0x03UL << FMC_PFAPR_M5AP_SHIFT)                    /*!< FMC_PFAPR: M5AP Mask                    */
#define FMC_PFAPR_M5AP_SHIFT                     10                                                  /*!< FMC_PFAPR: M5AP Position                */
#define FMC_PFAPR_M5AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M5AP_SHIFT))&FMC_PFAPR_M5AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M6AP_MASK                      (0x03UL << FMC_PFAPR_M6AP_SHIFT)                    /*!< FMC_PFAPR: M6AP Mask                    */
#define FMC_PFAPR_M6AP_SHIFT                     12                                                  /*!< FMC_PFAPR: M6AP Position                */
#define FMC_PFAPR_M6AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M6AP_SHIFT))&FMC_PFAPR_M6AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M7AP_MASK                      (0x03UL << FMC_PFAPR_M7AP_SHIFT)                    /*!< FMC_PFAPR: M7AP Mask                    */
#define FMC_PFAPR_M7AP_SHIFT                     14                                                  /*!< FMC_PFAPR: M7AP Position                */
#define FMC_PFAPR_M7AP(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M7AP_SHIFT))&FMC_PFAPR_M7AP_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M0PFD_MASK                     (0x01UL << FMC_PFAPR_M0PFD_SHIFT)                   /*!< FMC_PFAPR: M0PFD Mask                   */
#define FMC_PFAPR_M0PFD_SHIFT                    16                                                  /*!< FMC_PFAPR: M0PFD Position               */
#define FMC_PFAPR_M0PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M0PFD_SHIFT))&FMC_PFAPR_M0PFD_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M1PFD_MASK                     (0x01UL << FMC_PFAPR_M1PFD_SHIFT)                   /*!< FMC_PFAPR: M1PFD Mask                   */
#define FMC_PFAPR_M1PFD_SHIFT                    17                                                  /*!< FMC_PFAPR: M1PFD Position               */
#define FMC_PFAPR_M1PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M1PFD_SHIFT))&FMC_PFAPR_M1PFD_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M2PFD_MASK                     (0x01UL << FMC_PFAPR_M2PFD_SHIFT)                   /*!< FMC_PFAPR: M2PFD Mask                   */
#define FMC_PFAPR_M2PFD_SHIFT                    18                                                  /*!< FMC_PFAPR: M2PFD Position               */
#define FMC_PFAPR_M2PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M2PFD_SHIFT))&FMC_PFAPR_M2PFD_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M3PFD_MASK                     (0x01UL << FMC_PFAPR_M3PFD_SHIFT)                   /*!< FMC_PFAPR: M3PFD Mask                   */
#define FMC_PFAPR_M3PFD_SHIFT                    19                                                  /*!< FMC_PFAPR: M3PFD Position               */
#define FMC_PFAPR_M3PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M3PFD_SHIFT))&FMC_PFAPR_M3PFD_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M4PFD_MASK                     (0x01UL << FMC_PFAPR_M4PFD_SHIFT)                   /*!< FMC_PFAPR: M4PFD Mask                   */
#define FMC_PFAPR_M4PFD_SHIFT                    20                                                  /*!< FMC_PFAPR: M4PFD Position               */
#define FMC_PFAPR_M4PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M4PFD_SHIFT))&FMC_PFAPR_M4PFD_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M5PFD_MASK                     (0x01UL << FMC_PFAPR_M5PFD_SHIFT)                   /*!< FMC_PFAPR: M5PFD Mask                   */
#define FMC_PFAPR_M5PFD_SHIFT                    21                                                  /*!< FMC_PFAPR: M5PFD Position               */
#define FMC_PFAPR_M5PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M5PFD_SHIFT))&FMC_PFAPR_M5PFD_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M6PFD_MASK                     (0x01UL << FMC_PFAPR_M6PFD_SHIFT)                   /*!< FMC_PFAPR: M6PFD Mask                   */
#define FMC_PFAPR_M6PFD_SHIFT                    22                                                  /*!< FMC_PFAPR: M6PFD Position               */
#define FMC_PFAPR_M6PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M6PFD_SHIFT))&FMC_PFAPR_M6PFD_MASK) /*!< FMC_PFAPR                               */
#define FMC_PFAPR_M7PFD_MASK                     (0x01UL << FMC_PFAPR_M7PFD_SHIFT)                   /*!< FMC_PFAPR: M7PFD Mask                   */
#define FMC_PFAPR_M7PFD_SHIFT                    23                                                  /*!< FMC_PFAPR: M7PFD Position               */
#define FMC_PFAPR_M7PFD(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFAPR_M7PFD_SHIFT))&FMC_PFAPR_M7PFD_MASK) /*!< FMC_PFAPR                               */
/* ------- PFB0CR Bit Fields                        ------ */
#define FMC_PFB0CR_B0SEBE_MASK                   (0x01UL << FMC_PFB0CR_B0SEBE_SHIFT)                 /*!< FMC_PFB0CR: B0SEBE Mask                 */
#define FMC_PFB0CR_B0SEBE_SHIFT                  0                                                   /*!< FMC_PFB0CR: B0SEBE Position             */
#define FMC_PFB0CR_B0SEBE(x)                     (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0SEBE_SHIFT))&FMC_PFB0CR_B0SEBE_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_B0IPE_MASK                    (0x01UL << FMC_PFB0CR_B0IPE_SHIFT)                  /*!< FMC_PFB0CR: B0IPE Mask                  */
#define FMC_PFB0CR_B0IPE_SHIFT                   1                                                   /*!< FMC_PFB0CR: B0IPE Position              */
#define FMC_PFB0CR_B0IPE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0IPE_SHIFT))&FMC_PFB0CR_B0IPE_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_B0DPE_MASK                    (0x01UL << FMC_PFB0CR_B0DPE_SHIFT)                  /*!< FMC_PFB0CR: B0DPE Mask                  */
#define FMC_PFB0CR_B0DPE_SHIFT                   2                                                   /*!< FMC_PFB0CR: B0DPE Position              */
#define FMC_PFB0CR_B0DPE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0DPE_SHIFT))&FMC_PFB0CR_B0DPE_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_B0ICE_MASK                    (0x01UL << FMC_PFB0CR_B0ICE_SHIFT)                  /*!< FMC_PFB0CR: B0ICE Mask                  */
#define FMC_PFB0CR_B0ICE_SHIFT                   3                                                   /*!< FMC_PFB0CR: B0ICE Position              */
#define FMC_PFB0CR_B0ICE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0ICE_SHIFT))&FMC_PFB0CR_B0ICE_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_B0DCE_MASK                    (0x01UL << FMC_PFB0CR_B0DCE_SHIFT)                  /*!< FMC_PFB0CR: B0DCE Mask                  */
#define FMC_PFB0CR_B0DCE_SHIFT                   4                                                   /*!< FMC_PFB0CR: B0DCE Position              */
#define FMC_PFB0CR_B0DCE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0DCE_SHIFT))&FMC_PFB0CR_B0DCE_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_CRC_MASK                      (0x07UL << FMC_PFB0CR_CRC_SHIFT)                    /*!< FMC_PFB0CR: CRC Mask                    */
#define FMC_PFB0CR_CRC_SHIFT                     5                                                   /*!< FMC_PFB0CR: CRC Position                */
#define FMC_PFB0CR_CRC(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_CRC_SHIFT))&FMC_PFB0CR_CRC_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_B0MW_MASK                     (0x03UL << FMC_PFB0CR_B0MW_SHIFT)                   /*!< FMC_PFB0CR: B0MW Mask                   */
#define FMC_PFB0CR_B0MW_SHIFT                    17                                                  /*!< FMC_PFB0CR: B0MW Position               */
#define FMC_PFB0CR_B0MW(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0MW_SHIFT))&FMC_PFB0CR_B0MW_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_S_B_INV_MASK                  (0x01UL << FMC_PFB0CR_S_B_INV_SHIFT)                /*!< FMC_PFB0CR: S_B_INV Mask                */
#define FMC_PFB0CR_S_B_INV_SHIFT                 19                                                  /*!< FMC_PFB0CR: S_B_INV Position            */
#define FMC_PFB0CR_S_B_INV(x)                    (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_S_B_INV_SHIFT))&FMC_PFB0CR_S_B_INV_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_CINV_WAY_MASK                 (0x0FUL << FMC_PFB0CR_CINV_WAY_SHIFT)               /*!< FMC_PFB0CR: CINV_WAY Mask               */
#define FMC_PFB0CR_CINV_WAY_SHIFT                20                                                  /*!< FMC_PFB0CR: CINV_WAY Position           */
#define FMC_PFB0CR_CINV_WAY(x)                   (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_CINV_WAY_SHIFT))&FMC_PFB0CR_CINV_WAY_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_CLCK_WAY_MASK                 (0x0FUL << FMC_PFB0CR_CLCK_WAY_SHIFT)               /*!< FMC_PFB0CR: CLCK_WAY Mask               */
#define FMC_PFB0CR_CLCK_WAY_SHIFT                24                                                  /*!< FMC_PFB0CR: CLCK_WAY Position           */
#define FMC_PFB0CR_CLCK_WAY(x)                   (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_CLCK_WAY_SHIFT))&FMC_PFB0CR_CLCK_WAY_MASK) /*!< FMC_PFB0CR                              */
#define FMC_PFB0CR_B0RWSC_MASK                   (0x0FUL << FMC_PFB0CR_B0RWSC_SHIFT)                 /*!< FMC_PFB0CR: B0RWSC Mask                 */
#define FMC_PFB0CR_B0RWSC_SHIFT                  28                                                  /*!< FMC_PFB0CR: B0RWSC Position             */
#define FMC_PFB0CR_B0RWSC(x)                     (((uint32_t)(((uint32_t)(x))<<FMC_PFB0CR_B0RWSC_SHIFT))&FMC_PFB0CR_B0RWSC_MASK) /*!< FMC_PFB0CR                              */
/* ------- PFB1CR Bit Fields                        ------ */
#define FMC_PFB1CR_B1SEBE_MASK                   (0x01UL << FMC_PFB1CR_B1SEBE_SHIFT)                 /*!< FMC_PFB1CR: B1SEBE Mask                 */
#define FMC_PFB1CR_B1SEBE_SHIFT                  0                                                   /*!< FMC_PFB1CR: B1SEBE Position             */
#define FMC_PFB1CR_B1SEBE(x)                     (((uint32_t)(((uint32_t)(x))<<FMC_PFB1CR_B1SEBE_SHIFT))&FMC_PFB1CR_B1SEBE_MASK) /*!< FMC_PFB1CR                              */
#define FMC_PFB1CR_B1IPE_MASK                    (0x01UL << FMC_PFB1CR_B1IPE_SHIFT)                  /*!< FMC_PFB1CR: B1IPE Mask                  */
#define FMC_PFB1CR_B1IPE_SHIFT                   1                                                   /*!< FMC_PFB1CR: B1IPE Position              */
#define FMC_PFB1CR_B1IPE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB1CR_B1IPE_SHIFT))&FMC_PFB1CR_B1IPE_MASK) /*!< FMC_PFB1CR                              */
#define FMC_PFB1CR_B1DPE_MASK                    (0x01UL << FMC_PFB1CR_B1DPE_SHIFT)                  /*!< FMC_PFB1CR: B1DPE Mask                  */
#define FMC_PFB1CR_B1DPE_SHIFT                   2                                                   /*!< FMC_PFB1CR: B1DPE Position              */
#define FMC_PFB1CR_B1DPE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB1CR_B1DPE_SHIFT))&FMC_PFB1CR_B1DPE_MASK) /*!< FMC_PFB1CR                              */
#define FMC_PFB1CR_B1ICE_MASK                    (0x01UL << FMC_PFB1CR_B1ICE_SHIFT)                  /*!< FMC_PFB1CR: B1ICE Mask                  */
#define FMC_PFB1CR_B1ICE_SHIFT                   3                                                   /*!< FMC_PFB1CR: B1ICE Position              */
#define FMC_PFB1CR_B1ICE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB1CR_B1ICE_SHIFT))&FMC_PFB1CR_B1ICE_MASK) /*!< FMC_PFB1CR                              */
#define FMC_PFB1CR_B1DCE_MASK                    (0x01UL << FMC_PFB1CR_B1DCE_SHIFT)                  /*!< FMC_PFB1CR: B1DCE Mask                  */
#define FMC_PFB1CR_B1DCE_SHIFT                   4                                                   /*!< FMC_PFB1CR: B1DCE Position              */
#define FMC_PFB1CR_B1DCE(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_PFB1CR_B1DCE_SHIFT))&FMC_PFB1CR_B1DCE_MASK) /*!< FMC_PFB1CR                              */
#define FMC_PFB1CR_B1MW_MASK                     (0x03UL << FMC_PFB1CR_B1MW_SHIFT)                   /*!< FMC_PFB1CR: B1MW Mask                   */
#define FMC_PFB1CR_B1MW_SHIFT                    17                                                  /*!< FMC_PFB1CR: B1MW Position               */
#define FMC_PFB1CR_B1MW(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_PFB1CR_B1MW_SHIFT))&FMC_PFB1CR_B1MW_MASK) /*!< FMC_PFB1CR                              */
#define FMC_PFB1CR_B1RWSC_MASK                   (0x0FUL << FMC_PFB1CR_B1RWSC_SHIFT)                 /*!< FMC_PFB1CR: B1RWSC Mask                 */
#define FMC_PFB1CR_B1RWSC_SHIFT                  28                                                  /*!< FMC_PFB1CR: B1RWSC Position             */
#define FMC_PFB1CR_B1RWSC(x)                     (((uint32_t)(((uint32_t)(x))<<FMC_PFB1CR_B1RWSC_SHIFT))&FMC_PFB1CR_B1RWSC_MASK) /*!< FMC_PFB1CR                              */
/* ------- S0 Bit Fields                            ------ */
#define FMC_TAGVD0_valid_MASK                    (0x01UL << FMC_TAGVD0_valid_SHIFT)                  /*!< FMC_TAGVD0: valid Mask                  */
#define FMC_TAGVD0_valid_SHIFT                   0                                                   /*!< FMC_TAGVD0: valid Position              */
#define FMC_TAGVD0_valid(x)                      (((uint32_t)(((uint32_t)(x))<<FMC_TAGVD0_valid_SHIFT))&FMC_TAGVD0_valid_MASK) /*!< FMC_TAGVD0                              */
#define FMC_TAGVD0_tag_MASK                      (0x1FFFUL << FMC_TAGVD0_tag_SHIFT)                  /*!< FMC_TAGVD0: tag Mask                    */
#define FMC_TAGVD0_tag_SHIFT                     6                                                   /*!< FMC_TAGVD0: tag Position                */
#define FMC_TAGVD0_tag(x)                        (((uint32_t)(((uint32_t)(x))<<FMC_TAGVD0_tag_SHIFT))&FMC_TAGVD0_tag_MASK) /*!< FMC_TAGVD0                              */
/* ------- S0U Bit Fields                           ------ */
#define FMC_DATAWU_data_MASK                     (0xFFFFFFFFUL << FMC_DATAWU_data_SHIFT)             /*!< FMC_DATAWU: data Mask                   */
#define FMC_DATAWU_data_SHIFT                    0                                                   /*!< FMC_DATAWU: data Position               */
#define FMC_DATAWU_data(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_DATAWU_data_SHIFT))&FMC_DATAWU_data_MASK) /*!< FMC_DATAWU                              */
/* ------- S0L Bit Fields                           ------ */
#define FMC_DATAWL_data_MASK                     (0xFFFFFFFFUL << FMC_DATAWL_data_SHIFT)             /*!< FMC_DATAWL: data Mask                   */
#define FMC_DATAWL_data_SHIFT                    0                                                   /*!< FMC_DATAWL: data Position               */
#define FMC_DATAWL_data(x)                       (((uint32_t)(((uint32_t)(x))<<FMC_DATAWL_data_SHIFT))&FMC_DATAWL_data_MASK) /*!< FMC_DATAWL                              */
/**
 * @} */ /* End group FMC_Register_Masks_GROUP 
 */

/* FMC - Peripheral instance base addresses */
#define FMC_BasePtr                    0x4001F000UL //!< Peripheral base address
#define FMC                            ((FMC_Type *) FMC_BasePtr) //!< Freescale base pointer
#define FMC_BASE_PTR                   (FMC) //!< Freescale style base pointer
/**
 * @} */ /* End group FMC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FPB_Peripheral_access_layer_GROUP FPB Peripheral Access Layer
* @brief C Struct for FPB
* @{
*/

/* ================================================================================ */
/* ================           FPB (file:FPB)                       ================ */
/* ================================================================================ */

/**
 * @brief Flash Patch and Breakpoint Unit
 */
/**
* @addtogroup FPB_structs_GROUP FPB struct
* @brief Struct for FPB
* @{
*/
typedef struct {                                /*       FPB Structure                                                */
   __IO uint32_t  CTRL;                         /**< 0000: FlashPatch Control Register                                  */
   __IO uint32_t  REMAP;                        /**< 0004: FlashPatch Remap Register                                    */
   __IO uint32_t  COMP[8];                      /**< 0008: FlashPatch Comparator Register                               */
   __I  uint32_t  RESERVED0[1002];             
   __I  uint32_t  PID4;                         /**< 0FD0: Peripheral Identification Register 4                         */
   __I  uint32_t  PID5;                         /**< 0FD4: Peripheral Identification Register 5                         */
   __I  uint32_t  PID6;                         /**< 0FD8: Peripheral Identification Register 6                         */
   __I  uint32_t  PID7;                         /**< 0FDC: Peripheral Identification Register 7                         */
   __I  uint32_t  PID0;                         /**< 0FE0: Peripheral Identification Register 0                         */
   __I  uint32_t  PID1;                         /**< 0FE4: Peripheral Identification Register 1                         */
   __I  uint32_t  PID2;                         /**< 0FE8: Peripheral Identification Register 2                         */
   __I  uint32_t  PID3;                         /**< 0FEC: Peripheral Identification Register 3                         */
   __I  uint32_t  CID0;                         /**< 0FF0: Component Identification Register 0                          */
   __I  uint32_t  CID1;                         /**< 0FF4: Component Identification Register 1                          */
   __I  uint32_t  CID2;                         /**< 0FF8: Component Identification Register 2                          */
   __I  uint32_t  CID3;                         /**< 0FFC: Component Identification Register 3                          */
} FPB_Type;

/**
 * @} */ /* End group FPB_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FPB' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FPB_Register_Masks_GROUP FPB Register Masks
* @brief Register Masks for FPB
* @{
*/
/* ------- CTRL Bit Fields                          ------ */
#define FPB_CTRL_ENABLE_MASK                     (0x01UL << FPB_CTRL_ENABLE_SHIFT)                   /*!< FPB_CTRL: ENABLE Mask                   */
#define FPB_CTRL_ENABLE_SHIFT                    0                                                   /*!< FPB_CTRL: ENABLE Position               */
#define FPB_CTRL_ENABLE(x)                       (((uint32_t)(((uint32_t)(x))<<FPB_CTRL_ENABLE_SHIFT))&FPB_CTRL_ENABLE_MASK) /*!< FPB_CTRL                                */
#define FPB_CTRL_KEY_MASK                        (0x01UL << FPB_CTRL_KEY_SHIFT)                      /*!< FPB_CTRL: KEY Mask                      */
#define FPB_CTRL_KEY_SHIFT                       1                                                   /*!< FPB_CTRL: KEY Position                  */
#define FPB_CTRL_KEY(x)                          (((uint32_t)(((uint32_t)(x))<<FPB_CTRL_KEY_SHIFT))&FPB_CTRL_KEY_MASK) /*!< FPB_CTRL                                */
#define FPB_CTRL_NUM_CODE_least_MASK             (0x0FUL << FPB_CTRL_NUM_CODE_least_SHIFT)           /*!< FPB_CTRL: NUM_CODE_least Mask           */
#define FPB_CTRL_NUM_CODE_least_SHIFT            4                                                   /*!< FPB_CTRL: NUM_CODE_least Position       */
#define FPB_CTRL_NUM_CODE_least(x)               (((uint32_t)(((uint32_t)(x))<<FPB_CTRL_NUM_CODE_least_SHIFT))&FPB_CTRL_NUM_CODE_least_MASK) /*!< FPB_CTRL                                */
#define FPB_CTRL_NUM_LIT_MASK                    (0x0FUL << FPB_CTRL_NUM_LIT_SHIFT)                  /*!< FPB_CTRL: NUM_LIT Mask                  */
#define FPB_CTRL_NUM_LIT_SHIFT                   8                                                   /*!< FPB_CTRL: NUM_LIT Position              */
#define FPB_CTRL_NUM_LIT(x)                      (((uint32_t)(((uint32_t)(x))<<FPB_CTRL_NUM_LIT_SHIFT))&FPB_CTRL_NUM_LIT_MASK) /*!< FPB_CTRL                                */
#define FPB_CTRL_NUM_CODE_most_MASK              (0x07UL << FPB_CTRL_NUM_CODE_most_SHIFT)            /*!< FPB_CTRL: NUM_CODE_most Mask            */
#define FPB_CTRL_NUM_CODE_most_SHIFT             12                                                  /*!< FPB_CTRL: NUM_CODE_most Position        */
#define FPB_CTRL_NUM_CODE_most(x)                (((uint32_t)(((uint32_t)(x))<<FPB_CTRL_NUM_CODE_most_SHIFT))&FPB_CTRL_NUM_CODE_most_MASK) /*!< FPB_CTRL                                */
/* ------- REMAP Bit Fields                         ------ */
#define FPB_REMAP_REMAP_MASK                     (0xFFFFFFUL << FPB_REMAP_REMAP_SHIFT)               /*!< FPB_REMAP: REMAP Mask                   */
#define FPB_REMAP_REMAP_SHIFT                    5                                                   /*!< FPB_REMAP: REMAP Position               */
#define FPB_REMAP_REMAP(x)                       (((uint32_t)(((uint32_t)(x))<<FPB_REMAP_REMAP_SHIFT))&FPB_REMAP_REMAP_MASK) /*!< FPB_REMAP                               */
#define FPB_REMAP_RMPSPT_MASK                    (0x01UL << FPB_REMAP_RMPSPT_SHIFT)                  /*!< FPB_REMAP: RMPSPT Mask                  */
#define FPB_REMAP_RMPSPT_SHIFT                   29                                                  /*!< FPB_REMAP: RMPSPT Position              */
#define FPB_REMAP_RMPSPT(x)                      (((uint32_t)(((uint32_t)(x))<<FPB_REMAP_RMPSPT_SHIFT))&FPB_REMAP_RMPSPT_MASK) /*!< FPB_REMAP                               */
/* ------- COMP Bit Fields                          ------ */
#define FPB_COMP_ENABLE_MASK                     (0x01UL << FPB_COMP_ENABLE_SHIFT)                   /*!< FPB_COMP: ENABLE Mask                   */
#define FPB_COMP_ENABLE_SHIFT                    0                                                   /*!< FPB_COMP: ENABLE Position               */
#define FPB_COMP_ENABLE(x)                       (((uint32_t)(((uint32_t)(x))<<FPB_COMP_ENABLE_SHIFT))&FPB_COMP_ENABLE_MASK) /*!< FPB_COMP                                */
#define FPB_COMP_COMP_MASK                       (0x7FFFFFFUL << FPB_COMP_COMP_SHIFT)                /*!< FPB_COMP: COMP Mask                     */
#define FPB_COMP_COMP_SHIFT                      2                                                   /*!< FPB_COMP: COMP Position                 */
#define FPB_COMP_COMP(x)                         (((uint32_t)(((uint32_t)(x))<<FPB_COMP_COMP_SHIFT))&FPB_COMP_COMP_MASK) /*!< FPB_COMP                                */
#define FPB_COMP_REPLACE_MASK                    (0x03UL << FPB_COMP_REPLACE_SHIFT)                  /*!< FPB_COMP: REPLACE Mask                  */
#define FPB_COMP_REPLACE_SHIFT                   30                                                  /*!< FPB_COMP: REPLACE Position              */
#define FPB_COMP_REPLACE(x)                      (((uint32_t)(((uint32_t)(x))<<FPB_COMP_REPLACE_SHIFT))&FPB_COMP_REPLACE_MASK) /*!< FPB_COMP                                */
/* ------- PID4 Bit Fields                          ------ */
#define FPB_PID4_JEP106_MASK                     (0x0FUL << FPB_PID4_JEP106_SHIFT)                   /*!< FPB_PID4: JEP106 Mask                   */
#define FPB_PID4_JEP106_SHIFT                    0                                                   /*!< FPB_PID4: JEP106 Position               */
#define FPB_PID4_JEP106(x)                       (((uint32_t)(((uint32_t)(x))<<FPB_PID4_JEP106_SHIFT))&FPB_PID4_JEP106_MASK) /*!< FPB_PID4                                */
#define FPB_PID4_c4KB_MASK                       (0x0FUL << FPB_PID4_c4KB_SHIFT)                     /*!< FPB_PID4: c4KB Mask                     */
#define FPB_PID4_c4KB_SHIFT                      4                                                   /*!< FPB_PID4: c4KB Position                 */
#define FPB_PID4_c4KB(x)                         (((uint32_t)(((uint32_t)(x))<<FPB_PID4_c4KB_SHIFT))&FPB_PID4_c4KB_MASK) /*!< FPB_PID4                                */
/* ------- PID5 Bit Fields                          ------ */
/* ------- PID6 Bit Fields                          ------ */
/* ------- PID7 Bit Fields                          ------ */
/* ------- PID0 Bit Fields                          ------ */
#define FPB_PID0_PartNumber_MASK                 (0xFFUL << FPB_PID0_PartNumber_SHIFT)               /*!< FPB_PID0: PartNumber Mask               */
#define FPB_PID0_PartNumber_SHIFT                0                                                   /*!< FPB_PID0: PartNumber Position           */
#define FPB_PID0_PartNumber(x)                   (((uint32_t)(((uint32_t)(x))<<FPB_PID0_PartNumber_SHIFT))&FPB_PID0_PartNumber_MASK) /*!< FPB_PID0                                */
/* ------- PID1 Bit Fields                          ------ */
#define FPB_PID1_PartNumber_MASK                 (0x0FUL << FPB_PID1_PartNumber_SHIFT)               /*!< FPB_PID1: PartNumber Mask               */
#define FPB_PID1_PartNumber_SHIFT                0                                                   /*!< FPB_PID1: PartNumber Position           */
#define FPB_PID1_PartNumber(x)                   (((uint32_t)(((uint32_t)(x))<<FPB_PID1_PartNumber_SHIFT))&FPB_PID1_PartNumber_MASK) /*!< FPB_PID1                                */
#define FPB_PID1_JEP106_identity_code_MASK       (0x0FUL << FPB_PID1_JEP106_identity_code_SHIFT)     /*!< FPB_PID1: JEP106_identity_code Mask     */
#define FPB_PID1_JEP106_identity_code_SHIFT      4                                                   /*!< FPB_PID1: JEP106_identity_code Position */
#define FPB_PID1_JEP106_identity_code(x)         (((uint32_t)(((uint32_t)(x))<<FPB_PID1_JEP106_identity_code_SHIFT))&FPB_PID1_JEP106_identity_code_MASK) /*!< FPB_PID1                                */
/* ------- PID2 Bit Fields                          ------ */
#define FPB_PID2_JEP106_identity_code_MASK       (0x07UL << FPB_PID2_JEP106_identity_code_SHIFT)     /*!< FPB_PID2: JEP106_identity_code Mask     */
#define FPB_PID2_JEP106_identity_code_SHIFT      0                                                   /*!< FPB_PID2: JEP106_identity_code Position */
#define FPB_PID2_JEP106_identity_code(x)         (((uint32_t)(((uint32_t)(x))<<FPB_PID2_JEP106_identity_code_SHIFT))&FPB_PID2_JEP106_identity_code_MASK) /*!< FPB_PID2                                */
#define FPB_PID2_Revision_MASK                   (0x0FUL << FPB_PID2_Revision_SHIFT)                 /*!< FPB_PID2: Revision Mask                 */
#define FPB_PID2_Revision_SHIFT                  4                                                   /*!< FPB_PID2: Revision Position             */
#define FPB_PID2_Revision(x)                     (((uint32_t)(((uint32_t)(x))<<FPB_PID2_Revision_SHIFT))&FPB_PID2_Revision_MASK) /*!< FPB_PID2                                */
/* ------- PID3 Bit Fields                          ------ */
#define FPB_PID3_CustomerModified_MASK           (0x0FUL << FPB_PID3_CustomerModified_SHIFT)         /*!< FPB_PID3: CustomerModified Mask         */
#define FPB_PID3_CustomerModified_SHIFT          0                                                   /*!< FPB_PID3: CustomerModified Position     */
#define FPB_PID3_CustomerModified(x)             (((uint32_t)(((uint32_t)(x))<<FPB_PID3_CustomerModified_SHIFT))&FPB_PID3_CustomerModified_MASK) /*!< FPB_PID3                                */
#define FPB_PID3_RevAnd_MASK                     (0x0FUL << FPB_PID3_RevAnd_SHIFT)                   /*!< FPB_PID3: RevAnd Mask                   */
#define FPB_PID3_RevAnd_SHIFT                    4                                                   /*!< FPB_PID3: RevAnd Position               */
#define FPB_PID3_RevAnd(x)                       (((uint32_t)(((uint32_t)(x))<<FPB_PID3_RevAnd_SHIFT))&FPB_PID3_RevAnd_MASK) /*!< FPB_PID3                                */
/* ------- CID0 Bit Fields                          ------ */
#define FPB_CID0_Preamble_MASK                   (0xFFUL << FPB_CID0_Preamble_SHIFT)                 /*!< FPB_CID0: Preamble Mask                 */
#define FPB_CID0_Preamble_SHIFT                  0                                                   /*!< FPB_CID0: Preamble Position             */
#define FPB_CID0_Preamble(x)                     (((uint32_t)(((uint32_t)(x))<<FPB_CID0_Preamble_SHIFT))&FPB_CID0_Preamble_MASK) /*!< FPB_CID0                                */
/* ------- CID1 Bit Fields                          ------ */
#define FPB_CID1_Preamble_MASK                   (0x0FUL << FPB_CID1_Preamble_SHIFT)                 /*!< FPB_CID1: Preamble Mask                 */
#define FPB_CID1_Preamble_SHIFT                  0                                                   /*!< FPB_CID1: Preamble Position             */
#define FPB_CID1_Preamble(x)                     (((uint32_t)(((uint32_t)(x))<<FPB_CID1_Preamble_SHIFT))&FPB_CID1_Preamble_MASK) /*!< FPB_CID1                                */
#define FPB_CID1_ComponentClass_MASK             (0x0FUL << FPB_CID1_ComponentClass_SHIFT)           /*!< FPB_CID1: ComponentClass Mask           */
#define FPB_CID1_ComponentClass_SHIFT            4                                                   /*!< FPB_CID1: ComponentClass Position       */
#define FPB_CID1_ComponentClass(x)               (((uint32_t)(((uint32_t)(x))<<FPB_CID1_ComponentClass_SHIFT))&FPB_CID1_ComponentClass_MASK) /*!< FPB_CID1                                */
/* ------- CID2 Bit Fields                          ------ */
#define FPB_CID2_Preamble_MASK                   (0xFFUL << FPB_CID2_Preamble_SHIFT)                 /*!< FPB_CID2: Preamble Mask                 */
#define FPB_CID2_Preamble_SHIFT                  0                                                   /*!< FPB_CID2: Preamble Position             */
#define FPB_CID2_Preamble(x)                     (((uint32_t)(((uint32_t)(x))<<FPB_CID2_Preamble_SHIFT))&FPB_CID2_Preamble_MASK) /*!< FPB_CID2                                */
/* ------- CID3 Bit Fields                          ------ */
#define FPB_CID3_Preamble_MASK                   (0xFFUL << FPB_CID3_Preamble_SHIFT)                 /*!< FPB_CID3: Preamble Mask                 */
#define FPB_CID3_Preamble_SHIFT                  0                                                   /*!< FPB_CID3: Preamble Position             */
#define FPB_CID3_Preamble(x)                     (((uint32_t)(((uint32_t)(x))<<FPB_CID3_Preamble_SHIFT))&FPB_CID3_Preamble_MASK) /*!< FPB_CID3                                */
/**
 * @} */ /* End group FPB_Register_Masks_GROUP 
 */

/* FPB - Peripheral instance base addresses */
#define FPB_BasePtr                    0xE0002000UL //!< Peripheral base address
#define FPB                            ((FPB_Type *) FPB_BasePtr) //!< Freescale base pointer
#define FPB_BASE_PTR                   (FPB) //!< Freescale style base pointer
/**
 * @} */ /* End group FPB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTFL_Peripheral_access_layer_GROUP FTFL Peripheral Access Layer
* @brief C Struct for FTFL
* @{
*/

/* ================================================================================ */
/* ================           FTFL (file:FTFL)                     ================ */
/* ================================================================================ */

/**
 * @brief Flash Memory Interface
 */
/**
* @addtogroup FTFL_structs_GROUP FTFL struct
* @brief Struct for FTFL
* @{
*/
typedef struct {                                /*       FTFL Structure                                               */
   __IO uint8_t   FSTAT;                        /**< 0000: Flash Status Register                                        */
   __IO uint8_t   FCNFG;                        /**< 0001: Flash Configuration Register                                 */
   __I  uint8_t   FSEC;                         /**< 0002: Flash Security Register                                      */
   __I  uint8_t   FOPT;                         /**< 0003: Flash Option Register                                        */
   __IO uint8_t   FCCOB3;                       /**< 0004: FCCOB 3 - Usually Flash address [7..0]                       */
   __IO uint8_t   FCCOB2;                       /**< 0005: FCCOB 2 - Usually Flash address [15..8]                      */
   __IO uint8_t   FCCOB1;                       /**< 0006: FCCOB 1 - Usually Flash address [23..16]                     */
   __IO uint8_t   FCCOB0;                       /**< 0007: FCCOB 0 - Usually FCMD (Flash command)                       */
   __IO uint8_t   FCCOB7;                       /**< 0008: FCCOB 7 - Usually Data Byte 3                                */
   __IO uint8_t   FCCOB6;                       /**< 0009: FCCOB 6 - Usually Data Byte 2                                */
   __IO uint8_t   FCCOB5;                       /**< 000A: FCCOB 5 - Usually Data Byte 1                                */
   __IO uint8_t   FCCOB4;                       /**< 000B: FCCOB 4 - Usually Data Byte 0                                */
   __IO uint8_t   FCCOBB;                       /**< 000C: FCCOB B - Usually Data Byte 7                                */
   __IO uint8_t   FCCOBA;                       /**< 000D: FCCOB A - Usually Data Byte 6                                */
   __IO uint8_t   FCCOB9;                       /**< 000E: FCCOB 9 - Usually Data Byte 5                                */
   __IO uint8_t   FCCOB8;                       /**< 000F: FCCOB 8 - Usually Data Byte 4                                */
   __IO uint8_t   FPROT3;                       /**< 0010: Program Flash Protection                                     */
   __IO uint8_t   FPROT2;                       /**< 0011: Program Flash Protection                                     */
   __IO uint8_t   FPROT1;                       /**< 0012: Program Flash Protection                                     */
   __IO uint8_t   FPROT0;                       /**< 0013: Program Flash Protection                                     */
   __I  uint16_t  RESERVED0;                   
   __IO uint8_t   FEPROT;                       /**< 0016: EEPROM Protection Register                                   */
   __IO uint8_t   FDPROT;                       /**< 0017: Data Flash Protection Register                               */
} FTFL_Type;

/**
 * @} */ /* End group FTFL_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTFL' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FTFL_Register_Masks_GROUP FTFL Register Masks
* @brief Register Masks for FTFL
* @{
*/
/* ------- FSTAT Bit Fields                         ------ */
#define FTFL_FSTAT_MGSTAT0_MASK                  (0x01UL << FTFL_FSTAT_MGSTAT0_SHIFT)                /*!< FTFL_FSTAT: MGSTAT0 Mask                */
#define FTFL_FSTAT_MGSTAT0_SHIFT                 0                                                   /*!< FTFL_FSTAT: MGSTAT0 Position            */
#define FTFL_FSTAT_MGSTAT0(x)                    (((uint8_t)(((uint8_t)(x))<<FTFL_FSTAT_MGSTAT0_SHIFT))&FTFL_FSTAT_MGSTAT0_MASK) /*!< FTFL_FSTAT                              */
#define FTFL_FSTAT_FPVIOL_MASK                   (0x01UL << FTFL_FSTAT_FPVIOL_SHIFT)                 /*!< FTFL_FSTAT: FPVIOL Mask                 */
#define FTFL_FSTAT_FPVIOL_SHIFT                  4                                                   /*!< FTFL_FSTAT: FPVIOL Position             */
#define FTFL_FSTAT_FPVIOL(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FSTAT_FPVIOL_SHIFT))&FTFL_FSTAT_FPVIOL_MASK) /*!< FTFL_FSTAT                              */
#define FTFL_FSTAT_ACCERR_MASK                   (0x01UL << FTFL_FSTAT_ACCERR_SHIFT)                 /*!< FTFL_FSTAT: ACCERR Mask                 */
#define FTFL_FSTAT_ACCERR_SHIFT                  5                                                   /*!< FTFL_FSTAT: ACCERR Position             */
#define FTFL_FSTAT_ACCERR(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FSTAT_ACCERR_SHIFT))&FTFL_FSTAT_ACCERR_MASK) /*!< FTFL_FSTAT                              */
#define FTFL_FSTAT_RDCOLERR_MASK                 (0x01UL << FTFL_FSTAT_RDCOLERR_SHIFT)               /*!< FTFL_FSTAT: RDCOLERR Mask               */
#define FTFL_FSTAT_RDCOLERR_SHIFT                6                                                   /*!< FTFL_FSTAT: RDCOLERR Position           */
#define FTFL_FSTAT_RDCOLERR(x)                   (((uint8_t)(((uint8_t)(x))<<FTFL_FSTAT_RDCOLERR_SHIFT))&FTFL_FSTAT_RDCOLERR_MASK) /*!< FTFL_FSTAT                              */
#define FTFL_FSTAT_CCIF_MASK                     (0x01UL << FTFL_FSTAT_CCIF_SHIFT)                   /*!< FTFL_FSTAT: CCIF Mask                   */
#define FTFL_FSTAT_CCIF_SHIFT                    7                                                   /*!< FTFL_FSTAT: CCIF Position               */
#define FTFL_FSTAT_CCIF(x)                       (((uint8_t)(((uint8_t)(x))<<FTFL_FSTAT_CCIF_SHIFT))&FTFL_FSTAT_CCIF_MASK) /*!< FTFL_FSTAT                              */
/* ------- FCNFG Bit Fields                         ------ */
#define FTFL_FCNFG_EEERDY_MASK                   (0x01UL << FTFL_FCNFG_EEERDY_SHIFT)                 /*!< FTFL_FCNFG: EEERDY Mask                 */
#define FTFL_FCNFG_EEERDY_SHIFT                  0                                                   /*!< FTFL_FCNFG: EEERDY Position             */
#define FTFL_FCNFG_EEERDY(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCNFG_EEERDY_SHIFT))&FTFL_FCNFG_EEERDY_MASK) /*!< FTFL_FCNFG                              */
#define FTFL_FCNFG_RAMRDY_MASK                   (0x01UL << FTFL_FCNFG_RAMRDY_SHIFT)                 /*!< FTFL_FCNFG: RAMRDY Mask                 */
#define FTFL_FCNFG_RAMRDY_SHIFT                  1                                                   /*!< FTFL_FCNFG: RAMRDY Position             */
#define FTFL_FCNFG_RAMRDY(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FCNFG_RAMRDY_SHIFT))&FTFL_FCNFG_RAMRDY_MASK) /*!< FTFL_FCNFG                              */
#define FTFL_FCNFG_PFLSH_MASK                    (0x01UL << FTFL_FCNFG_PFLSH_SHIFT)                  /*!< FTFL_FCNFG: PFLSH Mask                  */
#define FTFL_FCNFG_PFLSH_SHIFT                   2                                                   /*!< FTFL_FCNFG: PFLSH Position              */
#define FTFL_FCNFG_PFLSH(x)                      (((uint8_t)(((uint8_t)(x))<<FTFL_FCNFG_PFLSH_SHIFT))&FTFL_FCNFG_PFLSH_MASK) /*!< FTFL_FCNFG                              */
#define FTFL_FCNFG_SWAP_MASK                     (0x01UL << FTFL_FCNFG_SWAP_SHIFT)                   /*!< FTFL_FCNFG: SWAP Mask                   */
#define FTFL_FCNFG_SWAP_SHIFT                    3                                                   /*!< FTFL_FCNFG: SWAP Position               */
#define FTFL_FCNFG_SWAP(x)                       (((uint8_t)(((uint8_t)(x))<<FTFL_FCNFG_SWAP_SHIFT))&FTFL_FCNFG_SWAP_MASK) /*!< FTFL_FCNFG                              */
#define FTFL_FCNFG_ERSSUSP_MASK                  (0x01UL << FTFL_FCNFG_ERSSUSP_SHIFT)                /*!< FTFL_FCNFG: ERSSUSP Mask                */
#define FTFL_FCNFG_ERSSUSP_SHIFT                 4                                                   /*!< FTFL_FCNFG: ERSSUSP Position            */
#define FTFL_FCNFG_ERSSUSP(x)                    (((uint8_t)(((uint8_t)(x))<<FTFL_FCNFG_ERSSUSP_SHIFT))&FTFL_FCNFG_ERSSUSP_MASK) /*!< FTFL_FCNFG                              */
#define FTFL_FCNFG_ERSAREQ_MASK                  (0x01UL << FTFL_FCNFG_ERSAREQ_SHIFT)                /*!< FTFL_FCNFG: ERSAREQ Mask                */
#define FTFL_FCNFG_ERSAREQ_SHIFT                 5                                                   /*!< FTFL_FCNFG: ERSAREQ Position            */
#define FTFL_FCNFG_ERSAREQ(x)                    (((uint8_t)(((uint8_t)(x))<<FTFL_FCNFG_ERSAREQ_SHIFT))&FTFL_FCNFG_ERSAREQ_MASK) /*!< FTFL_FCNFG                              */
#define FTFL_FCNFG_RDCOLLIE_MASK                 (0x01UL << FTFL_FCNFG_RDCOLLIE_SHIFT)               /*!< FTFL_FCNFG: RDCOLLIE Mask               */
#define FTFL_FCNFG_RDCOLLIE_SHIFT                6                                                   /*!< FTFL_FCNFG: RDCOLLIE Position           */
#define FTFL_FCNFG_RDCOLLIE(x)                   (((uint8_t)(((uint8_t)(x))<<FTFL_FCNFG_RDCOLLIE_SHIFT))&FTFL_FCNFG_RDCOLLIE_MASK) /*!< FTFL_FCNFG                              */
#define FTFL_FCNFG_CCIE_MASK                     (0x01UL << FTFL_FCNFG_CCIE_SHIFT)                   /*!< FTFL_FCNFG: CCIE Mask                   */
#define FTFL_FCNFG_CCIE_SHIFT                    7                                                   /*!< FTFL_FCNFG: CCIE Position               */
#define FTFL_FCNFG_CCIE(x)                       (((uint8_t)(((uint8_t)(x))<<FTFL_FCNFG_CCIE_SHIFT))&FTFL_FCNFG_CCIE_MASK) /*!< FTFL_FCNFG                              */
/* ------- FSEC Bit Fields                          ------ */
#define FTFL_FSEC_SEC_MASK                       (0x03UL << FTFL_FSEC_SEC_SHIFT)                     /*!< FTFL_FSEC: SEC Mask                     */
#define FTFL_FSEC_SEC_SHIFT                      0                                                   /*!< FTFL_FSEC: SEC Position                 */
#define FTFL_FSEC_SEC(x)                         (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_SEC_SHIFT))&FTFL_FSEC_SEC_MASK) /*!< FTFL_FSEC                               */
#define FTFL_FSEC_FSLACC_MASK                    (0x03UL << FTFL_FSEC_FSLACC_SHIFT)                  /*!< FTFL_FSEC: FSLACC Mask                  */
#define FTFL_FSEC_FSLACC_SHIFT                   2                                                   /*!< FTFL_FSEC: FSLACC Position              */
#define FTFL_FSEC_FSLACC(x)                      (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_FSLACC_SHIFT))&FTFL_FSEC_FSLACC_MASK) /*!< FTFL_FSEC                               */
#define FTFL_FSEC_MEEN_MASK                      (0x03UL << FTFL_FSEC_MEEN_SHIFT)                    /*!< FTFL_FSEC: MEEN Mask                    */
#define FTFL_FSEC_MEEN_SHIFT                     4                                                   /*!< FTFL_FSEC: MEEN Position                */
#define FTFL_FSEC_MEEN(x)                        (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_MEEN_SHIFT))&FTFL_FSEC_MEEN_MASK) /*!< FTFL_FSEC                               */
#define FTFL_FSEC_KEYEN_MASK                     (0x03UL << FTFL_FSEC_KEYEN_SHIFT)                   /*!< FTFL_FSEC: KEYEN Mask                   */
#define FTFL_FSEC_KEYEN_SHIFT                    6                                                   /*!< FTFL_FSEC: KEYEN Position               */
#define FTFL_FSEC_KEYEN(x)                       (((uint8_t)(((uint8_t)(x))<<FTFL_FSEC_KEYEN_SHIFT))&FTFL_FSEC_KEYEN_MASK) /*!< FTFL_FSEC                               */
/* ------- FOPT Bit Fields                          ------ */
#define FTFL_FOPT_OPT_MASK                       (0xFFUL << FTFL_FOPT_OPT_SHIFT)                     /*!< FTFL_FOPT: OPT Mask                     */
#define FTFL_FOPT_OPT_SHIFT                      0                                                   /*!< FTFL_FOPT: OPT Position                 */
#define FTFL_FOPT_OPT(x)                         (((uint8_t)(((uint8_t)(x))<<FTFL_FOPT_OPT_SHIFT))&FTFL_FOPT_OPT_MASK) /*!< FTFL_FOPT                               */
/* ------- FCCOB Bit Fields                         ------ */
#define FTFL_FCCOB_CCOBn_MASK                    (0xFFUL << FTFL_FCCOB_CCOBn_SHIFT)                  /*!< FTFL_FCCOB: CCOBn Mask                  */
#define FTFL_FCCOB_CCOBn_SHIFT                   0                                                   /*!< FTFL_FCCOB: CCOBn Position              */
#define FTFL_FCCOB_CCOBn(x)                      (((uint8_t)(((uint8_t)(x))<<FTFL_FCCOB_CCOBn_SHIFT))&FTFL_FCCOB_CCOBn_MASK) /*!< FTFL_FCCOB                              */
/* ------- FPROT Bit Fields                         ------ */
#define FTFL_FPROT_PROT_MASK                     (0xFFUL << FTFL_FPROT_PROT_SHIFT)                   /*!< FTFL_FPROT: PROT Mask                   */
#define FTFL_FPROT_PROT_SHIFT                    0                                                   /*!< FTFL_FPROT: PROT Position               */
#define FTFL_FPROT_PROT(x)                       (((uint8_t)(((uint8_t)(x))<<FTFL_FPROT_PROT_SHIFT))&FTFL_FPROT_PROT_MASK) /*!< FTFL_FPROT                              */
/* ------- FEPROT Bit Fields                        ------ */
#define FTFL_FEPROT_EPROT_MASK                   (0xFFUL << FTFL_FEPROT_EPROT_SHIFT)                 /*!< FTFL_FEPROT: EPROT Mask                 */
#define FTFL_FEPROT_EPROT_SHIFT                  0                                                   /*!< FTFL_FEPROT: EPROT Position             */
#define FTFL_FEPROT_EPROT(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FEPROT_EPROT_SHIFT))&FTFL_FEPROT_EPROT_MASK) /*!< FTFL_FEPROT                             */
/* ------- FDPROT Bit Fields                        ------ */
#define FTFL_FDPROT_DPROT_MASK                   (0xFFUL << FTFL_FDPROT_DPROT_SHIFT)                 /*!< FTFL_FDPROT: DPROT Mask                 */
#define FTFL_FDPROT_DPROT_SHIFT                  0                                                   /*!< FTFL_FDPROT: DPROT Position             */
#define FTFL_FDPROT_DPROT(x)                     (((uint8_t)(((uint8_t)(x))<<FTFL_FDPROT_DPROT_SHIFT))&FTFL_FDPROT_DPROT_MASK) /*!< FTFL_FDPROT                             */
/**
 * @} */ /* End group FTFL_Register_Masks_GROUP 
 */

/* FTFL - Peripheral instance base addresses */
#define FTFL_BasePtr                   0x40020000UL //!< Peripheral base address
#define FTFL                           ((FTFL_Type *) FTFL_BasePtr) //!< Freescale base pointer
#define FTFL_BASE_PTR                  (FTFL) //!< Freescale style base pointer
/**
 * @} */ /* End group FTFL_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTM_Peripheral_access_layer_GROUP FTM Peripheral Access Layer
* @brief C Struct for FTM
* @{
*/

/* ================================================================================ */
/* ================           FTM0 (file:FTM0_8CH)                 ================ */
/* ================================================================================ */

/**
 * @brief FlexTimer Module (8 channels)
 */
/**
* @addtogroup FTM_structs_GROUP FTM struct
* @brief Struct for FTM
* @{
*/
typedef struct {                                /*       FTM0 Structure                                               */
   __IO uint32_t  SC;                           /**< 0000: Status and Control                                           */
   __IO uint32_t  CNT;                          /**< 0004: Counter                                                      */
   __IO uint32_t  MOD;                          /**< 0008: Modulo                                                       */
   struct {
      __IO uint32_t  CnSC;                      /**< 000C: Channel  Status and Control                                  */
      __IO uint32_t  CnV;                       /**< 0010: Channel  Value                                               */
   } CONTROLS[8];                               /**< 000C: (cluster: size=0x0040, 64)                                   */
   __IO uint32_t  CNTIN;                        /**< 004C: Counter Initial Value                                        */
   __IO uint32_t  STATUS;                       /**< 0050: Capture and Compare Status                                   */
   __IO uint32_t  MODE;                         /**< 0054: Features Mode Selection                                      */
   __IO uint32_t  SYNC;                         /**< 0058: Synchronization                                              */
   __IO uint32_t  OUTINIT;                      /**< 005C: Initial State for Channels Output                            */
   __IO uint32_t  OUTMASK;                      /**< 0060: Output Mask                                                  */
   __IO uint32_t  COMBINE;                      /**< 0064: Function for Linked Channels                                 */
   __IO uint32_t  DEADTIME;                     /**< 0068: Deadtime Insertion Control                                   */
   __IO uint32_t  EXTTRIG;                      /**< 006C: FTM External Trigger                                         */
   __IO uint32_t  POL;                          /**< 0070: Channels Polarity                                            */
   __IO uint32_t  FMS;                          /**< 0074: Fault Mode Status                                            */
   __IO uint32_t  FILTER;                       /**< 0078: Input Capture Filter Control                                 */
   __IO uint32_t  FLTCTRL;                      /**< 007C: Fault Control                                                */
   __IO uint32_t  QDCTRL;                       /**< 0080: Quadrature Decoder Control and Status                        */
   __IO uint32_t  CONF;                         /**< 0084: Configuration                                                */
   __IO uint32_t  FLTPOL;                       /**< 0088: FTM Fault Input Polarity                                     */
   __IO uint32_t  SYNCONF;                      /**< 008C: Synchronization Configuration                                */
   __IO uint32_t  INVCTRL;                      /**< 0090: FTM Inverting Control                                        */
   __IO uint32_t  SWOCTRL;                      /**< 0094: FTM Software Output Control                                  */
   __IO uint32_t  PWMLOAD;                      /**< 0098: FTM PWM Load                                                 */
} FTM_Type;

/**
 * @} */ /* End group FTM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTM0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FTM_Register_Masks_GROUP FTM Register Masks
* @brief Register Masks for FTM
* @{
*/
/* ------- SC Bit Fields                            ------ */
#define FTM_SC_PS_MASK                           (0x07UL << FTM_SC_PS_SHIFT)                         /*!< FTM0_SC: PS Mask                        */
#define FTM_SC_PS_SHIFT                          0                                                   /*!< FTM0_SC: PS Position                    */
#define FTM_SC_PS(x)                             (((uint32_t)(((uint32_t)(x))<<FTM_SC_PS_SHIFT))&FTM_SC_PS_MASK) /*!< FTM0_SC                                 */
#define FTM_SC_CLKS_MASK                         (0x03UL << FTM_SC_CLKS_SHIFT)                       /*!< FTM0_SC: CLKS Mask                      */
#define FTM_SC_CLKS_SHIFT                        3                                                   /*!< FTM0_SC: CLKS Position                  */
#define FTM_SC_CLKS(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_SC_CLKS_SHIFT))&FTM_SC_CLKS_MASK) /*!< FTM0_SC                                 */
#define FTM_SC_CPWMS_MASK                        (0x01UL << FTM_SC_CPWMS_SHIFT)                      /*!< FTM0_SC: CPWMS Mask                     */
#define FTM_SC_CPWMS_SHIFT                       5                                                   /*!< FTM0_SC: CPWMS Position                 */
#define FTM_SC_CPWMS(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_SC_CPWMS_SHIFT))&FTM_SC_CPWMS_MASK) /*!< FTM0_SC                                 */
#define FTM_SC_TOIE_MASK                         (0x01UL << FTM_SC_TOIE_SHIFT)                       /*!< FTM0_SC: TOIE Mask                      */
#define FTM_SC_TOIE_SHIFT                        6                                                   /*!< FTM0_SC: TOIE Position                  */
#define FTM_SC_TOIE(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_SC_TOIE_SHIFT))&FTM_SC_TOIE_MASK) /*!< FTM0_SC                                 */
#define FTM_SC_TOF_MASK                          (0x01UL << FTM_SC_TOF_SHIFT)                        /*!< FTM0_SC: TOF Mask                       */
#define FTM_SC_TOF_SHIFT                         7                                                   /*!< FTM0_SC: TOF Position                   */
#define FTM_SC_TOF(x)                            (((uint32_t)(((uint32_t)(x))<<FTM_SC_TOF_SHIFT))&FTM_SC_TOF_MASK) /*!< FTM0_SC                                 */
/* ------- CNT Bit Fields                           ------ */
#define FTM_CNT_COUNT_MASK                       (0xFFFFUL << FTM_CNT_COUNT_SHIFT)                   /*!< FTM0_CNT: COUNT Mask                    */
#define FTM_CNT_COUNT_SHIFT                      0                                                   /*!< FTM0_CNT: COUNT Position                */
#define FTM_CNT_COUNT(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CNT_COUNT_SHIFT))&FTM_CNT_COUNT_MASK) /*!< FTM0_CNT                                */
/* ------- MOD Bit Fields                           ------ */
#define FTM_MOD_MOD_MASK                         (0xFFFFUL << FTM_MOD_MOD_SHIFT)                     /*!< FTM0_MOD: MOD Mask                      */
#define FTM_MOD_MOD_SHIFT                        0                                                   /*!< FTM0_MOD: MOD Position                  */
#define FTM_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_MOD_MOD_SHIFT))&FTM_MOD_MOD_MASK) /*!< FTM0_MOD                                */
/* ------- CnSC Bit Fields                          ------ */
#define FTM_CnSC_DMA_MASK                        (0x01UL << FTM_CnSC_DMA_SHIFT)                      /*!< FTM0_CnSC: DMA Mask                     */
#define FTM_CnSC_DMA_SHIFT                       0                                                   /*!< FTM0_CnSC: DMA Position                 */
#define FTM_CnSC_DMA(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_DMA_SHIFT))&FTM_CnSC_DMA_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_ELS_MASK                        (0x03UL << FTM_CnSC_ELS_SHIFT)                      /*!< FTM0_CnSC: ELS Mask                     */
#define FTM_CnSC_ELS_SHIFT                       2                                                   /*!< FTM0_CnSC: ELS Position                 */
#define FTM_CnSC_ELS(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_ELS_SHIFT))&FTM_CnSC_ELS_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_ELSA_MASK                       (0x01UL << FTM_CnSC_ELSA_SHIFT)                     /*!< FTM0_CnSC: ELSA Mask                    */
#define FTM_CnSC_ELSA_SHIFT                      2                                                   /*!< FTM0_CnSC: ELSA Position                */
#define FTM_CnSC_ELSA(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_ELSA_SHIFT))&FTM_CnSC_ELSA_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_ELSB_MASK                       (0x01UL << FTM_CnSC_ELSB_SHIFT)                     /*!< FTM0_CnSC: ELSB Mask                    */
#define FTM_CnSC_ELSB_SHIFT                      3                                                   /*!< FTM0_CnSC: ELSB Position                */
#define FTM_CnSC_ELSB(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_ELSB_SHIFT))&FTM_CnSC_ELSB_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_MS_MASK                         (0x03UL << FTM_CnSC_MS_SHIFT)                       /*!< FTM0_CnSC: MS Mask                      */
#define FTM_CnSC_MS_SHIFT                        4                                                   /*!< FTM0_CnSC: MS Position                  */
#define FTM_CnSC_MS(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_MS_SHIFT))&FTM_CnSC_MS_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_MSA_MASK                        (0x01UL << FTM_CnSC_MSA_SHIFT)                      /*!< FTM0_CnSC: MSA Mask                     */
#define FTM_CnSC_MSA_SHIFT                       4                                                   /*!< FTM0_CnSC: MSA Position                 */
#define FTM_CnSC_MSA(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_MSA_SHIFT))&FTM_CnSC_MSA_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_MSB_MASK                        (0x01UL << FTM_CnSC_MSB_SHIFT)                      /*!< FTM0_CnSC: MSB Mask                     */
#define FTM_CnSC_MSB_SHIFT                       5                                                   /*!< FTM0_CnSC: MSB Position                 */
#define FTM_CnSC_MSB(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_MSB_SHIFT))&FTM_CnSC_MSB_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_CHIE_MASK                       (0x01UL << FTM_CnSC_CHIE_SHIFT)                     /*!< FTM0_CnSC: CHIE Mask                    */
#define FTM_CnSC_CHIE_SHIFT                      6                                                   /*!< FTM0_CnSC: CHIE Position                */
#define FTM_CnSC_CHIE(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_CHIE_SHIFT))&FTM_CnSC_CHIE_MASK) /*!< FTM0_CnSC                               */
#define FTM_CnSC_CHF_MASK                        (0x01UL << FTM_CnSC_CHF_SHIFT)                      /*!< FTM0_CnSC: CHF Mask                     */
#define FTM_CnSC_CHF_SHIFT                       7                                                   /*!< FTM0_CnSC: CHF Position                 */
#define FTM_CnSC_CHF(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_CHF_SHIFT))&FTM_CnSC_CHF_MASK) /*!< FTM0_CnSC                               */
/* ------- CnV Bit Fields                           ------ */
#define FTM_CnV_VAL_MASK                         (0xFFFFUL << FTM_CnV_VAL_SHIFT)                     /*!< FTM0_CnV: VAL Mask                      */
#define FTM_CnV_VAL_SHIFT                        0                                                   /*!< FTM0_CnV: VAL Position                  */
#define FTM_CnV_VAL(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_CnV_VAL_SHIFT))&FTM_CnV_VAL_MASK) /*!< FTM0_CnV                                */
/* ------- CNTIN Bit Fields                         ------ */
#define FTM_CNTIN_INIT_MASK                      (0xFFFFUL << FTM_CNTIN_INIT_SHIFT)                  /*!< FTM0_CNTIN: INIT Mask                   */
#define FTM_CNTIN_INIT_SHIFT                     0                                                   /*!< FTM0_CNTIN: INIT Position               */
#define FTM_CNTIN_INIT(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_CNTIN_INIT_SHIFT))&FTM_CNTIN_INIT_MASK) /*!< FTM0_CNTIN                              */
/* ------- STATUS Bit Fields                        ------ */
#define FTM_STATUS_CH0F_MASK                     (0x01UL << FTM_STATUS_CH0F_SHIFT)                   /*!< FTM0_STATUS: CH0F Mask                  */
#define FTM_STATUS_CH0F_SHIFT                    0                                                   /*!< FTM0_STATUS: CH0F Position              */
#define FTM_STATUS_CH0F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH0F_SHIFT))&FTM_STATUS_CH0F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH1F_MASK                     (0x01UL << FTM_STATUS_CH1F_SHIFT)                   /*!< FTM0_STATUS: CH1F Mask                  */
#define FTM_STATUS_CH1F_SHIFT                    1                                                   /*!< FTM0_STATUS: CH1F Position              */
#define FTM_STATUS_CH1F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH1F_SHIFT))&FTM_STATUS_CH1F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH2F_MASK                     (0x01UL << FTM_STATUS_CH2F_SHIFT)                   /*!< FTM0_STATUS: CH2F Mask                  */
#define FTM_STATUS_CH2F_SHIFT                    2                                                   /*!< FTM0_STATUS: CH2F Position              */
#define FTM_STATUS_CH2F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH2F_SHIFT))&FTM_STATUS_CH2F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH3F_MASK                     (0x01UL << FTM_STATUS_CH3F_SHIFT)                   /*!< FTM0_STATUS: CH3F Mask                  */
#define FTM_STATUS_CH3F_SHIFT                    3                                                   /*!< FTM0_STATUS: CH3F Position              */
#define FTM_STATUS_CH3F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH3F_SHIFT))&FTM_STATUS_CH3F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH4F_MASK                     (0x01UL << FTM_STATUS_CH4F_SHIFT)                   /*!< FTM0_STATUS: CH4F Mask                  */
#define FTM_STATUS_CH4F_SHIFT                    4                                                   /*!< FTM0_STATUS: CH4F Position              */
#define FTM_STATUS_CH4F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH4F_SHIFT))&FTM_STATUS_CH4F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH5F_MASK                     (0x01UL << FTM_STATUS_CH5F_SHIFT)                   /*!< FTM0_STATUS: CH5F Mask                  */
#define FTM_STATUS_CH5F_SHIFT                    5                                                   /*!< FTM0_STATUS: CH5F Position              */
#define FTM_STATUS_CH5F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH5F_SHIFT))&FTM_STATUS_CH5F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH6F_MASK                     (0x01UL << FTM_STATUS_CH6F_SHIFT)                   /*!< FTM0_STATUS: CH6F Mask                  */
#define FTM_STATUS_CH6F_SHIFT                    6                                                   /*!< FTM0_STATUS: CH6F Position              */
#define FTM_STATUS_CH6F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH6F_SHIFT))&FTM_STATUS_CH6F_MASK) /*!< FTM0_STATUS                             */
#define FTM_STATUS_CH7F_MASK                     (0x01UL << FTM_STATUS_CH7F_SHIFT)                   /*!< FTM0_STATUS: CH7F Mask                  */
#define FTM_STATUS_CH7F_SHIFT                    7                                                   /*!< FTM0_STATUS: CH7F Position              */
#define FTM_STATUS_CH7F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH7F_SHIFT))&FTM_STATUS_CH7F_MASK) /*!< FTM0_STATUS                             */
/* ------- MODE Bit Fields                          ------ */
#define FTM_MODE_FTMEN_MASK                      (0x01UL << FTM_MODE_FTMEN_SHIFT)                    /*!< FTM0_MODE: FTMEN Mask                   */
#define FTM_MODE_FTMEN_SHIFT                     0                                                   /*!< FTM0_MODE: FTMEN Position               */
#define FTM_MODE_FTMEN(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FTMEN_SHIFT))&FTM_MODE_FTMEN_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_INIT_MASK                       (0x01UL << FTM_MODE_INIT_SHIFT)                     /*!< FTM0_MODE: INIT Mask                    */
#define FTM_MODE_INIT_SHIFT                      1                                                   /*!< FTM0_MODE: INIT Position                */
#define FTM_MODE_INIT(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_MODE_INIT_SHIFT))&FTM_MODE_INIT_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_WPDIS_MASK                      (0x01UL << FTM_MODE_WPDIS_SHIFT)                    /*!< FTM0_MODE: WPDIS Mask                   */
#define FTM_MODE_WPDIS_SHIFT                     2                                                   /*!< FTM0_MODE: WPDIS Position               */
#define FTM_MODE_WPDIS(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_MODE_WPDIS_SHIFT))&FTM_MODE_WPDIS_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_PWMSYNC_MASK                    (0x01UL << FTM_MODE_PWMSYNC_SHIFT)                  /*!< FTM0_MODE: PWMSYNC Mask                 */
#define FTM_MODE_PWMSYNC_SHIFT                   3                                                   /*!< FTM0_MODE: PWMSYNC Position             */
#define FTM_MODE_PWMSYNC(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_MODE_PWMSYNC_SHIFT))&FTM_MODE_PWMSYNC_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_CAPTEST_MASK                    (0x01UL << FTM_MODE_CAPTEST_SHIFT)                  /*!< FTM0_MODE: CAPTEST Mask                 */
#define FTM_MODE_CAPTEST_SHIFT                   4                                                   /*!< FTM0_MODE: CAPTEST Position             */
#define FTM_MODE_CAPTEST(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_MODE_CAPTEST_SHIFT))&FTM_MODE_CAPTEST_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_FAULTM_MASK                     (0x03UL << FTM_MODE_FAULTM_SHIFT)                   /*!< FTM0_MODE: FAULTM Mask                  */
#define FTM_MODE_FAULTM_SHIFT                    5                                                   /*!< FTM0_MODE: FAULTM Position              */
#define FTM_MODE_FAULTM(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FAULTM_SHIFT))&FTM_MODE_FAULTM_MASK) /*!< FTM0_MODE                               */
#define FTM_MODE_FAULTIE_MASK                    (0x01UL << FTM_MODE_FAULTIE_SHIFT)                  /*!< FTM0_MODE: FAULTIE Mask                 */
#define FTM_MODE_FAULTIE_SHIFT                   7                                                   /*!< FTM0_MODE: FAULTIE Position             */
#define FTM_MODE_FAULTIE(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FAULTIE_SHIFT))&FTM_MODE_FAULTIE_MASK) /*!< FTM0_MODE                               */
/* ------- SYNC Bit Fields                          ------ */
#define FTM_SYNC_CNTMIN_MASK                     (0x01UL << FTM_SYNC_CNTMIN_SHIFT)                   /*!< FTM0_SYNC: CNTMIN Mask                  */
#define FTM_SYNC_CNTMIN_SHIFT                    0                                                   /*!< FTM0_SYNC: CNTMIN Position              */
#define FTM_SYNC_CNTMIN(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_CNTMIN_SHIFT))&FTM_SYNC_CNTMIN_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_CNTMAX_MASK                     (0x01UL << FTM_SYNC_CNTMAX_SHIFT)                   /*!< FTM0_SYNC: CNTMAX Mask                  */
#define FTM_SYNC_CNTMAX_SHIFT                    1                                                   /*!< FTM0_SYNC: CNTMAX Position              */
#define FTM_SYNC_CNTMAX(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_CNTMAX_SHIFT))&FTM_SYNC_CNTMAX_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_REINIT_MASK                     (0x01UL << FTM_SYNC_REINIT_SHIFT)                   /*!< FTM0_SYNC: REINIT Mask                  */
#define FTM_SYNC_REINIT_SHIFT                    2                                                   /*!< FTM0_SYNC: REINIT Position              */
#define FTM_SYNC_REINIT(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_REINIT_SHIFT))&FTM_SYNC_REINIT_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_SYNCHOM_MASK                    (0x01UL << FTM_SYNC_SYNCHOM_SHIFT)                  /*!< FTM0_SYNC: SYNCHOM Mask                 */
#define FTM_SYNC_SYNCHOM_SHIFT                   3                                                   /*!< FTM0_SYNC: SYNCHOM Position             */
#define FTM_SYNC_SYNCHOM(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_SYNCHOM_SHIFT))&FTM_SYNC_SYNCHOM_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_TRIG0_MASK                      (0x01UL << FTM_SYNC_TRIG0_SHIFT)                    /*!< FTM0_SYNC: TRIG0 Mask                   */
#define FTM_SYNC_TRIG0_SHIFT                     4                                                   /*!< FTM0_SYNC: TRIG0 Position               */
#define FTM_SYNC_TRIG0(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_TRIG0_SHIFT))&FTM_SYNC_TRIG0_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_TRIG1_MASK                      (0x01UL << FTM_SYNC_TRIG1_SHIFT)                    /*!< FTM0_SYNC: TRIG1 Mask                   */
#define FTM_SYNC_TRIG1_SHIFT                     5                                                   /*!< FTM0_SYNC: TRIG1 Position               */
#define FTM_SYNC_TRIG1(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_TRIG1_SHIFT))&FTM_SYNC_TRIG1_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_TRIG2_MASK                      (0x01UL << FTM_SYNC_TRIG2_SHIFT)                    /*!< FTM0_SYNC: TRIG2 Mask                   */
#define FTM_SYNC_TRIG2_SHIFT                     6                                                   /*!< FTM0_SYNC: TRIG2 Position               */
#define FTM_SYNC_TRIG2(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_TRIG2_SHIFT))&FTM_SYNC_TRIG2_MASK) /*!< FTM0_SYNC                               */
#define FTM_SYNC_SWSYNC_MASK                     (0x01UL << FTM_SYNC_SWSYNC_SHIFT)                   /*!< FTM0_SYNC: SWSYNC Mask                  */
#define FTM_SYNC_SWSYNC_SHIFT                    7                                                   /*!< FTM0_SYNC: SWSYNC Position              */
#define FTM_SYNC_SWSYNC(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_SWSYNC_SHIFT))&FTM_SYNC_SWSYNC_MASK) /*!< FTM0_SYNC                               */
/* ------- OUTINIT Bit Fields                       ------ */
#define FTM_OUTINIT_CH0OI_MASK                   (0x01UL << FTM_OUTINIT_CH0OI_SHIFT)                 /*!< FTM0_OUTINIT: CH0OI Mask                */
#define FTM_OUTINIT_CH0OI_SHIFT                  0                                                   /*!< FTM0_OUTINIT: CH0OI Position            */
#define FTM_OUTINIT_CH0OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH0OI_SHIFT))&FTM_OUTINIT_CH0OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH1OI_MASK                   (0x01UL << FTM_OUTINIT_CH1OI_SHIFT)                 /*!< FTM0_OUTINIT: CH1OI Mask                */
#define FTM_OUTINIT_CH1OI_SHIFT                  1                                                   /*!< FTM0_OUTINIT: CH1OI Position            */
#define FTM_OUTINIT_CH1OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH1OI_SHIFT))&FTM_OUTINIT_CH1OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH2OI_MASK                   (0x01UL << FTM_OUTINIT_CH2OI_SHIFT)                 /*!< FTM0_OUTINIT: CH2OI Mask                */
#define FTM_OUTINIT_CH2OI_SHIFT                  2                                                   /*!< FTM0_OUTINIT: CH2OI Position            */
#define FTM_OUTINIT_CH2OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH2OI_SHIFT))&FTM_OUTINIT_CH2OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH3OI_MASK                   (0x01UL << FTM_OUTINIT_CH3OI_SHIFT)                 /*!< FTM0_OUTINIT: CH3OI Mask                */
#define FTM_OUTINIT_CH3OI_SHIFT                  3                                                   /*!< FTM0_OUTINIT: CH3OI Position            */
#define FTM_OUTINIT_CH3OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH3OI_SHIFT))&FTM_OUTINIT_CH3OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH4OI_MASK                   (0x01UL << FTM_OUTINIT_CH4OI_SHIFT)                 /*!< FTM0_OUTINIT: CH4OI Mask                */
#define FTM_OUTINIT_CH4OI_SHIFT                  4                                                   /*!< FTM0_OUTINIT: CH4OI Position            */
#define FTM_OUTINIT_CH4OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH4OI_SHIFT))&FTM_OUTINIT_CH4OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH5OI_MASK                   (0x01UL << FTM_OUTINIT_CH5OI_SHIFT)                 /*!< FTM0_OUTINIT: CH5OI Mask                */
#define FTM_OUTINIT_CH5OI_SHIFT                  5                                                   /*!< FTM0_OUTINIT: CH5OI Position            */
#define FTM_OUTINIT_CH5OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH5OI_SHIFT))&FTM_OUTINIT_CH5OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH6OI_MASK                   (0x01UL << FTM_OUTINIT_CH6OI_SHIFT)                 /*!< FTM0_OUTINIT: CH6OI Mask                */
#define FTM_OUTINIT_CH6OI_SHIFT                  6                                                   /*!< FTM0_OUTINIT: CH6OI Position            */
#define FTM_OUTINIT_CH6OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH6OI_SHIFT))&FTM_OUTINIT_CH6OI_MASK) /*!< FTM0_OUTINIT                            */
#define FTM_OUTINIT_CH7OI_MASK                   (0x01UL << FTM_OUTINIT_CH7OI_SHIFT)                 /*!< FTM0_OUTINIT: CH7OI Mask                */
#define FTM_OUTINIT_CH7OI_SHIFT                  7                                                   /*!< FTM0_OUTINIT: CH7OI Position            */
#define FTM_OUTINIT_CH7OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH7OI_SHIFT))&FTM_OUTINIT_CH7OI_MASK) /*!< FTM0_OUTINIT                            */
/* ------- OUTMASK Bit Fields                       ------ */
#define FTM_OUTMASK_CH0OM_MASK                   (0x01UL << FTM_OUTMASK_CH0OM_SHIFT)                 /*!< FTM0_OUTMASK: CH0OM Mask                */
#define FTM_OUTMASK_CH0OM_SHIFT                  0                                                   /*!< FTM0_OUTMASK: CH0OM Position            */
#define FTM_OUTMASK_CH0OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH0OM_SHIFT))&FTM_OUTMASK_CH0OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH1OM_MASK                   (0x01UL << FTM_OUTMASK_CH1OM_SHIFT)                 /*!< FTM0_OUTMASK: CH1OM Mask                */
#define FTM_OUTMASK_CH1OM_SHIFT                  1                                                   /*!< FTM0_OUTMASK: CH1OM Position            */
#define FTM_OUTMASK_CH1OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH1OM_SHIFT))&FTM_OUTMASK_CH1OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH2OM_MASK                   (0x01UL << FTM_OUTMASK_CH2OM_SHIFT)                 /*!< FTM0_OUTMASK: CH2OM Mask                */
#define FTM_OUTMASK_CH2OM_SHIFT                  2                                                   /*!< FTM0_OUTMASK: CH2OM Position            */
#define FTM_OUTMASK_CH2OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH2OM_SHIFT))&FTM_OUTMASK_CH2OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH3OM_MASK                   (0x01UL << FTM_OUTMASK_CH3OM_SHIFT)                 /*!< FTM0_OUTMASK: CH3OM Mask                */
#define FTM_OUTMASK_CH3OM_SHIFT                  3                                                   /*!< FTM0_OUTMASK: CH3OM Position            */
#define FTM_OUTMASK_CH3OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH3OM_SHIFT))&FTM_OUTMASK_CH3OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH4OM_MASK                   (0x01UL << FTM_OUTMASK_CH4OM_SHIFT)                 /*!< FTM0_OUTMASK: CH4OM Mask                */
#define FTM_OUTMASK_CH4OM_SHIFT                  4                                                   /*!< FTM0_OUTMASK: CH4OM Position            */
#define FTM_OUTMASK_CH4OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH4OM_SHIFT))&FTM_OUTMASK_CH4OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH5OM_MASK                   (0x01UL << FTM_OUTMASK_CH5OM_SHIFT)                 /*!< FTM0_OUTMASK: CH5OM Mask                */
#define FTM_OUTMASK_CH5OM_SHIFT                  5                                                   /*!< FTM0_OUTMASK: CH5OM Position            */
#define FTM_OUTMASK_CH5OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH5OM_SHIFT))&FTM_OUTMASK_CH5OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH6OM_MASK                   (0x01UL << FTM_OUTMASK_CH6OM_SHIFT)                 /*!< FTM0_OUTMASK: CH6OM Mask                */
#define FTM_OUTMASK_CH6OM_SHIFT                  6                                                   /*!< FTM0_OUTMASK: CH6OM Position            */
#define FTM_OUTMASK_CH6OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH6OM_SHIFT))&FTM_OUTMASK_CH6OM_MASK) /*!< FTM0_OUTMASK                            */
#define FTM_OUTMASK_CH7OM_MASK                   (0x01UL << FTM_OUTMASK_CH7OM_SHIFT)                 /*!< FTM0_OUTMASK: CH7OM Mask                */
#define FTM_OUTMASK_CH7OM_SHIFT                  7                                                   /*!< FTM0_OUTMASK: CH7OM Position            */
#define FTM_OUTMASK_CH7OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH7OM_SHIFT))&FTM_OUTMASK_CH7OM_MASK) /*!< FTM0_OUTMASK                            */
/* ------- COMBINE Bit Fields                       ------ */
#define FTM_COMBINE_COMBINE0_MASK                (0x01UL << FTM_COMBINE_COMBINE0_SHIFT)              /*!< FTM0_COMBINE: COMBINE0 Mask             */
#define FTM_COMBINE_COMBINE0_SHIFT               0                                                   /*!< FTM0_COMBINE: COMBINE0 Position         */
#define FTM_COMBINE_COMBINE0(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE0_SHIFT))&FTM_COMBINE_COMBINE0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMP0_MASK                   (0x01UL << FTM_COMBINE_COMP0_SHIFT)                 /*!< FTM0_COMBINE: COMP0 Mask                */
#define FTM_COMBINE_COMP0_SHIFT                  1                                                   /*!< FTM0_COMBINE: COMP0 Position            */
#define FTM_COMBINE_COMP0(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMP0_SHIFT))&FTM_COMBINE_COMP0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAPEN0_MASK                (0x01UL << FTM_COMBINE_DECAPEN0_SHIFT)              /*!< FTM0_COMBINE: DECAPEN0 Mask             */
#define FTM_COMBINE_DECAPEN0_SHIFT               2                                                   /*!< FTM0_COMBINE: DECAPEN0 Position         */
#define FTM_COMBINE_DECAPEN0(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAPEN0_SHIFT))&FTM_COMBINE_DECAPEN0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAP0_MASK                  (0x01UL << FTM_COMBINE_DECAP0_SHIFT)                /*!< FTM0_COMBINE: DECAP0 Mask               */
#define FTM_COMBINE_DECAP0_SHIFT                 3                                                   /*!< FTM0_COMBINE: DECAP0 Position           */
#define FTM_COMBINE_DECAP0(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAP0_SHIFT))&FTM_COMBINE_DECAP0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DTEN0_MASK                   (0x01UL << FTM_COMBINE_DTEN0_SHIFT)                 /*!< FTM0_COMBINE: DTEN0 Mask                */
#define FTM_COMBINE_DTEN0_SHIFT                  4                                                   /*!< FTM0_COMBINE: DTEN0 Position            */
#define FTM_COMBINE_DTEN0(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DTEN0_SHIFT))&FTM_COMBINE_DTEN0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_SYNCEN0_MASK                 (0x01UL << FTM_COMBINE_SYNCEN0_SHIFT)               /*!< FTM0_COMBINE: SYNCEN0 Mask              */
#define FTM_COMBINE_SYNCEN0_SHIFT                5                                                   /*!< FTM0_COMBINE: SYNCEN0 Position          */
#define FTM_COMBINE_SYNCEN0(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_SYNCEN0_SHIFT))&FTM_COMBINE_SYNCEN0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_FAULTEN0_MASK                (0x01UL << FTM_COMBINE_FAULTEN0_SHIFT)              /*!< FTM0_COMBINE: FAULTEN0 Mask             */
#define FTM_COMBINE_FAULTEN0_SHIFT               6                                                   /*!< FTM0_COMBINE: FAULTEN0 Position         */
#define FTM_COMBINE_FAULTEN0(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_FAULTEN0_SHIFT))&FTM_COMBINE_FAULTEN0_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMBINE1_MASK                (0x01UL << FTM_COMBINE_COMBINE1_SHIFT)              /*!< FTM0_COMBINE: COMBINE1 Mask             */
#define FTM_COMBINE_COMBINE1_SHIFT               8                                                   /*!< FTM0_COMBINE: COMBINE1 Position         */
#define FTM_COMBINE_COMBINE1(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE1_SHIFT))&FTM_COMBINE_COMBINE1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMP1_MASK                   (0x01UL << FTM_COMBINE_COMP1_SHIFT)                 /*!< FTM0_COMBINE: COMP1 Mask                */
#define FTM_COMBINE_COMP1_SHIFT                  9                                                   /*!< FTM0_COMBINE: COMP1 Position            */
#define FTM_COMBINE_COMP1(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMP1_SHIFT))&FTM_COMBINE_COMP1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAPEN1_MASK                (0x01UL << FTM_COMBINE_DECAPEN1_SHIFT)              /*!< FTM0_COMBINE: DECAPEN1 Mask             */
#define FTM_COMBINE_DECAPEN1_SHIFT               10                                                  /*!< FTM0_COMBINE: DECAPEN1 Position         */
#define FTM_COMBINE_DECAPEN1(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAPEN1_SHIFT))&FTM_COMBINE_DECAPEN1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAP1_MASK                  (0x01UL << FTM_COMBINE_DECAP1_SHIFT)                /*!< FTM0_COMBINE: DECAP1 Mask               */
#define FTM_COMBINE_DECAP1_SHIFT                 11                                                  /*!< FTM0_COMBINE: DECAP1 Position           */
#define FTM_COMBINE_DECAP1(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAP1_SHIFT))&FTM_COMBINE_DECAP1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DTEN1_MASK                   (0x01UL << FTM_COMBINE_DTEN1_SHIFT)                 /*!< FTM0_COMBINE: DTEN1 Mask                */
#define FTM_COMBINE_DTEN1_SHIFT                  12                                                  /*!< FTM0_COMBINE: DTEN1 Position            */
#define FTM_COMBINE_DTEN1(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DTEN1_SHIFT))&FTM_COMBINE_DTEN1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_SYNCEN1_MASK                 (0x01UL << FTM_COMBINE_SYNCEN1_SHIFT)               /*!< FTM0_COMBINE: SYNCEN1 Mask              */
#define FTM_COMBINE_SYNCEN1_SHIFT                13                                                  /*!< FTM0_COMBINE: SYNCEN1 Position          */
#define FTM_COMBINE_SYNCEN1(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_SYNCEN1_SHIFT))&FTM_COMBINE_SYNCEN1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_FAULTEN1_MASK                (0x01UL << FTM_COMBINE_FAULTEN1_SHIFT)              /*!< FTM0_COMBINE: FAULTEN1 Mask             */
#define FTM_COMBINE_FAULTEN1_SHIFT               14                                                  /*!< FTM0_COMBINE: FAULTEN1 Position         */
#define FTM_COMBINE_FAULTEN1(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_FAULTEN1_SHIFT))&FTM_COMBINE_FAULTEN1_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMBINE2_MASK                (0x01UL << FTM_COMBINE_COMBINE2_SHIFT)              /*!< FTM0_COMBINE: COMBINE2 Mask             */
#define FTM_COMBINE_COMBINE2_SHIFT               16                                                  /*!< FTM0_COMBINE: COMBINE2 Position         */
#define FTM_COMBINE_COMBINE2(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE2_SHIFT))&FTM_COMBINE_COMBINE2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMP2_MASK                   (0x01UL << FTM_COMBINE_COMP2_SHIFT)                 /*!< FTM0_COMBINE: COMP2 Mask                */
#define FTM_COMBINE_COMP2_SHIFT                  17                                                  /*!< FTM0_COMBINE: COMP2 Position            */
#define FTM_COMBINE_COMP2(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMP2_SHIFT))&FTM_COMBINE_COMP2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAPEN2_MASK                (0x01UL << FTM_COMBINE_DECAPEN2_SHIFT)              /*!< FTM0_COMBINE: DECAPEN2 Mask             */
#define FTM_COMBINE_DECAPEN2_SHIFT               18                                                  /*!< FTM0_COMBINE: DECAPEN2 Position         */
#define FTM_COMBINE_DECAPEN2(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAPEN2_SHIFT))&FTM_COMBINE_DECAPEN2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAP2_MASK                  (0x01UL << FTM_COMBINE_DECAP2_SHIFT)                /*!< FTM0_COMBINE: DECAP2 Mask               */
#define FTM_COMBINE_DECAP2_SHIFT                 19                                                  /*!< FTM0_COMBINE: DECAP2 Position           */
#define FTM_COMBINE_DECAP2(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAP2_SHIFT))&FTM_COMBINE_DECAP2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DTEN2_MASK                   (0x01UL << FTM_COMBINE_DTEN2_SHIFT)                 /*!< FTM0_COMBINE: DTEN2 Mask                */
#define FTM_COMBINE_DTEN2_SHIFT                  20                                                  /*!< FTM0_COMBINE: DTEN2 Position            */
#define FTM_COMBINE_DTEN2(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DTEN2_SHIFT))&FTM_COMBINE_DTEN2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_SYNCEN2_MASK                 (0x01UL << FTM_COMBINE_SYNCEN2_SHIFT)               /*!< FTM0_COMBINE: SYNCEN2 Mask              */
#define FTM_COMBINE_SYNCEN2_SHIFT                21                                                  /*!< FTM0_COMBINE: SYNCEN2 Position          */
#define FTM_COMBINE_SYNCEN2(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_SYNCEN2_SHIFT))&FTM_COMBINE_SYNCEN2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_FAULTEN2_MASK                (0x01UL << FTM_COMBINE_FAULTEN2_SHIFT)              /*!< FTM0_COMBINE: FAULTEN2 Mask             */
#define FTM_COMBINE_FAULTEN2_SHIFT               22                                                  /*!< FTM0_COMBINE: FAULTEN2 Position         */
#define FTM_COMBINE_FAULTEN2(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_FAULTEN2_SHIFT))&FTM_COMBINE_FAULTEN2_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMBINE3_MASK                (0x01UL << FTM_COMBINE_COMBINE3_SHIFT)              /*!< FTM0_COMBINE: COMBINE3 Mask             */
#define FTM_COMBINE_COMBINE3_SHIFT               24                                                  /*!< FTM0_COMBINE: COMBINE3 Position         */
#define FTM_COMBINE_COMBINE3(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE3_SHIFT))&FTM_COMBINE_COMBINE3_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_COMP3_MASK                   (0x01UL << FTM_COMBINE_COMP3_SHIFT)                 /*!< FTM0_COMBINE: COMP3 Mask                */
#define FTM_COMBINE_COMP3_SHIFT                  25                                                  /*!< FTM0_COMBINE: COMP3 Position            */
#define FTM_COMBINE_COMP3(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMP3_SHIFT))&FTM_COMBINE_COMP3_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAPEN3_MASK                (0x01UL << FTM_COMBINE_DECAPEN3_SHIFT)              /*!< FTM0_COMBINE: DECAPEN3 Mask             */
#define FTM_COMBINE_DECAPEN3_SHIFT               26                                                  /*!< FTM0_COMBINE: DECAPEN3 Position         */
#define FTM_COMBINE_DECAPEN3(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAPEN3_SHIFT))&FTM_COMBINE_DECAPEN3_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DECAP3_MASK                  (0x01UL << FTM_COMBINE_DECAP3_SHIFT)                /*!< FTM0_COMBINE: DECAP3 Mask               */
#define FTM_COMBINE_DECAP3_SHIFT                 27                                                  /*!< FTM0_COMBINE: DECAP3 Position           */
#define FTM_COMBINE_DECAP3(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAP3_SHIFT))&FTM_COMBINE_DECAP3_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_DTEN3_MASK                   (0x01UL << FTM_COMBINE_DTEN3_SHIFT)                 /*!< FTM0_COMBINE: DTEN3 Mask                */
#define FTM_COMBINE_DTEN3_SHIFT                  28                                                  /*!< FTM0_COMBINE: DTEN3 Position            */
#define FTM_COMBINE_DTEN3(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DTEN3_SHIFT))&FTM_COMBINE_DTEN3_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_SYNCEN3_MASK                 (0x01UL << FTM_COMBINE_SYNCEN3_SHIFT)               /*!< FTM0_COMBINE: SYNCEN3 Mask              */
#define FTM_COMBINE_SYNCEN3_SHIFT                29                                                  /*!< FTM0_COMBINE: SYNCEN3 Position          */
#define FTM_COMBINE_SYNCEN3(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_SYNCEN3_SHIFT))&FTM_COMBINE_SYNCEN3_MASK) /*!< FTM0_COMBINE                            */
#define FTM_COMBINE_FAULTEN3_MASK                (0x01UL << FTM_COMBINE_FAULTEN3_SHIFT)              /*!< FTM0_COMBINE: FAULTEN3 Mask             */
#define FTM_COMBINE_FAULTEN3_SHIFT               30                                                  /*!< FTM0_COMBINE: FAULTEN3 Position         */
#define FTM_COMBINE_FAULTEN3(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_FAULTEN3_SHIFT))&FTM_COMBINE_FAULTEN3_MASK) /*!< FTM0_COMBINE                            */
/* ------- DEADTIME Bit Fields                      ------ */
#define FTM_DEADTIME_DTVAL_MASK                  (0x3FUL << FTM_DEADTIME_DTVAL_SHIFT)                /*!< FTM0_DEADTIME: DTVAL Mask               */
#define FTM_DEADTIME_DTVAL_SHIFT                 0                                                   /*!< FTM0_DEADTIME: DTVAL Position           */
#define FTM_DEADTIME_DTVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_DEADTIME_DTVAL_SHIFT))&FTM_DEADTIME_DTVAL_MASK) /*!< FTM0_DEADTIME                           */
#define FTM_DEADTIME_DTPS_MASK                   (0x03UL << FTM_DEADTIME_DTPS_SHIFT)                 /*!< FTM0_DEADTIME: DTPS Mask                */
#define FTM_DEADTIME_DTPS_SHIFT                  6                                                   /*!< FTM0_DEADTIME: DTPS Position            */
#define FTM_DEADTIME_DTPS(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_DEADTIME_DTPS_SHIFT))&FTM_DEADTIME_DTPS_MASK) /*!< FTM0_DEADTIME                           */
/* ------- EXTTRIG Bit Fields                       ------ */
#define FTM_EXTTRIG_CH2TRIG_MASK                 (0x01UL << FTM_EXTTRIG_CH2TRIG_SHIFT)               /*!< FTM0_EXTTRIG: CH2TRIG Mask              */
#define FTM_EXTTRIG_CH2TRIG_SHIFT                0                                                   /*!< FTM0_EXTTRIG: CH2TRIG Position          */
#define FTM_EXTTRIG_CH2TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH2TRIG_SHIFT))&FTM_EXTTRIG_CH2TRIG_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_CH3TRIG_MASK                 (0x01UL << FTM_EXTTRIG_CH3TRIG_SHIFT)               /*!< FTM0_EXTTRIG: CH3TRIG Mask              */
#define FTM_EXTTRIG_CH3TRIG_SHIFT                1                                                   /*!< FTM0_EXTTRIG: CH3TRIG Position          */
#define FTM_EXTTRIG_CH3TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH3TRIG_SHIFT))&FTM_EXTTRIG_CH3TRIG_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_CH4TRIG_MASK                 (0x01UL << FTM_EXTTRIG_CH4TRIG_SHIFT)               /*!< FTM0_EXTTRIG: CH4TRIG Mask              */
#define FTM_EXTTRIG_CH4TRIG_SHIFT                2                                                   /*!< FTM0_EXTTRIG: CH4TRIG Position          */
#define FTM_EXTTRIG_CH4TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH4TRIG_SHIFT))&FTM_EXTTRIG_CH4TRIG_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_CH5TRIG_MASK                 (0x01UL << FTM_EXTTRIG_CH5TRIG_SHIFT)               /*!< FTM0_EXTTRIG: CH5TRIG Mask              */
#define FTM_EXTTRIG_CH5TRIG_SHIFT                3                                                   /*!< FTM0_EXTTRIG: CH5TRIG Position          */
#define FTM_EXTTRIG_CH5TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH5TRIG_SHIFT))&FTM_EXTTRIG_CH5TRIG_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_CH0TRIG_MASK                 (0x01UL << FTM_EXTTRIG_CH0TRIG_SHIFT)               /*!< FTM0_EXTTRIG: CH0TRIG Mask              */
#define FTM_EXTTRIG_CH0TRIG_SHIFT                4                                                   /*!< FTM0_EXTTRIG: CH0TRIG Position          */
#define FTM_EXTTRIG_CH0TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH0TRIG_SHIFT))&FTM_EXTTRIG_CH0TRIG_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_CH1TRIG_MASK                 (0x01UL << FTM_EXTTRIG_CH1TRIG_SHIFT)               /*!< FTM0_EXTTRIG: CH1TRIG Mask              */
#define FTM_EXTTRIG_CH1TRIG_SHIFT                5                                                   /*!< FTM0_EXTTRIG: CH1TRIG Position          */
#define FTM_EXTTRIG_CH1TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH1TRIG_SHIFT))&FTM_EXTTRIG_CH1TRIG_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_INITTRIGEN_MASK              (0x01UL << FTM_EXTTRIG_INITTRIGEN_SHIFT)            /*!< FTM0_EXTTRIG: INITTRIGEN Mask           */
#define FTM_EXTTRIG_INITTRIGEN_SHIFT             6                                                   /*!< FTM0_EXTTRIG: INITTRIGEN Position       */
#define FTM_EXTTRIG_INITTRIGEN(x)                (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_INITTRIGEN_SHIFT))&FTM_EXTTRIG_INITTRIGEN_MASK) /*!< FTM0_EXTTRIG                            */
#define FTM_EXTTRIG_TRIGF_MASK                   (0x01UL << FTM_EXTTRIG_TRIGF_SHIFT)                 /*!< FTM0_EXTTRIG: TRIGF Mask                */
#define FTM_EXTTRIG_TRIGF_SHIFT                  7                                                   /*!< FTM0_EXTTRIG: TRIGF Position            */
#define FTM_EXTTRIG_TRIGF(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_TRIGF_SHIFT))&FTM_EXTTRIG_TRIGF_MASK) /*!< FTM0_EXTTRIG                            */
/* ------- POL Bit Fields                           ------ */
#define FTM_POL_POL0_MASK                        (0x01UL << FTM_POL_POL0_SHIFT)                      /*!< FTM0_POL: POL0 Mask                     */
#define FTM_POL_POL0_SHIFT                       0                                                   /*!< FTM0_POL: POL0 Position                 */
#define FTM_POL_POL0(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL0_SHIFT))&FTM_POL_POL0_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL1_MASK                        (0x01UL << FTM_POL_POL1_SHIFT)                      /*!< FTM0_POL: POL1 Mask                     */
#define FTM_POL_POL1_SHIFT                       1                                                   /*!< FTM0_POL: POL1 Position                 */
#define FTM_POL_POL1(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL1_SHIFT))&FTM_POL_POL1_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL2_MASK                        (0x01UL << FTM_POL_POL2_SHIFT)                      /*!< FTM0_POL: POL2 Mask                     */
#define FTM_POL_POL2_SHIFT                       2                                                   /*!< FTM0_POL: POL2 Position                 */
#define FTM_POL_POL2(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL2_SHIFT))&FTM_POL_POL2_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL3_MASK                        (0x01UL << FTM_POL_POL3_SHIFT)                      /*!< FTM0_POL: POL3 Mask                     */
#define FTM_POL_POL3_SHIFT                       3                                                   /*!< FTM0_POL: POL3 Position                 */
#define FTM_POL_POL3(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL3_SHIFT))&FTM_POL_POL3_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL4_MASK                        (0x01UL << FTM_POL_POL4_SHIFT)                      /*!< FTM0_POL: POL4 Mask                     */
#define FTM_POL_POL4_SHIFT                       4                                                   /*!< FTM0_POL: POL4 Position                 */
#define FTM_POL_POL4(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL4_SHIFT))&FTM_POL_POL4_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL5_MASK                        (0x01UL << FTM_POL_POL5_SHIFT)                      /*!< FTM0_POL: POL5 Mask                     */
#define FTM_POL_POL5_SHIFT                       5                                                   /*!< FTM0_POL: POL5 Position                 */
#define FTM_POL_POL5(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL5_SHIFT))&FTM_POL_POL5_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL6_MASK                        (0x01UL << FTM_POL_POL6_SHIFT)                      /*!< FTM0_POL: POL6 Mask                     */
#define FTM_POL_POL6_SHIFT                       6                                                   /*!< FTM0_POL: POL6 Position                 */
#define FTM_POL_POL6(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL6_SHIFT))&FTM_POL_POL6_MASK) /*!< FTM0_POL                                */
#define FTM_POL_POL7_MASK                        (0x01UL << FTM_POL_POL7_SHIFT)                      /*!< FTM0_POL: POL7 Mask                     */
#define FTM_POL_POL7_SHIFT                       7                                                   /*!< FTM0_POL: POL7 Position                 */
#define FTM_POL_POL7(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL7_SHIFT))&FTM_POL_POL7_MASK) /*!< FTM0_POL                                */
/* ------- FMS Bit Fields                           ------ */
#define FTM_FMS_FAULTF0_MASK                     (0x01UL << FTM_FMS_FAULTF0_SHIFT)                   /*!< FTM0_FMS: FAULTF0 Mask                  */
#define FTM_FMS_FAULTF0_SHIFT                    0                                                   /*!< FTM0_FMS: FAULTF0 Position              */
#define FTM_FMS_FAULTF0(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF0_SHIFT))&FTM_FMS_FAULTF0_MASK) /*!< FTM0_FMS                                */
#define FTM_FMS_FAULTF1_MASK                     (0x01UL << FTM_FMS_FAULTF1_SHIFT)                   /*!< FTM0_FMS: FAULTF1 Mask                  */
#define FTM_FMS_FAULTF1_SHIFT                    1                                                   /*!< FTM0_FMS: FAULTF1 Position              */
#define FTM_FMS_FAULTF1(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF1_SHIFT))&FTM_FMS_FAULTF1_MASK) /*!< FTM0_FMS                                */
#define FTM_FMS_FAULTF2_MASK                     (0x01UL << FTM_FMS_FAULTF2_SHIFT)                   /*!< FTM0_FMS: FAULTF2 Mask                  */
#define FTM_FMS_FAULTF2_SHIFT                    2                                                   /*!< FTM0_FMS: FAULTF2 Position              */
#define FTM_FMS_FAULTF2(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF2_SHIFT))&FTM_FMS_FAULTF2_MASK) /*!< FTM0_FMS                                */
#define FTM_FMS_FAULTF3_MASK                     (0x01UL << FTM_FMS_FAULTF3_SHIFT)                   /*!< FTM0_FMS: FAULTF3 Mask                  */
#define FTM_FMS_FAULTF3_SHIFT                    3                                                   /*!< FTM0_FMS: FAULTF3 Position              */
#define FTM_FMS_FAULTF3(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF3_SHIFT))&FTM_FMS_FAULTF3_MASK) /*!< FTM0_FMS                                */
#define FTM_FMS_FAULTIN_MASK                     (0x01UL << FTM_FMS_FAULTIN_SHIFT)                   /*!< FTM0_FMS: FAULTIN Mask                  */
#define FTM_FMS_FAULTIN_SHIFT                    5                                                   /*!< FTM0_FMS: FAULTIN Position              */
#define FTM_FMS_FAULTIN(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTIN_SHIFT))&FTM_FMS_FAULTIN_MASK) /*!< FTM0_FMS                                */
#define FTM_FMS_WPEN_MASK                        (0x01UL << FTM_FMS_WPEN_SHIFT)                      /*!< FTM0_FMS: WPEN Mask                     */
#define FTM_FMS_WPEN_SHIFT                       6                                                   /*!< FTM0_FMS: WPEN Position                 */
#define FTM_FMS_WPEN(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_FMS_WPEN_SHIFT))&FTM_FMS_WPEN_MASK) /*!< FTM0_FMS                                */
#define FTM_FMS_FAULTF_MASK                      (0x01UL << FTM_FMS_FAULTF_SHIFT)                    /*!< FTM0_FMS: FAULTF Mask                   */
#define FTM_FMS_FAULTF_SHIFT                     7                                                   /*!< FTM0_FMS: FAULTF Position               */
#define FTM_FMS_FAULTF(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF_SHIFT))&FTM_FMS_FAULTF_MASK) /*!< FTM0_FMS                                */
/* ------- FILTER Bit Fields                        ------ */
#define FTM_FILTER_CH0FVAL_MASK                  (0x0FUL << FTM_FILTER_CH0FVAL_SHIFT)                /*!< FTM0_FILTER: CH0FVAL Mask               */
#define FTM_FILTER_CH0FVAL_SHIFT                 0                                                   /*!< FTM0_FILTER: CH0FVAL Position           */
#define FTM_FILTER_CH0FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH0FVAL_SHIFT))&FTM_FILTER_CH0FVAL_MASK) /*!< FTM0_FILTER                             */
#define FTM_FILTER_CH1FVAL_MASK                  (0x0FUL << FTM_FILTER_CH1FVAL_SHIFT)                /*!< FTM0_FILTER: CH1FVAL Mask               */
#define FTM_FILTER_CH1FVAL_SHIFT                 4                                                   /*!< FTM0_FILTER: CH1FVAL Position           */
#define FTM_FILTER_CH1FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH1FVAL_SHIFT))&FTM_FILTER_CH1FVAL_MASK) /*!< FTM0_FILTER                             */
#define FTM_FILTER_CH2FVAL_MASK                  (0x0FUL << FTM_FILTER_CH2FVAL_SHIFT)                /*!< FTM0_FILTER: CH2FVAL Mask               */
#define FTM_FILTER_CH2FVAL_SHIFT                 8                                                   /*!< FTM0_FILTER: CH2FVAL Position           */
#define FTM_FILTER_CH2FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH2FVAL_SHIFT))&FTM_FILTER_CH2FVAL_MASK) /*!< FTM0_FILTER                             */
#define FTM_FILTER_CH3FVAL_MASK                  (0x0FUL << FTM_FILTER_CH3FVAL_SHIFT)                /*!< FTM0_FILTER: CH3FVAL Mask               */
#define FTM_FILTER_CH3FVAL_SHIFT                 12                                                  /*!< FTM0_FILTER: CH3FVAL Position           */
#define FTM_FILTER_CH3FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH3FVAL_SHIFT))&FTM_FILTER_CH3FVAL_MASK) /*!< FTM0_FILTER                             */
/* ------- FLTCTRL Bit Fields                       ------ */
#define FTM_FLTCTRL_FAULT0EN_MASK                (0x01UL << FTM_FLTCTRL_FAULT0EN_SHIFT)              /*!< FTM0_FLTCTRL: FAULT0EN Mask             */
#define FTM_FLTCTRL_FAULT0EN_SHIFT               0                                                   /*!< FTM0_FLTCTRL: FAULT0EN Position         */
#define FTM_FLTCTRL_FAULT0EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT0EN_SHIFT))&FTM_FLTCTRL_FAULT0EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FAULT1EN_MASK                (0x01UL << FTM_FLTCTRL_FAULT1EN_SHIFT)              /*!< FTM0_FLTCTRL: FAULT1EN Mask             */
#define FTM_FLTCTRL_FAULT1EN_SHIFT               1                                                   /*!< FTM0_FLTCTRL: FAULT1EN Position         */
#define FTM_FLTCTRL_FAULT1EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT1EN_SHIFT))&FTM_FLTCTRL_FAULT1EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FAULT2EN_MASK                (0x01UL << FTM_FLTCTRL_FAULT2EN_SHIFT)              /*!< FTM0_FLTCTRL: FAULT2EN Mask             */
#define FTM_FLTCTRL_FAULT2EN_SHIFT               2                                                   /*!< FTM0_FLTCTRL: FAULT2EN Position         */
#define FTM_FLTCTRL_FAULT2EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT2EN_SHIFT))&FTM_FLTCTRL_FAULT2EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FAULT3EN_MASK                (0x01UL << FTM_FLTCTRL_FAULT3EN_SHIFT)              /*!< FTM0_FLTCTRL: FAULT3EN Mask             */
#define FTM_FLTCTRL_FAULT3EN_SHIFT               3                                                   /*!< FTM0_FLTCTRL: FAULT3EN Position         */
#define FTM_FLTCTRL_FAULT3EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT3EN_SHIFT))&FTM_FLTCTRL_FAULT3EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FFLTR0EN_MASK                (0x01UL << FTM_FLTCTRL_FFLTR0EN_SHIFT)              /*!< FTM0_FLTCTRL: FFLTR0EN Mask             */
#define FTM_FLTCTRL_FFLTR0EN_SHIFT               4                                                   /*!< FTM0_FLTCTRL: FFLTR0EN Position         */
#define FTM_FLTCTRL_FFLTR0EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR0EN_SHIFT))&FTM_FLTCTRL_FFLTR0EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FFLTR1EN_MASK                (0x01UL << FTM_FLTCTRL_FFLTR1EN_SHIFT)              /*!< FTM0_FLTCTRL: FFLTR1EN Mask             */
#define FTM_FLTCTRL_FFLTR1EN_SHIFT               5                                                   /*!< FTM0_FLTCTRL: FFLTR1EN Position         */
#define FTM_FLTCTRL_FFLTR1EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR1EN_SHIFT))&FTM_FLTCTRL_FFLTR1EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FFLTR2EN_MASK                (0x01UL << FTM_FLTCTRL_FFLTR2EN_SHIFT)              /*!< FTM0_FLTCTRL: FFLTR2EN Mask             */
#define FTM_FLTCTRL_FFLTR2EN_SHIFT               6                                                   /*!< FTM0_FLTCTRL: FFLTR2EN Position         */
#define FTM_FLTCTRL_FFLTR2EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR2EN_SHIFT))&FTM_FLTCTRL_FFLTR2EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FFLTR3EN_MASK                (0x01UL << FTM_FLTCTRL_FFLTR3EN_SHIFT)              /*!< FTM0_FLTCTRL: FFLTR3EN Mask             */
#define FTM_FLTCTRL_FFLTR3EN_SHIFT               7                                                   /*!< FTM0_FLTCTRL: FFLTR3EN Position         */
#define FTM_FLTCTRL_FFLTR3EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR3EN_SHIFT))&FTM_FLTCTRL_FFLTR3EN_MASK) /*!< FTM0_FLTCTRL                            */
#define FTM_FLTCTRL_FFVAL_MASK                   (0x0FUL << FTM_FLTCTRL_FFVAL_SHIFT)                 /*!< FTM0_FLTCTRL: FFVAL Mask                */
#define FTM_FLTCTRL_FFVAL_SHIFT                  8                                                   /*!< FTM0_FLTCTRL: FFVAL Position            */
#define FTM_FLTCTRL_FFVAL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFVAL_SHIFT))&FTM_FLTCTRL_FFVAL_MASK) /*!< FTM0_FLTCTRL                            */
/* ------- QDCTRL Bit Fields                        ------ */
#define FTM_QDCTRL_QUADEN_MASK                   (0x01UL << FTM_QDCTRL_QUADEN_SHIFT)                 /*!< FTM0_QDCTRL: QUADEN Mask                */
#define FTM_QDCTRL_QUADEN_SHIFT                  0                                                   /*!< FTM0_QDCTRL: QUADEN Position            */
#define FTM_QDCTRL_QUADEN(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_QUADEN_SHIFT))&FTM_QDCTRL_QUADEN_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_TOFDIR_MASK                   (0x01UL << FTM_QDCTRL_TOFDIR_SHIFT)                 /*!< FTM0_QDCTRL: TOFDIR Mask                */
#define FTM_QDCTRL_TOFDIR_SHIFT                  1                                                   /*!< FTM0_QDCTRL: TOFDIR Position            */
#define FTM_QDCTRL_TOFDIR(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_TOFDIR_SHIFT))&FTM_QDCTRL_TOFDIR_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_QUADIR_MASK                   (0x01UL << FTM_QDCTRL_QUADIR_SHIFT)                 /*!< FTM0_QDCTRL: QUADIR Mask                */
#define FTM_QDCTRL_QUADIR_SHIFT                  2                                                   /*!< FTM0_QDCTRL: QUADIR Position            */
#define FTM_QDCTRL_QUADIR(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_QUADIR_SHIFT))&FTM_QDCTRL_QUADIR_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_QUADMODE_MASK                 (0x01UL << FTM_QDCTRL_QUADMODE_SHIFT)               /*!< FTM0_QDCTRL: QUADMODE Mask              */
#define FTM_QDCTRL_QUADMODE_SHIFT                3                                                   /*!< FTM0_QDCTRL: QUADMODE Position          */
#define FTM_QDCTRL_QUADMODE(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_QUADMODE_SHIFT))&FTM_QDCTRL_QUADMODE_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_PHBPOL_MASK                   (0x01UL << FTM_QDCTRL_PHBPOL_SHIFT)                 /*!< FTM0_QDCTRL: PHBPOL Mask                */
#define FTM_QDCTRL_PHBPOL_SHIFT                  4                                                   /*!< FTM0_QDCTRL: PHBPOL Position            */
#define FTM_QDCTRL_PHBPOL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_PHBPOL_SHIFT))&FTM_QDCTRL_PHBPOL_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_PHAPOL_MASK                   (0x01UL << FTM_QDCTRL_PHAPOL_SHIFT)                 /*!< FTM0_QDCTRL: PHAPOL Mask                */
#define FTM_QDCTRL_PHAPOL_SHIFT                  5                                                   /*!< FTM0_QDCTRL: PHAPOL Position            */
#define FTM_QDCTRL_PHAPOL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_PHAPOL_SHIFT))&FTM_QDCTRL_PHAPOL_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_PHBFLTREN_MASK                (0x01UL << FTM_QDCTRL_PHBFLTREN_SHIFT)              /*!< FTM0_QDCTRL: PHBFLTREN Mask             */
#define FTM_QDCTRL_PHBFLTREN_SHIFT               6                                                   /*!< FTM0_QDCTRL: PHBFLTREN Position         */
#define FTM_QDCTRL_PHBFLTREN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_PHBFLTREN_SHIFT))&FTM_QDCTRL_PHBFLTREN_MASK) /*!< FTM0_QDCTRL                             */
#define FTM_QDCTRL_PHAFLTREN_MASK                (0x01UL << FTM_QDCTRL_PHAFLTREN_SHIFT)              /*!< FTM0_QDCTRL: PHAFLTREN Mask             */
#define FTM_QDCTRL_PHAFLTREN_SHIFT               7                                                   /*!< FTM0_QDCTRL: PHAFLTREN Position         */
#define FTM_QDCTRL_PHAFLTREN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_PHAFLTREN_SHIFT))&FTM_QDCTRL_PHAFLTREN_MASK) /*!< FTM0_QDCTRL                             */
/* ------- CONF Bit Fields                          ------ */
#define FTM_CONF_NUMTOF_MASK                     (0x1FUL << FTM_CONF_NUMTOF_SHIFT)                   /*!< FTM0_CONF: NUMTOF Mask                  */
#define FTM_CONF_NUMTOF_SHIFT                    0                                                   /*!< FTM0_CONF: NUMTOF Position              */
#define FTM_CONF_NUMTOF(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_CONF_NUMTOF_SHIFT))&FTM_CONF_NUMTOF_MASK) /*!< FTM0_CONF                               */
#define FTM_CONF_BDMMODE_MASK                    (0x03UL << FTM_CONF_BDMMODE_SHIFT)                  /*!< FTM0_CONF: BDMMODE Mask                 */
#define FTM_CONF_BDMMODE_SHIFT                   6                                                   /*!< FTM0_CONF: BDMMODE Position             */
#define FTM_CONF_BDMMODE(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_CONF_BDMMODE_SHIFT))&FTM_CONF_BDMMODE_MASK) /*!< FTM0_CONF                               */
#define FTM_CONF_GTBEEN_MASK                     (0x01UL << FTM_CONF_GTBEEN_SHIFT)                   /*!< FTM0_CONF: GTBEEN Mask                  */
#define FTM_CONF_GTBEEN_SHIFT                    9                                                   /*!< FTM0_CONF: GTBEEN Position              */
#define FTM_CONF_GTBEEN(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_CONF_GTBEEN_SHIFT))&FTM_CONF_GTBEEN_MASK) /*!< FTM0_CONF                               */
#define FTM_CONF_GTBEOUT_MASK                    (0x01UL << FTM_CONF_GTBEOUT_SHIFT)                  /*!< FTM0_CONF: GTBEOUT Mask                 */
#define FTM_CONF_GTBEOUT_SHIFT                   10                                                  /*!< FTM0_CONF: GTBEOUT Position             */
#define FTM_CONF_GTBEOUT(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_CONF_GTBEOUT_SHIFT))&FTM_CONF_GTBEOUT_MASK) /*!< FTM0_CONF                               */
/* ------- FLTPOL Bit Fields                        ------ */
#define FTM_FLTPOL_FLT0POL_MASK                  (0x01UL << FTM_FLTPOL_FLT0POL_SHIFT)                /*!< FTM0_FLTPOL: FLT0POL Mask               */
#define FTM_FLTPOL_FLT0POL_SHIFT                 0                                                   /*!< FTM0_FLTPOL: FLT0POL Position           */
#define FTM_FLTPOL_FLT0POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT0POL_SHIFT))&FTM_FLTPOL_FLT0POL_MASK) /*!< FTM0_FLTPOL                             */
#define FTM_FLTPOL_FLT1POL_MASK                  (0x01UL << FTM_FLTPOL_FLT1POL_SHIFT)                /*!< FTM0_FLTPOL: FLT1POL Mask               */
#define FTM_FLTPOL_FLT1POL_SHIFT                 1                                                   /*!< FTM0_FLTPOL: FLT1POL Position           */
#define FTM_FLTPOL_FLT1POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT1POL_SHIFT))&FTM_FLTPOL_FLT1POL_MASK) /*!< FTM0_FLTPOL                             */
#define FTM_FLTPOL_FLT2POL_MASK                  (0x01UL << FTM_FLTPOL_FLT2POL_SHIFT)                /*!< FTM0_FLTPOL: FLT2POL Mask               */
#define FTM_FLTPOL_FLT2POL_SHIFT                 2                                                   /*!< FTM0_FLTPOL: FLT2POL Position           */
#define FTM_FLTPOL_FLT2POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT2POL_SHIFT))&FTM_FLTPOL_FLT2POL_MASK) /*!< FTM0_FLTPOL                             */
#define FTM_FLTPOL_FLT3POL_MASK                  (0x01UL << FTM_FLTPOL_FLT3POL_SHIFT)                /*!< FTM0_FLTPOL: FLT3POL Mask               */
#define FTM_FLTPOL_FLT3POL_SHIFT                 3                                                   /*!< FTM0_FLTPOL: FLT3POL Position           */
#define FTM_FLTPOL_FLT3POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT3POL_SHIFT))&FTM_FLTPOL_FLT3POL_MASK) /*!< FTM0_FLTPOL                             */
/* ------- SYNCONF Bit Fields                       ------ */
#define FTM_SYNCONF_HWTRIGMODE_MASK              (0x01UL << FTM_SYNCONF_HWTRIGMODE_SHIFT)            /*!< FTM0_SYNCONF: HWTRIGMODE Mask           */
#define FTM_SYNCONF_HWTRIGMODE_SHIFT             0                                                   /*!< FTM0_SYNCONF: HWTRIGMODE Position       */
#define FTM_SYNCONF_HWTRIGMODE(x)                (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWTRIGMODE_SHIFT))&FTM_SYNCONF_HWTRIGMODE_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_CNTINC_MASK                  (0x01UL << FTM_SYNCONF_CNTINC_SHIFT)                /*!< FTM0_SYNCONF: CNTINC Mask               */
#define FTM_SYNCONF_CNTINC_SHIFT                 2                                                   /*!< FTM0_SYNCONF: CNTINC Position           */
#define FTM_SYNCONF_CNTINC(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_CNTINC_SHIFT))&FTM_SYNCONF_CNTINC_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_INVC_MASK                    (0x01UL << FTM_SYNCONF_INVC_SHIFT)                  /*!< FTM0_SYNCONF: INVC Mask                 */
#define FTM_SYNCONF_INVC_SHIFT                   4                                                   /*!< FTM0_SYNCONF: INVC Position             */
#define FTM_SYNCONF_INVC(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_INVC_SHIFT))&FTM_SYNCONF_INVC_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SWOC_MASK                    (0x01UL << FTM_SYNCONF_SWOC_SHIFT)                  /*!< FTM0_SYNCONF: SWOC Mask                 */
#define FTM_SYNCONF_SWOC_SHIFT                   5                                                   /*!< FTM0_SYNCONF: SWOC Position             */
#define FTM_SYNCONF_SWOC(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWOC_SHIFT))&FTM_SYNCONF_SWOC_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SYNCMODE_MASK                (0x01UL << FTM_SYNCONF_SYNCMODE_SHIFT)              /*!< FTM0_SYNCONF: SYNCMODE Mask             */
#define FTM_SYNCONF_SYNCMODE_SHIFT               7                                                   /*!< FTM0_SYNCONF: SYNCMODE Position         */
#define FTM_SYNCONF_SYNCMODE(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SYNCMODE_SHIFT))&FTM_SYNCONF_SYNCMODE_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SWRSTCNT_MASK                (0x01UL << FTM_SYNCONF_SWRSTCNT_SHIFT)              /*!< FTM0_SYNCONF: SWRSTCNT Mask             */
#define FTM_SYNCONF_SWRSTCNT_SHIFT               8                                                   /*!< FTM0_SYNCONF: SWRSTCNT Position         */
#define FTM_SYNCONF_SWRSTCNT(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWRSTCNT_SHIFT))&FTM_SYNCONF_SWRSTCNT_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SWWRBUF_MASK                 (0x01UL << FTM_SYNCONF_SWWRBUF_SHIFT)               /*!< FTM0_SYNCONF: SWWRBUF Mask              */
#define FTM_SYNCONF_SWWRBUF_SHIFT                9                                                   /*!< FTM0_SYNCONF: SWWRBUF Position          */
#define FTM_SYNCONF_SWWRBUF(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWWRBUF_SHIFT))&FTM_SYNCONF_SWWRBUF_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SWOM_MASK                    (0x01UL << FTM_SYNCONF_SWOM_SHIFT)                  /*!< FTM0_SYNCONF: SWOM Mask                 */
#define FTM_SYNCONF_SWOM_SHIFT                   10                                                  /*!< FTM0_SYNCONF: SWOM Position             */
#define FTM_SYNCONF_SWOM(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWOM_SHIFT))&FTM_SYNCONF_SWOM_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SWINVC_MASK                  (0x01UL << FTM_SYNCONF_SWINVC_SHIFT)                /*!< FTM0_SYNCONF: SWINVC Mask               */
#define FTM_SYNCONF_SWINVC_SHIFT                 11                                                  /*!< FTM0_SYNCONF: SWINVC Position           */
#define FTM_SYNCONF_SWINVC(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWINVC_SHIFT))&FTM_SYNCONF_SWINVC_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_SWSOC_MASK                   (0x01UL << FTM_SYNCONF_SWSOC_SHIFT)                 /*!< FTM0_SYNCONF: SWSOC Mask                */
#define FTM_SYNCONF_SWSOC_SHIFT                  12                                                  /*!< FTM0_SYNCONF: SWSOC Position            */
#define FTM_SYNCONF_SWSOC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWSOC_SHIFT))&FTM_SYNCONF_SWSOC_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_HWRSTCNT_MASK                (0x01UL << FTM_SYNCONF_HWRSTCNT_SHIFT)              /*!< FTM0_SYNCONF: HWRSTCNT Mask             */
#define FTM_SYNCONF_HWRSTCNT_SHIFT               16                                                  /*!< FTM0_SYNCONF: HWRSTCNT Position         */
#define FTM_SYNCONF_HWRSTCNT(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWRSTCNT_SHIFT))&FTM_SYNCONF_HWRSTCNT_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_HWWRBUF_MASK                 (0x01UL << FTM_SYNCONF_HWWRBUF_SHIFT)               /*!< FTM0_SYNCONF: HWWRBUF Mask              */
#define FTM_SYNCONF_HWWRBUF_SHIFT                17                                                  /*!< FTM0_SYNCONF: HWWRBUF Position          */
#define FTM_SYNCONF_HWWRBUF(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWWRBUF_SHIFT))&FTM_SYNCONF_HWWRBUF_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_HWOM_MASK                    (0x01UL << FTM_SYNCONF_HWOM_SHIFT)                  /*!< FTM0_SYNCONF: HWOM Mask                 */
#define FTM_SYNCONF_HWOM_SHIFT                   18                                                  /*!< FTM0_SYNCONF: HWOM Position             */
#define FTM_SYNCONF_HWOM(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWOM_SHIFT))&FTM_SYNCONF_HWOM_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_HWINVC_MASK                  (0x01UL << FTM_SYNCONF_HWINVC_SHIFT)                /*!< FTM0_SYNCONF: HWINVC Mask               */
#define FTM_SYNCONF_HWINVC_SHIFT                 19                                                  /*!< FTM0_SYNCONF: HWINVC Position           */
#define FTM_SYNCONF_HWINVC(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWINVC_SHIFT))&FTM_SYNCONF_HWINVC_MASK) /*!< FTM0_SYNCONF                            */
#define FTM_SYNCONF_HWSOC_MASK                   (0x01UL << FTM_SYNCONF_HWSOC_SHIFT)                 /*!< FTM0_SYNCONF: HWSOC Mask                */
#define FTM_SYNCONF_HWSOC_SHIFT                  20                                                  /*!< FTM0_SYNCONF: HWSOC Position            */
#define FTM_SYNCONF_HWSOC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWSOC_SHIFT))&FTM_SYNCONF_HWSOC_MASK) /*!< FTM0_SYNCONF                            */
/* ------- INVCTRL Bit Fields                       ------ */
#define FTM_INVCTRL_INV0EN_MASK                  (0x01UL << FTM_INVCTRL_INV0EN_SHIFT)                /*!< FTM0_INVCTRL: INV0EN Mask               */
#define FTM_INVCTRL_INV0EN_SHIFT                 0                                                   /*!< FTM0_INVCTRL: INV0EN Position           */
#define FTM_INVCTRL_INV0EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV0EN_SHIFT))&FTM_INVCTRL_INV0EN_MASK) /*!< FTM0_INVCTRL                            */
#define FTM_INVCTRL_INV1EN_MASK                  (0x01UL << FTM_INVCTRL_INV1EN_SHIFT)                /*!< FTM0_INVCTRL: INV1EN Mask               */
#define FTM_INVCTRL_INV1EN_SHIFT                 1                                                   /*!< FTM0_INVCTRL: INV1EN Position           */
#define FTM_INVCTRL_INV1EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV1EN_SHIFT))&FTM_INVCTRL_INV1EN_MASK) /*!< FTM0_INVCTRL                            */
#define FTM_INVCTRL_INV2EN_MASK                  (0x01UL << FTM_INVCTRL_INV2EN_SHIFT)                /*!< FTM0_INVCTRL: INV2EN Mask               */
#define FTM_INVCTRL_INV2EN_SHIFT                 2                                                   /*!< FTM0_INVCTRL: INV2EN Position           */
#define FTM_INVCTRL_INV2EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV2EN_SHIFT))&FTM_INVCTRL_INV2EN_MASK) /*!< FTM0_INVCTRL                            */
#define FTM_INVCTRL_INV3EN_MASK                  (0x01UL << FTM_INVCTRL_INV3EN_SHIFT)                /*!< FTM0_INVCTRL: INV3EN Mask               */
#define FTM_INVCTRL_INV3EN_SHIFT                 3                                                   /*!< FTM0_INVCTRL: INV3EN Position           */
#define FTM_INVCTRL_INV3EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV3EN_SHIFT))&FTM_INVCTRL_INV3EN_MASK) /*!< FTM0_INVCTRL                            */
/* ------- SWOCTRL Bit Fields                       ------ */
#define FTM_SWOCTRL_CH0OC_MASK                   (0x01UL << FTM_SWOCTRL_CH0OC_SHIFT)                 /*!< FTM0_SWOCTRL: CH0OC Mask                */
#define FTM_SWOCTRL_CH0OC_SHIFT                  0                                                   /*!< FTM0_SWOCTRL: CH0OC Position            */
#define FTM_SWOCTRL_CH0OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH0OC_SHIFT))&FTM_SWOCTRL_CH0OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH1OC_MASK                   (0x01UL << FTM_SWOCTRL_CH1OC_SHIFT)                 /*!< FTM0_SWOCTRL: CH1OC Mask                */
#define FTM_SWOCTRL_CH1OC_SHIFT                  1                                                   /*!< FTM0_SWOCTRL: CH1OC Position            */
#define FTM_SWOCTRL_CH1OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH1OC_SHIFT))&FTM_SWOCTRL_CH1OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH2OC_MASK                   (0x01UL << FTM_SWOCTRL_CH2OC_SHIFT)                 /*!< FTM0_SWOCTRL: CH2OC Mask                */
#define FTM_SWOCTRL_CH2OC_SHIFT                  2                                                   /*!< FTM0_SWOCTRL: CH2OC Position            */
#define FTM_SWOCTRL_CH2OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH2OC_SHIFT))&FTM_SWOCTRL_CH2OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH3OC_MASK                   (0x01UL << FTM_SWOCTRL_CH3OC_SHIFT)                 /*!< FTM0_SWOCTRL: CH3OC Mask                */
#define FTM_SWOCTRL_CH3OC_SHIFT                  3                                                   /*!< FTM0_SWOCTRL: CH3OC Position            */
#define FTM_SWOCTRL_CH3OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH3OC_SHIFT))&FTM_SWOCTRL_CH3OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH4OC_MASK                   (0x01UL << FTM_SWOCTRL_CH4OC_SHIFT)                 /*!< FTM0_SWOCTRL: CH4OC Mask                */
#define FTM_SWOCTRL_CH4OC_SHIFT                  4                                                   /*!< FTM0_SWOCTRL: CH4OC Position            */
#define FTM_SWOCTRL_CH4OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH4OC_SHIFT))&FTM_SWOCTRL_CH4OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH5OC_MASK                   (0x01UL << FTM_SWOCTRL_CH5OC_SHIFT)                 /*!< FTM0_SWOCTRL: CH5OC Mask                */
#define FTM_SWOCTRL_CH5OC_SHIFT                  5                                                   /*!< FTM0_SWOCTRL: CH5OC Position            */
#define FTM_SWOCTRL_CH5OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH5OC_SHIFT))&FTM_SWOCTRL_CH5OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH6OC_MASK                   (0x01UL << FTM_SWOCTRL_CH6OC_SHIFT)                 /*!< FTM0_SWOCTRL: CH6OC Mask                */
#define FTM_SWOCTRL_CH6OC_SHIFT                  6                                                   /*!< FTM0_SWOCTRL: CH6OC Position            */
#define FTM_SWOCTRL_CH6OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH6OC_SHIFT))&FTM_SWOCTRL_CH6OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH7OC_MASK                   (0x01UL << FTM_SWOCTRL_CH7OC_SHIFT)                 /*!< FTM0_SWOCTRL: CH7OC Mask                */
#define FTM_SWOCTRL_CH7OC_SHIFT                  7                                                   /*!< FTM0_SWOCTRL: CH7OC Position            */
#define FTM_SWOCTRL_CH7OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH7OC_SHIFT))&FTM_SWOCTRL_CH7OC_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH0OCV_MASK                  (0x01UL << FTM_SWOCTRL_CH0OCV_SHIFT)                /*!< FTM0_SWOCTRL: CH0OCV Mask               */
#define FTM_SWOCTRL_CH0OCV_SHIFT                 8                                                   /*!< FTM0_SWOCTRL: CH0OCV Position           */
#define FTM_SWOCTRL_CH0OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH0OCV_SHIFT))&FTM_SWOCTRL_CH0OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH1OCV_MASK                  (0x01UL << FTM_SWOCTRL_CH1OCV_SHIFT)                /*!< FTM0_SWOCTRL: CH1OCV Mask               */
#define FTM_SWOCTRL_CH1OCV_SHIFT                 9                                                   /*!< FTM0_SWOCTRL: CH1OCV Position           */
#define FTM_SWOCTRL_CH1OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH1OCV_SHIFT))&FTM_SWOCTRL_CH1OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH2OCV_MASK                  (0x01UL << FTM_SWOCTRL_CH2OCV_SHIFT)                /*!< FTM0_SWOCTRL: CH2OCV Mask               */
#define FTM_SWOCTRL_CH2OCV_SHIFT                 10                                                  /*!< FTM0_SWOCTRL: CH2OCV Position           */
#define FTM_SWOCTRL_CH2OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH2OCV_SHIFT))&FTM_SWOCTRL_CH2OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH3OCV_MASK                  (0x01UL << FTM_SWOCTRL_CH3OCV_SHIFT)                /*!< FTM0_SWOCTRL: CH3OCV Mask               */
#define FTM_SWOCTRL_CH3OCV_SHIFT                 11                                                  /*!< FTM0_SWOCTRL: CH3OCV Position           */
#define FTM_SWOCTRL_CH3OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH3OCV_SHIFT))&FTM_SWOCTRL_CH3OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH4OCV_MASK                  (0x01UL << FTM_SWOCTRL_CH4OCV_SHIFT)                /*!< FTM0_SWOCTRL: CH4OCV Mask               */
#define FTM_SWOCTRL_CH4OCV_SHIFT                 12                                                  /*!< FTM0_SWOCTRL: CH4OCV Position           */
#define FTM_SWOCTRL_CH4OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH4OCV_SHIFT))&FTM_SWOCTRL_CH4OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH5OCV_MASK                  (0x01UL << FTM_SWOCTRL_CH5OCV_SHIFT)                /*!< FTM0_SWOCTRL: CH5OCV Mask               */
#define FTM_SWOCTRL_CH5OCV_SHIFT                 13                                                  /*!< FTM0_SWOCTRL: CH5OCV Position           */
#define FTM_SWOCTRL_CH5OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH5OCV_SHIFT))&FTM_SWOCTRL_CH5OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH6OCV_MASK                  (0x01UL << FTM_SWOCTRL_CH6OCV_SHIFT)                /*!< FTM0_SWOCTRL: CH6OCV Mask               */
#define FTM_SWOCTRL_CH6OCV_SHIFT                 14                                                  /*!< FTM0_SWOCTRL: CH6OCV Position           */
#define FTM_SWOCTRL_CH6OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH6OCV_SHIFT))&FTM_SWOCTRL_CH6OCV_MASK) /*!< FTM0_SWOCTRL                            */
#define FTM_SWOCTRL_CH7OCV_MASK                  (0x01UL << FTM_SWOCTRL_CH7OCV_SHIFT)                /*!< FTM0_SWOCTRL: CH7OCV Mask               */
#define FTM_SWOCTRL_CH7OCV_SHIFT                 15                                                  /*!< FTM0_SWOCTRL: CH7OCV Position           */
#define FTM_SWOCTRL_CH7OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH7OCV_SHIFT))&FTM_SWOCTRL_CH7OCV_MASK) /*!< FTM0_SWOCTRL                            */
/* ------- PWMLOAD Bit Fields                       ------ */
#define FTM_PWMLOAD_CH0SEL_MASK                  (0x01UL << FTM_PWMLOAD_CH0SEL_SHIFT)                /*!< FTM0_PWMLOAD: CH0SEL Mask               */
#define FTM_PWMLOAD_CH0SEL_SHIFT                 0                                                   /*!< FTM0_PWMLOAD: CH0SEL Position           */
#define FTM_PWMLOAD_CH0SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH0SEL_SHIFT))&FTM_PWMLOAD_CH0SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH1SEL_MASK                  (0x01UL << FTM_PWMLOAD_CH1SEL_SHIFT)                /*!< FTM0_PWMLOAD: CH1SEL Mask               */
#define FTM_PWMLOAD_CH1SEL_SHIFT                 1                                                   /*!< FTM0_PWMLOAD: CH1SEL Position           */
#define FTM_PWMLOAD_CH1SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH1SEL_SHIFT))&FTM_PWMLOAD_CH1SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH2SEL_MASK                  (0x01UL << FTM_PWMLOAD_CH2SEL_SHIFT)                /*!< FTM0_PWMLOAD: CH2SEL Mask               */
#define FTM_PWMLOAD_CH2SEL_SHIFT                 2                                                   /*!< FTM0_PWMLOAD: CH2SEL Position           */
#define FTM_PWMLOAD_CH2SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH2SEL_SHIFT))&FTM_PWMLOAD_CH2SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH3SEL_MASK                  (0x01UL << FTM_PWMLOAD_CH3SEL_SHIFT)                /*!< FTM0_PWMLOAD: CH3SEL Mask               */
#define FTM_PWMLOAD_CH3SEL_SHIFT                 3                                                   /*!< FTM0_PWMLOAD: CH3SEL Position           */
#define FTM_PWMLOAD_CH3SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH3SEL_SHIFT))&FTM_PWMLOAD_CH3SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH4SEL_MASK                  (0x01UL << FTM_PWMLOAD_CH4SEL_SHIFT)                /*!< FTM0_PWMLOAD: CH4SEL Mask               */
#define FTM_PWMLOAD_CH4SEL_SHIFT                 4                                                   /*!< FTM0_PWMLOAD: CH4SEL Position           */
#define FTM_PWMLOAD_CH4SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH4SEL_SHIFT))&FTM_PWMLOAD_CH4SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH5SEL_MASK                  (0x01UL << FTM_PWMLOAD_CH5SEL_SHIFT)                /*!< FTM0_PWMLOAD: CH5SEL Mask               */
#define FTM_PWMLOAD_CH5SEL_SHIFT                 5                                                   /*!< FTM0_PWMLOAD: CH5SEL Position           */
#define FTM_PWMLOAD_CH5SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH5SEL_SHIFT))&FTM_PWMLOAD_CH5SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH6SEL_MASK                  (0x01UL << FTM_PWMLOAD_CH6SEL_SHIFT)                /*!< FTM0_PWMLOAD: CH6SEL Mask               */
#define FTM_PWMLOAD_CH6SEL_SHIFT                 6                                                   /*!< FTM0_PWMLOAD: CH6SEL Position           */
#define FTM_PWMLOAD_CH6SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH6SEL_SHIFT))&FTM_PWMLOAD_CH6SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_CH7SEL_MASK                  (0x01UL << FTM_PWMLOAD_CH7SEL_SHIFT)                /*!< FTM0_PWMLOAD: CH7SEL Mask               */
#define FTM_PWMLOAD_CH7SEL_SHIFT                 7                                                   /*!< FTM0_PWMLOAD: CH7SEL Position           */
#define FTM_PWMLOAD_CH7SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH7SEL_SHIFT))&FTM_PWMLOAD_CH7SEL_MASK) /*!< FTM0_PWMLOAD                            */
#define FTM_PWMLOAD_LDOK_MASK                    (0x01UL << FTM_PWMLOAD_LDOK_SHIFT)                  /*!< FTM0_PWMLOAD: LDOK Mask                 */
#define FTM_PWMLOAD_LDOK_SHIFT                   9                                                   /*!< FTM0_PWMLOAD: LDOK Position             */
#define FTM_PWMLOAD_LDOK(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_LDOK_SHIFT))&FTM_PWMLOAD_LDOK_MASK) /*!< FTM0_PWMLOAD                            */
/**
 * @} */ /* End group FTM_Register_Masks_GROUP 
 */

/* FTM0 - Peripheral instance base addresses */
#define FTM0_BasePtr                   0x40038000UL //!< Peripheral base address
#define FTM0                           ((FTM_Type *) FTM0_BasePtr) //!< Freescale base pointer
#define FTM0_BASE_PTR                  (FTM0) //!< Freescale style base pointer
/**
 * @} */ /* End group FTM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTM_Peripheral_access_layer_GROUP FTM Peripheral Access Layer
* @brief C Struct for FTM
* @{
*/

/* ================================================================================ */
/* ================           FTM1 (file:FTM1_2CH)                 ================ */
/* ================================================================================ */

/**
 * @brief FlexTimer Module (2 channels)
 */
/**
* @addtogroup FTM_structs_GROUP FTM struct
* @brief Struct for FTM
* @{
*/
typedef struct {                                /*       FTM1 Structure                                               */
   __IO uint32_t  SC;                           /**< 0000: Status and Control                                           */
   __IO uint32_t  CNT;                          /**< 0004: Counter                                                      */
   __IO uint32_t  MOD;                          /**< 0008: Modulo                                                       */
   struct {
      __IO uint32_t  CnSC;                      /**< 000C: Channel  Status and Control                                  */
      __IO uint32_t  CnV;                       /**< 0010: Channel  Value                                               */
   } CONTROLS[2];                               /**< 000C: (cluster: size=0x0010, 16)                                   */
   __I  uint32_t  RESERVED0[12];               
   __IO uint32_t  CNTIN;                        /**< 004C: Counter Initial Value                                        */
   __IO uint32_t  STATUS;                       /**< 0050: Capture and Compare Status                                   */
   __IO uint32_t  MODE;                         /**< 0054: Features Mode Selection                                      */
   __IO uint32_t  SYNC;                         /**< 0058: Synchronization                                              */
   __IO uint32_t  OUTINIT;                      /**< 005C: Initial State for Channels Output                            */
   __IO uint32_t  OUTMASK;                      /**< 0060: Output Mask                                                  */
   __IO uint32_t  COMBINE;                      /**< 0064: Function for Linked Channels                                 */
   __IO uint32_t  DEADTIME;                     /**< 0068: Deadtime Insertion Control                                   */
   __IO uint32_t  EXTTRIG;                      /**< 006C: FTM External Trigger                                         */
   __IO uint32_t  POL;                          /**< 0070: Channels Polarity                                            */
   __IO uint32_t  FMS;                          /**< 0074: Fault Mode Status                                            */
   __IO uint32_t  FILTER;                       /**< 0078: Input Capture Filter Control                                 */
   __IO uint32_t  FLTCTRL;                      /**< 007C: Fault Control                                                */
   __IO uint32_t  QDCTRL;                       /**< 0080: Quadrature Decoder Control and Status                        */
   __IO uint32_t  CONF;                         /**< 0084: Configuration                                                */
   __IO uint32_t  FLTPOL;                       /**< 0088: FTM Fault Input Polarity                                     */
   __IO uint32_t  SYNCONF;                      /**< 008C: Synchronization Configuration                                */
   __IO uint32_t  INVCTRL;                      /**< 0090: FTM Inverting Control                                        */
   __IO uint32_t  SWOCTRL;                      /**< 0094: FTM Software Output Control                                  */
   __IO uint32_t  PWMLOAD;                      /**< 0098: FTM PWM Load                                                 */
} FTM1_Type;

/**
 * @} */ /* End group FTM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTM1' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FTM_Register_Masks_GROUP FTM Register Masks
* @brief Register Masks for FTM
* @{
*/
/* ------- SC Bit Fields                            ------ */
/* ------- CNT Bit Fields                           ------ */
/* ------- MOD Bit Fields                           ------ */
/* ------- CnSC Bit Fields                          ------ */
/* ------- CnV Bit Fields                           ------ */
/* ------- CNTIN Bit Fields                         ------ */
/* ------- STATUS Bit Fields                        ------ */
/* ------- MODE Bit Fields                          ------ */
/* ------- SYNC Bit Fields                          ------ */
/* ------- OUTINIT Bit Fields                       ------ */
/* ------- OUTMASK Bit Fields                       ------ */
/* ------- COMBINE Bit Fields                       ------ */
/* ------- DEADTIME Bit Fields                      ------ */
/* ------- EXTTRIG Bit Fields                       ------ */
/* ------- POL Bit Fields                           ------ */
/* ------- FMS Bit Fields                           ------ */
/* ------- FILTER Bit Fields                        ------ */
/* ------- FLTCTRL Bit Fields                       ------ */
/* ------- QDCTRL Bit Fields                        ------ */
/* ------- CONF Bit Fields                          ------ */
/* ------- FLTPOL Bit Fields                        ------ */
/* ------- SYNCONF Bit Fields                       ------ */
/* ------- INVCTRL Bit Fields                       ------ */
/* ------- SWOCTRL Bit Fields                       ------ */
/* ------- PWMLOAD Bit Fields                       ------ */
/**
 * @} */ /* End group FTM_Register_Masks_GROUP 
 */

/* FTM1 - Peripheral instance base addresses */
#define FTM1_BasePtr                   0x40039000UL //!< Peripheral base address
#define FTM1                           ((FTM1_Type *) FTM1_BasePtr) //!< Freescale base pointer
#define FTM1_BASE_PTR                  (FTM1) //!< Freescale style base pointer
/**
 * @} */ /* End group FTM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTM_Peripheral_access_layer_GROUP FTM Peripheral Access Layer
* @brief C Struct for FTM
* @{
*/

/* ================================================================================ */
/* ================           FTM2 (derived from FTM1)             ================ */
/* ================================================================================ */

/**
 * @brief FlexTimer Module (2 channels)
 */

/* FTM2 - Peripheral instance base addresses */
#define FTM2_BasePtr                   0x400B8000UL //!< Peripheral base address
#define FTM2                           ((FTM1_Type *) FTM2_BasePtr) //!< Freescale base pointer
#define FTM2_BASE_PTR                  (FTM2) //!< Freescale style base pointer
/**
 * @} */ /* End group FTM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOA (file:GPIOA_0x400FF000)        ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
/**
* @addtogroup GPIOA_structs_GROUP GPIOA struct
* @brief Struct for GPIOA
* @{
*/
typedef struct {                                /*       GPIOA Structure                                              */
   __IO uint32_t  PDOR;                         /**< 0000: Port Data Output Register                                    */
   __O  uint32_t  PSOR;                         /**< 0004: Port Set Output Register                                     */
   __O  uint32_t  PCOR;                         /**< 0008: Port Clear Output Register                                   */
   __O  uint32_t  PTOR;                         /**< 000C: Port Toggle Output Register                                  */
   __I  uint32_t  PDIR;                         /**< 0010: Port Data Input Register                                     */
   __IO uint32_t  PDDR;                         /**< 0014: Port Data Direction Register                                 */
} GPIO_Type;

/**
 * @} */ /* End group GPIOA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'GPIOA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup GPIOA_Register_Masks_GROUP GPIOA Register Masks
* @brief Register Masks for GPIOA
* @{
*/
/* ------- PDOR Bit Fields                          ------ */
/* ------- PSOR Bit Fields                          ------ */
/* ------- PCOR Bit Fields                          ------ */
/* ------- PTOR Bit Fields                          ------ */
/* ------- PDIR Bit Fields                          ------ */
/* ------- PDDR Bit Fields                          ------ */
/**
 * @} */ /* End group GPIOA_Register_Masks_GROUP 
 */

/* GPIOA - Peripheral instance base addresses */
#define GPIOA_BasePtr                  0x400FF000UL //!< Peripheral base address
#define GPIOA                          ((GPIO_Type *) GPIOA_BasePtr) //!< Freescale base pointer
#define GPIOA_BASE_PTR                 (GPIOA) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOB (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOB - Peripheral instance base addresses */
#define GPIOB_BasePtr                  0x400FF040UL //!< Peripheral base address
#define GPIOB                          ((GPIO_Type *) GPIOB_BasePtr) //!< Freescale base pointer
#define GPIOB_BASE_PTR                 (GPIOB) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOC (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOC - Peripheral instance base addresses */
#define GPIOC_BasePtr                  0x400FF080UL //!< Peripheral base address
#define GPIOC                          ((GPIO_Type *) GPIOC_BasePtr) //!< Freescale base pointer
#define GPIOC_BASE_PTR                 (GPIOC) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOD (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOD - Peripheral instance base addresses */
#define GPIOD_BasePtr                  0x400FF0C0UL //!< Peripheral base address
#define GPIOD                          ((GPIO_Type *) GPIOD_BasePtr) //!< Freescale base pointer
#define GPIOD_BASE_PTR                 (GPIOD) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIOA_Peripheral_access_layer_GROUP GPIOA Peripheral Access Layer
* @brief C Struct for GPIOA
* @{
*/

/* ================================================================================ */
/* ================           GPIOE (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOE - Peripheral instance base addresses */
#define GPIOE_BasePtr                  0x400FF100UL //!< Peripheral base address
#define GPIOE                          ((GPIO_Type *) GPIOE_BasePtr) //!< Freescale base pointer
#define GPIOE_BASE_PTR                 (GPIOE) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIOA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           I2C0 (file:I2C0_MK10D5)              ================ */
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
   __IO uint8_t   A1;                           /**< 0000: Address Register 1                                           */
   __IO uint8_t   F;                            /**< 0001: Frequency Divider register                                   */
   __IO uint8_t   C1;                           /**< 0002: Control Register 1                                           */
   __IO uint8_t   S;                            /**< 0003: Status Register                                              */
   __IO uint8_t   D;                            /**< 0004: Data I/O register                                            */
   __IO uint8_t   C2;                           /**< 0005: Control Register 2                                           */
   __IO uint8_t   FLT;                          /**< 0006: Programmable Input Glitch Filter register                    */
   __IO uint8_t   RA;                           /**< 0007: Range Address register                                       */
   __IO uint8_t   SMB;                          /**< 0008: SMBus Control and Status register                            */
   __IO uint8_t   A2;                           /**< 0009: Address Register 2                                           */
   __IO uint8_t   SLTH;                         /**< 000A: SCL Low Timeout Register High                                */
   __IO uint8_t   SLTL;                         /**< 000B: SCL Low Timeout Register Low                                 */
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
#define I2C_A1_AD_MASK                           (0x7FUL << I2C_A1_AD_SHIFT)                         /*!< I2C0_A1: AD Mask                        */
#define I2C_A1_AD_SHIFT                          1                                                   /*!< I2C0_A1: AD Position                    */
#define I2C_A1_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_A1_AD_SHIFT))&I2C_A1_AD_MASK) /*!< I2C0_A1                                 */
/* ------- F Bit Fields                             ------ */
#define I2C_F_ICR_MASK                           (0x3FUL << I2C_F_ICR_SHIFT)                         /*!< I2C0_F: ICR Mask                        */
#define I2C_F_ICR_SHIFT                          0                                                   /*!< I2C0_F: ICR Position                    */
#define I2C_F_ICR(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_F_ICR_SHIFT))&I2C_F_ICR_MASK) /*!< I2C0_F                                  */
#define I2C_F_MULT_MASK                          (0x03UL << I2C_F_MULT_SHIFT)                        /*!< I2C0_F: MULT Mask                       */
#define I2C_F_MULT_SHIFT                         6                                                   /*!< I2C0_F: MULT Position                   */
#define I2C_F_MULT(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_F_MULT_SHIFT))&I2C_F_MULT_MASK) /*!< I2C0_F                                  */
/* ------- C1 Bit Fields                            ------ */
#define I2C_C1_DMAEN_MASK                        (0x01UL << I2C_C1_DMAEN_SHIFT)                      /*!< I2C0_C1: DMAEN Mask                     */
#define I2C_C1_DMAEN_SHIFT                       0                                                   /*!< I2C0_C1: DMAEN Position                 */
#define I2C_C1_DMAEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C1_DMAEN_SHIFT))&I2C_C1_DMAEN_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_WUEN_MASK                         (0x01UL << I2C_C1_WUEN_SHIFT)                       /*!< I2C0_C1: WUEN Mask                      */
#define I2C_C1_WUEN_SHIFT                        1                                                   /*!< I2C0_C1: WUEN Position                  */
#define I2C_C1_WUEN(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C1_WUEN_SHIFT))&I2C_C1_WUEN_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_RSTA_MASK                         (0x01UL << I2C_C1_RSTA_SHIFT)                       /*!< I2C0_C1: RSTA Mask                      */
#define I2C_C1_RSTA_SHIFT                        2                                                   /*!< I2C0_C1: RSTA Position                  */
#define I2C_C1_RSTA(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C1_RSTA_SHIFT))&I2C_C1_RSTA_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_TXAK_MASK                         (0x01UL << I2C_C1_TXAK_SHIFT)                       /*!< I2C0_C1: TXAK Mask                      */
#define I2C_C1_TXAK_SHIFT                        3                                                   /*!< I2C0_C1: TXAK Position                  */
#define I2C_C1_TXAK(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C1_TXAK_SHIFT))&I2C_C1_TXAK_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_TX_MASK                           (0x01UL << I2C_C1_TX_SHIFT)                         /*!< I2C0_C1: TX Mask                        */
#define I2C_C1_TX_SHIFT                          4                                                   /*!< I2C0_C1: TX Position                    */
#define I2C_C1_TX(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_C1_TX_SHIFT))&I2C_C1_TX_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_MST_MASK                          (0x01UL << I2C_C1_MST_SHIFT)                        /*!< I2C0_C1: MST Mask                       */
#define I2C_C1_MST_SHIFT                         5                                                   /*!< I2C0_C1: MST Position                   */
#define I2C_C1_MST(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_C1_MST_SHIFT))&I2C_C1_MST_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_IICIE_MASK                        (0x01UL << I2C_C1_IICIE_SHIFT)                      /*!< I2C0_C1: IICIE Mask                     */
#define I2C_C1_IICIE_SHIFT                       6                                                   /*!< I2C0_C1: IICIE Position                 */
#define I2C_C1_IICIE(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C1_IICIE_SHIFT))&I2C_C1_IICIE_MASK) /*!< I2C0_C1                                 */
#define I2C_C1_IICEN_MASK                        (0x01UL << I2C_C1_IICEN_SHIFT)                      /*!< I2C0_C1: IICEN Mask                     */
#define I2C_C1_IICEN_SHIFT                       7                                                   /*!< I2C0_C1: IICEN Position                 */
#define I2C_C1_IICEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C1_IICEN_SHIFT))&I2C_C1_IICEN_MASK) /*!< I2C0_C1                                 */
/* ------- S Bit Fields                             ------ */
#define I2C_S_RXAK_MASK                          (0x01UL << I2C_S_RXAK_SHIFT)                        /*!< I2C0_S: RXAK Mask                       */
#define I2C_S_RXAK_SHIFT                         0                                                   /*!< I2C0_S: RXAK Position                   */
#define I2C_S_RXAK(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_RXAK_SHIFT))&I2C_S_RXAK_MASK) /*!< I2C0_S                                  */
#define I2C_S_IICIF_MASK                         (0x01UL << I2C_S_IICIF_SHIFT)                       /*!< I2C0_S: IICIF Mask                      */
#define I2C_S_IICIF_SHIFT                        1                                                   /*!< I2C0_S: IICIF Position                  */
#define I2C_S_IICIF(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_S_IICIF_SHIFT))&I2C_S_IICIF_MASK) /*!< I2C0_S                                  */
#define I2C_S_SRW_MASK                           (0x01UL << I2C_S_SRW_SHIFT)                         /*!< I2C0_S: SRW Mask                        */
#define I2C_S_SRW_SHIFT                          2                                                   /*!< I2C0_S: SRW Position                    */
#define I2C_S_SRW(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_S_SRW_SHIFT))&I2C_S_SRW_MASK) /*!< I2C0_S                                  */
#define I2C_S_RAM_MASK                           (0x01UL << I2C_S_RAM_SHIFT)                         /*!< I2C0_S: RAM Mask                        */
#define I2C_S_RAM_SHIFT                          3                                                   /*!< I2C0_S: RAM Position                    */
#define I2C_S_RAM(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_S_RAM_SHIFT))&I2C_S_RAM_MASK) /*!< I2C0_S                                  */
#define I2C_S_ARBL_MASK                          (0x01UL << I2C_S_ARBL_SHIFT)                        /*!< I2C0_S: ARBL Mask                       */
#define I2C_S_ARBL_SHIFT                         4                                                   /*!< I2C0_S: ARBL Position                   */
#define I2C_S_ARBL(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_ARBL_SHIFT))&I2C_S_ARBL_MASK) /*!< I2C0_S                                  */
#define I2C_S_BUSY_MASK                          (0x01UL << I2C_S_BUSY_SHIFT)                        /*!< I2C0_S: BUSY Mask                       */
#define I2C_S_BUSY_SHIFT                         5                                                   /*!< I2C0_S: BUSY Position                   */
#define I2C_S_BUSY(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_BUSY_SHIFT))&I2C_S_BUSY_MASK) /*!< I2C0_S                                  */
#define I2C_S_IAAS_MASK                          (0x01UL << I2C_S_IAAS_SHIFT)                        /*!< I2C0_S: IAAS Mask                       */
#define I2C_S_IAAS_SHIFT                         6                                                   /*!< I2C0_S: IAAS Position                   */
#define I2C_S_IAAS(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_S_IAAS_SHIFT))&I2C_S_IAAS_MASK) /*!< I2C0_S                                  */
#define I2C_S_TCF_MASK                           (0x01UL << I2C_S_TCF_SHIFT)                         /*!< I2C0_S: TCF Mask                        */
#define I2C_S_TCF_SHIFT                          7                                                   /*!< I2C0_S: TCF Position                    */
#define I2C_S_TCF(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_S_TCF_SHIFT))&I2C_S_TCF_MASK) /*!< I2C0_S                                  */
/* ------- D Bit Fields                             ------ */
#define I2C_D_DATA_MASK                          (0xFFUL << I2C_D_DATA_SHIFT)                        /*!< I2C0_D: DATA Mask                       */
#define I2C_D_DATA_SHIFT                         0                                                   /*!< I2C0_D: DATA Position                   */
#define I2C_D_DATA(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_D_DATA_SHIFT))&I2C_D_DATA_MASK) /*!< I2C0_D                                  */
/* ------- C2 Bit Fields                            ------ */
#define I2C_C2_AD_MASK                           (0x07UL << I2C_C2_AD_SHIFT)                         /*!< I2C0_C2: AD Mask                        */
#define I2C_C2_AD_SHIFT                          0                                                   /*!< I2C0_C2: AD Position                    */
#define I2C_C2_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_C2_AD_SHIFT))&I2C_C2_AD_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_RMEN_MASK                         (0x01UL << I2C_C2_RMEN_SHIFT)                       /*!< I2C0_C2: RMEN Mask                      */
#define I2C_C2_RMEN_SHIFT                        3                                                   /*!< I2C0_C2: RMEN Position                  */
#define I2C_C2_RMEN(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C2_RMEN_SHIFT))&I2C_C2_RMEN_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_SBRC_MASK                         (0x01UL << I2C_C2_SBRC_SHIFT)                       /*!< I2C0_C2: SBRC Mask                      */
#define I2C_C2_SBRC_SHIFT                        4                                                   /*!< I2C0_C2: SBRC Position                  */
#define I2C_C2_SBRC(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C2_SBRC_SHIFT))&I2C_C2_SBRC_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_HDRS_MASK                         (0x01UL << I2C_C2_HDRS_SHIFT)                       /*!< I2C0_C2: HDRS Mask                      */
#define I2C_C2_HDRS_SHIFT                        5                                                   /*!< I2C0_C2: HDRS Position                  */
#define I2C_C2_HDRS(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_C2_HDRS_SHIFT))&I2C_C2_HDRS_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_ADEXT_MASK                        (0x01UL << I2C_C2_ADEXT_SHIFT)                      /*!< I2C0_C2: ADEXT Mask                     */
#define I2C_C2_ADEXT_SHIFT                       6                                                   /*!< I2C0_C2: ADEXT Position                 */
#define I2C_C2_ADEXT(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C2_ADEXT_SHIFT))&I2C_C2_ADEXT_MASK) /*!< I2C0_C2                                 */
#define I2C_C2_GCAEN_MASK                        (0x01UL << I2C_C2_GCAEN_SHIFT)                      /*!< I2C0_C2: GCAEN Mask                     */
#define I2C_C2_GCAEN_SHIFT                       7                                                   /*!< I2C0_C2: GCAEN Position                 */
#define I2C_C2_GCAEN(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_C2_GCAEN_SHIFT))&I2C_C2_GCAEN_MASK) /*!< I2C0_C2                                 */
/* ------- FLT Bit Fields                           ------ */
#define I2C_FLT_FLT_MASK                         (0x1FUL << I2C_FLT_FLT_SHIFT)                       /*!< I2C0_FLT: FLT Mask                      */
#define I2C_FLT_FLT_SHIFT                        0                                                   /*!< I2C0_FLT: FLT Position                  */
#define I2C_FLT_FLT(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_FLT_FLT_SHIFT))&I2C_FLT_FLT_MASK) /*!< I2C0_FLT                                */
/* ------- RA Bit Fields                            ------ */
#define I2C_RA_RAD_MASK                          (0x7FUL << I2C_RA_RAD_SHIFT)                        /*!< I2C0_RA: RAD Mask                       */
#define I2C_RA_RAD_SHIFT                         1                                                   /*!< I2C0_RA: RAD Position                   */
#define I2C_RA_RAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_RA_RAD_SHIFT))&I2C_RA_RAD_MASK) /*!< I2C0_RA                                 */
/* ------- SMB Bit Fields                           ------ */
#define I2C_SMB_SHTF2IE_MASK                     (0x01UL << I2C_SMB_SHTF2IE_SHIFT)                   /*!< I2C0_SMB: SHTF2IE Mask                  */
#define I2C_SMB_SHTF2IE_SHIFT                    0                                                   /*!< I2C0_SMB: SHTF2IE Position              */
#define I2C_SMB_SHTF2IE(x)                       (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SHTF2IE_SHIFT))&I2C_SMB_SHTF2IE_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_SHTF2_MASK                       (0x01UL << I2C_SMB_SHTF2_SHIFT)                     /*!< I2C0_SMB: SHTF2 Mask                    */
#define I2C_SMB_SHTF2_SHIFT                      1                                                   /*!< I2C0_SMB: SHTF2 Position                */
#define I2C_SMB_SHTF2(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SHTF2_SHIFT))&I2C_SMB_SHTF2_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_SHTF1_MASK                       (0x01UL << I2C_SMB_SHTF1_SHIFT)                     /*!< I2C0_SMB: SHTF1 Mask                    */
#define I2C_SMB_SHTF1_SHIFT                      2                                                   /*!< I2C0_SMB: SHTF1 Position                */
#define I2C_SMB_SHTF1(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SHTF1_SHIFT))&I2C_SMB_SHTF1_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_SLTF_MASK                        (0x01UL << I2C_SMB_SLTF_SHIFT)                      /*!< I2C0_SMB: SLTF Mask                     */
#define I2C_SMB_SLTF_SHIFT                       3                                                   /*!< I2C0_SMB: SLTF Position                 */
#define I2C_SMB_SLTF(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SLTF_SHIFT))&I2C_SMB_SLTF_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_TCKSEL_MASK                      (0x01UL << I2C_SMB_TCKSEL_SHIFT)                    /*!< I2C0_SMB: TCKSEL Mask                   */
#define I2C_SMB_TCKSEL_SHIFT                     4                                                   /*!< I2C0_SMB: TCKSEL Position               */
#define I2C_SMB_TCKSEL(x)                        (((uint8_t)(((uint8_t)(x))<<I2C_SMB_TCKSEL_SHIFT))&I2C_SMB_TCKSEL_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_SIICAEN_MASK                     (0x01UL << I2C_SMB_SIICAEN_SHIFT)                   /*!< I2C0_SMB: SIICAEN Mask                  */
#define I2C_SMB_SIICAEN_SHIFT                    5                                                   /*!< I2C0_SMB: SIICAEN Position              */
#define I2C_SMB_SIICAEN(x)                       (((uint8_t)(((uint8_t)(x))<<I2C_SMB_SIICAEN_SHIFT))&I2C_SMB_SIICAEN_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_ALERTEN_MASK                     (0x01UL << I2C_SMB_ALERTEN_SHIFT)                   /*!< I2C0_SMB: ALERTEN Mask                  */
#define I2C_SMB_ALERTEN_SHIFT                    6                                                   /*!< I2C0_SMB: ALERTEN Position              */
#define I2C_SMB_ALERTEN(x)                       (((uint8_t)(((uint8_t)(x))<<I2C_SMB_ALERTEN_SHIFT))&I2C_SMB_ALERTEN_MASK) /*!< I2C0_SMB                                */
#define I2C_SMB_FACK_MASK                        (0x01UL << I2C_SMB_FACK_SHIFT)                      /*!< I2C0_SMB: FACK Mask                     */
#define I2C_SMB_FACK_SHIFT                       7                                                   /*!< I2C0_SMB: FACK Position                 */
#define I2C_SMB_FACK(x)                          (((uint8_t)(((uint8_t)(x))<<I2C_SMB_FACK_SHIFT))&I2C_SMB_FACK_MASK) /*!< I2C0_SMB                                */
/* ------- A2 Bit Fields                            ------ */
#define I2C_A2_SAD_MASK                          (0x7FUL << I2C_A2_SAD_SHIFT)                        /*!< I2C0_A2: SAD Mask                       */
#define I2C_A2_SAD_SHIFT                         1                                                   /*!< I2C0_A2: SAD Position                   */
#define I2C_A2_SAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_A2_SAD_SHIFT))&I2C_A2_SAD_MASK) /*!< I2C0_A2                                 */
/* ------- SLTH Bit Fields                          ------ */
#define I2C_SLTH_SSLT_MASK                       (0xFFUL << I2C_SLTH_SSLT_SHIFT)                     /*!< I2C0_SLTH: SSLT Mask                    */
#define I2C_SLTH_SSLT_SHIFT                      0                                                   /*!< I2C0_SLTH: SSLT Position                */
#define I2C_SLTH_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTH_SSLT_SHIFT))&I2C_SLTH_SSLT_MASK) /*!< I2C0_SLTH                               */
/* ------- SLTL Bit Fields                          ------ */
#define I2C_SLTL_SSLT_MASK                       (0xFFUL << I2C_SLTL_SSLT_SHIFT)                     /*!< I2C0_SLTL: SSLT Mask                    */
#define I2C_SLTL_SSLT_SHIFT                      0                                                   /*!< I2C0_SLTL: SSLT Position                */
#define I2C_SLTL_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTL_SSLT_SHIFT))&I2C_SLTL_SSLT_MASK) /*!< I2C0_SLTL                               */
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
* @addtogroup I2S_Peripheral_access_layer_GROUP I2S Peripheral Access Layer
* @brief C Struct for I2S
* @{
*/

/* ================================================================================ */
/* ================           I2S0 (file:I2S0_2CH)                 ================ */
/* ================================================================================ */

/**
 * @brief Inter-IC Sound / Synchronous Audio Interface
 */
/**
* @addtogroup I2S_structs_GROUP I2S struct
* @brief Struct for I2S
* @{
*/
typedef struct {                                /*       I2S0 Structure                                               */
   __IO uint32_t  TCSR;                         /**< 0000: SAI Transmit Control Register                                */
   __IO uint32_t  TCR1;                         /**< 0004: SAI Transmit Configuration 1 Register                        */
   __IO uint32_t  TCR2;                         /**< 0008: SAI Transmit Configuration 2 Register                        */
   __IO uint32_t  TCR3;                         /**< 000C: SAI Transmit Configuration 3 Register                        */
   __IO uint32_t  TCR4;                         /**< 0010: SAI Transmit Configuration 4 Register                        */
   __IO uint32_t  TCR5;                         /**< 0014: SAI Transmit Configuration 5 Register                        */
   __I  uint32_t  RESERVED0[2];                
   __O  uint32_t  TDR[2];                       /**< 0020: Transmit Data Register                                       */
   __I  uint32_t  RESERVED1[6];                
   __I  uint32_t  TFR[2];                       /**< 0040: SAI Transmit FIFO Register                                   */
   __I  uint32_t  RESERVED2[6];                
   __IO uint32_t  TMR;                          /**< 0060: SAI Transmit Mask Register                                   */
   __I  uint32_t  RESERVED3[7];                
   __IO uint32_t  RCSR;                         /**< 0080: SAI Receive Control Register                                 */
   __IO uint32_t  RCR1;                         /**< 0084: SAI Receive Configuration 1 Register                         */
   __IO uint32_t  RCR2;                         /**< 0088: SAI Receive Configuration 2 Register                         */
   __IO uint32_t  RCR3;                         /**< 008C: SAI Receive Configuration 3 Register                         */
   __IO uint32_t  RCR4;                         /**< 0090: SAI Receive Configuration 4 Register                         */
   __IO uint32_t  RCR5;                         /**< 0094: SAI Receive Configuration 5 Register                         */
   __I  uint32_t  RESERVED4[2];                
   __I  uint32_t  RDR[2];                       /**< 00A0: SAI Receive Data Register                                    */
   __I  uint32_t  RESERVED5[6];                
   __I  uint32_t  RFR[2];                       /**< 00C0: SAI Receive FIFO Register                                    */
   __I  uint32_t  RESERVED6[6];                
   __IO uint32_t  RMR;                          /**< 00E0: SAI Receive Mask Register                                    */
   __I  uint32_t  RESERVED7[7];                
   __IO uint32_t  MCR;                          /**< 0100: SAI MCLK Control Register                                    */
   __IO uint32_t  MDR;                          /**< 0104: SAI MCLK Divide Register                                     */
} I2S_Type;

/**
 * @} */ /* End group I2S_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'I2S0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup I2S_Register_Masks_GROUP I2S Register Masks
* @brief Register Masks for I2S
* @{
*/
/* ------- TCSR Bit Fields                          ------ */
#define I2S_TCSR_FRDE_MASK                       (0x01UL << I2S_TCSR_FRDE_SHIFT)                     /*!< I2S0_TCSR: FRDE Mask                    */
#define I2S_TCSR_FRDE_SHIFT                      0                                                   /*!< I2S0_TCSR: FRDE Position                */
#define I2S_TCSR_FRDE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FRDE_SHIFT))&I2S_TCSR_FRDE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FWDE_MASK                       (0x01UL << I2S_TCSR_FWDE_SHIFT)                     /*!< I2S0_TCSR: FWDE Mask                    */
#define I2S_TCSR_FWDE_SHIFT                      1                                                   /*!< I2S0_TCSR: FWDE Position                */
#define I2S_TCSR_FWDE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FWDE_SHIFT))&I2S_TCSR_FWDE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FRIE_MASK                       (0x01UL << I2S_TCSR_FRIE_SHIFT)                     /*!< I2S0_TCSR: FRIE Mask                    */
#define I2S_TCSR_FRIE_SHIFT                      8                                                   /*!< I2S0_TCSR: FRIE Position                */
#define I2S_TCSR_FRIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FRIE_SHIFT))&I2S_TCSR_FRIE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FWIE_MASK                       (0x01UL << I2S_TCSR_FWIE_SHIFT)                     /*!< I2S0_TCSR: FWIE Mask                    */
#define I2S_TCSR_FWIE_SHIFT                      9                                                   /*!< I2S0_TCSR: FWIE Position                */
#define I2S_TCSR_FWIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FWIE_SHIFT))&I2S_TCSR_FWIE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FEIE_MASK                       (0x01UL << I2S_TCSR_FEIE_SHIFT)                     /*!< I2S0_TCSR: FEIE Mask                    */
#define I2S_TCSR_FEIE_SHIFT                      10                                                  /*!< I2S0_TCSR: FEIE Position                */
#define I2S_TCSR_FEIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FEIE_SHIFT))&I2S_TCSR_FEIE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_SEIE_MASK                       (0x01UL << I2S_TCSR_SEIE_SHIFT)                     /*!< I2S0_TCSR: SEIE Mask                    */
#define I2S_TCSR_SEIE_SHIFT                      11                                                  /*!< I2S0_TCSR: SEIE Position                */
#define I2S_TCSR_SEIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_SEIE_SHIFT))&I2S_TCSR_SEIE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_WSIE_MASK                       (0x01UL << I2S_TCSR_WSIE_SHIFT)                     /*!< I2S0_TCSR: WSIE Mask                    */
#define I2S_TCSR_WSIE_SHIFT                      12                                                  /*!< I2S0_TCSR: WSIE Position                */
#define I2S_TCSR_WSIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_WSIE_SHIFT))&I2S_TCSR_WSIE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FRF_MASK                        (0x01UL << I2S_TCSR_FRF_SHIFT)                      /*!< I2S0_TCSR: FRF Mask                     */
#define I2S_TCSR_FRF_SHIFT                       16                                                  /*!< I2S0_TCSR: FRF Position                 */
#define I2S_TCSR_FRF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FRF_SHIFT))&I2S_TCSR_FRF_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FWF_MASK                        (0x01UL << I2S_TCSR_FWF_SHIFT)                      /*!< I2S0_TCSR: FWF Mask                     */
#define I2S_TCSR_FWF_SHIFT                       17                                                  /*!< I2S0_TCSR: FWF Position                 */
#define I2S_TCSR_FWF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FWF_SHIFT))&I2S_TCSR_FWF_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FEF_MASK                        (0x01UL << I2S_TCSR_FEF_SHIFT)                      /*!< I2S0_TCSR: FEF Mask                     */
#define I2S_TCSR_FEF_SHIFT                       18                                                  /*!< I2S0_TCSR: FEF Position                 */
#define I2S_TCSR_FEF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FEF_SHIFT))&I2S_TCSR_FEF_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_SEF_MASK                        (0x01UL << I2S_TCSR_SEF_SHIFT)                      /*!< I2S0_TCSR: SEF Mask                     */
#define I2S_TCSR_SEF_SHIFT                       19                                                  /*!< I2S0_TCSR: SEF Position                 */
#define I2S_TCSR_SEF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_SEF_SHIFT))&I2S_TCSR_SEF_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_WSF_MASK                        (0x01UL << I2S_TCSR_WSF_SHIFT)                      /*!< I2S0_TCSR: WSF Mask                     */
#define I2S_TCSR_WSF_SHIFT                       20                                                  /*!< I2S0_TCSR: WSF Position                 */
#define I2S_TCSR_WSF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_WSF_SHIFT))&I2S_TCSR_WSF_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_SR_MASK                         (0x01UL << I2S_TCSR_SR_SHIFT)                       /*!< I2S0_TCSR: SR Mask                      */
#define I2S_TCSR_SR_SHIFT                        24                                                  /*!< I2S0_TCSR: SR Position                  */
#define I2S_TCSR_SR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_SR_SHIFT))&I2S_TCSR_SR_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_FR_MASK                         (0x01UL << I2S_TCSR_FR_SHIFT)                       /*!< I2S0_TCSR: FR Mask                      */
#define I2S_TCSR_FR_SHIFT                        25                                                  /*!< I2S0_TCSR: FR Position                  */
#define I2S_TCSR_FR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_FR_SHIFT))&I2S_TCSR_FR_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_BCE_MASK                        (0x01UL << I2S_TCSR_BCE_SHIFT)                      /*!< I2S0_TCSR: BCE Mask                     */
#define I2S_TCSR_BCE_SHIFT                       28                                                  /*!< I2S0_TCSR: BCE Position                 */
#define I2S_TCSR_BCE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_BCE_SHIFT))&I2S_TCSR_BCE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_DBGE_MASK                       (0x01UL << I2S_TCSR_DBGE_SHIFT)                     /*!< I2S0_TCSR: DBGE Mask                    */
#define I2S_TCSR_DBGE_SHIFT                      29                                                  /*!< I2S0_TCSR: DBGE Position                */
#define I2S_TCSR_DBGE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_DBGE_SHIFT))&I2S_TCSR_DBGE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_STOPE_MASK                      (0x01UL << I2S_TCSR_STOPE_SHIFT)                    /*!< I2S0_TCSR: STOPE Mask                   */
#define I2S_TCSR_STOPE_SHIFT                     30                                                  /*!< I2S0_TCSR: STOPE Position               */
#define I2S_TCSR_STOPE(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_STOPE_SHIFT))&I2S_TCSR_STOPE_MASK) /*!< I2S0_TCSR                               */
#define I2S_TCSR_TE_MASK                         (0x01UL << I2S_TCSR_TE_SHIFT)                       /*!< I2S0_TCSR: TE Mask                      */
#define I2S_TCSR_TE_SHIFT                        31                                                  /*!< I2S0_TCSR: TE Position                  */
#define I2S_TCSR_TE(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TCSR_TE_SHIFT))&I2S_TCSR_TE_MASK) /*!< I2S0_TCSR                               */
/* ------- TCR1 Bit Fields                          ------ */
#define I2S_TCR1_TFW_MASK                        (0x07UL << I2S_TCR1_TFW_SHIFT)                      /*!< I2S0_TCR1: TFW Mask                     */
#define I2S_TCR1_TFW_SHIFT                       0                                                   /*!< I2S0_TCR1: TFW Position                 */
#define I2S_TCR1_TFW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR1_TFW_SHIFT))&I2S_TCR1_TFW_MASK) /*!< I2S0_TCR1                               */
/* ------- TCR2 Bit Fields                          ------ */
#define I2S_TCR2_DIV_MASK                        (0xFFUL << I2S_TCR2_DIV_SHIFT)                      /*!< I2S0_TCR2: DIV Mask                     */
#define I2S_TCR2_DIV_SHIFT                       0                                                   /*!< I2S0_TCR2: DIV Position                 */
#define I2S_TCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_DIV_SHIFT))&I2S_TCR2_DIV_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_BCD_MASK                        (0x01UL << I2S_TCR2_BCD_SHIFT)                      /*!< I2S0_TCR2: BCD Mask                     */
#define I2S_TCR2_BCD_SHIFT                       24                                                  /*!< I2S0_TCR2: BCD Position                 */
#define I2S_TCR2_BCD(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_BCD_SHIFT))&I2S_TCR2_BCD_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_BCP_MASK                        (0x01UL << I2S_TCR2_BCP_SHIFT)                      /*!< I2S0_TCR2: BCP Mask                     */
#define I2S_TCR2_BCP_SHIFT                       25                                                  /*!< I2S0_TCR2: BCP Position                 */
#define I2S_TCR2_BCP(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_BCP_SHIFT))&I2S_TCR2_BCP_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_MSEL_MASK                       (0x03UL << I2S_TCR2_MSEL_SHIFT)                     /*!< I2S0_TCR2: MSEL Mask                    */
#define I2S_TCR2_MSEL_SHIFT                      26                                                  /*!< I2S0_TCR2: MSEL Position                */
#define I2S_TCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_MSEL_SHIFT))&I2S_TCR2_MSEL_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_BCI_MASK                        (0x01UL << I2S_TCR2_BCI_SHIFT)                      /*!< I2S0_TCR2: BCI Mask                     */
#define I2S_TCR2_BCI_SHIFT                       28                                                  /*!< I2S0_TCR2: BCI Position                 */
#define I2S_TCR2_BCI(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_BCI_SHIFT))&I2S_TCR2_BCI_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_BCS_MASK                        (0x01UL << I2S_TCR2_BCS_SHIFT)                      /*!< I2S0_TCR2: BCS Mask                     */
#define I2S_TCR2_BCS_SHIFT                       29                                                  /*!< I2S0_TCR2: BCS Position                 */
#define I2S_TCR2_BCS(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_BCS_SHIFT))&I2S_TCR2_BCS_MASK) /*!< I2S0_TCR2                               */
#define I2S_TCR2_SYNC_MASK                       (0x03UL << I2S_TCR2_SYNC_SHIFT)                     /*!< I2S0_TCR2: SYNC Mask                    */
#define I2S_TCR2_SYNC_SHIFT                      30                                                  /*!< I2S0_TCR2: SYNC Position                */
#define I2S_TCR2_SYNC(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR2_SYNC_SHIFT))&I2S_TCR2_SYNC_MASK) /*!< I2S0_TCR2                               */
/* ------- TCR3 Bit Fields                          ------ */
#define I2S_TCR3_WDFL_MASK                       (0x1FUL << I2S_TCR3_WDFL_SHIFT)                     /*!< I2S0_TCR3: WDFL Mask                    */
#define I2S_TCR3_WDFL_SHIFT                      0                                                   /*!< I2S0_TCR3: WDFL Position                */
#define I2S_TCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR3_WDFL_SHIFT))&I2S_TCR3_WDFL_MASK) /*!< I2S0_TCR3                               */
#define I2S_TCR3_TCE_MASK                        (0x03UL << I2S_TCR3_TCE_SHIFT)                      /*!< I2S0_TCR3: TCE Mask                     */
#define I2S_TCR3_TCE_SHIFT                       16                                                  /*!< I2S0_TCR3: TCE Position                 */
#define I2S_TCR3_TCE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR3_TCE_SHIFT))&I2S_TCR3_TCE_MASK) /*!< I2S0_TCR3                               */
/* ------- TCR4 Bit Fields                          ------ */
#define I2S_TCR4_FSD_MASK                        (0x01UL << I2S_TCR4_FSD_SHIFT)                      /*!< I2S0_TCR4: FSD Mask                     */
#define I2S_TCR4_FSD_SHIFT                       0                                                   /*!< I2S0_TCR4: FSD Position                 */
#define I2S_TCR4_FSD(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FSD_SHIFT))&I2S_TCR4_FSD_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_FSP_MASK                        (0x01UL << I2S_TCR4_FSP_SHIFT)                      /*!< I2S0_TCR4: FSP Mask                     */
#define I2S_TCR4_FSP_SHIFT                       1                                                   /*!< I2S0_TCR4: FSP Position                 */
#define I2S_TCR4_FSP(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FSP_SHIFT))&I2S_TCR4_FSP_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_FSE_MASK                        (0x01UL << I2S_TCR4_FSE_SHIFT)                      /*!< I2S0_TCR4: FSE Mask                     */
#define I2S_TCR4_FSE_SHIFT                       3                                                   /*!< I2S0_TCR4: FSE Position                 */
#define I2S_TCR4_FSE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FSE_SHIFT))&I2S_TCR4_FSE_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_MF_MASK                         (0x01UL << I2S_TCR4_MF_SHIFT)                       /*!< I2S0_TCR4: MF Mask                      */
#define I2S_TCR4_MF_SHIFT                        4                                                   /*!< I2S0_TCR4: MF Position                  */
#define I2S_TCR4_MF(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_MF_SHIFT))&I2S_TCR4_MF_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_SYWD_MASK                       (0x1FUL << I2S_TCR4_SYWD_SHIFT)                     /*!< I2S0_TCR4: SYWD Mask                    */
#define I2S_TCR4_SYWD_SHIFT                      8                                                   /*!< I2S0_TCR4: SYWD Position                */
#define I2S_TCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_SYWD_SHIFT))&I2S_TCR4_SYWD_MASK) /*!< I2S0_TCR4                               */
#define I2S_TCR4_FRSZ_MASK                       (0x1FUL << I2S_TCR4_FRSZ_SHIFT)                     /*!< I2S0_TCR4: FRSZ Mask                    */
#define I2S_TCR4_FRSZ_SHIFT                      16                                                  /*!< I2S0_TCR4: FRSZ Position                */
#define I2S_TCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_TCR4_FRSZ_SHIFT))&I2S_TCR4_FRSZ_MASK) /*!< I2S0_TCR4                               */
/* ------- TCR5 Bit Fields                          ------ */
#define I2S_TCR5_FBT_MASK                        (0x1FUL << I2S_TCR5_FBT_SHIFT)                      /*!< I2S0_TCR5: FBT Mask                     */
#define I2S_TCR5_FBT_SHIFT                       8                                                   /*!< I2S0_TCR5: FBT Position                 */
#define I2S_TCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_FBT_SHIFT))&I2S_TCR5_FBT_MASK) /*!< I2S0_TCR5                               */
#define I2S_TCR5_W0W_MASK                        (0x1FUL << I2S_TCR5_W0W_SHIFT)                      /*!< I2S0_TCR5: W0W Mask                     */
#define I2S_TCR5_W0W_SHIFT                       16                                                  /*!< I2S0_TCR5: W0W Position                 */
#define I2S_TCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_W0W_SHIFT))&I2S_TCR5_W0W_MASK) /*!< I2S0_TCR5                               */
#define I2S_TCR5_WNW_MASK                        (0x1FUL << I2S_TCR5_WNW_SHIFT)                      /*!< I2S0_TCR5: WNW Mask                     */
#define I2S_TCR5_WNW_SHIFT                       24                                                  /*!< I2S0_TCR5: WNW Position                 */
#define I2S_TCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_TCR5_WNW_SHIFT))&I2S_TCR5_WNW_MASK) /*!< I2S0_TCR5                               */
/* ------- TDR Bit Fields                           ------ */
#define I2S_TDR_TDR_MASK                         (0xFFFFFFFFUL << I2S_TDR_TDR_SHIFT)                 /*!< I2S0_TDR: TDR Mask                      */
#define I2S_TDR_TDR_SHIFT                        0                                                   /*!< I2S0_TDR: TDR Position                  */
#define I2S_TDR_TDR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TDR_TDR_SHIFT))&I2S_TDR_TDR_MASK) /*!< I2S0_TDR                                */
/* ------- TFR Bit Fields                           ------ */
#define I2S_TFR_RFP_MASK                         (0x0FUL << I2S_TFR_RFP_SHIFT)                       /*!< I2S0_TFR: RFP Mask                      */
#define I2S_TFR_RFP_SHIFT                        0                                                   /*!< I2S0_TFR: RFP Position                  */
#define I2S_TFR_RFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TFR_RFP_SHIFT))&I2S_TFR_RFP_MASK) /*!< I2S0_TFR                                */
#define I2S_TFR_WFP_MASK                         (0x0FUL << I2S_TFR_WFP_SHIFT)                       /*!< I2S0_TFR: WFP Mask                      */
#define I2S_TFR_WFP_SHIFT                        16                                                  /*!< I2S0_TFR: WFP Position                  */
#define I2S_TFR_WFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TFR_WFP_SHIFT))&I2S_TFR_WFP_MASK) /*!< I2S0_TFR                                */
/* ------- TMR Bit Fields                           ------ */
#define I2S_TMR_TWM_MASK                         (0xFFFFUL << I2S_TMR_TWM_SHIFT)                     /*!< I2S0_TMR: TWM Mask                      */
#define I2S_TMR_TWM_SHIFT                        0                                                   /*!< I2S0_TMR: TWM Position                  */
#define I2S_TMR_TWM(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_TMR_TWM_SHIFT))&I2S_TMR_TWM_MASK) /*!< I2S0_TMR                                */
/* ------- RCSR Bit Fields                          ------ */
#define I2S_RCSR_FRDE_MASK                       (0x01UL << I2S_RCSR_FRDE_SHIFT)                     /*!< I2S0_RCSR: FRDE Mask                    */
#define I2S_RCSR_FRDE_SHIFT                      0                                                   /*!< I2S0_RCSR: FRDE Position                */
#define I2S_RCSR_FRDE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FRDE_SHIFT))&I2S_RCSR_FRDE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FWDE_MASK                       (0x01UL << I2S_RCSR_FWDE_SHIFT)                     /*!< I2S0_RCSR: FWDE Mask                    */
#define I2S_RCSR_FWDE_SHIFT                      1                                                   /*!< I2S0_RCSR: FWDE Position                */
#define I2S_RCSR_FWDE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FWDE_SHIFT))&I2S_RCSR_FWDE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FRIE_MASK                       (0x01UL << I2S_RCSR_FRIE_SHIFT)                     /*!< I2S0_RCSR: FRIE Mask                    */
#define I2S_RCSR_FRIE_SHIFT                      8                                                   /*!< I2S0_RCSR: FRIE Position                */
#define I2S_RCSR_FRIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FRIE_SHIFT))&I2S_RCSR_FRIE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FWIE_MASK                       (0x01UL << I2S_RCSR_FWIE_SHIFT)                     /*!< I2S0_RCSR: FWIE Mask                    */
#define I2S_RCSR_FWIE_SHIFT                      9                                                   /*!< I2S0_RCSR: FWIE Position                */
#define I2S_RCSR_FWIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FWIE_SHIFT))&I2S_RCSR_FWIE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FEIE_MASK                       (0x01UL << I2S_RCSR_FEIE_SHIFT)                     /*!< I2S0_RCSR: FEIE Mask                    */
#define I2S_RCSR_FEIE_SHIFT                      10                                                  /*!< I2S0_RCSR: FEIE Position                */
#define I2S_RCSR_FEIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FEIE_SHIFT))&I2S_RCSR_FEIE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_SEIE_MASK                       (0x01UL << I2S_RCSR_SEIE_SHIFT)                     /*!< I2S0_RCSR: SEIE Mask                    */
#define I2S_RCSR_SEIE_SHIFT                      11                                                  /*!< I2S0_RCSR: SEIE Position                */
#define I2S_RCSR_SEIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_SEIE_SHIFT))&I2S_RCSR_SEIE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_WSIE_MASK                       (0x01UL << I2S_RCSR_WSIE_SHIFT)                     /*!< I2S0_RCSR: WSIE Mask                    */
#define I2S_RCSR_WSIE_SHIFT                      12                                                  /*!< I2S0_RCSR: WSIE Position                */
#define I2S_RCSR_WSIE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_WSIE_SHIFT))&I2S_RCSR_WSIE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FRF_MASK                        (0x01UL << I2S_RCSR_FRF_SHIFT)                      /*!< I2S0_RCSR: FRF Mask                     */
#define I2S_RCSR_FRF_SHIFT                       16                                                  /*!< I2S0_RCSR: FRF Position                 */
#define I2S_RCSR_FRF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FRF_SHIFT))&I2S_RCSR_FRF_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FWF_MASK                        (0x01UL << I2S_RCSR_FWF_SHIFT)                      /*!< I2S0_RCSR: FWF Mask                     */
#define I2S_RCSR_FWF_SHIFT                       17                                                  /*!< I2S0_RCSR: FWF Position                 */
#define I2S_RCSR_FWF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FWF_SHIFT))&I2S_RCSR_FWF_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FEF_MASK                        (0x01UL << I2S_RCSR_FEF_SHIFT)                      /*!< I2S0_RCSR: FEF Mask                     */
#define I2S_RCSR_FEF_SHIFT                       18                                                  /*!< I2S0_RCSR: FEF Position                 */
#define I2S_RCSR_FEF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FEF_SHIFT))&I2S_RCSR_FEF_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_SEF_MASK                        (0x01UL << I2S_RCSR_SEF_SHIFT)                      /*!< I2S0_RCSR: SEF Mask                     */
#define I2S_RCSR_SEF_SHIFT                       19                                                  /*!< I2S0_RCSR: SEF Position                 */
#define I2S_RCSR_SEF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_SEF_SHIFT))&I2S_RCSR_SEF_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_WSF_MASK                        (0x01UL << I2S_RCSR_WSF_SHIFT)                      /*!< I2S0_RCSR: WSF Mask                     */
#define I2S_RCSR_WSF_SHIFT                       20                                                  /*!< I2S0_RCSR: WSF Position                 */
#define I2S_RCSR_WSF(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_WSF_SHIFT))&I2S_RCSR_WSF_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_SR_MASK                         (0x01UL << I2S_RCSR_SR_SHIFT)                       /*!< I2S0_RCSR: SR Mask                      */
#define I2S_RCSR_SR_SHIFT                        24                                                  /*!< I2S0_RCSR: SR Position                  */
#define I2S_RCSR_SR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_SR_SHIFT))&I2S_RCSR_SR_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_FR_MASK                         (0x01UL << I2S_RCSR_FR_SHIFT)                       /*!< I2S0_RCSR: FR Mask                      */
#define I2S_RCSR_FR_SHIFT                        25                                                  /*!< I2S0_RCSR: FR Position                  */
#define I2S_RCSR_FR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_FR_SHIFT))&I2S_RCSR_FR_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_BCE_MASK                        (0x01UL << I2S_RCSR_BCE_SHIFT)                      /*!< I2S0_RCSR: BCE Mask                     */
#define I2S_RCSR_BCE_SHIFT                       28                                                  /*!< I2S0_RCSR: BCE Position                 */
#define I2S_RCSR_BCE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_BCE_SHIFT))&I2S_RCSR_BCE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_DBGE_MASK                       (0x01UL << I2S_RCSR_DBGE_SHIFT)                     /*!< I2S0_RCSR: DBGE Mask                    */
#define I2S_RCSR_DBGE_SHIFT                      29                                                  /*!< I2S0_RCSR: DBGE Position                */
#define I2S_RCSR_DBGE(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_DBGE_SHIFT))&I2S_RCSR_DBGE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_STOPE_MASK                      (0x01UL << I2S_RCSR_STOPE_SHIFT)                    /*!< I2S0_RCSR: STOPE Mask                   */
#define I2S_RCSR_STOPE_SHIFT                     30                                                  /*!< I2S0_RCSR: STOPE Position               */
#define I2S_RCSR_STOPE(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_STOPE_SHIFT))&I2S_RCSR_STOPE_MASK) /*!< I2S0_RCSR                               */
#define I2S_RCSR_RE_MASK                         (0x01UL << I2S_RCSR_RE_SHIFT)                       /*!< I2S0_RCSR: RE Mask                      */
#define I2S_RCSR_RE_SHIFT                        31                                                  /*!< I2S0_RCSR: RE Position                  */
#define I2S_RCSR_RE(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RCSR_RE_SHIFT))&I2S_RCSR_RE_MASK) /*!< I2S0_RCSR                               */
/* ------- RCR1 Bit Fields                          ------ */
#define I2S_RCR1_RFW_MASK                        (0x07UL << I2S_RCR1_RFW_SHIFT)                      /*!< I2S0_RCR1: RFW Mask                     */
#define I2S_RCR1_RFW_SHIFT                       0                                                   /*!< I2S0_RCR1: RFW Position                 */
#define I2S_RCR1_RFW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR1_RFW_SHIFT))&I2S_RCR1_RFW_MASK) /*!< I2S0_RCR1                               */
/* ------- RCR2 Bit Fields                          ------ */
#define I2S_RCR2_DIV_MASK                        (0xFFUL << I2S_RCR2_DIV_SHIFT)                      /*!< I2S0_RCR2: DIV Mask                     */
#define I2S_RCR2_DIV_SHIFT                       0                                                   /*!< I2S0_RCR2: DIV Position                 */
#define I2S_RCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_DIV_SHIFT))&I2S_RCR2_DIV_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_BCD_MASK                        (0x01UL << I2S_RCR2_BCD_SHIFT)                      /*!< I2S0_RCR2: BCD Mask                     */
#define I2S_RCR2_BCD_SHIFT                       24                                                  /*!< I2S0_RCR2: BCD Position                 */
#define I2S_RCR2_BCD(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_BCD_SHIFT))&I2S_RCR2_BCD_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_BCP_MASK                        (0x01UL << I2S_RCR2_BCP_SHIFT)                      /*!< I2S0_RCR2: BCP Mask                     */
#define I2S_RCR2_BCP_SHIFT                       25                                                  /*!< I2S0_RCR2: BCP Position                 */
#define I2S_RCR2_BCP(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_BCP_SHIFT))&I2S_RCR2_BCP_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_MSEL_MASK                       (0x03UL << I2S_RCR2_MSEL_SHIFT)                     /*!< I2S0_RCR2: MSEL Mask                    */
#define I2S_RCR2_MSEL_SHIFT                      26                                                  /*!< I2S0_RCR2: MSEL Position                */
#define I2S_RCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_MSEL_SHIFT))&I2S_RCR2_MSEL_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_BCI_MASK                        (0x01UL << I2S_RCR2_BCI_SHIFT)                      /*!< I2S0_RCR2: BCI Mask                     */
#define I2S_RCR2_BCI_SHIFT                       28                                                  /*!< I2S0_RCR2: BCI Position                 */
#define I2S_RCR2_BCI(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_BCI_SHIFT))&I2S_RCR2_BCI_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_BCS_MASK                        (0x01UL << I2S_RCR2_BCS_SHIFT)                      /*!< I2S0_RCR2: BCS Mask                     */
#define I2S_RCR2_BCS_SHIFT                       29                                                  /*!< I2S0_RCR2: BCS Position                 */
#define I2S_RCR2_BCS(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_BCS_SHIFT))&I2S_RCR2_BCS_MASK) /*!< I2S0_RCR2                               */
#define I2S_RCR2_SYNC_MASK                       (0x03UL << I2S_RCR2_SYNC_SHIFT)                     /*!< I2S0_RCR2: SYNC Mask                    */
#define I2S_RCR2_SYNC_SHIFT                      30                                                  /*!< I2S0_RCR2: SYNC Position                */
#define I2S_RCR2_SYNC(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR2_SYNC_SHIFT))&I2S_RCR2_SYNC_MASK) /*!< I2S0_RCR2                               */
/* ------- RCR3 Bit Fields                          ------ */
#define I2S_RCR3_WDFL_MASK                       (0x1FUL << I2S_RCR3_WDFL_SHIFT)                     /*!< I2S0_RCR3: WDFL Mask                    */
#define I2S_RCR3_WDFL_SHIFT                      0                                                   /*!< I2S0_RCR3: WDFL Position                */
#define I2S_RCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR3_WDFL_SHIFT))&I2S_RCR3_WDFL_MASK) /*!< I2S0_RCR3                               */
#define I2S_RCR3_RCE_MASK                        (0x03UL << I2S_RCR3_RCE_SHIFT)                      /*!< I2S0_RCR3: RCE Mask                     */
#define I2S_RCR3_RCE_SHIFT                       16                                                  /*!< I2S0_RCR3: RCE Position                 */
#define I2S_RCR3_RCE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR3_RCE_SHIFT))&I2S_RCR3_RCE_MASK) /*!< I2S0_RCR3                               */
/* ------- RCR4 Bit Fields                          ------ */
#define I2S_RCR4_FSD_MASK                        (0x01UL << I2S_RCR4_FSD_SHIFT)                      /*!< I2S0_RCR4: FSD Mask                     */
#define I2S_RCR4_FSD_SHIFT                       0                                                   /*!< I2S0_RCR4: FSD Position                 */
#define I2S_RCR4_FSD(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FSD_SHIFT))&I2S_RCR4_FSD_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_FSP_MASK                        (0x01UL << I2S_RCR4_FSP_SHIFT)                      /*!< I2S0_RCR4: FSP Mask                     */
#define I2S_RCR4_FSP_SHIFT                       1                                                   /*!< I2S0_RCR4: FSP Position                 */
#define I2S_RCR4_FSP(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FSP_SHIFT))&I2S_RCR4_FSP_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_FSE_MASK                        (0x01UL << I2S_RCR4_FSE_SHIFT)                      /*!< I2S0_RCR4: FSE Mask                     */
#define I2S_RCR4_FSE_SHIFT                       3                                                   /*!< I2S0_RCR4: FSE Position                 */
#define I2S_RCR4_FSE(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FSE_SHIFT))&I2S_RCR4_FSE_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_MF_MASK                         (0x01UL << I2S_RCR4_MF_SHIFT)                       /*!< I2S0_RCR4: MF Mask                      */
#define I2S_RCR4_MF_SHIFT                        4                                                   /*!< I2S0_RCR4: MF Position                  */
#define I2S_RCR4_MF(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_MF_SHIFT))&I2S_RCR4_MF_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_SYWD_MASK                       (0x1FUL << I2S_RCR4_SYWD_SHIFT)                     /*!< I2S0_RCR4: SYWD Mask                    */
#define I2S_RCR4_SYWD_SHIFT                      8                                                   /*!< I2S0_RCR4: SYWD Position                */
#define I2S_RCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_SYWD_SHIFT))&I2S_RCR4_SYWD_MASK) /*!< I2S0_RCR4                               */
#define I2S_RCR4_FRSZ_MASK                       (0x1FUL << I2S_RCR4_FRSZ_SHIFT)                     /*!< I2S0_RCR4: FRSZ Mask                    */
#define I2S_RCR4_FRSZ_SHIFT                      16                                                  /*!< I2S0_RCR4: FRSZ Position                */
#define I2S_RCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_RCR4_FRSZ_SHIFT))&I2S_RCR4_FRSZ_MASK) /*!< I2S0_RCR4                               */
/* ------- RCR5 Bit Fields                          ------ */
#define I2S_RCR5_FBT_MASK                        (0x1FUL << I2S_RCR5_FBT_SHIFT)                      /*!< I2S0_RCR5: FBT Mask                     */
#define I2S_RCR5_FBT_SHIFT                       8                                                   /*!< I2S0_RCR5: FBT Position                 */
#define I2S_RCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_FBT_SHIFT))&I2S_RCR5_FBT_MASK) /*!< I2S0_RCR5                               */
#define I2S_RCR5_W0W_MASK                        (0x1FUL << I2S_RCR5_W0W_SHIFT)                      /*!< I2S0_RCR5: W0W Mask                     */
#define I2S_RCR5_W0W_SHIFT                       16                                                  /*!< I2S0_RCR5: W0W Position                 */
#define I2S_RCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_W0W_SHIFT))&I2S_RCR5_W0W_MASK) /*!< I2S0_RCR5                               */
#define I2S_RCR5_WNW_MASK                        (0x1FUL << I2S_RCR5_WNW_SHIFT)                      /*!< I2S0_RCR5: WNW Mask                     */
#define I2S_RCR5_WNW_SHIFT                       24                                                  /*!< I2S0_RCR5: WNW Position                 */
#define I2S_RCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_RCR5_WNW_SHIFT))&I2S_RCR5_WNW_MASK) /*!< I2S0_RCR5                               */
/* ------- RDR Bit Fields                           ------ */
#define I2S_RDR_RDR_MASK                         (0xFFFFFFFFUL << I2S_RDR_RDR_SHIFT)                 /*!< I2S0_RDR: RDR Mask                      */
#define I2S_RDR_RDR_SHIFT                        0                                                   /*!< I2S0_RDR: RDR Position                  */
#define I2S_RDR_RDR(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RDR_RDR_SHIFT))&I2S_RDR_RDR_MASK) /*!< I2S0_RDR                                */
/* ------- RFR Bit Fields                           ------ */
#define I2S_RFR_RFP_MASK                         (0x0FUL << I2S_RFR_RFP_SHIFT)                       /*!< I2S0_RFR: RFP Mask                      */
#define I2S_RFR_RFP_SHIFT                        0                                                   /*!< I2S0_RFR: RFP Position                  */
#define I2S_RFR_RFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RFR_RFP_SHIFT))&I2S_RFR_RFP_MASK) /*!< I2S0_RFR                                */
#define I2S_RFR_WFP_MASK                         (0x0FUL << I2S_RFR_WFP_SHIFT)                       /*!< I2S0_RFR: WFP Mask                      */
#define I2S_RFR_WFP_SHIFT                        16                                                  /*!< I2S0_RFR: WFP Position                  */
#define I2S_RFR_WFP(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RFR_WFP_SHIFT))&I2S_RFR_WFP_MASK) /*!< I2S0_RFR                                */
/* ------- RMR Bit Fields                           ------ */
#define I2S_RMR_RWM_MASK                         (0xFFFFUL << I2S_RMR_RWM_SHIFT)                     /*!< I2S0_RMR: RWM Mask                      */
#define I2S_RMR_RWM_SHIFT                        0                                                   /*!< I2S0_RMR: RWM Position                  */
#define I2S_RMR_RWM(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_RMR_RWM_SHIFT))&I2S_RMR_RWM_MASK) /*!< I2S0_RMR                                */
/* ------- MCR Bit Fields                           ------ */
#define I2S_MCR_MICS_MASK                        (0x03UL << I2S_MCR_MICS_SHIFT)                      /*!< I2S0_MCR: MICS Mask                     */
#define I2S_MCR_MICS_SHIFT                       24                                                  /*!< I2S0_MCR: MICS Position                 */
#define I2S_MCR_MICS(x)                          (((uint32_t)(((uint32_t)(x))<<I2S_MCR_MICS_SHIFT))&I2S_MCR_MICS_MASK) /*!< I2S0_MCR                                */
#define I2S_MCR_MOE_MASK                         (0x01UL << I2S_MCR_MOE_SHIFT)                       /*!< I2S0_MCR: MOE Mask                      */
#define I2S_MCR_MOE_SHIFT                        30                                                  /*!< I2S0_MCR: MOE Position                  */
#define I2S_MCR_MOE(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_MCR_MOE_SHIFT))&I2S_MCR_MOE_MASK) /*!< I2S0_MCR                                */
#define I2S_MCR_DUF_MASK                         (0x01UL << I2S_MCR_DUF_SHIFT)                       /*!< I2S0_MCR: DUF Mask                      */
#define I2S_MCR_DUF_SHIFT                        31                                                  /*!< I2S0_MCR: DUF Position                  */
#define I2S_MCR_DUF(x)                           (((uint32_t)(((uint32_t)(x))<<I2S_MCR_DUF_SHIFT))&I2S_MCR_DUF_MASK) /*!< I2S0_MCR                                */
/* ------- MDR Bit Fields                           ------ */
#define I2S_MDR_DIVIDE_MASK                      (0xFFFUL << I2S_MDR_DIVIDE_SHIFT)                   /*!< I2S0_MDR: DIVIDE Mask                   */
#define I2S_MDR_DIVIDE_SHIFT                     0                                                   /*!< I2S0_MDR: DIVIDE Position               */
#define I2S_MDR_DIVIDE(x)                        (((uint32_t)(((uint32_t)(x))<<I2S_MDR_DIVIDE_SHIFT))&I2S_MDR_DIVIDE_MASK) /*!< I2S0_MDR                                */
#define I2S_MDR_FRACT_MASK                       (0xFFUL << I2S_MDR_FRACT_SHIFT)                     /*!< I2S0_MDR: FRACT Mask                    */
#define I2S_MDR_FRACT_SHIFT                      12                                                  /*!< I2S0_MDR: FRACT Position                */
#define I2S_MDR_FRACT(x)                         (((uint32_t)(((uint32_t)(x))<<I2S_MDR_FRACT_SHIFT))&I2S_MDR_FRACT_MASK) /*!< I2S0_MDR                                */
/**
 * @} */ /* End group I2S_Register_Masks_GROUP 
 */

/* I2S0 - Peripheral instance base addresses */
#define I2S0_BasePtr                   0x4002F000UL //!< Peripheral base address
#define I2S0                           ((I2S_Type *) I2S0_BasePtr) //!< Freescale base pointer
#define I2S0_BASE_PTR                  (I2S0) //!< Freescale style base pointer
/**
 * @} */ /* End group I2S_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LCD_Peripheral_access_layer_GROUP LCD Peripheral Access Layer
* @brief C Struct for LCD
* @{
*/

/* ================================================================================ */
/* ================           LCD (file:LCD_MK)                    ================ */
/* ================================================================================ */

/**
 * @brief Segment Liquid Crystal Display
 */
/**
* @addtogroup LCD_structs_GROUP LCD struct
* @brief Struct for LCD
* @{
*/
typedef struct {                                /*       LCD Structure                                                */
   __IO uint32_t  GCR;                          /**< 0000: LCD General Control Register                                 */
   __IO uint32_t  AR;                           /**< 0004: LCD Auxiliary Register                                       */
   __IO uint32_t  FDCR;                         /**< 0008: LCD Fault Detect Control Register                            */
   __IO uint32_t  FDSR;                         /**< 000C: LCD Fault Detect Status Register                             */
   __IO uint32_t  PEN[2];                       /**< 0010: LCD Pin Enable                                               */
   __IO uint32_t  BPEN[2];                      /**< 0018: LCD Back Plane Enable register                               */
   union {                                      /**< 0000: (size=0040)                                                  */
      __IO uint8_t   WF[64];                    /**< 0020: LCD Waveform Register                                        */
      struct {                                  /**< 0000: (size=0040)                                                  */
         __IO uint32_t  WF3TO0;                 /**< 0020: LCD Waveform register                                        */
         __IO uint32_t  WF7TO4;                 /**< 0024: LCD Waveform register                                        */
         __IO uint32_t  WF11TO8;                /**< 0028: LCD Waveform register                                        */
         __IO uint32_t  WF15TO12;               /**< 002C: LCD Waveform register                                        */
         __IO uint32_t  WF19TO16;               /**< 0030: LCD Waveform register                                        */
         __IO uint32_t  WF23TO20;               /**< 0034: LCD Waveform register                                        */
         __IO uint32_t  WF27TO24;               /**< 0038: LCD Waveform register                                        */
         __IO uint32_t  WF31TO28;               /**< 003C: LCD Waveform register                                        */
         __IO uint32_t  WF35TO32;               /**< 0040: LCD Waveform register                                        */
         __IO uint32_t  WF39TO36;               /**< 0044: LCD Waveform register                                        */
         __IO uint32_t  WF43TO40;               /**< 0048: LCD Waveform register                                        */
         __IO uint32_t  WF47TO44;               /**< 004C: LCD Waveform register                                        */
         __IO uint32_t  WF51TO48;               /**< 0050: LCD Waveform register                                        */
         __IO uint32_t  WF55TO52;               /**< 0054: LCD Waveform register                                        */
         __IO uint32_t  WF59TO56;               /**< 0058: LCD Waveform register                                        */
         __IO uint32_t  WF63TO60;               /**< 005C: LCD Waveform register                                        */
      };
   };
} LCD_Type;

/**
 * @} */ /* End group LCD_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LCD' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup LCD_Register_Masks_GROUP LCD Register Masks
* @brief Register Masks for LCD
* @{
*/
/* ------- GCR Bit Fields                           ------ */
#define LCD_GCR_DUTY_MASK                        (0x07UL << LCD_GCR_DUTY_SHIFT)                      /*!< LCD_GCR: DUTY Mask                      */
#define LCD_GCR_DUTY_SHIFT                       0                                                   /*!< LCD_GCR: DUTY Position                  */
#define LCD_GCR_DUTY(x)                          (((uint32_t)(((uint32_t)(x))<<LCD_GCR_DUTY_SHIFT))&LCD_GCR_DUTY_MASK) /*!< LCD_GCR                                 */
#define LCD_GCR_LCLK_MASK                        (0x07UL << LCD_GCR_LCLK_SHIFT)                      /*!< LCD_GCR: LCLK Mask                      */
#define LCD_GCR_LCLK_SHIFT                       3                                                   /*!< LCD_GCR: LCLK Position                  */
#define LCD_GCR_LCLK(x)                          (((uint32_t)(((uint32_t)(x))<<LCD_GCR_LCLK_SHIFT))&LCD_GCR_LCLK_MASK) /*!< LCD_GCR                                 */
#define LCD_GCR_SOURCE_MASK                      (0x01UL << LCD_GCR_SOURCE_SHIFT)                    /*!< LCD_GCR: SOURCE Mask                    */
#define LCD_GCR_SOURCE_SHIFT                     6                                                   /*!< LCD_GCR: SOURCE Position                */
#define LCD_GCR_SOURCE(x)                        (((uint32_t)(((uint32_t)(x))<<LCD_GCR_SOURCE_SHIFT))&LCD_GCR_SOURCE_MASK) /*!< LCD_GCR                                 */
#define LCD_GCR_LCDEN_MASK                       (0x01UL << LCD_GCR_LCDEN_SHIFT)                     /*!< LCD_GCR: LCDEN Mask                     */
#define LCD_GCR_LCDEN_SHIFT                      7                                                   /*!< LCD_GCR: LCDEN Position                 */
#define LCD_GCR_LCDEN(x)                         (((uint32_t)(((uint32_t)(x))<<LCD_GCR_LCDEN_SHIFT))&LCD_GCR_LCDEN_MASK) /*!< LCD_GCR                                 */
#define LCD_GCR_LCDSTP_MASK                      (0x01UL << LCD_GCR_LCDSTP_SHIFT)                    /*!< LCD_GCR: LCDSTP Mask                    */
#define LCD_GCR_LCDSTP_SHIFT                     8                                                   /*!< LCD_GCR: LCDSTP Position                */
#define LCD_GCR_LCDSTP(x)                        (((uint32_t)(((uint32_t)(x))<<LCD_GCR_LCDSTP_SHIFT))&LCD_GCR_LCDSTP_MASK) /*!< LCD_GCR                                 */
#define LCD_GCR_LCDWAIT_MASK                     (0x01UL << LCD_GCR_LCDWAIT_SHIFT)                   /*!< LCD_GCR: LCDWAIT Mask                   */
#define LCD_GCR_LCDWAIT_SHIFT                    9                                                   /*!< LCD_GCR: LCDWAIT Position               */
#define LCD_GCR_LCDWAIT(x)                       (((uint32_t)(((uint32_t)(x))<<LCD_GCR_LCDWAIT_SHIFT))&LCD_GCR_LCDWAIT_MASK) /*!< LCD_GCR                                 */
#define LCD_GCR_ALTDIV_MASK                      (0x03UL << LCD_GCR_ALTDIV_SHIFT)                    /*!< LCD_GCR: ALTDIV Mask                    */
#define LCD_GCR_ALTDIV_SHIFT                     12                                                  /*!< LCD_GCR: ALTDIV Position                */
#define LCD_GCR_ALTDIV(x)                        (((uint32_t)(((uint32_t)(x))<<LCD_GCR_ALTDIV_SHIFT))&LCD_GCR_ALTDIV_MASK) /*!< LCD_GCR                                 */
#define LCD_GCR_FDCIEN_MASK                      (0x01UL << LCD_GCR_FDCIEN_SHIFT)                    /*!< LCD_GCR: FDCIEN Mask                    */
#define LCD_GCR_FDCIEN_SHIFT                     14                                                  /*!< LCD_GCR: FDCIEN Position                */
#define LCD_GCR_FDCIEN(x)                        (((uint32_t)(((uint32_t)(x))<<LCD_GCR_FDCIEN_SHIFT))&LCD_GCR_FDCIEN_MASK) /*!< LCD_GCR                                 */
#define LCD_GCR_LCDIEN_MASK                      (0x01UL << LCD_GCR_LCDIEN_SHIFT)                    /*!< LCD_GCR: LCDIEN Mask                    */
#define LCD_GCR_LCDIEN_SHIFT                     15                                                  /*!< LCD_GCR: LCDIEN Position                */
#define LCD_GCR_LCDIEN(x)                        (((uint32_t)(((uint32_t)(x))<<LCD_GCR_LCDIEN_SHIFT))&LCD_GCR_LCDIEN_MASK) /*!< LCD_GCR                                 */
#define LCD_GCR_VSUPPLY_MASK                     (0x03UL << LCD_GCR_VSUPPLY_SHIFT)                   /*!< LCD_GCR: VSUPPLY Mask                   */
#define LCD_GCR_VSUPPLY_SHIFT                    16                                                  /*!< LCD_GCR: VSUPPLY Position               */
#define LCD_GCR_VSUPPLY(x)                       (((uint32_t)(((uint32_t)(x))<<LCD_GCR_VSUPPLY_SHIFT))&LCD_GCR_VSUPPLY_MASK) /*!< LCD_GCR                                 */
#define LCD_GCR_LADJ_MASK                        (0x03UL << LCD_GCR_LADJ_SHIFT)                      /*!< LCD_GCR: LADJ Mask                      */
#define LCD_GCR_LADJ_SHIFT                       20                                                  /*!< LCD_GCR: LADJ Position                  */
#define LCD_GCR_LADJ(x)                          (((uint32_t)(((uint32_t)(x))<<LCD_GCR_LADJ_SHIFT))&LCD_GCR_LADJ_MASK) /*!< LCD_GCR                                 */
#define LCD_GCR_HREFSEL_MASK                     (0x01UL << LCD_GCR_HREFSEL_SHIFT)                   /*!< LCD_GCR: HREFSEL Mask                   */
#define LCD_GCR_HREFSEL_SHIFT                    22                                                  /*!< LCD_GCR: HREFSEL Position               */
#define LCD_GCR_HREFSEL(x)                       (((uint32_t)(((uint32_t)(x))<<LCD_GCR_HREFSEL_SHIFT))&LCD_GCR_HREFSEL_MASK) /*!< LCD_GCR                                 */
#define LCD_GCR_CPSEL_MASK                       (0x01UL << LCD_GCR_CPSEL_SHIFT)                     /*!< LCD_GCR: CPSEL Mask                     */
#define LCD_GCR_CPSEL_SHIFT                      23                                                  /*!< LCD_GCR: CPSEL Position                 */
#define LCD_GCR_CPSEL(x)                         (((uint32_t)(((uint32_t)(x))<<LCD_GCR_CPSEL_SHIFT))&LCD_GCR_CPSEL_MASK) /*!< LCD_GCR                                 */
#define LCD_GCR_RVTRIM_MASK                      (0x0FUL << LCD_GCR_RVTRIM_SHIFT)                    /*!< LCD_GCR: RVTRIM Mask                    */
#define LCD_GCR_RVTRIM_SHIFT                     24                                                  /*!< LCD_GCR: RVTRIM Position                */
#define LCD_GCR_RVTRIM(x)                        (((uint32_t)(((uint32_t)(x))<<LCD_GCR_RVTRIM_SHIFT))&LCD_GCR_RVTRIM_MASK) /*!< LCD_GCR                                 */
#define LCD_GCR_RVEN_MASK                        (0x01UL << LCD_GCR_RVEN_SHIFT)                      /*!< LCD_GCR: RVEN Mask                      */
#define LCD_GCR_RVEN_SHIFT                       31                                                  /*!< LCD_GCR: RVEN Position                  */
#define LCD_GCR_RVEN(x)                          (((uint32_t)(((uint32_t)(x))<<LCD_GCR_RVEN_SHIFT))&LCD_GCR_RVEN_MASK) /*!< LCD_GCR                                 */
/* ------- AR Bit Fields                            ------ */
#define LCD_AR_BRATE_MASK                        (0x07UL << LCD_AR_BRATE_SHIFT)                      /*!< LCD_AR: BRATE Mask                      */
#define LCD_AR_BRATE_SHIFT                       0                                                   /*!< LCD_AR: BRATE Position                  */
#define LCD_AR_BRATE(x)                          (((uint32_t)(((uint32_t)(x))<<LCD_AR_BRATE_SHIFT))&LCD_AR_BRATE_MASK) /*!< LCD_AR                                  */
#define LCD_AR_BMODE_MASK                        (0x01UL << LCD_AR_BMODE_SHIFT)                      /*!< LCD_AR: BMODE Mask                      */
#define LCD_AR_BMODE_SHIFT                       3                                                   /*!< LCD_AR: BMODE Position                  */
#define LCD_AR_BMODE(x)                          (((uint32_t)(((uint32_t)(x))<<LCD_AR_BMODE_SHIFT))&LCD_AR_BMODE_MASK) /*!< LCD_AR                                  */
#define LCD_AR_BLANK_MASK                        (0x01UL << LCD_AR_BLANK_SHIFT)                      /*!< LCD_AR: BLANK Mask                      */
#define LCD_AR_BLANK_SHIFT                       5                                                   /*!< LCD_AR: BLANK Position                  */
#define LCD_AR_BLANK(x)                          (((uint32_t)(((uint32_t)(x))<<LCD_AR_BLANK_SHIFT))&LCD_AR_BLANK_MASK) /*!< LCD_AR                                  */
#define LCD_AR_ALT_MASK                          (0x01UL << LCD_AR_ALT_SHIFT)                        /*!< LCD_AR: ALT Mask                        */
#define LCD_AR_ALT_SHIFT                         6                                                   /*!< LCD_AR: ALT Position                    */
#define LCD_AR_ALT(x)                            (((uint32_t)(((uint32_t)(x))<<LCD_AR_ALT_SHIFT))&LCD_AR_ALT_MASK) /*!< LCD_AR                                  */
#define LCD_AR_BLINK_MASK                        (0x01UL << LCD_AR_BLINK_SHIFT)                      /*!< LCD_AR: BLINK Mask                      */
#define LCD_AR_BLINK_SHIFT                       7                                                   /*!< LCD_AR: BLINK Position                  */
#define LCD_AR_BLINK(x)                          (((uint32_t)(((uint32_t)(x))<<LCD_AR_BLINK_SHIFT))&LCD_AR_BLINK_MASK) /*!< LCD_AR                                  */
#define LCD_AR_LCDIF_MASK                        (0x01UL << LCD_AR_LCDIF_SHIFT)                      /*!< LCD_AR: LCDIF Mask                      */
#define LCD_AR_LCDIF_SHIFT                       15                                                  /*!< LCD_AR: LCDIF Position                  */
#define LCD_AR_LCDIF(x)                          (((uint32_t)(((uint32_t)(x))<<LCD_AR_LCDIF_SHIFT))&LCD_AR_LCDIF_MASK) /*!< LCD_AR                                  */
/* ------- FDCR Bit Fields                          ------ */
#define LCD_FDCR_FDPINID_MASK                    (0x3FUL << LCD_FDCR_FDPINID_SHIFT)                  /*!< LCD_FDCR: FDPINID Mask                  */
#define LCD_FDCR_FDPINID_SHIFT                   0                                                   /*!< LCD_FDCR: FDPINID Position              */
#define LCD_FDCR_FDPINID(x)                      (((uint32_t)(((uint32_t)(x))<<LCD_FDCR_FDPINID_SHIFT))&LCD_FDCR_FDPINID_MASK) /*!< LCD_FDCR                                */
#define LCD_FDCR_FDBPEN_MASK                     (0x01UL << LCD_FDCR_FDBPEN_SHIFT)                   /*!< LCD_FDCR: FDBPEN Mask                   */
#define LCD_FDCR_FDBPEN_SHIFT                    6                                                   /*!< LCD_FDCR: FDBPEN Position               */
#define LCD_FDCR_FDBPEN(x)                       (((uint32_t)(((uint32_t)(x))<<LCD_FDCR_FDBPEN_SHIFT))&LCD_FDCR_FDBPEN_MASK) /*!< LCD_FDCR                                */
#define LCD_FDCR_FDEN_MASK                       (0x01UL << LCD_FDCR_FDEN_SHIFT)                     /*!< LCD_FDCR: FDEN Mask                     */
#define LCD_FDCR_FDEN_SHIFT                      7                                                   /*!< LCD_FDCR: FDEN Position                 */
#define LCD_FDCR_FDEN(x)                         (((uint32_t)(((uint32_t)(x))<<LCD_FDCR_FDEN_SHIFT))&LCD_FDCR_FDEN_MASK) /*!< LCD_FDCR                                */
#define LCD_FDCR_FDSWW_MASK                      (0x07UL << LCD_FDCR_FDSWW_SHIFT)                    /*!< LCD_FDCR: FDSWW Mask                    */
#define LCD_FDCR_FDSWW_SHIFT                     9                                                   /*!< LCD_FDCR: FDSWW Position                */
#define LCD_FDCR_FDSWW(x)                        (((uint32_t)(((uint32_t)(x))<<LCD_FDCR_FDSWW_SHIFT))&LCD_FDCR_FDSWW_MASK) /*!< LCD_FDCR                                */
#define LCD_FDCR_FDPRS_MASK                      (0x07UL << LCD_FDCR_FDPRS_SHIFT)                    /*!< LCD_FDCR: FDPRS Mask                    */
#define LCD_FDCR_FDPRS_SHIFT                     12                                                  /*!< LCD_FDCR: FDPRS Position                */
#define LCD_FDCR_FDPRS(x)                        (((uint32_t)(((uint32_t)(x))<<LCD_FDCR_FDPRS_SHIFT))&LCD_FDCR_FDPRS_MASK) /*!< LCD_FDCR                                */
/* ------- FDSR Bit Fields                          ------ */
#define LCD_FDSR_FDCNT_MASK                      (0xFFUL << LCD_FDSR_FDCNT_SHIFT)                    /*!< LCD_FDSR: FDCNT Mask                    */
#define LCD_FDSR_FDCNT_SHIFT                     0                                                   /*!< LCD_FDSR: FDCNT Position                */
#define LCD_FDSR_FDCNT(x)                        (((uint32_t)(((uint32_t)(x))<<LCD_FDSR_FDCNT_SHIFT))&LCD_FDSR_FDCNT_MASK) /*!< LCD_FDSR                                */
#define LCD_FDSR_FDCF_MASK                       (0x01UL << LCD_FDSR_FDCF_SHIFT)                     /*!< LCD_FDSR: FDCF Mask                     */
#define LCD_FDSR_FDCF_SHIFT                      15                                                  /*!< LCD_FDSR: FDCF Position                 */
#define LCD_FDSR_FDCF(x)                         (((uint32_t)(((uint32_t)(x))<<LCD_FDSR_FDCF_SHIFT))&LCD_FDSR_FDCF_MASK) /*!< LCD_FDSR                                */
/* ------- PEN Bit Fields                           ------ */
#define LCD_PEN_PEN_MASK                         (0xFFFFFFFFUL << LCD_PEN_PEN_SHIFT)                 /*!< LCD_PEN: PEN Mask                       */
#define LCD_PEN_PEN_SHIFT                        0                                                   /*!< LCD_PEN: PEN Position                   */
#define LCD_PEN_PEN(x)                           (((uint32_t)(((uint32_t)(x))<<LCD_PEN_PEN_SHIFT))&LCD_PEN_PEN_MASK) /*!< LCD_PEN                                 */
/* ------- BPEN Bit Fields                          ------ */
#define LCD_BPEN_BPEN_MASK                       (0xFFFFFFFFUL << LCD_BPEN_BPEN_SHIFT)               /*!< LCD_BPEN: BPEN Mask                     */
#define LCD_BPEN_BPEN_SHIFT                      0                                                   /*!< LCD_BPEN: BPEN Position                 */
#define LCD_BPEN_BPEN(x)                         (((uint32_t)(((uint32_t)(x))<<LCD_BPEN_BPEN_SHIFT))&LCD_BPEN_BPEN_MASK) /*!< LCD_BPEN                                */
/* ------- WF Bit Fields                            ------ */
#define LCD_WF_BPALCD0_MASK                      (0x01UL << LCD_WF_BPALCD0_SHIFT)                    /*!< LCD_WF: BPALCD0 Mask                    */
#define LCD_WF_BPALCD0_SHIFT                     0                                                   /*!< LCD_WF: BPALCD0 Position                */
#define LCD_WF_BPALCD0(x)                        (((uint8_t)(((uint8_t)(x))<<LCD_WF_BPALCD0_SHIFT))&LCD_WF_BPALCD0_MASK) /*!< LCD_WF                                  */
#define LCD_WF_BPBLCD0_MASK                      (0x01UL << LCD_WF_BPBLCD0_SHIFT)                    /*!< LCD_WF: BPBLCD0 Mask                    */
#define LCD_WF_BPBLCD0_SHIFT                     1                                                   /*!< LCD_WF: BPBLCD0 Position                */
#define LCD_WF_BPBLCD0(x)                        (((uint8_t)(((uint8_t)(x))<<LCD_WF_BPBLCD0_SHIFT))&LCD_WF_BPBLCD0_MASK) /*!< LCD_WF                                  */
#define LCD_WF_BPCLCD0_MASK                      (0x01UL << LCD_WF_BPCLCD0_SHIFT)                    /*!< LCD_WF: BPCLCD0 Mask                    */
#define LCD_WF_BPCLCD0_SHIFT                     2                                                   /*!< LCD_WF: BPCLCD0 Position                */
#define LCD_WF_BPCLCD0(x)                        (((uint8_t)(((uint8_t)(x))<<LCD_WF_BPCLCD0_SHIFT))&LCD_WF_BPCLCD0_MASK) /*!< LCD_WF                                  */
#define LCD_WF_BPDLCD0_MASK                      (0x01UL << LCD_WF_BPDLCD0_SHIFT)                    /*!< LCD_WF: BPDLCD0 Mask                    */
#define LCD_WF_BPDLCD0_SHIFT                     3                                                   /*!< LCD_WF: BPDLCD0 Position                */
#define LCD_WF_BPDLCD0(x)                        (((uint8_t)(((uint8_t)(x))<<LCD_WF_BPDLCD0_SHIFT))&LCD_WF_BPDLCD0_MASK) /*!< LCD_WF                                  */
#define LCD_WF_BPELCD0_MASK                      (0x01UL << LCD_WF_BPELCD0_SHIFT)                    /*!< LCD_WF: BPELCD0 Mask                    */
#define LCD_WF_BPELCD0_SHIFT                     4                                                   /*!< LCD_WF: BPELCD0 Position                */
#define LCD_WF_BPELCD0(x)                        (((uint8_t)(((uint8_t)(x))<<LCD_WF_BPELCD0_SHIFT))&LCD_WF_BPELCD0_MASK) /*!< LCD_WF                                  */
#define LCD_WF_BPFLCD0_MASK                      (0x01UL << LCD_WF_BPFLCD0_SHIFT)                    /*!< LCD_WF: BPFLCD0 Mask                    */
#define LCD_WF_BPFLCD0_SHIFT                     5                                                   /*!< LCD_WF: BPFLCD0 Position                */
#define LCD_WF_BPFLCD0(x)                        (((uint8_t)(((uint8_t)(x))<<LCD_WF_BPFLCD0_SHIFT))&LCD_WF_BPFLCD0_MASK) /*!< LCD_WF                                  */
#define LCD_WF_BPGLCD0_MASK                      (0x01UL << LCD_WF_BPGLCD0_SHIFT)                    /*!< LCD_WF: BPGLCD0 Mask                    */
#define LCD_WF_BPGLCD0_SHIFT                     6                                                   /*!< LCD_WF: BPGLCD0 Position                */
#define LCD_WF_BPGLCD0(x)                        (((uint8_t)(((uint8_t)(x))<<LCD_WF_BPGLCD0_SHIFT))&LCD_WF_BPGLCD0_MASK) /*!< LCD_WF                                  */
#define LCD_WF_BPHLCD0_MASK                      (0x01UL << LCD_WF_BPHLCD0_SHIFT)                    /*!< LCD_WF: BPHLCD0 Mask                    */
#define LCD_WF_BPHLCD0_SHIFT                     7                                                   /*!< LCD_WF: BPHLCD0 Position                */
#define LCD_WF_BPHLCD0(x)                        (((uint8_t)(((uint8_t)(x))<<LCD_WF_BPHLCD0_SHIFT))&LCD_WF_BPHLCD0_MASK) /*!< LCD_WF                                  */
/* ------- WF3TO0 Bit Fields                        ------ */
#define LCD_WF3TO0_WF0_MASK                      (0xFFUL << LCD_WF3TO0_WF0_SHIFT)                    /*!< LCD_WF3TO0: WF0 Mask                    */
#define LCD_WF3TO0_WF0_SHIFT                     0                                                   /*!< LCD_WF3TO0: WF0 Position                */
#define LCD_WF3TO0_WF0(x)                        (((uint32_t)(((uint32_t)(x))<<LCD_WF3TO0_WF0_SHIFT))&LCD_WF3TO0_WF0_MASK) /*!< LCD_WF3TO0                              */
#define LCD_WF3TO0_WF1_MASK                      (0xFFUL << LCD_WF3TO0_WF1_SHIFT)                    /*!< LCD_WF3TO0: WF1 Mask                    */
#define LCD_WF3TO0_WF1_SHIFT                     8                                                   /*!< LCD_WF3TO0: WF1 Position                */
#define LCD_WF3TO0_WF1(x)                        (((uint32_t)(((uint32_t)(x))<<LCD_WF3TO0_WF1_SHIFT))&LCD_WF3TO0_WF1_MASK) /*!< LCD_WF3TO0                              */
#define LCD_WF3TO0_WF2_MASK                      (0xFFUL << LCD_WF3TO0_WF2_SHIFT)                    /*!< LCD_WF3TO0: WF2 Mask                    */
#define LCD_WF3TO0_WF2_SHIFT                     16                                                  /*!< LCD_WF3TO0: WF2 Position                */
#define LCD_WF3TO0_WF2(x)                        (((uint32_t)(((uint32_t)(x))<<LCD_WF3TO0_WF2_SHIFT))&LCD_WF3TO0_WF2_MASK) /*!< LCD_WF3TO0                              */
#define LCD_WF3TO0_WF3_MASK                      (0xFFUL << LCD_WF3TO0_WF3_SHIFT)                    /*!< LCD_WF3TO0: WF3 Mask                    */
#define LCD_WF3TO0_WF3_SHIFT                     24                                                  /*!< LCD_WF3TO0: WF3 Position                */
#define LCD_WF3TO0_WF3(x)                        (((uint32_t)(((uint32_t)(x))<<LCD_WF3TO0_WF3_SHIFT))&LCD_WF3TO0_WF3_MASK) /*!< LCD_WF3TO0                              */
/* ------- WF7TO4 Bit Fields                        ------ */
#define LCD_WF7TO4_WF4_MASK                      (0xFFUL << LCD_WF7TO4_WF4_SHIFT)                    /*!< LCD_WF7TO4: WF4 Mask                    */
#define LCD_WF7TO4_WF4_SHIFT                     0                                                   /*!< LCD_WF7TO4: WF4 Position                */
#define LCD_WF7TO4_WF4(x)                        (((uint32_t)(((uint32_t)(x))<<LCD_WF7TO4_WF4_SHIFT))&LCD_WF7TO4_WF4_MASK) /*!< LCD_WF7TO4                              */
#define LCD_WF7TO4_WF5_MASK                      (0xFFUL << LCD_WF7TO4_WF5_SHIFT)                    /*!< LCD_WF7TO4: WF5 Mask                    */
#define LCD_WF7TO4_WF5_SHIFT                     8                                                   /*!< LCD_WF7TO4: WF5 Position                */
#define LCD_WF7TO4_WF5(x)                        (((uint32_t)(((uint32_t)(x))<<LCD_WF7TO4_WF5_SHIFT))&LCD_WF7TO4_WF5_MASK) /*!< LCD_WF7TO4                              */
#define LCD_WF7TO4_WF6_MASK                      (0xFFUL << LCD_WF7TO4_WF6_SHIFT)                    /*!< LCD_WF7TO4: WF6 Mask                    */
#define LCD_WF7TO4_WF6_SHIFT                     16                                                  /*!< LCD_WF7TO4: WF6 Position                */
#define LCD_WF7TO4_WF6(x)                        (((uint32_t)(((uint32_t)(x))<<LCD_WF7TO4_WF6_SHIFT))&LCD_WF7TO4_WF6_MASK) /*!< LCD_WF7TO4                              */
#define LCD_WF7TO4_WF7_MASK                      (0xFFUL << LCD_WF7TO4_WF7_SHIFT)                    /*!< LCD_WF7TO4: WF7 Mask                    */
#define LCD_WF7TO4_WF7_SHIFT                     24                                                  /*!< LCD_WF7TO4: WF7 Position                */
#define LCD_WF7TO4_WF7(x)                        (((uint32_t)(((uint32_t)(x))<<LCD_WF7TO4_WF7_SHIFT))&LCD_WF7TO4_WF7_MASK) /*!< LCD_WF7TO4                              */
/* ------- WF11TO8 Bit Fields                       ------ */
#define LCD_WF11TO8_WF8_MASK                     (0xFFUL << LCD_WF11TO8_WF8_SHIFT)                   /*!< LCD_WF11TO8: WF8 Mask                   */
#define LCD_WF11TO8_WF8_SHIFT                    0                                                   /*!< LCD_WF11TO8: WF8 Position               */
#define LCD_WF11TO8_WF8(x)                       (((uint32_t)(((uint32_t)(x))<<LCD_WF11TO8_WF8_SHIFT))&LCD_WF11TO8_WF8_MASK) /*!< LCD_WF11TO8                             */
#define LCD_WF11TO8_WF9_MASK                     (0xFFUL << LCD_WF11TO8_WF9_SHIFT)                   /*!< LCD_WF11TO8: WF9 Mask                   */
#define LCD_WF11TO8_WF9_SHIFT                    8                                                   /*!< LCD_WF11TO8: WF9 Position               */
#define LCD_WF11TO8_WF9(x)                       (((uint32_t)(((uint32_t)(x))<<LCD_WF11TO8_WF9_SHIFT))&LCD_WF11TO8_WF9_MASK) /*!< LCD_WF11TO8                             */
#define LCD_WF11TO8_WF10_MASK                    (0xFFUL << LCD_WF11TO8_WF10_SHIFT)                  /*!< LCD_WF11TO8: WF10 Mask                  */
#define LCD_WF11TO8_WF10_SHIFT                   16                                                  /*!< LCD_WF11TO8: WF10 Position              */
#define LCD_WF11TO8_WF10(x)                      (((uint32_t)(((uint32_t)(x))<<LCD_WF11TO8_WF10_SHIFT))&LCD_WF11TO8_WF10_MASK) /*!< LCD_WF11TO8                             */
#define LCD_WF11TO8_WF11_MASK                    (0xFFUL << LCD_WF11TO8_WF11_SHIFT)                  /*!< LCD_WF11TO8: WF11 Mask                  */
#define LCD_WF11TO8_WF11_SHIFT                   24                                                  /*!< LCD_WF11TO8: WF11 Position              */
#define LCD_WF11TO8_WF11(x)                      (((uint32_t)(((uint32_t)(x))<<LCD_WF11TO8_WF11_SHIFT))&LCD_WF11TO8_WF11_MASK) /*!< LCD_WF11TO8                             */
/* ------- WF15TO12 Bit Fields                      ------ */
#define LCD_WF15TO12_WF12_MASK                   (0xFFUL << LCD_WF15TO12_WF12_SHIFT)                 /*!< LCD_WF15TO12: WF12 Mask                 */
#define LCD_WF15TO12_WF12_SHIFT                  0                                                   /*!< LCD_WF15TO12: WF12 Position             */
#define LCD_WF15TO12_WF12(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF15TO12_WF12_SHIFT))&LCD_WF15TO12_WF12_MASK) /*!< LCD_WF15TO12                            */
#define LCD_WF15TO12_WF13_MASK                   (0xFFUL << LCD_WF15TO12_WF13_SHIFT)                 /*!< LCD_WF15TO12: WF13 Mask                 */
#define LCD_WF15TO12_WF13_SHIFT                  8                                                   /*!< LCD_WF15TO12: WF13 Position             */
#define LCD_WF15TO12_WF13(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF15TO12_WF13_SHIFT))&LCD_WF15TO12_WF13_MASK) /*!< LCD_WF15TO12                            */
#define LCD_WF15TO12_WF14_MASK                   (0xFFUL << LCD_WF15TO12_WF14_SHIFT)                 /*!< LCD_WF15TO12: WF14 Mask                 */
#define LCD_WF15TO12_WF14_SHIFT                  16                                                  /*!< LCD_WF15TO12: WF14 Position             */
#define LCD_WF15TO12_WF14(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF15TO12_WF14_SHIFT))&LCD_WF15TO12_WF14_MASK) /*!< LCD_WF15TO12                            */
#define LCD_WF15TO12_WF15_MASK                   (0xFFUL << LCD_WF15TO12_WF15_SHIFT)                 /*!< LCD_WF15TO12: WF15 Mask                 */
#define LCD_WF15TO12_WF15_SHIFT                  24                                                  /*!< LCD_WF15TO12: WF15 Position             */
#define LCD_WF15TO12_WF15(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF15TO12_WF15_SHIFT))&LCD_WF15TO12_WF15_MASK) /*!< LCD_WF15TO12                            */
/* ------- WF19TO16 Bit Fields                      ------ */
#define LCD_WF19TO16_WF16_MASK                   (0xFFUL << LCD_WF19TO16_WF16_SHIFT)                 /*!< LCD_WF19TO16: WF16 Mask                 */
#define LCD_WF19TO16_WF16_SHIFT                  0                                                   /*!< LCD_WF19TO16: WF16 Position             */
#define LCD_WF19TO16_WF16(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF19TO16_WF16_SHIFT))&LCD_WF19TO16_WF16_MASK) /*!< LCD_WF19TO16                            */
#define LCD_WF19TO16_WF17_MASK                   (0xFFUL << LCD_WF19TO16_WF17_SHIFT)                 /*!< LCD_WF19TO16: WF17 Mask                 */
#define LCD_WF19TO16_WF17_SHIFT                  8                                                   /*!< LCD_WF19TO16: WF17 Position             */
#define LCD_WF19TO16_WF17(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF19TO16_WF17_SHIFT))&LCD_WF19TO16_WF17_MASK) /*!< LCD_WF19TO16                            */
#define LCD_WF19TO16_WF18_MASK                   (0xFFUL << LCD_WF19TO16_WF18_SHIFT)                 /*!< LCD_WF19TO16: WF18 Mask                 */
#define LCD_WF19TO16_WF18_SHIFT                  16                                                  /*!< LCD_WF19TO16: WF18 Position             */
#define LCD_WF19TO16_WF18(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF19TO16_WF18_SHIFT))&LCD_WF19TO16_WF18_MASK) /*!< LCD_WF19TO16                            */
#define LCD_WF19TO16_WF19_MASK                   (0xFFUL << LCD_WF19TO16_WF19_SHIFT)                 /*!< LCD_WF19TO16: WF19 Mask                 */
#define LCD_WF19TO16_WF19_SHIFT                  24                                                  /*!< LCD_WF19TO16: WF19 Position             */
#define LCD_WF19TO16_WF19(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF19TO16_WF19_SHIFT))&LCD_WF19TO16_WF19_MASK) /*!< LCD_WF19TO16                            */
/* ------- WF23TO20 Bit Fields                      ------ */
#define LCD_WF23TO20_WF20_MASK                   (0xFFUL << LCD_WF23TO20_WF20_SHIFT)                 /*!< LCD_WF23TO20: WF20 Mask                 */
#define LCD_WF23TO20_WF20_SHIFT                  0                                                   /*!< LCD_WF23TO20: WF20 Position             */
#define LCD_WF23TO20_WF20(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF23TO20_WF20_SHIFT))&LCD_WF23TO20_WF20_MASK) /*!< LCD_WF23TO20                            */
#define LCD_WF23TO20_WF21_MASK                   (0xFFUL << LCD_WF23TO20_WF21_SHIFT)                 /*!< LCD_WF23TO20: WF21 Mask                 */
#define LCD_WF23TO20_WF21_SHIFT                  8                                                   /*!< LCD_WF23TO20: WF21 Position             */
#define LCD_WF23TO20_WF21(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF23TO20_WF21_SHIFT))&LCD_WF23TO20_WF21_MASK) /*!< LCD_WF23TO20                            */
#define LCD_WF23TO20_WF22_MASK                   (0xFFUL << LCD_WF23TO20_WF22_SHIFT)                 /*!< LCD_WF23TO20: WF22 Mask                 */
#define LCD_WF23TO20_WF22_SHIFT                  16                                                  /*!< LCD_WF23TO20: WF22 Position             */
#define LCD_WF23TO20_WF22(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF23TO20_WF22_SHIFT))&LCD_WF23TO20_WF22_MASK) /*!< LCD_WF23TO20                            */
#define LCD_WF23TO20_WF23_MASK                   (0xFFUL << LCD_WF23TO20_WF23_SHIFT)                 /*!< LCD_WF23TO20: WF23 Mask                 */
#define LCD_WF23TO20_WF23_SHIFT                  24                                                  /*!< LCD_WF23TO20: WF23 Position             */
#define LCD_WF23TO20_WF23(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF23TO20_WF23_SHIFT))&LCD_WF23TO20_WF23_MASK) /*!< LCD_WF23TO20                            */
/* ------- WF27TO24 Bit Fields                      ------ */
#define LCD_WF27TO24_WF24_MASK                   (0xFFUL << LCD_WF27TO24_WF24_SHIFT)                 /*!< LCD_WF27TO24: WF24 Mask                 */
#define LCD_WF27TO24_WF24_SHIFT                  0                                                   /*!< LCD_WF27TO24: WF24 Position             */
#define LCD_WF27TO24_WF24(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF27TO24_WF24_SHIFT))&LCD_WF27TO24_WF24_MASK) /*!< LCD_WF27TO24                            */
#define LCD_WF27TO24_WF25_MASK                   (0xFFUL << LCD_WF27TO24_WF25_SHIFT)                 /*!< LCD_WF27TO24: WF25 Mask                 */
#define LCD_WF27TO24_WF25_SHIFT                  8                                                   /*!< LCD_WF27TO24: WF25 Position             */
#define LCD_WF27TO24_WF25(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF27TO24_WF25_SHIFT))&LCD_WF27TO24_WF25_MASK) /*!< LCD_WF27TO24                            */
#define LCD_WF27TO24_WF26_MASK                   (0xFFUL << LCD_WF27TO24_WF26_SHIFT)                 /*!< LCD_WF27TO24: WF26 Mask                 */
#define LCD_WF27TO24_WF26_SHIFT                  16                                                  /*!< LCD_WF27TO24: WF26 Position             */
#define LCD_WF27TO24_WF26(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF27TO24_WF26_SHIFT))&LCD_WF27TO24_WF26_MASK) /*!< LCD_WF27TO24                            */
#define LCD_WF27TO24_WF27_MASK                   (0xFFUL << LCD_WF27TO24_WF27_SHIFT)                 /*!< LCD_WF27TO24: WF27 Mask                 */
#define LCD_WF27TO24_WF27_SHIFT                  24                                                  /*!< LCD_WF27TO24: WF27 Position             */
#define LCD_WF27TO24_WF27(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF27TO24_WF27_SHIFT))&LCD_WF27TO24_WF27_MASK) /*!< LCD_WF27TO24                            */
/* ------- WF31TO28 Bit Fields                      ------ */
#define LCD_WF31TO28_WF28_MASK                   (0xFFUL << LCD_WF31TO28_WF28_SHIFT)                 /*!< LCD_WF31TO28: WF28 Mask                 */
#define LCD_WF31TO28_WF28_SHIFT                  0                                                   /*!< LCD_WF31TO28: WF28 Position             */
#define LCD_WF31TO28_WF28(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF31TO28_WF28_SHIFT))&LCD_WF31TO28_WF28_MASK) /*!< LCD_WF31TO28                            */
#define LCD_WF31TO28_WF29_MASK                   (0xFFUL << LCD_WF31TO28_WF29_SHIFT)                 /*!< LCD_WF31TO28: WF29 Mask                 */
#define LCD_WF31TO28_WF29_SHIFT                  8                                                   /*!< LCD_WF31TO28: WF29 Position             */
#define LCD_WF31TO28_WF29(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF31TO28_WF29_SHIFT))&LCD_WF31TO28_WF29_MASK) /*!< LCD_WF31TO28                            */
#define LCD_WF31TO28_WF30_MASK                   (0xFFUL << LCD_WF31TO28_WF30_SHIFT)                 /*!< LCD_WF31TO28: WF30 Mask                 */
#define LCD_WF31TO28_WF30_SHIFT                  16                                                  /*!< LCD_WF31TO28: WF30 Position             */
#define LCD_WF31TO28_WF30(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF31TO28_WF30_SHIFT))&LCD_WF31TO28_WF30_MASK) /*!< LCD_WF31TO28                            */
#define LCD_WF31TO28_WF31_MASK                   (0xFFUL << LCD_WF31TO28_WF31_SHIFT)                 /*!< LCD_WF31TO28: WF31 Mask                 */
#define LCD_WF31TO28_WF31_SHIFT                  24                                                  /*!< LCD_WF31TO28: WF31 Position             */
#define LCD_WF31TO28_WF31(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF31TO28_WF31_SHIFT))&LCD_WF31TO28_WF31_MASK) /*!< LCD_WF31TO28                            */
/* ------- WF35TO32 Bit Fields                      ------ */
#define LCD_WF35TO32_WF32_MASK                   (0xFFUL << LCD_WF35TO32_WF32_SHIFT)                 /*!< LCD_WF35TO32: WF32 Mask                 */
#define LCD_WF35TO32_WF32_SHIFT                  0                                                   /*!< LCD_WF35TO32: WF32 Position             */
#define LCD_WF35TO32_WF32(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF35TO32_WF32_SHIFT))&LCD_WF35TO32_WF32_MASK) /*!< LCD_WF35TO32                            */
#define LCD_WF35TO32_WF33_MASK                   (0xFFUL << LCD_WF35TO32_WF33_SHIFT)                 /*!< LCD_WF35TO32: WF33 Mask                 */
#define LCD_WF35TO32_WF33_SHIFT                  8                                                   /*!< LCD_WF35TO32: WF33 Position             */
#define LCD_WF35TO32_WF33(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF35TO32_WF33_SHIFT))&LCD_WF35TO32_WF33_MASK) /*!< LCD_WF35TO32                            */
#define LCD_WF35TO32_WF34_MASK                   (0xFFUL << LCD_WF35TO32_WF34_SHIFT)                 /*!< LCD_WF35TO32: WF34 Mask                 */
#define LCD_WF35TO32_WF34_SHIFT                  16                                                  /*!< LCD_WF35TO32: WF34 Position             */
#define LCD_WF35TO32_WF34(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF35TO32_WF34_SHIFT))&LCD_WF35TO32_WF34_MASK) /*!< LCD_WF35TO32                            */
#define LCD_WF35TO32_WF35_MASK                   (0xFFUL << LCD_WF35TO32_WF35_SHIFT)                 /*!< LCD_WF35TO32: WF35 Mask                 */
#define LCD_WF35TO32_WF35_SHIFT                  24                                                  /*!< LCD_WF35TO32: WF35 Position             */
#define LCD_WF35TO32_WF35(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF35TO32_WF35_SHIFT))&LCD_WF35TO32_WF35_MASK) /*!< LCD_WF35TO32                            */
/* ------- WF39TO36 Bit Fields                      ------ */
#define LCD_WF39TO36_WF36_MASK                   (0xFFUL << LCD_WF39TO36_WF36_SHIFT)                 /*!< LCD_WF39TO36: WF36 Mask                 */
#define LCD_WF39TO36_WF36_SHIFT                  0                                                   /*!< LCD_WF39TO36: WF36 Position             */
#define LCD_WF39TO36_WF36(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF39TO36_WF36_SHIFT))&LCD_WF39TO36_WF36_MASK) /*!< LCD_WF39TO36                            */
#define LCD_WF39TO36_WF37_MASK                   (0xFFUL << LCD_WF39TO36_WF37_SHIFT)                 /*!< LCD_WF39TO36: WF37 Mask                 */
#define LCD_WF39TO36_WF37_SHIFT                  8                                                   /*!< LCD_WF39TO36: WF37 Position             */
#define LCD_WF39TO36_WF37(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF39TO36_WF37_SHIFT))&LCD_WF39TO36_WF37_MASK) /*!< LCD_WF39TO36                            */
#define LCD_WF39TO36_WF38_MASK                   (0xFFUL << LCD_WF39TO36_WF38_SHIFT)                 /*!< LCD_WF39TO36: WF38 Mask                 */
#define LCD_WF39TO36_WF38_SHIFT                  16                                                  /*!< LCD_WF39TO36: WF38 Position             */
#define LCD_WF39TO36_WF38(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF39TO36_WF38_SHIFT))&LCD_WF39TO36_WF38_MASK) /*!< LCD_WF39TO36                            */
#define LCD_WF39TO36_WF39_MASK                   (0xFFUL << LCD_WF39TO36_WF39_SHIFT)                 /*!< LCD_WF39TO36: WF39 Mask                 */
#define LCD_WF39TO36_WF39_SHIFT                  24                                                  /*!< LCD_WF39TO36: WF39 Position             */
#define LCD_WF39TO36_WF39(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF39TO36_WF39_SHIFT))&LCD_WF39TO36_WF39_MASK) /*!< LCD_WF39TO36                            */
/* ------- WF43TO40 Bit Fields                      ------ */
#define LCD_WF43TO40_WF40_MASK                   (0xFFUL << LCD_WF43TO40_WF40_SHIFT)                 /*!< LCD_WF43TO40: WF40 Mask                 */
#define LCD_WF43TO40_WF40_SHIFT                  0                                                   /*!< LCD_WF43TO40: WF40 Position             */
#define LCD_WF43TO40_WF40(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF43TO40_WF40_SHIFT))&LCD_WF43TO40_WF40_MASK) /*!< LCD_WF43TO40                            */
#define LCD_WF43TO40_WF41_MASK                   (0xFFUL << LCD_WF43TO40_WF41_SHIFT)                 /*!< LCD_WF43TO40: WF41 Mask                 */
#define LCD_WF43TO40_WF41_SHIFT                  8                                                   /*!< LCD_WF43TO40: WF41 Position             */
#define LCD_WF43TO40_WF41(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF43TO40_WF41_SHIFT))&LCD_WF43TO40_WF41_MASK) /*!< LCD_WF43TO40                            */
#define LCD_WF43TO40_WF42_MASK                   (0xFFUL << LCD_WF43TO40_WF42_SHIFT)                 /*!< LCD_WF43TO40: WF42 Mask                 */
#define LCD_WF43TO40_WF42_SHIFT                  16                                                  /*!< LCD_WF43TO40: WF42 Position             */
#define LCD_WF43TO40_WF42(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF43TO40_WF42_SHIFT))&LCD_WF43TO40_WF42_MASK) /*!< LCD_WF43TO40                            */
#define LCD_WF43TO40_WF43_MASK                   (0xFFUL << LCD_WF43TO40_WF43_SHIFT)                 /*!< LCD_WF43TO40: WF43 Mask                 */
#define LCD_WF43TO40_WF43_SHIFT                  24                                                  /*!< LCD_WF43TO40: WF43 Position             */
#define LCD_WF43TO40_WF43(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF43TO40_WF43_SHIFT))&LCD_WF43TO40_WF43_MASK) /*!< LCD_WF43TO40                            */
/* ------- WF47TO44 Bit Fields                      ------ */
#define LCD_WF47TO44_WF44_MASK                   (0xFFUL << LCD_WF47TO44_WF44_SHIFT)                 /*!< LCD_WF47TO44: WF44 Mask                 */
#define LCD_WF47TO44_WF44_SHIFT                  0                                                   /*!< LCD_WF47TO44: WF44 Position             */
#define LCD_WF47TO44_WF44(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF47TO44_WF44_SHIFT))&LCD_WF47TO44_WF44_MASK) /*!< LCD_WF47TO44                            */
#define LCD_WF47TO44_WF45_MASK                   (0xFFUL << LCD_WF47TO44_WF45_SHIFT)                 /*!< LCD_WF47TO44: WF45 Mask                 */
#define LCD_WF47TO44_WF45_SHIFT                  8                                                   /*!< LCD_WF47TO44: WF45 Position             */
#define LCD_WF47TO44_WF45(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF47TO44_WF45_SHIFT))&LCD_WF47TO44_WF45_MASK) /*!< LCD_WF47TO44                            */
#define LCD_WF47TO44_WF46_MASK                   (0xFFUL << LCD_WF47TO44_WF46_SHIFT)                 /*!< LCD_WF47TO44: WF46 Mask                 */
#define LCD_WF47TO44_WF46_SHIFT                  16                                                  /*!< LCD_WF47TO44: WF46 Position             */
#define LCD_WF47TO44_WF46(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF47TO44_WF46_SHIFT))&LCD_WF47TO44_WF46_MASK) /*!< LCD_WF47TO44                            */
#define LCD_WF47TO44_WF47_MASK                   (0xFFUL << LCD_WF47TO44_WF47_SHIFT)                 /*!< LCD_WF47TO44: WF47 Mask                 */
#define LCD_WF47TO44_WF47_SHIFT                  24                                                  /*!< LCD_WF47TO44: WF47 Position             */
#define LCD_WF47TO44_WF47(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF47TO44_WF47_SHIFT))&LCD_WF47TO44_WF47_MASK) /*!< LCD_WF47TO44                            */
/* ------- WF51TO48 Bit Fields                      ------ */
#define LCD_WF51TO48_WF48_MASK                   (0xFFUL << LCD_WF51TO48_WF48_SHIFT)                 /*!< LCD_WF51TO48: WF48 Mask                 */
#define LCD_WF51TO48_WF48_SHIFT                  0                                                   /*!< LCD_WF51TO48: WF48 Position             */
#define LCD_WF51TO48_WF48(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF51TO48_WF48_SHIFT))&LCD_WF51TO48_WF48_MASK) /*!< LCD_WF51TO48                            */
#define LCD_WF51TO48_WF49_MASK                   (0xFFUL << LCD_WF51TO48_WF49_SHIFT)                 /*!< LCD_WF51TO48: WF49 Mask                 */
#define LCD_WF51TO48_WF49_SHIFT                  8                                                   /*!< LCD_WF51TO48: WF49 Position             */
#define LCD_WF51TO48_WF49(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF51TO48_WF49_SHIFT))&LCD_WF51TO48_WF49_MASK) /*!< LCD_WF51TO48                            */
#define LCD_WF51TO48_WF50_MASK                   (0xFFUL << LCD_WF51TO48_WF50_SHIFT)                 /*!< LCD_WF51TO48: WF50 Mask                 */
#define LCD_WF51TO48_WF50_SHIFT                  16                                                  /*!< LCD_WF51TO48: WF50 Position             */
#define LCD_WF51TO48_WF50(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF51TO48_WF50_SHIFT))&LCD_WF51TO48_WF50_MASK) /*!< LCD_WF51TO48                            */
#define LCD_WF51TO48_WF51_MASK                   (0xFFUL << LCD_WF51TO48_WF51_SHIFT)                 /*!< LCD_WF51TO48: WF51 Mask                 */
#define LCD_WF51TO48_WF51_SHIFT                  24                                                  /*!< LCD_WF51TO48: WF51 Position             */
#define LCD_WF51TO48_WF51(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF51TO48_WF51_SHIFT))&LCD_WF51TO48_WF51_MASK) /*!< LCD_WF51TO48                            */
/* ------- WF55TO52 Bit Fields                      ------ */
#define LCD_WF55TO52_WF52_MASK                   (0xFFUL << LCD_WF55TO52_WF52_SHIFT)                 /*!< LCD_WF55TO52: WF52 Mask                 */
#define LCD_WF55TO52_WF52_SHIFT                  0                                                   /*!< LCD_WF55TO52: WF52 Position             */
#define LCD_WF55TO52_WF52(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF55TO52_WF52_SHIFT))&LCD_WF55TO52_WF52_MASK) /*!< LCD_WF55TO52                            */
#define LCD_WF55TO52_WF53_MASK                   (0xFFUL << LCD_WF55TO52_WF53_SHIFT)                 /*!< LCD_WF55TO52: WF53 Mask                 */
#define LCD_WF55TO52_WF53_SHIFT                  8                                                   /*!< LCD_WF55TO52: WF53 Position             */
#define LCD_WF55TO52_WF53(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF55TO52_WF53_SHIFT))&LCD_WF55TO52_WF53_MASK) /*!< LCD_WF55TO52                            */
#define LCD_WF55TO52_WF54_MASK                   (0xFFUL << LCD_WF55TO52_WF54_SHIFT)                 /*!< LCD_WF55TO52: WF54 Mask                 */
#define LCD_WF55TO52_WF54_SHIFT                  16                                                  /*!< LCD_WF55TO52: WF54 Position             */
#define LCD_WF55TO52_WF54(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF55TO52_WF54_SHIFT))&LCD_WF55TO52_WF54_MASK) /*!< LCD_WF55TO52                            */
#define LCD_WF55TO52_WF55_MASK                   (0xFFUL << LCD_WF55TO52_WF55_SHIFT)                 /*!< LCD_WF55TO52: WF55 Mask                 */
#define LCD_WF55TO52_WF55_SHIFT                  24                                                  /*!< LCD_WF55TO52: WF55 Position             */
#define LCD_WF55TO52_WF55(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF55TO52_WF55_SHIFT))&LCD_WF55TO52_WF55_MASK) /*!< LCD_WF55TO52                            */
/* ------- WF59TO56 Bit Fields                      ------ */
#define LCD_WF59TO56_WF56_MASK                   (0xFFUL << LCD_WF59TO56_WF56_SHIFT)                 /*!< LCD_WF59TO56: WF56 Mask                 */
#define LCD_WF59TO56_WF56_SHIFT                  0                                                   /*!< LCD_WF59TO56: WF56 Position             */
#define LCD_WF59TO56_WF56(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF59TO56_WF56_SHIFT))&LCD_WF59TO56_WF56_MASK) /*!< LCD_WF59TO56                            */
#define LCD_WF59TO56_WF57_MASK                   (0xFFUL << LCD_WF59TO56_WF57_SHIFT)                 /*!< LCD_WF59TO56: WF57 Mask                 */
#define LCD_WF59TO56_WF57_SHIFT                  8                                                   /*!< LCD_WF59TO56: WF57 Position             */
#define LCD_WF59TO56_WF57(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF59TO56_WF57_SHIFT))&LCD_WF59TO56_WF57_MASK) /*!< LCD_WF59TO56                            */
#define LCD_WF59TO56_WF58_MASK                   (0xFFUL << LCD_WF59TO56_WF58_SHIFT)                 /*!< LCD_WF59TO56: WF58 Mask                 */
#define LCD_WF59TO56_WF58_SHIFT                  16                                                  /*!< LCD_WF59TO56: WF58 Position             */
#define LCD_WF59TO56_WF58(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF59TO56_WF58_SHIFT))&LCD_WF59TO56_WF58_MASK) /*!< LCD_WF59TO56                            */
#define LCD_WF59TO56_WF59_MASK                   (0xFFUL << LCD_WF59TO56_WF59_SHIFT)                 /*!< LCD_WF59TO56: WF59 Mask                 */
#define LCD_WF59TO56_WF59_SHIFT                  24                                                  /*!< LCD_WF59TO56: WF59 Position             */
#define LCD_WF59TO56_WF59(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF59TO56_WF59_SHIFT))&LCD_WF59TO56_WF59_MASK) /*!< LCD_WF59TO56                            */
/* ------- WF63TO60 Bit Fields                      ------ */
#define LCD_WF63TO60_WF60_MASK                   (0xFFUL << LCD_WF63TO60_WF60_SHIFT)                 /*!< LCD_WF63TO60: WF60 Mask                 */
#define LCD_WF63TO60_WF60_SHIFT                  0                                                   /*!< LCD_WF63TO60: WF60 Position             */
#define LCD_WF63TO60_WF60(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF63TO60_WF60_SHIFT))&LCD_WF63TO60_WF60_MASK) /*!< LCD_WF63TO60                            */
#define LCD_WF63TO60_WF61_MASK                   (0xFFUL << LCD_WF63TO60_WF61_SHIFT)                 /*!< LCD_WF63TO60: WF61 Mask                 */
#define LCD_WF63TO60_WF61_SHIFT                  8                                                   /*!< LCD_WF63TO60: WF61 Position             */
#define LCD_WF63TO60_WF61(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF63TO60_WF61_SHIFT))&LCD_WF63TO60_WF61_MASK) /*!< LCD_WF63TO60                            */
#define LCD_WF63TO60_WF62_MASK                   (0xFFUL << LCD_WF63TO60_WF62_SHIFT)                 /*!< LCD_WF63TO60: WF62 Mask                 */
#define LCD_WF63TO60_WF62_SHIFT                  16                                                  /*!< LCD_WF63TO60: WF62 Position             */
#define LCD_WF63TO60_WF62(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF63TO60_WF62_SHIFT))&LCD_WF63TO60_WF62_MASK) /*!< LCD_WF63TO60                            */
#define LCD_WF63TO60_WF63_MASK                   (0xFFUL << LCD_WF63TO60_WF63_SHIFT)                 /*!< LCD_WF63TO60: WF63 Mask                 */
#define LCD_WF63TO60_WF63_SHIFT                  24                                                  /*!< LCD_WF63TO60: WF63 Position             */
#define LCD_WF63TO60_WF63(x)                     (((uint32_t)(((uint32_t)(x))<<LCD_WF63TO60_WF63_SHIFT))&LCD_WF63TO60_WF63_MASK) /*!< LCD_WF63TO60                            */
/**
 * @} */ /* End group LCD_Register_Masks_GROUP 
 */

/* LCD - Peripheral instance base addresses */
#define LCD_BasePtr                    0x400BE000UL //!< Peripheral base address
#define LCD                            ((LCD_Type *) LCD_BasePtr) //!< Freescale base pointer
#define LCD_BASE_PTR                   (LCD) //!< Freescale style base pointer
/**
 * @} */ /* End group LCD_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LLWU_Peripheral_access_layer_GROUP LLWU Peripheral Access Layer
* @brief C Struct for LLWU
* @{
*/

/* ================================================================================ */
/* ================           LLWU (file:LLWU_PE3_FILT2_RST)       ================ */
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
   __IO uint8_t   PE1;                          /**< 0000: Pin Enable 1 Register                                        */
   __IO uint8_t   PE2;                          /**< 0001: Pin Enable 2 Register                                        */
   __IO uint8_t   PE3;                          /**< 0002: Pin Enable 3 Register                                        */
   __IO uint8_t   PE4;                          /**< 0003: Pin Enable 4 Register                                        */
   __IO uint8_t   ME;                           /**< 0004: Module Enable Register                                       */
   __IO uint8_t   F1;                           /**< 0005: Flag 1 Register                                              */
   __IO uint8_t   F2;                           /**< 0006: Flag 2 Register                                              */
   union {                                      /**< 0000: (size=0001)                                                  */
      __IO uint8_t   F3;                        /**< 0007: Flag 3 Register                                              */
      __I  uint8_t   MF0;                       /**< 0007: Module Flag 0 Register                                       */
   };
   __IO uint8_t   FILT1;                        /**< 0008: Pin Filter 1 register                                        */
   __IO uint8_t   FILT2;                        /**< 0009: Pin Filter 2 register                                        */
   __IO uint8_t   RST;                          /**< 000A: Reset Enable Register                                        */
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
#define LLWU_PE1_WUPE0_MASK                      (0x03UL << LLWU_PE1_WUPE0_SHIFT)                    /*!< LLWU_PE1: WUPE0 Mask                    */
#define LLWU_PE1_WUPE0_SHIFT                     0                                                   /*!< LLWU_PE1: WUPE0 Position                */
#define LLWU_PE1_WUPE0(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE0_SHIFT))&LLWU_PE1_WUPE0_MASK) /*!< LLWU_PE1                                */
#define LLWU_PE1_WUPE1_MASK                      (0x03UL << LLWU_PE1_WUPE1_SHIFT)                    /*!< LLWU_PE1: WUPE1 Mask                    */
#define LLWU_PE1_WUPE1_SHIFT                     2                                                   /*!< LLWU_PE1: WUPE1 Position                */
#define LLWU_PE1_WUPE1(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE1_SHIFT))&LLWU_PE1_WUPE1_MASK) /*!< LLWU_PE1                                */
#define LLWU_PE1_WUPE2_MASK                      (0x03UL << LLWU_PE1_WUPE2_SHIFT)                    /*!< LLWU_PE1: WUPE2 Mask                    */
#define LLWU_PE1_WUPE2_SHIFT                     4                                                   /*!< LLWU_PE1: WUPE2 Position                */
#define LLWU_PE1_WUPE2(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE2_SHIFT))&LLWU_PE1_WUPE2_MASK) /*!< LLWU_PE1                                */
#define LLWU_PE1_WUPE3_MASK                      (0x03UL << LLWU_PE1_WUPE3_SHIFT)                    /*!< LLWU_PE1: WUPE3 Mask                    */
#define LLWU_PE1_WUPE3_SHIFT                     6                                                   /*!< LLWU_PE1: WUPE3 Position                */
#define LLWU_PE1_WUPE3(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE1_WUPE3_SHIFT))&LLWU_PE1_WUPE3_MASK) /*!< LLWU_PE1                                */
/* ------- PE2 Bit Fields                           ------ */
#define LLWU_PE2_WUPE4_MASK                      (0x03UL << LLWU_PE2_WUPE4_SHIFT)                    /*!< LLWU_PE2: WUPE4 Mask                    */
#define LLWU_PE2_WUPE4_SHIFT                     0                                                   /*!< LLWU_PE2: WUPE4 Position                */
#define LLWU_PE2_WUPE4(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE4_SHIFT))&LLWU_PE2_WUPE4_MASK) /*!< LLWU_PE2                                */
#define LLWU_PE2_WUPE5_MASK                      (0x03UL << LLWU_PE2_WUPE5_SHIFT)                    /*!< LLWU_PE2: WUPE5 Mask                    */
#define LLWU_PE2_WUPE5_SHIFT                     2                                                   /*!< LLWU_PE2: WUPE5 Position                */
#define LLWU_PE2_WUPE5(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE5_SHIFT))&LLWU_PE2_WUPE5_MASK) /*!< LLWU_PE2                                */
#define LLWU_PE2_WUPE6_MASK                      (0x03UL << LLWU_PE2_WUPE6_SHIFT)                    /*!< LLWU_PE2: WUPE6 Mask                    */
#define LLWU_PE2_WUPE6_SHIFT                     4                                                   /*!< LLWU_PE2: WUPE6 Position                */
#define LLWU_PE2_WUPE6(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE6_SHIFT))&LLWU_PE2_WUPE6_MASK) /*!< LLWU_PE2                                */
#define LLWU_PE2_WUPE7_MASK                      (0x03UL << LLWU_PE2_WUPE7_SHIFT)                    /*!< LLWU_PE2: WUPE7 Mask                    */
#define LLWU_PE2_WUPE7_SHIFT                     6                                                   /*!< LLWU_PE2: WUPE7 Position                */
#define LLWU_PE2_WUPE7(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE2_WUPE7_SHIFT))&LLWU_PE2_WUPE7_MASK) /*!< LLWU_PE2                                */
/* ------- PE3 Bit Fields                           ------ */
#define LLWU_PE3_WUPE8_MASK                      (0x03UL << LLWU_PE3_WUPE8_SHIFT)                    /*!< LLWU_PE3: WUPE8 Mask                    */
#define LLWU_PE3_WUPE8_SHIFT                     0                                                   /*!< LLWU_PE3: WUPE8 Position                */
#define LLWU_PE3_WUPE8(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE8_SHIFT))&LLWU_PE3_WUPE8_MASK) /*!< LLWU_PE3                                */
#define LLWU_PE3_WUPE9_MASK                      (0x03UL << LLWU_PE3_WUPE9_SHIFT)                    /*!< LLWU_PE3: WUPE9 Mask                    */
#define LLWU_PE3_WUPE9_SHIFT                     2                                                   /*!< LLWU_PE3: WUPE9 Position                */
#define LLWU_PE3_WUPE9(x)                        (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE9_SHIFT))&LLWU_PE3_WUPE9_MASK) /*!< LLWU_PE3                                */
#define LLWU_PE3_WUPE10_MASK                     (0x03UL << LLWU_PE3_WUPE10_SHIFT)                   /*!< LLWU_PE3: WUPE10 Mask                   */
#define LLWU_PE3_WUPE10_SHIFT                    4                                                   /*!< LLWU_PE3: WUPE10 Position               */
#define LLWU_PE3_WUPE10(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE10_SHIFT))&LLWU_PE3_WUPE10_MASK) /*!< LLWU_PE3                                */
#define LLWU_PE3_WUPE11_MASK                     (0x03UL << LLWU_PE3_WUPE11_SHIFT)                   /*!< LLWU_PE3: WUPE11 Mask                   */
#define LLWU_PE3_WUPE11_SHIFT                    6                                                   /*!< LLWU_PE3: WUPE11 Position               */
#define LLWU_PE3_WUPE11(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE3_WUPE11_SHIFT))&LLWU_PE3_WUPE11_MASK) /*!< LLWU_PE3                                */
/* ------- PE4 Bit Fields                           ------ */
#define LLWU_PE4_WUPE12_MASK                     (0x03UL << LLWU_PE4_WUPE12_SHIFT)                   /*!< LLWU_PE4: WUPE12 Mask                   */
#define LLWU_PE4_WUPE12_SHIFT                    0                                                   /*!< LLWU_PE4: WUPE12 Position               */
#define LLWU_PE4_WUPE12(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE12_SHIFT))&LLWU_PE4_WUPE12_MASK) /*!< LLWU_PE4                                */
#define LLWU_PE4_WUPE13_MASK                     (0x03UL << LLWU_PE4_WUPE13_SHIFT)                   /*!< LLWU_PE4: WUPE13 Mask                   */
#define LLWU_PE4_WUPE13_SHIFT                    2                                                   /*!< LLWU_PE4: WUPE13 Position               */
#define LLWU_PE4_WUPE13(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE13_SHIFT))&LLWU_PE4_WUPE13_MASK) /*!< LLWU_PE4                                */
#define LLWU_PE4_WUPE14_MASK                     (0x03UL << LLWU_PE4_WUPE14_SHIFT)                   /*!< LLWU_PE4: WUPE14 Mask                   */
#define LLWU_PE4_WUPE14_SHIFT                    4                                                   /*!< LLWU_PE4: WUPE14 Position               */
#define LLWU_PE4_WUPE14(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE14_SHIFT))&LLWU_PE4_WUPE14_MASK) /*!< LLWU_PE4                                */
#define LLWU_PE4_WUPE15_MASK                     (0x03UL << LLWU_PE4_WUPE15_SHIFT)                   /*!< LLWU_PE4: WUPE15 Mask                   */
#define LLWU_PE4_WUPE15_SHIFT                    6                                                   /*!< LLWU_PE4: WUPE15 Position               */
#define LLWU_PE4_WUPE15(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_PE4_WUPE15_SHIFT))&LLWU_PE4_WUPE15_MASK) /*!< LLWU_PE4                                */
/* ------- ME Bit Fields                            ------ */
#define LLWU_ME_WUME0_MASK                       (0x01UL << LLWU_ME_WUME0_SHIFT)                     /*!< LLWU_ME: WUME0 Mask                     */
#define LLWU_ME_WUME0_SHIFT                      0                                                   /*!< LLWU_ME: WUME0 Position                 */
#define LLWU_ME_WUME0(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME0_SHIFT))&LLWU_ME_WUME0_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME1_MASK                       (0x01UL << LLWU_ME_WUME1_SHIFT)                     /*!< LLWU_ME: WUME1 Mask                     */
#define LLWU_ME_WUME1_SHIFT                      1                                                   /*!< LLWU_ME: WUME1 Position                 */
#define LLWU_ME_WUME1(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME1_SHIFT))&LLWU_ME_WUME1_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME2_MASK                       (0x01UL << LLWU_ME_WUME2_SHIFT)                     /*!< LLWU_ME: WUME2 Mask                     */
#define LLWU_ME_WUME2_SHIFT                      2                                                   /*!< LLWU_ME: WUME2 Position                 */
#define LLWU_ME_WUME2(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME2_SHIFT))&LLWU_ME_WUME2_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME3_MASK                       (0x01UL << LLWU_ME_WUME3_SHIFT)                     /*!< LLWU_ME: WUME3 Mask                     */
#define LLWU_ME_WUME3_SHIFT                      3                                                   /*!< LLWU_ME: WUME3 Position                 */
#define LLWU_ME_WUME3(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME3_SHIFT))&LLWU_ME_WUME3_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME4_MASK                       (0x01UL << LLWU_ME_WUME4_SHIFT)                     /*!< LLWU_ME: WUME4 Mask                     */
#define LLWU_ME_WUME4_SHIFT                      4                                                   /*!< LLWU_ME: WUME4 Position                 */
#define LLWU_ME_WUME4(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME4_SHIFT))&LLWU_ME_WUME4_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME5_MASK                       (0x01UL << LLWU_ME_WUME5_SHIFT)                     /*!< LLWU_ME: WUME5 Mask                     */
#define LLWU_ME_WUME5_SHIFT                      5                                                   /*!< LLWU_ME: WUME5 Position                 */
#define LLWU_ME_WUME5(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME5_SHIFT))&LLWU_ME_WUME5_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME6_MASK                       (0x01UL << LLWU_ME_WUME6_SHIFT)                     /*!< LLWU_ME: WUME6 Mask                     */
#define LLWU_ME_WUME6_SHIFT                      6                                                   /*!< LLWU_ME: WUME6 Position                 */
#define LLWU_ME_WUME6(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME6_SHIFT))&LLWU_ME_WUME6_MASK) /*!< LLWU_ME                                 */
#define LLWU_ME_WUME7_MASK                       (0x01UL << LLWU_ME_WUME7_SHIFT)                     /*!< LLWU_ME: WUME7 Mask                     */
#define LLWU_ME_WUME7_SHIFT                      7                                                   /*!< LLWU_ME: WUME7 Position                 */
#define LLWU_ME_WUME7(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_ME_WUME7_SHIFT))&LLWU_ME_WUME7_MASK) /*!< LLWU_ME                                 */
/* ------- F1 Bit Fields                            ------ */
#define LLWU_F1_WUF0_MASK                        (0x01UL << LLWU_F1_WUF0_SHIFT)                      /*!< LLWU_F1: WUF0 Mask                      */
#define LLWU_F1_WUF0_SHIFT                       0                                                   /*!< LLWU_F1: WUF0 Position                  */
#define LLWU_F1_WUF0(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF0_SHIFT))&LLWU_F1_WUF0_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF1_MASK                        (0x01UL << LLWU_F1_WUF1_SHIFT)                      /*!< LLWU_F1: WUF1 Mask                      */
#define LLWU_F1_WUF1_SHIFT                       1                                                   /*!< LLWU_F1: WUF1 Position                  */
#define LLWU_F1_WUF1(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF1_SHIFT))&LLWU_F1_WUF1_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF2_MASK                        (0x01UL << LLWU_F1_WUF2_SHIFT)                      /*!< LLWU_F1: WUF2 Mask                      */
#define LLWU_F1_WUF2_SHIFT                       2                                                   /*!< LLWU_F1: WUF2 Position                  */
#define LLWU_F1_WUF2(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF2_SHIFT))&LLWU_F1_WUF2_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF3_MASK                        (0x01UL << LLWU_F1_WUF3_SHIFT)                      /*!< LLWU_F1: WUF3 Mask                      */
#define LLWU_F1_WUF3_SHIFT                       3                                                   /*!< LLWU_F1: WUF3 Position                  */
#define LLWU_F1_WUF3(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF3_SHIFT))&LLWU_F1_WUF3_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF4_MASK                        (0x01UL << LLWU_F1_WUF4_SHIFT)                      /*!< LLWU_F1: WUF4 Mask                      */
#define LLWU_F1_WUF4_SHIFT                       4                                                   /*!< LLWU_F1: WUF4 Position                  */
#define LLWU_F1_WUF4(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF4_SHIFT))&LLWU_F1_WUF4_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF5_MASK                        (0x01UL << LLWU_F1_WUF5_SHIFT)                      /*!< LLWU_F1: WUF5 Mask                      */
#define LLWU_F1_WUF5_SHIFT                       5                                                   /*!< LLWU_F1: WUF5 Position                  */
#define LLWU_F1_WUF5(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF5_SHIFT))&LLWU_F1_WUF5_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF6_MASK                        (0x01UL << LLWU_F1_WUF6_SHIFT)                      /*!< LLWU_F1: WUF6 Mask                      */
#define LLWU_F1_WUF6_SHIFT                       6                                                   /*!< LLWU_F1: WUF6 Position                  */
#define LLWU_F1_WUF6(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF6_SHIFT))&LLWU_F1_WUF6_MASK) /*!< LLWU_F1                                 */
#define LLWU_F1_WUF7_MASK                        (0x01UL << LLWU_F1_WUF7_SHIFT)                      /*!< LLWU_F1: WUF7 Mask                      */
#define LLWU_F1_WUF7_SHIFT                       7                                                   /*!< LLWU_F1: WUF7 Position                  */
#define LLWU_F1_WUF7(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F1_WUF7_SHIFT))&LLWU_F1_WUF7_MASK) /*!< LLWU_F1                                 */
/* ------- F2 Bit Fields                            ------ */
#define LLWU_F2_WUF8_MASK                        (0x01UL << LLWU_F2_WUF8_SHIFT)                      /*!< LLWU_F2: WUF8 Mask                      */
#define LLWU_F2_WUF8_SHIFT                       0                                                   /*!< LLWU_F2: WUF8 Position                  */
#define LLWU_F2_WUF8(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF8_SHIFT))&LLWU_F2_WUF8_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF9_MASK                        (0x01UL << LLWU_F2_WUF9_SHIFT)                      /*!< LLWU_F2: WUF9 Mask                      */
#define LLWU_F2_WUF9_SHIFT                       1                                                   /*!< LLWU_F2: WUF9 Position                  */
#define LLWU_F2_WUF9(x)                          (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF9_SHIFT))&LLWU_F2_WUF9_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF10_MASK                       (0x01UL << LLWU_F2_WUF10_SHIFT)                     /*!< LLWU_F2: WUF10 Mask                     */
#define LLWU_F2_WUF10_SHIFT                      2                                                   /*!< LLWU_F2: WUF10 Position                 */
#define LLWU_F2_WUF10(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF10_SHIFT))&LLWU_F2_WUF10_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF11_MASK                       (0x01UL << LLWU_F2_WUF11_SHIFT)                     /*!< LLWU_F2: WUF11 Mask                     */
#define LLWU_F2_WUF11_SHIFT                      3                                                   /*!< LLWU_F2: WUF11 Position                 */
#define LLWU_F2_WUF11(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF11_SHIFT))&LLWU_F2_WUF11_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF12_MASK                       (0x01UL << LLWU_F2_WUF12_SHIFT)                     /*!< LLWU_F2: WUF12 Mask                     */
#define LLWU_F2_WUF12_SHIFT                      4                                                   /*!< LLWU_F2: WUF12 Position                 */
#define LLWU_F2_WUF12(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF12_SHIFT))&LLWU_F2_WUF12_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF13_MASK                       (0x01UL << LLWU_F2_WUF13_SHIFT)                     /*!< LLWU_F2: WUF13 Mask                     */
#define LLWU_F2_WUF13_SHIFT                      5                                                   /*!< LLWU_F2: WUF13 Position                 */
#define LLWU_F2_WUF13(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF13_SHIFT))&LLWU_F2_WUF13_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF14_MASK                       (0x01UL << LLWU_F2_WUF14_SHIFT)                     /*!< LLWU_F2: WUF14 Mask                     */
#define LLWU_F2_WUF14_SHIFT                      6                                                   /*!< LLWU_F2: WUF14 Position                 */
#define LLWU_F2_WUF14(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF14_SHIFT))&LLWU_F2_WUF14_MASK) /*!< LLWU_F2                                 */
#define LLWU_F2_WUF15_MASK                       (0x01UL << LLWU_F2_WUF15_SHIFT)                     /*!< LLWU_F2: WUF15 Mask                     */
#define LLWU_F2_WUF15_SHIFT                      7                                                   /*!< LLWU_F2: WUF15 Position                 */
#define LLWU_F2_WUF15(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F2_WUF15_SHIFT))&LLWU_F2_WUF15_MASK) /*!< LLWU_F2                                 */
/* ------- F3 Bit Fields                            ------ */
#define LLWU_F3_MWUF0_MASK                       (0x01UL << LLWU_F3_MWUF0_SHIFT)                     /*!< LLWU_F3: MWUF0 Mask                     */
#define LLWU_F3_MWUF0_SHIFT                      0                                                   /*!< LLWU_F3: MWUF0 Position                 */
#define LLWU_F3_MWUF0(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF0_SHIFT))&LLWU_F3_MWUF0_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF1_MASK                       (0x01UL << LLWU_F3_MWUF1_SHIFT)                     /*!< LLWU_F3: MWUF1 Mask                     */
#define LLWU_F3_MWUF1_SHIFT                      1                                                   /*!< LLWU_F3: MWUF1 Position                 */
#define LLWU_F3_MWUF1(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF1_SHIFT))&LLWU_F3_MWUF1_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF2_MASK                       (0x01UL << LLWU_F3_MWUF2_SHIFT)                     /*!< LLWU_F3: MWUF2 Mask                     */
#define LLWU_F3_MWUF2_SHIFT                      2                                                   /*!< LLWU_F3: MWUF2 Position                 */
#define LLWU_F3_MWUF2(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF2_SHIFT))&LLWU_F3_MWUF2_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF3_MASK                       (0x01UL << LLWU_F3_MWUF3_SHIFT)                     /*!< LLWU_F3: MWUF3 Mask                     */
#define LLWU_F3_MWUF3_SHIFT                      3                                                   /*!< LLWU_F3: MWUF3 Position                 */
#define LLWU_F3_MWUF3(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF3_SHIFT))&LLWU_F3_MWUF3_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF4_MASK                       (0x01UL << LLWU_F3_MWUF4_SHIFT)                     /*!< LLWU_F3: MWUF4 Mask                     */
#define LLWU_F3_MWUF4_SHIFT                      4                                                   /*!< LLWU_F3: MWUF4 Position                 */
#define LLWU_F3_MWUF4(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF4_SHIFT))&LLWU_F3_MWUF4_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF5_MASK                       (0x01UL << LLWU_F3_MWUF5_SHIFT)                     /*!< LLWU_F3: MWUF5 Mask                     */
#define LLWU_F3_MWUF5_SHIFT                      5                                                   /*!< LLWU_F3: MWUF5 Position                 */
#define LLWU_F3_MWUF5(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF5_SHIFT))&LLWU_F3_MWUF5_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF6_MASK                       (0x01UL << LLWU_F3_MWUF6_SHIFT)                     /*!< LLWU_F3: MWUF6 Mask                     */
#define LLWU_F3_MWUF6_SHIFT                      6                                                   /*!< LLWU_F3: MWUF6 Position                 */
#define LLWU_F3_MWUF6(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF6_SHIFT))&LLWU_F3_MWUF6_MASK) /*!< LLWU_F3                                 */
#define LLWU_F3_MWUF7_MASK                       (0x01UL << LLWU_F3_MWUF7_SHIFT)                     /*!< LLWU_F3: MWUF7 Mask                     */
#define LLWU_F3_MWUF7_SHIFT                      7                                                   /*!< LLWU_F3: MWUF7 Position                 */
#define LLWU_F3_MWUF7(x)                         (((uint8_t)(((uint8_t)(x))<<LLWU_F3_MWUF7_SHIFT))&LLWU_F3_MWUF7_MASK) /*!< LLWU_F3                                 */
/* ------- MF0 Bit Fields                           ------ */
/* ------- FILT Bit Fields                          ------ */
#define LLWU_FILT_FILTSEL_MASK                   (0x0FUL << LLWU_FILT_FILTSEL_SHIFT)                 /*!< LLWU_FILT: FILTSEL Mask                 */
#define LLWU_FILT_FILTSEL_SHIFT                  0                                                   /*!< LLWU_FILT: FILTSEL Position             */
#define LLWU_FILT_FILTSEL(x)                     (((uint8_t)(((uint8_t)(x))<<LLWU_FILT_FILTSEL_SHIFT))&LLWU_FILT_FILTSEL_MASK) /*!< LLWU_FILT                               */
#define LLWU_FILT_FILTE_MASK                     (0x03UL << LLWU_FILT_FILTE_SHIFT)                   /*!< LLWU_FILT: FILTE Mask                   */
#define LLWU_FILT_FILTE_SHIFT                    5                                                   /*!< LLWU_FILT: FILTE Position               */
#define LLWU_FILT_FILTE(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_FILT_FILTE_SHIFT))&LLWU_FILT_FILTE_MASK) /*!< LLWU_FILT                               */
#define LLWU_FILT_FILTF_MASK                     (0x01UL << LLWU_FILT_FILTF_SHIFT)                   /*!< LLWU_FILT: FILTF Mask                   */
#define LLWU_FILT_FILTF_SHIFT                    7                                                   /*!< LLWU_FILT: FILTF Position               */
#define LLWU_FILT_FILTF(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_FILT_FILTF_SHIFT))&LLWU_FILT_FILTF_MASK) /*!< LLWU_FILT                               */
/* ------- RST Bit Fields                           ------ */
#define LLWU_RST_RSTFILT_MASK                    (0x01UL << LLWU_RST_RSTFILT_SHIFT)                  /*!< LLWU_RST: RSTFILT Mask                  */
#define LLWU_RST_RSTFILT_SHIFT                   0                                                   /*!< LLWU_RST: RSTFILT Position              */
#define LLWU_RST_RSTFILT(x)                      (((uint8_t)(((uint8_t)(x))<<LLWU_RST_RSTFILT_SHIFT))&LLWU_RST_RSTFILT_MASK) /*!< LLWU_RST                                */
#define LLWU_RST_LLRSTE_MASK                     (0x01UL << LLWU_RST_LLRSTE_SHIFT)                   /*!< LLWU_RST: LLRSTE Mask                   */
#define LLWU_RST_LLRSTE_SHIFT                    1                                                   /*!< LLWU_RST: LLRSTE Position               */
#define LLWU_RST_LLRSTE(x)                       (((uint8_t)(((uint8_t)(x))<<LLWU_RST_LLRSTE_SHIFT))&LLWU_RST_LLRSTE_MASK) /*!< LLWU_RST                                */
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
/* ================           LPTMR0 (file:LPTMR0_0)               ================ */
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
   __IO uint32_t  CSR;                          /**< 0000: Control Status Register                                      */
   __IO uint32_t  PSR;                          /**< 0004: Prescale Register                                            */
   __IO uint32_t  CMR;                          /**< 0008: Compare Register                                             */
   __IO uint32_t  CNR;                          /**< 000C: Counter Register                                             */
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
#define LPTMR_CSR_TEN_MASK                       (0x01UL << LPTMR_CSR_TEN_SHIFT)                     /*!< LPTMR0_CSR: TEN Mask                    */
#define LPTMR_CSR_TEN_SHIFT                      0                                                   /*!< LPTMR0_CSR: TEN Position                */
#define LPTMR_CSR_TEN(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TEN_SHIFT))&LPTMR_CSR_TEN_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TMS_MASK                       (0x01UL << LPTMR_CSR_TMS_SHIFT)                     /*!< LPTMR0_CSR: TMS Mask                    */
#define LPTMR_CSR_TMS_SHIFT                      1                                                   /*!< LPTMR0_CSR: TMS Position                */
#define LPTMR_CSR_TMS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TMS_SHIFT))&LPTMR_CSR_TMS_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TFC_MASK                       (0x01UL << LPTMR_CSR_TFC_SHIFT)                     /*!< LPTMR0_CSR: TFC Mask                    */
#define LPTMR_CSR_TFC_SHIFT                      2                                                   /*!< LPTMR0_CSR: TFC Position                */
#define LPTMR_CSR_TFC(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TFC_SHIFT))&LPTMR_CSR_TFC_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TPP_MASK                       (0x01UL << LPTMR_CSR_TPP_SHIFT)                     /*!< LPTMR0_CSR: TPP Mask                    */
#define LPTMR_CSR_TPP_SHIFT                      3                                                   /*!< LPTMR0_CSR: TPP Position                */
#define LPTMR_CSR_TPP(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TPP_SHIFT))&LPTMR_CSR_TPP_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TPS_MASK                       (0x03UL << LPTMR_CSR_TPS_SHIFT)                     /*!< LPTMR0_CSR: TPS Mask                    */
#define LPTMR_CSR_TPS_SHIFT                      4                                                   /*!< LPTMR0_CSR: TPS Position                */
#define LPTMR_CSR_TPS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TPS_SHIFT))&LPTMR_CSR_TPS_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TIE_MASK                       (0x01UL << LPTMR_CSR_TIE_SHIFT)                     /*!< LPTMR0_CSR: TIE Mask                    */
#define LPTMR_CSR_TIE_SHIFT                      6                                                   /*!< LPTMR0_CSR: TIE Position                */
#define LPTMR_CSR_TIE(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TIE_SHIFT))&LPTMR_CSR_TIE_MASK) /*!< LPTMR0_CSR                              */
#define LPTMR_CSR_TCF_MASK                       (0x01UL << LPTMR_CSR_TCF_SHIFT)                     /*!< LPTMR0_CSR: TCF Mask                    */
#define LPTMR_CSR_TCF_SHIFT                      7                                                   /*!< LPTMR0_CSR: TCF Position                */
#define LPTMR_CSR_TCF(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_CSR_TCF_SHIFT))&LPTMR_CSR_TCF_MASK) /*!< LPTMR0_CSR                              */
/* ------- PSR Bit Fields                           ------ */
#define LPTMR_PSR_PCS_MASK                       (0x03UL << LPTMR_PSR_PCS_SHIFT)                     /*!< LPTMR0_PSR: PCS Mask                    */
#define LPTMR_PSR_PCS_SHIFT                      0                                                   /*!< LPTMR0_PSR: PCS Position                */
#define LPTMR_PSR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PCS_SHIFT))&LPTMR_PSR_PCS_MASK) /*!< LPTMR0_PSR                              */
#define LPTMR_PSR_PBYP_MASK                      (0x01UL << LPTMR_PSR_PBYP_SHIFT)                    /*!< LPTMR0_PSR: PBYP Mask                   */
#define LPTMR_PSR_PBYP_SHIFT                     2                                                   /*!< LPTMR0_PSR: PBYP Position               */
#define LPTMR_PSR_PBYP(x)                        (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PBYP_SHIFT))&LPTMR_PSR_PBYP_MASK) /*!< LPTMR0_PSR                              */
#define LPTMR_PSR_PRESCALE_MASK                  (0x0FUL << LPTMR_PSR_PRESCALE_SHIFT)                /*!< LPTMR0_PSR: PRESCALE Mask               */
#define LPTMR_PSR_PRESCALE_SHIFT                 3                                                   /*!< LPTMR0_PSR: PRESCALE Position           */
#define LPTMR_PSR_PRESCALE(x)                    (((uint32_t)(((uint32_t)(x))<<LPTMR_PSR_PRESCALE_SHIFT))&LPTMR_PSR_PRESCALE_MASK) /*!< LPTMR0_PSR                              */
/* ------- CMR Bit Fields                           ------ */
#define LPTMR_CMR_COMPARE_MASK                   (0xFFFFUL << LPTMR_CMR_COMPARE_SHIFT)               /*!< LPTMR0_CMR: COMPARE Mask                */
#define LPTMR_CMR_COMPARE_SHIFT                  0                                                   /*!< LPTMR0_CMR: COMPARE Position            */
#define LPTMR_CMR_COMPARE(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CMR_COMPARE_SHIFT))&LPTMR_CMR_COMPARE_MASK) /*!< LPTMR0_CMR                              */
/* ------- CNR Bit Fields                           ------ */
#define LPTMR_CNR_COUNTER_MASK                   (0xFFFFUL << LPTMR_CNR_COUNTER_SHIFT)               /*!< LPTMR0_CNR: COUNTER Mask                */
#define LPTMR_CNR_COUNTER_SHIFT                  0                                                   /*!< LPTMR0_CNR: COUNTER Position            */
#define LPTMR_CNR_COUNTER(x)                     (((uint32_t)(((uint32_t)(x))<<LPTMR_CNR_COUNTER_SHIFT))&LPTMR_CNR_COUNTER_MASK) /*!< LPTMR0_CNR                              */
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
* @addtogroup MCG_Peripheral_access_layer_GROUP MCG Peripheral Access Layer
* @brief C Struct for MCG
* @{
*/

/* ================================================================================ */
/* ================           MCG (file:MCG_MK)                    ================ */
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
   __IO uint8_t   C1;                           /**< 0000: Control 1 Register                                           */
   __IO uint8_t   C2;                           /**< 0001: Control 2 Register                                           */
   __IO uint8_t   C3;                           /**< 0002: Control 3 Register                                           */
   __IO uint8_t   C4;                           /**< 0003: Control 4 Register                                           */
   __IO uint8_t   C5;                           /**< 0004: Control 5 Register                                           */
   __IO uint8_t   C6;                           /**< 0005: Control 6 Register                                           */
   __IO uint8_t   S;                            /**< 0006: Status Register                                              */
   __I  uint8_t   RESERVED0;                   
   __IO uint8_t   SC;                           /**< 0008: Status and Control Register                                  */
   __I  uint8_t   RESERVED1;                   
   __IO uint8_t   ATCVH;                        /**< 000A: ATM Compare Value High                                       */
   __IO uint8_t   ATCVL;                        /**< 000B: ATM Compare Value Low                                        */
   __IO uint8_t   C7;                           /**< 000C: Control 7 Register                                           */
   __IO uint8_t   C8;                           /**< 000D: Control 8 Register                                           */
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
#define MCG_C1_IREFSTEN_MASK                     (0x01UL << MCG_C1_IREFSTEN_SHIFT)                   /*!< MCG_C1: IREFSTEN Mask                   */
#define MCG_C1_IREFSTEN_SHIFT                    0                                                   /*!< MCG_C1: IREFSTEN Position               */
#define MCG_C1_IREFSTEN(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C1_IREFSTEN_SHIFT))&MCG_C1_IREFSTEN_MASK) /*!< MCG_C1                                  */
#define MCG_C1_IRCLKEN_MASK                      (0x01UL << MCG_C1_IRCLKEN_SHIFT)                    /*!< MCG_C1: IRCLKEN Mask                    */
#define MCG_C1_IRCLKEN_SHIFT                     1                                                   /*!< MCG_C1: IRCLKEN Position                */
#define MCG_C1_IRCLKEN(x)                        (((uint8_t)(((uint8_t)(x))<<MCG_C1_IRCLKEN_SHIFT))&MCG_C1_IRCLKEN_MASK) /*!< MCG_C1                                  */
#define MCG_C1_IREFS_MASK                        (0x01UL << MCG_C1_IREFS_SHIFT)                      /*!< MCG_C1: IREFS Mask                      */
#define MCG_C1_IREFS_SHIFT                       2                                                   /*!< MCG_C1: IREFS Position                  */
#define MCG_C1_IREFS(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C1_IREFS_SHIFT))&MCG_C1_IREFS_MASK) /*!< MCG_C1                                  */
#define MCG_C1_FRDIV_MASK                        (0x07UL << MCG_C1_FRDIV_SHIFT)                      /*!< MCG_C1: FRDIV Mask                      */
#define MCG_C1_FRDIV_SHIFT                       3                                                   /*!< MCG_C1: FRDIV Position                  */
#define MCG_C1_FRDIV(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C1_FRDIV_SHIFT))&MCG_C1_FRDIV_MASK) /*!< MCG_C1                                  */
#define MCG_C1_CLKS_MASK                         (0x03UL << MCG_C1_CLKS_SHIFT)                       /*!< MCG_C1: CLKS Mask                       */
#define MCG_C1_CLKS_SHIFT                        6                                                   /*!< MCG_C1: CLKS Position                   */
#define MCG_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C1_CLKS_SHIFT))&MCG_C1_CLKS_MASK) /*!< MCG_C1                                  */
/* ------- C2 Bit Fields                            ------ */
#define MCG_C2_IRCS_MASK                         (0x01UL << MCG_C2_IRCS_SHIFT)                       /*!< MCG_C2: IRCS Mask                       */
#define MCG_C2_IRCS_SHIFT                        0                                                   /*!< MCG_C2: IRCS Position                   */
#define MCG_C2_IRCS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C2_IRCS_SHIFT))&MCG_C2_IRCS_MASK) /*!< MCG_C2                                  */
#define MCG_C2_LP_MASK                           (0x01UL << MCG_C2_LP_SHIFT)                         /*!< MCG_C2: LP Mask                         */
#define MCG_C2_LP_SHIFT                          1                                                   /*!< MCG_C2: LP Position                     */
#define MCG_C2_LP(x)                             (((uint8_t)(((uint8_t)(x))<<MCG_C2_LP_SHIFT))&MCG_C2_LP_MASK) /*!< MCG_C2                                  */
#define MCG_C2_EREFS0_MASK                       (0x01UL << MCG_C2_EREFS0_SHIFT)                     /*!< MCG_C2: EREFS0 Mask                     */
#define MCG_C2_EREFS0_SHIFT                      2                                                   /*!< MCG_C2: EREFS0 Position                 */
#define MCG_C2_EREFS0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C2_EREFS0_SHIFT))&MCG_C2_EREFS0_MASK) /*!< MCG_C2                                  */
#define MCG_C2_HGO0_MASK                         (0x01UL << MCG_C2_HGO0_SHIFT)                       /*!< MCG_C2: HGO0 Mask                       */
#define MCG_C2_HGO0_SHIFT                        3                                                   /*!< MCG_C2: HGO0 Position                   */
#define MCG_C2_HGO0(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C2_HGO0_SHIFT))&MCG_C2_HGO0_MASK) /*!< MCG_C2                                  */
#define MCG_C2_RANGE0_MASK                       (0x03UL << MCG_C2_RANGE0_SHIFT)                     /*!< MCG_C2: RANGE0 Mask                     */
#define MCG_C2_RANGE0_SHIFT                      4                                                   /*!< MCG_C2: RANGE0 Position                 */
#define MCG_C2_RANGE0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C2_RANGE0_SHIFT))&MCG_C2_RANGE0_MASK) /*!< MCG_C2                                  */
#define MCG_C2_LOCRE0_MASK                       (0x01UL << MCG_C2_LOCRE0_SHIFT)                     /*!< MCG_C2: LOCRE0 Mask                     */
#define MCG_C2_LOCRE0_SHIFT                      7                                                   /*!< MCG_C2: LOCRE0 Position                 */
#define MCG_C2_LOCRE0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C2_LOCRE0_SHIFT))&MCG_C2_LOCRE0_MASK) /*!< MCG_C2                                  */
/* ------- C3 Bit Fields                            ------ */
#define MCG_C3_SCTRIM_MASK                       (0xFFUL << MCG_C3_SCTRIM_SHIFT)                     /*!< MCG_C3: SCTRIM Mask                     */
#define MCG_C3_SCTRIM_SHIFT                      0                                                   /*!< MCG_C3: SCTRIM Position                 */
#define MCG_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C3_SCTRIM_SHIFT))&MCG_C3_SCTRIM_MASK) /*!< MCG_C3                                  */
/* ------- C4 Bit Fields                            ------ */
#define MCG_C4_SCFTRIM_MASK                      (0x01UL << MCG_C4_SCFTRIM_SHIFT)                    /*!< MCG_C4: SCFTRIM Mask                    */
#define MCG_C4_SCFTRIM_SHIFT                     0                                                   /*!< MCG_C4: SCFTRIM Position                */
#define MCG_C4_SCFTRIM(x)                        (((uint8_t)(((uint8_t)(x))<<MCG_C4_SCFTRIM_SHIFT))&MCG_C4_SCFTRIM_MASK) /*!< MCG_C4                                  */
#define MCG_C4_FCTRIM_MASK                       (0x0FUL << MCG_C4_FCTRIM_SHIFT)                     /*!< MCG_C4: FCTRIM Mask                     */
#define MCG_C4_FCTRIM_SHIFT                      1                                                   /*!< MCG_C4: FCTRIM Position                 */
#define MCG_C4_FCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C4_FCTRIM_SHIFT))&MCG_C4_FCTRIM_MASK) /*!< MCG_C4                                  */
#define MCG_C4_DRST_DRS_MASK                     (0x03UL << MCG_C4_DRST_DRS_SHIFT)                   /*!< MCG_C4: DRST_DRS Mask                   */
#define MCG_C4_DRST_DRS_SHIFT                    5                                                   /*!< MCG_C4: DRST_DRS Position               */
#define MCG_C4_DRST_DRS(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C4_DRST_DRS_SHIFT))&MCG_C4_DRST_DRS_MASK) /*!< MCG_C4                                  */
#define MCG_C4_DMX32_MASK                        (0x01UL << MCG_C4_DMX32_SHIFT)                      /*!< MCG_C4: DMX32 Mask                      */
#define MCG_C4_DMX32_SHIFT                       7                                                   /*!< MCG_C4: DMX32 Position                  */
#define MCG_C4_DMX32(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C4_DMX32_SHIFT))&MCG_C4_DMX32_MASK) /*!< MCG_C4                                  */
/* ------- C5 Bit Fields                            ------ */
#define MCG_C5_PRDIV0_MASK                       (0x1FUL << MCG_C5_PRDIV0_SHIFT)                     /*!< MCG_C5: PRDIV0 Mask                     */
#define MCG_C5_PRDIV0_SHIFT                      0                                                   /*!< MCG_C5: PRDIV0 Position                 */
#define MCG_C5_PRDIV0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C5_PRDIV0_SHIFT))&MCG_C5_PRDIV0_MASK) /*!< MCG_C5                                  */
#define MCG_C5_PLLSTEN0_MASK                     (0x01UL << MCG_C5_PLLSTEN0_SHIFT)                   /*!< MCG_C5: PLLSTEN0 Mask                   */
#define MCG_C5_PLLSTEN0_SHIFT                    5                                                   /*!< MCG_C5: PLLSTEN0 Position               */
#define MCG_C5_PLLSTEN0(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C5_PLLSTEN0_SHIFT))&MCG_C5_PLLSTEN0_MASK) /*!< MCG_C5                                  */
#define MCG_C5_PLLCLKEN0_MASK                    (0x01UL << MCG_C5_PLLCLKEN0_SHIFT)                  /*!< MCG_C5: PLLCLKEN0 Mask                  */
#define MCG_C5_PLLCLKEN0_SHIFT                   6                                                   /*!< MCG_C5: PLLCLKEN0 Position              */
#define MCG_C5_PLLCLKEN0(x)                      (((uint8_t)(((uint8_t)(x))<<MCG_C5_PLLCLKEN0_SHIFT))&MCG_C5_PLLCLKEN0_MASK) /*!< MCG_C5                                  */
/* ------- C6 Bit Fields                            ------ */
#define MCG_C6_VDIV0_MASK                        (0x1FUL << MCG_C6_VDIV0_SHIFT)                      /*!< MCG_C6: VDIV0 Mask                      */
#define MCG_C6_VDIV0_SHIFT                       0                                                   /*!< MCG_C6: VDIV0 Position                  */
#define MCG_C6_VDIV0(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C6_VDIV0_SHIFT))&MCG_C6_VDIV0_MASK) /*!< MCG_C6                                  */
#define MCG_C6_CME0_MASK                         (0x01UL << MCG_C6_CME0_SHIFT)                       /*!< MCG_C6: CME0 Mask                       */
#define MCG_C6_CME0_SHIFT                        5                                                   /*!< MCG_C6: CME0 Position                   */
#define MCG_C6_CME0(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C6_CME0_SHIFT))&MCG_C6_CME0_MASK) /*!< MCG_C6                                  */
#define MCG_C6_PLLS_MASK                         (0x01UL << MCG_C6_PLLS_SHIFT)                       /*!< MCG_C6: PLLS Mask                       */
#define MCG_C6_PLLS_SHIFT                        6                                                   /*!< MCG_C6: PLLS Position                   */
#define MCG_C6_PLLS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C6_PLLS_SHIFT))&MCG_C6_PLLS_MASK) /*!< MCG_C6                                  */
#define MCG_C6_LOLIE0_MASK                       (0x01UL << MCG_C6_LOLIE0_SHIFT)                     /*!< MCG_C6: LOLIE0 Mask                     */
#define MCG_C6_LOLIE0_SHIFT                      7                                                   /*!< MCG_C6: LOLIE0 Position                 */
#define MCG_C6_LOLIE0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C6_LOLIE0_SHIFT))&MCG_C6_LOLIE0_MASK) /*!< MCG_C6                                  */
/* ------- S Bit Fields                             ------ */
#define MCG_S_IRCST_MASK                         (0x01UL << MCG_S_IRCST_SHIFT)                       /*!< MCG_S: IRCST Mask                       */
#define MCG_S_IRCST_SHIFT                        0                                                   /*!< MCG_S: IRCST Position                   */
#define MCG_S_IRCST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_IRCST_SHIFT))&MCG_S_IRCST_MASK) /*!< MCG_S                                   */
#define MCG_S_OSCINIT0_MASK                      (0x01UL << MCG_S_OSCINIT0_SHIFT)                    /*!< MCG_S: OSCINIT0 Mask                    */
#define MCG_S_OSCINIT0_SHIFT                     1                                                   /*!< MCG_S: OSCINIT0 Position                */
#define MCG_S_OSCINIT0(x)                        (((uint8_t)(((uint8_t)(x))<<MCG_S_OSCINIT0_SHIFT))&MCG_S_OSCINIT0_MASK) /*!< MCG_S                                   */
#define MCG_S_CLKST_MASK                         (0x03UL << MCG_S_CLKST_SHIFT)                       /*!< MCG_S: CLKST Mask                       */
#define MCG_S_CLKST_SHIFT                        2                                                   /*!< MCG_S: CLKST Position                   */
#define MCG_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_CLKST_SHIFT))&MCG_S_CLKST_MASK) /*!< MCG_S                                   */
#define MCG_S_IREFST_MASK                        (0x01UL << MCG_S_IREFST_SHIFT)                      /*!< MCG_S: IREFST Mask                      */
#define MCG_S_IREFST_SHIFT                       4                                                   /*!< MCG_S: IREFST Position                  */
#define MCG_S_IREFST(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_S_IREFST_SHIFT))&MCG_S_IREFST_MASK) /*!< MCG_S                                   */
#define MCG_S_PLLST_MASK                         (0x01UL << MCG_S_PLLST_SHIFT)                       /*!< MCG_S: PLLST Mask                       */
#define MCG_S_PLLST_SHIFT                        5                                                   /*!< MCG_S: PLLST Position                   */
#define MCG_S_PLLST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_PLLST_SHIFT))&MCG_S_PLLST_MASK) /*!< MCG_S                                   */
#define MCG_S_LOCK0_MASK                         (0x01UL << MCG_S_LOCK0_SHIFT)                       /*!< MCG_S: LOCK0 Mask                       */
#define MCG_S_LOCK0_SHIFT                        6                                                   /*!< MCG_S: LOCK0 Position                   */
#define MCG_S_LOCK0(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_LOCK0_SHIFT))&MCG_S_LOCK0_MASK) /*!< MCG_S                                   */
#define MCG_S_LOLS0_MASK                         (0x01UL << MCG_S_LOLS0_SHIFT)                       /*!< MCG_S: LOLS0 Mask                       */
#define MCG_S_LOLS0_SHIFT                        7                                                   /*!< MCG_S: LOLS0 Position                   */
#define MCG_S_LOLS0(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_LOLS0_SHIFT))&MCG_S_LOLS0_MASK) /*!< MCG_S                                   */
/* ------- SC Bit Fields                            ------ */
#define MCG_SC_LOCS0_MASK                        (0x01UL << MCG_SC_LOCS0_SHIFT)                      /*!< MCG_SC: LOCS0 Mask                      */
#define MCG_SC_LOCS0_SHIFT                       0                                                   /*!< MCG_SC: LOCS0 Position                  */
#define MCG_SC_LOCS0(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_SC_LOCS0_SHIFT))&MCG_SC_LOCS0_MASK) /*!< MCG_SC                                  */
#define MCG_SC_FCRDIV_MASK                       (0x07UL << MCG_SC_FCRDIV_SHIFT)                     /*!< MCG_SC: FCRDIV Mask                     */
#define MCG_SC_FCRDIV_SHIFT                      1                                                   /*!< MCG_SC: FCRDIV Position                 */
#define MCG_SC_FCRDIV(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_SC_FCRDIV_SHIFT))&MCG_SC_FCRDIV_MASK) /*!< MCG_SC                                  */
#define MCG_SC_FLTPRSRV_MASK                     (0x01UL << MCG_SC_FLTPRSRV_SHIFT)                   /*!< MCG_SC: FLTPRSRV Mask                   */
#define MCG_SC_FLTPRSRV_SHIFT                    4                                                   /*!< MCG_SC: FLTPRSRV Position               */
#define MCG_SC_FLTPRSRV(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_SC_FLTPRSRV_SHIFT))&MCG_SC_FLTPRSRV_MASK) /*!< MCG_SC                                  */
#define MCG_SC_ATMF_MASK                         (0x01UL << MCG_SC_ATMF_SHIFT)                       /*!< MCG_SC: ATMF Mask                       */
#define MCG_SC_ATMF_SHIFT                        5                                                   /*!< MCG_SC: ATMF Position                   */
#define MCG_SC_ATMF(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_SC_ATMF_SHIFT))&MCG_SC_ATMF_MASK) /*!< MCG_SC                                  */
#define MCG_SC_ATMS_MASK                         (0x01UL << MCG_SC_ATMS_SHIFT)                       /*!< MCG_SC: ATMS Mask                       */
#define MCG_SC_ATMS_SHIFT                        6                                                   /*!< MCG_SC: ATMS Position                   */
#define MCG_SC_ATMS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_SC_ATMS_SHIFT))&MCG_SC_ATMS_MASK) /*!< MCG_SC                                  */
#define MCG_SC_ATME_MASK                         (0x01UL << MCG_SC_ATME_SHIFT)                       /*!< MCG_SC: ATME Mask                       */
#define MCG_SC_ATME_SHIFT                        7                                                   /*!< MCG_SC: ATME Position                   */
#define MCG_SC_ATME(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_SC_ATME_SHIFT))&MCG_SC_ATME_MASK) /*!< MCG_SC                                  */
/* ------- ATCVH Bit Fields                         ------ */
#define MCG_ATCVH_ATCVH_MASK                     (0xFFUL << MCG_ATCVH_ATCVH_SHIFT)                   /*!< MCG_ATCVH: ATCVH Mask                   */
#define MCG_ATCVH_ATCVH_SHIFT                    0                                                   /*!< MCG_ATCVH: ATCVH Position               */
#define MCG_ATCVH_ATCVH(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVH_ATCVH_SHIFT))&MCG_ATCVH_ATCVH_MASK) /*!< MCG_ATCVH                               */
/* ------- ATCVL Bit Fields                         ------ */
#define MCG_ATCVL_ATCVL_MASK                     (0xFFUL << MCG_ATCVL_ATCVL_SHIFT)                   /*!< MCG_ATCVL: ATCVL Mask                   */
#define MCG_ATCVL_ATCVL_SHIFT                    0                                                   /*!< MCG_ATCVL: ATCVL Position               */
#define MCG_ATCVL_ATCVL(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVL_ATCVL_SHIFT))&MCG_ATCVL_ATCVL_MASK) /*!< MCG_ATCVL                               */
/* ------- C7 Bit Fields                            ------ */
#define MCG_C7_OSCSEL_MASK                       (0x01UL << MCG_C7_OSCSEL_SHIFT)                     /*!< MCG_C7: OSCSEL Mask                     */
#define MCG_C7_OSCSEL_SHIFT                      0                                                   /*!< MCG_C7: OSCSEL Position                 */
#define MCG_C7_OSCSEL(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C7_OSCSEL_SHIFT))&MCG_C7_OSCSEL_MASK) /*!< MCG_C7                                  */
/* ------- C8 Bit Fields                            ------ */
#define MCG_C8_LOCS1_MASK                        (0x01UL << MCG_C8_LOCS1_SHIFT)                      /*!< MCG_C8: LOCS1 Mask                      */
#define MCG_C8_LOCS1_SHIFT                       0                                                   /*!< MCG_C8: LOCS1 Position                  */
#define MCG_C8_LOCS1(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C8_LOCS1_SHIFT))&MCG_C8_LOCS1_MASK) /*!< MCG_C8                                  */
#define MCG_C8_CME1_MASK                         (0x01UL << MCG_C8_CME1_SHIFT)                       /*!< MCG_C8: CME1 Mask                       */
#define MCG_C8_CME1_SHIFT                        5                                                   /*!< MCG_C8: CME1 Position                   */
#define MCG_C8_CME1(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C8_CME1_SHIFT))&MCG_C8_CME1_MASK) /*!< MCG_C8                                  */
#define MCG_C8_LOLRE_MASK                        (0x01UL << MCG_C8_LOLRE_SHIFT)                      /*!< MCG_C8: LOLRE Mask                      */
#define MCG_C8_LOLRE_SHIFT                       6                                                   /*!< MCG_C8: LOLRE Position                  */
#define MCG_C8_LOLRE(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C8_LOLRE_SHIFT))&MCG_C8_LOLRE_MASK) /*!< MCG_C8                                  */
#define MCG_C8_LOCRE1_MASK                       (0x01UL << MCG_C8_LOCRE1_SHIFT)                     /*!< MCG_C8: LOCRE1 Mask                     */
#define MCG_C8_LOCRE1_SHIFT                      7                                                   /*!< MCG_C8: LOCRE1 Position                 */
#define MCG_C8_LOCRE1(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C8_LOCRE1_SHIFT))&MCG_C8_LOCRE1_MASK) /*!< MCG_C8                                  */
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
/* ================           MCM (file:MCM_MK10D7)                ================ */
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
   __I  uint32_t  RESERVED0[2];                
   __I  uint16_t  PLASC;                        /**< 0008: Crossbar Switch (AXBS) Slave Configuration                   */
   __I  uint16_t  PLAMC;                        /**< 000A: Crossbar Switch (AXBS) Master Configuration                  */
   __IO uint32_t  CR;                           /**< 000C: Control Register                                             */
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
#define MCM_PLASC_ASC_MASK                       (0xFFUL << MCM_PLASC_ASC_SHIFT)                     /*!< MCM_PLASC: ASC Mask                     */
#define MCM_PLASC_ASC_SHIFT                      0                                                   /*!< MCM_PLASC: ASC Position                 */
#define MCM_PLASC_ASC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLASC_ASC_SHIFT))&MCM_PLASC_ASC_MASK) /*!< MCM_PLASC                               */
/* ------- PLAMC Bit Fields                         ------ */
#define MCM_PLAMC_AMC_MASK                       (0xFFUL << MCM_PLAMC_AMC_SHIFT)                     /*!< MCM_PLAMC: AMC Mask                     */
#define MCM_PLAMC_AMC_SHIFT                      0                                                   /*!< MCM_PLAMC: AMC Position                 */
#define MCM_PLAMC_AMC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLAMC_AMC_SHIFT))&MCM_PLAMC_AMC_MASK) /*!< MCM_PLAMC                               */
/* ------- CR Bit Fields                            ------ */
#define MCM_CR_SRAMUAP_MASK                      (0x03UL << MCM_CR_SRAMUAP_SHIFT)                    /*!< MCM_CR: SRAMUAP Mask                    */
#define MCM_CR_SRAMUAP_SHIFT                     24                                                  /*!< MCM_CR: SRAMUAP Position                */
#define MCM_CR_SRAMUAP(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CR_SRAMUAP_SHIFT))&MCM_CR_SRAMUAP_MASK) /*!< MCM_CR                                  */
#define MCM_CR_SRAMUWP_MASK                      (0x01UL << MCM_CR_SRAMUWP_SHIFT)                    /*!< MCM_CR: SRAMUWP Mask                    */
#define MCM_CR_SRAMUWP_SHIFT                     26                                                  /*!< MCM_CR: SRAMUWP Position                */
#define MCM_CR_SRAMUWP(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CR_SRAMUWP_SHIFT))&MCM_CR_SRAMUWP_MASK) /*!< MCM_CR                                  */
#define MCM_CR_SRAMLAP_MASK                      (0x03UL << MCM_CR_SRAMLAP_SHIFT)                    /*!< MCM_CR: SRAMLAP Mask                    */
#define MCM_CR_SRAMLAP_SHIFT                     28                                                  /*!< MCM_CR: SRAMLAP Position                */
#define MCM_CR_SRAMLAP(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CR_SRAMLAP_SHIFT))&MCM_CR_SRAMLAP_MASK) /*!< MCM_CR                                  */
#define MCM_CR_SRAMLWP_MASK                      (0x01UL << MCM_CR_SRAMLWP_SHIFT)                    /*!< MCM_CR: SRAMLWP Mask                    */
#define MCM_CR_SRAMLWP_SHIFT                     30                                                  /*!< MCM_CR: SRAMLWP Position                */
#define MCM_CR_SRAMLWP(x)                        (((uint32_t)(((uint32_t)(x))<<MCM_CR_SRAMLWP_SHIFT))&MCM_CR_SRAMLWP_MASK) /*!< MCM_CR                                  */
/**
 * @} */ /* End group MCM_Register_Masks_GROUP 
 */

/* MCM - Peripheral instance base addresses */
#define MCM_BasePtr                    0xE0080000UL //!< Peripheral base address
#define MCM                            ((MCM_Type *) MCM_BasePtr) //!< Freescale base pointer
#define MCM_BASE_PTR                   (MCM) //!< Freescale style base pointer
/**
 * @} */ /* End group MCM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup NV_Peripheral_access_layer_GROUP NV Peripheral Access Layer
* @brief C Struct for NV
* @{
*/

/* ================================================================================ */
/* ================           NV (file:NV_FTFL)                    ================ */
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
   __I  uint8_t   FPROT3;                       /**< 0008: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FPROT2;                       /**< 0009: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FPROT1;                       /**< 000A: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FPROT0;                       /**< 000B: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FSEC;                         /**< 000C: Non-volatile Flash Security Register                         */
   __I  uint8_t   FOPT;                         /**< 000D: Non-volatile Flash Option Register                           */
   __I  uint8_t   FEPROT;                       /**< 000E: Non-volatile EEPROM Protection Register                      */
   __I  uint8_t   FDPROT;                       /**< 000F: Non-volatile D-Flash Protection Register                     */
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
#define NV_BACKKEY_KEY_MASK                      (0xFFUL << NV_BACKKEY_KEY_SHIFT)                    /*!< NV_BACKKEY: KEY Mask                    */
#define NV_BACKKEY_KEY_SHIFT                     0                                                   /*!< NV_BACKKEY: KEY Position                */
#define NV_BACKKEY_KEY(x)                        (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY_KEY_SHIFT))&NV_BACKKEY_KEY_MASK) /*!< NV_BACKKEY                              */
/* ------- FPROT Bit Fields                         ------ */
#define NV_FPROT_PROT_MASK                       (0xFFUL << NV_FPROT_PROT_SHIFT)                     /*!< NV_FPROT: PROT Mask                     */
#define NV_FPROT_PROT_SHIFT                      0                                                   /*!< NV_FPROT: PROT Position                 */
#define NV_FPROT_PROT(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FPROT_PROT_SHIFT))&NV_FPROT_PROT_MASK) /*!< NV_FPROT                                */
/* ------- FSEC Bit Fields                          ------ */
#define NV_FSEC_SEC_MASK                         (0x03UL << NV_FSEC_SEC_SHIFT)                       /*!< NV_FSEC: SEC Mask                       */
#define NV_FSEC_SEC_SHIFT                        0                                                   /*!< NV_FSEC: SEC Position                   */
#define NV_FSEC_SEC(x)                           (((uint8_t)(((uint8_t)(x))<<NV_FSEC_SEC_SHIFT))&NV_FSEC_SEC_MASK) /*!< NV_FSEC                                 */
#define NV_FSEC_FSLACC_MASK                      (0x03UL << NV_FSEC_FSLACC_SHIFT)                    /*!< NV_FSEC: FSLACC Mask                    */
#define NV_FSEC_FSLACC_SHIFT                     2                                                   /*!< NV_FSEC: FSLACC Position                */
#define NV_FSEC_FSLACC(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FSEC_FSLACC_SHIFT))&NV_FSEC_FSLACC_MASK) /*!< NV_FSEC                                 */
#define NV_FSEC_MEEN_MASK                        (0x03UL << NV_FSEC_MEEN_SHIFT)                      /*!< NV_FSEC: MEEN Mask                      */
#define NV_FSEC_MEEN_SHIFT                       4                                                   /*!< NV_FSEC: MEEN Position                  */
#define NV_FSEC_MEEN(x)                          (((uint8_t)(((uint8_t)(x))<<NV_FSEC_MEEN_SHIFT))&NV_FSEC_MEEN_MASK) /*!< NV_FSEC                                 */
#define NV_FSEC_KEYEN_MASK                       (0x03UL << NV_FSEC_KEYEN_SHIFT)                     /*!< NV_FSEC: KEYEN Mask                     */
#define NV_FSEC_KEYEN_SHIFT                      6                                                   /*!< NV_FSEC: KEYEN Position                 */
#define NV_FSEC_KEYEN(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FSEC_KEYEN_SHIFT))&NV_FSEC_KEYEN_MASK) /*!< NV_FSEC                                 */
/* ------- FOPT Bit Fields                          ------ */
#define NV_FOPT_LPBOOT_MASK                      (0x01UL << NV_FOPT_LPBOOT_SHIFT)                    /*!< NV_FOPT: LPBOOT Mask                    */
#define NV_FOPT_LPBOOT_SHIFT                     0                                                   /*!< NV_FOPT: LPBOOT Position                */
#define NV_FOPT_LPBOOT(x)                        (((uint8_t)(((uint8_t)(x))<<NV_FOPT_LPBOOT_SHIFT))&NV_FOPT_LPBOOT_MASK) /*!< NV_FOPT                                 */
#define NV_FOPT_EZPORT_DIS_MASK                  (0x01UL << NV_FOPT_EZPORT_DIS_SHIFT)                /*!< NV_FOPT: EZPORT_DIS Mask                */
#define NV_FOPT_EZPORT_DIS_SHIFT                 1                                                   /*!< NV_FOPT: EZPORT_DIS Position            */
#define NV_FOPT_EZPORT_DIS(x)                    (((uint8_t)(((uint8_t)(x))<<NV_FOPT_EZPORT_DIS_SHIFT))&NV_FOPT_EZPORT_DIS_MASK) /*!< NV_FOPT                                 */
#define NV_FOPT_NMI_DIS_MASK                     (0x01UL << NV_FOPT_NMI_DIS_SHIFT)                   /*!< NV_FOPT: NMI_DIS Mask                   */
#define NV_FOPT_NMI_DIS_SHIFT                    2                                                   /*!< NV_FOPT: NMI_DIS Position               */
#define NV_FOPT_NMI_DIS(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FOPT_NMI_DIS_SHIFT))&NV_FOPT_NMI_DIS_MASK) /*!< NV_FOPT                                 */
/* ------- FEPROT Bit Fields                        ------ */
#define NV_FEPROT_EPROT_MASK                     (0xFFUL << NV_FEPROT_EPROT_SHIFT)                   /*!< NV_FEPROT: EPROT Mask                   */
#define NV_FEPROT_EPROT_SHIFT                    0                                                   /*!< NV_FEPROT: EPROT Position               */
#define NV_FEPROT_EPROT(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FEPROT_EPROT_SHIFT))&NV_FEPROT_EPROT_MASK) /*!< NV_FEPROT                               */
/* ------- FDPROT Bit Fields                        ------ */
#define NV_FDPROT_DPROT_MASK                     (0xFFUL << NV_FDPROT_DPROT_SHIFT)                   /*!< NV_FDPROT: DPROT Mask                   */
#define NV_FDPROT_DPROT_SHIFT                    0                                                   /*!< NV_FDPROT: DPROT Position               */
#define NV_FDPROT_DPROT(x)                       (((uint8_t)(((uint8_t)(x))<<NV_FDPROT_DPROT_SHIFT))&NV_FDPROT_DPROT_MASK) /*!< NV_FDPROT                               */
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
/* ================           OSC0 (file:OSC0_MK)                  ================ */
/* ================================================================================ */

/**
 * @brief System Oscillator
 */
/**
* @addtogroup OSC_structs_GROUP OSC struct
* @brief Struct for OSC
* @{
*/
typedef struct {                                /*       OSC0 Structure                                               */
   __IO uint8_t   CR;                           /**< 0000: Control Register                                             */
} OSC_Type;

/**
 * @} */ /* End group OSC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'OSC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup OSC_Register_Masks_GROUP OSC Register Masks
* @brief Register Masks for OSC
* @{
*/
/* ------- CR Bit Fields                            ------ */
#define OSC_CR_SCP_MASK                          (0x0FUL << OSC_CR_SCP_SHIFT)                        /*!< OSC0_CR: SCP Mask                       */
#define OSC_CR_SCP_SHIFT                         0                                                   /*!< OSC0_CR: SCP Position                   */
#define OSC_CR_SCP(x)                            (((uint8_t)(((uint8_t)(x))<<OSC_CR_SCP_SHIFT))&OSC_CR_SCP_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_SC16P_MASK                        (0x01UL << OSC_CR_SC16P_SHIFT)                      /*!< OSC0_CR: SC16P Mask                     */
#define OSC_CR_SC16P_SHIFT                       0                                                   /*!< OSC0_CR: SC16P Position                 */
#define OSC_CR_SC16P(x)                          (((uint8_t)(((uint8_t)(x))<<OSC_CR_SC16P_SHIFT))&OSC_CR_SC16P_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_SC8P_MASK                         (0x01UL << OSC_CR_SC8P_SHIFT)                       /*!< OSC0_CR: SC8P Mask                      */
#define OSC_CR_SC8P_SHIFT                        1                                                   /*!< OSC0_CR: SC8P Position                  */
#define OSC_CR_SC8P(x)                           (((uint8_t)(((uint8_t)(x))<<OSC_CR_SC8P_SHIFT))&OSC_CR_SC8P_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_SC4P_MASK                         (0x01UL << OSC_CR_SC4P_SHIFT)                       /*!< OSC0_CR: SC4P Mask                      */
#define OSC_CR_SC4P_SHIFT                        2                                                   /*!< OSC0_CR: SC4P Position                  */
#define OSC_CR_SC4P(x)                           (((uint8_t)(((uint8_t)(x))<<OSC_CR_SC4P_SHIFT))&OSC_CR_SC4P_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_SC2P_MASK                         (0x01UL << OSC_CR_SC2P_SHIFT)                       /*!< OSC0_CR: SC2P Mask                      */
#define OSC_CR_SC2P_SHIFT                        3                                                   /*!< OSC0_CR: SC2P Position                  */
#define OSC_CR_SC2P(x)                           (((uint8_t)(((uint8_t)(x))<<OSC_CR_SC2P_SHIFT))&OSC_CR_SC2P_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_EREFSTEN_MASK                     (0x01UL << OSC_CR_EREFSTEN_SHIFT)                   /*!< OSC0_CR: EREFSTEN Mask                  */
#define OSC_CR_EREFSTEN_SHIFT                    5                                                   /*!< OSC0_CR: EREFSTEN Position              */
#define OSC_CR_EREFSTEN(x)                       (((uint8_t)(((uint8_t)(x))<<OSC_CR_EREFSTEN_SHIFT))&OSC_CR_EREFSTEN_MASK) /*!< OSC0_CR                                 */
#define OSC_CR_ERCLKEN_MASK                      (0x01UL << OSC_CR_ERCLKEN_SHIFT)                    /*!< OSC0_CR: ERCLKEN Mask                   */
#define OSC_CR_ERCLKEN_SHIFT                     7                                                   /*!< OSC0_CR: ERCLKEN Position               */
#define OSC_CR_ERCLKEN(x)                        (((uint8_t)(((uint8_t)(x))<<OSC_CR_ERCLKEN_SHIFT))&OSC_CR_ERCLKEN_MASK) /*!< OSC0_CR                                 */
/**
 * @} */ /* End group OSC_Register_Masks_GROUP 
 */

/* OSC0 - Peripheral instance base addresses */
#define OSC0_BasePtr                   0x40065000UL //!< Peripheral base address
#define OSC0                           ((OSC_Type *) OSC0_BasePtr) //!< Freescale base pointer
#define OSC0_BASE_PTR                  (OSC0) //!< Freescale style base pointer
/**
 * @} */ /* End group OSC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PDB_Peripheral_access_layer_GROUP PDB Peripheral Access Layer
* @brief C Struct for PDB
* @{
*/

/* ================================================================================ */
/* ================           PDB0 (file:PDB0_2CH_2TRIG_1DAC_3PO)       ================ */
/* ================================================================================ */

/**
 * @brief Programmable Delay Block (2 channels, 2 triggers, 2 DAC, 3 pulse outputs)
 */
/**
* @addtogroup PDB_structs_GROUP PDB struct
* @brief Struct for PDB
* @{
*/
typedef struct {                                /*       PDB0 Structure                                               */
   __IO uint32_t  SC;                           /**< 0000: Status and Control Register                                  */
   __IO uint32_t  MOD;                          /**< 0004: Modulus Register                                             */
   __I  uint32_t  CNT;                          /**< 0008: Counter Register                                             */
   __IO uint32_t  IDLY;                         /**< 000C: Interrupt Delay Register                                     */
   struct {
      __IO uint32_t  C1;                        /**< 0010: Channel  Control Register 1                                  */
      __IO uint32_t  S;                         /**< 0014: Channel  Status Register                                     */
      __IO uint32_t  DLY[2];                    /**< 0018: Channel Delay  Register                                      */
      __I  uint32_t  RESERVED0[6];             
   } CH[2];                                     /**< 0010: (cluster: size=0x0050, 80)                                   */
   __I  uint32_t  RESERVED0[60];               
   struct {
      __IO uint32_t  INTC;                      /**< 0150: DAC Interval Trigger n Control Register                      */
      __IO uint32_t  INT;                       /**< 0154: DAC Interval n Register                                      */
   } DAC[1];                                    /**< 0150: (cluster: size=0x0008, 8)                                    */
   __I  uint32_t  RESERVED1[14];               
   __IO uint32_t  POEN;                         /**< 0190: Pulse-Out Enable Register                                    */
   __IO uint32_t  PODLY[3];                     /**< 0194: Pulse-Out  Delay Register                                    */
} PDB_Type;

/**
 * @} */ /* End group PDB_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PDB0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PDB_Register_Masks_GROUP PDB Register Masks
* @brief Register Masks for PDB
* @{
*/
/* ------- SC Bit Fields                            ------ */
#define PDB_SC_LDOK_MASK                         (0x01UL << PDB_SC_LDOK_SHIFT)                       /*!< PDB0_SC: LDOK Mask                      */
#define PDB_SC_LDOK_SHIFT                        0                                                   /*!< PDB0_SC: LDOK Position                  */
#define PDB_SC_LDOK(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_SC_LDOK_SHIFT))&PDB_SC_LDOK_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_CONT_MASK                         (0x01UL << PDB_SC_CONT_SHIFT)                       /*!< PDB0_SC: CONT Mask                      */
#define PDB_SC_CONT_SHIFT                        1                                                   /*!< PDB0_SC: CONT Position                  */
#define PDB_SC_CONT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_SC_CONT_SHIFT))&PDB_SC_CONT_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_MULT_MASK                         (0x03UL << PDB_SC_MULT_SHIFT)                       /*!< PDB0_SC: MULT Mask                      */
#define PDB_SC_MULT_SHIFT                        2                                                   /*!< PDB0_SC: MULT Position                  */
#define PDB_SC_MULT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_SC_MULT_SHIFT))&PDB_SC_MULT_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_PDBIE_MASK                        (0x01UL << PDB_SC_PDBIE_SHIFT)                      /*!< PDB0_SC: PDBIE Mask                     */
#define PDB_SC_PDBIE_SHIFT                       5                                                   /*!< PDB0_SC: PDBIE Position                 */
#define PDB_SC_PDBIE(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_PDBIE_SHIFT))&PDB_SC_PDBIE_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_PDBIF_MASK                        (0x01UL << PDB_SC_PDBIF_SHIFT)                      /*!< PDB0_SC: PDBIF Mask                     */
#define PDB_SC_PDBIF_SHIFT                       6                                                   /*!< PDB0_SC: PDBIF Position                 */
#define PDB_SC_PDBIF(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_PDBIF_SHIFT))&PDB_SC_PDBIF_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_PDBEN_MASK                        (0x01UL << PDB_SC_PDBEN_SHIFT)                      /*!< PDB0_SC: PDBEN Mask                     */
#define PDB_SC_PDBEN_SHIFT                       7                                                   /*!< PDB0_SC: PDBEN Position                 */
#define PDB_SC_PDBEN(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_PDBEN_SHIFT))&PDB_SC_PDBEN_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_TRGSEL_MASK                       (0x0FUL << PDB_SC_TRGSEL_SHIFT)                     /*!< PDB0_SC: TRGSEL Mask                    */
#define PDB_SC_TRGSEL_SHIFT                      8                                                   /*!< PDB0_SC: TRGSEL Position                */
#define PDB_SC_TRGSEL(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_SC_TRGSEL_SHIFT))&PDB_SC_TRGSEL_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_PRESCALER_MASK                    (0x07UL << PDB_SC_PRESCALER_SHIFT)                  /*!< PDB0_SC: PRESCALER Mask                 */
#define PDB_SC_PRESCALER_SHIFT                   12                                                  /*!< PDB0_SC: PRESCALER Position             */
#define PDB_SC_PRESCALER(x)                      (((uint32_t)(((uint32_t)(x))<<PDB_SC_PRESCALER_SHIFT))&PDB_SC_PRESCALER_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_DMAEN_MASK                        (0x01UL << PDB_SC_DMAEN_SHIFT)                      /*!< PDB0_SC: DMAEN Mask                     */
#define PDB_SC_DMAEN_SHIFT                       15                                                  /*!< PDB0_SC: DMAEN Position                 */
#define PDB_SC_DMAEN(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_DMAEN_SHIFT))&PDB_SC_DMAEN_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_SWTRIG_MASK                       (0x01UL << PDB_SC_SWTRIG_SHIFT)                     /*!< PDB0_SC: SWTRIG Mask                    */
#define PDB_SC_SWTRIG_SHIFT                      16                                                  /*!< PDB0_SC: SWTRIG Position                */
#define PDB_SC_SWTRIG(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_SC_SWTRIG_SHIFT))&PDB_SC_SWTRIG_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_PDBEIE_MASK                       (0x01UL << PDB_SC_PDBEIE_SHIFT)                     /*!< PDB0_SC: PDBEIE Mask                    */
#define PDB_SC_PDBEIE_SHIFT                      17                                                  /*!< PDB0_SC: PDBEIE Position                */
#define PDB_SC_PDBEIE(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_SC_PDBEIE_SHIFT))&PDB_SC_PDBEIE_MASK) /*!< PDB0_SC                                 */
#define PDB_SC_LDMOD_MASK                        (0x03UL << PDB_SC_LDMOD_SHIFT)                      /*!< PDB0_SC: LDMOD Mask                     */
#define PDB_SC_LDMOD_SHIFT                       18                                                  /*!< PDB0_SC: LDMOD Position                 */
#define PDB_SC_LDMOD(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_SC_LDMOD_SHIFT))&PDB_SC_LDMOD_MASK) /*!< PDB0_SC                                 */
/* ------- MOD Bit Fields                           ------ */
#define PDB_MOD_MOD_MASK                         (0xFFFFUL << PDB_MOD_MOD_SHIFT)                     /*!< PDB0_MOD: MOD Mask                      */
#define PDB_MOD_MOD_SHIFT                        0                                                   /*!< PDB0_MOD: MOD Position                  */
#define PDB_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_MOD_MOD_SHIFT))&PDB_MOD_MOD_MASK) /*!< PDB0_MOD                                */
/* ------- CNT Bit Fields                           ------ */
#define PDB_CNT_CNT_MASK                         (0xFFFFUL << PDB_CNT_CNT_SHIFT)                     /*!< PDB0_CNT: CNT Mask                      */
#define PDB_CNT_CNT_SHIFT                        0                                                   /*!< PDB0_CNT: CNT Position                  */
#define PDB_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_CNT_CNT_SHIFT))&PDB_CNT_CNT_MASK) /*!< PDB0_CNT                                */
/* ------- IDLY Bit Fields                          ------ */
#define PDB_IDLY_IDLY_MASK                       (0xFFFFUL << PDB_IDLY_IDLY_SHIFT)                   /*!< PDB0_IDLY: IDLY Mask                    */
#define PDB_IDLY_IDLY_SHIFT                      0                                                   /*!< PDB0_IDLY: IDLY Position                */
#define PDB_IDLY_IDLY(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_IDLY_IDLY_SHIFT))&PDB_IDLY_IDLY_MASK) /*!< PDB0_IDLY                               */
/* ------- C1 Bit Fields                            ------ */
#define PDB_C1_EN_MASK                           (0xFFUL << PDB_C1_EN_SHIFT)                         /*!< PDB0_C1: EN Mask                        */
#define PDB_C1_EN_SHIFT                          0                                                   /*!< PDB0_C1: EN Position                    */
#define PDB_C1_EN(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_C1_EN_SHIFT))&PDB_C1_EN_MASK) /*!< PDB0_C1                                 */
#define PDB_C1_TOS_MASK                          (0xFFUL << PDB_C1_TOS_SHIFT)                        /*!< PDB0_C1: TOS Mask                       */
#define PDB_C1_TOS_SHIFT                         8                                                   /*!< PDB0_C1: TOS Position                   */
#define PDB_C1_TOS(x)                            (((uint32_t)(((uint32_t)(x))<<PDB_C1_TOS_SHIFT))&PDB_C1_TOS_MASK) /*!< PDB0_C1                                 */
#define PDB_C1_BB_MASK                           (0xFFUL << PDB_C1_BB_SHIFT)                         /*!< PDB0_C1: BB Mask                        */
#define PDB_C1_BB_SHIFT                          16                                                  /*!< PDB0_C1: BB Position                    */
#define PDB_C1_BB(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_C1_BB_SHIFT))&PDB_C1_BB_MASK) /*!< PDB0_C1                                 */
/* ------- S Bit Fields                             ------ */
#define PDB_S_ERR_MASK                           (0xFFUL << PDB_S_ERR_SHIFT)                         /*!< PDB0_S: ERR Mask                        */
#define PDB_S_ERR_SHIFT                          0                                                   /*!< PDB0_S: ERR Position                    */
#define PDB_S_ERR(x)                             (((uint32_t)(((uint32_t)(x))<<PDB_S_ERR_SHIFT))&PDB_S_ERR_MASK) /*!< PDB0_S                                  */
#define PDB_S_CF_MASK                            (0xFFUL << PDB_S_CF_SHIFT)                          /*!< PDB0_S: CF Mask                         */
#define PDB_S_CF_SHIFT                           16                                                  /*!< PDB0_S: CF Position                     */
#define PDB_S_CF(x)                              (((uint32_t)(((uint32_t)(x))<<PDB_S_CF_SHIFT))&PDB_S_CF_MASK) /*!< PDB0_S                                  */
/* ------- DLY Bit Fields                           ------ */
#define PDB_DLY_DLY_MASK                         (0xFFFFUL << PDB_DLY_DLY_SHIFT)                     /*!< PDB0_DLY: DLY Mask                      */
#define PDB_DLY_DLY_SHIFT                        0                                                   /*!< PDB0_DLY: DLY Position                  */
#define PDB_DLY_DLY(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_DLY_DLY_SHIFT))&PDB_DLY_DLY_MASK) /*!< PDB0_DLY                                */
/* ------- INTC Bit Fields                          ------ */
#define PDB_INTC_TOE_MASK                        (0x01UL << PDB_INTC_TOE_SHIFT)                      /*!< PDB0_INTC: TOE Mask                     */
#define PDB_INTC_TOE_SHIFT                       0                                                   /*!< PDB0_INTC: TOE Position                 */
#define PDB_INTC_TOE(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_INTC_TOE_SHIFT))&PDB_INTC_TOE_MASK) /*!< PDB0_INTC                               */
#define PDB_INTC_EXT_MASK                        (0x01UL << PDB_INTC_EXT_SHIFT)                      /*!< PDB0_INTC: EXT Mask                     */
#define PDB_INTC_EXT_SHIFT                       1                                                   /*!< PDB0_INTC: EXT Position                 */
#define PDB_INTC_EXT(x)                          (((uint32_t)(((uint32_t)(x))<<PDB_INTC_EXT_SHIFT))&PDB_INTC_EXT_MASK) /*!< PDB0_INTC                               */
/* ------- INT Bit Fields                           ------ */
#define PDB_INT_INT_MASK                         (0xFFFFUL << PDB_INT_INT_SHIFT)                     /*!< PDB0_INT: INT Mask                      */
#define PDB_INT_INT_SHIFT                        0                                                   /*!< PDB0_INT: INT Position                  */
#define PDB_INT_INT(x)                           (((uint32_t)(((uint32_t)(x))<<PDB_INT_INT_SHIFT))&PDB_INT_INT_MASK) /*!< PDB0_INT                                */
/* ------- POEN Bit Fields                          ------ */
#define PDB_POEN_POEN_MASK                       (0xFFUL << PDB_POEN_POEN_SHIFT)                     /*!< PDB0_POEN: POEN Mask                    */
#define PDB_POEN_POEN_SHIFT                      0                                                   /*!< PDB0_POEN: POEN Position                */
#define PDB_POEN_POEN(x)                         (((uint32_t)(((uint32_t)(x))<<PDB_POEN_POEN_SHIFT))&PDB_POEN_POEN_MASK) /*!< PDB0_POEN                               */
/* ------- PODLY Bit Fields                         ------ */
#define PDB_PODLY_DLY2_MASK                      (0xFFFFUL << PDB_PODLY_DLY2_SHIFT)                  /*!< PDB0_PODLY: DLY2 Mask                   */
#define PDB_PODLY_DLY2_SHIFT                     0                                                   /*!< PDB0_PODLY: DLY2 Position               */
#define PDB_PODLY_DLY2(x)                        (((uint32_t)(((uint32_t)(x))<<PDB_PODLY_DLY2_SHIFT))&PDB_PODLY_DLY2_MASK) /*!< PDB0_PODLY                              */
#define PDB_PODLY_DLY1_MASK                      (0xFFFFUL << PDB_PODLY_DLY1_SHIFT)                  /*!< PDB0_PODLY: DLY1 Mask                   */
#define PDB_PODLY_DLY1_SHIFT                     16                                                  /*!< PDB0_PODLY: DLY1 Position               */
#define PDB_PODLY_DLY1(x)                        (((uint32_t)(((uint32_t)(x))<<PDB_PODLY_DLY1_SHIFT))&PDB_PODLY_DLY1_MASK) /*!< PDB0_PODLY                              */
/**
 * @} */ /* End group PDB_Register_Masks_GROUP 
 */

/* PDB0 - Peripheral instance base addresses */
#define PDB0_BasePtr                   0x40036000UL //!< Peripheral base address
#define PDB0                           ((PDB_Type *) PDB0_BasePtr) //!< Freescale base pointer
#define PDB0_BASE_PTR                  (PDB0) //!< Freescale style base pointer
/**
 * @} */ /* End group PDB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PIT_Peripheral_access_layer_GROUP PIT Peripheral Access Layer
* @brief C Struct for PIT
* @{
*/

/* ================================================================================ */
/* ================           PIT (file:PIT_4CH)                   ================ */
/* ================================================================================ */

/**
 * @brief Periodic Interrupt Timer (4 channels)
 */
/**
* @addtogroup PIT_structs_GROUP PIT struct
* @brief Struct for PIT
* @{
*/
typedef struct {                                /*       PIT Structure                                                */
   __IO uint32_t  MCR;                          /**< 0000: Module Control Register                                      */
   __I  uint32_t  RESERVED0[63];               
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
/* -----------     'PIT' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PIT_Register_Masks_GROUP PIT Register Masks
* @brief Register Masks for PIT
* @{
*/
/* ------- MCR Bit Fields                           ------ */
#define PIT_MCR_FRZ_MASK                         (0x01UL << PIT_MCR_FRZ_SHIFT)                       /*!< PIT_MCR: FRZ Mask                       */
#define PIT_MCR_FRZ_SHIFT                        0                                                   /*!< PIT_MCR: FRZ Position                   */
#define PIT_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x))<<PIT_MCR_FRZ_SHIFT))&PIT_MCR_FRZ_MASK) /*!< PIT_MCR                                 */
#define PIT_MCR_MDIS_MASK                        (0x01UL << PIT_MCR_MDIS_SHIFT)                      /*!< PIT_MCR: MDIS Mask                      */
#define PIT_MCR_MDIS_SHIFT                       1                                                   /*!< PIT_MCR: MDIS Position                  */
#define PIT_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_MCR_MDIS_SHIFT))&PIT_MCR_MDIS_MASK) /*!< PIT_MCR                                 */
/* ------- LDVAL Bit Fields                         ------ */
#define PIT_LDVAL_TSV_MASK                       (0xFFFFFFFFUL << PIT_LDVAL_TSV_SHIFT)               /*!< PIT_LDVAL: TSV Mask                     */
#define PIT_LDVAL_TSV_SHIFT                      0                                                   /*!< PIT_LDVAL: TSV Position                 */
#define PIT_LDVAL_TSV(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_LDVAL_TSV_SHIFT))&PIT_LDVAL_TSV_MASK) /*!< PIT_LDVAL                               */
/* ------- CVAL Bit Fields                          ------ */
#define PIT_CVAL_TVL_MASK                        (0xFFFFFFFFUL << PIT_CVAL_TVL_SHIFT)                /*!< PIT_CVAL: TVL Mask                      */
#define PIT_CVAL_TVL_SHIFT                       0                                                   /*!< PIT_CVAL: TVL Position                  */
#define PIT_CVAL_TVL(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_CVAL_TVL_SHIFT))&PIT_CVAL_TVL_MASK) /*!< PIT_CVAL                                */
/* ------- TCTRL Bit Fields                         ------ */
#define PIT_TCTRL_TEN_MASK                       (0x01UL << PIT_TCTRL_TEN_SHIFT)                     /*!< PIT_TCTRL: TEN Mask                     */
#define PIT_TCTRL_TEN_SHIFT                      0                                                   /*!< PIT_TCTRL: TEN Position                 */
#define PIT_TCTRL_TEN(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_TCTRL_TEN_SHIFT))&PIT_TCTRL_TEN_MASK) /*!< PIT_TCTRL                               */
#define PIT_TCTRL_TIE_MASK                       (0x01UL << PIT_TCTRL_TIE_SHIFT)                     /*!< PIT_TCTRL: TIE Mask                     */
#define PIT_TCTRL_TIE_SHIFT                      1                                                   /*!< PIT_TCTRL: TIE Position                 */
#define PIT_TCTRL_TIE(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_TCTRL_TIE_SHIFT))&PIT_TCTRL_TIE_MASK) /*!< PIT_TCTRL                               */
/* ------- TFLG Bit Fields                          ------ */
#define PIT_TFLG_TIF_MASK                        (0x01UL << PIT_TFLG_TIF_SHIFT)                      /*!< PIT_TFLG: TIF Mask                      */
#define PIT_TFLG_TIF_SHIFT                       0                                                   /*!< PIT_TFLG: TIF Position                  */
#define PIT_TFLG_TIF(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_TFLG_TIF_SHIFT))&PIT_TFLG_TIF_MASK) /*!< PIT_TFLG                                */
/**
 * @} */ /* End group PIT_Register_Masks_GROUP 
 */

/* PIT - Peripheral instance base addresses */
#define PIT_BasePtr                    0x40037000UL //!< Peripheral base address
#define PIT                            ((PIT_Type *) PIT_BasePtr) //!< Freescale base pointer
#define PIT_BASE_PTR                   (PIT) //!< Freescale style base pointer
/**
 * @} */ /* End group PIT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PMC_Peripheral_access_layer_GROUP PMC Peripheral Access Layer
* @brief C Struct for PMC
* @{
*/

/* ================================================================================ */
/* ================           PMC (file:PMC_MK)                    ================ */
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
   __IO uint8_t   LVDSC1;                       /**< 0000: Low Voltage Status and Control 1                             */
   __IO uint8_t   LVDSC2;                       /**< 0001: Low Voltage Status and Control 2                             */
   __IO uint8_t   REGSC;                        /**< 0002: Regulator Status and Control                                 */
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
#define PMC_LVDSC1_LVDV_MASK                     (0x03UL << PMC_LVDSC1_LVDV_SHIFT)                   /*!< PMC_LVDSC1: LVDV Mask                   */
#define PMC_LVDSC1_LVDV_SHIFT                    0                                                   /*!< PMC_LVDSC1: LVDV Position               */
#define PMC_LVDSC1_LVDV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDV_SHIFT))&PMC_LVDSC1_LVDV_MASK) /*!< PMC_LVDSC1                              */
#define PMC_LVDSC1_LVDRE_MASK                    (0x01UL << PMC_LVDSC1_LVDRE_SHIFT)                  /*!< PMC_LVDSC1: LVDRE Mask                  */
#define PMC_LVDSC1_LVDRE_SHIFT                   4                                                   /*!< PMC_LVDSC1: LVDRE Position              */
#define PMC_LVDSC1_LVDRE(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDRE_SHIFT))&PMC_LVDSC1_LVDRE_MASK) /*!< PMC_LVDSC1                              */
#define PMC_LVDSC1_LVDIE_MASK                    (0x01UL << PMC_LVDSC1_LVDIE_SHIFT)                  /*!< PMC_LVDSC1: LVDIE Mask                  */
#define PMC_LVDSC1_LVDIE_SHIFT                   5                                                   /*!< PMC_LVDSC1: LVDIE Position              */
#define PMC_LVDSC1_LVDIE(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDIE_SHIFT))&PMC_LVDSC1_LVDIE_MASK) /*!< PMC_LVDSC1                              */
#define PMC_LVDSC1_LVDACK_MASK                   (0x01UL << PMC_LVDSC1_LVDACK_SHIFT)                 /*!< PMC_LVDSC1: LVDACK Mask                 */
#define PMC_LVDSC1_LVDACK_SHIFT                  6                                                   /*!< PMC_LVDSC1: LVDACK Position             */
#define PMC_LVDSC1_LVDACK(x)                     (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDACK_SHIFT))&PMC_LVDSC1_LVDACK_MASK) /*!< PMC_LVDSC1                              */
#define PMC_LVDSC1_LVDF_MASK                     (0x01UL << PMC_LVDSC1_LVDF_SHIFT)                   /*!< PMC_LVDSC1: LVDF Mask                   */
#define PMC_LVDSC1_LVDF_SHIFT                    7                                                   /*!< PMC_LVDSC1: LVDF Position               */
#define PMC_LVDSC1_LVDF(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDF_SHIFT))&PMC_LVDSC1_LVDF_MASK) /*!< PMC_LVDSC1                              */
/* ------- LVDSC2 Bit Fields                        ------ */
#define PMC_LVDSC2_LVWV_MASK                     (0x03UL << PMC_LVDSC2_LVWV_SHIFT)                   /*!< PMC_LVDSC2: LVWV Mask                   */
#define PMC_LVDSC2_LVWV_SHIFT                    0                                                   /*!< PMC_LVDSC2: LVWV Position               */
#define PMC_LVDSC2_LVWV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWV_SHIFT))&PMC_LVDSC2_LVWV_MASK) /*!< PMC_LVDSC2                              */
#define PMC_LVDSC2_LVWIE_MASK                    (0x01UL << PMC_LVDSC2_LVWIE_SHIFT)                  /*!< PMC_LVDSC2: LVWIE Mask                  */
#define PMC_LVDSC2_LVWIE_SHIFT                   5                                                   /*!< PMC_LVDSC2: LVWIE Position              */
#define PMC_LVDSC2_LVWIE(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWIE_SHIFT))&PMC_LVDSC2_LVWIE_MASK) /*!< PMC_LVDSC2                              */
#define PMC_LVDSC2_LVWACK_MASK                   (0x01UL << PMC_LVDSC2_LVWACK_SHIFT)                 /*!< PMC_LVDSC2: LVWACK Mask                 */
#define PMC_LVDSC2_LVWACK_SHIFT                  6                                                   /*!< PMC_LVDSC2: LVWACK Position             */
#define PMC_LVDSC2_LVWACK(x)                     (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWACK_SHIFT))&PMC_LVDSC2_LVWACK_MASK) /*!< PMC_LVDSC2                              */
#define PMC_LVDSC2_LVWF_MASK                     (0x01UL << PMC_LVDSC2_LVWF_SHIFT)                   /*!< PMC_LVDSC2: LVWF Mask                   */
#define PMC_LVDSC2_LVWF_SHIFT                    7                                                   /*!< PMC_LVDSC2: LVWF Position               */
#define PMC_LVDSC2_LVWF(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWF_SHIFT))&PMC_LVDSC2_LVWF_MASK) /*!< PMC_LVDSC2                              */
/* ------- REGSC Bit Fields                         ------ */
#define PMC_REGSC_BGBE_MASK                      (0x01UL << PMC_REGSC_BGBE_SHIFT)                    /*!< PMC_REGSC: BGBE Mask                    */
#define PMC_REGSC_BGBE_SHIFT                     0                                                   /*!< PMC_REGSC: BGBE Position                */
#define PMC_REGSC_BGBE(x)                        (((uint8_t)(((uint8_t)(x))<<PMC_REGSC_BGBE_SHIFT))&PMC_REGSC_BGBE_MASK) /*!< PMC_REGSC                               */
#define PMC_REGSC_REGONS_MASK                    (0x01UL << PMC_REGSC_REGONS_SHIFT)                  /*!< PMC_REGSC: REGONS Mask                  */
#define PMC_REGSC_REGONS_SHIFT                   2                                                   /*!< PMC_REGSC: REGONS Position              */
#define PMC_REGSC_REGONS(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_REGSC_REGONS_SHIFT))&PMC_REGSC_REGONS_MASK) /*!< PMC_REGSC                               */
#define PMC_REGSC_ACKISO_MASK                    (0x01UL << PMC_REGSC_ACKISO_SHIFT)                  /*!< PMC_REGSC: ACKISO Mask                  */
#define PMC_REGSC_ACKISO_SHIFT                   3                                                   /*!< PMC_REGSC: ACKISO Position              */
#define PMC_REGSC_ACKISO(x)                      (((uint8_t)(((uint8_t)(x))<<PMC_REGSC_ACKISO_SHIFT))&PMC_REGSC_ACKISO_MASK) /*!< PMC_REGSC                               */
#define PMC_REGSC_BGEN_MASK                      (0x01UL << PMC_REGSC_BGEN_SHIFT)                    /*!< PMC_REGSC: BGEN Mask                    */
#define PMC_REGSC_BGEN_SHIFT                     4                                                   /*!< PMC_REGSC: BGEN Position                */
#define PMC_REGSC_BGEN(x)                        (((uint8_t)(((uint8_t)(x))<<PMC_REGSC_BGEN_SHIFT))&PMC_REGSC_BGEN_MASK) /*!< PMC_REGSC                               */
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
/* ================           PORTA (file:PORTA_FILT)              ================ */
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
   __I  uint32_t  RESERVED0[6];                
   __IO uint32_t  ISFR;                         /**< 00A0: Interrupt Status Flag Register                               */
   __I  uint32_t  RESERVED1[7];                
   __IO uint32_t  DFER;                         /**< 00C0: Digital Filter Enable Register                               */
   __IO uint32_t  DFCR;                         /**< 00C4: Digital Filter Clock Register                                */
   __IO uint32_t  DFWR;                         /**< 00C8: Digital Filter Width Register                                */
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
#define PORT_PCR_PS_MASK                         (0x01UL << PORT_PCR_PS_SHIFT)                       /*!< PORTA_PCR: PS Mask                      */
#define PORT_PCR_PS_SHIFT                        0                                                   /*!< PORTA_PCR: PS Position                  */
#define PORT_PCR_PS(x)                           (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PS_SHIFT))&PORT_PCR_PS_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_PE_MASK                         (0x01UL << PORT_PCR_PE_SHIFT)                       /*!< PORTA_PCR: PE Mask                      */
#define PORT_PCR_PE_SHIFT                        1                                                   /*!< PORTA_PCR: PE Position                  */
#define PORT_PCR_PE(x)                           (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PE_SHIFT))&PORT_PCR_PE_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_SRE_MASK                        (0x01UL << PORT_PCR_SRE_SHIFT)                      /*!< PORTA_PCR: SRE Mask                     */
#define PORT_PCR_SRE_SHIFT                       2                                                   /*!< PORTA_PCR: SRE Position                 */
#define PORT_PCR_SRE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_SRE_SHIFT))&PORT_PCR_SRE_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_PFE_MASK                        (0x01UL << PORT_PCR_PFE_SHIFT)                      /*!< PORTA_PCR: PFE Mask                     */
#define PORT_PCR_PFE_SHIFT                       4                                                   /*!< PORTA_PCR: PFE Position                 */
#define PORT_PCR_PFE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PFE_SHIFT))&PORT_PCR_PFE_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_ODE_MASK                        (0x01UL << PORT_PCR_ODE_SHIFT)                      /*!< PORTA_PCR: ODE Mask                     */
#define PORT_PCR_ODE_SHIFT                       5                                                   /*!< PORTA_PCR: ODE Position                 */
#define PORT_PCR_ODE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_ODE_SHIFT))&PORT_PCR_ODE_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_DSE_MASK                        (0x01UL << PORT_PCR_DSE_SHIFT)                      /*!< PORTA_PCR: DSE Mask                     */
#define PORT_PCR_DSE_SHIFT                       6                                                   /*!< PORTA_PCR: DSE Position                 */
#define PORT_PCR_DSE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_DSE_SHIFT))&PORT_PCR_DSE_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_MUX_MASK                        (0x07UL << PORT_PCR_MUX_SHIFT)                      /*!< PORTA_PCR: MUX Mask                     */
#define PORT_PCR_MUX_SHIFT                       8                                                   /*!< PORTA_PCR: MUX Position                 */
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_MUX_SHIFT))&PORT_PCR_MUX_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_LK_MASK                         (0x01UL << PORT_PCR_LK_SHIFT)                       /*!< PORTA_PCR: LK Mask                      */
#define PORT_PCR_LK_SHIFT                        15                                                  /*!< PORTA_PCR: LK Position                  */
#define PORT_PCR_LK(x)                           (((uint32_t)(((uint32_t)(x))<<PORT_PCR_LK_SHIFT))&PORT_PCR_LK_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_IRQC_MASK                       (0x0FUL << PORT_PCR_IRQC_SHIFT)                     /*!< PORTA_PCR: IRQC Mask                    */
#define PORT_PCR_IRQC_SHIFT                      16                                                  /*!< PORTA_PCR: IRQC Position                */
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_PCR_IRQC_SHIFT))&PORT_PCR_IRQC_MASK) /*!< PORTA_PCR                               */
#define PORT_PCR_ISF_MASK                        (0x01UL << PORT_PCR_ISF_SHIFT)                      /*!< PORTA_PCR: ISF Mask                     */
#define PORT_PCR_ISF_SHIFT                       24                                                  /*!< PORTA_PCR: ISF Position                 */
#define PORT_PCR_ISF(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_ISF_SHIFT))&PORT_PCR_ISF_MASK) /*!< PORTA_PCR                               */
/* ------- GPCLR Bit Fields                         ------ */
#define PORT_GPCLR_GPWD_MASK                     (0xFFFFUL << PORT_GPCLR_GPWD_SHIFT)                 /*!< PORTA_GPCLR: GPWD Mask                  */
#define PORT_GPCLR_GPWD_SHIFT                    0                                                   /*!< PORTA_GPCLR: GPWD Position              */
#define PORT_GPCLR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWD_SHIFT))&PORT_GPCLR_GPWD_MASK) /*!< PORTA_GPCLR                             */
#define PORT_GPCLR_GPWE_MASK                     (0xFFFFUL << PORT_GPCLR_GPWE_SHIFT)                 /*!< PORTA_GPCLR: GPWE Mask                  */
#define PORT_GPCLR_GPWE_SHIFT                    16                                                  /*!< PORTA_GPCLR: GPWE Position              */
#define PORT_GPCLR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWE_SHIFT))&PORT_GPCLR_GPWE_MASK) /*!< PORTA_GPCLR                             */
/* ------- GPCHR Bit Fields                         ------ */
#define PORT_GPCHR_GPWD_MASK                     (0xFFFFUL << PORT_GPCHR_GPWD_SHIFT)                 /*!< PORTA_GPCHR: GPWD Mask                  */
#define PORT_GPCHR_GPWD_SHIFT                    0                                                   /*!< PORTA_GPCHR: GPWD Position              */
#define PORT_GPCHR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWD_SHIFT))&PORT_GPCHR_GPWD_MASK) /*!< PORTA_GPCHR                             */
#define PORT_GPCHR_GPWE_MASK                     (0xFFFFUL << PORT_GPCHR_GPWE_SHIFT)                 /*!< PORTA_GPCHR: GPWE Mask                  */
#define PORT_GPCHR_GPWE_SHIFT                    16                                                  /*!< PORTA_GPCHR: GPWE Position              */
#define PORT_GPCHR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWE_SHIFT))&PORT_GPCHR_GPWE_MASK) /*!< PORTA_GPCHR                             */
/* ------- ISFR Bit Fields                          ------ */
/* ------- DFER Bit Fields                          ------ */
/* ------- DFCR Bit Fields                          ------ */
#define PORT_DFCR_CS_MASK                        (0x01UL << PORT_DFCR_CS_SHIFT)                      /*!< PORTA_DFCR: CS Mask                     */
#define PORT_DFCR_CS_SHIFT                       0                                                   /*!< PORTA_DFCR: CS Position                 */
#define PORT_DFCR_CS(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_DFCR_CS_SHIFT))&PORT_DFCR_CS_MASK) /*!< PORTA_DFCR                              */
/* ------- DFWR Bit Fields                          ------ */
#define PORT_DFWR_FILT_MASK                      (0x1FUL << PORT_DFWR_FILT_SHIFT)                    /*!< PORTA_DFWR: FILT Mask                   */
#define PORT_DFWR_FILT_SHIFT                     0                                                   /*!< PORTA_DFWR: FILT Position               */
#define PORT_DFWR_FILT(x)                        (((uint32_t)(((uint32_t)(x))<<PORT_DFWR_FILT_SHIFT))&PORT_DFWR_FILT_MASK) /*!< PORTA_DFWR                              */
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
* @addtogroup RCM_Peripheral_access_layer_GROUP RCM Peripheral Access Layer
* @brief C Struct for RCM
* @{
*/

/* ================================================================================ */
/* ================           RCM (file:RCM_MK10D5)                ================ */
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
   __I  uint16_t  RESERVED0;                   
   __IO uint8_t   RPFC;                         /**< 0004: Reset Pin Filter Control Register                            */
   __IO uint8_t   RPFW;                         /**< 0005: Reset Pin Filter Width Register                              */
   __I  uint8_t   RESERVED1;                   
   __I  uint8_t   MR;                           /**< 0007: Mode Register                                                */
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
#define RCM_SRS0_WAKEUP_MASK                     (0x01UL << RCM_SRS0_WAKEUP_SHIFT)                   /*!< RCM_SRS0: WAKEUP Mask                   */
#define RCM_SRS0_WAKEUP_SHIFT                    0                                                   /*!< RCM_SRS0: WAKEUP Position               */
#define RCM_SRS0_WAKEUP(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_WAKEUP_SHIFT))&RCM_SRS0_WAKEUP_MASK) /*!< RCM_SRS0                                */
#define RCM_SRS0_LVD_MASK                        (0x01UL << RCM_SRS0_LVD_SHIFT)                      /*!< RCM_SRS0: LVD Mask                      */
#define RCM_SRS0_LVD_SHIFT                       1                                                   /*!< RCM_SRS0: LVD Position                  */
#define RCM_SRS0_LVD(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_LVD_SHIFT))&RCM_SRS0_LVD_MASK) /*!< RCM_SRS0                                */
#define RCM_SRS0_LOC_MASK                        (0x01UL << RCM_SRS0_LOC_SHIFT)                      /*!< RCM_SRS0: LOC Mask                      */
#define RCM_SRS0_LOC_SHIFT                       2                                                   /*!< RCM_SRS0: LOC Position                  */
#define RCM_SRS0_LOC(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_LOC_SHIFT))&RCM_SRS0_LOC_MASK) /*!< RCM_SRS0                                */
#define RCM_SRS0_LOL_MASK                        (0x01UL << RCM_SRS0_LOL_SHIFT)                      /*!< RCM_SRS0: LOL Mask                      */
#define RCM_SRS0_LOL_SHIFT                       3                                                   /*!< RCM_SRS0: LOL Position                  */
#define RCM_SRS0_LOL(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_LOL_SHIFT))&RCM_SRS0_LOL_MASK) /*!< RCM_SRS0                                */
#define RCM_SRS0_WDOG_MASK                       (0x01UL << RCM_SRS0_WDOG_SHIFT)                     /*!< RCM_SRS0: WDOG Mask                     */
#define RCM_SRS0_WDOG_SHIFT                      5                                                   /*!< RCM_SRS0: WDOG Position                 */
#define RCM_SRS0_WDOG(x)                         (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_WDOG_SHIFT))&RCM_SRS0_WDOG_MASK) /*!< RCM_SRS0                                */
#define RCM_SRS0_PIN_MASK                        (0x01UL << RCM_SRS0_PIN_SHIFT)                      /*!< RCM_SRS0: PIN Mask                      */
#define RCM_SRS0_PIN_SHIFT                       6                                                   /*!< RCM_SRS0: PIN Position                  */
#define RCM_SRS0_PIN(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_PIN_SHIFT))&RCM_SRS0_PIN_MASK) /*!< RCM_SRS0                                */
#define RCM_SRS0_POR_MASK                        (0x01UL << RCM_SRS0_POR_SHIFT)                      /*!< RCM_SRS0: POR Mask                      */
#define RCM_SRS0_POR_SHIFT                       7                                                   /*!< RCM_SRS0: POR Position                  */
#define RCM_SRS0_POR(x)                          (((uint8_t)(((uint8_t)(x))<<RCM_SRS0_POR_SHIFT))&RCM_SRS0_POR_MASK) /*!< RCM_SRS0                                */
/* ------- SRS1 Bit Fields                          ------ */
#define RCM_SRS1_JTAG_MASK                       (0x01UL << RCM_SRS1_JTAG_SHIFT)                     /*!< RCM_SRS1: JTAG Mask                     */
#define RCM_SRS1_JTAG_SHIFT                      0                                                   /*!< RCM_SRS1: JTAG Position                 */
#define RCM_SRS1_JTAG(x)                         (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_JTAG_SHIFT))&RCM_SRS1_JTAG_MASK) /*!< RCM_SRS1                                */
#define RCM_SRS1_LOCKUP_MASK                     (0x01UL << RCM_SRS1_LOCKUP_SHIFT)                   /*!< RCM_SRS1: LOCKUP Mask                   */
#define RCM_SRS1_LOCKUP_SHIFT                    1                                                   /*!< RCM_SRS1: LOCKUP Position               */
#define RCM_SRS1_LOCKUP(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_LOCKUP_SHIFT))&RCM_SRS1_LOCKUP_MASK) /*!< RCM_SRS1                                */
#define RCM_SRS1_SW_MASK                         (0x01UL << RCM_SRS1_SW_SHIFT)                       /*!< RCM_SRS1: SW Mask                       */
#define RCM_SRS1_SW_SHIFT                        2                                                   /*!< RCM_SRS1: SW Position                   */
#define RCM_SRS1_SW(x)                           (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_SW_SHIFT))&RCM_SRS1_SW_MASK) /*!< RCM_SRS1                                */
#define RCM_SRS1_MDM_AP_MASK                     (0x01UL << RCM_SRS1_MDM_AP_SHIFT)                   /*!< RCM_SRS1: MDM_AP Mask                   */
#define RCM_SRS1_MDM_AP_SHIFT                    3                                                   /*!< RCM_SRS1: MDM_AP Position               */
#define RCM_SRS1_MDM_AP(x)                       (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_MDM_AP_SHIFT))&RCM_SRS1_MDM_AP_MASK) /*!< RCM_SRS1                                */
#define RCM_SRS1_EZPT_MASK                       (0x01UL << RCM_SRS1_EZPT_SHIFT)                     /*!< RCM_SRS1: EZPT Mask                     */
#define RCM_SRS1_EZPT_SHIFT                      4                                                   /*!< RCM_SRS1: EZPT Position                 */
#define RCM_SRS1_EZPT(x)                         (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_EZPT_SHIFT))&RCM_SRS1_EZPT_MASK) /*!< RCM_SRS1                                */
#define RCM_SRS1_SACKERR_MASK                    (0x01UL << RCM_SRS1_SACKERR_SHIFT)                  /*!< RCM_SRS1: SACKERR Mask                  */
#define RCM_SRS1_SACKERR_SHIFT                   5                                                   /*!< RCM_SRS1: SACKERR Position              */
#define RCM_SRS1_SACKERR(x)                      (((uint8_t)(((uint8_t)(x))<<RCM_SRS1_SACKERR_SHIFT))&RCM_SRS1_SACKERR_MASK) /*!< RCM_SRS1                                */
/* ------- RPFC Bit Fields                          ------ */
#define RCM_RPFC_RSTFLTSRW_MASK                  (0x03UL << RCM_RPFC_RSTFLTSRW_SHIFT)                /*!< RCM_RPFC: RSTFLTSRW Mask                */
#define RCM_RPFC_RSTFLTSRW_SHIFT                 0                                                   /*!< RCM_RPFC: RSTFLTSRW Position            */
#define RCM_RPFC_RSTFLTSRW(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFC_RSTFLTSRW_SHIFT))&RCM_RPFC_RSTFLTSRW_MASK) /*!< RCM_RPFC                                */
#define RCM_RPFC_RSTFLTSS_MASK                   (0x01UL << RCM_RPFC_RSTFLTSS_SHIFT)                 /*!< RCM_RPFC: RSTFLTSS Mask                 */
#define RCM_RPFC_RSTFLTSS_SHIFT                  2                                                   /*!< RCM_RPFC: RSTFLTSS Position             */
#define RCM_RPFC_RSTFLTSS(x)                     (((uint8_t)(((uint8_t)(x))<<RCM_RPFC_RSTFLTSS_SHIFT))&RCM_RPFC_RSTFLTSS_MASK) /*!< RCM_RPFC                                */
/* ------- RPFW Bit Fields                          ------ */
#define RCM_RPFW_RSTFLTSEL_MASK                  (0x1FUL << RCM_RPFW_RSTFLTSEL_SHIFT)                /*!< RCM_RPFW: RSTFLTSEL Mask                */
#define RCM_RPFW_RSTFLTSEL_SHIFT                 0                                                   /*!< RCM_RPFW: RSTFLTSEL Position            */
#define RCM_RPFW_RSTFLTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<RCM_RPFW_RSTFLTSEL_SHIFT))&RCM_RPFW_RSTFLTSEL_MASK) /*!< RCM_RPFW                                */
/* ------- MR Bit Fields                            ------ */
#define RCM_MR_EZP_MS_MASK                       (0x01UL << RCM_MR_EZP_MS_SHIFT)                     /*!< RCM_MR: EZP_MS Mask                     */
#define RCM_MR_EZP_MS_SHIFT                      1                                                   /*!< RCM_MR: EZP_MS Position                 */
#define RCM_MR_EZP_MS(x)                         (((uint8_t)(((uint8_t)(x))<<RCM_MR_EZP_MS_SHIFT))&RCM_MR_EZP_MS_MASK) /*!< RCM_MR                                  */
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
/* ================           RFSYS (file:RFSYS_0)                 ================ */
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
#define RFSYS_REG_LL_MASK                        (0xFFUL << RFSYS_REG_LL_SHIFT)                      /*!< RFSYS_REG: LL Mask                      */
#define RFSYS_REG_LL_SHIFT                       0                                                   /*!< RFSYS_REG: LL Position                  */
#define RFSYS_REG_LL(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_LL_SHIFT))&RFSYS_REG_LL_MASK) /*!< RFSYS_REG                               */
#define RFSYS_REG_LH_MASK                        (0xFFUL << RFSYS_REG_LH_SHIFT)                      /*!< RFSYS_REG: LH Mask                      */
#define RFSYS_REG_LH_SHIFT                       8                                                   /*!< RFSYS_REG: LH Position                  */
#define RFSYS_REG_LH(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_LH_SHIFT))&RFSYS_REG_LH_MASK) /*!< RFSYS_REG                               */
#define RFSYS_REG_HL_MASK                        (0xFFUL << RFSYS_REG_HL_SHIFT)                      /*!< RFSYS_REG: HL Mask                      */
#define RFSYS_REG_HL_SHIFT                       16                                                  /*!< RFSYS_REG: HL Position                  */
#define RFSYS_REG_HL(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_HL_SHIFT))&RFSYS_REG_HL_MASK) /*!< RFSYS_REG                               */
#define RFSYS_REG_HH_MASK                        (0xFFUL << RFSYS_REG_HH_SHIFT)                      /*!< RFSYS_REG: HH Mask                      */
#define RFSYS_REG_HH_SHIFT                       24                                                  /*!< RFSYS_REG: HH Position                  */
#define RFSYS_REG_HH(x)                          (((uint32_t)(((uint32_t)(x))<<RFSYS_REG_HH_SHIFT))&RFSYS_REG_HH_MASK) /*!< RFSYS_REG                               */
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
/* ================           RFVBAT (file:RFVBAT_0)               ================ */
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
#define RFVBAT_REG_LL_MASK                       (0xFFUL << RFVBAT_REG_LL_SHIFT)                     /*!< RFVBAT_REG: LL Mask                     */
#define RFVBAT_REG_LL_SHIFT                      0                                                   /*!< RFVBAT_REG: LL Position                 */
#define RFVBAT_REG_LL(x)                         (((uint32_t)(((uint32_t)(x))<<RFVBAT_REG_LL_SHIFT))&RFVBAT_REG_LL_MASK) /*!< RFVBAT_REG                              */
#define RFVBAT_REG_LH_MASK                       (0xFFUL << RFVBAT_REG_LH_SHIFT)                     /*!< RFVBAT_REG: LH Mask                     */
#define RFVBAT_REG_LH_SHIFT                      8                                                   /*!< RFVBAT_REG: LH Position                 */
#define RFVBAT_REG_LH(x)                         (((uint32_t)(((uint32_t)(x))<<RFVBAT_REG_LH_SHIFT))&RFVBAT_REG_LH_MASK) /*!< RFVBAT_REG                              */
#define RFVBAT_REG_HL_MASK                       (0xFFUL << RFVBAT_REG_HL_SHIFT)                     /*!< RFVBAT_REG: HL Mask                     */
#define RFVBAT_REG_HL_SHIFT                      16                                                  /*!< RFVBAT_REG: HL Position                 */
#define RFVBAT_REG_HL(x)                         (((uint32_t)(((uint32_t)(x))<<RFVBAT_REG_HL_SHIFT))&RFVBAT_REG_HL_MASK) /*!< RFVBAT_REG                              */
#define RFVBAT_REG_HH_MASK                       (0xFFUL << RFVBAT_REG_HH_SHIFT)                     /*!< RFVBAT_REG: HH Mask                     */
#define RFVBAT_REG_HH_SHIFT                      24                                                  /*!< RFVBAT_REG: HH Position                 */
#define RFVBAT_REG_HH(x)                         (((uint32_t)(((uint32_t)(x))<<RFVBAT_REG_HH_SHIFT))&RFVBAT_REG_HH_MASK) /*!< RFVBAT_REG                              */
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
* @addtogroup RTC_Peripheral_access_layer_GROUP RTC Peripheral Access Layer
* @brief C Struct for RTC
* @{
*/

/* ================================================================================ */
/* ================           RTC (file:RTC_WAR_RAR_TSIE)          ================ */
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
   __I  uint32_t  RESERVED0[504];              
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
#define RTC_TSR_TSR_MASK                         (0xFFFFFFFFUL << RTC_TSR_TSR_SHIFT)                 /*!< RTC_TSR: TSR Mask                       */
#define RTC_TSR_TSR_SHIFT                        0                                                   /*!< RTC_TSR: TSR Position                   */
#define RTC_TSR_TSR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TSR_TSR_SHIFT))&RTC_TSR_TSR_MASK) /*!< RTC_TSR                                 */
/* ------- TPR Bit Fields                           ------ */
#define RTC_TPR_TPR_MASK                         (0xFFFFUL << RTC_TPR_TPR_SHIFT)                     /*!< RTC_TPR: TPR Mask                       */
#define RTC_TPR_TPR_SHIFT                        0                                                   /*!< RTC_TPR: TPR Position                   */
#define RTC_TPR_TPR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TPR_TPR_SHIFT))&RTC_TPR_TPR_MASK) /*!< RTC_TPR                                 */
/* ------- TAR Bit Fields                           ------ */
#define RTC_TAR_TAR_MASK                         (0xFFFFFFFFUL << RTC_TAR_TAR_SHIFT)                 /*!< RTC_TAR: TAR Mask                       */
#define RTC_TAR_TAR_SHIFT                        0                                                   /*!< RTC_TAR: TAR Position                   */
#define RTC_TAR_TAR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TAR_TAR_SHIFT))&RTC_TAR_TAR_MASK) /*!< RTC_TAR                                 */
/* ------- TCR Bit Fields                           ------ */
#define RTC_TCR_TCR_MASK                         (0xFFUL << RTC_TCR_TCR_SHIFT)                       /*!< RTC_TCR: TCR Mask                       */
#define RTC_TCR_TCR_SHIFT                        0                                                   /*!< RTC_TCR: TCR Position                   */
#define RTC_TCR_TCR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_TCR_SHIFT))&RTC_TCR_TCR_MASK) /*!< RTC_TCR                                 */
#define RTC_TCR_CIR_MASK                         (0xFFUL << RTC_TCR_CIR_SHIFT)                       /*!< RTC_TCR: CIR Mask                       */
#define RTC_TCR_CIR_SHIFT                        8                                                   /*!< RTC_TCR: CIR Position                   */
#define RTC_TCR_CIR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_CIR_SHIFT))&RTC_TCR_CIR_MASK) /*!< RTC_TCR                                 */
#define RTC_TCR_TCV_MASK                         (0xFFUL << RTC_TCR_TCV_SHIFT)                       /*!< RTC_TCR: TCV Mask                       */
#define RTC_TCR_TCV_SHIFT                        16                                                  /*!< RTC_TCR: TCV Position                   */
#define RTC_TCR_TCV(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_TCV_SHIFT))&RTC_TCR_TCV_MASK) /*!< RTC_TCR                                 */
#define RTC_TCR_CIC_MASK                         (0xFFUL << RTC_TCR_CIC_SHIFT)                       /*!< RTC_TCR: CIC Mask                       */
#define RTC_TCR_CIC_SHIFT                        24                                                  /*!< RTC_TCR: CIC Position                   */
#define RTC_TCR_CIC(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_TCR_CIC_SHIFT))&RTC_TCR_CIC_MASK) /*!< RTC_TCR                                 */
/* ------- CR Bit Fields                            ------ */
#define RTC_CR_SWR_MASK                          (0x01UL << RTC_CR_SWR_SHIFT)                        /*!< RTC_CR: SWR Mask                        */
#define RTC_CR_SWR_SHIFT                         0                                                   /*!< RTC_CR: SWR Position                    */
#define RTC_CR_SWR(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_SWR_SHIFT))&RTC_CR_SWR_MASK) /*!< RTC_CR                                  */
#define RTC_CR_WPE_MASK                          (0x01UL << RTC_CR_WPE_SHIFT)                        /*!< RTC_CR: WPE Mask                        */
#define RTC_CR_WPE_SHIFT                         1                                                   /*!< RTC_CR: WPE Position                    */
#define RTC_CR_WPE(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_WPE_SHIFT))&RTC_CR_WPE_MASK) /*!< RTC_CR                                  */
#define RTC_CR_SUP_MASK                          (0x01UL << RTC_CR_SUP_SHIFT)                        /*!< RTC_CR: SUP Mask                        */
#define RTC_CR_SUP_SHIFT                         2                                                   /*!< RTC_CR: SUP Position                    */
#define RTC_CR_SUP(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_SUP_SHIFT))&RTC_CR_SUP_MASK) /*!< RTC_CR                                  */
#define RTC_CR_UM_MASK                           (0x01UL << RTC_CR_UM_SHIFT)                         /*!< RTC_CR: UM Mask                         */
#define RTC_CR_UM_SHIFT                          3                                                   /*!< RTC_CR: UM Position                     */
#define RTC_CR_UM(x)                             (((uint32_t)(((uint32_t)(x))<<RTC_CR_UM_SHIFT))&RTC_CR_UM_MASK) /*!< RTC_CR                                  */
#define RTC_CR_OSCE_MASK                         (0x01UL << RTC_CR_OSCE_SHIFT)                       /*!< RTC_CR: OSCE Mask                       */
#define RTC_CR_OSCE_SHIFT                        8                                                   /*!< RTC_CR: OSCE Position                   */
#define RTC_CR_OSCE(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_OSCE_SHIFT))&RTC_CR_OSCE_MASK) /*!< RTC_CR                                  */
#define RTC_CR_CLKO_MASK                         (0x01UL << RTC_CR_CLKO_SHIFT)                       /*!< RTC_CR: CLKO Mask                       */
#define RTC_CR_CLKO_SHIFT                        9                                                   /*!< RTC_CR: CLKO Position                   */
#define RTC_CR_CLKO(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_CLKO_SHIFT))&RTC_CR_CLKO_MASK) /*!< RTC_CR                                  */
#define RTC_CR_SCP_MASK                          (0x0FUL << RTC_CR_SCP_SHIFT)                        /*!< RTC_CR: SCP Mask                        */
#define RTC_CR_SCP_SHIFT                         10                                                  /*!< RTC_CR: SCP Position                    */
#define RTC_CR_SCP(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_CR_SCP_SHIFT))&RTC_CR_SCP_MASK) /*!< RTC_CR                                  */
#define RTC_CR_SC16P_MASK                        (0x01UL << RTC_CR_SC16P_SHIFT)                      /*!< RTC_CR: SC16P Mask                      */
#define RTC_CR_SC16P_SHIFT                       10                                                  /*!< RTC_CR: SC16P Position                  */
#define RTC_CR_SC16P(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC16P_SHIFT))&RTC_CR_SC16P_MASK) /*!< RTC_CR                                  */
#define RTC_CR_SC8P_MASK                         (0x01UL << RTC_CR_SC8P_SHIFT)                       /*!< RTC_CR: SC8P Mask                       */
#define RTC_CR_SC8P_SHIFT                        11                                                  /*!< RTC_CR: SC8P Position                   */
#define RTC_CR_SC8P(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC8P_SHIFT))&RTC_CR_SC8P_MASK) /*!< RTC_CR                                  */
#define RTC_CR_SC4P_MASK                         (0x01UL << RTC_CR_SC4P_SHIFT)                       /*!< RTC_CR: SC4P Mask                       */
#define RTC_CR_SC4P_SHIFT                        12                                                  /*!< RTC_CR: SC4P Position                   */
#define RTC_CR_SC4P(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC4P_SHIFT))&RTC_CR_SC4P_MASK) /*!< RTC_CR                                  */
#define RTC_CR_SC2P_MASK                         (0x01UL << RTC_CR_SC2P_SHIFT)                       /*!< RTC_CR: SC2P Mask                       */
#define RTC_CR_SC2P_SHIFT                        13                                                  /*!< RTC_CR: SC2P Position                   */
#define RTC_CR_SC2P(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CR_SC2P_SHIFT))&RTC_CR_SC2P_MASK) /*!< RTC_CR                                  */
/* ------- SR Bit Fields                            ------ */
#define RTC_SR_TIF_MASK                          (0x01UL << RTC_SR_TIF_SHIFT)                        /*!< RTC_SR: TIF Mask                        */
#define RTC_SR_TIF_SHIFT                         0                                                   /*!< RTC_SR: TIF Position                    */
#define RTC_SR_TIF(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TIF_SHIFT))&RTC_SR_TIF_MASK) /*!< RTC_SR                                  */
#define RTC_SR_TOF_MASK                          (0x01UL << RTC_SR_TOF_SHIFT)                        /*!< RTC_SR: TOF Mask                        */
#define RTC_SR_TOF_SHIFT                         1                                                   /*!< RTC_SR: TOF Position                    */
#define RTC_SR_TOF(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TOF_SHIFT))&RTC_SR_TOF_MASK) /*!< RTC_SR                                  */
#define RTC_SR_TAF_MASK                          (0x01UL << RTC_SR_TAF_SHIFT)                        /*!< RTC_SR: TAF Mask                        */
#define RTC_SR_TAF_SHIFT                         2                                                   /*!< RTC_SR: TAF Position                    */
#define RTC_SR_TAF(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TAF_SHIFT))&RTC_SR_TAF_MASK) /*!< RTC_SR                                  */
#define RTC_SR_TCE_MASK                          (0x01UL << RTC_SR_TCE_SHIFT)                        /*!< RTC_SR: TCE Mask                        */
#define RTC_SR_TCE_SHIFT                         4                                                   /*!< RTC_SR: TCE Position                    */
#define RTC_SR_TCE(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_SR_TCE_SHIFT))&RTC_SR_TCE_MASK) /*!< RTC_SR                                  */
/* ------- LR Bit Fields                            ------ */
#define RTC_LR_TCL_MASK                          (0x01UL << RTC_LR_TCL_SHIFT)                        /*!< RTC_LR: TCL Mask                        */
#define RTC_LR_TCL_SHIFT                         3                                                   /*!< RTC_LR: TCL Position                    */
#define RTC_LR_TCL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_TCL_SHIFT))&RTC_LR_TCL_MASK) /*!< RTC_LR                                  */
#define RTC_LR_CRL_MASK                          (0x01UL << RTC_LR_CRL_SHIFT)                        /*!< RTC_LR: CRL Mask                        */
#define RTC_LR_CRL_SHIFT                         4                                                   /*!< RTC_LR: CRL Position                    */
#define RTC_LR_CRL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_CRL_SHIFT))&RTC_LR_CRL_MASK) /*!< RTC_LR                                  */
#define RTC_LR_SRL_MASK                          (0x01UL << RTC_LR_SRL_SHIFT)                        /*!< RTC_LR: SRL Mask                        */
#define RTC_LR_SRL_SHIFT                         5                                                   /*!< RTC_LR: SRL Position                    */
#define RTC_LR_SRL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_SRL_SHIFT))&RTC_LR_SRL_MASK) /*!< RTC_LR                                  */
#define RTC_LR_LRL_MASK                          (0x01UL << RTC_LR_LRL_SHIFT)                        /*!< RTC_LR: LRL Mask                        */
#define RTC_LR_LRL_SHIFT                         6                                                   /*!< RTC_LR: LRL Position                    */
#define RTC_LR_LRL(x)                            (((uint32_t)(((uint32_t)(x))<<RTC_LR_LRL_SHIFT))&RTC_LR_LRL_MASK) /*!< RTC_LR                                  */
/* ------- IER Bit Fields                           ------ */
#define RTC_IER_TIIE_MASK                        (0x01UL << RTC_IER_TIIE_SHIFT)                      /*!< RTC_IER: TIIE Mask                      */
#define RTC_IER_TIIE_SHIFT                       0                                                   /*!< RTC_IER: TIIE Position                  */
#define RTC_IER_TIIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TIIE_SHIFT))&RTC_IER_TIIE_MASK) /*!< RTC_IER                                 */
#define RTC_IER_TOIE_MASK                        (0x01UL << RTC_IER_TOIE_SHIFT)                      /*!< RTC_IER: TOIE Mask                      */
#define RTC_IER_TOIE_SHIFT                       1                                                   /*!< RTC_IER: TOIE Position                  */
#define RTC_IER_TOIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TOIE_SHIFT))&RTC_IER_TOIE_MASK) /*!< RTC_IER                                 */
#define RTC_IER_TAIE_MASK                        (0x01UL << RTC_IER_TAIE_SHIFT)                      /*!< RTC_IER: TAIE Mask                      */
#define RTC_IER_TAIE_SHIFT                       2                                                   /*!< RTC_IER: TAIE Position                  */
#define RTC_IER_TAIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TAIE_SHIFT))&RTC_IER_TAIE_MASK) /*!< RTC_IER                                 */
#define RTC_IER_TSIE_MASK                        (0x01UL << RTC_IER_TSIE_SHIFT)                      /*!< RTC_IER: TSIE Mask                      */
#define RTC_IER_TSIE_SHIFT                       4                                                   /*!< RTC_IER: TSIE Position                  */
#define RTC_IER_TSIE(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_IER_TSIE_SHIFT))&RTC_IER_TSIE_MASK) /*!< RTC_IER                                 */
/* ------- WAR Bit Fields                           ------ */
#define RTC_WAR_TSRW_MASK                        (0x01UL << RTC_WAR_TSRW_SHIFT)                      /*!< RTC_WAR: TSRW Mask                      */
#define RTC_WAR_TSRW_SHIFT                       0                                                   /*!< RTC_WAR: TSRW Position                  */
#define RTC_WAR_TSRW(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_WAR_TSRW_SHIFT))&RTC_WAR_TSRW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_TPRW_MASK                        (0x01UL << RTC_WAR_TPRW_SHIFT)                      /*!< RTC_WAR: TPRW Mask                      */
#define RTC_WAR_TPRW_SHIFT                       1                                                   /*!< RTC_WAR: TPRW Position                  */
#define RTC_WAR_TPRW(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_WAR_TPRW_SHIFT))&RTC_WAR_TPRW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_TARW_MASK                        (0x01UL << RTC_WAR_TARW_SHIFT)                      /*!< RTC_WAR: TARW Mask                      */
#define RTC_WAR_TARW_SHIFT                       2                                                   /*!< RTC_WAR: TARW Position                  */
#define RTC_WAR_TARW(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_WAR_TARW_SHIFT))&RTC_WAR_TARW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_TCRW_MASK                        (0x01UL << RTC_WAR_TCRW_SHIFT)                      /*!< RTC_WAR: TCRW Mask                      */
#define RTC_WAR_TCRW_SHIFT                       3                                                   /*!< RTC_WAR: TCRW Position                  */
#define RTC_WAR_TCRW(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_WAR_TCRW_SHIFT))&RTC_WAR_TCRW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_CRW_MASK                         (0x01UL << RTC_WAR_CRW_SHIFT)                       /*!< RTC_WAR: CRW Mask                       */
#define RTC_WAR_CRW_SHIFT                        4                                                   /*!< RTC_WAR: CRW Position                   */
#define RTC_WAR_CRW(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_WAR_CRW_SHIFT))&RTC_WAR_CRW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_SRW_MASK                         (0x01UL << RTC_WAR_SRW_SHIFT)                       /*!< RTC_WAR: SRW Mask                       */
#define RTC_WAR_SRW_SHIFT                        5                                                   /*!< RTC_WAR: SRW Position                   */
#define RTC_WAR_SRW(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_WAR_SRW_SHIFT))&RTC_WAR_SRW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_LRW_MASK                         (0x01UL << RTC_WAR_LRW_SHIFT)                       /*!< RTC_WAR: LRW Mask                       */
#define RTC_WAR_LRW_SHIFT                        6                                                   /*!< RTC_WAR: LRW Position                   */
#define RTC_WAR_LRW(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_WAR_LRW_SHIFT))&RTC_WAR_LRW_MASK) /*!< RTC_WAR                                 */
#define RTC_WAR_IERW_MASK                        (0x01UL << RTC_WAR_IERW_SHIFT)                      /*!< RTC_WAR: IERW Mask                      */
#define RTC_WAR_IERW_SHIFT                       7                                                   /*!< RTC_WAR: IERW Position                  */
#define RTC_WAR_IERW(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_WAR_IERW_SHIFT))&RTC_WAR_IERW_MASK) /*!< RTC_WAR                                 */
/* ------- RAR Bit Fields                           ------ */
#define RTC_RAR_TSRR_MASK                        (0x01UL << RTC_RAR_TSRR_SHIFT)                      /*!< RTC_RAR: TSRR Mask                      */
#define RTC_RAR_TSRR_SHIFT                       0                                                   /*!< RTC_RAR: TSRR Position                  */
#define RTC_RAR_TSRR(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_RAR_TSRR_SHIFT))&RTC_RAR_TSRR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_TPRR_MASK                        (0x01UL << RTC_RAR_TPRR_SHIFT)                      /*!< RTC_RAR: TPRR Mask                      */
#define RTC_RAR_TPRR_SHIFT                       1                                                   /*!< RTC_RAR: TPRR Position                  */
#define RTC_RAR_TPRR(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_RAR_TPRR_SHIFT))&RTC_RAR_TPRR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_TARR_MASK                        (0x01UL << RTC_RAR_TARR_SHIFT)                      /*!< RTC_RAR: TARR Mask                      */
#define RTC_RAR_TARR_SHIFT                       2                                                   /*!< RTC_RAR: TARR Position                  */
#define RTC_RAR_TARR(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_RAR_TARR_SHIFT))&RTC_RAR_TARR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_TCRR_MASK                        (0x01UL << RTC_RAR_TCRR_SHIFT)                      /*!< RTC_RAR: TCRR Mask                      */
#define RTC_RAR_TCRR_SHIFT                       3                                                   /*!< RTC_RAR: TCRR Position                  */
#define RTC_RAR_TCRR(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_RAR_TCRR_SHIFT))&RTC_RAR_TCRR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_CRR_MASK                         (0x01UL << RTC_RAR_CRR_SHIFT)                       /*!< RTC_RAR: CRR Mask                       */
#define RTC_RAR_CRR_SHIFT                        4                                                   /*!< RTC_RAR: CRR Position                   */
#define RTC_RAR_CRR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_RAR_CRR_SHIFT))&RTC_RAR_CRR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_SRR_MASK                         (0x01UL << RTC_RAR_SRR_SHIFT)                       /*!< RTC_RAR: SRR Mask                       */
#define RTC_RAR_SRR_SHIFT                        5                                                   /*!< RTC_RAR: SRR Position                   */
#define RTC_RAR_SRR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_RAR_SRR_SHIFT))&RTC_RAR_SRR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_LRR_MASK                         (0x01UL << RTC_RAR_LRR_SHIFT)                       /*!< RTC_RAR: LRR Mask                       */
#define RTC_RAR_LRR_SHIFT                        6                                                   /*!< RTC_RAR: LRR Position                   */
#define RTC_RAR_LRR(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_RAR_LRR_SHIFT))&RTC_RAR_LRR_MASK) /*!< RTC_RAR                                 */
#define RTC_RAR_IERR_MASK                        (0x01UL << RTC_RAR_IERR_SHIFT)                      /*!< RTC_RAR: IERR Mask                      */
#define RTC_RAR_IERR_SHIFT                       7                                                   /*!< RTC_RAR: IERR Position                  */
#define RTC_RAR_IERR(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_RAR_IERR_SHIFT))&RTC_RAR_IERR_MASK) /*!< RTC_RAR                                 */
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
/* ================           SIM (file:SIM_MK30D7)                ================ */
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
   __I  uint32_t  RESERVED0[1024];             
   __IO uint32_t  SOPT2;                        /**< 1004: System Options Register 2                                    */
   __I  uint32_t  RESERVED1;                   
   __IO uint32_t  SOPT4;                        /**< 100C: System Options Register 4                                    */
   __IO uint32_t  SOPT5;                        /**< 1010: System Options Register 5                                    */
   __I  uint32_t  RESERVED2;                   
   __IO uint32_t  SOPT7;                        /**< 1018: System Options Register 7                                    */
   __I  uint32_t  RESERVED3[2];                
   __I  uint32_t  SDID;                         /**< 1024: System Device Identification Register                        */
   __IO uint32_t  SCGC1;                        /**< 1028: System Clock Gating Control Register 1                       */
   __IO uint32_t  SCGC2;                        /**< 102C: System Clock Gating Control Register 2                       */
   __IO uint32_t  SCGC3;                        /**< 1030: System Clock Gating Control Register 3                       */
   __IO uint32_t  SCGC4;                        /**< 1034: System Clock Gating Control Register 4                       */
   __IO uint32_t  SCGC5;                        /**< 1038: System Clock Gating Control Register 5                       */
   __IO uint32_t  SCGC6;                        /**< 103C: System Clock Gating Control Register 6                       */
   __IO uint32_t  SCGC7;                        /**< 1040: System Clock Gating Control Register 7                       */
   __IO uint32_t  CLKDIV1;                      /**< 1044: System Clock Divider Register 1                              */
   __I  uint32_t  CLKDIV2;                      /**< 1048: System Clock Divider Register 2                              */
   __IO uint32_t  FCFG1;                        /**< 104C: Flash Configuration Register 1                               */
   __I  uint32_t  FCFG2;                        /**< 1050: Flash Configuration Register 2                               */
   __I  uint32_t  UIDH;                         /**< 1054: Unique Identification Register High                          */
   __I  uint32_t  UIDMH;                        /**< 1058: Unique Identification Register Mid-High                      */
   __I  uint32_t  UIDML;                        /**< 105C: Unique Identification Register Mid Low                       */
   __I  uint32_t  UIDL;                         /**< 1060: Unique Identification Register Low                           */
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
#define SIM_SOPT1_RAMSIZE_MASK                   (0x0FUL << SIM_SOPT1_RAMSIZE_SHIFT)                 /*!< SIM_SOPT1: RAMSIZE Mask                 */
#define SIM_SOPT1_RAMSIZE_SHIFT                  12                                                  /*!< SIM_SOPT1: RAMSIZE Position             */
#define SIM_SOPT1_RAMSIZE(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_RAMSIZE_SHIFT))&SIM_SOPT1_RAMSIZE_MASK) /*!< SIM_SOPT1                               */
#define SIM_SOPT1_OSC32KSEL_MASK                 (0x03UL << SIM_SOPT1_OSC32KSEL_SHIFT)               /*!< SIM_SOPT1: OSC32KSEL Mask               */
#define SIM_SOPT1_OSC32KSEL_SHIFT                18                                                  /*!< SIM_SOPT1: OSC32KSEL Position           */
#define SIM_SOPT1_OSC32KSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT1_OSC32KSEL_SHIFT))&SIM_SOPT1_OSC32KSEL_MASK) /*!< SIM_SOPT1                               */
/* ------- SOPT2 Bit Fields                         ------ */
#define SIM_SOPT2_RTCCLKOUTSEL_MASK              (0x01UL << SIM_SOPT2_RTCCLKOUTSEL_SHIFT)            /*!< SIM_SOPT2: RTCCLKOUTSEL Mask            */
#define SIM_SOPT2_RTCCLKOUTSEL_SHIFT             4                                                   /*!< SIM_SOPT2: RTCCLKOUTSEL Position        */
#define SIM_SOPT2_RTCCLKOUTSEL(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_RTCCLKOUTSEL_SHIFT))&SIM_SOPT2_RTCCLKOUTSEL_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_CLKOUTSEL_MASK                 (0x07UL << SIM_SOPT2_CLKOUTSEL_SHIFT)               /*!< SIM_SOPT2: CLKOUTSEL Mask               */
#define SIM_SOPT2_CLKOUTSEL_SHIFT                5                                                   /*!< SIM_SOPT2: CLKOUTSEL Position           */
#define SIM_SOPT2_CLKOUTSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_CLKOUTSEL_SHIFT))&SIM_SOPT2_CLKOUTSEL_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_PTD7PAD_MASK                   (0x01UL << SIM_SOPT2_PTD7PAD_SHIFT)                 /*!< SIM_SOPT2: PTD7PAD Mask                 */
#define SIM_SOPT2_PTD7PAD_SHIFT                  11                                                  /*!< SIM_SOPT2: PTD7PAD Position             */
#define SIM_SOPT2_PTD7PAD(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_PTD7PAD_SHIFT))&SIM_SOPT2_PTD7PAD_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_TRACECLKSEL_MASK               (0x01UL << SIM_SOPT2_TRACECLKSEL_SHIFT)             /*!< SIM_SOPT2: TRACECLKSEL Mask             */
#define SIM_SOPT2_TRACECLKSEL_SHIFT              12                                                  /*!< SIM_SOPT2: TRACECLKSEL Position         */
#define SIM_SOPT2_TRACECLKSEL(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_TRACECLKSEL_SHIFT))&SIM_SOPT2_TRACECLKSEL_MASK) /*!< SIM_SOPT2                               */
#define SIM_SOPT2_PLLFLLSEL_MASK                 (0x01UL << SIM_SOPT2_PLLFLLSEL_SHIFT)               /*!< SIM_SOPT2: PLLFLLSEL Mask               */
#define SIM_SOPT2_PLLFLLSEL_SHIFT                16                                                  /*!< SIM_SOPT2: PLLFLLSEL Position           */
#define SIM_SOPT2_PLLFLLSEL(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_SOPT2_PLLFLLSEL_SHIFT))&SIM_SOPT2_PLLFLLSEL_MASK) /*!< SIM_SOPT2                               */
/* ------- SOPT4 Bit Fields                         ------ */
#define SIM_SOPT4_FTM0FLT0_MASK                  (0x01UL << SIM_SOPT4_FTM0FLT0_SHIFT)                /*!< SIM_SOPT4: FTM0FLT0 Mask                */
#define SIM_SOPT4_FTM0FLT0_SHIFT                 0                                                   /*!< SIM_SOPT4: FTM0FLT0 Position            */
#define SIM_SOPT4_FTM0FLT0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM0FLT0_SHIFT))&SIM_SOPT4_FTM0FLT0_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM0FLT1_MASK                  (0x01UL << SIM_SOPT4_FTM0FLT1_SHIFT)                /*!< SIM_SOPT4: FTM0FLT1 Mask                */
#define SIM_SOPT4_FTM0FLT1_SHIFT                 1                                                   /*!< SIM_SOPT4: FTM0FLT1 Position            */
#define SIM_SOPT4_FTM0FLT1(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM0FLT1_SHIFT))&SIM_SOPT4_FTM0FLT1_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM0FLT2_MASK                  (0x01UL << SIM_SOPT4_FTM0FLT2_SHIFT)                /*!< SIM_SOPT4: FTM0FLT2 Mask                */
#define SIM_SOPT4_FTM0FLT2_SHIFT                 2                                                   /*!< SIM_SOPT4: FTM0FLT2 Position            */
#define SIM_SOPT4_FTM0FLT2(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM0FLT2_SHIFT))&SIM_SOPT4_FTM0FLT2_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM1FLT0_MASK                  (0x01UL << SIM_SOPT4_FTM1FLT0_SHIFT)                /*!< SIM_SOPT4: FTM1FLT0 Mask                */
#define SIM_SOPT4_FTM1FLT0_SHIFT                 4                                                   /*!< SIM_SOPT4: FTM1FLT0 Position            */
#define SIM_SOPT4_FTM1FLT0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM1FLT0_SHIFT))&SIM_SOPT4_FTM1FLT0_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM2FLT0_MASK                  (0x01UL << SIM_SOPT4_FTM2FLT0_SHIFT)                /*!< SIM_SOPT4: FTM2FLT0 Mask                */
#define SIM_SOPT4_FTM2FLT0_SHIFT                 8                                                   /*!< SIM_SOPT4: FTM2FLT0 Position            */
#define SIM_SOPT4_FTM2FLT0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM2FLT0_SHIFT))&SIM_SOPT4_FTM2FLT0_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM1CH0SRC_MASK                (0x03UL << SIM_SOPT4_FTM1CH0SRC_SHIFT)              /*!< SIM_SOPT4: FTM1CH0SRC Mask              */
#define SIM_SOPT4_FTM1CH0SRC_SHIFT               18                                                  /*!< SIM_SOPT4: FTM1CH0SRC Position          */
#define SIM_SOPT4_FTM1CH0SRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM1CH0SRC_SHIFT))&SIM_SOPT4_FTM1CH0SRC_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM2CH0SRC_MASK                (0x03UL << SIM_SOPT4_FTM2CH0SRC_SHIFT)              /*!< SIM_SOPT4: FTM2CH0SRC Mask              */
#define SIM_SOPT4_FTM2CH0SRC_SHIFT               20                                                  /*!< SIM_SOPT4: FTM2CH0SRC Position          */
#define SIM_SOPT4_FTM2CH0SRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM2CH0SRC_SHIFT))&SIM_SOPT4_FTM2CH0SRC_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM0CLKSEL_MASK                (0x01UL << SIM_SOPT4_FTM0CLKSEL_SHIFT)              /*!< SIM_SOPT4: FTM0CLKSEL Mask              */
#define SIM_SOPT4_FTM0CLKSEL_SHIFT               24                                                  /*!< SIM_SOPT4: FTM0CLKSEL Position          */
#define SIM_SOPT4_FTM0CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM0CLKSEL_SHIFT))&SIM_SOPT4_FTM0CLKSEL_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM1CLKSEL_MASK                (0x01UL << SIM_SOPT4_FTM1CLKSEL_SHIFT)              /*!< SIM_SOPT4: FTM1CLKSEL Mask              */
#define SIM_SOPT4_FTM1CLKSEL_SHIFT               25                                                  /*!< SIM_SOPT4: FTM1CLKSEL Position          */
#define SIM_SOPT4_FTM1CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM1CLKSEL_SHIFT))&SIM_SOPT4_FTM1CLKSEL_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM2CLKSEL_MASK                (0x01UL << SIM_SOPT4_FTM2CLKSEL_SHIFT)              /*!< SIM_SOPT4: FTM2CLKSEL Mask              */
#define SIM_SOPT4_FTM2CLKSEL_SHIFT               26                                                  /*!< SIM_SOPT4: FTM2CLKSEL Position          */
#define SIM_SOPT4_FTM2CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM2CLKSEL_SHIFT))&SIM_SOPT4_FTM2CLKSEL_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM0TRG0SRC_MASK               (0x01UL << SIM_SOPT4_FTM0TRG0SRC_SHIFT)             /*!< SIM_SOPT4: FTM0TRG0SRC Mask             */
#define SIM_SOPT4_FTM0TRG0SRC_SHIFT              28                                                  /*!< SIM_SOPT4: FTM0TRG0SRC Position         */
#define SIM_SOPT4_FTM0TRG0SRC(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM0TRG0SRC_SHIFT))&SIM_SOPT4_FTM0TRG0SRC_MASK) /*!< SIM_SOPT4                               */
#define SIM_SOPT4_FTM0TRG1SRC_MASK               (0x01UL << SIM_SOPT4_FTM0TRG1SRC_SHIFT)             /*!< SIM_SOPT4: FTM0TRG1SRC Mask             */
#define SIM_SOPT4_FTM0TRG1SRC_SHIFT              29                                                  /*!< SIM_SOPT4: FTM0TRG1SRC Position         */
#define SIM_SOPT4_FTM0TRG1SRC(x)                 (((uint32_t)(((uint32_t)(x))<<SIM_SOPT4_FTM0TRG1SRC_SHIFT))&SIM_SOPT4_FTM0TRG1SRC_MASK) /*!< SIM_SOPT4                               */
/* ------- SOPT5 Bit Fields                         ------ */
#define SIM_SOPT5_UART0TXSRC_MASK                (0x03UL << SIM_SOPT5_UART0TXSRC_SHIFT)              /*!< SIM_SOPT5: UART0TXSRC Mask              */
#define SIM_SOPT5_UART0TXSRC_SHIFT               0                                                   /*!< SIM_SOPT5: UART0TXSRC Position          */
#define SIM_SOPT5_UART0TXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART0TXSRC_SHIFT))&SIM_SOPT5_UART0TXSRC_MASK) /*!< SIM_SOPT5                               */
#define SIM_SOPT5_UART0RXSRC_MASK                (0x03UL << SIM_SOPT5_UART0RXSRC_SHIFT)              /*!< SIM_SOPT5: UART0RXSRC Mask              */
#define SIM_SOPT5_UART0RXSRC_SHIFT               2                                                   /*!< SIM_SOPT5: UART0RXSRC Position          */
#define SIM_SOPT5_UART0RXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART0RXSRC_SHIFT))&SIM_SOPT5_UART0RXSRC_MASK) /*!< SIM_SOPT5                               */
#define SIM_SOPT5_UART1TXSRC_MASK                (0x03UL << SIM_SOPT5_UART1TXSRC_SHIFT)              /*!< SIM_SOPT5: UART1TXSRC Mask              */
#define SIM_SOPT5_UART1TXSRC_SHIFT               4                                                   /*!< SIM_SOPT5: UART1TXSRC Position          */
#define SIM_SOPT5_UART1TXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART1TXSRC_SHIFT))&SIM_SOPT5_UART1TXSRC_MASK) /*!< SIM_SOPT5                               */
#define SIM_SOPT5_UART1RXSRC_MASK                (0x03UL << SIM_SOPT5_UART1RXSRC_SHIFT)              /*!< SIM_SOPT5: UART1RXSRC Mask              */
#define SIM_SOPT5_UART1RXSRC_SHIFT               6                                                   /*!< SIM_SOPT5: UART1RXSRC Position          */
#define SIM_SOPT5_UART1RXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT5_UART1RXSRC_SHIFT))&SIM_SOPT5_UART1RXSRC_MASK) /*!< SIM_SOPT5                               */
/* ------- SOPT7 Bit Fields                         ------ */
#define SIM_SOPT7_ADC0TRGSEL_MASK                (0x0FUL << SIM_SOPT7_ADC0TRGSEL_SHIFT)              /*!< SIM_SOPT7: ADC0TRGSEL Mask              */
#define SIM_SOPT7_ADC0TRGSEL_SHIFT               0                                                   /*!< SIM_SOPT7: ADC0TRGSEL Position          */
#define SIM_SOPT7_ADC0TRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC0TRGSEL_SHIFT))&SIM_SOPT7_ADC0TRGSEL_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_ADC0PRETRGSEL_MASK             (0x01UL << SIM_SOPT7_ADC0PRETRGSEL_SHIFT)           /*!< SIM_SOPT7: ADC0PRETRGSEL Mask           */
#define SIM_SOPT7_ADC0PRETRGSEL_SHIFT            4                                                   /*!< SIM_SOPT7: ADC0PRETRGSEL Position       */
#define SIM_SOPT7_ADC0PRETRGSEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC0PRETRGSEL_SHIFT))&SIM_SOPT7_ADC0PRETRGSEL_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_ADC0ALTTRGEN_MASK              (0x01UL << SIM_SOPT7_ADC0ALTTRGEN_SHIFT)            /*!< SIM_SOPT7: ADC0ALTTRGEN Mask            */
#define SIM_SOPT7_ADC0ALTTRGEN_SHIFT             7                                                   /*!< SIM_SOPT7: ADC0ALTTRGEN Position        */
#define SIM_SOPT7_ADC0ALTTRGEN(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC0ALTTRGEN_SHIFT))&SIM_SOPT7_ADC0ALTTRGEN_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_ADC1TRGSEL_MASK                (0x0FUL << SIM_SOPT7_ADC1TRGSEL_SHIFT)              /*!< SIM_SOPT7: ADC1TRGSEL Mask              */
#define SIM_SOPT7_ADC1TRGSEL_SHIFT               8                                                   /*!< SIM_SOPT7: ADC1TRGSEL Position          */
#define SIM_SOPT7_ADC1TRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC1TRGSEL_SHIFT))&SIM_SOPT7_ADC1TRGSEL_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_ADC1PRETRGSEL_MASK             (0x01UL << SIM_SOPT7_ADC1PRETRGSEL_SHIFT)           /*!< SIM_SOPT7: ADC1PRETRGSEL Mask           */
#define SIM_SOPT7_ADC1PRETRGSEL_SHIFT            12                                                  /*!< SIM_SOPT7: ADC1PRETRGSEL Position       */
#define SIM_SOPT7_ADC1PRETRGSEL(x)               (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC1PRETRGSEL_SHIFT))&SIM_SOPT7_ADC1PRETRGSEL_MASK) /*!< SIM_SOPT7                               */
#define SIM_SOPT7_ADC1ALTTRGEN_MASK              (0x01UL << SIM_SOPT7_ADC1ALTTRGEN_SHIFT)            /*!< SIM_SOPT7: ADC1ALTTRGEN Mask            */
#define SIM_SOPT7_ADC1ALTTRGEN_SHIFT             15                                                  /*!< SIM_SOPT7: ADC1ALTTRGEN Position        */
#define SIM_SOPT7_ADC1ALTTRGEN(x)                (((uint32_t)(((uint32_t)(x))<<SIM_SOPT7_ADC1ALTTRGEN_SHIFT))&SIM_SOPT7_ADC1ALTTRGEN_MASK) /*!< SIM_SOPT7                               */
/* ------- SDID Bit Fields                          ------ */
#define SIM_SDID_PINID_MASK                      (0x0FUL << SIM_SDID_PINID_SHIFT)                    /*!< SIM_SDID: PINID Mask                    */
#define SIM_SDID_PINID_SHIFT                     0                                                   /*!< SIM_SDID: PINID Position                */
#define SIM_SDID_PINID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_PINID_SHIFT))&SIM_SDID_PINID_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_FAMID_MASK                      (0x07UL << SIM_SDID_FAMID_SHIFT)                    /*!< SIM_SDID: FAMID Mask                    */
#define SIM_SDID_FAMID_SHIFT                     4                                                   /*!< SIM_SDID: FAMID Position                */
#define SIM_SDID_FAMID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_FAMID_SHIFT))&SIM_SDID_FAMID_MASK) /*!< SIM_SDID                                */
#define SIM_SDID_REVID_MASK                      (0x0FUL << SIM_SDID_REVID_SHIFT)                    /*!< SIM_SDID: REVID Mask                    */
#define SIM_SDID_REVID_SHIFT                     12                                                  /*!< SIM_SDID: REVID Position                */
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SDID_REVID_SHIFT))&SIM_SDID_REVID_MASK) /*!< SIM_SDID                                */
/* ------- SCGC1 Bit Fields                         ------ */
#define SIM_SCGC1_UART4_MASK                     (0x01UL << SIM_SCGC1_UART4_SHIFT)                   /*!< SIM_SCGC1: UART4 Mask                   */
#define SIM_SCGC1_UART4_SHIFT                    10                                                  /*!< SIM_SCGC1: UART4 Position               */
#define SIM_SCGC1_UART4(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC1_UART4_SHIFT))&SIM_SCGC1_UART4_MASK) /*!< SIM_SCGC1                               */
/* ------- SCGC2 Bit Fields                         ------ */
#define SIM_SCGC2_DAC0_MASK                      (0x01UL << SIM_SCGC2_DAC0_SHIFT)                    /*!< SIM_SCGC2: DAC0 Mask                    */
#define SIM_SCGC2_DAC0_SHIFT                     12                                                  /*!< SIM_SCGC2: DAC0 Position                */
#define SIM_SCGC2_DAC0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC2_DAC0_SHIFT))&SIM_SCGC2_DAC0_MASK) /*!< SIM_SCGC2                               */
/* ------- SCGC3 Bit Fields                         ------ */
#define SIM_SCGC3_FTM2_MASK                      (0x01UL << SIM_SCGC3_FTM2_SHIFT)                    /*!< SIM_SCGC3: FTM2 Mask                    */
#define SIM_SCGC3_FTM2_SHIFT                     24                                                  /*!< SIM_SCGC3: FTM2 Position                */
#define SIM_SCGC3_FTM2(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC3_FTM2_SHIFT))&SIM_SCGC3_FTM2_MASK) /*!< SIM_SCGC3                               */
#define SIM_SCGC3_ADC1_MASK                      (0x01UL << SIM_SCGC3_ADC1_SHIFT)                    /*!< SIM_SCGC3: ADC1 Mask                    */
#define SIM_SCGC3_ADC1_SHIFT                     27                                                  /*!< SIM_SCGC3: ADC1 Position                */
#define SIM_SCGC3_ADC1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC3_ADC1_SHIFT))&SIM_SCGC3_ADC1_MASK) /*!< SIM_SCGC3                               */
#define SIM_SCGC3_SLCD_MASK                      (0x01UL << SIM_SCGC3_SLCD_SHIFT)                    /*!< SIM_SCGC3: SLCD Mask                    */
#define SIM_SCGC3_SLCD_SHIFT                     30                                                  /*!< SIM_SCGC3: SLCD Position                */
#define SIM_SCGC3_SLCD(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC3_SLCD_SHIFT))&SIM_SCGC3_SLCD_MASK) /*!< SIM_SCGC3                               */
/* ------- SCGC4 Bit Fields                         ------ */
#define SIM_SCGC4_EWM_MASK                       (0x01UL << SIM_SCGC4_EWM_SHIFT)                     /*!< SIM_SCGC4: EWM Mask                     */
#define SIM_SCGC4_EWM_SHIFT                      1                                                   /*!< SIM_SCGC4: EWM Position                 */
#define SIM_SCGC4_EWM(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_EWM_SHIFT))&SIM_SCGC4_EWM_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_CMT_MASK                       (0x01UL << SIM_SCGC4_CMT_SHIFT)                     /*!< SIM_SCGC4: CMT Mask                     */
#define SIM_SCGC4_CMT_SHIFT                      2                                                   /*!< SIM_SCGC4: CMT Position                 */
#define SIM_SCGC4_CMT(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_CMT_SHIFT))&SIM_SCGC4_CMT_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_I2C0_MASK                      (0x01UL << SIM_SCGC4_I2C0_SHIFT)                    /*!< SIM_SCGC4: I2C0 Mask                    */
#define SIM_SCGC4_I2C0_SHIFT                     6                                                   /*!< SIM_SCGC4: I2C0 Position                */
#define SIM_SCGC4_I2C0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_I2C0_SHIFT))&SIM_SCGC4_I2C0_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_I2C1_MASK                      (0x01UL << SIM_SCGC4_I2C1_SHIFT)                    /*!< SIM_SCGC4: I2C1 Mask                    */
#define SIM_SCGC4_I2C1_SHIFT                     7                                                   /*!< SIM_SCGC4: I2C1 Position                */
#define SIM_SCGC4_I2C1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_I2C1_SHIFT))&SIM_SCGC4_I2C1_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_UART0_MASK                     (0x01UL << SIM_SCGC4_UART0_SHIFT)                   /*!< SIM_SCGC4: UART0 Mask                   */
#define SIM_SCGC4_UART0_SHIFT                    10                                                  /*!< SIM_SCGC4: UART0 Position               */
#define SIM_SCGC4_UART0(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_UART0_SHIFT))&SIM_SCGC4_UART0_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_UART1_MASK                     (0x01UL << SIM_SCGC4_UART1_SHIFT)                   /*!< SIM_SCGC4: UART1 Mask                   */
#define SIM_SCGC4_UART1_SHIFT                    11                                                  /*!< SIM_SCGC4: UART1 Position               */
#define SIM_SCGC4_UART1(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_UART1_SHIFT))&SIM_SCGC4_UART1_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_UART2_MASK                     (0x01UL << SIM_SCGC4_UART2_SHIFT)                   /*!< SIM_SCGC4: UART2 Mask                   */
#define SIM_SCGC4_UART2_SHIFT                    12                                                  /*!< SIM_SCGC4: UART2 Position               */
#define SIM_SCGC4_UART2(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_UART2_SHIFT))&SIM_SCGC4_UART2_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_UART3_MASK                     (0x01UL << SIM_SCGC4_UART3_SHIFT)                   /*!< SIM_SCGC4: UART3 Mask                   */
#define SIM_SCGC4_UART3_SHIFT                    13                                                  /*!< SIM_SCGC4: UART3 Position               */
#define SIM_SCGC4_UART3(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_UART3_SHIFT))&SIM_SCGC4_UART3_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_CMP_MASK                       (0x01UL << SIM_SCGC4_CMP_SHIFT)                     /*!< SIM_SCGC4: CMP Mask                     */
#define SIM_SCGC4_CMP_SHIFT                      19                                                  /*!< SIM_SCGC4: CMP Position                 */
#define SIM_SCGC4_CMP(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_CMP_SHIFT))&SIM_SCGC4_CMP_MASK) /*!< SIM_SCGC4                               */
#define SIM_SCGC4_VREF_MASK                      (0x01UL << SIM_SCGC4_VREF_SHIFT)                    /*!< SIM_SCGC4: VREF Mask                    */
#define SIM_SCGC4_VREF_SHIFT                     20                                                  /*!< SIM_SCGC4: VREF Position                */
#define SIM_SCGC4_VREF(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC4_VREF_SHIFT))&SIM_SCGC4_VREF_MASK) /*!< SIM_SCGC4                               */
/* ------- SCGC5 Bit Fields                         ------ */
#define SIM_SCGC5_LPTIMER_MASK                   (0x01UL << SIM_SCGC5_LPTIMER_SHIFT)                 /*!< SIM_SCGC5: LPTIMER Mask                 */
#define SIM_SCGC5_LPTIMER_SHIFT                  0                                                   /*!< SIM_SCGC5: LPTIMER Position             */
#define SIM_SCGC5_LPTIMER(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_LPTIMER_SHIFT))&SIM_SCGC5_LPTIMER_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_TSI0_MASK                      (0x01UL << SIM_SCGC5_TSI0_SHIFT)                    /*!< SIM_SCGC5: TSI0 Mask                    */
#define SIM_SCGC5_TSI0_SHIFT                     5                                                   /*!< SIM_SCGC5: TSI0 Position                */
#define SIM_SCGC5_TSI0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_TSI0_SHIFT))&SIM_SCGC5_TSI0_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_PORTA_MASK                     (0x01UL << SIM_SCGC5_PORTA_SHIFT)                   /*!< SIM_SCGC5: PORTA Mask                   */
#define SIM_SCGC5_PORTA_SHIFT                    9                                                   /*!< SIM_SCGC5: PORTA Position               */
#define SIM_SCGC5_PORTA(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTA_SHIFT))&SIM_SCGC5_PORTA_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_PORTB_MASK                     (0x01UL << SIM_SCGC5_PORTB_SHIFT)                   /*!< SIM_SCGC5: PORTB Mask                   */
#define SIM_SCGC5_PORTB_SHIFT                    10                                                  /*!< SIM_SCGC5: PORTB Position               */
#define SIM_SCGC5_PORTB(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTB_SHIFT))&SIM_SCGC5_PORTB_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_PORTC_MASK                     (0x01UL << SIM_SCGC5_PORTC_SHIFT)                   /*!< SIM_SCGC5: PORTC Mask                   */
#define SIM_SCGC5_PORTC_SHIFT                    11                                                  /*!< SIM_SCGC5: PORTC Position               */
#define SIM_SCGC5_PORTC(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTC_SHIFT))&SIM_SCGC5_PORTC_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_PORTD_MASK                     (0x01UL << SIM_SCGC5_PORTD_SHIFT)                   /*!< SIM_SCGC5: PORTD Mask                   */
#define SIM_SCGC5_PORTD_SHIFT                    12                                                  /*!< SIM_SCGC5: PORTD Position               */
#define SIM_SCGC5_PORTD(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTD_SHIFT))&SIM_SCGC5_PORTD_MASK) /*!< SIM_SCGC5                               */
#define SIM_SCGC5_PORTE_MASK                     (0x01UL << SIM_SCGC5_PORTE_SHIFT)                   /*!< SIM_SCGC5: PORTE Mask                   */
#define SIM_SCGC5_PORTE_SHIFT                    13                                                  /*!< SIM_SCGC5: PORTE Position               */
#define SIM_SCGC5_PORTE(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SCGC5_PORTE_SHIFT))&SIM_SCGC5_PORTE_MASK) /*!< SIM_SCGC5                               */
/* ------- SCGC6 Bit Fields                         ------ */
#define SIM_SCGC6_FTFL_MASK                      (0x01UL << SIM_SCGC6_FTFL_SHIFT)                    /*!< SIM_SCGC6: FTFL Mask                    */
#define SIM_SCGC6_FTFL_SHIFT                     0                                                   /*!< SIM_SCGC6: FTFL Position                */
#define SIM_SCGC6_FTFL(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_FTFL_SHIFT))&SIM_SCGC6_FTFL_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_DMAMUX0_MASK                   (0x01UL << SIM_SCGC6_DMAMUX0_SHIFT)                 /*!< SIM_SCGC6: DMAMUX0 Mask                 */
#define SIM_SCGC6_DMAMUX0_SHIFT                  1                                                   /*!< SIM_SCGC6: DMAMUX0 Position             */
#define SIM_SCGC6_DMAMUX0(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_DMAMUX0_SHIFT))&SIM_SCGC6_DMAMUX0_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_FLEXCAN0_MASK                  (0x01UL << SIM_SCGC6_FLEXCAN0_SHIFT)                /*!< SIM_SCGC6: FLEXCAN0 Mask                */
#define SIM_SCGC6_FLEXCAN0_SHIFT                 4                                                   /*!< SIM_SCGC6: FLEXCAN0 Position            */
#define SIM_SCGC6_FLEXCAN0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_FLEXCAN0_SHIFT))&SIM_SCGC6_FLEXCAN0_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_SPI0_MASK                      (0x01UL << SIM_SCGC6_SPI0_SHIFT)                    /*!< SIM_SCGC6: SPI0 Mask                    */
#define SIM_SCGC6_SPI0_SHIFT                     12                                                  /*!< SIM_SCGC6: SPI0 Position                */
#define SIM_SCGC6_SPI0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_SPI0_SHIFT))&SIM_SCGC6_SPI0_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_SPI1_MASK                      (0x01UL << SIM_SCGC6_SPI1_SHIFT)                    /*!< SIM_SCGC6: SPI1 Mask                    */
#define SIM_SCGC6_SPI1_SHIFT                     13                                                  /*!< SIM_SCGC6: SPI1 Position                */
#define SIM_SCGC6_SPI1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_SPI1_SHIFT))&SIM_SCGC6_SPI1_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_I2S_MASK                       (0x01UL << SIM_SCGC6_I2S_SHIFT)                     /*!< SIM_SCGC6: I2S Mask                     */
#define SIM_SCGC6_I2S_SHIFT                      15                                                  /*!< SIM_SCGC6: I2S Position                 */
#define SIM_SCGC6_I2S(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_I2S_SHIFT))&SIM_SCGC6_I2S_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_CRC_MASK                       (0x01UL << SIM_SCGC6_CRC_SHIFT)                     /*!< SIM_SCGC6: CRC Mask                     */
#define SIM_SCGC6_CRC_SHIFT                      18                                                  /*!< SIM_SCGC6: CRC Position                 */
#define SIM_SCGC6_CRC(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_CRC_SHIFT))&SIM_SCGC6_CRC_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_PDB_MASK                       (0x01UL << SIM_SCGC6_PDB_SHIFT)                     /*!< SIM_SCGC6: PDB Mask                     */
#define SIM_SCGC6_PDB_SHIFT                      22                                                  /*!< SIM_SCGC6: PDB Position                 */
#define SIM_SCGC6_PDB(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_PDB_SHIFT))&SIM_SCGC6_PDB_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_PIT_MASK                       (0x01UL << SIM_SCGC6_PIT_SHIFT)                     /*!< SIM_SCGC6: PIT Mask                     */
#define SIM_SCGC6_PIT_SHIFT                      23                                                  /*!< SIM_SCGC6: PIT Position                 */
#define SIM_SCGC6_PIT(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_PIT_SHIFT))&SIM_SCGC6_PIT_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_FTM0_MASK                      (0x01UL << SIM_SCGC6_FTM0_SHIFT)                    /*!< SIM_SCGC6: FTM0 Mask                    */
#define SIM_SCGC6_FTM0_SHIFT                     24                                                  /*!< SIM_SCGC6: FTM0 Position                */
#define SIM_SCGC6_FTM0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_FTM0_SHIFT))&SIM_SCGC6_FTM0_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_FTM1_MASK                      (0x01UL << SIM_SCGC6_FTM1_SHIFT)                    /*!< SIM_SCGC6: FTM1 Mask                    */
#define SIM_SCGC6_FTM1_SHIFT                     25                                                  /*!< SIM_SCGC6: FTM1 Position                */
#define SIM_SCGC6_FTM1(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_FTM1_SHIFT))&SIM_SCGC6_FTM1_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_ADC0_MASK                      (0x01UL << SIM_SCGC6_ADC0_SHIFT)                    /*!< SIM_SCGC6: ADC0 Mask                    */
#define SIM_SCGC6_ADC0_SHIFT                     27                                                  /*!< SIM_SCGC6: ADC0 Position                */
#define SIM_SCGC6_ADC0(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_ADC0_SHIFT))&SIM_SCGC6_ADC0_MASK) /*!< SIM_SCGC6                               */
#define SIM_SCGC6_RTC_MASK                       (0x01UL << SIM_SCGC6_RTC_SHIFT)                     /*!< SIM_SCGC6: RTC Mask                     */
#define SIM_SCGC6_RTC_SHIFT                      29                                                  /*!< SIM_SCGC6: RTC Position                 */
#define SIM_SCGC6_RTC(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC6_RTC_SHIFT))&SIM_SCGC6_RTC_MASK) /*!< SIM_SCGC6                               */
/* ------- SCGC7 Bit Fields                         ------ */
#define SIM_SCGC7_DMA_MASK                       (0x01UL << SIM_SCGC7_DMA_SHIFT)                     /*!< SIM_SCGC7: DMA Mask                     */
#define SIM_SCGC7_DMA_SHIFT                      1                                                   /*!< SIM_SCGC7: DMA Position                 */
#define SIM_SCGC7_DMA(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_SCGC7_DMA_SHIFT))&SIM_SCGC7_DMA_MASK) /*!< SIM_SCGC7                               */
/* ------- CLKDIV1 Bit Fields                       ------ */
#define SIM_CLKDIV1_OUTDIV4_MASK                 (0x0FUL << SIM_CLKDIV1_OUTDIV4_SHIFT)               /*!< SIM_CLKDIV1: OUTDIV4 Mask               */
#define SIM_CLKDIV1_OUTDIV4_SHIFT                16                                                  /*!< SIM_CLKDIV1: OUTDIV4 Position           */
#define SIM_CLKDIV1_OUTDIV4(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV4_SHIFT))&SIM_CLKDIV1_OUTDIV4_MASK) /*!< SIM_CLKDIV1                             */
#define SIM_CLKDIV1_OUTDIV2_MASK                 (0x0FUL << SIM_CLKDIV1_OUTDIV2_SHIFT)               /*!< SIM_CLKDIV1: OUTDIV2 Mask               */
#define SIM_CLKDIV1_OUTDIV2_SHIFT                24                                                  /*!< SIM_CLKDIV1: OUTDIV2 Position           */
#define SIM_CLKDIV1_OUTDIV2(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV2_SHIFT))&SIM_CLKDIV1_OUTDIV2_MASK) /*!< SIM_CLKDIV1                             */
#define SIM_CLKDIV1_OUTDIV1_MASK                 (0x0FUL << SIM_CLKDIV1_OUTDIV1_SHIFT)               /*!< SIM_CLKDIV1: OUTDIV1 Mask               */
#define SIM_CLKDIV1_OUTDIV1_SHIFT                28                                                  /*!< SIM_CLKDIV1: OUTDIV1 Position           */
#define SIM_CLKDIV1_OUTDIV1(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_CLKDIV1_OUTDIV1_SHIFT))&SIM_CLKDIV1_OUTDIV1_MASK) /*!< SIM_CLKDIV1                             */
/* ------- CLKDIV2 Bit Fields                       ------ */
/* ------- FCFG1 Bit Fields                         ------ */
#define SIM_FCFG1_FLASHDIS_MASK                  (0x01UL << SIM_FCFG1_FLASHDIS_SHIFT)                /*!< SIM_FCFG1: FLASHDIS Mask                */
#define SIM_FCFG1_FLASHDIS_SHIFT                 0                                                   /*!< SIM_FCFG1: FLASHDIS Position            */
#define SIM_FCFG1_FLASHDIS(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_FLASHDIS_SHIFT))&SIM_FCFG1_FLASHDIS_MASK) /*!< SIM_FCFG1                               */
#define SIM_FCFG1_FLASHDOZE_MASK                 (0x01UL << SIM_FCFG1_FLASHDOZE_SHIFT)               /*!< SIM_FCFG1: FLASHDOZE Mask               */
#define SIM_FCFG1_FLASHDOZE_SHIFT                1                                                   /*!< SIM_FCFG1: FLASHDOZE Position           */
#define SIM_FCFG1_FLASHDOZE(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_FLASHDOZE_SHIFT))&SIM_FCFG1_FLASHDOZE_MASK) /*!< SIM_FCFG1                               */
#define SIM_FCFG1_DEPART_MASK                    (0x0FUL << SIM_FCFG1_DEPART_SHIFT)                  /*!< SIM_FCFG1: DEPART Mask                  */
#define SIM_FCFG1_DEPART_SHIFT                   8                                                   /*!< SIM_FCFG1: DEPART Position              */
#define SIM_FCFG1_DEPART(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_DEPART_SHIFT))&SIM_FCFG1_DEPART_MASK) /*!< SIM_FCFG1                               */
#define SIM_FCFG1_EESIZE_MASK                    (0x0FUL << SIM_FCFG1_EESIZE_SHIFT)                  /*!< SIM_FCFG1: EESIZE Mask                  */
#define SIM_FCFG1_EESIZE_SHIFT                   16                                                  /*!< SIM_FCFG1: EESIZE Position              */
#define SIM_FCFG1_EESIZE(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_EESIZE_SHIFT))&SIM_FCFG1_EESIZE_MASK) /*!< SIM_FCFG1                               */
#define SIM_FCFG1_PFSIZE_MASK                    (0x0FUL << SIM_FCFG1_PFSIZE_SHIFT)                  /*!< SIM_FCFG1: PFSIZE Mask                  */
#define SIM_FCFG1_PFSIZE_SHIFT                   24                                                  /*!< SIM_FCFG1: PFSIZE Position              */
#define SIM_FCFG1_PFSIZE(x)                      (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_PFSIZE_SHIFT))&SIM_FCFG1_PFSIZE_MASK) /*!< SIM_FCFG1                               */
#define SIM_FCFG1_NVMSIZE_MASK                   (0x0FUL << SIM_FCFG1_NVMSIZE_SHIFT)                 /*!< SIM_FCFG1: NVMSIZE Mask                 */
#define SIM_FCFG1_NVMSIZE_SHIFT                  28                                                  /*!< SIM_FCFG1: NVMSIZE Position             */
#define SIM_FCFG1_NVMSIZE(x)                     (((uint32_t)(((uint32_t)(x))<<SIM_FCFG1_NVMSIZE_SHIFT))&SIM_FCFG1_NVMSIZE_MASK) /*!< SIM_FCFG1                               */
/* ------- FCFG2 Bit Fields                         ------ */
#define SIM_FCFG2_MAXADDR1_MASK                  (0x7FUL << SIM_FCFG2_MAXADDR1_SHIFT)                /*!< SIM_FCFG2: MAXADDR1 Mask                */
#define SIM_FCFG2_MAXADDR1_SHIFT                 16                                                  /*!< SIM_FCFG2: MAXADDR1 Position            */
#define SIM_FCFG2_MAXADDR1(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_MAXADDR1_SHIFT))&SIM_FCFG2_MAXADDR1_MASK) /*!< SIM_FCFG2                               */
#define SIM_FCFG2_PFLSH_MASK                     (0x01UL << SIM_FCFG2_PFLSH_SHIFT)                   /*!< SIM_FCFG2: PFLSH Mask                   */
#define SIM_FCFG2_PFLSH_SHIFT                    23                                                  /*!< SIM_FCFG2: PFLSH Position               */
#define SIM_FCFG2_PFLSH(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_PFLSH_SHIFT))&SIM_FCFG2_PFLSH_MASK) /*!< SIM_FCFG2                               */
#define SIM_FCFG2_MAXADDR0_MASK                  (0x7FUL << SIM_FCFG2_MAXADDR0_SHIFT)                /*!< SIM_FCFG2: MAXADDR0 Mask                */
#define SIM_FCFG2_MAXADDR0_SHIFT                 24                                                  /*!< SIM_FCFG2: MAXADDR0 Position            */
#define SIM_FCFG2_MAXADDR0(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_MAXADDR0_SHIFT))&SIM_FCFG2_MAXADDR0_MASK) /*!< SIM_FCFG2                               */
#define SIM_FCFG2_SWAPPFLSH_MASK                 (0x01UL << SIM_FCFG2_SWAPPFLSH_SHIFT)               /*!< SIM_FCFG2: SWAPPFLSH Mask               */
#define SIM_FCFG2_SWAPPFLSH_SHIFT                31                                                  /*!< SIM_FCFG2: SWAPPFLSH Position           */
#define SIM_FCFG2_SWAPPFLSH(x)                   (((uint32_t)(((uint32_t)(x))<<SIM_FCFG2_SWAPPFLSH_SHIFT))&SIM_FCFG2_SWAPPFLSH_MASK) /*!< SIM_FCFG2                               */
/* ------- UIDH Bit Fields                          ------ */
#define SIM_UIDH_UID_MASK                        (0xFFFFFFFFUL << SIM_UIDH_UID_SHIFT)                /*!< SIM_UIDH: UID Mask                      */
#define SIM_UIDH_UID_SHIFT                       0                                                   /*!< SIM_UIDH: UID Position                  */
#define SIM_UIDH_UID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UIDH_UID_SHIFT))&SIM_UIDH_UID_MASK) /*!< SIM_UIDH                                */
/* ------- UIDMH Bit Fields                         ------ */
#define SIM_UIDMH_UID_MASK                       (0xFFFFFFFFUL << SIM_UIDMH_UID_SHIFT)               /*!< SIM_UIDMH: UID Mask                     */
#define SIM_UIDMH_UID_SHIFT                      0                                                   /*!< SIM_UIDMH: UID Position                 */
#define SIM_UIDMH_UID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_UIDMH_UID_SHIFT))&SIM_UIDMH_UID_MASK) /*!< SIM_UIDMH                               */
/* ------- UIDML Bit Fields                         ------ */
#define SIM_UIDML_UID_MASK                       (0xFFFFFFFFUL << SIM_UIDML_UID_SHIFT)               /*!< SIM_UIDML: UID Mask                     */
#define SIM_UIDML_UID_SHIFT                      0                                                   /*!< SIM_UIDML: UID Position                 */
#define SIM_UIDML_UID(x)                         (((uint32_t)(((uint32_t)(x))<<SIM_UIDML_UID_SHIFT))&SIM_UIDML_UID_MASK) /*!< SIM_UIDML                               */
/* ------- UIDL Bit Fields                          ------ */
#define SIM_UIDL_UID_MASK                        (0xFFFFFFFFUL << SIM_UIDL_UID_SHIFT)                /*!< SIM_UIDL: UID Mask                      */
#define SIM_UIDL_UID_SHIFT                       0                                                   /*!< SIM_UIDL: UID Position                  */
#define SIM_UIDL_UID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UIDL_UID_SHIFT))&SIM_UIDL_UID_MASK) /*!< SIM_UIDL                                */
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
/* ================           SMC (file:SMC_MK10D7)                ================ */
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
   __IO uint8_t   PMPROT;                       /**< 0000: Power Mode Protection Register                               */
   __IO uint8_t   PMCTRL;                       /**< 0001: Power Mode Control Register                                  */
   __IO uint8_t   VLLSCTRL;                     /**< 0002: VLLS Control Register                                        */
   __I  uint8_t   PMSTAT;                       /**< 0003: Power Mode Status Register                                   */
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
#define SMC_PMPROT_AVLLS_MASK                    (0x01UL << SMC_PMPROT_AVLLS_SHIFT)                  /*!< SMC_PMPROT: AVLLS Mask                  */
#define SMC_PMPROT_AVLLS_SHIFT                   1                                                   /*!< SMC_PMPROT: AVLLS Position              */
#define SMC_PMPROT_AVLLS(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMPROT_AVLLS_SHIFT))&SMC_PMPROT_AVLLS_MASK) /*!< SMC_PMPROT                              */
#define SMC_PMPROT_ALLS_MASK                     (0x01UL << SMC_PMPROT_ALLS_SHIFT)                   /*!< SMC_PMPROT: ALLS Mask                   */
#define SMC_PMPROT_ALLS_SHIFT                    3                                                   /*!< SMC_PMPROT: ALLS Position               */
#define SMC_PMPROT_ALLS(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMPROT_ALLS_SHIFT))&SMC_PMPROT_ALLS_MASK) /*!< SMC_PMPROT                              */
#define SMC_PMPROT_AVLP_MASK                     (0x01UL << SMC_PMPROT_AVLP_SHIFT)                   /*!< SMC_PMPROT: AVLP Mask                   */
#define SMC_PMPROT_AVLP_SHIFT                    5                                                   /*!< SMC_PMPROT: AVLP Position               */
#define SMC_PMPROT_AVLP(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMPROT_AVLP_SHIFT))&SMC_PMPROT_AVLP_MASK) /*!< SMC_PMPROT                              */
/* ------- PMCTRL Bit Fields                        ------ */
#define SMC_PMCTRL_STOPM_MASK                    (0x07UL << SMC_PMCTRL_STOPM_SHIFT)                  /*!< SMC_PMCTRL: STOPM Mask                  */
#define SMC_PMCTRL_STOPM_SHIFT                   0                                                   /*!< SMC_PMCTRL: STOPM Position              */
#define SMC_PMCTRL_STOPM(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_STOPM_SHIFT))&SMC_PMCTRL_STOPM_MASK) /*!< SMC_PMCTRL                              */
#define SMC_PMCTRL_STOPA_MASK                    (0x01UL << SMC_PMCTRL_STOPA_SHIFT)                  /*!< SMC_PMCTRL: STOPA Mask                  */
#define SMC_PMCTRL_STOPA_SHIFT                   3                                                   /*!< SMC_PMCTRL: STOPA Position              */
#define SMC_PMCTRL_STOPA(x)                      (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_STOPA_SHIFT))&SMC_PMCTRL_STOPA_MASK) /*!< SMC_PMCTRL                              */
#define SMC_PMCTRL_RUNM_MASK                     (0x03UL << SMC_PMCTRL_RUNM_SHIFT)                   /*!< SMC_PMCTRL: RUNM Mask                   */
#define SMC_PMCTRL_RUNM_SHIFT                    5                                                   /*!< SMC_PMCTRL: RUNM Position               */
#define SMC_PMCTRL_RUNM(x)                       (((uint8_t)(((uint8_t)(x))<<SMC_PMCTRL_RUNM_SHIFT))&SMC_PMCTRL_RUNM_MASK) /*!< SMC_PMCTRL                              */
/* ------- VLLSCTRL Bit Fields                      ------ */
#define SMC_VLLSCTRL_VLLSM_MASK                  (0x07UL << SMC_VLLSCTRL_VLLSM_SHIFT)                /*!< SMC_VLLSCTRL: VLLSM Mask                */
#define SMC_VLLSCTRL_VLLSM_SHIFT                 0                                                   /*!< SMC_VLLSCTRL: VLLSM Position            */
#define SMC_VLLSCTRL_VLLSM(x)                    (((uint8_t)(((uint8_t)(x))<<SMC_VLLSCTRL_VLLSM_SHIFT))&SMC_VLLSCTRL_VLLSM_MASK) /*!< SMC_VLLSCTRL                            */
/* ------- PMSTAT Bit Fields                        ------ */
#define SMC_PMSTAT_PMSTAT_MASK                   (0x7FUL << SMC_PMSTAT_PMSTAT_SHIFT)                 /*!< SMC_PMSTAT: PMSTAT Mask                 */
#define SMC_PMSTAT_PMSTAT_SHIFT                  0                                                   /*!< SMC_PMSTAT: PMSTAT Position             */
#define SMC_PMSTAT_PMSTAT(x)                     (((uint8_t)(((uint8_t)(x))<<SMC_PMSTAT_PMSTAT_SHIFT))&SMC_PMSTAT_PMSTAT_MASK) /*!< SMC_PMSTAT                              */
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
/* ================           SPI0 (file:SPI0_MK_PCSIS6)           ================ */
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
   __I  uint32_t  RESERVED0;                   
   __IO uint32_t  TCR;                          /**< 0008: Transfer Count Register                                      */
   union {                                      /**< 0000: (size=0008)                                                  */
      __IO uint32_t  CTAR[2];                   /**< 000C: Clock and Transfer Attributes Register (In Master Mode)      */
      __IO uint32_t  CTAR_SLAVE;                /**< 000C: Clock and Transfer Attributes Register (In Slave Mode)       */
   };
   __I  uint32_t  RESERVED1[6];                
   __IO uint32_t  SR;                           /**< 002C: Status register                                              */
   __IO uint32_t  RSER;                         /**< 0030: DMA/Interrupt Request Select and Enable Register             */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  PUSHR;                     /**< 0034: PUSH TX FIFO Register In Master Mode                         */
      __IO uint32_t  PUSHR_SLAVE;               /**< 0034: PUSH TX FIFO Register In Slave Mode                          */
   };
   __I  uint32_t  POPR;                         /**< 0038: POP RX FIFO Register                                         */
   __I  uint32_t  TXFR[4];                      /**< 003C: Transmit FIFO                                                */
   __I  uint32_t  RESERVED2[12];               
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
#define SPI_MCR_HALT_MASK                        (0x01UL << SPI_MCR_HALT_SHIFT)                      /*!< SPI0_MCR: HALT Mask                     */
#define SPI_MCR_HALT_SHIFT                       0                                                   /*!< SPI0_MCR: HALT Position                 */
#define SPI_MCR_HALT(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_MCR_HALT_SHIFT))&SPI_MCR_HALT_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_SMPL_PT_MASK                     (0x03UL << SPI_MCR_SMPL_PT_SHIFT)                   /*!< SPI0_MCR: SMPL_PT Mask                  */
#define SPI_MCR_SMPL_PT_SHIFT                    8                                                   /*!< SPI0_MCR: SMPL_PT Position              */
#define SPI_MCR_SMPL_PT(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_MCR_SMPL_PT_SHIFT))&SPI_MCR_SMPL_PT_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_CLR_RXF_MASK                     (0x01UL << SPI_MCR_CLR_RXF_SHIFT)                   /*!< SPI0_MCR: CLR_RXF Mask                  */
#define SPI_MCR_CLR_RXF_SHIFT                    10                                                  /*!< SPI0_MCR: CLR_RXF Position              */
#define SPI_MCR_CLR_RXF(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_MCR_CLR_RXF_SHIFT))&SPI_MCR_CLR_RXF_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_CLR_TXF_MASK                     (0x01UL << SPI_MCR_CLR_TXF_SHIFT)                   /*!< SPI0_MCR: CLR_TXF Mask                  */
#define SPI_MCR_CLR_TXF_SHIFT                    11                                                  /*!< SPI0_MCR: CLR_TXF Position              */
#define SPI_MCR_CLR_TXF(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_MCR_CLR_TXF_SHIFT))&SPI_MCR_CLR_TXF_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_DIS_RXF_MASK                     (0x01UL << SPI_MCR_DIS_RXF_SHIFT)                   /*!< SPI0_MCR: DIS_RXF Mask                  */
#define SPI_MCR_DIS_RXF_SHIFT                    12                                                  /*!< SPI0_MCR: DIS_RXF Position              */
#define SPI_MCR_DIS_RXF(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_MCR_DIS_RXF_SHIFT))&SPI_MCR_DIS_RXF_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_DIS_TXF_MASK                     (0x01UL << SPI_MCR_DIS_TXF_SHIFT)                   /*!< SPI0_MCR: DIS_TXF Mask                  */
#define SPI_MCR_DIS_TXF_SHIFT                    13                                                  /*!< SPI0_MCR: DIS_TXF Position              */
#define SPI_MCR_DIS_TXF(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_MCR_DIS_TXF_SHIFT))&SPI_MCR_DIS_TXF_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_MDIS_MASK                        (0x01UL << SPI_MCR_MDIS_SHIFT)                      /*!< SPI0_MCR: MDIS Mask                     */
#define SPI_MCR_MDIS_SHIFT                       14                                                  /*!< SPI0_MCR: MDIS Position                 */
#define SPI_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_MCR_MDIS_SHIFT))&SPI_MCR_MDIS_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_DOZE_MASK                        (0x01UL << SPI_MCR_DOZE_SHIFT)                      /*!< SPI0_MCR: DOZE Mask                     */
#define SPI_MCR_DOZE_SHIFT                       15                                                  /*!< SPI0_MCR: DOZE Position                 */
#define SPI_MCR_DOZE(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_MCR_DOZE_SHIFT))&SPI_MCR_DOZE_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_PCSIS_MASK                       (0x3FUL << SPI_MCR_PCSIS_SHIFT)                     /*!< SPI0_MCR: PCSIS Mask                    */
#define SPI_MCR_PCSIS_SHIFT                      16                                                  /*!< SPI0_MCR: PCSIS Position                */
#define SPI_MCR_PCSIS(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_MCR_PCSIS_SHIFT))&SPI_MCR_PCSIS_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_ROOE_MASK                        (0x01UL << SPI_MCR_ROOE_SHIFT)                      /*!< SPI0_MCR: ROOE Mask                     */
#define SPI_MCR_ROOE_SHIFT                       24                                                  /*!< SPI0_MCR: ROOE Position                 */
#define SPI_MCR_ROOE(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_MCR_ROOE_SHIFT))&SPI_MCR_ROOE_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_MTFE_MASK                        (0x01UL << SPI_MCR_MTFE_SHIFT)                      /*!< SPI0_MCR: MTFE Mask                     */
#define SPI_MCR_MTFE_SHIFT                       26                                                  /*!< SPI0_MCR: MTFE Position                 */
#define SPI_MCR_MTFE(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_MCR_MTFE_SHIFT))&SPI_MCR_MTFE_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_FRZ_MASK                         (0x01UL << SPI_MCR_FRZ_SHIFT)                       /*!< SPI0_MCR: FRZ Mask                      */
#define SPI_MCR_FRZ_SHIFT                        27                                                  /*!< SPI0_MCR: FRZ Position                  */
#define SPI_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_MCR_FRZ_SHIFT))&SPI_MCR_FRZ_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_DCONF_MASK                       (0x03UL << SPI_MCR_DCONF_SHIFT)                     /*!< SPI0_MCR: DCONF Mask                    */
#define SPI_MCR_DCONF_SHIFT                      28                                                  /*!< SPI0_MCR: DCONF Position                */
#define SPI_MCR_DCONF(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_MCR_DCONF_SHIFT))&SPI_MCR_DCONF_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_CONT_SCKE_MASK                   (0x01UL << SPI_MCR_CONT_SCKE_SHIFT)                 /*!< SPI0_MCR: CONT_SCKE Mask                */
#define SPI_MCR_CONT_SCKE_SHIFT                  30                                                  /*!< SPI0_MCR: CONT_SCKE Position            */
#define SPI_MCR_CONT_SCKE(x)                     (((uint32_t)(((uint32_t)(x))<<SPI_MCR_CONT_SCKE_SHIFT))&SPI_MCR_CONT_SCKE_MASK) /*!< SPI0_MCR                                */
#define SPI_MCR_MSTR_MASK                        (0x01UL << SPI_MCR_MSTR_SHIFT)                      /*!< SPI0_MCR: MSTR Mask                     */
#define SPI_MCR_MSTR_SHIFT                       31                                                  /*!< SPI0_MCR: MSTR Position                 */
#define SPI_MCR_MSTR(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_MCR_MSTR_SHIFT))&SPI_MCR_MSTR_MASK) /*!< SPI0_MCR                                */
/* ------- TCR Bit Fields                           ------ */
#define SPI_TCR_SPI_TCNT_MASK                    (0xFFFFUL << SPI_TCR_SPI_TCNT_SHIFT)                /*!< SPI0_TCR: SPI_TCNT Mask                 */
#define SPI_TCR_SPI_TCNT_SHIFT                   16                                                  /*!< SPI0_TCR: SPI_TCNT Position             */
#define SPI_TCR_SPI_TCNT(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_TCR_SPI_TCNT_SHIFT))&SPI_TCR_SPI_TCNT_MASK) /*!< SPI0_TCR                                */
/* ------- CTAR Bit Fields                          ------ */
#define SPI_CTAR_BR_MASK                         (0x0FUL << SPI_CTAR_BR_SHIFT)                       /*!< SPI0_CTAR: BR Mask                      */
#define SPI_CTAR_BR_SHIFT                        0                                                   /*!< SPI0_CTAR: BR Position                  */
#define SPI_CTAR_BR(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_BR_SHIFT))&SPI_CTAR_BR_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_DT_MASK                         (0x0FUL << SPI_CTAR_DT_SHIFT)                       /*!< SPI0_CTAR: DT Mask                      */
#define SPI_CTAR_DT_SHIFT                        4                                                   /*!< SPI0_CTAR: DT Position                  */
#define SPI_CTAR_DT(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_DT_SHIFT))&SPI_CTAR_DT_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_ASC_MASK                        (0x0FUL << SPI_CTAR_ASC_SHIFT)                      /*!< SPI0_CTAR: ASC Mask                     */
#define SPI_CTAR_ASC_SHIFT                       8                                                   /*!< SPI0_CTAR: ASC Position                 */
#define SPI_CTAR_ASC(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_ASC_SHIFT))&SPI_CTAR_ASC_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_CSSCK_MASK                      (0x0FUL << SPI_CTAR_CSSCK_SHIFT)                    /*!< SPI0_CTAR: CSSCK Mask                   */
#define SPI_CTAR_CSSCK_SHIFT                     12                                                  /*!< SPI0_CTAR: CSSCK Position               */
#define SPI_CTAR_CSSCK(x)                        (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_CSSCK_SHIFT))&SPI_CTAR_CSSCK_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_PBR_MASK                        (0x03UL << SPI_CTAR_PBR_SHIFT)                      /*!< SPI0_CTAR: PBR Mask                     */
#define SPI_CTAR_PBR_SHIFT                       16                                                  /*!< SPI0_CTAR: PBR Position                 */
#define SPI_CTAR_PBR(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_PBR_SHIFT))&SPI_CTAR_PBR_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_PDT_MASK                        (0x03UL << SPI_CTAR_PDT_SHIFT)                      /*!< SPI0_CTAR: PDT Mask                     */
#define SPI_CTAR_PDT_SHIFT                       18                                                  /*!< SPI0_CTAR: PDT Position                 */
#define SPI_CTAR_PDT(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_PDT_SHIFT))&SPI_CTAR_PDT_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_PASC_MASK                       (0x03UL << SPI_CTAR_PASC_SHIFT)                     /*!< SPI0_CTAR: PASC Mask                    */
#define SPI_CTAR_PASC_SHIFT                      20                                                  /*!< SPI0_CTAR: PASC Position                */
#define SPI_CTAR_PASC(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_PASC_SHIFT))&SPI_CTAR_PASC_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_PCSSCK_MASK                     (0x03UL << SPI_CTAR_PCSSCK_SHIFT)                   /*!< SPI0_CTAR: PCSSCK Mask                  */
#define SPI_CTAR_PCSSCK_SHIFT                    22                                                  /*!< SPI0_CTAR: PCSSCK Position              */
#define SPI_CTAR_PCSSCK(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_PCSSCK_SHIFT))&SPI_CTAR_PCSSCK_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_LSBFE_MASK                      (0x01UL << SPI_CTAR_LSBFE_SHIFT)                    /*!< SPI0_CTAR: LSBFE Mask                   */
#define SPI_CTAR_LSBFE_SHIFT                     24                                                  /*!< SPI0_CTAR: LSBFE Position               */
#define SPI_CTAR_LSBFE(x)                        (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_LSBFE_SHIFT))&SPI_CTAR_LSBFE_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_MODE_MASK                       (0x03UL << SPI_CTAR_MODE_SHIFT)                     /*!< SPI0_CTAR: MODE Mask                    */
#define SPI_CTAR_MODE_SHIFT                      25                                                  /*!< SPI0_CTAR: MODE Position                */
#define SPI_CTAR_MODE(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_MODE_SHIFT))&SPI_CTAR_MODE_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_CPHA_MASK                       (0x01UL << SPI_CTAR_CPHA_SHIFT)                     /*!< SPI0_CTAR: CPHA Mask                    */
#define SPI_CTAR_CPHA_SHIFT                      25                                                  /*!< SPI0_CTAR: CPHA Position                */
#define SPI_CTAR_CPHA(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_CPHA_SHIFT))&SPI_CTAR_CPHA_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_CPOL_MASK                       (0x01UL << SPI_CTAR_CPOL_SHIFT)                     /*!< SPI0_CTAR: CPOL Mask                    */
#define SPI_CTAR_CPOL_SHIFT                      26                                                  /*!< SPI0_CTAR: CPOL Position                */
#define SPI_CTAR_CPOL(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_CPOL_SHIFT))&SPI_CTAR_CPOL_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_FMSZ_MASK                       (0x0FUL << SPI_CTAR_FMSZ_SHIFT)                     /*!< SPI0_CTAR: FMSZ Mask                    */
#define SPI_CTAR_FMSZ_SHIFT                      27                                                  /*!< SPI0_CTAR: FMSZ Position                */
#define SPI_CTAR_FMSZ(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_FMSZ_SHIFT))&SPI_CTAR_FMSZ_MASK) /*!< SPI0_CTAR                               */
#define SPI_CTAR_DBR_MASK                        (0x01UL << SPI_CTAR_DBR_SHIFT)                      /*!< SPI0_CTAR: DBR Mask                     */
#define SPI_CTAR_DBR_SHIFT                       31                                                  /*!< SPI0_CTAR: DBR Position                 */
#define SPI_CTAR_DBR(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_DBR_SHIFT))&SPI_CTAR_DBR_MASK) /*!< SPI0_CTAR                               */
/* ------- CTAR_SLAVE Bit Fields                    ------ */
#define SPI_CTAR_SLAVE_MODE_MASK                 (0x03UL << SPI_CTAR_SLAVE_MODE_SHIFT)               /*!< SPI0_CTAR_SLAVE: MODE Mask              */
#define SPI_CTAR_SLAVE_MODE_SHIFT                25                                                  /*!< SPI0_CTAR_SLAVE: MODE Position          */
#define SPI_CTAR_SLAVE_MODE(x)                   (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_SLAVE_MODE_SHIFT))&SPI_CTAR_SLAVE_MODE_MASK) /*!< SPI0_CTAR_SLAVE                         */
#define SPI_CTAR_SLAVE_CPHA_MASK                 (0x01UL << SPI_CTAR_SLAVE_CPHA_SHIFT)               /*!< SPI0_CTAR_SLAVE: CPHA Mask              */
#define SPI_CTAR_SLAVE_CPHA_SHIFT                25                                                  /*!< SPI0_CTAR_SLAVE: CPHA Position          */
#define SPI_CTAR_SLAVE_CPHA(x)                   (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_SLAVE_CPHA_SHIFT))&SPI_CTAR_SLAVE_CPHA_MASK) /*!< SPI0_CTAR_SLAVE                         */
#define SPI_CTAR_SLAVE_CPOL_MASK                 (0x01UL << SPI_CTAR_SLAVE_CPOL_SHIFT)               /*!< SPI0_CTAR_SLAVE: CPOL Mask              */
#define SPI_CTAR_SLAVE_CPOL_SHIFT                26                                                  /*!< SPI0_CTAR_SLAVE: CPOL Position          */
#define SPI_CTAR_SLAVE_CPOL(x)                   (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_SLAVE_CPOL_SHIFT))&SPI_CTAR_SLAVE_CPOL_MASK) /*!< SPI0_CTAR_SLAVE                         */
#define SPI_CTAR_SLAVE_FMSZ_MASK                 (0x1FUL << SPI_CTAR_SLAVE_FMSZ_SHIFT)               /*!< SPI0_CTAR_SLAVE: FMSZ Mask              */
#define SPI_CTAR_SLAVE_FMSZ_SHIFT                27                                                  /*!< SPI0_CTAR_SLAVE: FMSZ Position          */
#define SPI_CTAR_SLAVE_FMSZ(x)                   (((uint32_t)(((uint32_t)(x))<<SPI_CTAR_SLAVE_FMSZ_SHIFT))&SPI_CTAR_SLAVE_FMSZ_MASK) /*!< SPI0_CTAR_SLAVE                         */
/* ------- SR Bit Fields                            ------ */
#define SPI_SR_POPNXTPTR_MASK                    (0x0FUL << SPI_SR_POPNXTPTR_SHIFT)                  /*!< SPI0_SR: POPNXTPTR Mask                 */
#define SPI_SR_POPNXTPTR_SHIFT                   0                                                   /*!< SPI0_SR: POPNXTPTR Position             */
#define SPI_SR_POPNXTPTR(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_SR_POPNXTPTR_SHIFT))&SPI_SR_POPNXTPTR_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_RXCTR_MASK                        (0x0FUL << SPI_SR_RXCTR_SHIFT)                      /*!< SPI0_SR: RXCTR Mask                     */
#define SPI_SR_RXCTR_SHIFT                       4                                                   /*!< SPI0_SR: RXCTR Position                 */
#define SPI_SR_RXCTR(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_SR_RXCTR_SHIFT))&SPI_SR_RXCTR_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_TXNXTPTR_MASK                     (0x0FUL << SPI_SR_TXNXTPTR_SHIFT)                   /*!< SPI0_SR: TXNXTPTR Mask                  */
#define SPI_SR_TXNXTPTR_SHIFT                    8                                                   /*!< SPI0_SR: TXNXTPTR Position              */
#define SPI_SR_TXNXTPTR(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_SR_TXNXTPTR_SHIFT))&SPI_SR_TXNXTPTR_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_TXCTR_MASK                        (0x0FUL << SPI_SR_TXCTR_SHIFT)                      /*!< SPI0_SR: TXCTR Mask                     */
#define SPI_SR_TXCTR_SHIFT                       12                                                  /*!< SPI0_SR: TXCTR Position                 */
#define SPI_SR_TXCTR(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_SR_TXCTR_SHIFT))&SPI_SR_TXCTR_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_RFDF_MASK                         (0x01UL << SPI_SR_RFDF_SHIFT)                       /*!< SPI0_SR: RFDF Mask                      */
#define SPI_SR_RFDF_SHIFT                        17                                                  /*!< SPI0_SR: RFDF Position                  */
#define SPI_SR_RFDF(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_SR_RFDF_SHIFT))&SPI_SR_RFDF_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_RFOF_MASK                         (0x01UL << SPI_SR_RFOF_SHIFT)                       /*!< SPI0_SR: RFOF Mask                      */
#define SPI_SR_RFOF_SHIFT                        19                                                  /*!< SPI0_SR: RFOF Position                  */
#define SPI_SR_RFOF(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_SR_RFOF_SHIFT))&SPI_SR_RFOF_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_TFFF_MASK                         (0x01UL << SPI_SR_TFFF_SHIFT)                       /*!< SPI0_SR: TFFF Mask                      */
#define SPI_SR_TFFF_SHIFT                        25                                                  /*!< SPI0_SR: TFFF Position                  */
#define SPI_SR_TFFF(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_SR_TFFF_SHIFT))&SPI_SR_TFFF_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_TFUF_MASK                         (0x01UL << SPI_SR_TFUF_SHIFT)                       /*!< SPI0_SR: TFUF Mask                      */
#define SPI_SR_TFUF_SHIFT                        27                                                  /*!< SPI0_SR: TFUF Position                  */
#define SPI_SR_TFUF(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_SR_TFUF_SHIFT))&SPI_SR_TFUF_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_EOQF_MASK                         (0x01UL << SPI_SR_EOQF_SHIFT)                       /*!< SPI0_SR: EOQF Mask                      */
#define SPI_SR_EOQF_SHIFT                        28                                                  /*!< SPI0_SR: EOQF Position                  */
#define SPI_SR_EOQF(x)                           (((uint32_t)(((uint32_t)(x))<<SPI_SR_EOQF_SHIFT))&SPI_SR_EOQF_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_TXRXS_MASK                        (0x01UL << SPI_SR_TXRXS_SHIFT)                      /*!< SPI0_SR: TXRXS Mask                     */
#define SPI_SR_TXRXS_SHIFT                       30                                                  /*!< SPI0_SR: TXRXS Position                 */
#define SPI_SR_TXRXS(x)                          (((uint32_t)(((uint32_t)(x))<<SPI_SR_TXRXS_SHIFT))&SPI_SR_TXRXS_MASK) /*!< SPI0_SR                                 */
#define SPI_SR_TCF_MASK                          (0x01UL << SPI_SR_TCF_SHIFT)                        /*!< SPI0_SR: TCF Mask                       */
#define SPI_SR_TCF_SHIFT                         31                                                  /*!< SPI0_SR: TCF Position                   */
#define SPI_SR_TCF(x)                            (((uint32_t)(((uint32_t)(x))<<SPI_SR_TCF_SHIFT))&SPI_SR_TCF_MASK) /*!< SPI0_SR                                 */
/* ------- RSER Bit Fields                          ------ */
#define SPI_RSER_RFDF_DIRS_MASK                  (0x01UL << SPI_RSER_RFDF_DIRS_SHIFT)                /*!< SPI0_RSER: RFDF_DIRS Mask               */
#define SPI_RSER_RFDF_DIRS_SHIFT                 16                                                  /*!< SPI0_RSER: RFDF_DIRS Position           */
#define SPI_RSER_RFDF_DIRS(x)                    (((uint32_t)(((uint32_t)(x))<<SPI_RSER_RFDF_DIRS_SHIFT))&SPI_RSER_RFDF_DIRS_MASK) /*!< SPI0_RSER                               */
#define SPI_RSER_RFDF_RE_MASK                    (0x01UL << SPI_RSER_RFDF_RE_SHIFT)                  /*!< SPI0_RSER: RFDF_RE Mask                 */
#define SPI_RSER_RFDF_RE_SHIFT                   17                                                  /*!< SPI0_RSER: RFDF_RE Position             */
#define SPI_RSER_RFDF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RSER_RFDF_RE_SHIFT))&SPI_RSER_RFDF_RE_MASK) /*!< SPI0_RSER                               */
#define SPI_RSER_RFOF_RE_MASK                    (0x01UL << SPI_RSER_RFOF_RE_SHIFT)                  /*!< SPI0_RSER: RFOF_RE Mask                 */
#define SPI_RSER_RFOF_RE_SHIFT                   19                                                  /*!< SPI0_RSER: RFOF_RE Position             */
#define SPI_RSER_RFOF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RSER_RFOF_RE_SHIFT))&SPI_RSER_RFOF_RE_MASK) /*!< SPI0_RSER                               */
#define SPI_RSER_TFFF_DIRS_MASK                  (0x01UL << SPI_RSER_TFFF_DIRS_SHIFT)                /*!< SPI0_RSER: TFFF_DIRS Mask               */
#define SPI_RSER_TFFF_DIRS_SHIFT                 24                                                  /*!< SPI0_RSER: TFFF_DIRS Position           */
#define SPI_RSER_TFFF_DIRS(x)                    (((uint32_t)(((uint32_t)(x))<<SPI_RSER_TFFF_DIRS_SHIFT))&SPI_RSER_TFFF_DIRS_MASK) /*!< SPI0_RSER                               */
#define SPI_RSER_TFFF_RE_MASK                    (0x01UL << SPI_RSER_TFFF_RE_SHIFT)                  /*!< SPI0_RSER: TFFF_RE Mask                 */
#define SPI_RSER_TFFF_RE_SHIFT                   25                                                  /*!< SPI0_RSER: TFFF_RE Position             */
#define SPI_RSER_TFFF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RSER_TFFF_RE_SHIFT))&SPI_RSER_TFFF_RE_MASK) /*!< SPI0_RSER                               */
#define SPI_RSER_TFUF_RE_MASK                    (0x01UL << SPI_RSER_TFUF_RE_SHIFT)                  /*!< SPI0_RSER: TFUF_RE Mask                 */
#define SPI_RSER_TFUF_RE_SHIFT                   27                                                  /*!< SPI0_RSER: TFUF_RE Position             */
#define SPI_RSER_TFUF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RSER_TFUF_RE_SHIFT))&SPI_RSER_TFUF_RE_MASK) /*!< SPI0_RSER                               */
#define SPI_RSER_EOQF_RE_MASK                    (0x01UL << SPI_RSER_EOQF_RE_SHIFT)                  /*!< SPI0_RSER: EOQF_RE Mask                 */
#define SPI_RSER_EOQF_RE_SHIFT                   28                                                  /*!< SPI0_RSER: EOQF_RE Position             */
#define SPI_RSER_EOQF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RSER_EOQF_RE_SHIFT))&SPI_RSER_EOQF_RE_MASK) /*!< SPI0_RSER                               */
#define SPI_RSER_TCF_RE_MASK                     (0x01UL << SPI_RSER_TCF_RE_SHIFT)                   /*!< SPI0_RSER: TCF_RE Mask                  */
#define SPI_RSER_TCF_RE_SHIFT                    31                                                  /*!< SPI0_RSER: TCF_RE Position              */
#define SPI_RSER_TCF_RE(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_RSER_TCF_RE_SHIFT))&SPI_RSER_TCF_RE_MASK) /*!< SPI0_RSER                               */
/* ------- PUSHR Bit Fields                         ------ */
#define SPI_PUSHR_TXDATA_MASK                    (0xFFFFUL << SPI_PUSHR_TXDATA_SHIFT)                /*!< SPI0_PUSHR: TXDATA Mask                 */
#define SPI_PUSHR_TXDATA_SHIFT                   0                                                   /*!< SPI0_PUSHR: TXDATA Position             */
#define SPI_PUSHR_TXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_TXDATA_SHIFT))&SPI_PUSHR_TXDATA_MASK) /*!< SPI0_PUSHR                              */
#define SPI_PUSHR_PCS_MASK                       (0x3FUL << SPI_PUSHR_PCS_SHIFT)                     /*!< SPI0_PUSHR: PCS Mask                    */
#define SPI_PUSHR_PCS_SHIFT                      16                                                  /*!< SPI0_PUSHR: PCS Position                */
#define SPI_PUSHR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_PCS_SHIFT))&SPI_PUSHR_PCS_MASK) /*!< SPI0_PUSHR                              */
#define SPI_PUSHR_CTCNT_MASK                     (0x01UL << SPI_PUSHR_CTCNT_SHIFT)                   /*!< SPI0_PUSHR: CTCNT Mask                  */
#define SPI_PUSHR_CTCNT_SHIFT                    26                                                  /*!< SPI0_PUSHR: CTCNT Position              */
#define SPI_PUSHR_CTCNT(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_CTCNT_SHIFT))&SPI_PUSHR_CTCNT_MASK) /*!< SPI0_PUSHR                              */
#define SPI_PUSHR_EOQ_MASK                       (0x01UL << SPI_PUSHR_EOQ_SHIFT)                     /*!< SPI0_PUSHR: EOQ Mask                    */
#define SPI_PUSHR_EOQ_SHIFT                      27                                                  /*!< SPI0_PUSHR: EOQ Position                */
#define SPI_PUSHR_EOQ(x)                         (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_EOQ_SHIFT))&SPI_PUSHR_EOQ_MASK) /*!< SPI0_PUSHR                              */
#define SPI_PUSHR_CTAS_MASK                      (0x07UL << SPI_PUSHR_CTAS_SHIFT)                    /*!< SPI0_PUSHR: CTAS Mask                   */
#define SPI_PUSHR_CTAS_SHIFT                     28                                                  /*!< SPI0_PUSHR: CTAS Position               */
#define SPI_PUSHR_CTAS(x)                        (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_CTAS_SHIFT))&SPI_PUSHR_CTAS_MASK) /*!< SPI0_PUSHR                              */
#define SPI_PUSHR_CONT_MASK                      (0x01UL << SPI_PUSHR_CONT_SHIFT)                    /*!< SPI0_PUSHR: CONT Mask                   */
#define SPI_PUSHR_CONT_SHIFT                     31                                                  /*!< SPI0_PUSHR: CONT Position               */
#define SPI_PUSHR_CONT(x)                        (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_CONT_SHIFT))&SPI_PUSHR_CONT_MASK) /*!< SPI0_PUSHR                              */
/* ------- PUSHR_SLAVE Bit Fields                   ------ */
#define SPI_PUSHR_SLAVE_TXDATA_MASK              (0xFFFFUL << SPI_PUSHR_SLAVE_TXDATA_SHIFT)          /*!< SPI0_PUSHR_SLAVE: TXDATA Mask           */
#define SPI_PUSHR_SLAVE_TXDATA_SHIFT             0                                                   /*!< SPI0_PUSHR_SLAVE: TXDATA Position       */
#define SPI_PUSHR_SLAVE_TXDATA(x)                (((uint32_t)(((uint32_t)(x))<<SPI_PUSHR_SLAVE_TXDATA_SHIFT))&SPI_PUSHR_SLAVE_TXDATA_MASK) /*!< SPI0_PUSHR_SLAVE                        */
/* ------- POPR Bit Fields                          ------ */
#define SPI_POPR_RXDATA_MASK                     (0xFFFFFFFFUL << SPI_POPR_RXDATA_SHIFT)             /*!< SPI0_POPR: RXDATA Mask                  */
#define SPI_POPR_RXDATA_SHIFT                    0                                                   /*!< SPI0_POPR: RXDATA Position              */
#define SPI_POPR_RXDATA(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_POPR_RXDATA_SHIFT))&SPI_POPR_RXDATA_MASK) /*!< SPI0_POPR                               */
/* ------- TXFR Bit Fields                          ------ */
#define SPI_TXFR_TXDATA_MASK                     (0xFFFFUL << SPI_TXFR_TXDATA_SHIFT)                 /*!< SPI0_TXFR: TXDATA Mask                  */
#define SPI_TXFR_TXDATA_SHIFT                    0                                                   /*!< SPI0_TXFR: TXDATA Position              */
#define SPI_TXFR_TXDATA(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_TXFR_TXDATA_SHIFT))&SPI_TXFR_TXDATA_MASK) /*!< SPI0_TXFR                               */
#define SPI_TXFR_TXCMD_TXDATA_MASK               (0xFFFFUL << SPI_TXFR_TXCMD_TXDATA_SHIFT)           /*!< SPI0_TXFR: TXCMD_TXDATA Mask            */
#define SPI_TXFR_TXCMD_TXDATA_SHIFT              16                                                  /*!< SPI0_TXFR: TXCMD_TXDATA Position        */
#define SPI_TXFR_TXCMD_TXDATA(x)                 (((uint32_t)(((uint32_t)(x))<<SPI_TXFR_TXCMD_TXDATA_SHIFT))&SPI_TXFR_TXCMD_TXDATA_MASK) /*!< SPI0_TXFR                               */
/* ------- RXFR Bit Fields                          ------ */
#define SPI_RXFR_RXDATA_MASK                     (0xFFFFFFFFUL << SPI_RXFR_RXDATA_SHIFT)             /*!< SPI0_RXFR: RXDATA Mask                  */
#define SPI_RXFR_RXDATA_SHIFT                    0                                                   /*!< SPI0_RXFR: RXDATA Position              */
#define SPI_RXFR_RXDATA(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_RXFR_RXDATA_SHIFT))&SPI_RXFR_RXDATA_MASK) /*!< SPI0_RXFR                               */
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
#define SYST_CSR_ENABLE_MASK                     (0x01UL << SYST_CSR_ENABLE_SHIFT)                   /*!< SYST_CSR: ENABLE Mask                   */
#define SYST_CSR_ENABLE_SHIFT                    0                                                   /*!< SYST_CSR: ENABLE Position               */
#define SYST_CSR_ENABLE(x)                       (((uint32_t)(((uint32_t)(x))<<SYST_CSR_ENABLE_SHIFT))&SYST_CSR_ENABLE_MASK) /*!< SYST_CSR                                */
#define SYST_CSR_TICKINT_MASK                    (0x01UL << SYST_CSR_TICKINT_SHIFT)                  /*!< SYST_CSR: TICKINT Mask                  */
#define SYST_CSR_TICKINT_SHIFT                   1                                                   /*!< SYST_CSR: TICKINT Position              */
#define SYST_CSR_TICKINT(x)                      (((uint32_t)(((uint32_t)(x))<<SYST_CSR_TICKINT_SHIFT))&SYST_CSR_TICKINT_MASK) /*!< SYST_CSR                                */
#define SYST_CSR_CLKSOURCE_MASK                  (0x01UL << SYST_CSR_CLKSOURCE_SHIFT)                /*!< SYST_CSR: CLKSOURCE Mask                */
#define SYST_CSR_CLKSOURCE_SHIFT                 2                                                   /*!< SYST_CSR: CLKSOURCE Position            */
#define SYST_CSR_CLKSOURCE(x)                    (((uint32_t)(((uint32_t)(x))<<SYST_CSR_CLKSOURCE_SHIFT))&SYST_CSR_CLKSOURCE_MASK) /*!< SYST_CSR                                */
#define SYST_CSR_COUNTFLAG_MASK                  (0x01UL << SYST_CSR_COUNTFLAG_SHIFT)                /*!< SYST_CSR: COUNTFLAG Mask                */
#define SYST_CSR_COUNTFLAG_SHIFT                 16                                                  /*!< SYST_CSR: COUNTFLAG Position            */
#define SYST_CSR_COUNTFLAG(x)                    (((uint32_t)(((uint32_t)(x))<<SYST_CSR_COUNTFLAG_SHIFT))&SYST_CSR_COUNTFLAG_MASK) /*!< SYST_CSR                                */
/* ------- RVR Bit Fields                           ------ */
#define SYST_RVR_RELOAD_MASK                     (0xFFFFFFUL << SYST_RVR_RELOAD_SHIFT)               /*!< SYST_RVR: RELOAD Mask                   */
#define SYST_RVR_RELOAD_SHIFT                    0                                                   /*!< SYST_RVR: RELOAD Position               */
#define SYST_RVR_RELOAD(x)                       (((uint32_t)(((uint32_t)(x))<<SYST_RVR_RELOAD_SHIFT))&SYST_RVR_RELOAD_MASK) /*!< SYST_RVR                                */
/* ------- CVR Bit Fields                           ------ */
#define SYST_CVR_CURRENT_MASK                    (0xFFFFFFUL << SYST_CVR_CURRENT_SHIFT)              /*!< SYST_CVR: CURRENT Mask                  */
#define SYST_CVR_CURRENT_SHIFT                   0                                                   /*!< SYST_CVR: CURRENT Position              */
#define SYST_CVR_CURRENT(x)                      (((uint32_t)(((uint32_t)(x))<<SYST_CVR_CURRENT_SHIFT))&SYST_CVR_CURRENT_MASK) /*!< SYST_CVR                                */
/* ------- CALIB Bit Fields                         ------ */
#define SYST_CALIB_TENMS_MASK                    (0xFFFFFFUL << SYST_CALIB_TENMS_SHIFT)              /*!< SYST_CALIB: TENMS Mask                  */
#define SYST_CALIB_TENMS_SHIFT                   0                                                   /*!< SYST_CALIB: TENMS Position              */
#define SYST_CALIB_TENMS(x)                      (((uint32_t)(((uint32_t)(x))<<SYST_CALIB_TENMS_SHIFT))&SYST_CALIB_TENMS_MASK) /*!< SYST_CALIB                              */
#define SYST_CALIB_SKEW_MASK                     (0x01UL << SYST_CALIB_SKEW_SHIFT)                   /*!< SYST_CALIB: SKEW Mask                   */
#define SYST_CALIB_SKEW_SHIFT                    30                                                  /*!< SYST_CALIB: SKEW Position               */
#define SYST_CALIB_SKEW(x)                       (((uint32_t)(((uint32_t)(x))<<SYST_CALIB_SKEW_SHIFT))&SYST_CALIB_SKEW_MASK) /*!< SYST_CALIB                              */
#define SYST_CALIB_NOREF_MASK                    (0x01UL << SYST_CALIB_NOREF_SHIFT)                  /*!< SYST_CALIB: NOREF Mask                  */
#define SYST_CALIB_NOREF_SHIFT                   31                                                  /*!< SYST_CALIB: NOREF Position              */
#define SYST_CALIB_NOREF(x)                      (((uint32_t)(((uint32_t)(x))<<SYST_CALIB_NOREF_SHIFT))&SYST_CALIB_NOREF_MASK) /*!< SYST_CALIB                              */
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
* @addtogroup TPIU_Peripheral_access_layer_GROUP TPIU Peripheral Access Layer
* @brief C Struct for TPIU
* @{
*/

/* ================================================================================ */
/* ================           TPIU (file:TPIU_0)                   ================ */
/* ================================================================================ */

/**
 * @brief Trace Port Interface Unit
 */
/**
* @addtogroup TPIU_structs_GROUP TPIU struct
* @brief Struct for TPIU
* @{
*/
typedef struct {                                /*       TPIU Structure                                               */
   __I  uint32_t  SSPSR;                        /**< 0000: Supported Parallel Port Size Register                        */
   __IO uint32_t  CSPSR;                        /**< 0004: Current Parallel Port Size Register                          */
   __I  uint32_t  RESERVED0[2];                
   __IO uint32_t  ACPR;                         /**< 0010: Asynchronous Clock Prescaler Register                        */
   __I  uint32_t  RESERVED1[55];               
   __IO uint32_t  SPPR;                         /**< 00F0: Selected Pin Protocol Register                               */
   __I  uint32_t  RESERVED2[131];              
   __I  uint32_t  FFSR;                         /**< 0300: Formatter and Flush Status Register                          */
   __IO uint32_t  FFCR;                         /**< 0304: Formatter and Flush Control Register                         */
   __IO uint32_t  FSCR;                         /**< 0308: Formatter Synchronization Counter Register                   */
   __I  uint32_t  RESERVED3[759];              
   __I  uint32_t  TRIGGER;                      /**< 0EE8: Trigger Register                                             */
   __I  uint32_t  FIFODATA0;                    /**< 0EEC: FIFODATA0 Register                                           */
   __I  uint32_t  ITATBCTR2;                    /**< 0EF0: Integration Test ATB Control 2 Register                      */
   __I  uint32_t  RESERVED4;                   
   __I  uint32_t  ITATBCTR0;                    /**< 0EF8: Integration Test ATB Control 0 Register                      */
   __I  uint32_t  FIFODATA1;                    /**< 0EFC: FIFODATA1 Register                                           */
   __IO uint32_t  ITCTRL;                       /**< 0F00: Integration Mode Control Register                            */
   __I  uint32_t  RESERVED5[39];               
   __IO uint32_t  CLAIMSET;                     /**< 0FA0: Claim Tag Set Register                                       */
   __IO uint32_t  CLAIMCLR;                     /**< 0FA4: Claim Tag Clear Register                                     */
   __I  uint32_t  RESERVED6[8];                
   __I  uint32_t  DEVID;                        /**< 0FC8: TPIU_DEVID Register                                          */
   __I  uint32_t  RESERVED7;                   
   __I  uint32_t  PID4;                         /**< 0FD0: Peripheral Identification Register 4                         */
   __I  uint32_t  PID5;                         /**< 0FD4: Peripheral Identification Register 5                         */
   __I  uint32_t  PID6;                         /**< 0FD8: Peripheral Identification Register 6                         */
   __I  uint32_t  PID7;                         /**< 0FDC: Peripheral Identification Register 7                         */
   __I  uint32_t  PID0;                         /**< 0FE0: Peripheral Identification Register 0                         */
   __I  uint32_t  PID1;                         /**< 0FE4: Peripheral Identification Register 1                         */
   __I  uint32_t  PID2;                         /**< 0FE8: Peripheral Identification Register 2                         */
   __I  uint32_t  PID3;                         /**< 0FEC: Peripheral Identification Register 3                         */
   __I  uint32_t  CID0;                         /**< 0FF0: Component Identification Register 0                          */
   __I  uint32_t  CID1;                         /**< 0FF4: Component Identification Register 1                          */
   __I  uint32_t  CID2;                         /**< 0FF8: Component Identification Register 2                          */
   __I  uint32_t  CID3;                         /**< 0FFC: Component Identification Register 3                          */
} TPIU_Type;

/**
 * @} */ /* End group TPIU_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'TPIU' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup TPIU_Register_Masks_GROUP TPIU Register Masks
* @brief Register Masks for TPIU
* @{
*/
/* ------- SSPSR Bit Fields                         ------ */
#define TPIU_SSPSR_SWIDTH_MASK                   (0xFFFFFFFFUL << TPIU_SSPSR_SWIDTH_SHIFT)           /*!< TPIU_SSPSR: SWIDTH Mask                 */
#define TPIU_SSPSR_SWIDTH_SHIFT                  0                                                   /*!< TPIU_SSPSR: SWIDTH Position             */
#define TPIU_SSPSR_SWIDTH(x)                     (((uint32_t)(((uint32_t)(x))<<TPIU_SSPSR_SWIDTH_SHIFT))&TPIU_SSPSR_SWIDTH_MASK) /*!< TPIU_SSPSR                              */
/* ------- CSPSR Bit Fields                         ------ */
#define TPIU_CSPSR_CWIDTH_MASK                   (0xFFFFFFFFUL << TPIU_CSPSR_CWIDTH_SHIFT)           /*!< TPIU_CSPSR: CWIDTH Mask                 */
#define TPIU_CSPSR_CWIDTH_SHIFT                  0                                                   /*!< TPIU_CSPSR: CWIDTH Position             */
#define TPIU_CSPSR_CWIDTH(x)                     (((uint32_t)(((uint32_t)(x))<<TPIU_CSPSR_CWIDTH_SHIFT))&TPIU_CSPSR_CWIDTH_MASK) /*!< TPIU_CSPSR                              */
/* ------- ACPR Bit Fields                          ------ */
#define TPIU_ACPR_PRESCALER_MASK                 (0x1FFFUL << TPIU_ACPR_PRESCALER_SHIFT)             /*!< TPIU_ACPR: PRESCALER Mask               */
#define TPIU_ACPR_PRESCALER_SHIFT                0                                                   /*!< TPIU_ACPR: PRESCALER Position           */
#define TPIU_ACPR_PRESCALER(x)                   (((uint32_t)(((uint32_t)(x))<<TPIU_ACPR_PRESCALER_SHIFT))&TPIU_ACPR_PRESCALER_MASK) /*!< TPIU_ACPR                               */
/* ------- SPPR Bit Fields                          ------ */
#define TPIU_SPPR_TXMODE_MASK                    (0x03UL << TPIU_SPPR_TXMODE_SHIFT)                  /*!< TPIU_SPPR: TXMODE Mask                  */
#define TPIU_SPPR_TXMODE_SHIFT                   0                                                   /*!< TPIU_SPPR: TXMODE Position              */
#define TPIU_SPPR_TXMODE(x)                      (((uint32_t)(((uint32_t)(x))<<TPIU_SPPR_TXMODE_SHIFT))&TPIU_SPPR_TXMODE_MASK) /*!< TPIU_SPPR                               */
/* ------- FFSR Bit Fields                          ------ */
#define TPIU_FFSR_F1InProg_MASK                  (0x01UL << TPIU_FFSR_F1InProg_SHIFT)                /*!< TPIU_FFSR: F1InProg Mask                */
#define TPIU_FFSR_F1InProg_SHIFT                 0                                                   /*!< TPIU_FFSR: F1InProg Position            */
#define TPIU_FFSR_F1InProg(x)                    (((uint32_t)(((uint32_t)(x))<<TPIU_FFSR_F1InProg_SHIFT))&TPIU_FFSR_F1InProg_MASK) /*!< TPIU_FFSR                               */
#define TPIU_FFSR_FtStopped_MASK                 (0x01UL << TPIU_FFSR_FtStopped_SHIFT)               /*!< TPIU_FFSR: FtStopped Mask               */
#define TPIU_FFSR_FtStopped_SHIFT                1                                                   /*!< TPIU_FFSR: FtStopped Position           */
#define TPIU_FFSR_FtStopped(x)                   (((uint32_t)(((uint32_t)(x))<<TPIU_FFSR_FtStopped_SHIFT))&TPIU_FFSR_FtStopped_MASK) /*!< TPIU_FFSR                               */
#define TPIU_FFSR_TCPresent_MASK                 (0x01UL << TPIU_FFSR_TCPresent_SHIFT)               /*!< TPIU_FFSR: TCPresent Mask               */
#define TPIU_FFSR_TCPresent_SHIFT                2                                                   /*!< TPIU_FFSR: TCPresent Position           */
#define TPIU_FFSR_TCPresent(x)                   (((uint32_t)(((uint32_t)(x))<<TPIU_FFSR_TCPresent_SHIFT))&TPIU_FFSR_TCPresent_MASK) /*!< TPIU_FFSR                               */
#define TPIU_FFSR_FtNonStop_MASK                 (0x01UL << TPIU_FFSR_FtNonStop_SHIFT)               /*!< TPIU_FFSR: FtNonStop Mask               */
#define TPIU_FFSR_FtNonStop_SHIFT                3                                                   /*!< TPIU_FFSR: FtNonStop Position           */
#define TPIU_FFSR_FtNonStop(x)                   (((uint32_t)(((uint32_t)(x))<<TPIU_FFSR_FtNonStop_SHIFT))&TPIU_FFSR_FtNonStop_MASK) /*!< TPIU_FFSR                               */
/* ------- FFCR Bit Fields                          ------ */
#define TPIU_FFCR_EnFCont_MASK                   (0x01UL << TPIU_FFCR_EnFCont_SHIFT)                 /*!< TPIU_FFCR: EnFCont Mask                 */
#define TPIU_FFCR_EnFCont_SHIFT                  1                                                   /*!< TPIU_FFCR: EnFCont Position             */
#define TPIU_FFCR_EnFCont(x)                     (((uint32_t)(((uint32_t)(x))<<TPIU_FFCR_EnFCont_SHIFT))&TPIU_FFCR_EnFCont_MASK) /*!< TPIU_FFCR                               */
#define TPIU_FFCR_TrigIn_MASK                    (0x01UL << TPIU_FFCR_TrigIn_SHIFT)                  /*!< TPIU_FFCR: TrigIn Mask                  */
#define TPIU_FFCR_TrigIn_SHIFT                   8                                                   /*!< TPIU_FFCR: TrigIn Position              */
#define TPIU_FFCR_TrigIn(x)                      (((uint32_t)(((uint32_t)(x))<<TPIU_FFCR_TrigIn_SHIFT))&TPIU_FFCR_TrigIn_MASK) /*!< TPIU_FFCR                               */
/* ------- FSCR Bit Fields                          ------ */
#define TPIU_FSCR_CycCount_MASK                  (0xFFFUL << TPIU_FSCR_CycCount_SHIFT)               /*!< TPIU_FSCR: CycCount Mask                */
#define TPIU_FSCR_CycCount_SHIFT                 0                                                   /*!< TPIU_FSCR: CycCount Position            */
#define TPIU_FSCR_CycCount(x)                    (((uint32_t)(((uint32_t)(x))<<TPIU_FSCR_CycCount_SHIFT))&TPIU_FSCR_CycCount_MASK) /*!< TPIU_FSCR                               */
/* ------- TRIGGER Bit Fields                       ------ */
#define TPIU_TRIGGER_TRIGGER_MASK                (0x01UL << TPIU_TRIGGER_TRIGGER_SHIFT)              /*!< TPIU_TRIGGER: TRIGGER Mask              */
#define TPIU_TRIGGER_TRIGGER_SHIFT               0                                                   /*!< TPIU_TRIGGER: TRIGGER Position          */
#define TPIU_TRIGGER_TRIGGER(x)                  (((uint32_t)(((uint32_t)(x))<<TPIU_TRIGGER_TRIGGER_SHIFT))&TPIU_TRIGGER_TRIGGER_MASK) /*!< TPIU_TRIGGER                            */
/* ------- FIFODATA0 Bit Fields                     ------ */
#define TPIU_FIFODATA0_ETMdata0_MASK             (0xFFUL << TPIU_FIFODATA0_ETMdata0_SHIFT)           /*!< TPIU_FIFODATA0: ETMdata0 Mask           */
#define TPIU_FIFODATA0_ETMdata0_SHIFT            0                                                   /*!< TPIU_FIFODATA0: ETMdata0 Position       */
#define TPIU_FIFODATA0_ETMdata0(x)               (((uint32_t)(((uint32_t)(x))<<TPIU_FIFODATA0_ETMdata0_SHIFT))&TPIU_FIFODATA0_ETMdata0_MASK) /*!< TPIU_FIFODATA0                          */
#define TPIU_FIFODATA0_ETMdata1_MASK             (0xFFUL << TPIU_FIFODATA0_ETMdata1_SHIFT)           /*!< TPIU_FIFODATA0: ETMdata1 Mask           */
#define TPIU_FIFODATA0_ETMdata1_SHIFT            8                                                   /*!< TPIU_FIFODATA0: ETMdata1 Position       */
#define TPIU_FIFODATA0_ETMdata1(x)               (((uint32_t)(((uint32_t)(x))<<TPIU_FIFODATA0_ETMdata1_SHIFT))&TPIU_FIFODATA0_ETMdata1_MASK) /*!< TPIU_FIFODATA0                          */
#define TPIU_FIFODATA0_ETMdata2_MASK             (0xFFUL << TPIU_FIFODATA0_ETMdata2_SHIFT)           /*!< TPIU_FIFODATA0: ETMdata2 Mask           */
#define TPIU_FIFODATA0_ETMdata2_SHIFT            16                                                  /*!< TPIU_FIFODATA0: ETMdata2 Position       */
#define TPIU_FIFODATA0_ETMdata2(x)               (((uint32_t)(((uint32_t)(x))<<TPIU_FIFODATA0_ETMdata2_SHIFT))&TPIU_FIFODATA0_ETMdata2_MASK) /*!< TPIU_FIFODATA0                          */
#define TPIU_FIFODATA0_ETMbytecount_MASK         (0x03UL << TPIU_FIFODATA0_ETMbytecount_SHIFT)       /*!< TPIU_FIFODATA0: ETMbytecount Mask       */
#define TPIU_FIFODATA0_ETMbytecount_SHIFT        24                                                  /*!< TPIU_FIFODATA0: ETMbytecount Position   */
#define TPIU_FIFODATA0_ETMbytecount(x)           (((uint32_t)(((uint32_t)(x))<<TPIU_FIFODATA0_ETMbytecount_SHIFT))&TPIU_FIFODATA0_ETMbytecount_MASK) /*!< TPIU_FIFODATA0                          */
#define TPIU_FIFODATA0_ETMATVALID_MASK           (0x01UL << TPIU_FIFODATA0_ETMATVALID_SHIFT)         /*!< TPIU_FIFODATA0: ETMATVALID Mask         */
#define TPIU_FIFODATA0_ETMATVALID_SHIFT          26                                                  /*!< TPIU_FIFODATA0: ETMATVALID Position     */
#define TPIU_FIFODATA0_ETMATVALID(x)             (((uint32_t)(((uint32_t)(x))<<TPIU_FIFODATA0_ETMATVALID_SHIFT))&TPIU_FIFODATA0_ETMATVALID_MASK) /*!< TPIU_FIFODATA0                          */
#define TPIU_FIFODATA0_ITMbytecount_MASK         (0x03UL << TPIU_FIFODATA0_ITMbytecount_SHIFT)       /*!< TPIU_FIFODATA0: ITMbytecount Mask       */
#define TPIU_FIFODATA0_ITMbytecount_SHIFT        27                                                  /*!< TPIU_FIFODATA0: ITMbytecount Position   */
#define TPIU_FIFODATA0_ITMbytecount(x)           (((uint32_t)(((uint32_t)(x))<<TPIU_FIFODATA0_ITMbytecount_SHIFT))&TPIU_FIFODATA0_ITMbytecount_MASK) /*!< TPIU_FIFODATA0                          */
#define TPIU_FIFODATA0_ITMATVALID_MASK           (0x01UL << TPIU_FIFODATA0_ITMATVALID_SHIFT)         /*!< TPIU_FIFODATA0: ITMATVALID Mask         */
#define TPIU_FIFODATA0_ITMATVALID_SHIFT          29                                                  /*!< TPIU_FIFODATA0: ITMATVALID Position     */
#define TPIU_FIFODATA0_ITMATVALID(x)             (((uint32_t)(((uint32_t)(x))<<TPIU_FIFODATA0_ITMATVALID_SHIFT))&TPIU_FIFODATA0_ITMATVALID_MASK) /*!< TPIU_FIFODATA0                          */
/* ------- ITATBCTR2 Bit Fields                     ------ */
#define TPIU_ITATBCTR2_ATREADY1_ATREADY2_MASK    (0x01UL << TPIU_ITATBCTR2_ATREADY1_ATREADY2_SHIFT)  /*!< TPIU_ITATBCTR2: ATREADY1_ATREADY2 Mask  */
#define TPIU_ITATBCTR2_ATREADY1_ATREADY2_SHIFT   0                                                   /*!< TPIU_ITATBCTR2: ATREADY1_ATREADY2 Position*/
#define TPIU_ITATBCTR2_ATREADY1_ATREADY2(x)      (((uint32_t)(((uint32_t)(x))<<TPIU_ITATBCTR2_ATREADY1_ATREADY2_SHIFT))&TPIU_ITATBCTR2_ATREADY1_ATREADY2_MASK) /*!< TPIU_ITATBCTR2                          */
/* ------- ITATBCTR0 Bit Fields                     ------ */
#define TPIU_ITATBCTR0_ATVALID1_ATVALID2_MASK    (0x01UL << TPIU_ITATBCTR0_ATVALID1_ATVALID2_SHIFT)  /*!< TPIU_ITATBCTR0: ATVALID1_ATVALID2 Mask  */
#define TPIU_ITATBCTR0_ATVALID1_ATVALID2_SHIFT   0                                                   /*!< TPIU_ITATBCTR0: ATVALID1_ATVALID2 Position*/
#define TPIU_ITATBCTR0_ATVALID1_ATVALID2(x)      (((uint32_t)(((uint32_t)(x))<<TPIU_ITATBCTR0_ATVALID1_ATVALID2_SHIFT))&TPIU_ITATBCTR0_ATVALID1_ATVALID2_MASK) /*!< TPIU_ITATBCTR0                          */
/* ------- FIFODATA1 Bit Fields                     ------ */
#define TPIU_FIFODATA1_ITMdata0_MASK             (0xFFUL << TPIU_FIFODATA1_ITMdata0_SHIFT)           /*!< TPIU_FIFODATA1: ITMdata0 Mask           */
#define TPIU_FIFODATA1_ITMdata0_SHIFT            0                                                   /*!< TPIU_FIFODATA1: ITMdata0 Position       */
#define TPIU_FIFODATA1_ITMdata0(x)               (((uint32_t)(((uint32_t)(x))<<TPIU_FIFODATA1_ITMdata0_SHIFT))&TPIU_FIFODATA1_ITMdata0_MASK) /*!< TPIU_FIFODATA1                          */
#define TPIU_FIFODATA1_ITMdata1_MASK             (0xFFUL << TPIU_FIFODATA1_ITMdata1_SHIFT)           /*!< TPIU_FIFODATA1: ITMdata1 Mask           */
#define TPIU_FIFODATA1_ITMdata1_SHIFT            8                                                   /*!< TPIU_FIFODATA1: ITMdata1 Position       */
#define TPIU_FIFODATA1_ITMdata1(x)               (((uint32_t)(((uint32_t)(x))<<TPIU_FIFODATA1_ITMdata1_SHIFT))&TPIU_FIFODATA1_ITMdata1_MASK) /*!< TPIU_FIFODATA1                          */
#define TPIU_FIFODATA1_ITMdata2_MASK             (0xFFUL << TPIU_FIFODATA1_ITMdata2_SHIFT)           /*!< TPIU_FIFODATA1: ITMdata2 Mask           */
#define TPIU_FIFODATA1_ITMdata2_SHIFT            16                                                  /*!< TPIU_FIFODATA1: ITMdata2 Position       */
#define TPIU_FIFODATA1_ITMdata2(x)               (((uint32_t)(((uint32_t)(x))<<TPIU_FIFODATA1_ITMdata2_SHIFT))&TPIU_FIFODATA1_ITMdata2_MASK) /*!< TPIU_FIFODATA1                          */
#define TPIU_FIFODATA1_ETMbytecount_MASK         (0x03UL << TPIU_FIFODATA1_ETMbytecount_SHIFT)       /*!< TPIU_FIFODATA1: ETMbytecount Mask       */
#define TPIU_FIFODATA1_ETMbytecount_SHIFT        24                                                  /*!< TPIU_FIFODATA1: ETMbytecount Position   */
#define TPIU_FIFODATA1_ETMbytecount(x)           (((uint32_t)(((uint32_t)(x))<<TPIU_FIFODATA1_ETMbytecount_SHIFT))&TPIU_FIFODATA1_ETMbytecount_MASK) /*!< TPIU_FIFODATA1                          */
#define TPIU_FIFODATA1_ETMATVALID_MASK           (0x01UL << TPIU_FIFODATA1_ETMATVALID_SHIFT)         /*!< TPIU_FIFODATA1: ETMATVALID Mask         */
#define TPIU_FIFODATA1_ETMATVALID_SHIFT          26                                                  /*!< TPIU_FIFODATA1: ETMATVALID Position     */
#define TPIU_FIFODATA1_ETMATVALID(x)             (((uint32_t)(((uint32_t)(x))<<TPIU_FIFODATA1_ETMATVALID_SHIFT))&TPIU_FIFODATA1_ETMATVALID_MASK) /*!< TPIU_FIFODATA1                          */
#define TPIU_FIFODATA1_ITMbytecount_MASK         (0x03UL << TPIU_FIFODATA1_ITMbytecount_SHIFT)       /*!< TPIU_FIFODATA1: ITMbytecount Mask       */
#define TPIU_FIFODATA1_ITMbytecount_SHIFT        27                                                  /*!< TPIU_FIFODATA1: ITMbytecount Position   */
#define TPIU_FIFODATA1_ITMbytecount(x)           (((uint32_t)(((uint32_t)(x))<<TPIU_FIFODATA1_ITMbytecount_SHIFT))&TPIU_FIFODATA1_ITMbytecount_MASK) /*!< TPIU_FIFODATA1                          */
#define TPIU_FIFODATA1_ITMATVALID_MASK           (0x01UL << TPIU_FIFODATA1_ITMATVALID_SHIFT)         /*!< TPIU_FIFODATA1: ITMATVALID Mask         */
#define TPIU_FIFODATA1_ITMATVALID_SHIFT          29                                                  /*!< TPIU_FIFODATA1: ITMATVALID Position     */
#define TPIU_FIFODATA1_ITMATVALID(x)             (((uint32_t)(((uint32_t)(x))<<TPIU_FIFODATA1_ITMATVALID_SHIFT))&TPIU_FIFODATA1_ITMATVALID_MASK) /*!< TPIU_FIFODATA1                          */
/* ------- ITCTRL Bit Fields                        ------ */
#define TPIU_ITCTRL_Mode_MASK                    (0x03UL << TPIU_ITCTRL_Mode_SHIFT)                  /*!< TPIU_ITCTRL: Mode Mask                  */
#define TPIU_ITCTRL_Mode_SHIFT                   0                                                   /*!< TPIU_ITCTRL: Mode Position              */
#define TPIU_ITCTRL_Mode(x)                      (((uint32_t)(((uint32_t)(x))<<TPIU_ITCTRL_Mode_SHIFT))&TPIU_ITCTRL_Mode_MASK) /*!< TPIU_ITCTRL                             */
/* ------- CLAIMSET Bit Fields                      ------ */
#define TPIU_CLAIMSET_CLAIMSET_MASK              (0x0FUL << TPIU_CLAIMSET_CLAIMSET_SHIFT)            /*!< TPIU_CLAIMSET: CLAIMSET Mask            */
#define TPIU_CLAIMSET_CLAIMSET_SHIFT             0                                                   /*!< TPIU_CLAIMSET: CLAIMSET Position        */
#define TPIU_CLAIMSET_CLAIMSET(x)                (((uint32_t)(((uint32_t)(x))<<TPIU_CLAIMSET_CLAIMSET_SHIFT))&TPIU_CLAIMSET_CLAIMSET_MASK) /*!< TPIU_CLAIMSET                           */
/* ------- CLAIMCLR Bit Fields                      ------ */
#define TPIU_CLAIMCLR_CLAIMCLR_MASK              (0x0FUL << TPIU_CLAIMCLR_CLAIMCLR_SHIFT)            /*!< TPIU_CLAIMCLR: CLAIMCLR Mask            */
#define TPIU_CLAIMCLR_CLAIMCLR_SHIFT             0                                                   /*!< TPIU_CLAIMCLR: CLAIMCLR Position        */
#define TPIU_CLAIMCLR_CLAIMCLR(x)                (((uint32_t)(((uint32_t)(x))<<TPIU_CLAIMCLR_CLAIMCLR_SHIFT))&TPIU_CLAIMCLR_CLAIMCLR_MASK) /*!< TPIU_CLAIMCLR                           */
/* ------- DEVID Bit Fields                         ------ */
#define TPIU_DEVID_NumberOfTraceInputs_MASK      (0x1FUL << TPIU_DEVID_NumberOfTraceInputs_SHIFT)    /*!< TPIU_DEVID: NumberOfTraceInputs Mask    */
#define TPIU_DEVID_NumberOfTraceInputs_SHIFT     0                                                   /*!< TPIU_DEVID: NumberOfTraceInputs Position*/
#define TPIU_DEVID_NumberOfTraceInputs(x)        (((uint32_t)(((uint32_t)(x))<<TPIU_DEVID_NumberOfTraceInputs_SHIFT))&TPIU_DEVID_NumberOfTraceInputs_MASK) /*!< TPIU_DEVID                              */
#define TPIU_DEVID_TRACECELKIN_MASK              (0x01UL << TPIU_DEVID_TRACECELKIN_SHIFT)            /*!< TPIU_DEVID: TRACECELKIN Mask            */
#define TPIU_DEVID_TRACECELKIN_SHIFT             5                                                   /*!< TPIU_DEVID: TRACECELKIN Position        */
#define TPIU_DEVID_TRACECELKIN(x)                (((uint32_t)(((uint32_t)(x))<<TPIU_DEVID_TRACECELKIN_SHIFT))&TPIU_DEVID_TRACECELKIN_MASK) /*!< TPIU_DEVID                              */
#define TPIU_DEVID_MinimumBufferSize_MASK        (0x07UL << TPIU_DEVID_MinimumBufferSize_SHIFT)      /*!< TPIU_DEVID: MinimumBufferSize Mask      */
#define TPIU_DEVID_MinimumBufferSize_SHIFT       6                                                   /*!< TPIU_DEVID: MinimumBufferSize Position  */
#define TPIU_DEVID_MinimumBufferSize(x)          (((uint32_t)(((uint32_t)(x))<<TPIU_DEVID_MinimumBufferSize_SHIFT))&TPIU_DEVID_MinimumBufferSize_MASK) /*!< TPIU_DEVID                              */
#define TPIU_DEVID_TraceAndClockModes_MASK       (0x01UL << TPIU_DEVID_TraceAndClockModes_SHIFT)     /*!< TPIU_DEVID: TraceAndClockModes Mask     */
#define TPIU_DEVID_TraceAndClockModes_SHIFT      9                                                   /*!< TPIU_DEVID: TraceAndClockModes Position */
#define TPIU_DEVID_TraceAndClockModes(x)         (((uint32_t)(((uint32_t)(x))<<TPIU_DEVID_TraceAndClockModes_SHIFT))&TPIU_DEVID_TraceAndClockModes_MASK) /*!< TPIU_DEVID                              */
#define TPIU_DEVID_Manchester_MASK               (0x01UL << TPIU_DEVID_Manchester_SHIFT)             /*!< TPIU_DEVID: Manchester Mask             */
#define TPIU_DEVID_Manchester_SHIFT              10                                                  /*!< TPIU_DEVID: Manchester Position         */
#define TPIU_DEVID_Manchester(x)                 (((uint32_t)(((uint32_t)(x))<<TPIU_DEVID_Manchester_SHIFT))&TPIU_DEVID_Manchester_MASK) /*!< TPIU_DEVID                              */
#define TPIU_DEVID_NRZ_MASK                      (0x01UL << TPIU_DEVID_NRZ_SHIFT)                    /*!< TPIU_DEVID: NRZ Mask                    */
#define TPIU_DEVID_NRZ_SHIFT                     11                                                  /*!< TPIU_DEVID: NRZ Position                */
#define TPIU_DEVID_NRZ(x)                        (((uint32_t)(((uint32_t)(x))<<TPIU_DEVID_NRZ_SHIFT))&TPIU_DEVID_NRZ_MASK) /*!< TPIU_DEVID                              */
/* ------- PID4 Bit Fields                          ------ */
#define TPIU_PID4_JEP106_MASK                    (0x0FUL << TPIU_PID4_JEP106_SHIFT)                  /*!< TPIU_PID4: JEP106 Mask                  */
#define TPIU_PID4_JEP106_SHIFT                   0                                                   /*!< TPIU_PID4: JEP106 Position              */
#define TPIU_PID4_JEP106(x)                      (((uint32_t)(((uint32_t)(x))<<TPIU_PID4_JEP106_SHIFT))&TPIU_PID4_JEP106_MASK) /*!< TPIU_PID4                               */
#define TPIU_PID4_c4KB_MASK                      (0x0FUL << TPIU_PID4_c4KB_SHIFT)                    /*!< TPIU_PID4: c4KB Mask                    */
#define TPIU_PID4_c4KB_SHIFT                     4                                                   /*!< TPIU_PID4: c4KB Position                */
#define TPIU_PID4_c4KB(x)                        (((uint32_t)(((uint32_t)(x))<<TPIU_PID4_c4KB_SHIFT))&TPIU_PID4_c4KB_MASK) /*!< TPIU_PID4                               */
/* ------- PID5 Bit Fields                          ------ */
/* ------- PID6 Bit Fields                          ------ */
/* ------- PID7 Bit Fields                          ------ */
/* ------- PID0 Bit Fields                          ------ */
#define TPIU_PID0_PartNumber_MASK                (0xFFUL << TPIU_PID0_PartNumber_SHIFT)              /*!< TPIU_PID0: PartNumber Mask              */
#define TPIU_PID0_PartNumber_SHIFT               0                                                   /*!< TPIU_PID0: PartNumber Position          */
#define TPIU_PID0_PartNumber(x)                  (((uint32_t)(((uint32_t)(x))<<TPIU_PID0_PartNumber_SHIFT))&TPIU_PID0_PartNumber_MASK) /*!< TPIU_PID0                               */
/* ------- PID1 Bit Fields                          ------ */
#define TPIU_PID1_PartNumber_MASK                (0x0FUL << TPIU_PID1_PartNumber_SHIFT)              /*!< TPIU_PID1: PartNumber Mask              */
#define TPIU_PID1_PartNumber_SHIFT               0                                                   /*!< TPIU_PID1: PartNumber Position          */
#define TPIU_PID1_PartNumber(x)                  (((uint32_t)(((uint32_t)(x))<<TPIU_PID1_PartNumber_SHIFT))&TPIU_PID1_PartNumber_MASK) /*!< TPIU_PID1                               */
#define TPIU_PID1_JEP106_identity_code_MASK      (0x0FUL << TPIU_PID1_JEP106_identity_code_SHIFT)    /*!< TPIU_PID1: JEP106_identity_code Mask    */
#define TPIU_PID1_JEP106_identity_code_SHIFT     4                                                   /*!< TPIU_PID1: JEP106_identity_code Position*/
#define TPIU_PID1_JEP106_identity_code(x)        (((uint32_t)(((uint32_t)(x))<<TPIU_PID1_JEP106_identity_code_SHIFT))&TPIU_PID1_JEP106_identity_code_MASK) /*!< TPIU_PID1                               */
/* ------- PID2 Bit Fields                          ------ */
#define TPIU_PID2_JEP106_identity_code_MASK      (0x07UL << TPIU_PID2_JEP106_identity_code_SHIFT)    /*!< TPIU_PID2: JEP106_identity_code Mask    */
#define TPIU_PID2_JEP106_identity_code_SHIFT     0                                                   /*!< TPIU_PID2: JEP106_identity_code Position*/
#define TPIU_PID2_JEP106_identity_code(x)        (((uint32_t)(((uint32_t)(x))<<TPIU_PID2_JEP106_identity_code_SHIFT))&TPIU_PID2_JEP106_identity_code_MASK) /*!< TPIU_PID2                               */
#define TPIU_PID2_Revision_MASK                  (0x0FUL << TPIU_PID2_Revision_SHIFT)                /*!< TPIU_PID2: Revision Mask                */
#define TPIU_PID2_Revision_SHIFT                 4                                                   /*!< TPIU_PID2: Revision Position            */
#define TPIU_PID2_Revision(x)                    (((uint32_t)(((uint32_t)(x))<<TPIU_PID2_Revision_SHIFT))&TPIU_PID2_Revision_MASK) /*!< TPIU_PID2                               */
/* ------- PID3 Bit Fields                          ------ */
#define TPIU_PID3_CustomerModified_MASK          (0x0FUL << TPIU_PID3_CustomerModified_SHIFT)        /*!< TPIU_PID3: CustomerModified Mask        */
#define TPIU_PID3_CustomerModified_SHIFT         0                                                   /*!< TPIU_PID3: CustomerModified Position    */
#define TPIU_PID3_CustomerModified(x)            (((uint32_t)(((uint32_t)(x))<<TPIU_PID3_CustomerModified_SHIFT))&TPIU_PID3_CustomerModified_MASK) /*!< TPIU_PID3                               */
#define TPIU_PID3_RevAnd_MASK                    (0x0FUL << TPIU_PID3_RevAnd_SHIFT)                  /*!< TPIU_PID3: RevAnd Mask                  */
#define TPIU_PID3_RevAnd_SHIFT                   4                                                   /*!< TPIU_PID3: RevAnd Position              */
#define TPIU_PID3_RevAnd(x)                      (((uint32_t)(((uint32_t)(x))<<TPIU_PID3_RevAnd_SHIFT))&TPIU_PID3_RevAnd_MASK) /*!< TPIU_PID3                               */
/* ------- CID0 Bit Fields                          ------ */
#define TPIU_CID0_Preamble_MASK                  (0xFFUL << TPIU_CID0_Preamble_SHIFT)                /*!< TPIU_CID0: Preamble Mask                */
#define TPIU_CID0_Preamble_SHIFT                 0                                                   /*!< TPIU_CID0: Preamble Position            */
#define TPIU_CID0_Preamble(x)                    (((uint32_t)(((uint32_t)(x))<<TPIU_CID0_Preamble_SHIFT))&TPIU_CID0_Preamble_MASK) /*!< TPIU_CID0                               */
/* ------- CID1 Bit Fields                          ------ */
#define TPIU_CID1_Preamble_MASK                  (0x0FUL << TPIU_CID1_Preamble_SHIFT)                /*!< TPIU_CID1: Preamble Mask                */
#define TPIU_CID1_Preamble_SHIFT                 0                                                   /*!< TPIU_CID1: Preamble Position            */
#define TPIU_CID1_Preamble(x)                    (((uint32_t)(((uint32_t)(x))<<TPIU_CID1_Preamble_SHIFT))&TPIU_CID1_Preamble_MASK) /*!< TPIU_CID1                               */
#define TPIU_CID1_ComponentClass_MASK            (0x0FUL << TPIU_CID1_ComponentClass_SHIFT)          /*!< TPIU_CID1: ComponentClass Mask          */
#define TPIU_CID1_ComponentClass_SHIFT           4                                                   /*!< TPIU_CID1: ComponentClass Position      */
#define TPIU_CID1_ComponentClass(x)              (((uint32_t)(((uint32_t)(x))<<TPIU_CID1_ComponentClass_SHIFT))&TPIU_CID1_ComponentClass_MASK) /*!< TPIU_CID1                               */
/* ------- CID2 Bit Fields                          ------ */
#define TPIU_CID2_Preamble_MASK                  (0xFFUL << TPIU_CID2_Preamble_SHIFT)                /*!< TPIU_CID2: Preamble Mask                */
#define TPIU_CID2_Preamble_SHIFT                 0                                                   /*!< TPIU_CID2: Preamble Position            */
#define TPIU_CID2_Preamble(x)                    (((uint32_t)(((uint32_t)(x))<<TPIU_CID2_Preamble_SHIFT))&TPIU_CID2_Preamble_MASK) /*!< TPIU_CID2                               */
/* ------- CID3 Bit Fields                          ------ */
#define TPIU_CID3_Preamble_MASK                  (0xFFUL << TPIU_CID3_Preamble_SHIFT)                /*!< TPIU_CID3: Preamble Mask                */
#define TPIU_CID3_Preamble_SHIFT                 0                                                   /*!< TPIU_CID3: Preamble Position            */
#define TPIU_CID3_Preamble(x)                    (((uint32_t)(((uint32_t)(x))<<TPIU_CID3_Preamble_SHIFT))&TPIU_CID3_Preamble_MASK) /*!< TPIU_CID3                               */
/**
 * @} */ /* End group TPIU_Register_Masks_GROUP 
 */

/* TPIU - Peripheral instance base addresses */
#define TPIU_BasePtr                   0xE0040000UL //!< Peripheral base address
#define TPIU                           ((TPIU_Type *) TPIU_BasePtr) //!< Freescale base pointer
#define TPIU_BASE_PTR                  (TPIU) //!< Freescale style base pointer
/**
 * @} */ /* End group TPIU_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup TSI_Peripheral_access_layer_GROUP TSI Peripheral Access Layer
* @brief C Struct for TSI
* @{
*/

/* ================================================================================ */
/* ================           TSI0 (file:TSI0_MK10D10)             ================ */
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
   __IO uint32_t  GENCS;                        /**< 0000: General Control and Status Register                          */
   __IO uint32_t  SCANC;                        /**< 0004: SCAN Control Register                                        */
   __IO uint32_t  PEN;                          /**< 0008: Pin Enable Register                                          */
   __I  uint32_t  WUCNTR;                       /**< 000C: Wake-Up Channel Counter Register                             */
   __I  uint32_t  RESERVED0[60];               
   __I  uint32_t  CNTR1;                        /**< 0100: Counter Register 1                                           */
   __I  uint32_t  CNTR3;                        /**< 0104: Counter Register 3                                           */
   __I  uint32_t  CNTR5;                        /**< 0108: Counter Register 5                                           */
   __I  uint32_t  CNTR7;                        /**< 010C: Counter Register 7                                           */
   __I  uint32_t  CNTR9;                        /**< 0110: Counter Register 9                                           */
   __I  uint32_t  CNTR11;                       /**< 0114: Counter Register 11                                          */
   __I  uint32_t  CNTR13;                       /**< 0118: Counter Register 13                                          */
   __I  uint32_t  CNTR15;                       /**< 011C: Counter Register 15                                          */
   __IO uint32_t  THRESHOLD;                    /**< 0120: Low Power Channel Threshold Register                         */
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
#define TSI_GENCS_STPE_MASK                      (0x01UL << TSI_GENCS_STPE_SHIFT)                    /*!< TSI0_GENCS: STPE Mask                   */
#define TSI_GENCS_STPE_SHIFT                     0                                                   /*!< TSI0_GENCS: STPE Position               */
#define TSI_GENCS_STPE(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_STPE_SHIFT))&TSI_GENCS_STPE_MASK) /*!< TSI0_GENCS                              */
#define TSI_GENCS_STM_MASK                       (0x01UL << TSI_GENCS_STM_SHIFT)                     /*!< TSI0_GENCS: STM Mask                    */
#define TSI_GENCS_STM_SHIFT                      1                                                   /*!< TSI0_GENCS: STM Position                */
#define TSI_GENCS_STM(x)                         (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_STM_SHIFT))&TSI_GENCS_STM_MASK) /*!< TSI0_GENCS                              */
#define TSI_GENCS_ESOR_MASK                      (0x01UL << TSI_GENCS_ESOR_SHIFT)                    /*!< TSI0_GENCS: ESOR Mask                   */
#define TSI_GENCS_ESOR_SHIFT                     4                                                   /*!< TSI0_GENCS: ESOR Position               */
#define TSI_GENCS_ESOR(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_ESOR_SHIFT))&TSI_GENCS_ESOR_MASK) /*!< TSI0_GENCS                              */
#define TSI_GENCS_ERIE_MASK                      (0x01UL << TSI_GENCS_ERIE_SHIFT)                    /*!< TSI0_GENCS: ERIE Mask                   */
#define TSI_GENCS_ERIE_SHIFT                     5                                                   /*!< TSI0_GENCS: ERIE Position               */
#define TSI_GENCS_ERIE(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_ERIE_SHIFT))&TSI_GENCS_ERIE_MASK) /*!< TSI0_GENCS                              */
#define TSI_GENCS_TSIIE_MASK                     (0x01UL << TSI_GENCS_TSIIE_SHIFT)                   /*!< TSI0_GENCS: TSIIE Mask                  */
#define TSI_GENCS_TSIIE_SHIFT                    6                                                   /*!< TSI0_GENCS: TSIIE Position              */
#define TSI_GENCS_TSIIE(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_TSIIE_SHIFT))&TSI_GENCS_TSIIE_MASK) /*!< TSI0_GENCS                              */
#define TSI_GENCS_TSIEN_MASK                     (0x01UL << TSI_GENCS_TSIEN_SHIFT)                   /*!< TSI0_GENCS: TSIEN Mask                  */
#define TSI_GENCS_TSIEN_SHIFT                    7                                                   /*!< TSI0_GENCS: TSIEN Position              */
#define TSI_GENCS_TSIEN(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_TSIEN_SHIFT))&TSI_GENCS_TSIEN_MASK) /*!< TSI0_GENCS                              */
#define TSI_GENCS_SWTS_MASK                      (0x01UL << TSI_GENCS_SWTS_SHIFT)                    /*!< TSI0_GENCS: SWTS Mask                   */
#define TSI_GENCS_SWTS_SHIFT                     8                                                   /*!< TSI0_GENCS: SWTS Position               */
#define TSI_GENCS_SWTS(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_SWTS_SHIFT))&TSI_GENCS_SWTS_MASK) /*!< TSI0_GENCS                              */
#define TSI_GENCS_SCNIP_MASK                     (0x01UL << TSI_GENCS_SCNIP_SHIFT)                   /*!< TSI0_GENCS: SCNIP Mask                  */
#define TSI_GENCS_SCNIP_SHIFT                    9                                                   /*!< TSI0_GENCS: SCNIP Position              */
#define TSI_GENCS_SCNIP(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_SCNIP_SHIFT))&TSI_GENCS_SCNIP_MASK) /*!< TSI0_GENCS                              */
#define TSI_GENCS_OVRF_MASK                      (0x01UL << TSI_GENCS_OVRF_SHIFT)                    /*!< TSI0_GENCS: OVRF Mask                   */
#define TSI_GENCS_OVRF_SHIFT                     12                                                  /*!< TSI0_GENCS: OVRF Position               */
#define TSI_GENCS_OVRF(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_OVRF_SHIFT))&TSI_GENCS_OVRF_MASK) /*!< TSI0_GENCS                              */
#define TSI_GENCS_EXTERF_MASK                    (0x01UL << TSI_GENCS_EXTERF_SHIFT)                  /*!< TSI0_GENCS: EXTERF Mask                 */
#define TSI_GENCS_EXTERF_SHIFT                   13                                                  /*!< TSI0_GENCS: EXTERF Position             */
#define TSI_GENCS_EXTERF(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_EXTERF_SHIFT))&TSI_GENCS_EXTERF_MASK) /*!< TSI0_GENCS                              */
#define TSI_GENCS_OUTRGF_MASK                    (0x01UL << TSI_GENCS_OUTRGF_SHIFT)                  /*!< TSI0_GENCS: OUTRGF Mask                 */
#define TSI_GENCS_OUTRGF_SHIFT                   14                                                  /*!< TSI0_GENCS: OUTRGF Position             */
#define TSI_GENCS_OUTRGF(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_OUTRGF_SHIFT))&TSI_GENCS_OUTRGF_MASK) /*!< TSI0_GENCS                              */
#define TSI_GENCS_EOSF_MASK                      (0x01UL << TSI_GENCS_EOSF_SHIFT)                    /*!< TSI0_GENCS: EOSF Mask                   */
#define TSI_GENCS_EOSF_SHIFT                     15                                                  /*!< TSI0_GENCS: EOSF Position               */
#define TSI_GENCS_EOSF(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_EOSF_SHIFT))&TSI_GENCS_EOSF_MASK) /*!< TSI0_GENCS                              */
#define TSI_GENCS_PS_MASK                        (0x07UL << TSI_GENCS_PS_SHIFT)                      /*!< TSI0_GENCS: PS Mask                     */
#define TSI_GENCS_PS_SHIFT                       16                                                  /*!< TSI0_GENCS: PS Position                 */
#define TSI_GENCS_PS(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_PS_SHIFT))&TSI_GENCS_PS_MASK) /*!< TSI0_GENCS                              */
#define TSI_GENCS_NSCN_MASK                      (0x1FUL << TSI_GENCS_NSCN_SHIFT)                    /*!< TSI0_GENCS: NSCN Mask                   */
#define TSI_GENCS_NSCN_SHIFT                     19                                                  /*!< TSI0_GENCS: NSCN Position               */
#define TSI_GENCS_NSCN(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_NSCN_SHIFT))&TSI_GENCS_NSCN_MASK) /*!< TSI0_GENCS                              */
#define TSI_GENCS_LPSCNITV_MASK                  (0x0FUL << TSI_GENCS_LPSCNITV_SHIFT)                /*!< TSI0_GENCS: LPSCNITV Mask               */
#define TSI_GENCS_LPSCNITV_SHIFT                 24                                                  /*!< TSI0_GENCS: LPSCNITV Position           */
#define TSI_GENCS_LPSCNITV(x)                    (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_LPSCNITV_SHIFT))&TSI_GENCS_LPSCNITV_MASK) /*!< TSI0_GENCS                              */
#define TSI_GENCS_LPCLKS_MASK                    (0x01UL << TSI_GENCS_LPCLKS_SHIFT)                  /*!< TSI0_GENCS: LPCLKS Mask                 */
#define TSI_GENCS_LPCLKS_SHIFT                   28                                                  /*!< TSI0_GENCS: LPCLKS Position             */
#define TSI_GENCS_LPCLKS(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_GENCS_LPCLKS_SHIFT))&TSI_GENCS_LPCLKS_MASK) /*!< TSI0_GENCS                              */
/* ------- SCANC Bit Fields                         ------ */
#define TSI_SCANC_AMPSC_MASK                     (0x07UL << TSI_SCANC_AMPSC_SHIFT)                   /*!< TSI0_SCANC: AMPSC Mask                  */
#define TSI_SCANC_AMPSC_SHIFT                    0                                                   /*!< TSI0_SCANC: AMPSC Position              */
#define TSI_SCANC_AMPSC(x)                       (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_AMPSC_SHIFT))&TSI_SCANC_AMPSC_MASK) /*!< TSI0_SCANC                              */
#define TSI_SCANC_AMCLKS_MASK                    (0x03UL << TSI_SCANC_AMCLKS_SHIFT)                  /*!< TSI0_SCANC: AMCLKS Mask                 */
#define TSI_SCANC_AMCLKS_SHIFT                   3                                                   /*!< TSI0_SCANC: AMCLKS Position             */
#define TSI_SCANC_AMCLKS(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_AMCLKS_SHIFT))&TSI_SCANC_AMCLKS_MASK) /*!< TSI0_SCANC                              */
#define TSI_SCANC_SMOD_MASK                      (0xFFUL << TSI_SCANC_SMOD_SHIFT)                    /*!< TSI0_SCANC: SMOD Mask                   */
#define TSI_SCANC_SMOD_SHIFT                     8                                                   /*!< TSI0_SCANC: SMOD Position               */
#define TSI_SCANC_SMOD(x)                        (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_SMOD_SHIFT))&TSI_SCANC_SMOD_MASK) /*!< TSI0_SCANC                              */
#define TSI_SCANC_EXTCHRG_MASK                   (0x0FUL << TSI_SCANC_EXTCHRG_SHIFT)                 /*!< TSI0_SCANC: EXTCHRG Mask                */
#define TSI_SCANC_EXTCHRG_SHIFT                  16                                                  /*!< TSI0_SCANC: EXTCHRG Position            */
#define TSI_SCANC_EXTCHRG(x)                     (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_EXTCHRG_SHIFT))&TSI_SCANC_EXTCHRG_MASK) /*!< TSI0_SCANC                              */
#define TSI_SCANC_REFCHRG_MASK                   (0x0FUL << TSI_SCANC_REFCHRG_SHIFT)                 /*!< TSI0_SCANC: REFCHRG Mask                */
#define TSI_SCANC_REFCHRG_SHIFT                  24                                                  /*!< TSI0_SCANC: REFCHRG Position            */
#define TSI_SCANC_REFCHRG(x)                     (((uint32_t)(((uint32_t)(x))<<TSI_SCANC_REFCHRG_SHIFT))&TSI_SCANC_REFCHRG_MASK) /*!< TSI0_SCANC                              */
/* ------- PEN Bit Fields                           ------ */
#define TSI_PEN_PEN0_MASK                        (0x01UL << TSI_PEN_PEN0_SHIFT)                      /*!< TSI0_PEN: PEN0 Mask                     */
#define TSI_PEN_PEN0_SHIFT                       0                                                   /*!< TSI0_PEN: PEN0 Position                 */
#define TSI_PEN_PEN0(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_PEN_PEN0_SHIFT))&TSI_PEN_PEN0_MASK) /*!< TSI0_PEN                                */
#define TSI_PEN_PEN1_MASK                        (0x01UL << TSI_PEN_PEN1_SHIFT)                      /*!< TSI0_PEN: PEN1 Mask                     */
#define TSI_PEN_PEN1_SHIFT                       1                                                   /*!< TSI0_PEN: PEN1 Position                 */
#define TSI_PEN_PEN1(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_PEN_PEN1_SHIFT))&TSI_PEN_PEN1_MASK) /*!< TSI0_PEN                                */
#define TSI_PEN_PEN2_MASK                        (0x01UL << TSI_PEN_PEN2_SHIFT)                      /*!< TSI0_PEN: PEN2 Mask                     */
#define TSI_PEN_PEN2_SHIFT                       2                                                   /*!< TSI0_PEN: PEN2 Position                 */
#define TSI_PEN_PEN2(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_PEN_PEN2_SHIFT))&TSI_PEN_PEN2_MASK) /*!< TSI0_PEN                                */
#define TSI_PEN_PEN3_MASK                        (0x01UL << TSI_PEN_PEN3_SHIFT)                      /*!< TSI0_PEN: PEN3 Mask                     */
#define TSI_PEN_PEN3_SHIFT                       3                                                   /*!< TSI0_PEN: PEN3 Position                 */
#define TSI_PEN_PEN3(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_PEN_PEN3_SHIFT))&TSI_PEN_PEN3_MASK) /*!< TSI0_PEN                                */
#define TSI_PEN_PEN4_MASK                        (0x01UL << TSI_PEN_PEN4_SHIFT)                      /*!< TSI0_PEN: PEN4 Mask                     */
#define TSI_PEN_PEN4_SHIFT                       4                                                   /*!< TSI0_PEN: PEN4 Position                 */
#define TSI_PEN_PEN4(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_PEN_PEN4_SHIFT))&TSI_PEN_PEN4_MASK) /*!< TSI0_PEN                                */
#define TSI_PEN_PEN5_MASK                        (0x01UL << TSI_PEN_PEN5_SHIFT)                      /*!< TSI0_PEN: PEN5 Mask                     */
#define TSI_PEN_PEN5_SHIFT                       5                                                   /*!< TSI0_PEN: PEN5 Position                 */
#define TSI_PEN_PEN5(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_PEN_PEN5_SHIFT))&TSI_PEN_PEN5_MASK) /*!< TSI0_PEN                                */
#define TSI_PEN_PEN6_MASK                        (0x01UL << TSI_PEN_PEN6_SHIFT)                      /*!< TSI0_PEN: PEN6 Mask                     */
#define TSI_PEN_PEN6_SHIFT                       6                                                   /*!< TSI0_PEN: PEN6 Position                 */
#define TSI_PEN_PEN6(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_PEN_PEN6_SHIFT))&TSI_PEN_PEN6_MASK) /*!< TSI0_PEN                                */
#define TSI_PEN_PEN7_MASK                        (0x01UL << TSI_PEN_PEN7_SHIFT)                      /*!< TSI0_PEN: PEN7 Mask                     */
#define TSI_PEN_PEN7_SHIFT                       7                                                   /*!< TSI0_PEN: PEN7 Position                 */
#define TSI_PEN_PEN7(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_PEN_PEN7_SHIFT))&TSI_PEN_PEN7_MASK) /*!< TSI0_PEN                                */
#define TSI_PEN_PEN8_MASK                        (0x01UL << TSI_PEN_PEN8_SHIFT)                      /*!< TSI0_PEN: PEN8 Mask                     */
#define TSI_PEN_PEN8_SHIFT                       8                                                   /*!< TSI0_PEN: PEN8 Position                 */
#define TSI_PEN_PEN8(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_PEN_PEN8_SHIFT))&TSI_PEN_PEN8_MASK) /*!< TSI0_PEN                                */
#define TSI_PEN_PEN9_MASK                        (0x01UL << TSI_PEN_PEN9_SHIFT)                      /*!< TSI0_PEN: PEN9 Mask                     */
#define TSI_PEN_PEN9_SHIFT                       9                                                   /*!< TSI0_PEN: PEN9 Position                 */
#define TSI_PEN_PEN9(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_PEN_PEN9_SHIFT))&TSI_PEN_PEN9_MASK) /*!< TSI0_PEN                                */
#define TSI_PEN_PEN10_MASK                       (0x01UL << TSI_PEN_PEN10_SHIFT)                     /*!< TSI0_PEN: PEN10 Mask                    */
#define TSI_PEN_PEN10_SHIFT                      10                                                  /*!< TSI0_PEN: PEN10 Position                */
#define TSI_PEN_PEN10(x)                         (((uint32_t)(((uint32_t)(x))<<TSI_PEN_PEN10_SHIFT))&TSI_PEN_PEN10_MASK) /*!< TSI0_PEN                                */
#define TSI_PEN_PEN11_MASK                       (0x01UL << TSI_PEN_PEN11_SHIFT)                     /*!< TSI0_PEN: PEN11 Mask                    */
#define TSI_PEN_PEN11_SHIFT                      11                                                  /*!< TSI0_PEN: PEN11 Position                */
#define TSI_PEN_PEN11(x)                         (((uint32_t)(((uint32_t)(x))<<TSI_PEN_PEN11_SHIFT))&TSI_PEN_PEN11_MASK) /*!< TSI0_PEN                                */
#define TSI_PEN_PEN12_MASK                       (0x01UL << TSI_PEN_PEN12_SHIFT)                     /*!< TSI0_PEN: PEN12 Mask                    */
#define TSI_PEN_PEN12_SHIFT                      12                                                  /*!< TSI0_PEN: PEN12 Position                */
#define TSI_PEN_PEN12(x)                         (((uint32_t)(((uint32_t)(x))<<TSI_PEN_PEN12_SHIFT))&TSI_PEN_PEN12_MASK) /*!< TSI0_PEN                                */
#define TSI_PEN_PEN13_MASK                       (0x01UL << TSI_PEN_PEN13_SHIFT)                     /*!< TSI0_PEN: PEN13 Mask                    */
#define TSI_PEN_PEN13_SHIFT                      13                                                  /*!< TSI0_PEN: PEN13 Position                */
#define TSI_PEN_PEN13(x)                         (((uint32_t)(((uint32_t)(x))<<TSI_PEN_PEN13_SHIFT))&TSI_PEN_PEN13_MASK) /*!< TSI0_PEN                                */
#define TSI_PEN_PEN14_MASK                       (0x01UL << TSI_PEN_PEN14_SHIFT)                     /*!< TSI0_PEN: PEN14 Mask                    */
#define TSI_PEN_PEN14_SHIFT                      14                                                  /*!< TSI0_PEN: PEN14 Position                */
#define TSI_PEN_PEN14(x)                         (((uint32_t)(((uint32_t)(x))<<TSI_PEN_PEN14_SHIFT))&TSI_PEN_PEN14_MASK) /*!< TSI0_PEN                                */
#define TSI_PEN_PEN15_MASK                       (0x01UL << TSI_PEN_PEN15_SHIFT)                     /*!< TSI0_PEN: PEN15 Mask                    */
#define TSI_PEN_PEN15_SHIFT                      15                                                  /*!< TSI0_PEN: PEN15 Position                */
#define TSI_PEN_PEN15(x)                         (((uint32_t)(((uint32_t)(x))<<TSI_PEN_PEN15_SHIFT))&TSI_PEN_PEN15_MASK) /*!< TSI0_PEN                                */
#define TSI_PEN_LPSP_MASK                        (0x0FUL << TSI_PEN_LPSP_SHIFT)                      /*!< TSI0_PEN: LPSP Mask                     */
#define TSI_PEN_LPSP_SHIFT                       16                                                  /*!< TSI0_PEN: LPSP Position                 */
#define TSI_PEN_LPSP(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_PEN_LPSP_SHIFT))&TSI_PEN_LPSP_MASK) /*!< TSI0_PEN                                */
/* ------- WUCNTR Bit Fields                        ------ */
#define TSI_WUCNTR_WUCNT_MASK                    (0xFFFFUL << TSI_WUCNTR_WUCNT_SHIFT)                /*!< TSI0_WUCNTR: WUCNT Mask                 */
#define TSI_WUCNTR_WUCNT_SHIFT                   0                                                   /*!< TSI0_WUCNTR: WUCNT Position             */
#define TSI_WUCNTR_WUCNT(x)                      (((uint32_t)(((uint32_t)(x))<<TSI_WUCNTR_WUCNT_SHIFT))&TSI_WUCNTR_WUCNT_MASK) /*!< TSI0_WUCNTR                             */
/* ------- CNTR Bit Fields                          ------ */
#define TSI_CNTR_CTN1_MASK                       (0xFFFFUL << TSI_CNTR_CTN1_SHIFT)                   /*!< TSI0_CNTR: CTN1 Mask                    */
#define TSI_CNTR_CTN1_SHIFT                      0                                                   /*!< TSI0_CNTR: CTN1 Position                */
#define TSI_CNTR_CTN1(x)                         (((uint32_t)(((uint32_t)(x))<<TSI_CNTR_CTN1_SHIFT))&TSI_CNTR_CTN1_MASK) /*!< TSI0_CNTR                               */
#define TSI_CNTR_CTN_MASK                        (0xFFFFUL << TSI_CNTR_CTN_SHIFT)                    /*!< TSI0_CNTR: CTN Mask                     */
#define TSI_CNTR_CTN_SHIFT                       16                                                  /*!< TSI0_CNTR: CTN Position                 */
#define TSI_CNTR_CTN(x)                          (((uint32_t)(((uint32_t)(x))<<TSI_CNTR_CTN_SHIFT))&TSI_CNTR_CTN_MASK) /*!< TSI0_CNTR                               */
/* ------- THRESHOLD Bit Fields                     ------ */
#define TSI_THRESHOLD_HTHH_MASK                  (0xFFFFUL << TSI_THRESHOLD_HTHH_SHIFT)              /*!< TSI0_THRESHOLD: HTHH Mask               */
#define TSI_THRESHOLD_HTHH_SHIFT                 0                                                   /*!< TSI0_THRESHOLD: HTHH Position           */
#define TSI_THRESHOLD_HTHH(x)                    (((uint32_t)(((uint32_t)(x))<<TSI_THRESHOLD_HTHH_SHIFT))&TSI_THRESHOLD_HTHH_MASK) /*!< TSI0_THRESHOLD                          */
#define TSI_THRESHOLD_LTHH_MASK                  (0xFFFFUL << TSI_THRESHOLD_LTHH_SHIFT)              /*!< TSI0_THRESHOLD: LTHH Mask               */
#define TSI_THRESHOLD_LTHH_SHIFT                 16                                                  /*!< TSI0_THRESHOLD: LTHH Position           */
#define TSI_THRESHOLD_LTHH(x)                    (((uint32_t)(((uint32_t)(x))<<TSI_THRESHOLD_LTHH_SHIFT))&TSI_THRESHOLD_LTHH_MASK) /*!< TSI0_THRESHOLD                          */
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
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART0 (file:UART0_MK10D7_C7816)       ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */
/**
* @addtogroup UART_structs_GROUP UART struct
* @brief Struct for UART
* @{
*/
typedef struct {                                /*       UART0 Structure                                              */
   __IO uint8_t   BDH;                          /**< 0000: Baud Rate Register: High                                     */
   __IO uint8_t   BDL;                          /**< 0001: Baud Rate Register: Low                                      */
   __IO uint8_t   C1;                           /**< 0002: Control Register 1                                           */
   __IO uint8_t   C2;                           /**< 0003: Control Register 2                                           */
   __I  uint8_t   S1;                           /**< 0004: Status Register 1                                            */
   __IO uint8_t   S2;                           /**< 0005: Status Register 2                                            */
   __IO uint8_t   C3;                           /**< 0006: Control Register 3                                           */
   __IO uint8_t   D;                            /**< 0007: Data Register                                                */
   __IO uint8_t   MA1;                          /**< 0008: Match Address Registers 1                                    */
   __IO uint8_t   MA2;                          /**< 0009: Match Address Registers 2                                    */
   __IO uint8_t   C4;                           /**< 000A: Control Register 4                                           */
   __IO uint8_t   C5;                           /**< 000B: Control Register 5                                           */
   __I  uint8_t   ED;                           /**< 000C: Extended Data Register                                       */
   __IO uint8_t   MODEM;                        /**< 000D: Modem Register                                               */
   __IO uint8_t   IR;                           /**< 000E: Infrared Register                                            */
   __I  uint8_t   RESERVED0;                   
   __IO uint8_t   PFIFO;                        /**< 0010: FIFO Parameters                                              */
   __IO uint8_t   CFIFO;                        /**< 0011: FIFO Control Register                                        */
   __IO uint8_t   SFIFO;                        /**< 0012: FIFO Status Register                                         */
   __IO uint8_t   TWFIFO;                       /**< 0013: FIFO Transmit Watermark                                      */
   __I  uint8_t   TCFIFO;                       /**< 0014: FIFO Transmit Count                                          */
   __IO uint8_t   RWFIFO;                       /**< 0015: FIFO Receive Watermark                                       */
   __I  uint8_t   RCFIFO;                       /**< 0016: FIFO Receive Count                                           */
   __I  uint8_t   RESERVED1;                   
   __IO uint8_t   C7816;                        /**< 0018: 7816 Control Register                                        */
   __IO uint8_t   IE7816;                       /**< 0019: 7816 Interrupt Enable Register                               */
   __IO uint8_t   IS7816;                       /**< 001A: 7816 Interrupt Status Register                               */
   union {                                      /**< 0000: (size=0001)                                                  */
      __IO uint8_t   WP7816T0;                  /**< 001B: 7816 Wait Parameter Register                                 */
      __IO uint8_t   WP7816T1;                  /**< 001B: 7816 Wait Parameter Register                                 */
   };
   __IO uint8_t   WN7816;                       /**< 001C: 7816 Wait N Register                                         */
   __IO uint8_t   WF7816;                       /**< 001D: 7816 Wait FD Register                                        */
   __IO uint8_t   ET7816;                       /**< 001E: 7816 Error Threshold Register                                */
   __IO uint8_t   TL7816;                       /**< 001F: 7816 Transmit Length Register                                */
} UART_Type;

/**
 * @} */ /* End group UART_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'UART0' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup UART_Register_Masks_GROUP UART Register Masks
* @brief Register Masks for UART
* @{
*/
/* ------- BDH Bit Fields                           ------ */
#define UART_BDH_SBR_MASK                        (0x1FUL << UART_BDH_SBR_SHIFT)                      /*!< UART0_BDH: SBR Mask                     */
#define UART_BDH_SBR_SHIFT                       0                                                   /*!< UART0_BDH: SBR Position                 */
#define UART_BDH_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDH_SBR_SHIFT))&UART_BDH_SBR_MASK) /*!< UART0_BDH                               */
#define UART_BDH_RXEDGIE_MASK                    (0x01UL << UART_BDH_RXEDGIE_SHIFT)                  /*!< UART0_BDH: RXEDGIE Mask                 */
#define UART_BDH_RXEDGIE_SHIFT                   6                                                   /*!< UART0_BDH: RXEDGIE Position             */
#define UART_BDH_RXEDGIE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_BDH_RXEDGIE_SHIFT))&UART_BDH_RXEDGIE_MASK) /*!< UART0_BDH                               */
#define UART_BDH_LBKDIE_MASK                     (0x01UL << UART_BDH_LBKDIE_SHIFT)                   /*!< UART0_BDH: LBKDIE Mask                  */
#define UART_BDH_LBKDIE_SHIFT                    7                                                   /*!< UART0_BDH: LBKDIE Position              */
#define UART_BDH_LBKDIE(x)                       (((uint8_t)(((uint8_t)(x))<<UART_BDH_LBKDIE_SHIFT))&UART_BDH_LBKDIE_MASK) /*!< UART0_BDH                               */
/* ------- BDL Bit Fields                           ------ */
#define UART_BDL_SBR_MASK                        (0xFFUL << UART_BDL_SBR_SHIFT)                      /*!< UART0_BDL: SBR Mask                     */
#define UART_BDL_SBR_SHIFT                       0                                                   /*!< UART0_BDL: SBR Position                 */
#define UART_BDL_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDL_SBR_SHIFT))&UART_BDL_SBR_MASK) /*!< UART0_BDL                               */
/* ------- C1 Bit Fields                            ------ */
#define UART_C1_PT_MASK                          (0x01UL << UART_C1_PT_SHIFT)                        /*!< UART0_C1: PT Mask                       */
#define UART_C1_PT_SHIFT                         0                                                   /*!< UART0_C1: PT Position                   */
#define UART_C1_PT(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C1_PT_SHIFT))&UART_C1_PT_MASK) /*!< UART0_C1                                */
#define UART_C1_PE_MASK                          (0x01UL << UART_C1_PE_SHIFT)                        /*!< UART0_C1: PE Mask                       */
#define UART_C1_PE_SHIFT                         1                                                   /*!< UART0_C1: PE Position                   */
#define UART_C1_PE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C1_PE_SHIFT))&UART_C1_PE_MASK) /*!< UART0_C1                                */
#define UART_C1_ILT_MASK                         (0x01UL << UART_C1_ILT_SHIFT)                       /*!< UART0_C1: ILT Mask                      */
#define UART_C1_ILT_SHIFT                        2                                                   /*!< UART0_C1: ILT Position                  */
#define UART_C1_ILT(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C1_ILT_SHIFT))&UART_C1_ILT_MASK) /*!< UART0_C1                                */
#define UART_C1_WAKE_MASK                        (0x01UL << UART_C1_WAKE_SHIFT)                      /*!< UART0_C1: WAKE Mask                     */
#define UART_C1_WAKE_SHIFT                       3                                                   /*!< UART0_C1: WAKE Position                 */
#define UART_C1_WAKE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C1_WAKE_SHIFT))&UART_C1_WAKE_MASK) /*!< UART0_C1                                */
#define UART_C1_M_MASK                           (0x01UL << UART_C1_M_SHIFT)                         /*!< UART0_C1: M Mask                        */
#define UART_C1_M_SHIFT                          4                                                   /*!< UART0_C1: M Position                    */
#define UART_C1_M(x)                             (((uint8_t)(((uint8_t)(x))<<UART_C1_M_SHIFT))&UART_C1_M_MASK) /*!< UART0_C1                                */
#define UART_C1_RSRC_MASK                        (0x01UL << UART_C1_RSRC_SHIFT)                      /*!< UART0_C1: RSRC Mask                     */
#define UART_C1_RSRC_SHIFT                       5                                                   /*!< UART0_C1: RSRC Position                 */
#define UART_C1_RSRC(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C1_RSRC_SHIFT))&UART_C1_RSRC_MASK) /*!< UART0_C1                                */
#define UART_C1_UARTSWAI_MASK                    (0x01UL << UART_C1_UARTSWAI_SHIFT)                  /*!< UART0_C1: UARTSWAI Mask                 */
#define UART_C1_UARTSWAI_SHIFT                   6                                                   /*!< UART0_C1: UARTSWAI Position             */
#define UART_C1_UARTSWAI(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C1_UARTSWAI_SHIFT))&UART_C1_UARTSWAI_MASK) /*!< UART0_C1                                */
#define UART_C1_LOOPS_MASK                       (0x01UL << UART_C1_LOOPS_SHIFT)                     /*!< UART0_C1: LOOPS Mask                    */
#define UART_C1_LOOPS_SHIFT                      7                                                   /*!< UART0_C1: LOOPS Position                */
#define UART_C1_LOOPS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C1_LOOPS_SHIFT))&UART_C1_LOOPS_MASK) /*!< UART0_C1                                */
/* ------- C2 Bit Fields                            ------ */
#define UART_C2_SBK_MASK                         (0x01UL << UART_C2_SBK_SHIFT)                       /*!< UART0_C2: SBK Mask                      */
#define UART_C2_SBK_SHIFT                        0                                                   /*!< UART0_C2: SBK Position                  */
#define UART_C2_SBK(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_SBK_SHIFT))&UART_C2_SBK_MASK) /*!< UART0_C2                                */
#define UART_C2_RWU_MASK                         (0x01UL << UART_C2_RWU_SHIFT)                       /*!< UART0_C2: RWU Mask                      */
#define UART_C2_RWU_SHIFT                        1                                                   /*!< UART0_C2: RWU Position                  */
#define UART_C2_RWU(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_RWU_SHIFT))&UART_C2_RWU_MASK) /*!< UART0_C2                                */
#define UART_C2_RE_MASK                          (0x01UL << UART_C2_RE_SHIFT)                        /*!< UART0_C2: RE Mask                       */
#define UART_C2_RE_SHIFT                         2                                                   /*!< UART0_C2: RE Position                   */
#define UART_C2_RE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C2_RE_SHIFT))&UART_C2_RE_MASK) /*!< UART0_C2                                */
#define UART_C2_TE_MASK                          (0x01UL << UART_C2_TE_SHIFT)                        /*!< UART0_C2: TE Mask                       */
#define UART_C2_TE_SHIFT                         3                                                   /*!< UART0_C2: TE Position                   */
#define UART_C2_TE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C2_TE_SHIFT))&UART_C2_TE_MASK) /*!< UART0_C2                                */
#define UART_C2_ILIE_MASK                        (0x01UL << UART_C2_ILIE_SHIFT)                      /*!< UART0_C2: ILIE Mask                     */
#define UART_C2_ILIE_SHIFT                       4                                                   /*!< UART0_C2: ILIE Position                 */
#define UART_C2_ILIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C2_ILIE_SHIFT))&UART_C2_ILIE_MASK) /*!< UART0_C2                                */
#define UART_C2_RIE_MASK                         (0x01UL << UART_C2_RIE_SHIFT)                       /*!< UART0_C2: RIE Mask                      */
#define UART_C2_RIE_SHIFT                        5                                                   /*!< UART0_C2: RIE Position                  */
#define UART_C2_RIE(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_RIE_SHIFT))&UART_C2_RIE_MASK) /*!< UART0_C2                                */
#define UART_C2_TCIE_MASK                        (0x01UL << UART_C2_TCIE_SHIFT)                      /*!< UART0_C2: TCIE Mask                     */
#define UART_C2_TCIE_SHIFT                       6                                                   /*!< UART0_C2: TCIE Position                 */
#define UART_C2_TCIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C2_TCIE_SHIFT))&UART_C2_TCIE_MASK) /*!< UART0_C2                                */
#define UART_C2_TIE_MASK                         (0x01UL << UART_C2_TIE_SHIFT)                       /*!< UART0_C2: TIE Mask                      */
#define UART_C2_TIE_SHIFT                        7                                                   /*!< UART0_C2: TIE Position                  */
#define UART_C2_TIE(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C2_TIE_SHIFT))&UART_C2_TIE_MASK) /*!< UART0_C2                                */
/* ------- S1 Bit Fields                            ------ */
#define UART_S1_PF_MASK                          (0x01UL << UART_S1_PF_SHIFT)                        /*!< UART0_S1: PF Mask                       */
#define UART_S1_PF_SHIFT                         0                                                   /*!< UART0_S1: PF Position                   */
#define UART_S1_PF(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_PF_SHIFT))&UART_S1_PF_MASK) /*!< UART0_S1                                */
#define UART_S1_FE_MASK                          (0x01UL << UART_S1_FE_SHIFT)                        /*!< UART0_S1: FE Mask                       */
#define UART_S1_FE_SHIFT                         1                                                   /*!< UART0_S1: FE Position                   */
#define UART_S1_FE(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_FE_SHIFT))&UART_S1_FE_MASK) /*!< UART0_S1                                */
#define UART_S1_NF_MASK                          (0x01UL << UART_S1_NF_SHIFT)                        /*!< UART0_S1: NF Mask                       */
#define UART_S1_NF_SHIFT                         2                                                   /*!< UART0_S1: NF Position                   */
#define UART_S1_NF(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_NF_SHIFT))&UART_S1_NF_MASK) /*!< UART0_S1                                */
#define UART_S1_OR_MASK                          (0x01UL << UART_S1_OR_SHIFT)                        /*!< UART0_S1: OR Mask                       */
#define UART_S1_OR_SHIFT                         3                                                   /*!< UART0_S1: OR Position                   */
#define UART_S1_OR(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_OR_SHIFT))&UART_S1_OR_MASK) /*!< UART0_S1                                */
#define UART_S1_IDLE_MASK                        (0x01UL << UART_S1_IDLE_SHIFT)                      /*!< UART0_S1: IDLE Mask                     */
#define UART_S1_IDLE_SHIFT                       4                                                   /*!< UART0_S1: IDLE Position                 */
#define UART_S1_IDLE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S1_IDLE_SHIFT))&UART_S1_IDLE_MASK) /*!< UART0_S1                                */
#define UART_S1_RDRF_MASK                        (0x01UL << UART_S1_RDRF_SHIFT)                      /*!< UART0_S1: RDRF Mask                     */
#define UART_S1_RDRF_SHIFT                       5                                                   /*!< UART0_S1: RDRF Position                 */
#define UART_S1_RDRF(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S1_RDRF_SHIFT))&UART_S1_RDRF_MASK) /*!< UART0_S1                                */
#define UART_S1_TC_MASK                          (0x01UL << UART_S1_TC_SHIFT)                        /*!< UART0_S1: TC Mask                       */
#define UART_S1_TC_SHIFT                         6                                                   /*!< UART0_S1: TC Position                   */
#define UART_S1_TC(x)                            (((uint8_t)(((uint8_t)(x))<<UART_S1_TC_SHIFT))&UART_S1_TC_MASK) /*!< UART0_S1                                */
#define UART_S1_TDRE_MASK                        (0x01UL << UART_S1_TDRE_SHIFT)                      /*!< UART0_S1: TDRE Mask                     */
#define UART_S1_TDRE_SHIFT                       7                                                   /*!< UART0_S1: TDRE Position                 */
#define UART_S1_TDRE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S1_TDRE_SHIFT))&UART_S1_TDRE_MASK) /*!< UART0_S1                                */
/* ------- S2 Bit Fields                            ------ */
#define UART_S2_RAF_MASK                         (0x01UL << UART_S2_RAF_SHIFT)                       /*!< UART0_S2: RAF Mask                      */
#define UART_S2_RAF_SHIFT                        0                                                   /*!< UART0_S2: RAF Position                  */
#define UART_S2_RAF(x)                           (((uint8_t)(((uint8_t)(x))<<UART_S2_RAF_SHIFT))&UART_S2_RAF_MASK) /*!< UART0_S2                                */
#define UART_S2_LBKDE_MASK                       (0x01UL << UART_S2_LBKDE_SHIFT)                     /*!< UART0_S2: LBKDE Mask                    */
#define UART_S2_LBKDE_SHIFT                      1                                                   /*!< UART0_S2: LBKDE Position                */
#define UART_S2_LBKDE(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_LBKDE_SHIFT))&UART_S2_LBKDE_MASK) /*!< UART0_S2                                */
#define UART_S2_BRK13_MASK                       (0x01UL << UART_S2_BRK13_SHIFT)                     /*!< UART0_S2: BRK13 Mask                    */
#define UART_S2_BRK13_SHIFT                      2                                                   /*!< UART0_S2: BRK13 Position                */
#define UART_S2_BRK13(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_BRK13_SHIFT))&UART_S2_BRK13_MASK) /*!< UART0_S2                                */
#define UART_S2_RWUID_MASK                       (0x01UL << UART_S2_RWUID_SHIFT)                     /*!< UART0_S2: RWUID Mask                    */
#define UART_S2_RWUID_SHIFT                      3                                                   /*!< UART0_S2: RWUID Position                */
#define UART_S2_RWUID(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_RWUID_SHIFT))&UART_S2_RWUID_MASK) /*!< UART0_S2                                */
#define UART_S2_RXINV_MASK                       (0x01UL << UART_S2_RXINV_SHIFT)                     /*!< UART0_S2: RXINV Mask                    */
#define UART_S2_RXINV_SHIFT                      4                                                   /*!< UART0_S2: RXINV Position                */
#define UART_S2_RXINV(x)                         (((uint8_t)(((uint8_t)(x))<<UART_S2_RXINV_SHIFT))&UART_S2_RXINV_MASK) /*!< UART0_S2                                */
#define UART_S2_MSBF_MASK                        (0x01UL << UART_S2_MSBF_SHIFT)                      /*!< UART0_S2: MSBF Mask                     */
#define UART_S2_MSBF_SHIFT                       5                                                   /*!< UART0_S2: MSBF Position                 */
#define UART_S2_MSBF(x)                          (((uint8_t)(((uint8_t)(x))<<UART_S2_MSBF_SHIFT))&UART_S2_MSBF_MASK) /*!< UART0_S2                                */
#define UART_S2_RXEDGIF_MASK                     (0x01UL << UART_S2_RXEDGIF_SHIFT)                   /*!< UART0_S2: RXEDGIF Mask                  */
#define UART_S2_RXEDGIF_SHIFT                    6                                                   /*!< UART0_S2: RXEDGIF Position              */
#define UART_S2_RXEDGIF(x)                       (((uint8_t)(((uint8_t)(x))<<UART_S2_RXEDGIF_SHIFT))&UART_S2_RXEDGIF_MASK) /*!< UART0_S2                                */
#define UART_S2_LBKDIF_MASK                      (0x01UL << UART_S2_LBKDIF_SHIFT)                    /*!< UART0_S2: LBKDIF Mask                   */
#define UART_S2_LBKDIF_SHIFT                     7                                                   /*!< UART0_S2: LBKDIF Position               */
#define UART_S2_LBKDIF(x)                        (((uint8_t)(((uint8_t)(x))<<UART_S2_LBKDIF_SHIFT))&UART_S2_LBKDIF_MASK) /*!< UART0_S2                                */
/* ------- C3 Bit Fields                            ------ */
#define UART_C3_PEIE_MASK                        (0x01UL << UART_C3_PEIE_SHIFT)                      /*!< UART0_C3: PEIE Mask                     */
#define UART_C3_PEIE_SHIFT                       0                                                   /*!< UART0_C3: PEIE Position                 */
#define UART_C3_PEIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_PEIE_SHIFT))&UART_C3_PEIE_MASK) /*!< UART0_C3                                */
#define UART_C3_FEIE_MASK                        (0x01UL << UART_C3_FEIE_SHIFT)                      /*!< UART0_C3: FEIE Mask                     */
#define UART_C3_FEIE_SHIFT                       1                                                   /*!< UART0_C3: FEIE Position                 */
#define UART_C3_FEIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_FEIE_SHIFT))&UART_C3_FEIE_MASK) /*!< UART0_C3                                */
#define UART_C3_NEIE_MASK                        (0x01UL << UART_C3_NEIE_SHIFT)                      /*!< UART0_C3: NEIE Mask                     */
#define UART_C3_NEIE_SHIFT                       2                                                   /*!< UART0_C3: NEIE Position                 */
#define UART_C3_NEIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_NEIE_SHIFT))&UART_C3_NEIE_MASK) /*!< UART0_C3                                */
#define UART_C3_ORIE_MASK                        (0x01UL << UART_C3_ORIE_SHIFT)                      /*!< UART0_C3: ORIE Mask                     */
#define UART_C3_ORIE_SHIFT                       3                                                   /*!< UART0_C3: ORIE Position                 */
#define UART_C3_ORIE(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C3_ORIE_SHIFT))&UART_C3_ORIE_MASK) /*!< UART0_C3                                */
#define UART_C3_TXINV_MASK                       (0x01UL << UART_C3_TXINV_SHIFT)                     /*!< UART0_C3: TXINV Mask                    */
#define UART_C3_TXINV_SHIFT                      4                                                   /*!< UART0_C3: TXINV Position                */
#define UART_C3_TXINV(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C3_TXINV_SHIFT))&UART_C3_TXINV_MASK) /*!< UART0_C3                                */
#define UART_C3_TXDIR_MASK                       (0x01UL << UART_C3_TXDIR_SHIFT)                     /*!< UART0_C3: TXDIR Mask                    */
#define UART_C3_TXDIR_SHIFT                      5                                                   /*!< UART0_C3: TXDIR Position                */
#define UART_C3_TXDIR(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C3_TXDIR_SHIFT))&UART_C3_TXDIR_MASK) /*!< UART0_C3                                */
#define UART_C3_T8_MASK                          (0x01UL << UART_C3_T8_SHIFT)                        /*!< UART0_C3: T8 Mask                       */
#define UART_C3_T8_SHIFT                         6                                                   /*!< UART0_C3: T8 Position                   */
#define UART_C3_T8(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C3_T8_SHIFT))&UART_C3_T8_MASK) /*!< UART0_C3                                */
#define UART_C3_R8_MASK                          (0x01UL << UART_C3_R8_SHIFT)                        /*!< UART0_C3: R8 Mask                       */
#define UART_C3_R8_SHIFT                         7                                                   /*!< UART0_C3: R8 Position                   */
#define UART_C3_R8(x)                            (((uint8_t)(((uint8_t)(x))<<UART_C3_R8_SHIFT))&UART_C3_R8_MASK) /*!< UART0_C3                                */
/* ------- D Bit Fields                             ------ */
#define UART_D_RT_MASK                           (0xFFUL << UART_D_RT_SHIFT)                         /*!< UART0_D: RT Mask                        */
#define UART_D_RT_SHIFT                          0                                                   /*!< UART0_D: RT Position                    */
#define UART_D_RT(x)                             (((uint8_t)(((uint8_t)(x))<<UART_D_RT_SHIFT))&UART_D_RT_MASK) /*!< UART0_D                                 */
/* ------- MA Bit Fields                            ------ */
#define UART_MA_MA_MASK                          (0xFFUL << UART_MA_MA_SHIFT)                        /*!< UART0_MA: MA Mask                       */
#define UART_MA_MA_SHIFT                         0                                                   /*!< UART0_MA: MA Position                   */
#define UART_MA_MA(x)                            (((uint8_t)(((uint8_t)(x))<<UART_MA_MA_SHIFT))&UART_MA_MA_MASK) /*!< UART0_MA                                */
/* ------- C4 Bit Fields                            ------ */
#define UART_C4_BRFA_MASK                        (0x1FUL << UART_C4_BRFA_SHIFT)                      /*!< UART0_C4: BRFA Mask                     */
#define UART_C4_BRFA_SHIFT                       0                                                   /*!< UART0_C4: BRFA Position                 */
#define UART_C4_BRFA(x)                          (((uint8_t)(((uint8_t)(x))<<UART_C4_BRFA_SHIFT))&UART_C4_BRFA_MASK) /*!< UART0_C4                                */
#define UART_C4_M10_MASK                         (0x01UL << UART_C4_M10_SHIFT)                       /*!< UART0_C4: M10 Mask                      */
#define UART_C4_M10_SHIFT                        5                                                   /*!< UART0_C4: M10 Position                  */
#define UART_C4_M10(x)                           (((uint8_t)(((uint8_t)(x))<<UART_C4_M10_SHIFT))&UART_C4_M10_MASK) /*!< UART0_C4                                */
#define UART_C4_MAEN2_MASK                       (0x01UL << UART_C4_MAEN2_SHIFT)                     /*!< UART0_C4: MAEN2 Mask                    */
#define UART_C4_MAEN2_SHIFT                      6                                                   /*!< UART0_C4: MAEN2 Position                */
#define UART_C4_MAEN2(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C4_MAEN2_SHIFT))&UART_C4_MAEN2_MASK) /*!< UART0_C4                                */
#define UART_C4_MAEN1_MASK                       (0x01UL << UART_C4_MAEN1_SHIFT)                     /*!< UART0_C4: MAEN1 Mask                    */
#define UART_C4_MAEN1_SHIFT                      7                                                   /*!< UART0_C4: MAEN1 Position                */
#define UART_C4_MAEN1(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C4_MAEN1_SHIFT))&UART_C4_MAEN1_MASK) /*!< UART0_C4                                */
/* ------- C5 Bit Fields                            ------ */
#define UART_C5_RDMAS_MASK                       (0x01UL << UART_C5_RDMAS_SHIFT)                     /*!< UART0_C5: RDMAS Mask                    */
#define UART_C5_RDMAS_SHIFT                      5                                                   /*!< UART0_C5: RDMAS Position                */
#define UART_C5_RDMAS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C5_RDMAS_SHIFT))&UART_C5_RDMAS_MASK) /*!< UART0_C5                                */
#define UART_C5_TDMAS_MASK                       (0x01UL << UART_C5_TDMAS_SHIFT)                     /*!< UART0_C5: TDMAS Mask                    */
#define UART_C5_TDMAS_SHIFT                      7                                                   /*!< UART0_C5: TDMAS Position                */
#define UART_C5_TDMAS(x)                         (((uint8_t)(((uint8_t)(x))<<UART_C5_TDMAS_SHIFT))&UART_C5_TDMAS_MASK) /*!< UART0_C5                                */
/* ------- ED Bit Fields                            ------ */
#define UART_ED_PARITYE_MASK                     (0x01UL << UART_ED_PARITYE_SHIFT)                   /*!< UART0_ED: PARITYE Mask                  */
#define UART_ED_PARITYE_SHIFT                    6                                                   /*!< UART0_ED: PARITYE Position              */
#define UART_ED_PARITYE(x)                       (((uint8_t)(((uint8_t)(x))<<UART_ED_PARITYE_SHIFT))&UART_ED_PARITYE_MASK) /*!< UART0_ED                                */
#define UART_ED_NOISY_MASK                       (0x01UL << UART_ED_NOISY_SHIFT)                     /*!< UART0_ED: NOISY Mask                    */
#define UART_ED_NOISY_SHIFT                      7                                                   /*!< UART0_ED: NOISY Position                */
#define UART_ED_NOISY(x)                         (((uint8_t)(((uint8_t)(x))<<UART_ED_NOISY_SHIFT))&UART_ED_NOISY_MASK) /*!< UART0_ED                                */
/* ------- MODEM Bit Fields                         ------ */
#define UART_MODEM_TXCTSE_MASK                   (0x01UL << UART_MODEM_TXCTSE_SHIFT)                 /*!< UART0_MODEM: TXCTSE Mask                */
#define UART_MODEM_TXCTSE_SHIFT                  0                                                   /*!< UART0_MODEM: TXCTSE Position            */
#define UART_MODEM_TXCTSE(x)                     (((uint8_t)(((uint8_t)(x))<<UART_MODEM_TXCTSE_SHIFT))&UART_MODEM_TXCTSE_MASK) /*!< UART0_MODEM                             */
#define UART_MODEM_TXRTSE_MASK                   (0x01UL << UART_MODEM_TXRTSE_SHIFT)                 /*!< UART0_MODEM: TXRTSE Mask                */
#define UART_MODEM_TXRTSE_SHIFT                  1                                                   /*!< UART0_MODEM: TXRTSE Position            */
#define UART_MODEM_TXRTSE(x)                     (((uint8_t)(((uint8_t)(x))<<UART_MODEM_TXRTSE_SHIFT))&UART_MODEM_TXRTSE_MASK) /*!< UART0_MODEM                             */
#define UART_MODEM_TXRTSPOL_MASK                 (0x01UL << UART_MODEM_TXRTSPOL_SHIFT)               /*!< UART0_MODEM: TXRTSPOL Mask              */
#define UART_MODEM_TXRTSPOL_SHIFT                2                                                   /*!< UART0_MODEM: TXRTSPOL Position          */
#define UART_MODEM_TXRTSPOL(x)                   (((uint8_t)(((uint8_t)(x))<<UART_MODEM_TXRTSPOL_SHIFT))&UART_MODEM_TXRTSPOL_MASK) /*!< UART0_MODEM                             */
#define UART_MODEM_RXRTSE_MASK                   (0x01UL << UART_MODEM_RXRTSE_SHIFT)                 /*!< UART0_MODEM: RXRTSE Mask                */
#define UART_MODEM_RXRTSE_SHIFT                  3                                                   /*!< UART0_MODEM: RXRTSE Position            */
#define UART_MODEM_RXRTSE(x)                     (((uint8_t)(((uint8_t)(x))<<UART_MODEM_RXRTSE_SHIFT))&UART_MODEM_RXRTSE_MASK) /*!< UART0_MODEM                             */
/* ------- IR Bit Fields                            ------ */
#define UART_IR_TNP_MASK                         (0x03UL << UART_IR_TNP_SHIFT)                       /*!< UART0_IR: TNP Mask                      */
#define UART_IR_TNP_SHIFT                        0                                                   /*!< UART0_IR: TNP Position                  */
#define UART_IR_TNP(x)                           (((uint8_t)(((uint8_t)(x))<<UART_IR_TNP_SHIFT))&UART_IR_TNP_MASK) /*!< UART0_IR                                */
#define UART_IR_IREN_MASK                        (0x01UL << UART_IR_IREN_SHIFT)                      /*!< UART0_IR: IREN Mask                     */
#define UART_IR_IREN_SHIFT                       2                                                   /*!< UART0_IR: IREN Position                 */
#define UART_IR_IREN(x)                          (((uint8_t)(((uint8_t)(x))<<UART_IR_IREN_SHIFT))&UART_IR_IREN_MASK) /*!< UART0_IR                                */
/* ------- PFIFO Bit Fields                         ------ */
#define UART_PFIFO_RXFIFOSIZE_MASK               (0x07UL << UART_PFIFO_RXFIFOSIZE_SHIFT)             /*!< UART0_PFIFO: RXFIFOSIZE Mask            */
#define UART_PFIFO_RXFIFOSIZE_SHIFT              0                                                   /*!< UART0_PFIFO: RXFIFOSIZE Position        */
#define UART_PFIFO_RXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_RXFIFOSIZE_SHIFT))&UART_PFIFO_RXFIFOSIZE_MASK) /*!< UART0_PFIFO                             */
#define UART_PFIFO_RXFE_MASK                     (0x01UL << UART_PFIFO_RXFE_SHIFT)                   /*!< UART0_PFIFO: RXFE Mask                  */
#define UART_PFIFO_RXFE_SHIFT                    3                                                   /*!< UART0_PFIFO: RXFE Position              */
#define UART_PFIFO_RXFE(x)                       (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_RXFE_SHIFT))&UART_PFIFO_RXFE_MASK) /*!< UART0_PFIFO                             */
#define UART_PFIFO_TXFIFOSIZE_MASK               (0x07UL << UART_PFIFO_TXFIFOSIZE_SHIFT)             /*!< UART0_PFIFO: TXFIFOSIZE Mask            */
#define UART_PFIFO_TXFIFOSIZE_SHIFT              4                                                   /*!< UART0_PFIFO: TXFIFOSIZE Position        */
#define UART_PFIFO_TXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_TXFIFOSIZE_SHIFT))&UART_PFIFO_TXFIFOSIZE_MASK) /*!< UART0_PFIFO                             */
#define UART_PFIFO_TXFE_MASK                     (0x01UL << UART_PFIFO_TXFE_SHIFT)                   /*!< UART0_PFIFO: TXFE Mask                  */
#define UART_PFIFO_TXFE_SHIFT                    7                                                   /*!< UART0_PFIFO: TXFE Position              */
#define UART_PFIFO_TXFE(x)                       (((uint8_t)(((uint8_t)(x))<<UART_PFIFO_TXFE_SHIFT))&UART_PFIFO_TXFE_MASK) /*!< UART0_PFIFO                             */
/* ------- CFIFO Bit Fields                         ------ */
#define UART_CFIFO_RXUFE_MASK                    (0x01UL << UART_CFIFO_RXUFE_SHIFT)                  /*!< UART0_CFIFO: RXUFE Mask                 */
#define UART_CFIFO_RXUFE_SHIFT                   0                                                   /*!< UART0_CFIFO: RXUFE Position             */
#define UART_CFIFO_RXUFE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_CFIFO_RXUFE_SHIFT))&UART_CFIFO_RXUFE_MASK) /*!< UART0_CFIFO                             */
#define UART_CFIFO_TXOFE_MASK                    (0x01UL << UART_CFIFO_TXOFE_SHIFT)                  /*!< UART0_CFIFO: TXOFE Mask                 */
#define UART_CFIFO_TXOFE_SHIFT                   1                                                   /*!< UART0_CFIFO: TXOFE Position             */
#define UART_CFIFO_TXOFE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_CFIFO_TXOFE_SHIFT))&UART_CFIFO_TXOFE_MASK) /*!< UART0_CFIFO                             */
#define UART_CFIFO_RXOFE_MASK                    (0x01UL << UART_CFIFO_RXOFE_SHIFT)                  /*!< UART0_CFIFO: RXOFE Mask                 */
#define UART_CFIFO_RXOFE_SHIFT                   2                                                   /*!< UART0_CFIFO: RXOFE Position             */
#define UART_CFIFO_RXOFE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_CFIFO_RXOFE_SHIFT))&UART_CFIFO_RXOFE_MASK) /*!< UART0_CFIFO                             */
#define UART_CFIFO_RXFLUSH_MASK                  (0x01UL << UART_CFIFO_RXFLUSH_SHIFT)                /*!< UART0_CFIFO: RXFLUSH Mask               */
#define UART_CFIFO_RXFLUSH_SHIFT                 6                                                   /*!< UART0_CFIFO: RXFLUSH Position           */
#define UART_CFIFO_RXFLUSH(x)                    (((uint8_t)(((uint8_t)(x))<<UART_CFIFO_RXFLUSH_SHIFT))&UART_CFIFO_RXFLUSH_MASK) /*!< UART0_CFIFO                             */
#define UART_CFIFO_TXFLUSH_MASK                  (0x01UL << UART_CFIFO_TXFLUSH_SHIFT)                /*!< UART0_CFIFO: TXFLUSH Mask               */
#define UART_CFIFO_TXFLUSH_SHIFT                 7                                                   /*!< UART0_CFIFO: TXFLUSH Position           */
#define UART_CFIFO_TXFLUSH(x)                    (((uint8_t)(((uint8_t)(x))<<UART_CFIFO_TXFLUSH_SHIFT))&UART_CFIFO_TXFLUSH_MASK) /*!< UART0_CFIFO                             */
/* ------- SFIFO Bit Fields                         ------ */
#define UART_SFIFO_RXUF_MASK                     (0x01UL << UART_SFIFO_RXUF_SHIFT)                   /*!< UART0_SFIFO: RXUF Mask                  */
#define UART_SFIFO_RXUF_SHIFT                    0                                                   /*!< UART0_SFIFO: RXUF Position              */
#define UART_SFIFO_RXUF(x)                       (((uint8_t)(((uint8_t)(x))<<UART_SFIFO_RXUF_SHIFT))&UART_SFIFO_RXUF_MASK) /*!< UART0_SFIFO                             */
#define UART_SFIFO_TXOF_MASK                     (0x01UL << UART_SFIFO_TXOF_SHIFT)                   /*!< UART0_SFIFO: TXOF Mask                  */
#define UART_SFIFO_TXOF_SHIFT                    1                                                   /*!< UART0_SFIFO: TXOF Position              */
#define UART_SFIFO_TXOF(x)                       (((uint8_t)(((uint8_t)(x))<<UART_SFIFO_TXOF_SHIFT))&UART_SFIFO_TXOF_MASK) /*!< UART0_SFIFO                             */
#define UART_SFIFO_RXOF_MASK                     (0x01UL << UART_SFIFO_RXOF_SHIFT)                   /*!< UART0_SFIFO: RXOF Mask                  */
#define UART_SFIFO_RXOF_SHIFT                    2                                                   /*!< UART0_SFIFO: RXOF Position              */
#define UART_SFIFO_RXOF(x)                       (((uint8_t)(((uint8_t)(x))<<UART_SFIFO_RXOF_SHIFT))&UART_SFIFO_RXOF_MASK) /*!< UART0_SFIFO                             */
#define UART_SFIFO_RXEMPT_MASK                   (0x01UL << UART_SFIFO_RXEMPT_SHIFT)                 /*!< UART0_SFIFO: RXEMPT Mask                */
#define UART_SFIFO_RXEMPT_SHIFT                  6                                                   /*!< UART0_SFIFO: RXEMPT Position            */
#define UART_SFIFO_RXEMPT(x)                     (((uint8_t)(((uint8_t)(x))<<UART_SFIFO_RXEMPT_SHIFT))&UART_SFIFO_RXEMPT_MASK) /*!< UART0_SFIFO                             */
#define UART_SFIFO_TXEMPT_MASK                   (0x01UL << UART_SFIFO_TXEMPT_SHIFT)                 /*!< UART0_SFIFO: TXEMPT Mask                */
#define UART_SFIFO_TXEMPT_SHIFT                  7                                                   /*!< UART0_SFIFO: TXEMPT Position            */
#define UART_SFIFO_TXEMPT(x)                     (((uint8_t)(((uint8_t)(x))<<UART_SFIFO_TXEMPT_SHIFT))&UART_SFIFO_TXEMPT_MASK) /*!< UART0_SFIFO                             */
/* ------- TWFIFO Bit Fields                        ------ */
#define UART_TWFIFO_TXWATER_MASK                 (0xFFUL << UART_TWFIFO_TXWATER_SHIFT)               /*!< UART0_TWFIFO: TXWATER Mask              */
#define UART_TWFIFO_TXWATER_SHIFT                0                                                   /*!< UART0_TWFIFO: TXWATER Position          */
#define UART_TWFIFO_TXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TWFIFO_TXWATER_SHIFT))&UART_TWFIFO_TXWATER_MASK) /*!< UART0_TWFIFO                            */
/* ------- TCFIFO Bit Fields                        ------ */
#define UART_TCFIFO_TXCOUNT_MASK                 (0xFFUL << UART_TCFIFO_TXCOUNT_SHIFT)               /*!< UART0_TCFIFO: TXCOUNT Mask              */
#define UART_TCFIFO_TXCOUNT_SHIFT                0                                                   /*!< UART0_TCFIFO: TXCOUNT Position          */
#define UART_TCFIFO_TXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_TCFIFO_TXCOUNT_SHIFT))&UART_TCFIFO_TXCOUNT_MASK) /*!< UART0_TCFIFO                            */
/* ------- RWFIFO Bit Fields                        ------ */
#define UART_RWFIFO_RXWATER_MASK                 (0xFFUL << UART_RWFIFO_RXWATER_SHIFT)               /*!< UART0_RWFIFO: RXWATER Mask              */
#define UART_RWFIFO_RXWATER_SHIFT                0                                                   /*!< UART0_RWFIFO: RXWATER Position          */
#define UART_RWFIFO_RXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RWFIFO_RXWATER_SHIFT))&UART_RWFIFO_RXWATER_MASK) /*!< UART0_RWFIFO                            */
/* ------- RCFIFO Bit Fields                        ------ */
#define UART_RCFIFO_RXCOUNT_MASK                 (0xFFUL << UART_RCFIFO_RXCOUNT_SHIFT)               /*!< UART0_RCFIFO: RXCOUNT Mask              */
#define UART_RCFIFO_RXCOUNT_SHIFT                0                                                   /*!< UART0_RCFIFO: RXCOUNT Position          */
#define UART_RCFIFO_RXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<UART_RCFIFO_RXCOUNT_SHIFT))&UART_RCFIFO_RXCOUNT_MASK) /*!< UART0_RCFIFO                            */
/* ------- C7816 Bit Fields                         ------ */
#define UART_C7816_ISO_7816E_MASK                (0x01UL << UART_C7816_ISO_7816E_SHIFT)              /*!< UART0_C7816: ISO_7816E Mask             */
#define UART_C7816_ISO_7816E_SHIFT               0                                                   /*!< UART0_C7816: ISO_7816E Position         */
#define UART_C7816_ISO_7816E(x)                  (((uint8_t)(((uint8_t)(x))<<UART_C7816_ISO_7816E_SHIFT))&UART_C7816_ISO_7816E_MASK) /*!< UART0_C7816                             */
#define UART_C7816_TTYPE_MASK                    (0x01UL << UART_C7816_TTYPE_SHIFT)                  /*!< UART0_C7816: TTYPE Mask                 */
#define UART_C7816_TTYPE_SHIFT                   1                                                   /*!< UART0_C7816: TTYPE Position             */
#define UART_C7816_TTYPE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C7816_TTYPE_SHIFT))&UART_C7816_TTYPE_MASK) /*!< UART0_C7816                             */
#define UART_C7816_INIT_MASK                     (0x01UL << UART_C7816_INIT_SHIFT)                   /*!< UART0_C7816: INIT Mask                  */
#define UART_C7816_INIT_SHIFT                    2                                                   /*!< UART0_C7816: INIT Position              */
#define UART_C7816_INIT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_C7816_INIT_SHIFT))&UART_C7816_INIT_MASK) /*!< UART0_C7816                             */
#define UART_C7816_ANACK_MASK                    (0x01UL << UART_C7816_ANACK_SHIFT)                  /*!< UART0_C7816: ANACK Mask                 */
#define UART_C7816_ANACK_SHIFT                   3                                                   /*!< UART0_C7816: ANACK Position             */
#define UART_C7816_ANACK(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C7816_ANACK_SHIFT))&UART_C7816_ANACK_MASK) /*!< UART0_C7816                             */
#define UART_C7816_ONACK_MASK                    (0x01UL << UART_C7816_ONACK_SHIFT)                  /*!< UART0_C7816: ONACK Mask                 */
#define UART_C7816_ONACK_SHIFT                   4                                                   /*!< UART0_C7816: ONACK Position             */
#define UART_C7816_ONACK(x)                      (((uint8_t)(((uint8_t)(x))<<UART_C7816_ONACK_SHIFT))&UART_C7816_ONACK_MASK) /*!< UART0_C7816                             */
/* ------- IE7816 Bit Fields                        ------ */
#define UART_IE7816_RXTE_MASK                    (0x01UL << UART_IE7816_RXTE_SHIFT)                  /*!< UART0_IE7816: RXTE Mask                 */
#define UART_IE7816_RXTE_SHIFT                   0                                                   /*!< UART0_IE7816: RXTE Position             */
#define UART_IE7816_RXTE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_RXTE_SHIFT))&UART_IE7816_RXTE_MASK) /*!< UART0_IE7816                            */
#define UART_IE7816_TXTE_MASK                    (0x01UL << UART_IE7816_TXTE_SHIFT)                  /*!< UART0_IE7816: TXTE Mask                 */
#define UART_IE7816_TXTE_SHIFT                   1                                                   /*!< UART0_IE7816: TXTE Position             */
#define UART_IE7816_TXTE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_TXTE_SHIFT))&UART_IE7816_TXTE_MASK) /*!< UART0_IE7816                            */
#define UART_IE7816_GTVE_MASK                    (0x01UL << UART_IE7816_GTVE_SHIFT)                  /*!< UART0_IE7816: GTVE Mask                 */
#define UART_IE7816_GTVE_SHIFT                   2                                                   /*!< UART0_IE7816: GTVE Position             */
#define UART_IE7816_GTVE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_GTVE_SHIFT))&UART_IE7816_GTVE_MASK) /*!< UART0_IE7816                            */
#define UART_IE7816_INITDE_MASK                  (0x01UL << UART_IE7816_INITDE_SHIFT)                /*!< UART0_IE7816: INITDE Mask               */
#define UART_IE7816_INITDE_SHIFT                 4                                                   /*!< UART0_IE7816: INITDE Position           */
#define UART_IE7816_INITDE(x)                    (((uint8_t)(((uint8_t)(x))<<UART_IE7816_INITDE_SHIFT))&UART_IE7816_INITDE_MASK) /*!< UART0_IE7816                            */
#define UART_IE7816_BWTE_MASK                    (0x01UL << UART_IE7816_BWTE_SHIFT)                  /*!< UART0_IE7816: BWTE Mask                 */
#define UART_IE7816_BWTE_SHIFT                   5                                                   /*!< UART0_IE7816: BWTE Position             */
#define UART_IE7816_BWTE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_BWTE_SHIFT))&UART_IE7816_BWTE_MASK) /*!< UART0_IE7816                            */
#define UART_IE7816_CWTE_MASK                    (0x01UL << UART_IE7816_CWTE_SHIFT)                  /*!< UART0_IE7816: CWTE Mask                 */
#define UART_IE7816_CWTE_SHIFT                   6                                                   /*!< UART0_IE7816: CWTE Position             */
#define UART_IE7816_CWTE(x)                      (((uint8_t)(((uint8_t)(x))<<UART_IE7816_CWTE_SHIFT))&UART_IE7816_CWTE_MASK) /*!< UART0_IE7816                            */
#define UART_IE7816_WTE_MASK                     (0x01UL << UART_IE7816_WTE_SHIFT)                   /*!< UART0_IE7816: WTE Mask                  */
#define UART_IE7816_WTE_SHIFT                    7                                                   /*!< UART0_IE7816: WTE Position              */
#define UART_IE7816_WTE(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IE7816_WTE_SHIFT))&UART_IE7816_WTE_MASK) /*!< UART0_IE7816                            */
/* ------- IS7816 Bit Fields                        ------ */
#define UART_IS7816_RXT_MASK                     (0x01UL << UART_IS7816_RXT_SHIFT)                   /*!< UART0_IS7816: RXT Mask                  */
#define UART_IS7816_RXT_SHIFT                    0                                                   /*!< UART0_IS7816: RXT Position              */
#define UART_IS7816_RXT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_RXT_SHIFT))&UART_IS7816_RXT_MASK) /*!< UART0_IS7816                            */
#define UART_IS7816_TXT_MASK                     (0x01UL << UART_IS7816_TXT_SHIFT)                   /*!< UART0_IS7816: TXT Mask                  */
#define UART_IS7816_TXT_SHIFT                    1                                                   /*!< UART0_IS7816: TXT Position              */
#define UART_IS7816_TXT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_TXT_SHIFT))&UART_IS7816_TXT_MASK) /*!< UART0_IS7816                            */
#define UART_IS7816_GTV_MASK                     (0x01UL << UART_IS7816_GTV_SHIFT)                   /*!< UART0_IS7816: GTV Mask                  */
#define UART_IS7816_GTV_SHIFT                    2                                                   /*!< UART0_IS7816: GTV Position              */
#define UART_IS7816_GTV(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_GTV_SHIFT))&UART_IS7816_GTV_MASK) /*!< UART0_IS7816                            */
#define UART_IS7816_INITD_MASK                   (0x01UL << UART_IS7816_INITD_SHIFT)                 /*!< UART0_IS7816: INITD Mask                */
#define UART_IS7816_INITD_SHIFT                  4                                                   /*!< UART0_IS7816: INITD Position            */
#define UART_IS7816_INITD(x)                     (((uint8_t)(((uint8_t)(x))<<UART_IS7816_INITD_SHIFT))&UART_IS7816_INITD_MASK) /*!< UART0_IS7816                            */
#define UART_IS7816_BWT_MASK                     (0x01UL << UART_IS7816_BWT_SHIFT)                   /*!< UART0_IS7816: BWT Mask                  */
#define UART_IS7816_BWT_SHIFT                    5                                                   /*!< UART0_IS7816: BWT Position              */
#define UART_IS7816_BWT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_BWT_SHIFT))&UART_IS7816_BWT_MASK) /*!< UART0_IS7816                            */
#define UART_IS7816_CWT_MASK                     (0x01UL << UART_IS7816_CWT_SHIFT)                   /*!< UART0_IS7816: CWT Mask                  */
#define UART_IS7816_CWT_SHIFT                    6                                                   /*!< UART0_IS7816: CWT Position              */
#define UART_IS7816_CWT(x)                       (((uint8_t)(((uint8_t)(x))<<UART_IS7816_CWT_SHIFT))&UART_IS7816_CWT_MASK) /*!< UART0_IS7816                            */
#define UART_IS7816_WT_MASK                      (0x01UL << UART_IS7816_WT_SHIFT)                    /*!< UART0_IS7816: WT Mask                   */
#define UART_IS7816_WT_SHIFT                     7                                                   /*!< UART0_IS7816: WT Position               */
#define UART_IS7816_WT(x)                        (((uint8_t)(((uint8_t)(x))<<UART_IS7816_WT_SHIFT))&UART_IS7816_WT_MASK) /*!< UART0_IS7816                            */
/* ------- WP7816T0 Bit Fields                      ------ */
#define UART_WP7816T0_WI_MASK                    (0xFFUL << UART_WP7816T0_WI_SHIFT)                  /*!< UART0_WP7816T0: WI Mask                 */
#define UART_WP7816T0_WI_SHIFT                   0                                                   /*!< UART0_WP7816T0: WI Position             */
#define UART_WP7816T0_WI(x)                      (((uint8_t)(((uint8_t)(x))<<UART_WP7816T0_WI_SHIFT))&UART_WP7816T0_WI_MASK) /*!< UART0_WP7816T0                          */
/* ------- WP7816T1 Bit Fields                      ------ */
#define UART_WP7816T1_BWI_MASK                   (0x0FUL << UART_WP7816T1_BWI_SHIFT)                 /*!< UART0_WP7816T1: BWI Mask                */
#define UART_WP7816T1_BWI_SHIFT                  0                                                   /*!< UART0_WP7816T1: BWI Position            */
#define UART_WP7816T1_BWI(x)                     (((uint8_t)(((uint8_t)(x))<<UART_WP7816T1_BWI_SHIFT))&UART_WP7816T1_BWI_MASK) /*!< UART0_WP7816T1                          */
#define UART_WP7816T1_CWI_MASK                   (0x0FUL << UART_WP7816T1_CWI_SHIFT)                 /*!< UART0_WP7816T1: CWI Mask                */
#define UART_WP7816T1_CWI_SHIFT                  4                                                   /*!< UART0_WP7816T1: CWI Position            */
#define UART_WP7816T1_CWI(x)                     (((uint8_t)(((uint8_t)(x))<<UART_WP7816T1_CWI_SHIFT))&UART_WP7816T1_CWI_MASK) /*!< UART0_WP7816T1                          */
/* ------- WN7816 Bit Fields                        ------ */
#define UART_WN7816_GTN_MASK                     (0xFFUL << UART_WN7816_GTN_SHIFT)                   /*!< UART0_WN7816: GTN Mask                  */
#define UART_WN7816_GTN_SHIFT                    0                                                   /*!< UART0_WN7816: GTN Position              */
#define UART_WN7816_GTN(x)                       (((uint8_t)(((uint8_t)(x))<<UART_WN7816_GTN_SHIFT))&UART_WN7816_GTN_MASK) /*!< UART0_WN7816                            */
/* ------- WF7816 Bit Fields                        ------ */
#define UART_WF7816_GTFD_MASK                    (0xFFUL << UART_WF7816_GTFD_SHIFT)                  /*!< UART0_WF7816: GTFD Mask                 */
#define UART_WF7816_GTFD_SHIFT                   0                                                   /*!< UART0_WF7816: GTFD Position             */
#define UART_WF7816_GTFD(x)                      (((uint8_t)(((uint8_t)(x))<<UART_WF7816_GTFD_SHIFT))&UART_WF7816_GTFD_MASK) /*!< UART0_WF7816                            */
/* ------- ET7816 Bit Fields                        ------ */
#define UART_ET7816_RXTHRESHOLD_MASK             (0x0FUL << UART_ET7816_RXTHRESHOLD_SHIFT)           /*!< UART0_ET7816: RXTHRESHOLD Mask          */
#define UART_ET7816_RXTHRESHOLD_SHIFT            0                                                   /*!< UART0_ET7816: RXTHRESHOLD Position      */
#define UART_ET7816_RXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_RXTHRESHOLD_SHIFT))&UART_ET7816_RXTHRESHOLD_MASK) /*!< UART0_ET7816                            */
#define UART_ET7816_TXTHRESHOLD_MASK             (0x0FUL << UART_ET7816_TXTHRESHOLD_SHIFT)           /*!< UART0_ET7816: TXTHRESHOLD Mask          */
#define UART_ET7816_TXTHRESHOLD_SHIFT            4                                                   /*!< UART0_ET7816: TXTHRESHOLD Position      */
#define UART_ET7816_TXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x))<<UART_ET7816_TXTHRESHOLD_SHIFT))&UART_ET7816_TXTHRESHOLD_MASK) /*!< UART0_ET7816                            */
/* ------- TL7816 Bit Fields                        ------ */
#define UART_TL7816_TLEN_MASK                    (0xFFUL << UART_TL7816_TLEN_SHIFT)                  /*!< UART0_TL7816: TLEN Mask                 */
#define UART_TL7816_TLEN_SHIFT                   0                                                   /*!< UART0_TL7816: TLEN Position             */
#define UART_TL7816_TLEN(x)                      (((uint8_t)(((uint8_t)(x))<<UART_TL7816_TLEN_SHIFT))&UART_TL7816_TLEN_MASK) /*!< UART0_TL7816                            */
/**
 * @} */ /* End group UART_Register_Masks_GROUP 
 */

/* UART0 - Peripheral instance base addresses */
#define UART0_BasePtr                  0x4006A000UL //!< Peripheral base address
#define UART0                          ((UART_Type *) UART0_BasePtr) //!< Freescale base pointer
#define UART0_BASE_PTR                 (UART0) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART1 (file:UART1_MK10D5)            ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */
/**
* @addtogroup UART_structs_GROUP UART struct
* @brief Struct for UART
* @{
*/
typedef struct {                                /*       UART1 Structure                                              */
   __IO uint8_t   BDH;                          /**< 0000: Baud Rate Register: High                                     */
   __IO uint8_t   BDL;                          /**< 0001: Baud Rate Register: Low                                      */
   __IO uint8_t   C1;                           /**< 0002: Control Register 1                                           */
   __IO uint8_t   C2;                           /**< 0003: Control Register 2                                           */
   __I  uint8_t   S1;                           /**< 0004: Status Register 1                                            */
   __IO uint8_t   S2;                           /**< 0005: Status Register 2                                            */
   __IO uint8_t   C3;                           /**< 0006: Control Register 3                                           */
   __IO uint8_t   D;                            /**< 0007: Data Register                                                */
   __IO uint8_t   MA1;                          /**< 0008: Match Address Registers 1                                    */
   __IO uint8_t   MA2;                          /**< 0009: Match Address Registers 2                                    */
   __IO uint8_t   C4;                           /**< 000A: Control Register 4                                           */
   __IO uint8_t   C5;                           /**< 000B: Control Register 5                                           */
   __I  uint8_t   ED;                           /**< 000C: Extended Data Register                                       */
   __IO uint8_t   MODEM;                        /**< 000D: Modem Register                                               */
   __IO uint8_t   IR;                           /**< 000E: Infrared Register                                            */
   __I  uint8_t   RESERVED0;                   
   __IO uint8_t   PFIFO;                        /**< 0010: FIFO Parameters                                              */
   __IO uint8_t   CFIFO;                        /**< 0011: FIFO Control Register                                        */
   __IO uint8_t   SFIFO;                        /**< 0012: FIFO Status Register                                         */
   __IO uint8_t   TWFIFO;                       /**< 0013: FIFO Transmit Watermark                                      */
   __I  uint8_t   TCFIFO;                       /**< 0014: FIFO Transmit Count                                          */
   __IO uint8_t   RWFIFO;                       /**< 0015: FIFO Receive Watermark                                       */
   __I  uint8_t   RCFIFO;                       /**< 0016: FIFO Receive Count                                           */
} UART1_Type;

/**
 * @} */ /* End group UART_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'UART1' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup UART_Register_Masks_GROUP UART Register Masks
* @brief Register Masks for UART
* @{
*/
/* ------- BDH Bit Fields                           ------ */
/* ------- BDL Bit Fields                           ------ */
/* ------- C1 Bit Fields                            ------ */
/* ------- C2 Bit Fields                            ------ */
/* ------- S1 Bit Fields                            ------ */
/* ------- S2 Bit Fields                            ------ */
/* ------- C3 Bit Fields                            ------ */
/* ------- D Bit Fields                             ------ */
/* ------- MA Bit Fields                            ------ */
/* ------- C4 Bit Fields                            ------ */
/* ------- C5 Bit Fields                            ------ */
/* ------- ED Bit Fields                            ------ */
/* ------- MODEM Bit Fields                         ------ */
/* ------- IR Bit Fields                            ------ */
/* ------- PFIFO Bit Fields                         ------ */
/* ------- CFIFO Bit Fields                         ------ */
/* ------- SFIFO Bit Fields                         ------ */
/* ------- TWFIFO Bit Fields                        ------ */
/* ------- TCFIFO Bit Fields                        ------ */
/* ------- RWFIFO Bit Fields                        ------ */
/* ------- RCFIFO Bit Fields                        ------ */
/**
 * @} */ /* End group UART_Register_Masks_GROUP 
 */

/* UART1 - Peripheral instance base addresses */
#define UART1_BasePtr                  0x4006B000UL //!< Peripheral base address
#define UART1                          ((UART1_Type *) UART1_BasePtr) //!< Freescale base pointer
#define UART1_BASE_PTR                 (UART1) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART2 (derived from UART1)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */

/* UART2 - Peripheral instance base addresses */
#define UART2_BasePtr                  0x4006C000UL //!< Peripheral base address
#define UART2                          ((UART1_Type *) UART2_BasePtr) //!< Freescale base pointer
#define UART2_BASE_PTR                 (UART2) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART3 (derived from UART1)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */

/* UART3 - Peripheral instance base addresses */
#define UART3_BasePtr                  0x4006D000UL //!< Peripheral base address
#define UART3                          ((UART1_Type *) UART3_BasePtr) //!< Freescale base pointer
#define UART3_BASE_PTR                 (UART3) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART4 (derived from UART1)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */

/* UART4 - Peripheral instance base addresses */
#define UART4_BasePtr                  0x400EA000UL //!< Peripheral base address
#define UART4                          ((UART1_Type *) UART4_BasePtr) //!< Freescale base pointer
#define UART4_BASE_PTR                 (UART4) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup VREF_Peripheral_access_layer_GROUP VREF Peripheral Access Layer
* @brief C Struct for VREF
* @{
*/

/* ================================================================================ */
/* ================           VREF (file:VREF_C)                   ================ */
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
#define VREF_TRM_TRIM_MASK                       (0x3FUL << VREF_TRM_TRIM_SHIFT)                     /*!< VREF_TRM: TRIM Mask                     */
#define VREF_TRM_TRIM_SHIFT                      0                                                   /*!< VREF_TRM: TRIM Position                 */
#define VREF_TRM_TRIM(x)                         (((uint8_t)(((uint8_t)(x))<<VREF_TRM_TRIM_SHIFT))&VREF_TRM_TRIM_MASK) /*!< VREF_TRM                                */
#define VREF_TRM_CHOPEN_MASK                     (0x01UL << VREF_TRM_CHOPEN_SHIFT)                   /*!< VREF_TRM: CHOPEN Mask                   */
#define VREF_TRM_CHOPEN_SHIFT                    6                                                   /*!< VREF_TRM: CHOPEN Position               */
#define VREF_TRM_CHOPEN(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_TRM_CHOPEN_SHIFT))&VREF_TRM_CHOPEN_MASK) /*!< VREF_TRM                                */
/* ------- SC Bit Fields                            ------ */
#define VREF_SC_MODE_LV_MASK                     (0x03UL << VREF_SC_MODE_LV_SHIFT)                   /*!< VREF_SC: MODE_LV Mask                   */
#define VREF_SC_MODE_LV_SHIFT                    0                                                   /*!< VREF_SC: MODE_LV Position               */
#define VREF_SC_MODE_LV(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_SC_MODE_LV_SHIFT))&VREF_SC_MODE_LV_MASK) /*!< VREF_SC                                 */
#define VREF_SC_VREFST_MASK                      (0x01UL << VREF_SC_VREFST_SHIFT)                    /*!< VREF_SC: VREFST Mask                    */
#define VREF_SC_VREFST_SHIFT                     2                                                   /*!< VREF_SC: VREFST Position                */
#define VREF_SC_VREFST(x)                        (((uint8_t)(((uint8_t)(x))<<VREF_SC_VREFST_SHIFT))&VREF_SC_VREFST_MASK) /*!< VREF_SC                                 */
#define VREF_SC_ICOMPEN_MASK                     (0x01UL << VREF_SC_ICOMPEN_SHIFT)                   /*!< VREF_SC: ICOMPEN Mask                   */
#define VREF_SC_ICOMPEN_SHIFT                    5                                                   /*!< VREF_SC: ICOMPEN Position               */
#define VREF_SC_ICOMPEN(x)                       (((uint8_t)(((uint8_t)(x))<<VREF_SC_ICOMPEN_SHIFT))&VREF_SC_ICOMPEN_MASK) /*!< VREF_SC                                 */
#define VREF_SC_REGEN_MASK                       (0x01UL << VREF_SC_REGEN_SHIFT)                     /*!< VREF_SC: REGEN Mask                     */
#define VREF_SC_REGEN_SHIFT                      6                                                   /*!< VREF_SC: REGEN Position                 */
#define VREF_SC_REGEN(x)                         (((uint8_t)(((uint8_t)(x))<<VREF_SC_REGEN_SHIFT))&VREF_SC_REGEN_MASK) /*!< VREF_SC                                 */
#define VREF_SC_VREFEN_MASK                      (0x01UL << VREF_SC_VREFEN_SHIFT)                    /*!< VREF_SC: VREFEN Mask                    */
#define VREF_SC_VREFEN_SHIFT                     7                                                   /*!< VREF_SC: VREFEN Position                */
#define VREF_SC_VREFEN(x)                        (((uint8_t)(((uint8_t)(x))<<VREF_SC_VREFEN_SHIFT))&VREF_SC_VREFEN_MASK) /*!< VREF_SC                                 */
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
#define WDOG_STCTRLH_WDOGEN_MASK                 (0x01UL << WDOG_STCTRLH_WDOGEN_SHIFT)               /*!< WDOG_STCTRLH: WDOGEN Mask               */
#define WDOG_STCTRLH_WDOGEN_SHIFT                0                                                   /*!< WDOG_STCTRLH: WDOGEN Position           */
#define WDOG_STCTRLH_WDOGEN(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_WDOGEN_SHIFT))&WDOG_STCTRLH_WDOGEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_CLKSRC_MASK                 (0x01UL << WDOG_STCTRLH_CLKSRC_SHIFT)               /*!< WDOG_STCTRLH: CLKSRC Mask               */
#define WDOG_STCTRLH_CLKSRC_SHIFT                1                                                   /*!< WDOG_STCTRLH: CLKSRC Position           */
#define WDOG_STCTRLH_CLKSRC(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_CLKSRC_SHIFT))&WDOG_STCTRLH_CLKSRC_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_IRQRSTEN_MASK               (0x01UL << WDOG_STCTRLH_IRQRSTEN_SHIFT)             /*!< WDOG_STCTRLH: IRQRSTEN Mask             */
#define WDOG_STCTRLH_IRQRSTEN_SHIFT              2                                                   /*!< WDOG_STCTRLH: IRQRSTEN Position         */
#define WDOG_STCTRLH_IRQRSTEN(x)                 (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_IRQRSTEN_SHIFT))&WDOG_STCTRLH_IRQRSTEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_WINEN_MASK                  (0x01UL << WDOG_STCTRLH_WINEN_SHIFT)                /*!< WDOG_STCTRLH: WINEN Mask                */
#define WDOG_STCTRLH_WINEN_SHIFT                 3                                                   /*!< WDOG_STCTRLH: WINEN Position            */
#define WDOG_STCTRLH_WINEN(x)                    (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_WINEN_SHIFT))&WDOG_STCTRLH_WINEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_ALLOWUPDATE_MASK            (0x01UL << WDOG_STCTRLH_ALLOWUPDATE_SHIFT)          /*!< WDOG_STCTRLH: ALLOWUPDATE Mask          */
#define WDOG_STCTRLH_ALLOWUPDATE_SHIFT           4                                                   /*!< WDOG_STCTRLH: ALLOWUPDATE Position      */
#define WDOG_STCTRLH_ALLOWUPDATE(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_ALLOWUPDATE_SHIFT))&WDOG_STCTRLH_ALLOWUPDATE_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_DBGEN_MASK                  (0x01UL << WDOG_STCTRLH_DBGEN_SHIFT)                /*!< WDOG_STCTRLH: DBGEN Mask                */
#define WDOG_STCTRLH_DBGEN_SHIFT                 5                                                   /*!< WDOG_STCTRLH: DBGEN Position            */
#define WDOG_STCTRLH_DBGEN(x)                    (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_DBGEN_SHIFT))&WDOG_STCTRLH_DBGEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_STOPEN_MASK                 (0x01UL << WDOG_STCTRLH_STOPEN_SHIFT)               /*!< WDOG_STCTRLH: STOPEN Mask               */
#define WDOG_STCTRLH_STOPEN_SHIFT                6                                                   /*!< WDOG_STCTRLH: STOPEN Position           */
#define WDOG_STCTRLH_STOPEN(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_STOPEN_SHIFT))&WDOG_STCTRLH_STOPEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_WAITEN_MASK                 (0x01UL << WDOG_STCTRLH_WAITEN_SHIFT)               /*!< WDOG_STCTRLH: WAITEN Mask               */
#define WDOG_STCTRLH_WAITEN_SHIFT                7                                                   /*!< WDOG_STCTRLH: WAITEN Position           */
#define WDOG_STCTRLH_WAITEN(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_WAITEN_SHIFT))&WDOG_STCTRLH_WAITEN_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_TESTWDOG_MASK               (0x01UL << WDOG_STCTRLH_TESTWDOG_SHIFT)             /*!< WDOG_STCTRLH: TESTWDOG Mask             */
#define WDOG_STCTRLH_TESTWDOG_SHIFT              10                                                  /*!< WDOG_STCTRLH: TESTWDOG Position         */
#define WDOG_STCTRLH_TESTWDOG(x)                 (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_TESTWDOG_SHIFT))&WDOG_STCTRLH_TESTWDOG_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_TESTSEL_MASK                (0x01UL << WDOG_STCTRLH_TESTSEL_SHIFT)              /*!< WDOG_STCTRLH: TESTSEL Mask              */
#define WDOG_STCTRLH_TESTSEL_SHIFT               11                                                  /*!< WDOG_STCTRLH: TESTSEL Position          */
#define WDOG_STCTRLH_TESTSEL(x)                  (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_TESTSEL_SHIFT))&WDOG_STCTRLH_TESTSEL_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_BYTESEL_MASK                (0x03UL << WDOG_STCTRLH_BYTESEL_SHIFT)              /*!< WDOG_STCTRLH: BYTESEL Mask              */
#define WDOG_STCTRLH_BYTESEL_SHIFT               12                                                  /*!< WDOG_STCTRLH: BYTESEL Position          */
#define WDOG_STCTRLH_BYTESEL(x)                  (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_BYTESEL_SHIFT))&WDOG_STCTRLH_BYTESEL_MASK) /*!< WDOG_STCTRLH                            */
#define WDOG_STCTRLH_DISTESTWDOG_MASK            (0x01UL << WDOG_STCTRLH_DISTESTWDOG_SHIFT)          /*!< WDOG_STCTRLH: DISTESTWDOG Mask          */
#define WDOG_STCTRLH_DISTESTWDOG_SHIFT           14                                                  /*!< WDOG_STCTRLH: DISTESTWDOG Position      */
#define WDOG_STCTRLH_DISTESTWDOG(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLH_DISTESTWDOG_SHIFT))&WDOG_STCTRLH_DISTESTWDOG_MASK) /*!< WDOG_STCTRLH                            */
/* ------- STCTRLL Bit Fields                       ------ */
#define WDOG_STCTRLL_INTFLG_MASK                 (0x01UL << WDOG_STCTRLL_INTFLG_SHIFT)               /*!< WDOG_STCTRLL: INTFLG Mask               */
#define WDOG_STCTRLL_INTFLG_SHIFT                15                                                  /*!< WDOG_STCTRLL: INTFLG Position           */
#define WDOG_STCTRLL_INTFLG(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_STCTRLL_INTFLG_SHIFT))&WDOG_STCTRLL_INTFLG_MASK) /*!< WDOG_STCTRLL                            */
/* ------- TOVAL Bit Fields                         ------ */
#define WDOG_TOVAL_TOVAL_MASK                    (0xFFFFFFFFUL << WDOG_TOVAL_TOVAL_SHIFT)            /*!< WDOG_TOVAL: TOVAL Mask                  */
#define WDOG_TOVAL_TOVAL_SHIFT                   0                                                   /*!< WDOG_TOVAL: TOVAL Position              */
#define WDOG_TOVAL_TOVAL(x)                      (((uint32_t)(((uint32_t)(x))<<WDOG_TOVAL_TOVAL_SHIFT))&WDOG_TOVAL_TOVAL_MASK) /*!< WDOG_TOVAL                              */
/* ------- TOVALH Bit Fields                        ------ */
#define WDOG_TOVALH_TOVALHIGH_MASK               (0xFFFFUL << WDOG_TOVALH_TOVALHIGH_SHIFT)           /*!< WDOG_TOVALH: TOVALHIGH Mask             */
#define WDOG_TOVALH_TOVALHIGH_SHIFT              0                                                   /*!< WDOG_TOVALH: TOVALHIGH Position         */
#define WDOG_TOVALH_TOVALHIGH(x)                 (((uint16_t)(((uint16_t)(x))<<WDOG_TOVALH_TOVALHIGH_SHIFT))&WDOG_TOVALH_TOVALHIGH_MASK) /*!< WDOG_TOVALH                             */
/* ------- TOVALL Bit Fields                        ------ */
#define WDOG_TOVALL_TOVALLOW_MASK                (0xFFFFUL << WDOG_TOVALL_TOVALLOW_SHIFT)            /*!< WDOG_TOVALL: TOVALLOW Mask              */
#define WDOG_TOVALL_TOVALLOW_SHIFT               0                                                   /*!< WDOG_TOVALL: TOVALLOW Position          */
#define WDOG_TOVALL_TOVALLOW(x)                  (((uint16_t)(((uint16_t)(x))<<WDOG_TOVALL_TOVALLOW_SHIFT))&WDOG_TOVALL_TOVALLOW_MASK) /*!< WDOG_TOVALL                             */
/* ------- WIN Bit Fields                           ------ */
#define WDOG_WIN_WIN_MASK                        (0xFFFFFFFFUL << WDOG_WIN_WIN_SHIFT)                /*!< WDOG_WIN: WIN Mask                      */
#define WDOG_WIN_WIN_SHIFT                       0                                                   /*!< WDOG_WIN: WIN Position                  */
#define WDOG_WIN_WIN(x)                          (((uint32_t)(((uint32_t)(x))<<WDOG_WIN_WIN_SHIFT))&WDOG_WIN_WIN_MASK) /*!< WDOG_WIN                                */
/* ------- WINH Bit Fields                          ------ */
#define WDOG_WINH_WINHIGH_MASK                   (0xFFFFUL << WDOG_WINH_WINHIGH_SHIFT)               /*!< WDOG_WINH: WINHIGH Mask                 */
#define WDOG_WINH_WINHIGH_SHIFT                  0                                                   /*!< WDOG_WINH: WINHIGH Position             */
#define WDOG_WINH_WINHIGH(x)                     (((uint16_t)(((uint16_t)(x))<<WDOG_WINH_WINHIGH_SHIFT))&WDOG_WINH_WINHIGH_MASK) /*!< WDOG_WINH                               */
/* ------- WINL Bit Fields                          ------ */
#define WDOG_WINL_WINLOW_MASK                    (0xFFFFUL << WDOG_WINL_WINLOW_SHIFT)                /*!< WDOG_WINL: WINLOW Mask                  */
#define WDOG_WINL_WINLOW_SHIFT                   0                                                   /*!< WDOG_WINL: WINLOW Position              */
#define WDOG_WINL_WINLOW(x)                      (((uint16_t)(((uint16_t)(x))<<WDOG_WINL_WINLOW_SHIFT))&WDOG_WINL_WINLOW_MASK) /*!< WDOG_WINL                               */
/* ------- REFRESH Bit Fields                       ------ */
#define WDOG_REFRESH_WDOGREFRESH_MASK            (0xFFFFUL << WDOG_REFRESH_WDOGREFRESH_SHIFT)        /*!< WDOG_REFRESH: WDOGREFRESH Mask          */
#define WDOG_REFRESH_WDOGREFRESH_SHIFT           0                                                   /*!< WDOG_REFRESH: WDOGREFRESH Position      */
#define WDOG_REFRESH_WDOGREFRESH(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_REFRESH_WDOGREFRESH_SHIFT))&WDOG_REFRESH_WDOGREFRESH_MASK) /*!< WDOG_REFRESH                            */
/* ------- UNLOCK Bit Fields                        ------ */
#define WDOG_UNLOCK_WDOGUNLOCK_MASK              (0xFFFFUL << WDOG_UNLOCK_WDOGUNLOCK_SHIFT)          /*!< WDOG_UNLOCK: WDOGUNLOCK Mask            */
#define WDOG_UNLOCK_WDOGUNLOCK_SHIFT             0                                                   /*!< WDOG_UNLOCK: WDOGUNLOCK Position        */
#define WDOG_UNLOCK_WDOGUNLOCK(x)                (((uint16_t)(((uint16_t)(x))<<WDOG_UNLOCK_WDOGUNLOCK_SHIFT))&WDOG_UNLOCK_WDOGUNLOCK_MASK) /*!< WDOG_UNLOCK                             */
/* ------- TMROUT Bit Fields                        ------ */
#define WDOG_TMROUT_TIMEROUTHIGH_MASK            (0xFFFFFFFFUL << WDOG_TMROUT_TIMEROUTHIGH_SHIFT)    /*!< WDOG_TMROUT: TIMEROUTHIGH Mask          */
#define WDOG_TMROUT_TIMEROUTHIGH_SHIFT           0                                                   /*!< WDOG_TMROUT: TIMEROUTHIGH Position      */
#define WDOG_TMROUT_TIMEROUTHIGH(x)              (((uint32_t)(((uint32_t)(x))<<WDOG_TMROUT_TIMEROUTHIGH_SHIFT))&WDOG_TMROUT_TIMEROUTHIGH_MASK) /*!< WDOG_TMROUT                             */
/* ------- TMROUTH Bit Fields                       ------ */
#define WDOG_TMROUTH_TIMEROUTHIGH_MASK           (0xFFFFUL << WDOG_TMROUTH_TIMEROUTHIGH_SHIFT)       /*!< WDOG_TMROUTH: TIMEROUTHIGH Mask         */
#define WDOG_TMROUTH_TIMEROUTHIGH_SHIFT          0                                                   /*!< WDOG_TMROUTH: TIMEROUTHIGH Position     */
#define WDOG_TMROUTH_TIMEROUTHIGH(x)             (((uint16_t)(((uint16_t)(x))<<WDOG_TMROUTH_TIMEROUTHIGH_SHIFT))&WDOG_TMROUTH_TIMEROUTHIGH_MASK) /*!< WDOG_TMROUTH                            */
/* ------- TMROUTL Bit Fields                       ------ */
#define WDOG_TMROUTL_TIMEROUTLOW_MASK            (0xFFFFUL << WDOG_TMROUTL_TIMEROUTLOW_SHIFT)        /*!< WDOG_TMROUTL: TIMEROUTLOW Mask          */
#define WDOG_TMROUTL_TIMEROUTLOW_SHIFT           0                                                   /*!< WDOG_TMROUTL: TIMEROUTLOW Position      */
#define WDOG_TMROUTL_TIMEROUTLOW(x)              (((uint16_t)(((uint16_t)(x))<<WDOG_TMROUTL_TIMEROUTLOW_SHIFT))&WDOG_TMROUTL_TIMEROUTLOW_MASK) /*!< WDOG_TMROUTL                            */
/* ------- RSTCNT Bit Fields                        ------ */
#define WDOG_RSTCNT_RSTCNT_MASK                  (0xFFFFUL << WDOG_RSTCNT_RSTCNT_SHIFT)              /*!< WDOG_RSTCNT: RSTCNT Mask                */
#define WDOG_RSTCNT_RSTCNT_SHIFT                 0                                                   /*!< WDOG_RSTCNT: RSTCNT Position            */
#define WDOG_RSTCNT_RSTCNT(x)                    (((uint16_t)(((uint16_t)(x))<<WDOG_RSTCNT_RSTCNT_SHIFT))&WDOG_RSTCNT_RSTCNT_MASK) /*!< WDOG_RSTCNT                             */
/* ------- PRESC Bit Fields                         ------ */
#define WDOG_PRESC_PRESCVAL_MASK                 (0x07UL << WDOG_PRESC_PRESCVAL_SHIFT)               /*!< WDOG_PRESC: PRESCVAL Mask               */
#define WDOG_PRESC_PRESCVAL_SHIFT                8                                                   /*!< WDOG_PRESC: PRESCVAL Position           */
#define WDOG_PRESC_PRESCVAL(x)                   (((uint16_t)(((uint16_t)(x))<<WDOG_PRESC_PRESCVAL_SHIFT))&WDOG_PRESC_PRESCVAL_MASK) /*!< WDOG_PRESC                              */
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


#endif  /* MCU_MK30D7 */

