/*
 * traffic_light.c
 *
 *  Created on: Dec 11, 2024
 *      Author: PC
 */
#include "traffic_light.h"

	void  redx_greeny()
	{
		HAL_GPIO_WritePin(led_red_x_GPIO_Port, led_red_x_Pin, 0);
		HAL_GPIO_WritePin(led_green_x_GPIO_Port, led_green_x_Pin, 1);
		HAL_GPIO_WritePin(led_yellow_x_GPIO_Port, led_yellow_x_Pin, 1);
		HAL_GPIO_WritePin(led_green_y_GPIO_Port, led_green_y_Pin, 0);
		HAL_GPIO_WritePin(led_red_y_GPIO_Port, led_red_y_Pin, 1);
		HAL_GPIO_WritePin(led_yellow_y_GPIO_Port, led_yellow_y_Pin, 1);
	}

	void redx_yellowy()
	{
		HAL_GPIO_WritePin(led_red_x_GPIO_Port, led_red_x_Pin, 0);
		HAL_GPIO_WritePin(led_green_x_GPIO_Port, led_green_x_Pin, 1);
		HAL_GPIO_WritePin(led_yellow_x_GPIO_Port, led_yellow_x_Pin, 1);
		HAL_GPIO_WritePin(led_green_y_GPIO_Port, led_green_y_Pin, 1);
		HAL_GPIO_WritePin(led_red_y_GPIO_Port, led_red_y_Pin, 1);
		HAL_GPIO_WritePin(led_yellow_y_GPIO_Port, led_yellow_y_Pin, 0);
	}

	void greenx_redy()
	{
		HAL_GPIO_WritePin(led_red_x_GPIO_Port, led_red_x_Pin, 1);
		HAL_GPIO_WritePin(led_green_x_GPIO_Port, led_green_x_Pin, 0);
		HAL_GPIO_WritePin(led_yellow_x_GPIO_Port, led_yellow_x_Pin, 1);
		HAL_GPIO_WritePin(led_green_y_GPIO_Port, led_green_y_Pin, 1);
		HAL_GPIO_WritePin(led_red_y_GPIO_Port, led_red_y_Pin, 0);
		HAL_GPIO_WritePin(led_yellow_y_GPIO_Port, led_yellow_y_Pin, 1);
	}

	void yellowx_redy()
	{
		HAL_GPIO_WritePin(led_red_x_GPIO_Port, led_red_x_Pin, 1);
		HAL_GPIO_WritePin(led_green_x_GPIO_Port, led_green_x_Pin, 1);
		HAL_GPIO_WritePin(led_yellow_x_GPIO_Port, led_yellow_x_Pin, 0);
		HAL_GPIO_WritePin(led_green_y_GPIO_Port, led_green_y_Pin, 1);
		HAL_GPIO_WritePin(led_red_y_GPIO_Port, led_red_y_Pin, 0);
		HAL_GPIO_WritePin(led_yellow_y_GPIO_Port, led_yellow_y_Pin, 1);
	}

	void red_man()
	{
		if(is_time_expired(4))
		{
			set_timer(4, 250);
			HAL_GPIO_TogglePin(led_red_x_GPIO_Port, led_red_x_Pin);
			HAL_GPIO_WritePin(led_green_x_GPIO_Port, led_green_x_Pin, 1);
			HAL_GPIO_WritePin(led_yellow_x_GPIO_Port, led_yellow_x_Pin, 1);
			HAL_GPIO_WritePin(led_green_y_GPIO_Port, led_green_y_Pin, 1);
			HAL_GPIO_TogglePin(led_red_y_GPIO_Port, led_red_y_Pin);
			HAL_GPIO_WritePin(led_yellow_y_GPIO_Port, led_yellow_y_Pin, 1);
		}
	}

	void yellow_man()
	{
		if(is_time_expired(4))
		{
			set_timer(4, 250);
			HAL_GPIO_TogglePin(led_yellow_x_GPIO_Port, led_yellow_x_Pin);
			HAL_GPIO_WritePin(led_green_x_GPIO_Port, led_green_x_Pin, 1);
			HAL_GPIO_WritePin(led_red_x_GPIO_Port, led_red_x_Pin, 1);
			HAL_GPIO_WritePin(led_green_y_GPIO_Port, led_green_y_Pin, 1);
			HAL_GPIO_TogglePin(led_yellow_y_GPIO_Port, led_yellow_y_Pin);
			HAL_GPIO_WritePin(led_red_y_GPIO_Port, led_red_y_Pin, 1);
		}
	}

	void green_man()
	{
		if(is_time_expired(4))
		{
			set_timer(4, 250);
			HAL_GPIO_TogglePin(led_green_x_GPIO_Port, led_green_x_Pin);
			HAL_GPIO_WritePin(led_red_x_GPIO_Port, led_red_x_Pin, 1);
			HAL_GPIO_WritePin(led_yellow_x_GPIO_Port, led_yellow_x_Pin, 1);
			HAL_GPIO_WritePin(led_red_y_GPIO_Port, led_red_y_Pin, 1);
			HAL_GPIO_TogglePin(led_green_y_GPIO_Port, led_green_y_Pin);
			HAL_GPIO_WritePin(led_yellow_y_GPIO_Port, led_yellow_y_Pin, 1);
		}
	}
