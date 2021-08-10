/*****************************************************************************
* File Name: String Function
* Written by: Elior Nataf
* Date: 16/3/21
/*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __STRING_FUNCTION_H__
#define __STRING_FUNCTION_H__

/*------------------------------- Header Files ------------------------------*/

/*---------------------------------- Typedef --------------------------------*/

/*----------------------------------- Define --------------------------------*/

#define STRLEN_POINTER_NOT_INITIALIZE (0)
#define STRCMP_POINTER_NOT_INITIALIZE (-999)

/*------------------------------------ Enum  --------------------------------*/

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that takes a string as an argument and returns its length.
 * '\0' is not count.
 *
 * Input:
 * str - pointer to const string whose length is to be found.
 *
 * Output:
 * STRLEN_POINTER_NOT_INITIALIZE - string pointer is not initialized, length is not calculate.
 * the number of bytes in the string.
 *
 * Error: 
 * STRLEN_POINTER_NOT_INITIALIZE - string pointer is not initialized, length is not calculate.
 */
size_t Strlen(const char *str);

/* Description:
 * A function that takes a string as an argument and returns its length.
 * '\0' is not count.
 *
 * Input:
 * str - pointer to const string.
 *
 * Output:
 * STRLEN_POINTER_NOT_INITIALIZE - string pointer is not initialized, length is not calculate.
 * the number of bytes in the string.
 *
 * Error: 
 * STRLEN_POINTER_NOT_INITIALIZE - string pointer is not initialized, length is not calculate.
 */
size_t StrlenRec(const char *str);

/* Description:
 * A function that compares 2 strings character by character.
 *
 * Input:
 * s1- pointer to const string.
 * s2 - pointer to const string.
 *
 * Output:
 * STRCMP_POINTER_NOT_INITIALIZE - string pointer is not initialized.
 * compare is not possible.
 * 0 if strings are equal, greater then zero if s1 is bigger or less then zero if s2
 * is bigger.
 *
 * Error: 
 * STRCMP_POINTER_NOT_INITIALIZE - string pointer is not initialized. 
 * compare is not possible.
 */
int Strcmp(const char *s1, const char *s2);

/* Description:
 * A function that compares 2 strings character by character.
 *
 * Input:
 * s1- pointer to const string.
 * s2 - pointer to const string.
 *
 * Output:
 * STRCMP_POINTER_NOT_INITIALIZE - string pointer is not initialized.
 * compare is not possible.
 * 0 if strings are equal, greater then zero if s1 is bigger or less then zero if s2
 * is bigger.
 *
 * Error: 
 * STRCMP_POINTER_NOT_INITIALIZE - string pointer is not initialized.
 * compare is not possible.
 */
int StrcmpRecu(const char *s1, const char *s2);

/* Description:
 * A function that copies the string pointed by src (including the null character)
 * to the dest. the size of the dest string should be large enough to store
 * the copied string, otherwise, it may result in undefined behavior.
 *
 * Input:
 * dest - pointer to string where the content is to be copied.
 * src - pointer to const string to be copied.
 *
 * Output:
 * NULL - string pointer is not initialized, copy is not possible.
 * pointer to the dest string.
 *
 * Error: 
 * NULL - string pointer is not initialized, copy is not possible.
 */
char *Strcpy(char *dest, const char *src);

/* Description:
 * A function that copies the string pointed by src (including the null character)
 * to the dest. the size of the dest string should be large enough to store
 * the copied string, otherwise, it may result in undefined behavior.
 *
 * Input:
 * dest - pointer to string where the content is to be copied.
 * src - pointer to const string to be copied.
 *
 * Output:
 * NULL - string pointer is not initialized, copy is not possible.
 * pointer to the dest string.
 *
 * Error: 
 * NULL - string pointer is not initialized, copy is not possible.
 */
char *StrcpyRecu(char *dest, const char *src);

/* Description:
 * A function that copies up to n characters from the string pointed by 
 * src (including the null character) to the dest. 
 * the size of the dest string should be large enough to store
 * the copied string, otherwise, it may result in undefined behavior.
 *
 * Input:
 * dest - pointer to string where the content is to be copied.
 * src - pointer to const string to be copied.
 * n - the number of characters to be copied from src.
 *
 * Output:
 * NULL - string pointer is not initialized, copy is not possible.
 * pointer to the dest string.
 *
 * Error: 
 * NULL - string pointer is not initialized, copy is not possible.
 */
char *Strncpy(char *dest, const char *src, size_t n);

/* Description:
 * A function that copies up to n characters from the string pointed by 
 * src (including the null character) to the dest. 
 * the size of the dest string should be large enough to store
 * the copied string, otherwise, it may result in undefined behavior.
 *
 * Input:
 * dest - pointer to string where the content is to be copied.
 * src - pointer to const string to be copied.
 * n - the number of characters to be copied from src.
 *
 * Output:
 * NULL - string pointer is not initialized, copy is not possible.
 * pointer to the dest string.
 *
 * Error: 
 * NULL - string pointer is not initialized, copy is not possible.
 */
char *StrncpyRecu(char *dest, const char *src, size_t n);

/* Description:
 * A function that concatenates the dest string and the src string, and 
 * the result is stored in the dest string.
 * the size of the dest string should be large enough to store
 * the copied string, otherwise, it may result in undefined behavior.
 *
 * Input:
 * dest - pointer to string where the content is to be copied.
 * src - pointer to const string to be appended.
 *
 * Output:
 * NULL - string pointer is not initialized, concatenate is not possible.
 * pointer to the dest string.
 *
 * Error: 
 * NULL - string pointer is not initialized, concatenate is not possible.
 */
char *Strcat(char *dest, const char *src);

/* Description:
 * A function that takes two arguments: haystack and needle, it searches for 
 * the first occurrence of needle in the string pointed to by haystack.
 * the terminating null characters are ignored.
 *
 * Input:
 * haystack - pointer to const string to be scanned.
 * needle - pointer to const string to be searched within haystack string.
 *
 * Output:
 * NULL - string pointer is not initialized, scanned is not possible.
 * NULL - substring is not found.
 * pointer to the first occurrence in haystack if the substring is found.
 *
 * Error: 
 * NULL - string pointer is not initialized, scanned is not possible.
 * NULL - substring is not found.
 */
char *Strstr(const char *haystack, const char *needle);

#endif /* __STRING_FUNCTION_H__ */
