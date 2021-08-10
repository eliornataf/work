#include "mu_test.h" // MU Test Header
#include <algorithm> // std::algorithm
#include <cstddef> // size_t
#include <vector> // std::vector
#include "min_stack.hpp" // Min Stack Header
#include "ball.hpp" // Ball Header

#define VECTOR_SIZE (5)

using namespace advcpp;

BEGIN_TEST(SimpleTestWithVector)
    MinStack<int> minStack;
    std::vector<int> vector {8, 4, 9, 12 ,1};
    
    for (size_t i = 0;i < vector.size();++i) 
    {
        minStack.Push(vector.at(i));
    }

    ASSERT_THAT(1 == minStack.Min());

    minStack.Pop();
    
    ASSERT_THAT(4 == minStack.Min());
END_TEST

BEGIN_TEST(SimpleTestWithBalls)
    std::vector<Ball> ballVector;
    ballVector.reserve(VECTOR_SIZE);

    std::vector<Ball::Color> colorsVector {Ball::BLACK, Ball::BLUE, Ball::RED, Ball::RED ,Ball::WHITE};
    std::vector<unsigned int> radiosVector {8, 4, 9, 12 ,1};

    for (size_t i = 0;i < ballVector.capacity();++i) 
    {
        ballVector.push_back(Ball(colorsVector.at(i), radiosVector.at(i)));
    }

    MinStack<Ball> minStack;

    for (size_t i = 0;i < ballVector.size();++i) 
    {
        minStack.Push(ballVector.at(i));
    }

    ASSERT_THAT(static_cast<unsigned int>(1) == minStack.Min().GetRadius());

    minStack.Pop();

    ASSERT_THAT(static_cast<unsigned int>(4) == minStack.Min().GetRadius());
END_TEST

BEGIN_SUITE(minStackTest)
    TEST(SimpleTestWithVector)
    TEST(SimpleTestWithBalls)
END_SUITE