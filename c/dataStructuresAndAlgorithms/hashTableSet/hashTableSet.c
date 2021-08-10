#include <stdlib.h> /* malloc, free, size_t */
#include <math.h> /* sqrt */
#include "hashTableSet.h" /* Hash Table Set Header */

#define IS_NOT_PRIME_NUM (0)
#define IS_PRIME_NUM (1)
#define IS_NOT_FOUND (0)
#define IS_FOUND (1)

struct HashTable
{
    void **m_arrOfElements;
    char *m_arrOfIndexesStatus;
    HashFunc_t m_hashFunc;
    EqualityFunc_t m_equalityFunc;
    size_t m_originalCapacity;
    size_t m_realCapacity;
    size_t m_numOfElements;
    size_t m_maxRehashOperations;
    size_t m_countInsertions;
    size_t m_countRehashOperations;
};

typedef enum Status
{
    EMPTY = 0,
    FULL = 1,
    EMPTY_AND_WAS_FULL = 2
} Status_t;

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static int IsPrimeNumber(size_t _num, size_t _numSquare);
static size_t FindRealCapacity(size_t _capacity);
static void DestroyElements(HashTable_t *_hashTable, void (*_elementDestroy)(void *element));
static size_t Rehash(size_t _hashKey, size_t _realCapacity);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

HashTable_t *HashTableCreate(size_t _capacity, HashFunc_t _hashFunc, EqualityFunc_t _equalityFunc)
{
    HashTable_t *hashTable = NULL;
    size_t realCapacity;

    if (_capacity < 2 || !_hashFunc || !_equalityFunc)
    {
        return NULL;
    }

    hashTable = (HashTable_t*)malloc(sizeof(HashTable_t));
    if (!hashTable)
    {
        return NULL;
    }

    realCapacity = FindRealCapacity(_capacity);

    hashTable->m_arrOfElements = (void**)malloc(realCapacity * sizeof(void*));
    if (!hashTable->m_arrOfElements)
    {
        free(hashTable);
        return NULL;
    }

    hashTable->m_arrOfIndexesStatus = (char*)calloc(realCapacity, sizeof(char));
    if (!hashTable->m_arrOfIndexesStatus)
    {
        free(hashTable->m_arrOfElements);
        free(hashTable);
        return NULL;
    }

    hashTable->m_hashFunc = _hashFunc;
    hashTable->m_equalityFunc = _equalityFunc;
    hashTable->m_originalCapacity = _capacity;
    hashTable->m_realCapacity = realCapacity;
    hashTable->m_numOfElements = 0;
    hashTable->m_maxRehashOperations = 0;
    hashTable->m_countInsertions = 0;
    hashTable->m_countRehashOperations = 0;

    return hashTable;
}

void HashTableDestroy(HashTable_t **_hashTable, void (*_elementDestroy)(void *element))
{
    if (!_hashTable || !*_hashTable)
    {
        return;
    }

    if (_elementDestroy)
    {
        DestroyElements(*_hashTable, _elementDestroy);
    }

    free((*_hashTable)->m_arrOfElements);
    free((*_hashTable)->m_arrOfIndexesStatus);
    free(*_hashTable);

    *_hashTable = NULL;
}

HashTableStatus_t HashTableInsert(HashTable_t *_hashTable, void *_element)
{
    size_t maxRehash = 0;
    size_t hashKey;

    if (!_hashTable || !_element)
    {
        return HASH_TABLE_POINTER_NOT_INITIALIZE;
    }

    if (_hashTable->m_originalCapacity == _hashTable->m_numOfElements)
    {
        return HASH_TABLE_OVERFLOW;
    }

    if (HashTableIsFound(_hashTable, _element))
    {   
        return HASH_TABLE_DUPLICATE_FOUND;
    }

    hashKey = _hashTable->m_hashFunc(_element) % _hashTable->m_realCapacity;

    while (1)
    {
        if (FULL != _hashTable->m_arrOfIndexesStatus[hashKey])
        {
            _hashTable->m_arrOfElements[hashKey] = _element;
            _hashTable->m_arrOfIndexesStatus[hashKey] = FULL;

            ++_hashTable->m_numOfElements;
            ++_hashTable->m_countInsertions;

            break;
        }

        ++_hashTable->m_countRehashOperations;
        ++maxRehash;

        hashKey = Rehash(hashKey, _hashTable->m_realCapacity);
    } 

    if (_hashTable->m_maxRehashOperations < maxRehash)
    {
        _hashTable->m_maxRehashOperations = maxRehash;
    }

    return HASH_TABLE_SUCCESS;
}

HashTableStatus_t HashTableRemove(HashTable_t *_hashTable, void *_elementToBeFreed, void **_freedElement)
{
    size_t maxRehash, hashKey;

    if (!_hashTable || !_elementToBeFreed || !_freedElement)
    {
        return HASH_TABLE_POINTER_NOT_INITIALIZE;
    }

    hashKey = _hashTable->m_hashFunc(_elementToBeFreed) % _hashTable->m_realCapacity;

    for (maxRehash = 0;maxRehash <= _hashTable->m_maxRehashOperations;++maxRehash)
    {
        if (FULL == _hashTable->m_arrOfIndexesStatus[hashKey] && _hashTable->m_equalityFunc(_hashTable->m_arrOfElements[hashKey], _elementToBeFreed))
        {
            *_freedElement = _hashTable->m_arrOfElements[hashKey];
            _hashTable->m_arrOfIndexesStatus[hashKey] = EMPTY_AND_WAS_FULL;

            --_hashTable->m_numOfElements;

            return HASH_TABLE_SUCCESS;
        }
        else if (_hashTable->m_arrOfIndexesStatus[hashKey] == EMPTY)
        {
            break;
        }

        hashKey = Rehash(hashKey, _hashTable->m_realCapacity);
    }

    return HASH_TABLE_ELEMENT_IS_NOT_FOUND;
}

int HashTableIsFound(const HashTable_t *_hashTable, void *_element)
{
    size_t maxRehash, hashKey;

    if (!_hashTable || !_element)
    {
        return POINTER_NOT_INITIALIZE_HASH_IS_FOUND;
    }

    hashKey = _hashTable->m_hashFunc(_element) % _hashTable->m_realCapacity;

    for (maxRehash = 0;maxRehash <= _hashTable->m_maxRehashOperations;++maxRehash)
    {
        if (FULL == _hashTable->m_arrOfIndexesStatus[hashKey] && _hashTable->m_equalityFunc(_hashTable->m_arrOfElements[hashKey], _element))
        {
            return IS_FOUND;
        }
        else if (_hashTable->m_arrOfIndexesStatus[hashKey] == EMPTY)
        {
            break;
        }

        hashKey = Rehash(hashKey, _hashTable->m_realCapacity);
    }

    return IS_NOT_FOUND;
}

size_t HashTableNumOfElements(const HashTable_t *_hashTable)
{
    if (!_hashTable)
    {
        return POINTER_NOT_INITIALIZE_HASH_NUM_OF_ELEMENTS;
    }

    return _hashTable->m_numOfElements;
}

size_t HashTableCapacity(const HashTable_t *_hashTable)
{
    if (!_hashTable)
    {
        return POINTER_NOT_INITIALIZE_HASH_CAPACITY;
    }

    return _hashTable->m_originalCapacity;
}

double HashTableAvgRehashes(const HashTable_t *_hashTable)
{
    if (!_hashTable)
    {
        return POINTER_NOT_INITIALIZE_HASH_AVERAGE_REHASHES;
    }

    return !_hashTable->m_countInsertions ? 0 : ((double)_hashTable->m_countRehashOperations / _hashTable->m_countInsertions);
}

size_t HashTableMaxRehashes(const HashTable_t *_hashTable)
{
    if (!_hashTable)
    {
        return POINTER_NOT_INITIALIZE_HASH_MAX_REHASHES;
    }

    return _hashTable->m_maxRehashOperations;
} 

void HashTablePrint(const HashTable_t *_hashTable, void (*_PrintElement)(void *element, size_t hashKey))
{
    size_t i;
    
    if (!_hashTable || !_PrintElement)
    {
        return;
    }

    for (i = 0;i < _hashTable->m_realCapacity;++i)
    {
        if (FULL == _hashTable->m_arrOfIndexesStatus[i])
        {
            _PrintElement(_hashTable->m_arrOfElements[i], i);
        }
    }
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

static size_t FindRealCapacity(size_t _capacity)
{
    size_t realCapacity = _capacity * 1.3;
    size_t realCapacitySquare;

    while (1)
    {
        realCapacitySquare = sqrt(realCapacity);

        if (IS_PRIME_NUM == IsPrimeNumber(realCapacity, realCapacitySquare))
        {
            break;
        }

        ++realCapacity;
    }

    return realCapacity;
}

static void DestroyElements(HashTable_t *_hashTable, void (*_elementDestroy)(void *element))
{
    size_t i;

    for (i = 0;i < _hashTable->m_realCapacity;++i)
    {
        if (FULL == _hashTable->m_arrOfIndexesStatus[i])
        {
            _elementDestroy(_hashTable->m_arrOfElements[i]);
        }
    }
}

static size_t Rehash(size_t _hashKey, size_t _realCapacity)
{
    return ++_hashKey % _realCapacity;
}