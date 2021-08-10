/*****************************************************************************
* File Name: Bubble Sort
* Written by: Elior Nataf
* Date: 2/3/21
/*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __BUBBLE_SORT_H__
#define __BUBBLE_SORT_H__

/*------------------------------- Header Files ------------------------------*/

#include <stddef.h> /* size_t */

/*------------------------------- Enum & Define -----------------------------*/

#define SUCCESS (0)
#define FAILURE (1)

/*----------------------------- Struct & Typedef ----------------------------*/

typedef int (*SortCriteria_t) (int firstElement, int secondElement);

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * 
 * Input:
 * arr - pointer to array.
 * arrSize - array size.
 * sortCriteria - pointer to sort creiteria function.
 *
 * Output:
 * FAILURE - the pointer to array is not initialized.
 * SUCCESS - sort succeeded.
 *
 * Error: 
 * FAILURE - the pointer to array is not initialized.
 */
int BubbleSort(int *arr, size_t arrSize, SortCriteria_t sortCriteria);

#endif /* __BUBBLE_SORT_H__ */
