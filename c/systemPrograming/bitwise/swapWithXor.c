#include <stdio.h> /* printf, scanf */

static void Swap(int *_x, int *_y)
{
    *_x = (*_x ^ *_y);    
    *_y = (*_x ^ *_y);    
    *_x = (*_x ^ *_y); 
}

int main(void)
{
    int x, y;
	
	printf("Please enter two numbers [x, y]:\n");
	scanf("%d %d", &x, &y);

    Swap(&x, &y);
	
	printf("After swap: x = %d y = %d\n", x, y);
	
	return 0;	
}