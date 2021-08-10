#include <stdio.h> /* printf, scanf */

size_t CountSetBits(unsigned char _num)
{
	size_t count = 0;
	
	while (_num)
	{
		count += _num & 1;
		_num >>= 1;
	}
	
	return count;
}

int main(void)
{
	unsigned char num = 5;
	
	printf("The number of set bits is: %ld\n", CountSetBits(num));
	
	return 0;	
}