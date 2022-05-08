/*
 * navswitch.h
 *
 *  Created on: Apr 14, 2022
 *      Author: ike
 */

#ifndef INC_NAVSWITCH_H_
#define INC_NAVSWITCH_H_

#include "applyEffects.h"
#include "stdio.h"

void checkGPIO(effects_t *curEffect, int input1, int input2);

void Effect(effects_t curEffect, float input);



#endif /* INC_NAVSWITCH_H_ */


