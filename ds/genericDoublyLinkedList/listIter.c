#include <stdlib.h> /* malloc, free */
#include "listIter.h" /* List Iterator Header */
#include "internal.h" /* Internal Header */

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

ListIter_t ListIterBegin(const List_t *_list)
{
    if (!_list)
    {
        return NULL;
    }

    return (ListIter_t)_list->m_head.m_next;
}

ListIter_t ListIterEnd(const List_t *_list)
{
    if (!_list)
    {
        return NULL;
    }

    return (ListIter_t)&_list->m_tail;
}

int ListIterEqual(const ListIter_t _firstIter, const ListIter_t _secondIter)
{
    if (!_firstIter || !_secondIter)
    {
        return POINTER_NOT_INITIALIZE_EQUAL;
    }

    return (_firstIter == _secondIter);
}

ListIter_t ListIterNext(ListIter_t _iter)
{
    if (!_iter)
    {
        return NULL;
    }

    return (ListIter_t)(((Node_t*)_iter)->m_next);
}

ListIter_t ListIterPrev(ListIter_t _iter)
{
    if (!_iter)
    {
        return NULL;
    }

    if (((Node_t*)_iter)->m_prev == ((Node_t*)_iter)->m_prev->m_prev)
    {
        return _iter;
    }

    return (ListIter_t)(((Node_t*)_iter)->m_prev);
}

void *ListIterGet(ListIter_t _iter)
{
    if (!_iter)
    {
        return NULL;
    }

    return ((Node_t*)_iter)->m_data;
}

void *ListIterSet(ListIter_t _iter, const void *_data)
{
    void *elementOldData = NULL;
    
    if (!_iter || !_data)
	{
		return NULL;
	}

    if ((Node_t*)_iter == ((Node_t*)_iter)->m_next)
    {
        return NULL;
    }

    elementOldData = ((Node_t*)_iter)->m_data;

    ((Node_t*)_iter)->m_data = (void*)_data;

    return elementOldData;
}

ListIter_t ListIterInsertBefore(ListIter_t _iter, const void *_data)
{
    Node_t *newNode = NULL;
	
	if (!_iter || !_data)
	{
		return NULL;
	}
	
	newNode = (Node_t*)malloc(sizeof(Node_t));
	if (!newNode)
	{
		return NULL;
	}
	
	newNode->m_data = (void*)_data;
	newNode->m_prev = ((Node_t*)_iter)->m_prev;
	newNode->m_next = (Node_t*)_iter;
	
	newNode->m_prev->m_next = newNode;
	newNode->m_next->m_prev = newNode;
	
	return (ListIter_t)newNode;
}

void *ListIterRemove(ListIter_t _iter)
{
    void *removeElementData = NULL;
    
    if (!_iter)
	{
		return NULL;
	}

    if ((Node_t*)_iter == ((Node_t*)_iter)->m_next)
    {
        return NULL;
    }

    ((Node_t*)_iter)->m_prev->m_next = ((Node_t*)_iter)->m_next;
    ((Node_t*)_iter)->m_next->m_prev = ((Node_t*)_iter)->m_prev;

    removeElementData = ((Node_t*)_iter)->m_data;

    free(_iter);

    return removeElementData;
}