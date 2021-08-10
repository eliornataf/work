#include <stdio.h> /* printf */

#define MAX_NUM_TO_CHECK (999)
#define IS_ARMSTRONG_NUMBER (1)
#define IS_NOT_ARMSTRONG_NUMBER (0)

/*****************************************************************************/

int Pow(int _num, int _pow)
{
	int res = 1;
	int i;
	
	for (i = 0;i < _pow;++i)
	{
		res *= _num;
	}
	
	return res;
}

int CountNumOfDigits(int _numToCount)
{
	int numToCountCopy = _numToCount;
	int countDigits = 0;
	int numAfterArmstrong = 0;
	int lastDigit;

	while (numToCountCopy != 0)
	{
		++countDigits;
		numToCountCopy /= 10;
	}
	
	numToCountCopy = _numToCount;
	
	if (countDigits < 2)
	{
		return IS_ARMSTRONG_NUMBER;
	}
	else
	{
		while (numToCountCopy != 0)
		{
			lastDigit = Pow((numToCountCopy % 10), countDigits);
			numAfterArmstrong += lastDigit;
			numToCountCopy /= 10;
		}
	}

	return (_numToCount == numAfterArmstrong) ? IS_ARMSTRONG_NUMBER 
													: IS_NOT_ARMSTRONG_NUMBER;
}

/*****************************************************************************/

int main(void)
{
	int i;
	
	for (i = 0;i <= MAX_NUM_TO_CHECK;++i)
	{	
		if (CountNumOfDigits(i) == IS_ARMSTRONG_NUMBER)
		{
			printf("%d->", i);
		}
	}	
	
	printf("X\n");
	
	return 0;
}
