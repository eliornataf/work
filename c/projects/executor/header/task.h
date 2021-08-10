/*****************************************************************************
* File Name: Task - ADT
* Written by: Elior Nataf
* Date: 11/4/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __TASK_H__
#define __TASK_H__

/*------------------------------- Header Files ------------------------------*/

#define _XOPEN_SOURCE 600
#include <stddef.h> /* size_t */
#include <time.h> /* time */

/*---------------------------------- Typedef --------------------------------*/

typedef struct Task Task_t;

/* Description:
 * Function that makes action on task, specified by user demand. 
 * 
 * Time Complexity: O(1)..O(n) (depends user function).
 *
 * Input:
 * context - Pointer to user provided context. null is possible.
 *
 * Output:
 * return zero to run task again and 1 to destroy task.
 *
 * Error: 
 * None.
 */
typedef int	(*TaskFunc_t)(void *context);

/*------------------------------- Enum & Define -----------------------------*/

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creating a new task. Memory will be specially allocated.
 *
 * Time Complexity: O(1).
 * 
 * Input:
 * taskAction - user provided function pointer to be execute on task.
 * context - user provided context, will be sent to taskAction. null is possible.
 * periodTimeInMSec - The period time (in ms) to execute taskAction.
 * 
 * Output:
 * NULL - taskAction is null, create is not possible.  
 * NULL - periodTimeInMSec invalid input (!periodTimeInMSec), create is not 
 * possible.
 * NULL - task allocation failed.
 * task - pointer to new created task.
 *
 * Error: 
 * NULL - taskAction is null, create is not possible.  
 * NULL - periodTimeInMSec invalid input (!periodTimeInMSec), create is not 
 * possible.
 * NULL - task allocation failed.
 */
Task_t *CreateTask(TaskFunc_t taskAction, void *context, size_t periodTimeInMSec);

/* Description:
 * A function that destroys a specified task. Previously allocated memory will be 
 * freed.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * task - pointer to task to be deallocated.
 *
 * Output:
 * None.
 *
 * Error: 
 * task pointer is not initialized, destroy is not possible.
 */
void DestroyTask(Task_t *task);

/* Description:
 * A function that produce task first execute time using clockID.
 *
 * Input:
 * task - pointer to task to be first task executed.
 * clockID - clockID type (CLOCK_MONOTONIC || CLOCK_REALTIME ||
 * CLOCK_REALTIME_COARSE).
 * 
 * Output:
 * None.
 *
 * Error: 
 * task pointer is not initialized, first task execute is not possible.
 * clockID invalid input (CLOCK_MONOTONIC != _clockID && CLOCK_REALTIME 
 * != _clockID && CLOCK_REALTIME_COARSE != _clockID), task first execute 
 * is not possible.
 */
void FirstTaskExecuteTime(Task_t *task, clockid_t clockID);

/* Description:
 * A function that execute a specified task using taskAction and context.
 *
 * Input:
 * task - pointer to task to be executed.
 * 
 * Output:
 * MAX_INT - task pointer is not initialized, execute is not possible.
 * return zero to run task again and 1 to destroy task.
 *
 * Error: 
 * MAX_INT - task pointer is not initialized, execute is not possible.
 */
int ExecuteTask(Task_t *task);

/* Description:
 * A function that update execute time to specified task using periodTimeInMSec.
 *
 * Input:
 * task - pointer to task to be updated.
 * 
 * Output:
 * None.
 *
 * Error: 
 * task pointer is not initialized, update is not possible.
 */
void UpdateTaskExecuteTime(Task_t *task);

/* Description:
 * A function that get task execute time.
 *
 * Input:
 * task - pointer to task to be get execute time from.
 * 
 * Output:
 * MAX_INT - task pointer is not initialized, get is not possible.
 * task execute time.
 *
 * Error: 
 * MAX_INT - task pointer is not initialized, get is not possible.
 */
size_t GetTaskExecuteTime(Task_t *task);

/* Description:
 * A function that compare between tasks execute time.
 *
 * Input:
 * task1 - pointer to task1 to be compared.
 * task2 - pointer to task2 to be compared.
 * 
 * Output:
 * INT_MAX - task1/task2 pointer is not initialized, compare 
 * is not possible.
 * return zero if task2 is smaller and 1 if task1 is smaller.
 *
 * Error: 
 * INT_MAX - task1/task2 pointer is not initialized, compare 
 * is not possible.
 */
int CompareTasks(const void *_task1, const void *_task2);

#endif /* __TASK_H__ */
