#include <stdio.h> /* printf */

#define ARRAY_IS_EMPTY (-999.98)
#define POINTER_IS_NOT_INITIALIZE (-999.99)

double FindArrayAverageRecu(int *_arr, size_t _arrSize, size_t _constArrSize)
{	
	if (!_arrSize)
	{
		return _arr[_arrSize - 1];
	}

	if (_arrSize == _constArrSize)
	{
		return (_arr[_arrSize - 1] + FindArrayAverageRecu(_arr, _arrSize - 1, _constArrSize)) 
																		/ _constArrSize;
	}

	return _arr[_arrSize - 1] + FindArrayAverageRecu(_arr, _arrSize - 1, _constArrSize);
}

double FindArrayAverage(int *_arr, size_t _arrSize)
{
	if (!_arr)
	{
		return POINTER_IS_NOT_INITIALIZE;
	}
	
	if (!_arrSize)
	{
		return ARRAY_IS_EMPTY;
	}
	
	return FindArrayAverageRecu(_arr, _arrSize, _arrSize);
}

int main(void)
{
	int arrTest[] = {1, 2, 3, 4, 5, 6, 7, 8};
	size_t arrSize = sizeof(arrTest) / sizeof(arrTest[0]);

	printf("Array average is: %f\n", FindArrayAverage(arrTest, arrSize));

	return 0;
}
