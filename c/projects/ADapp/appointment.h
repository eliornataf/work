/*****************************************************************************
* File Name: Appointment - ADT
* Written by: Elior Nataf
* Date: 19/2/21
******************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __APPOINTMENT_H__
#define __APPOINTMENT_H__

/*------------------------------- Header Files ------------------------------*/

#include "appStates.h" /* APP States header */

/*---------------------------------- Typedef --------------------------------*/

typedef struct Appointment Appointment_t;

/*------------------------------- Enum & Define -----------------------------*/

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creating a new appointment. Memory will be specially allocated
 * from a given size.
 *
 * Input:
 * appoStartTime - appointment start time (0 <= appoStartTime <= 23.99) ||
 * appoEndTime <= appoStartTime.
 * appoEndTime - appointment end time (0 <= appoEndTime <= 23.99).
 * roomNum - appointment room number.
 * status - pointer to CreateAppointment status.
 * 
 * Output:
 * NULL - status pointer is not initialized.
 * NULL - appoStartTime or/and appoEndTime time error (appoStartTime/appoEndTime
 * < 0 || 23.99 < appoStartTime/appoEndTime).
 * NULL - allocation failed.
 * Appointment - pointer to new appointment.
 *
 * Error: 
 * NULL - status pointer is not initialized.
 * NULL - appoStartTime or/and appoEndTime time error (appoStartTime/appoEndTime
 * < 0 || 23.99 < appoStartTime/appoEndTime).
 * NULL - allocation failed.
 */
Appointment_t *CreateAppointment(float appoStartTime, float appoEndTime
											, int roomNum, app_states_t *status);

/* Description:
 * A function that destroys a specified appointment.
 *
 * Input:
 * Appointment - pointer to appointment.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized - destroy failed.
 */
void DestoryAppointment(Appointment_t *Appointment);

#endif /* __APPOINTMENT_H__ */
