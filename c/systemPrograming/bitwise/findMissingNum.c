#include <stdio.h> /* printf */

#define ARR_SIZE (9)

int FindMissingNumPairs(int *_arr, size_t _arrSize)
{
    int missingNum = _arr[0];
    size_t i;

    for (i = 1;i < _arrSize;++i)
    {
        missingNum ^= _arr[i];
    }

    return missingNum;
}

int FindMissingNumThrees(int *_arr, size_t _arrSize)
{
    int missingNum = _arr[0];
    size_t i;

    for (i = 1;i < _arrSize;++i)
    {
        missingNum ^= _arr[i];
    }

    return missingNum;
}

int main(void)
{
    int pairsArr[] = {1, 3, 7, 7, 3, 1, 4, 2, 2, 9, 4, 4, 8, 9, 8};
    size_t parisArrSize = sizeof(pairsArr) / sizeof(pairsArr[0]);

    int threesArr[] = {8, 3, 8, 8, 7, 7, 7, 3, 1, 5, 5, 3, 5, 9, 6, 6, 9, 9};
    size_t threesArrSize = sizeof(threesArr) / sizeof(threesArr[0]);

    printf("Pairs missing number is: %d\n", FindMissingNumPairs(pairsArr, parisArrSize));

    printf("Threes missing number is: %d\n", FindMissingNumThrees(threesArr, threesArrSize));

    return 0;
}