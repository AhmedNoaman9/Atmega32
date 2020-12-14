/*
 * TWI.c
 *
 * Created: 10/16/2020 4:23:55 PM
 *  Author: ahmed
 */ 
#include "I2C.h"

void TWIInit(void)
{
	//set SCL to 400kHz
	myTWSR = 0x00;
	myTWBR = 0x0C;
	//enable TWI
	myTWCR = (1<<TWEN);
}

void TWIStop(void)
{
	myTWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}
void TWIStart(void)
{
	myTWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while ((myTWCR & (1<<TWINT)) == 0);
}
//send stop signal

void TWIWrite(uint8 u8data)
{
	myTWDR = u8data;
	myTWCR = (1<<TWINT)|(1<<TWEN);
	while ((myTWCR & (1<<TWINT)) == 0);
}

uint8 TWIReadACK(void)
{
	myTWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while ((myTWCR & (1<<TWINT)) == 0);
	return myTWDR;
}
//read byte with NACK
uint8 TWIReadNACK(void)
{
	myTWCR = (1<<TWINT)|(1<<TWEN);
	while ((myTWCR & (1<<TWINT)) == 0);
	return myTWDR;
}

uint8 TWIGetStatus(void)
{
	uint8 status;
	//mask status
	status = myTWSR & 0xF8;
	return status;
}
