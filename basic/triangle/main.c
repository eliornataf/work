#include <stdio.h> /* printf, scanf */
#include "triangle.h" /* triangle header */

int main(void)
{
	int size;
	char ch;
	
	printf("Please enter a character [character to print] & size [number of lines]: ");
	scanf("%c %d", &ch, &size);
	
	printf("\nDrawRightAngleTriangle: \n\n");
	DrawRightAngleTriangle(size, ch);
	
	printf("\nDrawRightAngleTriangleOverTurned: \n\n");
	DrawRightAngleTriangleOverTurned(size, ch);
	
	printf("\nDrawIsoscelesTriangle: \n\n");
	DrawIsoscelesTriangle(size, ch);
	
	printf("\nDrawEquilateralTriangle: \n\n");
	DrawEquilateralTriangle(size, ch);
	
	printf("\nDrawEquilateralTriangleOverTurned: \n\n");
	DrawEquilateralTriangleOverTurned(size, ch);
	
	printf("\nDrawRhombus: \n\n");
	DrawRhombus(size, ch);
	
	return 0;
}
