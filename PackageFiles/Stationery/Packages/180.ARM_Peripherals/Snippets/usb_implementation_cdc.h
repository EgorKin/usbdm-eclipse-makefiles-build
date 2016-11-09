/*
 * usb_implementation.h
 *
 *  Created on: 30Oct.,2016
 *      Author: podonoghue
 *
 *  This file provides the implementation specific code for the USB interface.
 *  It will need to be modified to suit an application.
 */

#ifndef PROJECT_HEADERS_USB_IMPLEMENTATION_H_
#define PROJECT_HEADERS_USB_IMPLEMENTATION_H_

/*
 * Under Windows 8, or 10 there is no need to install a driver for
 * the bulk end-points if the MS_COMPATIBLE_ID_FEATURE is enabled.
 * winusb.sys driver will be automatically loaded.
 *
 * Under Windows 10 the usbser.sys driver will be loaded automatically
 * for the CDC (serial) interface
 *
 * Under Linux drivers for bulk and CDC are automatically loaded
 */
#define MS_COMPATIBLE_ID_FEATURE
#include "usb_cdc_uart.h"

#define UNIQUE_ID
//#include "configure.h"

namespace USBDM {

//======================================================================
// Customise for each USB device
//

/** Causes a semi-unique serial number to be generated for each USB device */
#define UNIQUE_ID

#ifndef SERIAL_NO
#ifdef UNIQUE_ID
#define SERIAL_NO "USBDM-MK-%lu"
#else
#define SERIAL_NO "USBDM-MK-0001"
#endif
#endif
#ifndef PRODUCT_DESCRIPTION
#define PRODUCT_DESCRIPTION "USBDM ARM-SWD for MK"
#endif
#ifndef MANUFACTURER
#define MANUFACTURER        "pgo"
#endif

#ifndef VENDOR_ID
#define VENDOR_ID  (0x16D0)
#endif
#ifndef PRODUCT_ID
#define PRODUCT_ID (0x8888)
#endif
#ifndef VERSION_ID
#define VERSION_ID (0x0100)
#endif

//======================================================================
// Maximum packet sizes for each endpoint
//
static constexpr uint  CONTROL_EP_MAXSIZE           = 64; //!< Control in/out    64

static constexpr uint  CDC_NOTIFICATION_EP_MAXSIZE  = 16; //!< CDC notification  16
static constexpr uint  CDC_DATA_OUT_EP_MAXSIZE      = 16; //!< CDC data out      16
static constexpr uint  CDC_DATA_IN_EP_MAXSIZE       = 16; //!< CDC data in       16

#ifdef USBDM_USB0_IS_DEFINED
/**
 * Class representing USB0
 */
class Usb0 : public UsbBase_T<Usb0Info, CONTROL_EP_MAXSIZE> {

   friend UsbBase_T<Usb0Info, CONTROL_EP_MAXSIZE>;

public:
   /**
    * String indexes
    *
    * Must agree with stringDescriptors[] order
    */
   enum StringIds {
      /** Language information for string descriptors */
      s_language_index=0,    // Must be zero
      /** Manufacturer */
      s_manufacturer_index,
      /** Product Description */
      s_product_index,
      /** Serial Number */
      s_serial_index,
      /** Configuration Index */
      s_config_index,

      /** Name of CDC interface */
      s_cdc_interface_index,
      /** CDC Control Interface */
      s_cdc_control_interface_index,
      /** CDC Data Interface */
      s_cdc_data_Interface_index,
      /*
       * TODO Add additional String indexes
       */

      /** Marks last entry */
      s_last_string_descriptor_index
   };

   /**
    * Endpoint numbers\n
    * Must be consecutive
    */
   enum EndpointNumbers {
      /** USB Control endpoint number - must be zero */
      CONTROL_ENDPOINT  = 0,

      /* end-points are assumed consecutive */

      /** CDC Control endpoint number */
      CDC_NOTIFICATION_ENDPOINT,
      /** CDC Data out endpoint number */
      CDC_DATA_OUT_ENDPOINT,
      /** CDC Data in endpoint number */
      CDC_DATA_IN_ENDPOINT,

      /*
       * TODO Add additional Endpoint numbers here
       */
      /** Total number of end-points */
      NUMBER_OF_ENDPOINTS,
   };

   /**
    * Configuration numbers, consecutive from 1
    */
   enum Configurations {
     CONFIGURATION_NUM = 1,
     /*
      * Assumes single configuration
      */
     /** Total number of configurations */
     NUMBER_OF_CONFIGURATIONS = CONFIGURATION_NUM,
   };

   /**
    * String descriptor table
    */
   static const uint8_t *const stringDescriptors[];

protected:
   /* end-points */
   static const InEndpoint  <Usb0Info, Usb0::CDC_NOTIFICATION_ENDPOINT, CDC_NOTIFICATION_EP_MAXSIZE>  epCdcNotification;
   static const OutEndpoint <Usb0Info, Usb0::CDC_DATA_OUT_ENDPOINT,     CDC_DATA_OUT_EP_MAXSIZE>      epCdcDataOut;
   static const InEndpoint  <Usb0Info, Usb0::CDC_DATA_IN_ENDPOINT,      CDC_DATA_IN_EP_MAXSIZE>       epCdcDataIn;
   /*
    * TODO Add additional End-points here
    */

public:

   /**
    * Initialise the USB interface
    */
   static void initialise();

   /**
    * Handler for USB interrupt
    *
    * Determines source and dispatches to appropriate routine.
    */
   static void irqHandler(void);

   /**
    * CDC Transmit
    *
    * @param data Pointer to data to transmit
    * @param size Number of bytes to transmit
    */
   static void cdcSendData(const uint8_t *data, unsigned size);

   /**
    * CDC Receive
    *
    * @param data    Pointer to data to receive
    * @param maxSize Maximum number of bytes to receive
    *
    * @return Number of bytes received
    */
   static int cdcReceiveData(uint8_t *data, unsigned maxSize);

   /**
    * Device Descriptor
    */
   static const DeviceDescriptor deviceDescriptor;

   /**
    * Other descriptors type
    */
   struct Descriptors;

   /**
    * Other descriptors
    */
   static const Descriptors otherDescriptors;

protected:
   /**
    * Initialises all end-points
    */
   static void initialiseEndpoints(void) {
      UsbBase_T::initialiseEndpoints();
      epCdcNotification.initialise();
      epCdcDataOut.initialise();
      epCdcDataIn.initialise();

      epCdcDataOut.setCallback(cdcOutTransactionCallback);
      epCdcDataIn.setCallback(cdcInTransactionCallback);

      // Start CDC status transmission
      epCdcSendNotification();
	  
	  // Make sure epCdcDataOut is ready for polling (OUT)
      epCdcDataOut.startRxTransaction(EPDataOut);

      static const uint8_t cdcInBuff[] = "Hello there\n";
      epCdcDataIn.startTxTransaction(sizeof(cdcInBuff), cdcInBuff, EPDataIn);
      /*
       * TODO Initialise additional End-points here
       */
   }

   /**
    * Callback for SOF tokens
    */
   static void sofCallback();

   /**
    * Call-back handling CDC-INtransaction complete
    */
   static void cdcInTransactionCallback(EndpointState state);

   /**
    * Call-back handling CDC-OUT transaction complete
    */
   static void cdcOutTransactionCallback(EndpointState state);

   /**
    * Handler for Token Complete USB interrupts for\n
    * end-points other than EP0
    */
   static void handleTokenComplete(void);

   static void startCdcIn();

   /**
    * Configure epCdcNotification for an IN transaction [Tx, device -> host, DATA0/1]
    */
   static void epCdcSendNotification();

   /**
    * Handle SETUP requests not handled by base handler
    *
    * @param setup SETUP packet received from host
    */
   static void handleUserEp0SetupRequests(const SetupPacket &setup);

   /**
    * CDC Set line coding handler
    */
   static void handleSetLineCoding();

   /**
    * CDC Set line coding handler
    */
   static void handleGetLineCoding();

   /**
    * CDC Set line state handler
    */
   static void handleSetControlLineState();

   /**
    * CDC Send break handler
    */
   static void handleSendBreak();

};

using UsbImplementation = Usb0;
#endif // USBDM_USB0_IS_DEFINED

} // End namespace USBDM

#endif /* PROJECT_HEADERS_USB_IMPLEMENTATION_H_ */
