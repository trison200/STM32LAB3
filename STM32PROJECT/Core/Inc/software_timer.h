/*
 * software_timer.h
 *
 *  Created on: Nov 28, 2024
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag[4];

void timerRun(int timer_index);
void setTimer(int duration, int timer_index);


#endif /* INC_SOFTWARE_TIMER_H_ */
