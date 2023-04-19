/*
 * LCD.c
 *
 * Created: 10-Feb-23 
 *  Author: NO3M4N
 */ 

#include "../../LIB/Std_types.h"

#include "../../MCAL/DIO/DIO.h"
#include "LCD.h"
#include "LCD_Cfg.h"


const LCD_strCfg_t	LCD_CfgStr[1]={
	
	[0]= {
		
		.LCD_enuDataPins={
			DIO_enuPin24,
			DIO_enuPin25,
			DIO_enuPin26,
			DIO_enuPin27,
			DIO_enuPin28,
			DIO_enuPin29,
			DIO_enuPin30,
			DIO_enuPin31
		},
		.LCD_enuCmdPins = {
			DIO_enuPin16,
			DIO_enuPin17,
			DIO_enuPin18
			
		}
		
		
	}

	
	
};