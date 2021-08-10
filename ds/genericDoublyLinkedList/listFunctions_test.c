#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc, free */
#include "listFunctions.h" /* List Function Header */
#include "listIter.h" /* List Iterator Header */
#include "internal.h" /* Internal Header */
#include "genericDoublyLinkedList.h" /* Generic Doubly Linked List Header */

#define ARR_SIZE (100)

#define NOT_FOUND (0)
#define IS_FOUND (1)

#define STOP (0)
#define CONTINUE (1)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

/*******************************************************************************/

static void FreeNodes(void *_item)
{
	free(_item);
}

static int PredicateFunc(void *_element, void *_context)
{
    if (*(int*)_element == *(int*)_context)
    {
        return IS_FOUND;
    }

    return NOT_FOUND;
}

static int PrintNode(void *_element, void *_context)
{
	(void)_context;

	printf("%d | ", *(int*)_element);

	return CONTINUE;
}

/*******************************************************************************/

void ListIterFindFirstTest1(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    ListIter_t iter = NULL;
    int arr[ARR_SIZE];
	size_t i;

	printf("\033[1;34m\n*******List Iter Find First Test 1:*******\n\n\033[0m");
	
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
    
    printf("\nFind First Func Test: ");

    iter = ListIterFindFirst(ListIterBegin(listTest), ListIterEnd(listTest), PredicateFunc, &arr[1]);

    CHECK_FUNC(1 == *(int*)ListIterGet(iter));

	printf("\nExpected: 1 SUCCESS (value check)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListIterFindFirstTest2(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    ListIter_t iter = NULL;
    int arr[ARR_SIZE];
	size_t i;

	printf("\033[1;34m\n*******List Iter Find First Test 2:*******\n\n\033[0m");
	
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
    
    printf("\nFind First Func Test: ");

    arr[3] = 3;

    iter = ListIterFindFirst(ListIterBegin(listTest), ListIterEnd(listTest), PredicateFunc, &arr[3]);

    CHECK_FUNC(NULL == ListIterGet(iter));

	printf("\nExpected: 1 SUCCESS (value check)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListIterFindFirstTest3(void)
{
	List_t *listTest = NULL;
    ListIter_t iter = NULL;

	printf("\033[1;34m\n*******List Iter Find First Test 3:*******\n\n\033[0m");
	
	printf("number of insert before = 3\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n");
    
    printf("\nFind First Func Test: ");

    iter = ListIterFindFirst(NULL, NULL, NULL, NULL);

    CHECK_FUNC(NULL == ListIterGet(iter));

	printf("\nExpected: 1 SUCCESS (value check) - fromIter/toIter/predicateFunc/context - is NULL\n");

	ListDestory(&listTest, FreeNodes);
}

void ListIterCountIfTest1(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    size_t counter = 0;
    int arr[ARR_SIZE];
	size_t i;

	printf("\033[1;34m\n*******List Iter Count If Test 1:*******\n\n\033[0m");
	
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
    
    printf("\nCount If Func Test: ");

    counter = ListIterCountIf(ListIterBegin(listTest), ListIterEnd(listTest), PredicateFunc, &arr[1]);

    CHECK_FUNC(1 == counter);

	printf("\nExpected: 1 SUCCESS (value check)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListIterCountIfTest2(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    size_t counter = 0;
    int arr[ARR_SIZE];
	size_t i;

	printf("\033[1;34m\n*******List Iter Count If Test 2:*******\n\n\033[0m");
	
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
    
    printf("\nCount If Func Test: ");

    arr[3] = 3;

    counter = ListIterCountIf(ListIterBegin(listTest), ListIterEnd(listTest), PredicateFunc, &arr[3]);

    CHECK_FUNC(0 == counter);

	printf("\nExpected: 1 SUCCESS (value check)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListIterCountIfTest3(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    size_t counter = 0;
    int arr[ARR_SIZE];
	size_t i;

	printf("\033[1;34m\n*******List Iter Count If Test 3:*******\n\n\033[0m");
	
	printf("number of insert before = 3\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n");

	printf("\nInsert Before Func Test:\n\n");

	for (i = 0;i < 3;++i)
	{
		arr[i] = 0;

		returnData = ListIterInsertBefore(ListIterEnd(listTest), &arr[i]);
		
		printf("Insert Before number %ld check (status): ", i + 1);
		
		CHECK_FUNC(arr[i] == *(int*)ListIterGet(returnData));
	}
	
	printf("\nExpected: 3 SUCCESS (return value check)\n");
    
    printf("\nCount If Func Test: ");

    counter = ListIterCountIf(ListIterBegin(listTest), ListIterEnd(listTest), PredicateFunc, &arr[0]);

    CHECK_FUNC(3 == counter);

	printf("\nExpected: 1 SUCCESS (value check)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListIterCountIfTest4(void)
{
	List_t *listTest = NULL;
    size_t counter = 0;

	printf("\033[1;34m\n*******List Iter Count If Test 4:*******\n\n\033[0m");
	
	printf("number of insert before = 3\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n");
    
    printf("\nCount If Func Test: ");

    counter = ListIterCountIf(NULL, NULL, NULL, NULL);

    CHECK_FUNC(COUNT_IF_POINTER_NOT_INITIALIZE == counter);

	printf("\nExpected: 1 SUCCESS (value check)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListIterForEachTest1(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    ListIter_t iter = NULL;
    int arr[ARR_SIZE];
	size_t i;

	printf("\033[1;34m\n*******List Iter For Each Test 1:*******\n\n\033[0m");
	
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
	
	printf("\nExpected: 3 SUCCESS (return value check)\n\n");
    
    iter = ListIterForEach(ListIterBegin(listTest), ListIterEnd(listTest), PrintNode, NULL);

    printf("\n\nFor Each First Func Test: ");

    CHECK_FUNC(ListIterEnd(listTest) == iter);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListIterForEachTest2(void)
{
	List_t *listTest = NULL;
	void *returnData = NULL;
    ListIter_t iter = NULL;
    int arr[ARR_SIZE];
	size_t i;

	printf("\033[1;34m\n*******List Iter For Each Test 2:*******\n\n\033[0m");
	
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
	
	printf("\nExpected: 3 SUCCESS (return value check)\n\n");
    
    iter = ListIterForEach(ListIterBegin(listTest), ListIterPrev(ListIterEnd(listTest)), PrintNode, NULL);

    printf("\n\nFor Each First Func Test: ");

    CHECK_FUNC(ListIterPrev(ListIterEnd(listTest)) == iter);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListIterForEachTest3(void)
{
	List_t *listTest = NULL;
    ListIter_t iter = NULL;

	printf("\033[1;34m\n*******List Iter For Each Test 3:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n");
    
    iter = ListIterForEach(NULL, NULL, NULL, NULL);

    printf("For Each First Func Test: ");

    CHECK_FUNC(NULL == iter);

    printf("\nExpected: 1 SUCCESS (for each check)- fromIter/toIter/actionFunc is NULL\n");

	ListDestory(&listTest, FreeNodes);
}

int main(void)
{
    ListIterFindFirstTest1();
    ListIterFindFirstTest2();
    ListIterFindFirstTest3();

    ListIterCountIfTest1();
    ListIterCountIfTest2();
    ListIterCountIfTest3();
    ListIterCountIfTest4();

    ListIterForEachTest1();
    ListIterForEachTest2();
    ListIterForEachTest3();

    return 0;
}