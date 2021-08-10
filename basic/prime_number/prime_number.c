#include <stdio.h> /* printf, scanf*/

#define IS_NOT_PRIME_NUMBER (0)
#define IS_PRIME_NUMBER (1)

int isPrimeNumber(_num)
{
	int i;

	for (i = 2;i < _num;++i)
	{
		if (_num % i == 0)
		{
			return IS_NOT_PRIME_NUMBER;
		}
	}
	
	return IS_PRIME_NUMBER;
}

int main(void)
{
	int num, res;
	
	printf("Please enter a number: ");
	scanf("%d", &num);
	
	if (num < 2)
	{
		printf("%d is not prime number\n", num);
		return IS_NOT_PRIME_NUMBER;
	} 
	
	res = isPrimeNumber(num);
	
	res ? printf("%d is prime number\n", num) 
									: printf("%d is not prime number\n", num);
	
	return 0;
}
