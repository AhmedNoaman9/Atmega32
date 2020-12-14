/*
 * I2C.h
 *
 * Created: 10/11/2020 3:52:18 PM
 *  Author: ahmed
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "DataTypes.h"
#include "GPIO.h"
#include "AtmegaRegs.h"

#define PRESCALER_i2c 1
void I2C_init();
void I2C_start(void);
uint8 I2C_writeADR(uint8 adr_byte);
uint8 I2C_transmit(uint8 adr_byte);
void I2C_stop();
void I2C_setAddress(uint8 addr);
uint8 I2C_read(uint8 ack);
///////////////////////////////////////////////////
/*
void TWIInit(void);
void TWIStop(void);
void TWIStart(void);
void TWIWrite(uint8 u8data);
uint8 TWIReadACK(void);
uint8 TWIReadNACK(void);
uint8 TWIGetStatus(void);*/



/* TWCR */
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
/* bit 1 reserved */
#define TWIE    0

/* TWAR */
#define TWA6    7
#define TWA5    6
#define TWA4    5
#define TWA3    4
#define TWA2    3
#define TWA1    2
#define TWA0    1
#define TWGCE   0

/* TWSR */
#define TWS7    7
#define TWS6    6
#define TWS5    5
#define TWS4    4
#define TWS3    3
/* bit 2 reserved */
#define TWPS1   1
#define TWPS0   0

#define write_i2c 0
#define read_i2c 1


#endif /* I2C_H_ */