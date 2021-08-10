#include <stdio.h> /* printf */
#include "dynamicVector.h" /* Dynamic Vector header */

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

void DynamicVectorCreateTest1(void)
{
	dynamic_t *DynamicVectorTest = NULL;
	int arrayCapacity = 10;
	int incBlockSize = 5;
	
	printf("\033[1;34m\n*******Dynamic Vector Create Test 1:*******\n\n\033[0m");
	
	printf("arrayCapacity == 10, incBlockSize == 5\n\n");
	
	printf("Create Func Test: ");
	
	DynamicVectorTest = DynamicVectorCreate(arrayCapacity, incBlockSize);
	
	CHECK_FUNC(NULL != DynamicVectorTest);
	
	DynamicVectorDestroy(DynamicVectorTest);
}

void DynamicVectorCreateTest2(void)
{
	dynamic_t *DynamicVectorTest = NULL;
	int arrayCapacity = -1;
	int incBlockSize = 5;
	
	printf("\033[1;34m\n*******Dynamic Vector Create Test 2:*******\n\n\033[0m");
	
	printf("arrayCapacity == -1, incBlockSize == 5\n\n");
	
	printf("Create Func Test: ");
	
	DynamicVectorTest = DynamicVectorCreate(arrayCapacity, incBlockSize);
	
	CHECK_FUNC(NULL != DynamicVectorTest);
	
	DynamicVectorDestroy(DynamicVectorTest);
}

void DynamicVectorInsertTest1(void)
{
	dynamic_t *DynamicVectorTest = NULL;
	int arrayCapacity = 10;
	int incBlockSize = 5;
	int inputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Dynamic Vector Insert Test 1:*******\n\n\033[0m");
	
	printf("arrayCapacity == 10, incBlockSize == 5, insertNumber == 17\n\n");
	
	printf("Create Func Test: ");
	
	DynamicVectorTest = DynamicVectorCreate(arrayCapacity, incBlockSize);
	
	CHECK_FUNC(NULL != DynamicVectorTest);
	
	printf("\nInsert Func Test:\n\n");
	
	for (i = 0;i < 17;++i)
	{
		status = DynamicVectorInsert(DynamicVectorTest, inputData + i);
	
		printf("Insert number %d: ", i);
		
		CHECK_FUNC(INSERT_SUCCESS == status);
	}
	
	DynamicVectorDestroy(DynamicVectorTest);
}

void DynamicVectorInsertTest2(void)
{
	dynamic_t *DynamicVectorTest = NULL;
	int arrayCapacity = 10;
	int incBlockSize = 0;
	int inputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Dynamic Vector Insert Test 2:*******\n\n\033[0m");
	
	printf("arrayCapacity == 10, incBlockSize == 0, insertNumber == 17\n\n");
	
	printf("Create Func Test: ");
	
	DynamicVectorTest = DynamicVectorCreate(arrayCapacity, incBlockSize);
	
	CHECK_FUNC(NULL != DynamicVectorTest);
	
	printf("\nInsert Func Test:\n\n");
	
	for (i = 0;i < 17;++i)
	{
		status = DynamicVectorInsert(DynamicVectorTest, inputData + i);
	
		printf("Insert number %d: ", i);
		
		CHECK_FUNC(INSERT_SUCCESS == status);
	}
	
	DynamicVectorDestroy(DynamicVectorTest);
}

void DynamicVectorInsertTest3(void)
{
	dynamic_t *DynamicVectorTest = NULL;
	int arrayCapacity = 0;
	int incBlockSize = 5;
	int inputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Dynamic Vector Insert Test 3:*******\n\n\033[0m");
	
	printf("arrayCapacity == 0, incBlockSize == 5, insertNumber == 17\n\n");
	
	printf("Create Func Test: ");
	
	DynamicVectorTest = DynamicVectorCreate(arrayCapacity, incBlockSize);
	
	CHECK_FUNC(NULL != DynamicVectorTest);
	
	printf("\nInsert Func Test:\n\n");
	
	for (i = 0;i < 17;++i)
	{
		status = DynamicVectorInsert(DynamicVectorTest, inputData + i);
	
		printf("Insert number %d: ", i);
		
		CHECK_FUNC(INSERT_SUCCESS == status);
	}
	
	DynamicVectorDestroy(DynamicVectorTest);
}

void DynamicVectorInsertTest4(void)
{
	dynamic_t *DynamicVectorTest = NULL;
	int arrayCapacity = -1;
	int incBlockSize = 5;
	int inputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Dynamic Vector Insert Test 4:*******\n\n\033[0m");
	
	printf("arrayCapacity == -1, incBlockSize == 5, insertNumber == 17\n\n");
	
	printf("Create Func Test: ");
	
	DynamicVectorTest = DynamicVectorCreate(arrayCapacity, incBlockSize);
	
	CHECK_FUNC(NULL != DynamicVectorTest);
	
	printf("\nInsert Func Test:\n\n");
	
	for (i = 0;i < 17;++i)
	{
		status = DynamicVectorInsert(DynamicVectorTest, inputData + i);
	
		printf("Insert number %d: ", i);
		
		CHECK_FUNC(INSERT_SUCCESS == status);
	}
	
	DynamicVectorDestroy(DynamicVectorTest);
}

void DynamicVectorDeleteTest1(void)
{
	dynamic_t *DynamicVectorTest = NULL;
	int arrayCapacity = 10;
	int incBlockSize = 5;
	int inputData = 0;
	int outputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Dynamic Vector Delete Test 1:*******\n\n\033[0m");
	
	printf("arrayCapacity == 10, incBlockSize == 5, insertNumber == 17, deleteNumber = 17\n\n");
	
	printf("Create Func Test: ");
	
	DynamicVectorTest = DynamicVectorCreate(arrayCapacity, incBlockSize);
	
	CHECK_FUNC(NULL != DynamicVectorTest);
	
	printf("\nInsert Func Test:\n\n");
	
	for (i = 0;i < 17;++i)
	{
		status = DynamicVectorInsert(DynamicVectorTest, inputData + i);
	
		printf("Insert number %d: ", i);
		
		CHECK_FUNC(INSERT_SUCCESS == status);
	}
	
	printf("\nDelete Func Test:\n\n");
	
	for (i = 16;0 <= i;--i)
	{
		status = DynamicVectorDelete(DynamicVectorTest, &outputData);
	
		printf("Delete number %d: ", i);
		
		CHECK_FUNC(DELETE_SUCCESS == status);
		
		printf("Check outputData: ");
		
		CHECK_FUNC(i == outputData);
	}
	
	DynamicVectorDestroy(DynamicVectorTest);
}

void DynamicVectorDeleteTest2(void)
{
	dynamic_t *DynamicVectorTest = NULL;
	int arrayCapacity = 10;
	int incBlockSize = 5;
	int inputData = 0;
	int outputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Dynamic Vector Delete Test 2:*******\n\n\033[0m");
	
	printf("arrayCapacity == 10, incBlockSize == 5, insertNumber == 17, deleteNumber = 18\n\n");
	
	printf("Create Func Test: ");
	
	DynamicVectorTest = DynamicVectorCreate(arrayCapacity, incBlockSize);
	
	CHECK_FUNC(NULL != DynamicVectorTest);
	
	printf("\nInsert Func Test:\n\n");
	
	for (i = 0;i < 17;++i)
	{
		status = DynamicVectorInsert(DynamicVectorTest, inputData + i);
	
		printf("Insert number %d: ", i);
		
		CHECK_FUNC(INSERT_SUCCESS == status);
	}
	
	printf("\nDelete Func Test:\n\n");
	
	for (i = 17;0 <= i;--i)
	{
		status = DynamicVectorDelete(DynamicVectorTest, &outputData);
	
		printf("Delete number %d: ", i);
		
		CHECK_FUNC(DELETE_SUCCESS == status);
	}
	
	DynamicVectorDestroy(DynamicVectorTest);
}

void DynamicVectorDeleteTest3(void)
{
	dynamic_t *DynamicVectorTest = NULL;
	int arrayCapacity = 10;
	int incBlockSize = 5;
	int inputData = 0;
	int outputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Dynamic Vector Delete Test 3:*******\n\n\033[0m");
	
	printf("arrayCapacity == 10, incBlockSize == 5, insertNumber == 0, deleteNumber = 18\n\n");
	
	printf("Create Func Test: ");
	
	DynamicVectorTest = DynamicVectorCreate(arrayCapacity, incBlockSize);
	
	CHECK_FUNC(NULL != DynamicVectorTest);
	
	printf("\nDelete Func Test:\n\n");
	
	for (i = 17;0 <= i;--i)
	{
		status = DynamicVectorDelete(DynamicVectorTest, &outputData);
	
		printf("Delete number %d: ", i);
		
		CHECK_FUNC(DELETE_SUCCESS == status);
	}
	
	DynamicVectorDestroy(DynamicVectorTest);
}

void DynamicVectorDeleteTest4(void)
{
	dynamic_t *DynamicVectorTest = NULL;
	int arrayCapacity = 0;
	int incBlockSize = 5;
	int inputData = 0;
	int outputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Dynamic Vector Delete Test 4:*******\n\n\033[0m");
	
	printf("arrayCapacity == 0, incBlockSize == 5, insertNumber == 0, deleteNumber = 18\n\n");
	
	printf("Create Func Test: ");
	
	DynamicVectorTest = DynamicVectorCreate(arrayCapacity, incBlockSize);
	
	CHECK_FUNC(NULL != DynamicVectorTest);
	
	printf("\nDelete Func Test:\n\n");
	
	for (i = 17;0 <= i;--i)
	{
		status = DynamicVectorDelete(DynamicVectorTest, &outputData);
	
		printf("Delete number %d: ", i);
		
		CHECK_FUNC(DELETE_SUCCESS == status);
	}
	
	DynamicVectorDestroy(DynamicVectorTest);
}

void DynamicVectorDeleteTest5(void)
{
	dynamic_t *DynamicVectorTest = NULL;
	int arrayCapacity = -1;
	int incBlockSize = 5;
	int inputData = 0;
	int outputData = 0;
	int i, status;
	
	printf("\033[1;34m\n*******Dynamic Vector Delete Test 5:*******\n\n\033[0m");
	
	printf("arrayCapacity == -1, incBlockSize == 5, insertNumber == 0, deleteNumber = 18\n\n");
	
	printf("Create Func Test: ");
	
	DynamicVectorTest = DynamicVectorCreate(arrayCapacity, incBlockSize);
	
	CHECK_FUNC(NULL != DynamicVectorTest);
	
	printf("\nDelete Func Test:\n\n");
	
	for (i = 17;0 <= i;--i)
	{
		status = DynamicVectorDelete(DynamicVectorTest, &outputData);
	
		printf("Delete number %d: ", i);
		
		CHECK_FUNC(DELETE_SUCCESS == status);
	}
	
	DynamicVectorDestroy(DynamicVectorTest);
}


int main(void)
{
	DynamicVectorCreateTest1();
	
	/*DynamicVectorCreateTest2();*/ /* assert test */
	
	DynamicVectorInsertTest1();
	
	DynamicVectorInsertTest2();
	
	DynamicVectorInsertTest3();
	
	/*DynamicVectorInsertTest4();*/ /* assert test */
	
	DynamicVectorDeleteTest1();
	
	DynamicVectorDeleteTest2();
	
	DynamicVectorDeleteTest3();
	
	DynamicVectorDeleteTest4();
	
	/*DynamicVectorDeleteTest5();*/ /* assert test */
}
