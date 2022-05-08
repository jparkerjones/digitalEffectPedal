/*
 * bitcrusherEffect.c
 *
 *  Created on: Apr 17, 2022
 *      Author: tolgaust
 */


#include "applyEffects.h"
#include "bitcrusherEffect.h"

int16_t bitcrusherEffect(int bitDepth) {
	// bitDepth = the number of bits that we want for the audio sample

	int16_t temp = samples[currentInd] >> (16-bitDepth);

	int16_t sampleOut = temp << (16-bitDepth);

	return sampleOut;

}
