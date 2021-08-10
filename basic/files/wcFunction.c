#include <stdio.h> /* fopen, fclose, printf, fread, fputs */ 

#define SUCCESS (0)
#define FAILURE (1)

#define READ_ONE_CHAR 1
#define ONE_CHAR_READED 1

#define WAITING_FOR_SPACE (0)
#define SPACE_FOUND (1)

int WcFunc(void)
{
	FILE *newFile = NULL;
	char buffer[1];
	size_t chars = 0;
	size_t words = 0;
	size_t lines = 0;
	int spaceFlag = WAITING_FOR_SPACE;

	newFile = fopen("gatsby.txt", "r+");
	if (NULL == newFile)
	{
		return FAILURE;
	}
	
	while (ONE_CHAR_READED == fread(buffer, sizeof(char), READ_ONE_CHAR, newFile))
	{
		++chars;
		
		if (' ' == *buffer || '\t' == *buffer)
		{
			spaceFlag = SPACE_FOUND;
		}
		else if ('\n' == *buffer)
		{
			spaceFlag = SPACE_FOUND;
			++lines;
		}
		else
		{
			if (SPACE_FOUND == spaceFlag)
			{
				++words;
			}
			
			spaceFlag = WAITING_FOR_SPACE;
		}
	}
	
	printf("Number of lines: %ld\nNumber of words: %ld\nNumber of chars: %ld\n", lines, words, chars);

	fclose(newFile);
	
	return SUCCESS;
}

int main(void)
{
	int status;
	
	status = WcFunc();
	
	(status == SUCCESS) ? fputs("Count was succeeded\n", stdout) : fputs("Count was failed\n", stdout);

	return 0;
}
