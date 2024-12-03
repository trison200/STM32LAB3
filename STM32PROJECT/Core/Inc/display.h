/*
 * display.h
 *
 *  Created on: Nov 28, 2024
 *      Author: ADMIN
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "global.h"

enum LED
{
	RED1,
	RED2,
	GREEN1,
	GREEN2,
	YELLOW1,
	YELLOW2,
};

extern int led_buffer[4];

void display7SEG(int num);
void clearAll();
void en_Pin(int number);
void update7SEG(int index);
void updateLedBuffer(int num1, int num2);
void turnOn(enum LED led);
void blinking(enum LED led);

#endif /* INC_DISPLAY_H_ */
