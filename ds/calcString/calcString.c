int calcPosix(char *_posixStr, ADTError_t *_status)
{
	int outputData1, outputData2;
	
	Stack_t *Stack = StackCreate(_stackCapacity, _stackIncBlockSize);
	if (!Stack)
	{
		*_status = POINTER_NOT_INITIALIZE;
		return NULL;
	}
	
	for (i = 0;_posixStr[i] != '\0';++i)
	{
		if ('0' <= _posixStr[i] && _posixStr[i] <= '9')
		{
			*_status = StackPush(Stack, _infixStr[i]);
			if (OK != *_status)
			{
				return NULL;
			}
		}
		else if ('+' == _infixStr[i] || '-' == _infixStr[i] || '*' == _infixStr[i] 
																|| '/' == _infixStr[i])
		{
			*_status = StackPop(Stack, &outputData1);
			if (OK != *_status)
			{
				return NULL;
			}
			
			*_status = StackPop(Stack, &outputData2);
			if (OK != *_status)
			{
				return NULL;
			}
			
			if ('+' == _infixStr[i])
			{
				*_status = StackPush(Stack, outputData2 + outputData1);
				if (OK != *_status)
				{
					return NULL;
				}
			}
			else if ('-' == _infixStr[i])
			{
				*_status = StackPush(Stack, outputData2 - outputData1);
				if (OK != *_status)
				{
					return NULL;
				}
			}
			else if ('*' == _infixStr[i])
			{
				*_status = StackPush(Stack, outputData2 * outputData1);
				if (OK != *_status)
				{
					return NULL;
				}
			}
			else if ('/' == _infixStr[i])
			{
				*_status = StackPush(Stack, outputData2 / outputData1);
				if (OK != *_status)
				{
					return NULL;
				}
			}
		}
		else
		{
			printf("Invalid input!\n");
			return NULL;
		}
	}
	
	return _posixStr;
}

char *InfixToPosix(char *_infixStr, ADTError_t *_status)
{
	size_t infixStrStrlen = strlen(_infixStr);
	char posixStr[infixStrStrlen + 1];
	int i, j, outputDataTop, outputDataPop;
	
	Stack_t *Stack = StackCreate(_stackCapacity, _stackIncBlockSize);
	if (!Stack)
	{
		*_status = POINTER_NOT_INITIALIZE;
		return NULL;
	}
	
	for (i = 0;_infixStr[i] != '\0';++i)
	{
		if ('0' <= _infixStr[i] && _infixStr[i] <= '9')
		{
			posixStr[x] = _infixStr[i];
			++x;
		}
		else if ('+' == _infixStr[i] || '-' == _infixStr[i])
		{
			if (StackIsEmpty(Stack))
			{
				*_status = StackPush(Stack, _infixStr[i]);
				if (OK != *_status)
				{
					return NULL;
				}
			}
			else
			{
				*_status = StackPop(Stack, &outputDataPop);
				if (OK != *_status)
				{
					return NULL;
				}
					
				posixStr[x] = outputDataPop;
				++x;
					
				*_status StackPush(Stack, _infixStr[i]);
				if (OK != *_status)
				{
						return NULL;
				}	
			}			
		}
		else if ('*' == _infixStr[i] || '/' == _infixStr[i]))
		{
			if (StackIsEmpty(Stack))
			{
				*_status = StackPush(Stack, _infixStr[i]);
				if (OK != *_status)
				{
					return NULL;
				}
			}
			else
			{
				*_status = StackTop(Stack, &outputDataTop);
				if (OK != *_status)
				{
					return NULL;
				}
				
				if ('+' == outputDataTop || '-' == outputDataTop)
				{
					*_status StackPush(Stack, _infixStr[i]);
					if (OK != *_status)
					{
						return NULL;
					}	
				}
				else if ('*' == outputDataTop || '/' == outputDataTop)
				{
					*_status = StackPop(Stack, &outputDataPop);
					if (OK != *_status)
					{
						return NULL;
					}
					
					posixStr[x] = outputDataPop;
					++x;
					
					*_status StackPush(Stack, _infixStr[i]);
					if (OK != *_status)
					{
						return NULL;
					}	
				}
			}
		}
		else
		{
			printf("Invalid input!\n");
			return NULL;
		}
		
	}
		
	while (STACK_IS_EMPTY != StackIsEmpty(Stack))
	{
		*_status = StackPop(Stack, &outputDataPop);
		if (OK != *_status)
		{
			return NULL;
		}
					
		posixStr[x] = outputDataPop;
		++x;
	}
		
	posixStr[x] = '\0';

	return posixStr;	
}
