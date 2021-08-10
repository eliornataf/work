/*****************************************************************************
* File Name: Stack - ADT
* Written by: Elior Nataf
* Date: 17/2/21
******************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __STACK_H__
#define __STACK_H__

/*------------------------------- Header Files ------------------------------*/

#include <stddef.h> /* size_t */
#include "ADTError.h" /* ADT Errors header */

/*---------------------------------- Typedef --------------------------------*/

typedef struct Stack Stack_t;

/*------------------------------- Enum & Define -----------------------------*/

#define STACK_IS_NOT_EMPTY 0
#define STACK_IS_EMPTY 1

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creating a new available stack. Memory will be specially 
 * allocated from a given size.
 *
 * Time Complexity: O(1). 
 *
 * Input:
 * capacity - given stack size.
 * incBlockSize - number of elements to resize stack capacity.
 *
 * Output:
 * NULL - allocation failed.
 * NULL - capacity & incBlockSize equal to zero.
 * stack - pointer to stack.
 *
 * Error: 
 * NULL - allocation failed.
 * NULL - capacity & incBlockSize equal to zero.
 */
Stack_t *StackCreate(size_t capacity, size_t incBlockSize);

/* Description:
 * A function that destroys a specified stack.
 *
 * Time Complexity: O(1). 
 *
 * Input:
 * stack - pointer to stack.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized - destroy failed.
 */
void StackDestroy(Stack_t *stack);

/* Description:
 * A function that adds an element at the end of the stack.
 *
 * Time Complexity: O(1).
 * 
 * Input:
 * stack - pointer to stack.
 * inputData - data to be added.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * OVERFLOW - stack capacity is full, resize not possible.
 * REALLOCATION_FAILED - realloc failed (returns NULL).
 * OK - insert input data is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * OVERFLOW - stack capacity is full, resize not possible.
 * REALLOCATION_FAILED - realloc failed (returns NULL).
 */
ADTError_t StackPush(Stack_t *stack, int inputData);

/* Description:
 * A function that deletes the last element of the stack.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * stack - pointer to stack.
 * outputData - pointer to data to be deleted.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - the stack is empty, delete is not possible.
 * REALLOCATION_FAILED - realloc failed (returns NULL).
 * OK - delete last element is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - the stack is empty, delete is not possible.
 * REALLOCATION_FAILED - realloc failed (returns NULL).
 */
ADTError_t StackPop(Stack_t *stack, int *outputData);

/* Description:
 * A function that peeking at the element placed at the top of the stack.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * stack - pointer to stack.
 * outputData - pointer to data element placed at the top.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - the stack is empty, peek is not possible.
 * WRONG_INDEX - the given index is wrong.
 * OK - vector get element succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - the stack is empty, peek is not possible.
 * WRONG_INDEX - the given index is wrong.
 */
ADTError_t StackPeek(Stack_t *stack, int *outputData);

/* Description:
 * A function that checks if a specified stack is empty.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * stack - pointer to stack.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - returns STACK_IS_EMPTY, stack is empty is not checked.
 * returns STACK_IS_EMPTY if stack is empty, or STACK_IS_NOT_EMPTY if it's not.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - returns STACK_IS_EMPTY, stack is empty is not checked.
 */
int StackIsEmpty(Stack_t *stack);

/* Description:
 * A function that prints a specified stack. 
 *
 * Time Complexity: O(n).
 *
 * Input:
 * stack - pointer to stack.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized - print failed.
 */
void StackPrint(Stack_t *stack);

#endif /* __STACK_H__ */
