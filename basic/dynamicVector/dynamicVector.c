#include <assert.h> /* assert */
#include <stdlib.h> /* malloc, realloc */
#include "dynamicVector.h" /* Dynamic Vector header */

#define NUM_OF_ELEMENTS_INIT 0

/*****************************************************************************/

struct DynamicVector
{
	int *array;
	int arrayCapacity;
	int incBlockSize;
	int numOfElements;
};

/*****************************************************************************/

dynamic_t *DynamicVectorCreate(int _arrayCapacity, int _incBlockSize)
{
	dynamic_t *DynamicVector = (dynamic_t*)malloc(sizeof(dynamic_t));
	if (NULL == DynamicVector)
	{
		return NULL;
	}
	
	assert(MIN_ARRAY_CAPACITY <= _arrayCapacity);
	
	DynamicVector->array = (int*)malloc(_arrayCapacity * sizeof(int));
	if (NULL == DynamicVector->array)
	{
		free(DynamicVector);
		return NULL;
	}
	
	DynamicVector->arrayCapacity = _arrayCapacity;
	DynamicVector->incBlockSize = _incBlockSize;
	DynamicVector->numOfElements = NUM_OF_ELEMENTS_INIT;
	
	return DynamicVector;
}

void DynamicVectorDestroy(dynamic_t *_DynamicVector)
{
	assert(NULL != _DynamicVector);
	assert(NULL != _DynamicVector->array);
	
	free(_DynamicVector->array);
	_DynamicVector->array = NULL;
	
	free(_DynamicVector);
}

int DynamicVectorInsert(dynamic_t *_DynamicVector, int _inputData)
{
	int *tempPointerForRealloc = NULL;
	
	if (NULL == _DynamicVector || NULL == _DynamicVector->array)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	if (_DynamicVector->arrayCapacity < MIN_ARRAY_CAPACITY)
	{
		return ARRAY_CAPACITY_ERROR;
	}
	
	if (_DynamicVector->arrayCapacity == _DynamicVector->numOfElements)
	{	
		if (!_DynamicVector->incBlockSize)
		{
			return ARRAY_CAPACITY_FULL;
		}
		
		tempPointerForRealloc = realloc(_DynamicVector->array, (_DynamicVector->arrayCapacity + 												_DynamicVector->incBlockSize) * sizeof(int));
		if (NULL == tempPointerForRealloc)
		{
			return REALLOC_FAILED;
		}
		
		_DynamicVector->array = tempPointerForRealloc;
		
		_DynamicVector->arrayCapacity += _DynamicVector->incBlockSize;
	}
	
	*(_DynamicVector->array + _DynamicVector->numOfElements) = _inputData;
	++_DynamicVector->numOfElements;
	
	return INSERT_SUCCESS;
}

int DynamicVectorDelete(dynamic_t *_DynamicVector, int *_outputData)
{
	if (NULL == _DynamicVector || NULL == _DynamicVector->array)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	if (_DynamicVector->arrayCapacity < MIN_ARRAY_CAPACITY)
	{
		return ARRAY_CAPACITY_ERROR;
	}
	
	if (!_DynamicVector->numOfElements)
	{
		return ARRAY_IS_EMPTY;
	}
	
	--_DynamicVector->numOfElements;
	
	*_outputData = *(_DynamicVector->array + _DynamicVector->numOfElements);

	return DELETE_SUCCESS;
}
