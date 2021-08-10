/*****************************************************************************
* File Name: Heap - ADT
* Written by: Elior Nataf
* Date: 3/3/21
******************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __HEAP_H__
#define __HEAP_H__

/*------------------------------- Header Files ------------------------------*/

#include "ADTError.h" /* ADT Errors header */
#include "dynamicVector.h" /* Dynamic Vector Header */

/*---------------------------------- Typedef --------------------------------*/

typedef struct Heap Heap_t;

/*----------------------------------- Define --------------------------------*/

#define HEAP_IS_EMPTY (0)

/*------------------------------------ Enum  --------------------------------*/


/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creating a new available heap and build him. Memory will be 
 * specially allocated.
 *
 * Time Complexity: O(logn).
 *
 * Input:
 * dynamicVector - pointer to dynamic vector.
 *
 * Output:
 * NULL - allocation failed.
 * NULL - vector pointer is not initialized.
 * heap - pointer to heap.
 *
 * Error: 
 * NULL - allocation failed.
 * NULL - vector pointer is not initialized.
 */
Heap_t *HeapBuild(Vector_t *dynamicVector);

/* Description:
 * A function that destroys a specified heap. Previously allocated memory will
 * be free. All remaining data will be lost.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * heap - pointer to heap.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized - destroy failed.
 */
void HeapDestroy(Heap_t *heap);

/* Description:
 * A function that creates a new heap element and adds it to the corrent place.
 *
 * Time Complexity: O(logn).
 *
 * Input:
 * heap - pointer to heap.
 * inputData - data to be added.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer (heap/vector) is not initialized.
 * OVERFLOW - vector capacity is full, resize not possible.
 * REALLOCATION_FAILED - vector realloc failed (returns NULL).
 * OK - insert input data is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer (heap/vector) is not initialized.
 * OVERFLOW - vector capacity is full, resize not possible.
 * REALLOCATION_FAILED - vector realloc failed (returns NULL).
 */
ADTError_t HeapInsert(Heap_t *heap, int inputData);

/* Description:
 * A function that returns the max valued element in the heap.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * heap - pointer to heap.
 * outputData - pointer to max element data.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer (heap/outputdata/vector) is not initialized.
 * UNDERFLOW - the heap is empty, max is not possible.
 * OK - max valued element returns is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer (heap/outputdata/vector) is not initialized.
 * UNDERFLOW - the heap is empty, max is not possible.
 */
ADTError_t HeapMax(Heap_t *heap, int *outputData);

/* Description:
 * A function that extracts the max valued element from the heap.
 *
 * Time Complexity: O(logn).
 *
 * Input:
 * heap - pointer to heap.
 * outputData - pointer to max element data.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer (heap/outputdata/vector) is not initialized.
 * UNDERFLOW - the heap is empty, max is not possible.
 * REALLOCATION_FAILED - vector realloc failed (returns NULL).
 * OK - max valued element returns is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer (heap/outputdata/vector) is not initialized.
 * UNDERFLOW - the heap is empty, max is not possible.
 * REALLOCATION_FAILED - vector realloc failed (returns NULL).
 */
ADTError_t HeapExtractMax(Heap_t *heap, int *outputData);

/* Description:
 * A function that returns the current number of elements in a heap.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * heap - pointer to heap.
 *
 * Output:
 * HEAP_IS_EMPTY - the pointer is not initialized, heap items is not checked.
 * heap current number of elements.
 *
 * Error: 
 * HEAP_IS_EMPTY - the pointer is not initialized, heap items is not checked.
 */
int HeapItemsNum(Heap_t *heap);

/* Description:
 * A function that prints a specified heap. 
 *
 * Time Complexity: O(n).
 *
 * Input:
 * heap - pointer to heap.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized - print failed.
 */
void HeapPrint(Heap_t *heap);

#endif /* __HEAP_H__ */
