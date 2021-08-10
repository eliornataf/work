#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc, free */
#include "genericDoublyLinkedList.h" /* Generic Doubly Linked List Header */
#include "listIter.h" /* List Iterator Header */
#include "internal.h" /* Internal Header */

#define ARR_SIZE (100)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

/*************************************************************************/

static void FreeNodes(void *_item)
{
	free(_item);
}

/*************************************************************************/

void ListInsertBeforeTest1(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    int arr[ARR_SIZE];
	size_t i;

	printf("\033[1;34m\n*******List Insert Before Test 1:*******\n\n\033[0m");
	
	printf("number of insert before = 3\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n");

	printf("\nInsert Before Func Test:\n\n");

	for (i = 0;i < 2;++i)
	{
		arr[i] = i;

		returnData = ListIterInsertBefore(ListIterEnd(listTest), &arr[i]);
		
		printf("Insert Before number %ld check (status): ", i + 1);
		
		CHECK_FUNC(arr[i] == *(int*)ListIterGet(returnData));
	}
	
	printf("\nExpected: 2 SUCCESS (return value check)\n");

    printf("\nInsert Before Func Test 2: ");

    CHECK_FUNC(0 == *(int*)ListIterGet(ListIterBegin(listTest)));

	printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nInsert Before Func Test 3: ");

    CHECK_FUNC(1 == *(int*)ListIterGet(ListIterNext(ListIterBegin(listTest))));

	printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nInsert Before Func Test 4:\n\n");

    for (;i < 3;++i)
	{
		arr[i] = i;

		returnData = ListIterInsertBefore(ListIterBegin(listTest), &arr[i]);
		
		printf("Push Head number %ld check (status): ", i + 1);
		
		CHECK_FUNC(arr[i] == *(int*)ListIterGet(returnData));
	}
    
    printf("\nInsert Before Func Test 5: ");

    CHECK_FUNC(2 == *(int*)ListIterGet(ListIterBegin(listTest)));

	printf("\nExpected: 1 SUCCESS (value check)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListInsertBeforeTest2(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    int arr[ARR_SIZE];
	size_t i;

	printf("\033[1;34m\n*******List Insert Before Test 2:*******\n\n\033[0m");
	
	printf("number of insert before = 2\n\n");

	printf("Insert Before Func Test:\n\n");

	for (i = 0;i < 2;++i)
	{
		arr[i] = i;

		returnData = ListIterInsertBefore(ListIterEnd(listTest), &arr[i]);
		
		printf("Insert Before number %ld check (status): ", i + 1);
		
		CHECK_FUNC(NULL == ListIterGet(returnData));
	}
	
	printf("\nExpected: 2 SUCCESS (return value check) - listTest is NULL\n");

	ListDestory(&listTest, FreeNodes);
}

void ListInsertBeforeTest3(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    void *data = NULL;
	size_t i;

	printf("\033[1;34m\n*******List Insert Before Test 3:*******\n\n\033[0m");
	
	printf("number of insert before = 2\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n");

	printf("\nInsert Before Func Test:\n\n");

	for (i = 0;i < 2;++i)
	{
		returnData = ListIterInsertBefore(ListIterEnd(listTest), data);
		
		printf("Insert Before number %ld check (status): ", i + 1);
		
		CHECK_FUNC(NULL == returnData);
	}
	
	printf("\nExpected: 2 SUCCESS (return value check) - data is NULL\n");

	ListDestory(&listTest, FreeNodes);
}

void ListBeginTest1(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    int arr[ARR_SIZE];
	size_t i;

	printf("\033[1;34m\n*******List Begin Test 1:*******\n\n\033[0m");
	
	printf("number of insert before = 3\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n");

	printf("\nInsert Before Func Test:\n\n");

	for (i = 0;i < 2;++i)
	{
		arr[i] = i;

		returnData = ListIterInsertBefore(ListIterBegin(listTest), &arr[i]);
		
		printf("Insert Before number %ld check (status): ", i + 1);
		
		CHECK_FUNC(arr[i] == *(int*)ListIterGet(returnData));
	}
	
	printf("\nExpected: 2 SUCCESS (return value check)\n");

    printf("\nBegin Func Test 1: ");

    CHECK_FUNC(1 == *(int*)ListIterGet(ListIterBegin(listTest)));

	printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nBegin Func Test 2: ");

    CHECK_FUNC(0 == *(int*)ListIterGet(ListIterNext(ListIterBegin(listTest))));

	printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nInsert Before Func Test 2:\n\n");

    for (;i < 3;++i)
	{
		arr[i] = i;

		returnData = ListIterInsertBefore(ListIterBegin(listTest), &arr[i]);
		
		printf("Insert Before number %ld check (status): ", i + 1);
		
		CHECK_FUNC(arr[i] == *(int*)ListIterGet(returnData));
	}
    
    printf("\nBegin Func Test 3: ");

    CHECK_FUNC(2 == *(int*)ListIterGet(ListIterBegin(listTest)));

	printf("\nExpected: 1 SUCCESS (value check)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListBeginTest2(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;

	printf("\033[1;34m\n*******List Begin Test 2:*******\n\n\033[0m");

    printf("Begin Func Test: ");

    returnData = ListIterBegin(listTest);

    CHECK_FUNC(NULL == ListIterGet(returnData));

	printf("\nExpected: 1 SUCCESS (value check) - list is NULL\n");

	ListDestory(&listTest, FreeNodes);
}

void ListEndTest1(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    int arr[ARR_SIZE];
	size_t i;

	printf("\033[1;34m\n*******List End Test 1:*******\n\n\033[0m");
	
	printf("number of insert before = 2\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n");

	printf("\nInsert Before Func Test:\n\n");

	for (i = 0;i < 2;++i)
	{
		arr[i] = i;

		returnData = ListIterInsertBefore(ListIterEnd(listTest), &arr[i]);
		
		printf("Insert Before number %ld check (status): ", i + 1);
		
		CHECK_FUNC(arr[i] == *(int*)ListIterGet(returnData));
	}
	
	printf("\nExpected: 2 SUCCESS (return value check)\n");

    printf("\nEnd Func Test 1: ");

    CHECK_FUNC(0 == *(int*)ListIterGet(ListIterBegin(listTest)));

	printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nEnd Func Test 2: ");

    CHECK_FUNC(1 == *(int*)ListIterGet(ListIterNext(ListIterBegin(listTest))));

	printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nEnd Func Test 3: ");

    CHECK_FUNC(NULL == ListIterGet(ListIterEnd(listTest)));

    printf("\nExpected: 1 SUCCESS (value check)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListEndTest2(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;

	printf("\033[1;34m\n*******List End Test 2:*******\n\n\033[0m");

    printf("End Func Test: ");

    returnData = ListIterEnd(listTest);

    CHECK_FUNC(NULL == ListIterGet(returnData));

	printf("\nExpected: 1 SUCCESS (value check) - list is NULL\n");

	ListDestory(&listTest, FreeNodes);
}

void ListEqualTest1(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    int arr[ARR_SIZE];
	size_t i;

	printf("\033[1;34m\n*******List Equal Test 1:*******\n\n\033[0m");
	
	printf("number of insert before = 3\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n");

	printf("\nInsert Before Func Test:\n\n");

	for (i = 0;i < 3;++i)
	{
		arr[i] = i;

		returnData = ListIterInsertBefore(ListIterEnd(listTest), &arr[i]);
		
		printf("Insert Before number %ld check (status): ", i + 1);
		
		CHECK_FUNC(arr[i] == *(int*)ListIterGet(returnData));
	}
	
	printf("\nExpected: 2 SUCCESS (return value check)\n");

    printf("\nIs Equal Func Test 1: ");

    CHECK_FUNC(ListIterEqual(ListIterBegin(listTest), ListIterBegin(listTest)));

	printf("\nExpected: 1 SUCCESS (equal check)\n");

    printf("\nIs Equal Func Test 2: ");

    CHECK_FUNC(ListIterEqual ( ListIterNext(ListIterBegin(listTest)), ListIterPrev(ListIterPrev(ListIterEnd(listTest))) ) );

	printf("\nExpected: 1 SUCCESS (equal check)\n");

    printf("\nIs Equal Func Test 3: ");

    CHECK_FUNC(!ListIterEqual ( ListIterNext(ListIterBegin(listTest)), ListIterPrev(ListIterEnd(listTest)) ) );

	printf("\nExpected: 1 SUCCESS (equal check)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListEqualTest2(void)
{
	List_t *listTest = NULL;
    void *firstIter = NULL;
    void *secondIter = NULL;

	printf("\033[1;34m\n*******List Equal Test 2:*******\n\n\033[0m");

    printf("Is Equal Func Test 1: ");

    CHECK_FUNC(POINTER_NOT_INITIALIZE_EQUAL == ListIterEqual(firstIter, secondIter));

	printf("\nExpected: 1 SUCCESS (return value check) - firstIter/secondIter is NULL\n");

	ListDestory(&listTest, FreeNodes);
}

void ListNextTest1(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    int arr[ARR_SIZE];
	size_t i;

	printf("\033[1;34m\n*******List Next Test 1:*******\n\n\033[0m");
	
	printf("number of insert before = 3\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n");

	printf("\nInsert Before Func Test:\n\n");

	for (i = 0;i < 3;++i)
	{
		arr[i] = i;

		returnData = ListIterInsertBefore(ListIterEnd(listTest), &arr[i]);
		
		printf("Insert Before number %ld check (status): ", i + 1);
		
		CHECK_FUNC(arr[i] == *(int*)ListIterGet(returnData));
	}
	
	printf("\nExpected: 2 SUCCESS (return value check)\n");

    printf("\nNext Func Test 1: ");

    CHECK_FUNC(ListIterEqual ( ListIterNext(ListIterBegin(listTest)), ListIterPrev(ListIterPrev(ListIterEnd(listTest))) ) );

	printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nNext Func Test 2: ");

    CHECK_FUNC(ListIterEqual ( ListIterNext(ListIterNext(ListIterBegin(listTest))), ListIterPrev(ListIterEnd(listTest)) ) );

	printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nNext Func Test 3: ");

    CHECK_FUNC(ListIterEqual(ListIterNext(ListIterEnd(listTest)), ListIterEnd(listTest)));

	printf("\nExpected: 1 SUCCESS (value check)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListNextTest2(void)
{
	List_t *listTest = NULL;
    void *iter = NULL;

	printf("\033[1;34m\n*******List Next Test 2:*******\n\n\033[0m");

    printf("Next Func Test: ");

    CHECK_FUNC(NULL == ListIterNext(iter));

	printf("\nExpected: 1 SUCCESS (value check) - iter is NULL\n");

	ListDestory(&listTest, FreeNodes);
}

void ListPrevTest1(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    int arr[ARR_SIZE];
	size_t i;

	printf("\033[1;34m\n*******List Prev Test 1:*******\n\n\033[0m");
	
	printf("number of insert before = 3\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n");

	printf("\nInsert Before Func Test:\n\n");

	for (i = 0;i < 3;++i)
	{
		arr[i] = i;

		returnData = ListIterInsertBefore(ListIterEnd(listTest), &arr[i]);
		
		printf("Insert Before number %ld check (status): ", i + 1);
		
		CHECK_FUNC(arr[i] == *(int*)ListIterGet(returnData));
	}
	
	printf("\nExpected: 2 SUCCESS (return value check)\n");

    printf("\nPrev Func Test 1: ");

    CHECK_FUNC(ListIterEqual ( ListIterNext(ListIterBegin(listTest)), ListIterPrev(ListIterPrev(ListIterEnd(listTest))) ) );

	printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nPrev Func Test 2: ");

    CHECK_FUNC(ListIterEqual ( ListIterNext(ListIterBegin(listTest)), ListIterPrev(ListIterPrev(ListIterEnd(listTest))) ) );

	printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nPrev Func Test 3: ");

    CHECK_FUNC(ListIterEqual(ListIterPrev(ListIterBegin(listTest)), (ListIterBegin(listTest))));

	printf("\nExpected: 1 SUCCESS (value check)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListPrevTest2(void)
{
	List_t *listTest = NULL;
    void *iter = NULL;

	printf("\033[1;34m\n*******List Prev Test 2:*******\n\n\033[0m");

    printf("Prev Func Test: ");

    CHECK_FUNC(NULL == ListIterPrev(iter));

	printf("\nExpected: 1 SUCCESS (value check) - iter is NULL\n");

	ListDestory(&listTest, FreeNodes);
}

void ListGetTest1(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    int arr[ARR_SIZE];
	size_t i;

	printf("\033[1;34m\n*******List Get Test 1:*******\n\n\033[0m");
	
	printf("number of insert before = 3\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n");

	printf("\nGet Func Test:\n\n");

	for (i = 0;i < 2;++i)
	{
		arr[i] = i;

		returnData = ListIterInsertBefore(ListIterEnd(listTest), &arr[i]);
		
		printf("Get number %ld check (status): ", i + 1);
		
		CHECK_FUNC(arr[i] == *(int*)ListIterGet(returnData));
	}
	
	printf("\nExpected: 2 SUCCESS (return value check)\n");

    printf("\nGet Func Test 2: ");

    CHECK_FUNC(0 == *(int*)ListIterGet(ListIterBegin(listTest)));

	printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nGet Func Test 3: ");

    CHECK_FUNC(1 == *(int*)ListIterGet(ListIterNext(ListIterBegin(listTest))));

	printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nGet Func Test 4: ");

    for (;i < 3;++i)
	{
		arr[i] = i;

		returnData = ListIterInsertBefore(ListIterBegin(listTest), &arr[i]);
		
		printf("Get number %ld check (status): ", i + 1);
		
		CHECK_FUNC(arr[i] == *(int*)ListIterGet(returnData));
	}
    
    printf("\nGet Func Test 5: ");

    CHECK_FUNC(2 == *(int*)ListIterGet(ListIterBegin(listTest)));

	printf("\nExpected: 1 SUCCESS (value check)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListGetTest2(void)
{
	List_t *listTest = NULL;
    void *iter = NULL;

	printf("\033[1;34m\n*******List Get Test 2:*******\n\n\033[0m");

    printf("Get Func Test: ");

    CHECK_FUNC(NULL == ListIterGet(iter));

	printf("\nExpected: 1 SUCCESS (value check) - iter is NULL\n");

	ListDestory(&listTest, FreeNodes);
}

void ListSetTest1(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    int arr[ARR_SIZE];
	size_t i;

	printf("\033[1;34m\n*******List Set Test 1:*******\n\n\033[0m");
	
	printf("number of insert before = 3\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n");

	printf("\nInsert Before Func Test:\n\n");

	for (i = 0;i < 3;++i)
	{
		arr[i] = i;

		returnData = ListIterInsertBefore(ListIterEnd(listTest), &arr[i]);
		
		printf("Insert Before number %ld check (status): ", i + 1);
		
		CHECK_FUNC(arr[i] == *(int*)ListIterGet(returnData));
	}
    
    for (;i < 6;++i)
	{
        arr[i] = i;		
	}

	printf("\nSet Func Test 1: ");
		
    returnData = ListIterSet(ListIterBegin(listTest), &arr[3]);

    CHECK_FUNC(0 == *(int*)returnData);

    printf("Get Func Test 1: ");

	CHECK_FUNC(3 == *(int*)ListIterGet(ListIterBegin(listTest)));

	printf("\nExpected: 2 SUCCESS (value check)\n");

    printf("\nSet Func Test 2: ");
		
    returnData = ListIterSet(ListIterNext(ListIterBegin(listTest)), &arr[4]);

    CHECK_FUNC(1 == *(int*)returnData);

    printf("Get Func Test 2: ");

	CHECK_FUNC(4 == *(int*)ListIterGet(ListIterNext(ListIterBegin(listTest))));

	printf("\nExpected: 2 SUCCESS (value check)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListSetTest2(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    int data = 3;

	printf("\033[1;34m\n*******List Set Test 2:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n");

	printf("\nSet Func Test: ");
		
    returnData = ListIterSet(ListIterEnd(listTest), &data);

    CHECK_FUNC(NULL == returnData);

	printf("\nExpected: 1 SUCCESS (value check) - end iter set is NULL\n");

	ListDestory(&listTest, FreeNodes);
}

void ListSetTest3(void)
{
	List_t *listTest = NULL;
    void *returnData = NULL;
    void *iter = NULL;

	printf("\033[1;34m\n*******List Set Test 3:*******\n\n\033[0m");

	printf("Set Func Test: ");

    returnData = ListIterSet(ListIterEnd(listTest), iter);
    
    CHECK_FUNC(NULL == returnData);

	printf("\nExpected: 1 SUCCESS (value check) - iter is NULL\n");

	ListDestory(&listTest, FreeNodes);
}

void ListRemoveTest1(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    int arr[ARR_SIZE];
	size_t i;

	printf("\033[1;34m\n*******List Remove Test 1:*******\n\n\033[0m");
	
	printf("number of insert before = 3\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n");

	printf("\nInsert Before Func Test:\n\n");

	for (i = 0;i < 3;++i)
	{
		arr[i] = i;

		returnData = ListIterInsertBefore(ListIterEnd(listTest), &arr[i]);
		
		printf("Insert Before number %ld check (status): ", i + 1);
		
		CHECK_FUNC(arr[i] == *(int*)ListIterGet(returnData));
	}
	
	printf("\nExpected: 3 SUCCESS (return value check)\n");

    printf("\nRemove Func Test:\n\n");

	for (i = 0;i < 3;++i)
	{
		returnData = ListIterRemove(ListIterBegin(listTest));
		
		printf("Remove number %ld check (status): ", i + 1);
		
		CHECK_FUNC((int)i == *(int*)returnData);
	}

	printf("\nExpected: 3 SUCCESS (value check)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListRemoveTest2(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    int arr[ARR_SIZE];
	size_t i;

	printf("\033[1;34m\n*******List Remove Test 2:*******\n\n\033[0m");
	
	printf("number of insert before = 3\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n");

	printf("\nInsert Before Func Test:\n\n");

	for (i = 0;i < 3;++i)
	{
		arr[i] = i;

		returnData = ListIterInsertBefore(ListIterEnd(listTest), &arr[i]);
		
		printf("Insert Before number %ld check (status): ", i + 1);
		
		CHECK_FUNC(arr[i] == *(int*)ListIterGet(returnData));
	}
	
	printf("\nExpected: 3 SUCCESS (return value check)\n");

    printf("\nRemove Func Test: ");

	returnData = ListIterRemove(ListIterEnd(listTest));
				
	CHECK_FUNC(NULL == returnData);

	printf("\nExpected: 1 SUCCESS (value check) - remove tail is NULL\n");

	ListDestory(&listTest, FreeNodes);
}

void ListRemoveTest3(void)
{
	List_t *listTest = NULL;
    void *returnData = NULL;

	printf("\033[1;34m\n*******List Remove Test 3:*******\n\n\033[0m");

    printf("Remove Func Test: ");

	returnData = ListIterRemove(ListIterPrev(ListIterEnd(listTest)));
    
    CHECK_FUNC(NULL == returnData);

	printf("\nExpected: 1 SUCCESS (value check) - iter is NULL\n");

	ListDestory(&listTest, FreeNodes);
}

/*************************************************************************/

int main(void)
{
	ListInsertBeforeTest1();
    ListInsertBeforeTest2();
    ListInsertBeforeTest3();

    ListBeginTest1();
    ListBeginTest2();

    ListEndTest1();
    ListEndTest2();

    ListEqualTest1();
    ListEqualTest2();

    ListNextTest1();
    ListNextTest2();

    ListPrevTest1();
    ListPrevTest2();

    ListGetTest1();
    ListGetTest2();

    ListSetTest1();
    ListSetTest2();
    ListSetTest3();

    ListRemoveTest1();
    ListRemoveTest2();
    ListRemoveTest3();

	return 0;
}
