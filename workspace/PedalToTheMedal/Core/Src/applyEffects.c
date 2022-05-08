/*
 * applyEffects.c
 *
 *  Created on: Apr 7, 2022
 *      Author: Parker Jones
 */
#include "applyEffects.h"




int16_t applyEffect(effects_t effect)
{
	//sample to output
	int16_t sampleOut;

	switch(effect)
	{
		case DELAY:
			sampleOut = delayEffect(sampleDelay, cleanGain, delayGain);
			break;
		case UNDERSAMPLING:
			sampleOut = undersamplingEffect(usFactor);
			break;
		case BITCRUSHER:
			sampleOut = bitcrusherEffect(bitCount);
			break;
		case TREMOLO:
			sampleOut = tremoloEffect(tremoloRate, tremoloDepth);
			break;
		case CHORUS:
			sampleOut = chorusEffect(chorusVoices, chorusRate, chorusSampleDepth, voiceGain);
//			sampleOut = samples[currentInd];
			break;
		case PASSTHROUGH:
			sampleOut = samples[currentInd];
			break;
	}
	return sampleOut;
}


