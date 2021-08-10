/*****************************************************************************
* File Name: List Functions - ADT
* Written by: Elior Nataf
* Date: 24/3/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __LIST_FUNCTIONS_H__
#define __LIST_FUNCTIONS_H__

/*------------------------------- Header Files ------------------------------*/

#include <stddef.h> /* size_t */
#include "listIter.h" /* List Iterator Header */

/*----------------------------------- Define --------------------------------*/

#define COUNT_IF_POINTER_NOT_INITIALIZE (888)
#define COUNT_IF_ALLOCATION_FAILED (999)

/*------------------------------------ Enum  --------------------------------*/

/*---------------------------------- Typedef --------------------------------*/

/* Description:
 * Function that makes predicate on list node, specified by user demand. 
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * element - pointer to list node.
 * context - pointer to context.
 * 
 * Output:
 * return 1 if predicate holds for element and zero if not.
 *
 * Error: 
 * None.
 */
typedef int (*PredicateFunc_t)(void *element, void *context);

/* Description:
 * Function that makes action on list node, specified by user demand. 
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * element - pointer to list node.
 * context - pointer to context.
 *
 * Output:
 * return zero to stop for each iteration and 1 to continue.
 *
 * Error: 
 * None.
 */
typedef int	(*ActionFunc_t)(void *element, void *context);

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that iterates over a specified sub-list of nodes in a doubly linked
 * list and returns iterator that pointing to the first node that match the user 
 * provided context, or the toIter iterator if not. 
 * 
 * Time Complexity: O(n).
 *
 * Input:
 * fromIter - A list iterator to start operations from.
 * toIter - A list iterator to end operations on. to is not included.
 * predicateFunc - User provided function pointer to find with.
 * context - User provided context, will be sent to predicateFunc.
 * 
 * Output:
 * NULL - iter/predicateFunc/context pointer is not initialized, find is not possible.
 * NULL - allocation failed.
 * ListIter - list iterator to the element where the iteration was found, 
 * or the to iterator if not.
 * 
 * Error: 
 * NULL - iter/predicateFunc/context pointer is not initialized, find is not possible.
 */
ListIter_t ListIterFindFirst(ListIter_t fromIter, ListIter_t toIter, PredicateFunc_t predicateFunc, void *context);

/* Description:
 * A function that iterates over a specified sub-list of nodes in a doubly linked
 * list and returns the number of nodes that match the user provided context. 
 * 
 * Time Complexity: O(n).
 *
 * Input:
 * fromIter - A list iterator to start operations from.
 * toIter - A list iterator to end operations on. to is not included.
 * predicateFunc - User provided function pointer to count with.
 * context - User provided context, will be sent to predicateFunc.
 * 
 * Output:
 * COUNT_IF_POINTER_NOT_INITIALIZE - iter/predicateFunc/context pointer is not 
 * initialized, return 888, count is not possible.
 * COUNT_IF_ALLOCATION_FAILED - allocation failed, return 999, count is not possible.
 * the number of nodes that holds the user provided context.
 *  
 * Error: 
 * COUNT_IF_POINTER_NOT_INITIALIZE - iter/predicateFunc/context pointer is not 
 * initialized, return 888, count is not possible.
 * COUNT_IF_ALLOCATION_FAILED - allocation failed, return 999, count is not possible. * NULL - allocation failed.
 */
size_t ListIterCountIf(ListIter_t fromIter, ListIter_t toIter, PredicateFunc_t predicateFunc, void *context);

/* Description:
 * A function that iterates over a specified sub-list of nodes in a doubly linked list.
 * linked list an executes a specified function on each one of them.
 * The user provided action function, and the function will called for each element.
 * the iteration will stop if action will return a zero for an element.
 * 
 * Time Complexity: O(n).
 *
 * Input:
 * fromIter - A list iterator to start operations from.
 * toIter - A list iterator to end operations on. to is not included.
 * actionFunc - User provided function pointer to be invoked for each element.
 * context - User provided context, will be sent to actionFunc.
 * 
 * Output:
 * NULL - iter/actionFunc pointer is not initialized, for each is not possible.
 * NULL - allocation failed.
 * ListIter - list iterator to the element where the iteration stoped.
 * 
 * Error: 
 * NULL - iter/actionFunc pointer is not initialized, for each is not possible.
 * NULL - allocation failed.
 */
ListIter_t ListIterForEach(ListIter_t fromIter, ListIter_t toIter, ActionFunc_t actionFunc, void *context);

#endif /* __LIST_FUNCTIONS_H__ */
