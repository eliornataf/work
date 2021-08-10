#include <stdlib.h> /* malloc, free */
#include "genericDoublyLinkedList.h" /* Generic Doubly Linked List Header */
#include "internal.h" /* Internal Header */

/****************************************************************************/

static void DestroyNodes(List_t *_list ,NodeDestroy_t _nodeDestroy)
{
    Node_t *currentNode = _list->m_head.m_next;
	Node_t *nextNode = NULL;

    for (;currentNode != &_list->m_tail;currentNode = nextNode)
    {
        nextNode = currentNode->m_next;
        _nodeDestroy(currentNode->m_data);
		free(currentNode);
    }
}

/****************************************************************************/

List_t *ListCreate(void)
{
	List_t *list = (List_t*)malloc(sizeof(List_t));
	if (NULL == list)
	{
		return NULL;
	}
	
	list->m_head.m_data = NULL;
	list->m_head.m_prev = &list->m_head;
	list->m_head.m_next = &list->m_tail;
	
	list->m_tail.m_data = NULL;
	list->m_tail.m_prev = &list->m_head;
	list->m_tail.m_next = &list->m_tail;
	
	return list;
}

void ListDestory(List_t **_list, NodeDestroy_t _nodeDestroy)
{
    if (NULL == _list || NULL == *_list)
    {
        return;
    }

    if (NULL != _nodeDestroy)
    {
        DestroyNodes(*_list, _nodeDestroy);
    }

    free(*_list);
    *_list = NULL;
}

DListResult_t ListPushHead(List_t *_list, void *_data)
{
    Node_t *newNode = NULL;
	
	if (NULL == _list)
	{
		return DLIST_POINTER_NOT_INITIALIZE;
	}
	
	newNode = (Node_t*)malloc(sizeof(Node_t));
	if (NULL == newNode)
	{
		return DLIST_ALLOCATION_FAILED;
	}
	
	newNode->m_data = _data;
	newNode->m_prev = &_list->m_head;
	newNode->m_next = _list->m_head.m_next;
	newNode->m_prev->m_next = newNode;
	newNode->m_next->m_prev = newNode;
	
	return DLIST_SUCCESS;
}

DListResult_t ListPushTail(List_t *_list, void *_data)
{
	Node_t *newNode = NULL;
	
	if (NULL == _list)
	{
		return DLIST_POINTER_NOT_INITIALIZE;
	}
	
	newNode = (Node_t*)malloc(sizeof(Node_t));
	if (NULL == newNode)
	{
		return DLIST_ALLOCATION_FAILED;
	}
	
	newNode->m_data = _data;
	newNode->m_prev = _list->m_tail.m_prev;
	newNode->m_next = &_list->m_tail;
	
	newNode->m_prev->m_next = newNode;
	newNode->m_next->m_prev = newNode;
	
	return DLIST_SUCCESS;
}

DListResult_t ListPopHead(List_t *_list, void **_pData)
{
    Node_t *removeNode = NULL;

	if (NULL == _list || NULL == _pData)
	{
		return DLIST_POINTER_NOT_INITIALIZE;
	}

	if (_list->m_head.m_next == &_list->m_tail)
	{
		return DLIST_UNDERFLOW;
	}

	removeNode = _list->m_head.m_next;
	
	*_pData = removeNode->m_data;
	
	removeNode->m_prev->m_next = removeNode->m_next;
	removeNode->m_next->m_prev = removeNode->m_prev;
	
	free(removeNode);
	
	return DLIST_SUCCESS;
}

DListResult_t ListPopTail(List_t *_list, void **_pData)
{
	Node_t *removeNode = NULL;

	if (NULL == _list || NULL == _pData)
	{
		return DLIST_POINTER_NOT_INITIALIZE;
	}
	
	if (_list->m_head.m_next == &_list->m_tail)
	{
		return DLIST_UNDERFLOW;
	}
	
	removeNode = _list->m_tail.m_prev;

	*_pData = removeNode->m_data;
	
	removeNode->m_prev->m_next = removeNode->m_next;
	removeNode->m_next->m_prev = removeNode->m_prev;
	
	free(removeNode);
	
	return DLIST_SUCCESS;
}

size_t ListSize(List_t *_list)
{
	Node_t *iter = NULL;
	size_t countNodes = 0;
	
	if (NULL == _list)
	{
		return POINTER_NOT_INITIALIZE_DOUBLY_LINKED_LIST_SIZE;
	}
	
	for (iter = _list->m_head.m_next;iter != &_list->m_tail;iter = iter->m_next)
	{
		++countNodes;
	}

	return countNodes;
}
