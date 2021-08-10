#include <stdio.h> /* printf */
#include <stdlib.h> /* free */
#include "genericBinaryTree.h" /* Generic Binary Tree Header */

#define DUPLICATE_FOUND (-1)
#define GO_LEFT (0)
#define GO_RIGHT (1)

#define ARR_SIZE (100)

#define IS_NOT_FOUND (0)
#define IS_FOUND (1)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

/*********************************************************************************/

static int CompareNodesData(const void *currNodeData, const void *newNodeData)
{
    if (*(int*)currNodeData < *(int*)newNodeData)
    {
        return GO_RIGHT;
    }
    else if (*(int*)newNodeData < *(int*)currNodeData)
    {
        return GO_LEFT;
    }

    return DUPLICATE_FOUND;
}

static void FreeNodes(void *_node)
{
	free(_node);
}

static void SetArrayElements(int *arr)
{
    arr[0] = 50;
    arr[1] = 30;
    arr[2] = 80;
    arr[3] = 10;
    arr[4] = 60;
    arr[5] = 90;
    arr[6] = 40;
    arr[7] = 40;
    arr[8] = 20;
    arr[9] = 35;
    arr[10] = 35;
    arr[11] = 15;
    arr[12] = 70;
    arr[13] = 25;
    arr[14] = 110;
    arr[15] = 100;
    arr[16] = 100;

                       /*         50
                                /   \
                              30     80
                            /  \    / \
                          10   40 60  90
                           \   /   \   \
                           20 35   70  110
                          / \         /
                        15  25      100     */
}

static int FindNode(const void *_nodeData, const void *_context)
{
    if (*(int*)_nodeData == *(int*)_context)
    {
        return IS_FOUND;
    }

    return IS_NOT_FOUND;
}

/*********************************************************************************/

void BSTCreateTest1(void)
{
	BST_t *bstTest = NULL;
	
	printf("\033[1;34m\n*******BST Create Test 1:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");
	
	BSTDestroy(&bstTest, FreeNodes);
}

void BSTCreateTest2(void)
{
	BST_t *bstTest = NULL;
	
	printf("\033[1;34m\n*******BST Create Test 2:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	bstTest = BSTCreate(NULL);
	
	CHECK_FUNC(NULL == bstTest);
	
	printf("\nExpected: SUCCESS (NULL == bstTest) - compareFunc is NULL\n");
	
	BSTDestroy(&bstTest, FreeNodes);
}

void BSTInsertTest1(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int arr[ARR_SIZE];
    size_t i;
	
	printf("\033[1;34m\n*******BST Insert Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 5\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 5;++i)
	{
		arr[i] = i;

		iter = BSTInsert(bstTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC((int)i == *(int*)BSTIterGet(iter));
	}
    
    printf("\nExpected: 5 SUCCESS (check status)\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTInsertTest2(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int arr[ARR_SIZE];
    size_t i;
	
	printf("\033[1;34m\n*******BST Insert Test 2:*******\n\n\033[0m");
	
	printf("number of insert = 16\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

    SetArrayElements(arr);

    for (i = 0;i < 16;++i)
	{
		iter = BSTInsert(bstTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(NULL != iter);
	}
    
    printf("\nExpected: 16 SUCCESS (check status)\n");

                       /*         50
                                /   \
                              30     80
                            /  \    / \
                          10   40 60  90
                           \   /   \   \
                           20 35   70  110
                          / \         /
                        15  25      100     */

    printf("\nInsert & Begin & Next & Get Func Test:\n\n");

    iter = BSTIterBegin(bstTest);
		
	CHECK_FUNC(10 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(15 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(20 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(25 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(30 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(35 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(40 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(50 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(60 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(70 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(80 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(90 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(100 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(110 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(NULL == BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(NULL == BSTIterGet(iter));

    printf("\nExpected: 16 SUCCESS (value check)\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTInsertTest3(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int arr[ARR_SIZE];
    size_t i;
	
	printf("\033[1;34m\n*******BST Insert Test 3:*******\n\n\033[0m");
	
	printf("number of insert = 16\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

    SetArrayElements(arr);

    for (i = 0;i < 16;++i)
	{
		iter = BSTInsert(bstTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(NULL != iter);
	}
    
    printf("\nExpected: 16 SUCCESS (check status)\n");

                       /*         50
                                /   \
                              30     80
                            /  \    / \
                          10   40 60  90
                           \   /   \   \
                           20 35   70  110
                          / \         /
                        15  25      100     */

    printf("\nInsert & End & Prev & Get Func Test:\n\n");

    iter = BSTIterEnd(bstTest);
		
	CHECK_FUNC(NULL == BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(110 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(100 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(90 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(80 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(70 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(60 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(50 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(40 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(35 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(30 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(25 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(20 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(15 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(10 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(10 == *(int*)BSTIterGet(iter));

    printf("\nExpected: 16 SUCCESS (value check)\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTInsertTest4(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int arr[ARR_SIZE];
    size_t i;
	
	printf("\033[1;34m\n*******BST Insert Test 4:*******\n\n\033[0m");

	printf("number of insert = 2\n\n");

    printf("Insert Func Test:\n\n");

    for (i = 0;i < 2;++i)
	{
		arr[i] = i;

		iter = BSTInsert(bstTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);

		CHECK_FUNC(NULL == BSTIterGet(iter));
	}
    
    printf("\nExpected: 2 SUCCESS (check status) - bstTest is NULL\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTInsertTest5(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    void *data = NULL;
    size_t i;
	
	printf("\033[1;34m\n*******BST Insert Test 5:*******\n\n\033[0m");

	printf("number of insert = 2\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 2;++i)
	{
		iter = BSTInsert(bstTest, data);
		
		printf("Insert number %ld check (status): ", i + 1);

		CHECK_FUNC(BSTIterEqual(BSTIterEnd(bstTest), iter));
	}
    
    printf("\nExpected: 2 SUCCESS (check status) - data is NULL\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTInsertTest6(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int data1 = 10;
    int data2 = 10;
	
	printf("\033[1;34m\n*******BST Insert Test 6:*******\n\n\033[0m");

	printf("number of insert = 2\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

	printf("Insert number 1 check (status): ");

	iter = BSTInsert(bstTest, &data1);
		
	CHECK_FUNC(!BSTIterEqual(BSTIterEnd(bstTest), iter));

    printf("Insert number 2 check (status): ");

	iter = BSTInsert(bstTest, &data2);
		
	CHECK_FUNC(BSTIterEqual(BSTIterEnd(bstTest), iter));

    printf("\nExpected: 2 SUCCESS (check status) - duplicate data\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTFindTest1(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int arr[ARR_SIZE];
    int searchData1 = 10;
    int searchData2 = 100;
    int searchData3 = 88;
    size_t i;
	
	printf("\033[1;34m\n*******BST Find Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 16\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

    SetArrayElements(arr);

    for (i = 0;i < 16;++i)
	{
		iter = BSTInsert(bstTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(NULL != iter);
	}
    
    printf("\nExpected: 16 SUCCESS (check status)\n");

                       /*         50
                                /   \
                              30     80
                            /  \    / \
                          10   40 60  90
                           \   /   \   \
                           20 35   70  110
                          / \         /
                        15  25      100     */

    printf("\nFind Func Test 1: ");

    iter = BSTFindFirst(bstTest, FindNode, &searchData1);

	CHECK_FUNC(BSTIterEqual(BSTIterBegin(bstTest), iter));

    printf("\nExpected: 1 SUCCESS (is equal check)\n");

    printf("\nFind Func Test 2: ");

    iter = BSTFindFirst(bstTest, FindNode, &searchData2);

	CHECK_FUNC(BSTIterEqual(BSTIterPrev(BSTIterPrev(BSTIterEnd(bstTest))), iter));

    printf("\nExpected: 1 SUCCESS (is equal check)\n");

    printf("\nFind Func Test 3: ");

    iter = BSTFindFirst(bstTest, FindNode, &searchData3);

	CHECK_FUNC(BSTIterEqual(BSTIterEnd(bstTest), iter));

    printf("\nExpected: 1 SUCCESS (is equal check) - context is not found\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTFindTest2(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int arr[ARR_SIZE];
    int searchData = 10;
    size_t i;
	
	printf("\033[1;34m\n*******BST Find Test 2:*******\n\n\033[0m");
	
	printf("number of insert = 16\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

    SetArrayElements(arr);

    for (i = 0;i < 16;++i)
	{
		iter = BSTInsert(bstTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(NULL != iter);
	}
    
    printf("\nExpected: 16 SUCCESS (check status)\n");

                       /*         50
                                /   \
                              30     80
                            /  \    / \
                          10   40 60  90
                           \   /   \   \
                           20 35   70  110
                          / \         /
                        15  25      100     */

    printf("\nFind Func Test: ");

    iter = BSTFindFirst(bstTest, NULL, &searchData);

	CHECK_FUNC(NULL == iter);

    printf("\nExpected: 1 SUCCESS (is equal check) - predicateFunc is NULL\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTFindTest3(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int searchData = 10;
	
	printf("\033[1;34m\n*******BST Find Test 3:*******\n\n\033[0m");

    printf("Find Func Test: ");

    iter = BSTFindFirst(bstTest, FindNode, &searchData);

	CHECK_FUNC(NULL == iter);

    printf("\nExpected: 1 SUCCESS (is equal check) - bstTest is NULL\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTBeginTest1(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int arr[ARR_SIZE];
    size_t i;
	
	printf("\033[1;34m\n*******BST Begin Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 16\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

    SetArrayElements(arr);

    for (i = 0;i < 16;++i)
	{
		iter = BSTInsert(bstTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(NULL != iter);
	}
    
    printf("\nExpected: 16 SUCCESS (check status)\n");

                       /*         50
                                /   \
                              30     80
                            /  \    / \
                          10   40 60  90
                           \   /   \   \
                           20 35   70  110
                          / \         /
                        15  25      100     */

    printf("\nBegin Func Test: ");

    iter = BSTIterBegin(bstTest);

	CHECK_FUNC(10 == *(int*)BSTIterGet(iter));

    printf("\nExpected: 1 SUCCESS (value check)\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTBeginTest2(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
	
	printf("\033[1;34m\n*******BST Begin Test 2:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nBegin Func Test: ");

    iter = BSTIterBegin(bstTest);

	CHECK_FUNC(BSTIterEqual(BSTIterEnd(bstTest), iter));

    printf("\nExpected: 1 SUCCESS (is equal check) - bstTest is empty\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTBeginTest3(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
	
	printf("\033[1;34m\n*******BST Begin Test 3:*******\n\n\033[0m");

    printf("Begin Func Test: ");

    iter = BSTIterBegin(bstTest);

	CHECK_FUNC(NULL == iter);

    printf("\nExpected: 1 SUCCESS (value check) - bstTest is NULL\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTEndTest1(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int arr[ARR_SIZE];
    size_t i;
	
	printf("\033[1;34m\n*******BST End Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 16\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

    SetArrayElements(arr);

    for (i = 0;i < 16;++i)
	{
		iter = BSTInsert(bstTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(NULL != iter);
	}
    
    printf("\nExpected: 16 SUCCESS (check status)\n");

                       /*         50
                                /   \
                              30     80
                            /  \    / \
                          10   40 60  90
                           \   /   \   \
                           20 35   70  110
                          / \         /
                        15  25      100     */

    printf("\nEnd Func Test: ");

    iter = BSTIterEnd(bstTest);

	CHECK_FUNC(NULL == BSTIterGet(iter));

    printf("\nExpected: 1 SUCCESS (value check)\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTEndTest2(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
	
	printf("\033[1;34m\n*******BST End Test 2:*******\n\n\033[0m");

    printf("End Func Test: ");

    iter = BSTIterEnd(bstTest);

	CHECK_FUNC(NULL == iter);

    printf("\nExpected: 1 SUCCESS (value check) - bstTest is NULL\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTIsEqualTest(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    BSTIter_t *firstIter = NULL;
    int arr[ARR_SIZE];
    size_t i;
	
	printf("\033[1;34m\n*******BST Is Equal Test:*******\n\n\033[0m");
	
	printf("number of insert = 16\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

    SetArrayElements(arr);

    for (i = 0;i < 16;++i)
	{
		iter = BSTInsert(bstTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(NULL != iter);
	}
    
    printf("\nExpected: 16 SUCCESS (check status)\n");

                       /*         50
                                /   \
                              30     80
                            /  \    / \
                          10   40 60  90
                           \   /   \   \
                           20 35   70  110
                          / \         /
                        15  25      100     */

    printf("\nIs Equal Func Test 1: ");

	CHECK_FUNC(BSTIterEqual(BSTIterBegin(bstTest), BSTIterPrev(BSTIterBegin(bstTest))));

    printf("\nExpected: 1 SUCCESS (is equal check)\n");

    printf("\nIs Equal Func Test 2: ");

	CHECK_FUNC(!BSTIterEqual(BSTIterBegin(bstTest), BSTIterNext(BSTIterBegin(bstTest))));

    printf("\nExpected: 1 SUCCESS (is equal check)\n");

    printf("\nIs Equal Func Test 3: ");

	CHECK_FUNC(POINTER_NOT_INITIALIZE_EQUAL == BSTIterEqual(BSTIterBegin(bstTest), firstIter));

    printf("\nExpected: 1 SUCCESS (is equal check) - firstIter is NULL\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTNextTest1(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int arr[ARR_SIZE];
    size_t i;
	
	printf("\033[1;34m\n*******BST Next Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 16\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

    SetArrayElements(arr);

    for (i = 0;i < 16;++i)
	{
		iter = BSTInsert(bstTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(NULL != iter);
	}
    
    printf("\nExpected: 16 SUCCESS (check status)\n");

                       /*         50
                                /   \
                              30     80
                            /  \    / \
                          10   40 60  90
                           \   /   \   \
                           20 35   70  110
                          / \         /
                        15  25      100     */

    printf("\nInsert & Begin & Next & Get Func Test:\n\n");

    iter = BSTIterBegin(bstTest);
		
	CHECK_FUNC(10 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(15 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(20 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(25 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(30 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(35 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(40 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(50 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(60 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(70 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(80 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(90 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(100 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(110 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(NULL == BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(NULL == BSTIterGet(iter));

    printf("\nExpected: 16 SUCCESS (value check)\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTNextTest2(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
	
	printf("\033[1;34m\n*******BST Next Test 2:*******\n\n\033[0m");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nNext Func Test: ");
		
	CHECK_FUNC(NULL == BSTIterGet(iter));

    printf("\nExpected: 1 SUCCESS (value check) - iter is NULL\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTPrevTest1(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int arr[ARR_SIZE];
    size_t i;
	
	printf("\033[1;34m\n*******BST Prev Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 16\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

    SetArrayElements(arr);

    for (i = 0;i < 16;++i)
	{
		iter = BSTInsert(bstTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(NULL != iter);
	}
    
    printf("\nExpected: 16 SUCCESS (check status)\n");

                       /*         50
                                /   \
                              30     80
                            /  \    / \
                          10   40 60  90
                           \   /   \   \
                           20 35   70  110
                          / \         /
                        15  25      100     */

    printf("\nInsert & End & Prev & Get Func Test:\n\n");

    iter = BSTIterEnd(bstTest);
		
	CHECK_FUNC(NULL == BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(110 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(100 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(90 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(80 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(70 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(60 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(50 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(40 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(35 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(30 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(25 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(20 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(15 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(10 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(10 == *(int*)BSTIterGet(iter));

    printf("\nExpected: 16 SUCCESS (value check)\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTPrevTest2(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
	
	printf("\033[1;34m\n*******BST Prev Test 2:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nPrev Func Test: ");

    iter = BSTIterPrev(BSTIterEnd(bstTest));

	CHECK_FUNC(BSTIterEqual(BSTIterEnd(bstTest), iter));
    
    printf("\nExpected: 1 SUCCESS (is equal check) - bstTest is empty\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTPrevTest3(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
	
	printf("\033[1;34m\n*******BST Prev Test 3:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nPrev Func Test: ");

	CHECK_FUNC(NULL == BSTIterPrev(iter));
    
    printf("\nExpected: 1 SUCCESS (value check) - iter is NULL\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTGetTest1(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int arr[ARR_SIZE];
    size_t i;
	
	printf("\033[1;34m\n*******BST Get Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 16\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

    SetArrayElements(arr);

    for (i = 0;i < 16;++i)
	{
		iter = BSTInsert(bstTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(NULL != iter);
	}
    
    printf("\nExpected: 16 SUCCESS (check status)\n");

                       /*         50
                                /   \
                              30     80
                            /  \    / \
                          10   40 60  90
                           \   /   \   \
                           20 35   70  110
                          / \         /
                        15  25      100     */

    printf("\nInsert & End & Prev & Get Func Test:\n\n");

    iter = BSTIterEnd(bstTest);
		
	CHECK_FUNC(NULL == BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(110 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(100 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(90 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(80 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(70 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(60 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(50 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(40 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(35 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(30 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(25 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(20 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(15 == *(int*)BSTIterGet(iter));

    iter = BSTIterPrev(iter);

	CHECK_FUNC(10 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterPrev(iter);

	CHECK_FUNC(10 == *(int*)BSTIterGet(iter));

    printf("\nExpected: 16 SUCCESS (value check)\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTGetTest2(void)
{
    BST_t *bstTest = NULL;
	
	printf("\033[1;34m\n*******BST Get Test 2:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nGet Func Test: ");

	CHECK_FUNC(NULL == BSTIterGet(BSTIterEnd(bstTest)));
    
    printf("\nExpected: 1 SUCCESS (value check) - bstTest is empty\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTGetTest3(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
	
	printf("\033[1;34m\n*******BST Get Test 3:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nGet Func Test: ");

	CHECK_FUNC(NULL == BSTIterGet(iter));
    
    printf("\nExpected: 1 SUCCESS (value check) - iter is NULL\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTRemoveTest1(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int arr[ARR_SIZE];
    size_t i;
	
	printf("\033[1;34m\n*******BST Remove Test 1:*******\n\n\033[0m");
	
	printf("number of insert = 16\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

    SetArrayElements(arr);

    for (i = 0;i < 16;++i)
	{
		iter = BSTInsert(bstTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(NULL != iter);
	}
    
    printf("\nExpected: 16 SUCCESS (check status)\n");

                       /*         50
                                /   \
                              30     80
                            /  \    / \
                          10   40 60  90
                           \   /   \   \
                           20 35   70  110
                          / \         /
                        15  25      100     */

    printf("\nRemove Func Test 1: ");

	CHECK_FUNC(15 == *(int*)BSTIterRemove(BSTIterNext(BSTIterBegin(bstTest))));
    
    printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nRemove Func Test 2: ");

	CHECK_FUNC(25 == *(int*)BSTIterRemove(BSTIterNext(BSTIterNext(BSTIterBegin(bstTest)))));
    
    printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nRemove Func Test 3: ");

	CHECK_FUNC(100 == *(int*)BSTIterRemove(BSTIterPrev(BSTIterPrev(BSTIterEnd(bstTest)))));
    
    printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nInsert & Begin & Next & Get Func Test:\n\n");

    iter = BSTIterBegin(bstTest);
		
	CHECK_FUNC(10 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(20 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(30 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(35 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(40 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(50 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(60 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(70 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(80 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(90 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(110 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(NULL == BSTIterGet(iter));

    printf("\nExpected: 12 SUCCESS (value check)\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTRemoveTest2(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int arr[ARR_SIZE];
    size_t i;
	
	printf("\033[1;34m\n*******BST Remove Test 2:*******\n\n\033[0m");
	
	printf("number of insert = 16\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

    SetArrayElements(arr);

    for (i = 0;i < 16;++i)
	{
		iter = BSTInsert(bstTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(NULL != iter);
	}
    
    printf("\nExpected: 16 SUCCESS (check status)\n");

                       /*         50
                                /   \
                              30     80
                            /  \    / \
                          10   40 60  90
                           \   /   \   \
                           20 35   70  110
                          / \         /
                        15  25      100     */

    printf("\nRemove Func Test 1: ");

	CHECK_FUNC(110 == *(int*)BSTIterRemove(BSTIterPrev(BSTIterEnd(bstTest))));
    
    printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nRemove Func Test 2: ");

	CHECK_FUNC(90 == *(int*)BSTIterRemove(BSTIterPrev(BSTIterPrev(BSTIterEnd(bstTest)))));
    
    printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nInsert & Begin & Next & Get Func Test:\n\n");

    iter = BSTIterBegin(bstTest);
		
	CHECK_FUNC(10 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(15 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(20 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(25 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(30 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(35 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(40 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(50 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(60 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(70 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(80 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(100 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(NULL == BSTIterGet(iter));

    printf("\nExpected: 13 SUCCESS (value check)\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTRemoveTest3(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int arr[ARR_SIZE];
    size_t i;
	
	printf("\033[1;34m\n*******BST Remove Test 3:*******\n\n\033[0m");
	
	printf("number of insert = 16\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

    SetArrayElements(arr);

    for (i = 0;i < 16;++i)
	{
		iter = BSTInsert(bstTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(NULL != iter);
	}
    
    printf("\nExpected: 16 SUCCESS (check status)\n");

                       /*         50
                                /   \
                              30     80
                            /  \    / \
                          10   40 60  90
                           \   /   \   \
                           20 35   70  110
                          / \         /
                        15  25      100     */

    printf("\nRemove Func Test: ");

	CHECK_FUNC(20 == *(int*)BSTIterRemove(BSTIterNext(BSTIterNext(BSTIterBegin(bstTest)))));
    
    printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nInsert & Begin & Next & Get Func Test:\n\n");

    iter = BSTIterBegin(bstTest);
		
	CHECK_FUNC(10 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(15 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(25 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(30 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(35 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(40 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(50 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(60 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(70 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(80 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(90 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(100 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(110 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(NULL == BSTIterGet(iter));

    printf("\nExpected: 14 SUCCESS (value check)\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTRemoveTest4(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int arr[ARR_SIZE];
    size_t i;
	
	printf("\033[1;34m\n*******BST Remove Test 4:*******\n\n\033[0m");
	
	printf("number of insert = 16\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

    SetArrayElements(arr);

    for (i = 0;i < 16;++i)
	{
		iter = BSTInsert(bstTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(NULL != iter);
	}
    
    printf("\nExpected: 16 SUCCESS (check status)\n");

                       /*         50
                                /   \
                              30     80
                            /  \    / \
                          10   40 60  90
                           \   /   \   \
                           20 35   70  110
                          / \         /
                        15  25      100     */

    printf("\nRemove Func Test: ");

	CHECK_FUNC(30 == *(int*)BSTIterRemove(BSTIterNext(BSTIterNext(BSTIterNext(BSTIterNext(BSTIterBegin(bstTest)))))));
    
    printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nInsert & Begin & Next & Get Func Test:\n\n");

    iter = BSTIterBegin(bstTest);
		
	CHECK_FUNC(10 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(15 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(20 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(25 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(35 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(40 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(50 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(60 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(70 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(80 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(90 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(100 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(110 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(NULL == BSTIterGet(iter));

    printf("\nExpected: 14 SUCCESS (value check)\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTRemoveTest5(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int arr[ARR_SIZE];
    size_t i;
	
	printf("\033[1;34m\n*******BST Remove Test 5:*******\n\n\033[0m");
	
	printf("number of insert = 16\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

    SetArrayElements(arr);

    for (i = 0;i < 16;++i)
	{
		iter = BSTInsert(bstTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(NULL != iter);
	}
    
    printf("\nExpected: 16 SUCCESS (check status)\n");

                       /*         50
                                /   \
                              30     80
                            /  \    / \
                          10   40 60  90
                           \   /   \   \
                           20 35   70  110
                          / \         /
                        15  25      100     */

    printf("\nRemove Func Test: ");

	CHECK_FUNC(50 == *(int*)BSTIterRemove(BSTIterNext(BSTIterNext(BSTIterNext(BSTIterNext(BSTIterNext(BSTIterNext(BSTIterNext(BSTIterBegin(bstTest))))))))));
    
    printf("\nExpected: 1 SUCCESS (value check)\n");

    printf("\nInsert & Begin & Next & Get Func Test:\n\n");

    iter = BSTIterBegin(bstTest);
		
	CHECK_FUNC(10 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(15 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(20 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(25 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(30 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

    CHECK_FUNC(35 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(40 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

    CHECK_FUNC(60 == *(int*)BSTIterGet(iter));
    
    iter = BSTIterNext(iter);

	CHECK_FUNC(70 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(80 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(90 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(100 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(110 == *(int*)BSTIterGet(iter));

    iter = BSTIterNext(iter);

	CHECK_FUNC(NULL == BSTIterGet(iter));

    printf("\nExpected: 14 SUCCESS (value check)\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTRemoveTest6(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
	
	printf("\033[1;34m\n*******BST Remove Test 6:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nRemove Func Test: ");

	CHECK_FUNC(NULL == BSTIterRemove(iter));
    
    printf("\nExpected: 1 SUCCESS (value check) - iter is NULL\n");

	BSTDestroy(&bstTest, FreeNodes);
}

void BSTRemoveTest7(void)
{
    BST_t *bstTest = NULL;
    BSTIter_t *iter = NULL;
    int arr[ARR_SIZE];
    size_t i;
	
	printf("\033[1;34m\n*******BST Remove Test 7:*******\n\n\033[0m");
	
	printf("number of insert = 16\n\n");

	printf("Create Func Test: ");

	bstTest = BSTCreate(CompareNodesData);
	
	CHECK_FUNC(NULL != bstTest);
	
	printf("\nExpected: SUCCESS (NULL != bstTest)\n");

    printf("\nInsert Func Test:\n\n");

    SetArrayElements(arr);

    for (i = 0;i < 16;++i)
	{
		iter = BSTInsert(bstTest, &arr[i]);
		
		printf("Insert number %ld check (status): ", i + 1);
		
		CHECK_FUNC(NULL != iter);
	}
    
    printf("\nExpected: 16 SUCCESS (check status)\n");

                       /*         50
                                /   \
                              30     80
                            /  \    / \
                          10   40 60  90
                           \   /   \   \
                           20 35   70  110
                          / \         /
                        15  25      100     */

    printf("\nRemove Func Test: ");

	CHECK_FUNC(NULL == BSTIterRemove(BSTIterEnd(bstTest)));
    
    printf("\nExpected: 1 SUCCESS (value check) - iter is end\n");

	BSTDestroy(&bstTest, FreeNodes);
}

int main(void)
{
    BSTCreateTest1();
    BSTCreateTest2();

    BSTInsertTest1();
    BSTInsertTest2();
    BSTInsertTest3();
    BSTInsertTest4();
    BSTInsertTest5();
    BSTInsertTest6();

    BSTFindTest1();
    BSTFindTest2();
    BSTFindTest3();

    BSTBeginTest1();
    BSTBeginTest2();
    BSTBeginTest3();

    BSTEndTest1();
    BSTEndTest2();

    BSTIsEqualTest();

    BSTNextTest1();
    BSTNextTest2();

    BSTPrevTest1();
    BSTPrevTest2();
    BSTPrevTest3();

    BSTGetTest1();
    BSTGetTest2();
    BSTGetTest3();

    BSTRemoveTest1();
    BSTRemoveTest2();
    BSTRemoveTest3();
    BSTRemoveTest4();
    BSTRemoveTest5();
    BSTRemoveTest6();
    BSTRemoveTest7();

    return 0;
}