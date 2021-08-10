#include <stdio.h> /* printf, scanf */

int main(void)
{
	int a, b;
	
	printf("Please enter 2 interger [a, b]: ");
	scanf("%d %d", &a, &b);
	printf("Sum of the 2 numbers: %d\n", a+b);
	printf("The difference between the 2 numbers: %d\n", a-b);
	printf("The multiply of the 2 numbers: %d\n", a*b);
	printf("The modulu of the 2 numbers: %d\n", a%b);
	
	return 0;
}
