/*****************************************************************************
* File Name: Generic Doubly Linked List - ADT
* Written by: Elior Nataf
* Date: 21/3/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __GENERIC_DOUBLY_LINKED_LIST_H__
#define __GENERIC_DOUBLY_LINKED_LIST_H__

/*------------------------------- Header Files ------------------------------*/

#include <stddef.h> /* size_t */
#include "internal.h" /* Internal Header */

/*----------------------------------- Define --------------------------------*/

#define POINTER_NOT_INITIALIZE_DOUBLY_LINKED_LIST_SIZE (999)

/*------------------------------------ Enum  --------------------------------*/

typedef enum DListResult 
{
	DLIST_SUCCESS = 0,
	DLIST_POINTER_NOT_INITIALIZE = 1,
	DLIST_ALLOCATION_FAILED = 2,			
	DLIST_UNDERFLOW = 3
} DListResult_t;

/*---------------------------------- Typedef --------------------------------*/

/* Description:
 * Function that delete node for a doubly linked list, specified by user demand.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * node - pointer to a doubly linked list node.
 *
 * Output:
 * None.
 * 
 * Error: 
 * None.
 */
typedef void (*NodeDestroy_t)(void *node);

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creating a new available doubly linked list. Memory will be 
 * specially allocated.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * None.
 *
 * Output:
 * NULL - list allocation failed.
 * dlist - pointer to new doubly linked list.
 *
 * Error: 
 * NULL - list allocation failed.
 */
List_t *ListCreate(void);

/* Description:
 * A function that destroys a specified doubly linked list. optionally destroys
 * elements using user provided function.
 *
 * Time Complexity: O(n).
 *
 * Input:
 * dlist - pointer to doubly linked list to be deallocated.
 * nodeDestroy - A function pointer to be used to destroy all nodes in the doubly
 * linked list. If the pointer is NULL if no such destroy is required.
 * 
 * Output:
 * None.
 *
 * Error: 
 * list pointer is not initialized, destroy is not possible.
 */
void ListDestory(List_t **list, NodeDestroy_t nodeDestroy);

/* Description:
 * A function that creates a new node that holds specified data and
 * adds it to the head of a doubly linked list.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * list - pointer to doubly linked list to be added to.
 * data - pointer to data to be added.
 *
 * Output:
 * DLIST_POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * DLIST_ALLOCATION_FAILED - memory allocation failed.
 * DLIST_SUCCESS - the items add is succeeded.
 *
 * Error: 
 * DLIST_POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * DLIST_ALLOCATION_FAILED - memory allocation failed.
 */
DListResult_t ListPushHead(List_t *list, void *data);

/* Description:
 * A function that creates a new node that holds specified data and
 * adds it to the tail of a doubly linked list.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * list - pointer to doubly linked list to be added to.
 * data - pointer to data to be added.
 *
 * Output:
 * DLIST_POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * DLIST_ALLOCATION_FAILED - memory allocation failed.
 * DLIST_SUCCESS - the items add is succeeded.
 *
 * Error: 
 * DLIST_POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * DLIST_ALLOCATION_FAILED - memory allocation failed.
 */
DListResult_t ListPushTail(List_t *list, void *data);

/* Description:
 * A function that removes a node from the head of a doubly linked list.
 * Frees memory that was previously allocated for the node that is being removed.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * list - pointer to doubly linked list to be removed from.
 * pData - pointer to the removed data.
 *
 * Output:
 * DLIST_POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * DLIST_UNDERFLOW - the doubly linked list is empty, pop is not possible.
 * DLIST_SUCCESS - the items remove is succeeded.
 *
 * Error: 
 * DLIST_POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * DLIST_UNDERFLOW - the doubly linked list is empty, pop is not possible.
 */
DListResult_t ListPopHead(List_t *list, void **pData);

/* Description:
 * A function that removes a node from the tail of a doubly linked list.
 * Frees memory that was previously allocated for the node that is being removed.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * list - pointer to doubly linked list to be removed from.
 * pData - pointer to the removed data.
 *
 * Output:
 * DLIST_POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * DLIST_UNDERFLOW - the doubly linked list is empty, pop is not possible.
 * DLIST_SUCCESS - the items remove is succeeded.
 *
 * Error: 
 * DLIST_POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * DLIST_UNDERFLOW - the doubly linked list is empty, pop is not possible.
 */
DListResult_t ListPopTail(List_t *list, void **pData);

/* Description:
 * A function that returns the current number of nodes in a doubly linked list.
 *
 * Time Complexity: O(n).
 *
 * Input:
 * list - pointer to doubly linked list.
 *
 * Output:
 * POINTER_NOT_INITIALIZE_DOUBLY_LINKED_LIST_SIZE - the pointer is not initialized,
 * return 999 items, size is not possible.
 * current number of nodes in a doubly linked list.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE_DOUBLY_LINKED_LIST_SIZE - the pointer is not initialized,
 * return 999 items, size is not possible.
 */
size_t ListSize(List_t *list);

#endif /* __GENERIC_DOUBLY_LINKED_LIST_H__ */
