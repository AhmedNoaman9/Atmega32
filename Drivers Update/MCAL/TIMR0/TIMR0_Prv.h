/*
 * TIMR0_Prv.h
 *
 * Created: 28-Feb-23 7:57:10 PM
 *  Author: NO3M4N
 */ 


#ifndef TIMR0_PRV_H_
#define TIMR0_PRV_H_

#define TIMER_BASE_ADDRESS  0x52

/*
#define OCR0	*((volatile	u8* const)	0x5C )
#define TIMSK	*((volatile	u8* const)	0x59 )
#define TIFR	*((volatile	u8* const)	0x58 )
#define TIMSK	*((volatile	u8* const)	0x52 )
*/

#define TIMSK	*((volatile u8*)0x59)
#define TIMSK_TOIE0		0
#define TIMSK_OCIE0		1

#define TIFR	*((volatile u8*)0x58)
#define TIFR_TOV0		0
#define TIFR_OCF0		1

#define OCR0	*((volatile u8*)0x5C)
#define TCCR0	*((volatile u8*)0x53)
#define TCNT0	*((volatile u8*)0x52)
/*
typedef struct
{
	// 	u8 OCR2;
	// 	u8 TCNT2;
	// 	u8 TCCR2;
	// 	u8 ICR1L;
	// 	u8 ICR1H;
	// 	u8 OCR1BL;
	// 	u8 OCR1BH;
	// 	u8 OCR1AL;
	// 	u8 OCR1AH;
	// 	u8 TCNT1L;
	// 	u8 TCNT1H;
	// 	u8 TCCR1B;
	// 	u8 TCCR1A;
	// 	u8 SFIOR;
	// 	u8 OCDR;
	// 	u8 OSCCAL;
	volatile u8 TCNT0;
	volatile u8 TCCR0;
	volatile u8 MCUCSR;
	volatile u8 MCUCR;
	volatile u8 TWCR;
	volatile u8 SPMCR;
	volatile u8 TIFR;
	volatile u8 TIMSK;
	volatile u8 GIFR;
	volatile u8 GICR;
	volatile u8 OCR0;	
}Timer_t;

#define TIMER ((volatile Timer_t* const)(TIMER_BASE_ADDRESS))

*/

#define TIM0_OVF_VECTOR		11
#define TIM0_CTC_VECTOR		10



#endif /* TIMR0_PRV_H_ */