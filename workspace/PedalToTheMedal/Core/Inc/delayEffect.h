/*
 * delayEffect.h
 *
 *  Created on: Apr 7, 2022
 *      Author: Parker Jones
 */

#ifndef INC_DELAYEFFECT_H_
#define INC_DELAYEFFECT_H_

//For the delay effect, the number of samples to delay
float secondDelay;
uint32_t sampleDelay;
//gain for the current sample
float cleanGain;
//gain for the delayed sample
float delayGain;

#include <stdint.h>

int16_t delayEffect(uint32_t delay_samples, float gain_clean, float gain_delay);


#endif /* INC_DELAYEFFECT_H_ */
