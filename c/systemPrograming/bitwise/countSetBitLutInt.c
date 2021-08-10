#include <stdio.h> /* printf, scanf */

#define ASCII_SIZE (256)

size_t CountSetBitsForSingleNum(unsigned char _num)
{
	size_t count = 0;
	
	while (_num)
	{
		count += _num & 1;
		_num >>= 1;
	}
	
	return count;
}

static void BuildLUT(char *lut)
{
    size_t i;

    for (i = 0;i < ASCII_SIZE;++i)
    {
        lut[i] = CountSetBitsForSingleNum(i);
    }
}

size_t CountSetBits(unsigned int _num)
{
    static char lut[ASCII_SIZE];
    static char isLutInit;
    size_t count = 0;

    if (!isLutInit)
    {
        BuildLUT(lut);
        ++isLutInit;
    }

    while (_num)
    {
        count += lut[(char)_num];
        _num >>= 8;
    }

    return count;
}

int main(void)
{
	unsigned int num = 5555555;
	
	printf("The number of set bits is: %ld\n", CountSetBits(num));
	
	return 0;	
}