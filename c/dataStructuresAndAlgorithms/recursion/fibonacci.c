#include <stdio.h> /* printf */

size_t fibonacciIter(size_t _index)
{
	size_t first = 0;
	size_t sum = 0;
	size_t last = 1;
	size_t i;
	
	for (i = 0;i < _index;++i)
	{
		first = sum;
		sum = first + last;
		last = first;
	}
	
	return last;
}

size_t fibonacciRecu(size_t _index)
{
	if (_index < 2)
	{
		return _index;
	}
	
	return fibonacciRecu(_index - 1) + fibonacciRecu(_index - 2);
}


int main(void)
{
	size_t index;
	
	printf("Please enter index number: ");
	scanf("%lu", &index);
	
	printf("Iteration function: index %ld is %ld\n", index, fibonacciIter(index));
	printf("Recursion function: index %ld is %ld\n", index, fibonacciRecu(index - 1));
	
	return 0;
}
