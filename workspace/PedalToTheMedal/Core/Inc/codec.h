/*
 * codec.h
 *
 *  Created on: Feb 22, 2022
 *      Author: Parker Jones
 *
 *      Header file for communications with the Audio Codec, SGTL5000.
 *      https://www.pjrc.com/teensy/SGTL5000.pdf
 *
 *      The codec is controlled using I2C, pins 18(SDA) and 19(SCL), on the Teensy4.0 Audio Breakout Board
 *      These are connected to pins PB10 (SCL) and PB11 (SDA) on the WeActStudio Board
 *      I2C address of the chip is 0b0n01010(R/W).  n is determined by the value of the CTRL_ADR0_CS pin, which by default is 1 on the breakout board.
 *		W = 0, R = 1
 *		Multiple reads/writes using auto-increment is supported, not currently implemented
 *
 *      I2S control
 */

#ifndef INC_CODEC_H_
#define INC_CODEC_H_

#include <stdbool.h>
#include <stdint.h>
#include "i2c.h"



/*
 *Function to perform an I2C read to the codec. Returns pointer to a byte array which holds read data.
 *ARGS:
 *regAddr - address of register to read.
 */
void codecCTRLRead(uint16_t regAddr, uint8_t* data);

/*
 * Function to perform an I2C write.  Returns NULL
 * ARGS:
 * regAddr - address of the register to write
 * data - pointer to uint8_t array of data to write.  Two bytes long.
 *
 */
void codecCTRLWrite(uint16_t regAddr, uint8_t* data);

/*
 * Function to read the device info.  returns true if device ID and revision number match the expected value
 * According to manufacturer, expected value is 0xA011
 */
bool getDeviceID();

/*
 * Function to initialize the codec device.  Register values found by using the Teensy 4.0 Audio Library as a starting point
 */
void codecInit();




#endif /* INC_CODEC_H_ */
