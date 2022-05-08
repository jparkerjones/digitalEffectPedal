/*
 * applyEffects.h
 *
 *  Created on: Apr 7, 2022
 *      Author: ParkerPC
 */

#ifndef INC_APPLYEFFECTS_H_
#define INC_APPLYEFFECTS_H_

#include <stdint.h>
#include "delayEffect.h"
#include "undersamplingEffect.h"
#include "bitcrusherEffect.h"
#include "tremoloEffect.h"
#include "chorusEffect.h"

//Set a 3 second long buffer
#define SIZE_OF_BUFFER 132350

int16_t samples[SIZE_OF_BUFFER];
//this is the index currently being written to.
int currentInd;

typedef enum {

	UNDERSAMPLING = 0,
	DELAY,
	BITCRUSHER,
	TREMOLO,
	CHORUS,
	PASSTHROUGH,

} effects_t;


int16_t applyEffect(effects_t effect);


#endif /* INC_APPLYEFFECTS_H_ */
