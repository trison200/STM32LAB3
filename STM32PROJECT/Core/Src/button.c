/*
 * button.c
 *
 *  Created on: Nov 28, 2024
 *      Author: ADMIN
 */

#include "button.h"

int buttonDebounce0[NO_OF_BUTTONS];
int buttonDebounce1[NO_OF_BUTTONS];
int buttonDebounce2[NO_OF_BUTTONS];
int buttonDebounce3[NO_OF_BUTTONS];
int button_flag[NO_OF_BUTTONS];
int TimerForKeyPressed[NO_OF_BUTTONS];


void initButton()
{
	for (int i = 0; i < NO_OF_BUTTONS; i++)
	{
		buttonDebounce0[i] = NORMAL_STATE;
		buttonDebounce1[i] = NORMAL_STATE;
		buttonDebounce2[i] = NORMAL_STATE;
		buttonDebounce3[i] = NORMAL_STATE;
		button_flag[i] = 0;
		TimerForKeyPressed[i] = 200;
	}
}


int isButtonPressed(int index)
{
	if (button_flag[index] == 1)
	{
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index)
{
	button_flag[index] = 1;
}

void getKeyInput()
{
	for (int i = 0; i < NO_OF_BUTTONS; i++)
	{
		buttonDebounce0[i] = buttonDebounce1[i];
		buttonDebounce1[i] = buttonDebounce2[i];
		switch(i)
		{
			case 0:
				buttonDebounce2[i] = HAL_GPIO_ReadPin(BUTTON0_GPIO_Port, BUTTON0_Pin);
				break;
			case 1:
				buttonDebounce2[i] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
				break;
			case 2:
				buttonDebounce2[i] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
				break;
			default:
				break;
		}
		if (buttonDebounce0[i] == buttonDebounce1[i] && buttonDebounce1[i] == buttonDebounce2[i])
		{
			if (buttonDebounce3[i] != buttonDebounce2[i])
			{
				buttonDebounce3[i] = buttonDebounce2[i];
				if (buttonDebounce2[i] == PRESSED_STATE)
				{
					//TODO
					subKeyProcess(i);
					TimerForKeyPressed[i] = 200;
				}
				else
				{
					buttonDebounce3[i] = NORMAL_STATE;
				}
			}
		}

	}
}

