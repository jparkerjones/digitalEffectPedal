/*
 * delayEffect.c
 *
 *  Created on: Apr 7, 2022
 *      Author: Parker Jones
 *
 */
#include "applyEffects.h"

int16_t delayEffect(uint32_t delay_samples, float gain_clean, float gain_delay)
{
	//calculate new output sample
	int delay_index = (currentInd - delay_samples);
	//if index is negative, need to wrap around buffer.  In C % is REMAINDER, not modulo, will not resolve negative case
	if(delay_index < 0)
	{
		delay_index = SIZE_OF_BUFFER + delay_index;
	}

	int16_t sampleOut = (int16_t)(gain_clean * samples[currentInd]) + (int16_t)(gain_delay * samples[delay_index]);

	return sampleOut;
}

