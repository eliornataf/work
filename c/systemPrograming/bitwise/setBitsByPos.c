#include <stdio.h> /* printf, scanf */

#define BITS_IN_BYTE (8)
#define NUM_OF_BITS sizeof(unsigned int) * BITS_IN_BYTE

unsigned int setBitsByPos(unsigned int _x, unsigned _y, size_t _numOfBitsFromLBS, size_t _setPos)
{
	_y <<= NUM_OF_BITS - _numOfBitsFromLBS;
	_y >>= NUM_OF_BITS - _setPos;
	
	return _x |= _y;
}

int main(void)
{
	unsigned int x, y;
	size_t numOfBitsFromLBS, setPos;
	
	printf("Please enter 2 number [x & y]:\n");
	scanf("%u %u", &x, &y);
	
	printf("Please enter the number of bits from LBS and the set position:\n");
	scanf("%lu %lu", &numOfBitsFromLBS, &setPos);
	
	printf("X after set bits: %d\n", setBitsByPos(x, y, numOfBitsFromLBS, setPos));
	
	return 0;
}
