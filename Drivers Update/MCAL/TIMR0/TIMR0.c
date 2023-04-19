/*
 * TIMR0.c
 *
 * Created: 28-Feb-23 7:55:45 PM
 *  Author: NO3M4N
 */ 


#include "Bit_math.h"
#include "Std_types.h"
#include "avr/interrupt.h"

#include "TIMR0.h"
#include "TIMR0_Prv.h"


static	volatile	u8 staticOVFval;
static	volatile	u8	TickClocks;
static	volatile	u8	staticClockSelect ;

	
static void(*TIMR0_pvCallBackNotificationFunc)(void) = Nullptr;

/* ------------------------------- ISR -----------------------------*/



/*
void TMR0_vidInitPreCompile(void){
	
}

*/

TMR0_enuErrorStatus TMR0_vidInitPostCompile(const TMR0Config_t* TIM0Cfg_str){
	
	u8	Loc_u8TempReg =	TCCR0;
	u8	Loc_TIMSK		= TIMSK;
	TMR0_enuErrorStatus	Loc_ErrorStatus = TIM0_OK;
	
	if (TIM0Cfg_str)
	{
	
		Loc_u8TempReg &= TIM0_MODE_CLR; 	
		Loc_u8TempReg |= TIM0Cfg_str->TIM0_Mode;
		
		Loc_u8TempReg &= TIM0_OC0_BIT_CLR;
		Loc_u8TempReg |= TIM0Cfg_str->TIM0_OC_Mode;
		
		//Loc_u8TempReg &= TIM0_CLK_BIT_CLR;
		
		Loc_TIMSK &= TIM0_INT_BIT_CLR;
		Loc_TIMSK |= TIM0Cfg_str->TIM0_INTen;
		
		
		
		
		TCCR0 |= Loc_u8TempReg;
		TIMSK |= Loc_TIMSK;
		
		staticClockSelect = TIM0Cfg_str->Clock_select;
		staticOVFval	= TIM0Cfg_str->OVF_Count;
		
		
	}	
	else{
		Loc_ErrorStatus = TIM0_NULLptr;
	}
	
	return	Loc_ErrorStatus;
	
}

TMR0_enuErrorStatus TMR0_enuSetTickTimeMS(u16 Copy_u16TickTime, u32 Copy_u32Clock){
	
	u8 Loc_TempReg = TCNT0;
	
	SET_BIT(TIMSK, 0);
	
	Loc_TempReg = (1000 * Copy_u16TickTime) / (1 / Copy_u32Clock) ;
	
	Loc_TempReg =  255 - Loc_TempReg ;
		
	staticOVFval = Loc_TempReg;
		
	TCNT0 = Loc_TempReg ;
	
	
	return TIM0_OK;
	 
	/**	InComplete	**/	
}

TMR0_enuErrorStatus TMR0_enuStart(u8 Value){
	
	u8 Loc_u8TempReg	= TCCR0;
	
	TickClocks = Value;
	
	TCNT0 = Value;
	
	Loc_u8TempReg	&= TIM0_CLK_BIT_CLR;
	Loc_u8TempReg	|= staticClockSelect;
	
	TCCR0 |= Loc_u8TempReg; 
	
	
	
	return TIM0_OK;	
}

TMR0_enuErrorStatus TMR0_enuSetCallback(TMR0cbf_t	Cbf){
	
	if (Cbf)
	{
		TIMR0_pvCallBackNotificationFunc = Cbf;
	}
	
	return	TIM0_OK;
}


ISR(TIMER0_OVF_vect){
	
	
	static u16 Loc_u16OVFcounter = 0;
	
	
	
	if (Loc_u16OVFcounter == staticOVFval)
	{
		
		if(TIMR0_pvCallBackNotificationFunc){
			TIMR0_pvCallBackNotificationFunc();
			Loc_u16OVFcounter =0;
		}
		else{
			//	Error 
		}
		
		
	}
	else{
		
		Loc_u16OVFcounter++;
		
	}
	
	TCNT0 = TickClocks;
	
}
// 
// ISR_Custom(10){
// 	
// 	
// 	static u16 Loc_u16OVFcounter = 0;
// 	
// 	
// 	
// 	if (Loc_u16OVFcounter == staticOVFval)
// 	{
// 		
// 		if(TIMR0_pvCallBackNotificationFunc){
// 			TIMR0_pvCallBackNotificationFunc();
// 			Loc_u16OVFcounter =0;
// 		}
// 		else{
// 			//	Error
// 		}
// 		
// 		
// 	}
// 	else{
// 		
// 		Loc_u16OVFcounter++;
// 		
// 	}
// 	
// 	TCNT0 = TickClocks;
// 	
// }
// ISR_Custom(12){
// 	
// 	
// 	static u16 Loc_u16OVFcounter = 0;
// 	
// 	
// 	
// 	if (Loc_u16OVFcounter == staticOVFval)
// 	{
// 		
// 		if(TIMR0_pvCallBackNotificationFunc){
// 			TIMR0_pvCallBackNotificationFunc();
// 			Loc_u16OVFcounter =0;
// 		}
// 		else{
// 			//	Error
// 		}
// 		
// 		
// 	}
// 	else{
// 		
// 		Loc_u16OVFcounter++;
// 		
// 	}
// 	
// 	TCNT0 = TickClocks;
// 	
// }
