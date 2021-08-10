#include <stdio.h> /* printf, scanf */

#define INPUT_ERROR (-1)
#define IS_NOT_ASCENDING_ORDER (0)
#define IS_ASCENDING_ORDER (1)

int main(void)
{
	int num, lastDig;
	
	printf("Please enter a number [2 digits or more]: ");
	scanf("%d", &num);
	
	if (num < 10)
	{
		printf("Input Error\n");
		return INPUT_ERROR;
	}
	
	lastDig = num % 10;
	
	while (num != 0)
	{
		num /= 10;
		
		if ( lastDig < (num % 10) )
		{
			printf("The numbers are not in ascending order\n");
			return IS_NOT_ASCENDING_ORDER;
		}
		
		lastDig = num % 10;
	}

	printf("The numbers are in ascending order\n");
	return IS_ASCENDING_ORDER;
}
