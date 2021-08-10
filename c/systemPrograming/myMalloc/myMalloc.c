#include <stdlib.h> /* absl */
#include "myMalloc.h" /* myMalloc header */

#define BLOCK_SIZE (sizeof(long))
#define THREE_METADATA_BLOCK (3)
#define SENTINEL_VALUE (0)

/**********************************************/

static void memoryBlockSizeAlignment(size_t *_memoryBlockSize)
{
    *_memoryBlockSize  -= (*_memoryBlockSize % BLOCK_SIZE);
}

static void RequestedBlockSizeAlignment(size_t *_requestedBlockSize)
{
    *_requestedBlockSize += ((BLOCK_SIZE - (*_requestedBlockSize % BLOCK_SIZE)) % BLOCK_SIZE);
}

/**********************************************/

void MyMallocInit(void *_memoryBlock, size_t _memoryBlockSize)
{
    if (!_memoryBlock || _memoryBlockSize < (BLOCK_SIZE * 4))
    {    
        return;
    }

    memoryBlockSizeAlignment(&_memoryBlockSize);

    *(long*)_memoryBlock = _memoryBlockSize;
    *(long*)((char*)_memoryBlock + BLOCK_SIZE) = _memoryBlockSize - BLOCK_SIZE * THREE_METADATA_BLOCK;
    *(long*)((char*)_memoryBlock + (_memoryBlockSize - BLOCK_SIZE)) = SENTINEL_VALUE;
}

void *MyAlloc(void *_memoryBlock, size_t _requestedBlockSize)
{
    void *blockRunner = NULL;
    void *newMetaDataBlock = NULL;

    if (!_memoryBlock || !_requestedBlockSize)
    {
        return NULL;
    }

    RequestedBlockSizeAlignment(&_requestedBlockSize);

    if ((long)_requestedBlockSize <= *(long*)_memoryBlock)
    {
        blockRunner = ((char*)_memoryBlock + BLOCK_SIZE);

        while (SENTINEL_VALUE != *(long*)blockRunner)
        {
            if ((long)(_requestedBlockSize + BLOCK_SIZE) < *(long*)blockRunner)
            {
                newMetaDataBlock = ((char*)blockRunner + BLOCK_SIZE + _requestedBlockSize);
                *(long*)newMetaDataBlock = *(long*)blockRunner - BLOCK_SIZE - _requestedBlockSize;

                *(long*)blockRunner = _requestedBlockSize * (-1);

                return ((char*)blockRunner + BLOCK_SIZE);
            }
            else if ((long)(_requestedBlockSize) <= *(long*)blockRunner)
            {
                if ((long)(_requestedBlockSize + BLOCK_SIZE) == *(long*)blockRunner)
                {
                    _requestedBlockSize += BLOCK_SIZE;
                }

                *(long*)blockRunner = _requestedBlockSize * (-1);

                return ((char*)blockRunner + BLOCK_SIZE);
            }

            blockRunner = ((char*)blockRunner + BLOCK_SIZE + labs(*(long*)blockRunner));
        }
    }

    return NULL;
}

void MyFree(void *_allocatedBlock)
{
    void *blockToFree = NULL;
    void *nextBlock = NULL;

    if (!_allocatedBlock)
    {
        return;
    }

    blockToFree = ((char*)_allocatedBlock - BLOCK_SIZE);

    if (*(long*)blockToFree < 0)
    {
        nextBlock = ((char*)blockToFree + BLOCK_SIZE + labs(*(long*)blockToFree));

        *(long*)blockToFree *= (-1);

        if (0 < *(long*)nextBlock)
        {
            *(long*)blockToFree += BLOCK_SIZE + *(long*)nextBlock;
        }
    }
}