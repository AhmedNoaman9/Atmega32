/*
 * ADC.c
 *
 * Created: 05-Feb-23 12:08:24 PM
 *  Author: NO3M4N
 */ 


/******************************INCLUDES****************************************/
#include "../../LIB/Bit_math.h"
#include "../../LIB/Std_types.h"

#include "ADC.h"



/********************************MACROS**********************************************/

#define ADMUX	*((volatile u8*const) 0x27 )
#define ADCSRA	*((volatile u8*const) 0x26 )
#define ADCH	*((volatile u8*const) 0x25 )
#define ADCL	*((volatile u8*const) 0x24 )
	
#define SFIOR	*((volatile u8*) 0x50 )

#define ADEN	7

#define ADLAR	5

#define ADSC	6

#define ADIE	3

#define ADIF	4




adc_enuErrorStatus_t	adc_EnableADC()
{	
	
	ADCSRA |= (1<<ADEN);	
	return ADC_OK;
}

adc_enuErrorStatus_t	adc_DisableADC()
{
	
	ADCSRA &= ~(1<<ADEN);
	return ADC_OK;
}


adc_enuErrorStatus_t	adc_SelectRefVolt(u8 RefVolt)
{
	u8 Loc_TempADMUX = ADMUX;
	adc_enuErrorStatus_t Loc_ErrorStatus = ADC_OK;
	
	if (RefVolt == 0x00 ||	RefVolt== 0x40 || RefVolt== 0xC0)
	{
		Loc_TempADMUX &= ~REFVOLT_CLEAR; 
		Loc_TempADMUX |= REFVOLT_MODE;
		
		ADMUX = Loc_TempADMUX;
	}
	else
	{
		Loc_ErrorStatus = ADC_NOK;
		
	}
	return Loc_ErrorStatus;
	
	
}

adc_enuErrorStatus_t	adc_SelectDataAdjustment(u8 AdjustValue)
{
	adc_enuErrorStatus_t Loc_ErrorStatus = ADC_OK;
	
	if(AdjustValue == ADJUST_LEFT  )
	{
		SET_BIT(ADMUX,ADLAR);
	}
	else if(AdjustValue == ADJUST_RIGHT  )
	{
		CLR_BIT(ADMUX,ADLAR);	
	}
	else
	{
		Loc_ErrorStatus = ADC_WRONG_CONF;
	}
	
	return Loc_ErrorStatus;
}

adc_enuErrorStatus_t	adc_SelectChannelandGain(u8 Channel)
{
	u8 Loc_TempADMUX = ADMUX;
	adc_enuErrorStatus_t Loc_ErrorStatus = ADC_OK;
	
	if (Channel <= CHANNEL_ADC_POS_DIFF_7_NOGAIN)
	{ //Max Confinguration Value
		
		Loc_TempADMUX &= MUX_0_4_CLEAR;
		Loc_TempADMUX |= Channel;
		
		ADMUX = Loc_TempADMUX;
	}
	else
	{
		Loc_ErrorStatus = ADC_WRONG_CONF;
	}
	
	return Loc_ErrorStatus;
}

adc_enuErrorStatus_t	adc_StartConversion(void)
{

	ADCSRA |= (1<< ADSC); /* SET ADSC BIT in ADCSRA Register to start Conversion	*/
	
	return ADC_OK;
	
}

adc_enuErrorStatus_t	adc_SetInterruptState(u8 InterruptState)
{
	adc_enuErrorStatus_t Loc_ErrorStatus = ADC_OK;
	
	if (InterruptState == INTERRUPTSTATE_ENABLE)
	{
		ADCSRA |= 1 << ADIE ; /* SET ADIE BIT in ADCSRA Register to Enable Interrupts	*/
	}
	else if (InterruptState == INTERRUPTSTATE_ENABLE)
	{
		ADCSRA &=  ~( 1 << ADIE ) ;  /* CLEAR ADIE BIT in ADCSRA Register to Enable Interrupts	*/
	}
	
	else
	{
		Loc_ErrorStatus = ADC_WRONG_CONF;
	}
	
	return Loc_ErrorStatus;

}

adc_enuErrorStatus_t	adc_SetPrescaler(u8 Prescaler)
{
	u8 Loc_TempADCSRA = ADCSRA;
	adc_enuErrorStatus_t Loc_ErrorStatus = ADC_OK;
	
	if (Prescaler <= PRESCALER_ADC_128)
	{
		Loc_TempADCSRA &= PRESCALER_ADC_CLEAR;	/* CLEAR ADPS bits using mask  */
		Loc_TempADCSRA |= Prescaler;			/* SET ADPS bits using mask  */
			
		ADCSRA = Loc_TempADCSRA;
	}
	else
	{
		Loc_ErrorStatus = ADC_WRONG_CONF;
	}
	
	return Loc_ErrorStatus;
	
}

adc_enuErrorStatus_t	adc_ReadADCsync(u8 Channel, u16* ptrData)
{
	adc_enuErrorStatus_t Loc_ErrorStatus = ADC_OK;
	u16 Loc_TimeOut= 0;
	*ptrData = 0;
	ADCSRA |= (1<< ADSC); /* SET ADSC BIT in ADCSRA Register to start Conversion	*/
	u8 Loc_TempADMUX = ADMUX;
	
	
	if (Channel <= CHANNEL_ADC_POS_DIFF_7_NOGAIN)
	{ //Max Confinguration Value
		
		Loc_TempADMUX &= MUX_0_4_CLEAR;
		Loc_TempADMUX |= Channel;
		
		ADMUX = Loc_TempADMUX;
	}
	else
	{
		Loc_ErrorStatus = ADC_WRONG_CONF;
	}
	
	while( !(ADCSRA & ADIF_SET_MASK) && Loc_TimeOut <= 5000){ /* Check Flag */
		
		Loc_TimeOut++;
	}
	if( ADCSRA & ADIF_SET_MASK  )
	{
		if ( ADMUX & ADJUST_LEFT ){
			
			//*ptrData=  ((u16)ADCL & 0x00C0); // Read msb two bits and cast them to u16 and add to Data
			*ptrData+= (u16)ADCH;	// Read The Registers and cast it to u16 and add to Data
		}
		else
		{
			*ptrData= ( ( (u16)ADCL )& 0x00FF); // Read The Register and cast it to u16 and add to Data
			*ptrData= (*ptrData) + ( ( (u16)ADCH & 0x0003 )<< 8  );	// Read lsb two bits and cast them to u16 and add to Data
		}
	}
	else if (Loc_TimeOut >=5000)
	{
		Loc_ErrorStatus = ADC_TimeOut;
	}
	else
	{
		Loc_ErrorStatus = ADC_NOK;
	}
	
	if ( !(ADCSRA & INTERRUPTSTATE_ENABLE) )
	{
		ADCSRA |= 0x04;  /*	Clear Flag*/
		
	}	
	return Loc_ErrorStatus;
	
	
}

adc_enuErrorStatus_t	adc_SetAutoTrigMode(u8 AutoTrig_Mode)
{
	adc_enuErrorStatus_t Loc_ErrorStatus = ADC_OK;
	u8 Loc_TempReg = SFIOR;
	
	if (AutoTrig_Mode <= AUTOTRIG_MODE_TIM1_CAPEVENT)
	{
		Loc_TempReg &= AUTOTRIG_MODE_SINGLE_MODE ;
		Loc_TempReg |= AutoTrig_Mode ;
		
		SFIOR = Loc_TempReg;	
	}
	else
	{
		Loc_ErrorStatus = ADC_WRONG_CONF;
		
	}
	
	return Loc_ErrorStatus;
}


void ADC_INT_SetCallBack(void (*ptr)(void))
{
	if (ptr != NULL)
	{
		
	}
	
}




/*
adc_enuErrorStatus_t	adc_IsReady(u8 AutoTrig_Mode)
{
	
}

*/