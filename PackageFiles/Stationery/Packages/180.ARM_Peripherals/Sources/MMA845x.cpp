/**
 * @file MMA845x.cpp
 *
 *  Created on: 22/11/2013
 *      Author: podonoghue
 */
#include "MMA845x.h"
#include "delay.h"

// Accelerometer registers
enum {
   STATUS,
   F_STATUS = STATUS,
   OUT_X_MSB,
   OUT_X_LSB,
   OUT_Y_MSB,
   OUT_Y_LSB,
   OUT_Z_MSB,
   OUT_Z_LSB,
   Reservedx07,
   Reservedx08,
   F_SETUP,
   TRIG_CFG,
   SYSMOD,
   INT_SOURCE,
   WHO_AM_I,
   XYZ_DATA_CFG,
   HP_FILTER_CUTOFF,
   PL_STATUS,
   PL_CFG,
   PL_COUNT,
   PL_BF_ZCOMP,
   P_L_THS_REG,
   FF_MT_CFG,
   FF_MT_SRC,
   FF_MT_THS,
   FF_MT_COUNT,
   reservedx19,
   reservedx1A,
   reservedx1B,
   reservedx1C,
   TRANSIENT_CFG,
   TRANSIENT_SCR,
   TRANSIENT_THS,
   TRANSIENT_COUNT,
   PULSE_CFG,
   PULSE_SRC,
   PULSE_THSX,
   PULSE_THSY,
   PULSE_THSZ,
   PULSE_TMLT,
   PULSE_LTCY,
   PULSE_WIND,
   ASLP_COUNT,
   CTRL_REG1,
   CTRL_REG2,
   CTRL_REG3,
   CTRL_REG4,
   CTRL_REG5,
   OFF_X,
   OFF_Y,
   OFF_Z,
};

/*
 * Constructor
 *
 * @param i2c  - The I2C interface to use
 * @param mode - Mode of operation (gain and filtering)
 */
MMA845x::MMA845x(USBDM::I2C *i2c, AccelerometerMode mode) : i2c(i2c) {
   if (readReg(WHO_AM_I) != WHO_AM_I_VALUE) {
      failedInit = true;
      return;
   }
   reset();
   setAccelerometerMode(mode);
   failedInit = false;
}

/**
 * Read Accelerometer register
 *
 * @param regNum  - Register number
 */
uint8_t MMA845x::readReg(uint8_t regNum) {
   uint8_t command[1];
   i2c->txRx(DEVICE_ADDRESS, &regNum, 1, command, sizeof(command));
   return command[0];
}

/**
 * Write Accelerometer register
 *
 * @param regNum  - Register number
 * @param value   - Value to write
 */
void MMA845x::writeReg(uint8_t regNum, uint8_t value) {
   uint8_t command[] = {regNum, value};

   i2c->transmit(DEVICE_ADDRESS, command, sizeof(command));
}

/**
 * Reset Accelerometer
 */
void MMA845x::reset(void) {

   writeReg(CTRL_REG2, MMA845x_CTRL_REG2_RST_MASK);

   // Device is not accessible after RESET
   // Wait 1 ms
   waitUS(1000);
}

/**
 * Put accelerometer into Standby mode
 */
void MMA845x::standby() {

   writeReg(CTRL_REG1, readReg(CTRL_REG1)&~MMA845x_CTRL_REG1_ACTIVE_MASK);
}

/**
 * Put accelerometer into Active mode
 */
void MMA845x::active() {

   writeReg(CTRL_REG1, readReg(CTRL_REG1)|MMA845x_CTRL_REG1_ACTIVE_MASK);
}

/**
 * Obtains measurements from the accelerometer
 *
 * @param status  - Indicates status of x, y & z measurements
 * @param x       - X axis value
 * @param y       - Y axis value
 * @param z       - Z axis value
 */
void MMA845x::readAccelerometerXYZ(int *status, int16_t *x, int16_t *y, int16_t *z) {
   uint8_t dataXYZ[7] = {STATUS};

   // Receive 7 registers (status, X-high, X-low, Y-high, Y-low, Z-high & Z-low)
   i2c->txRx(DEVICE_ADDRESS, dataXYZ, 1, sizeof(dataXYZ));

   // Unpack data and return
   *status = dataXYZ[0];
   *x = ((int16_t)((dataXYZ[1]<<8)+dataXYZ[2]))>>2;
   *y = ((int16_t)((dataXYZ[3]<<8)+dataXYZ[4]))>>2;
   *z = ((int16_t)((dataXYZ[5]<<8)+dataXYZ[6]))>>2;
}

/**
 * Set accelerometer mode (gain and filtering)
 *
 * @param mode - one of ACCEL_2Gmode etc.
 */
void MMA845x::setAccelerometerMode(AccelerometerMode mode) {
   writeReg(CTRL_REG1, 0x00);

   writeReg(XYZ_DATA_CFG, MMA845x_XYZ_DATA_CFG_FS(mode));

   writeReg(CTRL_REG1,
         MMA845x_CTRL_REG1_ASLP_RATE(0) | /* 50 Hz auto-sleep rate */
         MMA845x_CTRL_REG1_DR(2) |        /* 200 Hz update rate    */
         MMA845x_CTRL_REG1_ACTIVE_MASK);  /* Active     */
}

/*!
 * Read ID from accelerometer
 *
 * @return ID value as 8-bit number (0x1A for MMA8451Q)
 */
uint32_t MMA845x::readID(void) {
   uint8_t values[] = {WHO_AM_I};
   i2c->txRx(DEVICE_ADDRESS, values, 1, sizeof(values));
   return values[0];
}

/**
 * Calibrate accelerometer
 * (2g mode)
 */
void MMA845x::calibrateAccelerometer() {

   uint8_t originalControlReg1Value = readReg(CTRL_REG1);
   uint8_t originalXYXDataConfigValue = readReg(XYZ_DATA_CFG);

   // Make inactive so setting can be modified
   writeReg(CTRL_REG1, 0x00);

   // Clear existing offsets
   writeReg(OFF_X, 0);
   writeReg(OFF_Y, 0);
   writeReg(OFF_Z, 0);

   int mode = (originalXYXDataConfigValue&MMA845x_XYZ_DATA_CFG_FS_MASK)>>MMA845x_XYZ_DATA_CFG_FS_OFF;

   static const int calibration2Gs[]     = {4096*8, 2048*8, 1024*8};
   static const int calibrationFactors[] = {8*8, 4*8, 2*8};

   int calibration2G     = calibration2Gs[mode];
   int calibrationFactor = calibrationFactors[mode];

   writeReg(CTRL_REG1,
         MMA845x_CTRL_REG1_ASLP_RATE(0) | /* 50 Hz auto-sleep rate */
         MMA845x_CTRL_REG1_DR(2) |        /* 200 Hz update rate    */
         MMA845x_CTRL_REG1_ACTIVE_MASK);  /* Active     */

   int16_t Xout_Accel_14_bit, Yout_Accel_14_bit, Zout_Accel_14_bit;
   int     Xout_Accel=0, Yout_Accel=0, Zout_Accel=0;

   // Average 8 samples to reduce noise
   for (int i=0; i<8; i++) {
      int status;
      do {
         readAccelerometerXYZ(&status, &Xout_Accel_14_bit, &Yout_Accel_14_bit, &Zout_Accel_14_bit);
      } while ((status & MMA845x_STATUS_ZYXDR_MASK) == 0);
      Xout_Accel += Xout_Accel_14_bit;
      Yout_Accel += Yout_Accel_14_bit;
      Zout_Accel += Zout_Accel_14_bit;
   }

   // Make inactive so setting can be modified
   writeReg(CTRL_REG1, 0x00);

   char X_Accel_offset = -(Xout_Accel / calibrationFactor);                    // Compute X-axis offset correction value
   char Y_Accel_offset = -(Yout_Accel / calibrationFactor);                    // Compute Y-axis offset correction value
   char Z_Accel_offset = -((Zout_Accel - calibration2G) / calibrationFactor);  // Compute Z-axis offset correction value

   writeReg(OFF_X, X_Accel_offset);
   writeReg(OFF_Y, Y_Accel_offset);
   writeReg(OFF_Z, Z_Accel_offset);

   // Restore original settings
   writeReg(CTRL_REG1, originalControlReg1Value);
}
