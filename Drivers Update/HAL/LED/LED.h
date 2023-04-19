/*
 * LED.h
 *
 * Created: 17-Jan-23 8:27:58 PM
 *  Author: NO3M4N
 */ 


#ifndef LED_H_
#define LED_H_



typedef enum
{
	LED_enuActiveHigh,
	LED_enuActiveLow
}LED_tenuState;




typedef enum
{
	LED_enuOk =0,
	LED_enuNotOk,
	LED_enuNull,
	LED_enuInvalidPinNum,
	LED_enuInvalidPortNum
}LED_tenuErrorStatus;


typedef enum
{
	LED_enuPin0=0,
	LED_enuPin1	 ,
	LED_enuPin2	 ,
	LED_enuPin3	 ,
	LED_enuPin4	 ,
	LED_enuPin5	 ,
	LED_enuPin6	 ,
	LED_enuPin7	 ,
	LED_enuPin8	 ,
	LED_enuPin9	 ,
	LED_enuPin10 ,
	LED_enuPin11 ,
	LED_enuPin12 ,
	LED_enuPin13 ,
	LED_enuPin14 ,
	LED_enuPin15 ,
	LED_enuPin16 ,
	LED_enuPin17 ,
	LED_enuPin18 ,
	LED_enuPin19 ,
	LED_enuPin20 ,
	LED_enuPin21 ,
	LED_enuPin22 ,
	LED_enuPin23 ,
	LED_enuPin24 ,
	LED_enuPin25 ,
	LED_enuPin26 ,
	LED_enuPin27 ,
	LED_enuPin28 ,
	LED_enuPin29 ,
	LED_enuPin30 ,
	LED_enuPin31,
	LED_enuNumberOfPins
	
}LED_tenuPins;


typedef struct{
	LED_tenuPins Pin;
	LED_tenuState Active_State;	
}LED_LedCfg_t;



LED_tenuErrorStatus LED_enuLedOn(LED_tenuPins Cpy_enuPinNumber);
LED_tenuErrorStatus LED_enuLedOff(LED_tenuPins Cpy_enuPinNumber);




#endif /* LED_H_ */