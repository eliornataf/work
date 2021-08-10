#ifndef SEARCH_ALGORITHM_HPP
#define SEARCH_ALGORITHM_HPP

#include <climits> // INT_MAX
#include <cstddef> // size_t
#include <vector> // std::vector

namespace advcpp {

struct SearchAlgorithm {
public:
    // Methods

// Time Complexity: O(logn)
// Space Complexity: O(1)
// Requires: operator[], operator <
    static size_t BinarySearchIntArray(const int *a_array, const size_t a_arraySize, const int a_numberToSearch);

// Time Complexity: O(logn)
// Space Complexity: O(1)
// Requires: operator[], operator <
    template<typename T>
    size_t BinarySearchVector(const std::vector<T> &a_vector, const T &a_itemToFind);

// Time Complexity: O(logn)
// Space Complexity: O(1)
// Requires: operator[]
    template<typename FwdIter, typename T, typename U>
    void FillContainer(FwdIter a_startIter, FwdIter a_endIter, T a_startValue, U a_incrementValue);

    // Conatants

    static const int ITEM_NOT_FOUND = INT_MAX;
};

#include "inl/search_alg.hxx" // Search Algoritm Inline

} // advcpp

#endif /* SEARCH_ALGORITHM_HPP */
