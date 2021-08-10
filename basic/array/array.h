/*****************************************************************************
* File Name: array
* Written by: Elior Nataf
* Date: 9/2/21
/*****************************************************************************/

/*-----------------------------Libaries & Define-----------------------------*/

#define ARRAY_INPUT_SIZE_ERROR (-1)
#define ARRAY_INPUT_OK (1)

#define ARRAY_IS_SORTED (0)

/*--------------------------Functions declarations--------------------------*/

/* Description:
 * A function that returns the value that occurs the most in a given array.
 *
 * Input:
 * arr - given array.
 * arrSize - given array size.
 * status - pointer to integer, checks array size input;
 *
 * Output:
 * mostOccurElement - the value that occurs the most in a given array.
 *
 * Error: 
 * status equal to ARRAY_INPUT_SIZE_ERROR (size < 1).
 */
int MostOccurElementInArray(int arr[], int arrSize, int* status);

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
 * status equal to ARRAY_INPUT_SIZE_ERROR (size < 1).
 */
int SortElementsByEvenAndOdds(int arr[], int arrSize, int* status);

/* Description:
 * A function that sorted array elements in ascending order using Bubble Sort.
 *
 * Input:
 * arr - given array.
 * arrSize - given array size.
 *
 * Output:
 * ARRAY_INPUT_SIZE_ERROR - given size error.
 * ARRAY_IS_SORTED - the array is successfully sorted.
 *
 * Error: 
 * ARRAY_INPUT_SIZE_ERROR - given size error (size < 1).
 */
int SortArrayElementsWithBubbleSort(int arr[], int arrSize);
