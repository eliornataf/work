#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc, free */
#include "genericVector.h" /* Generic Dynamic Vector header */

#define ARR_SIZE (100)
#define STOP_FOR_EACH (0)
#define RUN_FOR_EACH_NEXT_ITER (1)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

/*************************************************************************/

static void FreeVectorElements(void *_item)
{
	free(_item);
}

static int PrintVectorElements(void *_element, size_t _index, void *_context)
{
	(void)_context;

	printf("Vector index %ld is %d\n", _index, *(int*)_element);

	return RUN_FOR_EACH_NEXT_ITER;
}

static int FindElementInVector(void *_element, size_t _index, void *_context)
{
	if (_element == _context)
	{
		printf("Element %d Found in Index %ld", *(int*)_element, _index);

		return STOP_FOR_EACH;
	}

	return RUN_FOR_EACH_NEXT_ITER;
}

/*************************************************************************/

void VectorCreateTest1(void)
{
	Vector_t *vectorTest = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
	
	printf("\033[1;34m\n*******Vector Create Test 1:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorCreateTest2(void)
{
	Vector_t *vectorTest = NULL;
	size_t initialCapacity = 0;
	size_t incBlockSize = 0;
	
	printf("\033[1;34m\n*******Vector Create Test 2:*******\n\n\033[0m");
	
	printf("initialCapacity = 0, incBlockSize = 0\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL == vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest == NULL check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorCreateTest3(void)
{
	Vector_t *vectorTest = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 0;
	
	printf("\033[1;34m\n*******Vector Create Test 3:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 0\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorCreateTest4(void)
{
	Vector_t *vectorTest = NULL;
	size_t initialCapacity = 0;
	size_t incBlockSize = 5;
	
	printf("\033[1;34m\n*******Vector Create Test 4:*******\n\n\033[0m");
	
	printf("initialCapacity = 0, incBlockSize = 5\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorDestroyTest(void)
{
	Vector_t *vectorTest = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
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
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 3\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

    printf("\nAppend Func Test:\n\n");

	status = VectorAppend(vectorTest, item1);

	printf("Append number 1 check (status): ");
		
	CHECK_FUNC(VECTOR_SUCCESS == status);

	status = VectorAppend(vectorTest, item2);

	printf("Append number 2check (status): ");
		
	CHECK_FUNC(VECTOR_SUCCESS == status);

	status = VectorAppend(vectorTest, item3);

	printf("Append number 3 check (status): ");
		
	CHECK_FUNC(VECTOR_SUCCESS == status);

	printf("\nExpected: 3 SUCCESS (status check)\n");

    printf("\nAppend & Size Func Test: ");

    CHECK_FUNC(3 == VectorSize(vectorTest));

    printf("\nExpected: 1 SUCCESS (size check)\n");
	
	VectorDestroy(&vectorTest, FreeVectorElements);
}

void VectorAppendTest1(void)
{
	Vector_t *vectorTest = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
    int arr[ARR_SIZE];
    int status, i;
	
	printf("\033[1;34m\n*******Vector Append Test 1:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 5\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

    printf("\nAppend Func Test:\n\n");

    for (i = 0;i < 5;++i)
	{
        arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}

	printf("\nExpected: 5 SUCCESS (status check)\n");

    printf("\nAppend & Size Func Test: ");

    CHECK_FUNC(5 == VectorSize(vectorTest));

    printf("\nExpected: 1 SUCCESS (size check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorAppendTest2(void)
{
	Vector_t *vectorTest = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
    int arr[ARR_SIZE];
    int status, i;
	
	printf("\033[1;34m\n*******Vector Append Test 2:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 15\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

    printf("\nAppend Func Test:\n\n");

    for (i = 0;i < 15;++i)
	{
        arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}
    
	printf("\nExpected: 15 SUCCESS (status check)\n");

    printf("\nAppend & Size Func Test: ");

    CHECK_FUNC(15 == VectorSize(vectorTest));

    printf("\nExpected: 1 SUCCESS (size check)\n");

    printf("\nAppend & Capacity Func Test: ");

    CHECK_FUNC(15 == VectorCapacity(vectorTest));

    printf("\nExpected: 1 SUCCESS (capacity check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorAppendTest3(void)
{
	Vector_t *vectorTest = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 0;
    int arr[ARR_SIZE];
    int status, i;
	
	printf("\033[1;34m\n*******Vector Append Test 3:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 0, number of append = 15\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

    printf("\nAppend Func Test:\n\n");

    for (i = 0;i < 15;++i)
	{
        arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}
    
	printf("\nExpected: 10 SUCCESS 5 FAILURE (status check)\n");

    printf("\nAppend & Size Func Test: ");

    CHECK_FUNC(10 == VectorSize(vectorTest));

    printf("\nExpected: 1 SUCCESS (size check)\n");

    printf("\nAppend & Capacity Func Test: ");

    CHECK_FUNC(10 == VectorCapacity(vectorTest));

    printf("\nExpected: 1 SUCCESS (capacity check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorAppendTest4(void)
{
	Vector_t *vectorTest = NULL;
    int arr[ARR_SIZE];
    int status, i;
	
	printf("\033[1;34m\n*******Vector Append Test 4:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 3\n\n");

    printf("\nAppend Func Test:\n\n");

    for (i = 0;i < 3;++i)
	{
        arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_POINTER_NOT_INITIALIZE == status);
	}
    
	printf("\nExpected: 3 SUCCESS (status check) - vector is NULL\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorAppendTest5(void)
{
	Vector_t *vectorTest = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
    int *item = NULL;
    int status, i;
	
	printf("\033[1;34m\n*******Vector Append Test 5:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 3\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

    printf("\nAppend Func Test:\n\n");

    for (i = 0;i < 3;++i)
	{
		status = VectorAppend(vectorTest, item);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_POINTER_NOT_INITIALIZE == status);
	}
    
	printf("\nExpected: 3 SUCCESS (status check) - item is NULL\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorRemoveTest1(void)
{
	Vector_t *vectorTest = NULL;
    void *pItem = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
    int arr[ARR_SIZE];
    int status, i, j;
	
	printf("\033[1;34m\n*******Vector Remove Test 1:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 5, number of remove = 5\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

    printf("\nAppend Func Test:\n\n");

    for (i = 0;i < 5;++i)
	{
        arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}

	printf("\nExpected: 5 SUCCESS (status check)\n");

    printf("\nRemove Func Test:\n\n");

	for (i = 4, j = 1;0 <= i;--i, ++j)
	{
		status = VectorRemove(vectorTest, &pItem);
	
		printf("Remove number %d check (status): ", j);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	
		printf("pItem data number %d check: ", j);
	
		CHECK_FUNC(i == *(int*)pItem);
	}

	printf("\nExpected: 5 SUCCESS (status check) &&  5 SUCCESS (remove number check)\n");

    printf("\nRemove & Size Func Test: ");

    CHECK_FUNC(0 == VectorSize(vectorTest));

    printf("\nExpected: 1 SUCCESS (size check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorRemoveTest2(void)
{
	Vector_t *vectorTest = NULL;
    void *pItem = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
    int arr[ARR_SIZE];
    int status, i, j;
	
	printf("\033[1;34m\n*******Vector Remove Test 2:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 5, number of remove = 7\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

    printf("\nAppend Func Test:\n\n");

    for (i = 0;i < 5;++i)
	{
        arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}

	printf("\nExpected: 5 SUCCESS (status check)\n");

    printf("\nRemove Func Test:\n\n");

	for (i = 6, j = 1;0 <= i;--i, ++j)
	{
		status = VectorRemove(vectorTest, &pItem);
	
		printf("Remove number %d check (status): ", j);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}

	printf("\nExpected: 5 SUCCESS 2 FAILURE (status check)\n");

    printf("\nRemove & Size Func Test: ");

    CHECK_FUNC(0 == VectorSize(vectorTest));

    printf("\nExpected: 1 SUCCESS (size check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorRemoveTest3(void)
{
	Vector_t *vectorTest = NULL;
    void *pItem = NULL;
	size_t initialCapacity = 5;
	size_t incBlockSize = 5;
    int arr[ARR_SIZE];
    int status, i, j;
	
	printf("\033[1;34m\n*******Vector Remove Test 3:*******\n\n\033[0m");
	
	printf("initialCapacity = 5, incBlockSize = 5, number of append = 15, number of remove = 6\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

    printf("\nAppend Func Test:\n\n");

    for (i = 0;i < 15;++i)
	{
        arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}

	printf("\nExpected: 5 SUCCESS (status check)\n");

    printf("\nRemove Func Test:\n\n");

	for (i = 14, j = 1;3 <= i;--i, ++j)
	{
		status = VectorRemove(vectorTest, &pItem);
	
		printf("Remove number %d check (status): ", j);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	
		printf("pItem data number %d check: ", j);
	
		CHECK_FUNC(i == *(int*)pItem);
	}

	printf("\nExpected: 12 SUCCESS (status check) && 12 SUCCESS (get number check)\n");

    printf("\nRemove & Size Func Test: ");

    CHECK_FUNC(3 == VectorSize(vectorTest));

    printf("\nExpected: 1 SUCCESS (size check)\n");

    printf("\nRemove & Capacity Func Test: ");

    CHECK_FUNC(10 == VectorCapacity(vectorTest));

    printf("\nExpected: 1 SUCCESS (capacity check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorRemoveTest4(void)
{
	Vector_t *vectorTest = NULL;
    void *pItem = NULL;
    int status, i, j;
	
	printf("\033[1;34m\n*******Vector Remove Test 4:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 0, number of remove = 2\n\n");

    printf("\nRemove Func Test:\n\n");

	for (i = 2, j = 1;0 <= i;--i, ++j)
	{
		status = VectorRemove(vectorTest, &pItem);
	
		printf("Remove number %d check (status): ", j);
		
		CHECK_FUNC(VECTOR_POINTER_NOT_INITIALIZE == status);
	}

	printf("\nExpected: 2 SUCCESS (status check) - vector is NULL\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorGetTest1(void)
{
	Vector_t *vectorTest = NULL;
    void *pItem = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
    int arr[ARR_SIZE];
    int status, i;
	
	printf("\033[1;34m\n*******Vector Get Test 1:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 5, number of get = 5 \n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

    printf("\nAppend & Get Func Test:\n\n");

    for (i = 0;i < 5;++i)
	{
        arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);

        status = VectorGet(vectorTest, i, &pItem);
		
		printf("Get number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
		
		printf("Get number %d check (outputData): ", i + 1);
		
		CHECK_FUNC(i == *(int*)pItem);
	}

	printf("\nExpected: 5 SUCCESS (status check) && Expected: 5 SUCCESS (status check) && Expected: 5 SUCCESS (get number check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorGetTest2(void)
{
	Vector_t *vectorTest = NULL;
    void *pItem = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
    int arr[ARR_SIZE];
    int status, i, j;
	
	printf("\033[1;34m\n*******Vector Get Test 2:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 5, number of get = 5\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

    printf("\nAppend & Get Func Test:\n\n");

    for (i = 0, j = 10;i < 5;++i, ++j)
	{
        arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);

        status = VectorGet(vectorTest, j, &pItem);
		
		printf("Get number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_WRONG_INDEX == status);
	}

	printf("\nExpected: 5 SUCCESS (status check) && Expected: 5 SUCCESS (status check)\n");

	VectorDestroy(&vectorTest, NULL);
}

void VectorGetTest3(void)
{
	Vector_t *vectorTest = NULL;
    void *pItem = NULL;
    int status, i;
	
	printf("\033[1;34m\n*******Vector Get Test 3:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 0\n\n");

    printf("Get Func Test:\n\n");

    for (i = 0;i < 5;++i)
	{
        status = VectorGet(vectorTest, i, &pItem);
		
		printf("Get number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_POINTER_NOT_INITIALIZE == status);
	}

	printf("\nExpected: 5 SUCCESS (status check) -vectorTest is NULL\n");

	VectorDestroy(&vectorTest, NULL);
}

void VectorSetTest1(void)
{
	Vector_t *vectorTest = NULL;
    void *pItem = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
    int arr[ARR_SIZE];
    int value = 5;
    int status, i;
	
	printf("\033[1;34m\n*******Vector Set Test 1:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 5, number of set = 5 , number of get = 5\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

    printf("\nAppend & Set Func Test:\n\n");

    for (i = 0;i < 5;++i)
	{
        arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);

        status = VectorSet(vectorTest, i, &value);
		
		printf("Set number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
		
        status = VectorGet(vectorTest, i, &pItem);

		printf("Get number %d check (outputData): ", i + 1);
		
		CHECK_FUNC(5 == *(int*)pItem);
	}

	printf("\nExpected: 5 SUCCESS (status check) && Expected: 5 SUCCESS (status check) && Expected: 5 SUCCESS (get number check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorSetTest2(void)
{
	Vector_t *vectorTest = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
    int arr[ARR_SIZE];
    int value = 5;
    int status, i, j;
	
	printf("\033[1;34m\n*******Vector Set Test 2:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 5, number of set = 5 \n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

    printf("\nAppend & Set Func Test:\n\n");

    for (i = 0, j = 10;i < 5;++i, ++j)
	{
        arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);

        status = VectorSet(vectorTest, j, &value);
		
		printf("Set number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_WRONG_INDEX == status);
	}

	printf("\nExpected: 5 SUCCESS (status check) && Expected: 5 SUCCESS (status check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorSetTest3(void)
{
	Vector_t *vectorTest = NULL;
    int value = 5;
    int status, i;
	
	printf("\033[1;34m\n*******Vector Set Test 3:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of set = 5 \n\n");
	
    printf("Set Func Test:\n\n");

    for (i = 0;i < 5;++i)
	{
        status = VectorSet(vectorTest, i, &value);
		
		printf("Set number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_POINTER_NOT_INITIALIZE == status);
	}

	printf("\nExpected: 5 SUCCESS (status check) - vectorTest idsNULL\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorSetTest4(void)
{
	Vector_t *vectorTest = NULL;
    int *value = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
    int status, i;
	
	printf("\033[1;34m\n*******Vector Set Test 4:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of set = 5\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

    printf("\nSet Func Test:\n\n");

    for (i = 0;i < 5;++i)
	{
        status = VectorSet(vectorTest, i, value);
		
		printf("Set number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_POINTER_NOT_INITIALIZE == status);
	}

	printf("\nExpected: 5 SUCCESS (status check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorSizeTest1(void)
{
	Vector_t *vectorTest = NULL;
    void *pItem = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
    int arr[ARR_SIZE];
    int status, i, j;
	
	printf("\033[1;34m\n*******Vector Size Test 1:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 5, number of remove = 5\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

    printf("\nSize Func Test 1: ");
			
	CHECK_FUNC(0 == VectorSize(vectorTest));

	printf("\nExpected: SUCCESS (size check)\n");

    printf("\nAppend Func Test:\n\n");

    for (i = 0;i < 5;++i)
	{
        arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}

	printf("\nExpected: 5 SUCCESS (status check)\n");

    printf("\nSize Func Test 2: ");
			
	CHECK_FUNC(5 == VectorSize(vectorTest));

	printf("\nExpected: SUCCESS (size check)\n");

    printf("\nRemove Func Test:\n\n");

	for (i = 4, j = 1;0 <= i;--i, ++j)
	{
		status = VectorRemove(vectorTest, &pItem);
	
		printf("Remove number %d check (status): ", j);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	
		printf("pItem data number %d check: ", j);
	
		CHECK_FUNC(i == *(int*)pItem);
	}

	printf("\nExpected: 5 SUCCESS (status check) &&  5 SUCCESS (remove number check)\n");

    printf("\nSize Func Test 3: ");
			
	CHECK_FUNC(0 == VectorSize(vectorTest));

	printf("\nExpected: SUCCESS (size check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorSizeTest2(void)
{
	Vector_t *vectorTest = NULL;
	
	printf("\033[1;34m\n*******Vector Size Test 2:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5\n\n");

    printf("\nSize Func Test: ");
			
	CHECK_FUNC(POINTER_NOT_INITIALIZE_VECTOR_SIZE == VectorSize(vectorTest));

	printf("\nExpected: SUCCESS (size check) - vectorTest is NULL\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorCapacityTest1(void)
{
	Vector_t *vectorTest = NULL;
    void *pItem = NULL;
	size_t initialCapacity = 5;
	size_t incBlockSize = 5;
    int arr[ARR_SIZE];
    int status, i, j;
	
	printf("\033[1;34m\n*******Vector Capacity Test 1:*******\n\n\033[0m");
	
	printf("initialCapacity = 5, incBlockSize = 5, number of append = 15, number of remove = 6\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

	printf("\nCapacity Func Test 1: ");
			
	CHECK_FUNC(5 == VectorCapacity(vectorTest));

	printf("\nExpected: SUCCESS (capacity check)\n");

    printf("\nAppend Func Test:\n\n");

    for (i = 0;i < 15;++i)
	{
        arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}

	printf("\nExpected: 5 SUCCESS (status check)\n");

	printf("\nCapacity Func Test 2: ");
			
	CHECK_FUNC(15 == VectorCapacity(vectorTest));

	printf("\nExpected: SUCCESS (capacity check)\n");

    printf("\nRemove Func Test:\n\n");

	for (i = 14, j = 1;3 <= i;--i, ++j)
	{
		status = VectorRemove(vectorTest, &pItem);
	
		printf("Remove number %d check (status): ", j);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	
		printf("pItem data number %d check: ", j);
	
		CHECK_FUNC(i == *(int*)pItem);
	}

	printf("\nExpected: 12 SUCCESS (status check) && 12 SUCCESS (get number check)\n");

    printf("\nCapacity Func Test 3: ");

    CHECK_FUNC(10 == VectorCapacity(vectorTest));

    printf("\nExpected: 1 SUCCESS (capacity check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorCapacityTest2(void)
{
	Vector_t *vectorTest = NULL;
	
	printf("\033[1;34m\n*******Vector Capacity Test 2:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5\n\n");

    printf("Capacity Func Test: ");
			
	CHECK_FUNC(POINTER_NOT_INITIALIZE_VECTOR_CAPACITY == VectorCapacity(vectorTest));

	printf("\nExpected: SUCCESS (capacity check) - vectorTest is NULL\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorForEachTest1(void)
{
	Vector_t *vectorTest = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
    int arr[ARR_SIZE];
    int status, i;
	
	printf("\033[1;34m\n*******Vector For Each Test 1:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 5\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

    printf("\nAppend Func Test:\n\n");

    for (i = 0;i < 5;++i)
	{
        arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}

	printf("\nExpected: 5 SUCCESS (status check)\n\n");

	status = VectorForEach(vectorTest, PrintVectorElements, NULL);

    printf("\nFor Each Func Test: ");

    CHECK_FUNC(5 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorForEachTest2(void)
{
	Vector_t *vectorTest = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
    int arr[ARR_SIZE];
    int status, i;
	
	printf("\033[1;34m\n*******Vector For Each Test 2:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5, number of append = 5\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

    printf("\nAppend Func Test:\n\n");

    for (i = 0;i < 5;++i)
	{
        arr[i] = i;

		status = VectorAppend(vectorTest, &arr[i]);

		printf("Append number %d check (status): ", i + 1);
		
		CHECK_FUNC(VECTOR_SUCCESS == status);
	}

	printf("\nExpected: 5 SUCCESS (status check)\n\n");

	status = VectorForEach(vectorTest, FindElementInVector, &arr[3]);

    printf("\n\nFor Each Func Test: ");

    CHECK_FUNC(3 == status);

    printf("\nExpected: 1 SUCCESS (for each check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorForEachTest3(void)
{
	Vector_t *vectorTest = NULL;
	
	printf("\033[1;34m\n*******Vector For Each Test 3:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5\n\n");
	
    printf("For Each Func Test: ");

    CHECK_FUNC(POINTER_NOT_INITIALIZE_VECTOR_FOR_EACH == VectorForEach(vectorTest, PrintVectorElements, NULL));

    printf("\nExpected: 1 SUCCESS (for each check) - vectorTest is NULL\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorForEachTest4(void)
{
	Vector_t *vectorTest = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
	
	printf("\033[1;34m\n*******Vector For Each Test 4:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

    printf("\nFor Each Func Test: ");

    CHECK_FUNC(POINTER_NOT_INITIALIZE_VECTOR_FOR_EACH == VectorForEach(vectorTest, NULL, NULL));

    printf("\nExpected: 1 SUCCESS (for each check) - action is NULL\n");
	
	VectorDestroy(&vectorTest, NULL);
}

void VectorForEachTest5(void)
{
	Vector_t *vectorTest = NULL;
	size_t initialCapacity = 10;
	size_t incBlockSize = 5;
	
	printf("\033[1;34m\n*******Vector For Each Test 5:*******\n\n\033[0m");
	
	printf("initialCapacity = 10, incBlockSize = 5\n\n");
	
	printf("Create Func Test: ");

	vectorTest = VectorCreate(initialCapacity, incBlockSize);

	CHECK_FUNC(NULL != vectorTest);
	
	printf("\nExpected: SUCCESS (vectorTest != NULL check)\n");

    printf("\nFor Each Func Test: ");

    CHECK_FUNC(UNDERFLOW_VECTOR_FOR_EACH == VectorForEach(vectorTest, PrintVectorElements, NULL));

    printf("\nExpected: 1 SUCCESS (for each check)\n");
	
	VectorDestroy(&vectorTest, NULL);
}

int main(void)
{
    VectorCreateTest1();
    VectorCreateTest2();
    VectorCreateTest3();
    VectorCreateTest4();

	VectorDestroyTest();

    VectorAppendTest1();
    VectorAppendTest2();
    VectorAppendTest3();
    VectorAppendTest4();
    VectorAppendTest5();

    VectorRemoveTest1();
    VectorRemoveTest2();
    VectorRemoveTest3();
    VectorRemoveTest4();

    VectorGetTest1();
    VectorGetTest2();
    VectorGetTest3();

    VectorSetTest1();
    VectorSetTest2();
    VectorSetTest3();
	VectorSetTest4();

	VectorSizeTest1();
	VectorSizeTest2();

	VectorCapacityTest1();
	VectorCapacityTest2();

	VectorForEachTest1();
	VectorForEachTest2();
	VectorForEachTest3();
	VectorForEachTest4();
	VectorForEachTest5();

    return 0;
}
