#include <stdio.h> /* printf, scanf, putchar */

#define SUCCESS (0)
#define FAILURE (1)

#define BITS_IN_BYTE (8)
#define NUM_OF_BITS sizeof(unsigned int) * BITS_IN_BYTE

#define STR_LENGTH 100

#define IS_NOT_SET (0)
#define IS_SET (1)

/*****************************************************************************/

typedef struct Byte
{
	unsigned char m_lowBits : BITS_IN_BYTE / 2;
	unsigned char m_highBits : BITS_IN_BYTE / 2;
} Byte_t;

/*****************************************************************************/

static void PrintStrBits(char *_strToConvert)
{
	size_t i;
	int j;
	
	for (i = 0;_strToConvert[i] != '\0';++i)
	{
		unsigned int currBit = _strToConvert[i];
			
		for (j = BITS_IN_BYTE - 1;0 <= j;--j)
		{
			(currBit & (1 << j)) ? putchar('1') : putchar('0');
		}
	}
}

/*****************************************************************************/

int ConvertStrTextToBitsBitField(char *_strToConvert)
{
	Byte_t *byte = NULL;
	int isFirstChSet = IS_NOT_SET;
	int isSecondChSet = IS_NOT_SET;
	size_t indexAfterConvert = 0;
	size_t i;
	
	if (NULL == _strToConvert)
	{
		return FAILURE;
	}
	
	for (i = 0;_strToConvert[i] != '\0';++i)
	{
		byte = (Byte_t*)&_strToConvert[indexAfterConvert];
	
		if (_strToConvert[i] < 'a' || 'o' < _strToConvert[i])
		{
			return FAILURE;
		}
		
		if (i % 2 == 0)
		{
			byte->m_highBits = _strToConvert[i] - 'a' + 1;
			isFirstChSet = IS_SET;
		}
		else if (i % 2 != 0)
		{
			byte->m_lowBits = _strToConvert[i]- 'a' + 1;
			isSecondChSet = IS_SET;
		}
		
		if (isFirstChSet && isSecondChSet)
		{
			isFirstChSet = IS_NOT_SET;
			isSecondChSet = IS_NOT_SET;
			++indexAfterConvert;
		}
	}

	if (isFirstChSet)
	{
		byte->m_lowBits = 0;
		++indexAfterConvert;
	}
	
	_strToConvert[indexAfterConvert] = '\0';
	
	return SUCCESS;
}

int main(void)
{
	char strToConvert[STR_LENGTH];
	int status;
	
	printf("Please enter a string to convert: ");
	scanf("%s", strToConvert);
	
	status = ConvertStrTextToBitsBitField(strToConvert);
	
	if (!status)
	{
		printf("\nStr after convert:\n");
	
		PrintStrBits(strToConvert);
	
		putchar('\n');	
	}
	else
	{
		printf("Input Error!\n");
	}
	
	
	return 0;
}
