/*****************************************************************************
* File Name: Queue - ADT
* Written by: Elior Nataf
* Date: 18/2/21
******************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __QUEUE_H__
#define __QUEUE_H__

/*------------------------------- Header Files ------------------------------*/

#include <stddef.h> /* size_t */
#include "ADTError.h" /* ADT Errors header */

/*---------------------------------- Typedef --------------------------------*/

typedef struct Queue Queue_t;

/*------------------------------- Enum & Define -----------------------------*/

#define QUEUE_IS_NOT_EMPTY 0
#define QUEUE_IS_EMPTY 1

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creating a new available queue. Memory will be specially 
 * allocated from a given size.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * capacity - given queue size.
 *
 * Output:
 * NULL - allocation failed.
 * queue - pointer to queue.
 *
 * Error: 
 * NULL - allocation failed.
 */
Queue_t *QueueCreate(size_t _capacity);

/* Description:
 * A function that destroys a specified queue.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * queue - pointer to queue.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized - destroy failed.
 */
void QueueDestroy(Queue_t *queue);

/* Description:
 * A function that adds an element at the end of the queue.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * queue - pointer to queue.
 * inputData - data to be added.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * OVERFLOW - queue capacity is full.
 * OK - insert input data is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * OVERFLOW - queue capacity is full.
 */
ADTError_t QueueEnqueue(Queue_t *queue, int inputData);

/* Description:
 * A function that removes a element from the head of the queue.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * queue - pointer to queue.
 * outputData - pointer to data to be deleted.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - the queue is empty, delete is not possible.
 * OK - remove a element from the head is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - the queue is empty, delete is not possible.
 */
ADTError_t QueueDequeue(Queue_t *queue, int *outputData);

/* Description:
 * A function that checks if a specified queue is empty.
 *
 *
 * Time Complexity: O(1).
 *
 * Input:
 * queue - pointer to queue.
 *
 * Output:
 * QUEUE_IS_EMPTY - pointer is not initialized returns QUEUE_IS_EMPTY, queue 
 * is empty is not checked.
 * returns QUEUE_IS_EMPTY if stack is empty, or QUEUE_IS_NOT_EMPTY if it's not.
 *
 * Error: 
 * QUEUE_IS_EMPTY - pointer is not initialized returns QUEUE_IS_EMPTY, queue 
 * is empty is not checked.
 */
int QueueIsEmpty(Queue_t *queue);

/* Description:
 * A function that prints a specified queue. 
 *
 * Time Complexity: O(n).
 *
 * Input:
 * queue - pointer to queue.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized - print failed.
 */
void QueuePrint(Queue_t *queue);

#endif /* __QUEUE_H__ */
