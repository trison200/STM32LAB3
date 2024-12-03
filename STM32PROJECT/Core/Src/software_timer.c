/*
 * software_timer.c
 *
 *  Created on: Nov 28, 2024
 *      Author: ADMIN
 */

#include "software_timer.h"

int timer_counter[4] = {0};
int timer_flag[4] = {0};

void setTimer(int duration, int timer_index){
	timer_counter[timer_index] = duration;
	timer_flag[timer_index] = 0;
}


void timerRun(int timer_index){
	if(timer_counter[timer_index] > 0){
		timer_counter[timer_index] --;
	}
	if(timer_counter[timer_index] <= 0){
		timer_flag[timer_index] = 1;
	}
}
