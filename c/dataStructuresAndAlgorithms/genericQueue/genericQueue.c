#include <stdlib.h> /* malloc, free */
#include "genericQueue.h" /* Generic queue header */

struct Queue
{
	void **m_arrOfElements;
	size_t m_capacity;
	size_t m_head;
	size_t m_tail;
	size_t m_numOfElements;
};

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static void DestroyQueueElements(Queue_t *queue ,ElementDestroy_t destoryItemFunc);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

Queue_t *QueueCreate(size_t _initialCapacity)
{
    Queue_t *queue = (Queue_t*)malloc(sizeof(Queue_t));
	if (!queue)
	{
		return NULL;
	}

    queue->m_arrOfElements = (void**)malloc(_initialCapacity * sizeof(void*));
	if (!queue->m_arrOfElements)
	{
		free(queue);
		return NULL;
	}

    queue->m_capacity = _initialCapacity;
	queue->m_head = 0;
	queue->m_tail = 0; 
	queue->m_numOfElements = 0;
	
	return queue;
}

void QueueDestroy(Queue_t **_queue, ElementDestroy_t _elementDestroy)
{
    if (!_queue || !*_queue)
	{
		return;
	}

    if (_elementDestroy)
    {
        DestroyQueueElements(*_queue, _elementDestroy);
    }

    free((*_queue)->m_arrOfElements);
    (*_queue)->m_arrOfElements = NULL;

    free(*_queue);
    *_queue = NULL;
}

QueueResult_t QueueInsert(Queue_t *_queue, void *_element)
{
    if (!_queue || !_element)
	{
		return QUEUE_POINTER_NOT_INITIALIZED;
	}
	
	if (_queue->m_numOfElements == _queue->m_capacity)
	{
		return QUEUE_OVERFLOW;
	}
	
	_queue->m_arrOfElements[_queue->m_tail++] = _element;
	_queue->m_tail %= _queue->m_capacity;  
	++_queue->m_numOfElements;
	
	return QUEUE_SUCCESS;
}

QueueResult_t QueueRemove(Queue_t *_queue, void **_element)
{
    if (!_queue || !_element)
	{
		return QUEUE_POINTER_NOT_INITIALIZED;
	}
	
	if (!_queue->m_numOfElements)
	{
		return QUEUE_UNDERFLOW;
	}
	
	*_element = _queue->m_arrOfElements[_queue->m_head++];
	_queue->m_head %= _queue->m_capacity; 
	--_queue->m_numOfElements; 
	
	return QUEUE_SUCCESS;
}

size_t QueueIsEmpty(const Queue_t *_queue)
{
    if (!_queue)
	{
		return POINTER_NOT_INITIALIZE_QUEUE_IS_EMPTY;
	}
	
	return (!_queue->m_numOfElements ? IS_EMPTY : IS_NOT_EMPTY); 
}

size_t QueueForEach(Queue_t *_queue, ActionFunc_t _actionFunc, void *_context)
{
    size_t i, j;
    
    if (!_queue || !_actionFunc)
	{
		return POINTER_NOT_INITIALIZE_QUEUE_FOR_EACH;
	}

    if (!_queue->m_numOfElements)
	{
		return UNDERFLOW_QUEUE_FOR_EACH;
	}

    for (i = 0, j = _queue->m_head;i < _queue->m_numOfElements;++i, ++j % _queue->m_capacity)
    {
        if (!_actionFunc(_queue->m_arrOfElements[j], j, _context))
        {
            break;
        }
    }

    return i;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static void DestroyQueueElements(Queue_t *_queue ,ElementDestroy_t _destoryItemFunc)
{
    size_t i, j;

    for (i = 0, j = _queue->m_head;i < _queue->m_numOfElements;++i, ++j % _queue->m_capacity)
    {
        _destoryItemFunc(_queue->m_arrOfElements[j]);
    }
}