/*

  \brief ePaper interface library

  \verbatim

  EPaper.cpp
  2013 Copyright (c) Seeed Technology Inc.  All right reserved.

  Modified by Loovee
  www.seeedstudio.com
  2013-7-2

  Modified by pgo
  http://usbdm.sourceforge.net
  2014-8-6

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  \endverbatim

 */

#include <stdio.h>
#include <stdlib.h>
#include "spi.h"
#include "epaper.h"

using namespace USBDM;

/*!
 * Constructor - Create ePaper interface
 *
 * @param gt20l16 Character generator
 * @param spi     SPI interface to use
 * @param sz      Display size selector
 * @param cs_n    CS for SPI interface
 */
EPaper::EPaper(GT20L16 *gt20l16, SPI *spi, EPD_size sz, const DigitalIO *cs_n) :
      gt20l16(gt20l16),
      size(sz),
      orientation(LANDSCAPE),
      epd(new EPD(spi, size)),
      width(epd->getWidth()),
      height(epd->getHeight()),
      invertX(false),
      invertY(false),
      writeMode(ORMODE),
      cs_n(cs_n) {
   cs_n->setDigitalOutput();
   cs_n->set();
}

/*!
 * Get temperature from temperature sensor
 *
 * @return Temperature in Celsius
 */
int EPaper::getTemperature() {
   const float ADC_SPAN       = 3.3;
   const float ADC_RESOLUTION = (float)((1<<16)-1);

   S8120CN_Pin_TEMP.setAnalogueInput(AnalogueIO::resolution_16bit_se);
   uint32_t sum = 0;
   for(int i=0; i<32; i++) {
      sum += (unsigned)S8120CN_Pin_TEMP.readAnalogue();
   }
   sum /= 32;
   /*
    * Equation based on Table 6 (for S-8120C Series)
    * From data sheet "CMOS TEMPERATURE SENSOR IC S-8110C/8120C Series Rev.5.0_00"
    */
   float temperature = (215.41-125.79*(ADC_SPAN*float(sum)/ADC_RESOLUTION))+0.5;
   return (int)(temperature+0.4999);
}

/*!
 *   Draw a unicode character using generator map
 *
 *   @param matrix  The character generator matrix to draw
 *   @param dataLen Size of matrix
 *   @param x       X position
 *   @param y       Y position
 *
 *   @return Width of character (for placement of next char)
 */
int EPaper::drawUnicode(const uint8_t *matrix, unsigned dataLen, unsigned x, unsigned y) {
   int rowOffset = 0;
   if (invertY) {
      // Adjust origin to bottom of text
      y += 16;
   }
   for (unsigned k = 0; k<dataLen; k+=dataLen/2) {
      // Each of 2 rows of ROM data (8-pixels high)
      for (unsigned j=0; j<(dataLen/2); j++) {
         // Each byte of data (a column of 8-pixels)
         for (unsigned i=0; i<8; i++) {
            // Each pixel in byte
            int color = (matrix[k+j] & (0x1<<i)) ? 1 : 0;
            int pX,pY;
            if (invertX) {
               pX = x - j;
            }
            else {
               pX = x + j;
            }
            if (invertY) {
               pY = y - (rowOffset+i);
            } else {
               pY = y + rowOffset+i;
            }
            drawPixel(pX, pY, color);
         }
      }
      rowOffset +=8;
   }
   if (invertX) {
      return -dataLen/2; // x +
   }
   else {
      return dataLen/2; // x -
   }
}

/*!
 *   Draw a unicode character
 *
 *   @param uniCode The UNICODE to draw
 *   @param x       X position
 *   @param y       Y position
 *
 *   @return With of character (for placement of next char)
 */
int EPaper::drawUnicode(unsigned uniCode, unsigned x, unsigned y) {
   uint8_t tMatrix[32];  //!< Buffer for character data

   // Get character font data
   int dataLen = gt20l16->getMatrixUnicode(uniCode, tMatrix);
   // Draw it
   return drawUnicode(tMatrix, dataLen, x, y);
}

/*!
 *   Draw a unicode character string
 *
 *   @param uniCode  The character generator matrix to draw
 *   @param length   Number of characters
 *   @param x        X position
 *   @param y        Y position
 *
 *   @return Width of string (for placement of next char)
 */
int EPaper::drawUnicodeString(const unsigned *uniCode, unsigned length, unsigned x, unsigned y) {
   int xSum  = 0;
   for(unsigned i=0; i<length; i++) {
      int xPlus = drawUnicode(uniCode[i], x, y);
      x    += xPlus;
      xSum += xPlus;
   }
   return xSum;
}

/*!
 *   Draw a unicode character
 *
 *   @param c      The UNICODE to draw
 *   @param x       X position
 *   @param y       Y position
 *
 *   @return Width of character (for placement of next char)
 */
int EPaper::drawChar(char c, unsigned x, unsigned y) {
   return drawUnicode(c, x, y);
}

/*!
 *   Draw a string
 *
 *   @param string   The character generator matrix to draw
 *   @param x        X position
 *   @param y        Y position
 *
 *   @return Width of char (for placement of next char)
 */
int EPaper::drawString(const char *string, unsigned x, unsigned y) {
   int sumX = 0;

   while(*string) {
      int xPlus = drawChar(*string++, x, y);
      sumX += xPlus;
      x    += xPlus;   /* Move 1 char over */
   }
   return sumX;
}

/*!
 *   Draw a number
 *
 *   @param num      The number to draw
 *   @param x        X position
 *   @param y        Y position
 *
 *   @return Width of number (for placement of next char)
 */
int EPaper::drawNumber(long num, unsigned x, unsigned y) {
   char tmp[10];
   sprintf(tmp, "%ld", num);
   return drawString(tmp, x, y);
}

/*!
 *   Draw a float number
 *
 *   @param num      The number to draw
 *   @param decimal  The number of decimal places
 *   @param x        X position
 *   @param y        Y position
 *
 *   @return Width of number (for placement of next char)
 */
int EPaper::drawFloat(float num, unsigned decimal, unsigned x, unsigned y) {
   unsigned long temp=0;
   float decy=0.0;
   float rounding = 0.5;

   float eep = 0.000001;

   int sumX    = 0;
   int xPlus   = 0;

   if(num-0.0 < eep) {
      // floatNumber < 0
      xPlus = drawChar('-',x, y);
      num = -num;

      x  += xPlus;
      sumX += xPlus;
   }
   for (unsigned char i=0; i<decimal; ++i) {
      rounding /= 10.0;
   }
   num += rounding;
   temp = (long)num;
   xPlus = drawNumber(temp,x, y);
   x  += xPlus;
   sumX += xPlus;

   if(decimal>0) {
      xPlus = drawChar('.',x, y);
      x    += xPlus;               /* Move cursor right            */
      sumX += xPlus;
   }
   else {
      return sumX;
   }
   decy = num - temp;
   for(unsigned char i=0; i<decimal; i++) {
      decy *= 10;                        /* for the next decimal         */
      temp = decy;                       /* get the decimal              */
      xPlus = drawNumber(temp,x, y);

      x += xPlus;                        /* Move cursor right            */
      sumX += xPlus;
      decy -= temp;
   }
   return sumX;
}

/*
 *  Draw a line
 *
 *  @param x0  X coordinate of start
 *  @param y0  Y coordinate of start
 *  @param x1  X coordinate of end
 *  @param y1  Y coordinate of end
 */
void EPaper::drawLine(unsigned x0, unsigned y0, unsigned x1, unsigned y1) {

   int x = x1-x0;
   int y = y1-y0;
   int dx = abs(x), sx = x0<x1 ? 1 : -1;
   int dy = -abs(y), sy = y0<y1 ? 1 : -1;
   int err = dx+dy, e2;
   for (;;) {
      drawPixel(x0,y0,1);
      e2 = 2*err;
      if (e2 >= dy) {
         if (x0 == x1) break;
         err += dy; x0 += sx;
      }
      if (e2 <= dx) {
         if (y0 == y1) break;
         err += dx; y0 += sy;
      }
   }
}

/*
 *  Draw a circle
 *
 *  @param poX  X coordinate of centre
 *  @param poY  Y coordinate of centre
 *  @param r    Radius
 */
void EPaper::drawCircle(unsigned poX, unsigned poY, unsigned r) {

   int x = -r, y = 0, err = 2-2*r, e2;
   do {
      drawPixel(poX-x, poY+y, 1);
      drawPixel(poX+x, poY+y, 1);
      drawPixel(poX+x, poY-y, 1);
      drawPixel(poX-x, poY-y, 1);
      e2 = err;
      if (e2 <= y) {
         err += ++y*2+1;
         if (-x == y && e2 <= x) e2 = 0;
      }
      if (e2 > x) err += ++x*2+1;
   } while (x <= 0);
}

/*
 *  Draw a horizontal line
 *
 *  @param poX  X coordinate of start
 *  @param poY  Y coordinate of start
 *  @param len  Length
 */
void EPaper::drawHorizontalLine(unsigned poX, unsigned poY, unsigned len) {
   drawLine(poX, poY, poX+len, poY);
}

/*
 *  Draw a vertical line
 *
 *  @param poX  X coordinate of start
 *  @param poY  Y coordinate of start
 *  @param len  Length
 */
void EPaper::drawVerticalLine(unsigned poX, unsigned poY, unsigned len) {
   drawLine(poX, poY, poX, poY+len);
}

/*
 *  Draw a rectangle
 *
 *  @param poX     X coordinate of left
 *  @param poY     Y coordinate of top
 *  @param width   Width
 *  @param height  Height
 */
void EPaper::drawRectangle(unsigned poX, unsigned poY, unsigned width, unsigned height) {
   drawHorizontalLine(poX, poY, width);
   drawHorizontalLine(poX, poY+height, width);
   drawVerticalLine(poX, poY, height);
   drawVerticalLine(poX + width, poY, height);
}

#if 0
/*
 *  Draw a filled circle
 *
 *  @param poX  X coordinate of centre
 *  @param poY  Y coordinate of centre
 *  @param r    Radius
 */
void EPaper::drawFilledCircle(unsigned poX, unsigned poY, unsigned r) {
   int x = -r, y = 0, err = 2-2*r, e2;
   do {
      drawVerticalLine(poX-x, poY-y, 2*y);
      drawVerticalLine(poX+x, poY-y, 2*y);

      e2 = err;
      if (e2 <= y) {
         err += ++y*2+1;
         if (-x == y && e2 <= x) e2 = 0;
      }
      if (e2 > x) err += ++x*2+1;
   } while (x <= 0);
}
#else
/*
 *  Draw a filled circle
 *
 *  @param poX  X coordinate of centre
 *  @param poY  Y coordinate of centre
 *  @param r    Radius
 *
 *  Note: probably slower than above algorithm but is works in XOR mode.
 */

void EPaper::drawFilledCircle(unsigned centre_x, unsigned centre_y, unsigned radius) {

   int radius_squared = radius*radius;
   int x, y;
   for (x = 0; x <= (signed)radius; x++) {
      for (y = 0; y <= (signed)radius; y++) {
         if ((x*x+y*y) <= radius_squared) {
            drawPixel(centre_x+x,centre_y+y, 1);
            if (x!=0) {
               drawPixel(centre_x-x,centre_y+y, 1);
            }
            if (y!=0) {
               drawPixel(centre_x+x,centre_y-y, 1);
            }
            if ((x!=0) && (y!=0)) {
               drawPixel(centre_x-x,centre_y-y, 1);
            }
         }
      }
   }
}
#endif

/*
 *  Draw a triangle
 *
 *  @param poX1  X coordinate of vertex 1
 *  @param poY1  Y coordinate of vertex 1
 *  @param poX2  X coordinate of vertex 2
 *  @param poY2  Y coordinate of vertex 2
 *  @param poX3  X coordinate of vertex 3
 *  @param poY4  Y coordinate of vertex 3
 */
void EPaper::drawTriangle(unsigned poX1, unsigned poY1, unsigned poX2, unsigned poY2, unsigned poX3, unsigned poY3) {
   drawLine(poX1, poY1, poX2, poY2);
   drawLine(poX1, poY1, poX3, poY3);
   drawLine(poX2, poY2, poX3, poY3);
}

/*
 *  Draw a filled rectangle
 *
 *  @param poX     X coordinate of left
 *  @param poY     Y coordinate of top
 *  @param width   Width
 *  @param height  Height
 */
void EPaper::drawFilledRectangle(unsigned poX, unsigned poY, unsigned width, unsigned height) {
   if (height>this->height) {
      height=this->height;
   }
   if (width>this->width) {
      width=this->width;
   }
   for(unsigned i=0; i<height; i++) {
      drawHorizontalLine(poX, poY+i, width);
   }
}

/*!
 * Draw pixel to frame buffer
 *
 *  @param x      X coordinate of left
 *  @param y      Y coordinate of top
 *  @param colour Colour of pixel to draw
 */
inline void EPaper::drawPixel(unsigned x, unsigned y, unsigned char colour) {
   unsigned x1 = x;
   unsigned y1 = y;

   if (invertX) {
      // Flip horizontal
      x = width-1-x;
   }
   if (invertY) {
      // Flip vertical
      y = height-1-y;
   }
   switch(orientation) {
      case PORTRAIT:
         // Rotate display
         x = y1;
         y = getWidth()-x1-1;
         break;

      default:
      case LANDSCAPE:
         break;
   }
   if ((x>=epd->getWidth()) || (y>=epd->getHeight())) {
      return;
   }
   int bit = x & 0x07;
   int byte = (x>>3) + y * (epd->getWidth()/8);
   int mask = 1 << bit;

   switch(writeMode) {
      case XORMODE:
         if (colour) {
            frameBuffer[byte] ^= mask;
         }
         break;
      case ORMODE:
         if (colour) {
            frameBuffer[byte] |= mask;
         }
         break;
      case ANDINVERT:
         if (colour) {
            frameBuffer[byte] &= ~mask;
         }
         break;
      default:
      case PAINTMODE:
         if (colour) {
            frameBuffer[byte] |= mask;
         } else {
            frameBuffer[byte] &= ~mask;
         }
         break;
   }
}
