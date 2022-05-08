/*
 * tremoloEffect.h
 *
 *  Created on: Apr 17, 2022
 *      Author: tolgaust
 */

#ifndef INC_TREMOLOEFFECT_H_
#define INC_TREMOLOEFFECT_H_


//For the Tremolo Effect, the depth of the AM for the effect
float tremoloDepth;
//For the Tremolo Effect, the rate of the sinusoid in the effect
float tremoloRate;

float t;

//For the sinusoid time, as the input for the AM

#include <stdint.h>

int16_t tremoloEffect(float tremolo_rate, float tremolo_depth);

#endif /* INC_TREMOLOEFFECT_H_ */
