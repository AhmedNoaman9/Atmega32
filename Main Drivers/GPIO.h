/*
 * GPIO.h
 *
 * Created: 9/1/2020 12:30:07 PM
 *  Author: ahmed
 */ 

#ifndef GPIO_H_
#define GPIO_H_


#include "DataTypes.h"
#include "AtmegaRegs.h"

#include "util/delay.h"

#define myPORTA  ((volatile unsigned char* const)0X3B)
#define myDDRA   ((volatile unsigned char* const)0X3A)
#define myPINA   ((volatile unsigned char* const)0X39)

#define myPORTB  ((volatile unsigned char* const)0X38)
#define myDDRB   ((volatile unsigned char* const)0X37)
#define myPINB   ((volatile unsigned char* const)0X36)

#define myPORTC  ((volatile unsigned char* const)0X35)
#define myDDRC   ((volatile unsigned char* const)0X34)
#define myPINC   ((volatile unsigned char* const)0X33)

#define myPORTD  ((volatile unsigned char* const)0X32)
#define myDDRD   ((volatile unsigned char* const)0X31)
#define myPIND   ((volatile unsigned char* const)0X30)


#define A 0x39
#define B 0x36
#define C 0x33
#define D 0x30

#define u8_Direction_input 0x00
#define u8_Direction_output 0xFF
//choose the default intialization for GPIO
#define Init_direction_default u8_Direction_input
#define no_of_pins_on_port 8

#define ISR(vector, ...)\
void vector(void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__;\
void vector(void)


void set(uint8 reg,uint8 bit);
void clear(uint8 reg,uint8 bit);


//=========================Initialization====================================
/*Comment!: Initialization function */
void GPIO_pinit(void);
//====================================================================
extern	void digitalWrite(uint8 portname, uint8 pinindex,uint8 pinval); // GPIO_writepinval(5,on,'a')

extern uint8 pinRead(uint8 PinIdx, uint8 Port_Name);

//extern uint8_t pinread(uint8_t port, uint8_t pin);
/*
extern uint8_t pin_read (uint8_t port, uint8_t pin);*/


extern	void pinMode(uint8 portname, uint8 pinindex,uint8 pindir);  // GPIO_writepindir(5,input,'a')

extern	uint8 writeportval(uint8 portval,uint8 portname);

extern	uint8 writeportdir(uint8 portdir,uint8 portname);

extern	uint8 readportval(uint8 portname);

extern	uint8 readportdir(uint8 portname);

#endif

