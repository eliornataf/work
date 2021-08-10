#include <stdio.h> /* printf */

int Pow(int _num, int _pow)
{
	if (!_pow)
	{
		return 1;
	}

	return _num * Pow(_num, _pow - 1);
}

int main(void)
{
	int num, pow;
	
	printf("please enter a number and a pow:\n");
	scanf("%d %d", &num, &pow);
	
	printf("%d to the power of %d is %d\n", num, pow, Pow(num, pow));
}
