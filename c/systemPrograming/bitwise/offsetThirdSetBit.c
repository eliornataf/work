#include <stdio.h> /* printf */
#include <limits.h> /* INT_MAX */

#define BITS_IN_BYTE (8)
#define THIRD_BIT (3)
#define STR_LENGTH (33)
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

static size_t OffsetThirdSetBit(unsigned int _num)
{
    size_t countBits, countSetBits;

    for (countBits = 0, countSetBits = 0;_num;_num >>= 1)
    {
        countSetBits += _num & 1;

        if (THIRD_BIT == countSetBits)
        {
            break;
        }

        ++countBits;
    }

    return (!_num) ? OFFSET_NOT_FOUND : countBits;
}

int main(void)
{
    unsigned int num = 88888;
    char binaryStr[STR_LENGTH];

    printf("The number is: %s\nThe offset of the third set bit is: %ld\n", DecimalToBinary(num, binaryStr, BITS_IN_BYTE * sizeof(int)), OffsetThirdSetBit(num));
	
	return 0;	
}