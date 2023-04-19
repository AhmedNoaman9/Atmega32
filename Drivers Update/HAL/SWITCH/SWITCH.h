/*******************************************/
/*         SWITCH Driver                 */
/*Target : ATMEGA32                        */
/*Author :NO3MAN                    */
/*Date   :2023-01-18                         */
/*******************************************/

#ifndef SWITCH_H
#define SWITCH_H

typedef struct
{
	u8 SW_Number;

}SWITCH_Cfg_t;




#define SWITCH_PUP_PRESSED	0
#define SWITCH_PUP_NOTPRESSED	1

#define SWITCH_PDOWN_PRESSED	1
#define SWITCH_PDOWN_NOTPRESSED	0


typedef enum
{
	SWITCH_enuOk =0,
	SWITCH_enuNotOk,
	SWITCH_enuNull,
	SWITCH_enuInvalidPinNum,
	SWITCH_enuInvalidPortNum

}SWITCH_tenuErrorStatus;


typedef enum
{
	SWITCH_enuPin0=0,
	SWITCH_enuPin1	 ,
	SWITCH_enuPin2	 ,
	SWITCH_enuPin3	 ,
	SWITCH_enuPin4	 ,
	SWITCH_enuPin5	 ,
	SWITCH_enuPin6	 ,
	SWITCH_enuPin7	 ,
	SWITCH_enuPin8	 ,
	SWITCH_enuPin9	 ,
	SWITCH_enuPin10 ,
	SWITCH_enuPin11 ,
	SWITCH_enuPin12 ,
	SWITCH_enuPin13 ,
	SWITCH_enuPin14 ,
	SWITCH_enuPin15 ,
	SWITCH_enuPin16 ,
	SWITCH_enuPin17 ,
	SWITCH_enuPin18 ,
	SWITCH_enuPin19 ,
	SWITCH_enuPin20 ,
	SWITCH_enuPin21 ,
	SWITCH_enuPin22 ,
	SWITCH_enuPin23 ,
	SWITCH_enuPin24 ,
	SWITCH_enuPin25 ,
	SWITCH_enuPin26 ,
	SWITCH_enuPin27 ,
	SWITCH_enuPin28 ,
	SWITCH_enuPin29 ,
	SWITCH_enuPin30 ,
	SWITCH_enuPin31,
	SWITCH_enuNumberOfPins
	
}SWITCH_tenuPins;



SWITCH_tenuErrorStatus SWITCH_enuGetSwitchValue(SWITCH_tenuPins Cpy_enuPinNumber,u8 *Add_pu8PinValue);

SWITCH_tenuErrorStatus SWITCH_enuIsPressed(SWITCH_tenuPins Cpy_enuPinNumber,u8 *Add_pu8PinValue);





#endif /*SWITCH_H*/
