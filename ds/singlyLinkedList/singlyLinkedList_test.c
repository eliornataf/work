#include <stdlib.h> /* malloc, free */
#include <stdio.h> /* printf */
#include <string.h> /* strcpy */
#include "singlyLinkedList.h" /* Singly Linked List Header */

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

void ListInsertHeadTest1(void)
{
	Person_t *head = NULL;
	Person_t *personTest = (Person_t*)malloc(sizeof(Person_t));
	
	printf("\033[1;34m\n*******Insert Head Test 1:*******\n\n\033[0m");
	
	printf("Insert Head Func Test: ");
	
	head = ListInsertHead(head, personTest);
	
	CHECK_FUNC(NULL != head);

	printf("\nExpected: SUCCESS (NULL != head)\n");

	free(personTest);	
}

void ListInsertHeadTest2(void)
{
	Person_t *head = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest = (Person_t*)malloc(sizeof(Person_t));
	
	head->m_id = 111;
	strcpy(head->m_name, "Elior");
	head->m_age = 31;
	head->m_next = NULL;
	
	personTest->m_id = 222;
	strcpy(personTest->m_name, "Hadar");
	personTest->m_age = 29;
	personTest->m_next = NULL;
	
	printf("\033[1;34m\n*******Insert Head Test 2:*******\n\n\033[0m");
	
	printf("Insert Head Func Test: ");

	head = ListInsertHead(head, personTest);
	
	CHECK_FUNC(NULL != head->m_next);

	printf("\nExpected: SUCCESS (NULL != head->m_next)\n");

	free(head->m_next);	
	free(head);	
}

void ListInsertHeadTest3(void)
{
	Person_t *head = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest = NULL;
	
	head->m_id = 111;
	strcpy(head->m_name, "Elior");
	head->m_age = 31;
	head->m_next = NULL;
	
	printf("\033[1;34m\n*******Insert Head Test 3:*******\n\n\033[0m");

	printf("Insert Head Func Test: ");

	head = ListInsertHead(head, personTest);

	CHECK_FUNC(NULL == head->m_next);

	printf("\nExpected: SUCCESS (NULL == head->m_next)\n");

	free(head);	
}

void ListRemoveHeadTest1(void)
{
	Person_t *head = NULL;
	Person_t *outputData = NULL; 
	
	printf("\033[1;34m\n*******Remove Head Test 1:*******\n\n\033[0m");
	
	printf("Remove Head Func Test: ");
	
	head = ListRemoveHead(head, &outputData);
	
	CHECK_FUNC(NULL == head);

	printf("\nExpected: SUCCESS (NULL == head)\n");
}

void ListRemoveHeadTest2(void)
{
	Person_t *head = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest = (Person_t*)malloc(sizeof(Person_t));
	Person_t *outputData = NULL; 
	
	head->m_id = 111;
	strcpy(head->m_name, "Elior");
	head->m_age = 31;
	head->m_next = NULL;
	
	personTest->m_id = 222;
	strcpy(personTest->m_name, "Hadar");
	personTest->m_age = 29;
	personTest->m_next = NULL;
	
	printf("\033[1;34m\n*******Remove Head Test 2:*******\n\n\033[0m");
	
	printf("Insert Head Func Test: ");

	head = ListInsertHead(head, personTest);
	
	CHECK_FUNC(NULL != head->m_next);

	printf("\nExpected: SUCCESS (NULL != head->m_next)\n");
	
	printf("\nRemove Head Func Test 1: ");
	
	head = ListRemoveHead(head, &outputData);
	
	CHECK_FUNC(NULL == head->m_next);

	printf("\nExpected: SUCCESS (NULL == head->m_next)\n");
	
	printf("\nRemove Head Func Test 2: ");
	
	CHECK_FUNC(222 == outputData->m_id);
	
	printf("\nExpected: SUCCESS (outputData test)\n");
	
	free(head);
	free(personTest);
}

void ListRemoveHeadTest3(void)
{
	Person_t *head = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest2 = (Person_t*)malloc(sizeof(Person_t));
	Person_t *outputData = NULL; 
	
	head->m_id = 111;
	strcpy(head->m_name, "Elior");
	head->m_age = 31;
	head->m_next = NULL;
	
	personTest->m_id = 222;
	strcpy(personTest->m_name, "Hadar");
	personTest->m_age = 29;
	personTest->m_next = NULL;
	
	personTest2->m_id = 333;
	strcpy(personTest2->m_name, "Moshe");
	personTest2->m_age = 26;
	personTest2->m_next = NULL;
	
	printf("\033[1;34m\n*******Remove Head Test 3:*******\n\n\033[0m");
	
	printf("Insert Head Func Test: ");

	head = ListInsertHead(head, personTest);
	head = ListInsertHead(head, personTest2);
	
	CHECK_FUNC(personTest == head->m_next);

	printf("\nExpected: SUCCESS (NULL != head->m_next)\n");
	
	printf("\nRemove Head Func Test 1: ");
	
	head = ListRemoveHead(head, &outputData);
	head = ListRemoveHead(head, &outputData);
	head = ListRemoveHead(head, &outputData);
	
	CHECK_FUNC(NULL == head);

	printf("\nExpected: SUCCESS (NULL == head)\n");
	
	printf("\nRemove Head Func Test 2: ");
	
	CHECK_FUNC(111 == outputData->m_id);
	
	printf("\nExpected: SUCCESS (outputData test)\n");

	free(personTest);
	free(personTest2);
	free(head);
}

void ListInsertByKeyTest1(void)
{
	Person_t *head = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest2 = (Person_t*)malloc(sizeof(Person_t));
	Person_t *outputData = NULL; 
	
	head->m_id = 111;
	strcpy(head->m_name, "Elior");
	head->m_age = 31;
	head->m_next = NULL;
	
	personTest->m_id = 222;
	strcpy(personTest->m_name, "Hadar");
	personTest->m_age = 29;
	personTest->m_next = NULL;
	
	personTest2->m_id = 333;
	strcpy(personTest2->m_name, "Moshe");
	personTest2->m_age = 26;
	personTest2->m_next = NULL;
	
	printf("\033[1;34m\n*******Insert By Key Test 1:*******\n\n\033[0m");
	
	printf("Insert By Key Func Test: ");

	head = ListInsertByKey(head, 333, personTest2);
	head = ListInsertByKey(head, 222, personTest);
	
	CHECK_FUNC(29 == head->m_next->m_age);

	printf("\nExpected: SUCCESS (head->m_next->m_age)\n");
	
	printf("\nRemove Head Func Test 1: ");
	
	head = ListRemoveHead(head, &outputData);
	
	CHECK_FUNC(NULL != head->m_next);

	printf("\nExpected: SUCCESS (NULL != head->m_next)\n");
	
	printf("\nRemove Head Func Test 2: ");
	
	CHECK_FUNC(111 == outputData->m_id);
	
	printf("\nExpected: SUCCESS (outputData test)\n");
	
	free(personTest);
	free(personTest2);
}

void ListInsertByKeyTest2(void)
{
	Person_t *head = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest = NULL;
	
	head->m_id = 111;
	strcpy(head->m_name, "Elior");
	head->m_age = 31;
	head->m_next = NULL;
	
	printf("\033[1;34m\n*******Insert By Key Test 2:*******\n\n\033[0m");
	
	printf("Insert By Key Func Test: ");

	head = ListInsertByKey(head, 999, personTest);
	
	CHECK_FUNC(NULL == head->m_next);

	printf("\nExpected: SUCCESS (NULL == head->m_next)\n");
	
	free(head);
}

void ListInsertByKeyTest3(void)
{
	Person_t *head = NULL;
	Person_t *personTest = (Person_t*)malloc(sizeof(Person_t));
	
	personTest->m_id = 222;
	strcpy(personTest->m_name, "Hadar");
	personTest->m_age = 29;
	personTest->m_next = NULL;
	
	printf("\033[1;34m\n*******Insert By Key Test 3:*******\n\n\033[0m");
	
	printf("Insert By Key Func Test: ");

	head = ListInsertByKey(head, 999, personTest);
	
	CHECK_FUNC(222 == head->m_id);

	printf("\nExpected: SUCCESS (test head->m_id)\n");
	
	free(head);
}

void ListInsertByKeyTest4(void)
{
	Person_t *head = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest = (Person_t*)malloc(sizeof(Person_t));
	
	head->m_id = 111;
	strcpy(head->m_name, "Elior");
	head->m_age = 31;
	head->m_next = NULL;
	
	personTest->m_id = 111;
	strcpy(personTest->m_name, "Hadar");
	personTest->m_age = 29;
	personTest->m_next = NULL;
	
	printf("\033[1;34m\n*******Insert By Key Test 4:*******\n\n\033[0m");
	
	printf("Insert By Key Func Test: ");

	head = ListInsertByKey(head, 111, personTest);
	
	CHECK_FUNC(NULL == head->m_next);

	printf("\nExpected: SUCCESS (NULL == head->m_next)\n");
	
	free(head);
	free(personTest);
}

void ListInsertByKeyTest5(void)
{
	Person_t *head = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest = (Person_t*)malloc(sizeof(Person_t));
	
	head->m_id = 111;
	strcpy(head->m_name, "Elior");
	head->m_age = 31;
	head->m_next = NULL;
	
	personTest->m_id = 000;
	strcpy(personTest->m_name, "Hadar");
	personTest->m_age = 29;
	personTest->m_next = NULL;
	
	printf("\033[1;34m\n*******Insert By Key Test 5:*******\n\n\033[0m");
	
	printf("Insert By Key Func Test: ");

	head = ListInsertByKey(head, 000, personTest);
	
	CHECK_FUNC(000 == head->m_id);

	printf("\nExpected: SUCCESS (head->m_id test)\n");
	
	free(personTest);
}

void ListInsertByKeyRecuTest1(void)
{
	Person_t *head = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest2 = (Person_t*)malloc(sizeof(Person_t));
	Person_t *outputData = NULL; 
	
	head->m_id = 111;
	strcpy(head->m_name, "Elior");
	head->m_age = 31;
	head->m_next = NULL;
	
	personTest->m_id = 222;
	strcpy(personTest->m_name, "Hadar");
	personTest->m_age = 29;
	personTest->m_next = NULL;
	
	personTest2->m_id = 333;
	strcpy(personTest2->m_name, "Moshe");
	personTest2->m_age = 26;
	personTest2->m_next = NULL;
	
	printf("\033[1;34m\n*******Insert By Key Recu Test 1:*******\n\n\033[0m");
	
	printf("Insert By Key Func Test: ");

	head = ListInsertByKeyRecu(head, 333, personTest2);
	head = ListInsertByKeyRecu(head, 222, personTest);
	
	CHECK_FUNC(29 == head->m_next->m_age);

	printf("\nExpected: SUCCESS (head->m_next->m_age)\n");
	
	printf("\nRemove Head Func Test 1: ");
	
	head = ListRemoveHead(head, &outputData);
	
	CHECK_FUNC(NULL != head->m_next);

	printf("\nExpected: SUCCESS (NULL != head->m_next)\n");
	
	printf("\nRemove Head Func Test 2: ");
	
	CHECK_FUNC(111 == outputData->m_id);
	
	printf("\nExpected: SUCCESS (outputData test)\n");
	
	free(personTest);
	free(personTest2);
}

void ListInsertByKeyRecuTest2(void)
{
	Person_t *head = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest = NULL;
	
	head->m_id = 111;
	strcpy(head->m_name, "Elior");
	head->m_age = 31;
	head->m_next = NULL;
	
	printf("\033[1;34m\n*******Insert By Key Recu Test 2:*******\n\n\033[0m");
	
	printf("Insert By Key Func Test: ");

	head = ListInsertByKeyRecu(head, 999, personTest);
	
	CHECK_FUNC(NULL == head->m_next);

	printf("\nExpected: SUCCESS (NULL == head->m_next)\n");
	
	free(head);
}

void ListInsertByKeyRecuTest3(void)
{
	Person_t *head = NULL;
	Person_t *personTest = (Person_t*)malloc(sizeof(Person_t));
	
	personTest->m_id = 222;
	strcpy(personTest->m_name, "Hadar");
	personTest->m_age = 29;
	personTest->m_next = NULL;
	
	printf("\033[1;34m\n*******Insert By Key Recu Test 3:*******\n\n\033[0m");
	
	printf("Insert By Key Func Test: ");

	head = ListInsertByKeyRecu(head, 999, personTest);
	
	CHECK_FUNC(222 == head->m_id);

	printf("\nExpected: SUCCESS (test head->m_id)\n");
	
	free(head);
}

void ListInsertByKeyRecuTest4(void)
{
	Person_t *head = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest = (Person_t*)malloc(sizeof(Person_t));
	
	head->m_id = 111;
	strcpy(head->m_name, "Elior");
	head->m_age = 31;
	head->m_next = NULL;
	
	personTest->m_id = 111;
	strcpy(personTest->m_name, "Hadar");
	personTest->m_age = 29;
	personTest->m_next = NULL;
	
	printf("\033[1;34m\n*******Insert By Key Recu Test 4:*******\n\n\033[0m");
	
	printf("Insert By Key Func Test: ");

	head = ListInsertByKeyRecu(head, 111, personTest);
	
	CHECK_FUNC(NULL == head->m_next);

	printf("\nExpected: SUCCESS (NULL == head->m_next)\n");
	
	free(head);
	free(personTest);
}

void ListInsertByKeyRecuTest5(void)
{
	Person_t *head = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest = (Person_t*)malloc(sizeof(Person_t));
	
	head->m_id = 111;
	strcpy(head->m_name, "Elior");
	head->m_age = 31;
	head->m_next = NULL;
	
	personTest->m_id = 000;
	strcpy(personTest->m_name, "Hadar");
	personTest->m_age = 29;
	personTest->m_next = NULL;
	
	printf("\033[1;34m\n*******Insert By Key Recu Test 5:*******\n\n\033[0m");
	
	printf("Insert By Key Func Test: ");

	head = ListInsertByKey(head, 000, personTest);
	
	CHECK_FUNC(000 == head->m_id);

	printf("\nExpected: SUCCESS (head->m_id test)\n");
	
	free(personTest);
}

void ListRemoveByKeyTest1(void)
{
	Person_t *head = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest = (Person_t*)malloc(sizeof(Person_t));
	Person_t *outputData = NULL; 
	
	head->m_id = 111;
	strcpy(head->m_name, "Elior");
	head->m_age = 31;
	head->m_next = NULL;
	
	personTest->m_id = 222;
	strcpy(personTest->m_name, "Hadar");
	personTest->m_age = 29;
	personTest->m_next = NULL;
	
	printf("\033[1;34m\n*******Remove By Key Test 1:*******\n\n\033[0m");
	
	printf("Insert By Key Func Test: ");

	head = ListInsertByKeyRecu(head, 222, personTest);
	
	CHECK_FUNC(29 == head->m_next->m_age);

	printf("\nExpected: SUCCESS (head->m_next->m_age)\n");
	
	printf("\nRemove By Key Func Test 1: ");
	
	head = ListRemoveByKey(head, 222, &outputData);
	
	CHECK_FUNC(NULL == head->m_next);

	printf("\nExpected: SUCCESS (NULL == head->m_next)\n");
	
	printf("\nRemove By Key Func Test 1: ");
	
	CHECK_FUNC(222 == outputData->m_id);
	
	printf("\nExpected: SUCCESS (outputData test)\n");
	
	free(personTest);
}

void ListRemoveByKeyTest2(void)
{
	Person_t *head = NULL;
	Person_t *outputData = NULL; 
	
	printf("\033[1;34m\n*******Remove By Key Test 2:*******\n\n\033[0m");
	
	head = ListRemoveByKey(head, 222, &outputData);

	printf("Remove By Key Func Test: ");
	
	CHECK_FUNC(NULL == head);

	printf("\nExpected: SUCCESS (NULL == head)\n");
}

void ListRemoveByKeyTest3(void)
{
	Person_t *head = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest = (Person_t*)malloc(sizeof(Person_t));
	Person_t *outputData = NULL; 
	
	head->m_id = 111;
	strcpy(head->m_name, "Elior");
	head->m_age = 31;
	head->m_next = NULL;
	
	personTest->m_id = 222;
	strcpy(personTest->m_name, "Hadar");
	personTest->m_age = 29;
	personTest->m_next = NULL;
	
	printf("\033[1;34m\n*******Remove By Key Test 3:*******\n\n\033[0m");
	
	printf("Insert By Key Func Test: ");

	head = ListInsertByKeyRecu(head, 222, personTest);
	
	CHECK_FUNC(29 == head->m_next->m_age);

	printf("\nExpected: SUCCESS (head->m_next->m_age)\n");
	
	printf("\nRemove By Key Func Test 1: ");
	
	head = ListRemoveByKey(head, 333, &outputData);
	
	CHECK_FUNC(NULL != head->m_next);

	printf("\nExpected: SUCCESS (NULL != head->m_next)\n");
	
	printf("\nRemove By Key Func Test 1: ");
	
	CHECK_FUNC(NULL == outputData);
	
	printf("\nExpected: SUCCESS (NULL == outputData)\n");
	
	free(personTest);
}

void ListRemoveByKeyRecuTest1(void)
{
	Person_t *head = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest = (Person_t*)malloc(sizeof(Person_t));
	Person_t *outputData = NULL; 
	
	head->m_id = 111;
	strcpy(head->m_name, "Elior");
	head->m_age = 31;
	head->m_next = NULL;
	
	personTest->m_id = 222;
	strcpy(personTest->m_name, "Hadar");
	personTest->m_age = 29;
	personTest->m_next = NULL;
	
	printf("\033[1;34m\n*******Remove By Key Recu Test 1:*******\n\n\033[0m");
	
	printf("Insert By Key Func Test: ");

	head = ListInsertByKeyRecu(head, 222, personTest);
	
	CHECK_FUNC(29 == head->m_next->m_age);

	printf("\nExpected: SUCCESS (head->m_next->m_age)\n");
	
	printf("\nRemove By Key Func Test 1: ");
	
	head = ListRemoveByKeyRecu(head, 222, &outputData);
	
	CHECK_FUNC(NULL == head->m_next);

	printf("\nExpected: SUCCESS (NULL == head->m_next)\n");
	
	printf("\nRemove By Key Func Test 1: ");
	
	CHECK_FUNC(222 == outputData->m_id);
	
	printf("\nExpected: SUCCESS (outputData test)\n");
	
	free(personTest);
}

void ListRemoveByKeyRecuTest2(void)
{
	Person_t *head = NULL;
	Person_t *outputData = NULL; 
	
	printf("\033[1;34m\n*******Remove By Key Recu Test 2:*******\n\n\033[0m");
	
	head = ListRemoveByKeyRecu(head, 222, &outputData);

	printf("Remove By Key Func Test: ");
	
	CHECK_FUNC(NULL == head);

	printf("\nExpected: SUCCESS (NULL == head)\n");
}

void ListRemoveByKeyRecuTest3(void)
{
	Person_t *head = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest = (Person_t*)malloc(sizeof(Person_t));
	Person_t *outputData = NULL; 
	
	head->m_id = 111;
	strcpy(head->m_name, "Elior");
	head->m_age = 31;
	head->m_next = NULL;
	
	personTest->m_id = 222;
	strcpy(personTest->m_name, "Hadar");
	personTest->m_age = 29;
	personTest->m_next = NULL;
	
	printf("\033[1;34m\n*******Remove By Key Recu Test 3:*******\n\n\033[0m");
	
	printf("Insert By Key Func Test: ");

	head = ListInsertByKeyRecu(head, 222, personTest);
	
	CHECK_FUNC(29 == head->m_next->m_age);

	printf("\nExpected: SUCCESS (head->m_next->m_age)\n");
	
	printf("\nRemove By Key Func Test 1: ");
	
	head = ListRemoveByKeyRecu(head, 333, &outputData);
	
	CHECK_FUNC(NULL != head->m_next);

	printf("\nExpected: SUCCESS (NULL != head->m_next)\n");
	
	printf("\nRemove By Key Func Test 1: ");
	
	CHECK_FUNC(NULL == outputData);
	
	printf("\nExpected: SUCCESS (NULL == outputData)\n");
	
	free(personTest);
}

void PrintListTest(void)
{
	Person_t *head = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest = (Person_t*)malloc(sizeof(Person_t));
	Person_t *personTest2 = (Person_t*)malloc(sizeof(Person_t));
	Person_t *outputData = NULL; 
	
	head->m_id = 111;
	strcpy(head->m_name, "Elior");
	head->m_age = 31;
	head->m_next = NULL;
	
	personTest->m_id = 222;
	strcpy(personTest->m_name, "Hadar");
	personTest->m_age = 29;
	personTest->m_next = NULL;
	
	personTest2->m_id = 333;
	strcpy(personTest2->m_name, "Moshe");
	personTest2->m_age = 26;
	personTest2->m_next = NULL;
	
	printf("\033[1;34m\n*******Print List Test:*******\n\n\033[0m");
	
	printf("Insert By Key Func Test:\n");

	head = ListInsertByKey(head, 333, personTest2);
	head = ListInsertByKey(head, 222, personTest);
	
	PrintList(head);

	printf("\nExpected: Node 1 - ID -> 111, Name -> Elior, Age -> 31 | Node 2 - ID -> 222, Name -> Hadar, 29 -> 31 | Node 3 - ID -> 333, Name -> Moshe, Age -> 26\n");
	
	printf("\nRemove Head Func Test 1:\n");
	
	head = ListRemoveHead(head, &outputData);
	
	PrintList(head);
	
printf("\nExpected: Node 1 - ID -> 222, Name -> Hadar, 29 -> 31 | Node 2 - ID -> 333, Name -> Moshe, Age -> 26\n");
	
	free(personTest);
	free(personTest2);
}

int main(void)
{
	ListInsertHeadTest1();
	ListInsertHeadTest2();
	ListInsertHeadTest3();
	
	ListRemoveHeadTest1();
	ListRemoveHeadTest2();
	ListRemoveHeadTest3();
	
	ListInsertByKeyTest1();
	ListInsertByKeyTest2();
	ListInsertByKeyTest3();
	ListInsertByKeyTest4();
	ListInsertByKeyTest5();
	
	ListInsertByKeyRecuTest1();
	ListInsertByKeyRecuTest2();
	ListInsertByKeyRecuTest3();
	ListInsertByKeyRecuTest4();
	ListInsertByKeyRecuTest5();
	
	ListRemoveByKeyTest1();
	ListRemoveByKeyTest2();
	ListRemoveByKeyTest3();
	
	ListRemoveByKeyRecuTest1();
	ListRemoveByKeyRecuTest2();
	ListRemoveByKeyRecuTest3();
	
	PrintListTest();
	
	return 0;
}
