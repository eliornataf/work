#include <stdio.h> /* printf */

#define STR_NAME_SIZE 30

typedef struct 
{
	int id;
	char name[STR_NAME_SIZE];
	int age;
	int education;
} person;

/***************************************************************************/

void PrintPersonArray(person *personArr, int personArrSize)
{
	int i;

	for (i = 0;i < personArrSize;++i)
	{
		printf("Array i = %d\n", i);
		printf("ID -> %d\n", personArr[i].id);
		printf("Name -> %s\n", personArr[i].name);
		printf("Age -> %d\n", personArr[i].age);
		printf("Education -> %d\n\n", personArr[i].education);
	}
}

/***************************************************************************/

void Step1(void)
{
	person eg = {123456789, "Eyal Golan", 50, 6}; 
	person *peg = &eg;

	printf("***********Step 1:***********\n\n");
	
	printf("eg, struct person:\n");
	
	printf("ID -> %d\nName -> %s\nAge -> %d\nEducation -> %d\n", eg.id, eg.name, eg.age, eg.education);
	
	printf("\n*peg, struct person:\n");
	
	printf("ID -> %d\nName -> %s\nAge -> %d\nEducation -> %d\n\n", peg->id, peg->name, peg->age, peg->education);
}

void Step2(void)
{
	person personArr[] = 
	{ 
		{333444555, "Haim Moshe", 46, 8}, 
		{222333444, "Omer Adam", 26, 12}, 
		{111222333, "Moshe Peretz", 33, 12} 
	};
	int personArrSize = sizeof(personArr) / sizeof(personArr[0]);
	int i, j;
	
	printf("***********Step 2:***********\n\n");
	
	printf("Person array elements:\n\n");
	
	PrintPersonArray(personArr, personArrSize);
	
	/* Sort by ID */
	
	for (i = 0;i < personArrSize - 1;++i)
	{
		for (j = i;0 <= j && personArr[j + 1].id < personArr[j].id;--j)
		{
			person temp = personArr[j];
			personArr[j] = personArr[j + 1];
			personArr[j + 1] = temp;
		}
	}
	
	printf("After Sort by ID:\n\n");
	
	PrintPersonArray(personArr, personArrSize);
	
	/* Sort by name */
	
	for (i = 0;i < personArrSize - 1;++i)
	{
		for (j = i;0 <= j && 0 < strcmp(personArr[j].name, personArr[j + 1].name);--j)
		{
			person temp = personArr[j];
			personArr[j] = personArr[j + 1];
			personArr[j + 1] = temp;
		}
	}
	
	printf("After Sort by name:\n\n");
	
	PrintPersonArray(personArr, personArrSize);
}

int main(void)
{
	Step1();
	
	Step2();
	
	return 0;
}
