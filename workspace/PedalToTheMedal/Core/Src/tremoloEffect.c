/*
 * tremoloEffect.c
 *
 *  Created on: Apr 17, 2022
 *      Author: tolgaust
 */


#include "applyEffects.h"
#include "tremoloEffect.h"


int16_t tremoloEffect(float tremolo_rate, float tremolo_depth) {
	// tremolo_rate = the rate of the sin wave for the AM for the modified signal
	// tremolo_depth = the depth (amplitude) of the AM for the modified signal

	// variable t for the sinusoid is set statically at the beginning to be the tremolo rate defined by the user
	// it will be updated every time the effect is called


	// the tremolo factor to be applied to the sample at currentInd
	float abc = sin(t * 2 * 3.14159 * tremoloRate);
	float a1 = ( 0.5 * abc + 0.5);
	float a2 = (tremolo_depth * a1);
	float tremolo_factor = 1.0 - a2;


	// increment by this every time it is called
	// tremolo rate for the sinusoid is set by the user
	t += (1.0/44100.0);

	if (t >= 1/tremoloRate) {
		t = 0;
	}


	int16_t sampleOut = samples[currentInd] * tremolo_factor;

	return sampleOut;

}
