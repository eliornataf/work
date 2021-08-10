/*****************************************************************************
* File Name: Dynamic Vector - ADT
* Written by: Elior Nataf
* Date: 16/2/21
******************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __DYNAMICVECTOR_H__
#define __DYNAMICVECTOR_H__

/*------------------------------- Header Files ------------------------------*/

#include <stddef.h> /* size_t */
#include "ADTError.h" /* ADT Errors header */

/*---------------------------------- Typedef --------------------------------*/

typedef struct DynamicVector Vector_t;

/*------------------------------- Enum & Define -----------------------------*/

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creates a new dynamic vector from a given size.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * capacity - given vector size.
 * incBlockSize - number of elements to resize vector capacity.
 *
 * Output:
 * NULL - allocation failed.
 * NULL - capacity & incBlockSize equal to zero.
 * vector - pointer to new dynamically allocated vector.
 *
 * Error: 
 * NULL - allocation failed.
 * NULL - capacity & incBlockSize equal to zero.
 */
Vector_t *VectorCreate(size_t capacity, size_t incBlockSize);

/* Description:
 * A function that destroys a specified dynamic vector.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * vector - pointer to dynamic vector.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized - destroy failed.
 */
void VectorDestroy(Vector_t *vector);

/* Description:
 * A function that adds an element at the end of the dynamically allocated vector.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * vector - pointer to dynamic vector.
 * inputData - data to be added.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * OVERFLOW - vector capacity is full, resize not possible.
 * REALLOCATION_FAILED - realloc failed (returns NULL).
 * OK - insert input data is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * OVERFLOW - vector capacity is full, resize not possible.
 * REALLOCATION_FAILED - realloc failed (returns NULL).
 */
ADTError_t VectorPush(Vector_t *vector, int inputData);

/* Description:
 * A function that deletes the last element of the dynamically allocated vector.
 *
 * Input:
 * vector - pointer to dynamic vector.
 * outputData - pointer to data to be deleted.
 *
 * Time Complexity: O(1).
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - the vector is empty, delete is not possible.
 * REALLOCATION_FAILED - realloc failed (returns NULL).
 * OK - delete last element is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - the vector is empty, delete is not possible.
 * REALLOCATION_FAILED - realloc failed (returns NULL).
 */
ADTError_t VectorPop(Vector_t *vector, int *outputData);

/* Description:
 * A function that gets data from given index in dynamically allocated vector.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * vector - pointer to dynamic vector.
 * index - given index.
 * outputData - pointer to data from a given index.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * WRONG_INDEX - the given index is wrong.
 * OK - vector get element succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * WRONG_INDEX - the given index is wrong.
 */
ADTError_t VectorGetElement(Vector_t *vector, size_t index, int *outputData);

/* Description:
 * A function that sets data from given index in dynamically allocated vector.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * vector - pointer to dynamic vector.
 * index - given index.
 * inputData - data to be sets.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * WRONG_INDEX - the given index is wrong.
 * OK - vector set element succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * WRONG_INDEX - the given index is wrong.
 */
ADTError_t VectorSetElement(Vector_t *vector, size_t index, int inputData);

/* Description:
 * A function that gets the number of elements from dynamically allocated vector.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * vector - pointer to dynamic vector.
 * numOfElements - pointer to the number of elements from dynamically allocated vector.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * OK - vector get number of elements succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 */
ADTError_t VectorNumOfElements(Vector_t *vector, size_t *numOfElements);

/* Description:
 * A function that prints a specified dynamically allocated vector. 
 *
 * Time Complexity: O(n).
 *
 * Input:
 * vector - pointer to dynamic vector.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized - print failed.
 */
void VectorPrint(Vector_t *_Vector);

#endif /* __DYNAMICVECTOR_H__ */
