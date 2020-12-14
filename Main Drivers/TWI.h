/*
 * TWI.h
 *
 * Created: 10/16/2020 5:25:07 PM
 *  Author: ahmed
 */ 


#ifndef TWI_H_
#define TWI_H_
void TWIInit(void);
void TWIStop(void);
void TWIStart(void);
void TWIWrite(uint8 u8data);
uint8 TWIReadACK(void);
uint8 TWIReadNACK(void);
uint8 TWIGetStatus(void);




#endif /* TWI_H_ */