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

/*****************************************************************************/

void toggleBits(unsigned int _num, char *_strAfterToggle)
{
	size_t numOfBits = countBits(_num);
	size_t i;
	
	for (i = 0;i < numOfBits;++i)
	{
		unsigned int temp = _num & (1 << i);
		_strAfterToggle[numOfBits - i - 1] = temp ? '0' : '1';
	}
	
	_strAfterToggle[numOfBits] = '\0';
}

int main(void)
{
	unsigned int num;
	char strAfterToggle[STR_LENGTH];
	
	printf("Please enter a number: ");
	scanf("%u", &num);
	
	toggleBits(num, strAfterToggle);
	
	printf("%d after toggle [in bits]: %s\n", num, strAfterToggle);
	
	return 0;
}
