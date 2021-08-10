#include <stdio.h> /* printf, fopen, fclose, fgets, fputs, fprintf */ 

#define STR_LENGHT 100

#define SUCCESS (0)
#define FAILURE (1)

int CreateAndWriteFile(void)
{
	FILE *newFile = NULL;
	char buffer[STR_LENGHT];
	int status;

	newFile = fopen("CreateAndWriteFile.txt", "a+");
	if (NULL == newFile)
	{
		return FAILURE;
	}
	
	fputs("Your Text:\n", newFile);
	
	printf("Please enter a string: ");
	fgets(buffer, STR_LENGHT, stdin);
	
	fputs(buffer, newFile);
	
	printf("Please enter another string: ");
	fgets(buffer, STR_LENGHT, stdin);
	
	fprintf(newFile, "%s", buffer);
	fputs("\n", newFile);
	
	fclose(newFile);
	
	return SUCCESS;
}

int main(void)
{
	int status;
	
	status = CreateAndWriteFile();
	
	(status == SUCCESS) ? fputs("Create and write was succeeded\n", stdout) : fputs("Create and write was failed\n", stdout);
	
	return 0;
}


