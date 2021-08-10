#include <assert.h> /* assert */
#include <stdlib.h> /* malloc, realloc */
#include "dynamic_allocation.h" /* dynamic_allocation header */

int *DynamicArrayCreate(int _arrayCapacity)
{
	int *dynamicArrayPtr;

	assert(MIN_ARRAY_CAPACITY <= _arrayCapacity);
	
	dynamicArrayPtr = (int*)malloc(_arrayCapacity * sizeof(int));
	
	return dynamicArrayPtr;
}

void DynamicArrayDestroy(int *_dynamicArrayPtr)
{
	assert(NULL != _dynamicArrayPtr);
	
	free(_dynamicArrayPtr);
}

int DynamicArrayInsert(int **_dynamicArrayPtr, int _inputData, int *_arrayCapacity,
											int *_numOfElements, int _incBlockSize)
{
	int *tempPointerForRealloc = NULL;
	
	if (NULL == _dynamicArrayPtr || NULL == *_dynamicArrayPtr)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	if (*_arrayCapacity < MIN_ARRAY_CAPACITY)
	{
		return ARRAY_CAPACITY_ERROR;
	}
	
	if (*_arrayCapacity == *_numOfElements)
	{	
		if (!_incBlockSize)
		{
			return ARRAY_CAPACITY_FULL;
		}
		
		tempPointerForRealloc = realloc(*_dynamicArrayPtr, (*_arrayCapacity + _incBlockSize) * sizeof(int));
		if (NULL == tempPointerForRealloc)
		{
			return REALLOC_FAILED;
		}
		
		*_dynamicArrayPtr = tempPointerForRealloc;
		
		*_arrayCapacity += _incBlockSize;
	}
		
	*(*_dynamicArrayPtr + *_numOfElements) = _inputData;
	++*_numOfElements;
	
	return INSERT_SUCCESS;
} 

int DynamicArrayDelete(int *_dynamicArrayPtr, int *_outputData, int *_numOfElements)
{
	if (NULL == _dynamicArrayPtr)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	if (*_arrayCapacity < MIN_ARRAY_CAPACITY)
	{
		return ARRAY_CAPACITY_ERROR;
	}
	
	if (!*_numOfElements)
	{
		return ARRAY_IS_EMPTY;
	}
	
	--*_numOfElements;
	
	*_outputData = *(_dynamicArrayPtr + *_numOfElements);

	return DELETE_SUCCESS;
}
