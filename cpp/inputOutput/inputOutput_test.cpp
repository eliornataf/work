#include <cstdio> /* printf */
#include <iostream> /* throw */
#include "endLine.hpp" /* EndLine Header */
#include "input.hpp" /* Input Header */
#include "output.hpp" /* Output Header */

#define STR_LENGTH (4096)

/*******************************************/

EndLine endl;
Input cin;
Output cout;
Output::LetterCase normal = Output::LetterCase::NORMAL;
Output::LetterCase lower = Output::LetterCase::LOWER;
Output::LetterCase upper = Output::LetterCase::UPPER;

/*******************************************/

void OutputTest() {
    printf("\033[1;34mOutput Test:\n\n\033[0m");

    try {
        // char *
        
        cout << "abcde";
        printf("\nExpected: will print 'abcde' to stdout without a newline\n\n");

        // char

        cout << 'h' << 'e' << 'y' << endl;
        printf("Expected: will print 'hey' to stdout with a new line\n\n");

        // int

        cout << 389;
        printf("\nExpected: will print '389' to stdout without a new line\n\n");

        // long

        cout << 389888888888888; 
        printf("\nExpected: will print '389888888888888' to stdout without a new line\n\n");

        // EndLine

        cout << endl;
        printf("Expected: will print a new line to stdout\n\n");

        // double && EndLine

        cout << 2.17878 << endl;
        printf("Expected: will print '2.17878' and a new line to stdout\n\n");

        // LetterCase

        cout << upper << "abc" << normal << "def" << upper << "g" << lower << "H" << normal << "iGk" << endl;
        printf("Expected: will print 'ABCdefGhiGk' and a new line to stdout\n");
    }
    catch(const std::exception &ex) {
        std::cout << std::endl << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
    }  
}

void InputTest() {
    printf("\033[1;34m\nInput Test:\n\n\033[0m");
    try {
        char str[STR_LENGTH];
        char a, b, c;
        double d;
        int i;
        long j;

        // char *

        cin >> str;
        printf("Print Str: %s\n", str);
        printf("Expected: will get string from stdin\n\n");

        // char

        cin >> a >> b >> c >> endl;
        printf("Print chars: %c, %c, %c\n", a, b, c);
        printf("Expected: will get characters from stdin\n\n");

        // int

        cin >> i;
        printf("Print int: %d\n", i);
        printf("Expected: will get int from stdin without a newline\n\n");

        // long

        cin >> j;
        printf("Print long: %li\n", j);
        printf("Expected: will get long from stdin without a newline\n\n");

        // double && More

        cin >> a >> d >> endl >> j;  
        printf("Print multi: %c, %lf, %li", a, d, j);
        printf("Expected: will get multi types from stdin without a newline\n\n");
    }
    catch(const std::exception &ex) {
        std::cout << std::endl << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
    }  
}

int main() {
    OutputTest();
    InputTest();

    return 0;
}