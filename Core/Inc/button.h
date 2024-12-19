/*
 * button.h
 *
 *  Created on: Dec 10, 2024
 *      Author: PC
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_



#endif /* INC_BUTTON_H_ */

#include "main.h"

#define NORMAL_STATE 	GPIO_PIN_SET
#define PRESSED_STATE 	GPIO_PIN_RESET

int isButtonPressed(int key_index);
void subKeyProcess(int key_index);

void getKeyInput();
