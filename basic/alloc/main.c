#include <stdio.h> /* printf */
#include "dynamic_allocation.h" /* dynamic_allocation header */

void DynamicAllocationTest(void)
{
	int arrayCapacity = 10;
	int *dynamicArrayPtr = NULL;
	int inputData = 0;
	int numOfElements = 0;
	int incBlockSize = 5;
	int i, ouptputData, status;
	
	dynamicArrayPtr = DynamicArrayCreate(arrayCapacity);
	if (NULL == dynamicArrayPtr)
	{
		printf("Allocated failed\n");
		return;
	}
	
	printf("**********Insert Test:**********\n\n");
	
	for (i = 0;i < 17;++i)
	{
		status = DynamicArrayInsert(&dynamicArrayPtr, inputData + i, &arrayCapacity,
										 			&numOfElements, incBlockSize);
		
		if (POINTER_NOT_INITIALIZE == status)
		{
			printf("Pointer not initialize\n");
			return;
		}
		else if (ARRAY_CAPACITY_ERROR == status)
		{
			printf("Array Capacity Error\n");
			return;
		}
		else if (ARRAY_CAPACITY_FULL == status)
		{
			printf("Array capacity is full, resize not possible\n");
			return;
		} 
		else if (REALLOC_FAILED == status)
		{
			printf("Resize failed\n");
			return;
		}
	}

	printf("arrayCapacity = %d [expected: arrayCapacity = 17]\nnumOfElements = %d [expected: arrayCapacity = 20]\n\n", arrayCapacity, numOfElements);
	
	printf("**********Delete Test:**********\n\n");
	
	for (i = 0;i < 13;++i)
	{
		status = DynamicArrayDelete(dynamicArrayPtr, &ouptputData, &numOfElements);
		
		if (POINTER_NOT_INITIALIZE == status)
		{
			printf("Pointer not initialize\n");
			return;
		}
		else if (ARRAY_CAPACITY_ERROR == status)
		{
			printf("Array Capacity Error\n");
			return;
		}
		else if (ARRAY_IS_EMPTY == status)
		{
			printf("the array is empty, delete is not possible\n");
			return;
		}
		
		printf("numOfElements = %d\touptputData = %d\n", numOfElements, ouptputData);
	}

	DynamicArrayDestroy(dynamicArrayPtr);
}

int main(void)
{
	DynamicAllocationTest();
	
	return 0;
}
