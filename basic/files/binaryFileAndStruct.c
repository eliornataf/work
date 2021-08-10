#include <stdio.h> /* printf, fopen, fclose, fwrite, fread, fseek, fputs */ 

#define STR_LENGTH 10000

#define STRUCT_ARR_SIZE 3

#define SUCCESS (0)
#define FAILURE (1)

/***************************************************************************/

typedef struct Person
{
	int m_id;
	char m_name[STR_LENGTH];
	int m_age;
	int m_education;
} Person_t;

/***************************************************************************/

int CreateStructPersonAndWriteToFile(void)
{
	Person_t signersArr[] = 
	{ 
		{111222333, "Eyal Golan", 50, 8}, 
		{222333444, "Omer Adam", 26, 12}, 
		{333444555, "Moshe Peretz", 33, 12} 
	};
	size_t personArrSize = sizeof(signersArr) / sizeof(signersArr[0]);
	Person_t copySignersArr[STRUCT_ARR_SIZE];
	FILE *newFile = NULL;
	int status, i;

	newFile = fopen("BinaryCreateStructPersonAndWriteToFile.bin", "w+");
	if (NULL == newFile)
	{
		return FAILURE;
	}

	fwrite(&signersArr, sizeof(Person_t), 4, newFile);
	
	fseek(newFile, 0, SEEK_SET);
	
	for (i = 0;i < personArrSize;++i)
	{
		fread(&copySignersArr[i], sizeof(Person_t), 1, newFile);
		printf("Struct member %d:\n", i + 1);
		printf("ID number: %d\n", copySignersArr[i].m_id);
		printf("Full name: %s\n", copySignersArr[i].m_name);
		printf("Age: %d\n", copySignersArr[i].m_age);
		printf("Years of eduction: %d\n\n", copySignersArr[i].m_education);
	}
	
	fclose(newFile);
	
	return SUCCESS;
}

int main(void)
{
	int status;
	
	status = CreateStructPersonAndWriteToFile();
	
	(status == SUCCESS) ? fputs("Create and write and read was succeeded\n", stdout) : fputs("Create and write and read was failed\n", stdout);

	return 0;
}
