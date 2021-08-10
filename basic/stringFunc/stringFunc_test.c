#include <stdio.h> /* printf */
#include <string.h> /* strlen, strcmp, strcpy, strncpy, strcat, strstr */ 
#include "stringFunc.h" /* String Function Header */

#define STR_LENGTH (100)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

void StrlenTest(void)
{
	char str1[STR_LENGTH] = "";
    char str2[STR_LENGTH] = "The winter is coming";
    char *str3 = "The summer is coming";
    char *str4 = NULL;
	
	printf("\033[1;34m\n*******Strlen Test:*******\n\n\033[0m");
	
	printf("Strlen Func Test 1: ");
	
	CHECK_FUNC(strlen(str1) == Strlen(str1));

    printf("Strlen Func Test 2: ");
	
	CHECK_FUNC(strlen(str2) == Strlen(str2));
	
	printf("Strlen Func Test 3: ");
	
	CHECK_FUNC(strlen(str3) == Strlen(str3));

	printf("Strlen Func Test 4: ");

    CHECK_FUNC(STRLEN_POINTER_NOT_INITIALIZE == Strlen(str4));

	printf("\nExpected: 4 SUCCESS\n");
}

void StrlenRecuTest(void)
{
	char str1[STR_LENGTH] = "";
    char str2[STR_LENGTH] = "The winter is coming";
    char *str3 = "The summer is coming";
    char *str4 = NULL;
	
	printf("\033[1;34m\n*******Strlen Recu Test:*******\n\n\033[0m");
	
	printf("Strlen Recu Func Test 1: ");
	
	CHECK_FUNC(strlen(str1) == StrlenRec(str1));

    printf("Strlen Recu Func Test 2: ");
	
	CHECK_FUNC(strlen(str2) == StrlenRec(str2));
	
	printf("Strlen Recu Func Test 3: ");
	
	CHECK_FUNC(strlen(str3) == StrlenRec(str3));

	printf("Strlen Recu Func Test 4: ");

    CHECK_FUNC(STRLEN_POINTER_NOT_INITIALIZE == StrlenRec(str4));

	printf("\nExpected: 4 SUCCESS\n");
}

void StrcmpTest(void)
{
	char str1[STR_LENGTH] = "abcd";
    char str2[STR_LENGTH] = "abcd";
    char *str3 = "abcde";
    char *str4 = NULL;
	
	printf("\033[1;34m\n*******Strcmp Test:*******\n\n\033[0m");
	
	printf("Strcmp Func Test 1: ");
	
	CHECK_FUNC(strcmp(str1, str2) == Strcmp(str1, str2));

	printf("Strcmp Func Test 2: ");

    CHECK_FUNC(STRCMP_POINTER_NOT_INITIALIZE == Strcmp(str1, str4));

	printf("\nExpected: 2 SUCCESS\n");
}

void StrcmpRecuTest(void)
{
	char str1[STR_LENGTH] = "abcd";
    char str2[STR_LENGTH] = "abcd";
    char *str3 = "abcde";
    char *str4 = NULL;
	
	printf("\033[1;34m\n*******Strcmp Recu Test:*******\n\n\033[0m");
	
	printf("Strcmp Recu Func Test 1: ");
	
	CHECK_FUNC(strcmp(str1, str2) == StrcmpRecu(str1, str2));

	printf("Strcmp Recu Func Test 2: ");

    CHECK_FUNC(STRCMP_POINTER_NOT_INITIALIZE == StrcmpRecu(str1, str4));

	printf("\nExpected: 2 SUCCESS\n");
}

void StrcpyTest(void)
{
	char src1[STR_LENGTH] = "abcd";
    char dest1[STR_LENGTH] = "";
	char src2[STR_LENGTH] = "abcd";
    char dest2[STR_LENGTH] = "";
	char src3[STR_LENGTH] = "abcd";
    char dest3[STR_LENGTH] = "defg";
	char src4[STR_LENGTH] = "abcd";
    char dest4[STR_LENGTH] = "defg";
    char *str5 = NULL;
	
	printf("\033[1;34m\n*******Strcpy Test:*******\n\n\033[0m");
	
	printf("Strcpy Func Test 1: ");
	
	Strcpy(dest1, src1);
    strcpy(dest2, src2);

	CHECK_FUNC(!strcmp(dest1, dest2));

    printf("Strcpy Func Test 2: ");
	
	Strcpy(dest3, src3);
    strcpy(dest4, src4);

    CHECK_FUNC(!strcmp(dest3, dest4));

	printf("Strcpy Func Test 3: ");

    CHECK_FUNC(NULL == Strcpy(dest1, str5));

	printf("\nExpected: 3 SUCCESS\n");
}

void StrcpyRecuTest(void)
{
	char src1[STR_LENGTH] = "abcd";
    char dest1[STR_LENGTH] = "";
	char src2[STR_LENGTH] = "abcd";
    char dest2[STR_LENGTH] = "";
	char src3[STR_LENGTH] = "abcd";
    char dest3[STR_LENGTH] = "defg";
	char src4[STR_LENGTH] = "abcd";
    char dest4[STR_LENGTH] = "defg";
    char *str5 = NULL;
	
	printf("\033[1;34m\n*******Strcpy Recu Test:*******\n\n\033[0m");
	
	printf("Strcpy Recu Func Test 1: ");
	
	StrcpyRecu(dest1, src1);
    strcpy(dest2, src2);

	CHECK_FUNC(!strcmp(dest1, dest2));

    printf("Strcpy Recu Func Test 2: ");
	
	StrcpyRecu(dest3, src3);
    strcpy(dest4, src4);

    CHECK_FUNC(!strcmp(dest3, dest4));

	printf("Strcpy Recu Func Test 3: ");

    CHECK_FUNC(NULL == StrcpyRecu(dest1, str5));

	printf("\nExpected: 3 SUCCESS\n");
}

void StrncpyTest(void)
{
	char src1[STR_LENGTH] = "abcd";
    char dest1[STR_LENGTH] = "";
	char src2[STR_LENGTH] = "abcd";
    char dest2[STR_LENGTH] = "";
	char src3[STR_LENGTH] = "abcd";
    char dest3[STR_LENGTH] = "defg";
	char src4[STR_LENGTH] = "abcd";
    char dest4[STR_LENGTH] = "defg";
    char *str5 = NULL;
	
	printf("\033[1;34m\n*******Strncpy Test:*******\n\n\033[0m");
	
	printf("Strncpy Func Test 1: ");

	Strncpy(dest1, src1, 2);
    strncpy(dest2, src2, 2);

	CHECK_FUNC(!strcmp(dest1, dest2));

    printf("Strncpy Func Test 2: ");
	
	Strncpy(dest3, src3, 4);
    strncpy(dest4, src4, 4);

    CHECK_FUNC(!strcmp(dest3, dest4));

	printf("Strncpy Func Test 3: ");

    CHECK_FUNC(NULL == Strncpy(dest1, str5, 4));

	printf("\nExpected: 3 SUCCESS\n");
}

void StrncpyRecuTest(void)
{
	char src1[STR_LENGTH] = "abcd";
    char dest1[STR_LENGTH] = "";
	char src2[STR_LENGTH] = "abcd";
    char dest2[STR_LENGTH] = "";
	char src3[STR_LENGTH] = "abcd";
    char dest3[STR_LENGTH] = "defg";
	char src4[STR_LENGTH] = "abcd";
    char dest4[STR_LENGTH] = "defg";
    char *str5 = NULL;
	
	printf("\033[1;34m\n*******Strncpy Recu Test:*******\n\n\033[0m");
	
	printf("Strncpy Recu Func Test 1: ");

	StrncpyRecu(dest1, src1, 2);
    strncpy(dest2, src2, 2);

	CHECK_FUNC(!strcmp(dest1, dest2));

    printf("Strncpy Recu Func Test 2: ");
	
	StrncpyRecu(dest3, src3, 4);
    strncpy(dest4, src4, 4);

    CHECK_FUNC(!strcmp(dest3, dest4));

	printf("Strncpy Recu Func Test 3: ");

    CHECK_FUNC(NULL == StrncpyRecu(dest1, str5, 4));

	printf("\nExpected: 3 SUCCESS\n");
}

void StrcatTest(void)
{
	char src1[STR_LENGTH] = "abcd";
    char dest1[STR_LENGTH] = "";
	char src2[STR_LENGTH] = "abcd";
    char dest2[STR_LENGTH] = "";
	char src3[STR_LENGTH] = "defg";
    char dest3[STR_LENGTH] = "abcd";
	char src4[STR_LENGTH] = "defg";
    char dest4[STR_LENGTH] = "abcd";
    char *str5 = NULL;
	
	printf("\033[1;34m\n*******Strcat Test:*******\n\n\033[0m");
	
	printf("Strcat Func Test 1: ");

	Strcat(dest1, src1);
    strcat(dest2, src2);

	CHECK_FUNC(!strcmp(dest1, dest2));

    printf("Strcat Func Test 2: ");
	
	Strcat(dest3, src3);
    strcat(dest4, src4);

    CHECK_FUNC(!strcmp(dest3, dest4));

	printf("Strncpy Func Test 3: ");

    CHECK_FUNC(NULL == Strcat(dest1, str5));

	printf("\nExpected: 3 SUCCESS\n");
}

void StrStrTest(void)
{
	char haystack1[STR_LENGTH] = "abcd";
    char needle1[STR_LENGTH] = "cd";
    char *haystack2 = "abbccde";
    char *needle2 = "cdf";
    char *haystack3 = NULL;
	
	printf("\033[1;34m\n*******StrStr Test:*******\n\n\033[0m");
	
	printf("StrStr Func Test 1: ");
	
	CHECK_FUNC(strstr(haystack1, needle1) == Strstr(haystack1, needle1));

    printf("StrStr Func Test 2: ");
	
	CHECK_FUNC(strstr(haystack2, needle2) == Strstr(haystack2, needle2));

	printf("StrStr Func Test 3: ");

    CHECK_FUNC(NULL == Strstr(haystack3, needle2));

	printf("\nExpected: 3 SUCCESS\n");
}

int main(void)
{
    StrlenTest();
    StrlenRecuTest();

    StrcmpTest();
    StrcmpRecuTest();

    StrcpyTest();
    StrcpyRecuTest();

    StrncpyTest();
    StrncpyRecuTest();

    StrcatTest();

    StrStrTest();

    return 0;
}