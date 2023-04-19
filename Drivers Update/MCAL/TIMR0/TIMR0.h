/*
 * TIMR0.h
 *
 * Created: 28-Feb-23 7:56:05 PM
 *  Author: NO3M4N
 */ 


#ifndef TIMR0_H_
#define TIMR0_H_


#define Nullptr  			(void*)0


#define		TIM0_NORMAL					0x00U
//#define		TIM0_PWM_PHASE_CORRECT		0x40U
#define		TIM0_CTC					0x08U
//#define		TIM0_FAST_PWM				0x48U
#define		TIM0_MODE_CLR				0xB7U


#define		TIM0_OC0_BIT_CLR						0x60U
#define		TIM0_OC0_NONPWM_DICONNECT				0x00U
//#define		TIM0_OC0_NONPWM_TOGGLE					0x10U
//#define		TIM0_OC0_NONPWM_CLRONCMP				0x20U
//#define		TIM0_OC0_NONPWM_SETONCMP				0x30U


//#define		TIM0_OC0_FASTPWM_DICONNECT				0x00U
//#define		TIM0_OC0_FASTPWM_NONINVERTING			0x20U
//#define		TIM0_OC0_FASTPWM_INVERTING				0x30U


#define		TIM0_CLK_BIT_CLR						0xF8U
#define		TIM0_CLK_DEACTIVATE						0x00U
#define		TIM0_NO_PRESCALER						0x01U
#define		TIM0_PRESCALER_DIV8						0x02U
#define		TIM0_PRESCALER_DIV64					0x03U
#define		TIM0_PRESCALER_DIV256					0x04U
#define		TIM0_PRESCALER_DIV1024					0x05U
#define		TIM0_EXT_CLK_FALLING					0x06U
#define		TIM0_EXT_CLK_RISING						0x07U

#define		TIM0_INT_OVF_ENABLE						0x01
#define		TIM0_INT_OC0_ENABLE						0x02
#define		TIM0_INT_DISABLE						0x00
#define		TIM0_INT_BIT_CLR						0xFC

#define	TIM0_MODE	TIM0_NORMAL		

#define TIM0_MAX_VAL								0xFF

//#define		TICKTIME_32us	



typedef void(*TMR0cbf_t)(void);

typedef struct 
{
	u8	TIM0_Mode;
	u8	TIM0_OC_Mode;
	u8	TIM0_INTen;
	u16	OVF_Count;
	u8	Clock_select;
}TMR0Config_t;


typedef	enum 
{
	TIM0_OK,
	TIM0_NOK,
	TIM0_NULLptr
	
}TMR0_enuErrorStatus;





//void TMR0_vidInitPreCompile(void);

TMR0_enuErrorStatus TMR0_vidInitPostCompile(const TMR0Config_t* TIM0Cfg_str);


/*

At 8MHZ	

No prescaler	max tick time is 32us
Prescaler 8		max tick time is 25us


*/

TMR0_enuErrorStatus TMR0_enuSetTickTimeMS(u16 Copy_u16TickTime, u32 Copy_u32Clock);

TMR0_enuErrorStatus TMR0_enuStart(u8 Value);

TMR0_enuErrorStatus TMR0_enuSetCallback(TMR0cbf_t	Cbf);




#endif /* TIMR0_H_ */