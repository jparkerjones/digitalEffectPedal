/*
 * navswitch.c
 *
 *  Created on: Apr 14, 2022
 *      Author: ike
 */

#include "navswitch.h"
#include "applyEffects.h"
#include "lcd.h"
#include "gpio.h"
#include "st7735.h"
#include "rotaryScale.h"
#include "stdio.h"
//#include "main.c"

ST7735_Object_t blue1;
ST7735_Object_t blue2;
ST7735_Object_t gblue1;
ST7735_Object_t gblue2;
ST7735_Object_t green1;
ST7735_Object_t green2;
ST7735_Object_t yellow1;
ST7735_Object_t yellow2;


uint32_t bright;
char mode[8][7] = {"mode1", "mode2", "mode3", "mode4", "mode5", "mode6", "mode7", "mode8"};
char color[8][7] = {"BLUE", "BLUE", "GBLUE", "GBLUE", "GREEN", "GREEN", "YELLOW", "YELLOW"};
int i = 0;
int check = 0;
extern effect_selection;
extern param_select;
extern position1;
extern *curEffect;

////Parameter variables
//extern usFactor;
extern secdelay;
//extern cleanGain;
//extern delayGain;
//extern bitCount;
//extern tremolo_rate;
//extern tremolo_depth;

void checkGPIO(effects_t *curEffect, int input1, int input2)
{
	int up = 0;
	int down = 0;
	int left = 0;
	int right = 0;

	uint16_t currentbright;
	uint8_t text[32];
	char buf[100];


	down = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_6);
	up = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1);
	left = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_5);
	right = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4);
	LCD_SetBrightness(400);


	if(up == 0)
		{
//		bright += 50;
//
//		if(bright > 500)
//		{
//			bright = 500;
//		}
//		LCD_SetBrightness(bright);
//		sprintf((char *)&text, "bright: %d    ", bright);
//		LCD_ShowString(4, 58, 160, 16, 16, text);
		param_select++;

		}
	else if(down == 0)
		{
//		  bright -= 50;
//
//		  if(bright < 0)
//		  {
//			  bright = 0;
//		  }
//		  LCD_SetBrightness(bright);
//
//		  sprintf((char *)&text, "bright: %d     ", bright);
//		  LCD_ShowString(4, 58, 160, 16, 16, text);
		  param_select--;
		}
	if(right == 0)
		{
//		  sprintf((char *)&text, "current: %s" , mode[i]);
//		  LCD_ShowString(4, 58, 160, 16, 16, text);
		  i++;
		  if(i > 7)
		  {
			  i = 7;
		  }
		  effect_selection++;
		  check = 1;
		}


	else if(left == 0)
		{
//		  sprintf((char *)&text, "current: %s", mode[i]);
//		  LCD_ShowString(4, 58, 160, 16, 16, text);
		  i--;
		  if(i < 0)
			{
				i = 0;
			}
		  effect_selection--;
		  check = 1;
		}

	effect_selection = effect_selection % 6;
	if (effect_selection < 0){
		effect_selection += 6;
	}


	if (check == 1)
	{
		switch (effect_selection)
			{
				case 0:
					*curEffect = UNDERSAMPLING;
					if(param_select != 0)
					{
						param_select = 0;
					}

					if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15) == 0)
					{
						usFactor += 0.1;
						if (usFactor > 10.0) usFactor = 10.0;

					}
					if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13) == 0)
					{
						usFactor -= 0.1;
						if (usFactor < 1.0) usFactor = 1.0;
					}

					//usFactor = rotaryScale((int)effect_selection, param_select);

					sprintf((char *)&text, "EFFECT: Undersampl   ");
					LCD_ShowString(4, 4, ST7735Ctx.Width, 16, 16, text);
					sprintf((char *)&text, "usFactor: %s         ", (gcvt(usFactor, 3, buf)));
					LCD_ShowString(4, 22, ST7735Ctx.Width, 16, 16, text);



					sprintf((char *)&text, "            ");
					LCD_ShowString(4, 40, ST7735Ctx.Width, 16, 16, text);
					break;
				case 1:
					*curEffect = DELAY;

					param_select = param_select % 3;
					if(param_select < 0)
					{
						param_select += 3;
					}

					switch (param_select) {
						case 0:

							if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15) == 0)
							{
								secondDelay += 0.1;
								if (secondDelay >= 3.0) secondDelay = 3.0;

							}
							if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13) == 0)
							{
								secondDelay -= 0.1;
								if (secondDelay < 0.0) secondDelay = 0.0;
							}

							sampleDelay = (uint32_t)(secondDelay*44100);
//							sampleDelay = rotaryScale((int)effect_selection, param_select);
							sprintf((char *)&text, "Delay (s): %s        ", (gcvt(secondDelay, 3, buf)));
							LCD_ShowString(4, 22, ST7735Ctx.Width, 16, 16, text);
							break;
						case 1:

							if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15) == 0)
							{
								cleanGain += 0.1;
								if (cleanGain > 1.0) cleanGain = 1.0;

							}
							if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13) == 0)
							{
								cleanGain -= 0.1;
								if (cleanGain < 0.0) cleanGain = 0.0;
							}

//							cleanGain = rotaryScale((int)effect_selection, param_select);
							sprintf((char *)&text, "Clean Gain: %s          ", (gcvt(cleanGain, 3, buf)));
							LCD_ShowString(4, 22, ST7735Ctx.Width, 16, 16, text);
							break;
						case 2:

							if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15) == 0)
							{
								delayGain += 0.1;
								if (delayGain > 1.0) delayGain = 1.0;

							}
							if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13) == 0)
							{
								delayGain -= 0.1;
								if (delayGain < 0.0) delayGain = 0.0;
							}

//							delayGain = rotaryScale((int)effect_selection, param_select);
							sprintf((char *)&text, "Delay Gain: %s           ", (gcvt(delayGain, 3, buf)));
							LCD_ShowString(4, 22, ST7735Ctx.Width, 16, 16, text);
							break;
					}


					sprintf((char *)&text, "EFFECT: Delay      ");
					LCD_ShowString(4, 4, ST7735Ctx.Width, 16, 16, text);




					sprintf((char *)&text, "            ");
					LCD_ShowString(4, 40, ST7735Ctx.Width, 16, 16, text);
					break;
				case 2:
					*curEffect = BITCRUSHER;
					if(param_select != 0)
					{
						param_select = 0;
					}

					if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15) == 0)
					{
						bitCount += 1;
						if (bitCount > 15.0) bitCount = 15.0;

					}
					if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13) == 0)
					{
						bitCount -= 1;
						if (bitCount < 0.0) bitCount = 0.0;
					}

//					bitCount = rotaryScale((int)effect_selection, param_select);


					sprintf((char *)&text, "EFFECT: Bitcrush    ");
					LCD_ShowString(4, 4, ST7735Ctx.Width, 16, 16, text);
					sprintf((char *)&text, "BitCount: %d          ", bitCount);
					LCD_ShowString(4, 22, ST7735Ctx.Width, 16, 16, text);

					sprintf((char *)&text, "            ");
					LCD_ShowString(4, 40, ST7735Ctx.Width, 16, 16, text);
					break;
				case 3:
					*curEffect = TREMOLO;
					param_select = param_select % 2;
					if(param_select < 0)
					{
						param_select += 2;
					}

					switch(param_select){
						case 0:

							if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15) == 0)
							{
								tremoloRate += 0.1;
								if (tremoloRate > 30.0) tremoloRate = 30.0;

							}
							if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13) == 0)
							{
								tremoloRate -= 0.1;
								if (tremoloRate < 0.0) tremoloRate = 0.0;
							}

//							tremoloRate = rotaryScale((int)effect_selection, param_select);
							sprintf((char *)&text, "Rate (Hz): %s             ", (gcvt(tremoloRate, 3, buf)));
							LCD_ShowString(4, 22, ST7735Ctx.Width, 16, 16, text);
							break;
						case 1:

							if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15) == 0)
							{
								tremoloDepth += 0.1;
								if (tremoloDepth > 1.0) tremoloDepth = 1.0;

							}
							if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13) == 0)
							{
								tremoloDepth -= 0.1;
								if (tremoloDepth < 0.0) tremoloDepth = 0.0;
							}

//							tremoloDepth = rotaryScale((int)effect_selection, param_select);
							sprintf((char *)&text, "Depth: %s             ", (gcvt(tremoloDepth, 3, buf)));
							LCD_ShowString(4, 22, ST7735Ctx.Width, 16, 16, text);
							break;
					}


					sprintf((char *)&text, "EFFECT: Tremolo    ");
					LCD_ShowString(4, 4, ST7735Ctx.Width, 16, 16, text);


					break;
				case 4:
					*curEffect = CHORUS;

					param_select = param_select % 4;
					if(param_select < 0)
					{
						param_select += 4;
					}

					switch(param_select){
						case 0:

							if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15) == 0)
							{
								chorusVoices += 1;
								if (chorusVoices > 2) chorusVoices = 2;

							}
							if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13) == 0)
							{
								chorusVoices -= 1;
								if (chorusVoices < 1) chorusVoices = 1;
							}

							sprintf((char *)&text, "Voices: %d            ", chorusVoices);
							LCD_ShowString(4, 22, ST7735Ctx.Width, 16, 16, text);
							break;
						case 1:

							if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15) == 0)
							{
								chorusRate += .1;
								if (chorusRate > 30.0) chorusRate = 30.0;

							}
							if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13) == 0)
							{
								chorusRate -= .1;
								if (chorusRate < 0.0) chorusRate = 0.0;
							}
//							chorusRate = rotaryScale((int)effect_selection, param_select);
							sprintf((char *)&text, "Rate (Hz): %s            ", (gcvt(chorusRate, 3, buf)));
							LCD_ShowString(4, 22, ST7735Ctx.Width, 16, 16, text);
							break;
						case 2:

							if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15) == 0)
							{
								//chorusTime += 0.1;
								chorusTime += 0.005;
								if (chorusTime >= 1.0) chorusTime = 1.0;

							}
							if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13) == 0)
							{
								//chorusTime -= 0.1;
								chorusTime -=0.005;
								if (chorusTime < 0.0) chorusTime = 0.0;
							}

							chorusSampleDepth = (uint32_t)(chorusTime*44100);

//							chorusTime = rotaryScale((int)effect_selection, param_select);
							sprintf((char *)&text, "Depth (s): %s             ", (gcvt(chorusTime, 5, buf)));
							LCD_ShowString(4, 22, ST7735Ctx.Width, 16, 16, text);
							break;
						case 3:

							if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15) == 0)
							{
								voiceGain += 0.1;
								if (voiceGain >= 1.0) voiceGain = 1.0;

							}
							if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13) == 0)
							{
								voiceGain -= 0.1;
								if (voiceGain < 0.0) voiceGain = 0.0;
							}



//							voiceGain = rotaryScale((int)effect_selection, param_select);
							sprintf((char *)&text, "Voice Gain: %s            ", (gcvt(voiceGain, 3, buf)));
							LCD_ShowString(4, 22, ST7735Ctx.Width, 16, 16, text);
							break;
					}
					sprintf((char *)&text, "EFFECT: CHORUS     ");
					LCD_ShowString(4, 4, ST7735Ctx.Width, 16, 16, text);

					break;
				case 5:
					*curEffect = PASSTHROUGH;
					sprintf((char *)&text, "EFFECT: BLANK     ");
					LCD_ShowString(4, 4, ST7735Ctx.Width, 16, 16, text);
					sprintf((char *)&text, "((Passthrough))            ");
					LCD_ShowString(4, 22, ST7735Ctx.Width, 16, 16, text);
					sprintf((char *)&text, "                 ");
					LCD_ShowString(4, 40, ST7735Ctx.Width, 16, 16, text);

					break;

			}
	}
}

void updateEffect(effects_t *curEffect, float input)
{
	uint8_t text[20];

//	switch (effect_selection % 4)
//	{
//		case 0:
//			*curEffect = UNDERSAMPLING;
//			break;
//		case 1:
//			*curEffect = DELAY;
//			sprintf((char *)&text, "EFFECT: Delay   ");
//			LCD_ShowString(4, 4, ST7735Ctx.Width, 16, 16, text);
//
//			sprintf((char *)&text, "Delay (s): 0.%d    ", ((int)10.0*input));
//			LCD_ShowString(4, 22, ST7735Ctx.Width, 16, 16, text);
//			break;
//		case 2:
//			*curEffect = BITCRUSHER;
//			break;
//		case 3:
//			*curEffect = TREMOLO;
//			break;
//	}


}
