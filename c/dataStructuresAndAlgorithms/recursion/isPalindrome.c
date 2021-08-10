#include <stdio.h> /* printf */
#include <string.h> /* strlen */

#define STR_LENGTH (100)
#define ARRAY_IS_EMPTY (-2)
#define POINTER_IS_NOT_INITIALIZE (-1)
#define IS_NOT_PALINDROME (0)
#define IS_PALINDROME (1)

int IsPalindromeRecu(char *_str, size_t _strSize)
{
	if (_strSize <= 1)
	{
		return IS_PALINDROME;
	}
	
	if (*_str != _str[_strSize - 1])
	{
		return IS_NOT_PALINDROME;
	}	
	
	return IsPalindromeRecu(_str + 1, _strSize - 2);
}

int IsPalindrome(char *_str)
{
	size_t strSize = strlen(_str);

	if (!_str)
	{
		return POINTER_IS_NOT_INITIALIZE;
	}
	
	if (!strSize)
	{
		return ARRAY_IS_EMPTY;
	}
	
	return IsPalindromeRecu(_str, strSize);
}

int main(void)
{
	char strTest[STR_LENGTH];
	int returnValueIsPalindrome;
	
	printf("Please enter a string: ");
	scanf("%s", strTest);

	returnValueIsPalindrome = IsPalindrome(strTest);
	
	returnValueIsPalindrome == IS_PALINDROME ? printf("%s is palindrome\n", strTest) : printf("%s is not palindrome\n", strTest);
	
	return 0;	
}
