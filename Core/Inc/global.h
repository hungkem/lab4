/*
 * global.h
 *
 *  Created on: Dec 10, 2024
 *      Author: PC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"
#include "button.h"
#include "software_timer.h"
#include "led.h"

#define INIT 					1
#define REDX_GREENY_AUTO		2
#define REDX_YELLOWY_AUTO		3
#define GREENX_REDY_AUTO 		4
#define YELLOWX_REDY_AUTO		5

#define RED_MAN					10
#define YELLOW_MAN				11
#define GREEN_MAN				12
#define RED_MAN_MODIFY			13
#define YELLOW_MAN_MODIFY		14
#define GREEN_MAN_MODIFY		15

#define REDX_GREENY				20
#define REDX_YELLOWY			21
#define GREENX_REDY				22
#define YELLOWX_REDY			23

extern int status;
extern int led_index;
extern int red_timer;
extern int yellow_timer;
extern int green_timer;
#endif /* INC_GLOBAL_H_ */
