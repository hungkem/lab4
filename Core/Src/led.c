/*
 * led.c
 *
 *  Created on: Dec 10, 2024
 *      Author: PC
 */

#include"led.h"
#include "global.h"
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};
int counter1 = 0;
int counter2 = 0;

	void clearLed()
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
	}

	void display7SEG(int num)
	{
		  if(num == 0)
		  {
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);
		  }
		  if(num == 1)
		  {
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);
		  }
		  if(num == 2)
			  {
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
			  }
		  if(num == 3)
			  {
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
			  }
		  if(num == 4)
			  {
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
			  }
		  if(num == 5)
			  {
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
			  }
		  if(num == 6)
			  {
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
			  }
		  if(num == 7)
			  {
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);
			  }
		  if(num == 8)
			  {
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
			  }
		  if(num == 9)
			  {
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
				  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
			  }
	}


	void update7SEG(int index)
	{
		switch(index)
		{
			case 0:
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,  0);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,  1);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 1);
				display7SEG(led_buffer[index]);
				break;
			case 1:
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,  1);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,  0);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 1);
				display7SEG(led_buffer[index]);
				break;
			case 2:
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,  1);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,  1);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 1);
				display7SEG(led_buffer[index]);
				break;
			case 3:
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,  1);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,  1);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);
				display7SEG(led_buffer[index]);
				break;
		}
	}
	// run led
	void scanLedBuffer()
	{
		if(is_time_expired(5))
		{
			set_timer(5, 250);
			update7SEG(index_led);
			index_led++;
			if(index_led >= MAX_LED)
			{
				index_led = 0;
			}
		}
	}

	void updateLedBufferVal(int val0, int val1, int val2, int val3)
	{
		led_buffer[0] = val0;
		led_buffer[1] = val1;
		led_buffer[2] = val2;
		led_buffer[3] = val3;
	}

	void displayLed(int led_index)
	{
		switch(led_index)
		{
			case RED_MAN:
							red_man();
				break;
			case YELLOW_MAN:
							yellow_man();
				break;
			case GREEN_MAN:
							green_man();
				break;
			case REDX_GREENY:
							redx_greeny();
				break;
			case REDX_YELLOWY:
							redx_yellowy();
				break;
			case GREENX_REDY:
							greenx_redy();
				break;
			case YELLOWX_REDY:
							yellowx_redy();
				break;
			default: break;
		}
	}













