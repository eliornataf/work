#include <cstdio> /* printf */
#include <iostream> /* cout */
#include <math.h> /* sqrt */
#include "point.hpp" /* Point Header */

#define TEST1_LEGNTH_ANSWER (5)
#define TEST1_DISTANCE_ANSWER (0)

#define TEST2_LEGNTH_ANSWER (sqrt(58))
#define TEST2_DISTANCE_ANSWER (sqrt(17))

#define TEST3_LEGNTH_ANSWER (0)
#define TEST3_DISTANCE_ANSWER (5)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

/*************************************/

void Part1(void) {
    std::cout << std::endl << "\033[1;34m" << "Part 1 Test:" << "\033[0m" << std::endl;

    try
    {
        Point p1(3, 4);
        Point p2(3, 4);

        std::cout << "\nLength Test: ";
        CHECK_FUNC(TEST1_LEGNTH_ANSWER == p1.Length());

        std::cout << "\nDistanceTo Test: ";
        CHECK_FUNC(TEST1_DISTANCE_ANSWER == p1.DistanceTo(&p2));
    }
    catch(const std::exception &ex)
    {
        std::cout << std::endl << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
    }  
}

void Part2(void) {
    std::cout << std::endl << "\033[1;34m" << "Part 2 Test:" << "\033[0m" << std::endl << std::endl;

    try
    {
        Point p1(3, 7);
        Point p2(4, 3);

        std::cout << "Length Test: ";
        CHECK_FUNC(TEST2_LEGNTH_ANSWER == p1.Length());

        std::cout << "\nPrint Test: ";
        p1.Print();

        std::cout << "\n\nDistanceTo Test: ";
        CHECK_FUNC(TEST2_DISTANCE_ANSWER == p1.DistanceTo(&p2));

        Point p3 = p1.operator+(p2);
        std::cout << "\nOperator+ & Print Test: ";
        p3.Print();

        Point p4 = p1.operator-(p2);
        std::cout << "\n\nOperator- & Print Test: ";
        p4.Print();
    }
    catch(const std::exception &ex)
    {
        std::cout << std::endl << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
    }  
}

void Part3(void) {
    std::cout << std::endl << std::endl << "\033[1;34m" << "Part 3 Test:" << "\033[0m" << std::endl << std::endl;

    try
    {
        Point p1;
        Point p2(4, 3);

        std::cout << "Length Test: ";
        CHECK_FUNC(TEST3_LEGNTH_ANSWER == p1.Length());

        std::cout << "\nPrint Test: ";
        p1.Print();

        std::cout << "\n\nDistanceTo Test: ";
        CHECK_FUNC(TEST3_DISTANCE_ANSWER == p1.DistanceTo(&p2));
    }
    catch(const std::exception &ex)
    {
        std::cout << std::endl << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
    }  
}

void Part4(void) {
    std::cout << std::endl << "\033[1;34m" << "Part 4 Test:" << "\033[0m" << std::endl << std::endl;
    
    try
    {
        Point p1(3, 7);
        p1.Move(2, 8);
        Point p2(5, 15);
        std::cout << "Move & Length Test: ";
        CHECK_FUNC(p1.Length() == p2.Length());

        Point p3 = p1.operator*(1.5);
        Point p4(7.5, 22.5);
        std::cout << "\nOperator* & Length Test: ";
        CHECK_FUNC(p3.Length() == p4.Length());

        p1.operator*=(1.5);
        std::cout << "\nOperator*= & Length Test: ";
        CHECK_FUNC(p1.Length() == p4.Length());
    }
    catch(const std::exception &ex)
    {
        std::cout << std::endl << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
    }  
}

void InvalidStringArguments(void)
{
    std::cout << std::endl << "\033[1;34m" << "Invalid String Arguments Test 1:" << "\033[0m" << std::endl;

    try
    {
        Point p1(3, 4);
        Point p2(3, 4);

        std::cout << "\nDistanceTo Test: ";
        CHECK_FUNC(TEST1_DISTANCE_ANSWER == p1.DistanceTo(NULL));
    }
    catch(const std::exception &ex)
    {
        std::cout << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
    }  
}

void PrintTest(void)
{
    std::cout << std::endl << "\033[1;34m" << "Print Test:" << "\033[0m" << std::endl;

    try {
        Point p1(4, 5);
        Point p2(6, 7, "str2");

        std::cout << "\nPrint Test 1 - No argument print:";
        std::cout << "\np1-> ";
        p1.Print();
        std::cout << "\np2-> ";
        p2.Print();

        std::cout << "\n\nPrint Test 2 - With a_prefix argument:";
        std::cout << "\np1-> ";
        p1.Print('a');
        std::cout << "\np2-> ";
        p2.Print('a');

        std::cout << "\n\nPrint Test 3 - With a_numOfTimes argument:";
        std::cout << "\np1-> ";
        p1.Print((size_t)3);
        std::cout << "\np2-> ";
        p2.Print((size_t)3);

        std::cout << "\n\nPrint Test 4 - With a_prefix & a_numOfTimes argument:";
        std::cout << "\np1-> ";
        p1.Print('c', 3);
        std::cout << "\np2-> ";
        p2.Print('c', 3);
    }
    catch(const std::exception &ex)
    {
        std::cout << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
    }  
}

void CopyTest(void)
{
    std::cout << std::endl << std::endl << "\033[1;34m" << "Copy Test:" << "\033[0m" << std::endl;

    try {
        Point p1(4, 5, "str1");
        Point p2 = p1;
        std::cout << "\nCopy with copy constructor Test:\n";
        p2.Print();
    }
    catch(const std::exception &ex)
    {
        std::cout << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
    }  
}

void AssignmentTest(void)
{
    std::cout << std::endl << std::endl << "\033[1;34m" << "Assignment Test:" << "\033[0m" << std::endl;

    try {
        Point p1(4, 5, "str1");
        Point p2(5, 6, "str2");
        p2 = p1;
        std::cout << "\nAssignment with assignment operator Test:\n";
        p2.Print();
    }
    catch(const std::exception &ex)
    {
        std::cout << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
    }  
}


int main(void) {
    
    Part1();
    Part2();
    Part3();
    Part4();

    InvalidStringArguments();

    PrintTest();
    CopyTest();
    AssignmentTest();

    return 0;
}