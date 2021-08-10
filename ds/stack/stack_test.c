#include <stdio.h> /* printf */
#include "stack.h" /* stack header */

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

void StackCreateTest1(void)
{
	Stack_t *stackTest = NULL;
	int capacity = 10;
	int incBlockSize = 5;
	
	printf("\033[1;34m\n*******Stack Create Test 1:*******\n\n\033[0m");
	
	printf("capacity = 10, incBlockSize = 5\n\n");
	
	printf("Create Func Test: ");

	stackTest = StackCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != stackTest);
	
	printf("\nExpected: SUCCESS (stackTest != NULL check)\n");
	
	StackDestroy(stackTest);
}

void StackCreateTest2(void)
{
	Stack_t *stackTest = NULL;
	int capacity = 10;
	int incBlockSize = 0;
	
	printf("\033[1;34m\n*******Stack Create Test 2:*******\n\n\033[0m");
	
	printf("capacity = 10, incBlockSize = 0\n\n");
	
	printf("Create Func Test: ");

	stackTest = StackCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != stackTest);
	
	printf("\nExpected: SUCCESS (stackTest != NULL check)\n");
	
	StackDestroy(stackTest);
}

void StackCreateTest3(void)
{
	Stack_t *stackTest = NULL;
	int capacity = 0;
	int incBlockSize = 10;
	
	printf("\033[1;34m\n*******Stack Create Test 3:*******\n\n\033[0m");
	
	printf("capacity = 0, incBlockSize = 10\n\n");
	
	printf("Create Func Test: ");

	stackTest = StackCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != stackTest);
	
	printf("\nExpected: SUCCESS (stackTest != NULL check)\n");
	
	StackDestroy(stackTest);
}

void StackCreateTest4(void)
{
	Stack_t *stackTest = NULL;
	int capacity = 0;
	int incBlockSize = 0;
	
	printf("\033[1;34m\n*******Stack Create Test 4:*******\n\n\033[0m");
	
	printf("capacity = 0, incBlockSize = 0\n\n");
	
	printf("Create Func Test: ");

	stackTest = StackCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL == stackTest);
	
	printf("\nExpected: SUCCESS (stackTest == NULL check)\n");
	
	StackDestroy(stackTest);
}

void StackPushTest1(void)
{
	Stack_t *stackTest = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int inputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Stack Push Test 1:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 5\n\n");
	
	printf("Create Func Test: ");
	
	stackTest = StackCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != stackTest);
	
	printf("\nExpected: SUCCESS (stackTest != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 5;++i)
	{
		status = StackPush(stackTest, inputData + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 5 SUCCESS (check status)\n");
	
	StackDestroy(stackTest);
}

void StackPushTest2(void)
{
	Stack_t *stackTest = NULL;
	int capacity = 2;
	int incBlockSize = 2;
	int inputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Stack Push Test 2:*******\n\n\033[0m");
	
	printf("capacity = 2, incBlockSize = 2, Number of Push = 8\n\n");
	
	printf("Create Func Test: ");
	
	stackTest = StackCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != stackTest);
	
	printf("\nExpected: SUCCESS (stackTest != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 8;++i)
	{
		status = StackPush(stackTest, inputData + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 8 SUCCESS (check status)\n");
	
	StackDestroy(stackTest);
}

void StackPushTest3(void)
{
	Stack_t *stackTest = NULL;
	int capacity = 5;
	int incBlockSize = 0;
	int inputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Stack Push Test 3:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 0, Number of Push = 6\n\n");
	
	printf("Create Func Test: ");
	
	stackTest = StackCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != stackTest);
	
	printf("\nExpected: SUCCESS (stackTest != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 6;++i)
	{
		status = StackPush(stackTest, inputData + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 5 SUCCESS 1 FAILURE (check status)\n");
	
	StackDestroy(stackTest);
}

void StackPushTest4(void)
{
	Stack_t *stackTest = NULL;
	int capacity = 0;
	int incBlockSize = 2;
	int inputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Stack Push Test 4:*******\n\n\033[0m");
	
	printf("capacity = 0, incBlockSize = 2, Number of Push = 6\n\n");
	
	printf("Create Func Test: ");
	
	stackTest = StackCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != stackTest);
	
	printf("\nExpected: SUCCESS (stackTest != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 6;++i)
	{
		status = StackPush(stackTest, inputData + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 6 SUCCESS (check status)\n");
	
	StackDestroy(stackTest);
}

void StackPushTest5(void)
{
	Stack_t *stackTest = NULL;
	int inputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Stack Push Test 5:*******\n\n\033[0m");
	
	printf("capacity = 0, incBlockSize = 2, Number of Push = 3\n\n");
	
	printf("Push Func Test:\n\n");
	
	for (i = 0;i < 3;++i)
	{
		status = StackPush(stackTest, inputData + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 3 SUCCESS (check status) - stackTest == NULL\n");
	
	StackDestroy(stackTest);
}

void StackPopTest1(void)
{
	Stack_t *stackTest = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int inputData = 0;
	int i, j, status, outputData;
	
	printf("\033[1;34m\n*******Stack Pop Test 1:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 4, Number of Pop = 3\n\n");
	
	printf("Create Func Test: ");
	
	stackTest = StackCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != stackTest);
	
	printf("\nExpected: SUCCESS (stackTest != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 4;++i)
	{
		status = StackPush(stackTest, inputData + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 4 SUCCESS (check status)\n");
	
	printf("\nPop Func Test:\n\n");
	
	for (i = 3, j = 1;0 <= i;--i, ++j)
	{
		status = StackPop(stackTest, &outputData);
	
		printf("Pop number %d check (status): ", j);
		
		CHECK_FUNC(OK == status);
	
		printf("Output data number %d check: ", j);
	
		CHECK_FUNC(i == outputData);
	}
	
	printf("\nExpected: 3 SUCCESS (check status) 3 SUCCESS (check outputData)\n");
	
	StackDestroy(stackTest);
}

void StackPopTest2(void)
{
	Stack_t *stackTest = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int inputData = 0;
	int i, j, k, status, outputData;
	
	printf("\033[1;34m\n*******Stack Pop Test 2:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 4, Number of Pop = 5\n\n");
	
	printf("Create Func Test: ");
	
	stackTest = StackCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != stackTest);
	
	printf("\nExpected: SUCCESS (stackTest != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 4;++i)
	{
		status = StackPush(stackTest, inputData + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 4 SUCCESS (check status)\n");
	
	printf("\nPop Func Test:\n\n");
	
	for (i = 0, j = 1, k = 3;i < 5;++i, ++j, --k)
	{
		status = StackPop(stackTest, &outputData);
	
		printf("Pop number %d check (status): ", j);
		
		CHECK_FUNC(OK == status);
	
		printf("Output data number %d check: ", j);
	
		CHECK_FUNC(k == outputData);
	}
	
	printf("\nExpected: 4 SUCCESS 1 FAILURE (check status) 4 SUCCESS 1 FAILURE (check outputData)\n");
	
	StackDestroy(stackTest);
}

void StackPopTest3(void)
{
	Stack_t *stackTest = NULL;
	int inputData = 0;
	int i, j, status, outputData;
	
	printf("\033[1;34m\n*******Stack Pop Test 3:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 4, Number of Pop = 5\n\n");
	
	printf("Push Func Test:\n\n");
	
	for (i = 0;i < 4;++i)
	{
		status = StackPush(stackTest, inputData + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 4 FAILURE (check status) - stackTest == NULL\n");
	
	printf("\nPop Func Test:\n\n");
	
	for (i = 0, j = 1;i < 5;++i, ++j)
	{
		status = StackPop(stackTest, &outputData);
	
		printf("Pop number %d check (status): ", j);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 5 FAILURE (check status) - stackTest == NULL\n");
	
	StackDestroy(stackTest);
}

void StackPopTest4(void)
{
	Stack_t *stackTest = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int i, j, status, outputData;
	
	printf("\033[1;34m\n*******Stack Pop Test 4:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 0, Number of Pop = 2\n\n");
	
	printf("Create Func Test: ");
	
	stackTest = StackCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != stackTest);
	
	printf("\nExpected: SUCCESS (stackTest != NULL check)\n");
	
	printf("\nPop Func Test:\n\n");
	
	for (i = 0, j = 1;i < 2;++i, ++j)
	{
		status = StackPop(stackTest, &outputData);
	
		printf("Pop number %d check (status): ", j);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 2 FAILURE (check status)\n");
	
	StackDestroy(stackTest);
}

void StackPeekTest1(void)
{
	Stack_t *stackTest = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int inputData = 0;
	int i, status, outputData;
	
	printf("\033[1;34m\n*******Stack Peek Test 1:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 5\n\n");
	
	printf("Create Func Test: ");
	
	stackTest = StackCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != stackTest);
	
	printf("\nExpected: SUCCESS (stackTest != NULL check)\n");
	
	printf("\nPush & Peek Func Test:\n\n");
	
	for (i = 0;i < 5;++i)
	{
		status = StackPush(stackTest, inputData + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
		
		status = StackPeek(stackTest, &outputData);
		
		printf("Peek number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
		
		printf("Peek number %d check (outputData): ", i + 1);
		
		CHECK_FUNC(i == outputData);
	}
	
	printf("\nExpected: 5 SUCCESS (push check status), 5 SUCCESS (peek check status), 5 SUCCESS (peek check outputData)\n");
	
	StackDestroy(stackTest);
}

void StackPeekTest2(void)
{
	Stack_t *stackTest = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int status, outputData;
	
	printf("\033[1;34m\n*******Stack Peek Test 2:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 0\n\n");
	
	printf("Create Func Test: ");
	
	stackTest = StackCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != stackTest);
	
	printf("\nExpected: SUCCESS (stackTest != NULL check)\n");
	
	printf("\nPeek Func Test:\n\n");
		
	status = StackPeek(stackTest, &outputData);
		
	printf("Peek number 1 check (status): ");
		
	CHECK_FUNC(UNDERFLOW == status);
	
	printf("\nExpected: 1 SUCCESS (peek check status)\n");
	
	StackDestroy(stackTest);
}

void StackPeekTest3(void)
{
	Stack_t *stackTest = NULL;
	int status, outputData;
	
	printf("\033[1;34m\n*******Stack Peek Test 3:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 0\n\n");
	
	printf("Peek Func Test:\n\n");
		
	status = StackPeek(stackTest, &outputData);
		
	printf("Peek number 1 check (status): ");
		
	CHECK_FUNC(POINTER_NOT_INITIALIZE == status);
	
	printf("\nExpected: 1 SUCCESS (peek check status) - stackTest == NULL\n");
	
	StackDestroy(stackTest);
}

void StackPeekTest4(void)
{
	Stack_t *stackTest = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int status, outputData;
	
	printf("\033[1;34m\n*******Stack Peek Test 4:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 2, Number of Pop = 1\n\n");
	
	printf("Create Func Test: ");
	
	stackTest = StackCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != stackTest);
	
	printf("\nExpected: SUCCESS (stackTest != NULL check)\n");
	
	printf("\nPush & Peek & Pop Func Test:\n\n");
	
	status = StackPush(stackTest, 7);
	
	printf("Push number 1 check (status): ");
		
	CHECK_FUNC(OK == status);
		
	status = StackPeek(stackTest, &outputData);

	printf("Peek number 1 check (status): ");
		
	CHECK_FUNC(OK == status);
		
	printf("Peek number 1 check (outputData): ");
		
	CHECK_FUNC(7 == outputData);
	
	status = StackPop(stackTest, &outputData);
	
	printf("Pop number 1 check (status): ");
		
	CHECK_FUNC(OK == status);

	status = StackPush(stackTest, 152);
	
	printf("Push number 2 check (status): ");
		
	CHECK_FUNC(OK == status);

	status = StackPeek(stackTest, &outputData);
		
	printf("Peek number 2 check (status): ");
		
	CHECK_FUNC(OK == status);
		
	printf("Peek number 2 check (outputData): ");
		
	CHECK_FUNC(152 == outputData);
	
	status = StackPop(stackTest, &outputData);
	
	printf("\nExpected: 2 SUCCESS (push check status), 1 SUCCESS (pop check status), 2 SUCCESS (peek check status), 2 SUCCESS (peek check outputData)\n");
	
	StackDestroy(stackTest);
}

void StackIsEmptyTest1(void)
{
	Stack_t *stackTest = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int status, isEmpty;
	
	printf("\033[1;34m\n*******Stack Is Empty Test 1:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 1\n\n");
	
	printf("Create Func Test: ");
	
	stackTest = StackCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != stackTest);
	
	printf("\nExpected: SUCCESS (stackTest != NULL check)\n");
	
	printf("\nIs Empty Func Test 1: ");
	
	isEmpty = StackIsEmpty(stackTest);
		
	CHECK_FUNC(STACK_IS_EMPTY == isEmpty);
	
	printf("\nExpected: 1 SUCCESS (is empty check return value)\n");
	
	printf("\nPush Func Test:\n\n");
	
	status = StackPush(stackTest, 172);
	
	printf("Push number 1 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 1 SUCCESS (push check status)\n");
	
	printf("\nIs Empty Func Test 2: ");
	
	isEmpty = StackIsEmpty(stackTest);
		
	CHECK_FUNC(STACK_IS_NOT_EMPTY == isEmpty);
	
	printf("\nExpected: 1 SUCCESS (is empty check return value)\n");
	
	StackDestroy(stackTest);
}

void StackIsEmptyTest2(void)
{
	Stack_t *stackTest = NULL;
	int isEmpty;
	
	printf("\033[1;34m\n*******Stack Is Empty Test 2:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2\n\n");
	
	printf("Is Empty Func Test 1: ");
	
	isEmpty = StackIsEmpty(stackTest);
		
	CHECK_FUNC(STACK_IS_EMPTY == isEmpty);
	
	printf("\nExpected: 1 SUCCESS (is empty check return value) - NULL == stackTest\n");
	
	StackDestroy(stackTest);
}

void StackPrintTest(void)
{
	Stack_t *stackTest = NULL;
	int capacity = 2;
	int incBlockSize = 2;
	int inputDataPush = 0;
	int i, status, outputData;
	
	printf("\033[1;34m\n*******Stack Print Test:*******\n\n\033[0m");
	
	printf("capacity = 2, incBlockSize = 2, Number of Push = 7, Number of Pop = 6\n\n");
	
	printf("Create Func Test: ");
	
	stackTest = StackCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != stackTest);
	
	printf("\nExpected: SUCCESS (stackTest != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 7;++i)
	{
		status = StackPush(stackTest, inputDataPush + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 7 SUCCESS (push check status)\n");
	
	printf("\nStack Print Func Test:\n\n");
	
	StackPrint(stackTest);
	
	printf("\nExpected: arrayCapacity = 8, arrayOriginalCapacity = 2, incBlockSize = 2, arrayCapacityAfter1Increase = 4, arrayCapacityAfter2Increase = 6, numOfElements = 7)\n");
	
	printf("\nPop Func Test:\n\n");
	
	for (i = 0;i < 6;++i)
	{
		status = StackPop(stackTest, &outputData);
	
		printf("Pop number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 6 SUCCESS (check status)\n\n");
	
	StackPrint(stackTest);
	
	printf("\nExpected: arrayCapacity = 4, arrayOriginalCapacity = 2, incBlockSize = 2, arrayCapacityAfter1Increase = 4, arrayCapacityAfter2Increase = 6, numOfElements = 1)\n");
	
	StackDestroy(stackTest);
}

int main(void)
{
	StackCreateTest1(); /* capacity = 10, incBlockSize = 5 */
	StackCreateTest2(); /* capacity = 10, incBlockSize = 0 */
	StackCreateTest3(); /* capacity = 0, incBlockSize = 10 */
	StackCreateTest4(); /* capacity = 0, incBlockSize = 0 */
	
	StackPushTest1(); /* capacity = 5, incBlockSize = 2, Number of Push = 5 */
	StackPushTest2(); /* capacity = 2, incBlockSize = 2, Number of Push = 8 */
	StackPushTest3(); /* capacity = 5, incBlockSize = 0, Number of Push = 6 */
	StackPushTest4(); /* capacity = 0, incBlockSize = 2, Number of Push = 6 */
	StackPushTest5(); /* capacity = 0, incBlockSize = 2, Number of Push = 3 */
	
	StackPopTest1(); /* capacity = 5, incBlockSize = 2, Number of Push = 4, Number of Pop = 3 */
	StackPopTest2(); /* capacity = 5, incBlockSize = 2, Number of Push = 4, Number of Pop = 5 */
	StackPopTest3(); /* capacity = 5, incBlockSize = 2, Number of Push = 4, Number of Pop = 5 */
	StackPopTest4(); /* capacity = 5, incBlockSize = 2, Number of Push = 0, Number of Pop = 2 */
	
	StackPeekTest1(); /* capacity = 5, incBlockSize = 2, Number of Push = 5 */
	StackPeekTest2(); /* capacity = 5, incBlockSize = 2, Number of Push = 0 */
	StackPeekTest3(); /* capacity = 5, incBlockSize = 2, Number of Push = 0 */
	StackPeekTest4(); /* capacity = 5, incBlockSize = 2, Number of Push = 2, Number of Pop = 1 */
	
	StackIsEmptyTest1(); /* capacity = 5, incBlockSize = 2, Number of Push = 1 */
	StackIsEmptyTest2(); /* capacity = 5, incBlockSize = 2 */
	
	StackPrintTest(); /* arrayCapacity = 2, incBlockSize = 2, Number of Push = 7, Number of Pop = 6 */

	return 0;
}
