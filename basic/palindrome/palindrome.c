#include <stdio.h> /* scanf, printf */ 

#define INPUT_ERROR (-1)
#define IS_PALINDROME (0)
#define IS_NOT_PALINDROME (1)

int ReverseNumber(_checkNum)
{
	int revNum = 0;
	int lastDig;
	
	while (_checkNum != 0)
	{
		revNum *= 10;
		lastDig = _checkNum % 10;
		revNum += lastDig;
		_checkNum /= 10;
	}
	
	return revNum;
}

int main(void)
{
	int origNum, checkNum, revNum;
	
	printf("Please enter a number [original number]: ");
	scanf("%d", &origNum);
	printf("Please enter a number to check: ");
	scanf("%d", &checkNum);
	
	if (origNum < 0 || checkNum < 0)
	{
		printf("Input Error\n");
		return INPUT_ERROR;
	}
	
	revNum = ReverseNumber(checkNum);
	
	if (origNum == revNum)
	{
		printf("Is palindrome\n");
		return IS_PALINDROME;
	}
	else
	{
		printf("Is not palindrome\n");
		return IS_NOT_PALINDROME;
	}
}
