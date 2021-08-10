#define _XOPEN_SOURCE 600
#include <time.h> /* clockid_t */
#include <stdlib.h> /* malloc, free */
#include <limits.h> /* MAX_INT */
#include "task.h" /* Tash Header */
#include "timeFunc.h" /* Time Header */

/********************************************/

struct Task
{
    TaskFunc_t m_taskAction;
    void *m_context;
    size_t m_periodTimeInMSec;
    size_t m_executeTimeInMSec;
};

/********************************************/

Task_t *CreateTask(TaskFunc_t _taskAction, void *_context, size_t _periodTimeInMSec)
{
    Task_t *task = NULL;

    if (NULL == _taskAction || !_periodTimeInMSec)
    {
        return NULL;
    }

    task = (Task_t*)malloc(sizeof(Task_t));
    if (!task)
    {
        return NULL;
    }

    task->m_taskAction = _taskAction;
    task->m_context = _context;
    task->m_periodTimeInMSec = _periodTimeInMSec;
    task->m_executeTimeInMSec = 0;

    return task;
}

void DestroyTask(Task_t *_task)
{
    if (!_task)
    {
        return;
    }

    free(_task);
}

void FirstTaskExecuteTime(Task_t *_task, clockid_t _clockID)
{
    if (!_task || (CLOCK_MONOTONIC != _clockID && CLOCK_REALTIME != _clockID && CLOCK_REALTIME_COARSE != _clockID) ) 
    {
        return;
    }

    _task->m_executeTimeInMSec = GetFirstExecuteTime(_clockID, _task->m_periodTimeInMSec);
}

int ExecuteTask(Task_t *_task)
{
    if (!_task)
    {
        return INT_MAX;
    }

    return _task->m_taskAction(_task->m_context);
}

void UpdateTaskExecuteTime(Task_t *_task)
{
    if (!_task)
    {
        return;
    }

    _task->m_executeTimeInMSec += _task->m_periodTimeInMSec; 
}

size_t GetTaskExecuteTime(Task_t *_task)
{
    if (!_task)
    {
        return INT_MAX;
    }

    return _task->m_executeTimeInMSec;
}

int CompareTasks(const void *_task1, const void *_task2)
{
    if (!_task1 || !_task2)
    {
        return INT_MAX;
    }

    return GetCompareBetweenTaskExecuteTime( ((Task_t*)_task1)->m_executeTimeInMSec, ((Task_t*)_task2)->m_executeTimeInMSec); 
}