#include <stdio.h> /* printf, scanf */
#include "string.h" /* string header */
#include <stdlib.h> /* malloc */

#define STR_SIZE 100
#define INT_MAX_DIGIT 12
#define BASE_10 10

/*****************************************************************************/

void ReverseStrTest(void)
{
	char str[STR_SIZE];
	char *strAfterReverse;
	
	printf("Please enter a string: ");
	scanf("%s", str);
	
	strAfterReverse = ReverseStr(str);
	
	if (NULL == strAfterReverse)
	{
		printf("String input size error\n");
		return;
	}
	
	printf("\nThe string after reverse is: %s\n", strAfterReverse);
}

void AtoiTest(void)
{
	char *str = "   -123456.789";
	int str2num;
	
	str2num = Atoi(str);
	
	printf("%s after convert is: %d\n", str, str2num);
}

void ItoaTest(void)
{
	int num;
	char *num2str = (char*)malloc(INT_MAX_DIGIT * (sizeof(char)));
	
	printf("Please enter a number: ");
	scanf("%d", &num);
	
	num2str = Itoa(num, num2str, BASE_10);
	
	printf("%d after convert is: %s\n", num, num2str);
}

int main(void)
{
	printf("ReverseStrTest:\n\n");
	ReverseStrTest();
	
	printf("\nAtoiTest:\n\n");
	AtoiTest();
	
	printf("\nItoaTest:\n\n");
	ItoaTest();
	
	return 0;
}
