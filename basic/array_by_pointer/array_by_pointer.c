#include <stdio.h> /* printf, putchar */
#include "array_by_pointer.h" /* array_by_pointer header */

#define MOVE_ELEMENT_RIGHT (1)
#define MOVE_ELEMENT_LEFT (-1)

/*****************************************************************************/

void SwapArrayElements(int *_arr, int _index, int swapDirection)
{
	int tempElement = *(_arr +_index);
	*(_arr + _index) = *(_arr + _index + swapDirection);
	*(_arr + _index + swapDirection) = tempElement;
}

/*****************************************************************************/

int MostOccurElementInArray(int *_arr, int _arrSize, int *status)
{
	int countOccurIter, mostOccurElement, i, j;
	int maxNumOccur = 0;
	
	if (NULL == _arr)
	{
		*status = ARRAY_IS_NULL;
		return ARRAY_IS_NULL;
	}
	
	if (_arrSize < 1)
	{
		*status = ARRAY_INPUT_SIZE_ERROR;
		return ARRAY_INPUT_SIZE_ERROR;
	}
	
	for (i = 0;i < _arrSize;++i)
	{
		countOccurIter = 0;
		
		for (j = i;j < _arrSize;++j)
		{
			if (*(_arr + i) == *(_arr + j))
			{
				++countOccurIter;
			}
		}
		
		if (maxNumOccur < countOccurIter)
		{
			maxNumOccur = countOccurIter;
			mostOccurElement = *(_arr + i);
		}
	}
	
	return mostOccurElement;
}

int SortElementsByEvenAndOdds(int *_arr, int _arrSize, int *status)
{
	int i, j;
	int numEvenElements = 0;
	
	if (NULL == _arr)
	{
		*status = ARRAY_IS_NULL;
		return ARRAY_IS_NULL;
	}
	
	if (_arrSize < 1)
	{
		*status = ARRAY_INPUT_SIZE_ERROR;
		return ARRAY_INPUT_SIZE_ERROR;
	}
	
	for (i = 0;i < _arrSize;++i)
	{
		if (*(_arr + i) % 2 == 0)
		{
			++numEvenElements;
		
			for (j = i;0 < j && (*(_arr + j - 1) % 2 != 0) ;--j)
			{
				SwapArrayElements(_arr, j, MOVE_ELEMENT_LEFT);
			}
		}
	}
	
	return numEvenElements;
}

int SortArrayElementsWithBubbleSort(int *_arr, int _arrSize)
{
	int i, j;
	
	if (NULL == _arr)
	{
		return ARRAY_IS_NULL;
	}
	
	if (_arrSize < 1)
	{
		return ARRAY_INPUT_SIZE_ERROR;
	}
	
	for (i = 0;i < _arrSize;++i)
	{
		for (j = 0;j < _arrSize;++j)
		{
			if (*(_arr + j + 1) < *(_arr + j))
			{
				SwapArrayElements(_arr, j, MOVE_ELEMENT_RIGHT);
			}
		}
	}
	
	return ARRAY_IS_SORTED;
}

int SearchInArrayElementsWithBinarySearch(int *_arr, int _arrSize, int _numToSearch)
{
	int left_index = 0; 
	int right_index = _arrSize - 1;
	
	if (NULL == _arr)
	{
		return ARRAY_IS_NULL;
	}
	
	if (_arrSize < 1)
	{
		return ARRAY_INPUT_SIZE_ERROR;
	}
	
	while (left_index <= right_index)
	{
		int middle_index = left_index + (right_index - left_index) / 2;
	
		if (*(_arr + middle_index) == _numToSearch)
		{
			return NUM_IS_FOUND;
		}
		else if (*(_arr + middle_index) < _numToSearch)
		{
			left_index = middle_index + 1;
		}
		else
		{
			right_index = middle_index - 1;
		}
	}
	
	return NUM_IS_NOT_FOUND;	
}
