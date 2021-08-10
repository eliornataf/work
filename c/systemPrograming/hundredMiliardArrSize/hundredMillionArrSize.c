#include <stdio.h> /* printf, rand */
#include <stdlib.h> /* malloc, free */
#include <time.h> /* clock */

#define HUNDRED_MILLION (100000000)

typedef enum Status
{
    SUCCESS = 0,
    FAILURE = 1
} Status_t;

void SetAscendingOrderElementsToArr(int *_arrWithAscendingOrderElements)
{
    size_t i;

    for (i = 0;i < HUNDRED_MILLION;++i)
    {
        _arrWithAscendingOrderElements[i] = i;
    }
}

void SetRandElementsToArr(int *_arrWithRandElements)
{
    size_t i;

    for (i = 0;i < HUNDRED_MILLION;++i)
    {
        _arrWithRandElements[i] = rand();
    }
}

int main(void)
{
    int *arrWithAscendingOrderElements = NULL;
    int *arrWithRandElements = NULL;
    clock_t benchmark_begin, benchmark_end;
	double time_spent;

    arrWithAscendingOrderElements = (int*)malloc(HUNDRED_MILLION * sizeof(int));
    if (!arrWithAscendingOrderElements)
    {
        return FAILURE;
    }

    arrWithRandElements = (int*)malloc(HUNDRED_MILLION * sizeof(int));
    if (!arrWithRandElements)
    {
        free(arrWithAscendingOrderElements);
        return FAILURE;
    }
	
	benchmark_begin = clock();
	
	SetAscendingOrderElementsToArr(arrWithAscendingOrderElements);
	
	benchmark_end = clock();
		
	time_spent = (double)(benchmark_end - benchmark_begin) / CLOCKS_PER_SEC;
	
	printf("\033[1;32mSet Ascending Order Elements To Arr benchmark: %f\n\033[0m", time_spent);

    benchmark_begin = clock();
	
	SetRandElementsToArr(arrWithRandElements);
	
	benchmark_end = clock();
		
	time_spent = (double)(benchmark_end - benchmark_begin) / CLOCKS_PER_SEC;
	
	printf("\033[1;33mSet Rand Elements To Arr benchmark: %f\n\033[0m", time_spent);

    free(arrWithAscendingOrderElements);
    free(arrWithRandElements);

    return SUCCESS;
}
