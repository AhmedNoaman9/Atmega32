/*
 * ADC.c
 *
 * Created: 10/15/2020 4:48:01 PM
 *  Author: ahmed
 */ 

#include "GPIO.h"
#include "AtmegaRegs.h"
#include "ADC.h"
#include <util/delay.h>

void ADC_Init()
{
	pinMode(A,0,INPUT);				/* Make ADC port as input */
	pinMode(A,1,INPUT);
	pinMode(A,2,INPUT);
	pinMode(A,3,INPUT);
	
	// AREF = AVcc
	myADMUX = (1<<REFS0);
		
	// ADC Enable and prescaler of 128
	
	myADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	

}

uint16 ADC_Read(uint8 channel)
{
	uint16 Ain,AinLow;
	
	myADMUX=myADMUX|(channel & 0x0f);	/* Set input channel to read */

	myADCSRA |= (1<<ADSC);		/* Start conversion */
	while((myADCSRA&(1<<ADIF))==0);	/* Polling interrupt */
	
	_delay_us(10);
	AinLow = (uint8)myADCL;		/* Read lower byte*/
	Ain = (uint16)myADCH*256;		/* Read higher 2 bits and 
					Multiply with weight */
	Ain = Ain + AinLow;				
	return(Ain);			/* Return digital value*/
}





















/*uint16 adc_read(uint8 ch)
{
	// select the corresponding channel 0~7
	// ANDing with ’7? will always keep the value
	// of ‘ch’ between 0 and 7
	ch &= 0b00000111;  // AND operation with 7
	ADMUX = (ADMUX & 0xF8)|ch; // clears the bottom 3 bits before ORing
	
	// start single convertion
	// write ’1? to ADSC
	ADCSRA |= (1<<ADSC);
	
	// wait for conversion to complete
	// ADSC becomes ’0? again
	// till then, run loop continuously
	while(ADCSRA & (1<<ADSC));
	
	return (ADC);
}*/