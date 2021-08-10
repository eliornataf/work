#include <stdio.h> /* printf, scanf */

#define STR_LENGTH 32

/*****************************************************************************/

static size_t countBits(unsigned int _num)
{
	size_t count = 0;

	while (_num)
	{
		++count;
		_num >>= 1;
	}
	
	return count;
}

static void numToStr(unsigned int _num, char *_strAfterRotate, size_t _numOfBits)
{
	size_t i;
	
	for (i = 0;i < _numOfBits;++i)
	{
		unsigned int temp = _num & (1 << i);
		_strAfterRotate[_numOfBits - i - 1] = temp ? '1' : '0';
	}
	
	_strAfterRotate[_numOfBits] = '\0'; 
}

/*****************************************************************************/

void RotateBits(unsigned int _num, char *_strAfterRotate, size_t _numOfRotates)
{
	size_t numOfBits = countBits(_num);
	size_t i, j;
	char tempCh;
	
	numToStr(_num, _strAfterRotate, numOfBits);

	for (i = 0;i < _numOfRotates;++i)
	{
		tempCh = _strAfterRotate[numOfBits - 1];
		
		for (j = numOfBits - 1;0 < j;--j)
		{
			_strAfterRotate[j] = _strAfterRotate[j - 1];
		}
		
		_strAfterRotate[0] = tempCh;
	}
}

int main(void)
{
	unsigned int num;
	char strAfterRotate[STR_LENGTH];
	size_t numOfRotates;
	
	printf("Please enter a number to rotate & number rotates [to the right]: ");
	scanf("%u %lu", &num, &numOfRotates);
	
	RotateBits(num, strAfterRotate, numOfRotates);
	
	printf("%u after rotate [in bits]: %s\n", num, strAfterRotate);
	
	return 0;
}
