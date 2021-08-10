#include <stdio.h> /* printf */
#include <string.h> /* strlen */

#define STR_LENGTH 100

void ReverseStrRecu(char *_str, size_t _strSize)
{
	char temp = '\0';

	if (_strSize <= 1)
	{
		return;
	}	
	
	temp = *_str;
	*_str = _str[_strSize - 1];
	_str[_strSize - 1] = temp;
	
	ReverseStrRecu(_str + 1, _strSize - 2);
}

void ReverseStr(char *_str)
{
	size_t strSize = strlen(_str);

	if (!_str)
	{
		return;
	}
	
	if (!strSize)
	{
		return;
	}
	
	ReverseStrRecu(_str, strSize);
}

int main(void)
{
	char strTest[STR_LENGTH];
	
	printf("Please enter a string: ");
	scanf("%s", strTest);

	ReverseStr(strTest);

	printf("The reversed string is: %s\n", strTest);
	
	return 0;	
}
