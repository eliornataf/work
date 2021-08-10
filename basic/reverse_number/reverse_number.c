#include <stdio.h> /* scanf, printf */ 

#define INPUT_ERROR (-1)

int main(void)
{
	int num, lastDig, numCopy;
	int revNum = 0;
	
	printf("Please enter a number: ");
	scanf("%d", &num);	
	
	if (num < 0)
	{
		printf("Input Error\n");
		return INPUT_ERROR;
	}
	
	numCopy = num;
		
	while (numCopy != 0)
	{
		revNum *= 10;
		lastDig = numCopy % 10;
		revNum += lastDig;
		numCopy /= 10;
	}
	
	printf("%d Reversed number is: %d\n",num, revNum);
	
	return 0;
}
