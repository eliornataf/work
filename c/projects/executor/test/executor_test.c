#define _XOPEN_SOURCE 600
#include <limits.h> /* MAX_INT */
#include <stdio.h> /* printf */
#include <stdlib.h> /* rand, srand */
#include <time.h> /* clock_t, srand*/
#include "executor.h" /* Executor Header */

#define CONTINUE_TASK_RUN (0)
#define STOP_TASK_RUN (1)
#define MAX_FUNC_INVOKED (10)

#define TASK_1 (1)
#define TASK_2 (2)
#define TASK_3 (3)
#define TASK_4 (4)
#define TASK_5 (5)
#define TASK_ERROR_COLOR (31)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

/*************************************************************/

typedef struct PauseTaskS
{
    Executor_t *m_executor;
    size_t *m_remainTaskToExecute;
} PauseTaskS_t;

/*************************************************************/

static size_t g_tasksCounter;

/*************************************************************/

static size_t ChooseColor(size_t _taskNum)
{
    switch(_taskNum)
    {
        case TASK_1: 
            return 32;

        case TASK_2: 
            return 33;

        case TASK_3: 
            return 34;

        case TASK_4: 
            return 36;

        case TASK_5: 
            return 37;
    }

    return TASK_ERROR_COLOR;
}

static int PrintCounter(void *_context)
{
    size_t taskNum = *(size_t*)_context;

    printf("\033[1;%ldmTask %ld: counter is: %ld\n\033[0m", ChooseColor(taskNum) ,taskNum, g_tasksCounter++);

    return (MAX_FUNC_INVOKED < g_tasksCounter) ? STOP_TASK_RUN : CONTINUE_TASK_RUN;
}

static int PauseTask(void *_context)
{
    *(((PauseTaskS_t*)_context)->m_remainTaskToExecute) = ExecutorPause( ((PauseTaskS_t*)_context)->m_executor);

    return STOP_TASK_RUN;
}

/*************************************************************/

void ExecutorCreateTest1(void)
{
    Executor_t *executor = NULL;

    printf("\033[1;34m\n*******Executor Create Test 1:*******\n\n\033[0m");

    executor = ExecutorCreate("exec", CLOCK_MONOTONIC);

    printf("Executor Create Func Test: ");

    CHECK_FUNC(NULL != executor);

    printf("\nExpected: SUCCESS - executor != NULL\n");

    ExecutorDestroy(executor);
}

void ExecutorCreateTest2(void)
{
    Executor_t *executor = NULL;

    printf("\033[1;34m\n*******Executor Create Test 2:*******\n\n\033[0m");

    executor = ExecutorCreate(NULL, CLOCK_MONOTONIC);

    printf("Executor Create Func Test: ");

    CHECK_FUNC(NULL == executor);

    printf("\nExpected: SUCCESS - executor is NULL, executorName is NULL\n");
}

void ExecutorCreateTest3(void)
{
    Executor_t *executor = NULL;

    printf("\033[1;34m\n*******Executor Create Test 3:*******\n\n\033[0m");

    executor = ExecutorCreate("exec", 888);

    printf("Executor Create Func Test: ");

    CHECK_FUNC(NULL == executor);

    printf("\nExpected: SUCCESS - executor is NULL, clockID invalid input\n");
}

void ExecutorAddTest1(void)
{
    Executor_t *executor = NULL;
    int status;
    size_t i;

    printf("\033[1;34m\n*******Executor Add Test 1:*******\n\n\033[0m");

    executor = ExecutorCreate("exec", CLOCK_MONOTONIC);

    printf("Executor Create Func Test: ");

    CHECK_FUNC(NULL != executor);

    printf("\nExpected: SUCCESS - executor != NULL\n");

    printf("\nExecutor Add Func Test:\n\n");

    for (i = 0;i < 5;++i)
    {
        status = ExecutorAddTask(executor, PrintCounter, NULL, 5000);

        printf("Add number %ld check (status): ", i + 1);

        CHECK_FUNC(SUCCEEDED == status);
    }

    printf("\nExpected: 5 SUCCESS - Add status is SUCCEEDED\n");

    ExecutorDestroy(executor);
}

void ExecutorAddTest2(void)
{
    Executor_t *executor = NULL;
    int status;
    size_t i;

    printf("\033[1;34m\n*******Executor Add Test 2:*******\n\n\033[0m");

    executor = ExecutorCreate("exec", CLOCK_MONOTONIC);

    printf("Executor Create Func Test: ");

    CHECK_FUNC(NULL != executor);

    printf("\nExpected: SUCCESS - executor != NULL\n");

    printf("\nExecutor Add Func Test:\n\n");

    for (i = 0;i < 20;++i)
    {
        status = ExecutorAddTask(executor, PrintCounter, NULL, 5000);

        printf("Add number %ld check (status): ", i + 1);

        CHECK_FUNC(SUCCEEDED == status);
    }

    printf("\nExpected: 5 SUCCESS - Add status is SUCCEEDED, resize vector\n");

    ExecutorDestroy(executor);
}

void ExecutorAddTest3(void)
{
    Executor_t *executor = NULL;
    int status;
    size_t i;

    printf("\033[1;34m\n*******Executor Add Test 3:*******\n\n\033[0m");

    printf("Executor Add Func Test:\n\n");

    for (i = 0;i < 2;++i)
    {
        status = ExecutorAddTask(executor, PrintCounter, NULL, 5000);

        printf("Add number %ld check (status): ", i + 1);

        CHECK_FUNC(FAILED == status);
    }

    printf("\nExpected: 2 SUCCESS - Add status is FAILED, executor is NULL\n");

    ExecutorDestroy(executor);
}

void ExecutorAddTest4(void)
{
    Executor_t *executor = NULL;
    int status;
    size_t i;

    printf("\033[1;34m\n*******Executor Add Test 4:*******\n\n\033[0m");

    executor = ExecutorCreate("exec", CLOCK_MONOTONIC);

    printf("Executor Create Func Test: ");

    CHECK_FUNC(NULL != executor);

    printf("\nExpected: SUCCESS - executor != NULL\n");

    printf("\nExecutor Add Func Test:\n\n");

    for (i = 0;i < 2;++i)
    {
        status = ExecutorAddTask(executor, NULL, NULL, 5000);

        printf("Add number %ld check (status): ", i + 1);

        CHECK_FUNC(FAILED == status);
    }

    printf("\nExpected: 2 SUCCESS - Add status is FAILED, taskAction is NULL\n");

    ExecutorDestroy(executor);
}

void ExecutorAddTest5(void)
{
    Executor_t *executor = NULL;
    int status;
    size_t i;

    printf("\033[1;34m\n*******Executor Add Test 5:*******\n\n\033[0m");

    executor = ExecutorCreate("exec", CLOCK_MONOTONIC);

    printf("Executor Create Func Test: ");

    CHECK_FUNC(NULL != executor);

    printf("\nExpected: SUCCESS - executor != NULL\n");

    printf("\nExecutor Add Func Test:\n\n");

    for (i = 0;i < 2;++i)
    {
        status = ExecutorAddTask(executor, PrintCounter, NULL, 0);

        printf("Add number %ld check (status): ", i + 1);

        CHECK_FUNC(FAILED == status);
    }

    printf("\nExpected: 2 SUCCESS - Add status is FAILED, periodTimeInMSec is zero\n");

    ExecutorDestroy(executor);
}

void ExecutorRunTest1(void)
{
    Executor_t *executor = NULL;
    size_t indexTask1 = 1, indexTask2 = 2, indexTask3 = 3, indexTask4 = 4, indexTask5 = 5;
    size_t countNumOfExecuteFunc = 0;
    int status;

    printf("\033[1;34m\n*******Executor Run Test 1:*******\n\n\033[0m");

    executor = ExecutorCreate("exec", CLOCK_MONOTONIC);

    printf("Executor Create Func Test: ");

    CHECK_FUNC(NULL != executor);

    printf("\nExpected: SUCCESS - executor != NULL\n");

    printf("\nExecutor Add Func Test:\n\n");

    status = ExecutorAddTask(executor, PrintCounter, &indexTask1, 10000);

    printf("Add number 1 check (status): ");

    CHECK_FUNC(SUCCEEDED == status);

    status = ExecutorAddTask(executor, PrintCounter, &indexTask2, 30000);

    printf("Add number 2 check (status): ");

    CHECK_FUNC(SUCCEEDED == status);
    
    status = ExecutorAddTask(executor, PrintCounter, &indexTask3, 20000);

    printf("Add number 3 check (status): ");

    CHECK_FUNC(SUCCEEDED == status);

    status = ExecutorAddTask(executor, PrintCounter, &indexTask4, 45000);

    printf("Add number 4 check (status): ");

    CHECK_FUNC(SUCCEEDED == status);

    status = ExecutorAddTask(executor, PrintCounter, &indexTask5, 35000);

    printf("Add number 5 check (status): ");

    CHECK_FUNC(SUCCEEDED == status);

    printf("\nExpected: 5 SUCCESS - Add status is SUCCEEDED\n");

    printf("\nExecutor Run Func Test:\n\n");

    countNumOfExecuteFunc = ExecutorRun(executor);

    printf("\nExecutor Count Number Of Execute Functions Test: ");

    CHECK_FUNC((size_t)(MAX_FUNC_INVOKED + 5) == countNumOfExecuteFunc);

    printf("\nExpected: 1 SUCCESS - countNumOfExecuteFunc is 15\n");

    ExecutorDestroy(executor);
}

void ExecutorRunTest2(void)
{
    Executor_t *executor = NULL;

    printf("\033[1;34m\n*******Executor Run Test 2:*******\n\n\033[0m");

    printf("Executor Run Func Test: ");

    CHECK_FUNC(INT_MAX == ExecutorRun(executor));

    printf("\nExpected: 1 SUCCESS - countNumOfExecuteFunc is INT_MAX, executor is NULL\n");

    ExecutorDestroy(executor);
}

void ExecutorPauseTest(void)
{
    Executor_t *executor = NULL;
    size_t indexTask1 = 1, indexTask2 = 2, indexTask3 = 3, indexTask4 = 4, indexTask5 = 5;
    size_t countNumOfExecuteFunc = 0, countRemainFuncToExecute = 0;
    PauseTaskS_t pauseTaskS;
    int status;

    g_tasksCounter = 0;

    printf("\033[1;34m\n*******Executor Pause Test:*******\n\n\033[0m");

    executor = ExecutorCreate("exec", CLOCK_MONOTONIC);

    printf("Executor Create Func Test: ");

    CHECK_FUNC(NULL != executor);

    printf("\nExpected: SUCCESS - executor != NULL\n");

    printf("\nExecutor Add Func Test:\n\n");

    status = ExecutorAddTask(executor, PrintCounter, &indexTask1, 10000);

    printf("Add number 1 check (status): ");

    CHECK_FUNC(SUCCEEDED == status);

    status = ExecutorAddTask(executor, PrintCounter, &indexTask2, 30000);

    printf("Add number 2 check (status): ");

    CHECK_FUNC(SUCCEEDED == status);
    
    status = ExecutorAddTask(executor, PrintCounter, &indexTask3, 20000);

    printf("Add number 3 check (status): ");

    CHECK_FUNC(SUCCEEDED == status);

    status = ExecutorAddTask(executor, PrintCounter, &indexTask4, 45000);

    printf("Add number 4 check (status): ");

    CHECK_FUNC(SUCCEEDED == status);

    status = ExecutorAddTask(executor, PrintCounter, &indexTask5, 35000);

    printf("Add number 5 check (status): ");

    CHECK_FUNC(SUCCEEDED == status);

    pauseTaskS.m_executor = executor;
    pauseTaskS.m_remainTaskToExecute = &countRemainFuncToExecute;

    status = ExecutorAddTask(executor, PauseTask, (void*)&pauseTaskS, 60000);

    printf("Add number 6 check (status): ");

    CHECK_FUNC(SUCCEEDED == status);

    printf("\nExpected: 6 SUCCESS - Add status is SUCCEEDED\n");

    printf("\nExecutor Run Func Test:\n\n");

    countNumOfExecuteFunc = ExecutorRun(executor);

    printf("\nExecutor Count Number Of Execute Functions Test: ");

    CHECK_FUNC(13 == countNumOfExecuteFunc);

    printf("\nExpected: 1 SUCCESS - countNumOfExecuteFunc is 13\n");

    printf("\nExecutor Pause Func Test: ");

    CHECK_FUNC(3 == countRemainFuncToExecute);

    printf("\nExpected: 1 SUCCESS - countRemainFuncToExecute is 4\n");

    ExecutorDestroy(executor);
}

int main(void)
{
    ExecutorCreateTest1();
    ExecutorCreateTest2();
    ExecutorCreateTest3();

    ExecutorAddTest1();
    ExecutorAddTest2();
    ExecutorAddTest3();
    ExecutorAddTest4();
    ExecutorAddTest5();

    ExecutorRunTest1();
    ExecutorRunTest2();

    ExecutorPauseTest();

    return 0;
}