#include <iostream> /* std::cout, std::endl */
#include "bitSet_inline.hpp" /* Bit Set Inline Header */

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

#define NUM_OF_BITS (130)

void OnOffToggleCountOnCountOffTest() {
    std::cout << "\033[1;34m" << "On/Off/Toggle/CountOn/CountOff Test:" << "\033[0m" << std::endl << std::endl;

    BitSet<NUM_OF_BITS> newBitSet;

    for (size_t i {0};i < NUM_OF_BITS;++i) {
        newBitSet.On(i);
    }

    std::cout << "On/Count On Test:" << std::endl;
    CHECK_FUNC(NUM_OF_BITS == newBitSet.CountOn());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;

    for (size_t i {0};i < NUM_OF_BITS;++i) {
        newBitSet.Off(i);
    }

    std::cout << "Off/Count Off Test:" << std::endl;
    CHECK_FUNC(NUM_OF_BITS == newBitSet.CountOff());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;

    for (size_t i {0};i < NUM_OF_BITS;++i) {
        newBitSet.Toggle(i);
    }

    std::cout << "Toggle/Count On Test:" << std::endl;
    CHECK_FUNC(NUM_OF_BITS == newBitSet.CountOn());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;

    for (size_t i {0};i < NUM_OF_BITS;i += 2) {
        newBitSet.Off(i);
    }

    std::cout << "Off/Count Off Test:" << std::endl;
    CHECK_FUNC(NUM_OF_BITS / 2 == newBitSet.CountOff());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;

    newBitSet.Off(0);

    std::cout << "On/Count On Test:" << std::endl;
    CHECK_FUNC(NUM_OF_BITS / 2 == newBitSet.CountOn());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;
}

void SizeAreAllOnAreAllOffTest() {
    std::cout << "\033[1;34m" << "Size/AreAllOn/AreAllOff Test:" << "\033[0m" << std::endl << std::endl;

    BitSet<NUM_OF_BITS> newBitSet;

    std::cout << "Size Test:" << std::endl;
    CHECK_FUNC(NUM_OF_BITS == newBitSet.Size());
    std::cout << "Expected: SUCCESS (size check)" << std::endl << std::endl;

    std::cout << "AreAllOff Test:" << std::endl;
    CHECK_FUNC(true == newBitSet.AreAllOff());
    std::cout << "Expected: SUCCESS (status check)" << std::endl << std::endl;

    for (size_t i {0};i < NUM_OF_BITS;++i) {
        newBitSet.On(i);
    }

    std::cout << "AreAllOn Test:" << std::endl;
    CHECK_FUNC(true == newBitSet.AreAllOn());
    std::cout << "Expected: SUCCESS (status check)" << std::endl << std::endl;

    newBitSet.Off(0);

    std::cout << "AreAllOff Test 2:" << std::endl;
    CHECK_FUNC(false == newBitSet.AreAllOff());
    std::cout << "Expected: SUCCESS (status check)" << std::endl << std::endl;

    std::cout << "AreAllOn Test 2:" << std::endl;
    CHECK_FUNC(false == newBitSet.AreAllOn());
    std::cout << "Expected: SUCCESS (status check)" << std::endl << std::endl;
}

void OperatorAndTest() {
    std::cout << "\033[1;34m" << "Operator And Test:" << "\033[0m" << std::endl << std::endl;

    BitSet<NUM_OF_BITS> newBitSet;
    BitSet<NUM_OF_BITS> aOtherBitSet1;
    BitSet<NUM_OF_BITS> aOtherBitSet2;

    for (size_t i {0};i < NUM_OF_BITS;++i) {
        aOtherBitSet1.On(i);
    }

    std::cout << "Operator And Test 1:" << std::endl;
    CHECK_FUNC(!newBitSet.operator&(aOtherBitSet1).CountOn());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;

    for (size_t i {0};i < NUM_OF_BITS;++i) {
        newBitSet.On(i);
    }

    for (size_t i {0};i < NUM_OF_BITS / 2;++i) {
        aOtherBitSet2.On(i);
    }

    std::cout << "Operator And Test 2:" << std::endl;
    CHECK_FUNC(NUM_OF_BITS / 2 == newBitSet.operator&(aOtherBitSet2).CountOn());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;
}

void OperatorOrTest() {
    std::cout << "\033[1;34m" << "Operator Or Test:" << "\033[0m" << std::endl << std::endl;

    BitSet<NUM_OF_BITS> newBitSet;
    BitSet<NUM_OF_BITS> aOtherBitSet1;
    BitSet<NUM_OF_BITS> aOtherBitSet2;

    for (size_t i {0};i < NUM_OF_BITS;++i) {
        aOtherBitSet1.On(i);
    }

    std::cout << "Operator Or Test 1:" << std::endl;
    CHECK_FUNC(NUM_OF_BITS ==  newBitSet.operator|(aOtherBitSet1).CountOn());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;

    for (size_t i {0};i < NUM_OF_BITS / 2;++i) {
        aOtherBitSet2.Off(i);
    }

    std::cout << "Operator Or Test 2:" << std::endl;
    CHECK_FUNC(!newBitSet.operator|(aOtherBitSet2).CountOn());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;
}

void OperatorXorTest() {
    std::cout << "\033[1;34m" << "Operator Xor Test:" << "\033[0m" << std::endl << std::endl;

    BitSet<NUM_OF_BITS> newBitSet;
    BitSet<NUM_OF_BITS> aOtherBitSet1;
    BitSet<NUM_OF_BITS> aOtherBitSet2;

    for (size_t i {0};i < NUM_OF_BITS;++i) {
        aOtherBitSet1.On(i);
    }

    std::cout << "Operator Xor Test 1:" << std::endl;
    CHECK_FUNC(NUM_OF_BITS  == newBitSet.operator^(aOtherBitSet1).CountOn());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;

    for (size_t i {0};i < NUM_OF_BITS / 2;++i) {
        aOtherBitSet2.On(i);
    }

    std::cout << newBitSet.operator&(aOtherBitSet2).CountOn();

    std::cout << "Operator Xor Test 2:" << std::endl;
    CHECK_FUNC(NUM_OF_BITS / 2 == newBitSet.operator^(aOtherBitSet2).CountOn());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;
}

void OperatorTildeTest() {
    std::cout << "\033[1;34m" << "Operator Tilde Test:" << "\033[0m" << std::endl << std::endl;

    BitSet<NUM_OF_BITS> newBitSet;
    BitSet<NUM_OF_BITS> aOtherBitSet1;

    std::cout << "Operator Tilde Test 1:" << std::endl;

    CHECK_FUNC(NUM_OF_BITS == newBitSet.operator~().CountOn());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;

    for (size_t i {0};i < NUM_OF_BITS / 2;++i) {
        aOtherBitSet1.On(i);
    }

    std::cout << "Operator Tilde Test 2:" << std::endl;
    CHECK_FUNC(NUM_OF_BITS / 2 == aOtherBitSet1.operator~().CountOn());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;
}

void OperatorAndEqualTest() {
    std::cout << "\033[1;34m" << "Operator And Equal Test:" << "\033[0m" << std::endl << std::endl;

    BitSet<NUM_OF_BITS> newBitSet;
    BitSet<NUM_OF_BITS> aOtherBitSet1;
    BitSet<NUM_OF_BITS> aOtherBitSet2;

    for (size_t i {0};i < NUM_OF_BITS;++i) {
        aOtherBitSet1.On(i);
    }

    std::cout << "Operator And Equal Test 1:" << std::endl;
    newBitSet.operator&=(aOtherBitSet1);
    CHECK_FUNC(!newBitSet.CountOn());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;

    for (size_t i {0};i < NUM_OF_BITS;++i) {
        newBitSet.On(i);
    }

    for (size_t i {0};i < NUM_OF_BITS / 2;++i) {
        aOtherBitSet2.On(i);
    }

    std::cout << "Operator And Equal Test 2:" << std::endl;
    newBitSet.operator&=(aOtherBitSet2);
    CHECK_FUNC(NUM_OF_BITS / 2 == newBitSet.CountOn());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;
}

void OperatorOrEqualTest() {
    std::cout << "\033[1;34m" << "Operator Or Equal Test:" << "\033[0m" << std::endl << std::endl;

    BitSet<NUM_OF_BITS> newBitSet;
    BitSet<NUM_OF_BITS> aOtherBitSet1;
    BitSet<NUM_OF_BITS> aOtherBitSet2;

    for (size_t i {0};i < NUM_OF_BITS;++i) {
        aOtherBitSet1.On(i);
    }

    std::cout << "Operator Or Equal Test 1:" << std::endl;
    newBitSet.operator|=(aOtherBitSet1);
    CHECK_FUNC(NUM_OF_BITS == newBitSet.CountOn());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;

    for (size_t i {0};i < NUM_OF_BITS / 2;++i) {
        aOtherBitSet2.Off(i);
    }

    std::cout << "Operator Or Equal Test 2:" << std::endl;
    newBitSet.operator|=(aOtherBitSet2);
    CHECK_FUNC(NUM_OF_BITS == newBitSet.CountOn());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;
}

void OperatorXorEqualTest() {
    std::cout << "\033[1;34m" << "Operator Xor Equal Test:" << "\033[0m" << std::endl << std::endl;

    BitSet<NUM_OF_BITS> newBitSet;
    BitSet<NUM_OF_BITS> aOtherBitSet1;
    BitSet<NUM_OF_BITS> aOtherBitSet2;

    for (size_t i {0};i < NUM_OF_BITS;++i) {
        aOtherBitSet1.On(i);
    }

    std::cout << "Operator Xor Equal Test 1:" << std::endl;
    newBitSet.operator^=(aOtherBitSet1);
    CHECK_FUNC(NUM_OF_BITS == newBitSet.CountOn());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;

    for (size_t i {0};i < NUM_OF_BITS / 2;++i) {
        aOtherBitSet2.On(i);
    }

    std::cout << "Operator Or Equal Test 2:" << std::endl;
    newBitSet.operator^=(aOtherBitSet2);
    CHECK_FUNC(NUM_OF_BITS / 2 == newBitSet.CountOn());
    std::cout << "Expected: SUCCESS (count check)" << std::endl << std::endl;
}

void OperatorEqualNotEqualTest() {
    std::cout << "\033[1;34m" << "Operator Equal/NotEqual Test:" << "\033[0m" << std::endl << std::endl;

    BitSet<NUM_OF_BITS> newBitSet;
    BitSet<NUM_OF_BITS> aOtherBitSet1;
    BitSet<NUM_OF_BITS> aOtherBitSet2;
    BitSet<NUM_OF_BITS> aOtherBitSet3;

    for (size_t i {0};i < NUM_OF_BITS;++i) {
        aOtherBitSet2.On(i);
    }

    for (size_t i {0};i < NUM_OF_BITS / 2;++i) {
        aOtherBitSet3.On(i);
    }

    std::cout << "Operator Equal Test 1:" << std::endl;
    CHECK_FUNC(true == newBitSet.operator==(aOtherBitSet1));
    std::cout << "Expected: SUCCESS (status check)" << std::endl << std::endl;

    std::cout << "Operator Not Equal Test 1:" << std::endl;
    CHECK_FUNC(true == newBitSet.operator!=(aOtherBitSet2));
    std::cout << "Expected: SUCCESS (status check)" << std::endl << std::endl;

    std::cout << "Operator Equal Test 2:" << std::endl;
    CHECK_FUNC(false == aOtherBitSet2.operator==(aOtherBitSet3));
    std::cout << "Expected: SUCCESS (status check)" << std::endl << std::endl;

    std::cout << "Operator Not Equal Test 2:" << std::endl;
    CHECK_FUNC(false == newBitSet.operator!=(aOtherBitSet1));
    std::cout << "Expected: SUCCESS (status check)" << std::endl << std::endl;
}

int main() {
    OnOffToggleCountOnCountOffTest();
    SizeAreAllOnAreAllOffTest();
    OperatorAndTest();
    OperatorOrTest();
    OperatorXorTest();
    OperatorTildeTest();
    OperatorAndEqualTest();
    OperatorOrEqualTest();
    OperatorXorEqualTest();
    OperatorEqualNotEqualTest();

    return 0;
}
