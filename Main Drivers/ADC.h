/*
 * ADC.h
 *
 * Created: 10/15/2020 4:48:23 PM
 *  Author: ahmed
 */ 


#ifndef ADC_H_
#define ADC_H_

void ADC_Init();

uint16 ADC_Read(uint8 channel);

/* ADCSRA */
#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0

/* ADMUX */
#define REFS1   7
#define REFS0   6
#define ADLAR   5
#define MUX4    4
#define MUX3    3
#define MUX2    2
#define MUX1    1
#define MUX0    0

#endif /* ADC_H_ */