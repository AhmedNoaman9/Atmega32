/*
 * ADC.h
 *
 * Created: 05-Feb-23 12:08:42 PM
 *  Author: NO3M4N
 */ 


#ifndef ADC_H_
#define ADC_H_


/******************************INCLUDES****************************************/


/********************************MACROS**********************************************/

// Reference Voltage options 

#define		REFVOLT_MODE		REFVOLT_AVCC

#define		REFVOLT_AREF				0x00
#define		REFVOLT_AVCC				0x40
#define		REFVOLT_INTERNAL2_56V		0xC0

#define		REFVOLT_CLEAR	0x1F

// Data Adjustment Value 



#define		ADJUST_LEFT				0x20
#define		ADJUST_RIGHT			0xDF


// Channel and Gain Selection



#define		CHANNEL_ADC_0	0x00		
#define		CHANNEL_ADC_1	0x01
#define		CHANNEL_ADC_2	0x02
#define		CHANNEL_ADC_3	0x03
#define		CHANNEL_ADC_4	0x04
#define		CHANNEL_ADC_5	0x05
#define		CHANNEL_ADC_6	0x06
#define		CHANNEL_ADC_7	0x07


#define		CHANNEL_ADC_POS_DIFF_0_GAIN10	0x08
#define		CHANNEL_ADC_POS_DIFF_1_GAIN10	0x09
#define		CHANNEL_ADC_POS_DIFF_0_GAIN200	0x0A
#define		CHANNEL_ADC_POS_DIFF_1_GAIN200	0x0B
#define		CHANNEL_ADC_POS_DIFF_2_GAIN10	0x0C
#define		CHANNEL_ADC_POS_DIFF_3_GAIN10	0x0D
#define		CHANNEL_ADC_POS_DIFF_2_GAIN200	0x0E
#define		CHANNEL_ADC_POS_DIFF_3_GAIN200	0x0F

#define		CHANNEL_ADC_POS_DIFF_0_NOGAIN			0x10
#define		CHANNEL_ADC_POS_DIFF_1_NOGAIN			0x11
#define		CHANNEL_ADC_POS_DIFF_2_NOGAIN			0x12
#define		CHANNEL_ADC_POS_DIFF_3_NOGAIN			0x13
#define		CHANNEL_ADC_POS_DIFF_4_NOGAIN			0x14
#define		CHANNEL_ADC_POS_DIFF_5_NOGAIN			0x15
#define		CHANNEL_ADC_POS_DIFF_6_NOGAIN			0x16
#define		CHANNEL_ADC_POS_DIFF_7_NOGAIN			0x17

#define		MUX_0_4_CLEAR							0xE0
/////////////////////////////////

#define		INTERRUPTSTATE_ENABLE	0x08
#define		INTERRUPTSTATE_DISABLE	0xF7

//////////////////////////////////////////////////

#define PRESCALER_ADC_CLEAR		0xF8

#define PRESCALER_ADC_2			0x01
#define PRESCALER_ADC_4			0x02
#define PRESCALER_ADC_8			0x03
#define PRESCALER_ADC_16		0x04
#define PRESCALER_ADC_32		0x05
#define PRESCALER_ADC_64		0x06
#define PRESCALER_ADC_128		0x07

///////////////////AUTOTRIGGER OPTIONS/////////////////////////////////////

#define AUTOTRIG_MODE_SINGLE_MODE			0xDF

#define AUTOTRIG_MODE_FREE_RUN				0x00
#define AUTOTRIG_MODE_ANALOG_COM			0x01
#define AUTOTRIG_MODE_EXTI_0				0x02
#define AUTOTRIG_MODE_TIM0_CMPMTCH			0x03
#define AUTOTRIG_MODE_TIM0_OVF				0x04
#define AUTOTRIG_MODE_TIM1_CMPMTCHB			0x05
#define AUTOTRIG_MODE_TIM1_OVF				0x06
#define AUTOTRIG_MODE_TIM1_CMPMTCH			0x07
#define AUTOTRIG_MODE_TIM1_CAPEVENT			0x08
//////////////////////////////////////////////////////

#define ADIF_SET_MASK	0x10





/********************************USER DEFINED TYPES********************************************/
typedef enum {
	
	ADC_OK,
	ADC_NOK,
	ADC_WRONG_CONF,
	ADC_TimeOut
	
	
	
}adc_enuErrorStatus_t;


/*******************************FUNCTION PROTOTYPES / APIs**********************************/



/************************************
ADC Enable and disable functions 

input : Void

output : adc_enuErrorStatus_t to report errors or completion of functionality

**********************************/
adc_enuErrorStatus_t	adc_EnableADC();
adc_enuErrorStatus_t	adc_DisableADC();



/************************************
ADC Reference Voltage Selection function

input : u8 RefVolt		(REFVOLT_AREF	 REFVOLT_AVCC	REFVOLT_INTERNAL2_56V)

output : adc_enuErrorStatus_t to report errors or completion of functionality

**********************************/
adc_enuErrorStatus_t	adc_SelectRefVolt(u8 RefVolt);

/************************************
ADC Data Adjustment Selection function

input : u8 AdjustValue		(ADJUST_LEFT   ADJUST_RIGHT)

output : adc_enuErrorStatus_t to report errors or completion of functionality

**********************************/
adc_enuErrorStatus_t	adc_SelectDataAdjustment(u8 AdjustValue);


/************************************
ADC Channel Selection function

input : u8 Channel 

output : adc_enuErrorStatus_t to report errors or completion of functionality

**********************************/
adc_enuErrorStatus_t	adc_SelectChannelandGain(u8 Channel);

/************************************
ADC Enable AutoTrigger function

input : void  (Configure Trigger source using ADTS in SFIOR OR corresponding Function)

output : adc_enuErrorStatus_t to report errors or completion of functionality

**********************************/
adc_enuErrorStatus_t	adc_StartConversion(void);

/************************************
ADC  SET Enable/Disable Interrupt function

input :u8 InterruptState  INTERRUPTSTATE_ENABLE, INTERRUPTSTATE_DISABLE  (Check Flag ADIF or Use Corresponding Function)

output : adc_enuErrorStatus_t to report errors or completion of functionality

**********************************/
adc_enuErrorStatus_t	adc_SetInterruptState(u8 InterruptState);

/************************************
ADC  SET Prescaler Value function

input :u8 Prescaler 

output : adc_enuErrorStatus_t to report errors or completion of functionality

**********************************/
adc_enuErrorStatus_t	adc_SetPrescaler(u8 Prescaler);


/************************************
ADC READ Value function (In Single Mode Only) 

input :u32

output : adc_enuErrorStatus_t to report errors or completion of functionality

**********************************/
adc_enuErrorStatus_t	adc_ReadADCsync(u8 Channel,u16* ptrData);



/************************************
ADC Set AutoTrigger Enable/Disable and mode function

input :u8	AutoTrig_Mode  

output : adc_enuErrorStatus_t to report errors or completion of functionality

**********************************/
adc_enuErrorStatus_t	adc_SetAutoTrigMode(u8 AutoTrig_Mode);



#define ISR_ADC_FREERUNNING()	void __vector_16(void) __attribute__((signal)); void __vector_16(void)



#endif /* ADC_H_ */