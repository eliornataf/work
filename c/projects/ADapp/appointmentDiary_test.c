#include <stdio.h> /* printf */
#include "appointment.h" /* Appointment header */
#include "appointmentDiary.h" /* Appointment Diary header */

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

void CreateAppointmentDiaryTest1(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 10;
	size_t incBlockSize = 2;
	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Appointment Diary Create Test 1:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
}

void CreateAppointmentDiaryTest2(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 10;
	size_t incBlockSize = 2;
	app_states_t *status = NULL;
	
	printf("\033[1;34m\n*******Appointment Diary Create Test 2:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, status);
	
	CHECK_FUNC(NULL == AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL == AppointmentDiaryTest) - status == NULL\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
}

void CreateAppointmentDiaryTest3(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 0;
	size_t incBlockSize = 0;
	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Appointment Diary Create Test 3:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL == AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL == AppointmentDiaryTest) - capacity & incBlockSize equal to 0\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
}

void CreateAppointmentDiaryTest4(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 0;
	size_t incBlockSize = 2;
	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Appointment Diary Create Test 4:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
}

void CreateAppointmentDiaryTest5(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 2;
	size_t incBlockSize = 0;
	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Appointment Diary Create Test 5:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
}

void CreateAppointmentTest1(void)
{
	Appointment_t *AppointmentTest = NULL;
	float appoStartTime = 5.99;
	float appoEndTime = 8.99;
	int roomNum = 100;
	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Appointment Create Test 1:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	AppointmentTest = CreateAppointment(appoStartTime, appoEndTime, roomNum, &status);
	
	CHECK_FUNC(NULL != AppointmentTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest)\n");
	
	DestoryAppointment(AppointmentTest);
}

void CreateAppointmentTest2(void)
{
	Appointment_t *AppointmentTest = NULL;
	float appoStartTime = 25.99;
	float appoEndTime = 8.99;
	int roomNum = 100;
	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Appointment Create Test 2:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	AppointmentTest = CreateAppointment(appoStartTime, appoEndTime, roomNum, &status);
	
	CHECK_FUNC(NULL == AppointmentTest);
	
	printf("\nExpected: SUCCESS (NULL == AppointmentTest)\n");
	
	DestoryAppointment(AppointmentTest);
}

void CreateAppointmentTest3(void)
{
	Appointment_t *AppointmentTest = NULL;
	float appoStartTime = 2.99;
	float appoEndTime = 28.99;
	int roomNum = 100;
	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Appointment Create Test 3:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	AppointmentTest = CreateAppointment(appoStartTime, appoEndTime, roomNum, &status);
	
	CHECK_FUNC(NULL == AppointmentTest);
	
	printf("\nExpected: SUCCESS (NULL == AppointmentTest)\n");
	
	DestoryAppointment(AppointmentTest);
}

void CreateAppointmentTest4(void)
{
	Appointment_t *AppointmentTest = NULL;
	float appoStartTime = 2.99;
	float appoEndTime = 28.99;
	int roomNum = 100;
	app_states_t *status = NULL;
	
	printf("\033[1;34m\n*******Appointment Create Test 4:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	AppointmentTest = CreateAppointment(appoStartTime, appoEndTime, roomNum, status);
	
	CHECK_FUNC(NULL == AppointmentTest);
	
	printf("\nExpected: SUCCESS (NULL == AppointmentTest) - status == NULL\n");
	
	DestoryAppointment(AppointmentTest);
}

void InsertAppointmentDiaryTest1(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 10;
	size_t incBlockSize = 2;
	Appointment_t *AppointmentTest = NULL;
	float appoStartTime = 2.99;
	float appoEndTime = 22.99;
	int roomNum = 100;
	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Insert Appointment Diary Test 1:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	printf("\nCreate Appointment Func Test: ");

	AppointmentTest = CreateAppointment(appoStartTime, appoEndTime, roomNum, &status);
	
	CHECK_FUNC(NULL != AppointmentTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest)\n");
	
	printf("\nInsert Appointment Diary Func Test: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	PrintAD(AppointmentDiaryTest);
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest);
}

void InsertAppointmentDiaryTest2(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 3;
	size_t incBlockSize = 2;
	Appointment_t *AppointmentTest1 = NULL;
	Appointment_t *AppointmentTest2 = NULL;
	Appointment_t *AppointmentTest3 = NULL;
	float appoStartTime = 2;
	float appoEndTime = 5;
	int roomNum = 100;

	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Insert Appointment Diary Test 1:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	printf("\nCreate Appointment Func Test 1: ");

	AppointmentTest1 = CreateAppointment(appoStartTime + 1, appoEndTime + 1, roomNum + 1, &status);
	
	CHECK_FUNC(NULL != AppointmentTest1);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest1)\n");
	
	printf("\nCreate Appointment Func Test 2: ");

	AppointmentTest2 = CreateAppointment(appoStartTime + 2, appoEndTime + 2, roomNum + 2, &status);
	
	CHECK_FUNC(NULL != AppointmentTest2);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest2)\n");
	
	printf("\nCreate Appointment Func Test 3: ");

	AppointmentTest3 = CreateAppointment(appoStartTime + 3, appoEndTime + 3, roomNum + 3, &status);
	
	CHECK_FUNC(NULL != AppointmentTest3);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest3)\n");
	
	printf("\nInsert Appointment Diary Func Test 1: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest1);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nInsert Appointment Diary Func Test 2: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest2);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nInsert Appointment Diary Func Test 3: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest3);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	PrintAD(AppointmentDiaryTest);
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest1);
	DestoryAppointment(AppointmentTest2);
	DestoryAppointment(AppointmentTest3);
}

void InsertAppointmentDiaryTest3(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 2;
	size_t incBlockSize = 2;
	Appointment_t *AppointmentTest1 = NULL;
	Appointment_t *AppointmentTest2 = NULL;
	Appointment_t *AppointmentTest3 = NULL;
	float appoStartTime = 2;
	float appoEndTime = 5;
	int roomNum = 100;

	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Insert Appointment Diary Test 3:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	printf("\nCreate Appointment Func Test 1: ");

	AppointmentTest1 = CreateAppointment(appoStartTime + 1, appoEndTime + 1, roomNum + 1, &status);
	
	CHECK_FUNC(NULL != AppointmentTest1);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest1)\n");
	
	printf("\nCreate Appointment Func Test 2: ");

	AppointmentTest2 = CreateAppointment(appoStartTime + 2, appoEndTime + 2, roomNum + 2, &status);
	
	CHECK_FUNC(NULL != AppointmentTest2);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest2)\n");
	
	printf("\nCreate Appointment Func Test 3: ");

	AppointmentTest3 = CreateAppointment(appoStartTime + 3, appoEndTime + 3, roomNum + 3, &status);
	
	CHECK_FUNC(NULL != AppointmentTest3);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest3)\n");
	
	printf("\nInsert Appointment Diary Func Test 1: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest1);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nInsert Appointment Diary Func Test 2: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest2);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nInsert Appointment Diary Func Test 3: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest3);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	PrintAD(AppointmentDiaryTest);
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest1);
	DestoryAppointment(AppointmentTest2);
	DestoryAppointment(AppointmentTest3);
}

void InsertAppointmentDiaryTest4(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 2;
	size_t incBlockSize = 2;
	Appointment_t *AppointmentTest1 = NULL;
	Appointment_t *AppointmentTest2 = NULL;
	Appointment_t *AppointmentTest3 = NULL;
	int roomNum = 100;

	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Insert Appointment Diary Test 4:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	printf("\nCreate Appointment Func Test 1: ");

	AppointmentTest1 = CreateAppointment(3, 4, roomNum + 1, &status);
	
	CHECK_FUNC(NULL != AppointmentTest1);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest1)\n");
	
	printf("\nCreate Appointment Func Test 2: ");

	AppointmentTest2 = CreateAppointment(2, 3, roomNum + 2, &status);
	
	CHECK_FUNC(NULL != AppointmentTest2);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest2)\n");
	
	printf("\nCreate Appointment Func Test 3: ");

	AppointmentTest3 = CreateAppointment(1, 2, roomNum + 3, &status);
	
	CHECK_FUNC(NULL != AppointmentTest3);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest3)\n");
	
	printf("\nInsert Appointment Diary Func Test 1: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest1);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nInsert Appointment Diary Func Test 2: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest2);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nInsert Appointment Diary Func Test 3: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest3);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	PrintAD(AppointmentDiaryTest);
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest1);
	DestoryAppointment(AppointmentTest2);
	DestoryAppointment(AppointmentTest3);
}

void InsertAppointmentDiaryTest5(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 2;
	size_t incBlockSize = 0;
	Appointment_t *AppointmentTest1 = NULL;
	Appointment_t *AppointmentTest2 = NULL;
	Appointment_t *AppointmentTest3 = NULL;
	int roomNum = 100;

	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Insert Appointment Diary Test 5:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	printf("\nCreate Appointment Func Test 1: ");

	AppointmentTest1 = CreateAppointment(3, 4, roomNum + 1, &status);
	
	CHECK_FUNC(NULL != AppointmentTest1);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest1)\n");
	
	printf("\nCreate Appointment Func Test 2: ");

	AppointmentTest2 = CreateAppointment(2, 3, roomNum + 2, &status);
	
	CHECK_FUNC(NULL != AppointmentTest2);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest2)\n");
	
	printf("\nCreate Appointment Func Test 3: ");

	AppointmentTest3 = CreateAppointment(1, 2, roomNum + 3, &status);
	
	CHECK_FUNC(NULL != AppointmentTest3);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest3)\n");
	
	printf("\nInsert Appointment Diary Func Test 1: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest1);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nInsert Appointment Diary Func Test 2: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest2);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nInsert Appointment Diary Func Test 3: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest3);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: FAILURE (status check)\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest1);
	DestoryAppointment(AppointmentTest2);
	DestoryAppointment(AppointmentTest3);
}

void InsertAppointmentDiaryTest6(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	Appointment_t *AppointmentTest = NULL;
	float appoStartTime = 2.99;
	float appoEndTime = 22.99;
	int roomNum = 100;
	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Insert Appointment Diary Test 6:*******\n\n\033[0m");
	
	printf("\nCreate Appointment Func Test: ");

	AppointmentTest = CreateAppointment(appoStartTime, appoEndTime, roomNum, &status);
	
	CHECK_FUNC(NULL != AppointmentTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest)\n");
	
	printf("\nInsert Appointment Diary Func Test: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest);
	
	CHECK_FUNC(POINTER_NOT_INITIALIZE == status);
	
	printf("\nExpected: SUCCESS (status check) - AppointmentDiaryTest == NULL\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest);
}

void InsertAppointmentDiaryTest7(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 10;
	size_t incBlockSize = 2;
	Appointment_t *AppointmentTest = NULL;
	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Insert Appointment Diary Test 7:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	printf("\nInsert Appointment Diary Func Test: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest);
	
	CHECK_FUNC(POINTER_NOT_INITIALIZE == status);
	
	printf("\nExpected: SUCCESS (status check) - Appointment == NULL\n");
	
	PrintAD(AppointmentDiaryTest);
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest);
}

void FindAppointmentDiaryTest1(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 10;
	size_t incBlockSize = 2;
	Appointment_t *AppointmentTest = NULL;
	float appoStartTime = 2.99;
	float appoEndTime = 22.99;
	int roomNum = 100;
	app_states_t status = OK;
	Appointment_t *foundAppointment = NULL;
	int foundIndex = -1;
	
	printf("\033[1;34m\n*******Find Appointment Diary Test 1:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	printf("\nCreate Appointment Func Test: ");

	AppointmentTest = CreateAppointment(appoStartTime, appoEndTime, roomNum, &status);
	
	CHECK_FUNC(NULL != AppointmentTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest)\n");
	
	printf("\nInsert Appointment Diary Func Test: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nFind Appointment Func Test 1: ");
	
	status = FindAppointmentInAD(AppointmentDiaryTest, appoStartTime
												, &foundAppointment, &foundIndex);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nFind Appointment Func Test 2: ");
	
	CHECK_FUNC(0 == foundIndex);
	
	printf("\nExpected: SUCCESS (foundIndex check)\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest);
}

void FindAppointmentDiaryTest2(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 2;
	size_t incBlockSize = 2;
	Appointment_t *AppointmentTest1 = NULL;
	Appointment_t *AppointmentTest2 = NULL;
	Appointment_t *AppointmentTest3 = NULL;
	int roomNum = 100;
	Appointment_t *foundAppointment = NULL;
	int foundIndex = -1;

	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Find Appointment Diary Test 2:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	printf("\nCreate Appointment Func Test 1: ");

	AppointmentTest1 = CreateAppointment(3, 4, roomNum + 1, &status);
	
	CHECK_FUNC(NULL != AppointmentTest1);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest1)\n");
	
	printf("\nCreate Appointment Func Test 2: ");

	AppointmentTest2 = CreateAppointment(2, 3, roomNum + 2, &status);
	
	CHECK_FUNC(NULL != AppointmentTest2);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest2)\n");
	
	printf("\nCreate Appointment Func Test 3: ");

	AppointmentTest3 = CreateAppointment(1, 2, roomNum + 3, &status);
	
	CHECK_FUNC(NULL != AppointmentTest3);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest3)\n");
	
	printf("\nInsert Appointment Diary Func Test 1: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest1);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nInsert Appointment Diary Func Test 2: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest2);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nInsert Appointment Diary Func Test 3: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest3);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nFind Appointment Func Test 1: ");
	
	status = FindAppointmentInAD(AppointmentDiaryTest, 3, &foundAppointment, &foundIndex);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nFind Appointment Func Test 2: ");
	
	CHECK_FUNC(2 == foundIndex);
	
	printf("\nExpected: SUCCESS (foundIndex check)\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest1);
	DestoryAppointment(AppointmentTest2);
	DestoryAppointment(AppointmentTest3);
}

void FindAppointmentDiaryTest3(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 2;
	size_t incBlockSize = 2;
	Appointment_t *AppointmentTest1 = NULL;
	Appointment_t *AppointmentTest2 = NULL;
	Appointment_t *AppointmentTest3 = NULL;
	int roomNum = 100;
	Appointment_t *foundAppointment = NULL;
	int foundIndex = -1;

	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Find Appointment Diary Test 3:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	printf("\nCreate Appointment Func Test 1: ");

	AppointmentTest1 = CreateAppointment(3, 4, roomNum + 1, &status);
	
	CHECK_FUNC(NULL != AppointmentTest1);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest1)\n");
	
	printf("\nCreate Appointment Func Test 2: ");

	AppointmentTest2 = CreateAppointment(2, 3, roomNum + 2, &status);
	
	CHECK_FUNC(NULL != AppointmentTest2);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest2)\n");
	
	printf("\nCreate Appointment Func Test 3: ");

	AppointmentTest3 = CreateAppointment(1, 2, roomNum + 3, &status);
	
	CHECK_FUNC(NULL != AppointmentTest3);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest3)\n");
	
	printf("\nInsert Appointment Diary Func Test 1: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest1);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nInsert Appointment Diary Func Test 2: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest2);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nInsert Appointment Diary Func Test 3: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest3);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nFind Appointment Func Test 1: ");
	
	status = FindAppointmentInAD(AppointmentDiaryTest, 5, &foundAppointment, &foundIndex);
	
	CHECK_FUNC(THE_APPOINTMENT_IS_NOT_FOUND == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nFind Appointment Func Test 2: ");
	
	CHECK_FUNC(-1 == foundIndex);
	
	printf("\nExpected: SUCCESS (foundIndex check)\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest1);
	DestoryAppointment(AppointmentTest2);
	DestoryAppointment(AppointmentTest3);
}

void FindAppointmentDiaryTest4(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 10;
	size_t incBlockSize = 2;
	Appointment_t *AppointmentTest = NULL;
	float appoStartTime = 2.99;
	float appoEndTime = 22.99;
	int roomNum = 100;
	app_states_t status = OK;
	Appointment_t *foundAppointment = NULL;
	int foundIndex = -1;
	
	printf("\033[1;34m\n*******Find Appointment Diary Test 4:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	printf("\nCreate Appointment Func Test: ");

	AppointmentTest = CreateAppointment(appoStartTime, appoEndTime, roomNum, &status);
	
	CHECK_FUNC(NULL != AppointmentTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest)\n");
	
	printf("\nFind Appointment Func Test 1: ");
	
	status = FindAppointmentInAD(AppointmentDiaryTest, appoStartTime
												, &foundAppointment, &foundIndex);
	
	CHECK_FUNC(UNDERFLOW == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nFind Appointment Func Test 2: ");
	
	CHECK_FUNC(-1 == foundIndex);
	
	printf("\nExpected: SUCCESS (foundIndex check)\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest);
}

void FindAppointmentDiaryTest5(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	Appointment_t *AppointmentTest = NULL;
	float appoStartTime = 2.99;
	float appoEndTime = 22.99;
	int roomNum = 100;
	app_states_t status = OK;
	Appointment_t *foundAppointment = NULL;
	int foundIndex = -1;
	
	printf("\033[1;34m\n*******Find Appointment Diary Test 5:*******\n\n\033[0m");
	
	printf("Create Appointment Func Test: ");

	AppointmentTest = CreateAppointment(appoStartTime, appoEndTime, roomNum, &status);
	
	CHECK_FUNC(NULL != AppointmentTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest)\n");
	
	printf("\nFind Appointment Func Test 1: ");
	
	status = FindAppointmentInAD(AppointmentDiaryTest, appoStartTime
												, &foundAppointment, &foundIndex);
	
	CHECK_FUNC(POINTER_NOT_INITIALIZE == status);
	
	printf("\nExpected: SUCCESS (status check) - AppointmentDiaryTest == NULL\n");
	
	printf("\nFind Appointment Func Test 2: ");
	
	CHECK_FUNC(-1 == foundIndex);
	
	printf("\nExpected: SUCCESS (foundIndex check)\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest);
}

void FindAppointmentDiaryTest6(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 10;
	size_t incBlockSize = 2;
	Appointment_t *AppointmentTest = NULL;
	float appoStartTime = 2.99;
	float appoEndTime = 22.99;
	int roomNum = 100;
	app_states_t status = OK;
	Appointment_t **foundAppointment = NULL;
	int foundIndex = -1;
	
	printf("\033[1;34m\n*******Find Appointment Diary Test 6:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");

	printf("\nCreate Appointment Func Test: ");

	AppointmentTest = CreateAppointment(appoStartTime, appoEndTime, roomNum, &status);
	
	CHECK_FUNC(NULL != AppointmentTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest)\n");

	printf("\nFind Appointment Func Test 1: ");
	
	status = FindAppointmentInAD(AppointmentDiaryTest, appoStartTime
												, foundAppointment, &foundIndex);
	
	CHECK_FUNC(POINTER_NOT_INITIALIZE == status);
	
	printf("\nExpected: SUCCESS (status check) - foundAppointment == NULL\n");
	
	printf("\nFind Appointment Func Test 2: ");
	
	CHECK_FUNC(-1 == foundIndex);
	
	printf("\nExpected: SUCCESS (foundIndex check)\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest);
}

void FindAppointmentDiaryTest7(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 10;
	size_t incBlockSize = 2;
	Appointment_t *AppointmentTest = NULL;
	float appoStartTime = 2.99;
	float appoEndTime = 22.99;
	int roomNum = 100;
	app_states_t status = OK;
	Appointment_t *foundAppointment = NULL;
	int *foundIndex = NULL;
	
	printf("\033[1;34m\n*******Find Appointment Diary Test 7:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	printf("\nCreate Appointment Func Test: ");

	AppointmentTest = CreateAppointment(appoStartTime, appoEndTime, roomNum, &status);
	
	CHECK_FUNC(NULL != AppointmentTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest)\n");
	
	printf("\nFind Appointment Func Test 1: ");
	
	status = FindAppointmentInAD(AppointmentDiaryTest, appoStartTime
												, &foundAppointment, foundIndex);
	
	CHECK_FUNC(POINTER_NOT_INITIALIZE == status);
	
	printf("\nExpected: SUCCESS (status check) - foundIndex == NULL\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest);
}

void FindAppointmentDiaryTest8(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 10;
	size_t incBlockSize = 2;
	Appointment_t *AppointmentTest = NULL;
	float appoStartTime = 2.99;
	float appoEndTime = 22.99;
	int roomNum = 100;
	app_states_t status = OK;
	Appointment_t *foundAppointment = NULL;
	int foundIndex = -1;
	
	printf("\033[1;34m\n*******Find Appointment Diary Test 8:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	printf("\nCreate Appointment Func Test: ");

	AppointmentTest = CreateAppointment(appoStartTime, appoEndTime, roomNum, &status);
	
	CHECK_FUNC(NULL != AppointmentTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest)\n");
	
	printf("\nInsert Appointment Diary Func Test: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nFind Appointment Func Test: ");
	
	status = FindAppointmentInAD(AppointmentDiaryTest, 30
												, &foundAppointment, &foundIndex);
	
	CHECK_FUNC(APPOINTMENT_START_TIME_ERROR == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest);
}

void RemoveAppointmentDiaryTest1(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 10;
	size_t incBlockSize = 2;
	Appointment_t *AppointmentTest = NULL;
	float appoStartTime = 2.99;
	float appoEndTime = 22.99;
	int roomNum = 100;
	app_states_t status = OK;
	Appointment_t *foundAppointment = NULL;
	int foundIndex = -1;
	Appointment_t *removedAppointment = NULL;
	
	printf("\033[1;34m\n*******Remove Appointment Diary Test 1:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	printf("\nCreate Appointment Func Test: ");

	AppointmentTest = CreateAppointment(appoStartTime, appoEndTime, roomNum, &status);
	
	CHECK_FUNC(NULL != AppointmentTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest)\n");
	
	printf("\nInsert Appointment Diary Func Test: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nFind Appointment Func Test 1: ");
	
	status = FindAppointmentInAD(AppointmentDiaryTest, appoStartTime
												, &foundAppointment, &foundIndex);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nFind Appointment Func Test 2: ");
	
	CHECK_FUNC(0 == foundIndex);
	
	printf("\nExpected: SUCCESS (foundIndex check)\n");
	
	printf("\nRemove Appointment Func Test: ");
	
	status = RemoveAppointmentFromAD(AppointmentDiaryTest, &removedAppointment, &foundIndex);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nPrint Appointment Func Test: ");
	
	status = PrintAD(AppointmentDiaryTest);
	
	CHECK_FUNC(UNDERFLOW == status);	
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest);
}

void RemoveAppointmentDiaryTest2(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 2;
	size_t incBlockSize = 2;
	Appointment_t *AppointmentTest1 = NULL;
	Appointment_t *AppointmentTest2 = NULL;
	Appointment_t *AppointmentTest3 = NULL;
	int roomNum = 100;
	Appointment_t *foundAppointment = NULL;
	int foundIndex = -1;
	Appointment_t *removedAppointment = NULL;

	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Remove Appointment Diary Test 2:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	printf("\nCreate Appointment Func Test 1: ");

	AppointmentTest1 = CreateAppointment(3, 4, roomNum + 1, &status);
	
	CHECK_FUNC(NULL != AppointmentTest1);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest1)\n");
	
	printf("\nCreate Appointment Func Test 2: ");

	AppointmentTest2 = CreateAppointment(2, 3, roomNum + 2, &status);
	
	CHECK_FUNC(NULL != AppointmentTest2);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest2)\n");
	
	printf("\nCreate Appointment Func Test 3: ");

	AppointmentTest3 = CreateAppointment(1, 2, roomNum + 3, &status);
	
	CHECK_FUNC(NULL != AppointmentTest3);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest3)\n");
	
	printf("\nInsert Appointment Diary Func Test 1: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest1);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nInsert Appointment Diary Func Test 2: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest2);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nInsert Appointment Diary Func Test 3: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest3);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nFind Appointment Func Test 1: ");
	
	status = FindAppointmentInAD(AppointmentDiaryTest, 3, &foundAppointment, &foundIndex);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nFind Appointment Func Test 2: ");
	
	CHECK_FUNC(2 == foundIndex);
	
	printf("\nExpected: SUCCESS (foundIndex check)\n");
	
	printf("\nRemove Appointment Func Test: ");
	
	status = RemoveAppointmentFromAD(AppointmentDiaryTest, &removedAppointment, &foundIndex);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	PrintAD(AppointmentDiaryTest);
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest1);
	DestoryAppointment(AppointmentTest2);
	DestoryAppointment(AppointmentTest3);
}

void RemoveAppointmentDiaryTest3(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	Appointment_t *AppointmentTest = NULL;
	float appoStartTime = 2.99;
	float appoEndTime = 22.99;
	int roomNum = 100;
	app_states_t status = OK;
	int foundIndex = -1;
	Appointment_t *removedAppointment = NULL;
	
	printf("\033[1;34m\n*******Remove Appointment Diary Test 3:*******\n\n\033[0m");
	
	printf("Create Appointment Func Test: ");

	AppointmentTest = CreateAppointment(appoStartTime, appoEndTime, roomNum, &status);
	
	CHECK_FUNC(NULL != AppointmentTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest)\n");
	
	printf("\nRemove Appointment Func Test: ");
	
	status = RemoveAppointmentFromAD(AppointmentDiaryTest, &removedAppointment, &foundIndex);
	
	CHECK_FUNC(POINTER_NOT_INITIALIZE == status);
	
	printf("\nExpected: SUCCESS (status check) - AppointmentDiaryTest == NULL\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest);
}

void RemoveAppointmentDiaryTest4(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 10;
	size_t incBlockSize = 2;
	Appointment_t *AppointmentTest = NULL;
	float appoStartTime = 2.99;
	float appoEndTime = 22.99;
	int roomNum = 100;
	app_states_t status = OK;
	int foundIndex = -1;
	Appointment_t **removedAppointment = NULL;
	
	printf("\033[1;34m\n*******Remove Appointment Diary Test 4:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	printf("\nCreate Appointment Func Test: ");

	AppointmentTest = CreateAppointment(appoStartTime, appoEndTime, roomNum, &status);
	
	CHECK_FUNC(NULL != AppointmentTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest)\n");
	
	printf("\nRemove Appointment Func Test: ");
	
	status = RemoveAppointmentFromAD(AppointmentDiaryTest, removedAppointment, &foundIndex);
	
	CHECK_FUNC(POINTER_NOT_INITIALIZE == status);
	
	printf("\nExpected: SUCCESS (status check) - removedAppointment == NULL\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest);
}

void RemoveAppointmentDiaryTest5(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 10;
	size_t incBlockSize = 2;
	Appointment_t *AppointmentTest = NULL;
	float appoStartTime = 2.99;
	float appoEndTime = 22.99;
	int roomNum = 100;
	app_states_t status = OK;
	int *removedIndex = NULL;
	Appointment_t *removedAppointment = NULL;
	
	printf("\033[1;34m\n*******Remove Appointment Diary Test 5:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	printf("\nCreate Appointment Func Test: ");

	AppointmentTest = CreateAppointment(appoStartTime, appoEndTime, roomNum, &status);
	
	CHECK_FUNC(NULL != AppointmentTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest)\n");
	
	printf("\nRemove Appointment Func Test: ");
	
	status = RemoveAppointmentFromAD(AppointmentDiaryTest, &removedAppointment, removedIndex);
	
	CHECK_FUNC(POINTER_NOT_INITIALIZE == status);
	
	printf("\nExpected: SUCCESS (status check) - removedIndex == NULL\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest);
}

void DestroyAppointmentDiaryTest1(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 10;
	size_t incBlockSize = 2;
	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Destory Appointment Diary Test 1:*******\n\n\033[0m");
	
	printf("Create Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	printf("\nDestory Appointment Func Test: ");
	
	status = DestroyAppointmentDiary(AppointmentDiaryTest);
	
	CHECK_FUNC(OK == status);	
	
	printf("\nExpected: SUCCESS (status check)\n");
}

void DestroyAppointmentDiaryTest2(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Destory Appointment Diary Test 1:*******\n\n\033[0m");
	
	printf("\nDestory Appointment Func Test: ");
	
	status = DestroyAppointmentDiary(AppointmentDiaryTest);
	
	CHECK_FUNC(POINTER_NOT_INITIALIZE == status);
	
	printf("\nExpected: SUCCESS (status check) - AppointmentDiaryTest == NULL\n");	
}

void PrintADTest1(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 3;
	size_t incBlockSize = 2;
	Appointment_t *AppointmentTest1 = NULL;
	Appointment_t *AppointmentTest2 = NULL;
	Appointment_t *AppointmentTest3 = NULL;
	float appoStartTime = 2;
	float appoEndTime = 5;
	int roomNum = 100;

	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Print Appointment Diary Test 1:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	printf("\nCreate Appointment Func Test 1: ");

	AppointmentTest1 = CreateAppointment(appoStartTime + 1, appoEndTime + 1, roomNum + 1, &status);
	
	CHECK_FUNC(NULL != AppointmentTest1);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest1)\n");
	
	printf("\nCreate Appointment Func Test 2: ");

	AppointmentTest2 = CreateAppointment(appoStartTime + 2, appoEndTime + 2, roomNum + 2, &status);
	
	CHECK_FUNC(NULL != AppointmentTest2);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest2)\n");
	
	printf("\nCreate Appointment Func Test 3: ");

	AppointmentTest3 = CreateAppointment(appoStartTime + 3, appoEndTime + 3, roomNum + 3, &status);
	
	CHECK_FUNC(NULL != AppointmentTest3);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentTest3)\n");
	
	printf("\nInsert Appointment Diary Func Test 1: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest1);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nInsert Appointment Diary Func Test 2: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest2);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	printf("\nInsert Appointment Diary Func Test 3: ");
	
	status = InsertAppointmentDiary(AppointmentDiaryTest, AppointmentTest3);
	
	CHECK_FUNC(OK == status);
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	status = PrintAD(AppointmentDiaryTest);
	
	printf("\nPrint Appointment Func Test: ");
	
	CHECK_FUNC(OK == status);	
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
	DestoryAppointment(AppointmentTest1);
	DestoryAppointment(AppointmentTest2);
	DestoryAppointment(AppointmentTest3);
}

void PrintADTest2(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	size_t capacity = 3;
	size_t incBlockSize = 2;
	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Print Appointment Diary Test 2:*******\n\n\033[0m");
	
	printf("Create Appointment Diary Func Test: ");

	AppointmentDiaryTest = CreateAppointmentDiary(capacity, incBlockSize, &status);
	
	CHECK_FUNC(NULL != AppointmentDiaryTest);
	
	printf("\nExpected: SUCCESS (NULL != AppointmentDiaryTest)\n");
	
	status = PrintAD(AppointmentDiaryTest);
	
	printf("\nPrint Appointment Func Test: ");
	
	CHECK_FUNC(UNDERFLOW == status);	
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
}

void PrintADTest3(void)
{
	AppointmentDiary_t *AppointmentDiaryTest = NULL;
	app_states_t status = OK;
	
	printf("\033[1;34m\n*******Print Appointment Diary Test 3:*******\n\n\033[0m");
	
	printf("Print Appointment Func Test: ");
	
	status = PrintAD(AppointmentDiaryTest);
	
	CHECK_FUNC(POINTER_NOT_INITIALIZE == status);	
	
	printf("\nExpected: SUCCESS (status check)\n");
	
	DestroyAppointmentDiary(AppointmentDiaryTest);
}

int main(void)
{
	CreateAppointmentDiaryTest1();
	CreateAppointmentDiaryTest2();
	CreateAppointmentDiaryTest3();
	CreateAppointmentDiaryTest4();
	CreateAppointmentDiaryTest5();
	
	CreateAppointmentTest1();
	CreateAppointmentTest2();
	CreateAppointmentTest3();
	CreateAppointmentTest4();
	
	InsertAppointmentDiaryTest1();
	InsertAppointmentDiaryTest2();
	InsertAppointmentDiaryTest3();
	InsertAppointmentDiaryTest4();
	InsertAppointmentDiaryTest5();
	InsertAppointmentDiaryTest6();
	InsertAppointmentDiaryTest7();
	
	FindAppointmentDiaryTest1();
	FindAppointmentDiaryTest2();
	FindAppointmentDiaryTest3();
	FindAppointmentDiaryTest4();
	FindAppointmentDiaryTest5();
	FindAppointmentDiaryTest6();
	FindAppointmentDiaryTest7();
	FindAppointmentDiaryTest8();
	
	RemoveAppointmentDiaryTest1();
	RemoveAppointmentDiaryTest2();
	RemoveAppointmentDiaryTest3();
	RemoveAppointmentDiaryTest4();
	RemoveAppointmentDiaryTest5();
	
	DestroyAppointmentDiaryTest1();
	DestroyAppointmentDiaryTest2();
	
	PrintADTest1();
	PrintADTest2();
	PrintADTest3();
	
	return 0;
}
