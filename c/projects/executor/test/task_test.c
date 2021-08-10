#define _XOPEN_SOURCE 600
#include <limits.h> /* MAX_INT */
#include <stdio.h> /* printf */
#include <stdlib.h> /* rand */
#include <time.h> /* clock_t */
#include "task.h" /* Task Header */

#define CONTINUE_RUN (0)
#define DONT_SWAP (0)
#define SWAP (1)

#define SEC_TO_MS_SEC(time) (time * 1000)
#define NANO_SEC_TO_MS_SEC(time) (time / 1000000)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))


/*************************************************************/

static int PrintRandNum(void *context)
{
    (void)context;

    printf("The rand num is: %d\n", rand());

    return CONTINUE_RUN;
}

/*************************************************************/

void CreateTaskTest1(void)
{
    Task_t *task = NULL;

    printf("\033[1;34m\n*******Create Task Test 1:*******\n\n\033[0m");

    task = CreateTask(PrintRandNum, NULL, 5000);

    printf("Create Task Func Test: ");

    CHECK_FUNC(NULL != task);

    printf("\nExpected: SUCCESS - task != NULL\n");

    DestroyTask(task);
}

void CreateTaskTest2(void)
{
    Task_t *task = NULL;

    printf("\033[1;34m\n*******Create Task Test 2:*******\n\n\033[0m");

    task = CreateTask(NULL, NULL, 5000);

    printf("Create Task Func Test: ");

    CHECK_FUNC(NULL == task);

    printf("\nExpected: SUCCESS - task == NULL, taskAction is NULL\n");
}

void CreateTaskTest3(void)
{
    Task_t *task = NULL;

    printf("\033[1;34m\n*******Create Task Test 3:*******\n\n\033[0m");

    task = CreateTask(PrintRandNum, NULL, 0);

    printf("Create Task Func Test: ");

    CHECK_FUNC(NULL == task);

    printf("\nExpected: SUCCESS - task == NULL, periodTimeInMSec is zero\n");
}

void FirstTaskExecuteTimeTest(void)
{
    struct timespec currTime;
    Task_t *task = NULL;
    size_t nowTime;

    printf("\033[1;34m\n*******First Task Execute Time Test:*******\n\n\033[0m");

    task = CreateTask(PrintRandNum, NULL, 5000);

    printf("Create Task Func Test: ");

    CHECK_FUNC(NULL != task);

    printf("\nExpected: SUCCESS - task != NULL\n");

    clock_gettime(CLOCK_MONOTONIC, &currTime);

    nowTime = SEC_TO_MS_SEC(currTime.tv_sec) + NANO_SEC_TO_MS_SEC(currTime.tv_nsec);

    printf("\nFirst Task Execute Time Func Test: ");

    FirstTaskExecuteTime(task, CLOCK_MONOTONIC);    

    CHECK_FUNC(nowTime + 5000 == GetTaskExecuteTime(task));

    printf("\nExpected: SUCCESS - nowTime + periodTimeInMSec is task execute time\n");

    DestroyTask(task);
}

void ExecuteTaskTest1(void)
{
    Task_t *task = NULL;

    printf("\033[1;34m\n*******Execute Task Test 1:*******\n\n\033[0m");

    task = CreateTask(PrintRandNum, NULL, 5000);

    printf("Create Task Func Test: ");

    CHECK_FUNC(NULL != task);

    printf("\nExpected: SUCCESS - task != NULL\n");

    printf("\nExecute Task Func Test:\n\n");

    ExecuteTask(task);

    printf("\nExpected: SUCCESS - print rand number\n");

    DestroyTask(task);
}

void ExecuteTaskTest2(void)
{
    Task_t *task = NULL;

    printf("\033[1;34m\n*******Execute Task Test 2:*******\n\n\033[0m");

    printf("Execute Task Func Test: ");

    CHECK_FUNC(INT_MAX == ExecuteTask(task));

    printf("\nExpected: SUCCESS - task is null, return INT_MAX\n");
}

void UpdateTaskExecuteTimeTest(void)
{
    struct timespec currTime;
    Task_t *task = NULL;
    size_t nowTime;

    printf("\033[1;34m\n*******Update Task Execute Time Test:*******\n\n\033[0m");

    task = CreateTask(PrintRandNum, NULL, 5000);

    printf("Create Task Func Test: ");

    CHECK_FUNC(NULL != task);

    printf("\nExpected: SUCCESS - task != NULL\n");

    clock_gettime(CLOCK_MONOTONIC, &currTime);

    nowTime = SEC_TO_MS_SEC(currTime.tv_sec) + NANO_SEC_TO_MS_SEC(currTime.tv_nsec);

    printf("\nUpdate Task Execute Time Func Test: ");

    FirstTaskExecuteTime(task, CLOCK_MONOTONIC);    

    UpdateTaskExecuteTime(task);

    CHECK_FUNC(nowTime + 5000 * 2 == GetTaskExecuteTime(task));

    printf("\nExpected: SUCCESS - nowTime + periodTimeInMSec * 2 is task execute time\n");

    DestroyTask(task);
}

void GetTaskExecuteTimeTest1(void)
{
    struct timespec currTime;
    Task_t *task = NULL;
    size_t nowTime;

    printf("\033[1;34m\n*******Get Task Execute Time Test 1:*******\n\n\033[0m");

    task = CreateTask(PrintRandNum, NULL, 5000);

    printf("Create Task Func Test: ");

    CHECK_FUNC(NULL != task);

    printf("\nExpected: SUCCESS - task != NULL\n");

    clock_gettime(CLOCK_MONOTONIC, &currTime);

    nowTime = SEC_TO_MS_SEC(currTime.tv_sec) + NANO_SEC_TO_MS_SEC(currTime.tv_nsec);

    printf("\nGet Task Execute Time Func Test: ");

    FirstTaskExecuteTime(task, CLOCK_MONOTONIC);    

    UpdateTaskExecuteTime(task);

    CHECK_FUNC(nowTime + 5000 * 2 == GetTaskExecuteTime(task));

    printf("\nExpected: SUCCESS - nowTime + periodTimeInMSec * 2 is task execute time\n");

    DestroyTask(task);
}

void GetTaskExecuteTimeTest2(void)
{
    Task_t *task = NULL;

    printf("\033[1;34m\n*******Get Task Execute Time Test 2:*******\n\n\033[0m");

    printf("Get Task Execute Time Func Test: ");

    CHECK_FUNC(INT_MAX == GetTaskExecuteTime(task));

    printf("\nExpected: SUCCESS - task is NULL, return INT_MAX\n");
}

void CompareTasksTest1(void)
{
    Task_t *task1 = NULL;
    Task_t *task2 = NULL;

    printf("\033[1;34m\n*******Compare Tasks Test 1:*******\n\n\033[0m");

    task1 = CreateTask(PrintRandNum, NULL, 1000);
    task2 = CreateTask(PrintRandNum, NULL, 2000);

    printf("Create Task Func Test 1: ");

    CHECK_FUNC(NULL != task1);

    printf("Create Task Func Test 2: ");

    CHECK_FUNC(NULL != task1);

    printf("\nExpected: 2 SUCCESS - task1 && task2 != NULL\n");

    UpdateTaskExecuteTime(task1);
    UpdateTaskExecuteTime(task2);

    printf("\nCompare Tasks Func Test: ");

    CHECK_FUNC(DONT_SWAP == CompareTasks(task1, task2));

    printf("\nExpected: SUCCESS - task1 is smaller, dont swap\n");

    DestroyTask(task1);
    DestroyTask(task2);
}

void CompareTasksTest2(void)
{
    Task_t *task1 = NULL;
    Task_t *task2 = NULL;

    printf("\033[1;34m\n*******Compare Tasks Test 2:*******\n\n\033[0m");

    task1 = CreateTask(PrintRandNum, NULL, 2000);
    task2 = CreateTask(PrintRandNum, NULL, 1000);

    printf("Create Task Func Test 1: ");

    CHECK_FUNC(NULL != task1);

    printf("Create Task Func Test 2: ");

    CHECK_FUNC(NULL != task1);

    printf("\nExpected: 2 SUCCESS - task1 && task2 != NULL\n");

    UpdateTaskExecuteTime(task1);
    UpdateTaskExecuteTime(task2);

    printf("\nCompare Tasks Func Test: ");

    CHECK_FUNC(SWAP == CompareTasks(task1, task2));

    printf("\nExpected: SUCCESS - task2 is smaller, swap\n");

    DestroyTask(task1);
    DestroyTask(task2);
}

void CompareTasksTest3(void)
{
    Task_t *task1 = NULL;
    Task_t *task2 = NULL;

    printf("\033[1;34m\n*******Compare Tasks Test 3:*******\n\n\033[0m");

    task1 = CreateTask(PrintRandNum, NULL, 2000);

    printf("Create Task Func Test 1: ");

    CHECK_FUNC(NULL != task1);

    printf("\nExpected: 1 SUCCESS - task1 != NULL\n");

    UpdateTaskExecuteTime(task1);

    printf("\nCompare Tasks Func Test: ");

    CHECK_FUNC(INT_MAX == CompareTasks(task1, task2));

    printf("\nExpected: SUCCESS - task2 is NULL, return INT_MAX\n");

    DestroyTask(task1);
}

void CompareTasksTest4(void)
{
    Task_t *task1 = NULL;
    Task_t *task2 = NULL;

    printf("\033[1;34m\n*******Compare Tasks Test 4:*******\n\n\033[0m");

    task2 = CreateTask(PrintRandNum, NULL, 2000);

    printf("Create Task Func Test 1: ");

    CHECK_FUNC(NULL != task2);

    printf("\nExpected: 1 SUCCESS - task2 != NULL\n");

    UpdateTaskExecuteTime(task2);

    printf("\nCompare Tasks Func Test: ");

    CHECK_FUNC(INT_MAX == CompareTasks(task1, task2));

    printf("\nExpected: SUCCESS - task1 is NULL, return INT_MAX\n");

    DestroyTask(task2);
}

int main(void)
{
    CreateTaskTest1();
    CreateTaskTest2();
    CreateTaskTest3();

    FirstTaskExecuteTimeTest();

    ExecuteTaskTest1();
    ExecuteTaskTest2();

    UpdateTaskExecuteTimeTest();

    GetTaskExecuteTimeTest1();
    GetTaskExecuteTimeTest2();

    CompareTasksTest1();
    CompareTasksTest2();
    CompareTasksTest3();
    CompareTasksTest4();

    return 0;
}