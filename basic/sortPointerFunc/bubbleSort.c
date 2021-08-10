#include "bubbleSort.h" /* Bubble Sort Header */

/*****************************************************************************/

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

int BubbleSort(int *_arr, size_t _arrSize, SortCriteria_t _sortCriteria)
{
	size_t i, j;
	
	if (NULL == _arr)
	{
		return FAILURE;
	}
	
	for (i = 0;i < _arrSize - 1;++i)
	{
		for (j = 0;j < _arrSize - 1;++j)
		{
			if ( (*_sortCriteria)(_arr[j], _arr[j + 1]) )
			{
				Swap(&_arr[j], &_arr[j + 1]);
			}
		}
	}
	
	return SUCCESS;
}





