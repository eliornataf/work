#include <stdlib.h> /* malloc, free */
#include <string.h> /* memcpy */
#include "genericBubbleSort.h" /* Generic Bubble Sort Header */

#define ONE_ELEMENT (1)

#define IS_NOT_SORTED (0)
#define IS_SORTED (1)

#define ELEMENT_OFFSET(arr, elementIndex, elementSize) (((char*)arr) + ((elementIndex)*(elementSize)))

/*****************************************************************************************/

static void SwapElements(void *_buffer, void *_arr, size_t _elementSize, size_t _elementIndex)
{
	memcpy(_buffer, ELEMENT_OFFSET(_arr, _elementIndex, _elementSize), _elementSize);
	memcpy(ELEMENT_OFFSET(_arr, _elementIndex, _elementSize), ELEMENT_OFFSET(_arr, _elementIndex + 1, _elementSize), _elementSize);
    memcpy(ELEMENT_OFFSET(_arr, _elementIndex + 1, _elementSize), _buffer, _elementSize);
}

/*****************************************************************************************/

int GenericBubbleSort(void *_arr, size_t _arrSize, size_t _elementSize, sortCriteria_t _sortCriteria)
{
    int arrIsSorted = IS_NOT_SORTED;
    void *buffer = NULL;
    size_t i, j;

    if ( (NULL == _arr) || (_arrSize < 2) || (!_elementSize) || (NULL == _sortCriteria) ) 
    {
        return FAILURE;
    }

    buffer = malloc(ONE_ELEMENT * _elementSize);
    if (NULL == buffer)
    {
        return FAILURE;
    }

	for (i = 0;i < _arrSize - 1 && IS_SORTED != arrIsSorted;++i)
    {
        int arrIsSorted = IS_SORTED;

        for (j = 0;j < _arrSize - 1 - i;++j)
        {
            if ( (*_sortCriteria)(ELEMENT_OFFSET(_arr, j, _elementSize), ELEMENT_OFFSET(_arr, j + 1, _elementSize) ) )
            {
                SwapElements(buffer, _arr, _elementSize, j);

                arrIsSorted = IS_NOT_SORTED;
            }
        }
    }

    free(buffer);

    return SUCCESS;
}
