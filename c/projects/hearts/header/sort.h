/*****************************************************************************
* File Name: Sort Algorithms
* Written by: Elior Nataf
* Date: 4/3/21
******************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __SORT_H__
#define __SORT_H__

/*------------------------------- Header Files ------------------------------*/

#include "dynamicVector.h" /* Dynamic Vector Header */
#include "enums.h" /* Enums header */

/*---------------------------------- Typedef --------------------------------*/

/*----------------------------------- Define --------------------------------*/

/*------------------------------------ Enum  --------------------------------*/

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that sort a vector of integers.
 *
 * Time Complexity: best - O(n), average - O(n^2), worst - O(n^2).
 * Space Complexity: O(1) - in place.
 * IsStability? yes.
 *
 * Input:
 * dynamicVector - pointer to dynamic vector.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 * OK - sort is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 */
ADTError_t BubbleSort(Vector_t *dynamicVector);

/* Description:
 * A function that sort a vector of integers.
 *
 * Time Complexity: best - O(n), average - O(n^2), worst - O(n^2).
 * Space Complexity: O(1) - in place.
 * IsStability? yes.
 *
 * Input:
 * dynamicVector - pointer to dynamic vector.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 * OK - sort is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 */
ADTError_t ShakeSort(Vector_t *dynamicVector);

/* Description:
 * A function that sort a vector of integers.
 *
 * Time Complexity: best - O(nlogn), average - O(nlogn), worst - O(n^2).
 * Space Complexity: O(1) - in place.
 * IsStability? no.
 *
 * Input:
 * dynamicVector - pointer to dynamic vector.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 * OK - sort is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 */
ADTError_t QuickSortRecu(Vector_t *dynamicVector);

/* Description:
 * A function that sort a vector of integers.
 *
 * Time Complexity: best - O(nlogn), average - O(nlogn), worst - O(n^2).
 * Space Complexity: O(1) - in place.
 * IsStability? no.
 *
 * Input:
 * dynamicVector - pointer to dynamic vector.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 * OK - sort is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 */
ADTError_t QuickSortIter(Vector_t *dynamicVector);

/* Description:
 * A function that sort a vector of integers.
 *
 * Time Complexity: best - O(n), average - O(n^2), worst - O(n^2).
 * Space Complexity: O(1) - in place.
 * IsStability? yes.
 *
 * Input:
 * dynamicVector - pointer to dynamic vector.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 * OK - sort is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 */
ADTError_t InsertionSort(Vector_t *dynamicVector);

/* Description:
 * A function that sort a vector of integers.
 *
 * Time Complexity: best - O(n^2), average - O(n^2), worst - O(n^2).
 * Space Complexity: O(1) - in place.
 * IsStability? yes.
 *
 * Input:
 * dynamicVector - pointer to dynamic vector.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 * OK - sort is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 */
ADTError_t SelectionSort(Vector_t *dynamicVector);

/* Description:
 * A function that sort a vector of integers.
 *
 * Time Complexity: best - O(n), average - O(n^2), worst - O(n^2).
 * Space Complexity: O(1) - in place.
 * IsStability? no.
 *
 * Input:
 * dynamicVector - pointer to dynamic vector.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 * OK - sort is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 */
ADTError_t ShellSort(Vector_t *dynamicVector);

/* Description:
 * A function that sort a vector of integers.
 *
 * Time Complexity: best - O(nlogn), average - O(nlogn), worst - O(nlogn).
 * Space Complexity: O(n).
 * IsStability? yes.
 *
 * Input:
 * dynamicVector - pointer to dynamic vector.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 * OK - sort is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 */
ADTError_t MergeSort(Vector_t *dynamicVector);

/* Description:
 * A function that sort a vector of integers.
 *
 * Time Complexity: best - O(n), average - O(n), worst - O(n).
 * Space Complexity: O(n).
 * IsStability? yes.
 *
 * Input:
 * dynamicVector - pointer to dynamic vector.
 * maxElementValue - array max element value.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 * OK - sort is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 */
ADTError_t CountingSort(Vector_t *dynamicVector, size_t maxElementValue);

/* Description:
 * A function that sort a vector of integers.
 *
 * Time Complexity: best - O(n), average - O(n), worst - O(n).
 * Space Complexity: O(n).
 * IsStability? yes.
 *
 * Input:
 * dynamicVector - pointer to dynamic vector.
 * numOfDigits - number of digits of array max element value.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 * OK - sort is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the vector pointer is not initialized.
 */
ADTError_t RadixSort(Vector_t *dynamicVector, size_t numOfDigits);

#endif /* __SORT_H__ */
