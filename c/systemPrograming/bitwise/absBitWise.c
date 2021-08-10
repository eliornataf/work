#include <stdio.h> /* printf, scanf */

#define STR_LENGTH (33)
#define BITS_IN_BYTE (8)
#define MSB (BITS_IN_BYTE * sizeof(int) - 1)

static char *DecimalToBinary(int _num, char *_strAfterRotate, size_t _numOfBits)
{
	size_t i;
	
	for (i = 0;i < _numOfBits;++i)
	{
		_strAfterRotate[_numOfBits - i - 1] = (_num & (1 << i)) ? '1' : '0';
	}
	
	_strAfterRotate[_numOfBits] = '\0'; 

    return _strAfterRotate;
}

size_t absNum(int _num)
{
    int mostSignificantBit = _num >> MSB;

    return (_num + mostSignificantBit) ^ mostSignificantBit;
}

int main(void)
{
    int num;
    char binaryStr[STR_LENGTH];

	printf("Please enter a number: ");
	scanf("%d", &num);

    printf("The number before absolute value is: %s\n", DecimalToBinary(num, binaryStr, BITS_IN_BYTE * sizeof(int)));

	printf("The number after absolute value is:  %s\n", DecimalToBinary(absNum(num), binaryStr, BITS_IN_BYTE * sizeof(int)));

	return 0;	
}