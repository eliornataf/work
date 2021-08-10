#include <stdio.h> /* fopen, fclose, printf, fread, fseek, ftell, getc, feof */ 

#define SUCCESS (0)
#define FAILURE (1)

#define FILE_BEGIN_POS (1)

int TailFunc(size_t numOfLines)
{
	FILE *newFile = NULL;
	size_t countLines = 0;
	int currIndex = -2;
	int currChar;

	newFile = fopen("gatsby.txt", "r+");
	if (NULL == newFile)
	{
		return FAILURE;
	}

	fseek(newFile, currIndex, SEEK_END);

	while (FILE_BEGIN_POS != ftell(newFile))
	{	
		currChar = getc(newFile);
		
		if ('\n' == currChar)
		{
			++countLines;
		}
		
		if (numOfLines == countLines)
		{
			break;
		}
		
		--currIndex;
		
		fseek(newFile, currIndex, SEEK_END);
	}
	
	while (!feof(newFile))
	{
		printf("%c", getc(newFile));
	}

	fclose(newFile);
	
	return SUCCESS;
}

int main(void)
{
	int status, numOfLines;
	
	printf("\nPlease enter number of lines to print (prints from the end of the file): ");
	scanf("%d", &numOfLines);
	
	status = TailFunc(numOfLines);
	
	(status == SUCCESS) ? fputs("Tail was succeeded\n", stdout) : fputs("Tail was failed\n", stdout);

	return 0;
}
