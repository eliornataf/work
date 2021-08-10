#include <stdlib.h> /* malloc, free */
#include <stdio.h> /* printf */
#include "myMalloc.h" /* myMalloc header */

#define BLOCK_SIZE (sizeof(long))

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

void MyMallocInitTest1(void)
{
    void *memoryBlock = NULL;
    size_t memoryBlockSize = 104;

    printf("\033[1;34m\n*******My Malloc Init Test 1:*******\n\n\033[0m");

    memoryBlock = (void*)malloc(memoryBlockSize);
    if (NULL == memoryBlock)
    {
        return;
    }

    MyMallocInit(memoryBlock, memoryBlockSize);

    printf("My Malloc Init Func Test 1: ");

    CHECK_FUNC((long)memoryBlockSize == *(long*)memoryBlock);

    printf("\nExpected: SUCCESS - First Metadata block equal to memoryBlockSize\n");

    printf("\nMy Malloc Init Func Test 2: ");

    CHECK_FUNC((long)(memoryBlockSize - BLOCK_SIZE * 3) == *(long*)((char*)memoryBlock + BLOCK_SIZE));

    printf("\nExpected: SUCCESS - Second Metadata block equal to memoryBlockSize minus BLOCK_SIZE * 3\n");

    printf("\nMy Malloc Init Func Test 3: ");

    CHECK_FUNC(0 == *(long*)((char*)memoryBlock + (memoryBlockSize - BLOCK_SIZE)));

    printf("\nExpected: SUCCESS - Last Metadata block equal to zero\n");

    free(memoryBlock);
}

void MyMallocInitTest2(void)
{
    void *memoryBlock = NULL;
    size_t memoryBlockSize = 44;
    size_t alignment = 4;

    printf("\033[1;34m\n*******My Malloc Init Test 2:*******\n\n\033[0m");

    memoryBlock = (void*)malloc(memoryBlockSize);
    if (NULL == memoryBlock)
    {
        return;
    }

    MyMallocInit(memoryBlock, memoryBlockSize);

    printf("My Malloc Init Func Test 1: ");

    CHECK_FUNC((long)(memoryBlockSize - alignment) == *(long*)memoryBlock);

    printf("\nExpected: SUCCESS - First Metadata block equal to memoryBlockSize minus alignment\n");

    printf("\nMy Malloc Init Func Test 2: ");

    CHECK_FUNC((long)(memoryBlockSize - BLOCK_SIZE * 3 - alignment) == *(long*)((char*)memoryBlock + BLOCK_SIZE));

    printf("\nExpected: SUCCESS - Second Metadata block equal to memoryBlockSize minus BLOCK_SIZE * 3 minus alignment\n");

    printf("\nMy Malloc Init Func Test 3: ");

    CHECK_FUNC(0 == *(long*)((char*)memoryBlock + (memoryBlockSize - BLOCK_SIZE - alignment)));

    printf("\nExpected: SUCCESS - Last Metadata block equal to zero\n");

    free(memoryBlock);
}

void MyAllocTest1(void)
{
    void *memoryBlock = NULL;
    void *allocatedBlock = NULL;
    size_t memoryBlockSize = 104;
    size_t requestedBlockSize = 64;

    printf("\033[1;34m\n*******My Alloc Test 1:*******\n\n\033[0m");

    memoryBlock = (void*)malloc(memoryBlockSize);
    if (NULL == memoryBlock)
    {
        return;
    }

    MyMallocInit(memoryBlock, memoryBlockSize);

    printf("My Malloc Init Func Test 1: ");

    CHECK_FUNC((long)memoryBlockSize == *(long*)memoryBlock);

    printf("\nExpected: SUCCESS - First Metadata block equal to memoryBlockSize\n");

    printf("\nMy Malloc Init Func Test 2: ");

    CHECK_FUNC((long)(memoryBlockSize - BLOCK_SIZE * 3) == *(long*)((char*)memoryBlock + BLOCK_SIZE));

    printf("\nExpected: SUCCESS - Second Metadata block equal to memoryBlockSize minus BLOCK_SIZE * 3\n");

    printf("\nMy Malloc Init Func Test 3: ");

    CHECK_FUNC(0 == *(long*)((char*)memoryBlock + (memoryBlockSize - BLOCK_SIZE)));

    printf("\nExpected: SUCCESS - Last Metadata block equal to zero\n");

    printf("\nMy Alloc Func Test 1: ");

    allocatedBlock = MyAlloc(memoryBlock, requestedBlockSize);

    CHECK_FUNC(NULL != allocatedBlock);

    printf("\nExpected: SUCCESS - requestedBlockSize is fine, alloc seccedded (allocatedBlock != NULL)\n");

    printf("\nMy Alloc Func Test 2: ");

    CHECK_FUNC((long)(requestedBlockSize * (-1)) == *(long*)((char*)allocatedBlock - BLOCK_SIZE));

    printf("\nExpected: SUCCESS - requestedBlockSize is fine, alloc seccedded (allocatedBlock size is correct)\n");

    free(memoryBlock);
}

void MyAllocTest2(void)
{
    void *memoryBlock = NULL;
    void *allocatedBlock = NULL;
    size_t memoryBlockSize = 104;
    size_t requestedBlockSize = 10;
    size_t alignment = 6;

    printf("\033[1;34m\n*******My Alloc Test 2:*******\n\n\033[0m");

    memoryBlock = (void*)malloc(memoryBlockSize);
    if (NULL == memoryBlock)
    {
        return;
    }

    MyMallocInit(memoryBlock, memoryBlockSize);

    printf("My Malloc Init Func Test 1: ");

    CHECK_FUNC((long)memoryBlockSize == *(long*)memoryBlock);

    printf("\nExpected: SUCCESS - First Metadata block equal to memoryBlockSize\n");

    printf("\nMy Malloc Init Func Test 2: ");

    CHECK_FUNC((long)(memoryBlockSize - BLOCK_SIZE * 3) == *(long*)((char*)memoryBlock + BLOCK_SIZE));

    printf("\nExpected: SUCCESS - Second Metadata block equal to memoryBlockSize minus BLOCK_SIZE * 3\n");

    printf("\nMy Malloc Init Func Test 3: ");

    CHECK_FUNC(0 == *(long*)((char*)memoryBlock + (memoryBlockSize - BLOCK_SIZE)));

    printf("\nExpected: SUCCESS - Last Metadata block equal to zero\n");

    printf("\nMy Alloc Func Test: ");

    allocatedBlock = MyAlloc(memoryBlock, requestedBlockSize);

    CHECK_FUNC((long)((requestedBlockSize + alignment) * (-1)) == *(long*)((char*)allocatedBlock - BLOCK_SIZE));

    printf("\nExpected: SUCCESS - requestedBlockSize is fine, alloc seccedded (allocatedBlock size is correct with alignment)\n");

    free(memoryBlock);
}
    
void MyAllocTest3(void)
{
    void *memoryBlock = NULL;
    void *allocatedBlock = NULL;
    size_t memoryBlockSize = 104;
    size_t firstRequestedBlockSize = 32;
    size_t secondRequestedBlockSize = 24;
    size_t thirdRequestedBlockSize = 8;

    printf("\033[1;34m\n*******My Alloc Test 3:*******\n\n\033[0m");

    memoryBlock = (void*)malloc(memoryBlockSize);
    if (NULL == memoryBlock)
    {
        return;
    }

    MyMallocInit(memoryBlock, memoryBlockSize);

    printf("My Malloc Init Func Test 1: ");

    CHECK_FUNC((long)memoryBlockSize == *(long*)memoryBlock);

    printf("\nExpected: SUCCESS - First Metadata block equal to memoryBlockSize\n");

    printf("\nMy Malloc Init Func Test 2: ");

    CHECK_FUNC((long)(memoryBlockSize - BLOCK_SIZE * 3) == *(long*)((char*)memoryBlock + BLOCK_SIZE));

    printf("\nExpected: SUCCESS - Second Metadata block equal to memoryBlockSize minus BLOCK_SIZE * 3\n");

    printf("\nMy Malloc Init Func Test 3: ");

    CHECK_FUNC(0 == *(long*)((char*)memoryBlock + (memoryBlockSize - BLOCK_SIZE)));

    printf("\nExpected: SUCCESS - Last Metadata block equal to zero\n");

    printf("\nMy Alloc Func Test 1: ");

    allocatedBlock = MyAlloc(memoryBlock, firstRequestedBlockSize);

    CHECK_FUNC((long)(firstRequestedBlockSize * (-1)) == *(long*)((char*)allocatedBlock - BLOCK_SIZE));

    printf("\nExpected: SUCCESS - firstRequestedBlockSize is fine, alloc seccedded (firstRequestedBlockSize size is correct)\n");

    printf("\nMy Alloc Func Test 2: ");

    allocatedBlock = MyAlloc(memoryBlock, secondRequestedBlockSize);

    CHECK_FUNC((long)(secondRequestedBlockSize * (-1)) == *(long*)((char*)allocatedBlock - BLOCK_SIZE));

    printf("\nExpected: SUCCESS - secondRequestedBlockSize is fine, alloc seccedded (secondRequestedBlockSize size is correct)\n");

    printf("\nMy Alloc Func Test 3: ");

    allocatedBlock = MyAlloc(memoryBlock, thirdRequestedBlockSize);

    CHECK_FUNC((long)(thirdRequestedBlockSize * (-1)) == *(long*)((char*)allocatedBlock - BLOCK_SIZE));

    printf("\nExpected: SUCCESS - thirdRequestedBlockSize is fine, alloc seccedded (thirdRequestedBlockSize size is correct)\n");

    free(memoryBlock);
}

void MyAllocTest4(void)
{
    void *memoryBlock = NULL;
    void *allocatedBlock = NULL;
    size_t memoryBlockSize = 104;
    size_t firstRequestedBlockSize = 32;
    size_t secondRequestedBlockSize = 24;
    size_t thirdRequestedBlockSize = 32;

    printf("\033[1;34m\n*******My Alloc Test 4:*******\n\n\033[0m");

    memoryBlock = (void*)malloc(memoryBlockSize);
    if (NULL == memoryBlock)
    {
        return;
    }

    MyMallocInit(memoryBlock, memoryBlockSize);

    printf("My Malloc Init Func Test 1: ");

    CHECK_FUNC((long)memoryBlockSize == *(long*)memoryBlock);

    printf("\nExpected: SUCCESS - First Metadata block equal to memoryBlockSize\n");

    printf("\nMy Malloc Init Func Test 2: ");

    CHECK_FUNC((long)(memoryBlockSize - BLOCK_SIZE * 3) == *(long*)((char*)memoryBlock + BLOCK_SIZE));

    printf("\nExpected: SUCCESS - Second Metadata block equal to memoryBlockSize minus BLOCK_SIZE * 3\n");

    printf("\nMy Malloc Init Func Test 3: ");

    CHECK_FUNC(0 == *(long*)((char*)memoryBlock + (memoryBlockSize - BLOCK_SIZE)));

    printf("\nExpected: SUCCESS - Last Metadata block equal to zero\n");

    printf("\nMy Alloc Func Test 1: ");

    allocatedBlock = MyAlloc(memoryBlock, firstRequestedBlockSize);

    CHECK_FUNC((long)(firstRequestedBlockSize * (-1)) == *(long*)((char*)allocatedBlock - BLOCK_SIZE));

    printf("\nExpected: SUCCESS - firstRequestedBlockSize is fine, alloc seccedded (firstRequestedBlockSize size is correct)\n");

    printf("\nMy Alloc Func Test 2: ");

    allocatedBlock = MyAlloc(memoryBlock, secondRequestedBlockSize);

    CHECK_FUNC((long)(secondRequestedBlockSize * (-1)) == *(long*)((char*)allocatedBlock - BLOCK_SIZE));

    printf("\nExpected: SUCCESS - secondRequestedBlockSize is fine, alloc seccedded (secondRequestedBlockSize size is correct)\n");

    printf("\nMy Alloc Func Test 3: ");

    allocatedBlock = MyAlloc(memoryBlock, thirdRequestedBlockSize);

    CHECK_FUNC(NULL == allocatedBlock);

    printf("\nExpected: SUCCESS - thirdRequestedBlockSize is bigger then possible, alloc failed (allocatedBlock is NULL)\n");

    free(memoryBlock);
}

void MyAllocTest5(void)
{
    void *memoryBlock = NULL;
    void *allocatedBlock = NULL;
    size_t memoryBlockSize = 128;
    size_t firstRequestedBlockSize = 38;
    size_t secondRequestedBlockSize = 30;
    size_t thirdRequestedBlockSize = 8;
    size_t alignment = 2;

    printf("\033[1;34m\n*******My Alloc Test 5:*******\n\n\033[0m");

    memoryBlock = (void*)malloc(memoryBlockSize);
    if (NULL == memoryBlock)
    {
        return;
    }

    MyMallocInit(memoryBlock, memoryBlockSize);

    printf("My Malloc Init Func Test 1: ");

    CHECK_FUNC((long)memoryBlockSize == *(long*)memoryBlock);

    printf("\nExpected: SUCCESS - First Metadata block equal to memoryBlockSize\n");

    printf("\nMy Malloc Init Func Test 2: ");

    CHECK_FUNC((long)(memoryBlockSize - BLOCK_SIZE * 3) == *(long*)((char*)memoryBlock + BLOCK_SIZE));

    printf("\nExpected: SUCCESS - Second Metadata block equal to memoryBlockSize minus BLOCK_SIZE * 3\n");

    printf("\nMy Malloc Init Func Test 3: ");

    CHECK_FUNC(0 == *(long*)((char*)memoryBlock + (memoryBlockSize - BLOCK_SIZE)));

    printf("\nExpected: SUCCESS - Last Metadata block equal to zero\n");

    printf("\nMy Alloc Func Test 1: ");

    allocatedBlock = MyAlloc(memoryBlock, firstRequestedBlockSize);

    CHECK_FUNC((long)((firstRequestedBlockSize + alignment) * (-1)) == *(long*)((char*)allocatedBlock - BLOCK_SIZE));

    printf("\nExpected: SUCCESS - firstRequestedBlockSize is fine, alloc seccedded (firstRequestedBlockSize size is correct with alignment)\n");

    printf("\nMy Alloc Func Test 2: ");

    allocatedBlock = MyAlloc(memoryBlock, secondRequestedBlockSize);

    CHECK_FUNC((long)((secondRequestedBlockSize + alignment) * (-1)) == *(long*)((char*)allocatedBlock - BLOCK_SIZE));

    printf("\nExpected: SUCCESS - secondRequestedBlockSize is fine, alloc seccedded (secondRequestedBlockSize size is correct with alignment)\n");

    printf("\nMy Alloc Func Test 3: ");

    allocatedBlock = MyAlloc(memoryBlock, thirdRequestedBlockSize);

    CHECK_FUNC((long)((thirdRequestedBlockSize + BLOCK_SIZE) * (-1)) == *(long*)((char*)allocatedBlock - BLOCK_SIZE));

    printf("\nExpected: SUCCESS - thirdRequestedBlockSize is fine, alloc seccedded (thirdRequestedBlockSize size is correct with fixed thirdRequestedBlockSize [Plus BLOCK_SIZE])\n");

    free(memoryBlock);
}

void MyAllocTest6(void)
{
    void *memoryBlock = NULL;
    void *allocatedBlock = NULL;
    size_t memoryBlockSize = 104;
    size_t requestedBlockSize = 104;

    printf("\033[1;34m\n*******My Alloc Test 6:*******\n\n\033[0m");

    memoryBlock = (void*)malloc(memoryBlockSize);
    if (NULL == memoryBlock)
    {
        return;
    }

    MyMallocInit(memoryBlock, memoryBlockSize);

    printf("My Malloc Init Func Test 1: ");

    CHECK_FUNC((long)memoryBlockSize == *(long*)memoryBlock);

    printf("\nExpected: SUCCESS - First Metadata block equal to memoryBlockSize\n");

    printf("\nMy Malloc Init Func Test 2: ");

    CHECK_FUNC((long)(memoryBlockSize - BLOCK_SIZE * 3) == *(long*)((char*)memoryBlock + BLOCK_SIZE));

    printf("\nExpected: SUCCESS - Second Metadata block equal to memoryBlockSize minus BLOCK_SIZE * 3\n");

    printf("\nMy Malloc Init Func Test 3: ");

    CHECK_FUNC(0 == *(long*)((char*)memoryBlock + (memoryBlockSize - BLOCK_SIZE)));

    printf("\nExpected: SUCCESS - Last Metadata block equal to zero\n");

    printf("\nMy Alloc Func Test: ");

    allocatedBlock = MyAlloc(memoryBlock, requestedBlockSize);

    CHECK_FUNC(NULL == allocatedBlock);

    printf("\nExpected: SUCCESS - memoryBlock is NULL, alloc failed (requestedBlockSize is bigger then possible)\n");

    free(memoryBlock);
}

void MyAllocTest7(void)
{
    void *memoryBlock = NULL;
    void *allocatedBlock = NULL;
    size_t memoryBlockSize = 104;
    size_t requestedBlockSize = 0;

    printf("\033[1;34m\n*******My Alloc Test 7:*******\n\n\033[0m");

    memoryBlock = (void*)malloc(memoryBlockSize);
    if (NULL == memoryBlock)
    {
        return;
    }

    MyMallocInit(memoryBlock, memoryBlockSize);

    printf("My Malloc Init Func Test 1: ");

    CHECK_FUNC((long)memoryBlockSize == *(long*)memoryBlock);

    printf("\nExpected: SUCCESS - First Metadata block equal to memoryBlockSize\n");

    printf("\nMy Malloc Init Func Test 2: ");

    CHECK_FUNC((long)(memoryBlockSize - BLOCK_SIZE * 3) == *(long*)((char*)memoryBlock + BLOCK_SIZE));

    printf("\nExpected: SUCCESS - Second Metadata block equal to memoryBlockSize minus BLOCK_SIZE * 3\n");

    printf("\nMy Malloc Init Func Test 3: ");

    CHECK_FUNC(0 == *(long*)((char*)memoryBlock + (memoryBlockSize - BLOCK_SIZE)));

    printf("\nExpected: SUCCESS - Last Metadata block equal to zero\n");

    printf("\nMy Alloc Func Test: ");

    allocatedBlock = MyAlloc(memoryBlock, requestedBlockSize);

    CHECK_FUNC(NULL == allocatedBlock);

    printf("\nExpected: SUCCESS - requestedBlockSize is zero, alloc failed\n");

    free(memoryBlock);
}

void MyAllocTest8(void)
{
    void *memoryBlock = NULL;
    void *allocatedBlock = NULL;
    size_t requestedBlockSize = 60;

    printf("\033[1;34m\n*******My Alloc Test 8:*******\n\n\033[0m");

    printf("My Alloc Func Test: ");

    allocatedBlock = MyAlloc(memoryBlock, requestedBlockSize);

    CHECK_FUNC(NULL == allocatedBlock);

    printf("\nExpected: SUCCESS - memoryBlock is NULL, alloc failed\n");

    free(memoryBlock);
}

void MyFreeTest1(void)
{
    void *memoryBlock = NULL;
    void *allocatedBlock = NULL;
    size_t memoryBlockSize = 104;
    size_t requestedBlockSize = 80;

    printf("\033[1;34m\n*******My Free Test 1:*******\n\n\033[0m");

    memoryBlock = (void*)malloc(memoryBlockSize);
    if (NULL == memoryBlock)
    {
        return;
    }

    MyMallocInit(memoryBlock, memoryBlockSize);

    printf("My Malloc Init Func Test 1: ");

    CHECK_FUNC((long)memoryBlockSize == *(long*)memoryBlock);

    printf("\nExpected: SUCCESS - First Metadata block equal to memoryBlockSize\n");

    printf("\nMy Malloc Init Func Test 2: ");

    CHECK_FUNC((long)(memoryBlockSize - BLOCK_SIZE * 3) == *(long*)((char*)memoryBlock + BLOCK_SIZE));

    printf("\nExpected: SUCCESS - Second Metadata block equal to memoryBlockSize minus BLOCK_SIZE * 3\n");

    printf("\nMy Malloc Init Func Test 3: ");

    CHECK_FUNC(0 == *(long*)((char*)memoryBlock + (memoryBlockSize - BLOCK_SIZE)));

    printf("\nExpected: SUCCESS - Last Metadata block equal to zero\n");

    printf("\nMy Alloc Func Test 1: ");

    allocatedBlock = MyAlloc(memoryBlock, requestedBlockSize);

    CHECK_FUNC((long)(requestedBlockSize * (-1)) == *(long*)((char*)allocatedBlock - BLOCK_SIZE));

    printf("\nExpected: SUCCESS - requestedBlockSize is fine, alloc seccedded (allocatedBlock size is correct)\n");

    MyFree(allocatedBlock);

    printf("\nMy Free Func Test: ");

    allocatedBlock = MyAlloc(memoryBlock, requestedBlockSize);

    CHECK_FUNC((long)(requestedBlockSize * (-1)) == *(long*)((char*)allocatedBlock - BLOCK_SIZE));

    printf("\nExpected: SUCCESS - requestedBlockSize is fine, alloc seccedded (allocatedBlock size is correct) - alloc max block size after free\n");

    free(memoryBlock);
}

void MyFreeTest2(void)
{
    void *memoryBlock = NULL;
    void *allocatedBlock1 = NULL;
    void *allocatedBlock2 = NULL;
    size_t memoryBlockSize = 104;
    size_t firstRequestedBlockSize = 32;
    size_t secondRequestedBlockSize = 40;
    size_t thirdRequestedBlockSize = 80;

    printf("\033[1;34m\n*******My Free Test 2:*******\n\n\033[0m");

    memoryBlock = (void*)malloc(memoryBlockSize);
    if (NULL == memoryBlock)
    {
        return;
    }

    MyMallocInit(memoryBlock, memoryBlockSize);

    printf("My Malloc Init Func Test 1: ");

    CHECK_FUNC((long)memoryBlockSize == *(long*)memoryBlock);

    printf("\nExpected: SUCCESS - First Metadata block equal to memoryBlockSize\n");

    printf("\nMy Malloc Init Func Test 2: ");

    CHECK_FUNC((long)(memoryBlockSize - BLOCK_SIZE * 3) == *(long*)((char*)memoryBlock + BLOCK_SIZE));

    printf("\nExpected: SUCCESS - Second Metadata block equal to memoryBlockSize minus BLOCK_SIZE * 3\n");

    printf("\nMy Malloc Init Func Test 3: ");

    CHECK_FUNC(0 == *(long*)((char*)memoryBlock + (memoryBlockSize - BLOCK_SIZE)));

    printf("\nExpected: SUCCESS - Last Metadata block equal to zero\n");

    printf("\nMy Alloc Func Test 1: ");

    allocatedBlock1 = MyAlloc(memoryBlock, firstRequestedBlockSize);

    CHECK_FUNC((long)(firstRequestedBlockSize * (-1)) == *(long*)((char*)allocatedBlock1 - BLOCK_SIZE));

    printf("\nExpected: SUCCESS - firstRequestedBlockSize is fine, alloc seccedded (allocatedBlock1 size is correct)\n");

    printf("\nMy Alloc Func Test 2: ");

    allocatedBlock2 = MyAlloc(memoryBlock, secondRequestedBlockSize);

    CHECK_FUNC((long)(secondRequestedBlockSize * (-1)) == *(long*)((char*)allocatedBlock2 - BLOCK_SIZE));

    printf("\nExpected: SUCCESS - secondRequestedBlockSize is fine, alloc seccedded (allocatedBlock2 size is correct) - memoryBlock is full\n");

    MyFree(allocatedBlock2);
    MyFree(allocatedBlock1);

    printf("\nMy Free Func Test: ");

    allocatedBlock1 = MyAlloc(memoryBlock, thirdRequestedBlockSize);

    CHECK_FUNC((long)(thirdRequestedBlockSize * (-1)) == *(long*)((char*)allocatedBlock1 - BLOCK_SIZE));

    printf("\nExpected: SUCCESS - thirdRequestedBlockSize is fine, alloc seccedded (allocatedBlock size is correct) - alloc max block size after free and add free spaces\n");

    free(memoryBlock);
}

void MyFreeTest3(void)
{
    void *memoryBlock = NULL;
    void *allocatedBlock = NULL;
    size_t memoryBlockSize = 104;
    size_t requestedBlockSize = 80;

    printf("\033[1;34m\n*******My Free Test 3:*******\n\n\033[0m");

    memoryBlock = (void*)malloc(memoryBlockSize);
    if (NULL == memoryBlock)
    {
        return;
    }

    MyMallocInit(memoryBlock, memoryBlockSize);

    printf("My Malloc Init Func Test 1: ");

    CHECK_FUNC((long)memoryBlockSize == *(long*)memoryBlock);

    printf("\nExpected: SUCCESS - First Metadata block equal to memoryBlockSize\n");

    printf("\nMy Malloc Init Func Test 2: ");

    CHECK_FUNC((long)(memoryBlockSize - BLOCK_SIZE * 3) == *(long*)((char*)memoryBlock + BLOCK_SIZE));

    printf("\nExpected: SUCCESS - Second Metadata block equal to memoryBlockSize minus BLOCK_SIZE * 3\n");

    printf("\nMy Malloc Init Func Test 3: ");

    CHECK_FUNC(0 == *(long*)((char*)memoryBlock + (memoryBlockSize - BLOCK_SIZE)));

    printf("\nExpected: SUCCESS - Last Metadata block equal to zero\n");

    printf("\nMy Alloc Func Test 1: ");

    allocatedBlock = MyAlloc(memoryBlock, requestedBlockSize);

    CHECK_FUNC((long)(requestedBlockSize * (-1)) == *(long*)((char*)allocatedBlock - BLOCK_SIZE));

    printf("\nExpected: SUCCESS - requestedBlockSize is fine, alloc seccedded (allocatedBlock size is correct)\n");

    MyFree(NULL);

    printf("\nMy Free Func Test: ");

    allocatedBlock = MyAlloc(memoryBlock, requestedBlockSize);

    CHECK_FUNC(NULL == allocatedBlock);

    printf("\nExpected: SUCCESS - memoryBlock in free is NULL, free is failed & alloc failed - memory size is full\n");

    free(memoryBlock);
}

void MyFreeTest4(void)
{
    void *memoryBlock = NULL;
    void *allocatedBlock = NULL;
    size_t memoryBlockSize = 104;
    size_t requestedBlockSize = 80;

    printf("\033[1;34m\n*******My Free Test 4:*******\n\n\033[0m");

    memoryBlock = (void*)malloc(memoryBlockSize);
    if (NULL == memoryBlock)
    {
        return;
    }

    MyMallocInit(memoryBlock, memoryBlockSize);

    printf("My Malloc Init Func Test 1: ");

    CHECK_FUNC((long)memoryBlockSize == *(long*)memoryBlock);

    printf("\nExpected: SUCCESS - First Metadata block equal to memoryBlockSize\n");

    printf("\nMy Malloc Init Func Test 2: ");

    CHECK_FUNC((long)(memoryBlockSize - BLOCK_SIZE * 3) == *(long*)((char*)memoryBlock + BLOCK_SIZE));

    printf("\nExpected: SUCCESS - Second Metadata block equal to memoryBlockSize minus BLOCK_SIZE * 3\n");

    printf("\nMy Malloc Init Func Test 3: ");

    CHECK_FUNC(0 == *(long*)((char*)memoryBlock + (memoryBlockSize - BLOCK_SIZE)));

    printf("\nExpected: SUCCESS - Last Metadata block equal to zero\n");

    printf("\nMy Alloc Func Test 1: ");

    allocatedBlock = MyAlloc(memoryBlock, requestedBlockSize);

    CHECK_FUNC((long)(requestedBlockSize * (-1)) == *(long*)((char*)allocatedBlock - BLOCK_SIZE));

    printf("\nExpected: SUCCESS - requestedBlockSize is fine, alloc seccedded (allocatedBlock size is correct)\n");

    MyFree(allocatedBlock);
    MyFree(allocatedBlock);

    printf("\nMy Free Func Test: ");

    allocatedBlock = MyAlloc(memoryBlock, requestedBlockSize);

    CHECK_FUNC((long)(requestedBlockSize * (-1)) == *(long*)((char*)allocatedBlock - BLOCK_SIZE));

    printf("\nExpected: SUCCESS - requestedBlockSize is fine, alloc seccedded (allocatedBlock size is correct) - alloc max block size after double free\n");

    free(memoryBlock);
}

int main(void)
{
    MyMallocInitTest1();
    MyMallocInitTest2();

    MyAllocTest1();
    MyAllocTest2();
    MyAllocTest3();
    MyAllocTest4();
    MyAllocTest5();
    MyAllocTest6();
    MyAllocTest7();
    MyAllocTest8();

    MyFreeTest1();
    MyFreeTest2();
    MyFreeTest3();
    MyFreeTest4();

    return 0;
}