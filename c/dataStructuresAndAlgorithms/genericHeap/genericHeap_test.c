#include <stdio.h> /* printf */
#include "genericVector.h" /* Generic Vector Header */
#include "genericHeap.h" /* Generic Heap Header */

#define ARR_SIZE (100)

#define DO_NOT_SWAP (0)
#define SWAP (1)

#define RUN_FOR_EACH_NEXT_ITER (1)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

/*****************************************************************************/

static int ComparatorFunc(const void *_firstElement, const void *_secondElement)
{
    if (*(int*)_firstElement < *(int*)_secondElement)
    {
        return SWAP;
    }

    return DO_NOT_SWAP;
}

static int PrintHeapElements(const void *_element, void *_context)
{
	(void)_context;

	printf("%d | ", *(int*)_element);

	return RUN_FOR_EACH_NEXT_ITER;
}

/*****************************************************************************/

void HeapBuildTest1(void)
{
	Vector_t *vectorTest = NULL;
	Heap_t *heapTest = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
	int arr[ARR_SIZE];
	int i, status;
	
	printf("\033[1;34m\n*******Heap Build Test 1:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 10\n\n");
	
	printf("Create Vector Func Test: ");
	
	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
    printf("\nAppend Func Test:\n\n");
	
    for (i = 0;i < 10;++i)
	{
		arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}
	
	printf("\nExpected: 10 SUCCESS (check status)\n");
	
    printf("\nAppend & Heap Size Func Test: ");

    CHECK_FUNC(10 == VectorSize(vectorTest));

	printf("\nBuild Heap Func Test: ");
	
	heapTest = HeapBuild(vectorTest, ComparatorFunc);

	CHECK_FUNC(NULL != heapTest);
	
	printf("\nExpected: SUCCESS (heapTest != NULL check)\n");
	
	HeapDestroy(&heapTest);
	VectorDestroy(&vectorTest, NULL);
}

void HeapBuildTest2(void)
{
	Vector_t *vectorTest = NULL;
	Heap_t *heapTest = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
	int arr[ARR_SIZE];
	int i, status;
	
	printf("\033[1;34m\n*******Heap Build Test 2:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 7\n\n");
	
	printf("Vector Create Func Test: ");
	
	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
    printf("\nVector Append Func Test:\n\n");
	
    for (i = 0;i < 7;++i)
	{
		arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}
	
	printf("\nExpected: 7 SUCCESS (check status)\n");
	
    printf("\nVector Append & Heap Size Func Test: ");

    CHECK_FUNC(7 == VectorSize(vectorTest));

	printf("\nHeap Build Func Test: ");
	
	heapTest = HeapBuild(vectorTest, ComparatorFunc);

	CHECK_FUNC(NULL != heapTest);
	
	printf("\nExpected: SUCCESS (heapTest != NULL check)\n\n");
	
	status = HeapForEach(heapTest, PrintHeapElements, NULL);

	printf("\n\nHeap For Each Func Test: ");

	CHECK_FUNC(7 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	HeapDestroy(&heapTest);
	VectorDestroy(&vectorTest, NULL);
}

void HeapBuildTest3(void)
{
	Vector_t *vectorTest = NULL;
	Heap_t *heapTest = NULL;
	
	printf("\033[1;34m\n*******Heap Build Test 3:*******\n\n\033[0m");
	
	printf("Build Heap Func Test: ");
	
	heapTest = HeapBuild(vectorTest, ComparatorFunc);

	CHECK_FUNC(NULL == heapTest);
	
	printf("\nExpected: SUCCESS (heapTest == NULL check) - vector is NULL\n");
}

void HeapBuildTest4(void)
{
	Vector_t *vectorTest = NULL;
	Heap_t *heapTest = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
	int arr[ARR_SIZE];
	int i, status;
	
	printf("\033[1;34m\n*******Heap Build Test 4:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 10\n\n");
	
	printf("Create Vector Func Test: ");
	
	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
    printf("\nAppend Func Test:\n\n");
	
    for (i = 0;i < 10;++i)
	{
		arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}
	
	printf("\nExpected: 10 SUCCESS (check status)\n");
	
    printf("\nAppend & Heap Size Func Test: ");

    CHECK_FUNC(10 == VectorSize(vectorTest));

	printf("\nBuild Heap Func Test: ");
	
	heapTest = HeapBuild(vectorTest, NULL);

	CHECK_FUNC(NULL == heapTest);
	
	printf("\nExpected: SUCCESS (heapTest -== NULL check) - compareFunc is NULL\n");
	
	HeapDestroy(&heapTest);
	VectorDestroy(&vectorTest, NULL);
}

void HeapDestroyTest1(void)
{
	Vector_t *vectorTest = NULL;
	Vector_t *vectorReturnValue = NULL;
	Heap_t *heapTest = NULL;
	Heap_t **pointerHeapTest = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
	int arr[ARR_SIZE];
	int i, status;
	
	printf("\033[1;34m\n*******Heap Destroy Test 1:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 10\n\n");
	
	printf("Create Vector Func Test: ");
	
	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
    printf("\nAppend Func Test:\n\n");
	
    for (i = 0;i < 10;++i)
	{
		arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}
	
	printf("\nExpected: 10 SUCCESS (check status)\n");
	
    printf("\nAppend & Size Func Test: ");

    CHECK_FUNC(10 == VectorSize(vectorTest));

	printf("\nBuild Heap Func Test: ");
	
	heapTest = HeapBuild(vectorTest, ComparatorFunc);
	pointerHeapTest = &heapTest;

	CHECK_FUNC(NULL != heapTest);
	
	printf("\nExpected: SUCCESS (heapTest != NULL check)\n");
	
	vectorReturnValue = HeapDestroy(pointerHeapTest);

	printf("\nDestroy & Heap Size Func Test: ");
			
	CHECK_FUNC(10 == VectorSize(vectorReturnValue));

	printf("\nExpected: SUCCESS (size check)\n");

	VectorDestroy(&vectorTest, NULL);
}

void HeapDestroyTest2(void)
{
	Heap_t *heapTest = NULL;
	Vector_t *vectorReturnValue = NULL;

	printf("\033[1;34m\n*******Heap Destroy Test 2:*******\n\n\033[0m");
		
	printf("Destroy Func Test: ");

	vectorReturnValue = HeapDestroy(&heapTest);

	CHECK_FUNC(NULL == vectorReturnValue);

	printf("\nExpected: SUCCESS (status check) - heapTest is NULL\n");
}

void HeapInsertTest1(void)
{
	Vector_t *vectorTest = NULL;
	Heap_t *heapTest = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
	int arr[ARR_SIZE];
	int i, status;
	
	printf("\033[1;34m\n*******Heap Insert Test 1:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 7, number of insert = 2\n\n");
	
	printf("Vector Create Func Test: ");
	
	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
    printf("\nVector Append Func Test:\n\n");
	
    for (i = 0;i < 7;++i)
	{
		arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}
	
	printf("\nExpected: 7 SUCCESS (check status)\n");
	
    printf("\nVector Append & Size Func Test: ");

    CHECK_FUNC(7 == VectorSize(vectorTest));

	printf("\nHeap Build Func Test: ");
	
	heapTest = HeapBuild(vectorTest, ComparatorFunc);

	CHECK_FUNC(NULL != heapTest);
	
	printf("\nExpected: SUCCESS (heapTest != NULL check)\n\n");
	
	status = HeapForEach(heapTest, PrintHeapElements, NULL);

	printf("\n\nHeap For Each Func Test: ");

	CHECK_FUNC(7 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	printf("\nHeap Insert Func Test: ");

	for (i = 7;i < 9;++i)
	{
		arr[i] = i - 1;

		status = HeapInsert(heapTest, &arr[i]);

		printf("Insert number %d check (status): ", i - 6);
		
		CHECK_FUNC(HEAP_SUCCESS == status);
	}

    printf("\nExpected: 2 SUCCESS (for each check)\n");

	status = HeapForEach(heapTest, PrintHeapElements, NULL);

	printf("\n\nHeap For Each Func Test: ");

	CHECK_FUNC(9 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	HeapDestroy(&heapTest);
	VectorDestroy(&vectorTest, NULL);
}

void HeapInsertTest2(void)
{
	Vector_t *vectorTest = NULL;
	Heap_t *heapTest = NULL;
	size_t initialCapacity = 1;
	size_t incBlockSize = 2;
	int arr[ARR_SIZE];
	int i, status;
	
	printf("\033[1;34m\n*******Heap Insert Test 2:*******\n\n\033[0m");
	
	printf("initialCapacity = 1, incBlockSize = 2, number of append = 7, number of insert = 2\n\n");
	
	printf("Vector Create Func Test: ");
	
	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
    printf("\nVector Append Func Test:\n\n");
	
    for (i = 0;i < 7;++i)
	{
		arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}
	
	printf("\nExpected: 7 SUCCESS (check status)\n");
	
    printf("\nVector Append & Size Func Test: ");

    CHECK_FUNC(7 == VectorSize(vectorTest));

	printf("\nHeap Build Func Test: ");
	
	heapTest = HeapBuild(vectorTest, ComparatorFunc);

	CHECK_FUNC(NULL != heapTest);
	
	printf("\nExpected: SUCCESS (heapTest != NULL check)\n\n");
	
	status = HeapForEach(heapTest, PrintHeapElements, NULL);

	printf("\n\nHeap For Each Func Test: ");

	CHECK_FUNC(7 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	printf("\nHeap Insert Func Test: ");

	for (i = 7;i < 9;++i)
	{
		arr[i] = i - 1;

		status = HeapInsert(heapTest, &arr[i]);

		printf("Insert number %d check (status): ", i - 6);
		
		CHECK_FUNC(HEAP_SUCCESS == status);
	}

    printf("\nExpected: 2 SUCCESS (for each check)\n");

	status = HeapForEach(heapTest, PrintHeapElements, NULL);

	printf("\n\nHeap For Each Func Test: ");

	CHECK_FUNC(9 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	HeapDestroy(&heapTest);
	VectorDestroy(&vectorTest, NULL);
}

void HeapInsertTest3(void)
{
	Vector_t *vectorTest = NULL;
	Heap_t *heapTest = NULL;
	size_t initialCapacity = 7;
	size_t incBlockSize = 0;
	int arr[ARR_SIZE];
	int i, status;
	
	printf("\033[1;34m\n*******Heap Insert Test 3:*******\n\n\033[0m");
	
	printf("initialCapacity = 7, incBlockSize = 0, number of append = 7, number of insert = 2\n\n");
	
	printf("Vector Create Func Test: ");
	
	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
    printf("\nVector Append Func Test:\n\n");
	
    for (i = 0;i < 7;++i)
	{
		arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}
	
	printf("\nExpected: 7 SUCCESS (check status)\n");
	
    printf("\nVector Append & Size Func Test: ");

    CHECK_FUNC(7 == VectorSize(vectorTest));

	printf("\nHeap Build Func Test: ");
	
	heapTest = HeapBuild(vectorTest, ComparatorFunc);

	CHECK_FUNC(NULL != heapTest);
	
	printf("\nExpected: SUCCESS (heapTest != NULL check)\n\n");
	
	status = HeapForEach(heapTest, PrintHeapElements, NULL);

	printf("\n\nHeap For Each Func Test: ");

	CHECK_FUNC(7 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	printf("\nHeap Insert Func Test: ");

	for (i = 7;i < 9;++i)
	{
		arr[i] = i - 1;

		status = HeapInsert(heapTest, &arr[i]);

		printf("Insert number %d check (status): ", i - 6);
		
		CHECK_FUNC(VECTOR_ERROR == status);
	}

    printf("\nExpected: 2 SUCCESS (for each check)\n");

	status = HeapForEach(heapTest, PrintHeapElements, NULL);

	printf("\n\nHeap For Each Func Test: ");

	CHECK_FUNC(7 == status);

    printf("\nExpected: 1 SUCCESS (for each check) - increase block size 0\n");

	HeapDestroy(&heapTest);
	VectorDestroy(&vectorTest, NULL);
}

void HeapInsertTest4(void)
{
	Heap_t *heapTest = NULL;
	int arr[ARR_SIZE];
	int i, status;
	
	printf("\033[1;34m\n*******Heap Insert Test 4:*******\n\n\033[0m");
	
	printf("number of insert = 2\n\n");

	printf("Heap Insert Func Test:\n\n");

	for (i = 7;i < 9;++i)
	{
		arr[i] = i - 1;

		status = HeapInsert(heapTest, &arr[i]);

		printf("Insert number %d check (status): ", i - 6);
		
		CHECK_FUNC(HEAP_POINTER_NOT_INITIALIZE == status);
	}

    printf("\nExpected: 2 SUCCESS (for each check) - heap is NULL\n");
}

void HeapPeekTest1(void)
{
	Vector_t *vectorTest = NULL;
	Heap_t *heapTest = NULL;
	const void *maxElement = NULL;
	size_t initialCapacity = 1;
	size_t incBlockSize = 2;
	int arr[ARR_SIZE];
	int i, status;
	
	printf("\033[1;34m\n*******Heap Peek Test 1:*******\n\n\033[0m");
	
	printf("initialCapacity = 1, incBlockSize = 2, number of append = 7, number of insert = 2, number of peek = 2\n\n");
	
	printf("Vector Create Func Test: ");
	
	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
    printf("\nVector Append Func Test:\n\n");
	
    for (i = 0;i < 7;++i)
	{
		arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}
	
	printf("\nExpected: 7 SUCCESS (check status)\n");
	
    printf("\nVector Append & Size Func Test: ");

    CHECK_FUNC(7 == VectorSize(vectorTest));

	printf("\nHeap Build Func Test: ");
	
	heapTest = HeapBuild(vectorTest, ComparatorFunc);

	CHECK_FUNC(NULL != heapTest);
	
	printf("\nExpected: SUCCESS (heapTest != NULL check)\n\n");
	
	status = HeapForEach(heapTest, PrintHeapElements, NULL);

	printf("\n\nHeap For Each Func Test: ");

	CHECK_FUNC(7 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	printf("\nHeap Max Func Test 1: ");

	maxElement = HeapPeek(heapTest);

	CHECK_FUNC(6 == *(int*)maxElement);

	printf("\nExpected: 1 SUCCESS (max value check)\n");

	printf("\nHeap Insert Func Test: ");

	for (i = 7;i < 9;++i)
	{
		arr[i] = i - 1;

		status = HeapInsert(heapTest, &arr[i]);

		printf("Insert number %d check (status): ", i - 6);
		
		CHECK_FUNC(HEAP_SUCCESS == status);
	}

    printf("\nExpected: 2 SUCCESS (for each check)\n\n");

	status = HeapForEach(heapTest, PrintHeapElements, NULL);

	printf("\n\nHeap For Each Func Test: ");

	CHECK_FUNC(9 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	printf("\nHeap Max Func Test 2: ");

	maxElement = HeapPeek(heapTest);

	CHECK_FUNC(7 == *(int*)maxElement);

	printf("\nExpected: 1 SUCCESS (max value check)\n");

	HeapDestroy(&heapTest);
	VectorDestroy(&vectorTest, NULL);
}

void HeapPeekTest2(void)
{
	Vector_t *vectorTest = NULL;
	Heap_t *heapTest = NULL;
	const void *maxElement = NULL;
	size_t initialCapacity = 1;
	size_t incBlockSize = 2;
	
	printf("\033[1;34m\n*******Heap Peek Test 2:*******\n\n\033[0m");
	
	printf("initialCapacity = 1, incBlockSize = 2\n\n");
	
	printf("Vector Create Func Test: ");
	
	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

	printf("\nHeap Build Func Test: ");
	
	heapTest = HeapBuild(vectorTest, ComparatorFunc);

	CHECK_FUNC(NULL != heapTest);
	
	printf("\nExpected: SUCCESS (heapTest != NULL check)\n\n");

	printf("Heap Max Func Test: ");

	maxElement = HeapPeek(heapTest);

	CHECK_FUNC(NULL == maxElement);

	printf("\nExpected: 1 SUCCESS (max value check) - heap size 0\n");

	HeapDestroy(&heapTest);
	VectorDestroy(&vectorTest, NULL);
}

void HeapPeekTest3(void)
{
	Heap_t *heapTest = NULL;
	const void *maxElement = NULL;
	
	printf("\033[1;34m\n*******Heap Peek Test 3:*******\n\n\033[0m");

	printf("Heap Max Func Test: ");

	maxElement = HeapPeek(heapTest);

	CHECK_FUNC(NULL == maxElement);

	printf("\nExpected: 1 SUCCESS (max value check) - heapTest is NULL\n");
}

void HeapExtractMaxTest1(void)
{
	Vector_t *vectorTest = NULL;
	Heap_t *heapTest = NULL;
	const void *maxElement = NULL;
	size_t initialCapacity = 1;
	size_t incBlockSize = 2;
	int arr[ARR_SIZE];
	int i, status;
	
	printf("\033[1;34m\n*******Heap Extract Max Test 1:*******\n\n\033[0m");
	
	printf("initialCapacity = 1, incBlockSize = 2, number of append = 7, number of insert = 2, number of extract = 2\n\n");
	
	printf("Vector Create Func Test: ");
	
	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
    printf("\nVector Append Func Test:\n\n");
	
    for (i = 0;i < 7;++i)
	{
		arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}
	
	printf("\nExpected: 7 SUCCESS (check status)\n");
	
    printf("\nVector Append & Size Func Test: ");

    CHECK_FUNC(7 == VectorSize(vectorTest));

	printf("\nHeap Build Func Test: ");
	
	heapTest = HeapBuild(vectorTest, ComparatorFunc);

	CHECK_FUNC(NULL != heapTest);
	
	printf("\nExpected: SUCCESS (heapTest != NULL check)\n\n");
	
	status = HeapForEach(heapTest, PrintHeapElements, NULL);

	printf("\n\nHeap For Each Func Test: ");

	CHECK_FUNC(7 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	printf("\nExtract Max Func Test 1: ");

	maxElement = HeapExtractMax(heapTest);

	CHECK_FUNC(6 == *(int*)maxElement);

	printf("\nExpected: 1 SUCCESS (extract max value check)\n\n");

	status = HeapForEach(heapTest, PrintHeapElements, NULL);

	printf("\n\nHeap For Each Func Test: ");

	CHECK_FUNC(6 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	printf("\nHeap Extract Max Func Test 2: ");

	maxElement = HeapExtractMax(heapTest);

	CHECK_FUNC(5 == *(int*)maxElement);

	printf("\nExpected: 1 SUCCESS (extract max value check)\n\n");

	status = HeapForEach(heapTest, PrintHeapElements, NULL);

	printf("\n\nHeap For Each Func Test: ");

	CHECK_FUNC(5 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	HeapDestroy(&heapTest);
	VectorDestroy(&vectorTest, NULL);
}

void HeapExtractMaxTest2(void)
{
	Vector_t *vectorTest = NULL;
	Heap_t *heapTest = NULL;
	const void *maxElement = NULL;
	size_t initialCapacity = 1;
	size_t incBlockSize = 2;
	
	printf("\033[1;34m\n*******Heap Extract Max Test 2:*******\n\n\033[0m");
	
	printf("initialCapacity = 1, incBlockSize = 2\n\n");
	
	printf("Vector Create Func Test: ");
	
	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

	printf("\nHeap Build Func Test: ");
	
	heapTest = HeapBuild(vectorTest, ComparatorFunc);

	CHECK_FUNC(NULL != heapTest);
	
	printf("\nExpected: SUCCESS (heapTest != NULL check)\n\n");

	printf("Heap Extract Max Func Test: ");

	maxElement = HeapExtractMax(heapTest);

	CHECK_FUNC(NULL == maxElement);

	printf("\nExpected: 1 SUCCESS (extract max value check) - heap size is 0\n");

	HeapDestroy(&heapTest);
	VectorDestroy(&vectorTest, NULL);
}

void HeapExtractMaxTest3(void)
{
	Heap_t *heapTest = NULL;
	const void *maxElement = NULL;
	
	printf("\033[1;34m\n*******Heap Extract Max Test 3:*******\n\n\033[0m");

	printf("Heap Extract Max Func Test: ");

	maxElement = HeapExtractMax(heapTest);

	CHECK_FUNC(NULL == maxElement);

	printf("\nExpected: 1 SUCCESS (extract max value check) - heapTest is NULL\n");
}

void HeapSizeTest1(void)
{
	Vector_t *vectorTest = NULL;
	Heap_t *heapTest = NULL;
	size_t initialCapacity = 1;
	size_t incBlockSize = 2;
	int arr[ARR_SIZE];
	int i, status;
	
	printf("\033[1;34m\n*******Heap Size Test 1:*******\n\n\033[0m");
	
	printf("initialCapacity = 1, incBlockSize = 2, number of append = 7, number of insert = 2, number of size = 2\n\n");
	
	printf("Vector Create Func Test: ");
	
	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
    printf("\nVector Append Func Test:\n\n");
	
    for (i = 0;i < 7;++i)
	{
		arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}
	
	printf("\nExpected: 7 SUCCESS (check status)\n");
	
    printf("\nVector Append & Size Func Test: ");

    CHECK_FUNC(7 == VectorSize(vectorTest));

	printf("\nHeap Build Func Test: ");
	
	heapTest = HeapBuild(vectorTest, ComparatorFunc);

	CHECK_FUNC(NULL != heapTest);
	
	printf("\nExpected: SUCCESS (heapTest != NULL check)\n\n");
	
	status = HeapForEach(heapTest, PrintHeapElements, NULL);

	printf("\n\nHeap For Each Func Test: ");

	CHECK_FUNC(7 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	printf("\nHeap size Func Test 1: ");

	CHECK_FUNC(7 == HeapSize(heapTest));

	printf("\nExpected: 1 SUCCESS (check size value)\n");

	printf("\nHeap Insert Func Test: ");

	for (i = 7;i < 9;++i)
	{
		arr[i] = i - 1;

		status = HeapInsert(heapTest, &arr[i]);

		printf("Insert number %d check (status): ", i - 6);
		
		CHECK_FUNC(HEAP_SUCCESS == status);
	}

    printf("\nExpected: 2 SUCCESS (for each check)\n\n");

	status = HeapForEach(heapTest, PrintHeapElements, NULL);

	printf("\n\nHeap For Each Func Test: ");

	CHECK_FUNC(9 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	printf("\nHeap size Func Test 2: ");

	CHECK_FUNC(9 == HeapSize(heapTest));

	printf("\nExpected: 1 SUCCESS (check size value)\n");

	HeapDestroy(&heapTest);
	VectorDestroy(&vectorTest, NULL);
}

void HeapSizeTest2(void)
{
	Heap_t *heapTest = NULL;
	
	printf("\033[1;34m\n*******Heap Size Test 2:*******\n\n\033[0m");

	printf("Heap size Func Test: ");

	CHECK_FUNC(POINTER_NOT_INITIALIZE_HEAP_SIZE == HeapSize(heapTest));

	printf("\nExpected: 1 SUCCESS (check size value)\n");
}

void HeapForEachTest1(void)
{
	Vector_t *vectorTest = NULL;
	Heap_t *heapTest = NULL;
	size_t initialCapacity = 1;
	size_t incBlockSize = 2;
	int arr[ARR_SIZE];
	int i, status;
	
	printf("\033[1;34m\n*******Heap For Each Test 1:*******\n\n\033[0m");
	
	printf("initialCapacity = 1, incBlockSize = 2, number of append = 7, number of insert = 2, number for each = 2\n\n");
	
	printf("Vector Create Func Test: ");
	
	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
    printf("\nVector Append Func Test:\n\n");
	
    for (i = 0;i < 7;++i)
	{
		arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}
	
	printf("\nExpected: 7 SUCCESS (check status)\n");
	
    printf("\nVector Append & Size Func Test: ");

    CHECK_FUNC(7 == VectorSize(vectorTest));

	printf("\nHeap Build Func Test: ");
	
	heapTest = HeapBuild(vectorTest, ComparatorFunc);

	CHECK_FUNC(NULL != heapTest);
	
	printf("\nExpected: SUCCESS (heapTest != NULL check)\n\n");
	
	status = HeapForEach(heapTest, PrintHeapElements, NULL);

	printf("\n\nHeap For Each Func Test: ");

	CHECK_FUNC(7 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	printf("\nHeap size Func Test 1: ");

	CHECK_FUNC(7 == HeapSize(heapTest));

	printf("\nExpected: 1 SUCCESS (check size value)\n");

	printf("\nHeap Insert Func Test: ");

	for (i = 7;i < 9;++i)
	{
		arr[i] = i - 1;

		status = HeapInsert(heapTest, &arr[i]);

		printf("Insert number %d check (status): ", i - 6);
		
		CHECK_FUNC(HEAP_SUCCESS == status);
	}

    printf("\nExpected: 2 SUCCESS (for each check)\n\n");

	status = HeapForEach(heapTest, PrintHeapElements, NULL);

	printf("\n\nHeap For Each Func Test: ");

	CHECK_FUNC(9 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	printf("\nHeap size Func Test 2: ");

	CHECK_FUNC(9 == HeapSize(heapTest));

	printf("\nExpected: 1 SUCCESS (check size value)\n");

	HeapDestroy(&heapTest);
	VectorDestroy(&vectorTest, NULL);
}

void HeapForEachTest2(void)
{
	Vector_t *vectorTest = NULL;
	Heap_t *heapTest = NULL;
	size_t initialCapacity = 1;
	size_t incBlockSize = 2;
	int status;
	
	printf("\033[1;34m\n*******Heap For Each Test 2:*******\n\n\033[0m");
	
	printf("initialCapacity = 1, incBlockSize = 2\n\n");
	
	printf("Vector Create Func Test: ");
	
	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

	printf("\nHeap Build Func Test: ");
	
	heapTest = HeapBuild(vectorTest, ComparatorFunc);

	CHECK_FUNC(NULL != heapTest);
	
	printf("\nExpected: SUCCESS (heapTest != NULL check)\n\n");
	
	status = HeapForEach(heapTest, PrintHeapElements, NULL);

	printf("Heap For Each Func Test: ");

	CHECK_FUNC(UNDERFLOW_HEAP_FOR_EACH == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	HeapDestroy(&heapTest);
	VectorDestroy(&vectorTest, NULL);
}

void HeapForEachTest3(void)
{
	Heap_t *heapTest = NULL;
	int status;
	
	printf("\033[1;34m\n*******Heap For Each Test 3:*******\n\n\033[0m");
	
	printf("initialCapacity = 1, incBlockSize = 2\n\n");
		
	status = HeapForEach(heapTest, PrintHeapElements, NULL);

	printf("Heap For Each Func Test: ");

	CHECK_FUNC(POINTER_NOT_INITIALIZE_HEAP_FOR_EACH == status);

    printf("\nExpected: 1 SUCCESS (for each check) - vectorTest is NULL\n");
}

void HeapForEachTest4(void)
{
	Vector_t *vectorTest = NULL;
	Heap_t *heapTest = NULL;
	size_t initialCapacity = 1;
	size_t incBlockSize = 2;
	int arr[ARR_SIZE];
	int i, status;
	
	printf("\033[1;34m\n*******Heap For Each Test 4:*******\n\n\033[0m");
	
	printf("initialCapacity = 1, incBlockSize = 2, number of append = 7\n\n");
	
	printf("Vector Create Func Test: ");
	
	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
    printf("\nVector Append Func Test:\n\n");
	
    for (i = 0;i < 7;++i)
	{
		arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}
	
	printf("\nExpected: 7 SUCCESS (check status)\n");
	
    printf("\nVector Append & Size Func Test: ");

    CHECK_FUNC(7 == VectorSize(vectorTest));

	printf("\nHeap Build Func Test: ");
	
	heapTest = HeapBuild(vectorTest, ComparatorFunc);

	CHECK_FUNC(NULL != heapTest);
	
	printf("\nExpected: SUCCESS (heapTest != NULL check)\n\n");
	
	status = HeapForEach(heapTest, NULL, NULL);

	printf("Heap For Each Func Test: ");

	CHECK_FUNC(POINTER_NOT_INITIALIZE_HEAP_FOR_EACH == status);

    printf("\nExpected: 1 SUCCESS (for each check) - actionFunc is NULL\n");

	HeapDestroy(&heapTest);
	VectorDestroy(&vectorTest, NULL);
}

int main(void)
{
	HeapBuildTest1();
	HeapBuildTest2();
	HeapBuildTest3();
	HeapBuildTest4();

	HeapDestroyTest1();
	HeapDestroyTest2();

	HeapInsertTest1();
	HeapInsertTest2();
	HeapInsertTest3();
	HeapInsertTest4();

	HeapPeekTest1();
	HeapPeekTest2();
	HeapPeekTest3();

	HeapExtractMaxTest1();
	HeapExtractMaxTest2();
	HeapExtractMaxTest3();

	HeapSizeTest1();
	HeapSizeTest2();

	HeapForEachTest1();
	HeapForEachTest2();
	HeapForEachTest3();
	HeapForEachTest4();

	return 0;
}
