#include <stdlib.h> /* malloc, realloc, free */
#include <stdio.h> /* printf */
#include "dynamicVector.h" /* Dynamic Vector header */

/******************************************************/

struct DynamicVector
{
	int *m_vector;
	size_t m_capacity;
	size_t m_OriginalCapacity;
	size_t m_incBlockSize;
	size_t m_capacityAfter1Increase;
	size_t m_capacityAfter2Increase;
	size_t m_numOfElements;
};

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

Vector_t *VectorCreate(size_t _capacity, size_t _incBlockSize)
{
	Vector_t *vector = NULL;
	
	if (!_capacity && !_incBlockSize)
	{
		return NULL;
	}
	
	vector = (Vector_t*)malloc(sizeof(Vector_t));
	if (!vector)
	{
		return NULL;
	}
	
	vector->m_vector = (int*)malloc(_capacity * sizeof(int));
	if (!vector->m_vector)
	{
		free(vector);
		return NULL;
	}
	
	vector->m_capacity = _capacity;
	vector->m_OriginalCapacity = _capacity;
	vector->m_incBlockSize = _incBlockSize;
	vector->m_capacityAfter1Increase = _capacity + _incBlockSize; 
	vector->m_capacityAfter2Increase = _capacity + (_incBlockSize * 2); 
	vector->m_numOfElements = 0;
	
	return vector;
}

void VectorDestroy(Vector_t *_vector)
{
	if (!_vector)
	{
		return;
	}
	
	free(_vector->m_vector);
	free(_vector);
}

ADTError_t VectorPush(Vector_t *_vector, int _inputData)
{
	int *tempPointerForRealloc = NULL;
	
	if (!_vector)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	if (_vector->m_capacity == _vector->m_numOfElements)
	{	
		if (!_vector->m_incBlockSize)
		{
			return OVERFLOW;
		}
		
		tempPointerForRealloc = realloc(_vector->m_vector, (_vector->m_capacity + _vector->m_incBlockSize) * sizeof(int));
		if (!tempPointerForRealloc)
		{
			return REALLOCATION_FAILED;
		}
		
		_vector->m_vector = tempPointerForRealloc;
		
		_vector->m_capacity += _vector->m_incBlockSize;
	}
	
	*(_vector->m_vector + _vector->m_numOfElements) = _inputData;
	++_vector->m_numOfElements;
	
	return OK;
}

ADTError_t VectorPop(Vector_t *_vector, int *_outputData)
{
	int *tempPointerForRealloc = NULL;

	if (!_vector || !_outputData)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	if (!_vector->m_numOfElements)
	{
		return UNDERFLOW;
	}
	
	if (_vector->m_capacityAfter2Increase <= _vector->m_capacity
			&& _vector->m_numOfElements <= _vector->m_OriginalCapacity)
	{
		tempPointerForRealloc = realloc(_vector->m_vector, _vector->m_capacityAfter1Increase * sizeof(int));
		if (!tempPointerForRealloc)
		{
			return REALLOCATION_FAILED;
		}
		
		_vector->m_vector = tempPointerForRealloc;
		
		_vector->m_capacity = _vector->m_capacityAfter1Increase;
	}
	
	--_vector->m_numOfElements;
	
	*_outputData = *(_vector->m_vector + _vector->m_numOfElements);

	return OK;
}

ADTError_t VectorGetElement(Vector_t *_vector, size_t _index, int *_outputData)
{
	if (!_vector || !_outputData)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	if (_vector->m_numOfElements <= _index)
	{
		return WRONG_INDEX;
	}
	
	*_outputData = *(_vector->m_vector + _index);
	
	return OK;
}

ADTError_t VectorSetElement(Vector_t *_vector, size_t _index, int _inputData)
{
	if (!_vector)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	if (_vector->m_numOfElements <= _index)
	{
		return WRONG_INDEX;
	}
	
	*(_vector->m_vector + _index) = _inputData;
	
	return OK;
}

ADTError_t VectorNumOfElements(Vector_t *_vector, size_t *_numOfElements)
{
	if (!_vector || !_numOfElements)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	*_numOfElements = _vector->m_numOfElements;
	
	return OK;
}

void VectorPrint(Vector_t *_vector)
{
	size_t i;

	if (!_vector)
	{
		return;
	}
	
	for (i = 0;i < _vector->m_numOfElements;++i)
	{
		printf("%d | ", _vector->m_vector[i]);
	}
	
	printf("\n\nvector Capacity: %lu\n", _vector->m_capacity);
	printf("vector original capacity: %lu\n", _vector->m_OriginalCapacity);
	printf("vector increase block size: %lu\n", _vector->m_incBlockSize);
	printf("vector capacity after 1 increase: %lu\n", _vector->m_capacityAfter1Increase);
	printf("vector capacity after 2 increase: %lu\n", _vector->m_capacityAfter2Increase);
	printf("vector number of elements: %lu\n", _vector->m_numOfElements);
}

/*****************************************************************************/
