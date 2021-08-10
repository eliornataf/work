#include <stdio.h> /* printf, scanf */
#include "stack.h" /* Stack Header */

#define STR_LENGTH (100)
#define PARANTHESIS_IS_NOT_BALANCED (0)
#define PARANTHESIS_IS_BALANCED (1)

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

int isSameParenthesisPairs(char strCharToCheck, char popCharToCheck)
{
	if ( (strCharToCheck == ')' && popCharToCheck == '(') 
		|| (strCharToCheck == ']' && popCharToCheck == '[') 
			|| (strCharToCheck == '}' && popCharToCheck == '{') )
	{
		return PARANTHESIS_IS_BALANCED;
	} 

	return PARANTHESIS_IS_NOT_BALANCED;
}

int checkParenthesis(char *_str, size_t _stackCapacity, size_t _stackIncBlockSize, ADTError_t *_status)
{
	int i, outputData;

	Stack_t *Stack = StackCreate(_stackCapacity, _stackIncBlockSize);
	if (!Stack)
	{
		*_status = POINTER_NOT_INITIALIZE;
		return PARANTHESIS_IS_NOT_BALANCED;
	}
	
	for (i = 0;_str[i] != '\0';++i)
	{
		if ('(' == _str[i] || '[' == _str[i] || '{' == _str[i])
		{
			*_status = StackPush(Stack, _str[i]);
			if (OK != *_status)
			{
				return PARANTHESIS_IS_NOT_BALANCED;
			}
		}
		else if (')' == _str[i] || ']' == _str[i] || '}' == _str[i])
		{
			if (StackIsEmpty(Stack))
			{
				return PARANTHESIS_IS_NOT_BALANCED;
			}
		
			*_status = StackPop(Stack, &outputData);
			if (OK != *_status)
			{
				return PARANTHESIS_IS_NOT_BALANCED;
			}
			
			if(!isSameParenthesisPairs(_str[i], outputData))
			{
				return PARANTHESIS_IS_NOT_BALANCED;
			}
		}
	}
	
	if (!StackIsEmpty(Stack))
	{
		return PARANTHESIS_IS_NOT_BALANCED;
	}
	
	StackDestroy(Stack);
	
	return PARANTHESIS_IS_BALANCED;
}

void checkParenthesisTest(void)
{
	size_t stackCapacity = 10;
	size_t stackIncBlockSize = 5;
	ADTError_t status = OK;
	char strToCheck[STR_LENGTH];
	int isBalanced;
	
	printf("\033[1;34m\n*******Check Parenthesis Test:*******\n\n\033[0m");

	printf("Please enter a string to check: ");
	scanf("%s", strToCheck);
	
	isBalanced = checkParenthesis(strToCheck, stackCapacity, stackIncBlockSize, &status);
	
	if (OK == status)
	{
		isBalanced == PARANTHESIS_IS_BALANCED? printf("\nThe string parenthesis is balanced\n") : printf("\nThe string parenthesis is not balanced\n");
	}
	else
	{
		printf("Error in stack functions\n");
	}
}

/*******************************************************
******************** Main Functions ********************
*******************************************************/

int main(void)
{
	checkParenthesisTest();

	return 0;	
}
