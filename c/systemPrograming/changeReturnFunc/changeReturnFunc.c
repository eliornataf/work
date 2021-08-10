#include <stdio.h> /* printf, rand */

#define NEW_RETURN_FUNC_ADDRESS (rand())

void Func2(int _var1, int _var2, int _var3, int _var4, int _var5, int _var6, int _var7)
{
    void *ptr = &_var7;

    ptr = (char*)ptr - sizeof(ptr);

    *((double*)ptr) = NEW_RETURN_FUNC_ADDRESS;

	printf("\033[1;31mFunction 2 return to function 1\n\033[0m");
}

void Func1(void)
{
    int var1, var2, var3, var4, var5, var6, var7;

	printf("\033[1;33mFunction 1 calling function 2\n\033[0m");

    Func2(var1, var2, var3, var4, var5, var6, var7);

	printf("\033[1;33mFunction 1 return to main function\n\033[0m");
}

int main(void)
{
	printf("\033[1;32mMain function calling function 1\n\033[0m");

    Func1();

	printf("\033[1;32mMain function end\n\033[0m");

    return 0;
}