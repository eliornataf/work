/*****************************************************************************
* File Name: Time Function - ADT
* Written by: Elior Nataf
* Date: 11/4/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __TIME_H__
#define __TIME_H__

/*------------------------------- Header Files ------------------------------*/

#define _XOPEN_SOURCE 600
#include <time.h> /* time */
#include <stddef.h> /* size_t */

/*---------------------------------- Typedef --------------------------------*/

/*------------------------------- Enum & Define -----------------------------*/

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that produce task first execute time using clockID and 
 * periodTimeInMSec.
 *
 * Time Complexity: O(1).
 * 
 * Input:
 * clockID - clockID type (CLOCK_MONOTONIC || CLOCK_REALTIME ||
 * CLOCK_REALTIME_COARSE).
 * periodTimeInMSec - The period time (in ms) to execute taskAction.
 * 
 * Output:
 * INT_MAX - clockID invalid input (CLOCK_MONOTONIC != _clockID && 
 * CLOCK_REALTIME != _clockID && CLOCK_REALTIME_COARSE != _clockID), 
 * first execute time is not possible.
 * INT_MAX - periodTimeInMSec invalid input (!_periodTimeInMSec), 
 * first execute time is not possible.
 * first task execute time.
 *
 * Error: 
 * INT_MAX - clockID invalid input (CLOCK_MONOTONIC != _clockID && 
 * CLOCK_REALTIME != _clockID && CLOCK_REALTIME_COARSE != _clockID), 
 * first execute time is not possible.
 * INT_MAX - periodTimeInMSec invalid input (!_periodTimeInMSec), 
 * first execute time is not possible.
 */
size_t GetFirstExecuteTime(clockid_t clockID, size_t periodTimeInMSec);

/* Description:
 * A function that compare between two task execute time.
 *
 * Time Complexity: O(1).
 * 
 * Input:
 * task1ExecuteTime - task1 execute time (in ms).
 * task2ExecuteTime - task2 execute time (in ms).
 * 
 * Output:
 * INT_MAX - task1ExecuteTime/task2ExecuteTime invalid input 
 * (!_task1ExecuteTime || !_task2ExecuteTime), compare is not possible.
 * return zero if task2 is smaller and 1 if task1 is smaller.
 *
 * Error: 
 * INT_MAX - task1ExecuteTime/task2ExecuteTime invalid input 
 * (!_task1ExecuteTime || !_task2ExecuteTime), compare is not possible.
 */
int GetCompareBetweenTaskExecuteTime(size_t task1ExecuteTime, size_t task2ExecuteTime);

/* Description:
 * A function that makes task sleep before task execute time.
 *
 * Time Complexity: O(1).
 * 
 * Input:
 * taskExecuteTime - task execute time (in ms).
 * clockID - clockID type (CLOCK_MONOTONIC || CLOCK_REALTIME ||
 * CLOCK_REALTIME_COARSE).
 * 
 * Output:
 * None.
 *
 * Error: 
 * taskExecuteTime invalid input (!_taskExecuteTime), sleep is not possible.
 * clockID invalid input (CLOCK_MONOTONIC != _clockID && 
 * CLOCK_REALTIME != _clockID && CLOCK_REALTIME_COARSE != _clockID), 
 * sleep is not possible.
 */
void SleepTaskBeforeExecute(size_t taskExecuteTime, clockid_t clockID);

#endif /* __TIME_H__ */
