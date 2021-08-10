#include <stdio.h> /* putchar, printf */
#include "triangle.h" /* triangle header */

/*****************************************************************************/

int checkParameters(int _size, char _ch)
{
	if (_size < MIN_INPUT_SIZE || MAX_INPUT_SIZE < _size)
	{
		return SIZE_INPUT_ERROR;
	}
	
	if (_ch < MIN_INPUT_CHAR || MAX_INPUT_CHAR < _ch)
	{
		return CHAR_INPUT_ERROR;
	}
	
	return PARAM_INPUT_OK;
}

void PrintLine(int _size, char _ch)
{
	int j;

	for (j = 1;j <= _size;++j)
	{
		putchar(_ch);
	}
}

void PrintLineAndSpace(int _size, char _ch)
{
	int j;

	for (j = 1;j <= _size;++j)
	{
		printf("%c ", _ch);
	}
}

/*****************************************************************************/

int DrawRightAngleTriangle(int _size, char _ch)
{
	int i, res;
	
	res = checkParameters(_size, _ch);
	
	if (res != PARAM_INPUT_OK)
	{
		return res;
	}
	
	for (i = 1;i <= _size;++i)
	{
		PrintLine(i, _ch);
		
		putchar('\n');
	}
	
	return PARAM_INPUT_OK;
}

int DrawRightAngleTriangleOverTurned(int _size, char _ch)
{
	int i, res;
	
	res = checkParameters(_size, _ch);
	
	if (res != PARAM_INPUT_OK)
	{
		return res;
	}
	
	for (i = _size;0 < i;--i)
	{
		PrintLine(i, _ch);
		
		putchar('\n');
	}
	
	return PARAM_INPUT_OK;
}

int DrawIsoscelesTriangle(int _size, char _ch)
{	
	int res;
	
	res = checkParameters(_size, _ch);
	
	if (res != PARAM_INPUT_OK)
	{
		return res;
	}

	DrawRightAngleTriangle(_size, _ch);
	DrawRightAngleTriangleOverTurned(_size-1, _ch);
	
	return PARAM_INPUT_OK; 
}

int DrawEquilateralTriangle(int _size, char _ch)
{
	int i, j, res;
	
	res = checkParameters(_size, _ch);
	
	if (res != PARAM_INPUT_OK)
	{
		return res;
	}
	
	for (i = _size, j = 1;1 <= i;--i, ++j)
	{
		PrintLine(i, ' ');
		
		PrintLineAndSpace(j, _ch);
		
		putchar('\n');
	}
	
	return PARAM_INPUT_OK; 
}

int DrawEquilateralTriangleOverTurned(int _size, char _ch)
{
	int i, j, res;
	
	res = checkParameters(_size, _ch);
	
	if (res != PARAM_INPUT_OK)
	{
		return res;
	}
	
	for (i = 1, j = _size;i <= _size;++i, --j)
	{
		PrintLine(i, ' ');
		
		PrintLineAndSpace(j, _ch);
		
		putchar('\n');
	}
	
	return PARAM_INPUT_OK; 
}

int DrawRhombus(int _size, char _ch)
{
	int res;
	int i = _size;
	
	res = checkParameters(_size, _ch);
	
	if (res != PARAM_INPUT_OK)
	{
		return res;
	}
	
	DrawEquilateralTriangle(_size-1, _ch);
	
	PrintLineAndSpace(i, _ch);
	
	putchar('\n');
	
	DrawEquilateralTriangleOverTurned(_size-1, _ch);
	
	return PARAM_INPUT_OK; 
}

