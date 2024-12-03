/*
 * button.h
 *
 *  Created on: Nov 28, 2024
 *      Author: ADMIN
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"

#define NO_OF_BUTTONS 3
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButtonPressed(int index);
void initButton();
void getKeyInput();

#endif /* INC_BUTTON_H_ */
