/*****************************************************************************
* File Name: Appointment Diary - ADT
* Written by: Elior Nataf
* Date: 19/2/21
******************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __APPOINTMENT_DIARY_H__
#define __APPOINTMENT_DIARY_H__

/*------------------------------- Header Files ------------------------------*/

#include <stddef.h> /* size_t */
#include "appStates.h" /* APP States header */
#include "appointment.h" /* Appointment header */

/*---------------------------------- Typedef --------------------------------*/

typedef struct AppointmentDiary AppointmentDiary_t;

/*------------------------------- Enum & Define -----------------------------*/

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creating a new available appointment diary. Memory will be  
 * specially allocated from a given size.
 *
 * Input:
 * capacity - given appointment diary size.
 * incBlockSize - number of elements to add then capacity is full.
 * status - pointer to CreateAppointmentDiary status.
 *
 * Output:
 * NULL - status pointer is not initialized.
 * NULL - capacity & incBlockSize equal to zero.
 * NULL - allocation failed.
 * AppointmentDiary - pointer to appointment diary.
 *
 * Error: 
 * NULL - status pointer is not initialized.
 * NULL - capacity & incBlockSize equal to zero.
 * NULL - allocation failed.
 */
AppointmentDiary_t *CreateAppointmentDiary(size_t capacity, size_t incBlockSize
															, app_states_t *status);

/* Description:
 * A function that adds an new appointment at the end of the appointment diary.
 *
 * Input:
 * AppointmentDiary - pointer to appointment diary.
 * Appointment - pointer to appointment to be added.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * OVERFLOW - appointment diary capacity is full, resize not possible.
 * REALLOCATION_FAILED - realloc failed.
 * OK - insert appointment is succeeded.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * OVERFLOW - stack capacity is full, resize not possible.
 * REALLOCATION_FAILED - realloc failed.
 */
app_states_t InsertAppointmentDiary(AppointmentDiary_t *AppointmentDiary
												, Appointment_t *Appointment);

/* Description:
 * A function that find appointment in a specified appointment diary.
 *
 * Input:
 * AppointmentDiary - pointer to appointment diary.
 * appoStartTime - appointment start time to search (0 <= appoStartTime <= 23.99).
 * foundAppointment - pointer to the found appointment.
 * foundIndex - pointer to the found appointment index.
 *
 * Output:
 * APPOINTMENT_START_TIME_ERROR - appoStartTime time error (appoStartTime
 * < 0 || 23.99 < appoStartTime).
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - appointment diary capacity is empty, find is not possible.
 * THE_APPOINTMENT_IS_NOT_FOUND - searched appointment is not in the appointment diary.
 * OK - appointment is found.
 *
 * Error: 
 * APPOINTMENT_START_TIME_ERROR - appoStartTime time error (appoStartTime
 * < 0 || 23.99 < appoStartTime).
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - appointment diary capacity is empty, find is not possible.
 * THE_APPOINTMENT_IS_NOT_FOUND - searched appointment is not in the appointment diary.
 */
app_states_t FindAppointmentInAD(AppointmentDiary_t *AppointmentDiary, float appoStartTime,
										 Appointment_t **foundAppointment, int *foundIndex);

/* Description:
 * A function that search and removes appointment in a specified appointment diary.
 *
 * Input:
 * AppointmentDiary - pointer to appointment diary.
 * removedAppointment -  pointer to the removed index appointment.
 * removeIndex - pointer to the removed index appointment.
 *
 * Output:
 * APPOINTMENT_START_TIME_ERROR - appoStartTime time error (appoStartTime
 * < 0 || 23.99 < appoStartTime).
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - appointment diary capacity is empty, find is not possible.
 * THE_APPOINTMENT_IS_NOT_FOUND - searched appointment is not in the appointment diary.
 * OK - the appointment removed.
 *
 * Error: 
 * APPOINTMENT_START_TIME_ERROR - appoStartTime time error (appoStartTime
 * < 0 || 23.99 < appoStartTime).
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - appointment diary capacity is empty, find is not possible.
 * THE_APPOINTMENT_IS_NOT_FOUND - searched appointment is not in the appointment diary.
 */
app_states_t RemoveAppointmentFromAD(AppointmentDiary_t *AppointmentDiary
						, Appointment_t **removedAppointment, int *removeIndex);
						
/* Description:
 * A function that destroys a specified appointment diary.
 *
 * Input:
 * AppointmentDiary - pointer to appointment diary.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized, destroy failed.
 * OK - the appointment diary is destroyed.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized, destroy failed.
 */
app_states_t DestroyAppointmentDiary(AppointmentDiary_t *AppointmentDiary);

/* Description:
 * A function that prints a specified appointment diary.
 *
 * Input:
 * AppointmentDiary - pointer to appointment diary.
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - appointment diary capacity is empty, print is not possible.
 * OK - list is successfully printed.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - appointment diary capacity is empty, print is not possible.
 */
app_states_t PrintAD(AppointmentDiary_t *AppointmentDiary);

/* Description:
 * A function that save a specified appointment diary to file.
 *
 * Input:
 * AppointmentDiary - pointer to appointment diary.
 * fileAppointmentDiaryForUser - pointer to file to be saved [for user].
 * fileAppointmentDiaryForLoad - pointer to file to be saved [for load].
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - appointment diary capacity is empty, print is not possible.
 * FILE_CREATE_FAILED - create appointment diary file failed.
 * OK - list is successfully saved.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * UNDERFLOW - appointment diary capacity is empty, print is not possible.
 * FILE_CREATE_FAILED - create appointment diary file failed.
 */
app_states_t SaveADToFile(AppointmentDiary_t *AppointmentDiary, FILE *fileAppointmentDiaryForUser,
																FILE *fileAppointmentDiaryForLoad);
																
/* Description:
 * A function that load appointment diary file to a specified appointment diary.
 * the old content will be erased.
 *
 * Input:
 * AppointmentDiary - pointer to appointment diary.
 * fileAppointmentDiaryForLoad - pointer to file to be saved [for load].
 *
 * Output:
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * FILE_OPEN_FAILED - open appointment diary file failed.
 * OVERFLOW - appointment diary capacity is full, resize not possible.
 * REALLOCATION_FAILED - realloc failed.
 * OK - list is successfully saved.
 *
 * Error: 
 * POINTER_NOT_INITIALIZE - the pointer is not initialized.
 * FILE_OPEN_FAILED - open appointment diary file failed.
 * OVERFLOW - appointment diary capacity is full, resize not possible.
 * REALLOCATION_FAILED - realloc failed.
 */
app_states_t SLoadADFromFile(AppointmentDiary_t *AppointmentDiary, FILE *fileAppointmentDiaryForLoad);

#endif /* __APPOINTMENT_DIARY_H__ */
