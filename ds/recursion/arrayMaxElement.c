#include <limits.h> /* INT_MAX */
#include <stdio.h> /* printf */

#define POINTER_IS_NOT_INITIALIZE (INT_MAX)
#define ARRAY_IS_EMPTY (INT_MAX)

int ArrayMaxElementRecu(int *arr, size_t arrSize, int maxElement)
{	
	if (!arrSize)
	{
		return maxElement;
	}
	
	maxElement = (maxElement < arr[arrSize - 1]) ? arr[arrSize - 1] : maxElement;
	
	return ArrayMaxElementRecu(arr, arrSize - 1, maxElement);
}

int ArrayMaxElement(int *arr, size_t arrSize)
{
	int maxElement;
 
	if (!arr)
	{
		return POINTER_IS_NOT_INITIALIZE;
	}
	
	if (!arrSize)
	{
		return ARRAY_IS_EMPTY;
	}
	
	maxElement = arr[arrSize - 1];
	
	return ArrayMaxElementRecu(arr, arrSize - 1, maxElement);
}

int main(void)
{
	int arrTest[] = {2, 6, 4, 3, 1, 0, 5};
	size_t arrSize = sizeof(arrTest) / sizeof(arrTest[0]);

	printf("The max elements is: %d\n", ArrayMaxElement(arrTest, arrSize));

	return 0;
}
