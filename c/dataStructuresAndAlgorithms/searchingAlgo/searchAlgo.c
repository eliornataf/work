#include <stdio.h> /* printf, rand */
#include <time.h> /* clock */

#define ARR_SIZE (1000000)
#define NUM_LIMIT (100000)
#define IS_NOT_FOUND (0)
#define IS_FOUND (1)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

/************************************************************/

int SimpleSearchAlgoFindNum(int *_arr, size_t _arrSize, int _numToSearch)
{
    size_t i;

    if (!_arr)
    {
        return IS_NOT_FOUND;
    }

    for (i = 0;i < _arrSize;++i)
    {
        if (_arr[i] == _numToSearch)
        {
            return IS_FOUND;
        }
    }

    return IS_NOT_FOUND;
}

int AdvanceSearchAlgoFindNum(int *_arr, size_t _arrSize, int _numToSearch)
{
    size_t maxArrIndex = _arrSize -1;
    size_t i;

    if (!_arr)
    {
        return IS_NOT_FOUND;
    }

    if (_arr[maxArrIndex] == _numToSearch)
    {
        return IS_FOUND;
    }
    else
    {
        _arr[maxArrIndex] = _numToSearch;
    }

    for (i = 0;_arr[i] != _numToSearch;++i)
    {
        /* empty for */
    }

    return ((i == maxArrIndex) ? IS_NOT_FOUND : IS_FOUND);
}

int main(void)
{
    int simpleAlgoArr[ARR_SIZE];
    int advanceAlgoArr[ARR_SIZE];
    clock_t benchmark_begin, benchmark_end;
	double time_spent;
    int status;
    size_t i;

	for (i = 0;i < ARR_SIZE;++i)
	{
        int randNUM = rand() % NUM_LIMIT;
		simpleAlgoArr[i] = randNUM;
        advanceAlgoArr[i] = randNUM;
	}

    printf("\nSimple Search Algo Func Test: ");
	
	benchmark_begin = clock();
	
	status = SimpleSearchAlgoFindNum(simpleAlgoArr, ARR_SIZE, 10);
	
	benchmark_end = clock();
	
	CHECK_FUNC(status);
	
	printf("\nExpected: 1 SUCCESS (check status)\n");
	
	time_spent = (double)(benchmark_end - benchmark_begin) / CLOCKS_PER_SEC;
	
	printf("\033[1;33m\nSimple Search Algo Sort benchmark: %f\n\033[0m", time_spent);

    printf("\nAdvance Search Algo Func Test: ");
	
	benchmark_begin = clock();
	
	status = AdvanceSearchAlgoFindNum(simpleAlgoArr, ARR_SIZE, 10);
	
	benchmark_end = clock();
	
	CHECK_FUNC(status);
	
	printf("\nExpected: 1 SUCCESS (check status)\n");
	
	time_spent = (double)(benchmark_end - benchmark_begin) / CLOCKS_PER_SEC;
	
	printf("\033[1;33m\nAdvance Search Algo Sort benchmark: %f\n\033[0m", time_spent);

    return 0;
}