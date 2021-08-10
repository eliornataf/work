/*****************************************************************************
* File Name: Dynamic Vector
* Written by: Elior Nataf
* Date: 14/2/21
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

/*-----------------------------------Typedef---------------------------------*/

typedef struct DynamicVector dynamic_t;

/*---------------------------Functions declarations--------------------------*/

/* Description:
 * A function that creates a new dynamic vector struct from a given size.
 *
 * Input:
 * arrayCapacity - given array size.
 * incBlockSize - number of elements to resize array capacity.
 *
 * Output:
 * NULL - struct / array allocation failed.
 * dynamicArrayPtr - pointer to new dynamically allocated vector.
 *
 * Error: 
 * NULL - struct / array allocation failed.
 * assert - array capacity size error (arrayCapacity < MIN_ARRAY_CAPACITY).
 */
dynamic_t *DynamicVectorCreate(int arrayCapacity, int incBlockSize);

/* Description:
 * A function that destroys the dynamic vector struct.
 *
 * Input:
 * DynamicVector - pointer to dynamic vector struct.
 *
 * Output:
 * DynamicVector equal to NULL - destroy failed.
 *
 * Error: 
 * DynamicVector equal to NULL - destroy failed.
 * assert - the pointer is not initialized.
 */
void DynamicVectorDestroy(dynamic_t *DynamicVector);

/* Description:
 * A function that adds an element at the end of the dynamically allocated array.
 *
 * Input:
 * DynamicVector - pointer to dynamic vector struct.
 * inputData - data to be added.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer (struct / array) is not initialized.
 * ARRAY_CAPACITY_ERROR - array capacity size error (arrayCapacity < MIN_ARRAY_CAPACITY).
 * ARRAY_CAPACITY_FULL - array capacity is full, resize not possible.
 * REALLOC_FAILED - realloc failed, tempPointerForRealloc returns NULL.
 * INSERT_SUCCESS - insert input data is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer (struct / array) is not initialized.
 * ARRAY_CAPACITY_ERROR - array capacity size error (arrayCapacity < MIN_ARRAY_CAPACITY).
 * ARRAY_CAPACITY_FULL - array capacity is full, resize not possible.
 * REALLOC_FAILED - realloc failed, tempPointerForRealloc returns NULL.
 */
int DynamicVectorInsert(dynamic_t *DynamicVector, int inputData);

/* Description:
 * A function that deletes the last element of the dynamically allocated array.
 *
 * Input:
 * DynamicVector - pointer to dynamic vector struct.
 * outputData - pointer to data to be deleted.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer (struct / array) is not initialized.
 * ARRAY_CAPACITY_ERROR - array capacity size error (arrayCapacity < MIN_ARRAY_CAPACITY).
 * ARRAY_IS_EMPTY - the array is empty, delete is not possible.
 * DELETE_SUCCESS - delete last element is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer (struct / array) is not initialized.
 * ARRAY_CAPACITY_ERROR - array capacity size error (arrayCapacity < MIN_ARRAY_CAPACITY).
 * ARRAY_IS_EMPTY - delete is not possible.
 */
int DynamicVectorDelete(dynamic_t *DynamicVector, int *outputData);
