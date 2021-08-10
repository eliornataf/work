#ifndef __SEARCH_ALGORITHM_INLINE_HPP__
#define __SEARCH_ALGORITHM_INLINE_HPP__

template<typename C, typename T>
size_t BinarySearch(const C &a_container, const size_t a_containerSize, const T &a_itemToFind)
{
    size_t leftIndex = 0;
    size_t rightIndex = a_containerSize - 1;

    while (leftIndex <= rightIndex)
    {
        size_t middleIndex =  leftIndex + (rightIndex - leftIndex) / 2;

        if (a_container[middleIndex] == a_itemToFind) 
        {
            return middleIndex;
        }
        else if (a_container[middleIndex] < a_itemToFind) 
        {
            leftIndex = middleIndex + 1;
        }
        else 
        {
            rightIndex = middleIndex -1;
        }
    }

    return SearchAlgorithm::ITEM_NOT_FOUND;
}

template<typename T>
size_t BinarySearchVector(const std::vector<T> &a_vector, const T &a_itemToFind) 
{
    return BinarySearch<std::vector<T>, T>(a_vector, a_vector.size(), a_itemToFind);
}

template<typename FwdIter, typename T, typename U>
void FillContainer(FwdIter a_startIter, FwdIter a_endIter, T a_startValue, U a_incrementValue) 
{
    while (a_startIter != a_endIter) 
    {
        *a_startIter = a_startValue;
        a_startValue += a_incrementValue;
        a_startIter++;
    }
}


#endif // SEARCH_ALGORITHM_INLINE_HPP