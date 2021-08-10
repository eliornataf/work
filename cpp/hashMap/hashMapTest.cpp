#include <iostream> /* std::cout, std::endl */
#include <string> /* std::string */
#include "hashMap.hpp" /* Hash Map Header */
#include "containerUtilites.hpp" /* Container Utilites Header */
#include "typesUtilites.hpp" /* Types Utitlies Header */

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

void InsertTest() {
    std::cout << "\033[1;34m" << "Insert Test:" << "\033[0m" << std::endl;

    try {
        HashMap newHashMap(10, HashFunc());
        valueType newBookNum1("Harry Potter", "J. K. Rowling", 1999, "12/01/2012");
        valueType newBookNum2("Lord Of The Rings", "J. R. R. Tolkien", 2011, "11/03/2016");
        valueType newBookNum3("Harry Potter", "J. K. Rowling", 1999, "12/01/2012");

        std::cout << std::endl << "Insert Test 1: ";
        CHECK_FUNC(HashMap::SUCCEEDED == newHashMap.Insert(keyType("randomKey"), newBookNum1));
        std::cout << "Expected: SUCCESS (status check)" << std::endl;

        std::cout << std::endl << "Insert Test 2: ";
        CHECK_FUNC(HashMap::SUCCEEDED == newHashMap.Insert(keyType("randomKey2"), newBookNum2));
        std::cout << "Expected: SUCCESS (status check)" << std::endl;

        std::cout << std::endl << "Insert Test 3: ";
        CHECK_FUNC(HashMap::FAILED == newHashMap.Insert(keyType("randomKey"), newBookNum3));
        std::cout << "Expected: SUCCESS (status check) - insert with exist key" << std::endl;

        std::cout << std::endl << "Insert Test 4: ";
        CHECK_FUNC(HashMap::SUCCEEDED == newHashMap.Insert(keyType("randomKey3"), newBookNum1));
        std::cout << "Expected: SUCCESS (status check)" << std::endl;
    }
    catch(const std::exception &ex) {
        std::cout << std::endl << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
    }  
}

void RemoveTest() {
    std::cout << std::endl << "\033[1;34m" << "Remove Test:" << "\033[0m" << std::endl;

    try {
        HashMap newHashMap(10, HashFunc());
        valueType newBookNum1("Harry Potter", "J. K. Rowling", 1999, "12/01/2012");
        valueType newBookNum2("Lord Of The Rings", "J. R. R. Tolkien", 2011, "11/03/2016");
        valueType newBookNum3("The Adventures of Sherlock Holmes", "Arthur Conan Doyle", 1970, "10/05/1991");

        std::cout << std::endl << "Insert Test 1: ";
        CHECK_FUNC(HashMap::SUCCEEDED == newHashMap.Insert(keyType("randomKey"), newBookNum1));
        std::cout << "Expected: SUCCESS (status check)" << std::endl;

        std::cout << std::endl << "Insert Test 2: ";
        CHECK_FUNC(HashMap::SUCCEEDED == newHashMap.Insert(keyType("randomKey2"), newBookNum2));
        std::cout << "Expected: SUCCESS (status check)" << std::endl;

        std::cout << std::endl << "Remove Test 1: ";
        CHECK_FUNC(HashMap::SUCCEEDED == newHashMap.Remove(keyType("randomKey2")));
        std::cout << "Expected: SUCCESS (status check)" << std::endl;

        std::cout << std::endl << "Remove Test 2: ";
        CHECK_FUNC(HashMap::FAILED == newHashMap.Remove(keyType("randomKey2")));
        std::cout << "Expected: SUCCESS (status check) - already free" << std::endl;

        std::cout << std::endl << "Remove Test 3: ";
        CHECK_FUNC(HashMap::FAILED == newHashMap.Remove(keyType("randomKey3")));
        std::cout << "Expected: SUCCESS (status check) - key not found" << std::endl;
    }
    catch(const std::exception &ex) {
        std::cout << std::endl << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
    }  
}
    
void FindTest() {
    std::cout << std::endl << "\033[1;34m" << "Find Test:" << "\033[0m" << std::endl;

    try {
        HashMap newHashMap(10, HashFunc());
        valueType newBookNum1("Harry Potter", "J. K. Rowling", 1999, "12/01/2012");
        valueType newBookNum2("Lord Of The Rings", "J. R. R. Tolkien", 2011, "11/03/2016");

        std::cout << std::endl << "Insert Test 1: ";
        CHECK_FUNC(HashMap::SUCCEEDED == newHashMap.Insert(keyType("randomKey"), newBookNum1));
        std::cout << "Expected: SUCCESS (status check)" << std::endl;

        std::cout << std::endl << "Insert Test 2: ";
        CHECK_FUNC(HashMap::SUCCEEDED == newHashMap.Insert(keyType("randomKey2"), newBookNum2));
        std::cout << "Expected: SUCCESS (status check)" << std::endl;

        std::cout << std::endl << "Find Test 1: ";
        CHECK_FUNC(keyType(newBookNum2.GetName()) == keyType(newHashMap.Find(keyType("randomKey2"))->GetValue().GetName()));
        std::cout << "Expected: SUCCESS (status check)" << std::endl;

        std::cout << std::endl << "Find Test 2: ";
        CHECK_FUNC(keyType(newBookNum2.GetName()) != keyType(newHashMap.Find(keyType("randomKey3"))->GetValue().GetName()));
        std::cout << "Expected: SUCCESS (status check) - key not exist" << std::endl;
    }
    catch(const std::exception &ex) {
        std::cout << std::endl << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
    }  
}

void IterTest() {
    std::cout << std::endl << "\033[1;34m" << "Find Test:" << "\033[0m" << std::endl;

    try {
        HashMap newHashMap(3, HashFunc());
        valueType newBookNum1("Harry Potter", "J. K. Rowling", 1999, "12/01/2012");
        valueType newBookNum2("Lord Of The Rings", "J. R. R. Tolkien", 2011, "11/03/2016");
        valueType newBookNum3("The Adventures of Sherlock Holmes", "Arthur Conan Doyle", 1970, "10/05/1991");

        std::cout << std::endl << "Insert Test 1: ";
        CHECK_FUNC(HashMap::SUCCEEDED == newHashMap.Insert(keyType("randomKey"), newBookNum1));
        std::cout << "Expected: SUCCESS (status check)" << std::endl;

        std::cout << std::endl << "Insert Test 2: ";
        CHECK_FUNC(HashMap::SUCCEEDED == newHashMap.Insert(keyType("randomKey2"), newBookNum2));
        std::cout << "Expected: SUCCESS (status check)" << std::endl;

        std::cout << std::endl << "Insert Test 3: ";
        CHECK_FUNC(HashMap::SUCCEEDED == newHashMap.Insert(keyType("randomKey3"), newBookNum3));
        std::cout << "Expected: SUCCESS (status check)" << std::endl;

        HashMapIter beginIter = newHashMap.Begin();
        HashMapIter endIter = newHashMap.End();

        std::cout << std::endl << "Iter Test 1: ";
        CHECK_FUNC(beginIter != endIter);
        std::cout << "Expected: SUCCESS (status check)" << std::endl;

        std::cout << std::endl << "Iter Test 2: ";
        CHECK_FUNC(keyType(newBookNum1.GetName()) == keyType(beginIter.operator*().GetName()));
        std::cout << "Expected: SUCCESS (status check)" << std::endl;

        beginIter.operator++();

        std::cout << std::endl << "Iter Test 3: ";
        CHECK_FUNC(keyType(newBookNum2.GetName()) == keyType(beginIter.operator*().GetName()));
        std::cout << "Expected: SUCCESS (status check)" << std::endl;

        beginIter.operator++();

        std::cout << std::endl << "Iter Test 4: ";
        CHECK_FUNC(keyType(newBookNum3.GetName()) == keyType(beginIter.operator*().GetName()));
        std::cout << "Expected: SUCCESS (status check)" << std::endl;

        beginIter.operator++();

        std::cout << std::endl << "Iter Test 5: ";
        CHECK_FUNC(beginIter == endIter);
        std::cout << "Expected: SUCCESS (status check)" << std::endl;
    }
    catch(const std::exception &ex) {
        std::cout << std::endl << "\033[1;31m" << ex.what() << "\033[0m" << std::endl;
    }  
}

int main() {
    InsertTest();
    RemoveTest();
    FindTest();
    IterTest();

    return 0;
}