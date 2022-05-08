/*
 * undersamplingEffect.h
 *
 *  Created on: Apr 11, 2022
 *      Author: ParkerPC
 */

#ifndef INC_UNDERSAMPLINGEFFECT_H_
#define INC_UNDERSAMPLINGEFFECT_H_

#include "stdint.h"

int16_t currentSample;

float usFactor;

float usSum;

int16_t undersamplingEffect(float factor);



#endif /* INC_UNDERSAMPLINGEFFECT_H_ */
