#include <stdlib.h> /* malloc, free */
#include "dynamicVector.h" /* Dynamic Vector Header */
#include "stack.h" /* Stack Header */
#include "sort.h" /* Sort Header */

#define IS_NOT_SORTED (0)
#define IS_SORTED (1)
#define STACK_CAPACITY (10)
#define STACK_BLOCK_SIZE (10)
#define BASE (10)

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static void GetElementsData(Vector_t *_dynamicVector, size_t _firstIndex, int *_firstIndexoutputData
											, size_t _secondIndex, int *_secondIndexoutputData);
static void SetElementsData(Vector_t *_dynamicVector, size_t _firstIndex, int _firstIndexinputData, 
											size_t _secondIndex, int _secondIndexinputData);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

ADTError_t BubbleSort(Vector_t *_dynamicVector)
{
	int firstElementData, secondElementData;
	int isVectorSorted = IS_NOT_SORTED;
	size_t vectorSize;
	size_t i, j;
	
	if (!_dynamicVector)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	VectorNumOfElements(_dynamicVector, &vectorSize);
	
	if (vectorSize < 2)
	{
		return OK;
	}
	
	for (i = 0;i < vectorSize - 1 && IS_SORTED != isVectorSorted;++i)
	{
		isVectorSorted = IS_SORTED;
		
		for (j = 0;j < vectorSize - 1 - i;++j)
		{
			GetElementsData(_dynamicVector, j, &firstElementData, j + 1, &secondElementData);
			
			if (secondElementData < firstElementData)
			{
				SetElementsData(_dynamicVector, j, secondElementData, j + 1, firstElementData);
				isVectorSorted = IS_NOT_SORTED;
			}
		}
	}
	
	return OK;
}

/*****************************************************************************/

ADTError_t ShakeSort(Vector_t *_dynamicVector)
{
	int firstElementData, secondElementData;
	int isVectorSorted = IS_NOT_SORTED;
	size_t vectorSize;
	int startIndex = 0;
	int endIndex, i;
	
	if (!_dynamicVector)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	VectorNumOfElements(_dynamicVector, &vectorSize);
	endIndex = (int)vectorSize - 1;
	
	while (IS_SORTED != isVectorSorted)
	{
		isVectorSorted = IS_SORTED;
	
		for (i = startIndex;i < endIndex;++i)
		{
			GetElementsData(_dynamicVector, i, &firstElementData, i + 1, &secondElementData);
			
			if (secondElementData < firstElementData)
			{
				SetElementsData(_dynamicVector, i, secondElementData, i + 1, firstElementData);
				isVectorSorted = IS_NOT_SORTED;
			}
		}
		
		if (IS_SORTED == isVectorSorted)
		{
			break;
		}
		
		--endIndex;
		
		isVectorSorted = IS_SORTED;
		
		for (i = endIndex;startIndex < i;--i)
		{
			GetElementsData(_dynamicVector, i, &firstElementData, i - 1, &secondElementData);
			
			if (firstElementData < secondElementData)
			{
				SetElementsData(_dynamicVector, i, secondElementData, i - 1, firstElementData);
				isVectorSorted = IS_NOT_SORTED;
			}
		}
		
		++startIndex;
	}
	
	return OK;
}

/*****************************************************************************/

static size_t Partition(Vector_t *_dynamicVector, size_t _leftIndex, size_t _rightIndex)
{
	int pivotData, leftElementData, rightElementData;
	size_t pivotIndex = _leftIndex;
	
	VectorGetElement(_dynamicVector, pivotIndex, &pivotData);

	++_leftIndex;

	while (_leftIndex <= _rightIndex)
	{
		GetElementsData(_dynamicVector, _leftIndex, &leftElementData, _rightIndex, &rightElementData);
	
		while (leftElementData <= pivotData && _leftIndex <= _rightIndex)
		{
			++_leftIndex;
			VectorGetElement(_dynamicVector, _leftIndex, &leftElementData);
		}
		
		while (pivotData < rightElementData)
		{
			--_rightIndex;
			VectorGetElement(_dynamicVector, _rightIndex, &rightElementData);
		}
		
		if (_leftIndex < _rightIndex)
		{
			SetElementsData(_dynamicVector, _leftIndex, rightElementData, _rightIndex, leftElementData);
		}
	}
	
	SetElementsData(_dynamicVector, pivotIndex, rightElementData, _rightIndex, pivotData);
	
	return _rightIndex;
}

static void QuickSortRecuAux(Vector_t *_dynamicVector, size_t _leftIndex, size_t _rightIndex)
{
	size_t pivotIndex;

	if (_rightIndex <= _leftIndex)
	{
		return;
	}

	pivotIndex = Partition(_dynamicVector, _leftIndex, _rightIndex);
	
	if (pivotIndex)
	{
		QuickSortRecuAux(_dynamicVector, _leftIndex, pivotIndex - 1);
	}
	if (pivotIndex < _rightIndex)
	{
		QuickSortRecuAux(_dynamicVector, pivotIndex + 1, _rightIndex); 
	}
}

static void QuickSortIterAux(Vector_t *_dynamicVector, size_t _leftIndex, size_t _rightIndex)
{
	int leftIndexPop, rightIndexPop;
	size_t pivotIndex;

	Stack_t *stack = StackCreate(STACK_CAPACITY, STACK_BLOCK_SIZE);
	if (NULL == stack)
	{
		return;
	}

	if (OK != StackPush(stack, (int)_rightIndex))
	{
		return;
	}

	if (OK != StackPush(stack, (int)_leftIndex))
	{
		return;
	}

	while (!StackIsEmpty(stack))
	{ 
		if (OK != StackPop(stack, &leftIndexPop))
		{
			return;
		}

		if (OK != StackPop(stack, &rightIndexPop))
		{
			return;
		}
		
		pivotIndex = Partition(_dynamicVector, leftIndexPop, rightIndexPop);

		if (leftIndexPop < (int)pivotIndex - 1) /* left side of the pivot is not empty */
		{
			if (OK != StackPush(stack, (int)(pivotIndex - 1)))
			{
				return;
			}

			if (OK != StackPush(stack, leftIndexPop))
			{
				return;
			}
		}

		if ((int)pivotIndex + 1 < rightIndexPop) /* right side of the pivot is not empty */
		{
			if (OK != StackPush(stack, rightIndexPop))
			{
				return;
			}

			if (OK != StackPush(stack, (int)(pivotIndex + 1)))
			{
				return;
			}
		}
	}

	StackDestroy(stack);
}

/*****************************************************************************/

ADTError_t QuickSortRecu(Vector_t *_dynamicVector)
{
	size_t numOfElements;
	
	if (!_dynamicVector)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	VectorNumOfElements(_dynamicVector, &numOfElements);
	
	if (numOfElements < 2)
	{
		return OK;
	}

	QuickSortRecuAux(_dynamicVector, 0, numOfElements - 1);
	
	return OK;
}

ADTError_t QuickSortIter(Vector_t *_dynamicVector)
{
	size_t numOfElements;
	
	if (!_dynamicVector)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	VectorNumOfElements(_dynamicVector, &numOfElements);
	
	if (numOfElements < 2)
	{
		return OK;
	}

	QuickSortIterAux(_dynamicVector, 0, numOfElements - 1);
	
	return OK;
}

ADTError_t InsertionSort(Vector_t *_dynamicVector)
{
	size_t numOfElements, i;
	int iElementData, jElementData, j;

	if (!_dynamicVector)
	{
		return POINTER_NOT_INITIALIZE;
	}

	VectorNumOfElements(_dynamicVector, &numOfElements);

	for (i = 1;i < numOfElements;++i)
	{
		j = i - 1;
		GetElementsData(_dynamicVector, j, &jElementData, i, &iElementData);

		while (0 <= j && iElementData < jElementData)
		{
			VectorSetElement(_dynamicVector, j + 1, jElementData);
			--j;
			VectorGetElement(_dynamicVector, j, &jElementData);
		}

		VectorSetElement(_dynamicVector, j + 1, iElementData);
	}

	return OK;
}

ADTError_t SelectionSort(Vector_t *_dynamicVector)
{
	size_t numOfElements, i, j, minElementIndex;
	int currElementData, minElementData, iElementData;

	if (!_dynamicVector)
	{
		return POINTER_NOT_INITIALIZE;
	}

	VectorNumOfElements(_dynamicVector, &numOfElements);

	for (i = 0;i < numOfElements;++i)
	{
		VectorGetElement(_dynamicVector, i, &minElementData);
		minElementIndex = i;

		for (j = i + 1;j < numOfElements;++j)
		{
			VectorGetElement(_dynamicVector, j, &currElementData);
			if (currElementData < minElementData)
			{
				minElementData = currElementData;
				minElementIndex = j;
			}
		}

		if (minElementIndex != i)
		{
			VectorGetElement(_dynamicVector, i, &iElementData);
			SetElementsData(_dynamicVector, i, minElementData, minElementIndex, iElementData);
		}
	}

	return OK;
}

ADTError_t ShellSort(Vector_t *_dynamicVector)
{
	size_t numOfElements, i, gap;
	int leftElementData, rightElementData;
	ADTError_t status;

	if (!_dynamicVector)
	{
		return POINTER_NOT_INITIALIZE;
	}

	VectorNumOfElements(_dynamicVector, &numOfElements);

	for (gap = numOfElements / 2;2 <= gap;gap /= 2)
	{
		for (i = 0;i < numOfElements / 2;++i)
		{
			GetElementsData(_dynamicVector, i, &leftElementData, i + gap, &rightElementData);

			if (rightElementData < leftElementData)
			{
				SetElementsData(_dynamicVector, i, rightElementData, i + gap, leftElementData);
			}
		}
	}

	status = InsertionSort(_dynamicVector);
	if (OK != status)
	{
		return status;
	}

	return OK;
}

/*****************************************************************************/

static void MergeAux(Vector_t *_dynamicVector, int *_tempArr, size_t _beginIndex, size_t _middleIndex, size_t _middlePlusIndex, size_t _endIndex)
{
	int beginIndexData, middlePlusData;
	size_t tempArrayIndex = 0;
	size_t i, j;

	while (_beginIndex <= _middleIndex && _middlePlusIndex <= _endIndex) /* find the smallest elements from the left and right side */
	{
		GetElementsData(_dynamicVector, _beginIndex, &beginIndexData, _middlePlusIndex, &middlePlusData);

		if (beginIndexData <= middlePlusData)
		{
			_tempArr[tempArrayIndex++] = beginIndexData;
			++_beginIndex;
		}
		else
		{
			_tempArr[tempArrayIndex++] = middlePlusData;
			++_middlePlusIndex;
		}
	}

	while (_beginIndex <= _middleIndex) /* copy the remain elements from begin */
	{
		VectorGetElement(_dynamicVector, _beginIndex, &beginIndexData);
		_tempArr[tempArrayIndex++] = beginIndexData;
		++_beginIndex;
	}

	while (_middlePlusIndex <= _endIndex) /* copy the remain elements from end */
	{
		VectorGetElement(_dynamicVector, _middlePlusIndex, &middlePlusData);
		_tempArr[tempArrayIndex++] = middlePlusData;
		++_middlePlusIndex;
	}

	for (i = _beginIndex, j = 0;i <= _endIndex;++i) /* copy from temp array to vector*/
	{
		VectorSetElement(_dynamicVector, i, _tempArr[j]);
	}
}

static void MergeRec(Vector_t *_dynamicVector, int *_tempArr, size_t _beginIndex, size_t _endIndex)
{
	size_t middleIndex;
	
	if (_endIndex <= _beginIndex)
	{
		return;
	}
	
	middleIndex = (_beginIndex + _endIndex) / 2;
	MergeRec(_dynamicVector, _tempArr ,_beginIndex, middleIndex);
	MergeRec(_dynamicVector, _tempArr, middleIndex + 1, _endIndex);
	MergeAux(_dynamicVector, _tempArr, _beginIndex, middleIndex, middleIndex + 1, _endIndex);
}

/*****************************************************************************/

ADTError_t MergeSort(Vector_t *_dynamicVector)
{
	size_t numOfElements;
	int *tempArr = NULL;

	if (!_dynamicVector)
	{
		return POINTER_NOT_INITIALIZE;
	}

	VectorNumOfElements(_dynamicVector, &numOfElements);

	if (numOfElements < 2)
	{
		return OK;
	}

	tempArr = (int*)malloc(numOfElements * sizeof(int));
	if (NULL == tempArr)
	{
		return REALLOCATION_FAILED;
	}

	MergeRec(_dynamicVector, tempArr, 0, numOfElements - 1);

	free(tempArr);

	return OK;
}

/********************************************************************/

static ADTError_t CountingSortAux(Vector_t *_dynamicVector, size_t _countingArraySize, size_t _digitToSort)
{
	size_t numOfElements, i;
	int *countingArray = NULL;
	int *sortingArray = NULL;
	int currElementData, j;
	size_t modulu;

	VectorNumOfElements(_dynamicVector, &numOfElements);

	countingArray = (int*)calloc(_countingArraySize, sizeof(int));
	if (!countingArray)
	{
		return REALLOCATION_FAILED;
	}

	sortingArray = (int*)malloc(numOfElements * sizeof(int));
	if (NULL == sortingArray)
	{
		free(countingArray);
		return REALLOCATION_FAILED;
	}

	modulu = (!_digitToSort) ? _countingArraySize - 1 : 10;
	_digitToSort = (!_digitToSort) ? 1 : _digitToSort;

	for (i = 0;i < numOfElements;++i)
	{
		VectorGetElement(_dynamicVector, i, &currElementData);
		++countingArray[(currElementData / _digitToSort) % modulu];
	}

	for (i = 1;i < _countingArraySize;++i)
	{
		countingArray[i] += countingArray[i - 1];
	}

	for(j = numOfElements - 1;0 <= j;--j)
	{
		VectorGetElement(_dynamicVector, j, &currElementData);
		sortingArray[countingArray[(currElementData / _digitToSort) % modulu] - 1] = currElementData;
		--countingArray[(currElementData / _digitToSort) % modulu];
	}

	for (i = 0;i < numOfElements;++i)
	{
		VectorSetElement(_dynamicVector, i, sortingArray[i]);
	}

	free(countingArray);
	free(sortingArray);

	return OK;
}

/********************************************************************/

ADTError_t CountingSort(Vector_t *_dynamicVector, size_t _maxElementValue)
{
	ADTError_t status;

	if (!_dynamicVector)
	{
		return POINTER_NOT_INITIALIZE;
	}

	if (_maxElementValue < 1)
	{
		return OK;
	}

	status = CountingSortAux(_dynamicVector, _maxElementValue + 1, 0);

	return status;
}

ADTError_t RadixSort(Vector_t *_dynamicVector, size_t _numOfDigits)
{
	ADTError_t status;
	size_t digitToSort; 
	size_t i;

	if (!_dynamicVector)
	{
		return POINTER_NOT_INITIALIZE;
	}

	if (!_numOfDigits)
	{
		return OK;
	}

	for (i = 0, digitToSort = 1;i < _numOfDigits;++i, digitToSort *= 10)
	{
		status = CountingSortAux(_dynamicVector, BASE, digitToSort);
		if (OK != status)
		{
			return status;
		}
	}

	return OK;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static void GetElementsData(Vector_t *_dynamicVector, size_t _firstIndex, int *_firstIndexoutputData
											, size_t _secondIndex, int *_secondIndexoutputData)
{	
	VectorGetElement(_dynamicVector, _firstIndex, _firstIndexoutputData);
	VectorGetElement(_dynamicVector, _secondIndex, _secondIndexoutputData);
}

static void SetElementsData(Vector_t *_dynamicVector, size_t _firstIndex, int _firstIndexinputData, 
											size_t _secondIndex, int _secondIndexinputData)
{
	VectorSetElement(_dynamicVector, _firstIndex, _firstIndexinputData);
	VectorSetElement(_dynamicVector, _secondIndex, _secondIndexinputData);
}