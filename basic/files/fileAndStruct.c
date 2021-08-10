#include <stdio.h> /* printf, fopen, fclose, fputs, fprintf */ 

#define STR_NAME_SIZE 30

#define SUCCESS (0)
#define FAILURE (1)

/***************************************************************************/

typedef struct Person
{
	int m_id;
	char m_name[STR_NAME_SIZE];
	int m_age;
	int m_education;
} Person_t;

/***************************************************************************/

int CreateStructPersonAndWriteToFile(void)
{
	FILE *newFile = NULL;
	int status, i;
	Person_t signersArr[] = 
	{ 
		{111222333, "Eyal Golan", 50, 8}, 
		{222333444, "Omer Adam", 26, 12}, 
		{333444555, "Moshe Peretz", 33, 12} 
	};
	int personArrSize = sizeof(signersArr) / sizeof(signersArr[0]);

	newFile = fopen("CreateStructPersonAndWriteToFile.txt", "w+");
	if (NULL == newFile)
	{
		return FAILURE;
	}
	
	for (i = 0;i < personArrSize;++i)
	{
		fprintf(newFile, "Struct member %d:\n", i + 1);
		fprintf(newFile, "ID number: %d\n", signersArr[i].m_id);
		fprintf(newFile, "Full name: %s\n", signersArr[i].m_name);
		fprintf(newFile, "Age: %d\n", signersArr[i].m_age);
		fprintf(newFile, "Years of dduction: %d\n\n", signersArr[i].m_education);
	}
	
	fclose(newFile);
	
	return SUCCESS;
}


int main(void)
{
	int status;
	
	status = CreateStructPersonAndWriteToFile();
	
	(status == SUCCESS) ? fputs("Create and write was succeeded\n", stdout) : fputs("Create and write was failed\n", stdout);

	return 0;
}
