#include <stdio.h> /* printf */
#include "doublyLinkedList.h" /* Doubly Linked List Header */

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

void ListCreateTest(void)
{
	List_t *listTest = NULL;
	
	printf("\033[1;34m\n*******List Create Test:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n");
	
	ListDestory(listTest);
}

void ListPushHeadTest1(void)
{
	List_t *listTest = NULL;
	ADTError_t status = OK;
	int i;
	
	printf("\033[1;34m\n*******List Push Head Test 1:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	for (i = 0;i < 2;++i)
	{
		status = ListPushHead(listTest, i + 1);
		
		printf("Push Head number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 2 SUCCESS (status test)\n");

	printf("\nPush Head & Count Items Test 1: ");

	CHECK_FUNC(2 == ListCountItems(listTest));
	
	printf("\nExpected: SUCCESS (count items test)\n");
	
	printf("\nPush Head & Print List 1:\n\n");
	
	ListPrint(listTest);
	
	printf("\n\nExpected: 2 -> 1\n\n");
	
	for (i = 2;i < 6;++i)
	{
		status = ListPushHead(listTest, i + 1);
		
		printf("Push Head number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 4 SUCCESS (status test)\n");
	
	printf("\nPush Head & Count Items Test 2: ");
	
	CHECK_FUNC(6 == ListCountItems(listTest));
	
	printf("\nExpected: SUCCESS (count items test)\n");

	printf("\nPush Head & Print List 2:\n\n");
	
	ListPrint(listTest);
	
	printf("\n\nExpected: 6 -> 5 -> 4 -> 3 -> 2 -> 1\n");

	ListDestory(listTest);
}

void ListPushHeadTest2(void)
{
	List_t *listTest = NULL;
	ADTError_t status = OK;
	int i;
	
	printf("\033[1;34m\n*******List Push Head Test 2:*******\n\n\033[0m");
	
	printf("Push Head:\n\n");
	
	for (i = 0;i < 2;++i)
	{
		status = ListPushHead(listTest, i + 1);
		
		printf("Push Head number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == POINTER_NOT_INITIALIZE);
	}
	
	printf("\nExpected: 2 FAILURE (status test) - listTest == NULL\n");

	ListDestory(listTest);
}

void ListPushTailTest1(void)
{
	List_t *listTest = NULL;
	ADTError_t status = OK;
	int i;
	
	printf("\033[1;34m\n*******List Push Tail Test 1:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	for (i = 0;i < 2;++i)
	{
		status = ListPushTail(listTest, i + 1);
		
		printf("Push Tail number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 2 SUCCESS (status test)\n");

	printf("\nPush Tail & Count Items Test 1: ");

	CHECK_FUNC(2 == ListCountItems(listTest));
	
	printf("\nExpected: SUCCESS (count items test)\n");
	
	printf("\nPush Tail & Print List 1:\n\n");
	
	ListPrint(listTest);
	
	printf("\n\nExpected: 1 -> 2\n\n");
	
	for (i = 2;i < 6;++i)
	{
		status = ListPushTail(listTest, i + 1);
		
		printf("Push Tail number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 4 SUCCESS (status test)\n");
	
	printf("\nPush Tail & Count Items Test 2: ");
	
	CHECK_FUNC(6 == ListCountItems(listTest));
	
	printf("\nExpected: SUCCESS (count items test)\n");

	printf("\nPush Tail & Print List 2:\n\n");
	
	ListPrint(listTest);
	
	printf("\n\nExpected: 1 -> 2 -> 3 -> 4 -> 5 -> 6\n");

	ListDestory(listTest);
}

void ListPushTailTest2(void)
{
	List_t *listTest = NULL;
	ADTError_t status = OK;
	int i;
	
	printf("\033[1;34m\n*******List Push Tail Test 2:*******\n\n\033[0m");
	
	printf("Push Tail:\n\n");
	
	for (i = 0;i < 2;++i)
	{
		status = ListPushTail(listTest, i + 1);
		
		printf("Push Tail number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == POINTER_NOT_INITIALIZE);
	}
	
	printf("\nExpected: 2 SUCCESS (status test) - listTest == NULL\n");

	ListDestory(listTest);
}

void ListPopHeadTest1(void)
{
	List_t *listTest = NULL;
	ADTError_t status = OK;
	int i, j, outputData;
	
	printf("\033[1;34m\n*******List Pop Head Test 1:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	for (i = 0;i < 6;++i)
	{
		status = ListPushTail(listTest, i + 1);
		
		printf("Push Tail number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 6 SUCCESS (status test)\n");
	
	printf("\nPush Tail & Print List:\n\n");
	
	ListPrint(listTest);
	
	printf("\n\nExpected: 1 -> 2 -> 3 -> 4 -> 5 -> 6\n\n");
	
	for (i = 0, j = 1;i < 3;++i, ++j)
	{
		status = ListPopHead(listTest, &outputData);
		
		printf("Pop Head number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
		
		printf("Output data number %d check: ", i + 1);
	
		CHECK_FUNC(j == outputData);
	}
	
	printf("\nExpected: 3 SUCCESS (check status) 3 SUCCESS (check outputData)\n");
	
	printf("\nPop Head & Count Items Test: ");
	
	CHECK_FUNC(3 == ListCountItems(listTest));
	
	printf("\nExpected: SUCCESS (count items test)\n");

	printf("\nPop Head & Print List:\n\n");
	
	ListPrint(listTest);
	
	printf("\n\nExpected: 4 -> 5 -> 6\n");

	ListDestory(listTest);
}

void ListPopHeadTest2(void)
{
	List_t *listTest = NULL;
	ADTError_t status = OK;
	int i, outputData;
	
	printf("\033[1;34m\n*******List Pop Head Test 2:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	for (i = 0;i < 3;++i)
	{
		status = ListPopHead(listTest, &outputData);
		
		printf("Pop Head number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 3 FAILURE (check status)\n");

	ListDestory(listTest);
}

void ListPopHeadTest3(void)
{
	List_t *listTest = NULL;
	ADTError_t status = OK;
	int i, outputData;
	
	printf("\033[1;34m\n*******List Pop Head Test 3:*******\n\n\033[0m");
	
	for (i = 0;i < 3;++i)
	{
		status = ListPopHead(listTest, &outputData);
		
		printf("Pop Head number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 3 FAILURE (check status) - listTest == NULL\n");

	ListDestory(listTest);
}

void ListPopHeadTest4(void)
{
	List_t *listTest = NULL;
	ADTError_t status = OK;
	int *outputData = NULL;
	int i;
	
	printf("\033[1;34m\n*******List Pop Head Test 4:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	for (i = 0;i < 6;++i)
	{
		status = ListPushTail(listTest, i + 1);
		
		printf("Push Tail number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 6 SUCCESS (status test)\n\n");
	
	for (i = 0;i < 3;++i)
	{
		status = ListPopHead(listTest, outputData);
		
		printf("Pop Head number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 3 FAILURE (check status) - outputData == NULL\n");

	ListDestory(listTest);
}

void ListPopTailTest1(void)
{
	List_t *listTest = NULL;
	ADTError_t status = OK;
	int i, j, outputData;
	
	printf("\033[1;34m\n*******List Pop Tail Test 1:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	for (i = 0;i < 6;++i)
	{
		status = ListPushTail(listTest, i + 1);
		
		printf("Push Tail number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 6 SUCCESS (status test)\n");
	
	printf("\nPush Tail & Print List:\n\n");
	
	ListPrint(listTest);
	
	printf("\n\nExpected: 1 -> 2 -> 3 -> 4 -> 5 -> 6\n\n");
	
	for (i = 0, j = 6;i < 3;++i, --j)
	{
		status = ListPopTail(listTest, &outputData);
		
		printf("Pop Tail number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
		
		printf("Output data number %d check: ", i + 1);
	
		CHECK_FUNC(j == outputData);
	}
	
	printf("\nExpected: 3 SUCCESS (check status) 3 SUCCESS (check outputData)\n");
	
	printf("\nPop Tail & Count Items Test: ");
	
	CHECK_FUNC(3 == ListCountItems(listTest));
	
	printf("\nExpected: SUCCESS (count items test)\n");

	printf("\nPop Tail & Print List:\n\n");
	
	ListPrint(listTest);
	
	printf("\n\nExpected: 1 -> 2 -> 3\n");

	ListDestory(listTest);
}

void ListPopTailTest2(void)
{
	List_t *listTest = NULL;
	ADTError_t status = OK;
	int i, outputData;
	
	printf("\033[1;34m\n*******List Pop Tail Test 2:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	for (i = 0;i < 3;++i)
	{
		status = ListPopTail(listTest, &outputData);
		
		printf("Pop Tail number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 3 FAILURE (check status)\n");

	ListDestory(listTest);
}

void ListPopTailTest3(void)
{
	List_t *listTest = NULL;
	ADTError_t status = OK;
	int i, outputData;
	
	printf("\033[1;34m\n*******List Pop Tail Test 3:*******\n\n\033[0m");
	
	for (i = 0;i < 3;++i)
	{
		status = ListPopTail(listTest, &outputData);
		
		printf("Pop Tail number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 3 FAILURE (check status) - listTest == NULL\n");

	ListDestory(listTest);
}

void ListPopTailTest4(void)
{
	List_t *listTest = NULL;
	ADTError_t status = OK;
	int *outputData = NULL;
	int i;
	
	printf("\033[1;34m\n*******List Pop Tail Test 4:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	for (i = 0;i < 6;++i)
	{
		status = ListPushTail(listTest, i + 1);
		
		printf("Push Tail number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 6 SUCCESS (status test)\n\n");
	
	for (i = 0;i < 3;++i)
	{
		status = ListPopTail(listTest, outputData);
		
		printf("Pop Tail number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 3 FAILURE (check status) - outputData == NULL\n");

	ListDestory(listTest);
}

void ListCountItemsTest(void)
{
	List_t *listTest = NULL;
	ADTError_t status = OK;
	int i, outputData;
	
	printf("\033[1;34m\n*******List Count Items Test:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	for (i = 0;i < 6;++i)
	{
		status = ListPushTail(listTest, i + 1);
		
		printf("Push Tail number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 6 SUCCESS (status test)\n");
	
	printf("\nCount Items Test 1: ");
	
	CHECK_FUNC(6 == ListCountItems(listTest));
	
	printf("\nExpected: SUCCESS (count items test)\n\n");
	
	for (i = 0;i < 4;++i)
	{
		status = ListPopTail(listTest, &outputData);
		
		printf("Pop Tail number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 4 SUCCESS (check status)\n");
	
	printf("\nCount Items Test 2: ");
	
	CHECK_FUNC(2 == ListCountItems(listTest));
	
	printf("\nExpected: SUCCESS (count items test)\n");

	ListDestory(listTest);
}

void ListIsEmptyTest(void)
{
	List_t *listTest = NULL;
	ADTError_t status = OK;
	int i, outputData;
	
	printf("\033[1;34m\n*******List Is Empty Test:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	printf("Is Empty Func Test 1: ");
	
	CHECK_FUNC(LIST_IS_EMPTY == ListIsEmpty(listTest));
	
	printf("\nExpected: SUCCESS (is empty test)\n\n");
	
	for (i = 0;i < 6;++i)
	{
		status = ListPushTail(listTest, i + 1);
		
		printf("Push Tail number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 6 SUCCESS (status test)\n");
	
	printf("\nIs Empty Func Test 2: ");
	
	CHECK_FUNC(LIST_IS_NOT_EMTPY == ListIsEmpty(listTest));
	
	printf("\nExpected: SUCCESS (is empty test)\n\n");
	
	for (i = 0;i < 6;++i)
	{
		status = ListPopTail(listTest, &outputData);
		
		printf("Pop Tail number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 6 SUCCESS (check status)\n");
	
	printf("\nIs Empty Func Test 3: ");
	
	CHECK_FUNC(LIST_IS_EMPTY == ListIsEmpty(listTest));
	
	printf("\nExpected: SUCCESS (is empty test)\n");

	ListDestory(listTest);
}

void ListPrintTest(void)
{
	List_t *listTest = NULL;
	ADTError_t status = OK;
	int i, outputData;
	
	printf("\033[1;34m\n*******List Print Test:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	for (i = 0;i < 6;++i)
	{
		status = ListPushTail(listTest, i + 1);
		
		printf("Push Tail number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 6 SUCCESS (status test)\n");
	
	printf("\nPrint List 1:\n\n");
	
	ListPrint(listTest);
	
	printf("\n\nExpected: 1 -> 2 -> 3 -> 4 -> 5 -> 6\n\n");
	
	for (i = 0;i < 3;++i)
	{
		status = ListPopTail(listTest, &outputData);
		
		printf("Pop Tail number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 3 SUCCESS (check status)\n");

	printf("\nPrint List 2:\n\n");
	
	ListPrint(listTest);
	
	printf("\n\nExpected: 1 -> 2 -> 3\n");

	ListDestory(listTest);
}


int main(void)
{
	ListCreateTest();

	ListPushHeadTest1();
	ListPushHeadTest2();

	ListPushTailTest1();
	ListPushTailTest2();
	
	ListPopHeadTest1();
	ListPopHeadTest2();
	ListPopHeadTest3();
	ListPopHeadTest4();
	
	ListPopTailTest1();
	ListPopTailTest2();
	ListPopTailTest3();
	ListPopTailTest4();
	
	ListCountItemsTest();
	
	ListIsEmptyTest();

	ListPrintTest();
	
	return 0;
}
