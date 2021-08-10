#include <stdio.h> /* printf, rand */
#include <time.h> /* srand, clock */
#include "dynamicVector.h" /* Dynamic Vector Header */
#include "sort.h" /* Sort Header */

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

#define NUM_LIMIT (60000)

void SortTest(void)
{
	Vector_t *bubbleVector = NULL;
	Vector_t *shakeVector = NULL;
	Vector_t *quickVectorRecu = NULL;
	Vector_t *quickVectorIter = NULL;
	Vector_t *insertionVector = NULL;
	Vector_t *selectionVector = NULL;
	Vector_t *shellVector = NULL;
	Vector_t *mergeVector = NULL;
	Vector_t *countingVector = NULL;
	Vector_t *radixVector = NULL;
	int capacity = 5;
	int incBlockSize = 2;
	int i, status, randNum;
	time_t currentTime;
	clock_t benchmark_begin, benchmark_end;
	double time_spent;
	
	srand((unsigned)time(&currentTime));
	
	printf("\033[1;34m\n*******Sort Test:*******\n\n\033[0m");
	
	printf("capacity = 5, incBlockSize = 2, Number of Push = 60000\n\n");
	
	printf("Create Bubble Vector Func Test: ");
	
	bubbleVector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != bubbleVector);
	
	printf("\nExpected: SUCCESS (bubbleVector != NULL check)\n");
	
	printf("\nCreate Shake Vector Func Test: ");
	
	shakeVector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != shakeVector);
	
	printf("\nExpected: SUCCESS (shakeVector != NULL check)\n");
	
	printf("\nCreate Quick Vector Recu Func Test: ");
	
	quickVectorRecu = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != quickVectorRecu);
	
	printf("\nExpected: SUCCESS (quickVectorRecu != NULL check)\n");

	printf("\nCreate Quick Vector Iter Func Test: ");
	
	quickVectorIter = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != quickVectorIter);
	
	printf("\nExpected: SUCCESS (quickVectorIter != NULL check)\n");

	printf("\nCreate Insertion Vector Func Test: ");
	
	insertionVector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != insertionVector);
	
	printf("\nExpected: SUCCESS (insertionVector != NULL check)\n");
	
	printf("\nCreate Selection Vector Func Test: ");
	
	selectionVector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != selectionVector);
	
	printf("\nExpected: SUCCESS (selectionVector != NULL check)\n");

	printf("\nCreate Shell Vector Func Test: ");
	
	shellVector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != shellVector);
	
	printf("\nExpected: SUCCESS (shellVector != NULL check)\n");

	printf("\nCreate Merge Vector Func Test: ");
	
	mergeVector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != mergeVector);
	
	printf("\nExpected: SUCCESS (mergeVector != NULL check)\n");
	
	printf("\nCreate Counting Vector Func Test: ");
	
	countingVector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != countingVector);
	
	printf("\nExpected: SUCCESS (countingVector != NULL check)\n");

	printf("\nCreate Radix Vector Func Test: ");
	
	radixVector = VectorCreate(capacity, incBlockSize);
	
	CHECK_FUNC(NULL != radixVector);
	
	printf("\nExpected: SUCCESS (radixVector != NULL check)\n");
	
	printf("\nPush Func Test: ");
	
	for (i = 0;i < NUM_LIMIT;++i)
	{
		randNum = rand() % NUM_LIMIT;
	
		status = VectorPush(bubbleVector, randNum);
		
		status = VectorPush(shakeVector, randNum);
		
		status = VectorPush(quickVectorRecu, randNum);

		status = VectorPush(quickVectorIter, randNum);	

		status = VectorPush(insertionVector, randNum);	

		status = VectorPush(selectionVector, randNum);	

		status = VectorPush(shellVector, randNum);	

		status = VectorPush(mergeVector, randNum);	

		status = VectorPush(countingVector, randNum);	

		status = VectorPush(radixVector, randNum);	
	}	
		
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 1 SUCCESS (bubbleVector check status) && 1 SUCCESS (shakeVector check status) && 1 SUCCESS (quickVectorRecu check status) && 1 SUCCESS (quickVectorIter check status) && 1 SUCCESS (insertionVector check status) && 1 SUCCESS (selectionVector check status) && 1 SUCCESS (shellVector check status) && 1 SUCCESS (mergeVector check status) && 1 SUCCESS (countingVector check status)\n");
	
	printf("\nBubble Sort Func Test: ");
	
	benchmark_begin = clock();
	
	status = BubbleSort(bubbleVector);
	
	benchmark_end = clock();
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 1 SUCCESS (check status)\n");
	
	time_spent = (double)(benchmark_end - benchmark_begin) / CLOCKS_PER_SEC;
	
	printf("\033[1;33m\nBubble Sort benchmark: %f\n\033[0m", time_spent);

	printf("\nShake Sort Func Test: ");
	
	benchmark_begin = clock();
	
	status = ShakeSort(shakeVector);
	
	benchmark_end = clock();
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 1 SUCCESS (check status)\n");
	
	time_spent = (double)(benchmark_end - benchmark_begin) / CLOCKS_PER_SEC;
	
	printf("\033[1;33m\nShake Sort benchmark: %f\n\033[0m", time_spent);
	
	printf("\nQuick Sort Recu Func Test: ");
	
	benchmark_begin = clock();
	
	status = QuickSortRecu(quickVectorRecu);
	
	benchmark_end = clock();
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 1 SUCCESS (check status)\n");
	
	time_spent = (double)(benchmark_end - benchmark_begin) / CLOCKS_PER_SEC;
	
	printf("\033[1;33m\nQuick Sort Recu benchmark: %f\n\033[0m", time_spent);

	printf("\nQuick Sort Iter Func Test: ");
	
	benchmark_begin = clock();
	
	status = QuickSortIter(quickVectorIter);
	
	benchmark_end = clock();
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 1 SUCCESS (check status)\n");
	
	time_spent = (double)(benchmark_end - benchmark_begin) / CLOCKS_PER_SEC;
	
	printf("\033[1;33m\nQuick Sort Iter benchmark: %f\n\033[0m", time_spent);

	printf("\nInsertion Sort Func Test: ");
	
	benchmark_begin = clock();
	
	status = InsertionSort(insertionVector);
	
	benchmark_end = clock();
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 1 SUCCESS (check status)\n");
	
	time_spent = (double)(benchmark_end - benchmark_begin) / CLOCKS_PER_SEC;
	
	printf("\033[1;33m\nInsertion Sort benchmark: %f\n\033[0m", time_spent);

	printf("\nSelection Sort Func Test: ");
	
	benchmark_begin = clock();
	
	status = SelectionSort(selectionVector);
	
	benchmark_end = clock();
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 1 SUCCESS (check status)\n");
	
	time_spent = (double)(benchmark_end - benchmark_begin) / CLOCKS_PER_SEC;
	
	printf("\033[1;33m\nSelection Sort benchmark: %f\n\033[0m", time_spent);

	printf("\nShell Sort Func Test: ");
	
	benchmark_begin = clock();
	
	status = ShellSort(shellVector);
	
	benchmark_end = clock();
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 1 SUCCESS (check status)\n");
	
	time_spent = (double)(benchmark_end - benchmark_begin) / CLOCKS_PER_SEC;
	
	printf("\033[1;33m\nShell Sort benchmark: %f\n\033[0m", time_spent);

	printf("\nMerge Sort Func Test: ");
	
	benchmark_begin = clock();
	
	status = ShellSort(mergeVector);
	
	benchmark_end = clock();
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 1 SUCCESS (check status)\n");
	
	time_spent = (double)(benchmark_end - benchmark_begin) / CLOCKS_PER_SEC;
	
	printf("\033[1;33m\nMerge Sort benchmark: %f\n\033[0m", time_spent);

	printf("\nCounting Sort Func Test: ");
	
	benchmark_begin = clock();
	
	status = CountingSort(countingVector, NUM_LIMIT);
	
	benchmark_end = clock();
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 1 SUCCESS (check status)\n");
	
	time_spent = (double)(benchmark_end - benchmark_begin) / CLOCKS_PER_SEC;
	
	printf("\033[1;33m\nCounting Sort benchmark: %f\n\033[0m", time_spent);

	printf("\nRadix Sort Func Test: ");
	
	benchmark_begin = clock();
	
	status = CountingSort(radixVector, NUM_LIMIT);
	
	benchmark_end = clock();
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: 1 SUCCESS (check status)\n");
	
	time_spent = (double)(benchmark_end - benchmark_begin) / CLOCKS_PER_SEC;
	
	printf("\033[1;33m\nRadix Sort benchmark: %f\n\033[0m", time_spent);

	VectorDestroy(bubbleVector);
	VectorDestroy(shakeVector);
	VectorDestroy(quickVectorRecu);
	VectorDestroy(quickVectorIter);
	VectorDestroy(insertionVector);
	VectorDestroy(selectionVector);
	VectorDestroy(shellVector);
	VectorDestroy(mergeVector);
	VectorDestroy(countingVector);
	VectorDestroy(radixVector);
}

int main(void)
{
	SortTest();
	
	return 0;
}
