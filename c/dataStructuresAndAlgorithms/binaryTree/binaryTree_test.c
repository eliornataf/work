#include <stdio.h> /* printf */
#include "binaryTree.h" /* Binary Tree Header */

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

void BinaryTreeCreateTest(void)
{
	BinaryTree_t *binaryTree = NULL;
	
	printf("\033[1;34m\n*******Binary Tree Create Test:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	binaryTree = BinaryTreeCreate();
	
	CHECK_FUNC(NULL != binaryTree);
	
	printf("\nExpected: SUCCESS (NULL != binaryTree)\n");
	
	BinaryTreeDestroy(binaryTree);
}

void BinaryTreeInsertTest1(void)
{
	BinaryTree_t *binaryTree = NULL;
	ADTError_t status = OK;
	int inputData = 5;
	
	printf("\033[1;34m\n*******Binary Tree Insert Test 1:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	binaryTree = BinaryTreeCreate();
	
	CHECK_FUNC(NULL != binaryTree);
	
	printf("\nExpected: SUCCESS (NULL != binaryTree)\n\n");
	
	printf("Insert Func Test:\n\n");
	
	status = BinaryTreeInsert(binaryTree, inputData);
		
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 1 SUCCESS (status test)\n");
	
	printf("\nPrint Func Test (In Order): ");
	
	BinaryTreePrint(binaryTree, IN_ORDER);
	
	printf("\nExpected: 5 ->\n");
	
	BinaryTreeDestroy(binaryTree);
}

void BinaryTreeInsertTest2(void)
{
	BinaryTree_t *binaryTree = NULL;
	ADTError_t status = OK;
	int inputData = 5;
	int i;
	
	printf("\033[1;34m\n*******Binary Tree Insert Test 2:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	binaryTree = BinaryTreeCreate();
	
	CHECK_FUNC(NULL != binaryTree);
	
	printf("\nExpected: SUCCESS (NULL != binaryTree)\n\n");
	
	printf("Insert Func Test:\n\n");
	
	for (i = 0;i < 2;++i)
	{
		status = BinaryTreeInsert(binaryTree, inputData + i);
		
		printf("Insert number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 2 SUCCESS (status test)\n");
	
	printf("\nPrint Func Test (In Order): ");
	
	BinaryTreePrint(binaryTree, IN_ORDER);
	
	printf("\nExpected: 5 -> 6 ->\n");
	
	BinaryTreeDestroy(binaryTree);
}

void BinaryTreeInsertTest3(void)
{
	BinaryTree_t *binaryTree = NULL;
	ADTError_t status = OK;
	int inputData = 5;
	int i;
	
	printf("\033[1;34m\n*******Binary Tree Insert Test 3:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	binaryTree = BinaryTreeCreate();
	
	CHECK_FUNC(NULL != binaryTree);
	
	printf("\nExpected: SUCCESS (NULL != binaryTree)\n\n");
	
	printf("Insert Func Test:\n\n");
	
	for (i = 0;i < 2;++i)
	{
		status = BinaryTreeInsert(binaryTree, inputData - i);
		
		printf("Insert number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 2 SUCCESS (status test)\n");
	
	printf("\nPrint Func Test (In Order): ");
	
	BinaryTreePrint(binaryTree, IN_ORDER);
	
	printf("\nExpected: 4 -> 5 ->\n");
	
	BinaryTreeDestroy(binaryTree);
}

void BinaryTreeInsertTest4(void)
{
	BinaryTree_t *binaryTree = NULL;
	ADTError_t status = OK;
	int inputData = 5;
	int i;
	
	printf("\033[1;34m\n*******Binary Tree Insert Test 4:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	binaryTree = BinaryTreeCreate();
	
	CHECK_FUNC(NULL != binaryTree);
	
	printf("\nExpected: SUCCESS (NULL != binaryTree)\n\n");
	
	printf("Insert Func Test:\n\n");
	
	for (i = 0;i < 2;++i)
	{
		status = BinaryTreeInsert(binaryTree, inputData - i);
		
		printf("Insert number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	status = BinaryTreeInsert(binaryTree, inputData + 1);
		
	printf("Insert number 3 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 3 SUCCESS (status test)\n");
	
	printf("\nPrint Func Test (In Order): ");
	
	BinaryTreePrint(binaryTree, IN_ORDER);
	
	printf("\nExpected: 4 -> 5 -> 6 ->\n");
	
	BinaryTreeDestroy(binaryTree);
}

void BinaryTreeInsertTest5(void)
{
	BinaryTree_t *binaryTree = NULL;
	ADTError_t status = OK;
	int inputData = 5;
	int i;
	
	printf("\033[1;34m\n*******Binary Tree Insert Test 5:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	binaryTree = BinaryTreeCreate();
	
	CHECK_FUNC(NULL != binaryTree);
	
	printf("\nExpected: SUCCESS (NULL != binaryTree)\n\n");
	
	printf("Insert Func Test:\n\n");
	
	for (i = 0;i < 2;++i)
	{
		status = BinaryTreeInsert(binaryTree, inputData - i);
		
		printf("Insert number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	status = BinaryTreeInsert(binaryTree, inputData + 1);
		
	printf("Insert number 3 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	for (i = 0;i < 2;++i)
	{
		status = BinaryTreeInsert(binaryTree, inputData + i + 2);
		
		printf("Insert number %d check (status): ", i + 4);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 6 SUCCESS (status test)\n");
	
	printf("\nPrint Func Test (In Order): ");
	
	BinaryTreePrint(binaryTree, IN_ORDER);
	
	printf("\nExpected: 4 -> 5 -> 6 -> 7 -> 8 ->\n");
	
	BinaryTreeDestroy(binaryTree);
}

void BinaryTreeInsertTest6(void)
{
	BinaryTree_t *binaryTree = NULL;
	ADTError_t status = OK;
	int inputData = 5;
	int i;
	
	printf("\033[1;34m\n*******Binary Tree Insert Test 6:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	binaryTree = BinaryTreeCreate();
	
	CHECK_FUNC(NULL != binaryTree);
	
	printf("\nExpected: SUCCESS (NULL != binaryTree)\n\n");
	
	printf("Insert Func Test:\n\n");
	
	for (i = 0;i < 2;++i)
	{
		status = BinaryTreeInsert(binaryTree, inputData - i);
		
		printf("Insert number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	status = BinaryTreeInsert(binaryTree, inputData + 1);
		
	printf("Insert number 3 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	for (i = 0;i < 2;++i)
	{
		status = BinaryTreeInsert(binaryTree, inputData + i + 3);
		
		printf("Insert number %d check (status): ", i + 4);
		
		CHECK_FUNC(OK == status);
	}
	
	status = BinaryTreeInsert(binaryTree, inputData - 3);
		
	printf("Insert number 6 check (status): ");
	
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData + 5);
		
	printf("Insert number 7 check (status): ");
	
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData -2);
		
	printf("Insert number 8 check (status): ");
	
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData + 2);
		
	printf("Insert number 9 check (status): ");
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 9 SUCCESS (status test)\n");
	
	printf("\nPrint Func Test (In Order): ");
	
	BinaryTreePrint(binaryTree, IN_ORDER);
	
	printf("\nExpected: 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 ->\n");
	
	BinaryTreeDestroy(binaryTree);
}

void BinaryTreeInsertTest7(void)
{
	BinaryTree_t *binaryTree = NULL;
	ADTError_t status = OK;
	int inputData = 5;
	int i;
	
	printf("\033[1;34m\n*******Binary Tree Insert Test 7:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	binaryTree = BinaryTreeCreate();
	
	CHECK_FUNC(NULL != binaryTree);
	
	printf("\nExpected: SUCCESS (NULL != binaryTree)\n\n");
	
	printf("Insert Func Test:\n\n");
	
	for (i = 0;i < 2;++i)
	{
		status = BinaryTreeInsert(binaryTree, inputData - i);
		
		printf("Insert number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	status = BinaryTreeInsert(binaryTree, inputData);
		
	printf("Insert number 3 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData - 1);
		
	printf("Insert number 4 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 2 SUCCESS 2 FAILURE (status test) - Duplicate data\n");
	
	printf("\nPrint Func Test (In Order): ");
	
	BinaryTreePrint(binaryTree, IN_ORDER);
	
	printf("\nExpected: 4 -> 5 ->\n");
	
	BinaryTreeDestroy(binaryTree);
}

void BinaryTreeInsertTest8(void)
{
	BinaryTree_t *binaryTree = NULL;
	ADTError_t status = OK;
	int inputData = 5;
	
	printf("\033[1;34m\n*******Binary Tree Insert Test 8:*******\n\n\033[0m");
	
	printf("Insert Func Test: ");
	
	status = BinaryTreeInsert(binaryTree, inputData);
		
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 1 FAILURE (status test) - binaryTree == NULL\n");
	
	BinaryTreeDestroy(binaryTree);
}

void BinaryTreeDataIsFoundTest1(void)
{
	BinaryTree_t *binaryTree = NULL;
	ADTError_t status = OK;
	int inputData = 5;
	int i;
	
	printf("\033[1;34m\n*******Binary Tree Data Is Found Test 1:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	binaryTree = BinaryTreeCreate();
	
	CHECK_FUNC(NULL != binaryTree);
	
	printf("\nExpected: SUCCESS (NULL != binaryTree)\n\n");
	
	printf("Insert Func Test:\n\n");
	
	status = BinaryTreeInsert(binaryTree, inputData);
		
	printf("Insert number 1 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData - 2);
		
	printf("Insert number 2 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData - 1);
		
	printf("Insert number 3 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData + 3);
		
	printf("Insert number 4 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData + 2);
		
	printf("Insert number 5 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData + 4);
		
	printf("Insert number 6 check (status): ");
		
	CHECK_FUNC(OK == status);
		
	status = BinaryTreeInsert(binaryTree, inputData - 3);
		
	printf("Insert number 7 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData - 4);
		
	printf("Insert number 8 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData + 5);
		
	printf("Insert number 9 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData + 1);
		
	printf("Insert number 10 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 10 SUCCESS (status test)\n");
	
	printf("\nPrint Func Test (In Order): ");
	
	BinaryTreePrint(binaryTree, IN_ORDER);
	
	printf("\nExpected: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 ->\n");
	
	printf("\nData Is Found Func Test:\n\n");
	
	for (i = 1;i < 15;++i)
	{
		status = BinaryTreeIsDataFound(binaryTree, i);
		
		printf("Data Is Found number %d check (status): ", i);
		
		CHECK_FUNC(DATA_IS_FOUND == status);
	}
	
	printf("\nExpected: 9 SUCCESS 4 FAILURE (status test)\n");
	
	BinaryTreeDestroy(binaryTree);
}

void BinaryTreeDataIsFoundTest2(void)
{
	BinaryTree_t *binaryTree = NULL;
	ADTError_t status = OK;
	int inputData = 5;
	
	printf("\033[1;34m\n*******Binary Tree Data Is Found Test 2:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	binaryTree = BinaryTreeCreate();
	
	CHECK_FUNC(NULL != binaryTree);
	
	printf("\nExpected: SUCCESS (NULL != binaryTree)\n\n");

	printf("Data Is Found Func Test:\n\n");
	
	status = BinaryTreeIsDataFound(binaryTree, inputData);
		
	printf("Data Is Found number 1 check (status): ");
		
	CHECK_FUNC(DATA_IS_NOT_FOUND == status);
	
	printf("\nExpected: 1 SUCCESS (status test) - Tree is empty\n");
	
	BinaryTreeDestroy(binaryTree);
}

void BinaryTreeDataIsFoundTest3(void)
{
	BinaryTree_t *binaryTree = NULL;
	ADTError_t status = OK;
	int inputData = 5;
	
	printf("\033[1;34m\n*******Binary Tree Data Is Found Test 3:*******\n\n\033[0m");

	printf("Data Is Found Func Test:\n\n");
	
	status = BinaryTreeIsDataFound(binaryTree, inputData);
		
	printf("Data Is Found number 1 check (status): ");
		
	CHECK_FUNC(DATA_IS_NOT_FOUND == status);
	
	printf("\nExpected: 1 SUCCESS (status test) - binaryTree == NULL\n");
	
	BinaryTreeDestroy(binaryTree);
}

void BinaryTreePrintTest(void)
{
	BinaryTree_t *binaryTree = NULL;
	ADTError_t status = OK;
	int inputData = 5;
	
	printf("\033[1;34m\n*******Binary Tree Print Test:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	binaryTree = BinaryTreeCreate();
	
	CHECK_FUNC(NULL != binaryTree);
	
	printf("\nExpected: SUCCESS (NULL != binaryTree)\n\n");
	
	printf("Insert Func Test:\n\n");
	
	status = BinaryTreeInsert(binaryTree, inputData);
		
	printf("Insert number 1 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData - 2);
		
	printf("Insert number 2 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData - 1);
		
	printf("Insert number 3 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData + 3);
		
	printf("Insert number 4 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData + 2);
		
	printf("Insert number 5 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData + 4);
		
	printf("Insert number 6 check (status): ");
		
	CHECK_FUNC(OK == status);
		
	status = BinaryTreeInsert(binaryTree, inputData - 3);
		
	printf("Insert number 7 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData - 4);
		
	printf("Insert number 8 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData + 5);
		
	printf("Insert number 9 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	status = BinaryTreeInsert(binaryTree, inputData + 1);
		
	printf("Insert number 10 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 10 SUCCESS (status test)\n");
	
	printf("\nPrint Func Test (Pre Order): ");
	
	BinaryTreePrint(binaryTree, PRE_ORDER);
	
	printf("\nExpected: 5 -> 3 -> 2 -> 1 -> 4 -> 8 -> 7 -> 6 -> 9 -> 10 ->\n");
	
	printf("\nPrint Func Test (In Order): ");
	
	BinaryTreePrint(binaryTree, IN_ORDER);
	
	printf("\nExpected: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 ->\n");
	
	printf("\nPrint Func Test (Post Order): ");
	
	BinaryTreePrint(binaryTree, POST_ORDER);
	
	printf("\nExpected: 1 -> 2 -> 4 -> 3 -> 6 -> 7 -> 10 -> 9 -> 8 -> 5 ->\n");
	
	BinaryTreeDestroy(binaryTree);
}

int main(void)
{
	BinaryTreeCreateTest();
	
	BinaryTreeInsertTest1();
	BinaryTreeInsertTest2();
	BinaryTreeInsertTest3();
	BinaryTreeInsertTest4();
	BinaryTreeInsertTest5();
	BinaryTreeInsertTest6();
	BinaryTreeInsertTest7();
	BinaryTreeInsertTest8();
	
	BinaryTreeDataIsFoundTest1();
	BinaryTreeDataIsFoundTest2();
	BinaryTreeDataIsFoundTest3();
	
	BinaryTreePrintTest();
	
	return 0;
}
