/*
 * EEPROM.c
 *
 * Created: 10/14/2020 3:25:54 PM
 *  Author: ahmed
 */ 


#define F_CPU 8000000UL
#include "EEPROM.h"









void EEPROM_Write (char data, char address)

{

	I2C_start();

	I2C_writeADR(0b10101000); //slave address is 1010.100 and a 0 in the 8th bit to indicate Writing.

	I2C_writeADR(address);

	I2C_transmit(data);

	I2C_stop();
	
	 

}

void EEPROM_Read (char address, char* ptr) 
// the function arguments are an address in the EEPROM to read from and a pointer to a memory place in the MCU to store the read data in

{

	I2C_start();

	I2C_writeADR(0xA8);

	I2C_writeADR(address);

	I2C_start();

	I2C_writeADR(0xA9);

	I2C_read(ptr);

	I2C_stop();




}

uint8 EEWriteByte(uint16 u16addr, char u8data)
{
	TWIStart();
	//if (TWIGetStatus() != 0x08)
	//return ERROR;
	//select devise and send A2 A1 A0 address bits
	TWIWrite((EEDEVADR)|(uint8)((u16addr & 0x0700)>>7));
	//if (TWIGetStatus() != 0x18)
	//return ERROR;
	//send the rest of address
	TWIWrite((uint8)(u16addr));
	//if (TWIGetStatus() != 0x28)
	//return ERROR;
	//write byte to eeprom
	TWIWrite(u8data);
	//if (TWIGetStatus() != 0x28)
	//return ERROR;
	TWIStop();
	//return SUCCESS;
}

uint8 EEReadByte(uint16 u16addr, char *u8data)
{
	//uint8_t databyte;
	TWIStart();
//	if (myTWSR != 0x08)
//	return ERROR;
	//select devise and send A2 A1 A0 address bits
	TWIWrite((EEDEVADR)|((uint8)((u16addr & 0x0700)>>7)));
//	if (TWIGetStatus() != 0x18)
//	return ERROR;
	//send the rest of address
	TWIWrite((uint8)(u16addr));
//	if (TWIGetStatus() != 0x28)
//	return ERROR;
	//send start
	TWIStart();
//	if (TWIGetStatus() != 0x10)
//	return ERROR;
	//select devise and send read bit
	TWIWrite((EEDEVADR)|((uint8)((u16addr & 0x0700)>>7)|1));
//	if (TWIGetStatus() != 0x40)
//	return ERROR;
	*u8data = TWIReadNACK();
//	if (TWIGetStatus() != 0x58)
//	return ERROR;
	TWIStop();
	return *u8data;
//	return SUCCESS;
}


uint8 EEWritePage(uint8 page, char *u8data)
{
	//calculate page address
	uint8 u8paddr = 0;
	uint8 i;
	u8paddr = page<<4;
	TWIStart();
	/*if (TWIGetStatus() != 0x08)
	return ERROR;*/
	//select page start address and send A2 A1 A0 bits send write command
	TWIWrite(((EEDEVADR)|(u8paddr>>3))&(~1));
	/*if (TWIGetStatus() != 0x18)
	return ERROR;*/
	//send the rest of address
	TWIWrite((u8paddr<<4));
	/*if (TWIGetStatus() != 0x28)
	return ERROR;*/
	//write page to eeprom
	for (i=0; i<16; i++)
	{
		TWIWrite(*u8data++);
		if (TWIGetStatus() != 0x28)
		return ERROR;
	}
	TWIStop();
	return SUCCESS;
}
uint8 EEReadPage(uint8 page, char *u8data)
{
	//calculate page address
	uint8 u8paddr = 0;
	uint8 i;
	u8paddr = page<<4;
	TWIStart();
	if (TWIGetStatus() != 0x08)
	return ERROR;
	//select page start address and send A2 A1 A0 bits send write command
	TWIWrite(((EEDEVADR)|(u8paddr>>3))&(~1));
	/*if (TWIGetStatus() != 0x18)
	return ERROR;*/
	//send the rest of address
	TWIWrite((u8paddr<<4));
	/*if (TWIGetStatus() != 0x28)
	return ERROR;*/
	//send start
	TWIStart();
	/*if (TWIGetStatus() != 0x10)
	return ERROR;*/
	//select devise and send read bit
	TWIWrite(((EEDEVADR)|(u8paddr>>3))|1);
	/*if (TWIGetStatus() != 0x40)
	return ERROR;*/
	for (i=0; i<15; i++)
	{
		*u8data++ = TWIReadACK();
		/*if (TWIGetStatus() != 0x50)
		return ERROR;*/
	}
	*u8data = TWIReadNACK();
	/*if (TWIGetStatus() != 0x58)
	return ERROR;*/
	TWIStop();
	//return SUCCESS;
}