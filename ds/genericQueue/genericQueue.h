/*****************************************************************************
* File Name: Generic Queue - ADT
* Written by: Elior Nataf
* Date: 18/3/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __GENERIC_QUEUE_H__
#define __GENERIC_QUEUE_H__

/*------------------------------- Header Files ------------------------------*/

#include <limits.h> /* INT_MAX */
#include <stddef.h> /* size_t */

/*---------------------------------- Typedef --------------------------------*/

typedef struct Queue Queue_t;

/* Description:
 * Function that deletes element for queue, specified by user demand.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * element - pointer to queue element.
 *
 * Output:
 * None.
 * 
 * Error: 
 * None.
 */
typedef void (*ElementDestroy_t)(void *element);

/* Description:
 * Function that makes action on queue element, specified by user demand. 
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * element - pointer to queue element.
 * index - index of the current element.
 * context - pointer to context.
 *
 * Output:
 * return zero to stop for each iteration and 1 to continue.
 *
 * Error: 
 * None.
 */
typedef int	(*ActionFunc_t)(const void *element, size_t index, void *context);

/*-------------------------------------- Enum --------------------------------*/

typedef enum
{
	QUEUE_SUCCESS = 0,
	QUEUE_POINTER_NOT_INITIALIZED = 1,
	QUEUE_OVERFLOW = 2,
	QUEUE_UNDERFLOW = 3
}QueueResult_t;

/*-------------------------------------- Define --------------------------------*/

#define IS_NOT_EMPTY (0)
#define IS_EMPTY (1)

#define POINTER_NOT_INITIALIZE_QUEUE_IS_EMPTY (INT_MAX)
#define POINTER_NOT_INITIALIZE_QUEUE_FOR_EACH (INT_MAX)
#define UNDERFLOW_QUEUE_FOR_EACH (INT_MAX)

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creates a new available queue. Memory will be specially 
 * allocated from a given size.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * capacity - given queue size.
 *
 * Output:
 * NULL - queue memory allocation failed.
 * queue - pointer to new created queue.
 *
 * Error: 
 * NULL - queue memory allocation failed.
 */
Queue_t *QueueCreate(size_t initialCapacity);

/* Description:
 * A function that destroys a specified queue. Previously allocated memory will
 * be freed. All remaining data will be lost.
 *
 * Time Complexity: O(n).
 *
 * Input:
 * queue - pointer to queue to be deallocated.
 * elementDestroy - A function pointer specified by user demand to destroy 
 * all elements from the queue.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized - destroy is not possible.
 */
void QueueDestroy(Queue_t **queue, ElementDestroy_t elementDestroy);

/* Description:
 * A function that inserts an element to the rear of the queue.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * queue - pointer to queue to insert element to.
 * element - element to be added.
 *
 * Output:
 * QUEUE_POINTER_NOT_INITIALIZED - the pointer is not initialized.
 * QUEUE_OVERFLOW - queue capacity is full, insert is not possible.
 * QUEUE_SUCCESS - insert element to the rear is succeeded.
 *
 * Error: 
 * QUEUE_POINTER_NOT_INITIALIZED - the pointer is not initialized.
 * QUEUE_OVERFLOW - queue capacity is full, insert is not possible.
 */
QueueResult_t QueueInsert(Queue_t *queue, void *element);

/* Description:
 * A function that removes a element from the front of the queue.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * queue - pointer to queue to remove element from.
 * element - pointer to item to be deleted.
 *
 * Output:
 * QUEUE_POINTER_NOT_INITIALIZED - the pointer is not initialized.
 * QUEUE_UNDERFLOW - the queue is empty, remove is not possible.
 * QUEUE_SUCCESS - remove a element from the front is succeeded.
 *
 * Error: 
 * QUEUE_POINTER_NOT_INITIALIZED - the pointer is not initialized.
 * QUEUE_UNDERFLOW - the queue is empty, remove is not possible.
 */
QueueResult_t QueueRemove(Queue_t *queue, void **element);

/* Description:
 * A function that checks if a specified queue is empty or not.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * queue - pointer to queue to be checked.
 *
 * Output:
 * POINTER_NOT_INITIALIZE_QUEUE_IS_EMPTY - the pointer is not initialized,
 * return INT_MAX, is empty check is not possible. 
 * returns IS_EMPTY if queue is empty, or IS_NOT_EMPTY if is not.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE_QUEUE_IS_EMPTY - the pointer is not initialized,
 * return INT_MAX, is empty check is not possible.
 */
size_t QueueIsEmpty(const Queue_t *queue);

/* Description:
 * A function that Iterate over all elements in the queue. action function that 
 * provided by user will be called for each element. the iteration will stop if 
 * action will return a zero for an element.
 * 
 * Time Complexity: O(n).
 *
 * Input:
 * queue - pointer to queue to iterate over.
 * actionFunc - User provided function pointer to be invoked for each element.
 * context - User provided context, will be sent to actionFunc.
 *
 * Output:
 * POINTER_NOT_INITIALIZE_QUEUE_FOR_EACH - the pointer is not initialized,
 * return INT_MAX items, for each is not possible. 
 * UNDERFLOW_QUEUE_FOR_EACH - the queue is empty, return INT_MAX items,
 * for each is not possible. 
 * number of times the user function was invokeded. 
 * 
 * Error: 
 * POINTER_NOT_INITIALIZE_QUEUE_FOR_EACH - the pointer is not initialized,
 * return INT_MAX items, for each is not possible. 
 * UNDERFLOW_QUEUE_FOR_EACH - the queue is empty, return INT_MAX items,
 * for each is not possible. 
*/
size_t QueueForEach(Queue_t *queue, ActionFunc_t actionFunc, void *context);

#endif /* __GENERIC_QUEUE_H__ */
