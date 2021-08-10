#include <stdio.h> /* printf, putchar */

#define ARRAY_IS_SORTED (0)
#define ARRAY_INPUT_SIZE_ERROR (1)

/****************************************************************************/

void PrintArrayElements(int *_arr, int _arrSize)
{
	int i;
	
	for (i = 0;i < _arrSize;++i)
	{
		printf("%d | ", *(_arr + i));
	}
}

void SwapArrayElements(int *_arr, int _index)
{
	int tempElement = _arr[_index];
	_arr[_index] = _arr[_index - 1];
	_arr[_index - 1] = tempElement;
}

/****************************************************************************/

int SortArrayElementsByZerosAndOnes(int *_arr, int _arrSize)
{
	int i, j;

	if (_arrSize < 1)
	{
		return ARRAY_INPUT_SIZE_ERROR;
	}
	
	for (i = 0;i < _arrSize;++i)
	{
		if (_arr[i] == 0)
		{
			for (j = i;0 < j && (_arr[j - 1] == 1) ;--j)
			{
				SwapArrayElements(_arr, j);
			}
		}
	}
	
	return ARRAY_IS_SORTED;
}


int main(void)
{
	int arr[] = {0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0};	
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	int status;
	
	printf("The Array Before sort:\n\n");
	
	PrintArrayElements(arr, arrSize);
	
	status = SortArrayElementsByZerosAndOnes(arr, arrSize);
	
	if (ARRAY_INPUT_SIZE_ERROR == status)
	{
		printf("Array input size error:\n\n");
	}
	
	printf("\n\nThe Array after sort:\n\n");
	
	PrintArrayElements(arr, arrSize);
	
	putchar('\n');
	
	return 0;
}
