#include <string.h> /* strlen */
#include "string.h" /* string header */
#include <stdlib.h> /* abs */

#define MiNUS_PLUS_OR_NUM_IS_NOT_FOUND (0)
#define MiNUS_PLUS_OR_NUM_IS_FOUND (1)

#define ZERO_IN_ASCII_TABLE (48)
#define BASE_10 (10)

#define PLUS_SIGN (1)
#define MINUS_SIGN (-1)

/****************************************************************************/

int CountDigit(int _num)
{
	int count = 0;
	
	while (_num != 0)
	{
		++count;
		_num /= 10;
	}
	
	return count;
}

char *ReverseStr(char str[])
{
	int strSize = strlen(str);
	int i;
	
	if (strSize < 2)
	{
		return NULL;
	}
	
	for (i = 0;i < strSize / 2;++i)
	{
		char temp = str[i];
		str[i] = str[strSize - 1 - i];
		str[strSize - 1 - i] = temp;
	}
	
	return str;
}

int Atoi(const char *str)
{	
	int str2num = 0;
	int status = MiNUS_PLUS_OR_NUM_IS_NOT_FOUND;
	int sign = PLUS_SIGN;

	while (*str != '\0')
	{
		if (' ' == *str && (MiNUS_PLUS_OR_NUM_IS_NOT_FOUND == status) )
		{
			++str;
		}
		else if ('+' == *str && MiNUS_PLUS_OR_NUM_IS_NOT_FOUND == status)
		{
			status = MiNUS_PLUS_OR_NUM_IS_FOUND;
			++str;
		}
		else if ('-' == *str && MiNUS_PLUS_OR_NUM_IS_NOT_FOUND == status)
		{
			status = MiNUS_PLUS_OR_NUM_IS_FOUND;
			sign = MINUS_SIGN;
			++str;
		}
		else if (ZERO_IN_ASCII_TABLE <= *str && *str <= ZERO_IN_ASCII_TABLE + 9)
		{
			status = MiNUS_PLUS_OR_NUM_IS_FOUND;
			str2num *= BASE_10;
			str2num += *str - ZERO_IN_ASCII_TABLE;
			++str;
		}
		else
		{
			break;
		}
	}
	
	return str2num * sign;
}

char *Itoa(int value, char *str, int base)
{
	int numOfDigits = CountDigit(value);
	char *strFirstLocation = str;
	int strStrlen = 0;
	int lastDig, i;
	
	if (value < 0)
	{
		str[0] = '-';
		++strStrlen;
	}
	
	strStrlen += numOfDigits;
	
	for (i = strStrlen - 1;value != 0;--i)
	{
		lastDig = abs(value % 10);
		str[i] = lastDig + ZERO_IN_ASCII_TABLE;
		value /= 10;
	}
	
	str[strStrlen] = '\0';
	
	return strFirstLocation;
}
