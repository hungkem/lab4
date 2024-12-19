/*
 * fsm_automatic.c
 *
 *  Created on: Dec 10, 2024
 *      Author: PC
 */


#include"fsm_automatic.h"

	void fsm_automatic_run()
	{
		switch(status)
		{
			case INIT:
				clearLed();
				status = REDX_GREENY_AUTO; // next state
				counter1 = red_timer;
				counter2 = green_timer;
				updateLedBufferVal(counter1/10, counter1%10, counter2/10, counter2%10);
				set_timer(1, green_timer*1000);
				set_timer(2, 1000);
				set_timer(5, 250);
				break;

			case REDX_GREENY_AUTO:
				displayLed(REDX_GREENY);
				// reset after 1s
				if(is_time_expired(2))
				{
					set_timer(2, 1000);
					counter1--;
					counter2--;
					updateLedBufferVal(counter1/10, counter1%10, counter2/10, counter2%10);
				}
				//next state
				if(is_time_expired(1))
				{
					status = REDX_YELLOWY_AUTO;
					set_timer(1, (red_timer - green_timer)*1000);
					counter1 = red_timer - green_timer;
					counter2 = yellow_timer;
					updateLedBufferVal(counter1/10, counter1%10, counter2/10, counter2%10);
				}
				// mode 2
				if(isButtonPressed(0))
				{
					switchMode2();
				}

				break;

			case REDX_YELLOWY_AUTO:
				displayLed(REDX_YELLOWY);
				// reset after 1s
				if(is_time_expired(2))
				{
					set_timer(2,1000);
					counter1--;
					counter2--;
					updateLedBufferVal(counter1/10, counter1%10, counter2/10, counter2%10);
				}
				// next state
				if(is_time_expired(1))
				{
					status = GREENX_REDY_AUTO;
					set_timer(1, green_timer*1000);
					counter1 = red_timer;
					counter2 = green_timer;
					updateLedBufferVal(counter1/10, counter1%10, counter2/10, counter2%10);
				}
				//mode 2
				if(isButtonPressed(0))
				{
					switchMode2();
				}
				break;
			case GREENX_REDY_AUTO:
				displayLed(GREENX_REDY);
				// reset after 1s
				if(is_time_expired(2))
				{
					set_timer(2,1000);
					counter1--;
					counter2--;
					updateLedBufferVal(counter1/10, counter1%10, counter2/10, counter2%10);
				}
				// next state
				if(is_time_expired(1))
				{
					status = YELLOWX_REDY_AUTO;
					set_timer(1, (red_timer - green_timer)*1000);
					counter1 = red_timer - green_timer;
					counter2 = yellow_timer;
					updateLedBufferVal(counter1/10, counter1%10, counter2/10, counter2%10);
				}
				//mode 2
				if(isButtonPressed(0))
				{
					switchMode2();
				}
				break;

			case YELLOWX_REDY_AUTO:
				displayLed(YELLOWX_REDY);
				// reset after 1s
				if(is_time_expired(2))
				{
					set_timer(2,1000);
					counter1--;
					counter2--;
					updateLedBufferVal(counter1/10, counter1%10, counter2/10, counter2%10);
				}
				// next state
				if(is_time_expired(1))
				{
					status = REDX_GREENY_AUTO;
					set_timer(1, green_timer*1000);
					counter1 = red_timer;
					counter2 = green_timer;
					updateLedBufferVal(counter1/10, counter1%10, counter2/10, counter2%10);

				}
				//mode 2
				if(isButtonPressed(0))
				{
					switchMode2();
				}
				break;

			default : break;
		}
	}


