#include <stdio.h> /* printf, putchar, rand */
#include "genericBubbleSort.h" /* Generic Bubble Sort Header */

#define ARR_SIZE (10)
#define ARRAY_ELEMENT_SIZE_LIMIT (10)

/*****************************************************************************/

static void setArrayElement(int *_arr, size_t _arrSize)
{
	size_t i;
	
	for (i = 0;i < _arrSize;++i)
	{
		_arr[i] = rand() % ARRAY_ELEMENT_SIZE_LIMIT;
	}
}

static void printArray(int *_arr, size_t _arrSize)
{
	size_t i;
	
	for (i = 0;i < _arrSize;++i)
	{
		printf("%d | ", _arr[i]);
	}
}

/*****************************************************************************/

static int Small2Big(const void *_firstElement, const void *_secondElement)
{
	return ( *(int*)_secondElement < *(int*)_firstElement);
}

static int Big2Small(const void *_firstElement, const void *_secondElement)
{
	return (*(int*)_firstElement < *(int*)_secondElement);
}

static int OddFirstEvenLast(const void *_firstElement, const void *_secondElement)
{
	return ( (!(*(int*)_firstElement % 2)) && (*(int*)_secondElement % 2) );
}

static int Num0First(const void *_firstElement, const void *_secondElement)
{
	return ( (*(int*)_firstElement) && (!*(int*)_secondElement) );
}

/*****************************************************************************/

static void Small2BigTest(void)
{
	int arr[ARR_SIZE];

    printf("\033[1;34m\n*******Small 2 Big Test:*******\n\033[0m");

	setArrayElement(arr, ARR_SIZE);

    printf("\033[1;33m\nThe array before sort:\n\n\033[0m");
	
	printArray(arr, ARR_SIZE);
		
	if (FAILURE == GenericBubbleSort(arr, ARR_SIZE, sizeof(int), Small2Big))
    {
        printf("\033[1;31m\n*******The sort is failed*******\n\n\033[0m");
        return;
    }

    printf("\033[1;32m\n\nThe array after Small2Big sort:\n\n\033[0m");

    printArray(arr, ARR_SIZE);

    putchar('\n');
}

static void Big2SmallTest(void)
{
	int arr[ARR_SIZE];

    printf("\033[1;34m\n*******Big 2 Small Test:*******\n\033[0m");

	setArrayElement(arr, ARR_SIZE);

    printf("\033[1;33m\nThe array before sort:\n\n\033[0m");
	
	printArray(arr, ARR_SIZE);
		
	if (FAILURE == GenericBubbleSort(arr, ARR_SIZE, sizeof(int), Big2Small))
    {
        printf("\033[1;31m\n*******The sort is failed*******\n\n\033[0m");
        return;
    }

    printf("\033[1;32m\n\nThe array after Big2Small sort:\n\n\033[0m");

    printArray(arr, ARR_SIZE);

    putchar('\n');
} 

static void OddFirstEvenLastTest(void)
{
	int arr[ARR_SIZE];

    printf("\033[1;34m\n*******Odd First Even Last Test:*******\n\033[0m");

	setArrayElement(arr, ARR_SIZE);

    printf("\033[1;33m\nThe array before sort:\n\n\033[0m");
	
	printArray(arr, ARR_SIZE);
		
	if (FAILURE == GenericBubbleSort(arr, ARR_SIZE, sizeof(int), OddFirstEvenLast))
    {
        printf("\033[1;31m\n*******The sort is failed*******\n\n\033[0m");
        return;
    }

    printf("\033[1;32m\n\nThe array after OddFirstEvenLast sort:\n\n\033[0m");

    printArray(arr, ARR_SIZE);

    putchar('\n');
} 

static void Num0FirstTest(void)
{
	int arr[ARR_SIZE];

    printf("\033[1;34m\n*******Num 0 First Test:*******\n\033[0m");

	setArrayElement(arr, ARR_SIZE);

    printf("\033[1;33m\nThe array before sort:\n\n\033[0m");
	
	printArray(arr, ARR_SIZE);
		
	if (FAILURE == GenericBubbleSort(arr, ARR_SIZE, sizeof(int), Num0First))
    {
        printf("\033[1;31m\n*******The sort is failed*******\n\n\033[0m");
        return;
    }

    printf("\033[1;32m\n\nThe array after Num0FirstTest sort:\n\n\033[0m");

    printArray(arr, ARR_SIZE);

    putchar('\n');
    putchar('\n');
} 

int main(void)
{
    Small2BigTest();

    Big2SmallTest();

    OddFirstEvenLastTest();

    Num0FirstTest();

	return SUCCESS;
}
