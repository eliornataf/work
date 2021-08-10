#include <stdio.h> /* printf, rand */
#include <time.h> /* clock */

#define ARR_SIZE (50000)

#define SWAP(data1, data2, type) {type temp = data1; data1 = data2; data2 = temp;}

/*****************************************************************************/

static void setArrayElement(int *_arr, size_t _arrSize)
{
	int i;
	
	if (NULL == _arr)
	{
		return;
	}
	
	for (i = 0;i < _arrSize;++i)
	{
		_arr[i] = rand() % ARR_SIZE;
	}
}

static void printArray(int *_arr, size_t _arrSize)
{
	int i;
	
	if (NULL == _arr)
	{
		return;
	}
	
	for (i = 0;i < _arrSize;++i)
	{
		printf("%d | ", _arr[i]);
	}
}

static void Swap(int *_data1, int *_data2)
{
	int temp;
	
	if (NULL == _data1 || NULL == _data2)
	{
		return;
	}
	
	temp = *_data1;
	*_data1 = *_data2;
	*_data2 = temp;
}

/*****************************************************************************/

void SortArrayElementsWithBubbleSortSwapFunc(int *_arr, size_t _arrSize)
{
	register int i, j;
	
	if (NULL == _arr)
	{
		return;
	}
	
	for (i = 0;i < _arrSize - 1;++i)
	{
		for (j = 0;j < _arrSize - 1;++j)
		{
			if (_arr[j + 1] < _arr[j])
			{
				Swap(&_arr[j + 1], &_arr[j]);
			}
		}
	}
} 

void SortArrayElementsWithBubbleSortSwapMacro(int *_arr, size_t _arrSize)
{
	register int i, j;
	
	if (NULL == _arr)
	{
		return;
	}
	
	for (i = 0;i < _arrSize - 1;++i)
	{
		for (j = 0;j < _arrSize - 1;++j)
		{
			if (_arr[j + 1] < _arr[j])
			{
				SWAP(_arr[j + 1], _arr[j], int);
			}
		}
	}
} 

/*****************************************************************************/

int main(void)
{
	int funcArr[ARR_SIZE], macroArr[ARR_SIZE];
	clock_t benchmark_begin, benchmark_end;
	double time_spent;
		
	setArrayElement(funcArr, ARR_SIZE);
	setArrayElement(macroArr, ARR_SIZE);
	
	benchmark_begin = clock();
	
	SortArrayElementsWithBubbleSortSwapFunc(funcArr, ARR_SIZE);
	
	benchmark_end = clock();
	
	time_spent = (double)(benchmark_end - benchmark_begin) / CLOCKS_PER_SEC;

	printf("Func Arr benchmark: %f", time_spent);
	
	benchmark_begin = clock();
	
	SortArrayElementsWithBubbleSortSwapFunc(macroArr, ARR_SIZE);
	
	benchmark_end = clock();
	
	time_spent = (double)(benchmark_end - benchmark_begin) / CLOCKS_PER_SEC;
	
	printf("\n\nMacro Arr benchmark: %f\n", time_spent);
	
	return 0;
}
