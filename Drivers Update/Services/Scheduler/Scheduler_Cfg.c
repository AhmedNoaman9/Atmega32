/*
 * Scheduler_Cfg.c
 *
 * Created: 07-Mar-23 2:32:11 PM
 *  Author: NO3M4N
 */ 


#include "../LIB/Std_types.h"
#include "Scheduler.h"
#include "Scheduler_Cfg.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/LED/LED.h"
#include "../HAL/SWITCH/SWITCH.h"


void LED_TaskOn(){
	
	DIO_enuSetPin(LED_enuPin5);
}
void LED_TaskOff(){
	
	DIO_enuClearPin(LED_enuPin5);	
}



const Task_t Tasks[NUMBER_OF_TASKS] = {
	
	[0] = {
		.cyclicTimeMs = 2,
		.Task = LED_TaskOn
	},
	[1] = {
		.cyclicTimeMs = 4,
		.Task = LED_TaskOff
	}	
	
	
};