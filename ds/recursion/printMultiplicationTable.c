#include <stdio.h> /* printf */

#define MAX_MULTIPLAY (10)

void PrintMultiplicationTableSetElements(size_t _num, size_t _multiply)
{
	if (_num)
	{
		PrintMultiplicationTableSetElements(_num - 1, _multiply);
		printf("%ld\t", _num * _multiply);
	}

	return;
}

void PrintMultiplicationTableSetRows(size_t _rowsOrElementsNum, size_t _multiply)
{
	if (_multiply <= MAX_MULTIPLAY)
	{
		PrintMultiplicationTableSetElements(_rowsOrElementsNum, _multiply);
		printf("\n");
		PrintMultiplicationTableSetRows(_rowsOrElementsNum, _multiply + 1);
	}
	
	return;
}

int main(void)
{
	size_t rowOrElementNum = 10;
	size_t multiply = 1;

	PrintMultiplicationTableSetRows(rowOrElementNum, multiply);
	
	return 0;
}
