#include <stdio.h> /* printf */
#include "appointmentDiary.h" /* Appointment Diary header */
#include "appointment.h" /* Appointment header */
#include "appStates.h" /* APP States header */

#define IS_NOT_INITIALIZED (0)
#define IS_INITIALIZED (1)

/****************************************************************************/

typedef enum app_actions
{
	CREATE_AD = 1,
	CREATE_APPOINTMENT = 2,
	INSERT_APPOINTMENT_TO_AD = 3,
	REMOVE_APPOINTMENT_FROM_AD = 4,
	FIND_APPOINTMENT_IN_AD = 5,
	DESTROY_AD = 6,
	PRINT_AD = 7,
	SAVE_AD_TO_FILE = 8,
	LOAD_AD_FROM_FILE = 9,
	WAITING_FOR_INPUT
} app_actions_t;

/****************************************************************************/

app_states_t CaseCreateAd(AppointmentDiary_t **AppointmentDiary, int *initAppointmentDiary)
{
	size_t capacity, incBlockSize;
	app_states_t status = OK;

	if (IS_INITIALIZED == *initAppointmentDiary)
	{
		printf("\033[1;31m\nAppointment diary was already created!\n\033[0m");
		return APPOINTMENT_DAIRY_IS_ALREADY_INITIALIZED;
	}
	
	printf("\033[1;34m\nWelcome to create appointment diary:\n\n\033[0m");
	
	printf("Please enter Appointment Diary capacity and increase block size:\n");
	scanf("%lu %lu", &capacity, &incBlockSize);
	
	*AppointmentDiary = CreateAppointmentDiary(capacity, incBlockSize, &status);
	if (!AppointmentDiary || OK != status)
	{
		printf("\033[1;31m\nError! try again.\n\033[0m");
		return status;
	}
	
	*initAppointmentDiary = IS_INITIALIZED;
	
	printf("\033[1;36m\nAppointment diary successfully created!\n\033[0m");
	
	return OK;
}

app_states_t CaseCreateAppointment(Appointment_t **Appointment, int *initAppointment)
{
	float appoStartTime, appoEndTime;
	int roomNum;
	app_states_t status = OK;

	if (IS_INITIALIZED == *initAppointment)
	{
		printf("\033[1;31m\nAppointment was already created!\n\033[0m");
		return APPOINTMENT_IS_ALREADY_INITIALIZED;
	}
	
	printf("\033[1;34m\nWelcome to create appointment:\n\n\033[0m");
	
	printf("Please enter appointment start time and appointment end time:\n");
	scanf("%f %f", &appoStartTime, &appoEndTime);
	printf("Please enter room number:\n");
	scanf("%d", &roomNum);
	
	*Appointment = CreateAppointment(appoStartTime, appoEndTime, roomNum, &status);
	if (!Appointment || OK != status)
	{
		printf("\033[1;31m\nError! try again.\n\033[0m");
		return status;
	}
	
	*initAppointment = IS_INITIALIZED;
	
	printf("\033[1;36m\nAppointment successfully created!\n\033[0m");
	
	return OK;
}

app_states_t CaseInsertAppointmentToAD(AppointmentDiary_t *AppointmentDiary
			, int initAppointmentDiary, Appointment_t *Appointment, int *initAppointment)
{
	app_states_t status = OK;

	if (IS_NOT_INITIALIZED == initAppointmentDiary)
	{
		printf("\033[1;31m\nAppointment diary was not created!\n\033[0m");
		return APPOINTMENT_DAIRY_IS_NOT_INITIALIZED;
	}
	
	if (IS_NOT_INITIALIZED == *initAppointment)
	{
		printf("\033[1;31m\nAppointment was not created!\n\033[0m");
		return APPOINTMENT_IS_NOT_INITIALIZED;
	}
	
	status = InsertAppointmentDiary(AppointmentDiary, Appointment);
	if (OK != status)
	{
		printf("\033[1;31m\nError! try again.\n\033[0m");
		return status;
	}
	
	*initAppointment = IS_NOT_INITIALIZED; 
	
	printf("\033[1;36m\nAppointment diary successfully inserted!\n\033[0m");
	
	return OK;
}

app_states_t CaseFindAppointmentInAD(AppointmentDiary_t *AppointmentDiary
					, int initAppointmentDiary, Appointment_t **foundAppointment, int *foundIndex)
{
	app_states_t status = OK;
	float appoStartTime;

	if (IS_NOT_INITIALIZED == initAppointmentDiary)
	{
		printf("\033[1;31m\nAppointment diary was not created!\n\033[0m");
		return APPOINTMENT_DAIRY_IS_NOT_INITIALIZED;
	}
	
	printf("\nPlease enter appointment start time:\n");
	scanf("%f", &appoStartTime);
	
	status = FindAppointmentInAD(AppointmentDiary, appoStartTime, foundAppointment, foundIndex);
	if (OK != status)
	{
		printf("\033[1;31m\nError! try again.\n\033[0m");
		return status;
	}
	
	printf("\033[1;36m\nAppointment diary found in index %d!\n\033[0m", *foundIndex);
	
	return OK;
}

app_states_t CaseRemoveAppointmentFromAD(AppointmentDiary_t *AppointmentDiary
					, int initAppointmentDiary, Appointment_t **foundAppointment, 
								Appointment_t **removedAppointment, int *foundIndex)
{
	app_states_t status = OK;
	
	status = CaseFindAppointmentInAD(AppointmentDiary, initAppointmentDiary, foundAppointment, foundIndex);

	if (OK != status)
	{
		printf("\033[1;31m\nError! try again.\n\033[0m");
		return status;
	}
	
	status = RemoveAppointmentFromAD(AppointmentDiary, removedAppointment, foundIndex);
	if (OK != status)
	{
		printf("\033[1;31m\nError! try again.\n\033[0m");
		return status;
	}
	
	printf("\033[1;36m\nAppointment diary index %d is successfully removed!\n\033[0m", *foundIndex);
	
	return OK;
}

app_states_t CaseDestroyAd(AppointmentDiary_t *AppointmentDiary, int initAppointmentDiary, int *isRunning)
{
	app_states_t status = OK;

	if (IS_NOT_INITIALIZED == initAppointmentDiary)
	{
		printf("\033[1;31m\nAppointment diary was not created!\n\033[0m");
		return APPOINTMENT_DAIRY_IS_NOT_INITIALIZED;
	}

	status = DestroyAppointmentDiary(AppointmentDiary);
	if (OK != status)
	{
		printf("\033[1;31m\nError! try again.\n\033[0m");
		return status;
	}

	*isRunning = STOP_APP_RUNNING;
	
	printf("\033[1;36m\nAppointment diary successfully destroyed! Goodbye!\n\033[0m");
	
	return OK;
}

app_states_t CasePrintAD(AppointmentDiary_t *AppointmentDiary, int initAppointmentDiary)
{
	app_states_t status = OK;

	if (IS_NOT_INITIALIZED == initAppointmentDiary)
	{
		printf("\033[1;31m\nAppointment diary was not created!\n\033[0m");
		return APPOINTMENT_DAIRY_IS_NOT_INITIALIZED;
	}
	
	status = PrintAD(AppointmentDiary);
	if (OK != status)
	{
		printf("\033[1;31m\nError! try again.\n\033[0m");
		return status;
	}
	
	printf("\033[1;36m\nAppointment diary successfully printed!\n\033[0m");
	
	return OK;
}

app_states_t CaseSaveADToFile(AppointmentDiary_t *AppointmentDiary, int initAppointmentDiary, FILE *fileAppointmentDiary, FILE *fileAppointmentDiaryForLoad)
{
	app_states_t status = OK;

	if (IS_NOT_INITIALIZED == initAppointmentDiary)
	{
		printf("\033[1;31m\nAppointment diary was not created!\n\033[0m");
		return APPOINTMENT_DAIRY_IS_NOT_INITIALIZED;
	}
	
	status = SaveADToFile(AppointmentDiary, fileAppointmentDiary, fileAppointmentDiaryForLoad);
	if (OK != status)
	{
		printf("\033[1;31m\nError! try again.\n\033[0m");
		return status;
	}
	
	printf("\033[1;36m\nAppointment diary successfully saved to file!\n\033[0m");
	
	return OK;
}

app_states_t CaseLoadADFromFile(AppointmentDiary_t *AppointmentDiary, int initAppointmentDiary, FILE *fileAppointmentDiaryForLoad)
{
	app_states_t status = OK;

	if (IS_NOT_INITIALIZED == initAppointmentDiary)
	{
		printf("\033[1;31m\nAppointment diary was not created!\n\033[0m");
		return APPOINTMENT_DAIRY_IS_NOT_INITIALIZED;
	}
	
	status = SLoadADFromFile(AppointmentDiary, fileAppointmentDiaryForLoad);
	if (OK != status)
	{
		printf("\033[1;31m\nError! try again.\n\033[0m");
		return status;
	}
	
	printf("\033[1;36m\nAppointment diary successfully load from file!\n\033[0m");
	
	return OK;
}

/****************************************************************************/

void runApp(void)
{
	AppointmentDiary_t *AppointmentDiary = NULL;
	Appointment_t *Appointment = NULL; 
	Appointment_t *foundAppointment = NULL; 
	Appointment_t *removedAppointment = NULL;
	int initAppointmentDiary = IS_NOT_INITIALIZED;
	int initAppointment = IS_NOT_INITIALIZED;
	int foundIndex = -1;
	int isRunning = APP_IS_RUNNING;
	FILE *fileAppointmentDiaryForUser = NULL;
	FILE *fileAppointmentDiaryForLoad = NULL;

	while (APP_IS_RUNNING == isRunning)
	{
			int action = WAITING_FOR_INPUT;
			app_states_t status = OK;
	
			printf("\033[1;33m\nPlease choose an action:\n\n");
			printf("Create appointment Diary [press: 1]\n");
			printf("Create appointment [press: 2]\n");
			printf("Insert appointment to appointment diary [press: 3]\n");
			printf("Remove appointment form appointment diary [press: 4]\n");
			printf("Find appointment in appointment diary [press: 5]\n");
			printf("Destroy appointment diary [press: 6]\n");
			printf("Print appointment diary [press: 7]\n");
			printf("Save appointment diary to file [press: 8]\n");
			printf("Load appointment diary from file [press: 9]\n\n\033[0m");
			
			scanf("%d", &action);
			
			switch (action)
			{
				case CREATE_AD: 
				status = CaseCreateAd(&AppointmentDiary, &initAppointmentDiary);
				break;
				
				case CREATE_APPOINTMENT:
				status = CaseCreateAppointment(&Appointment, &initAppointment);
				break;
				
				case INSERT_APPOINTMENT_TO_AD:
				status = CaseInsertAppointmentToAD(AppointmentDiary, initAppointmentDiary, Appointment, &initAppointment);
				break;
				
				case REMOVE_APPOINTMENT_FROM_AD:
				status = CaseRemoveAppointmentFromAD(AppointmentDiary, initAppointmentDiary, &foundAppointment, &removedAppointment, &foundIndex);
				break;
				
				case FIND_APPOINTMENT_IN_AD:
				status = CaseFindAppointmentInAD(AppointmentDiary, initAppointmentDiary, &foundAppointment, &foundIndex);
				break;
				
				case DESTROY_AD:
				status = CaseDestroyAd(AppointmentDiary, initAppointmentDiary, &isRunning);
				break;
				
				case PRINT_AD:
				status = CasePrintAD(AppointmentDiary, initAppointmentDiary);
				break;
				
				case SAVE_AD_TO_FILE:
				status = CaseSaveADToFile(AppointmentDiary, initAppointmentDiary, fileAppointmentDiaryForUser, fileAppointmentDiaryForLoad);
				break;
				
				case LOAD_AD_FROM_FILE:
				status = CaseLoadADFromFile(AppointmentDiary, initAppointmentDiary, fileAppointmentDiaryForLoad);
				break;
				
				default:
				printf("Invalid input, please choose again\n\n");
				break;
			}
	}
	
}

int main(void)
{
	runApp();
	
	return 0;
}
