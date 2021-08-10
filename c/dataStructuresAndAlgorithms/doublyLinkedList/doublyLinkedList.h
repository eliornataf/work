/*****************************************************************************
* File Name: Doubly Linked List
* Written by: Elior Nataf
* Date: 23/2/21
******************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

/*------------------------------- Header Files ------------------------------*/

#include <limits.h> /* INT_MAX */
#include <stddef.h> /* size_t */
#include "ADTError.h" /* ADT Errors header */

/*------------------------------- Enum & Define -----------------------------*/

#define LIST_IS_NOT_EMTPY (0)
#define LIST_IS_EMPTY (1)
#define POINTER_IS_NOT_INIT (INT_MAX)

/*----------------------------- Struct & Typedef ----------------------------*/

typedef struct Node Node_t;
typedef struct List List_t;

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
 * NULL - allocation failed.
 * List - pointer to list.
 *
 * Error: 
 * NULL - allocation failed.
 */
List_t *ListCreate(void);

/* Description:
 * A function that destroys a specified doubly linked list.
 *
 * Time Complexity: O(n).
 *
 * Input:
 * List - pointer to list.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized - destroy failed.
 */
void ListDestory(List_t *_List);

/* Description:
 * A function that adds a node at the head of a doubly linked list.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * List - pointer to list.
 * inputData - data to be sets.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * ALLOCATION_FAILED - dynamic allocation failed.
 * OK - insert input data is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * ALLOCATION_FAILED - dynamic allocation failed.
 */
ADTError_t ListPushHead(List_t *List, int inputData);

/* Description:
 * A function that adds a node at the tail of a doubly linked list.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * List - pointer to list.
 * inputData - data to be sets.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * ALLOCATION_FAILED - dynamic allocation failed.
 * OK - insert input data is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * ALLOCATION_FAILED - dynamic allocation failed.
 */
ADTError_t ListPushTail(List_t *List, int inputData);

/* Description:
 * A function that removes a node at the head of a doubly linked list.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * List - pointer to list.
 * outputData - pointer to the removed node data.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - the doubly linked list is empty, pop is not possible.
 * OK - insert input data is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - the doubly linked list is empty, pop is not possible.
 */
ADTError_t ListPopHead(List_t *List, int *outputData);

/* Description:
 * A function that removes a node at the tail of a doubly linked list.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * List - pointer to list.
 * outputData - pointer to the removed node data.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - the doubly linked list is empty, pop is not possible.
 * OK - insert input data is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - the doubly linked list is empty, pop is not possible.
 */
ADTError_t ListPopHead(List_t *List, int *outputData);

/* Description:
 * A function that gets the number of nodes from a specified doubly linked list.
 *
 * Time Complexity: O(n).
 *
 * Input:
 * List - pointer to list.
 *
 * Output:
 * POINTER_IS_NOT_INIT - the pointer is not initialized, return 0 items.
 * doubly linked list number of nodes.
 *
 * Error: 
 * POINTER_IS_NOT_INIT - the pointer is not initialized, return 0 items.
 */
size_t ListCountItems(List_t *List);

/* Description:
 * A function that checks if a specified doubly linked list is empty.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * List - pointer to list.
 *
 * Output:
 * POINTER_IS_NOT_INIT - pointer is not initialized returns POINTER_IS_NOT_INIT, stack 
 * is empty is not checked.
 * returns LIST_IS_EMPTY if stack is empty, or LIST_IS_NOT_EMTPY if it's not.
 *
 * Error: 
 * POINTER_IS_NOT_INIT - pointer is not initialized returns POINTER_IS_NOT_INIT, stack 
 * is empty is not checked.
 */
int ListIsEmpty(List_t *List);

/* Description:
 * A function that prints a specified doubly linked list. 
 *
 * Time Complexity: O(n).
 *
 * Input:
 * List - pointer to list.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized - print failed.
 */
void ListPrint(List_t *_List);

#endif /* __DOUBLY_LINKED_LIST_H__ */
