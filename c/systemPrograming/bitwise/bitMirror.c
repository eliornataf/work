#include <stdio.h> /* printf */

#define ASCII_SIZE (256)
#define BITS_IN_BYTE (8)
#define STR_LENGTH (33)
#define OFFSET (24)

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

size_t BitMirrorCharSize(unsigned char _num)
{
    size_t i, highBitIndex, smallBitIndex;

    for (i = 0, highBitIndex = 7, smallBitIndex = 0;i < BITS_IN_BYTE / 2;++i, --highBitIndex, ++smallBitIndex)
    {
        if ( ( (0 < (_num & (1 << highBitIndex))) && (!(_num & (1 << smallBitIndex))) ) 
                        || ( (!(_num & (1 << highBitIndex))) && (0 < (_num & (1 << smallBitIndex))) ) )
        {
            _num ^= (1 << highBitIndex);
            _num ^= (1 << smallBitIndex);
        }
    }

    return _num;
}

static void BuildLUT(char *lut)
{
    size_t i;

    for (i = 0;i < ASCII_SIZE;++i)
    {
        lut[i] = BitMirrorCharSize(i);
    }
}

static unsigned int BitMirror(unsigned int _num)
{
    static char lut[ASCII_SIZE];
    unsigned int mirroredNum = 0;
    static char isLutInit;
    size_t numOfMoves;

    if (!isLutInit)
    {
        BuildLUT(lut);
        ++isLutInit;
    }

    for (numOfMoves = OFFSET;_num;_num >>= 8, numOfMoves -= 8)
    {
        mirroredNum |= (lut[(char)_num] << numOfMoves);
    }

    return mirroredNum;
}

int main(void)
{
    unsigned int num = 355555555;
    char binaryStr[STR_LENGTH];

    printf("The number before mirror bits is: %s\n", DecimalToBinary(num, binaryStr, BITS_IN_BYTE * sizeof(int)));

	printf("The number after mirror bits is:  %s\n", DecimalToBinary(BitMirror(num), binaryStr, BITS_IN_BYTE * sizeof(int)));
	
	return 0;	
}