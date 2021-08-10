/*****************************************************************************
* File Name: dynamic_allocation
* Written by: Elior Nataf
* Date: 10/2/21
/*****************************************************************************/

/*-----------------------------Libaries & Define-----------------------------*/

#define MIN_ARRAY_CAPACITY 0

#define POINTER_NOT_INITIALIZE (-4)
#define ARRAY_CAPACITY_ERROR (-3)
#define ARRAY_CAPACITY_FULL (-2)
#define REALLOC_FAILED (-1)
#define INSERT_SUCCESS (0)

#define ARRAY_IS_EMPTY (-1)
#define DELETE_SUCCESS (0)

/*--------------------------Functions declarations--------------------------*/

/* Description:
 * A function that allocates a dynamic array from a given size.
 *
 * Input:
 * arrayCapacity - given array size.
 *
 * Output:
 * NULL - allocation failed.
 * dynamicArrayPtr - pointer to new dynamically allocated array.
 *
 * Error: 
 * NULL - allocation failed.
 * assert - array capacity size error (arrayCapacity < MIN_ARRAY_CAPACITY).
 */
int *DynamicArrayCreate(int arrayCapacity);

/* Description:
 * A function that destroys the allocated dynamic array.
 *
 * Input:
 * dynamicArrayPtr - pointer to dynamically allocated array.
 *
 * Output:
 * dynamicArrayPtr equal to NULL - destroy failed.
 *
 * Error: 
 * dynamicArrayPtr equal to NULL - destroy failed.
 * assert - the pointer is not initialized.
 */
void DynamicArrayDestroy(int* dynamicArrayPtr);

/* Description:
 * A function that adds an element at the end of the dynamically allocated array.
 *
 * Input:
 * dynamicArrayPtr - pointer to new dynamically allocated array.
 * inputData - data to be added.
 * arrayCapacity - array max number of elements.
 * numOfElements - current array number of elements.
 * incBlockSize - number of elements to resize array capacity.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * ARRAY_CAPACITY_ERROR - array capacity size error (arrayCapacity < MIN_ARRAY_CAPACITY).
 * ARRAY_CAPACITY_FULL - array capacity is full, resize not possible.
 * REALLOC_FAILED - realloc failed, tempPointerForRealloc returns NULL.
 * INSERT_SUCCESS - insert input data is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * ARRAY_CAPACITY_ERROR - array capacity size error (arrayCapacity < MIN_ARRAY_CAPACITY).
 * ARRAY_CAPACITY_FULL - array capacity is full, resize not possible.
 * REALLOC_FAILED - realloc failed, tempPointerForRealloc returns NULL.
 */
int DynamicArrayInsert(int **dynamicArrayPtr, int inputData, int *arrayCapacity,
											int *numOfElements, int incBlockSize);
											
/* Description:
 * A function that deletes the last element of the dynamically allocated array.
 *
 * Input:
 * dynamicArrayPtr - pointer to new dynamically allocated array.
 * outputData - pointer to data to be deleted.
 * numOfElements - current array number of elements.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * ARRAY_CAPACITY_ERROR - array capacity size error (arrayCapacity < MIN_ARRAY_CAPACITY).
 * ARRAY_IS_EMPTY - the array is empty, delete is not possible.
 * DELETE_SUCCESS - delete last element is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * ARRAY_CAPACITY_ERROR - array capacity size error (arrayCapacity < MIN_ARRAY_CAPACITY).
 * ARRAY_IS_EMPTY - delete is not possible.
 */
 
int DynamicArrayDelete(int *dynamicArrayPtr, int *outputData, int *numOfElements);
