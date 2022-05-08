/*
 * chorusEffect.c
 *
 *  Created on: Apr 24, 2022
 *      Author: ParkerPC
 */

#include "applyEffects.h"

int16_t chorusEffect(int numVoices, float rate, uint16_t sampleDepth, float voiceGain)
{

	int16_t sampleOut;

	int32_t sum = samples[currentInd];

	//numVoices = 1;
	for(int i = 0; i < numVoices; i++)
	{
		//calculate delay for this voice
		//float adjust = ((44100.0/rate)/((float)numVoices) * i);
		uint16_t voiceDelay = sampleDepth * (0.5 *sin((chorus_t + ((44100.0/rate)/((float)numVoices) * i)) * 2 * 3.14159 * rate) + 0.5);
		sum = sum + delayEffect(voiceDelay, 0.0, voiceGain);
	}

	//overflow occurred, clip
	if(sum >= 32767)
	{
		sum = 32767;
	}
	if(sum <= -32768)
	{
		sum = -32768;
	}

	sampleOut = (int16_t)sum;



	chorus_t += (1.0/44100.0);

	if (chorus_t >= 1.0/rate) {
		chorus_t = 0.0;
	}
	return sampleOut;
}

