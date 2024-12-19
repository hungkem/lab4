/*
 * scheduler.h
 *
 *  Created on: 13 Dec. 2024
 *      Author: PC
 */
#include "main.h"
#include <stdlib.h>
#include <stdint.h>
#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_


#endif /* INC_SCHEDULER_H_ */

#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0

typedef struct Task
{
	void (*pTask)(void);
	unsigned long delay;
	unsigned long period;
	struct Task *next_task; // link
}Task;

unsigned long SCH_Global_tick_counter; //tick
Task *SCH_TaskList; // head of task list

void SCH_Init(void);
void SCH_Update(void);
void SCH_Dispatch_Task(void);
unsigned char SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD);
unsigned char SCH_Delete_Task(const int TASK_INDEX);
