/*****************************************************************************
* File Name: array_by_pointer
* Written by: Elior Nataf
* Date: 9/2/21
/*****************************************************************************/

/*-----------------------------Libaries & Define-----------------------------*/

#define ARRAY_IS_NULL (-2)
#define ARRAY_INPUT_SIZE_ERROR (-1)
#define ARRAY_INPUT_OK (0)
#define ARRAY_IS_SORTED (1)
#define NUM_IS_FOUND (2)
#define NUM_IS_NOT_FOUND (3)

/*--------------------------Functions declarations--------------------------*/

/* Description:
 * A function that returns the value that occurs the most in a given array.
 *
 * Input:
 * arr - given array.
 * arrSize - given array size.
 * status - pointer to integer, checks array size input.
 *
 * Output:
 * mostOccurElement - the value that occurs the most in a given array.
 *
 * Error: 
 * status equal to ARRAY_IS_NULL.
 * status equal to ARRAY_INPUT_SIZE_ERROR (size < 1).
 */
int MostOccurElementInArray(int *arr, int arrSize, int *status);

/* Description:
 * A function that sorted array elements, first the even numbers, and after
 * that all odd numbers, without changing the order of even numbers and order
 * of odd numbers.
 *
 * Input:
 * arr - given array.
 * arrSize - given array size.
 * status - pointer to integer, checks array size input.
 *
 * Output:
 * numEvenElements - number of even numbers.
 *
 * Error: 
 * status equal to ARRAY_IS_NULL.
 * status equal to ARRAY_INPUT_SIZE_ERROR (size < 1).
 */
int SortElementsByEvenAndOdds(int *arr, int arrSize, int *status);

/* Description:
 * A function that sorted array elements in ascending order using Bubble Sort.
 *
 * Input:
 * arr - given array.
 * arrSize - given array size.
 *
 * Output:
 * ARRAY_IS_NULL - given array is NULL.
 * ARRAY_INPUT_SIZE_ERROR - given size error (size < 1).
 * ARRAY_IS_SORTED - the array is successfully sorted.
 *
 * Error: 
 * ARRAY_IS_NULL - given array is NULL.
 * ARRAY_INPUT_SIZE_ERROR - given size error (size < 1).
 */
int SortArrayElementsWithBubbleSort(int *arr, int arrSize);

/* Description:
 * A function that searches given integer in array elements using Binary Search.
 *
 * Input:
 * arr - given array.
 * arrSize - given array size.
 * numToSearch - given number to search.
 *
 * Output:
 * ARRAY_IS_NULL - given array is NULL;
 * ARRAY_INPUT_SIZE_ERROR - given size error.
 * numIsFound - NUM_IS_FOUND if the given number is found, NUM_IS_NOT_FOUND if not.
 *
 * Error: 
 * ARRAY_IS_NULL - given array is NULL.
 * ARRAY_INPUT_SIZE_ERROR - given size error (size < 1).
 */
int SearchInArrayElementsWithBinarySearch(int *arr, int arrSize, int numToSearch);
