#include "mu_test.h" // MU Test Header
#include <cassert> // assert
#include <functional> // std::function
#include <iostream> // std::cout
#include <list> // std::list
#include <numeric> // std:accumulate
#include <vector> // std::vector

template <typename C, typename T>
T calculateAccumulateMountain(const C &a_container, const T a_width)
{
    static_assert(std::is_arithmetic<T>::value, "T is not arithmetic");

    auto mountainLambda = [](const T a_totalArea, const T a_currentHeight) {
        return a_totalArea + abs(a_currentHeight);
    };

    return std::accumulate(a_container.begin(), a_container.end(), T(), mountainLambda) * a_width;
}

double RiemannSum(const double a_leftBound, const double a_rightBound, const size_t a_numberOfSlices, const std::function<double(double)> &a_func)
{
    assert(0 != a_numberOfSlices);

    double delta = (a_rightBound - a_leftBound) / a_numberOfSlices;
    double totalArea = 0.0;
    double leftRiemannSum = a_leftBound;

    for (size_t i = 0;i < a_numberOfSlices;++i)
    {
        totalArea += a_func(a_leftBound);
        leftRiemannSum += delta;
    }

    return totalArea * delta;
}

BEGIN_TEST(SimpleMountainVectorIntTest)
    std::vector<int> mountainVectorInt{3, 6, 8, 12, 5, 1, 7};

    ASSERT_THAT(42 == calculateAccumulateMountain(mountainVectorInt, 1));
END_TEST

BEGIN_TEST(SimpleMountainVectornDoubleTest)
    std::vector<double> mountainVectorDouble{3.2, 7.1, 8.1, 12.2, 2.4, 1.1, 7.0};

    ASSERT_THAT(41.1 == calculateAccumulateMountain(mountainVectorDouble, 1.0));
END_TEST

BEGIN_TEST(SimpleMountainListIntTest)
    std::list<int> mountainVectorInt{3, 6, 8, 12, 5, 1, 7};

    ASSERT_THAT(42 == calculateAccumulateMountain(mountainVectorInt, 1));
END_TEST

BEGIN_TEST(SimpleMountainListDoubleTest)
    std::vector<double> mountainVectorDouble{3.2, 7.1, 8.1, 12.2, 2.4, 1.1, 7.0};

    ASSERT_THAT(41.1 == calculateAccumulateMountain(mountainVectorDouble, 1.0));
END_TEST

BEGIN_TEST(RiemannSumTest)
    std::cout << "Riemann sum is " << RiemannSum(1.9, 5.7, 15000, [](double x){return x*x;}) << std::endl;

    ASSERT_PASS();
END_TEST

BEGIN_SUITE(MountainTest)
    TEST(SimpleMountainVectorIntTest)
    TEST(SimpleMountainVectornDoubleTest)
    TEST(SimpleMountainListIntTest)
    TEST(SimpleMountainListDoubleTest)
    TEST(RiemannSumTest)
END_SUITE