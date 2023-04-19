/*
 * LED.c
 *
 * Created: 17-Jan-23 8:27:39 PM
 *  Author: NO3M4N
 */ 


#include "../../LIB/Std_types.h"
#include "../../LIB/Bit_math.h"

#include "../../MCAL/DIO/DIO.h"
#include "LED.h"
#include "LED_Cfg.h"
#include "LED_Prv.h"



/**************************************************************
Led ON Function
Input: Pin Number from (0 to 31) Using LedEnum (LED_tenuPins)
Output: LED_tenuErrorStatus To report Error status through enum
****************************************************************/
LED_tenuErrorStatus LED_enuLedOn(LED_tenuPins Cpy_enuPinNumber)
{
	DIO_tenuErrorStatus Loc_enuDIOErrorStatus = DIO_enuOk;
	LED_tenuErrorStatus Loc_enuLEDErrorStatus = LED_enuOk;
	
	u8 Loc_u8PinNumber	 = 0;
	
	if (Cpy_enuPinNumber > LED_enuNumberOfPins - 1 ){
		
		Loc_enuLEDErrorStatus = LED_enuInvalidPinNum;
		
	}
	else{
		Loc_u8PinNumber	 = Cpy_enuPinNumber % 8;
		Loc_enuDIOErrorStatus = DIO_enuSetPin(Loc_u8PinNumber);
		
		if (Loc_enuDIOErrorStatus != DIO_enuOk )
		{
			Loc_enuLEDErrorStatus = LED_enuNotOk;
		}
		
	}
	return Loc_enuLEDErrorStatus;
}


/**************************************************************
Led OFF Function
Input: Pin Number from (0 to 31)
Output: DIO_tenuErrorStatus To report Error status through enum
****************************************************************/
LED_tenuErrorStatus LED_enuLedOff(LED_tenuPins Cpy_enuPinNumber)
{
	DIO_tenuErrorStatus Loc_enuDIOErrorStatus = DIO_enuOk;
	LED_tenuErrorStatus Loc_enuLEDErrorStatus = LED_enuOk;
	

	u8 Loc_u8PinNumber  =  0;
	
	if (Cpy_enuPinNumber > LED_enuNumberOfPins - 1 ){
		
		Loc_enuLEDErrorStatus = LED_enuInvalidPinNum;
		
	}
	else{

		Loc_u8PinNumber	 = Cpy_enuPinNumber % 8;
		Loc_enuDIOErrorStatus = DIO_enuClearPin(Loc_u8PinNumber);
		
		if (Loc_enuDIOErrorStatus != DIO_enuOk )
		{
			Loc_enuLEDErrorStatus = LED_enuNotOk;
		}
		
	}
	return Loc_enuLEDErrorStatus;
}

