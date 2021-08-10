/*****************************************************************************
* File Name: Hash Table Set - ADT
* Written by: Elior Nataf
* Date: 4/4/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __HASH_TABLE_SET_H__
#define __HASH_TABLE_SET_H__

/*------------------------------- Header Files ------------------------------*/

#include <stddef.h> /* size_t */
#include <limits.h> /* INT_MAX */

/*---------------------------------- Typedef --------------------------------*/

typedef struct HashTable HashTable_t;

/* Description:
 * Function that generate index for given element, specified by user demand. 
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * element - pointer to given element.
 * 
 * Output:
 * return the generate index.
 *
 * Error: 
 * None.
 */
typedef size_t (*HashFunc_t)(const void *element);

/* Description:
 * Function that used to compare element, specified by user demand. 
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * firstElement - pointer to the first element.
 * secondElement - pointer to the second element.
 * 
 * Output:
 * return 1 if elements are same, zero if not.
 *
 * Error: 
 * None.
 */
typedef int (*EqualityFunc_t)(const void *firstElement, const void *secondElement);

/*----------------------------------- Define --------------------------------*/

#define POINTER_NOT_INITIALIZE_HASH_IS_FOUND (INT_MAX)
#define POINTER_NOT_INITIALIZE_HASH_NUM_OF_ELEMENTS (INT_MAX)
#define POINTER_NOT_INITIALIZE_HASH_CAPACITY (INT_MAX)
#define POINTER_NOT_INITIALIZE_HASH_AVERAGE_REHASHES (INT_MAX)
#define POINTER_NOT_INITIALIZE_HASH_MAX_REHASHES (INT_MAX)

/*------------------------------------ Enum  --------------------------------*/

typedef enum HashTableStatus
{
	HASH_TABLE_SUCCESS = 0,
	HASH_TABLE_POINTER_NOT_INITIALIZE = 1,
	HASH_TABLE_OVERFLOW = 2,
	HASH_TABLE_DUPLICATE_FOUND = 3,
	HASH_TABLE_ELEMENT_IS_NOT_FOUND = 4
} HashTableStatus_t;

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creates a new hash table. Memory will be specially allocated from 
 * a given size.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * capacity - given hash table size (max capacity).
 * hashFunc - function that generate index for given element.
 * equalityFunc - function that used to compare element.
 *
 * Output:
 * NULL - capacity error (capacity < 2).
 * NULL - hashFunc/equalityFunc pointer is not initialize, create is not possible.
 * NULL - allocation failed.
 * hashTable - pointer to new created hash table.
 *
 * Error: 
* NULL - capacity error (capacity < 2).
 * NULL - hashFunc/equalityFunc pointer is not initialize, create is not possible.
 * NULL - allocation failed.
 */
HashTable_t *HashTableCreate(size_t capacity, HashFunc_t hashFunc, EqualityFunc_t equalityFunc);

/* Description:
 * A function that destroys a specified hash table. If supplied with non-NULL destroyer 
 * function, frees items in hash table. All remaining data will be lost.
 *
 * Time Complexity: O(1)..O(n) (depends on memory freeing).
 *
 * Input:
 * hashTable - pointer to hash table to be deallocated.
 * elementDestroy - A function pointer to be used to destroy all elements in the hash table (may 
 * be NULL if unnecessary).
 *
 * Output:
 * None.
 *
 * Error: 
 * hash table pointer is not initialized, destroy is not possible.
 */
void HashTableDestroy(HashTable_t **hashTable, void (*elementDestroy)(void *element));

/* Description:
 * A function that inserts a new entry into hash table.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * hashTable - pointer to hash table to insert element.
 * element - pointer to element to be added.
 *
 * Output:
 * HAST_TABLE_POINTER_NOT_INITIALIZE - hashTable/element pointer is not initialize, insert is
 * not possible.
 * HASH_TABLE_OVERFLOW - hash table capacity is full, insert is not possible.
 * HASH_TABLE_DUPLICATE_FOUND - the element is already there, duplicate is not allowed, insert is
 * not possible.
 * HASH_TABLE_SUCCESS - hast table insert element succeeded.
 * 
 * Error: 
 * HAST_TABLE_POINTER_NOT_INITIALIZE - hashTable/element pointer is not initialize, insert is
 * not possible.
 * HASH_TABLE_OVERFLOW - hash table capacity is full, insert is not possible.
 * HASH_TABLE_DUPLICATE_FOUND - the element is already there, duplicate is not allowed, insert is
 * not possible.
 */
HashTableStatus_t HashTableInsert(HashTable_t *hashTable, void *element);

/* Description:
 * A function that removes element entry from a hash table.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * hashTable - pointer to hash table to remove element from.
 * elementToBeFreed - pointer to element to be freed.
 * freedElement - pointer freed element.
 *
 * Output:
 * HAST_TABLE_POINTER_NOT_INITIALIZE - hashTable/elementToBeFreed/freedElement pointer is not
 * initialize, remove is not possible.
 * HASH_TABLE_ELEMENT_IS_NOT_FOUND - the elementToBeFreed is not found, remove is not possible.
 * HASH_TABLE_SUCCESS - hast table insert element succeeded.
 * 
 * Error: 
 * HAST_TABLE_POINTER_NOT_INITIALIZE - hashTable/elementToBeFreed/freedElement pointer is not
 * initialize, remove is not possible.
 * HASH_TABLE_ELEMENT_IS_NOT_FOUND - the elementToBeFreed is not found, remove is not possible.
 */
HashTableStatus_t HashTableRemove(HashTable_t *hashTable, void *elementToBeFreed, void **freedElement);

/* Description:
 * A function that checks if an element is exist in a specified hash table, or not.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * hashTable - pointer to hash table to found element from.
 * element - pointer to element to be found.
 *
 * Output:
 * POINTER_NOT_INITIALIZE_HASH_IS_FOUND - hashTable/element pointer is not initialize, found is 
 * not possible.
 * return 1 if element is found, zero if not.
 * 
 * Error: 
 * POINTER_NOT_INITIALIZE_HASH_IS_FOUND - hashTable/element pointer is not initialize, found is 
 * not possible.
 */
int HashTableIsFound(const HashTable_t *hashTable, void *element);

/* Description:
 * A function that returns the current number of entries in a hash table.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * hashTable - pointer to hash table to get number of elements from.
 *
 * Output:
 * POINTER_NOT_INITIALIZE_HASH_NUM_OF_ELEMENTS - hashTable pointer is not initialize, get number
 * of elements is not possible.
 * returns the current number of entries in a hash table.
 * 
 * Error: 
 * POINTER_NOT_INITIALIZE_HASH_NUM_OF_ELEMENTS - hashTable pointer is not initialize, get number
 * of elements is not possible.
 */
size_t HashTableNumOfElements(const HashTable_t *hashTable);

/* Description:
 * A function that returns the capacity (max number of elements) of in a hash table.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * hashTable - pointer to hash table to get capacity from.
 *
 * Output:
 * POINTER_NOT_INITIALIZE_HASH_CAPACITY - hashTable pointer is not initialize, get capacity is 
 * not possible.
 * returns the capacity (max number of elements) of in a hash table.
 * 
 * Error: 
 * POINTER_NOT_INITIALIZE_HASH_CAPACITY - hashTable pointer is not initialize, get capacity is 
 * not possible.
 */
size_t HashTableCapacity(const HashTable_t *hashTable);

/* Description:
 * A function that returns the average rehashes in a hash table using rehash operations counter
 * divided insertion counter.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * hashTable - pointer to hash table to get average rehashes from.
 *
 * Output:
 * POINTER_NOT_INITIALIZE_HASH_AVERAGE_REHASHES - hashTable pointer is not initialize, get average 
 * rehashes is not possible.
 * returns the average rehashes in a hash table.
 * 
 * Error: 
 * POINTER_NOT_INITIALIZE_HASH_AVERAGE_REHASHES - hashTable pointer is not initialize, get average 
 * rehashes is not possible.
 */
double HashTableAvgRehashes(const HashTable_t *hashTable);

/* Description:
 * A function that returns the max rehashes of a single insertion in a hash table.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * hashTable - pointer to hash table to get max rehashes from.
 *
 * Output:
 * POINTER_NOT_INITIALIZE_HASH_MAX_REHASHES - hashTable pointer is not initialize, get max rehashes is 
 * not possible.
 * returns the max rehashes of a single insertion in a hash table..
 * 
 * Error: 
 * POINTER_NOT_INITIALIZE_HASH_MAX_REHASHES - hashTable pointer is not initialize, get max rehashes is 
 * not possible.
 */
size_t HashTableMaxRehashes(const HashTable_t *hashTable);

/* Description:
 * A function that prints a specified hash table. 
 *
 * Time Complexity: O(n).
 *
 * Input:
 * hashTable - pointer to hash table to print elements from.
 *
 * Output:
 * None.
 *
 * Error: 
 * hashTable/PrintElement pointer is not initialized, print is not possible.
 */
void HashTablePrint(const HashTable_t *hashTable, void (*_PrintElement)(void *element, size_t hashKey));

#endif /* __HASH_TABLE_SET_H__ */
