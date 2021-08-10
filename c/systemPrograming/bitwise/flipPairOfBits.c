#include <stdio.h> /* printf */

#define ASCII_SIZE (256)
#define BINARY_10101010 (170)
#define BINARY_01010101 (85)
#define BITS_IN_BYTE (8)
#define STR_LENGTH (33)
#define OFFSET (0)

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

size_t FlipPairOfBitsOfCharSize(unsigned char _num)
{
    return ((_num & BINARY_10101010) >> 1) | ((_num & BINARY_01010101) << 1); 
}

static void BuildLUT(char *lut)
{
    size_t i;

    for (i = 0;i < ASCII_SIZE;++i)
    {
        lut[i] = FlipPairOfBitsOfCharSize(i);
    }
}

static unsigned int FlipPairOfBits(unsigned int _num)
{
    static char lut[ASCII_SIZE];
    unsigned int flippedNum = 0;
    static char isLutInit;
    size_t numOfMoves;

    if (!isLutInit)
    {
        BuildLUT(lut);
        ++isLutInit;
    }

    for (numOfMoves = OFFSET;_num;_num >>= 8, numOfMoves += 8)
    {
        flippedNum |= (lut[(char)_num] << numOfMoves);
    }

    return flippedNum;
}

int main(void)
{
    unsigned int num = 555555555;
    char binaryStr[STR_LENGTH];

    printf("The number before flip pair of bits is: %s\n", DecimalToBinary(num, binaryStr, BITS_IN_BYTE * sizeof(int)));

	printf("The number of after flip pair of bits:  %s\n", DecimalToBinary(FlipPairOfBits(num), binaryStr, BITS_IN_BYTE * sizeof(int)));
	
	return 0;	
}


/*          11010010

    11010010 &      11010010 &  
    10101010        01010101
    --------        --------
    10000010        01010000 
  >>                        <<
    01000001        10100000

            01000001 |
            10100000
            --------
            11100001            */
