#include <stdio.h> /* printf */
#include "array_by_pointer.h" /* array_by_pointer header */

/*****************************************************************************/

void AllocateArrayElements(int *_arr, int _arrSize)
{
	int i;

	for (i = 0;i < _arrSize;++i)
	{
		*(_arr + i) = rand() % 100;
	}
}

void PrintArrayElements(int *_arr, int _arrSize)
{
	int i;
	
	for (i = 0;i < _arrSize;++i)
	{
		printf("%d | ", *(_arr + i));
	}
}

/*****************************************************************************/

void MostOccurElementInArrayTest(int *_arr, int _arrSize)
{
	int mostOccurElement;
	int status = ARRAY_INPUT_OK;
	
	mostOccurElement = MostOccurElementInArray(_arr, _arrSize, &status);
	
	if (status == ARRAY_IS_NULL)
	{
		printf("Array is NULL\n");
		return;
	}
	
	if (status == ARRAY_INPUT_SIZE_ERROR)
	{
		printf("Array input size error\n");
		return;
	}
	
	printf("The most occurring element in the array is: %d\n", mostOccurElement);
}

void SortElementsByEvenAndOddsTest(int *_arr, int _arrSize)
{
	int numEvenElements;
	int status = ARRAY_INPUT_OK;

	numEvenElements = SortElementsByEvenAndOdds(_arr, _arrSize, &status);
	
	if (status == ARRAY_IS_NULL)
	{
		printf("Array is NULL\n");
		return;
	}
	
	if (status == ARRAY_INPUT_SIZE_ERROR)
	{
		printf("Array input size error\n");
		return;
	}
	
	printf("The array after the sorted:\n\n");
	
	PrintArrayElements(_arr, _arrSize);
	
	printf("\n\nThe number of even numbers is: %d\n", numEvenElements);
}

void SortArrayElementsWithBubbleSortTest(int *_arr, int _arrSize)
{
	int returnValue;
	
	returnValue = SortArrayElementsWithBubbleSort(_arr, _arrSize);
	
	if (returnValue == ARRAY_IS_NULL)
	{
		printf("Array is NULL\n");
		return;
	}
	
	if (returnValue == ARRAY_INPUT_SIZE_ERROR)
	{
		printf("Array input size error\n");
		return;
	}
	
	printf("The array after the sorted:\n\n");
	
	PrintArrayElements(_arr, _arrSize);
	
	putchar('\n');
}

void SearchInArrayElementsWithBinarySearchTest(int *_arr, int _arrSize
																, int _numToSearch)
{
	int returnValue;

	returnValue = SearchInArrayElementsWithBinarySearch(_arr, _arrSize, _numToSearch);
	
	if (returnValue == ARRAY_IS_NULL)
	{
		printf("Array is NULL\n");
		return;
	}
	
	if (returnValue == ARRAY_INPUT_SIZE_ERROR)
	{
		printf("Array input size error\n");
		return;
	}
	
	if (returnValue == NUM_IS_FOUND)
	{
		printf("%d is found in the array\n", _numToSearch);
	}
	else
	{
		printf("%d is not found in the array\n", _numToSearch);
	}
}

int main(void)
{
	int arr[15];
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	int numToSearch = rand() % 100;
	
	AllocateArrayElements(arr, arrSize);
	
	printf("\033[1;31mPrintArrayElements:\n\n\033[0m");
	PrintArrayElements(arr, arrSize);


	printf("\033[1;31m\n\nMostOccurElementInArray:\n\n\033[0m");
	MostOccurElementInArrayTest(arr, arrSize);
	
	printf("\033[1;31m\nSortElementsByEvenAndOdds:\n\n\033[0m");
	SortElementsByEvenAndOddsTest(arr, arrSize);
	
	printf("\033[1;31m\nSortArrayElementsWithBubbleSort:\n\n\033[0m");
	SortArrayElementsWithBubbleSortTest(arr, arrSize);
	
	printf("\033[1;31m\nSearchInArrayElementsWithBinarySearchTest:\n\n\033[0m");
	SearchInArrayElementsWithBinarySearchTest(arr, arrSize, numToSearch);
	
	return 0;
}
