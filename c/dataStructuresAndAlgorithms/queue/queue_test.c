#include <stdio.h> /* printf */
#include "queue.h" /* queue header */

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

void QueueCreateTest1(void)
{
	Queue_t *queueTest = NULL;
	int capacity = 10;
	
	printf("\033[1;34m\n*******Queue Create Test 1:*******\n\n\033[0m");
	
	printf("capacity = 10\n\n");
	
	printf("Create Func Test: ");

	queueTest = QueueCreate(capacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");
	
	QueueDestroy(queueTest);
}

void QueueCreateTest2(void)
{
	Queue_t *queueTest = NULL;
	int capacity = 0;
	
	printf("\033[1;34m\n*******Queue Create Test 2:*******\n\n\033[0m");
	
	printf("capacity = 0\n\n");
	
	printf("Create Func Test: ");

	queueTest = QueueCreate(capacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");
	
	QueueDestroy(queueTest);
}

void QueueEnqueueTest1(void)
{
	Queue_t *queueTest = NULL;
	int capacity = 5;
	int inputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Queue Enqueue Test 1:*******\n\n\033[0m");
	
	printf("capacity = 5, Number of Enqueue = 5\n\n");
	
	printf("Create Func Test: ");
	
	queueTest = QueueCreate(capacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");
	
	printf("\nEnqueue Func Test:\n\n");
	
	for (i = 0;i < 5;++i)
	{
		status = QueueEnqueue(queueTest, inputData + i);
	
		printf("Enqueue number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status)\n");
	
	QueueDestroy(queueTest);
}

void QueueEnqueueTest2(void)
{
	Queue_t *queueTest = NULL;
	int capacity = 5;
	int inputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Queue Enqueue Test 2:*******\n\n\033[0m");
	
	printf("capacity = 5, Number of Enqueue = 7\n\n");
	
	printf("Create Func Test: ");
	
	queueTest = QueueCreate(capacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");
	
	printf("\nEnqueue Func Test:\n\n");
	
	for (i = 0;i < 7;++i)
	{
		status = QueueEnqueue(queueTest, inputData + i);
	
		printf("Enqueue number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 5 SUCCESS 2 FAILURE (check status)\n");
	
	QueueDestroy(queueTest);
}

void QueueEnqueueTest3(void)
{
	Queue_t *queueTest = NULL;
	int inputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Queue Enqueue Test 3:*******\n\n\033[0m");
	
	printf("capacity = 5, Number of Enqueue = 2\n\n");
	
	printf("Enqueue Func Test:\n\n");
	
	for (i = 0;i < 2;++i)
	{
		status = QueueEnqueue(queueTest, inputData + i);
	
		printf("Enqueue number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 2 FAILURE (check status) - queueTest == NULL \n");
	
	QueueDestroy(queueTest);
}

void QueueDequeueTest1(void)
{
	Queue_t *queueTest = NULL;
	int capacity = 5;
	int inputData = 0;
	int i, j, status, outputData;
	
	printf("\033[1;34m\n*******Queue Dequeue Test 1:*******\n\n\033[0m");
	
	printf("capacity = 5, Number of Enqueue = 5, Number of Dequeue = 5\n\n");
	
	printf("Create Func Test: ");
	
	queueTest = QueueCreate(capacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");
	
	printf("\nEnqueue Func Test:\n\n");
	
	for (i = 0;i < 5;++i)
	{
		status = QueueEnqueue(queueTest, inputData + i);
	
		printf("Enqueue number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status) \n");
	
	printf("\nDequeue Func Test:\n\n");
	
	for (i = 0, j = 1;i < 5;++i, ++j)
	{
		status = QueueDequeue(queueTest, &outputData);
	
		printf("Dequeue number %d check (status): ", j);
		
		CHECK_FUNC(OK == status);
	
		printf("Output data number %d check: ", j);
	
		CHECK_FUNC(i == outputData);
	}
	
	printf("\nExpected: 5 SUCCESS (check status) 5 SUCCESS (check outputData)\n");
	
	QueueDestroy(queueTest);
}

void QueueDequeueTest2(void)
{
	Queue_t *queueTest = NULL;
	int capacity = 5;
	int inputData = 0;
	int i, j, status, outputData;
	
	printf("\033[1;34m\n*******Queue Dequeue Test 2:*******\n\n\033[0m");
	
	printf("capacity = 5, Number of Enqueue = 9, Number of Dequeue = 5\n\n");
	
	printf("Create Func Test: ");
	
	queueTest = QueueCreate(capacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");
	
	printf("\nEnqueue Func Test 1:\n\n");
	
	for (i = 0;i < 5;++i)
	{
		status = QueueEnqueue(queueTest, inputData + i);
	
		printf("Enqueue number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status) \n");
	
	printf("\nDequeue Func Test:\n\n");
	
	for (i = 0, j = 1;i < 5;++i, ++j)
	{
		status = QueueDequeue(queueTest, &outputData);
	
		printf("Dequeue number %d check (status): ", j);
		
		CHECK_FUNC(OK == status);
	
		printf("Output data number %d check: ", j);
	
		CHECK_FUNC(i == outputData);
	}
	
	printf("\nExpected: 5 SUCCESS (check status) 5 SUCCESS (check outputData)\n");
	
	printf("\nEnqueue Func Test 2:\n\n");
	
	for (i = 0;i < 4;++i)
	{
		status = QueueEnqueue(queueTest, inputData + i);
	
		printf("Enqueue number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 4 SUCCESS (check status) \n");
	
	QueueDestroy(queueTest);
}

void QueueDequeueTest3(void)
{
	Queue_t *queueTest = NULL;
	int inputData = 0;
	int i, j, status, outputData;
	
	printf("\033[1;34m\n*******Queue Dequeue Test 3:*******\n\n\033[0m");
	
	printf("capacity = 5, Number of Enqueue = 2, Number of Dequeue = 2\n\n");
	
	printf("\nEnqueue Func Test:\n\n");
	
	for (i = 0;i < 2;++i)
	{
		status = QueueEnqueue(queueTest, inputData + i);
	
		printf("Enqueue number %d check (status): ", i + 1);
		
		CHECK_FUNC(POINTER_NOT_INITIALIZE == status);
	}
	
	printf("\nExpected: 2 SUCCESS (check status) - queueTest == NULL\n");
	
	printf("\nDequeue Func Test:\n\n");
	
	for (i = 0, j = 1;i < 2;++i, ++j)
	{
		status = QueueDequeue(queueTest, &outputData);
	
		printf("Dequeue number %d check (status): ", j);
		
		CHECK_FUNC(POINTER_NOT_INITIALIZE == status);
	}
	
	printf("\nExpected: 2 SUCCESS (check status) - queueTest == NULL\n");
	
	QueueDestroy(queueTest);
}

void QueueDequeueTest4(void)
{
	Queue_t *queueTest = NULL;
	int capacity = 5;
	int i, j, status, outputData;
	
	printf("\033[1;34m\n*******Queue Dequeue Test 4:*******\n\n\033[0m");
	
	printf("capacity = 5, Number of Enqueue = 0, Number of Dequeue = 2\n\n");
	
	printf("Create Func Test: ");
	
	queueTest = QueueCreate(capacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");
	
	printf("\nDequeue Func Test:\n\n");
	
	for (i = 0, j = 1;i < 2;++i, ++j)
	{
		status = QueueDequeue(queueTest, &outputData);
	
		printf("Dequeue number %d check (status): ", j);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 2 FAILURE (check status)\n");
	
	QueueDestroy(queueTest);
}

void QueueIsEmptyTest1(void)
{
	Queue_t *queueTest = NULL;
	int capacity = 5;
	int inputData = 0;
	int i, j, status, outputData, isEmpty;
	
	printf("\033[1;34m\n*******Queue Is Empty Test 1:*******\n\n\033[0m");
	
	printf("capacity = 5, Number of Enqueue = 5, Number of Dequeue = 5\n\n");
	
	printf("Create Func Test: ");
	
	queueTest = QueueCreate(capacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");
	
	printf("\nIs Empty Func Test 1: ");
	
	isEmpty = QueueIsEmpty(queueTest);
	
	CHECK_FUNC(QUEUE_IS_EMPTY == isEmpty);
	
	printf("\nExpected: 1 SUCCESS (check isEmpty)\n");
	
	printf("\nEnqueue Func Test:\n\n");
	
	for (i = 0;i < 5;++i)
	{
		status = QueueEnqueue(queueTest, inputData + i);
	
		printf("Enqueue number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status) \n");
	
	printf("\nIs Empty Func Test 2: ");
	
	isEmpty = QueueIsEmpty(queueTest);
	
	CHECK_FUNC(QUEUE_IS_NOT_EMPTY == isEmpty);
	
	printf("\nExpected: 1 SUCCESS (check isEmpty)\n");
	
	printf("\nDequeue Func Test:\n\n");
	
	for (i = 0, j = 1;i < 5;++i, ++j)
	{
		status = QueueDequeue(queueTest, &outputData);
	
		printf("Dequeue number %d check (status): ", j);
		
		CHECK_FUNC(OK == status);
	
		printf("Output data number %d check: ", j);
	
		CHECK_FUNC(i == outputData);
	}
	
	printf("\nExpected: 5 SUCCESS (check status) 5 SUCCESS (check outputData)\n");
	
	printf("\nIs Empty Func Test 3: ");
	
	isEmpty = QueueIsEmpty(queueTest);
	
	CHECK_FUNC(QUEUE_IS_EMPTY == isEmpty);
	
	printf("\nExpected: 1 SUCCESS (check isEmpty)\n");
	
	QueueDestroy(queueTest);
}

void QueueIsEmptyTest2(void)
{
	Queue_t *queueTest = NULL;
	int isEmpty;
	
	printf("\033[1;34m\n*******Queue Is Empty Test 2:*******\n\n\033[0m");
	
	printf("capacity = 5, Number of Enqueue = 0, Number of Dequeue = 0\n\n");
	
	printf("Is Empty Func Test: ");
	
	isEmpty = QueueIsEmpty(queueTest);
	
	CHECK_FUNC(QUEUE_IS_EMPTY == isEmpty);
	
	printf("\nExpected: 1 SUCCESS (check isEmpty) - queueTest == NULL\n");
	
	QueueDestroy(queueTest);
}

void QueuePrintTest(void)
{
	Queue_t *queueTest = NULL;
	int capacity = 5;
	int inputData = 0;
	int i, j, status, outputData;
	
	printf("\033[1;34m\n*******Queue Print Test:*******\n\n\033[0m");
	
	printf("capacity = 5, Number of Enqueue = 9, Number of Dequeue = 3\n\n");
	
	printf("Create Func Test: ");
	
	queueTest = QueueCreate(capacity);
	
	CHECK_FUNC(NULL != queueTest);
	
	printf("\nExpected: SUCCESS (queueTest != NULL check)\n");
	
	printf("\nPrint Func Test 1:\n");
	
	QueuePrint(queueTest);
	
	printf("\nExpected: m_capacity = 5, m_head = 0, m_tail = 0, m_numOfElements = 0\n");
	
	printf("\nEnqueue Func Test 1:\n\n");
	
	for (i = 0;i < 5;++i)
	{
		status = QueueEnqueue(queueTest, inputData + i);
	
		printf("Enqueue number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status) \n");
	
	printf("\nPrint Func Test 2:\n\n");
	
	QueuePrint(queueTest);
	
	printf("\nExpected: m_capacity = 5, m_head = 3, m_tail = 0, m_numOfElements = 2\n");
	
	printf("\nDequeue Func Test:\n\n");
	
	for (i = 0, j = 1;i < 3;++i, ++j)
	{
		status = QueueDequeue(queueTest, &outputData);
	
		printf("Dequeue number %d check (status): ", j);
		
		CHECK_FUNC(OK == status);
	
		printf("Output data number %d check: ", j);
	
		CHECK_FUNC(i == outputData);
	}
	
	printf("\nExpected: 3 SUCCESS (check status) 3 SUCCESS (check outputData)\n");
	
	printf("\nPrint Func Test 3:\n\n");
	
	QueuePrint(queueTest);
	
	printf("\nExpected: m_capacity = 5, m_head = 0, m_tail = 0, m_numOfElements = 5\n");
	
	printf("\nEnqueue Func Test 2:\n\n");
	
	for (i = 0;i < 2;++i)
	{
		status = QueueEnqueue(queueTest, inputData + i);
	
		printf("Enqueue number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 2 SUCCESS (check status) \n");
	
	printf("\nPrint Func Test 4:\n\n");
	
	QueuePrint(queueTest);
	
	printf("\nExpected: m_capacity = 5, m_head = 3, m_tail = 2, m_numOfElements = 4\n");
	
	for (i = 0;i < 2;++i)
	{
		status = QueueEnqueue(queueTest, inputData + i);
	
		printf("Enqueue number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 1 SUCCESS 1 FAILURE (check status) \n");
	
	printf("\nPrint Func Test 5:\n\n");
	
	QueuePrint(queueTest);
	
	printf("\nExpected: m_capacity = 5, m_head = 3, m_tail = 3, m_numOfElements = 5\n");
	
	QueueDestroy(queueTest);
}

int main(void)
{
	QueueCreateTest1(); /* capacity = 10 */
	
	QueueCreateTest2(); /* capacity = 0 */
	
	QueueEnqueueTest1(); /* capacity = 5, Number of Enqueue = 5 */
	
	QueueEnqueueTest2(); /* capacity = 5, Number of Enqueue = 7 */
	
	QueueEnqueueTest3(); /* capacity = 5, Number of Enqueue = 2 */
	
	QueueDequeueTest1(); /* capacity = 5, Number of Enqueue = 5, Number of Dequeue = 5 */
	
	QueueDequeueTest2(); /* capacity = 5, Number of Enqueue = 9, Number of Dequeue = 5 */
	
	QueueDequeueTest3(); /* capacity = 5, Number of Enqueue = 2, Number of Dequeue = 2 */
	
	QueueDequeueTest4(); /* capacity = 5, Number of Enqueue = 0, Number of Dequeue = 2 */
	
	QueueIsEmptyTest1(); /* capacity = 5, Number of Enqueue = 5, Number of Dequeue = 5 */
	
	QueueIsEmptyTest2(); /* capacity = 5, Number of Enqueue = 0, Number of Dequeue = 0 */
	
	QueuePrintTest(); /* capacity = 5, Number of Enqueue = 9, Number of Dequeue = 5 */
	
	return 0;
}
