#include <stdlib.h> /* malloc, free */
#include "appointment.h" /* Appointment header */

/*****************************************************************************/

struct Appointment
{
	float appoStartTime;
	float appoEndTime;
	int roomNum;
};

/*****************************************************************************/

Appointment_t *CreateAppointment(float appoStartTime, float appoEndTime
											, int roomNum, app_states_t *status)
{
	Appointment_t *Appointment = NULL; 
	
	if (!status)
	{
		return NULL;
	}
	
	if (appoStartTime < 0 || 23.99 < appoStartTime || appoEndTime <= appoStartTime)
	{
		*status = APPOINTMENT_START_TIME_ERROR;
		return NULL;
	}
	
	if (appoEndTime < 0 || 23.99 < appoEndTime)
	{
		*status = APPOINTMENT_END_TIME_ERROR;
		return NULL;
	}
	
	Appointment = (Appointment_t*)malloc(sizeof(Appointment_t));
	if (!Appointment)
	{
		*status = ALLOCATION_FAILED;
		return NULL;
	}

	Appointment->appoStartTime = appoStartTime;
	Appointment->appoEndTime = appoEndTime;
	Appointment->roomNum = roomNum;
	
	return Appointment;
}

void DestoryAppointment(Appointment_t *Appointment)
{
	if (!Appointment)
	{
		return;
	}
	
	free(Appointment);
}
