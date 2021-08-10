#include <stdlib.h> /* malloc, free */
#include <stdio.h> /* printf */
#include "doublyLinkedList.h" /* Doubly Linked List Header */

/******************************************************/

struct Node
{
	int m_data;
	Node_t *m_prev;
	Node_t *m_next;
};

struct List
{
	Node_t m_head;
	Node_t m_tail;
};

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

List_t *ListCreate(void)
{
	List_t *list = (List_t*)malloc(sizeof(List_t));
	if (!list)
	{
		return NULL;
	}
	
	list->m_head.m_data = 0;
	list->m_head.m_prev = NULL;
	list->m_head.m_next = &list->m_tail;
	
	list->m_tail.m_data = 0;
	list->m_tail.m_prev = &list->m_head;
	list->m_tail.m_next = NULL;
	
	return list;
}

void ListDestory(List_t *_list)
{
	Node_t *currentNode = NULL;
	Node_t *nextNode = NULL;

	if (!_list)
	{
		return;
	}
	
	currentNode = _list->m_head.m_next;
	nextNode = currentNode;
	
	if (!ListIsEmpty(_list))
	{
		while (&_list->m_tail != currentNode)
		{
			nextNode = nextNode->m_next;
			free(currentNode);
			currentNode = nextNode;
		}
	}
	
	free(_list);
}

ADTError_t ListPushHead(List_t *_list, int _inputData)
{
	Node_t *newNode = NULL;
	
	if (!_list)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	newNode = (Node_t*)malloc(sizeof(Node_t));
	if (!newNode)
	{
		return ALLOCATION_FAILED;
	}
	
	newNode->m_data = _inputData;
	newNode->m_prev = &_list->m_head;
	newNode->m_next = _list->m_head.m_next;
	
	newNode->m_prev->m_next = newNode;
	newNode->m_next->m_prev = newNode;
	
	return OK;
}

ADTError_t ListPushTail(List_t *_list, int _inputData)
{
	Node_t *newNode = NULL;
	
	if (!_list)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	newNode = (Node_t*)malloc(sizeof(Node_t));
	if (!newNode)
	{
		return ALLOCATION_FAILED;
	}
	
	newNode->m_data = _inputData;
	newNode->m_prev = _list->m_tail.m_prev;
	newNode->m_next = &_list->m_tail;
	
	newNode->m_prev->m_next = newNode;
	newNode->m_next->m_prev = newNode;
	
	return OK;
}

ADTError_t ListPopHead(List_t *_list, int *_outputData)
{
	Node_t *removeNode = NULL;

	if (!_list || !_outputData)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	if (ListIsEmpty(_list))
	{
		return UNDERFLOW;
	}
	
	removeNode = _list->m_head.m_next;
	
	*_outputData = removeNode->m_data;
	
	removeNode->m_prev->m_next = removeNode->m_next;
	removeNode->m_next->m_prev = removeNode->m_prev;
	
	free(removeNode);
	
	return OK;
}

ADTError_t ListPopTail(List_t *_list, int *_outputData)
{
	Node_t *removeNode = NULL;

	if (!_list || !_outputData)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	if (ListIsEmpty(_list))
	{
		return UNDERFLOW;
	}
	
	removeNode = _list->m_tail.m_prev;
	
	*_outputData = removeNode->m_data;
	
	removeNode->m_prev->m_next = removeNode->m_next;
	removeNode->m_next->m_prev = removeNode->m_prev;
	
	free(removeNode);
	
	return OK;
}

size_t ListCountItems(List_t *_list)
{
	Node_t *runner = NULL;
	size_t countNodes = 0;
	
	if (!_list)
	{
		return POINTER_IS_NOT_INIT;
	}
	
	runner = _list->m_head.m_next;

	while (&_list->m_tail != runner)
	{
		++countNodes;
		runner = runner->m_next;
	}

	return countNodes;
}

int ListIsEmpty(List_t *_list)
{
	if (!_list)
	{
		return POINTER_IS_NOT_INIT;
	}

	return (_list->m_head.m_next == &_list->m_tail) ? LIST_IS_EMPTY : LIST_IS_NOT_EMTPY;
}

void ListPrint(List_t *_list)
{
	Node_t *runner = NULL;

	if (!_list)
	{
		return;
	}

	for (runner = _list->m_head.m_next;&_list->m_tail != runner;runner = runner->m_next)
	{
		printf("%d -> ", runner->m_data);
	}
}
