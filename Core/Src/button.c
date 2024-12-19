/*
 * button.c
 *
 *  Created on: Dec 10, 2024
 *      Author: PC
 */

#include"button.h"
#define NUMBER_BUTTONS	3

	int key_reg_0[NUMBER_BUTTONS] 			= {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
	int key_reg_1[NUMBER_BUTTONS] 			= {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
	int key_reg_2[NUMBER_BUTTONS] 			= {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
	int key_reg_3[NUMBER_BUTTONS] 			= {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE}; // previous fixed state
	int time_for_key_press[NUMBER_BUTTONS]  = {200, 200, 200};
	int button_flag[NUMBER_BUTTONS] 		= {0, 0, 0};
	int gpio_pin[NUMBER_BUTTONS] 			= {button1_Pin, button2_Pin, button3_Pin};
	GPIO_TypeDef* gpio_port[NUMBER_BUTTONS] = {button1_GPIO_Port, button2_GPIO_Port, button3_GPIO_Port};

	// set flag
	void subKeyProcess(int key_index)
	{
		button_flag[key_index] = 1;
	}


	int isButtonPressed(int key_index)
	{
		if(button_flag[key_index] == 1)
		{
			button_flag[key_index] = 0;
			return 1;
		}
		return 0;
	}

	void getKeyInput()
	{
		for(int i = 0; i < NUMBER_BUTTONS; i++)
		{
			key_reg_0[i] = key_reg_1[i];
			key_reg_1[i] = key_reg_2[i];
			key_reg_2[i] = HAL_GPIO_ReadPin(gpio_port[i], gpio_pin[i]);
			if((key_reg_0[i] == key_reg_1[i]) && (key_reg_1[i] == key_reg_2[i]))
			{
				if(key_reg_3[i] != key_reg_2[i]) // press and drop
				{
					key_reg_3[i] = key_reg_2[i];
					if(key_reg_2[i] == PRESSED_STATE)
					{
						subKeyProcess(i);
						time_for_key_press[i] = 200;
					}
				}
				else // press and hold
				{
					time_for_key_press[i] --;
					if(time_for_key_press[i] <= 0)
					{
						if(key_reg_2[i] == PRESSED_STATE)
						{
							subKeyProcess(i);
						}
						time_for_key_press[i] = 200;
					}
				}
			}
		}
	}




