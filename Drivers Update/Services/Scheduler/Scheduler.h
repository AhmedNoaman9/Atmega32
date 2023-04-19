/*
 * Scheduler.h
 *
 * Created: 07-Mar-23 2:31:32 PM
 *  Author: NO3M4N
 */ 


#ifndef SCHEDULER_H_
#define SCHEDULER_H_



#define		TICKTIME	1;


typedef void(*CallBack)(void);


typedef	struct {
	
	CallBack	Task;
	u8		cyclicTimeMs;
	
	
	
}Task_t;



void	Scheduler_Init();

void	Scheduler_Start();

void	Scheduler();









#endif /* SCHEDULER_H_ */