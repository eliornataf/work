#include <stdlib.h> /* malloc, free, calloc, size_t */
#include <math.h> /* sqrt */
#include "hashTableMap.h" /* Hash Table Map Header */
#include "genericDoublyLinkedList.h" /* Generic Doubly Linked List Header */
#include "listIter.h" /* List Iterator Header */
#include "listFunctions.h" /* List Function Header */

/*****************************************************************************/

#define IS_NOT_PRIME_NUM (0)
#define IS_PRIME_NUM (1)
#define DO_NOT_FREE_ENTRIES (0)
#define FREE_ENTRIES (1)
#define STOP (0)
#define CONTINUE (1)
#define IS_NOT_FOUND (0)
#define IS_FOUND (1)

typedef void (*DestroyFunc_t)(void *entry);

/*****************************************************************************/

struct HashTable
{
    List_t **m_hashArr;
    HashFunc_t m_hashFunc;
    EqualityFunc_t m_equalityFunc;
    size_t m_realCapacity;
    size_t m_numOfElements;
};

typedef struct Entry
{
    void *m_key;
    void *m_value;
} Entry_t;

typedef struct EntryDestroyer
{
    DestroyFunc_t m_keyDestroy;
    DestroyFunc_t m_valueDestroy;
} EntryDestroyer_t;

typedef struct EntryFinder
{
    void *m_keyToFind;
    EqualityFunc_t m_equalityFunc;
} EntryFinder_t;

typedef struct EntryForEach
{
    void *m_userContext;
    ActionFunction_t m_actionFunc;
    size_t m_countFuncInvoked;
} EntryForEach_t;

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static int IsPrimeNumber(size_t _num, size_t _numSquare);
static size_t FindTheClosetPrimeNumber(size_t _capacity);
static void FreeEntry(void *_entry);
static int FreeKeyValue(void *_entry, void *_entryDestroyer);
static int IsKeysEqual(void *_entry, void *_entryFinder);
static ListIter_t FindEntry(const HashTable_t *_hashTable, const void *_keyToFind, size_t _hashKey);
static int ExtractEntryForEach(void *_entry, void *_entryForEach);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

HashTable_t *HashTableCreate(size_t _capacity, HashFunc_t _hashFunc, EqualityFunc_t _equalityFunc)
{
    HashTable_t *hashTable = NULL;

    if (_capacity < 2 || !_hashFunc || !_equalityFunc)
    {
        return NULL;
    }

    hashTable = (HashTable_t*)malloc(sizeof(HashTable_t));
    if (!hashTable)
    {
        return NULL;
    }

    hashTable->m_realCapacity = FindTheClosetPrimeNumber(_capacity);

    hashTable->m_hashArr = (List_t**)calloc(hashTable->m_realCapacity, sizeof(List_t*));
    if (!hashTable->m_hashArr)
    {
        free(hashTable);
        return NULL;
    }

    hashTable->m_hashFunc = _hashFunc;
    hashTable->m_equalityFunc = _equalityFunc;
    hashTable->m_numOfElements = 0;

    return hashTable;
}

void HashTableDestroy(HashTable_t **_hashTable, void (*_keyDestroy)(void *key), void (*_valueDestroy)(void *value))
{
    int isFreeEntryNeeded = DO_NOT_FREE_ENTRIES;
    EntryDestroyer_t entryDestroyer;
    size_t i;

    if (!_hashTable || !*_hashTable)
    {
        return;
    }

    if (_keyDestroy ||  _valueDestroy)
    {
        entryDestroyer.m_keyDestroy = _keyDestroy;
        entryDestroyer.m_valueDestroy = _valueDestroy;

        isFreeEntryNeeded = FREE_ENTRIES;
    }

    for (i = 0;i < (*_hashTable)->m_realCapacity;++i)
    {
        if ((*_hashTable)->m_hashArr[i])
        {
            if (FREE_ENTRIES == isFreeEntryNeeded)
            {
                ListIterForEach(ListIterBegin((*_hashTable)->m_hashArr[i]), ListIterEnd((*_hashTable)->m_hashArr[i]), FreeKeyValue, (void*)&entryDestroyer);
            }

            ListDestory(&((*_hashTable)->m_hashArr[i]), FreeEntry);
        }
    }

    free((*_hashTable)->m_hashArr);
    free(*_hashTable);

    *_hashTable = NULL;
}

HashTableStatus_t HashTableInsert(HashTable_t *_hashTable, const void *_key, const void *_value)
{
    Entry_t *entry = NULL;
    size_t hashKey;

    if (!_hashTable || !_key)
    {
        return HASH_TABLE_POINTER_NOT_INITIALIZE;
    }

    hashKey = _hashTable->m_hashFunc(_key) % _hashTable->m_realCapacity;

    if (!_hashTable->m_hashArr[hashKey])
    {
        _hashTable->m_hashArr[hashKey] = ListCreate();
        if (!_hashTable->m_hashArr[hashKey])
        {
            return HASH_TABLE_ALLOCATION_FAILED;
        }
    }
    else
    {
        if (FindEntry(_hashTable, _key, hashKey)) 
        {
            return HASH_TABLE_KEY_DUPLICATE;
        }
    }

    entry = (Entry_t*)malloc(sizeof(Entry_t));
    if (!entry)
    {
        return HASH_TABLE_ALLOCATION_FAILED;
    }

    entry->m_key = (void*)_key;
    entry->m_value = (void*)_value;

    if (DLIST_SUCCESS != ListPushTail(_hashTable->m_hashArr[hashKey], entry))
    {
        free(entry);
        return HASH_TABLE_ALLOCATION_FAILED;
    }

    ++_hashTable->m_numOfElements;

    return HASH_TABLE_SUCCESS;
}  

HashTableStatus_t HashTableRemove(HashTable_t *_hashTable, const void *_key, void **_pKey, void **_pValue)
{
    ListIter_t foundIter = NULL;
    Entry_t *entry = NULL;
    size_t hashKey;

    if (!_hashTable || !_key || !_pKey || !_pValue)
    {
        return HASH_TABLE_POINTER_NOT_INITIALIZE;
    }

    hashKey = _hashTable->m_hashFunc(_key) % _hashTable->m_realCapacity;

    if (!_hashTable->m_hashArr[hashKey])
    {
        return HASH_TABLE_KEY_NOT_FOUND;
    }

    foundIter = FindEntry(_hashTable, _key, hashKey);

    if (!foundIter)
    {
        return HASH_TABLE_KEY_NOT_FOUND;
    }

    entry = (Entry_t*)ListIterRemove(foundIter);

    *_pKey = entry->m_key;
    *_pValue = entry->m_value;

    free(entry);

    --_hashTable->m_numOfElements;

    return HASH_TABLE_SUCCESS;
}

HashTableStatus_t HashTableFind(const HashTable_t *_hashTable, const void *_key, void **_pValue)
{
    ListIter_t foundIter = NULL;
    size_t hashKey;

    if (!_hashTable || !_key || !_pValue)
    {
        return HASH_TABLE_POINTER_NOT_INITIALIZE;
    }

    hashKey = _hashTable->m_hashFunc(_key) % _hashTable->m_realCapacity;

    if (_hashTable->m_hashArr[hashKey])
    {
        foundIter = FindEntry(_hashTable, _key, hashKey);

        if (!foundIter)
        {
            return HASH_TABLE_KEY_NOT_FOUND;
        }
    }

    *_pValue = ((Entry_t*)ListIterGet(foundIter))->m_value;

    return HASH_TABLE_SUCCESS;
}

size_t HashTableSize(const HashTable_t *_hashTable)
{
    if (!_hashTable)
    {
        return POINTER_NOT_INITIALIZE_HASH_SIZE;
    }

    return _hashTable->m_numOfElements;
}

size_t HashTableForEach(const HashTable_t *_hashTable, ActionFunction_t _actionFunc, void *_context)
{
    EntryForEach_t entryForEach;
    size_t i;

    if (!_hashTable || !_actionFunc)
    {
        return POINTER_NOT_INITIALIZE_HASH_FOR_EACH;
    }

    entryForEach.m_userContext = _context;
    entryForEach.m_actionFunc = _actionFunc;
    entryForEach.m_countFuncInvoked = 0;

    for (i = 0;i < _hashTable->m_realCapacity;++i)
    {
        if (_hashTable->m_hashArr[i])
        {
            if (!ListIterForEach(ListIterBegin(_hashTable->m_hashArr[i]), ListIterEnd(_hashTable->m_hashArr[i]), ExtractEntryForEach, (void*)&entryForEach))
            {
                break;
            }
        }
    }

    return entryForEach.m_countFuncInvoked;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static int IsPrimeNumber(size_t _num, size_t _numSquare)
{
    size_t i;

    for (i = 2;i <= _numSquare;++i)
    {
        if (!(_num % i))
        {
            return IS_NOT_PRIME_NUM;
        }
    }

    return IS_PRIME_NUM;
}

static size_t FindTheClosetPrimeNumber(size_t _capacity)
{
    while (1)
    {
        if (IS_PRIME_NUM == IsPrimeNumber(_capacity, sqrt(_capacity)))
        {
            break;
        }

        ++_capacity;
    }

    return _capacity;
}

static void FreeEntry(void *_entry)
{
    free(_entry);
} 

static int FreeKeyValue(void *_entry, void *_entryDestroyer)
{
    if (((EntryDestroyer_t*)_entryDestroyer)->m_keyDestroy)
    {
        ((EntryDestroyer_t*)_entryDestroyer)->m_keyDestroy(((Entry_t*)_entry)->m_key);
    }

    if (((EntryDestroyer_t*)_entryDestroyer)->m_valueDestroy)
    {
        ((EntryDestroyer_t*)_entryDestroyer)->m_valueDestroy(((Entry_t*)_entry)->m_value);
    }

    return CONTINUE;
}

static int IsKeysEqual(void *_entry, void *_entryFinder)
{
    if ( ((EntryFinder_t*)_entryFinder)->m_equalityFunc( ((Entry_t*)_entry)->m_key, ((EntryFinder_t*)_entryFinder)->m_keyToFind ) )
    {
        return IS_FOUND;
    }

    return IS_NOT_FOUND;
}

static ListIter_t FindEntry(const HashTable_t *_hashTable, const void *_keyToFind, size_t _hashKey)
{
    ListIter_t foundIter = NULL;
    EntryFinder_t entryFinder;

    entryFinder.m_keyToFind = (void*)_keyToFind;
    entryFinder.m_equalityFunc = _hashTable->m_equalityFunc;

    foundIter = ListIterFindFirst (ListIterBegin(_hashTable->m_hashArr[_hashKey]), ListIterEnd(_hashTable->m_hashArr[_hashKey]), IsKeysEqual, (void*)&entryFinder );

    return (ListIterEqual(foundIter, ListIterEnd(_hashTable->m_hashArr[_hashKey]))) ? NULL : foundIter;
}

static int ExtractEntryForEach(void *_entry, void *_entryForEach)
{
    ++((EntryForEach_t*)_entryForEach)->m_countFuncInvoked;

    if ( !((EntryForEach_t*)_entryForEach)->m_actionFunc( ((Entry_t*)_entry)->m_key, ((Entry_t*)_entry)->m_value, ((EntryForEach_t*)_entryForEach)->m_userContext) )
    {
        return STOP;
    }

    return CONTINUE;
}