#include <stdio.h> /* printf, scanf */

#define INPUT_ERROR (-1)

int main(void)
{
	int fact = 1;
	int i, num;
	
	printf("Please enter a number: ");
	scanf("%d", &num);
	
	if (num < 0)
	{
		printf("Input Error\n");
		return INPUT_ERROR;
	}
	
	for(i = 2;i <= num;++i)
	{
		fact *= i;
	}
	
	printf("%d factorial is %d\n", num, fact);
	
	return 0;
}
