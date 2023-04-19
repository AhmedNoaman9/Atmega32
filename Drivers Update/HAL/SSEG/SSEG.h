/*******************************************/
/*         SSEG Driver                 */
/*Target : ATMEGA32                        */
/*Author :NO3M4N                    */
/*Date   :2023-01-20                         */
/*******************************************/



#ifndef SSEG_H
#define SSEG_H





typedef enum
{
	SSEG_enuOk =0,
	SSEG_enuNotOk,
	SSEG_enuNull,
	SSEG_enuInvalidPinNum,
	SSEG_enuInvalidSSEG,
	SSEG_MAX_NUM_DISP,
}SSEG_tenuErrorStatus;


typedef enum
{
	SSEG_enuPin0=0,
	SSEG_enuPin1	 ,
	SSEG_enuPin2	 ,
	SSEG_enuPin3	 ,
	SSEG_enuPin4	 ,
	SSEG_enuPin5	 ,
	SSEG_enuPin6	 ,
	SSEG_enuPin7	 ,
	SSEG_enuPin8	 ,
	SSEG_enuPin9	 ,
	SSEG_enuPin10 ,
	SSEG_enuPin11 ,
	SSEG_enuPin12 ,
	SSEG_enuPin13 ,
	SSEG_enuPin14 ,
	SSEG_enuPin15 ,
	SSEG_enuPin16 ,
	SSEG_enuPin17 ,
	SSEG_enuPin18 ,
	SSEG_enuPin19 ,
	SSEG_enuPin20 ,
	SSEG_enuPin21 ,
	SSEG_enuPin22 ,
	SSEG_enuPin23 ,
	SSEG_enuPin24 ,
	SSEG_enuPin25 ,
	SSEG_enuPin26 ,
	SSEG_enuPin27 ,
	SSEG_enuPin28 ,
	SSEG_enuPin29 ,
	SSEG_enuPin30 ,
	SSEG_enuPin31,
	SSEG_enuNumberOfPins
	
}SSEG_tenuPins;



extern const u8 SSEG_LookUpTable[10] ;


typedef struct {
	
	SSEG_tenuPins SSEG_enuPin[8];
	u8 SSEG_u8ActiveState;
}SSEG_tstrSSEGCfg_t;



#define SSEG_ZERO	0b0111111
#define SSEG_ONE	0b0000110
#define SSEG_TWO	0b1011011
#define SSEG_THREE	0b1001111
#define SSEG_FOUR	0b1100110
#define SSEG_FIVE	0b1101101
#define SSEG_SIX	0b1111101
#define SSEG_SEVEN	0b0000111
#define SSEG_EIGHT	0b1111111
#define SSEG_NINE	0b1101111


SSEG_tenuErrorStatus SSEG_enuInit(void);

SSEG_tenuErrorStatus SSEG_enuSetNumber(u8 Cpy_strSsegNumber , u8 Cpy_u8Number);
SSEG_tenuErrorStatus SSEG_enuClearNumber(u8 Cpy_strSsegNumber);




#endif /*SSEG_H*/
