/*****************************************************************************
* File Name: Heap Generic - ADT
* Written by: Elior Nataf
* Date: 18/3/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __HEAP_GENERIC_H__
#define __HEAP_GENERIC_H__

/*------------------------------- Header Files ------------------------------*/

#include <limits.h> /* INT_MAX */
#include "genericVector.h" /* Generic Vector Header */

/*---------------------------------- Typedef --------------------------------*/

typedef struct Heap Heap_t;

/* Description:
 * Function that makes action on heap elements, specified by user demand. 
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * element - pointer to vector elements.
 * context - pointer to context.
 *
 * Output:
 * return zero to stop for each iteration and 1 to continue.
 *
 * Error: 
 * None.
 */
typedef int	(*ActionFunc_t)(const void *element, void *context);

/* Description:
 * Function that to be used to compare elements. 
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * firstElement - const pointer to the first element.
 * secondElement - const pointer to the second element.
 *
 * Output:
 * return 1 to make swap and 0 if not.
 *
 * Error: 
 * None.
 */
typedef int	(*ComparatorFunc_t)(const void *firstElement, const void *secondElement);

/*----------------------------------- Define --------------------------------*/

#define POINTER_NOT_INITIALIZE_HEAP_SIZE (INT_MAX)
#define POINTER_NOT_INITIALIZE_HEAP_FOR_EACH (INT_MAX)
#define UNDERFLOW_HEAP_FOR_EACH (INT_MAX)

/*------------------------------------ Enum  --------------------------------*/

typedef enum HeapResult 
{
	HEAP_SUCCESS = 0,
	HEAP_POINTER_NOT_INITIALIZE = 1,
	VECTOR_ERROR = 2
} HeapResult_t;

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creating a new available heap. Memory will be specially allocated.
 * Allocating and freeing the underlying vector is user responsibility.
 *
 * Time Complexity: O(logn).
 *
 * Input:
 * vector - pointer to dynamic vector that hold the elements, must be initialized.
 * compareFunc - comparator to be used to compare elements. 
 *
 * Output:
 * NULL - vector/compareFunc pointer is not initialized.
 * NULL - allocation failed.
 * heap - pointer to heap.
 *
 * Error: 
 * NULL - vector/compareFunc pointer is not initialized.
 * NULL - allocation failed.
 */
Heap_t *HeapBuild(Vector_t *vector, ComparatorFunc_t compareFunc);

/* Description:
 * A function that destroys a specified heap. Previously allocated memory will
 * be free. All remaining data will be lost. Frees the heap but not the underlying 
 * vector. On success the heap will be nulled.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * heap - pointer to heap to be deallocated.
 *
 * Output:
 * NULL - the pointer is not initialized.
 * vector - pointer to vector, underlying vector.
 *
 * Error: 
 * NULL - the pointer is not initialized.
 */
Vector_t *HeapDestroy(Heap_t **heap);

/* Description:
 * A function that adds a new heap element in the corrent place.
 *
 * Time Complexity: O(logn).
 *
 * Input:
 * heap - pointer to heap to insert element to.
 * element - element to be added.
 *
 * Output:
 * HEAP_POINTER_NOT_INITIALIZE - the heap pointer is not initialized.
 * VECTOR_ERROR - the vector pointer is not initialized.
 * VECTOR_ERROR - vector capacity is full, resize is not possible.
 * VECTOR_ERROR - vector realloc failed.
 * HEAP_SUCCESS - insert input data is succeeded.
 *
 * Error: 
 * HEAP_POINTER_NOT_INITIALIZE - the heap pointer is not initialized.
 * VECTOR_ERROR - the vector pointer is not initialized.
 * VECTOR_ERROR - vector capacity is full, resize is not possible.
 * VECTOR_ERROR - vector realloc failed.
 */
HeapResult_t HeapInsert(Heap_t *heap, void *element);

/* Description:
 * A function that Peek to the top element on the heap and returns his value  
 * without extracting him.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * heap - pointer to heap to be peeked.
 *
 * Output:
 * NULL - the pointer (heap/vector) is not initialized, peek is not possible.
 * NULL - the heap is empty, peek is not possible.
 * element - const void pointer to top element.
 *
 * Error: 
 * NULL - the pointer (heap/vector) is not initialized, peek is not possible.
 * NULL - the heap is empty, peek is not possible.
 */
const void *HeapPeek(const Heap_t *heap);

/* Description:
 * A function that extracts the element on the top of the heap and remove him.
 *
 * Time Complexity: O(logn).
 *
 * Input:
 * heap - pointer to heap to extracted from.
 *
 * Output:
 * NULL - the pointer (heap/vector) is not initialized.
 * NULL - the heap is empty, max is not possible.
 * NULL - the vector pointer is not initialized.
 * NULL - the vector is empty, delete is not possible.
 * element - void pointer to top element.
 *
 * Error: 
 * NULL - the pointer (heap/vector) is not initialized.
 * NULL - the heap is empty, max is not possible.
 * NULL - the vector pointer is not initialized.
 * NULL - the vector is empty, delete is not possible.
 */
void *HeapExtractMax(Heap_t *heap);

/* Description:
 * A function that returns the current size (number of elements) in the heap.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * heap - pointer to heap to get size from.
 *
 * Output:
 * POINTER_NOT_INITIALIZE_HEAP_SIZE - the pointer is not initialized, 
 * return INT_MAX items, heap size is not possible.
 * heap current number of elements.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE_HEAP_SIZE - the pointer is not initialized, 
 * return INT_MAX items, heap size is not possible.
*/
size_t HeapSize(const Heap_t *heap);

/* Description:
 * A function that iterate over all elements in the heap from top to bottom. 
 * The user provided action function, and the function will called for each element.
 * the iteration will stop if action will return a zero for an element.
 * 
 * Time Complexity: O(n).
 *
 * Input:
 * heap - pointer to heap to iterate over.
 * actionFunc - User provided function pointer to be invoked for each element.
 * context - User provided context, will be sent to action.
 * 
 * Output:
 * POINTER_NOT_INITIALIZE_HEAP_FOR_EACH - the pointer is not initialized,
 * return INT_MAX items, for each is not possible. 
 * UNDERFLOW_HEAP_FOR_EACH - the vector is empty, return INT_MAX items,
 * for each is not possible. 
 * number of times the user function was invokeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE_HEAP_FOR_EACH - the pointer is not initialized,
 * return INT_MAX items, for each is not possible. 
 * UNDERFLOW_HEAP_FOR_EACH - the vector is empty, return INT_MAX items,
 * for each is not possible. 
 */
size_t HeapForEach(Heap_t *heap, ActionFunc_t actionFunc, void *context);

#endif /* __HEAP_GENERIC_H__ */
