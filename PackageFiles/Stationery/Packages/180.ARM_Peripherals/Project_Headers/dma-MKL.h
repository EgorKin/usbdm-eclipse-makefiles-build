/**
 * @file    dma.h  (180.ARM_Peripherals/Project_Headers/dma-MKL.h)
 * @brief   Direct Memory Controller
 *
 * @version  V4.12.1.210
 * @date     30 September 2017
 */

#ifndef INCLUDE_USBDM_DMA_H_
#define INCLUDE_USBDM_DMA_H_

#include "derivative.h"
#include "hardware.h"

/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
namespace USBDM {

/**
 * @addtogroup DMA_Group DMA, Direct Memory Access (DMA)
 * @brief Support for DMA operations
 * @{
 */

/**
 * Controls operation of DMA-MUX channel.
 */
enum DmaMuxEnable {
   DmaMuxEnable_Disabled    = DMAMUX_CHCFG_ENBL(0),                      //!< DMA channel is disabled
   DmaMuxEnable_Continuous = DMAMUX_CHCFG_ENBL(1)|DMAMUX_CHCFG_TRIG(0), //!< DMA channel is enabled continuously
   DmaMuxEnable_Triggered  = DMAMUX_CHCFG_ENBL(1)|DMAMUX_CHCFG_TRIG(1), //!< DMA channel is enabled and triggered by PIT channel
};

/**
 * DMA Channel numbers.
 */
enum DmaChannelNum {
   DmaChannelNum_0,      //!< Channel  0
   DmaChannelNum_1,      //!< Channel  1
   DmaChannelNum_2,      //!< Channel  2
   DmaChannelNum_3,      //!< Channel  3

   DmaChannelNum_All  = (1<<6),  //!< All channels, some operations may be applied to all channels
   DmaChannelNum_None = (1<<7),  //!< Used to indicate failed channel allocation 
};

/**
 * DMA transfer sizes.
 */
enum DmaSize {
   DmaSize_8bit    = 0b01,  //!< 8-bit transfer
   DmaSize_16bit   = 0b10,  //!< 16-bit transfer
   DmaSize_32bit   = 0b00,  //!< 32-bit transfer
};

/**
 * DMA modulo sizes.
 *
 * Defines the size of the data circular buffer used by the DMA Controller.\n
 * If enabled, the buffer base address is located on a boundary of the buffer size.\n
 * The value of this boundary depends on the initial transfer address (SAR/DAR).\n
 * The base address should be aligned to a 0-modulo-(circular buffer size) boundary.\n
 * Misaligned buffers are not possible. The boundary is forced to the value determined by the
 * upper address bits in the field selection.
 */
enum DmaModulo {
   DmaModulo_Disabled   = 0b0000, //!< Modulo function disabled
   DmaModulo_16bytes    = 0b0001, //!< Modulo 16-bytes
   DmaModulo_32bytes    = 0b0010, //!< Modulo 32-bytes
   DmaModulo_64bytes    = 0b0111, //!< Modulo 64-bytes
   DmaModulo_128bytes   = 0b0100, //!< Modulo 128-bytes
   DmaModulo_256bytes   = 0b0101, //!< Modulo 256-bytes
   DmaModulo_512bytes   = 0b0110, //!< Modulo 512-bytes
   DmaModulo_1KiBytes   = 0b0111, //!< Modulo 1 KiB
   DmaModulo_2KiBytes   = 0b1000, //!< Modulo 2 KiB
   DmaModulo_4KiBytes   = 0b1001, //!< Modulo 4 KiB
   DmaModulo_8KiBytes   = 0b1010, //!< Modulo 8 KiB
   DmaModulo_16KiBytes  = 0b1011, //!< Modulo 16 KiB
   DmaModulo_32KiBytes  = 0b1100, //!< Modulo 32 KiB
   DmaModulo_64KiBytes  = 0b1101, //!< Modulo 64 KiB
   DmaModulo_128KiBytes = 0b1110, //!< Modulo 128 KiB
   DmaModulo_256KiBytes = 0b1111, //!< Modulo 256 KiB
};

/**
 * Control Linking action of channel.
 *
 * Allows DMA channels to have their transfers linked.\n
 * The current DMA channel triggers a DMA request to the linked channels (LCH1 or LCH2) depending on the condition described by DmaLink bits.\n
 * DmaLink_Both and DmaLink_CycleSteal only link to LCH1 when in cycle-steal transfer mode (DCRn[CS]=DmaMode_CycleSteal).
 */
enum DmaLink {
   DmaLink_None         = 0b00, //!< No channel linking.
   DmaLink_Both         = 0b01, //!< Link to LCH1 after each cycle-steal followed by link to LCH2 after BCR decrements to zero.
   DmaLink_CycleSteal   = 0b10, //!< Perform a link to channel LCH1 after each cycle-steal transfer.
   DmaLink_Complete     = 0b11, //!< Perform a link to channel LCH1 after the BCR decrements to zero.
};

/**
 * Control whether a single or multiple transfers are done for each trigger event.
 */
enum DmaMode {
   DmaMode_Continuous = 0b0, //!< Transfer sequence started by peripheral request (DRC.ERQ) or software (DRC.START)
   DmaMode_CycleSteal = 0b1, //!< Single transfer per peripheral request (DRC.ERQ) or software (DRC.START)
};

/**
 * Type definition for DMA interrupt call back.
 *
 * channel[in] Channel
 */
typedef void (*DmaCallbackFunction)(DmaChannelNum channel);

/**
 * DMA Control register fields
 */
struct DmaTcdDcr {
   unsigned   LCH2:2;    //!< Link channel 2 see DmaLink
   unsigned   LCH1:2;    //!< Link channel 1 see DmaLink
   DmaLink    LINKCC:2;  //!< Link channel control
   unsigned   FILL1:1;
   bool       D_REQ:1;   //!< Disable peripheral requests (clear ERQ) when complete
   DmaModulo  DMOD:4;    //!< Destination address modulo
   DmaModulo  SMOD:4;    //!< Source address modulo
   bool       START:1;   //!< Start transfer (software triggered)
   DmaSize    DSIZE:2;   //!< Destination size
   bool       DINC:1;    //!< Destination increment
   DmaSize    SSIZE:2;   //!< Source size
   bool       SINC:1;    //!< Source increment
   bool       EADREQ:1;  //!< Enable asynchronous DMA
   unsigned   FILL2:4;
   bool       AA:1;      //!< Auto-align
   DmaMode    CS:1;      //!< Cycle steal or continuous mode
   bool       ERQ:1;     //!< Enable peripheral request
   bool       EINT:1;    //!< Enable interrupt request on completion of transfer

   /**
    * Empty constructor
    */
   constexpr DmaTcdDcr() :
         LCH2(0),
         LCH1(0),
         LINKCC(DmaLink_None),
         FILL1(0),
         D_REQ(0),
         DMOD(DmaModulo_Disabled),
         SMOD(DmaModulo_Disabled),
         START(false),
         DSIZE(DmaSize_32bit),
         DINC(0),
         SSIZE(DmaSize_32bit),
         SINC(0),
         EADREQ(0),
         FILL2(0),
         AA(0),
         CS(DmaMode_Continuous),
         ERQ(0),
         EINT(0)
   {}

   /**
    * Constructor
    *
    * @param sourceSize                         Source size
    * @param sourceModulo                       Source address modulo
    * @param sourceIncrement                    Source increment
    * @param destinationSize                    Destination size
    * @param destinationModulo                  Destination address modulo
    * @param destinationIncrement               Destination increment
    * @param dmaMode                            Cycle steal or continuous mode
    * @param autoAlign                          Auto-align
    * @param startTransfer                      Start transfer (software triggered)
    * @param enableAsynchronousRequests         Enable asynchronous DMA
    * @param enablePeripheralRequests           Enable peripheral request(set ERQ)
    * @param disablePeripheralRequestOnComplete Disable peripheral request (clear ERQ) when complete
    * @param enableInterrupts                   Enable interrupt on completion of transfer
    * @param linkControl                        Link channel control
    * @param linkChannel1                       Link channel 1
    * @param linkChannel2                       Link channel 2
    */
   constexpr DmaTcdDcr(
         DmaSize   sourceSize,
         DmaModulo sourceModulo,
         bool      sourceIncrement,
         DmaSize   destinationSize,
         DmaModulo destinationModulo,
         bool      destinationIncrement,
         DmaMode   dmaMode,
         bool      autoAlign,
         bool      startTransfer,
         bool      enableAsynchronousRequests,
         bool      enablePeripheralRequests,
         bool      disablePeripheralRequestOnComplete,
         bool      enableInterrupts,
         DmaLink   linkControl    = DmaLink_None,
         unsigned  linkChannel1   = 0,
         unsigned  linkChannel2   = 0
   ) :
      LCH2(linkChannel2),
      LCH1(linkChannel1),
      LINKCC(linkControl),
      FILL1(0),
      D_REQ(disablePeripheralRequestOnComplete),
      DMOD(destinationModulo),
      SMOD(sourceModulo),
      START(startTransfer),
      DSIZE(destinationSize),
      DINC(destinationIncrement),
      SSIZE(sourceSize),
      SINC(sourceIncrement),
      EADREQ(enableAsynchronousRequests),
      FILL2(0),
      AA(autoAlign),
      CS(dmaMode),
      ERQ(enablePeripheralRequests),
      EINT(enableInterrupts)
   {}
};

/**
 * Transfer Control Descriptor
 * @verbatim
 * +------------------------------+  DMA mode
 * | Loop =                       |  ===============================================================
 * | +--------------------------+ |
 * | | Each transfer            | |  The following are used during a loop:
 * | |   SADDR->DADDR           | |   - SADDR      Source address
 * | |   SADDR += DCR.SSIZE     | |   - DCR.SSIZE  Adjustment applied to SADDR after each transfer
 * | |   DADDR += DCR.DSIZE     | |   - DADDR      Destination address
 * | +--------------------------+ |   - DCR.DSIZE  Adjustment applied to DADDR after each transfer
 * |   Total transfer is BCR      |   - BCR        Number of bytes to transfer
 * +------------------------------+
 * @endverbatim
 *
 * Structure to define a DMA transfer
 */
struct DmaTcd {
   uint32_t  SAR;        //!< Source address
   uint32_t  DAR;        //!< Destination address
   uint32_t  BCR;        //!< Number of bytes to transfer bits [23:0] only
   DmaTcdDcr DCR;        //!< Control register

   /**
    * Empty constructor
    */
   constexpr DmaTcd():
      SAR(0),
      DAR(0),
      BCR(0),
      DCR(DmaTcdDcr()) {
   }

   /**
    *  Compound constructor
    *
    * @param transferSize         Number of bytes to transfer bits [23:0] only
    * @param sourceAddress        Source address
    * @param destinationAddress   Destination address
    * @param configuration        Transfer configuration
    */
   constexpr DmaTcd(
         uint32_t  transferSize,
         uint32_t  sourceAddress,
         uint32_t  destinationAddress,
         DmaTcdDcr configuration
         ) :
            SAR(sourceAddress),
            DAR(destinationAddress),
            BCR(transferSize),
            DCR(configuration)
   {
   }

   /**
    * Constructor
    *
    * @param transferSize                        Number of bytes to transfer bits [23:0] only
    * @param sourceAddress                       Source address
    * @param sourceSize                          Source size
    * @param sourceModulo                        Source address modulo
    * @param sourceIncrement                     Source increment
    * @param destinationAddress                  Destination address
    * @param destinationSize                     Destination size
    * @param destinationModulo                   Destination address modulo
    * @param destinationIncrement                Destination increment
    * @param dmaMode                             Cycle steal or continuous mode
    * @param autoAlign                           Auto-align
    * @param startTransfer                       Start transfer (software triggered)
    * @param enableAsynchronousRequests          Enable asynchronous DMA
    * @param enablePeripheralRequests            Enable peripheral request(set ERQ)
    * @param disablePeripheralRequestOnComplete  Disable peripheral request (clear ERQ) when complete
    * @param enableInterrupts                    Enable interrupt on completion of transfer
    * @param linkControl                         Link channel control
    * @param linkChannel1                        Link channel 1
    * @param linkChannel2                        Link channel 2
    */
   constexpr DmaTcd(
         uint32_t  transferSize,
         uint32_t  sourceAddress,
         DmaSize   sourceSize,
         DmaModulo sourceModulo,
         bool      sourceIncrement,
         uint32_t  destinationAddress,
         DmaSize   destinationSize,
         DmaModulo destinationModulo,
         bool      destinationIncrement,
         DmaMode   dmaMode,
         bool      autoAlign,
         bool      startTransfer,
         bool      enableAsynchronousRequests,
         bool      enablePeripheralRequests,
         bool      disablePeripheralRequestOnComplete,
         bool      enableInterrupts,
         DmaLink   linkControl   = DmaLink_None,
         unsigned  linkChannel1  = 0,
         unsigned  linkChannel2  = 0
   ) :
      SAR(sourceAddress),
      DAR(destinationAddress),
      BCR(transferSize),
      DCR(DmaTcdDcr(
            sourceSize,
            sourceModulo,
            sourceIncrement,
            destinationSize,
            destinationModulo,
            destinationIncrement,
            dmaMode,
            autoAlign,
            startTransfer,
            enableAsynchronousRequests,
            enablePeripheralRequests,
            disablePeripheralRequestOnComplete,
            enableInterrupts,
            linkControl,
            linkChannel1,
            linkChannel2
      )) {
   }
};

/**
 * Get DMA size of object.
 * For use in TCD.DSIZE, TCD.SSIZE value
 *
 * @param[in] obj Object to obtain DMA size value for
 *
 * @return one of the DmaSize_xxxx values
 */
template <class T>
static constexpr DmaSize dmaSize(const T &obj) {
   static_assert(((sizeof(obj)==1)||(sizeof(obj)==2)||(sizeof(obj)==4)), "Illegal DMA transfer size");
   return
      (sizeof(obj)==1) ?DmaSize_8bit:
      (sizeof(obj)==2) ?DmaSize_16bit:
      /*          ==4 */DmaSize_32bit;
}

/**
 * Get DMA size of object.
 * For use in TCD.DSIZE, TCD.SSIZE value
 *
 * @param[in] obj Object to obtain DMA size value for
 *
 * @return one of the DmaSize_xxxx values
 */
template <class T>
static constexpr DmaSize dmaSize(const T *obj) {
   static_assert(((sizeof(*obj)==1)||(sizeof(*obj)==2)||(sizeof(*obj)==4)), "Illegal DMA transfer size");
   return
      (sizeof(*obj)==1) ?DmaSize_8bit:
      (sizeof(*obj)==2) ?DmaSize_16bit:
      /*          ==4 */DmaSize_32bit;
}

/**
 * Get DMA size of object.
 * For use in TCD.DSIZE, TCD.SSIZE value
 *
 * @tparam T Type to get DMA size of
 *
 * @return one of the DmaSize_xxxx values
 */
template <class T>
static constexpr DmaSize dmaSize() {
   static_assert(((sizeof(T)==1)||(sizeof(T)==2)||(sizeof(T)==4)), "Illegal DMA transfer size");
   return
      (sizeof(T)==1) ?DmaSize_8bit:
      (sizeof(T)==2) ?DmaSize_16bit:
      /*          ==4 */DmaSize_32bit;
}

/**
 * Template class providing interface to DMA Multiplexor.
 *
 * @tparam DmaMuxInfo  Information class for DMAMux
 * @tparam NumChannels Number of DMA channels in associated DMA controller
 *
 * @code
 * using dmamux = DmaMux_T<DmaMuxInfo>;
 *
 *  dmamux::configure();
 *
 * @endcode
 */
template <class DmaMuxInfo, unsigned NumChannels>
class DmaMux_T {

public:
   /**
    * Configures and enable hardware requests on a channel.
    *
    * @param[in] dmaChannel   The DMA channel being enabled
    * @param[in] dmaSlot      The DMA slot (source) to connect to this channel
    * @param[in] dmaMuxEnable The mode for the channel
    */
   static void configure(DmaChannelNum dmaChannel, DmaSlot dmaSlot, DmaMuxEnable dmaMuxEnable=DmaMuxEnable_Continuous) {
#ifdef DEBUG_BUILD
      if (dmaChannel >= NumChannels) {
         // Channel doesn't exists
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
      if ((dmaMuxEnable == DmaMuxEnable_Triggered) && (dmaChannel>USBDM::PitInfo::NumChannels)) {
         // PIT triggering only available on channels corresponding to PIT channels
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
      if (((dmaChannel>=16)&&(dmaSlot<64))||((dmaChannel<16)&&(dmaSlot>=64))) {
         // DmaSlots 0-63 must associate with DMA channels 0-15
         // DmaSlots 64-128 must associate with DMA channels 15-31
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      // Enable clock to peripheral
      DmaMuxInfo::clockReg()  |= DmaMuxInfo::clockMask;

      // Configure channel - must be disabled to change
      DmaMuxInfo::dmamux().CHCFG[dmaChannel] = 0;
      DmaMuxInfo::dmamux().CHCFG[dmaChannel] = dmaMuxEnable|DMAMUX_CHCFG_SOURCE(dmaSlot);
   }

   /**
    * Disable hardware requests on channel
    *
    * @param dmaChannel DMA channel to disable
    */
   static void disable(DmaChannelNum dmaChannel) {
      // Enable clock to peripheral
      DmaMuxInfo::clockReg()  |= DmaMuxInfo::clockMask;

      // Disable channel
      DmaMuxInfo::dmamux().CHCFG[dmaChannel] = 0;
   }
};

/**
 * Class representing a DMA controller.
 *
 * @tparam Info Information describing DMA controller
 */
template<class Info>
class DmaBase_T {

   using MuxInfo = Dmamux0Info;

protected:
   /** Hardware instance pointer */
   static __attribute__((always_inline)) volatile DMA_Type &dmac() { return Info::dma(); }

   /** Clock register mask for peripheral */
   static __attribute__((always_inline)) volatile uint32_t &clockReg() { return Info::clockReg(); }

   /** Callback functions for ISRs */
   static DmaCallbackFunction sCallbacks[Info::NumVectors];

   /** Bit-mask of allocated channels */
   static uint32_t allocatedChannels;

   /** Callback to catch unhandled interrupt */
   static void noHandlerCallback(DmaChannelNum) {
      setAndCheckErrorCode(E_NO_HANDLER);
   }

public:
   /** DMA interrupt handler -  Calls DMA 0 callback */
   static void irq0Handler() {
      sCallbacks[0](DmaChannelNum_0);
   }

   /** DMA interrupt handler -  Calls DMA 1 callback */
   static void irq1Handler() {
      sCallbacks[1](DmaChannelNum_1);
   }

   /** DMA interrupt handler -  Calls DMA 2 callback */
   static void irq2Handler() {
      sCallbacks[2](DmaChannelNum_2);
   }

   /** DMA interrupt handler -  Calls DMA 3 callback */
   static void irq3Handler() {
      sCallbacks[3](DmaChannelNum_3);
   }

   /**
    * Enable and configure shared DMA settings.
    * This also clears all DMA channels.
    */
   static void configure() {
      // Enable clock to DMAC
      clockReg()  |= MuxInfo::clockMask;

      // Clear call-backs and TCDs
      for (unsigned channel=0; channel<Info::NumVectors; channel++) {
         static const DmaTcd emptyTcd;
         sCallbacks[channel] = noHandlerCallback;
         configureTransfer((DmaChannelNum)channel, emptyTcd);
      }
      // Reset record of allocated channels
      allocatedChannels = -1;
   }

   /**
    * Allocate DMA channel.
    *
    * @return DmaChannelNum_None - No suitable channel available.  Error code set.
    * @return Channel number     - Number of allocated channel
    */
   static DmaChannelNum allocateChannel() {
      unsigned channelNum = __builtin_ffs(allocatedChannels);
      if ((channelNum == 0)||(--channelNum>=Info::NumChannels)) {
         setErrorCode(E_NO_RESOURCE);
         return DmaChannelNum_None;
      }
      allocatedChannels &= ~(1<<channelNum);
      return (DmaChannelNum) channelNum;
   }

   /**
    * Allocate Periodic DMA channel.
    * This is a channel that may be throttled by an associated PIT channel.
    *
    * @return Error DmaChannelNum_None - No suitable channel available.  Error code set.
    * @return Channel number           - Number of allocated channel
    */
   static DmaChannelNum allocatePeriodicChannel() {
      unsigned channelNum = __builtin_ffs(allocatedChannels);
      if ((channelNum == 0)||(--channelNum>=Info::NumChannels)||(channelNum>=USBDM::PitInfo::NumChannels)) {
         setErrorCode(E_NO_RESOURCE);
         return DmaChannelNum_None;
      }
      allocatedChannels &= ~(1<<channelNum);
      return (DmaChannelNum) channelNum;
   }

   /**
    * Free DMA channel.
    *
    * @param dmaChannelNum Channel to release
    */
   static void freeChannel(DmaChannelNum dmaChannelNum) {
      usbdm_assert(dmaChannelNum<Info::NumChannels,        "Illegal DMA channel");
      usbdm_assert((allocatedChannels & channelMask) == 0, "Freeing unallocated DMA channel");
      allocatedChannels |= (1<<dmaChannelNum);
   }

   /**
    * Configure channel for arbitrary transfer defined by tcd.
    *
    * @param[in] channel DMA channel number
    * @param[in] tcd     Transfer Control Descriptor describing the transfer
    */
   static void configureTransfer(DmaChannelNum channel, const DmaTcd &tcd) {

      // Stop channel
      dmac().DMA[channel].DCR      = DMA_DCR_START(0)|DMA_DCR_ERQ(0);
      // Clear all flags
      dmac().DMA[channel].DSR_BCR  = DMA_DSR_BCR_DONE_MASK;

      // Copy TCD to DMAC channel
      (*(DmaTcd* const)(&dmac().DMA[channel])) = tcd;
   }

   /**
    * Waits until the channel indicates the transaction has completed.
    *	
    * @param[in] channel DMA channel number
    */
   static void waitUntilComplete(DmaChannelNum channel) {
      while ((dmac().DMA[channel].DSR & DMA_DSR_DONE_MASK) == 0) {
         __asm__ volatile("nop");
      }
      dmac().DMA[channel].DSR = DMA_DSR_DONE_MASK;
   }

   /**
    * Clear interrupt request flag for a channel.
    *
    * @param[in]  channel Channel being modified
    */
   static void __attribute__((always_inline)) clearInterruptRequest(DmaChannelNum channel) {
      dmac().DMA[channel].DSR_BCR = DMA_DSR_BCR_DONE_MASK;
      dmac().DMA[channel].DCR     = DMA_DCR_START(0)|DMA_DCR_ERQ(0);
   }

   /**
    * Enable channel interrupts in NVIC.
    * Any pending NVIC interrupts are first cleared.
    *
    * @param[in]  dmaChannelNum  Channel being modified
    */
   static void enableNvicInterrupts(DmaChannelNum dmaChannelNum) {
      usbdm_assert(dmaChannelNum<Info::NumChannels, "Illegal DMA channel");

      const IRQn_Type irqNum = Dma0Info::irqNums[0] + (dmaChannelNum&(Dma0Info::NumChannels-1));
      enableNvicInterrupt(irqNum);
   }

   /**
    * Enable and set priority of channel interrupts in NVIC.
    * Any pending NVIC interrupts are first cleared.
    *
    * @param[in]  dmaChannelNum  Channel being modified
    * @param[in]  nvicPriority   Interrupt priority
    */
   static void enableNvicInterrupts(DmaChannelNum dmaChannelNum, uint32_t nvicPriority) {
      usbdm_assert(dmaChannelNum<Info::NumChannels, "Illegal DMA channel");

      const IRQn_Type irqNum = Dma0Info::irqNums[0] + (dmaChannelNum&(Dma0Info::NumChannels-1));
      enableNvicInterrupt(irqNum, nvicPriority);
   }

   /**
    * Disable channel interrupts in NVIC.
    *
    * @param[in]  dmaChannelNum  Channel being modified
    */
   static void disableNvicInterrupts(DmaChannelNum dmaChannelNum) {
      usbdm_assert(dmaChannelNum<Info::NumChannels, "Illegal DMA channel");

      const IRQn_Type irqNum = Dma0Info::irqNums[0] + (dmaChannelNum&(Dma0Info::NumChannels-1));
      NVIC_DisableIRQ(irqNum);
   }


   /**
    * Set callback for ISR.
    *
    * @param[in]  channel  The DMA channel to set callback for
    * @param[in]  callback The function to call from stub ISR
    */
   static void __attribute__((always_inline)) setCallback(DmaChannelNum dmaChannelNum, DmaCallbackFunction callback) {
      if (callback == nullptr) {
         callback = noHandlerCallback;
      }
      sCallbacks[dmaChannelNum] = callback;
   }

};

/**
 * Callback table for programmatically set handlers.
 */
template<class Info> DmaCallbackFunction DmaBase_T<Info>::sCallbacks[];

/** Bit-mask of allocated channels */
template<class Info> uint32_t DmaBase_T<Info>::allocatedChannels = -1;

#ifdef USBDM_DMAMUX0_IS_DEFINED
using DmaMux0 = DmaMux_T<Dmamux0Info, Dma0Info::NumChannels>;
#endif

#ifdef USBDM_DMAMUX1_IS_DEFINED
using DmaMux1 = DmaMux_T<Dmamux1Info, Dma0Info::NumChannels>;
#endif

#ifdef USBDM_DMA0_IS_DEFINED
using Dma0 = DmaBase_T<Dma0Info>;
#endif

#ifdef USBDM_DMA1_IS_DEFINED
using Dma0 = DmaBase_T<Dma1Info>;
#endif

/**
 * End DMA_Group
 * @}
 */
} // End namespace USBDM

#endif /* INCLUDE_USBDM_DMA_H_ */
