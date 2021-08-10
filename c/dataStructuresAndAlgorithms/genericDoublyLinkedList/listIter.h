/*****************************************************************************
* File Name: List Iterator - ADT
* Written by: Elior Nataf
* Date: 22/3/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __LIST_ITER_H__
#define __LIST_ITER_H__

/*------------------------------- Header Files ------------------------------*/

#include "internal.h" /* Internal Header */

/*----------------------------------- Define --------------------------------*/

#define POINTER_NOT_INITIALIZE_EQUAL (-1)

/*------------------------------------ Enum  --------------------------------*/

/*---------------------------------- Typedef --------------------------------*/

typedef void* ListIter_t;

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that returns the begin iterator of a doubly linked list. In case 
 * the list is empty the tail iterator will return. 
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * list - pointer to list to return begin iterator from.
 *
 * Output:
 * NULL - list pointer is not initialized, begin is not possible.
 * iter - pointer to begin iterator of a doubly linked list.
 *
 * Error: 
 * NULL - list pointer is not initialized, begin is not possible.
 */
ListIter_t ListIterBegin(const List_t *list);

/* Description:
 * A function that returns the end iterator of a doubly linked list.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * list - pointer to list to return end iterator from.
 *
 * Output:
 * NULL - list pointer is not initialized, end is not possible.
 * iter - pointer to end iterator of a doubly linked list.
 *
 * Error: 
 * NULL - list pointer is not initialized, end is not possible.
 */
ListIter_t ListIterEnd(const List_t *list);

/* Description:
 * A function that checks if two iterators in a doubly linked list are the same or not.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * firstIter - pointer to first iterator to check from.
 * secondIter - pointer to second iterator to check from.
 *
 * Output:
 * POINTER_NOT_INITIALIZE_EQUAL - firstIter/secondIter pointer is not initialized, 
 * return -1, equal is not possible.
 * return 1 if iterator are same, zero if not.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE_EQUAL - firstIter/secondIter pointer is not initialized, 
 * return -1, equal is not possible.
 */
int ListIterEqual(const ListIter_t firstIter, const ListIter_t secondIter);

/* Description:
 * A function that returns the next iterator in a doubly linked. In case 
 * the list is empty or the iterator is the tail, the tail will return.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * iter - pointer to iter to get next from.
 *
 * Output:
 * NULL - iter pointer is not initialized, next is not possible.
 * iter - pointer to the next iterator of a doubly linked list.
 *
 * Error: 
 * NULL - iter pointer is not initialized, next is not possible.
 */
ListIter_t ListIterNext(ListIter_t iter);

/* Description:
 * A function that returns the prev iterator in a doubly linked. In case 
 * the list is empty and the iterator is the tail, the tail will return.
 * In case the iter is the first element, the first element will return.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * iter - pointer to iter to get prev from.
 *
 * Output:
 * NULL - iter pointer is not initialized, prev is not possible.
 * iter - pointer to the prev iterator of a doubly linked list.
 *
 * Error: 
 * NULL - iter pointer is not initialized, prev is not possible.
 */
ListIter_t ListIterPrev(ListIter_t iter);

/* Description:
 * A function that returns a pointer pointing to the data in a specified 
 * iterator of a doubly linked list. In case the iterator is the tail, NULL
 * will return.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * iter - pointer to iter to get from.
 *
 * Output:
 * NULL - iter pointer is not initialized, get is not possible.
 * NULL - the iterator is the tail.
 * iter - pointer to the iterator of a doubly linked list.
 *
 * Error: 
 * NULL - iter pointer is not initialized, get is not possible.
 */
void *ListIterGet(ListIter_t iter);

/* Description:
 * A function that set data at the node where the iterator is pointing to 
 * and returns a pointer pointing to the data that was changed. In case the 
 * iterator is the tail, NULL will return.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * iter - pointer to iter to set from.
 * data - the new element data that will change the iter data.
 *
 * Output:
 * NULL - iter/data pointer is not initialized, set is not possible.
 * NULL - the iterator is the tail.
 * iter - pointer to the iterator of a doubly linked list.
 *
 * Error: 
 * NULL - iter/data pointer is not initialized, set is not possible.
 */
void *ListIterSet(ListIter_t iter, const void *data);

/* Description:
 * A function that creates a new list node that points to specified data and inserts
 * it into a doubly linked list before iter. Memory will be allocated for the new node.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * iter - pointer to iter to be inserted before.
 * data - the new element data that will insert before the iter.
 *
 * Output:
 * NULL - iter/data pointer is not initialized, insert is not possible.
 * NULL - node allocation failed.
 * iter - pointer to the new element of a doubly linked list.
 *
 * Error: 
 * NULL - iter/data pointer is not initialized, insert is not possible.
 * NULL - node allocation failed.
 */
ListIter_t ListIterInsertBefore(ListIter_t iter, const void *data);

/* Description:
 * A function that removes a specified node from a doubly linked list. Free 
 * memory that was previously allocated for the node that is being removed.
 * In case the iterator is the tail, NULL will return.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * iter - pointer to iter to be removed.
 *
 * Output:
 * NULL - iter pointer is not initialized, remove is not possible.
 * NULL - the iterator is the tail.
 * iter - pointer to the element that will removed.
 *
 * Error: 
 * NULL - iter pointer is not initialized, remove is not possible.
 */
void *ListIterRemove(ListIter_t iter);

#endif /* __LIST_ITER_H__ */
