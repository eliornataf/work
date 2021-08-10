#include <stdio.h> /* printf */

int main(void)
{
	int i;
	int sum = 0;
	int arr[] = {2, 4, 6, 8, 10, 12, 14};
	int arrSize = sizeof(arr) / sizeof(arr[0]); 
	
	for (i = 0;i < arrSize;++i)
	{
		sum += arr[i];
	}
	
	printf("Average of array element is: %d\n", sum / arrSize);

	return 0;	
}

