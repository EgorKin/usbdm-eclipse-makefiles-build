#ifndef INCLUDE_USBDM_FONTS_H
#define INCLUDE_USBDM_FONTS_H

#include <stdint.h>

namespace USBDM {

struct Fonts {
public:
   /**
    * Font sizes
    */
   typedef enum {FontSmall, FontMedium, FontLarge} FontSize;

   static const uint8_t FONT6x8[97][8];
   static const uint8_t FONT8x8[97][8];
   static const uint8_t FONT8x16[97][16];
};

} // End namespace USBDM

#endif /* INCLUDE_USBDM_FONTS_H */
