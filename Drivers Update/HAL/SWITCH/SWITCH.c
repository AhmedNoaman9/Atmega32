/*******************************************/
/*SWITCH Driver*/
/* Target: ATMEGA32                        */
/* NO3MAN */
/* Date:2023-01-18                         */
/*******************************************/

#include "../../LIB/Bit_math.h"
#include "../../LIB/Std_types.h"

#include "../../MCAL/DIO/DIO.h"

#include "SWITCH.h"
#include "SWITCH_Cfg.h"


static u8 SwitchState[NUMBER_OF_SWITCH] = {0};

SWITCH_tenuErrorStatus SWITCH_enuGetSwitchValue(SWITCH_tenuPins Cpy_enuPinNumber,u8 *Add_pu8PinValue){
		
	
	SWITCH_tenuErrorStatus Loc_enuSWITCHErrorStatus = SWITCH_enuOk;
	DIO_tenuErrorStatus Loc_enuDIOErrorStatus = SWITCH_enuOk;
	
	if (Cpy_enuPinNumber > SWITCH_enuNumberOfPins - 1 ){
		
		Loc_enuSWITCHErrorStatus = SWITCH_enuInvalidPinNum;
		
	}
	else if( Add_pu8PinValue == NULL){
		Loc_enuSWITCHErrorStatus = SWITCH_enuInvalidPinNum;
		
	}
	else{
				
		Loc_enuDIOErrorStatus = DIO_enuGetPin(Cpy_enuPinNumber, Add_pu8PinValue);
		if (Loc_enuDIOErrorStatus != DIO_enuOk){
			Loc_enuSWITCHErrorStatus = SWITCH_enuNotOk;
		}
	
	
	}
	
	
	return Loc_enuSWITCHErrorStatus;
}



SWITCH_tenuErrorStatus SWITCH_enuIsPressed(SWITCH_tenuPins Cpy_enuPinNumber,u8 *Add_pu8PinValue){
	
	u8 Loc_Counter =0;
	DIO_tenuErrorStatus Loc_DIOErrorStatus = DIO_enuOk;
	SWITCH_tenuErrorStatus Loc_SWITCHErrorStatus = SWITCH_enuOk;
	
	
	
	Loc_DIOErrorStatus = DIO_enuGetPin(Cpy_enuPinNumber, Add_pu8PinValue);
	
	if (*Add_pu8PinValue == 1 && Loc_DIOErrorStatus == DIO_enuOk)
	{
		Loc_Counter++;
		DIO_enuGetPin(Cpy_enuPinNumber, Add_pu8PinValue);
		if (*Add_pu8PinValue == 1 && Loc_DIOErrorStatus == DIO_enuOk)
		{
			Loc_Counter++;
			DIO_enuGetPin(Cpy_enuPinNumber, Add_pu8PinValue);
			if (*Add_pu8PinValue == 1 && Loc_DIOErrorStatus == DIO_enuOk)
			{
				Loc_Counter++;
				DIO_enuGetPin(Cpy_enuPinNumber, Add_pu8PinValue);
				if(*Add_pu8PinValue == 1&& Loc_DIOErrorStatus == DIO_enuOk)
				{
					Loc_Counter++;
				}
				else
				{
					Loc_SWITCHErrorStatus = SWITCH_enuNotOk;
				}
			}
			else
			{
				Loc_SWITCHErrorStatus = SWITCH_enuNotOk;
			}
		}
		else
		{
			Loc_SWITCHErrorStatus = SWITCH_enuNotOk;
		}
	}
	if (Loc_Counter == 4)
	{
		*Add_pu8PinValue = 1;
		Loc_SWITCHErrorStatus = SWITCH_enuOk;
	}
	else
	{
		*Add_pu8PinValue = 0; 
		Loc_SWITCHErrorStatus = SWITCH_enuNotOk;
	}
	
	
	return Loc_SWITCHErrorStatus;
	
	
}

void Switch_vidTask(void)
{
	u8 Loc_u8Iterator = 0;
	u8 Loc_u8CurrentValue;
	static u8 Loc_u8PrvValue[NUMBER_OF_SWITCH];
	static u8 Loc_u8Counter[NUMBER_OF_SWITCH];

	for(Loc_u8Iterator = 0; Loc_u8Iterator < NUMBER_OF_SWITCH; Loc_u8Iterator++)
	{
		DIO_enuGetPin(SwitchConfig[Loc_u8Iterator].SW_Number, &Loc_u8CurrentValue);

		if(Loc_u8CurrentValue == Loc_u8PrvValue[Loc_u8Iterator])
		{
			Loc_u8Counter[Loc_u8Iterator]++;
		}
		else
		{
			Loc_u8Counter[Loc_u8Iterator] = 0;
		}

		if(Loc_u8Counter[Loc_u8Iterator] == 5)
		{
			SwitchState[Loc_u8Iterator] = Loc_u8CurrentValue;
			Loc_u8Counter[Loc_u8Iterator] = 0;
		}

		Loc_u8PrvValue[Loc_u8Iterator] = Loc_u8CurrentValue;
	}
}
