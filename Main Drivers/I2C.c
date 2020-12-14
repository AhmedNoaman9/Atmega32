/*
 * I2C.c
 *
 * Created: 10/11/2020 3:51:53 PM
 *  Author: ahmed
 */ 

#include "I2C.h"

void I2C_init(unsigned long SCL){
myTWBR= (uint8) (((F_CPU/SCL) - 16 )/ (2*PRESCALER_i2c));

if (PRESCALER_i2c== 1 ){
	myTWSR= 0;
}
else if (PRESCALER_i2c==4)
{
	myTWSR= 1;
}
else if (PRESCALER_i2c==16)
{
	myTWSR= 2;
}
else if (PRESCALER_i2c== 64)
{
	myTWSR= 3;
}
}


void I2C_start(void){
	myTWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);
	while(myTWCR & (1<<TWINT) == 0 );
	while ((myTWSR)!= 0x08);
	
}

uint8 I2C_writeADR(uint8 adr_byte){
	myTWDR= adr_byte;
	myTWCR=(1<<TWINT)|(1<<TWEN);
	while ((myTWCR & 0x80)== 0);
	return myTWDR;
}
uint8 I2C_transmit(uint8 adr_byte){
	myTWDR= adr_byte;
	myTWCR=(1<<TWINT)|(1<<TWEN);
	//while (myTWCR & (1<<7)==0);
	
	while ((myTWCR & 0x80)== 0);
	
	return myTWDR;
}

void I2C_stop()
{
	myTWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void I2C_setAddress(uint8 addr){
	myTWAR= addr;
}

uint8 I2C_read(uint8 ack){

	myTWCR=(1<<TWINT)|(1<<TWEN)|(ack<<TWEA);
	while (myTWCR& (1<<TWINT)==0);
	//while(myTWSR!=0x60);

	myTWCR=(1<<TWINT)|(1<<TWEN)|(ack<<TWEA);
	while (myTWCR& (1<<TWINT)==0);
	//while(myTWSR!=0x80)

	
	return myTWDR;
	
}