#include <stdio.h> /* fopen, fclose, printf, getc, feof */ 

#define SUCCESS (0)
#define FAILURE (1)

#define HALF_ASCII_TABLE (127)
#define FIRST_CAP_LETTER_ASCII (65)
#define LAST_CAP_LETTER_ASCII (90)

#define FIRST_LETTER_ASCII (97)
#define LAST_LETTER_ASCII (122)

int calcFreqInFile(void)
{
	FILE *newFile = NULL;
	int FreqArr[HALF_ASCII_TABLE] = {0};
	int currChar, i;
	
	newFile = fopen("gatsby.txt", "r+");
	if (NULL == newFile)
	{
		return FAILURE;
	}
	
	while (!feof(newFile))
	{
		currChar = getc(newFile);
		
		if ( (FIRST_CAP_LETTER_ASCII <= currChar && currChar <= LAST_CAP_LETTER_ASCII)
			|| (FIRST_LETTER_ASCII <= currChar && currChar <= LAST_LETTER_ASCII) )
		{
			++FreqArr[currChar];
		}
	}
	
	fclose(newFile);
	
	for (i = FIRST_CAP_LETTER_ASCII;i <= LAST_CAP_LETTER_ASCII;++i)
	{
		if (0 != FreqArr[i])
		{
			printf("%c: %d\n", i, FreqArr[i]);
		}
	}
	
	for (i = FIRST_LETTER_ASCII;i <= LAST_LETTER_ASCII;++i)
	{
		if (0 != FreqArr[i])
		{
			printf("%c: %d\n", i, FreqArr[i]);
		}
	}

	return SUCCESS;	
}

int main(void)
{
	int status;
	
	status = calcFreqInFile();
	
	(status == SUCCESS) ? fputs("Calc freq was succeeded\n", stdout) : fputs("Calc freq was failed\n", stdout);

	return 0;
}
