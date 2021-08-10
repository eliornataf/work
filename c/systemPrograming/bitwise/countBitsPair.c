#include <stdio.h> /* printf, scanf, putchar */

#define BITS_IN_BYTE (8)
#define NUM_OF_BITS sizeof(unsigned int) * BITS_IN_BYTE

size_t CountBitsPairs(unsigned int num)
{
	unsigned int currBit, nextBit;
	size_t countPairs = 0;
	size_t i;
	
	for (i = 0;i < NUM_OF_BITS;i += 2)
	{
		currBit = num & (1 << i);
		nextBit = num & (1 << (i + 1));
		
		if ( (currBit == nextBit) || (currBit && nextBit) )
		{
			++countPairs;
		}
	}
	
	return countPairs;
}

int main(void)
{
	unsigned int num;
	
	printf("Please enter a number: ");
	scanf("%u", &num);
	
	printf("%ld\n", CountBitsPairs(num));
	
	return 0;
}
