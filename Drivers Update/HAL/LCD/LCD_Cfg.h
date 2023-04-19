/*
 * LED_Cfg.h
 *
 * Created: 17-Jan-23 8:28:15 PM
 *  Author: NO3M4N
 */ 


#ifndef LED_CFG_H_
#define LED_CFG_H_





#define LCD_Data_Port		DIO_PORTD	/* Define LCD data port */
#define LCD_Command_Port	DIO_PORTC	/* Define LCD data port */

#define RS 0			/* Define Register Select signal pin */
#define RW 1			/* Define Read/Write signal pin */
#define EN 2			/* Define Enable signal pin */


#define LCD1	0


extern const LCD_strCfg_t	LCD_CfgStr[1];


#endif /* LED_CFG_H_ */