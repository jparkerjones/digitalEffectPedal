/*
 * rotaryScale.c
 *
 *  Created on: Apr 24, 2022
 *      Author: rishabtandon
 */

#include "lcd.h"
#include "gpio.h"
#include "st7735.h"
#include "rotaryScale.h"
#include "applyEffects.h"

extern position1;

float rotaryScale(effects_t effect_selection, int param_select){

	//int x = effect_selection % 4;
	float output;
	switch(effect_selection){

		case 0: //undersampling
			if (position1 <= 0){
				output = 0.0;
				position1 = 0;
			}
			else if (position1 >= 100){
				output = 10.0;
				position1 = 100;
			}
			else {
				output = (float)(position1) * 0.1; //increment by 0.1
			}
		break;

		case 1:	//delay
			if (param_select == 0){ //delay time (0-3s)
				if (position1 <= 0){
					output = 0.0;
					position1 = 0;
				}
				else if (position1 >= 30){
					output = 3.0;
					position1 = 30;
				}
				else {
					output = (float)(position1) * 0.1;
				}
			}
			else if (param_select == 1){	//clean gain
				if (position1 <= 0){
					output = 0.0;
					position1 = 0;
				}
				else if (position1 >= 10){
					output = 1.0;
					position1 = 10;
				}
				else {
					output = (float)(position1) * 0.1;
				}
			}
			else if (param_select == 2){	//depth gain
				if (position1 <= 0){
					output = 0.0;
					position1 = 0;
				}
				else if (position1 >= 10){
					output = 1.0;
					position1 = 10;
				}
				else {
					output = (float)(position1) * 0.1;
				}
			}
		break;

		case 2: //bitcrusher
			if (position1 <= 0){
				output = 0.0;
				position1 = 0;
			}
			else if (position1 >= 15){
				output = 15.0;
				position1 = 15;
			}
			else{
				output = (float)(position1);
			}
		break;

		case 3: //tremolo
			if (param_select == 0){ //tremolo rate
				if (position1 <= 0){
					output = 0.0;
					position1 = 0;
				}
				else if (position1 >= 300){
					output = 30.0;
					position1 = 300;
				}
				else {
					output = (float)(position1) * 0.1;
				}
			}
			else if (param_select == 1){	//tremolo depth
				if (position1 <= 0){
					output = 0.0;
					position1 = 0;
				}
				else if(position1 >= 10){
					output = 1.0;
					position1 = 10;
				}
				else {
					output = (float)(position1) * 0.1;
				}
			}
		break;

		case 4: // chorus
			if (param_select == 0){ //number of voices
				if (position1 <= 0){
					output = 0.0;
					position1 = 0;
				}
				else if (position1 >= 8){
					output = 8.0;
					position1 = 8;
				}
				else {
					output = (float)(position1);
				}
			}
			else if (param_select == 1){	//chorus rate
				if (position1 <= 0){
					output = 0.0;
					position1 = 0;
				}
				else if (position1 >= 300){
					output = 30.0;
					position1 = 300;
				}
				else {
					output = (float)(position1) * 0.1;
				}
			}
			else if (param_select == 2){	//chorus depth
				if (position1 <= 0){
					output = 0.0;
					position1 = 0;
				}
				else if (position1 >= 10){
					output = 1.0;
					position1 = 10;
				}
				else {
					output = (float)(position1) * 0.1;
				}
			}
			else if (param_select == 3){	//chorus voice amplitude
				if (position1 <= 0){
					output = 0.0;
					position1 = 0;
				}
				else if (position1 >= 10){
					output = 1.0;
					position1 = 10;
				}
				else {
					output = (float)(position1) * 0.1;
				}
			}
		break;

//		case 5:
//
//		break;
	}
	if (output < 0.01)
	{
		output = 0;
	}
	return output;
}
