#include <stdio.h> /* fopen, fclose, printf, fscanf */ 
#include <string.h> /* strcmp, strcpy */

#define SUCCESS (0)
#define FAILURE (1)

#define STR_LENGTH (100)
#define NUM_OF_WORDS (10000)
#define WORD_LENGTH (100)

#define WORD_IS_NOT_FOUND (0)
#define WORD_IS_FOUND (1)

int calcWordsFreqInFile(void)
{
	FILE *newFile = NULL;
	char buffer[STR_LENGTH];
	int countWordsNumOfFrqu[NUM_OF_WORDS] = {0};
	char ArrOfWords[NUM_OF_WORDS][WORD_LENGTH];
	size_t countNumOfWordsInArr = 0;
	int wordIsFound;
	size_t i;

	newFile = fopen("gatsby.txt", "r+");
	if (NULL == newFile)
	{
		return FAILURE;
	}

	while (EOF != fscanf(newFile, "%s", buffer))
	{
		wordIsFound = WORD_IS_NOT_FOUND;
		
		for (i = 0;i < countNumOfWordsInArr;++i)
		{
			if (!strcmp(buffer, ArrOfWords[i]))
			{
				++countWordsNumOfFrqu[i];
				wordIsFound = WORD_IS_FOUND;
				break;
			} 
		}
		
		if (!wordIsFound)
		{
			strcpy(ArrOfWords[countNumOfWordsInArr], buffer);
			++countWordsNumOfFrqu[countNumOfWordsInArr];
			++countNumOfWordsInArr;
		}
	}
	
	fclose(newFile);
	
	for (i = 0;i < countNumOfWordsInArr;++i)
	{
		printf("%s: %d\n", ArrOfWords[i], countWordsNumOfFrqu[i]);
	}
	
	return SUCCESS;	
}

int main(void)
{
	int status;
	
	status = calcWordsFreqInFile();
	
	(status == SUCCESS) ? fputs("Calc words freq was succeeded\n", stdout) : fputs("Calc words freq was failed\n", stdout);

	return 0;
}
