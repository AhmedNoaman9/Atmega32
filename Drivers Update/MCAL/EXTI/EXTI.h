/*******************************************/
/*         EXTI Driver                 */
/*Target : ATMEGA32                        */
/*Author :Ahmed Noaman                    */
/*Date   :2023-01-27                         */
/*******************************************/

#ifndef _EXTI_H
#define _EXTI_H



#define NUMBER_OF_EXTI	3



#define INT_LOW_LEVEL		0b11
#define INT_LOGIC_CHANGE	0b01
#define INT_FALLING_EDGE	0b10
#define INT_RISING_EDGE		0b11

#define INT2_RISING_EDGE	1
#define INT2_FALLING_EDGE	0



typedef enum
{
	EXTI_enuOk =0,
	EXTI_enuNotOk,
	EXTI_enuNull,
	EXTI_enuInvalidIntNum,
	EXTI_enuInvalidIntActStatus,
	EXTI_enuInvalidSenseControl,
	EXTI_INT2FireError
}EXTI_tenuErrorStatus;


typedef enum
{
	EXTI_enuINT0 = 5,
	EXTI_enuINT1,
	EXTI_enuINT2 = 7,
	EXTI_enuEXTINumber = 3,
}EXTI_tenuIntNumber;

typedef enum
{
	EXTI_enuLowLevel =0x00,
	EXTI_enuLogicChange = 0x01,
	EXTI_enuFallingEdge = 0x02,
	EXTI_enuRisingEdge= 0x03,
	EXTI_enuINT0SenseClear = 0xFC,
	EXTI_enuINT1SenseClear = 0xF3
	
}EXTI_tenuIntSenseControl;



typedef struct {

	u8 EXTI_enuIntNum;
	u8 EXTI_u8ActiveStatus;
	u8 EXTI_u8IntSenseControl;
	
}EXTI_strEXTICfg_t;


/***************************************************************

	Extrenal Interrupt Inittialization 
	Input : void   ( Configurations In Cfg.c )
	Output : EXTI_tenuErrorStatus ( Enum with detailed errors provided)
************************************************************************/

EXTI_tenuErrorStatus EXTI_enuInit(void);








#endif /*EXTI_H*/
