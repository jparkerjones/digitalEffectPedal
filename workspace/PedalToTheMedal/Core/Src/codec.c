/*
 * codec.c
 *
 *  Created on: Feb 22, 2022
 *      Author: Parker Jones
 */
#include "codec.h"
#include "codecRegs.h"
#include "i2c.h"

//I2C address of the chip, left shifted 1 bit for RW bit
static uint8_t deviceAddr = 0b00010100;
//i2c handler for i2c port 2, pins PB10 (SCL) and PB11 (SDA).  This port is connected to the codec control i2c port.
extern I2C_HandleTypeDef hi2c2;

void codecCTRLRead(uint16_t regAddr, uint8_t* data)
{
	HAL_I2C_Mem_Read(&hi2c2, deviceAddr, regAddr, I2C_MEMADD_SIZE_16BIT, &data[0], 2, 100);
	return;

}

void codecCTRLWrite(uint16_t regAddr, uint8_t* data)
{
	HAL_I2C_Mem_Write(&hi2c2, deviceAddr, regAddr, I2C_MEMADD_SIZE_16BIT, data, 2, 100);
	return;
}

bool getDeviceID()
{
	//device ID is stored in register 0x0000.  first byte is part ID, should equal 0xA0.  second byte is revision ID, should equal 0xHH
	uint8_t devInfo[2];
	uint16_t regAddr = 0x0000;
	codecCTRLRead(regAddr, &devInfo[0]);
	if(devInfo[0] == 0xA0 && devInfo[1] == 0x11)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void codecInit()
{
	//Codec registers must be written before the device will function
	uint8_t valBuffer[2];
	uint8_t testBuffer[2];
	//Initialize internal chip power supplies
	valBuffer[0] = 0x40;
	valBuffer[1] = 0x60;
	codecCTRLWrite(CHIP_ANA_POWER, &valBuffer[0]);

	//codecCTRLRead(CHIP_ANA_POWER, &testBuffer[0]);

	//Initalize internal chip linear regulators
	valBuffer[0] = 0x00;
	valBuffer[1] = 0x6C;
	codecCTRLWrite(CHIP_LINREG_CTRL, &valBuffer[0]);

	//codecCTRLRead(CHIP_LINREG_CTRL, &testBuffer[0]);

	//Initialize Analog Reference
	valBuffer[0] = 0x01;
	valBuffer[1] = 0xF2;
	codecCTRLWrite(CHIP_REF_CTRL, &valBuffer[0]);

	//codecCTRLRead(CHIP_REF_CTRL, &testBuffer[0]);

	//Initialize LineOut
	valBuffer[0] = 0x0F;
	valBuffer[1] = 0x22;
	codecCTRLWrite(CHIP_LINE_OUT_CTRL, &valBuffer[0]);

	//codecCTRLRead(CHIP_LINE_OUT_CTRL, &testBuffer[0]);

	//Initialize Short Detection
	valBuffer[0] = 0x44;
	valBuffer[1] = 0x46;
	codecCTRLWrite(CHIP_SHORT_CTRL, &valBuffer[0]);

	//codecCTRLRead(CHIP_SHORT_CTRL, &testBuffer[0]);

	//Mute outputs and enable ZCD
	valBuffer[0] = 0x01;
	valBuffer[1] = 0x37;
	codecCTRLWrite(CHIP_ANA_CTRL, &valBuffer[0]);

	//codecCTRLRead(CHIP_ANA_CTRL, &testBuffer[0]);

	//power up peripherals
	valBuffer[0] = 0x40;
	valBuffer[1] = 0xFF;
	codecCTRLWrite(CHIP_ANA_POWER, &valBuffer[0]);

	//codecCTRLRead(CHIP_ANA_POWER, &testBuffer[0]);

	valBuffer[0] = 0x00;
	valBuffer[1] = 0x73;
	codecCTRLWrite(CHIP_DIG_POWER, &valBuffer[0]);

	//codecCTRLRead(CHIP_DIG_POWER, &testBuffer[0]);

	//startup procedure in Teensy 4.0 library has a delay here, likely to wait for power up
	HAL_Delay(400);

	//Set LineOut Volumes
	valBuffer[0] = 0x1D;
	valBuffer[1] = 0x1D;
	codecCTRLWrite(CHIP_LINE_OUT_VOL, &valBuffer[0]);

	//codecCTRLRead(CHIP_LINE_OUT_VOL, &testBuffer[0]);

	//Setup I2S clock/sampling rate
	valBuffer[0] = 0x00;
	valBuffer[1] = 0x04;
	codecCTRLWrite(CHIP_CLK_CTRL, &valBuffer[0]);

	//codecCTRLRead(CHIP_CLK_CTRL, &testBuffer[0]);

	//Setup I2S mode and parameters
	valBuffer[0] = 0x00;
	valBuffer[1] = 0x30;
	codecCTRLWrite(CHIP_I2S_CTRL, &valBuffer[0]);

	//codecCTRLRead(CHIP_I2S_CTRL, &testBuffer[0]);

	//Setup internal data routing between peripherals
	valBuffer[0] = 0x00;
	valBuffer[1] = 0x10;
	codecCTRLWrite(CHIP_SSS_CTRL, &valBuffer[0]);

	//codecCTRLRead(CHIP_SSS_CTRL, &testBuffer[0]);

	//Setup ADC/DAC
	valBuffer[0] = 0x00;
	valBuffer[1] = 0x00;
	codecCTRLWrite(CHIP_ADCDAC_CTRL, &valBuffer[0]);

	//codecCTRLRead(CHIP_ADCDAC_CTRL, &testBuffer[0]);

	//Set DAC volume to max
	valBuffer[0] = 0x3C;
	valBuffer[1] = 0x3C;
	codecCTRLWrite(CHIP_DAC_VOL, &valBuffer[0]);

	//codecCTRLRead(CHIP_DAC_VOL, &testBuffer[0]);

	//Turn headphone out volume off
	valBuffer[0] = 0x7F;
	valBuffer[1] = 0x7F;
	codecCTRLWrite(CHIP_ANA_HP_CTRL, &valBuffer[0]);

	//codecCTRLRead(CHIP_ANA_HP_CTRL, &testBuffer[0]);

	//Unmute devices for normal operation
	valBuffer[0] = 0x00;
	valBuffer[1] = 0x36;
	codecCTRLWrite(CHIP_ANA_CTRL, &valBuffer[0]);

	//codecCTRLRead(CHIP_ANA_CTRL, &testBuffer[0]);

	return;






}
