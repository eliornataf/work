#define _XOPEN_SOURCE 600
#include <time.h> /* clockid_t */
#include <limits.h> /* MAX_INT */
#include <unistd.h> /* usleep */
#include "timeFunc.h" /* TimeFunc Header */

/********************************************/

#define SEC_TO_MS_SEC(time) (time * 1000)
#define NANO_SEC_TO_MS_SEC(time) (time / 1000000)
#define MS_SEC_TO_MICRO_SEC(time) (time * 1000)

/********************************************/

size_t GetFirstExecuteTime(clockid_t _clockID, size_t _periodTimeInMSec)
{
    struct timespec currTime;

    if ((CLOCK_MONOTONIC != _clockID && CLOCK_REALTIME != _clockID && CLOCK_REALTIME_COARSE != _clockID) || !_periodTimeInMSec)
    {
        return INT_MAX;
    }

    clock_gettime(_clockID, &currTime);

    return SEC_TO_MS_SEC(currTime.tv_sec) + NANO_SEC_TO_MS_SEC(currTime.tv_nsec) + _periodTimeInMSec;
}

int GetCompareBetweenTaskExecuteTime(size_t _task1ExecuteTime, size_t _task2ExecuteTime)
{
    if (!_task1ExecuteTime || !_task2ExecuteTime)
    {
        return INT_MAX;
    }

    return _task2ExecuteTime < _task1ExecuteTime;
}

void SleepTaskBeforeExecute(size_t _taskExecuteTime, clockid_t _clockID)
{
    size_t currTimeInMSec, diffTime;
    struct timespec currTime;

    if (!_taskExecuteTime || (CLOCK_MONOTONIC != _clockID && CLOCK_REALTIME != _clockID && CLOCK_REALTIME_COARSE != _clockID) ) 
    {
        return;
    }

    clock_gettime(_clockID, &currTime);

    currTimeInMSec = SEC_TO_MS_SEC(currTime.tv_sec) + NANO_SEC_TO_MS_SEC(currTime.tv_nsec);

    diffTime = (currTimeInMSec < _taskExecuteTime) ? _taskExecuteTime - currTimeInMSec : 0;

    usleep(MS_SEC_TO_MICRO_SEC(diffTime));
}