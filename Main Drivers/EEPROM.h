/*
 * EEPROM.h
 *
 * Created: 10/14/2020 3:26:23 PM
 *  Author: ahmed
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_


#include "I2C.h"
#include "TWI.h"
#include "AtmegaRegs.h"
#include "DataTypes.h"
#include <util/delay.h>


void TWI_Init (void);

void TWI_Start (void);

void TWI_Stop (void);

void TWI_Write (char data);

void TWI_Read_Nack (char* ptr);

void EEPROM_Write (char data, char address);

void EEPROM_Read (char address, char* ptr);


uint8 EEWriteByte(uint16 u16addr, char u8data);
uint8 EEReadByte(uint16 u16addr,  char *u8data);
uint8 EEWritePage(uint8 page,     char *u8data);
uint8 EEReadPage(uint8 page,      char *u8data);

#define EEDEVADR 0xA0
#define ERROR 0
#define SUCCESS 1



#endif /* EEPROM_H_ */