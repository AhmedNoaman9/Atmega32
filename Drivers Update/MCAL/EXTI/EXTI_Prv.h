/*******************************************/
/*         EXTI Driver                 */
/*Target : ATMEGA32                        */
/*Author :Ahmed Noaman                    */
/*Date   :2023-01-27                         */
/*******************************************/

#ifndef _EXTI_PRV_H
#define _EXTI_PRV_H


#define		MCUCR	*((volatile u8 *) 0x55)
#define		ISC00	0
#define		ISC01	1
#define		ISC10	2
#define		ISC11	3

	
	
	
#define		MCUSR	*((volatile u8 *) 0x54)
#define		ISC2	6


#define		GICR	*((volatile u8 *) 0x5B)
#define		GIFR	*((volatile u8 *) 0x5A)



#define INT0	6
#define INT1	7
#define INT2	5


#define INT_ENABLE	1
#define	INT_DISABLE	0




#endif /*EXTI_PRV_H*/
