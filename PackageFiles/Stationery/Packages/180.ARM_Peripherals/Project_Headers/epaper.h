/**
 * @file     EPaper.h
 * @brief    Drawing routines for EPaper
 *
 * @version  V4.11.1.70
 * @date     18 June 2015
 *
 * 2013 Copyright (c) Seeed Technology Inc.  All right reserved.
 *
 * Modified by Loovee
 * www.seeedstudio.com
 * 2013-7-2
 *
 * Modified for Kinetis FRDM boards by Peter O'Donoghue
 * 2014
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __EPAPER_H__
#define __EPAPER_H__

#include <string.h>
#include "gt20l16.h"
#include "epd.h"

namespace USBDM {

/**
 * @addtogroup EPaper_Group E-paper interface
 * @brief C++ Class allowing access to E-paper display
 * @{
 */

#define BLACK   1
#define WHITE   0

/**
 * Base class supplying drawing routines for EPaper
 */
class EPaper {

public:
   //! Orientation
   enum Orientation {
      PORTRAIT,  //!< Portrait orientation
      LANDSCAPE, //!< Landscape orientation
   };
   //! Paint mode
   enum WriteMode {
      PAINTMODE,  //!< Pixel is replaced by new value
      ORMODE,     //!< Existing pixel is ORed with new value
      XORMODE,    //!< Existing pixel is XORed with new value
      ANDINVERT,  //!< Existing pixel is ANDed with the inversion of new value
   };

protected:
   GT20L16         *gt20l16;                 //!< Character generator
   Epd             *epd;                     //!< EPD panel driver
   EpdSize          size;                    //!< EPD size
   Orientation      orientation;             //!< Orientation of display
   unsigned         width;                   //!< Width of display
   unsigned         height;                  //!< Height of display
   uint8_t          frameBuffer[264*176/8];  //!< Frame buffer (max size)
   bool             invertX;                 //!< Invert in x axis
   bool             invertY;                 //!< Invert in y axis
   WriteMode        writeMode;               //!< Write mode (Paint, xor etc)

   /**
    * Get temperature from temperature sensor
    *
    * @return Temperature in Celsius
    */
   virtual int getTemperature() = 0;

public:
   /**
    * Constructor - Create ePaper interface
    *
    * @param gt20l16 Character ROM interface
    * @param epd     EPD low-level interface
    */
   EPaper(GT20L16 *gt20l16, Epd *epd);

   /**
    * Set vertical inversion
    *
    * @param doit True to invert display
    */
   void setInvertX(bool doit) {
      invertX = doit;
   }

   /**
    * Set horizontal inversion
    *
    * @param doit True to reverse display
    */
   void setInvertY(bool doit) {
      invertY = doit;
   }

   /**
    * Set write mode
    *
    * @param writeMode Select PAINT, XOR or OR mode
    */
   void setWriteMode(WriteMode writeMode) {
      this->writeMode = writeMode;
   }

   /**
    * Set display orientation
    *
    * @param orientation Orientation (PORTRAIT or LANDSCAPE)
    */
   void setOrientation(Orientation orientation) {
      this->orientation = orientation;
      switch(orientation) {
         case PORTRAIT:
            width  = epd->getHeight();
            height = epd->getWidth();
            break;

         default:
         case LANDSCAPE:
            width  = epd->getWidth();
            height = epd->getHeight();
            break;
      }
   }

   /**
    * Get current width of display
    * (Obeys orientation)
    *
    * @return width
    */
   unsigned getWidth() {
      return width;
   }

   /**
    * Get current height of display
    * (Obeys orientation)
    *
    * @return height
    */
   unsigned getHeight() {
      return height;
   }

   /**
    * Clear the EPD
    * This immediately clears the Electronic Paper Display (sets to white)
    */
   void clearDisplay() {
      epd->setDisplayTemperature(getTemperature());  // Adjust for current temperature
      epd->powerOnAndInitialise();       // Power up the EPD panel
      epd->clear();                      // Clear display
      epd->powerOff();                   // Power down EPD panel
   }

   /**
    * Send an image to the EPD
    * The image is immediately displayed on the Electronic Paper Display
    *
    * @param image Image to send
    */
   void writeImage(const unsigned char *image) {
      epd->setDisplayTemperature(getTemperature());  // Adjust for current temperature
      epd->powerOnAndInitialise();       // Power up the EPD panel
      epd->image(image);                 // Send image
      epd->powerOff();                   // Power down EPD panel
   }

   /**
    * This writes the frame buffer to the EPD
    * It is expected that the various draw functions have been used to create an image beforehand.
    */
   void displayCanvas() {
      epd->setDisplayTemperature(getTemperature());  // Adjust for current temperature
      epd->powerOnAndInitialise();       // Power up the EPD panel
      epd->image(frameBuffer);           // Write to EPD
      epd->powerOff();                   // Power down EPD panel
   }

   /**
    * Clear the canvas.
    * This should be done before creating a new image.
    */
   void clearCanvas(void) {
      memset(frameBuffer, 0x00, sizeof(frameBuffer));
   }

   /**
    * Draw a single pixel to frame buffer
    *
    * @param x       X-coordinate
    * @param y       Y-coordinate
    * @param colour  Colour of pixel
    */
   void drawPixel(unsigned x, unsigned y, unsigned char colour);
   /**
    * Draw a character to frame buffer
    *
    * @param c       Character to draw
    * @param x       X-coordinate
    * @param y       Y-coordinate
    */
   int  drawChar(char c, unsigned x, unsigned y);
   /**
    * Draw a string to frame buffer
    *
    * @param string  String to draw
    * @param x       X-coordinate
    * @param y       Y-coordinate
    */
   int  drawString(const char *string, unsigned x, unsigned y);
   /**
    * Draw a long number to frame buffer
    *
    * @param longNum  Number to draw
    * @param x         X-coordinate
    * @param y         Y-coordinate
    */
   int  drawNumber(long longNum, unsigned x, unsigned y);
   /**
    * Draw a number to float number buffer
    *
    * @param floatNum  Number to draw
    * @param decimal   The number of decimal places
    * @param x         X-coordinate
    * @param y         Y-coordinate
    */
   int  drawFloat(float floatNum, unsigned decimal, unsigned x, unsigned y);
   /**
    * Draw a UNICODE character to frame buffer
    *
    * @param uniCode Character to draw
    * @param x       X-coordinate
    * @param y       Y-coordinate
    */
   int  drawUnicode(unsigned uniCode, unsigned x, unsigned y);
   /**
    *   Draw a UNICODE character using generator map
    *
    *   @param matrix  The character generator matrix to draw
    *   @param dataLen Size of matrix
    *   @param x       X position
    *   @param y       Y position
    *
    *   @return Width of character (for placement of next char)
    */
   int  drawUnicode(const uint8_t *matrix, unsigned dataLen, unsigned x, unsigned y);
   /**
    *   Draw a UNICODE character string
    *
    *   @param uniCode  The character generator matrix to draw
    *   @param length   Number of characters
    *   @param x        X position
    *   @param y        Y position
    *
    *   @return Width of string (for placement of next char)
    */
   int  drawUnicodeString(const unsigned *uniCode, unsigned length, unsigned x, unsigned y);
   /**
    * Draw line
    *
    * @param x0       X-coordinate of start
    * @param y0       Y-coordinate of start
    * @param x1       X-coordinate of end
    * @param y1       Y-coordinate of end
    */
   void drawLine(unsigned x0, unsigned y0, unsigned x1, unsigned y1);
   /**
    * Draw filled circle
    *
    * @param x       X-coordinate of centre
    * @param y       Y-coordinate of centre
    * @param r       Radius
    */
   void drawCircle(unsigned x, unsigned y, unsigned r);
   /**
    * Draw open circle
    *
    * @param x       X-coordinate of centre
    * @param y       Y-coordinate of centre
    * @param r       Radius
    */
   void drawFilledCircle(unsigned x, unsigned y, unsigned r);
   /**
    * Draw horizontal line
    *
    * @param x       X-coordinate of start
    * @param y       Y-coordinate of start
    * @param len     X-coordinate of endLength
    */
   void drawHorizontalLine( unsigned x, unsigned y, unsigned len);
   /**
    * Draw vertical line
    *
    * @param x       X-coordinate of start
    * @param y       Y-coordinate of start
    * @param len     X-coordinate of endLength
    */
   void drawVerticalLine( unsigned x, unsigned y, unsigned len);
   /**
    * Draw open rectangle
    *
    * @param x       X-coordinate of start
    * @param y       Y-coordinate of start
    * @param height  Height
    * @param width   Width
    */
   void drawRectangle(unsigned x, unsigned y, unsigned height, unsigned width);
   /**
    * Draw open rectangle
    *
    * @param x       X-coordinate of start
    * @param y       Y-coordinate of start
    * @param height  Height
    * @param width   Width
    */
   void drawFilledRectangle(unsigned x, unsigned y, unsigned height, unsigned width);
   /*
    *  Draw a triangle
    *
    *  @param x1  X coordinate of vertex 1
    *  @param y1  Y coordinate of vertex 1
    *  @param x2  X coordinate of vertex 2
    *  @param y2  Y coordinate of vertex 2
    *  @param x3  X coordinate of vertex 3
    *  @param y3  Y coordinate of vertex 3
    */
   void drawTriangle(unsigned x1, unsigned y1, unsigned x2, unsigned y2, unsigned x3, unsigned y3);
};

/**
 * Template class supplying drawing routines for EPaper
 *
 * @tparam s8120Cadc ADC function connected to S-8120C temperature IC
 */
template <class s8120Cadc>
class EPaper_T : public EPaper {
public:
   /**
    * Constructor - Create ePaper interface
    *
    * @param gt20l16 Character ROM interface
    * @param epd     EPD low-level interface
    */
   EPaper_T(GT20L16 *gt20l16, Epd *epd) : EPaper(gt20l16, epd) {
   }
   /**
    Read temperature from temperature sensor
    *
    * @return Temperature in Celsius
    */
   int getTemperature() {
      constexpr float ADC_SPAN       = 3.3;
      constexpr float ADC_RESOLUTION = (float)((1<<16)-1);

      s8120Cadc::setMode(Adc_Resolution::resolution_16bit_se);
      uint32_t sum = 0;
      for(int i=0; i<32; i++) {
         sum += (unsigned)s8120Cadc::readAnalogue();
      }
      sum /= 32;
      /*
       * Equation based on Table 6 (for S-8120C Series)
       * From data sheet "CMOS TEMPERATURE SENSOR IC S-8110C/8120C Series Rev.5.0_00"
       * Using +/- 30 celsius typical values as straight-line approximation.
       */
      int temperature = (215.41-125.79*(ADC_SPAN*float(sum)/ADC_RESOLUTION)) + 0.4999;
      return temperature;
   }
};

/**
 * @}
 */

} // End namespace USBDM
#endif
