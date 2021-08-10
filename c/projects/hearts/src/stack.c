#include <stdlib.h> /* malloc, free */
#include "stack.h" /* stack header */
#include "dynamicVector.h" /* Dynamic Vector header */

struct Stack
{
	Vector_t *m_Vector;
};

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

Stack_t *StackCreate(size_t _capacity, size_t _incBlockSize)
{
	Stack_t *stack = (Stack_t*)malloc(sizeof(Stack_t));
	if (!stack)
	{
		return NULL;
	}
	
	stack->m_Vector = VectorCreate(_capacity, _incBlockSize);
	if (!stack->m_Vector)
	{
		free(stack);
		return NULL;
	}
	
	return stack;
}

void StackDestroy(Stack_t *_stack)
{
	if (!_stack)
	{
		return;
	}
	
	VectorDestroy(_stack->m_Vector);
	free(_stack);
}

ADTError_t StackPush(Stack_t *_stack, int _inputData)
{
	if (!_stack)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	return VectorPush(_stack->m_Vector, _inputData);
}

ADTError_t StackPop(Stack_t *_stack, int *_outputData)
{
	if (!_stack || !_outputData)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	return VectorPop(_stack->m_Vector, _outputData);
}

ADTError_t StackPeek(Stack_t *_stack, int *_outputData)
{
	size_t numOfElements;
	
	if (!_stack || !_outputData)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	if (StackIsEmpty(_stack))
	{
		return UNDERFLOW;
	}
	
	VectorNumOfElements(_stack->m_Vector, &numOfElements);
	
	return VectorGetElement(_stack->m_Vector, numOfElements - 1, _outputData);
}

int StackIsEmpty(Stack_t *_stack)
{
	size_t numOfElements;

	if (!_stack)
	{
		return STACK_IS_EMPTY;
	}
	
	VectorNumOfElements(_stack->m_Vector, &numOfElements);
	
	return (!numOfElements ? STACK_IS_EMPTY : STACK_IS_NOT_EMPTY);
}

void StackPrint(Stack_t *_stack)
{
	if (!_stack || !_stack->m_Vector)
	{
		return;
	}

	VectorPrint(_stack->m_Vector);
}
