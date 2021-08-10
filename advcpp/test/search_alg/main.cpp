#include "mu_test.h" // MU Test Header
#include <climits> // INT_MAX
#include <vector> // std::vector
#include "search_alg.hpp" // Search Algorithms

using namespace advcpp;

#define ARR_SIZE (1000000)
#define ARR_SIZE_2 (100)

#define VECTOR_SIZE (1000000)
#define VECTOR_SIZE_2 (100)

BEGIN_TEST(IntArrFindExistElement)
    int array[ARR_SIZE];
    FillContainer(&array[0], &array[ARR_SIZE], (int)-100000, (int)1);

    size_t foundIndex = SearchAlgorithm::BinarySearchIntArray(array, ARR_SIZE, (int)1);
    ASSERT_THAT(100001 == foundIndex);
END_TEST

BEGIN_TEST(IntArrFindElementIsNotExist)
    int array[ARR_SIZE];
    FillContainer(&array[0], &array[ARR_SIZE], (int)-100000, (int)1);

    size_t foundIndex = SearchAlgorithm::BinarySearchIntArray(array, sizeof(array)/sizeof(array[0]), (int)1000000);
    ASSERT_THAT(INT_MAX == foundIndex);
END_TEST

BEGIN_TEST(IntArrIsNull)
    int *array = NULL;

    SearchAlgorithm::BinarySearchIntArray(array, sizeof(*array)/sizeof(array[0]), (int)0);
    ASSERT_FAIL("array is nullptr");
END_TEST

BEGIN_TEST(IntArrFindElementIsNotInArraySizeRange)
    int array[ARR_SIZE_2];
    FillContainer(&array[0], &array[ARR_SIZE_2], (int)0, (int)1);

    SearchAlgorithm::BinarySearchIntArray(array, ARR_SIZE_2 + 2, (int)1000000);
    ASSERT_FAIL("segmentation fault, out of array size range");
END_TEST

BEGIN_TEST(VectorFindExistElement)
    std::vector<int> m_vector (VECTOR_SIZE);
    FillContainer(m_vector.begin(), m_vector.end(), (int)-100000, (int)1);

    size_t foundIndex = BinarySearchVector(m_vector, (int)1);
    ASSERT_THAT(100001 == foundIndex);
END_TEST

BEGIN_TEST(VectorFindElementIsNotExist)
    std::vector<int> m_vector (VECTOR_SIZE);
    FillContainer(m_vector.begin(), m_vector.end(), (int)-100000, (int)1);

    size_t foundIndex = BinarySearchVector(m_vector, (int)1000000);
    ASSERT_THAT(INT_MAX == foundIndex);
END_TEST

BEGIN_SUITE(BinarySearchTests)
    TEST(IntArrFindExistElement)
    TEST(IntArrFindElementIsNotExist)
    TEST(IntArrIsNull)
    TEST(IntArrFindElementIsNotInArraySizeRange)

    TEST(VectorFindExistElement)
    TEST(VectorFindElementIsNotExist)
END_SUITE