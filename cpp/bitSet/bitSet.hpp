/*****************************************************************************
* File Name: Bit Set
* Written by: Elior Nataf
* Date: 26/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __BIT_SET_HPP_H__
#define __BIT_SET_HPP_H__

/*------------------------------- Header Files ------------------------------*/

#include <climits>

/*-------------------------------- Typedef -------------------------------*/

typedef unsigned long long bitSetUnit;

/*-------------------------------- Structure -------------------------------*/

template<bitSetUnit N>
class BitSet {
public:
    // Constructor

    BitSet();

    // Destructor

    ~BitSet() = default;

    // Copy Constructor

    BitSet(const BitSet &a_other) = default;

    // Assignment Operator

    BitSet &operator=(const BitSet &a_other) = default;

    // Functions

    bitSetUnit *Begin();
    bitSetUnit *BeforeEnd();
    bitSetUnit *End();

    void On(const size_t &a_bitIndex);
    void Off(const size_t &a_bitIndex);
    void Toggle(const size_t &a_bitIndex);

    bitSetUnit CountOn();
    bitSetUnit CountOff();
    bitSetUnit Size() const;

    bool AreAllOn();
    bool AreAllOff();

    BitSet<N> operator&(const BitSet &a_other);
    BitSet<N> operator|(const BitSet &a_other);
    BitSet<N> operator^(const BitSet &a_other);
    BitSet<N> operator~();

    BitSet<N> &operator&=(const BitSet &a_other);
    BitSet<N> &operator|=(const BitSet &a_other);
    BitSet<N> &operator^=(const BitSet &a_other);

    bool operator==(const BitSet &a_other);
    bool operator!=(const BitSet &a_other);

private:
   // Constants

    static constexpr bitSetUnit NUM_OF_BIT_SET_UNITS = (N / (sizeof(bitSetUnit) * CHAR_BIT)) + ((N % (sizeof(bitSetUnit) * CHAR_BIT)) != 0);
   
    static constexpr size_t NUM_OF_BIT_IN_BIT_SET_UNIT = sizeof(bitSetUnit) * CHAR_BIT;

    //  Struct members

   bitSetUnit m_bitSetUnitsArray[NUM_OF_BIT_SET_UNITS];
};

#endif /* __BIT_SET_HPP_H__ */