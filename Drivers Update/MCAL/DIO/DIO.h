/**************************************************
DIO INTEFACE FILE				*/
/*************************************************/

#ifndef DIO_H
#define DIO_H

#define HIGH	1	
#define LOW		0

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3


#define  MAX_PORT_PINS	8

typedef enum
{
	DIO_enuOk =0,
	DIO_enuNotOk,
	DIO_enuNull,
	DIO_enuInvalidPinNum,
	DIO_enuInvalidPortNum	
}DIO_tenuErrorStatus;

typedef enum
{
	DIO_enuPin0=0,
	DIO_enuPin1	 ,
	DIO_enuPin2	 ,
	DIO_enuPin3	 ,
	DIO_enuPin4	 ,
	DIO_enuPin5	 ,
	DIO_enuPin6	 ,
	DIO_enuPin7	 ,
	DIO_enuPin8	 ,
	DIO_enuPin9	 ,
	DIO_enuPin10 ,
	DIO_enuPin11 ,
	DIO_enuPin12 ,
	DIO_enuPin13 ,
	DIO_enuPin14 ,
	DIO_enuPin15 ,
	DIO_enuPin16 ,
	DIO_enuPin17 ,
	DIO_enuPin18 ,
	DIO_enuPin19 ,
	DIO_enuPin20 ,
	DIO_enuPin21 ,
	DIO_enuPin22 ,
	DIO_enuPin23 ,
	DIO_enuPin24 ,
	DIO_enuPin25 ,
	DIO_enuPin26 ,
	DIO_enuPin27 ,
	DIO_enuPin28 ,
	DIO_enuPin29 ,
	DIO_enuPin30 ,
	DIO_enuPin31,
	DIO_enuNumberOfPins
	
}DIO_tenuPins;

typedef enum 
{
	DIO_enuLow= 0,
	DIO_enuHigh
}DIO_tenuPinValue;


typedef struct
{
	u8 DIO_Pin_Direction;
	u8 DIO_InputStatus;
	
}DIO_strPinCfg_t;







/**************************************************************
DIO Init Function
Input: Void
Output: DIO_tenuErrorStatus To report Error status through enum
****************************************************************/
DIO_tenuErrorStatus DIO_enuInit(void);

/**************************************************************
DIO Set pin Function
Input: Pin Number from (0 to 31)
Output: DIO_tenuErrorStatus To report Error status through enum
****************************************************************/
DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPins Cpy_enuPinNumber);


/**************************************************************
DIO Clear pin Function
Input: Pin Number from (0 to 31)
Output: DIO_tenuErrorStatus To report Error status through enum
****************************************************************/
DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPins Cpy_enuPinNumber);



/**************************************************************
DIO Get pin Function
Input: Pin Number from (0 to 31) , Ptr To return Pin value in;
Output: DIO_tenuErrorStatus To report Error status through enum
****************************************************************/
DIO_tenuErrorStatus DIO_enuGetPin(DIO_tenuPins Cpy_enuPinNumber,u8* Add_pu8PinValue);



DIO_tenuErrorStatus DIO_enuSetPortDir(DIO_tenuPins Cpy_enuPortNumber);

DIO_tenuErrorStatus DIO_enuWritePort(u8	PortNum, u8 Value);









#endif  /*DIO_H*/
