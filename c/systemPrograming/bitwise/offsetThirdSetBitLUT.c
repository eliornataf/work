#include <stdio.h> /* printf, scanf */
#include <limits.h> /* INT_MAX */

#define STR_LENGTH (33)
#define ASCII_SIZE (256)
#define BITS_IN_BYTE (8)
#define ZERO_SET_BIT (0)
#define ONE_SET_BIT (1)
#define TWO_SET_BIT (2)
#define THREE_SET_BIT (3)
#define OFFSET_NOT_FOUND (INT_MAX)

static char *DecimalToBinary(unsigned int _num, char *_strAfterRotate, size_t _numOfBits)
{
	size_t i;
	
	for (i = 0;i < _numOfBits;++i)
	{
		_strAfterRotate[_numOfBits - i - 1] = (_num & (1 << i)) ? '1' : '0';
	}
	
	_strAfterRotate[_numOfBits] = '\0'; 

    return _strAfterRotate;
}

size_t CountSetBitsCharSize(unsigned char _num)
{
	size_t count = 0;
	
	while (_num)
	{
		count += _num & 1;
		_num >>= 1;
	}
	
	return count;
}

static void BuildLUTCountSetBit(char *_lut)
{
    size_t i;

    for (i = 0;i < ASCII_SIZE;++i)
    {
        _lut[i] = CountSetBitsCharSize(i);
    }
}

static size_t GenericFindSetBit(unsigned char _num, size_t _numSetBitToFound)
{
    size_t count = 0;
    size_t i;

    for (i = 0;_num;++i, _num >>= 1)
    {
        if (0 < (_num & 1))
        {
            ++count;

            if (count == _numSetBitToFound)
            {
                break;
            }
        }
    }

    return i;
}

static size_t FindFirstSetBit(unsigned char _num)
{
    return GenericFindSetBit(_num, ONE_SET_BIT);
}

static size_t FindSecondSetBit(unsigned char _num)
{
    return GenericFindSetBit(_num, TWO_SET_BIT);
}

static size_t FindThirdSetBit(unsigned char _num)
{
    return GenericFindSetBit(_num, THREE_SET_BIT);
}

size_t BuildLUTFirstThreeSetBits(char *_lutFirstSetBitOffset, char *_lutSecondSetBitOffset, char *_lutThirdSetBitOffset)
{
    size_t i;

    for (i = 0;i < ASCII_SIZE;++i)
    {
        _lutFirstSetBitOffset[i] = FindFirstSetBit(i);
        _lutSecondSetBitOffset[i] = FindSecondSetBit(i);
        _lutThirdSetBitOffset[i] = FindThirdSetBit(i);
    }    
}

size_t OffsetThirdSetBit(unsigned int _num)
{
    static char lut[ASCII_SIZE];
    static char lutFirstSetBitOffset[ASCII_SIZE];
    static char lutSecondSetBitOffset[ASCII_SIZE];
    static char lutThirdSetBitOffset[ASCII_SIZE];
    static char isLutInit;
    size_t countSetBitFromChar = 0;
    size_t totalSetBit = 0;

    if (!isLutInit)
    {
        BuildLUTCountSetBit(lut);
        BuildLUTFirstThreeSetBits(lutFirstSetBitOffset, lutSecondSetBitOffset, lutThirdSetBitOffset);
        ++isLutInit;
    }

    while (_num || THREE_SET_BIT <= totalSetBit)
    {
        countSetBitFromChar = lut[(char)_num];
        
        if (THREE_SET_BIT <= totalSetBit + countSetBitFromChar)
        {   
            switch (totalSetBit)
            {
                case ZERO_SET_BIT: 
                return lutThirdSetBitOffset[(char)_num];

                case ONE_SET_BIT:
                return lutSecondSetBitOffset[(char)_num];

                case TWO_SET_BIT: 
                return lutFirstSetBitOffset[(char)_num];
            }
        }

        totalSetBit += countSetBitFromChar;
        _num >>= 8;
    }

    return OFFSET_NOT_FOUND;
}

int main(void)
{
	unsigned int num = 988888899;
    char binaryStr[STR_LENGTH];
	
    printf("The number is: %s\nThe offset of the third set bit is: %ld\n", DecimalToBinary(num, binaryStr, BITS_IN_BYTE * sizeof(int)), OffsetThirdSetBit(num));
	
	return 0;	
}