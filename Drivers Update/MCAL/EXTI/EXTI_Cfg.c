/*
 * EXTI_Cfg.c
 *
 * Created: 27-Jan-23 10:08:49 AM
 *  Author: NO3M4N
 */ 

#include "../../LIB/Std_types.h"

#include "EXTI.h"
#include "EXTI_Cfg.h"
#include "EXTI_Prv.h"



const EXTI_strEXTICfg_t EXTI_strExtiCfg[EXTI_enuEXTINumber] =
{
	
	[0]=
	{
		.EXTI_enuIntNum = EXTI_enuINT0,
		.EXTI_u8ActiveStatus = INT_ENABLE,
		.EXTI_u8IntSenseControl = EXTI_enuFallingEdge 
		
	},
	
	[1]=
	{
		.EXTI_enuIntNum = EXTI_enuINT1,
		.EXTI_u8ActiveStatus = INT_ENABLE,
		.EXTI_u8IntSenseControl = EXTI_enuFallingEdge
		
	},
	
	[2]=
	{
		.EXTI_enuIntNum = EXTI_enuINT2,
		.EXTI_u8ActiveStatus = INT_ENABLE,
		.EXTI_u8IntSenseControl = EXTI_enuFallingEdge
		
		
	},
	
	
};
