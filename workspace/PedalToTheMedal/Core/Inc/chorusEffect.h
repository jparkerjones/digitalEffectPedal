/*
 * chorusEffect.h
 *
 *  Created on: Apr 24, 2022
 *      Author: ParkerPC
 */

#ifndef INC_CHORUSEFFECT_H_
#define INC_CHORUSEFFECT_H_

#include <stdint.h>
#include <math.h>

int chorusVoices;
float chorusRate;
uint16_t chorusSampleDepth;
float chorusTime;
float voiceGain;

float chorus_t;


int16_t chorusEffect(int numVoices, float rate, uint16_t sampleDepth, float voiceGain);


#endif /* INC_CHORUSEFFECT_H_ */
