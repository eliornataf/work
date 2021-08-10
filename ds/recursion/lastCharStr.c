#include <stdio.h> /* printf */
#include <string.h> /* strlen */

#define STR_LENGTH (100)
#define POINTER_IS_NOT_INITIALIZE ('\0')

char LastCharStrRecu(char *_str)
{
	if (_str[1] == '\0')
	{		
		return *_str;
	}

	return LastCharStrRecu(_str + 1);
}

char LastCharStr(char *_str)
{
	size_t strSize = strlen(_str);

	if (!_str)
	{
		return POINTER_IS_NOT_INITIALIZE;
	}
	
	if (!strSize || strSize == 1)
	{
		return *_str;
	}
	
	return LastCharStrRecu(_str);
}

int main(void)
{
	char strTest[STR_LENGTH];
	
	printf("Please enter a string: ");
	scanf("%s", strTest);

	printf("%s last character is: %c\n", strTest, LastCharStr(strTest));
	
	return 0;	
}
