#include <cstdio> /* printf */
#include <iostream> /* cout */
#include "stringPart2.hpp" /* String Part 2 Header */

#define DUMMY_NUM (4)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

/*************************************/

void StringPart2Test(void) {
    std::cout << std::endl << "\033[1;34m" << "String Test Part 2:" << "\033[0m" << std::endl;
    
    try {
        StringPart2 str1("hello");

        std::cout << std::endl << "Print str1: ";
        str1.Print();

        StringPart2 str2("bOoM");
        std::cout << std::endl << "Print str2: ";
        str2.Print();

        std::cout << std::endl << "Str1 & str2 with operator==: ";
        CHECK_FUNC(str1.operator==(str2));
        std::cout << "Expected: FAILURE (operator check) - is not equal\n";

        std::cout << std::endl << "Str1 & str2 with operator!=: ";
        CHECK_FUNC(str1.operator!=(str2));
        std::cout << "Expected: SUCCESS (operator check) - is not equal\n";

        std::cout << std::endl << "Str1 & str2 with operator>: ";
        CHECK_FUNC(str1.operator>(str2));
        std::cout << "Expected: SUCCESS (operator check) - str1 is bigger\n";

        std::cout << std::endl << "Str1 & str2 with operator<: ";
        CHECK_FUNC(str1.operator<(str2));
        std::cout << "Expected: FAILURE (operator check) - str2 is smaller\n";

        std::cout << std::endl << "Str1 & str2 with operator>=: ";
        CHECK_FUNC(str1.operator>=(str2));
        std::cout << "Expected: SUCCESS (operator check) - st1 is bigger\n";

        std::cout << std::endl << "Str1 & str2 with operator<=: ";
        CHECK_FUNC(str1.operator<=(str2));
        std::cout << "Expected: FAILURE (operator check) - str2 is smaller\n";

        StringPart2 str3 = str1.operator+(str2);
        std::cout << std::endl << "Print str3 && operator+: ";
        str3.Print();

        StringPart2 str4("oM");
        std::cout << std::endl << "Print str4: ";
        str4.Print();

        StringPart2 str5 = str2.operator-(str4);
        std::cout << std::endl << "Print str5 && operator-: ";
        str5.Print();

        str1.operator+=("world");
        std::cout << std::endl << "Print st1 && operator+=: ";
        str1.Print();

        str1.operator++();
        std::cout << std::endl << "Print st1 && operator++: ";
        str1.Print();

        str1.operator++();
        std::cout << std::endl << "Print st1 && operator++: ";
        str1.Print();

        str1.operator++(DUMMY_NUM);
        std::cout << std::endl << "Print st1 && operator++: ";
        str1.Print();

        StringPart2 str6 = str3.operator<<(3);
        std::cout << std::endl << "Print st6 && operator<<: ";
        str6.Print();

        StringPart2 str7 = str3.operator>>(2);
        std::cout << std::endl << "Print st7 && operator>>: ";
        str7.Print();

        char ch = str2.operator[](3);
        std::cout << std::endl << "Print ch: " << ch << std::endl;
        
        StringPart2 str8 = str1.operator+();
        std::cout << std::endl << "Print str8 && operator+: ";
        str8.Print();

        StringPart2 str9 = str2.operator-();
        std::cout << std::endl << "Print str9 && operator-: ";
        str9.Print();

        StringPart2 str10 = str2.operator!();
        std::cout << std::endl << "Print str10 && operator!: ";
        str10.Print();
    }
    catch(const std::exception &ex) {
        std::cout << std::endl << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
    }  
}

int main() {
    StringPart2Test();

    return 0;
}