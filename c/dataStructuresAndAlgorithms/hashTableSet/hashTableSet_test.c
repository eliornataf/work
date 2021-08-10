#include <stdio.h> /* printf */
#include <stdlib.h> /* free */
#include "hashTableSet.h" /* Hash Table Set Header */

#define CAPACITY 10
#define REAL_CAPACITY 13
#define ARR_SIZE (13)

#define IS_NOT_FOUND (0)
#define IS_FOUND (1)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

/*********************************************************************************/

static size_t HashFunc(const void *_element)
{
    return (*(int*)_element * 3) % REAL_CAPACITY;
}

static int EqualityFunc(const void *_firstElement, const void *_secondElement)
{
    return (*(int*)_firstElement == *(int*)_secondElement);
}

static void PrintElement(void *_element, size_t _hashKey)
{
    printf("index %ld element is %d\n", _hashKey, *(int*)_element);
}

/*********************************************************************************/

void HastTableCreateTest1(void)
{
	HashTable_t *hashTableTest = NULL;

	printf("\033[1;34m\n*******Hash Table Create Test 1:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");
	
	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableCreateTest2(void)
{
	HashTable_t *hashTableTest = NULL;

	printf("\033[1;34m\n*******Hash Table Create Test 2:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, NULL, EqualityFunc);
	
	CHECK_FUNC(NULL == hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL == hashTableTest) = HashFunc is NULL\n");
	
	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableCreateTest3(void)
{
	HashTable_t *hashTableTest = NULL;

	printf("\033[1;34m\n*******Hash Table Create Test 3:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, NULL);
	
	CHECK_FUNC(NULL == hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL == hashTableTest) = EqualityFunc is NULL\n");
	
	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableInsertTest1(void)
{
	HashTable_t *hashTableTest = NULL;
    int arr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Insert Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 9\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 9;++i)
	{
		arr[i] = i;

		status = HashTableInsert(hashTableTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 9 SUCCESS (check status)\n");

    printf("\nPrint Func Test:\n\n");

    HashTablePrint(hashTableTest, PrintElement);

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableInsertTest2(void)
{
	HashTable_t *hashTableTest = NULL;
    int arr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Insert Test 2:*******\n\n\033[0m");
	
	printf("number of insert = 8\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nInsert Func Test 1:\n\n");

    arr[0] = 10;
    arr[1] = 5;
    arr[2] = 10;

    for (i = 0;i < 3;++i)
	{
		status = HashTableInsert(hashTableTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 2 SUCCESS 1 FAILURE (check status) - duplicate\n");

    printf("\nPrint Func Test:\n\n");

    HashTablePrint(hashTableTest, PrintElement);

    printf("\nInsert Func Test 2:\n\n");

    arr[3] = 20;
    arr[4] = 6;
    arr[5] = 4;
    arr[6] = 7;
    arr[7] = 2;

    for (i = 3;i < 8;++i)
	{
		status = HashTableInsert(hashTableTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}

    printf("\nExpected: 5 SUCCESS (check status)\n");

    printf("\nPrint Func Test:\n\n");

    HashTablePrint(hashTableTest, PrintElement);

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableInsertTest3(void)
{
	HashTable_t *hashTableTest = NULL;
    int arr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Insert Test 3:*******\n\n\033[0m");
	
	printf("number of insert = 11\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 11;++i)
	{
		arr[i] = i;

		status = HashTableInsert(hashTableTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 10 SUCCESS 1 FAILURE (check status) - overflow\n");

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableInsertTest4(void)
{
	HashTable_t *hashTableTest = NULL;
    int *element = NULL;
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
		status = HashTableInsert(hashTableTest, element);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_POINTER_NOT_INITIALIZE == status);
	}
	
    printf("\nExpected: 2 SUCCESS (check status) - element is NULL\n");

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableInsertTest5(void)
{
	HashTable_t *hashTableTest = NULL;
    int arr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Insert Test 5:*******\n\n\033[0m");
	
	printf("number of insert = 2\n\n");

    printf("Insert Func Test:\n\n");

    for (i = 0;i < 2;++i)
	{
		arr[i] = i;

		status = HashTableInsert(hashTableTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_POINTER_NOT_INITIALIZE == status);
	}
	
    printf("\nExpected: 2 SUCCESS (check status) - hashTableTest is NULL\n");

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableRemoveTest1(void)
{
	HashTable_t *hashTableTest = NULL;
    void *freedElement = NULL;
    int arr[ARR_SIZE];
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
		arr[i] = i;

		status = HashTableInsert(hashTableTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 9 SUCCESS (check status)\n");

    printf("\nRemove Func Test 1:\n\n");

	status = HashTableRemove(hashTableTest, &arr[0], &freedElement);
		
	printf("Remove number 1 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 1 check (value): ");

    CHECK_FUNC(0 == *(int*)freedElement);

    printf("\nRemove Func Test 2:\n\n");

    status = HashTableRemove(hashTableTest, &arr[7], &freedElement);

    printf("Remove number 2 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 2 check (value): ");

    CHECK_FUNC(7 == *(int*)freedElement);

    printf("\nRemove Func Test 3:\n\n");

    status = HashTableRemove(hashTableTest, &arr[4], &freedElement);

    printf("Remove number 3 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 3 check (value): ");

    CHECK_FUNC(4 == *(int*)freedElement);

    printf("\nExpected: 3 SUCCESS (check status) 3 SUCCESS (check value)\n");

    printf("\nPrint Func Test:\n\n");

    HashTablePrint(hashTableTest, PrintElement);

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableRemoveTest2(void)
{
	HashTable_t *hashTableTest = NULL;
    void *freedElement = NULL;
    int arr[ARR_SIZE];
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
		arr[i] = i;

		status = HashTableInsert(hashTableTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 9 SUCCESS (check status)\n");

    printf("\nRemove Func Test 1:\n\n");

	status = HashTableRemove(hashTableTest, &arr[0], &freedElement);
		
	printf("Remove number 1 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 1 check (value): ");

    CHECK_FUNC(0 == *(int*)freedElement);

    printf("\nRemove Func Test 2:\n\n");

    status = HashTableRemove(hashTableTest, &arr[0], &freedElement);

    printf("Remove number 2 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_ELEMENT_IS_NOT_FOUND == status);

    printf("\nExpected: 2 SUCCESS (check status) 1 SUCCESS (check value) - is already freed\n");

    printf("\nPrint Func Test:\n\n");

    HashTablePrint(hashTableTest, PrintElement);

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableRemoveTest3(void)
{
	HashTable_t *hashTableTest = NULL;
    void *freedElement = NULL;
    int *element = NULL;
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Remove Test 3:*******\n\n\033[0m");
	
	printf("number of remove = 2\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nRemove Func Test:\n\n");

    for (i = 0;i < 2;++i)
	{
	    status = HashTableRemove(hashTableTest, element, &freedElement);
		
		printf("Remove number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_POINTER_NOT_INITIALIZE == status);
	}
	
    printf("\nExpected: 2 SUCCESS (check status) - element is NULL\n");

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableRemoveTest4(void)
{
	HashTable_t *hashTableTest = NULL;
    void *freedElement = NULL;
    int *element = NULL;
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Remove Test 4:*******\n\n\033[0m");
	
	printf("number of remove = 2\n\n");

    printf("Remove Func Test:\n\n");

    for (i = 0;i < 2;++i)
	{
		status = HashTableRemove(hashTableTest, element, &freedElement);
		
		printf("Remove number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_POINTER_NOT_INITIALIZE == status);
	}
	
    printf("\nExpected: 2 SUCCESS (check status) - hashTableTest is NULL\n");

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableIsFoundTest1(void)
{
	HashTable_t *hashTableTest = NULL;
    void *freedElement = NULL;
    int foundElement1 = 12;
    int foundElement2 = 0;
    int foundElement3 = 4;
    int foundElement4 = 2;
    int arr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Is Found Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 9, number of remove = 3, number of is found = 5\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 9;++i)
	{
		arr[i] = i;

		status = HashTableInsert(hashTableTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 9 SUCCESS (check status)\n");

    printf("\nIs Found Func Test 1: ");

    status = HashTableIsFound(hashTableTest, &arr[0]);
		
	CHECK_FUNC(IS_FOUND == status);

    printf("\nIs Found Func Test 2: ");

    status = HashTableIsFound(hashTableTest, &foundElement1);
		
	CHECK_FUNC(IS_NOT_FOUND == status);

    printf("\nRemove Func Test 1:\n\n");

	status = HashTableRemove(hashTableTest, &arr[0], &freedElement);
		
	printf("Remove number 1 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 1 check (value): ");

    CHECK_FUNC(0 == *(int*)freedElement);

    printf("\nIs Found Func Test 3: ");

    status = HashTableIsFound(hashTableTest, &foundElement2);
		
	CHECK_FUNC(IS_NOT_FOUND == status);

    printf("\nRemove Func Test 2:\n\n");

    status = HashTableRemove(hashTableTest, &arr[7], &freedElement);

    printf("Remove number 2 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 2 check (value): ");

    CHECK_FUNC(7 == *(int*)freedElement);

    printf("\nRemove Func Test 3:\n\n");

    status = HashTableRemove(hashTableTest, &arr[4], &freedElement);

    printf("Remove number 3 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 3 check (value): ");

    CHECK_FUNC(4 == *(int*)freedElement);

    printf("\nIs Found Func Test 4: ");

    status = HashTableIsFound(hashTableTest, &foundElement3);
		
	CHECK_FUNC(IS_NOT_FOUND == status);

    printf("\nIs Found Func Test 5: ");

    status = HashTableIsFound(hashTableTest, &foundElement4);
		
	CHECK_FUNC(IS_FOUND == status);

    printf("\nExpected: 3 SUCCESS (check status) 8 SUCCESS (check value)\n");

    printf("\nPrint Func Test:\n\n");

    HashTablePrint(hashTableTest, PrintElement);

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableIsFoundTest2(void)
{
	HashTable_t *hashTableTest = NULL;
    int *element = NULL;
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Is Found Test 2:*******\n\n\033[0m");
	
	printf("number of is found = 2\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nIs Found Func Test:\n\n");

    for (i = 0;i < 2;++i)
	{
	    status = HashTableIsFound(hashTableTest, element);
		
		printf("Is Found number %ld check (status): ", i + 1);
		
		CHECK_FUNC(POINTER_NOT_INITIALIZE_HASH_IS_FOUND == status);
	}
	
    printf("\nExpected: 2 SUCCESS (check status) - element is NULL\n");

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableIsFoundTest3(void)
{
	HashTable_t *hashTableTest = NULL;
    int *element = NULL;
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Is Found Test 2:*******\n\n\033[0m");
	
	printf("number of is found = 2\n\n");

    printf("Is Found Func Test:\n\n");

    for (i = 0;i < 2;++i)
	{
		status = HashTableIsFound(hashTableTest, element);
		
		printf("Is Found number %ld check (status): ", i + 1);
		
		CHECK_FUNC(POINTER_NOT_INITIALIZE_HASH_IS_FOUND == status);
	}
	
    printf("\nExpected: 2 SUCCESS (check status) - hashTableTest is NULL\n");

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableNumOfElementsTest1(void)
{
	HashTable_t *hashTableTest = NULL;
    void *freedElement = NULL;
    int arr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Num Of Elements Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 9, number of remove = 3, number of num of elements = 4\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nNum Of Elements Func Test 1: ");
		
	CHECK_FUNC(0 ==  HashTableNumOfElements(hashTableTest));

    printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 9;++i)
	{
		arr[i] = i;

		status = HashTableInsert(hashTableTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 9 SUCCESS (check status)\n");

    printf("\nNum Of Elements Func Test 2: ");
		
	CHECK_FUNC(9 ==  HashTableNumOfElements(hashTableTest));

    printf("\nRemove Func Test 1:\n\n");

	status = HashTableRemove(hashTableTest, &arr[0], &freedElement);
		
	printf("Remove number 1 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 1 check (value): ");

    CHECK_FUNC(0 == *(int*)freedElement);

    printf("\nNum Of Elements Func Test 3: ");
		
	CHECK_FUNC(8 ==  HashTableNumOfElements(hashTableTest));

    printf("\nRemove Func Test 2:\n\n");

    status = HashTableRemove(hashTableTest, &arr[7], &freedElement);

    printf("Remove number 2 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 2 check (value): ");

    CHECK_FUNC(7 == *(int*)freedElement);

    printf("\nRemove Func Test 3:\n\n");

    status = HashTableRemove(hashTableTest, &arr[4], &freedElement);

    printf("Remove number 3 check (status): ");
		
	CHECK_FUNC(HASH_TABLE_SUCCESS == status);

    printf("Remove number 3 check (value): ");

    CHECK_FUNC(4 == *(int*)freedElement);

    printf("\nNum Of Elements Func Test 4: ");
		
	CHECK_FUNC(6 ==  HashTableNumOfElements(hashTableTest));

    printf("\nExpected: 3 SUCCESS (check status) 7 SUCCESS (check value)\n");

    printf("\nPrint Func Test:\n\n");

    HashTablePrint(hashTableTest, PrintElement);

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableNumOfElementsTest2(void)
{
	HashTable_t *hashTableTest = NULL;

	printf("\033[1;34m\n*******Hash Table Num Of Elements Test 2:*******\n\n\033[0m");
	
	printf("number of num of elements = 1\n\n");

    printf("Num Of Elements Func Test: ");
		
	CHECK_FUNC(POINTER_NOT_INITIALIZE_HASH_NUM_OF_ELEMENTS ==  HashTableNumOfElements(hashTableTest));
	
    printf("\nExpected: 1 SUCCESS (check status) - hashTableTest is NULL\n");

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableCapacityTest1(void)
{
	HashTable_t *hashTableTest = NULL;

	printf("\033[1;34m\n*******Hash Table Capacity Test 1:*******\n\n\033[0m");
	
	printf("number of capacity = 1\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nCapacity Func Test: ");

	CHECK_FUNC(10 ==  HashTableCapacity(hashTableTest));
	
    printf("\nExpected: 1 SUCCESS (check status)\n");

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableCapacityTest2(void)
{
	HashTable_t *hashTableTest = NULL;

	printf("\033[1;34m\n*******Hash Table Capacity Test 2:*******\n\n\033[0m");
	
	printf("number of capacity = 1\n\n");

    printf("Capacity Func Test: ");

	CHECK_FUNC(POINTER_NOT_INITIALIZE_HASH_CAPACITY ==  HashTableCapacity(hashTableTest));
	
    printf("\nExpected: 1 SUCCESS (check status) - hashTableTest is NULL\n");

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableAvgRehashesTest1(void)
{
	HashTable_t *hashTableTest = NULL;
    int arr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Avg Rehashes Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 8, number of avg rehashes = 1\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nInsert Func Test 1:\n\n");

    arr[0] = 10;
    arr[1] = 5;
    arr[2] = 10;

    for (i = 0;i < 3;++i)
	{
		status = HashTableInsert(hashTableTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 2 SUCCESS 1 FAILURE (check status) - duplicate\n");

    printf("\nPrint Func Test:\n\n");

    HashTablePrint(hashTableTest, PrintElement);

    printf("\nInsert Func Test 2:\n\n");

    arr[3] = 20;
    arr[4] = 6;
    arr[5] = 4;
    arr[6] = 7;
    arr[7] = 2;

    for (i = 3;i < 8;++i)
	{
		status = HashTableInsert(hashTableTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}

    printf("\nExpected: 5 SUCCESS (check status)\n");

    printf("\nPrint Func Test:\n\n");

    HashTablePrint(hashTableTest, PrintElement);

    printf("\nAvg Rehashes Func Test: ");

	CHECK_FUNC((double)1/7 ==  HashTableAvgRehashes(hashTableTest));

    printf("\nAvg Rehashes is: %f\n", HashTableAvgRehashes(hashTableTest));

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableAvgRehashesTest2(void)
{
	HashTable_t *hashTableTest = NULL;

	printf("\033[1;34m\n*******Hash Table Avg Rehashes Test 2:*******\n\n\033[0m");
	
	printf("number of avg rehashes = 1\n\n");

    printf("Avg Rehashes Func Test: ");
	
	CHECK_FUNC(POINTER_NOT_INITIALIZE_HASH_CAPACITY ==  HashTableAvgRehashes(hashTableTest));

    printf("\nExpected: 1 SUCCESS (check status) - hashTableTest is NULL\n");

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableMaxRehashesTest1(void)
{
	HashTable_t *hashTableTest = NULL;
    int arr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Max Rehashes Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 8, number of rehashes = 1\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nInsert Func Test 1:\n\n");

    arr[0] = 10;
    arr[1] = 5;
    arr[2] = 10;

    for (i = 0;i < 3;++i)
	{
		status = HashTableInsert(hashTableTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 2 SUCCESS 1 FAILURE (check status) - duplicate\n");

    printf("\nPrint Func Test:\n\n");

    HashTablePrint(hashTableTest, PrintElement);

    printf("\nInsert Func Test 2:\n\n");

    arr[3] = 20;
    arr[4] = 6;
    arr[5] = 4;
    arr[6] = 7;
    arr[7] = 2;

    for (i = 3;i < 8;++i)
	{
		status = HashTableInsert(hashTableTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}

    printf("\nExpected: 5 SUCCESS (check status)\n");

    printf("\nPrint Func Test:\n\n");

    HashTablePrint(hashTableTest, PrintElement);

    printf("\nMax Rehashes Func Test: ");

	CHECK_FUNC(1 ==  HashTableMaxRehashes(hashTableTest));

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTableMaxRehashesTest2(void)
{
	HashTable_t *hashTableTest = NULL;

	printf("\033[1;34m\n*******Hash Table Max Rehashes Test 2:*******\n\n\033[0m");
	
	printf("number of max rehashes = 1\n\n");

    printf("Max Rehashes Func Test: ");
	
	CHECK_FUNC(POINTER_NOT_INITIALIZE_HASH_MAX_REHASHES ==  HashTableMaxRehashes(hashTableTest));

    printf("\nExpected: 1 SUCCESS (check status) - hashTableTest is NULL\n");

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTablePrintTest1(void)
{
	HashTable_t *hashTableTest = NULL;
    int arr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Print Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 9, number of print = 1\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 9;++i)
	{
		arr[i] = i;

		status = HashTableInsert(hashTableTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 9 SUCCESS (check status)\n");

    printf("\nPrint Func Test:\n\n");

    HashTablePrint(hashTableTest, PrintElement);

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTablePrintTest2(void)
{
	HashTable_t *hashTableTest = NULL;
    int arr[ARR_SIZE];
    int status;
    size_t i;

	printf("\033[1;34m\n*******Hash Table Print Test 2:*******\n\n\033[0m");
	
	printf("number of insert = 9, number of print = 1\n\n");

	printf("Create Func Test: ");

	hashTableTest = HashTableCreate(CAPACITY, HashFunc, EqualityFunc);
	
	CHECK_FUNC(NULL != hashTableTest);
	
	printf("\nExpected: SUCCESS (NULL != hashTableTest)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 9;++i)
	{
		arr[i] = i;

		status = HashTableInsert(hashTableTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(HASH_TABLE_SUCCESS == status);
	}
	
    printf("\nExpected: 9 SUCCESS (check status)\n");

    printf("\nPrint Func Test:\n\n");

    HashTablePrint(hashTableTest, NULL);

    printf("Expected: 1 FAILURE (check status) - PrintElement is NULL\n");

	HashTableDestroy(&hashTableTest, NULL);
}

void HastTablePrintTest3(void)
{
	HashTable_t *hashTableTest = NULL;

	printf("\033[1;34m\n*******Hash Table Print Test 3:*******\n\n\033[0m");

	printf("number of print = 1\n\n");

    printf("Print Func Test:\n\n");

    HashTablePrint(hashTableTest, PrintElement);

    printf("Expected: 1 FAILURE (check status) - hashTableTest is NULL\n");

	HashTableDestroy(&hashTableTest, NULL);
}

int main(void)
{
    HastTableCreateTest1();
    HastTableCreateTest2();
    HastTableCreateTest3();

    HastTableInsertTest1();
    HastTableInsertTest2();
    HastTableInsertTest3();
    HastTableInsertTest4();
    HastTableInsertTest5();

    HastTableRemoveTest1();
    HastTableRemoveTest2();
    HastTableRemoveTest3();
    HastTableRemoveTest4();
    
    HastTableIsFoundTest1();
    HastTableIsFoundTest2();
    HastTableIsFoundTest3();

    HastTableNumOfElementsTest1();
    HastTableNumOfElementsTest2();

    HastTableCapacityTest1();
    HastTableCapacityTest2();

    HastTableAvgRehashesTest1();
    HastTableAvgRehashesTest2();

    HastTableMaxRehashesTest1();
    HastTableMaxRehashesTest2();

    HastTablePrintTest1();
    HastTablePrintTest2();
    HastTablePrintTest3();

    return 0;
}
