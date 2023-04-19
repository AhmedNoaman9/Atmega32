/*
 * Scheduler.c
 *
 * Created: 07-Mar-23 2:30:59 PM
 *  Author: NO3M4N
 */ 


#include "Std_types.h"

#include "TIMR0/TIMR0.h"

#include "Scheduler.h"
#include "Scheduler_Cfg.h"


	
	

	
	



void	Scheduler_Init(){
	
	TMR0Config_t TMR_cfgStr = {
		
		
		.Clock_select= TIM0_PRESCALER_DIV64,
		.TIM0_Mode= TIM0_NORMAL,
		.TIM0_OC_Mode= TIM0_OC0_NONPWM_DICONNECT,
		.TIM0_INTen= TIM0_INT_OVF_ENABLE,
		.OVF_Count = 1	// 1 ovf to interrupt every 1 ms
	};
	

	TMR0_vidInitPostCompile(&TMR_cfgStr);
	TMR0_enuSetCallback(Scheduler);
	
	
}

void	Scheduler_Start(){
	
	TMR0_enuStart(TICK_PRELOAD_1ms_64DIV);
	while(1);
	
	
}

void	Scheduler(){
	
	u8	Loc_Iterator ;
	static	u32 Ticks_Ms;
	
	Ticks_Ms += TICKTIME;
	
	for (Loc_Iterator =0; Loc_Iterator < NUMBER_OF_TASKS; Loc_Iterator++)
	{
		if (Ticks_Ms % Tasks[Loc_Iterator].cyclicTimeMs == 0)
		{
			Tasks[Loc_Iterator].Task();
		}
		
	}
}