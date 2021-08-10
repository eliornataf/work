#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc, free */
#include "genericQueue.h" /* Generic queue header */

#define ARR_SIZE (100)
#define RUN_FOR_EACH_NEXT_ITER (1)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

/********************************************************/

static void FreeQueueElement(void *_item)
{
	free(_item);
}

static int PrintQueueElements(const void *_element, size_t _index, void *_context)
{
	(void)_context;

	printf("Vector index %ld is %d\n", _index, *(int*)_element);

	return RUN_FOR_EACH_NEXT_ITER;
}

/********************************************************/

void QueueCreateTest(void)
{
	Queue_t *queueTest = NULL;
	size_t initialCapacity = 10;
	
	printf("\033[1;34m\n*******Queue Create Test:*******\n\n\033[0m");
	
	printf("initialCapacity = 10\n\n");
	
	printf("Create Func Test: ");

	queueTest = QueueCreate(initialCapacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");
	
	QueueDestroy(&queueTest, NULL);
}

void QueueDestroyTest(void)
{
	Queue_t *queueTest = NULL;
	size_t initialCapacity = 10;
	int *item1, *item2, *item3;
    int status;

	item1 = (int*)malloc(sizeof(int));
	item2 = (int*)malloc(sizeof(int));
	item3 = (int*)malloc(sizeof(int));

	if (NULL == item1 || NULL == item2 || NULL == item3)
	{
		return;
	}

	printf("\033[1;34m\n*******Vector Destroy Test:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, number of insert = 3\n\n");
	
    printf("Create Func Test: ");

	queueTest = QueueCreate(initialCapacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");

    printf("\nInsert Func Test:\n\n");

	status = QueueInsert(queueTest, item1);

	printf("Insert number 1 check (status): ");
		
	CHECK_FUNC(QUEUE_SUCCESS == status);

	status = QueueInsert(queueTest, item2);

	printf("Insert number 2check (status): ");
		
	CHECK_FUNC(QUEUE_SUCCESS == status);

	status = QueueInsert(queueTest, item3);

	printf("Insert number 3 check (status): ");
		
	CHECK_FUNC(QUEUE_SUCCESS == status);

	printf("\nExpected: 3 SUCCESS (status check)\n");
	
	QueueDestroy(&queueTest, FreeQueueElement);
}

void QueueInsertTest1(void)
{
    Queue_t *queueTest = NULL;
    size_t initialCapacity = 10;
    int arr[ARR_SIZE];
    int status, i;

    printf("\033[1;34m\n*******Queue Insert Test 1:*******\n\n\033[0m");

    printf("initialCapacity = 10, number of insert = 5\n\n");
	
    printf("Create Func Test: ");

	queueTest = QueueCreate(initialCapacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 5;++i)
	{
        arr[i] = i;

	    status = QueueInsert(queueTest, &arr[i]);
	
		printf("Insert number %d check (status): ", i + 1);
		
	    CHECK_FUNC(QUEUE_SUCCESS == status);
	}

    printf("\nExpected: 5 SUCCESS (status check)\n");
	
	QueueDestroy(&queueTest, NULL);
}

void QueueInsertTest2(void)
{
    Queue_t *queueTest = NULL;
    size_t initialCapacity = 10;
    int arr[ARR_SIZE];
    int status, i;

    printf("\033[1;34m\n*******Queue Insert Test 2:*******\n\n\033[0m");

    printf("initialCapacity = 10, number of insert = 13\n\n");
	
    printf("Create Func Test: ");

	queueTest = QueueCreate(initialCapacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 13;++i)
	{
        arr[i] = i;

	    status = QueueInsert(queueTest, &arr[i]);
	
		printf("Insert number %d check (status): ", i + 1);
		
	    CHECK_FUNC(QUEUE_SUCCESS == status);
	}

    printf("\nExpected: 10 SUCCESS 3 FAILURE (status check) - overflow\n");
	
	QueueDestroy(&queueTest, NULL);
}

void QueueInsertTest3(void)
{
    Queue_t *queueTest = NULL;
    int arr[ARR_SIZE];
    int status, i;

    printf("\033[1;34m\n*******Queue Insert Test 3:*******\n\n\033[0m");

    printf("number of insert = 3\n\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 3;++i)
	{
        arr[i] = i;

	    status = QueueInsert(queueTest, &arr[i]);
	
		printf("Insert number %d check (status): ", i + 1);
		
	    CHECK_FUNC(QUEUE_POINTER_NOT_INITIALIZED == status);
	}

    printf("\nExpected: 5 SUCCESS (status check) - queueTest is NULL\n");
	
	QueueDestroy(&queueTest, NULL);
}

void QueueInsertTest4(void)
{
    Queue_t *queueTest = NULL;
    size_t initialCapacity = 10;
    int *element = NULL;
    int status, i;

    printf("\033[1;34m\n*******Queue Insert Test 4:*******\n\n\033[0m");

    printf("initialCapacity = 10, number of insert = 2\n\n");
	
    printf("Create Func Test: ");

	queueTest = QueueCreate(initialCapacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 2;++i)
	{
	    status = QueueInsert(queueTest, element);
	
		printf("Insert number %d check (status): ", i + 1);
		
	    CHECK_FUNC(QUEUE_POINTER_NOT_INITIALIZED == status);
	}

    printf("\nExpected: 2 SUCCESS (status check) - element is NULL\n");
	
	QueueDestroy(&queueTest, NULL);
}

void QueueRemoveTest1(void)
{
    Queue_t *queueTest = NULL;
    void *element = NULL;
    size_t initialCapacity = 10;
    int arr[ARR_SIZE];
    int status, i;

    printf("\033[1;34m\n*******Queue Remove Test 1:*******\n\n\033[0m");

    printf("initialCapacity = 10, number of insert = 5, number of remove = 5\n\n");
	
    printf("Create Func Test: ");

	queueTest = QueueCreate(initialCapacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 5;++i)
	{
        arr[i] = i;

	    status = QueueInsert(queueTest, &arr[i]);
	
		printf("Insert number %d check (status): ", i + 1);
		
	    CHECK_FUNC(QUEUE_SUCCESS == status);
	}

    printf("\nExpected: 5 SUCCESS (status check)\n");

    printf("\nRemove Func Test:\n\n");

	for (i = 0;i < 5;++i)
	{
		status = QueueRemove(queueTest, &element);
	
		printf("Remove number %d check (status): ", i + 1);
		
		CHECK_FUNC(QUEUE_SUCCESS == status);
	
		printf("element data number %d check: ", i + 1);
	
		CHECK_FUNC(i == *(int*)element);
	}

	printf("\nExpected: 5 SUCCESS (status check) &&  5 SUCCESS (remove number check)\n");
	
	QueueDestroy(&queueTest, NULL);
}

void QueueRemoveTest2(void)
{
    Queue_t *queueTest = NULL;
    void *element = NULL;
    size_t initialCapacity = 10;
    int arr[ARR_SIZE];
    int status, i;

    printf("\033[1;34m\n*******Queue Remove Test 2:*******\n\n\033[0m");

    printf("initialCapacity = 10, number of insert = 5, number of remove = 6\n\n");
	
    printf("Create Func Test: ");

	queueTest = QueueCreate(initialCapacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 5;++i)
	{
        arr[i] = i;

	    status = QueueInsert(queueTest, &arr[i]);
	
		printf("Insert number %d check (status): ", i + 1);
		
	    CHECK_FUNC(QUEUE_SUCCESS == status);
	}

    printf("\nExpected: 5 SUCCESS (status check)\n");

    printf("\nRemove Func Test:\n\n");

	for (i = 0;i < 6;++i)
	{
		status = QueueRemove(queueTest, &element);
	
		printf("Remove number %d check (status): ", i + 1);
		
		CHECK_FUNC(QUEUE_SUCCESS == status);
	
		printf("element data number %d check: ", i + 1);
	
		CHECK_FUNC(i == *(int*)element);
	}

	printf("\nExpected: 5 SUCCESS 1 FAILURE (status check) &&  5 SUCCESS 1 FAILURE (remove number check) - underflow\n");
	
	QueueDestroy(&queueTest, NULL);
}

void QueueRemoveTest3(void)
{
    Queue_t *queueTest = NULL;
    void *element = NULL;
    int status, i;

    printf("\033[1;34m\n*******Queue Remove Test 3:*******\n\n\033[0m");

    printf("number of remove = 2\n\n");

    printf("Remove Func Test:\n\n");

	for (i = 0;i < 2;++i)
	{
		status = QueueRemove(queueTest, &element);
	
		printf("Remove number %d check (status): ", i + 1);
		
		CHECK_FUNC(QUEUE_POINTER_NOT_INITIALIZED == status);
	}

	printf("\nExpected: 2 SUCCESS (status check) - queueTest is NULL\n");
	
	QueueDestroy(&queueTest, NULL);
}

void QueueIsEmptyTest1(void)
{
    Queue_t *queueTest = NULL;
    void *element = NULL;
    size_t initialCapacity = 10;
    int arr[ARR_SIZE];
    int status, i;

    printf("\033[1;34m\n*******Queue Is Empty Test 1:*******\n\n\033[0m");

    printf("initialCapacity = 10, number of insert = 5, number of remove = 5, number of is empty = 3\n\n");
	
    printf("Create Func Test: ");

	queueTest = QueueCreate(initialCapacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");

    printf("\nIs Empty Func Test 1: ");

	CHECK_FUNC(IS_EMPTY == QueueIsEmpty(queueTest));

    printf("\nExpected: 1 SUCCESS (is empty status check)\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 5;++i)
	{
        arr[i] = i;

	    status = QueueInsert(queueTest, &arr[i]);
	
		printf("Insert number %d check (status): ", i + 1);
		
	    CHECK_FUNC(QUEUE_SUCCESS == status);
	}

    printf("\nExpected: 5 SUCCESS (status check)\n");

    printf("\nIs Empty Func Test 2: ");

	CHECK_FUNC(IS_NOT_EMPTY == QueueIsEmpty(queueTest));

    printf("\nExpected: 1 SUCCESS (is empty status check)\n");

    printf("\nRemove Func Test:\n\n");

	for (i = 0;i < 5;++i)
	{
		status = QueueRemove(queueTest, &element);
	
		printf("Remove number %d check (status): ", i + 1);
		
		CHECK_FUNC(QUEUE_SUCCESS == status);
	
		printf("element data number %d check: ", i + 1);
	
		CHECK_FUNC(i == *(int*)element);
	}

	printf("\nExpected: 5 SUCCESS (status check) &&  5 SUCCESS (remove number check)\n");
	
    printf("\nIs Empty Func Test 3: ");

	CHECK_FUNC(IS_EMPTY == QueueIsEmpty(queueTest));

    printf("\nExpected: 1 SUCCESS (is empty status check)\n");

	QueueDestroy(&queueTest, NULL);
}

void QueueIsEmptyTest2(void)
{
    Queue_t *queueTest = NULL;

    printf("\033[1;34m\n*******Queue Is Empty Test 2:*******\n\n\033[0m");

    printf("number of is empty = 1\n\n");

    printf("Is Empty Func Test 1: ");

	CHECK_FUNC(POINTER_NOT_INITIALIZE_QUEUE_IS_EMPTY == QueueIsEmpty(queueTest));

	printf("\nExpected: 1 SUCCESS (is empty status check) - queueTest is NULL\n");
	
	QueueDestroy(&queueTest, NULL);
}

void QueueForEachTest1(void)
{
    Queue_t *queueTest = NULL;
    void *element = NULL;
    size_t initialCapacity = 10;
    int arr[ARR_SIZE];
    int status, i, j;

    printf("\033[1;34m\n*******Queue For Each Test 1:*******\n\n\033[0m");

    printf("initialCapacity = 10, number of insert = 5, number of remove = 5, number of for each = 4\n\n");
	
    printf("Create Func Test: ");

	queueTest = QueueCreate(initialCapacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");

    printf("\nFor Each Func Test:\n");

    status = QueueForEach(queueTest, PrintQueueElements, NULL);

    printf("\nFor Each Func Test: ");

    CHECK_FUNC(UNDERFLOW_QUEUE_FOR_EACH == status);

    printf("\nExpected: 1 SUCCESS (for each check) - underflow\n");

    printf("\nInsert Func Test:\n\n");

    for (i = 0;i < 5;++i)
	{
        arr[i] = i;

	    status = QueueInsert(queueTest, &arr[i]);
	
		printf("Insert number %d check (status): ", i + 1);
		
	    CHECK_FUNC(QUEUE_SUCCESS == status);
	}

    printf("\nExpected: 5 SUCCESS (status check)\n\n");

    status = QueueForEach(queueTest, PrintQueueElements, NULL);

    printf("\nFor Each Func Test: ");

    CHECK_FUNC(5 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

    printf("\nRemove Func Test:\n\n");

	for (j = 0;j < 2;++j)
	{
		status = QueueRemove(queueTest, &element);
	
		printf("Remove number %d check (status): ", j + 1);
		
		CHECK_FUNC(QUEUE_SUCCESS == status);
	
		printf("element data number %d check: ", j + 1);
	
		CHECK_FUNC(j == *(int*)element);
	}

	printf("\nExpected: 5 SUCCESS (status check) &&  5 SUCCESS (remove number check)\n\n");
	
    status = QueueForEach(queueTest, PrintQueueElements, NULL);

    printf("\nFor Each Func Test: ");

    CHECK_FUNC(3 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

    printf("\nInsert Func Test:\n\n");

    for (;i < 8;++i)
	{
        arr[i] = i;

	    status = QueueInsert(queueTest, &arr[i]);
	
		printf("Insert number %d check (status): ", i + 1);
		
	    CHECK_FUNC(QUEUE_SUCCESS == status);
	}

    printf("\nExpected: 3 SUCCESS (status check)\n\n");

    status = QueueForEach(queueTest, PrintQueueElements, NULL);

    printf("\nFor Each Func Test: ");

    CHECK_FUNC(6 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");

	QueueDestroy(&queueTest, NULL);
}

void QueueForEachTest2(void)
{
    Queue_t *queueTest = NULL;
    size_t initialCapacity = 10;
    int arr[ARR_SIZE];
    int status, i;

    printf("\033[1;34m\n*******Queue For Each Test 2:*******\n\n\033[0m");

    printf("initialCapacity = 10, number of insert = 5, number of for each = 1\n\n");
	
    printf("Create Func Test: ");

	queueTest = QueueCreate(initialCapacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");

    for (i = 0;i < 5;++i)
	{
        arr[i] = i;

	    status = QueueInsert(queueTest, &arr[i]);
	
		printf("Insert number %d check (status): ", i + 1);
		
	    CHECK_FUNC(QUEUE_SUCCESS == status);
	}

    printf("\nExpected: 5 SUCCESS (status check)\n\n");

    status = QueueForEach(queueTest, NULL, NULL);

    printf("For Each Func Test: ");

    CHECK_FUNC(POINTER_NOT_INITIALIZE_QUEUE_FOR_EACH == status);

    printf("\nExpected: 1 SUCCESS (for each check) - actionFunc is NULL\n");

	QueueDestroy(&queueTest, NULL);
}

void QueueForEachTest3(void)
{
    Queue_t *queueTest = NULL;
    int status;

    printf("\033[1;34m\n*******Queue For Each Test 3:*******\n\n\033[0m");

    printf("number of for each = 1\n\n");

    status = QueueForEach(queueTest, PrintQueueElements, NULL);

    printf("For Each Func Test: ");

    CHECK_FUNC(POINTER_NOT_INITIALIZE_QUEUE_FOR_EACH == status);

    printf("\nExpected: 1 SUCCESS (for each check) - queueTest is NULL\n");

	QueueDestroy(&queueTest, NULL);
}

int main(void)
{
    QueueCreateTest();

    QueueDestroyTest();

    QueueInsertTest1();
    QueueInsertTest2();
    QueueInsertTest3();
    QueueInsertTest4();

    QueueRemoveTest1();
    QueueRemoveTest2();
    QueueRemoveTest3();

    QueueIsEmptyTest1();
    QueueIsEmptyTest2();

    QueueForEachTest1();
    QueueForEachTest2();
    QueueForEachTest3();

    return 0;
}