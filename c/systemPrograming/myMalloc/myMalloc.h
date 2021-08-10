/*****************************************************************************
* File Name: myMalloc - ADT
* Written by: Elior Nataf
* Date: 13/4/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __MY_ALLOC_H__
#define __MY_ALLOC_H__

/*------------------------------- Header Files ------------------------------*/

#include <stddef.h> /* size_t */

/*---------------------------------- Typedef --------------------------------*/

/*------------------------------- Enum & Define -----------------------------*/

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that initialize a variable size allocation system. Memory pool will
 * be available for allocation. In case the pointer is poiting to an invalid address,
 * behavior will be undefined. 
 *
 * Time Complexity: O(1).
 * 
 * Input:
 * memoryBlock - pointer to beginning of memory block to by managed.
 * memoryBlockSize - total size of memory block to be managed.
 * 
 * Output:
 * None.
 *
 * Error: 
 * memoryBlock is null, init is not possible.  
 * memoryBlockSize invalid input (memoryBlockSize < (BLOCK_SIZE * 4),
 * init is not possible.
 */
void MyMallocInit(void *memoryBlock, size_t memoryBlockSize);

/* Description:
 * A function that allocates a variable size block from memoryBlock. In case 
 * the pointer is poiting to an invalid address, behavior will be undefined. In
 * case requestedBlockSize + BLOCK_SIZE == leftBlockSpace, BLOCK_SIZE will
 * add to requestedBlockSize to manage the memoryBlock efficient.
 *
 * Time Complexity: O(n).
 * 
 * Input:
 * memoryBlock - pointer to beginning of memory block to by managed.
 * requestedBlockSize - size of requested memory block for allocation.
 * 
 * Output:
 * NULL - memoryBlock is null, alloc is not possible.
 * NULL - requestedBlockSize invalid input (!requestedBlockSize), alloc 
 * is not possible.
 * NULL - in case their is no free space to allocate.
 * pointer to fixed size allocated memory.
 *
 * Error: 
 * NULL - memoryBlock is null, alloc is not possible.
 * NULL - requestedBlockSize invalid input (!requestedBlockSize), alloc 
 * is not possible.
 * NULL - in case their is no free space to allocate.
 */
void *MyAlloc(void *memoryBlock, size_t requestedBlockSize);

/* Description:
 * A function that free allocated memory from variable size memory block. In case 
 * the pointer is poiting to an invalid address, behavior will be undefined. In case
 * free function found the next block (from allocatedBlock) is also free, and if 
 * allocatedBlock pointer is fine, the two free blocks (allocatedBlock + next 
 * free block) will be one free space.
 *
 * Time Complexity: O(1).
 * 
 * Input:
 * allocatedBlock - pointer to beginning of memory block to by freed.
 * 
 * Output:
 * None.
 *
 * Error: 
 * NULL - allocatedBlock is null, free is not possible.
 */
void MyFree(void *allocatedBlock);

#endif /* __MY_ALLOC_H__ */
