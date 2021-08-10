/*****************************************************************************
* File Name: array
* Written by: Elior Nataf
* Date: 9/2/21
/*****************************************************************************/

/*-----------------------------Libaries & Define-----------------------------*/


/*--------------------------Functions declarations--------------------------*/

/* Description:
 * A function that receives a string and reverses her in place.
 *
 * Input:
 * str - given string.
 *
 * Output:
 * str - given string after reverses.
 * NULL - str given input size error (size < 2).
 *
 * Error: 
 * NULL - str given input size error (size < 2).
 */
char *ReverseStr(char str[]);

/* Description:
 * A function that converts the string agrument str to an integer.
 *
 * Input:
 * str - given string.
 *
 * Output:
 * str2num - the number after convert (if no valid conversion could be 
 * performed, its returns zero).
 *
 * Error: 
 * None.
 */
int Atoi(const char *str);

/* Description:
 * A function that converts an integer (value) a null-terminated string using
 * the specified base and stores the result in str parameter.
 *
 * Input:
 * value - value to converted to a string.
 * str - where to store the resulting null-terminated string.
 * base - numberical base used to represent the value as a string (we use
 * decimal base => 10).
 *
 * Output:
 * a pointer to the resulting null-terminated string, same as parameter str.
 *
 * Error: 
 * None.
 */
char *Itoa(int value, char *str, int base);
