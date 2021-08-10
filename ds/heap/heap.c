#include <stdlib.h> /* malloc, free */
#include "dynamicVector.h" /* Dynamic Vector Header */
#include "heap.h" /* Heap Header */

#define FIRST_ELEMENT_INDEX (0)
#define HEAP_SIZE_IS_1 (1)

struct Heap
{
	Vector_t *m_vector;
	size_t m_heapSize;
};

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static size_t ParentIndex(size_t _childIndex);
static size_t LeftChildIndex(size_t _parentIndex);
static size_t RightChildIndex(size_t _parentIndex);
static void GetElementsData(Heap_t *_heap, size_t _firstIndex, int *_firstIndexoutputData, size_t _secondIndex, int *_secondIndexoutputData);
static void SetElementsData(Heap_t *_heap, size_t _firstIndex, int _firstIndexinputData, size_t _secondIndex, int _secondIndexinputData);
static void Heapify(Heap_t *_heap, size_t _parentIndex);
static void BubbleUp(Heap_t *_heap, size_t _newElementIndex);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

Heap_t *HeapBuild(Vector_t *_dynamicVector)
{
	Heap_t *heap = NULL;
	size_t vectorNumOfElements, lastParentIndex;
	int i;
	
	if (!_dynamicVector)
	{
		return NULL;
	}
	
	heap = (Heap_t*)malloc(sizeof(Heap_t));
	if (!heap)
	{			
		return NULL;
	}
	
	heap->m_vector = _dynamicVector;
	
	VectorNumOfElements(heap->m_vector, &vectorNumOfElements);
	heap->m_heapSize = vectorNumOfElements;
	
	lastParentIndex = ParentIndex(heap->m_heapSize - 1);
	
	for (i = lastParentIndex;FIRST_ELEMENT_INDEX <= i;--i)
	{
		Heapify(heap, (size_t)i);
	}
	
	return heap;
}

void HeapDestroy(Heap_t *_heap)
{
	if (!_heap)
	{
		return;
	}

	free(_heap);
}

ADTError_t HeapInsert(Heap_t *_heap, int _inputData)
{
	size_t lastElementIndex;
	ADTError_t status;

	if (!_heap)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	status = VectorPush(_heap->m_vector, _inputData);
	if (OK != status)
	{
		return status;
	}
	
	++_heap->m_heapSize;
	lastElementIndex = _heap->m_heapSize - 1;
	
	BubbleUp(_heap, lastElementIndex);
	
	return OK;
}

ADTError_t HeapMax(Heap_t *_heap, int *_outputData)
{
	if (!_heap || !_outputData)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	if (!_heap->m_heapSize)
	{
		return UNDERFLOW;
	}
	
	VectorGetElement(_heap->m_vector, FIRST_ELEMENT_INDEX, _outputData);
	
	return OK;
}

ADTError_t HeapExtractMax(Heap_t *_heap, int *_outputData)
{
	int firstElementData, lastElementData;
	size_t lastElementIndex;
	ADTError_t status;
	
	if (!_heap || !_outputData)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	if (!_heap->m_heapSize)
	{
		return UNDERFLOW;
	}
	
	if (HEAP_SIZE_IS_1 == _heap->m_heapSize)
	{
		status = VectorPop(_heap->m_vector, _outputData);
		--_heap->m_heapSize;
		return status;
	}
	
	lastElementIndex = _heap->m_heapSize - 1;
	
	GetElementsData(_heap, FIRST_ELEMENT_INDEX, &firstElementData, lastElementIndex, &lastElementData);
	
	SetElementsData(_heap, FIRST_ELEMENT_INDEX, lastElementData, lastElementIndex, firstElementData);
	
	status = VectorPop(_heap->m_vector, _outputData);

	--_heap->m_heapSize;
	
	Heapify(_heap, FIRST_ELEMENT_INDEX);
	
	return status;
}

int HeapItemsNum(Heap_t *_heap)
{
	if (!_heap)
	{
		return HEAP_IS_EMPTY;
	}
	
	return _heap->m_heapSize;
}

void HeapPrint(Heap_t *_heap)
{
	if (!_heap)
	{
		return;
	}

	VectorPrint(_heap->m_vector);
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
	return ((_parentIndex * 2) + 1);
}

static size_t RightChildIndex(size_t _parentIndex)
{
	return ((_parentIndex * 2) + 2);
}

static void GetElementsData(Heap_t *_heap, size_t _firstIndex, int *_firstIndexoutputData, size_t _secondIndex, int *_secondIndexoutputData)
{
	VectorGetElement(_heap->m_vector, _firstIndex, _firstIndexoutputData);
	VectorGetElement(_heap->m_vector, _secondIndex, _secondIndexoutputData);
}

static void SetElementsData(Heap_t *_heap, size_t _firstIndex, int _firstIndexinputData, size_t _secondIndex, int _secondIndexinputData)
{
	VectorSetElement(_heap->m_vector, _firstIndex, _firstIndexinputData);
	VectorSetElement(_heap->m_vector, _secondIndex, _secondIndexinputData);
}

static void Heapify(Heap_t *_heap, size_t _parentIndex)
{
	int parentData, leftChildData, rightChildData; 
	size_t leftChildIndex = LeftChildIndex(_parentIndex);
	size_t rightChildIndex = RightChildIndex(_parentIndex);
	size_t lastElementIndex = _heap->m_heapSize - 1;
	
	VectorGetElement(_heap->m_vector, _parentIndex, &parentData);
	
	if (lastElementIndex == leftChildIndex) /* have left child */
	{
		VectorGetElement(_heap->m_vector, leftChildIndex, &leftChildData);
		
		if (parentData < leftChildData)
		{
			SetElementsData(_heap, _parentIndex, leftChildData, leftChildIndex, parentData);
			return;
		}
		
		return;
	}
	else if (lastElementIndex < leftChildIndex) /* have no children */
	{
		return;
	}
	
	GetElementsData(_heap, leftChildIndex, &leftChildData, rightChildIndex, &rightChildData);
	
	if (parentData < leftChildData || parentData < rightChildData)  
	{
		if (rightChildData <= leftChildData) /* have 2 children */
		{
			SetElementsData(_heap, _parentIndex, leftChildData, leftChildIndex, parentData);
			Heapify(_heap, leftChildIndex);
		}
		else
		{
			SetElementsData(_heap, _parentIndex, rightChildData, rightChildIndex, parentData);
			Heapify(_heap, rightChildIndex);
		}
	}
}

static void BubbleUp(Heap_t *_heap, size_t _newElementIndex)
{
	size_t parentIndex = ParentIndex(_newElementIndex);
	int parentData, newElementData;

	if (!_newElementIndex)
	{
		return;
	}
	
	GetElementsData(_heap, parentIndex, &parentData, _newElementIndex, &newElementData);
	
	if (parentData < newElementData)
	{
		SetElementsData(_heap, parentIndex, newElementData, _newElementIndex, parentData);
		BubbleUp(_heap, parentIndex);
	}
}