#include <stdio.h> /* printf */

#define ARGC_PRAM (3)
#define SUCCESS (0)
#define FAILURE (1)

int main(int agrc, char *argv[])
{
	int num1, num2;

	if (ARGC_PRAM != agrc)
	{
		return FAILURE;
	}
	
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	
	printf("The sum of the numbers is: %d\n", num1 + num2);
	printf("The multiplication of the numbers is: %d\n", num1 * num2);
	
	return SUCCESS;
}
