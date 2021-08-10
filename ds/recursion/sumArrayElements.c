#include <stdio.h> /* printf */

#define POINTER_IS_NOT_INITIALIZE (-1)

sumArrayElementsRecu(int *arr, size_t arrSize)
{
	if (!arrSize)
	{
		return 0;
	}
	
	return arr[arrSize - 1] + sumArrayElementsRecu(arr, arrSize - 1);
}

int sumArrayElements(int *arr, size_t arrSize)
{
	if (!arr)
	{
		return POINTER_IS_NOT_INITIALIZE;
	}
	
	sumArrayElementsRecu(arr, arrSize);
}

int main(void)
{
	int arrTest[] = {0, 1, 2, 3, 4, 5, 6};
	size_t arrSize = sizeof(arrTest) / sizeof(arrTest[0]);

	printf("Sum of the array elements is: %d\n", sumArrayElements(arrTest, arrSize));

	return 0;
}
