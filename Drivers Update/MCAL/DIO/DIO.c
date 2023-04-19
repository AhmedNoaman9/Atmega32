#include "../../LIB/Std_types.h"
#include "../../LIB/Bit_math.h"

#include "DIO.h"
#include "DIO_Cfg.h"
#include "DIO_Prv.h"



DIO_tenuErrorStatus DIO_enuInit(void)
{
	u8 Loc_u8Counter =0;
	volatile u8 Loc_u8PortNumber =0;
	volatile u8 Loc_u8PinNumber =0;
	
	for (Loc_u8Counter =0; Loc_u8Counter < DIO_enuNumberOfPins; Loc_u8Counter++)
	{
		Loc_u8PortNumber = Loc_u8Counter / 8;
		Loc_u8PinNumber = Loc_u8Counter % 8;
		
		switch(Loc_u8PortNumber){
			case (DIO_PORTA):
				if (DIO_strPinCfg[Loc_u8Counter].DIO_Pin_Direction == DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRA,Loc_u8PinNumber);
					
				}
				else
				{
					CLR_BIT(DDRA,Loc_u8PinNumber);
					if (DIO_strPinCfg[Loc_u8Counter].DIO_Pin_Direction == DIO_INPUT_PULL_UP)
					{
						SET_BIT(PORTA,Loc_u8PinNumber);
					}
					else
					{
						CLR_BIT(PORTA,Loc_u8PinNumber);
					}
				}
				break;
			case (DIO_PORTB):
				if (DIO_strPinCfg[Loc_u8Counter].DIO_Pin_Direction == DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRB,Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRB,Loc_u8PinNumber);
					if (DIO_strPinCfg[Loc_u8Counter].DIO_Pin_Direction == DIO_INPUT_PULL_UP)
					{
						SET_BIT(PORTB,Loc_u8PinNumber);
					}
					else
					{
						CLR_BIT(PORTB,Loc_u8PinNumber);
					}
				}
				break;
				
			case (DIO_PORTC):
				if (DIO_strPinCfg[Loc_u8Counter].DIO_Pin_Direction == DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRC,Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRC,Loc_u8PinNumber);
					if (DIO_strPinCfg[Loc_u8Counter].DIO_Pin_Direction == DIO_INPUT_PULL_UP)
					{
						SET_BIT(PORTC,Loc_u8PinNumber);
					}
					else
					{
						CLR_BIT(PORTC,Loc_u8PinNumber);
					}
				}
				break;
			case (DIO_PORTD):
				if (DIO_strPinCfg[Loc_u8Counter].DIO_Pin_Direction == DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRD,Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRD,Loc_u8PinNumber);
					if (DIO_strPinCfg[Loc_u8Counter].DIO_Pin_Direction == DIO_INPUT_PULL_UP)
					{
						SET_BIT(PORTD,Loc_u8PinNumber);
					}
					else
					{
						CLR_BIT(PORTD,Loc_u8PinNumber);
					}
				}
				break;
		}
	}
	
	return DIO_enuOk;
}



DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPins Cpy_enuPinNumber)
{
	DIO_tenuErrorStatus Loc_enuErrorStatus = DIO_enuOk;
	//u8 Loc_u8Counter =0;
	u8 Loc_u8PortNumber =0;
	u8 Loc_u8PinNumber =0;
//	u8 Loc_u8TempReg =0;
	
	if (Cpy_enuPinNumber > DIO_enuNumberOfPins - 1 ){
			Loc_enuErrorStatus = DIO_enuInvalidPinNum;
			
	}
	else{
		
			Loc_u8PortNumber = Cpy_enuPinNumber / 8;
			Loc_u8PinNumber =  Cpy_enuPinNumber % 8;
			
			switch(Loc_u8PortNumber){
				case (DIO_PORTA):
					SET_BIT(PORTA,Loc_u8PinNumber);
					break;
				case (DIO_PORTB):
					SET_BIT(PORTB,Loc_u8PinNumber);
					break;
				case (DIO_PORTC):
					SET_BIT(PORTC,Loc_u8PinNumber);
					break;
				case (DIO_PORTD):
					SET_BIT(PORTD,Loc_u8PinNumber);
					break;	
			}
				
		
	}
	return Loc_enuErrorStatus;
}


/**************************************************************
DIO Clear pin Function
Input: Pin Number from (0 to 31)
Output: DIO_tenuErrorStatus To report Error status through enum
****************************************************************/
DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPins Cpy_enuPinNumber){
	DIO_tenuErrorStatus Loc_enuErrorStatus = DIO_enuOk;
	//u8 Loc_u8Counter =0;
	u8 Loc_u8PortNumber =0;
	u8 Loc_u8PinNumber =0;
	
	if (Cpy_enuPinNumber > DIO_enuNumberOfPins - 1 ){
		Loc_enuErrorStatus = DIO_enuInvalidPinNum;
		
	}
	else{
		
			Loc_u8PortNumber = Cpy_enuPinNumber / 8;
			Loc_u8PinNumber = Cpy_enuPinNumber % 8;
			
			switch(Loc_u8PortNumber){
				case (DIO_PORTA):
					CLR_BIT(PORTA,Loc_u8PinNumber);
					break;
				case (DIO_PORTB):
					CLR_BIT(PORTB,Loc_u8PinNumber);
					break;
				case (DIO_PORTC):
					CLR_BIT(PORTC,Loc_u8PinNumber);
					break;
				case (DIO_PORTD):
					CLR_BIT(PORTD,Loc_u8PinNumber);
					break;
			}
		

	}
	
	return Loc_enuErrorStatus;
}



/**************************************************************
DIO Get pin Function
Input: Pin Number from (0 to 31) , Ptr To return Pin value in;
Output: DIO_tenuErrorStatus To report Error status through enum
****************************************************************/
DIO_tenuErrorStatus DIO_enuGetPin(DIO_tenuPins Cpy_enuPinNumber,u8* Add_pu8PinValue){
	DIO_tenuErrorStatus Loc_enuErrorStatus = DIO_enuOk;

	u8 Loc_u8PortNumber =0;
	u8 Loc_u8PinNumber =0;
	
	if (Cpy_enuPinNumber > DIO_enuNumberOfPins - 1 ){
		Loc_enuErrorStatus = DIO_enuInvalidPinNum;
		
	}
	else if( Add_pu8PinValue == NULL){
		Loc_enuErrorStatus = DIO_enuNull;
		
	}
	else{
		
			Loc_u8PortNumber = Cpy_enuPinNumber / 8;
			Loc_u8PinNumber = Cpy_enuPinNumber % 8;
			
			switch(Loc_u8PortNumber){
				case (DIO_PORTA):
					*Add_pu8PinValue = GET_BIT(PINA,Loc_u8PinNumber);
					break;
				case (DIO_PORTB):
					*Add_pu8PinValue = GET_BIT(PINB,Loc_u8PinNumber);
					break;
				case (DIO_PORTC):
					*Add_pu8PinValue = GET_BIT(PINC,Loc_u8PinNumber);
					break;
				case (DIO_PORTD):
					*Add_pu8PinValue = GET_BIT(PIND,Loc_u8PinNumber);
					break;
			}
		
	}	
	return Loc_enuErrorStatus;	
}



DIO_tenuErrorStatus DIO_enuWritePort(u8	PortNum, u8 Value){
	
	
	switch(PortNum){
		case (DIO_PORTA):
			PORTA = Value;
			break;
		case (DIO_PORTB):
			PORTB = Value;
			break;
		case (DIO_PORTC):
			PORTC = Value;
			break;
		case (DIO_PORTD):
			PORTD = Value;
			break;
	}
	
	
	return DIO_enuOk;
}