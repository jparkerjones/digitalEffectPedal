/*
 * undersamplingEffect.c
 *
 *  Created on: Apr 11, 2022
 *      Author: ParkerPC
 */
#include "applyEffects.h"
#include "undersamplingEffect.h"


int16_t undersamplingEffect(float factor)
{
	usSum = usSum + 1.0/factor;
	//if the usSum is >= 1, update current sample and reset usSum
	if(usSum >= 1.0)
	{
		usSum = usSum - 1;
		currentSample = samples[currentInd];
	}
	return currentSample;
}

