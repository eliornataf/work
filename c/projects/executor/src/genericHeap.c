#include <stdlib.h> /* malloc, free */
#include "genericVector.h" /* Generic Vector Header */
#include "genericHeap.h" /* Generic Heap Header */

/******************************************************/

struct Heap
{
	Vector_t *m_vector;
	size_t m_heapSize;
    ComparatorFunc_t m_compareFunc;
};

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static size_t ParentIndex(size_t childIndex);
static size_t LeftChildIndex(size_t parentIndex);
static size_t RightChildIndex(size_t parentIndex);
static void GetElementsDataAux(Heap_t *heap, size_t firstIndex, void **firstIndexElement, size_t secondIndex, void **secondIndexElement);
static void SetElementsDataAux(Heap_t *heap, size_t firstIndex, void *firstIndexElement, size_t secondIndex, void *secondIndexElement);
static void Heapify(Heap_t *heap, size_t parentIndex);
static void BubbleUp(Heap_t *heap, size_t newElementIndex);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

Heap_t *HeapBuild(Vector_t *_vector, ComparatorFunc_t _compareFunc)
{
	Heap_t *heap = NULL;
	int i;
	
	if (!_vector || !_compareFunc)
	{
		return NULL;
	}
	
	heap = (Heap_t*)malloc(sizeof(Heap_t));
	if (!heap)
	{			
		return NULL;
	}
	
	heap->m_vector = _vector;
    heap->m_compareFunc = _compareFunc;
	heap->m_heapSize = VectorSize(heap->m_vector);
	
	for (i = ParentIndex(heap->m_heapSize - 1);0 <= i;--i)
	{
		Heapify(heap, (size_t)i);
	}
	
	return heap;
}

Vector_t *HeapDestroy(Heap_t **_heap)
{
	Vector_t *heapVector = NULL;

    if (!_heap || !*_heap)
    {
        return NULL;
    }

	heapVector = (*_heap)->m_vector;

    free(*_heap);
	*_heap = NULL;

	return heapVector;
}

HeapResult_t HeapInsert(Heap_t *_heap, void *_element)
{
	VectorResult_t status;

	if (!_heap)
	{
		return HEAP_POINTER_NOT_INITIALIZE;
	}

	status = VectorAppend(_heap->m_vector, _element);
	if (VECTOR_SUCCESS != status)
	{
		return VECTOR_ERROR;
	}

	BubbleUp(_heap, _heap->m_heapSize++);

	return HEAP_SUCCESS;
}

const void *HeapPeek(const Heap_t *_heap)
{
	void *maxElement = NULL;

	if (!_heap)
	{
		return NULL;
	}

	if (!_heap->m_heapSize)
	{
		return NULL;
	}

	VectorGet(_heap->m_vector, 0, &maxElement);

	return maxElement;
}

void *HeapExtractMax(Heap_t *_heap)
{
	void *firstElement = NULL;
	void *lastElement = NULL;
	void *maxElement = NULL;
	VectorResult_t status;

	if (!_heap)
	{
		return NULL;
	}

	if (!_heap->m_heapSize)
	{
		return NULL;
	}

	GetElementsDataAux(_heap, 0, &firstElement, _heap->m_heapSize - 1, &lastElement);
	SetElementsDataAux(_heap, 0, lastElement, _heap->m_heapSize - 1, firstElement);

	status = VectorRemove(_heap->m_vector, &maxElement);
	if (VECTOR_SUCCESS != status)
	{
		return NULL;
	}

	--_heap->m_heapSize;

	Heapify(_heap, 0);

	return maxElement;
}

size_t HeapSize(const Heap_t *_heap)
{
	if (!_heap)
	{
		return POINTER_NOT_INITIALIZE_HEAP_SIZE;
	}

	return _heap->m_heapSize;
}

size_t HeapForEach(Heap_t *_heap, ActionFunc_t _actionFunc, void *_context)
{
    void *currElement = NULL;
    size_t i;
    
    if (!_heap || !_actionFunc)
	{
		return POINTER_NOT_INITIALIZE_HEAP_FOR_EACH;
	}

    if (!_heap->m_heapSize)
	{
		return UNDERFLOW_HEAP_FOR_EACH;
	}

    for (i = 0;i < _heap->m_heapSize;++i)
    {
        VectorGet(_heap->m_vector, i, &currElement);

        if (!_actionFunc(currElement, _context))
        {
            break;
        }
    }

    return i;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static size_t ParentIndex(size_t _childIndex)
{
	return ((_childIndex - 1) / 2);
}

static size_t LeftChildIndex(size_t _parentIndex)
{
	return (_parentIndex * 2 + 1);
}

static size_t RightChildIndex(size_t _parentIndex)
{
	return (_parentIndex * 2 + 2);
}

static void GetElementsDataAux(Heap_t *_heap, size_t _firstIndex, void **_firstIndexElement, size_t _secondIndex, void **_secondIndexElement)
{
	VectorGet(_heap->m_vector, _firstIndex, _firstIndexElement);
	VectorGet(_heap->m_vector, _secondIndex, _secondIndexElement);
}

static void SetElementsDataAux(Heap_t *_heap, size_t _firstIndex, void *_firstIndexElement, size_t _secondIndex, void *_secondIndexElement)
{
	VectorSet(_heap->m_vector, _firstIndex, _firstIndexElement);
	VectorSet(_heap->m_vector, _secondIndex, _secondIndexElement);
}

static void Heapify(Heap_t *_heap, size_t _parentIndex)
{
	void *parentElement = NULL;
	void *leftChildElement = NULL;
	void *rightChildElement = NULL; 
	size_t leftChildIndex = LeftChildIndex(_parentIndex);
	size_t rightChildIndex = RightChildIndex(_parentIndex);
	size_t lastElementIndex = _heap->m_heapSize - 1;
	
	VectorGet(_heap->m_vector, _parentIndex, &parentElement);
	
	if (lastElementIndex == leftChildIndex) /* have left child */
	{
		VectorGet(_heap->m_vector, leftChildIndex, &leftChildElement);
		
		if (_heap->m_compareFunc(parentElement, leftChildElement))
		{
			SetElementsDataAux(_heap, _parentIndex, leftChildElement, leftChildIndex, parentElement);
			return;
		}
		
		return;
	}
	else if (lastElementIndex < leftChildIndex) /* have no children */
	{
		return;
	}
	
	GetElementsDataAux(_heap, leftChildIndex, &leftChildElement, rightChildIndex, &rightChildElement); /* have 2 children */

	if ( (_heap->m_compareFunc(parentElement, leftChildElement)) || (_heap->m_compareFunc(parentElement, rightChildElement)) )
	{
		if (_heap->m_compareFunc(rightChildElement, leftChildElement)) 
		{
			SetElementsDataAux(_heap, _parentIndex, leftChildElement, leftChildIndex, parentElement);
			Heapify(_heap, leftChildIndex);
		}
		else
		{
			SetElementsDataAux(_heap, _parentIndex, rightChildElement, rightChildIndex, parentElement);
			Heapify(_heap, rightChildIndex);
		}
	}
}

static void BubbleUp(Heap_t *_heap, size_t _newElementIndex)
{
	size_t parentIndex = ParentIndex(_newElementIndex);
	void *parentElement = NULL;
	void *newElement = NULL;

	if (!_newElementIndex)
	{
		return;
	}
	
	GetElementsDataAux(_heap, parentIndex, &parentElement, _newElementIndex, &newElement);
	
	if (_heap->m_compareFunc(parentElement, newElement))
	{
		SetElementsDataAux(_heap, parentIndex, newElement, _newElementIndex, parentElement);
		BubbleUp(_heap, parentIndex);
	}
}