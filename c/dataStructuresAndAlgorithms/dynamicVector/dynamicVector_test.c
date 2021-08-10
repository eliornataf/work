#include <stdio.h> /* printf */
#include "dynamicVector.h" /* Dynamic Vector header */

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

void VectorCreateTest1(void)
{
	Vector_t *vectorTest = NULL;
	int capacity = 10;
	int incBlockSize = 5;
	
	printf("\033[1;34m\n*******Vector Create Test 1:*******\n\n\033[0m");
	
	printf("capacity = 10, incBlockSize = 5\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
	VectorDestroy(vectorTest);
}

void VectorCreateTest2(void)
{
	Vector_t *vectorTest = NULL;
	int capacity = 0;
	int incBlockSize = 0;
	
	printf("\033[1;34m\n*******Vector Create Test 2:*******\n\n\033[0m");
	
	printf("capacity = 0, incBlockSize = 0\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL == vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest == NULL check)\n");
	
	VectorDestroy(vectorTest);
}

void VectorPushTest1(void)
{
	Vector_t *vectorTest = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int inputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Vector Push Test 1:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 10\n\n");
	
	printf("Create Func Test: ");
	
	vectorTest = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 10;++i)
	{
		status = VectorPush(vectorTest, inputData + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 10 SUCCESS (check status)\n");
	
	VectorDestroy(vectorTest);
}

void VectorPushTest2(void)
{
	Vector_t *vectorTest = NULL;
	int capacity = 5;
	int incBlockSize = 0;
	int inputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Vector Push Test 2:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 0, Number of Push = 8\n\n");
	
	printf("Create Func Test: ");
	
	vectorTest = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 8;++i)
	{
		status = VectorPush(vectorTest, inputData + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 5 SUCCESS, 3 FAILURE (check status)\n");
	
	VectorDestroy(vectorTest);
}

void VectorPopTest1(void)
{
	Vector_t *vectorTest = NULL;
	int capacity = 5;
	int incBlockSize = 0;
	int inputData = 0;
	int i, j, status, outputData;
	
	printf("\033[1;34m\n*******Vector Pop Test 1:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 0, Number of Push = 4, Number of Pop = 3\n\n");
	
	printf("Create Func Test: ");
	
	vectorTest = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 4;++i)
	{
		status = VectorPush(vectorTest, inputData + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 4 SUCCESS (check status)\n");
	
	printf("\nPop Func Test:\n\n");
	
	for (i = 3, j = 1;0 <= i;--i, ++j)
	{
		status = VectorPop(vectorTest, &outputData);
	
		printf("Pop number %d check (status): ", j);
		
		CHECK_FUNC(OK == status);
	
		printf("Output data number %d check: ", j);
	
		CHECK_FUNC(i == outputData);
	}
	
	printf("\nExpected: 3 SUCCESS (check status) 3 SUCCESS (check outputData)\n");
	
	VectorDestroy(vectorTest);
}

void VectorPopTest2(void)
{
	Vector_t *vectorTest = NULL;
	int capacity = 5;
	int incBlockSize = 0;
	int inputData = 0;
	int i, j, k, status, outputData;
	
	printf("\033[1;34m\n*******Vector Pop Test 2:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 0, Number of Push = 4, Number of Pop = 5\n\n");
	
	printf("Create Func Test: ");
	
	vectorTest = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 4;++i)
	{
		status = VectorPush(vectorTest, inputData + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 4 SUCCESS (check status)\n");
	
	printf("\nPop Func Test:\n\n");
	
	for (i = 0, j = 1, k = 3;i < 5;++i, ++j, --k)
	{
		status = VectorPop(vectorTest, &outputData);
	
		printf("Pop number %d check (status): ", j);
		
		CHECK_FUNC(OK == status);
	
		printf("Output data number %d check: ", j);
	
		CHECK_FUNC(k == outputData);
	}
	
	printf("\nExpected: 4 SUCCESS 1 FAILURE (check status) 4 SUCCESS 1 FAILURE (check outputData)\n");
	
	VectorDestroy(vectorTest);
}

void VectorGetElementTest1(void)
{
	Vector_t *vectorTest = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int inputData = 0;
	int i, status, outputData;
	
	printf("\033[1;34m\n*******Vector Get Element Test 1:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 8\n\n");
	
	printf("Create Func Test: ");
	
	vectorTest = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
	printf("\nPush & Get Element Func Test:\n\n");
	
	for (i = 0;i < 8;++i)
	{
		status = VectorPush(vectorTest, inputData + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
		
		status = VectorGetElement(vectorTest, i, &outputData);
		
		printf("Get Element number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
		
		printf("Get Element number %d check (outputData): ", i + 1);
		
		CHECK_FUNC(i == outputData);
	}
	
	printf("\nExpected: 8 SUCCESS (push check status),  8 SUCCESS (get element check status), 8 SUCCESS (get element check outputData)\n");
	
	VectorDestroy(vectorTest);
}

void VectorGetElementTest2(void)
{
	Vector_t *vectorTest = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int inputData = 0;
	int i, status, outputData;
	
	printf("\033[1;34m\n*******Vector Get Element Test 2:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 3\n\n");
	
	printf("Create Func Test: ");
	
	vectorTest = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 3;++i)
	{
		status = VectorPush(vectorTest, inputData + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 3 SUCCESS (check status)\n");
	
	printf("\nGet Element Func Test:\n\n");
	
	status = VectorGetElement(vectorTest, 5, &outputData);
	
	printf("Get Element number 1 check (status): ");
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 1 FAILURE (check status, wrong index)\n");
	
	VectorDestroy(vectorTest);
}

void VectorSetElementTest1(void)
{
	Vector_t *vectorTest = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int inputDataPush = 0;
	int inputDataSetElement = 1;
	int i, status, outputData;
	
	printf("\033[1;34m\n*******Vector Set Element Test 1:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 6\n\n");
	
	printf("Create Func Test: ");
	
	vectorTest = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
	printf("\nPush & Set & Get Element Func Test:\n\n");
	
	for (i = 0;i < 6;++i)
	{
		status = VectorPush(vectorTest, inputDataPush + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
		
		status = VectorSetElement(vectorTest, i, inputDataSetElement);
		
		printf("Set Element number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
		
		printf("Set & Get Element number %d check (inputDataSetElement): ", i + 1);
		
		VectorGetElement(vectorTest, i, &outputData);
		
		CHECK_FUNC(inputDataSetElement == outputData);
		
		++inputDataSetElement;
	}
	
	printf("\nExpected: 6 SUCCESS (push check status), 6 SUCCESS (set element check status), 6 SUCCESS (set element check inputDataSetElement)\n");
	
	VectorDestroy(vectorTest);
}

void VectorSetElementTest2(void)
{
	Vector_t *vectorTest = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int inputDataPush = 0;
	int inputDataSetElement = 1;
	int i, status;
	
	printf("\033[1;34m\n*******Vector Set Element Test 2:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 6\n\n");
	
	printf("Create Func Test: ");
	
	vectorTest = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
	printf("\nPush & Set Element Func Test:\n\n");
	
	for (i = 0;i < 6;++i)
	{
		status = VectorPush(vectorTest, inputDataPush + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 6 SUCCESS (push check status)\n");
	
	printf("\nSet Element Func Test:\n\n");
	
	status = VectorSetElement(vectorTest, 8, inputDataSetElement);
	
	printf("Set Element number 1 check (status): ");
		
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 1 FAILURE (check status, wrong index)\n");
	
	VectorDestroy(vectorTest);
}

void VectorNumOfElementsTest(void)
{
	Vector_t *vectorTest = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int inputDataPush = 0;
	int i, status;
	size_t numOfElements;
	
	printf("\033[1;34m\n*******Vector Number of Elements Test:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 6\n\n");
	
	printf("Create Func Test: ");
	
	vectorTest = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
	printf("\nNumber of Element Func Test:\n\n");
	
	status = VectorNumOfElements(vectorTest, &numOfElements);
	
	printf("Number of Elements number 1 check (status): ");
	
	CHECK_FUNC(OK == status);
	
	printf("Number of Elements number 1 check (numOfElements): ");
	
	CHECK_FUNC(0 == numOfElements);
	
	printf("\nExpected: 1 SUCCESS (check status) 1 SUCCESS (check numOfElements)\n");
	
	printf("\nPush & Set Element Func Test:\n\n");
	
	for (i = 0;i < 6;++i)
	{
		status = VectorPush(vectorTest, inputDataPush + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 6 SUCCESS (push check status)\n");
	
	printf("\nNumber of Element Func Test:\n\n");
	
	status = VectorNumOfElements(vectorTest, &numOfElements);
	
	printf("Number of Elements number 1 check (status): ");
	
	CHECK_FUNC(OK == status);
	
	printf("Number of Elements number 1 check (numOfElements): ");
	
	CHECK_FUNC(6 == numOfElements);
	
	printf("\nExpected: 1 SUCCESS (check status) 1 SUCCESS (check numOfElements)\n");
	
	VectorDestroy(vectorTest);
}

void VectorPrintTest(void)
{
	Vector_t *vectorTest = NULL;
	int capacity = 2;
	int incBlockSize = 2;
	int inputDataPush = 0;
	int i, status, outputData;
	
	printf("\033[1;34m\n*******Vector Print Test:*******\n\n\033[0m");
	
	printf("capacity = 2, incBlockSize = 2, Number of Push = 7, Number of Pop = 6\n\n");
	
	printf("Create Func Test: ");
	
	vectorTest = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
	printf("\nPush Func Test:\n\n");
	
	for (i = 0;i < 7;++i)
	{
		status = VectorPush(vectorTest, inputDataPush + i);
	
		printf("Push number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 7 SUCCESS (push check status)\n");
	
	printf("\nVector Print Func Test:\n\n");
	
	VectorPrint(vectorTest);
	
	printf("\nExpected: capacity = 8, originalCapacity = 2, incBlockSize = 2, capacityAfter1Increase = 4, capacityAfter2Increase = 6, numOfElements = 7\n");
	
	printf("\nPop Func Test:\n\n");
	
	for (i = 0;i < 6;++i)
	{
		status = VectorPop(vectorTest, &outputData);
	
		printf("Pop number %d check (status): ", i + 1);
		
		CHECK_FUNC(OK == status);
	}
	
	printf("\nExpected: 6 SUCCESS (check status)\n\n");
	
	VectorPrint(vectorTest);
	
	printf("\nExpected: capacity = 4, originalCapacity = 2, incBlockSize = 2, capacityAfter1Increase = 4, capacityAfter2Increase = 6, numOfElements = 1\n");
	
	VectorDestroy(vectorTest);
}

int main(void)
{
	VectorCreateTest1(); /* capacity = 10, incBlockSize = 5 */
	
	VectorCreateTest2(); /* capacity = 0, incBlockSize = 0 */
	
	VectorPushTest1(); /* capacity = 5, incBlockSize = 2, Number of Push = 10 */
	
	VectorPushTest2(); /* capacity = 5, incBlockSize = 0, Number of Push = 8 */
	
	VectorPopTest1(); /* capacity = 5, incBlockSize = 0, Number of Push = 4
																			, Number of Pop = 3*/
	
	VectorPopTest2(); /* capacity = 5, incBlockSize = 0, Number of Push = 4
																			, Number of Pop = 5*/
	
	VectorGetElementTest1(); /* capacity = 5, incBlockSize = 2, Number of Push = 8 */
	
	VectorGetElementTest2(); /* capacity = 5, incBlockSize = 2, Number of Push = 6 */
	
	VectorSetElementTest1(); /* capacity = 5, incBlockSize = 2, Number of Push = 6 */
	
	VectorSetElementTest2(); /* capacity = 5, incBlockSize = 2, Number of Push = 6 */
	
	VectorNumOfElementsTest(); /* capacity = 5, incBlockSize = 2, Number of Push = 6 */
	
	VectorPrintTest(); /* capacity = 2, incBlockSize = 2, Number of Push = 7, 																			Number of Pop = 6*/
	
	return 0;
}
