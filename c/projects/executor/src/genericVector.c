#include <stdlib.h> /* malloc, realloc, free */
#include "genericVector.h" /* Generic Vector Header */

#define INIT_VALUE (0)

struct Vector
{
	void **m_arrOfElements;
	size_t m_currCapacity;
	size_t m_initialCapacity;
	size_t m_incBlockSize;
	size_t m_capacityAfter1Increase;
	size_t m_capacityAfter2Increase;
	size_t m_numOfElements;
};

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static void DestroyVectorElements(void **_arrOfElements, size_t _vectorNumOfElements, void (*_elementDestroy)(void *_item));
static VectorResult_t IncreaseVectorCapacity(Vector_t *_vector);
static void ReduceVectorCapacity(Vector_t *_vector);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

Vector_t *VectorCreate(size_t _initialCapacity, size_t _incBlockSize)
{
    Vector_t *vector = NULL;
	
	if (!_initialCapacity && !_incBlockSize)
	{
		return NULL;
	}
	
	vector = (Vector_t*)malloc(sizeof(Vector_t));
	if (!vector)
	{
		return NULL;
	}
	
	vector->m_arrOfElements = (void**)malloc(_initialCapacity * sizeof(void*));
	if (!vector->m_arrOfElements)
	{
		free(vector);
		return NULL;
	}
	
	vector->m_currCapacity = _initialCapacity;
	vector->m_initialCapacity = _initialCapacity;
	vector->m_incBlockSize = _incBlockSize;
	vector->m_capacityAfter1Increase = _initialCapacity + _incBlockSize; 
	vector->m_capacityAfter2Increase = _initialCapacity + (_incBlockSize * 2); 
	vector->m_numOfElements = INIT_VALUE;
	
	return vector;
}

void VectorDestroy(Vector_t **_vector, void (*_elementDestroy)(void *_item))
{
    if (!_vector || !*_vector)
	{
		return;
	}

    if (_elementDestroy)
    {
        DestroyVectorElements((*_vector)->m_arrOfElements, (*_vector)->m_numOfElements, _elementDestroy);
    }

    free((*_vector)->m_arrOfElements);
    (*_vector)->m_arrOfElements = NULL;

    free(*_vector);
    *_vector = NULL;
}

VectorResult_t VectorAppend(Vector_t *_vector, void *_item)
{
    VectorResult_t status;

	if (!_vector || !_item)
	{
		return VECTOR_POINTER_NOT_INITIALIZE;
	}

    if (_vector->m_currCapacity == _vector->m_numOfElements)
    {
        status = IncreaseVectorCapacity(_vector);
        if (VECTOR_SUCCESS != status)
        {
            return status;
        }
    }

	_vector->m_arrOfElements[_vector->m_numOfElements++] = _item;

	return VECTOR_SUCCESS;
}

VectorResult_t VectorRemove(Vector_t *_vector, void **_pItem)
{
    if (!_vector || !_pItem)
	{
		return VECTOR_POINTER_NOT_INITIALIZE;
	}

    if (!_vector->m_numOfElements)
	{
		return VECTOR_UNDERFLOW;
	}

    if (_vector->m_capacityAfter2Increase <= _vector->m_currCapacity
			&& _vector->m_numOfElements <= _vector->m_initialCapacity)
	{
		ReduceVectorCapacity(_vector);
	}

	*_pItem = _vector->m_arrOfElements[--_vector->m_numOfElements];
	
	return VECTOR_SUCCESS;
}

VectorResult_t VectorGet(const Vector_t *_vector, size_t _index, void **_pItem)
{
    if (!_vector || !_pItem)
	{
		return VECTOR_POINTER_NOT_INITIALIZE;
	}
	
	if (_vector->m_numOfElements <= _index)
	{
		return VECTOR_WRONG_INDEX;
	}
	
	*_pItem = _vector->m_arrOfElements[_index];
	
	return VECTOR_SUCCESS;
}

VectorResult_t VectorSet(Vector_t *_vector, size_t _index, void *_value)
{
    if (!_vector || !_value)
	{
		return VECTOR_POINTER_NOT_INITIALIZE;
	}
	
	if (_vector->m_numOfElements <= _index)
	{
		return VECTOR_WRONG_INDEX;
	}
	
	_vector->m_arrOfElements[_index] = _value;
	
	return VECTOR_SUCCESS;
}

size_t VectorSize(const Vector_t *_vector)
{
    if (!_vector)
	{
		return POINTER_NOT_INITIALIZE_VECTOR_SIZE;
	}

    return _vector->m_numOfElements;
}

size_t VectorCapacity(const Vector_t *_vector)
{
    if (!_vector)
	{
		return POINTER_NOT_INITIALIZE_VECTOR_CAPACITY;
	}

    return _vector->m_currCapacity;
}

size_t VectorForEach(const Vector_t *_vector, VectorElementAction_t _action, void* _context)
{
    void *currElementData = NULL;
    size_t i;
    
    if (!_vector || !_action)
	{
		return POINTER_NOT_INITIALIZE_VECTOR_FOR_EACH;
	}

    if (!_vector->m_numOfElements)
	{
		return UNDERFLOW_VECTOR_FOR_EACH;
	}

    for (i = 0;i < _vector->m_numOfElements;++i)
    {
        VectorGet(_vector, i, &currElementData);

        if (!_action(currElementData, i, _context))
        {
            break;
        }
    }

    return i;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static void DestroyVectorElements(void **_arrOfElements, size_t _vectorNumOfElements, void (*_elementDestroy)(void *_item))
{
    size_t i;

    for (i = 0;i < _vectorNumOfElements;++i)
    {
        _elementDestroy(_arrOfElements[i]);
    }
}

static VectorResult_t IncreaseVectorCapacity(Vector_t *_vector)
{
    void *tempPointerForRealloc = NULL;

	if (!_vector->m_incBlockSize)
	{
		return VECTOR_OVERFLOW;
	}
		
	tempPointerForRealloc = realloc(_vector->m_arrOfElements, (_vector->m_currCapacity + _vector->m_incBlockSize) * sizeof(void*));
	if (!tempPointerForRealloc)
	{
		return VECTOR_REALLOCATION_FAILED;
	}
		
	_vector->m_arrOfElements = tempPointerForRealloc;
	_vector->m_currCapacity += _vector->m_incBlockSize;

    return VECTOR_SUCCESS;
}

static void ReduceVectorCapacity(Vector_t *_vector)
{
    void *tempPointerForRealloc = NULL;

    tempPointerForRealloc = realloc(_vector->m_arrOfElements, _vector->m_capacityAfter1Increase * sizeof(void*));
	if (!tempPointerForRealloc)
	{
		return;
	}
		
	_vector->m_arrOfElements = tempPointerForRealloc;
	_vector->m_currCapacity = _vector->m_capacityAfter1Increase;
}