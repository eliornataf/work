#include <stdio.h> /* printf */
#include <stdlib.h> /* free */
#include "hashTableMap.h" /* Hash Table Map Header */
#include "genericDoublyLinkedList.h" /* Generic Doubly Linked List Header */
#include "internal.h" /* Internal Header */
#include "listIter.h" /* List Iterator Header */
#include "listFunctions.h" /* List Function Header */

#define CAPACITY 10

#define ARR_SIZE (10000)

#define CONTINUE (1)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

/*********************************************************************************/

static size_t HashFunc(const void *_element)
{
    return (*(int*)_element * 3);
}

static int EqualityFunc(const void *_firstElement, const void *_secondElement)
{
    return (*(int*)_firstElement == *(int*)_secondElement);
}

static void FreeElement(void *_element)
{
	free(_element);
}

static int PrintHashTable(void *_key, void *_value, void *_context)
{
    (void)_context;

    printf("key number is: %d value is: %d\n", *(int*)_key, *(int*)_value);

    return CONTINUE;
}

/*********************************************************************************/

void hashTableCreateTest1(void)
{
	HashTable_t *hashTableTest = NULL;

	printf("\033[1;34m\n*******Hash Table Create Test 1:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");
	
	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableCreateTest2(void)
{
	HashTable_t *hashTableTest = NULL;

	printf("\033[1;34m\n*******Hash Table Create Test 2:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(1, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL == hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL == hashTableTest) - capacity is 1\n");
	
	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableCreateTest3(void)
{
	HashTable_t *hashTableTest = NULL;

	printf("\033[1;34m\n*******Hash Table Create Test 3:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, NULL, EqualityFunc);
	
	CHECK_FUNC(NULL == hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL == hashTableTest) - HashFunc is NULL\n");
	
	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableCreateTest4(void)
{
	HashTable_t *hashTableTest = NULL;

	printf("\033[1;34m\n*******Hash Table Create Test 4:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, NULL);
	
	CHECK_FUNC(NULL == hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL == hashTableTest) - EqualityFunc is NULL\n");
	
	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableDestroyTest(void)
{
	HashTable_t *hashTableTest = NULL;
    int *key = NULL;
    int *value = NULL;
    int status;

    key = (int*)malloc(sizeof(int));
    value = (int*)malloc(sizeof(int));
    
    if (NULL == key || NULL == value)
    {
        return;
    }

    *key = 4;
    *value = 5;

	printf("\033[1;34m\n*******Hash Table Destroy Test:*******\n\n\033[0m");

	printf("number of insert = 1\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nInsert Func Test:\n\n");

	status = HashTableInsert(hashTableTest, key, value);
		
	printf("Insert number 1 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	
    printf("\nExpected: 1 SUCCESS (check status)\n");

	HashTableDestroy(&hashTableTest, FreeElement, FreeElement);
}

void hashTableInsertTest1(void)
{
	HashTable_t *hashTableTest = NULL;
    int keyArr[ARR_SIZE];
    int valueArr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Insert Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 5\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 5;++i)
	{
		keyArr[i] = i;

        valueArr[i] = i + 10;

		status = HashTableInsert(hashTableTest, &keyArr[i], &valueArr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 5 SUCCESS (check status)\n");

	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableInsertTest2(void)
{
	HashTable_t *hashTableTest = NULL;
    int keyArr[ARR_SIZE];
    int valueArr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Insert Test 2:*******\n\n\033[0m");
	
	printf("number of insert = 100\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 100;++i)
	{
		keyArr[i] = i;

        valueArr[i] = i + 10;

		status = HashTableInsert(hashTableTest, &keyArr[i], &valueArr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 100 SUCCESS (check status)\n");

	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableInsertTest3(void)
{
	HashTable_t *hashTableTest = NULL;
    int keyArr[ARR_SIZE];
    int *value = NULL;
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Insert Test 3:*******\n\n\033[0m");
	
	printf("number of insert = 8\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nInsert Func Test 1:\n\n");

    keyArr[0] = 10;
    keyArr[1] = 5;
    keyArr[2] = 10;

    for (i = 0;i < 3;++i)
	{
		status = HashTableInsert(hashTableTest, &keyArr[i], value);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 2 SUCCESS 1 FAILURE (check status) - duplicate\n");

    printf("\nInsert Func Test 2:\n\n");

    keyArr[3] = 20;
    keyArr[4] = 6;
    keyArr[5] = 4;
    keyArr[6] = 7;
    keyArr[7] = 2;

    for (i = 3;i < 8;++i)
	{
		status = HashTableInsert(hashTableTest, &keyArr[i], value);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}

    printf("\nExpected: 5 SUCCESS (check status)\n");

	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableInsertTest4(void)
{
	HashTable_t *hashTableTest = NULL;
    int *key = NULL;
    int *value = NULL;
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Insert Test 4:*******\n\n\033[0m");
	
	printf("number of insert = 2\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 2;++i)
	{
		status = HashTableInsert(hashTableTest, key, value);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_POINTER_NOT_INITIALIZE == status);
	}
	
    printf("\nExpected: 2 SUCCESS (check status) - key is NULL\n");

	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableInsertTest5(void)
{
	HashTable_t *hashTableTest = NULL;
    int keyArr[ARR_SIZE];
    int valueArr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Insert Test 5:*******\n\n\033[0m");
	
	printf("number of insert = 2\n\n");

    printf("Insert Func Test:\n\n");

    for (i = 0;i < 2;++i)
	{
		keyArr[i] = i;

        valueArr[i] = i;

		status = HashTableInsert(hashTableTest, &keyArr[i], &valueArr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_POINTER_NOT_INITIALIZE == status);
	}
	
    printf("\nExpected: 2 SUCCESS (check status) - hashTableTest is NULL\n");

	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableRemoveTest1(void)
{
	HashTable_t *hashTableTest = NULL;
    void *pKey = NULL;
    void *pValue = NULL;
    int keyArr[ARR_SIZE];
    int valueArr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Remove Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 9, number of remove = 3\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 9;++i)
	{
		keyArr[i] = i;

        valueArr[i] = i;

		status = HashTableInsert(hashTableTest, &keyArr[i], &valueArr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 9 SUCCESS (check status)\n");

    printf("\nRemove Func Test 1:\n\n");

	status = HashTableRemove(hashTableTest, &keyArr[0], &pKey, &pValue);
		
	printf("Remove number 1 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 1 check (value): ");

    CHECK_FUNC(0 == *(int*)pKey);

    printf("Remove number 1 check (value): ");

    CHECK_FUNC(0 == *(int*)pValue);

    printf("\nRemove Func Test 2:\n\n");

	status = HashTableRemove(hashTableTest, &keyArr[7], &pKey, &pValue);
		
	printf("Remove number 2 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 2 check (value): ");

    CHECK_FUNC(7 == *(int*)pKey);

    printf("Remove number 2 check (value): ");

    CHECK_FUNC(7 == *(int*)pValue);

    printf("\nRemove Func Test 3:\n\n");

	status = HashTableRemove(hashTableTest, &keyArr[2], &pKey, &pValue);
		
	printf("Remove number 3 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 3 check (value): ");

    CHECK_FUNC(2 == *(int*)pKey);

    printf("Remove number 3 check (value): ");

    CHECK_FUNC(2 == *(int*)pValue);

    printf("\nSize Func Test: ");

    CHECK_FUNC(6 == HashTableSize(hashTableTest));

    printf("\nExpected: 10 SUCCESS (check status + value)\n");

	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableRemoveTest2(void)
{
	HashTable_t *hashTableTest = NULL;
    void *pKey = NULL;
    void *pValue = NULL;
    int keyArr[ARR_SIZE];
    int valueArr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Remove Test 2:*******\n\n\033[0m");
	
	printf("number of insert = 9, number of remove = 2\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 9;++i)
	{
		keyArr[i] = i;

        valueArr[i] = i;

		status = HashTableInsert(hashTableTest, &keyArr[i], &valueArr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 9 SUCCESS (check status)\n");

    printf("\nRemove Func Test 1:\n\n");

	status = HashTableRemove(hashTableTest, &keyArr[0], &pKey, &pValue);
		
	printf("Remove number 1 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 1 check (pKey value): ");

    CHECK_FUNC(0 == *(int*)pKey);

    printf("Remove number 1 check (pValue value): ");

    CHECK_FUNC(0 == *(int*)pValue);

    printf("\nRemove Func Test 2:\n\n");

    status = HashTableRemove(hashTableTest, &keyArr[0], &pKey, &pValue);

    printf("Remove number 2 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_KEY_NOT_FOUND == status);

    printf("\nExpected: 2 SUCCESS (check status) 2 SUCCESS (check value) - is already freed\n");

	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableRemoveTest3(void)
{
	HashTable_t *hashTableTest = NULL;
    void *pKey = NULL;
    void *pValue = NULL;
    int keyArr[ARR_SIZE];
    int valueArr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Remove Test 3:*******\n\n\033[0m");
	
	printf("number of insert = 9, number of remove = 1\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nInsert Func Test 1:\n\n");

    for (i = 0;i < 9;++i)
	{
		keyArr[i] = i;

        valueArr[i] = i;

		status = HashTableInsert(hashTableTest, &keyArr[i], &valueArr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 9 SUCCESS (check status)\n");

    printf("\nRemove Func Test 1:\n\n");

	status = HashTableRemove(hashTableTest, &keyArr[0], &pKey, &pValue);
		
	printf("Remove number 1 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 1 check (pKey value): ");

    CHECK_FUNC(0 == *(int*)pKey);

    printf("Remove number 1 check (pValue value): ");

    CHECK_FUNC(0 == *(int*)pValue);

    printf("\nInsert Func Test 2:\n\n");

	status = HashTableInsert(hashTableTest, &keyArr[0], &valueArr[0]);
		
	printf("Insert number 1 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("\nExpected: 4 SUCCESS (check status + value)\n");

	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableRemoveTest4(void)
{
	HashTable_t *hashTableTest = NULL;
    void *key = NULL;
    void *pKey = NULL;
    void *pValue = NULL;
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Remove Test 4:*******\n\n\033[0m");
	
	printf("number of remove = 2\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nRemove Func Test:\n\n");

    for (i = 0;i < 2;++i)
	{
	    status = HashTableRemove(hashTableTest, key, &pKey, &pValue);
		
		printf("Remove number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_POINTER_NOT_INITIALIZE == status);
	}
	
    printf("\nExpected: 2 SUCCESS (check status) - key/pKey/pValue is NULL\n");

	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableRemoveTest5(void)
{
	HashTable_t *hashTableTest = NULL;
    void *key = NULL;
    void *pKey = NULL;
    void *pValue = NULL;
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Remove Test 5:*******\n\n\033[0m");
	
	printf("number of remove = 2\n\n");

    printf("Remove Func Test:\n\n");

    for (i = 0;i < 2;++i)
	{
		status = HashTableRemove(hashTableTest, key, &pKey, &pValue);
		
		printf("Remove number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_POINTER_NOT_INITIALIZE == status);
	}
	
    printf("\nExpected: 2 SUCCESS (check status) - hashTableTest is NULL\n");

	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableFindTest1(void)
{
	HashTable_t *hashTableTest = NULL;
    void *pKey = NULL;
    void *pValue = NULL;
    int foundElement1 = 12;
    int foundElement3 = 4;
    int keyArr[ARR_SIZE];
    int valueArr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Find Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 9, number of remove = 3, number of find = 4\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 9;++i)
	{
		keyArr[i] = i;

        valueArr[i] = i;

		status = HashTableInsert(hashTableTest, &keyArr[i], &valueArr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 9 SUCCESS (check status)\n");

    printf("\nFind Func Test 1 (status): ");

    status = HashTableFind(hashTableTest, &keyArr[0], &pValue);
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Find Func Test 1 (value): ");

    CHECK_FUNC(0 == *(int*)pValue);

    printf("\nFind Func Test 2 (status): ");

    status = HashTableFind(hashTableTest, &foundElement1, &pValue);
		
	CHECK_FUNC(HASH_TABLE_KEY_NOT_FOUND == status);

    printf("\nRemove Func Test 1:\n\n");

	status = HashTableRemove(hashTableTest, &keyArr[0], &pKey, &pValue);
		
	printf("Remove number 1 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 1 check (pKey value): ");

    CHECK_FUNC(0 == *(int*)pKey);

    printf("Remove number 1 check (pValue value): ");

    CHECK_FUNC(0 == *(int*)pValue);

    printf("\nFind Func Test 3 (status): ");

    status = HashTableFind(hashTableTest, &foundElement1, &pValue);
		
	CHECK_FUNC(HASH_TABLE_KEY_NOT_FOUND == status);

    printf("\nRemove Func Test 2:\n\n");

    status = HashTableRemove(hashTableTest, &keyArr[7], &pKey, &pValue);
		
	printf("Remove number 2 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 2 check (value): ");

    CHECK_FUNC(7 == *(int*)pKey);

    printf("Remove number 2 check (value): ");

    CHECK_FUNC(7 == *(int*)pValue);

    printf("\nRemove Func Test 3:\n\n");

    status = HashTableRemove(hashTableTest, &keyArr[4], &pKey, &pValue);
		
	printf("Remove number 2 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 2 check (value): ");

    CHECK_FUNC(4 == *(int*)pKey);

    printf("\nFind Func Test 4 (status): ");

    status = HashTableFind(hashTableTest, &foundElement3, &pValue);
		
	CHECK_FUNC(HASH_TABLE_KEY_NOT_FOUND == status);

    printf("\nExpected: 13 SUCCESS (check status + value)\n");

	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableFindTest2(void)
{
	HashTable_t *hashTableTest = NULL;
    void *pValue = NULL;
    int *key = NULL;
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Find Test 2:*******\n\n\033[0m");
	
	printf("number of find = 2\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nFind Func Test:\n\n");

    for (i = 0;i < 2;++i)
	{
	    status = HashTableFind(hashTableTest, key, &pValue);
		
		printf("Find number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_POINTER_NOT_INITIALIZE == status);
	}
	
    printf("\nExpected: 2 SUCCESS (check status) - key/pValue is NULL\n");

	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableFindTest3(void)
{
	HashTable_t *hashTableTest = NULL;
    void *pValue = NULL;
    int *key = NULL;
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Find Test 3:*******\n\n\033[0m");
	
	printf("number of find = 2\n\n");

    printf("Find Func Test:\n\n");

    for (i = 0;i < 2;++i)
	{
	    status = HashTableFind(hashTableTest, key, &pValue);
		
		printf("Find number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_POINTER_NOT_INITIALIZE == status);
	}
	
    printf("\nExpected: 2 SUCCESS (check status) - hashTableTest is NULL\n");

	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableSizeTest1(void)
{
	HashTable_t *hashTableTest = NULL;
    void *pKey = NULL;
    void *pValue = NULL;
    int keyArr[ARR_SIZE];
    int valueArr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Size Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 9, number of remove = 3, number of size = 4\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nSize Func Test 1: ");

    CHECK_FUNC(0 == HashTableSize(hashTableTest));

    printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 9;++i)
	{
		keyArr[i] = i;

        valueArr[i] = i;

		status = HashTableInsert(hashTableTest, &keyArr[i], &valueArr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 9 SUCCESS (check status)\n");

    printf("\nSize Func Test 2: ");

    CHECK_FUNC(9 == HashTableSize(hashTableTest));

    printf("\nRemove Func Test 1:\n\n");

	status = HashTableRemove(hashTableTest, &keyArr[0], &pKey, &pValue);
		
	printf("Remove number 1 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 1 check (value): ");

    CHECK_FUNC(0 == *(int*)pKey);

    printf("Remove number 1 check (value): ");

    CHECK_FUNC(0 == *(int*)pValue);

    printf("\nSize Func Test 3: ");

    CHECK_FUNC(8 == HashTableSize(hashTableTest));

    printf("\nRemove Func Test 2:\n\n");

	status = HashTableRemove(hashTableTest, &keyArr[7], &pKey, &pValue);
		
	printf("Remove number 2 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 2 check (value): ");

    CHECK_FUNC(7 == *(int*)pKey);

    printf("Remove number 2 check (value): ");

    CHECK_FUNC(7 == *(int*)pValue);

    printf("\nRemove Func Test 3:\n\n");

	status = HashTableRemove(hashTableTest, &keyArr[2], &pKey, &pValue);
		
	printf("Remove number 3 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 3 check (value): ");

    CHECK_FUNC(2 == *(int*)pKey);

    printf("Remove number 3 check (value): ");

    CHECK_FUNC(2 == *(int*)pValue);

    printf("\nSize Func Test 4: ");

    CHECK_FUNC(6 == HashTableSize(hashTableTest));

    printf("\nExpected: 12 SUCCESS (check status + value)\n");

	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableSizeTest2(void)
{
	HashTable_t *hashTableTest = NULL;

	printf("\033[1;34m\n*******Hash Table Size Test 1:*******\n\n\033[0m");
	
	printf("number of size = 1\n\n");

    printf("Size Func Test: ");
		
	CHECK_FUNC(POINTER_NOT_INITIALIZE_HASH_SIZE ==  HashTableSize(hashTableTest));
	
    printf("\nExpected: 1 SUCCESS (check status) - hashTableTest is NULL\n");

	HashTableDestroy(&hashTableTest, NULL, NULL);
}

void hashTableForEachTest1(void)
{
	HashTable_t *hashTableTest = NULL;
    int keyArr[ARR_SIZE];
    int valueArr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table ForEach Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 100\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 100;++i)
	{
		keyArr[i] = i;

        valueArr[i] = i;

		status = HashTableInsert(hashTableTest, &keyArr[i], &valueArr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 100 SUCCESS (check status)\n");

    printf("\nFor Each Func Test:\n\n");

    CHECK_FUNC(100 == HashTableForEach(hashTableTest, PrintHashTable, NULL));

    printf("\nExpected: 1 SUCCESS (value status)\n");

	HashTableDestroy(&hashTableTest, NULL, NULL);
}

int main(void)
{
    hashTableCreateTest1(); /* regular create */
    hashTableCreateTest2(); /* capacity error */
    hashTableCreateTest3(); /* HashFunc is null */
    hashTableCreateTest4(); /* equalityFunc is null */

    hashTableDestroyTest(); /* destroy key + value */ 

    hashTableInsertTest1(); /* insert 9 items */
    hashTableInsertTest2(); /* insert 100 items */
    hashTableInsertTest3(); /* duplicate key + value is null*/
    hashTableInsertTest4(); /* key is null */ 
    hashTableInsertTest5(); /* hash table is null */

    hashTableRemoveTest1(); /* remove 3 entries */
    hashTableRemoveTest2(); /* remove removed entry and find him (entry is not found) */
    hashTableRemoveTest3(); /* remove entry and insert entry with same key */
    hashTableRemoveTest4(); /* key/pkey/pvalue is null */
    hashTableRemoveTest5(); /* hash table is null */

    hashTableFindTest1(); /* find entries (try to find fake key entry) */
    hashTableFindTest2(); /* key/pvalue is null */
    hashTableFindTest3(); /* hash table is null */

    hashTableSizeTest1(); /* size 5 times (empty, with items, after remove) */
    hashTableSizeTest2(); /* hash table is null */

    hashTableForEachTest1(); /* print hash table */

    return 0;
}