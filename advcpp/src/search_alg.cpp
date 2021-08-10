#include <stddef.h> // size_t
#include <stdexcept> // std::runtime_error
#include "search_alg.hpp" // Search Algorithm Header

using namespace advcpp;

size_t SearchAlgorithm::BinarySearchIntArray(const int *a_array, const size_t a_arraySize, const int a_numberToSearch)
{
    if (!a_array) 
    {
        throw std::runtime_error("array is null");
    }

    return BinarySearch(a_array, a_arraySize, a_numberToSearch);
}