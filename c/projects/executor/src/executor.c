#define _XOPEN_SOURCE 600
#include <limits.h> /* MAX_INT */
#include <string.h> /* strcpy */
#include <stdlib.h> /* malloc, free */
#include <time.h> /* clockid_t */
#include "executor.h" /* Executor Header */
#include "task.h" /* Tash Header */
#include "timeFunc.h" /* Time Header */
#include "genericVector.h" /* Generic Vector */
#include "genericHeap.h" /* Generic Heap */

#define INIT_CAPACITY (10)
#define INIT_INC_BLOCK_SIZE (5)
#define STR_LENGTH (50)
#define NOT_RUNNING (0)
#define RUNNING (1)

/******************************************/

struct Executor
{
    char *m_executorName;
    Vector_t *m_tasksVec;
    clockid_t m_clockID;
    int m_isRunning;
};

/******************************************/

static void FreeElement(void *_element)
{
	free(_element);
}

/******************************************/

Executor_t *ExecutorCreate(const char *_executorName, clockid_t _clockID)
{
    Executor_t *executor = NULL;

    if (!_executorName || (CLOCK_MONOTONIC != _clockID && CLOCK_REALTIME != _clockID && CLOCK_REALTIME_COARSE != _clockID) )
    {
        return NULL;
    }

    executor = (Executor_t*)malloc(sizeof(Executor_t));
    if (!executor)
    {
        return NULL;
    }

    executor->m_executorName = (char*)malloc(STR_LENGTH * sizeof(char));
    if (!executor->m_executorName)
    {
        free(executor);
        return NULL;
    }

    strcpy(executor->m_executorName, (char*)_executorName);
    
    executor->m_tasksVec = VectorCreate(INIT_CAPACITY, INIT_INC_BLOCK_SIZE);
    if (!executor->m_tasksVec)
    {
        free(executor->m_executorName);
        free(executor);
        return NULL;
    }

    executor->m_clockID = _clockID;
    executor->m_isRunning = NOT_RUNNING;

    return executor;
}

void ExecutorDestroy(Executor_t *_executor)
{
    if (!_executor)
    {
        return;
    }

    VectorDestroy(&_executor->m_tasksVec, FreeElement);

    free(_executor->m_executorName);
    free(_executor);
}

int ExecutorAddTask(Executor_t *_executor, TaskFunc_t _taskAction, void *_context, size_t _periodTimeInMSec)
{
    Task_t *task = NULL;

    if (!_executor || !_taskAction || !_periodTimeInMSec)
    {
        return FAILED;
    }

    task = CreateTask(_taskAction, _context, _periodTimeInMSec);
    if (!task)
    {
        return FAILED;
    }

    if (VECTOR_SUCCESS != VectorAppend(_executor->m_tasksVec, task))
    {
        DestroyTask(task);
        return FAILED;
    }

    return SUCCEEDED;
}

size_t ExecutorRun(Executor_t *_executor)
{
    size_t countNumOfExecuteFunc = 0;
    Task_t *currTask = NULL;
    void *getTask = NULL;
    Heap_t *heap = NULL;
    size_t vecSize, i;

    if (!_executor)
    {
        return INT_MAX;
    }

    vecSize = VectorSize(_executor->m_tasksVec);

    for (i = 0;i < vecSize;++i)
    {
        VectorGet(_executor->m_tasksVec, i, &getTask);

        FirstTaskExecuteTime((Task_t*)getTask, _executor->m_clockID);
    }

    heap = HeapBuild(_executor->m_tasksVec, CompareTasks);
    if (!heap)
    {
        return INT_MAX;
    }

    _executor->m_isRunning = RUNNING;

    while (HeapSize(heap) && _executor->m_isRunning)
    {
        currTask = (Task_t*)HeapExtractMax(heap);

        ++countNumOfExecuteFunc;

        SleepTaskBeforeExecute(GetTaskExecuteTime(currTask), _executor->m_clockID);

        if (!ExecuteTask(currTask))
        {
            UpdateTaskExecuteTime(currTask);

            if (HEAP_SUCCESS != HeapInsert(heap, currTask))
            {
                break;
            }
        }
        else
        {
            DestroyTask(currTask);
        }
    }

    HeapDestroy(&heap);

    return countNumOfExecuteFunc;
}

size_t ExecutorPause(Executor_t *_executor)
{
    if (!_executor)
    {
        return INT_MAX;
    }

    _executor->m_isRunning = NOT_RUNNING;

    return VectorSize(_executor->m_tasksVec);
}
