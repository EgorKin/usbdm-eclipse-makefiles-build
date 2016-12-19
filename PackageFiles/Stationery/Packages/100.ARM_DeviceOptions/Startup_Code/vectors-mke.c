/*
 *  @file Vectors.c
 *  Derived from  Vectors-mke.c
 *
 *  Generic vectors and security for Kinetis MKExx
 *
 *  Created on: 07/12/2012
 *      Author: podonoghue
 */
#include <stdint.h>
#include <string.h>
#include "derivative.h"

/*
 * Security information
 */
typedef struct {
   uint8_t  backdoorKey[8];
   uint32_t reseved;
   uint8_t  eeprot;
   uint8_t  fprot;
   uint8_t  fsec;
   uint8_t  fopt;
} SecurityInfo;

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------
/*
  <h> Flash Configuration
  <i> 16-byte flash configuration field that stores default protection settings (loaded on reset)
  <i> and security information that allows the MCU to restrict access to the FTFL module.
  
  <h> Backdoor Comparison Key
  <i> The Verify Backdoor Access Key command releases security if user-supplied keys
  <i> matches the Backdoor Comparison Key bytes
    <o0>  Backdoor Comparison Key 0.  <0x0-0xFF>
    <o1>  Backdoor Comparison Key 1.  <0x0-0xFF>
    <o2>  Backdoor Comparison Key 2.  <0x0-0xFF>
    <o3>  Backdoor Comparison Key 3.  <0x0-0xFF>
    <o4>  Backdoor Comparison Key 4.  <0x0-0xFF>
    <o5>  Backdoor Comparison Key 5.  <0x0-0xFF>
    <o6>  Backdoor Comparison Key 6.  <0x0-0xFF>
    <o7>  Backdoor Comparison Key 7.  <0x0-0xFF>
  </h>
 */
#define BACKDOOR_VALUE {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, }
/*
   <h> Flash Region Protect (NV_FDPROT)
      <i> Each bit protects a 1/8 region of the flash memory.
      <q.0>   FPROT.0	<0=>protected  <1=>unprotected   <info> lowest 1/8 block
      <q.1>   FPROT.1  <0=>protected  <1=>unprotected
      <q.2>   FPROT.2  <0=>protected  <1=>unprotected
      <q.3>   FPROT.3  <0=>protected  <1=>unprotected
      <q.4>   FPROT.4  <0=>protected  <1=>unprotected
      <q.5>   FPROT.5  <0=>protected  <1=>unprotected
      <q.6>   FPROT.6  <0=>protected  <1=>unprotected
      <q.7>   FPROT.7	<0=>protected  <1=>unprotected   <info> highest 1/8 block
   </h>
*/
#define FPROT_VALUE 0xFF
/*
   <h> EEPROM Region Protect (NV_EEPROT)
      <i> Each bit protects a 1/8 region of the EEPROM memory.
      <i> (FlexNVM devices only)
      <q.0>   EEPROT.0	<0=>protected  <1=>unprotected   <info> lowest 1/8 block
      <q.1>   EEPROT.1  <0=>protected  <1=>unprotected
      <q.2>   EEPROT.2  <0=>protected  <1=>unprotected
      <q.3>   EEPROT.3  <0=>protected  <1=>unprotected
      <q.4>   EEPROT.4  <0=>protected  <1=>unprotected
      <q.5>   EEPROT.5  <0=>protected  <1=>unprotected
      <q.6>   EEPROT.6  <0=>protected  <1=>unprotected
      <q.7>   EEPROT.7	<0=>protected  <1=>unprotected   <info> highest 1/8 block
   </h>
*/
#define EEPROT_VALUE 0xFF

/*
<h> Flash security value (NV_FSEC)
   <o0> Backdoor Key Security Access Enable (FSEC.KEYEN)
      <i> Controls use of Backdoor Key access to unsecure device
      <info>KEYEN
      <2=> 2: Access enabled
      <3=> 3: Access disabled
   <o1> Flash Security (FSEC.SEC)
      <i> Defines the security state of the MCU. 
      <i> In the secure state, the MCU limits access to flash memory module resources. 
      <i> If the flash memory module is unsecured using backdoor key access, SEC is forced to 10b.
      <info>SEC
      <2=> 2: Unsecured
      <3=> 3: Secured
</h>
*/
#define FSEC_VALUE ((3<<NV_FSEC_KEYEN_SHIFT)|(2<<NV_FSEC_SEC_SHIFT)|0x3C)

/*
<h> Flash option Value (NV_FTFA_FOPT)
   <o> The FOPT value is copied from Flash to FTMRH_FOPT on reset  <0-255>
</h>
*/
#define FOPT_VALUE (0xFF)

__attribute__ ((section(".security_information")))
const SecurityInfo securityInfo = {
    /* backdoor */ BACKDOOR_VALUE,
    /* reseved  */ 0xFFFFFFFF,
    /* eeprot   */ EEPROT_VALUE,
    /* fprot    */ FPROT_VALUE,
    /* fsec     */ FSEC_VALUE,
    /* fopt     */ FOPT_VALUE,
};

/*
 * Vector table related
 */
typedef void( *const intfunc )( void );

#define WEAK_DEFAULT_HANDLER __attribute__ ((__weak__, alias("Default_Handler")))

#ifndef SCB_ICSR
#define SCB_ICSR (*(volatile uint32_t*)(0xE000ED04))
#endif

/**
 * Default handler for interrupts
 *
 * Most of the vector table is initialised to point at this handler.
 *
 * If you end up here it probably means:
 *   - Failed to enable the interrupt handler in the USBDM device configuration
 *   - You have accidently enabled an interrupt source in a peripheral
 *   - Enabled the wrong interrupt source
 *   - Failed to install or create a handler for an interrupt you intended using e.g. mis-spelled the name.
 *     Compare your handler (C function) name to that used in the vector table.
 *
 * You can check 'vectorNum' below to determine the interrupt source.  Look this up in the vector table below.
 */
__attribute__((__interrupt__))
void Default_Handler(void) {

   __attribute__((unused))
   volatile uint32_t vectorNum = (SCB_ICSR&SCB_ICSR_VECTACTIVE_Msk)>>SCB_ICSR_VECTACTIVE_Pos;

   while (1) {
      __BKPT(0);
   }
}

typedef struct {
   unsigned int r0;
   unsigned int r1;
   unsigned int r2;
   unsigned int r3;
   unsigned int r12;
   void       (*lr)();
   void       (*pc)();
   unsigned int psr;
} ExceptionFrame;

/*  Low-level exception handler
 *
 *  Interface from asm to C.
 *  Passes address of exception handler to C-level handler
 *
 *  See http://www.freertos.org/Debugging-Hard-Faults-On-Cortex-M-Microcontrollers.html
 */
__attribute__((__naked__, __weak__, __interrupt__))
void HardFault_Handler(void) {
   /*
    * Determines the active stack pointer and loads it into r0
    * This is used as the 1st argument to _HardFault_Handler(volatile ExceptionFrame *exceptionFrame)
    * and allows access to the saved processor state.
    * Other registers are unchanged and available in the usual register view
    */
   __asm__ volatile (
          "       mov r0,lr                                     \n"
          "       mov r1,#4                                     \n"
          "       and r0,r1                                     \n"
          "       bne skip1                                     \n"
          "       mrs r0,msp                                    \n"
          "       b   skip2                                     \n"
          "skip1:                                               \n"
          "       mrs r0,psp                                    \n"
          "skip2:                                               \n"
          "       nop                                           \n"
          "       ldr r2, handler_addr_const                    \n"
          "       bx r2                                         \n"
          "       handler_addr_const: .word _HardFault_Handler  \n"
      );
}

/******************************************************************************/
/* Hard fault handler in C with stack frame location as input parameter
 *
 * Assumed exception frame without floating-point storage
 *
 * @param exceptionFrame address of exception frame
 *
 * If you end up here you have probably done one of the following:
 *   - Accessed illegal/unimplemented memory e.g. gone off the end of an array
 *   - Accessed a disabled peripheral - Check you have enabled the clock
 *   - Accessed unaligned memory - unlikely I guess
 *
 */
__attribute__((__naked__))
void _HardFault_Handler(volatile ExceptionFrame *exceptionFrame __attribute__((__unused__))) {
   while (1) {
      // Stop here for debugger
      __BKPT(0);
   }
}

void __HardReset(void) __attribute__((__interrupt__));

extern uint32_t __StackTop;

/*
 * Each vector is assigned an unique name.  This is then 'weakly' assigned to the
 * default handler.
 * To install a handler, create a function with the name shown and it will override
 * the weak default.
 */
$(cVectorTable)

