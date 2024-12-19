/*
 * scheduler.c
 *
 *  Created on: 13 Dec. 2024
 *      Author: PC
 */

#include "scheduler.h"

	void SCH_Init()
	{
		SCH_Global_tick_counter = 0;
		SCH_TaskList = NULL;
	}

	// timer_run
	void SCH_Update()
	{
		SCH_Global_tick_counter++;
		if(SCH_TaskList == NULL) return; // no task
		Task *current_task = SCH_TaskList;
		if (current_task->delay <= SCH_Global_tick_counter)
		{
			current_task->pTask(); //run
			if(current_task->period > 0) // repeatedly
			{
				current_task->delay = SCH_Global_tick_counter + current_task->period;
			}
			else // period = 0
			{
				SCH_TaskList = current_task->next_task;
				free(current_task);
			}
		}

	}
	// timer flag == 1
	void SCH_Dispatch_Task()
	{
		Task *current_task = SCH_TaskList;
		unsigned char taskIndex = 0; // delete task
		while(current_task != NULL)
		{
			if (current_task->delay <= SCH_Global_tick_counter) // do task
			{
				current_task->pTask();
				if(current_task->period > 0) // check repeatedly
				{
					current_task->delay = SCH_Global_tick_counter + current_task->period;
					current_task = current_task->next_task;
					taskIndex++; // next task
				}
				else // period = 0 and delete task
				{
					unsigned char result = SCH_Delete_Task(taskIndex);

					if(result) // delete
					{
						current_task->next_task;
					}
//					else // error
//					{
//						current_task->next_task;
//					}

				}
			}
			else // not time yet
			{
				current_task->next_task;
				taskIndex++;
			}

		}

	}
	// set timer
	unsigned char SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD)
	{
		Task *new_task = (Task*)malloc(sizeof(Task)); //memory allocation
		if(new_task == NULL) return SCH_MAX_TASKS; //fail (not enough)
		new_task->pTask = pFunction;
		new_task->delay = SCH_Global_tick_counter + DELAY;
		new_task->period = PERIOD;
		new_task->next_task = NULL;
		// insert
		if(SCH_TaskList == NULL || SCH_TaskList->delay <= new_task->delay)
		{
			new_task->next_task = SCH_TaskList; // point to first task
			SCH_TaskList = new_task;// new task is first task
		}
		else
		{
			Task *current = SCH_TaskList; // scan task
			while((current->next_task != NULL) && (current->next_task->delay <= new_task->delay))
			{
				current = current->next_task; // priority current task
			}
			new_task->next_task = current->next_task;
			current->next_task = new_task;
		}
		 return 1; //success
	}

	unsigned char SCH_Delete_Task(const int TASK_INDEX)
	{
		  Task* current = SCH_TaskList; //head
		  Task* previous = NULL; // before task of current
		  unsigned char i = 0;
		  while((current != NULL) && (i < TASK_INDEX))
		  {
			  previous = current;
		      current = current->next_task;
		      i++;
		  }
		  if(current == NULL)
		  {
			  return 0;  // fail (Task not found)
		  }

		  if(previous == NULL) // head is current
		  {
			  SCH_TaskList = current->next_task;
		  }
		  else // task need delete not head
		  {
			  previous->next_task = current->next_task;
		  }
		  free(current);
		 return 1; // success
	}
