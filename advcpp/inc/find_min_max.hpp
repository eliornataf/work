#ifndef FIND_MIN_MAX_CONTAINER_HPP
#define FIND_MIN_MAX_CONTAINER_HPP

namespace advcpp {
// Time Complexity: O(3/2n)
// Space Complexity: O(1)
// Requires: operator<, operator*, operator==
template <typename C>
bool FindMinMaxInContainer(C &a_container, typename C::value_type &a_minValue, typename C::value_type &a_maxValue);

// Time Complexity: O(3/2n)
// Space Complexity: O(1)
// Requires: operator<, operator*, operator==
template <typename FwdIter>
bool FindMinMaxInContainerIter(FwdIter a_beginIter, FwdIter a_endIter, typename FwdIter::value_type &a_minValue, typename FwdIter::value_type &a_maxValue);

#include "inl/find_min_max.hxx" // Find Min Max Inline

} // advcpp

#endif // FIND_MIN_MAX_CONTAINER_HPP
