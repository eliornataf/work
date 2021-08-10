/*****************************************************************************
* File Name: Generic Sort
* Written by: Elior Nataf
* Date: 16/3/21
/*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __GENERIC_SORT_H__
#define __GENERIC_SORT_H__

/*------------------------------- Header Files ------------------------------*/

/*---------------------------------- Typedef --------------------------------*/

typedef int (*sortCriteria_t) (const void *firstElement, const void *secondElement);

/*----------------------------------- Define --------------------------------*/

/*------------------------------------ Enum  --------------------------------*/

typedef enum
{
    SUCCESS = 0,
    FAILURE = 1
} status_t;

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that sorts an array of elements based on Bubble Sort, sort criteria function and the element size.
 *
 * Input:
 * arr - pointer to the array to be sorted.
 * arrSize - the number of elements in the array.
 * elementSize - the size of one element.
 * sortCriteria - the function to sort with, takes 2 parameters and return the sort criteria.
 *
 * Output:
 * FAILURE - the array pointer is not initialized.
 * FAILURE - the array is empty/sorted (arrSize < 2).
 * FAILURE - elementSize is equal to zero.
 * FAILURE - the sortCriteria pointer is not initialized.
 * FAILURE - buffer allocation failed.
 * SUCCESS - the array is successfully sorted.
 *
 * Error: 
 * FAILURE - the array pointer is not initialized.
 * FAILURE - the array is empty/sorted (arrSize < 2).
 * FAILURE - elementSize is equal to zero.
 * FAILURE - the sortCriteria pointer is not initialized.
 * FAILURE - buffer allocation failed. 
 */
int GenericBubbleSort(void *arr, size_t arrSize, size_t elementSize, sortCriteria_t sortCriteria);

#endif /* __GENERIC_SORT_H__ */