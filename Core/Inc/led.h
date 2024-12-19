/*
 * led.h
 *
 *  Created on: Dec 10, 2024
 *      Author: PC
 */

#ifndef INC_LED_H_
#define INC_LED_H_
#include "main.h"
#include "software_timer.h"
#include "traffic_light.h"
void display7SEG(int num);
void update7SEG(int index);
void scanLedBuffer();
void clearLed();
void updateLedBufferVal(int val0, int val1, int val2, int val3);
void displayLed(int led_index);
extern int counter1;
extern int counter2;
#endif /* INC_LED_H_ */
