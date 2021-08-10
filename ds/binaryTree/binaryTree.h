/*****************************************************************************
* File Name: Binary Tree - ADT
* Written by: Elior Nataf
* Date: 24/2/21
******************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

/*------------------------------- Header Files ------------------------------*/

#include <stddef.h> /* size_t */
#include "ADTError.h" /* ADT Errors header */

/*---------------------------------- Typedef --------------------------------*/

typedef struct Node Node_t;
typedef struct BinaryTree BinaryTree_t;

/*----------------------------------- Define --------------------------------*/

#define DATA_IS_NOT_FOUND (0)
#define DATA_IS_FOUND (1)

/*------------------------------------ Enum  --------------------------------*/

typedef enum TreeTraverse
{
	PRE_ORDER = 0,
	IN_ORDER = 1,
	POST_ORDER = 2
} TreeTraverse_t;

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creating a new available binary tree. Memory will be specially 
 * allocated.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * None.
 *
 * Output:
 * NULL - allocation failed.
 * binaryTree - pointer to binary tree.
 *
 * Error: 
 * NULL - allocation failed.
 */
BinaryTree_t *BinaryTreeCreate(void);

/* Description:
 * A function that destroys a specified binary tree.
 *
 * Time Complexity: O(n).
 *
 * Input:
 * binaryTree - pointer to binary tree.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized - destroy failed.
 */
void BinaryTreeDestroy(BinaryTree_t *_binaryTree);

/* Description:
 * A function that creates a new node that holds specified data and add it to
 * the corrent place in the binary tree.
 *
 * Time Complexity: O(n).
 *
 * Input:
 * binaryTree - pointer to binary tree.
 * data - data to be added.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * ALLOCATION_FAILED - new node allocation failed.
 * DUPLICATE_DATA - data to be added is same to one of the node's data.
 * OK - insert a node to the tree is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * DUPLICATE_DATA - data to be added is same to one of the node's data.
 * ALLOCATION_FAILED - new node allocation failed.
 */
ADTError_t BinaryTreeInsert(BinaryTree_t *binaryTree, int data);

/* Description:
 * A function that find data in a specified binary tree.
 *
 * Time Complexity: O(n).
 *
 * Input:
 * binaryTree - pointer to binary tree.
 * data - data to be found.
 *
 * Output:
 * DATA_IS_NOT_FOUND - the pointer is not initialized.
 * DATA_IS_NOT_FOUND - data is not found in one of the node tree.
 * DATA_IS_FOUND - data is found in one of the node tree.
 *
 * Error: 
 * DATA_IS_NOT_FOUND - the pointer is not initialized.
 */
int BinaryTreeIsDataFound(BinaryTree_t *binaryTree, int data);

/* Description:
 * A function that prints a specified binary tree. 
 *
 * Time Complexity: O(n).
 *
 * Input:
 * binaryTree - pointer to binary tree.
 * traverseMode - you can choose one of the tree traverse: PRE_ORDER, 
 * IN_ORDER & POST_ORDER.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized - print failed.
 * the tree is empty - print failed.
 */
void BinaryTreePrint(BinaryTree_t *binaryTree, TreeTraverse_t traverseMode);

#endif /* __BINARY_TREE_H__ */
