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

size_t CountSetBits(unsigned char _num)
{
    static char flag;
    static char lut[ASCII_SIZE];

    if (!flag)
    {
        BuildLUT(lut);
        ++flag;
    }

    return lut[_num];
}

int main(void)
{
	unsigned char num = 5;
	
	printf("The number of set bits is: %ld\n", CountSetBits(num));
	
	return 0;	
}