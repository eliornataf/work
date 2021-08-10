#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc, free */
#include "genericDoublyLinkedList.h" /* Generic Doubly Linked List Header */

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

void ListCreateTest(void)
{
	List_t *listTest = NULL;
	
	printf("\033[1;34m\n*******List Create Test:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n");
	
	ListDestory(&listTest, NULL);
}

void ListPushHeadTest1(void)
{
	List_t *listTest = NULL;
	int arr[ARR_SIZE];
	int status;
	size_t i;
	
	printf("\033[1;34m\n*******List Push Head Test 1:*******\n\n\033[0m");
	
	printf("number of push head = 5\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	for (i = 0;i < 5;++i)
	{
		arr[i] = i;

		status = ListPushHead(listTest, &arr[i]);
		
		printf("Push Head number %ld check (status): ", i + 1);
		
		CHECK_FUNC(DLIST_SUCCESS == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status)\n");

	printf("\nPush Head & Size Test 1: ");

	CHECK_FUNC(5 == ListSize(listTest));
	
	printf("\nExpected: SUCCESS (check size value)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListPushHeadTest2(void)
{
	List_t *listTest = NULL;
	int arr[ARR_SIZE];
	int status;
	size_t i;
	
	printf("\033[1;34m\n*******List Push Head Test 2:*******\n\n\033[0m");
	
	printf("number of push head = 2\n\n");

	for (i = 0;i < 2;++i)
	{
		arr[i] = i;

		status = ListPushHead(listTest, &arr[i]);
		
		printf("Push Head number %ld check (status): ", i + 1);
		
		CHECK_FUNC(DLIST_POINTER_NOT_INITIALIZE == status);
	}
	
	printf("\nExpected: 2 SUCCESS (check status) - listTest is NULL\n");

	ListDestory(&listTest, FreeNodes);
}

void ListPushTailTest1(void)
{
	List_t *listTest = NULL;
	int arr[ARR_SIZE];
	int status;
	size_t i;
	
	printf("\033[1;34m\n*******List Push Tail Test 1:*******\n\n\033[0m");
	
	printf("number of push tail = 5\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	for (i = 0;i < 5;++i)
	{
		arr[i] = i;

		status = ListPushTail(listTest, &arr[i]);
		
		printf("Push Tail number %ld check (status): ", i + 1);
		
		CHECK_FUNC(DLIST_SUCCESS == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status)\n");

	printf("\nPush Tail & Size Test 1: ");

	CHECK_FUNC(5 == ListSize(listTest));
	
	printf("\nExpected: SUCCESS (check size value)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListPushTailTest2(void)
{
	List_t *listTest = NULL;
	int arr[ARR_SIZE];
	int status;
	size_t i;
	
	printf("\033[1;34m\n*******List Push Tail Test 2:*******\n\n\033[0m");
	
	printf("number of push tail = 2\n\n");

	for (i = 0;i < 2;++i)
	{
		arr[i] = i;

		status = ListPushTail(listTest, &arr[i]);
		
		printf("Push Tail number %ld check (status): ", i + 1);
		
		CHECK_FUNC(DLIST_POINTER_NOT_INITIALIZE == status);
	}
	
	printf("\nExpected: 2 SUCCESS (check status) - listTest is NULL\n");

	ListDestory(&listTest, FreeNodes);
}

void ListPopHeadTest1(void)
{
	List_t *listTest = NULL;
	void *pData = NULL;
	int arr[ARR_SIZE];
	int status;
	size_t i;
	
	printf("\033[1;34m\n*******List Pop Head Test 1:*******\n\n\033[0m");
	
	printf("number of push tail = 5, number of pop head = 5\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	for (i = 0;i < 5;++i)
	{
		arr[i] = i;

		status = ListPushTail(listTest, &arr[i]);
		
		printf("Push Tail number %ld check (status): ", i + 1);
		
		CHECK_FUNC(DLIST_SUCCESS == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status)\n");
	
	for (i = 0;i < 5;++i)
	{
		status = ListPopHead(listTest, &pData);
		
		printf("Pop Head number %ld check (status): ", i + 1);
		
		CHECK_FUNC(DLIST_SUCCESS == status);
		
		printf("pData data number %ld check: ", i + 1);
	
		CHECK_FUNC((int)i == *(int*)pData);
	}
	
	printf("\nExpected: 5 SUCCESS (check status) 5 SUCCESS (check pData value)\n");
	
	printf("\nPop Head & Size Test: ");
	
	CHECK_FUNC(0 == ListSize(listTest));
	
	printf("\nExpected: SUCCESS (check size value)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListPopHeadTest2(void)
{
	List_t *listTest = NULL;
	void *pData = NULL;
	int arr[ARR_SIZE];
	int status;
	size_t i, j;
	
	printf("\033[1;34m\n*******List Pop Head Test 2:*******\n\n\033[0m");
	
	printf("number of push head = 5, number of pop head = 5\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	for (i = 0;i < 5;++i)
	{
		arr[i] = i;

		status = ListPushHead(listTest, &arr[i]);
		
		printf("Push Head number %ld check (status): ", i + 1);
		
		CHECK_FUNC(DLIST_SUCCESS == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status)\n");
	
	for (i = 0, j = 4;i < 5;++i, --j)
	{
		status = ListPopHead(listTest, &pData);
		
		printf("Pop Head number %ld check (status): ", i + 1);
		
		CHECK_FUNC(DLIST_SUCCESS == status);
		
		printf("pData data number %ld check: ", i + 1);
	
		CHECK_FUNC((int)j == *(int*)pData);
	}
	
	printf("\nExpected: 5 SUCCESS (check status) 5 SUCCESS (check pData value)\n");
	
	printf("\nPop Head & Size Test: ");
	
	CHECK_FUNC(0 == ListSize(listTest));
	
	printf("\nExpected: SUCCESS (check size value)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListPopHeadTest3(void)
{
	List_t *listTest = NULL;
	void *pData = NULL;
	int status;
	size_t i;
	
	printf("\033[1;34m\n*******List Pop Head Test 3:*******\n\n\033[0m");
	
	printf("number of pop head = 2\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	for (i = 0;i < 2;++i)
	{
		status = ListPopHead(listTest, &pData);
		
		printf("Pop Head number %ld check (status): ", i + 1);
		
		CHECK_FUNC(DLIST_UNDERFLOW == status);
	}
	
	printf("\nExpected: 2 SUCCESS (check status) - list is empty\n");
	
	printf("\nPop Head & Size Test: ");
	
	CHECK_FUNC(0 == ListSize(listTest));
	
	printf("\nExpected: SUCCESS (check size value)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListPopHeadTest4(void)
{
	List_t *listTest = NULL;
	void *pData = NULL;
	int status;
	size_t i;
	
	printf("\033[1;34m\n*******List Pop Head Test 4:*******\n\n\033[0m");
	
	printf("number of pop head = 2\n\n");
	
	for (i = 0;i < 2;++i)
	{
		status = ListPopHead(listTest, &pData);
		
		printf("Pop Head number %ld check (status): ", i + 1);
		
		CHECK_FUNC(DLIST_POINTER_NOT_INITIALIZE == status);
	}
	
	printf("\nExpected: 2 SUCCESS (check status) - listTest is NULL\n");

	ListDestory(&listTest, FreeNodes);
}

void ListPopTailTest1(void)
{
	List_t *listTest = NULL;
	void *pData = NULL;
	int arr[ARR_SIZE];
	int status;
	size_t i, j;
	
	printf("\033[1;34m\n*******List Pop Tail Test 1:*******\n\n\033[0m");
	
	printf("number of push tail = 5, number of pop tail = 5\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	for (i = 0;i < 5;++i)
	{
		arr[i] = i;

		status = ListPushTail(listTest, &arr[i]);
		
		printf("Push Tail number %ld check (status): ", i + 1);
		
		CHECK_FUNC(DLIST_SUCCESS == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status)\n");
	
	for (i = 0, j = 4;i < 5;++i, --j)
	{
		status = ListPopTail(listTest, &pData);
		
		printf("Pop Tail number %ld check (status): ", i + 1);
		
		CHECK_FUNC(DLIST_SUCCESS == status);
		
		printf("pData data number %ld check: ", i + 1);
	
		CHECK_FUNC((int)j == *(int*)pData);
	}
	
	printf("\nExpected: 5 SUCCESS (check status) 5 SUCCESS (check pData value)\n");
	
	printf("\nPop Tail & Size Test: ");
	
	CHECK_FUNC(0 == ListSize(listTest));
	
	printf("\nExpected: SUCCESS (check size value)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListPopTailTest2(void)
{
	List_t *listTest = NULL;
	void *pData = NULL;
	int arr[ARR_SIZE];
	int status;
	size_t i;
	
	printf("\033[1;34m\n*******List Pop Tail Test 2:*******\n\n\033[0m");
	
	printf("number of push tail = 5, number of pop tail = 5\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	for (i = 0;i < 5;++i)
	{
		arr[i] = i;

		status = ListPushHead(listTest, &arr[i]);
		
		printf("Push Head number %ld check (status): ", i + 1);
		
		CHECK_FUNC(DLIST_SUCCESS == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status)\n");
	
	for (i = 0;i < 5;++i)
	{
		status = ListPopTail(listTest, &pData);
		
		printf("Pop Tail number %ld check (status): ", i + 1);
		
		CHECK_FUNC(DLIST_SUCCESS == status);
		
		printf("pData data number %ld check: ", i + 1);
	
		CHECK_FUNC((int)i == *(int*)pData);
	}
	
	printf("\nExpected: 5 SUCCESS (check status) 5 SUCCESS (check pData value)\n");
	
	printf("\nPop Tail & Size Test: ");
	
	CHECK_FUNC(0 == ListSize(listTest));
	
	printf("\nExpected: SUCCESS (check size value)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListPopTailTest3(void)
{
	List_t *listTest = NULL;
	void *pData = NULL;
	int status;
	size_t i;
	
	printf("\033[1;34m\n*******List Pop Tail Test 3:*******\n\n\033[0m");
	
	printf("number of pop tail = 2\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	for (i = 0;i < 2;++i)
	{
		status = ListPopTail(listTest, &pData);
		
		printf("Pop Tail number %ld check (status): ", i + 1);
		
		CHECK_FUNC(DLIST_UNDERFLOW == status);
	}
	
	printf("\nExpected: 2 SUCCESS (check status) - list is empty\n");
	
	printf("\nPop Tail & Size Test: ");
	
	CHECK_FUNC(0 == ListSize(listTest));
	
	printf("\nExpected: SUCCESS (check size value)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListPopTailTest4(void)
{
	List_t *listTest = NULL;
	void *pData = NULL;
	int status;
	size_t i;
	
	printf("\033[1;34m\n*******List Tail Head Test 4:*******\n\n\033[0m");
	
	printf("number of pop tail = 2\n\n");
	
	for (i = 0;i < 2;++i)
	{
		status = ListPopTail(listTest, &pData);
		
		printf("Pop Tail number %ld check (status): ", i + 1);
		
		CHECK_FUNC(DLIST_POINTER_NOT_INITIALIZE == status);
	}
	
	printf("\nExpected: 2 SUCCESS (check status) - listTest is NULL\n");

	ListDestory(&listTest, FreeNodes);
}

void ListSizeTest1(void)
{
	List_t *listTest = NULL;
	void *pData = NULL;
	int arr[ARR_SIZE];
	int status;
	size_t i, j;
	
	printf("\033[1;34m\n*******List Size Test 1:*******\n\n\033[0m");
	
	printf("number of push tail = 5, number of pop tail = 5, number of size = 3\n\n");

	printf("Create Func Test: ");

	listTest = ListCreate();
	
	CHECK_FUNC(NULL != listTest);
	
	printf("\nExpected: SUCCESS (NULL != listTest)\n\n");
	
	printf("Size Func Test 1: ");

	CHECK_FUNC(0 == ListSize(listTest));
	
	printf("\nExpected: SUCCESS (check size value)\n");

	for (i = 0;i < 5;++i)
	{
		arr[i] = i;

		status = ListPushTail(listTest, &arr[i]);
		
		printf("Push Tail number %ld check (status): ", i + 1);
		
		CHECK_FUNC(DLIST_SUCCESS == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status)\n");
	
	printf("\nSize Func Test 2: ");

	CHECK_FUNC(5 == ListSize(listTest));
	
	printf("\nExpected: SUCCESS (check size value)\n");

	for (i = 0, j = 4;i < 5;++i, --j)
	{
		status = ListPopTail(listTest, &pData);
		
		printf("Pop Tail number %ld check (status): ", i + 1);
		
		CHECK_FUNC(DLIST_SUCCESS == status);
		
		printf("pData data number %ld check: ", i + 1);
	
		CHECK_FUNC((int)j == *(int*)pData);
	}
	
	printf("\nExpected: 5 SUCCESS (check status) 5 SUCCESS (check pData value)\n");
	
	printf("\nPop Tail & Size Test: ");
	
	CHECK_FUNC(0 == ListSize(listTest));
	
	printf("\nExpected: SUCCESS (check size value)\n");

	ListDestory(&listTest, FreeNodes);
}

void ListSizeTest2(void)
{
	List_t *listTest = NULL;
	
	printf("\033[1;34m\n*******List Size Test 2:*******\n\n\033[0m");
	
	printf("number of size = 1\n\n");
	
	printf("Size Func Test 1: ");

	CHECK_FUNC(POINTER_NOT_INITIALIZE_DOUBLY_LINKED_LIST_SIZE == ListSize(listTest));
	
	printf("\nExpected: SUCCESS (check size value) - listTest is NULL\n");

	ListDestory(&listTest, FreeNodes);
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

	ListSizeTest1();
	ListSizeTest2();

	return 0;
}
