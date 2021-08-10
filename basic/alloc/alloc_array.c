#include <stdio.h> /* printf, putchar */
#include <stdlib.h> /* malloc */

#define SUCCESS 0
#define FAILURE 1

/****************************************************************************/

void PrintArrayElements(int *_arr, size_t _arrSize)
{
	size_t i;
	
	for (i = 0;i < _arrSize;++i)
	{
		printf("%d | ", *(_arr + i));
	}
}

/****************************************************************************/

int main(void)
{
	int *arr = NULL; 
	size_t arrSize, i;
	
	printf("Please enter array size:\n");
	scanf("%d", &arrSize);
	
	arr = (int*)malloc(arrSize * sizeof(int));
	if (NULL == arr)
	{
		printf("Array alloc failure [array is NULL]\n");
		return FAILURE;
	}
	
	printf("Please enter the array elements [one by one]: ");
	
	for (i = 0;i < arrSize;++i)
	{
		scanf("%d", &arr[i]);
	}
	
	printf("\nArray elements value:\n\n");
	
	PrintArrayElements(arr, arrSize);
	
	putchar('\n');
	
	free(arr);
	
	return SUCCESS;
}
