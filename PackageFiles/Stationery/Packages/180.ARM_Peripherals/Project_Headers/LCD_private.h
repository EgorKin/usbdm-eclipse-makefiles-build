/*
 * @file lcd_private.h
 */
#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

#ifndef LCD_SPI_PRIVATE
#error "This is a private header file - don't include"
#endif

#ifdef EPSON
//********************************************************************
//
//               EPSON Controller Definitions
//
//********************************************************************
#define DISON       0xAF
#define DISOFF      0xAE
#define DISNOR      0xA6
#define DISINV      0xA7
#define SLPIN       0x95
#define SLPOUT      0x94
#define COMSCN      0xBB
#define DISCTL      0xCA
#define PASET       0x75
#define CASET       0x15
#define DATCTL      0xBC
#define RGBSET8     0xCE
#define RAMWR       0x5C
#define RAMRD       0x5D
#define PTLIN       0xA8
#define PTLOUT      0xA9
#define RMWIN       0xE0
#define RMWOUT      0xEE
#define ASCSET      0xAA
#define SCSTART     0xAB
#define OSCON       0xD1
#define OSCOFF      0xD2
#define PWRCTR      0x20
#define VOLCTR      0x81
#define VOLUP       0xD6
#define VOLDOWN     0xD7
#define TMPGRD      0x82
#define EPCTIN      0xCD
#define EPCOUT      0xCC
#define EPMWR       0xFC
#define EPMRD       0xFD
#define EPSRRD1     0x7C
#define EPSRRD2     0x7D
#define NOP         0x25
#endif /* EPSON */

#ifdef PHILIPS
//*************************************************************************************
//   
// Philips PCF8833 (Philips data sheet Feb 14, 2003)
//
//*************************************************************************************
#define   P_NOP         0x00   // nop 
#define   P_SWRESET     0x01   // software reset 
#define   P_BSTROFF     0x02   // booster voltage OFF 
#define   P_BSTRON      0x03   // booster voltage ON 
#define   P_RDDIDIF     0x04   // read display identification 
#define   P_RDDST       0x09   // read display status 
#define   P_SLEEPIN     0x10   // sleep in 
#define   P_SLEEPOUT    0x11   // sleep out 
#define   P_PTLON       0x12   // partial display mode 
#define   P_NORON       0x13   // display normal mode 
#define   P_INVOFF      0x20   // inversion OFF 
#define   P_INVON       0x21   // inversion ON 
#define   P_DALO        0x22   // all pixel OFF 
#define   P_DAL         0x23   // all pixel ON 
#define   P_SETCON      0x25   // write contrast 
#define   P_DISPOFF     0x28   // display OFF 
#define   P_DISPON      0x29   // display ON 
#define   P_CASET       0x2A   // column address set 
#define   P_PASET       0x2B   // page address set 
#define   P_RAMWR       0x2C   // memory write 
#define   P_RGBSET      0x2D   // colour set 
#define   P_PTLAR       0x30   // partial area 
#define   P_VSCRDEF     0x33   // vertical scrolling definition 
#define   P_TEOFF       0x34   // test mode 
#define   P_TEON        0x35   // test mode 
#define   P_MADCTL      0x36   // memory access control 
#define   P_SEP         0x37   // vertical scrolling start address 
#define   P_IDMOFF      0x38   // idle mode OFF 
#define   P_IDMON       0x39   // idle mode ON 
#define   P_COLMOD      0x3A   // interface pixel format 
#define   P_SETVOP      0xB0   // set Vop
#define   P_BRS         0xB4   // bottom row swap 
#define   P_TRS         0xB6   // top row swap 
#define   P_DISCTR      0xB9   // display control 
#define   P_DOR         0xBA   // data order 
#define   P_TCDFE       0xBD   // enable/disable DF temperature compensation 
#define   P_TCVOPE      0xBF   // enable/disable Vop temp comp 
#define   P_EC          0xC0   // internal or external oscillator 
#define   P_SETMUL      0xC2   // set multiplication factor 
#define   P_TCVOPAB     0xC3   // set TCVOP slopes A and B 
#define   P_TCVOPCD     0xC4   // set TCVOP slopes c and d 
#define   P_TCDF        0xC5   // set divider frequency 
#define   P_DF8COLOR    0xC6   // set divider frequency 8-color mode 
#define   P_SETBS       0xC7   // set bias system 
#define   P_RDTEMP      0xC8   // temperature read back 
#define   P_NLI         0xC9   // n-line inversion 
#define   P_RDID1       0xDA   // read ID1 
#define   P_RDID2       0xDB   // read ID2 
#define   P_RDID3       0xDC   // read ID3 
#endif /* PHILLIPS */

#endif /* LCD_PRIVATE_H */
