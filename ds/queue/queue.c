#include <stdlib.h> /* malloc, free */
#include <stdio.h> /* printf */
#include "queue.h" /* queue header */

#define INITALIZE_VALUE (0)

struct Queue
{
	int *m_queue;
	size_t m_capacity;
	size_t m_head;
	size_t m_tail;
	size_t m_numOfElements;
};

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

Queue_t *QueueCreate(size_t _capacity)
{
	Queue_t *queue = (Queue_t*)malloc(sizeof(Queue_t));
	if (!queue)
	{
		return NULL;
	}
	
	queue->m_queue = (int*)malloc(_capacity * sizeof(int));
	if (!queue->m_queue)
	{
		free(queue);
		return NULL;
	}
	
	queue->m_capacity = _capacity;
	queue->m_head = INITALIZE_VALUE;
	queue->m_tail = INITALIZE_VALUE;
	queue->m_numOfElements = INITALIZE_VALUE;
	
	return queue;
}

void QueueDestroy(Queue_t *_queue)
{
	if (!_queue)
	{
		return;
	}
	
	free(_queue->m_queue);
	free(_queue);
}

ADTError_t QueueEnqueue(Queue_t *_queue, int _inputData)
{
	if (!_queue)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	if (_queue->m_numOfElements == _queue->m_capacity)
	{
		return OVERFLOW;
	}
	
	*(_queue->m_queue + _queue->m_tail) = _inputData;
	_queue->m_tail = (++_queue->m_tail) % _queue->m_capacity;  
	++_queue->m_numOfElements;
	
	return OK;
}

ADTError_t QueueDequeue(Queue_t *_queue, int *_outputData)
{
	if (!_queue || !_outputData)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	if (QueueIsEmpty(_queue))
	{
		return UNDERFLOW;
	}
	
	*_outputData = *(_queue->m_queue + _queue->m_head);
	_queue->m_head = (++_queue->m_head) % _queue->m_capacity; 
	--_queue->m_numOfElements; 
	
	return OK;
}

int QueueIsEmpty(Queue_t *_queue)
{
	if (!_queue)
	{
		return QUEUE_IS_EMPTY;
	}
	
	return (!_queue->m_numOfElements ? QUEUE_IS_EMPTY : QUEUE_IS_NOT_EMPTY); 
}

void QueuePrint(Queue_t *_queue)
{
	size_t i, j;

	if (!_queue)
	{
		return;
	}
	
	for (i = 0, j = _queue->m_head;i < _queue->m_numOfElements;++i, j = (j + 1) % _queue->m_capacity)
	{
		printf("Queue index %ld is %d\n", j, _queue->m_queue[j]);
	}
	
	printf("\nQueue capacity: %ld\n", _queue->m_capacity);
	printf("Queue head index: %ld\n", _queue->m_head);
	printf("Queue tail index: %ld\n", _queue->m_tail);
	printf("Queue number of elements: %ld\n", _queue->m_numOfElements);
}
