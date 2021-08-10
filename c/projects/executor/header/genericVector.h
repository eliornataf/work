/*****************************************************************************
* File Name: Generic Dynamic Vector - ADT
* Written by: Elior Nataf
* Date: 17/3/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __GENERIC_DYNAMIC_VECTOR_H__
#define __GENERIC_DYNAMIC_VECTOR_H__

/*------------------------------- Header Files ------------------------------*/

#include <stddef.h> /* size_t */

/*---------------------------------- Typedef --------------------------------*/

typedef struct Vector Vector_t;

/* Description:
 * Function that makes action on vector elements, specified by user demand. 
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * element - pointer to element.
 * index - index of the current element.
 * context - pointer to context.
 *
 * Output:
 * return zero to stop for each iteration and 1 to continue.
 *
 * Error: 
 * None.
 */
typedef int	(*VectorElementAction_t)(void *element, size_t index, void *context);

/*----------------------------------- Enum ----------------------------------*/

typedef enum VectorResult 
{
	VECTOR_SUCCESS,
	VECTOR_POINTER_NOT_INITIALIZE,				
	VECTOR_OVERFLOW,				
	VECTOR_REALLOCATION_FAILED,
    VECTOR_UNDERFLOW,
    VECTOR_WRONG_INDEX
} VectorResult_t;

/*---------------------------------- Define ---------------------------------*/

#define POINTER_NOT_INITIALIZE_VECTOR_SIZE (999)
#define POINTER_NOT_INITIALIZE_VECTOR_CAPACITY (999)
#define POINTER_NOT_INITIALIZE_VECTOR_FOR_EACH (999)
#define UNDERFLOW_VECTOR_FOR_EACH (999)

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * Function that creates a new dynamic vector. memory will be specially 
 * allocated according to parameters initial capacity and block size.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * initialCapacity - number of elements that can be stored initially.
 * incBlockSize - the vector will grow or shrink on demand by this size.
 *
 * Output:
 * NULL - initialCapacity & incBlockSize equal to zero.
 * NULL - allocation failed.
 * vector - pointer to new dynamically allocated vector.
 *
 * Error: 
 * NULL - initialCapacity & incBlockSize equal to zero.
 * NULL - allocation failed.
 */
Vector_t *VectorCreate(size_t initialCapacity, size_t incBlockSize);

/* Description:
 * A function that destroys dynamic vector by pointer. previously allocated 
 * memory will be free. any remain data will be lost.
 *
 * Time Complexity: O(n).
 *
 * Input:
 * vector - pointer to dynamic vector to be deallocated.
 * elementDestroy - A function pointer to be used to destroy all elements in the vector.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized - destroy is not possible.
 */
void VectorDestroy(Vector_t **vector, void (*elementDestroy)(void* item));

/* Description:
 * A function that appends an element at the end of a dynamic vector.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * vector - pointer to dynamic vector to append element to.
 * item - pointer to item to be added.
 *
 * Output:
 * VECTOR_POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * VECTOR_OVERFLOW - vector capacity is full, resize is not possible.
 * VECTOR_REALLOCATION_FAILED - vector realloc failed.
 * VECTOR_SUCCESS - insert input data is succeeded.
 *
 * Error: 
 * VECTOR_POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * VECTOR_OVERFLOW - vector capacity is full, resize is not possible.
 * VECTOR_REALLOCATION_FAILED - vector realloc failed.
 */
VectorResult_t VectorAppend(Vector_t *vector, void *item);

/* Description:
 * A function that removes the last element in a dynamic vector.
 *
 * Input:
 * vector - pointer to dynamic vector to remove element from.
 * pItem - pointer to item to be deleted.
 *
 * Time Complexity: O(1).
 *
 * Output:
 * VECTOR_POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * VECTOR_UNDERFLOW - the vector is empty, delete is not possible.
 * VECTOR_SUCCESS - remove last element is succeeded.
 *
 * Error: 
 * VECTOR_POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * VECTOR_UNDERFLOW - the vector is empty, delete is not possible.
 */
VectorResult_t VectorRemove(Vector_t *vector, void **pItem);

/* Description:
 * Function that gets a value of item element in the dynamic vector,
 * specified by index.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * vector - pointer to dynamic vector to be used.
 * index - index of item to get value from.
 * pItem - pointer to item to receive data from.
 *
 * Output:
 * VECTOR_POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * VECTOR_WRONG_INDEX - the specified index is larger that vector size.
 * VECTOR_SUCCESS - vector get element succeeded.
 *
 * Error: 
 * VECTOR_POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * VECTOR_WRONG_INDEX - the specified index is larger that vector size.
 */
VectorResult_t VectorGet(const Vector_t *vector, size_t index, void **pItem);

/* Description:
 * Function that set a value of item element in the dynamic vector,
 * specified by index.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * vector - pointer to dynamic vector to be used.
 * index - index of item to get value from.
 * value - new element value to be set.
 *
 * Output:
 * VECTOR_POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * VECTOR_WRONG_INDEX - the specified index is larger that vector size.
 * VECTOR_SUCCESS - vector get element succeeded.
 *
 * Error: 
 * VECTOR_POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * VECTOR_WRONG_INDEX - the specified index is larger that vector size.
 */
VectorResult_t VectorSet(Vector_t *vector, size_t index, void *value);

/* Description:
 * Function that returns current number of elements held by dynamic vector.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * vector - const pointer to dynamic vector to be used.
 *
 * Output:
 * POINTER_NOT_INITIALIZE_VECTOR_SIZE - the pointer is not initialized,
 * return 999 items, size check is not possible. 
 * the number of actual items currently in the vector.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE_VECTOR_SIZE - the pointer is not initialized,
 * return 999 items, size check is not possible. 
 */
size_t VectorSize(const Vector_t *vector);

/* Description:
 * Function that returns current total capacity (max number of
 * elements) of dynamic vector.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * vector - const pointer to dynamic vector to be used.
 *
 * Output:
 * POINTER_NOT_INITIALIZE_VECTOR_CAPACITY - the pointer is not initialized,
 * return 999 items, capacity check is not possible.
 * the number of actual capacity vector.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE_VECTOR_CAPACITY - the pointer is not initialized,
 * return 999 items, capacity check is not possible.
 */
size_t VectorCapacity(const Vector_t *vector);

/* Description:
 * A function that Iterate over all elements in the vector. action function that 
 * provided by user will be called for each element. the iteration will stop if 
 * action will return a zero for an element.
 * 
 * Time Complexity: O(n).
 *
 * Input:
 * vector - const pointer to dynamic vector to iterate over.
 * action - User provided function pointer to be invoked for each element.
 * context - User provided context, will be sent to action.
 *
 * Output:
 * POINTER_NOT_INITIALIZE_VECTOR_FOR_EACH - the pointer is not initialized,
 * return 999 items, for each is not possible. 
 * UNDERFLOW_VECTOR_FOR_EACH - the vector is empty, return 999 items,
 * for each is not possible. 
 * number of times the user functions was invokeded.
 *
 * equivalent to:
 * 
 * {....
 * 
 *      for(i = 0;i < VectorSize(vector);++i)
 *      {
 *          VectorGet(vector, i, &element);
 * 
 *          if (!action(element, i, context))
 *          {
 *          break;	
 *          }		
 *      }
 * 
 * return i;
 * 
 * }     
 * 
 * Error: 
 * POINTER_NOT_INITIALIZE_VECTOR_FOR_EACH - the pointer is not initialized,
 * return 999 items, for each is not possible. 
 * UNDERFLOW_VECTOR_FOR_EACH - the vector is empty, return 999 items,
 * for each is not possible. 
*/
size_t VectorForEach(const Vector_t *vector, VectorElementAction_t action, void *context);

#endif /* __GENERIC_DYNAMIC_VECTOR_H__ */
