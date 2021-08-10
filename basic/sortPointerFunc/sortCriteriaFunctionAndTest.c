#include <stdio.h> /* printf, putchar, rand */
#include "bubbleSort.h" /* Bubble Sort Header */

#define ARR_SIZE (30)
#define ARRAY_ELEMENT_SIZE_LIMIT (10)

/*****************************************************************************/

static void setArrayElement(int *_arr, size_t _arrSize)
{
	size_t i;
	
	if (NULL == _arr)
	{
		return;
	}
	
	for (i = 0;i < _arrSize;++i)
	{
		_arr[i] = rand() % ARRAY_ELEMENT_SIZE_LIMIT;
	}
}

static void printArray(int *_arr, size_t _arrSize)
{
	size_t i;
	
	if (NULL == _arr)
	{
		return;
	}
	
	for (i = 0;i < _arrSize;++i)
	{
		printf("%d | ", _arr[i]);
	}
}

/*****************************************************************************/

static int Small2Big(int _firstElement, int _secondElement)
{
	return (_firstElement > _secondElement);
}

static int Big2Small(int _firstElement, int _secondElement)
{
	return (_secondElement > _firstElement);
}

static int OddFirstEvenLast(int _firstElement, int _secondElement)
{
	return ( (!(_firstElement % 2)) && (_secondElement % 2) );
}

static int Num0First(int _firstElement, int _secondElement)
{
	return ( (_firstElement) && (!_secondElement) );
}

/*****************************************************************************/

int main(void)
{
	int arr[ARR_SIZE];
	int status = SUCCESS;
	
	setArrayElement(arr, ARR_SIZE);
	
	printf("The array before sort:\n\n");
	
	printArray(arr, ARR_SIZE);
	
	printf("\n\nThe array after Small2Big sort:\n\n");
	
	status = BubbleSort(arr, ARR_SIZE, Small2Big);
	if (FAILURE == status)
	{
		return FAILURE;
	}
	
	printArray(arr, ARR_SIZE);
	
	printf("\n\nThe array after Big2Small sort:\n\n");
	
	status = BubbleSort(arr, ARR_SIZE, Big2Small);
	if (FAILURE == status)
	{
		return FAILURE;
	}
	
	printArray(arr, ARR_SIZE);
	
	printf("\n\nThe array after OddFirstEvenLast sort:\n\n");
	
	status = BubbleSort(arr, ARR_SIZE, OddFirstEvenLast);
	if (FAILURE == status)
	{
		return FAILURE;
	}
	
	printArray(arr, ARR_SIZE);
	
	printf("\n\nThe array after Num0First sort:\n\n");
	
	status = BubbleSort(arr, ARR_SIZE, Num0First);
	if (FAILURE == status)
	{
		return FAILURE;
	}
	
	printArray(arr, ARR_SIZE);
	
	putchar('\n');
	
	return SUCCESS;
}
