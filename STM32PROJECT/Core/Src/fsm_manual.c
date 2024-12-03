/*
 * fsm_manual.c
 *
 *  Created on: Nov 28, 2024
 *      Author: ADMIN
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
	case MAN_RED:
	{
		horizontal = redDuration;
		vertical = mode;
		if(timer_flag[3] == 1)
		{
		blinking(RED1);
		setTimer(100,3);
		}
		if(isButtonPressed(0) == 1){
			if(isButtonPressed(2) == 0){
						redDuration = tempRed;
					}
			status = MAN_YELLOW;
			mode = 3;
			setTimer(100,3);
		}
		if(isButtonPressed(1) == 1 && mode == 2){
			redDuration += 1;
			if(redDuration > 99){
				redDuration = 1;
			}
		}
		break;
	}
	case MAN_YELLOW:
		{
			horizontal = yellowDuration;
			vertical = mode;
			if(timer_flag[3] == 1)
			{
			blinking(YELLOW1);
			setTimer(100 , 3);
			}
			if(isButtonPressed(0) == 1){
				if(isButtonPressed(2) == 0){
						yellowDuration = tempYellow;
					}
				status = MAN_GREEN;
				mode = 4;
				setTimer(100 , 3);
			}
			if(isButtonPressed(1) == 1 && mode == 3){
				yellowDuration += 1;
				if(yellowDuration > 99){
					yellowDuration = 1;
				}
			}
			break;
		}
	case MAN_GREEN:
		{
			horizontal = greenDuration;
			vertical = mode;
			if(timer_flag[3] == 1)
			{
			blinking(GREEN1);
			setTimer(100 , 3);
			}
			if(isButtonPressed(0) == 1){
				if(isButtonPressed(2) == 0){
								redDuration = tempRed;
							}
				if (redDuration == (greenDuration + yellowDuration)){
				status = RED1_GREEN2;
				mode = 1;
				setTimer(greenDuration*100 , 0);
				horizontal = redDuration;
				vertical = greenDuration;
				setTimer(100, 1);
				setTimer(25, 2);
				}
				else
				{
					status = ERROR;
				}
			}
			if(isButtonPressed(1) == 1 && mode == 4){
				greenDuration += 1;
				if(greenDuration > 99){
					greenDuration = 1;
				}
			}
			break;
		}
	case ERROR:
		status = RED1_GREEN2;
		redDuration = tempRed;
		yellowDuration = tempYellow;
		greenDuration = tempGreen;
		mode = 1;
		horizontal = redDuration;
		vertical = greenDuration;
		setTimer(greenDuration*100, 0);
		setTimer(100, 1);
		setTimer(25, 2);
	default:
		break;
	}
}


