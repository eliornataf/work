/*****************************************************************************
* File Name: Generic Binary Search Tree - ADT
* Written by: Elior Nataf
* Date: 25/3/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __GENERIC_BINARY_SEARCH_TREE_H__
#define __GENERIC_BINARY_SEARCH_TREE_H__

/*------------------------------- Header Files ------------------------------*/

#include <stddef.h> /* size_t */

/*---------------------------------- Typedef --------------------------------*/

typedef struct Node Node_t;
typedef struct BST BST_t;
typedef void* BSTIter_t;

/* Description:
 * Function that used to compare nodes data by them size, specified by user demand. 
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * currNodeData - const pointer to the current node data.
 * newNodeData - const pointer to the new node data.
 *
 * Output:
 * return -1 in case firstNodeData & secondNodeData is equal, zero in case currNodeData 
 * is bigger and 1 in case newNodeData is bigger.
 *
 * Error: 
 * None.
 */
typedef int	(*ComparatorFunc_t)(const void *currNodeData, const void *newNodeData);

/* Description:
 * Function that makes predicate on bst node, specified by user demand. 
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * nodeData - pointer to bst node data.
 * context - pointer to context.
 * 
 * Output:
 * return 1 if predicate holds for node data and zero if not.
 *
 * Error: 
 * None.
 */
typedef int (*PredicateFunc_t)(const void *nodeData, const void *context);

/* Description:
 * Function that makes action on bst node, specified by user demand. 
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * node - pointer to bst node.
 * context - pointer to context.
 *
 * Output:
 * return zero to stop for each iteration and 1 to continue.
 *
 * Error: 
 * None.
 */
typedef int	(*ActionFunc_t)(void *node, void *context);

/*----------------------------------- Define --------------------------------*/

#define POINTER_NOT_INITIALIZE_EQUAL (-1)

/*------------------------------------ Enum  --------------------------------*/

typedef enum BSTreeTraversalMode
{
	BSTREE_TRAVERSAL_PRE_ORDER = 0,
	BSTREE_TRAVERSAL_IN_ORDER = 1,
	BSTREE_TRAVERSAL_POST_ORDER = 2
} BSTreeTraversalMode_t;

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creating a new available bst. The tree is implemented using a sentinel.
 * Memory will be specially allocated. Creates an empty binary search tree with sentinel.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * compareFunc - A comparison function. return -1 in case firstNodeData & secondNodeData is
 * equal, zero in case currNodeData is bigger and 1 in case newNodeData is bigger.
 *
 * Output:
 * NULL - compareFunc pointer is not initialize, create is not possible.
 * NULL - allocation failed.
 * bst - pointer to new created bst.
 *
 * Error: 
 * NULL - compareFunc pointer is not initialize, create is not possible.
 * NULL - allocation failed.
 */
BST_t *BSTCreate(ComparatorFunc_t compareFunc);

/* Description:
 * A function that destroys a specified bst. If supplied with non-NULL destroyer 
 * function, frees items in tree.
 *
 * Time Complexity: O(1)..O(n) (depends on memory freeing).
 *
 * Input:
 * bst - pointer to bst to be deallocated.
 * destroyNodes - A function pointer to be used to destroy all node in the bst (may 
 * be NULL if unnecessary).
 *
 * Output:
 * None.
 *
 * Error: 
 * bst pointer is not initialized, destroy is not possible.
 */
void BSTDestroy(BST_t **bst, void (*nodeDestroy)(void* node));

/* Description:
 * A function that creates a new node that holds specified data (if is not already there,
 * duplicate is not allowed) and add it to the corrent place in the bst using the tree's
 * comparison function. Memory will be allocated for new bst node. The first node in the 
 * tree is the sentinel left subtree.
 *
 * Time Complexity: Average O(log n), Worst O(n).
 *
 * Input:
 * bst - pointer to bst to insert element to.
 * data - pointer to data to be added.
 *
 * Output:
 * NULL - bst pointer is not initialized, insert is not possible.
 * iter - iterator to end, data pointer is not initialized.
 * iter - iterator to end, new node allocation failed.
 * iter - iterator to end, data to be added is same to one of node's data.
 * iter - iterator pointing to the new node on success.
 *
 * Error: 
 * NULL - bst pointer is not initialized, insert is not possible.
 * iter - iterator to end, data pointer is not initialized.
 * iter - iterator to end, new node allocation failed.
 * iter - iterator to end, data to be added is same to one of node's data.
 */
BSTIter_t BSTInsert(BST_t *bst, void *data);

/* Description:
 * A function that iterates over bst and returns iterator that pointing to the 
 * first node that match the user provided context or end iterator if tree node
 * is not found. Search the first node for which the given predicate returns 0
 * iterating using in-order manner over nodes. In case the user provided context 
 * pointer that is not initialize, behavior is underfined.
 *
 * Time Complexity: O(k * n) where O(k) is the time complexity of the predicate.
 *
 * Input:
 * bst - pointer to bst to find context from.
 * predicateFunc - User provided function pointer to find with.
 * context - User provided context, will be sent to predicateFunc.
 *
 * Output:
 * NULL - bst/predicateFunc pointer is not initialized, find is not possible.
 * iter - iterator to end, the node is not found.
 * iter - iterator pointing to the first node with data found on success.
 *
 * Error: 
 * NULL - bst/predicateFunc pointer is not initialized, find is not possible.
 */
BSTIter_t BSTFindFirst(const BST_t *bst, PredicateFunc_t predicateFunc, void *context);

/* Description:
 * A function that returns the begin iterator of a bst. Get an in-order iterator to the 
 * tree's begin (the smallest node's data). In case the list is empty the end iterator 
 * will return. 
 * 
 * Time Complexity: Average O(log n) Worst O(n).
 *
 * Input:
 * bst - pointer to bst to return begin iterator from.
 *
 * Output:
 * NULL - bst pointer is not initialized, begin is not possible.
 * iter - pointer to begin iterator of a bst.
 *
 * Error: 
 * NULL - bst pointer is not initialized, begin is not possible.
 */
BSTIter_t BSTIterBegin(const BST_t *bst);

/* Description:
 * A function that returns the end iterator of a bst. the sentinel is the end iterator.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * bst - pointer to bst to return end iterator from.
 *
 * Output:
 * NULL - bst pointer is not initialized, end is not possible.
 * iter - pointer to end iterator of a bst.
 *
 * Error: 
 * NULL - bst pointer is not initialized, end is not possible.
 */
BSTIter_t BSTIterEnd(const BST_t *bst);

/* Description:
 * A function that checks if two iterators in a bst are the same or not.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * firstIter - pointer to first iterator to check from.
 * secondIter - pointer to second iterator to check from.
 *
 * Output:
 * POINTER_NOT_INITIALIZE_EQUAL - firstIter/secondIter pointer is not initialized, 
 * return -1, equal is not possible.
 * return 1 if iterator are same, zero if not.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE_EQUAL - firstIter/secondIter pointer is not initialized, 
 * return -1, equal is not possible.
 */
int BSTIterEqual(const BSTIter_t firstIter, const BSTIter_t secondIter);

/* Description:
 * A function that returns the next iterator in a bst. Get an in-order next iterator 
 * to the current iterator (the first node's data who is bigger the current node).
 * In case the bst is empty, or the node is the biggest data, or the iterator is the end,
 * the end will return.
 * 
 * Time Complexity: Average O(log n) Worst O(n).
 *
 * Input:
 * iter - pointer to iter to get next from.
 *
 * Output:
 * NULL - iter pointer is not initialized, next is not possible.
 * iter - pointer to the next iterator of a bst.
 *
 * Error: 
 * NULL - iter pointer is not initialized, next is not possible.
 */
BSTIter_t BSTIterNext(BSTIter_t iter);

/* Description:
 * A function that returns the prev iterator in a bst. Get an in-order prev iterator 
 * to the current iterator (the first node's data who is smaller the current iterator).
 * In case the bst is empty, the end will return. In case prev to the bst smallest 
 * node's data the smallest node's data will return. In case prev to the end the 
 * biggest node's data will return.
 * 
 * Time Complexity: Average O(log n) Worst O(n).
 *
 * Input:
 * iter - pointer to iter to get prev from.
 *
 * Output:
 * NULL - iter pointer is not initialized, prev is not possible.
 * iter - pointer to the prev iterator of a bst.
 *
 * Error: 
 * NULL - iter pointer is not initialized, prev is not possible.
 */
BSTIter_t BSTIterPrev(BSTIter_t iter);

/* Description:
 * A function that returns a pointer pointing to the data in a specified 
 * iterator of a bst. In case the iterator is the end, NULL will return.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * iter - pointer to iter to get from.
 *
 * Output:
 * NULL - iter pointer is not initialized, get is not possible.
 * NULL - the iterator is the end.
 * iter - pointer to the iterator of a bst.
 *
 * Error: 
 * NULL - iter pointer is not initialized, get is not possible.
 * NULL - the iterator is the end.
 */
void *BSTIterGet(BSTIter_t iter);

/* Description:
 * A function that removes a iterator from the bst and rearranges it so that it 
 * maintains binary search tree arrangement. Frees memory that was previously 
 * allocated for the iterator that is being removed. returns a pointer pointing to 
 * the removed node's data. In case the iterator is the end, NULL will return.
 * 
 * Time Complexity: Average O(log n) Worst O(n).
 *
 * Input:
 * iter - pointer to iter to be freed.
 *
 * Output:
 * NULL - iter pointer is not initialized, remove is not possible.
 * NULL - the iterator is the end.
 * data - the removed node's data.
 *
 * Error: 
 * NULL - iter pointer is not initialized, remove is not possible.
 * NULL - the iterator is the end.
 */
void *BSTIterRemove(BSTIter_t iter);

#endif /* __GENERIC_BINARY_SEARCH_TREE_H__ */
