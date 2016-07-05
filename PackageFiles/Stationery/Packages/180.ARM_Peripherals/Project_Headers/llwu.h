/*
 * llwu.h
 *
 *  Created on: 25/10/2013
 *      Author: podonoghue
 */

#ifndef LLWU_H_
#define LLWU_H_
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
 * Type definition for LLWU interrupt call back
 *
 *  @param timeSinceEpoch - Time since the epoch in seconds
 */
typedef void (*LLWUCallbackFunction)();

template <class Info>
class LlwuBase_T {

protected:
   static constexpr volatile LLWU_Type *llwu     = Info::llwu;

public:
   /**
    * Initialise LLWU to default settings\n
    * Configures all LLWU pins
    */
   static void initialise() {

      // Configure pins
      Info::initPCRs();

      llwu->PE1   = Info::pe1;
      llwu->PE2   = Info::pe2;
      llwu->PE3   = Info::pe3;
      llwu->PE4   = Info::pe4;

      llwu->ME    = Info::me;

      llwu->FILT1 = Info::filt1|LLWU_FILT_FILTF_MASK;
      llwu->FILT2 = Info::filt2|LLWU_FILT_FILTF_MASK;

      llwu->RST   = Info::rst;

      if (Info::irqHandlerInstalled) {
         // Enable timer interrupts
         NVIC_EnableIRQ(Info::irqNums[0]);

         // Set priority level
         NVIC_SetPriority(Info::irqNums[0], Info::irqLevel);
      }

   }
};

/**
 * Template class to provide LLWU callback
 */
template<class Info>
class LlwuIrq_T : public LlwuBase_T<Info> {

protected:
   /** Callback function for ISR */
   static LLWUCallbackFunction callback;

public:
   /**
    * IRQ handler
    */
   static void irqHandler(void) {
      if (callback != 0) {
         callback();
      }
   }

   /**
    * Set Callback function
    *
    *   @param theCallback - Callback function to be executed on LLWU interrupt
    */
   static void setCallback(LLWUCallbackFunction theCallback) {
      callback = theCallback;
      if (callback != NULL) {
         // Enable interrupts from LLWU alarm
         NVIC_EnableIRQ(Info::irqNums[0]);
      }
      else {
         // Disable interrupts from LLWU alarm
         NVIC_DisableIRQ(Info::irqNums[0]);
      }
   }
};

template<class Info> LLWUCallbackFunction LlwuIrq_T<Info>::callback = 0;

#ifdef USBDM_LLWU_IS_DEFINED
/**
 * Class representing LLWU
 */
using Llwu = LlwuIrq_T<LlwuInfo>;

#endif

} // End namespace USBDM

#endif /* LLWU_H_ */