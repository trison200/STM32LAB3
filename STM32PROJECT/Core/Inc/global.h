/*
 * global.h
 *
 *  Created on: Nov 28, 2024
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "fsm_automatic.h"
#include "display.h"
#include "fsm_manual.h"

#define INIT 1
#define RED1_GREEN2 2
#define RED1_YELLOW2 3
#define GREEN1_RED2 4
#define YELLOW1_RED2 5

#define MAN_RED 20
#define MAN_GREEN 21
#define MAN_YELLOW 22
#define ERROR 23

extern int redDuration;
extern int greenDuration;
extern int yellowDuration;

extern int horizontal;
extern int vertical;

extern int mode;
extern int tempRed;
extern int tempGreen;
extern int tempYellow;

extern int status;

#endif /* INC_GLOBAL_H_ */
