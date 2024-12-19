/*
 * fsm_manual.c
 *
 *  Created on: Dec 10, 2024
 *      Author: PC
 */


#include"fsm_manual.h"
	int timer_man = 0;
	void switchMode2()
		{
			status = RED_MAN;
			counter1 = red_timer;
			set_timer(2,1000);
			set_timer(4,250);
			updateLedBufferVal(counter1/10,counter1%10, counter1/10, 2);
		}

	void switchMode3()
		{
			status = YELLOW_MAN;
			counter1 = yellow_timer;
			set_timer(2,1000);
			set_timer(4,250);
			updateLedBufferVal(counter1/10, counter1%10, counter1/10, 3);
		}
	void switchMode4()
		{
			status = GREEN_MAN;
			counter1 = green_timer;
			set_timer(2,1000);
			set_timer(4,250);
			updateLedBufferVal(counter1/10, counter1%10, counter1/10, 4);
		}

	void fsm_manual_run()
	{
		switch(status)
		{
			case RED_MAN:
				displayLed(RED_MAN);
				// reset after 1s
				if(is_time_expired(2))
				{
					set_timer(2, 1000);
					updateLedBufferVal(counter1/10, counter1%10, counter1/10, 2);
				}
				//mode 3
				if(isButtonPressed(0))
				{
					switchMode3();
				}
				// next state
				if(isButtonPressed(1))
				{
					status = RED_MAN_MODIFY;
					timer_man = red_timer;
					updateLedBufferVal(timer_man/10, timer_man%10, 0, 2);
				}
				break;

			case RED_MAN_MODIFY:
				displayLed(RED_MAN);
				// back mode 2
				if(isButtonPressed(0))
				{
					status = RED_MAN;
				}
				// modify
				if(isButtonPressed(1))
				{
					timer_man++;
					if(timer_man > 99) timer_man = 1;
					updateLedBufferVal(timer_man/10, timer_man%10, 0, 2);
				}
				// save value
				if(isButtonPressed(2))
				{
					red_timer = timer_man;
					green_timer = red_timer - yellow_timer;

				}
				break;

			case YELLOW_MAN:
				displayLed(YELLOW_MAN);
				// reset after 1s
				if(is_time_expired(2))
				{
					set_timer(2, 1000);
					updateLedBufferVal(counter1/10, counter1%10, 0, 3);
				}
				// mode 4
				if(isButtonPressed(0))
				{
					switchMode4();
				}
				//next state
				if(isButtonPressed(1))
				{
					status = YELLOW_MAN_MODIFY;
					timer_man = yellow_timer;
					updateLedBufferVal(timer_man/10, timer_man%10, 0, 3);
				}
				break;

			case YELLOW_MAN_MODIFY:
				displayLed(YELLOW_MAN);
				//back mode 3
				if(isButtonPressed(0))
				{
					status = YELLOW_MAN;
				}
				// modify
				if(isButtonPressed(1))
				{
					timer_man++;
					if(timer_man > 99) timer_man = 1;
					updateLedBufferVal(timer_man/10, timer_man%10, 0, 3);
				}
				// save value
				if(isButtonPressed(2))
				{
					yellow_timer = timer_man;
					green_timer = red_timer - yellow_timer;
				}
				break;

			case GREEN_MAN:
				displayLed(GREEN_MAN);
				// reset after 1s
				if(is_time_expired(2))
				{
					set_timer(2, 1000);
					updateLedBufferVal(counter1/10, counter1%10, 0, 4);
				}
				// mode INIT
				if(isButtonPressed(0))
				{
					status = INIT;
				}
				// next state
				if(isButtonPressed(1))
				{
					status = GREEN_MAN_MODIFY;
					timer_man = green_timer;
					updateLedBufferVal(timer_man/10, timer_man%10, 0, 4);
				}
				break;

			case GREEN_MAN_MODIFY:
				displayLed(GREEN_MAN);
				//back mode 4
				if(isButtonPressed(0))
				{
					status = GREEN_MAN;
				}
				//modify
				if(isButtonPressed(1))
				{
					timer_man++;
					if(timer_man > 99) timer_man = 1;
					updateLedBufferVal(timer_man/10, timer_man%10, 0, 4);
				}
				//save value
				if(isButtonPressed(2))
				{
					green_timer = timer_man;
					yellow_timer = red_timer - green_timer;
				}

				break;

			default: break;
		}
	}







