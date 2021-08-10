#define _XOPEN_SOURCE 600
#include <limits.h> /* MAX_INT */
#include <stdio.h> /* printf */
#include <time.h> /* clock_t */
#include <unistd.h> /* sleep */
#include "timeFunc.h" /* Time Header */

#define SEC_TO_MS_SEC(time) (time * 1000)
#define DONT_SWAP (0)
#define SWAP (1)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

void GetFirstExecuteTimeTest1(void)
{
    size_t firstTaskExecTime, secondTaskExecuteTime;
    
    printf("\033[1;34m\n*******Get First Execute Time Test 1:*******\n\n\033[0m");

    firstTaskExecTime =  GetFirstExecuteTime(CLOCK_MONOTONIC, 1000);

    sleep(5);

    secondTaskExecuteTime = GetFirstExecuteTime(CLOCK_MONOTONIC, 1000);

    printf("Get First Execute Time Func Test: ");

    CHECK_FUNC(SEC_TO_MS_SEC(5) == secondTaskExecuteTime - firstTaskExecTime);

    printf("\nExpected: SUCCESS - Check difference between two execute time (using 5 sec sleep)\n");
}

void GetFirstExecuteTimeTest2(void)
{
    printf("\033[1;34m\n*******Get First Execute Time Test 2:*******\n\n\033[0m");

    printf("Get First Execute Time Func Test: ");

    CHECK_FUNC(INT_MAX == GetFirstExecuteTime(CLOCK_MONOTONIC, 0));

    printf("\nExpected: SUCCESS - periodTimeInMSec is zero, return INT_MAX\n");
}

void GetFirstExecuteTimeTest3(void)
{
    printf("\033[1;34m\n*******Get First Execute Time Test 3:*******\n\n\033[0m");

    printf("Get First Execute Time Func Test: ");

    CHECK_FUNC(INT_MAX == GetFirstExecuteTime(88, 1000));

    printf("\nExpected: SUCCESS - clockID invalid input, return INT_MAX\n");
}

void GetCompareBetweenTaskExecuteTimeTest1(void)
{
    size_t firstTaskExecTime, secondTaskExecuteTime;

    printf("\033[1;34m\n*******Get Compare Between Task Execute Time Test 1:*******\n\n\033[0m");

    firstTaskExecTime =  GetFirstExecuteTime(CLOCK_MONOTONIC, 1000);

    secondTaskExecuteTime = GetFirstExecuteTime(CLOCK_MONOTONIC, 5000);

    printf("Get First Execute Time Func Test: ");

    CHECK_FUNC(DONT_SWAP == GetCompareBetweenTaskExecuteTime(firstTaskExecTime, secondTaskExecuteTime));

    printf("\nExpected: SUCCESS - task1 is bigger, do not swap\n");
}

void GetCompareBetweenTaskExecuteTimeTest2(void)
{
    size_t firstTaskExecTime, secondTaskExecuteTime;

    printf("\033[1;34m\n*******Get Compare Between Task Execute Time Test 2:*******\n\n\033[0m");

    firstTaskExecTime =  GetFirstExecuteTime(CLOCK_MONOTONIC, 5000);

    secondTaskExecuteTime = GetFirstExecuteTime(CLOCK_MONOTONIC, 1000);

    printf("Get First Execute Time Func Test: ");

    CHECK_FUNC(SWAP == GetCompareBetweenTaskExecuteTime(firstTaskExecTime, secondTaskExecuteTime));

    printf("\nExpected: SUCCESS - task2 is bigger, swap\n");
}

void GetCompareBetweenTaskExecuteTimeTest3(void)
{
    size_t secondTaskExecuteTime;

    printf("\033[1;34m\n*******Get Compare Between Task Execute Time Test 3:*******\n\n\033[0m");

    secondTaskExecuteTime = GetFirstExecuteTime(CLOCK_MONOTONIC, 5000);

    printf("Get First Execute Time Func Test: ");

    CHECK_FUNC(INT_MAX == GetCompareBetweenTaskExecuteTime(0, secondTaskExecuteTime));

    printf("\nExpected: SUCCESS - firstTaskExecTime is zero return INT_MAX\n");
}

void GetCompareBetweenTaskExecuteTimeTest4(void)
{
    size_t firstTaskExecTime;

    printf("\033[1;34m\n*******Get Compare Between Task Execute Time Test 4:*******\n\n\033[0m");

    firstTaskExecTime = GetFirstExecuteTime(CLOCK_MONOTONIC, 5000);

    printf("Get First Execute Time Func Test: ");

    CHECK_FUNC(INT_MAX == GetCompareBetweenTaskExecuteTime(firstTaskExecTime, 0));

    printf("\nExpected: SUCCESS - secondTaskExecuteTime is zero return INT_MAX\n");
}

void SleepTaskBeforeExecuteTest1(void)
{
    size_t firstTaskExecTime, benchmark_begin, benchmark_end, time_spent;
    struct timespec currTime;
    
    printf("\033[1;34m\n*******Sleep Task Before Execute Test 1:*******\n\n\033[0m");

    firstTaskExecTime =  GetFirstExecuteTime(CLOCK_REALTIME, 5000);

    clock_gettime(CLOCK_REALTIME, &currTime);

    benchmark_begin = currTime.tv_sec;

    SleepTaskBeforeExecute(firstTaskExecTime, CLOCK_REALTIME);

    clock_gettime(CLOCK_REALTIME, &currTime);

    benchmark_end = currTime.tv_sec;

    time_spent = benchmark_end - benchmark_begin;

    printf("\033[1;33mSleep Task Before Execute benchmark: %ld\n\033[0m", time_spent);

    printf("\nExpected: SUCCESS - benchmark is 5 sec\n");
}

void SleepTaskBeforeExecuteTest2(void)
{
    size_t benchmark_begin, benchmark_end, time_spent;
    struct timespec currTime;
    
    printf("\033[1;34m\n*******Sleep Task Before Execute Test 2:*******\n\n\033[0m");

    clock_gettime(CLOCK_REALTIME, &currTime);

    benchmark_begin = currTime.tv_sec;

    SleepTaskBeforeExecute(0, CLOCK_REALTIME);

    clock_gettime(CLOCK_REALTIME, &currTime);

    benchmark_end = currTime.tv_sec;

    time_spent = benchmark_end - benchmark_begin;

    printf("\033[1;33mSleep Task Before Execute benchmark: %ld\n\033[0m", time_spent);

    printf("\nExpected: SUCCESS - benchmark is zero sec, taskExecuteTime is zero\n");
}

void SleepTaskBeforeExecuteTest3(void)
{
    size_t benchmark_begin, benchmark_end, time_spent;
    struct timespec currTime;
    
    printf("\033[1;34m\n*******Sleep Task Before Execute Test 3:*******\n\n\033[0m");

    clock_gettime(CLOCK_REALTIME, &currTime);

    benchmark_begin = currTime.tv_sec;

    SleepTaskBeforeExecute(SEC_TO_MS_SEC(currTime.tv_sec) + 50000, 88);

    clock_gettime(CLOCK_REALTIME, &currTime);

    benchmark_end = currTime.tv_sec;

    time_spent = benchmark_end - benchmark_begin;

    printf("\033[1;33mSleep Task Before Execute benchmark: %ld\n\033[0m", time_spent);

    printf("\nExpected: SUCCESS - benchmark is zero sec, clockID invalid input\n");
}

int main(void)
{
    GetFirstExecuteTimeTest1();
    GetFirstExecuteTimeTest2();
    GetFirstExecuteTimeTest3();

    GetCompareBetweenTaskExecuteTimeTest1();
    GetCompareBetweenTaskExecuteTimeTest2();
    GetCompareBetweenTaskExecuteTimeTest3();
    GetCompareBetweenTaskExecuteTimeTest4();

    SleepTaskBeforeExecuteTest1();
    SleepTaskBeforeExecuteTest2();
    SleepTaskBeforeExecuteTest3();

    return 0;
}