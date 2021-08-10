#include <cstdio> /* printf */
#include <iostream> /* cout */
#include "string.hpp" /* String Header */

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

/*************************************/

void ValidStringArguments(void) {
    std::cout << std::endl << "\033[1;34m" << "Valid String Arguments Test:" << "\033[0m" << std::endl;
    
    try {
        String str1("hello");

        std::cout << std::endl << "Print str1: ";
        str1.Print();

        const String *str2 = new String("world");

        std::cout << std::endl << "Print str2: ";
        str2->Print();

        str1.operator+=(str2);
        std::cout << std::endl << "Print str1 after str2 concat: ";
        str1.Print();
        std::cout << std::endl << "Print str2 after concat: ";
        str2->Print();

        str1.operator+=(str2);
        std::cout << std::endl << "Print str1 after another str2 concat: ";
        str1.Print();

        String str3(" ");
        str1.operator+=(&str3);
        str1.operator+=(&str1);
        std::cout << std::endl << "Print str3 + str1 after str1 concat: ";
        str1.Print();

        delete str2;
    }
    catch(const std::exception &ex) {
        std::cout << std::endl << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
    }  
}

void InvalidStringArguments1(void) {
    std::cout << std::endl << "\033[1;34m" << "Invalid String Arguments Test 1:" << "\033[0m" << std::endl;
    
    const String *str2 = NULL;

    try {
        String str1(NULL);

        std::cout << std::endl << "Print str1: ";
        str1.Print();

        str2 = new String("world");

        std::cout << std::endl << "Print str2: ";
        str2->Print();

        str1.operator+=(str2);
        std::cout << std::endl << "Print str1 after str2 concat: ";
        str1.Print();
        std::cout << std::endl << "Print str2 after concat: ";
        str2->Print();

        str1.operator+=(str2);
        std::cout << std::endl << "Print str1 after another str2 concat: ";
        str1.Print();

        String str3(" ");
        str1.operator+=(&str3);
        str1.operator+=(&str1);
        std::cout << std::endl << "Print str3 + str1 after str1 concat: ";
        str1.Print();
    }
    catch(const std::exception &ex) {
        std::cout << std::endl << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
        delete str2;
    }  
}

void InvalidStringArguments2(void) {
    std::cout << std::endl << "\033[1;34m" << "Invalid String Arguments Test 2:" << "\033[0m" << std::endl;
    
    const String *str2 = NULL;

    try {    
        String str1("hello");

        std::cout << std::endl << "Print str1: ";
        str1.Print();

        str2 = new String(NULL);

        std::cout << std::endl << "Print str2: ";
        str2->Print();

        str1.operator+=(str2);
        std::cout << std::endl << "Print str1 after str2 concat: ";
        str1.Print();
        std::cout << std::endl << "Print str2 after concat: ";
        str2->Print();

        str1.operator+=(str2);
        std::cout << std::endl << "Print str1 after another str2 concat: ";
        str1.Print();

        String str3(" ");
        str1.operator+=(&str3);
        str1.operator+=(&str1);
        std::cout << std::endl << "Print str3 + str1 after str1 concat: ";
        str1.Print();

        delete str2;
    }
    catch(const std::exception &ex) {
        std::cout << std::endl << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
        delete str2;
    }  
}

void InvalidStringArguments3(void) {
    std::cout << std::endl << "\033[1;34m" << "Invalid String Arguments Test 3:" << "\033[0m" << std::endl;

    const String *str2 = NULL;

    try {    
        String str1("hello");

        std::cout << std::endl << "Print str1: ";
        str1.Print();

        str2 = new String("world");

        std::cout << std::endl << "Print str2: ";
        str2->Print();

        str1.operator+=(NULL);
        std::cout << std::endl << "Print str1 after str2 concat: ";
        str1.Print();
        std::cout << std::endl << "Print str2 after concat: ";
        str2->Print();

        str1.operator+=(str2);
        std::cout << std::endl << "Print str1 after another str2 concat: ";
        str1.Print();

        String str3(" ");
        str1.operator+=(&str3);
        str1.operator+=(&str1);
        std::cout << std::endl << "Print str3 + str1 after str1 concat: ";
        str1.Print();

        delete str2;
    }
    catch(const std::exception &ex) {
        std::cout << std::endl << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
        delete str2;
    }  
}

int main(void) {
    
    ValidStringArguments();

    InvalidStringArguments1();
    InvalidStringArguments2();
    InvalidStringArguments3();

    return 0;
}