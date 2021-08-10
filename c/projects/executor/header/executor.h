/*****************************************************************************
* File Name: Executor - ADT
* Written by: Elior Nataf
* Date: 11/4/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __EXECUTOR_H__
#define __EXECUTOR_H__

/*------------------------------- Header Files ------------------------------*/

#define _XOPEN_SOURCE 600
#include "task.h" /* Tash Header */

/*---------------------------------- Typedef --------------------------------*/

typedef struct Executor Executor_t;

/*------------------------------- Enum & Define -----------------------------*/

typedef enum Status
{
    SUCCEEDED = 0,
    FAILED = 1
} Status_t;

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creating a new executor. Memory will be specially allocated.
 *
 * Time Complexity: O(1).
 * 
 * Input:
 * executorName - the name of the executor.
 * clockID - clockID type (CLOCK_MONOTONIC || CLOCK_REALTIME ||
 * CLOCK_REALTIME_COARSE).
 * 
 * Output:
 * NULL - executorName is null, create is not possible.  
 * NULL - clockID invalid input (CLOCK_MONOTONIC != _clockID && 
 * CLOCK_REALTIME != _clockID && CLOCK_REALTIME_COARSE != _clockID), 
 * create is not possible.
 * NULL - allocation failed.
 * executor - pointer to new created executor.
 *
 * Error: 
 * NULL - executorName is null, create is not possible.  
 * NULL - clockID invalid input (CLOCK_MONOTONIC != _clockID && 
 * CLOCK_REALTIME != _clockID && CLOCK_REALTIME_COARSE != _clockID), 
 * create is not possible.
 * NULL - allocation failed.
 */
Executor_t *ExecutorCreate(const char *executorName, clockid_t clockID);

/* Description:
 * A function that destroys a specified executor. Previously allocated memory will be 
 * freed.
 * 
 * Time Complexity: O(n).
 *
 * Input:
 * executor - pointer to executor to be deallocated.
 *
 * Output:
 * None.
 *
 * Error: 
 * executor pointer is not initialized, destroy is not possible.
 */
void ExecutorDestroy(Executor_t *_executor);

/* Description:
 * A function that creates a new a executor element that holds specified task and adds it to 
 * the executor. Memory will be allocated for new executor element.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * executor - pointer to executor to be added.
 * taskAction - user provided function pointer to be execute on task.
 * context - user provided context, will be sent to taskAction. null is possible.
 * periodTimeInMSec - the period time (in ms) to execute taskAction.
 *
 * Output:
 * FAILED - executor/taskAction is null, add is not possible.  
 * FAILED - periodTimeInMSec invalid input (!periodTimeInMSec), add is not 
 * possible.
 * FAILED - task create failed.
 * FAILED - add structure error.
 * SUCCEEDED - add task is succeeded.
 * 
 * Error: 
 * FAILED - executor/taskAction is null, add is not possible.  
 * FAILED - periodTimeInMSec invalid input (!periodTimeInMSec), add is not 
 * possible.
 * FAILED - task create failed.
 * FAILED - add structure error.
 */
int ExecutorAddTask(Executor_t *executor, TaskFunc_t taskAction, void *context, size_t periodTimeInMSec);

/* Description:
 * A function that run the tasks till is empty or executor was paused. 
 * 
 * Time Complexity: O(1)..O(n) (depends user function).
 *
 * Input:
 * executor - pointer to executor to be runned.
 *
 * Output:
 * INT_MAX - executor is null, run is not possible.  
 * INT_MAX - run structure error, run is not possible.
 * number of times the functions was executed.
 * 
 * Error: 
 * INT_MAX - executor is null, run is not possible.  
 * INT_MAX - run structure error, run is not possible.
 */
size_t ExecutorRun(Executor_t *executor);

/* Description:
 * A function that pause the executor and returns the number of
 * remain tasks to executed. 
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * executor - pointer to executor to be paused.
 *
 * Output:
 * INT_MAX - executor is null, run is not possible.  
 * number of remain tasks to executed.
 * 
 * Error: 
 * INT_MAX - executor is null, run is not possible.  
 */
size_t ExecutorPause(Executor_t *executor);

#endif /* __EXECUTOR_H__ */
