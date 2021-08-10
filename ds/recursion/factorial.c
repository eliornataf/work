#include <stdio.h> /* printf, scanf */

int factorial(int num)
{
	if (num <= 1)
	{
		return 1;
	}
	
	return factorial(num - 1) * num;
}

int main(void)
{
	int num;
	
	printf("Please enter a number: ");
	scanf("%d", &num);
	
	printf("%d factorial is %d\n", num, factorial(num));
	
	return 0;
}
