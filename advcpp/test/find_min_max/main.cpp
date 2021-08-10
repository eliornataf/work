#include "mu_test.h" // MU Test Header
#include <vector> // std::vector
#include "find_min_max.hpp" // Find Min Max Header

#define VECTOR_SIZE (1000000)

using namespace advcpp;

BEGIN_TEST(SimpleTestWithInts)
    std::vector<int> vector {6, 4, 2, 7, 1, 8};
    int minElement {};
    int maxElement {};

    bool result = FindMinMaxInContainer(vector, minElement, maxElement);
    ASSERT_THAT(true == result);
    ASSERT_THAT(1 == minElement);
    ASSERT_THAT(8 == maxElement);
END_TEST

BEGIN_TEST(SimpleTestWithDoubles)
    std::vector<double> vector {6.2, 8.9, 11.3, 5.9, 2.2, 3.2, 7.8};
    double minElement {};
    double maxElement {};

    bool result = FindMinMaxInContainer(vector, minElement, maxElement);
    ASSERT_THAT(true == result);
    ASSERT_THAT(2.2 == minElement);
    ASSERT_THAT(11.3 == maxElement);
END_TEST

BEGIN_TEST(VectorIsEmpty)
    std::vector<int> vector {};
    int minElement {};
    int maxElement {};

    bool result = FindMinMaxInContainer(vector, minElement, maxElement);
    ASSERT_THAT(false == result);
END_TEST

BEGIN_TEST(OneMillinVectorElementsLong)
    std::vector<long> vector;
    vector.reserve(VECTOR_SIZE);

    for (size_t i = 0, j = 0;i < VECTOR_SIZE;++i, j += 2)
    {
        vector.push_back(j);
    }

    long minElement {};
    long maxElement {};

    bool result = FindMinMaxInContainer(vector, minElement, maxElement);
    ASSERT_THAT(true == result);
    ASSERT_THAT(0 == minElement);
    ASSERT_THAT((VECTOR_SIZE * 2 - 2) == maxElement);
END_TEST

BEGIN_SUITE(FindMinMaxTests)
    TEST(SimpleTestWithInts)
    TEST(SimpleTestWithDoubles)
    TEST(VectorIsEmpty)
    TEST(OneMillinVectorElementsLong)
END_SUITE
