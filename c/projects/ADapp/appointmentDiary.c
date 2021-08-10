#include <stdlib.h> /* malloc, realloc, free */
#include <stdio.h> /* printf */

#include "appointment.h" /* Appointment header */
#include "appointmentDiary.h" /* Appointment Diary header */

#define NUM_OF_ELEMENTS_INIT (0)
#define AD_IS_EMPTY (0)
#define FCLOSE_SUCCEEDED (0)

/*****************************************************************************/

struct Appointment
{
	float appoStartTime;
	float appoEndTime;
	int roomNum;
};

struct AppointmentDiary
{
	Appointment_t *m_array;
	size_t m_capacity;
	size_t m_incBlockSize;
	size_t m_numOfElements;
};

/*****************************************************************************/

AppointmentDiary_t *CreateAppointmentDiary(size_t capacity, size_t incBlockSize
															, app_states_t *status)
{
	AppointmentDiary_t *AppointmentDiary = NULL;
	
	if (!status)
	{
		return NULL;
	}
	
	if (!capacity && !incBlockSize)
	{
		*status = INCREASE_CAPACITY_AND_BLOCK_SIZE_ZERO;
		return NULL;
	}
	
	AppointmentDiary = (AppointmentDiary_t*)malloc(sizeof(AppointmentDiary_t));
	if (!AppointmentDiary)
	{
		*status = ALLOCATION_FAILED;
		return NULL;
	}
	
	AppointmentDiary->m_array = (Appointment_t*)malloc(capacity * sizeof(Appointment_t));
	if (!AppointmentDiary->m_array)
	{
		*status = ALLOCATION_FAILED;
		free(AppointmentDiary);
		return NULL;
	}
	
	AppointmentDiary->m_capacity = capacity;
	AppointmentDiary->m_incBlockSize = incBlockSize;
	AppointmentDiary->m_numOfElements = NUM_OF_ELEMENTS_INIT;
	
	return AppointmentDiary;
}

app_states_t InsertAppointmentDiary(AppointmentDiary_t *AppointmentDiary, Appointment_t *Appointment)
{
	Appointment_t *tempPointerForRealloc = NULL;
	size_t i;
	int j;
	
	if (!AppointmentDiary || !AppointmentDiary->m_array || !Appointment)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	if (AppointmentDiary->m_capacity == AppointmentDiary->m_numOfElements)
	{
		if (!AppointmentDiary->m_incBlockSize)
		{
			return OVERFLOW;
		}
		
		tempPointerForRealloc = realloc(AppointmentDiary->m_array, (AppointmentDiary->m_capacity + 
									AppointmentDiary->m_incBlockSize) * sizeof(Appointment_t));
		if (!tempPointerForRealloc)
		{
			return REALLOCATION_FAILED;
		}
		
		AppointmentDiary->m_array = tempPointerForRealloc;
		AppointmentDiary->m_capacity += AppointmentDiary->m_incBlockSize;
	}

	*(AppointmentDiary->m_array + AppointmentDiary->m_numOfElements) = *Appointment;
	++AppointmentDiary->m_numOfElements;
	
	for (i = 0;i < AppointmentDiary->m_numOfElements - 1;++i)
	{
		for (j = i;0 <= j && AppointmentDiary->m_array[j + 1].appoStartTime 
									< AppointmentDiary->m_array[j].appoStartTime;--j)
		{
			Appointment_t temp = AppointmentDiary->m_array[j];
			AppointmentDiary->m_array[j] = AppointmentDiary->m_array[j + 1];
			AppointmentDiary->m_array[j + 1] = temp;
		}
	}
	
	return OK;
}

app_states_t FindAppointmentInAD(AppointmentDiary_t *AppointmentDiary, float appoStartTime
											, Appointment_t **foundAppointment, int *foundIndex)
{
	size_t i;

	if (appoStartTime < 0 || 23.99 < appoStartTime)
	{
		return APPOINTMENT_START_TIME_ERROR;
	}

	if (!AppointmentDiary || !AppointmentDiary->m_array || !foundAppointment || !foundIndex)
	{
		return POINTER_NOT_INITIALIZE;
	}

	if (!AppointmentDiary->m_numOfElements)
	{
		return UNDERFLOW;
	}
	
	for (i = 0;i < AppointmentDiary->m_numOfElements;++i)
	{
		if (AppointmentDiary->m_array[i].appoStartTime == appoStartTime)
		{
			*foundAppointment = (AppointmentDiary->m_array + i);
			*foundIndex = i;
			return OK;
		}
	}
	
	return THE_APPOINTMENT_IS_NOT_FOUND;
}

app_states_t RemoveAppointmentFromAD(AppointmentDiary_t *AppointmentDiary, Appointment_t **removedAppointment, int *removeIndex)
{
	size_t i;
	
	if (!AppointmentDiary || !AppointmentDiary->m_array || !removedAppointment 
												|| !removedAppointment || !removeIndex)	
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	for (i = *removeIndex;i < AppointmentDiary->m_numOfElements - 1;++i)
	{
		Appointment_t temp = AppointmentDiary->m_array[i];
		AppointmentDiary->m_array[i] = AppointmentDiary->m_array[i + 1];
		AppointmentDiary->m_array[i + 1] = temp;
	}
	
	--AppointmentDiary->m_numOfElements;
	*removedAppointment = (AppointmentDiary->m_array + AppointmentDiary->m_numOfElements);
	
	return OK; 
}

app_states_t DestroyAppointmentDiary(AppointmentDiary_t *AppointmentDiary)
{
	if (!AppointmentDiary || !AppointmentDiary->m_array)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	free(AppointmentDiary->m_array);
	free(AppointmentDiary);
	
	return OK;
}

app_states_t PrintAD(AppointmentDiary_t *AppointmentDiary)
{
	size_t i;

	if (!AppointmentDiary || !AppointmentDiary->m_array)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	if (!AppointmentDiary->m_numOfElements)
	{
		return UNDERFLOW;
	}
	
	for (i = 0;i < AppointmentDiary->m_numOfElements;++i)
	{
		printf("\nAppointment i = %ld\n", i);
		printf("Appointment start time -> %f\n", AppointmentDiary->m_array[i].appoStartTime);
		printf("Appointment end time -> %f\n", AppointmentDiary->m_array[i].appoEndTime);
		printf("Room number -> %d\n", AppointmentDiary->m_array[i].roomNum);
	}
	
	printf("\nAppointment diary capacity: %ld\n", AppointmentDiary->m_capacity);
	printf("Appointment diary increase block size: %ld\n", AppointmentDiary->m_incBlockSize);
	printf("Appointment diary number of elements: %ld\n", AppointmentDiary->m_numOfElements);
	
	return OK;	
}

app_states_t SaveADToFile(AppointmentDiary_t *AppointmentDiary, FILE *fileAppointmentDiaryForUser, FILE *fileAppointmentDiaryForLoad)
{
	size_t i;

	if (!AppointmentDiary || !AppointmentDiary->m_array)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	if (!AppointmentDiary->m_numOfElements)
	{
		return UNDERFLOW;
	}
	
	fileAppointmentDiaryForUser = fopen("AppointmentDiaryForUser.txt", "w+");
	if (!fileAppointmentDiaryForUser)
	{
		return FILE_CREATE_FAILED;
	}
	
	fileAppointmentDiaryForLoad = fopen("AppointmentDiaryForLoad.txt", "w+");
	if (!fileAppointmentDiaryForLoad)
	{
		return FILE_CREATE_FAILED;
	}
	
	fputs("Welcome! Here are today's appointments:\n", fileAppointmentDiaryForUser);
	
	for (i = 0;i < AppointmentDiary->m_numOfElements;++i)
	{		
		fprintf(fileAppointmentDiaryForUser, "\nAppointment %ld:\n", i + 1);
		fprintf(fileAppointmentDiaryForUser, "Appointment start time -> %f\n"
									, AppointmentDiary->m_array[i].appoStartTime);
		fprintf(fileAppointmentDiaryForUser, "Appointment end time -> %f\n",
										 AppointmentDiary->m_array[i].appoEndTime);
		fprintf(fileAppointmentDiaryForUser, "Room number -> %d\n"
											, AppointmentDiary->m_array[i].roomNum);
											
		fprintf(fileAppointmentDiaryForLoad, "%f ", AppointmentDiary->m_array[i].appoStartTime);
		fprintf(fileAppointmentDiaryForLoad, "%f ", AppointmentDiary->m_array[i].appoEndTime);
		fprintf(fileAppointmentDiaryForLoad, "%d\n", AppointmentDiary->m_array[i].roomNum);
	}
	
	fprintf(fileAppointmentDiaryForUser, "\nAppointment diary capacity: %ld\n", AppointmentDiary->m_capacity);
	fprintf(fileAppointmentDiaryForUser, "Appointment diary increase block size: %ld\n", AppointmentDiary->m_incBlockSize);
	fprintf(fileAppointmentDiaryForUser, "Appointment diary number of elements: %ld\n", AppointmentDiary->m_numOfElements);
	
	fclose(fileAppointmentDiaryForUser);
	fclose(fileAppointmentDiaryForLoad);
	
	return OK;	
}

app_states_t SLoadADFromFile(AppointmentDiary_t *AppointmentDiary, FILE *fileAppointmentDiaryForLoad)
{
	Appointment_t *Appointment = NULL;
	float appoStartTime, appoEndTime;
	int roomNum, userChoise;
	app_states_t status = OK;
	
	if (!AppointmentDiary || !AppointmentDiary->m_array)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	fileAppointmentDiaryForLoad = fopen("AppointmentDiaryForLoad.txt", "r+");
	if (NULL == fileAppointmentDiaryForLoad)
	{
		return FILE_OPEN_FAILED;
	}
	
	printf("The content of the appointment diary will be deleted and fileAppointmentDiaryForLoad content will be added instead. Are you sure you? [press 0 for yes / press 1 for no]: ");
	scanf("%d", &userChoise);
	
	if (userChoise)
	{
		return USER_CHOOSES_TO_EXIT_LOAD_FILE;
	}
	
	AppointmentDiary->m_numOfElements = AD_IS_EMPTY;
	
	fscanf(fileAppointmentDiaryForLoad, "%f %f %d", &appoStartTime, &appoEndTime, &roomNum);
	
	while (!feof(fileAppointmentDiaryForLoad))
	{
		Appointment = CreateAppointment(appoStartTime, appoEndTime, roomNum, &status);
		if (NULL == Appointment || OK != status)
		{
			return status;
		}
		
		status = InsertAppointmentDiary(AppointmentDiary, Appointment);
		if (OK != status)
		{
			return status;
		}
		
		fscanf(fileAppointmentDiaryForLoad, "%f %f %d", &appoStartTime, &appoEndTime, &roomNum);
	}
	
	fclose(fileAppointmentDiaryForLoad);
	
	return OK;	
}
