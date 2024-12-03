/*
 * fsm_automatic.c
 *
 *  Created on: Nov 28, 2024
 *      Author: ADMIN
 */
#include "fsm_automatic.h"

int index_7LED = 0;

void fsm_automatic_run(){
	switch(status){
	case INIT:
	{
		clearAll();
		mode = 1;
		initButton();
		status = RED1_GREEN2;
		horizontal = redDuration;
		vertical = greenDuration;
		setTimer(greenDuration*100, 0);
		setTimer(100, 1);
		setTimer(25, 2);
		break;
	}
	case RED1_GREEN2:
	{
		turnOn(RED1);
		turnOn(GREEN2);
		if(timer_flag[1] == 1){
		horizontal--;
		vertical--;
		setTimer(100, 1);
		}
		if(timer_flag[0] == 1){
		horizontal = yellowDuration;
		vertical = yellowDuration;
		status = RED1_YELLOW2;
		setTimer(yellowDuration*100, 0);
		}
		if (isButtonPressed(0))
			{
				clearAll();
				status = MAN_RED;
				mode = 2;
				setTimer(100 , 3);
				tempRed = redDuration;
				tempGreen = greenDuration;
				tempYellow = yellowDuration;
				isButtonPressed(1);
				isButtonPressed(2);
			}
		break;
	}
	case RED1_YELLOW2:
		{
			turnOn(RED1);
			turnOn(YELLOW2);
			if(timer_flag[1] == 1)
			{
			horizontal--;
			vertical--;
			setTimer(100, 1);
			}

			if (timer_flag[0] == 1)
			{
				horizontal = greenDuration;
				vertical = redDuration;
				status = GREEN1_RED2;
				setTimer(greenDuration*100, 0);
			}
			if (isButtonPressed(0))
				{
					clearAll();
					status = MAN_RED;
					mode = 2;
					setTimer(100 , 3);
					tempRed = redDuration;
					tempGreen = greenDuration;
					tempYellow = yellowDuration;
					isButtonPressed(1);
					isButtonPressed(2);
				}
			break;
		}
	case GREEN1_RED2:
		{
			turnOn(GREEN1);
			turnOn(RED2);
			if(timer_flag[1] == 1)
			{
			horizontal--;
			vertical--;
			setTimer(100, 1);
			}

			if (timer_flag[0] == 1)
			{
				horizontal = yellowDuration;
				vertical = yellowDuration;
				status = YELLOW1_RED2;
				setTimer(yellowDuration*100, 0);
			}
			if (isButtonPressed(0))
				{
					clearAll();
					status = MAN_RED;
					mode = 2;
					setTimer(100 , 3);
					tempRed = redDuration;
					tempGreen = greenDuration;
					tempYellow = yellowDuration;
					isButtonPressed(1);
					isButtonPressed(2);
				}
			break;
		}
	case YELLOW1_RED2:
		{
			turnOn(YELLOW1);
			turnOn(RED2);
			if(timer_flag[1] == 1)
			{
			horizontal--;
			vertical--;
			setTimer(100, 1);
			}

			if (timer_flag[0] == 1)
			{
				horizontal = redDuration;
				vertical = greenDuration;
				status = RED1_GREEN2;
				setTimer(greenDuration*100, 0);
			}
			if (isButtonPressed(0))
				{
					clearAll();
					status = MAN_RED;
					mode = 2;
					setTimer(100 , 3);
					tempRed = redDuration;
					tempGreen = greenDuration;
					tempYellow = yellowDuration;
					isButtonPressed(1);
					isButtonPressed(2);
				}
			break;
		}
	default:
		break;
	}
	if (timer_flag[2] == 1) {
		updateLedBuffer(horizontal,vertical);
		update7SEG(index_7LED++);
		if (index_7LED >= 4) index_7LED = 0;
		setTimer(25, 2);
	}
}


