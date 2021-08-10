#ifndef __BIT_SET_INLINE_HPP__
#define __BIT_SET_INLINE_HPP__

#include <algorithm> /* std::algorithm */
#include <cstring> /* memcpy */
#include <climits> /* CHAR_BIT */
#include <stdexcept> /* std::out_of_range */
#include <numeric> /* std::accumulate */
#include "bitSet.hpp" /* Bit Set Header */

/************************************************************************/

static bool AreAllOnRemianderUnit(bitSetUnit lastBitsUnit, const size_t a_remianderBits) {
    bitSetUnit mask = ~0;
    mask >>= sizeof(bitSetUnit) * CHAR_BIT - a_remianderBits;

    return (mask == lastBitsUnit);
}

static void TildeOperatorRemianderUnit(bitSetUnit *lastBitsUnit, const size_t a_remianderBits) {
    for (size_t i {0};i < a_remianderBits;++i) {
        *lastBitsUnit = (*lastBitsUnit << bitSetUnit(1)) ^ bitSetUnit(1);
    }
}

/************************************************************************/

template<bitSetUnit N>
BitSet<N>::BitSet() 
: m_bitSetUnitsArray() {
}

template<bitSetUnit N>
bitSetUnit *BitSet<N>::Begin() {
    return this->m_bitSetUnitsArray;
}

template<bitSetUnit N>
bitSetUnit *BitSet<N>::BeforeEnd() {
    return this->m_bitSetUnitsArray + (NUM_OF_BIT_SET_UNITS - 1);
}

template<bitSetUnit N>
bitSetUnit *BitSet<N>::End() {
    return this->m_bitSetUnitsArray + (NUM_OF_BIT_SET_UNITS);
}

template<bitSetUnit N>
void BitSet<N>::On(const size_t &a_bitIndex) {
    if (N <= a_bitIndex) {
        throw std::out_of_range("a_bitIndex is not valid");
    }

    this->m_bitSetUnitsArray[a_bitIndex / NUM_OF_BIT_IN_BIT_SET_UNIT] |= (bitSetUnit(1) << (a_bitIndex % NUM_OF_BIT_IN_BIT_SET_UNIT));
}

template<bitSetUnit N>
void BitSet<N>::Off(const size_t &a_bitIndex) {
    if (N <= a_bitIndex) {
        throw std::out_of_range("a_bitIndex is not valid");
    }

    this->m_bitSetUnitsArray[a_bitIndex / NUM_OF_BIT_IN_BIT_SET_UNIT] &= ~(bitSetUnit(1) 
    << (a_bitIndex % NUM_OF_BIT_IN_BIT_SET_UNIT));
}

template<bitSetUnit N>
void BitSet<N>::Toggle(const size_t &a_bitIndex) {
    if (N <= a_bitIndex) {
        throw std::out_of_range("a_bitIndex is not valid");
    }

    this->m_bitSetUnitsArray[a_bitIndex / NUM_OF_BIT_IN_BIT_SET_UNIT] ^= (bitSetUnit(1) 
    << (a_bitIndex % NUM_OF_BIT_IN_BIT_SET_UNIT));
}

template<bitSetUnit N>
bitSetUnit BitSet<N>::CountOn() {
    struct CountOnBits {
        size_t operator()(bitSetUnit a_totalOnBits, bitSetUnit a_currBitUnit){
            bitSetUnit countUnitOnBits {0};
            for (size_t i {0};i < NUM_OF_BIT_IN_BIT_SET_UNIT;++i) {
                countUnitOnBits += (a_currBitUnit >> i) & bitSetUnit(1);
            }

            return a_totalOnBits + countUnitOnBits;
        }
    };

    return (std::accumulate(this->Begin(), this->End(), 0, CountOnBits()));
}

template<bitSetUnit N>
bitSetUnit BitSet<N>::CountOff() {
    return N - this->CountOn();
}

template<bitSetUnit N>
bitSetUnit BitSet<N>::Size() const {
    return N;
}

template<bitSetUnit N>
bool BitSet<N>::AreAllOn() {
    struct AreAllOnBits {
        bool operator()(bitSetUnit a_currBitUnit){
            return (a_currBitUnit == ~0);
        }
    };

    if (!N % NUM_OF_BIT_IN_BIT_SET_UNIT) {
        return std::all_of(this->Begin(), this->End(), AreAllOnBits());
    }
    else {
        return std::all_of(this->Begin(), this->BeforeEnd(), AreAllOnBits()) && AreAllOnRemianderUnit(*(this->BeforeEnd()), N % NUM_OF_BIT_IN_BIT_SET_UNIT);
    }
}

template<bitSetUnit N>
bool BitSet<N>::AreAllOff() {
    struct AreAllOffBits {
        bool operator()(bitSetUnit a_currBitUnit){  
            return (a_currBitUnit == 0);
        }
    };

    return std::all_of(this->Begin(), this->End(), AreAllOffBits());
}

template<bitSetUnit N>
BitSet<N> BitSet<N>::operator&(const BitSet &a_other) {
    BitSet<N> newBitSetUnitArray;
    struct OperatorAnd {
        bitSetUnit operator()(bitSetUnit a_originalBitUnit, bitSetUnit a_newBitUnit) {          
            return a_originalBitUnit & a_newBitUnit;
        }
    };
    
    std::transform(this->Begin(), this->End(), a_other.m_bitSetUnitsArray, newBitSetUnitArray.m_bitSetUnitsArray, OperatorAnd());

    return newBitSetUnitArray;
}

template<bitSetUnit N>
BitSet<N> BitSet<N>::operator|(const BitSet &a_other) {
    BitSet<N> newBitSetUnitArray;
    struct OperatorOr {
        bitSetUnit operator()(bitSetUnit a_originalBitUnit, bitSetUnit a_newBitUnit){
            return a_originalBitUnit | a_newBitUnit;
        }
    };
    
    std::transform(this->Begin(), this->End(), a_other.m_bitSetUnitsArray, newBitSetUnitArray.m_bitSetUnitsArray, OperatorOr());

    return newBitSetUnitArray;
}

template<bitSetUnit N>
BitSet<N> BitSet<N>::operator^(const BitSet &a_other) {
    BitSet<N> newBitSetUnitArray;
    struct OperatorXor {
        bitSetUnit operator()(bitSetUnit a_originalBitUnit, bitSetUnit a_newBitUnit){
            return a_originalBitUnit ^ a_newBitUnit;
        }
    };
    
    std::transform(this->Begin(), this->End(), a_other.m_bitSetUnitsArray, newBitSetUnitArray.m_bitSetUnitsArray, OperatorXor());

    return newBitSetUnitArray;
}

template<bitSetUnit N>
BitSet<N> BitSet<N>::operator~() {
    BitSet<N> newBitSetUnitArray;

    struct TildeOperator {
        bitSetUnit operator()(bitSetUnit a_currBitUnit){
            return ~a_currBitUnit;
        }
    };

    if (!(N % NUM_OF_BIT_IN_BIT_SET_UNIT)) {
        std::transform(this->Begin(), this->End(), newBitSetUnitArray.m_bitSetUnitsArray, TildeOperator());
    }
    else {
        std::transform(this->Begin(), this->BeforeEnd(), newBitSetUnitArray.m_bitSetUnitsArray, TildeOperator());

        TildeOperatorRemianderUnit(newBitSetUnitArray.BeforeEnd(), N % NUM_OF_BIT_IN_BIT_SET_UNIT);
    }

    return newBitSetUnitArray;
}

template<bitSetUnit N>
BitSet<N> &BitSet<N>::operator&=(const BitSet &a_other) {
    struct OperatorAndEqual {
        bitSetUnit operator()(bitSetUnit a_originalBitUnit, bitSetUnit a_newBitUnit){
            return a_originalBitUnit &= a_newBitUnit;
        }
    };
    
    std::transform(this->Begin(), this->End(), a_other.m_bitSetUnitsArray, this->m_bitSetUnitsArray, OperatorAndEqual());

    return *this;
}

template<bitSetUnit N>
BitSet<N> &BitSet<N>::operator|=(const BitSet &a_other) {
    struct OperatorOrEqual {
        bitSetUnit operator()(bitSetUnit a_originalBitUnit, bitSetUnit a_newBitUnit){
            return a_originalBitUnit |= a_newBitUnit;
        }
    };
    
    std::transform(this->Begin(), this->End(), a_other.m_bitSetUnitsArray, this->m_bitSetUnitsArray, OperatorOrEqual());

    return *this;
}

template<bitSetUnit N>
BitSet<N> &BitSet<N>::operator^=(const BitSet &a_other) {
    struct OperatorXorEqual {
        bitSetUnit operator()(bitSetUnit a_originalBitUnit, bitSetUnit a_newBitUnit){
            return a_originalBitUnit ^= a_newBitUnit;
        }
    };
    
    std::transform(this->Begin(), this->End(), a_other.m_bitSetUnitsArray, this->m_bitSetUnitsArray, OperatorXorEqual());

    return *this;
}

template<bitSetUnit N>
bool BitSet<N>::operator==(const BitSet &a_other) {
    return std::equal(this->Begin(), this->End(), a_other.m_bitSetUnitsArray);
}

template<bitSetUnit N>
bool BitSet<N>::operator!=(const BitSet &a_other) {
    return !this->operator==(a_other);
}

#endif /* __BIT_SET_INLINE_HPP__ */
