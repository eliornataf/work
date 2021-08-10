/*****************************************************************************
* File Name: Hash Table Map - ADT
* Written by: Elior Nataf
* Date: 5/4/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __HASH_TABLE_MAP_H__
#define __HASH_TABLE_MAP_H__

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

/* Description:
 * Function that makes action on hash table entries, specified by user demand. 
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * key - pointer to the key to serve as index.
 * value - pointer to value to associate with the key.
 * context - pointer to context.
 *
 * Output:
 * return zero to stop for each iteration and 1 to continue.
 *
 * Error: 
 * None.
 */
typedef int	(*ActionFunction_t)(void *key, void *value, void *context);

/*----------------------------------- Define --------------------------------*/

#define POINTER_NOT_INITIALIZE_HASH_SIZE (INT_MAX)
#define POINTER_NOT_INITIALIZE_HASH_FOR_EACH (INT_MAX)

/*------------------------------------ Enum  --------------------------------*/

typedef enum HashTableStatus
{
	HASH_TABLE_SUCCESS = 0,
	HASH_TABLE_POINTER_NOT_INITIALIZE,
    HASH_TABLE_ALLOCATION_FAILED,
    HASH_TABLE_KEY_DUPLICATE,
    HASH_TABLE_KEY_NOT_FOUND
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
 * hashFunc - function that generate index for given key.
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
 * A function that destroys a specified hash table and set the hash table to null. 
 * If supplied with non-NULL destroyer function, frees key && || values in hash table. All
 * remaining data will be lost.
 *
 * Time Complexity: O(1)..O(n) (depends on memory freeing).
 *
 * Input:
 * hashTable - pointer to hash table to be deallocated.
 * keyDestroy - A function pointer to be used to destroy all keys entries in the hash table (may 
 * be NULL if unnecessary).
 * valueDestroy - A function pointer to be used to destroy all values entries in the hash table (may 
 * be NULL if unnecessary).
 *
 * Output:
 * None.
 *
 * Error: 
 * hash table pointer is not initialized, destroy is not possible.
 */
void HashTableDestroy(HashTable_t **hashTable, void (*keyDestroy)(void *key), void (*valueDestroy)(void *value));

/* Description:
 * A function that inserts a new entry into hash table. Key must be unique and destinct, value can
 * be NULL.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * hashTable - pointer to hash table to insert element.
 * key - pointer to the key to serve as index.
 * value - pointer to value to associate with the key.
 *
 * Output:
 * HASH_TABLE_POINTER_NOT_INITIALIZE - hashTable/key pointer is not initialize, insert is
 * not possible.
 * HASH_TABLE_KEY_DUPLICATE - the key is already there, duplicate is not allowed, insert is
 * not possible.
 * HASH_TABLE_ALLOCATION_FAILED - failed to allocate hash table entry.
 * HASH_TABLE_SUCCESS - hash table insert element succeeded.
 * 
 * Error: 
 * HASH_TABLE_POINTER_NOT_INITIALIZE - hashTable/key pointer is not initialize, insert is
 * not possible.
 * HASH_TABLE_KEY_DUPLICATE - the key is already there, duplicate is not allowed, insert is
 * not possible.
 * HASH_TABLE_ALLOCATION_FAILED - failed to allocate hash table entry.
 */
HashTableStatus_t HashTableInsert(HashTable_t *hashTable, const void *key, const void *value);

/* Description:
 * A function that removes element entry from a hash table. In case the entry is removed
 * pKey/pValue previously memory allocation is in user responsibility. 
 *
 * Time Complexity: O(1).
 *
 * Input:
 * hashTable - pointer to hash table to remove element from.
 * key - pointer to the key to serve as index to locate value.
 * pKey - pointer to the removed entry key from the hash table, if found.
 * pValue - pointer to the removed entry value from the hash table, if found.
 *
 * Output:
 * HASH_TABLE_POINTER_NOT_INITIALIZE - hashTable/key/pKey/pValue pointer is not
 * initialize, remove is not possible.
 * HASH_TABLE_KEY_NOT_FOUND - the key is not found, remove is not possible.
 * HASH_TABLE_SUCCESS - hash table insert element succeeded.
 * 
 * Error: 
 * HASH_TABLE_POINTER_NOT_INITIALIZE - hashTable/key/pKey/pValue pointer is not
 * initialize, remove is not possible.
 * HASH_TABLE_KEY_NOT_FOUND - the key is not found, remove is not possible.
 */
HashTableStatus_t HashTableRemove(HashTable_t *hashTable, const void *key, void **pKey, void **pValue);

/* Description:
 * A function that checks if an entry is exist in a specified hash table, by key, or not.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * hashTable - pointer to hash table to found element from.
 * key - pointer to the key to serve as index to locate value.
 * pValue - pointer to the removed entry value from the hash table, if found.
 *
 * Output:
 * HASH_TABLE_POINTER_NOT_INITIALIZE - hashTable/key/pValue pointer is not
 * initialize, is found is not possible.
 * HASH_TABLE_KEY_NOT_FOUND - the key is not found.
 * HASH_TABLE_SUCCESS - the hash table's key is found.
 * 
 * Error: 
 * HASH_TABLE_POINTER_NOT_INITIALIZE - hashTable/key/pValue pointer is not
 * initialize, is found is not possible.
 * HASH_TABLE_KEY_NOT_FOUND - the key is not found.
 */
HashTableStatus_t HashTableFind(const HashTable_t *hashTable, const void *key, void **pValue);

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
size_t HashTableSize(const HashTable_t *hashTable);

/* Description:
 * A function that iterates over a all hash table entries. The user provided action function, and 
 * the function will called for each element. the iteration will stop if action will return a zero 
 * for an element.
 * 
 * Time Complexity: O(n).
 *
 * Input:
 * hashTable - pointer to hash table to iterator from.
 * actionFunc - User provided function pointer to be invoked for each element.
 * context - User provided context, will be sent to actionFunc.
 * 
 * Output:
 * POINTER_NOT_INITIALIZE_HASH_FOR_EACH - hashTable/actionFunc pointer is not initialized, 
 * for each is not possible.
 * number of times the user functions was invokeded.
 * 
 * Error: 
 * POINTER_NOT_INITIALIZE_HASH_FOR_EACH - hashTable/actionFunc pointer is not initialized, 
 * for each is not possible.
 */
size_t HashTableForEach(const HashTable_t *hashTable, ActionFunction_t actionFunc, void *context);

#endif /* __HASH_TABLE_MAP_H__ */
