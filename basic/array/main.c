#include <stdio.h> /* printf */
#include "array.h" /* array header */

void MostOccurElementInArrayTest(int _arr[], int _arrSize)
{
	int mostOccurElement;
	int status = ARRAY_INPUT_OK;
	
	mostOccurElement = MostOccurElementInArray(_arr, _arrSize, &status);
	
	if (status == ARRAY_INPUT_SIZE_ERROR)
	{
		printf("Array input size error\n");
		return;
	}
	
	printf("The most occurring element in the array is: %d\n", mostOccurElement);
}

void SortElementsByEvenAndOddsTest(int _arr[], int _arrSize)
{
	int numEvenElements, i;
	int status = ARRAY_INPUT_OK;

	numEvenElements = SortElementsByEvenAndOdds(_arr, _arrSize, &status);
	
	if (status == ARRAY_INPUT_SIZE_ERROR)
	{
		printf("Array input size error\n");
		return;
	}
	
	printf("The array after the sorted:\n");
	
	for (i = 0;i < _arrSize;++i)
	{
		printf("%d | ", _arr[i]);
	}
	
	printf("\n\nThe number of even numbers is: %d\n", numEvenElements);
}

void SortArrayElementsWithBubbleSortTest(int _arr[], int _arrSize)
{
	int i, returnValue;
	
	returnValue = SortArrayElementsWithBubbleSort(_arr, _arrSize);
	
	if (returnValue == ARRAY_INPUT_SIZE_ERROR)
	{
		printf("Array input size error\n");
		return;
	}
	
	printf("The array after the sorted:\n");
	
	for (i = 0;i < _arrSize;++i)
	{
		printf("%d | ", _arr[i]);
	}
	
	putchar('\n');
}

int main(void)
{
	int arr[] = {8, 6, 3, 2, 2, 7, 9, 1, 1, 4, 5};
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	printf("MostOccurElementInArray:\n\n");
	MostOccurElementInArrayTest(arr, arrSize);
	
	printf("\nSortElementsByEvenAndOdds:\n\n");
	SortElementsByEvenAndOddsTest(arr, arrSize);
	
	printf("\nSortArrayElementsWithBubbleSort:\n\n");
	SortArrayElementsWithBubbleSortTest(arr, arrSize);
	
	return 0;
}
