/*******************************************/
/*SSEG Driver*/
/* Target: ATMEGA32                        */
/* NO3M4N */
/* Date:2023-01-20                         */
/*******************************************/

#include "../../LIB/Std_types.h"
#include "../../LIB/Bit_math.h"
#include "../../MCAL/DIO/DIO.h"

#include "SSEG.h"
#include "SSEG_Cfg.h"
#include "SSEG_Prv.h"



 
SSEG_tenuErrorStatus SSEG_enuInit(void){
	u8 Loc_u8SsegCounter;
	u8 Loc_u8PinCounter;
	
	SSEG_tenuErrorStatus Loc_enuSsegErrorStatus = SSEG_enuOk;
	
	for (Loc_u8SsegCounter = 0; Loc_u8SsegCounter < NUMBER_OF_SSEG; Loc_u8SsegCounter++)
	{
		if (SSEG_tstrSsegCfg[Loc_u8SsegCounter].SSEG_u8ActiveState == ACTIVE_HIGH )
		{
			for(Loc_u8PinCounter = 0; Loc_u8PinCounter <= SSEG_MAX_LEDS ; Loc_u8PinCounter++)
			{	
				DIO_enuSetPin(SSEG_tstrSsegCfg[Loc_u8SsegCounter].SSEG_enuPin[Loc_u8PinCounter]);	
			}
		}

		else if (SSEG_tstrSsegCfg[Loc_u8SsegCounter].SSEG_u8ActiveState == ACTIVE_LOW )
		{
			for(Loc_u8PinCounter = 0; Loc_u8PinCounter <= SSEG_MAX_LEDS ; Loc_u8PinCounter++)
			{

				DIO_enuClearPin(SSEG_tstrSsegCfg[Loc_u8SsegCounter].SSEG_enuPin[Loc_u8PinCounter]);	
			}
			
		}
	}
				
	
	return	Loc_enuSsegErrorStatus;
}






SSEG_tenuErrorStatus SSEG_enuSetNumber(u8 Cpy_u8SsegNumber , u8 Cpy_u8Number){
	u8 Loc_u8Counter;
	
	SSEG_tenuErrorStatus Loc_enuErrorStatus = SSEG_enuOk;
	if(Cpy_u8SsegNumber < NUMBER_OF_SSEG){	
	
		if (Cpy_u8Number <= 0b1111111){	
			
			if (SSEG_tstrSsegCfg[Cpy_u8SsegNumber].SSEG_u8ActiveState == ACTIVE_HIGH )
			{
				for(Loc_u8Counter = 0; Loc_u8Counter <= SSEG_MAX_LEDS ; Loc_u8Counter++){
					if(  (1<<(Loc_u8Counter)) & Cpy_u8Number )  
					{
						DIO_enuClearPin(SSEG_tstrSsegCfg[Cpy_u8SsegNumber].SSEG_enuPin[Loc_u8Counter]);
					}
				}
			}
			else if (SSEG_tstrSsegCfg[Cpy_u8SsegNumber].SSEG_u8ActiveState == ACTIVE_LOW )
			{
				for(Loc_u8Counter = 0; Loc_u8Counter <= SSEG_MAX_LEDS ; Loc_u8Counter++)
				{
					if( ( (1<<(Loc_u8Counter)) & Cpy_u8Number) )
					{
						DIO_enuSetPin(SSEG_tstrSsegCfg[Cpy_u8SsegNumber].SSEG_enuPin[Loc_u8Counter]);
					}
				}
			}
		}
		else{
			Loc_enuErrorStatus = SSEG_MAX_NUM_DISP;
		}	
	}
	else{
		Loc_enuErrorStatus = SSEG_enuInvalidSSEG;
	}
	
	
	return	Loc_enuErrorStatus;
}



SSEG_tenuErrorStatus SSEG_enuClearNumber(u8 Cpy_u8SsegNumber ){
	u8 Loc_u8Counter;
	SSEG_tenuErrorStatus Loc_enuErrorStatus = SSEG_enuOk;
	
	if(Cpy_u8SsegNumber < NUMBER_OF_SSEG){
			
		if (SSEG_tstrSsegCfg[Cpy_u8SsegNumber].SSEG_u8ActiveState == ACTIVE_HIGH )
		{
			for(Loc_u8Counter = 0; Loc_u8Counter <= SSEG_MAX_LEDS ; Loc_u8Counter++){
				
				DIO_enuSetPin(SSEG_tstrSsegCfg[Cpy_u8SsegNumber].SSEG_enuPin[Loc_u8Counter]);
				
			}
		}
		else if (SSEG_tstrSsegCfg[Cpy_u8SsegNumber].SSEG_u8ActiveState == ACTIVE_LOW )
		{
			for(Loc_u8Counter = 0; Loc_u8Counter <= SSEG_MAX_LEDS ; Loc_u8Counter++){
							
				DIO_enuClearPin(SSEG_tstrSsegCfg[Cpy_u8SsegNumber].SSEG_enuPin[Loc_u8Counter]);
				
			}
		}
	}
	else
	{
		Loc_enuErrorStatus = SSEG_enuInvalidSSEG;
	}
	
	
	return	Loc_enuErrorStatus;
}


