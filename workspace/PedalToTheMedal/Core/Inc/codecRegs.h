/*
 * codecRegs.h
 *
 * Created on: March 14, 2022
 *      Author: Parker Jones
 *
 *      Header to define all internal registers in the audio codec.
 *      https://www.pjrc.com/teensy/SGTL5000.pdf
 *
 */




//Register address definitions

#define CHIP_ID 					0x0000	//Manufacturer ID, Part ID
#define CHIP_DIG_POWER 				0x0002	//Power up modules
#define CHIP_CLK_CTRL 				0x0004	//Clock Settings
#define CHIP_I2S_CTRL 				0x0006	//I2S Settings
//no 0x0008
#define CHIP_SSS_CTRL 				0x000A	//Internal Routing
//no 0x000C
#define CHIP_ADCDAC_CTRL 			0x000E	//ADC-DAC settings
#define CHIP_DAC_VOL 				0x0010	//DAC Volume control
//no 0x0012
#define CHIP_PAD_STRENGTH 			0x0014	//I2S drive strength
//no 0x0016, 0x0018
#define CHIP_ANA_ADC_CTRL 			0x0020	//ADC Volume control
#define CHIP_ANA_HP_CTRL 			0x0022	//Headphone output control
#define CHIP_ANA_CTRL 				0x0024	//Mute and routing
#define CHIP_LINREG_CTRL 			0x0026	//
#define CHIP_REF_CTRL 				0x0028
#define CHIP_MIC_CTRL				0x002A
#define CHIP_LINE_OUT_CTRL			0x002C
#define CHIP_LINE_OUT_VOL			0x002E
#define CHIP_ANA_POWER				0x0030
#define CHIP_PLL_CTRL 				0x0032
#define CHIP_CLK_TOP_CTRL			0x0034
#define CHIP_ANA_STATUS				0x0036
#define CHIP_ANA_TEST1 				0x0038
#define CHIP_ANA_TEST2				0x003A
#define CHIP_SHORT_CTRL				0x003C
//no 0x003E

//DAP CONTROL
#define DAP_CONTROL					0x0100
#define DAP_PEQ						0x0102
#define DAP_BASS_ENHANCE			0x0104
#define DAP_BASS_ENHANCE_CTRL		0x0106
#define DAP_AUDIO_EQ				0x0108
#define	DAP_SGTL_SURROUND			0x010A
#define DAP_FILTER_COEF_ACCESS		0x010C
#define DAP_COEF_WR_B0_MSB			0x010E
#define DAP_COEF_WR_B0_LSB			0x0110
//no 0x0112, 0x0114
#define DAP_AUDIO_EQ_BASS_BAND0 	0x0116
#define DAP_AUDIO_EQ_BAND1			0x0118
#define DAP_AUDIO_EQ_BAND2			0x011A
#define DAP_AUDIO_EQ_BAND3			0x011C
#define DAP_AUDIO_EQ_TREBLE_BAND4 	0x011E
#define DAP_MAIN_CHAN 				0x0120
#define DAP_MIX_CHAN				0x0122
#define DAP_AVC_CTRL				0x0124
#define DAP_AVC_THRESHOLD 			0x0126
#define DAP_AVC_ATTACK				0x0128
#define DAP_AVC_DECAY				0x012A
#define DAP_COEF_WR_B1_MSB			0x012C
#define DAP_COEF_WR_B1_LSB			0x012E
#define DAP_COEF_WR_B2_MSB			0x0130
#define DAP_COEF_WR_B2_LSB			0x0132
#define DAP_COEF_WR_A1_MSB			0x0134
#define DAP_COEF_WR_A1_LSB			0x0136
#define DAP_COEF_WR_A2_MSB			0x0138
#define DAP_COEF_WR_A2_LSB			0x013A

