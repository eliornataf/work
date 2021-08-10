#include <stdio.h> 

int main(void)
{
	const char *str1 = "the";
	char const *str2 = "winter";
	char *const str3 = "is";
	const char *const str4 = "coming";
	
	/* OK */
	
	++str1;
	++str2;
	*(str3 + 1) = '\0';
	
	/* Error */
	
	/* *str1 = '...';
	   *str2 = '...';
	   	++str3;
	   	str4 = '...';
	   	++str4;
	*/
	
	return 0;
}
