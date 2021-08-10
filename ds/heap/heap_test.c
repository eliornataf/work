#include <stdio.h> /* printf, rand */
#include <time.h> /* srand */
#include "heap.h" /* Heap Header */
#include "dynamicVector.h" /* Dynamic Vector Header */

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

#define NUM_LIMIT (10)

void HeapBuildTest1(void)
{
	Vector_t *vector = NULL;
	Heap_t *heap = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int i, status;
	
	printf("\033[1;34m\n*******Heap Build Test 1:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 10\n\n");
	
	printf("Create Vector Func Test: ");
	
	vector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vector);
	
	printf("\nExpected: SUCCESS (vector != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 10;++i)
	{
		status = VectorPush(vector, rand() % NUM_LIMIT);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 10 SUCCESS (check status)\n");
	
	printf("\nBuild Heap Func Test: ");
	
	heap = HeapBuild(vector);
	
	CHECK_FUNC(NULL != heap);
	
	printf("\nExpected: SUCCESS (heap != NULL check)\n");
	
	VectorDestroy(vector);
	
	HeapDestroy(heap);
}

void HeapBuildTest2(void)
{
	Vector_t *vector = NULL;
	Heap_t *heap = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int i, status;
	time_t currentTime;
	
	srand((unsigned)time(&currentTime));
	
	printf("\033[1;34m\n*******Heap Build Test 2:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 10\n\n");
	
	printf("Create Vector Func Test: ");
	
	vector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vector);
	
	printf("\nExpected: SUCCESS (vector != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 10;++i)
	{
		status = VectorPush(vector, rand() % NUM_LIMIT);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 10 SUCCESS (check status)\n");
	
	printf("\nPrint Vector:\n\n");
	
	VectorPrint(vector);
	
	printf("\nBuild Heap Func Test: ");
	
	heap = HeapBuild(vector);
	
	CHECK_FUNC(NULL != heap);
	
	printf("\nExpected: SUCCESS (heap != NULL check)\n");
	
	printf("\nPrint Heap:\n\n");
	
	HeapPrint(heap);
	
	VectorDestroy(vector);
	
	HeapDestroy(heap);
}

void HeapBuildTest3(void)
{
	Vector_t *vector = NULL;
	Heap_t *heap = NULL;
	
	printf("\033[1;34m\n*******Heap Build Test 3:*******\n\n\033[0m");
	
	printf("Build Heap Func Test: ");
	
	heap = HeapBuild(vector);
	
	CHECK_FUNC(NULL == heap);
	
	printf("\nExpected: SUCCESS (heap == NULL check) - vector is NULL\n");
	
	HeapDestroy(heap);
}

void HeapInsertTest1(void)
{
	Vector_t *vector = NULL;
	Heap_t *heap = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int inputData = 10;
	int i, status;
	time_t currentTime;
	
	srand((unsigned)time(&currentTime));
	
	printf("\033[1;34m\n*******Heap Insert Test 1:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 5, Number of Insert = 1\n\n");
	
	printf("Create Vector Func Test: ");
	
	vector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vector);
	
	printf("\nExpected: SUCCESS (vector != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 5;++i)
	{
		status = VectorPush(vector, rand() % NUM_LIMIT);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status)\n");
	
	printf("\nPrint Vector:\n\n");
	
	VectorPrint(vector);
	
	printf("\nBuild Heap Func Test: ");
	
	heap = HeapBuild(vector);
	
	CHECK_FUNC(NULL != heap);
	
	printf("\nExpected: SUCCESS (heap != NULL check)\n");
	
	printf("\nPrint Heap:\n\n");
	
	HeapPrint(heap);
	
	printf("\nInsert Heap:\n\n");
	
	status = HeapInsert(heap, inputData);
	
	printf("Insert number 1 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 1 SUCCESS (check status)\n");
	
	VectorDestroy(vector);
	
	HeapDestroy(heap);
}

void HeapInsertTest2(void)
{
	Vector_t *vector = NULL;
	Heap_t *heap = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int inputData = 10;
	int i, status;
	time_t currentTime;
	
	srand((unsigned)time(&currentTime));
	
	printf("\033[1;34m\n*******Heap Insert Test 2:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 5, Number of Insert = 3\n\n");
	
	printf("Create Vector Func Test: ");
	
	vector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vector);
	
	printf("\nExpected: SUCCESS (vector != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 5;++i)
	{
		status = VectorPush(vector, rand() % NUM_LIMIT);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status)\n");
	
	printf("\nPrint Vector:\n\n");
	
	VectorPrint(vector);
	
	printf("\nBuild Heap Func Test: ");
	
	heap = HeapBuild(vector);
	
	CHECK_FUNC(NULL != heap);
	
	printf("\nExpected: SUCCESS (heap != NULL check)\n");
	
	printf("\nPrint Heap:\n\n");
	
	HeapPrint(heap);
	
	printf("\nInsert Heap:\n\n");
	
	for (i = 0;i < 3;++i)
	{
		status = HeapInsert(heap, inputData + i);
	
		printf("Insert number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 3 SUCCESS (check status)\n");
	
	printf("\nPrint Heap:\n\n");
	
	HeapPrint(heap);

	VectorDestroy(vector);
	
	HeapDestroy(heap);
}

void HeapInsertTest3(void)
{
	Heap_t *heap = NULL;
	int inputData = 10;
	int status;
	time_t currentTime;
	
	srand((unsigned)time(&currentTime));
	
	printf("\033[1;34m\n*******Heap Insert Test 2:*******\n\n\033[0m");
	
	printf("\nInsert Heap:\n\n");
	
	status = HeapInsert(heap, inputData);
	
	printf("Insert number 1 check (status): ");
		
	CHECK_FUNC(POINTER_NOT_INITIALIZE == status);
	
	printf("\nExpected: 1 SUCCESS (check status) - heap is NULL\n");
}

void HeapInsertTest4(void)
{
	Vector_t *vector = NULL;
	Heap_t *heap = NULL;
	int capacity = 5;
	int incBlockSize = 0;
	int inputData = 10;
	int i, status;
	time_t currentTime;
	
	srand((unsigned)time(&currentTime));
	
	printf("\033[1;34m\n*******Heap Insert Test 4:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 0, Number of Push = 5, Number of Insert = 3\n\n");
	
	printf("Create Vector Func Test: ");
	
	vector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vector);
	
	printf("\nExpected: SUCCESS (vector != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 5;++i)
	{
		status = VectorPush(vector, rand() % NUM_LIMIT);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status)\n");
	
	printf("\nBuild Heap Func Test: ");
	
	heap = HeapBuild(vector);
	
	CHECK_FUNC(NULL != heap);
	
	printf("\nExpected: SUCCESS (heap != NULL check)\n");
	
	printf("\nInsert Heap:\n\n");
	
	for (i = 0;i < 3;++i)
	{
		status = HeapInsert(heap, inputData + i);
	
		printf("Insert number %d check (status): ", i + 1);
		
		CHECK_FUNC(OVERFLOW == status);
	}
	
	printf("\nExpected: 3 SUCCESS (check status) - OVERFLOW\n");

	VectorDestroy(vector);
	
	HeapDestroy(heap);
}

void HeapInsertTest5(void)
{
	Vector_t *vector = NULL;
	Heap_t *heap = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int inputData = 10;
	int i, status;
	time_t currentTime;
	
	srand((unsigned)time(&currentTime));
	
	printf("\033[1;34m\n*******Heap Insert Test 5:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 5, Number of Insert = 3\n\n");
	
	printf("Create Vector Func Test: ");
	
	vector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vector);
	
	printf("\nExpected: SUCCESS (vector != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 5;++i)
	{
		status = VectorPush(vector, rand() % NUM_LIMIT);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status)\n");
	
	printf("\nPrint Vector:\n\n");
	
	VectorPrint(vector);
	
	printf("\nBuild Heap Func Test: ");
	
	heap = HeapBuild(vector);
	
	CHECK_FUNC(NULL != heap);
	
	printf("\nExpected: SUCCESS (heap != NULL check)\n");
	
	printf("\nPrint Heap:\n\n");
	
	HeapPrint(heap);
	
	printf("\nInsert Heap:\n\n");
	
	for (i = 0;i < 3;++i)
	{
		status = HeapInsert(heap, inputData);
	
		printf("Insert number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 3 SUCCESS (check status)\n");
	
	printf("\nPrint Heap:\n\n");
	
	HeapPrint(heap);

	VectorDestroy(vector);
	
	HeapDestroy(heap);
}

void HeapMaxTest1(void)
{
	Vector_t *vector = NULL;
	Heap_t *heap = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int i, status, outputData;
	time_t currentTime;
	
	srand((unsigned)time(&currentTime));
	
	printf("\033[1;34m\n*******Heap Max Test 1:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 5, Number of Max = 1\n\n");
	
	printf("Create Vector Func Test: ");
	
	vector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vector);
	
	printf("\nExpected: SUCCESS (vector != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 5;++i)
	{
		status = VectorPush(vector, rand() % NUM_LIMIT);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status)\n");
	
	printf("\nPrint Vector:\n\n");
	
	VectorPrint(vector);
	
	printf("\nBuild Heap Func Test: ");
	
	heap = HeapBuild(vector);
	
	CHECK_FUNC(NULL != heap);
	
	printf("\nExpected: SUCCESS (heap != NULL check)\n");
	
	printf("\nPrint Heap:\n\n");
	
	HeapPrint(heap);
	
	printf("\nMax Heap: ");
	
	status = HeapMax(heap, &outputData);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 1 SUCCESS (check status)\n");
	
	printf("\nPrint Max: %d\n\n", outputData);

	VectorDestroy(vector);
	
	HeapDestroy(heap);
}

void HeapMaxTest2(void)
{
	Heap_t *heap = NULL;
	int status, outputData;
	time_t currentTime;
	
	srand((unsigned)time(&currentTime));
	
	printf("\033[1;34m\n*******Heap Max Test 2:*******\n\n\033[0m");
	
	printf("Max Heap: ");
	
	status = HeapMax(heap, &outputData);
	
	CHECK_FUNC(POINTER_NOT_INITIALIZE == status);
	
	printf("\nExpected: 1 SUCCESS (check status) - heap == null\n");
	
	HeapDestroy(heap);
}

void HeapMaxTest3(void)
{
	Vector_t *vector = NULL;
	Heap_t *heap = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int status, outputData;
	time_t currentTime;
	
	srand((unsigned)time(&currentTime));
	
	printf("\033[1;34m\n*******Heap Max Test 3:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Max = 1\n\n");
	
	printf("Create Vector Func Test: ");
	
	vector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vector);
	
	printf("\nExpected: SUCCESS (vector != NULL check)\n");
	
	printf("\nBuild Heap Func Test: ");
	
	heap = HeapBuild(vector);
	
	CHECK_FUNC(NULL != heap);
	
	printf("\nExpected: SUCCESS (heap != NULL check)\n");
	
	printf("\nMax Heap: ");
	
	status = HeapMax(heap, &outputData);
	
	CHECK_FUNC(UNDERFLOW == status);
	
	printf("\nExpected: 1 SUCCESS (check status) - UNDERFLOW\n");

	VectorDestroy(vector);
	
	HeapDestroy(heap);
}

void HeapExtractMaxTest1(void)
{
	Vector_t *vector = NULL;
	Heap_t *heap = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int i, status, outputData;
	time_t currentTime;
	
	srand((unsigned)time(&currentTime));
	
	printf("\033[1;34m\n*******Heap Max Test 1:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 5, Number of Extract = 3\n\n");
	
	printf("Create Vector Func Test: ");
	
	vector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vector);
	
	printf("\nExpected: SUCCESS (vector != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 5;++i)
	{
		status = VectorPush(vector, rand() % NUM_LIMIT);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status)\n");
	
	printf("\nBuild Heap Func Test: ");
	
	heap = HeapBuild(vector);
	
	CHECK_FUNC(NULL != heap);
	
	printf("\nExpected: SUCCESS (heap != NULL check)\n");
	
	printf("\nPrint Heap:\n\n");
	
	HeapPrint(heap);
	
	for (i = 0;i < 2;++i)
	{
		status = HeapExtractMax(heap, &outputData);
	
		printf("\nExtract number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
		
		printf("\nThe OutputData is: %d\n\n", outputData);
		
		HeapPrint(heap);
	}
	
	printf("\nExpected: 3 SUCCESS (check status)\n");

	VectorDestroy(vector);
	
	HeapDestroy(heap);
}

void HeapExtractMaxTest2(void)
{
	Heap_t *heap = NULL;
	int status, outputData;
	
	printf("\033[1;34m\n*******Heap Max Test 2:*******\n\n\033[0m");
	
	status = HeapExtractMax(heap, &outputData);
	
	printf("Extract number 1 check (status): ");
		
	CHECK_FUNC(POINTER_NOT_INITIALIZE == status);
	
	printf("\nExpected: 1 SUCCESS (check status) - heap == NULL\n");
}

void HeapExtractMaxTest3(void)
{
	Vector_t *vector = NULL;
	Heap_t *heap = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int i, status, outputData;
	time_t currentTime;
	
	srand((unsigned)time(&currentTime));
	
	printf("\033[1;34m\n*******Heap Max Test 3:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 0, Number of Extract = 2\n\n");
	
	printf("Create Vector Func Test: ");
	
	vector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vector);
	
	printf("\nExpected: SUCCESS (vector != NULL check)\n");
	
	printf("\nBuild Heap Func Test: ");
	
	heap = HeapBuild(vector);
	
	CHECK_FUNC(NULL != heap);
	
	printf("\nExpected: SUCCESS (heap != NULL check)\n");
	
	for (i = 0;i < 2;++i)
	{
		status = HeapExtractMax(heap, &outputData);
	
		printf("\nExtract number %d check (status): ", i + 1);
		
		CHECK_FUNC(UNDERFLOW == status);
	}
	
	printf("\nExpected: 2 SUCCESS (check status) - UNDERFLOW\n");

	VectorDestroy(vector);
	
	HeapDestroy(heap);
}

void HeapItemsNum1(void)
{
	Vector_t *vector = NULL;
	Heap_t *heap = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int inputData = 10;
	int i, status, numOfItems;
	time_t currentTime;
	
	srand((unsigned)time(&currentTime));
	
	printf("\033[1;34m\n*******Heap Items Num Test 1:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 5, Number of Insert = 3\n\n");
	
	printf("Create Vector Func Test: ");
	
	vector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vector);
	
	printf("\nExpected: SUCCESS (vector != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 5;++i)
	{
		status = VectorPush(vector, rand() % NUM_LIMIT);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status)\n");
	
	printf("\nBuild Heap Func Test: ");
	
	heap = HeapBuild(vector);
	
	CHECK_FUNC(NULL != heap);
	
	printf("\nExpected: SUCCESS (heap != NULL check)\n");
	
	printf("\nItems Number Func Test 1: ");
	
	numOfItems = HeapItemsNum(heap);
		
	CHECK_FUNC(5 == numOfItems);
	
	printf("\nExpected: 1 SUCCESS (check return value)\n");
	
	printf("\nInsert Heap:\n\n");
	
	for (i = 0;i < 3;++i)
	{
		status = HeapInsert(heap, inputData + i);
	
		printf("Insert number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 3 SUCCESS (check status)\n");
	
	printf("\nItems Number Func Test 2: ");
	
	numOfItems = HeapItemsNum(heap);
		
	CHECK_FUNC(8 == numOfItems);

	printf("\nExpected: 1 SUCCESS (check return value)\n");

	VectorDestroy(vector);
	
	HeapDestroy(heap);
}

void HeapItemsNum2(void)
{
	Vector_t *vector = NULL;
	Heap_t *heap = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int inputData = 10;
	int i, status, numOfItems;
	time_t currentTime;
	
	srand((unsigned)time(&currentTime));
	
	printf("\033[1;34m\n*******Heap Items Num Test 2:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 0, Number of Insert = 3\n\n");
	
	printf("Create Vector Func Test: ");
	
	vector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vector);
	
	printf("\nExpected: SUCCESS (vector != NULL check)\n");
	
	printf("\nBuild Heap Func Test: ");
	
	heap = HeapBuild(vector);
	
	CHECK_FUNC(NULL != heap);
	
	printf("\nExpected: SUCCESS (heap != NULL check)\n");
	
	printf("\nItems Number Func Test 1: ");
	
	numOfItems = HeapItemsNum(heap);
		
	CHECK_FUNC(0 == numOfItems);
	
	printf("\nExpected: 1 SUCCESS (check return value)\n");
	
	printf("\nInsert Heap:\n\n");
	
	for (i = 0;i < 3;++i)
	{
		status = HeapInsert(heap, inputData + i);
	
		printf("Insert number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 3 SUCCESS (check status)\n");
	
	printf("\nItems Number Func Test 2: ");
	
	numOfItems = HeapItemsNum(heap);
		
	CHECK_FUNC(3 == numOfItems);

	printf("\nExpected: 1 SUCCESS (check return value)\n");

	VectorDestroy(vector);
	
	HeapDestroy(heap);
}

void HeapItemsNum3(void)
{
	Heap_t *heap = NULL;
	int numOfItems;
	time_t currentTime;
	
	srand((unsigned)time(&currentTime));
	
	printf("\033[1;34m\n*******Heap Items Num Test 3:*******\n\n\033[0m");
	
	printf("Items Number Func Test: ");
	
	numOfItems = HeapItemsNum(heap);
		
	CHECK_FUNC(0 == numOfItems);
	
	printf("\nExpected: 1 SUCCESS (check return value) - heap is NULL\n");
}
 
void HeapPrintTest1(void)
{
	Vector_t *vector = NULL;
	Heap_t *heap = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int i, status, outputData;
	time_t currentTime;
	
	srand((unsigned)time(&currentTime));
	
	printf("\033[1;34m\n*******Heap Print Test 1:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 5, Number of Extract = 3\n\n");
	
	printf("Create Vector Func Test: ");
	
	vector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vector);
	
	printf("\nExpected: SUCCESS (vector != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 5;++i)
	{
		status = VectorPush(vector, rand() % NUM_LIMIT);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status)\n");
	
	printf("\nBuild Heap Func Test: ");
	
	heap = HeapBuild(vector);
	
	CHECK_FUNC(NULL != heap);
	
	printf("\nExpected: SUCCESS (heap != NULL check)\n");
	
	printf("\nPrint Heap:\n\n");
	
	HeapPrint(heap);
	
	for (i = 0;i < 2;++i)
	{
		status = HeapExtractMax(heap, &outputData);
	
		printf("\nExtract number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
		
		printf("\nThe OutputData is: %d\n\n", outputData);
		
		HeapPrint(heap);
	}
	
	printf("\nExpected: 3 SUCCESS (check status)\n");

	VectorDestroy(vector);
	
	HeapDestroy(heap);
}

void HeapPrintTest2(void)
{
	Heap_t *heap = NULL;
	time_t currentTime;
	
	srand((unsigned)time(&currentTime));
	
	printf("\033[1;34m\n*******Heap Print Test 2:*******\n\n\033[0m");
	
	printf("Print Heap:\n\n");
	
	HeapPrint(heap);
}

int main(void)
{
	HeapBuildTest1(); /* check heap is not null */
	HeapBuildTest2(); /* check heap heapify with heap print */
	HeapBuildTest3(); /* check if heap equal to null (vector is NULL) */
	
	HeapInsertTest1(); /* check heap insert status */
	HeapInsertTest2(); /* check heap insert & bubble up with heap print */
	HeapInsertTest3(); /* check heap insert (heap is null) */
	HeapInsertTest4(); /* check heap insert (capacity is full) */
	HeapInsertTest5(); /* check heap insert - duplicate data */
	
	HeapMaxTest1(); /* check heap max status + value */
	HeapMaxTest2(); /* check heap max equal to NULL */
	HeapMaxTest3(); /* check heap max UNDERFLOW */
	
	HeapExtractMaxTest1(); /* check heap extract status, value and print */
	HeapExtractMaxTest2(); /* check heap extract (heap equal to null) */
	HeapExtractMaxTest3(); /* check heap extract - UNDERFLOW */
	
	HeapItemsNum1(); /* check heap num items return value */
	HeapItemsNum2(); /* check heap num items return value (empty & not empty)*/
	HeapItemsNum3(); /* check heap num items return value (heap is null) */
	
	HeapPrintTest1(); /* check heap prints */
	HeapPrintTest2(); /* check heap print (heap is equal to null) */
	
	return 0;
}
