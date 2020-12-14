/*
 * GPIO.c
 *
 * Created: 9/1/2020 12:31:04 PM
 *  Author: ahmed
 */ 
#include "GPIO.h"
#include "lcd.h"

volatile unsigned char*  GPIO_ports[]= {myPORTA,myPORTB,myPORTC,myPORTD};
volatile unsigned char*  GPIO_dirs[] = {myDDRA,myDDRB,myDDRC,myDDRD};
volatile unsigned char*  GPIO_pins[] = {myPINA,myPINB,myPINC,myPIND};

uint8 Get_port_index(uint8 portname){
	
	uint8 i=0;
	
	switch (portname)
	{
		
		case'A':
		case 'a':
		i=0;
		break;

		case 'B':
		case 'b':
		i=1;
		break;

		case 'C':
		case 'c':
		i=2;
		break;

		case 'D':
		case 'd':
		i=3;
		break;
		

	}
	return i;
}


void GPIO_pinit(void)		//initilization -
{
	GPIO_dirs[0]=Init_direction_default;
	GPIO_dirs[1]=Init_direction_default;
	GPIO_dirs[2]=Init_direction_default;
	GPIO_dirs[3]=Init_direction_default;
}
void set(uint8_t reg,uint8_t bit){
	reg |= 1<<bit;
}
void clear(uint8_t reg,uint8_t bit){
reg &= ~(1<<bit);
}

void digitalWrite(uint8_t portname, uint8_t pinindex,uint8_t pinval){
//	uint8_t status;
	
	
		switch(pinval){
			case 1:
			*GPIO_ports[Get_port_index(portname)] |= 1<<pinindex;    // set pin
			//status =No_error;
			break;
			
			case 0:
			*GPIO_ports[Get_port_index(portname)] &= ~( 1<<(pinindex));
			//status =No_error;
			break;
			
		//	default:
	//		status= error_happen;
			
		}
	
	
	
}

void pinMode(uint8_t portname,uint8_t pinindex,uint8_t pindir){
	
	
	
	
		switch(pindir){
			case OUTPUT:
			*GPIO_dirs[Get_port_index(portname)] |= 1<< pinindex;
		//	status = No_error;
			break;
			
			case INPUT:
			*GPIO_dirs[Get_port_index(portname)] &= ~(1<< pinindex);
			//status = No_error;
			break;
			
		}
	
}

uint8_t pinRead(uint8_t PinIdx, uint8_t portname)
{
	uint8_t API_Status ;
	//uint8_t *PtrToVal; 
	
	

		API_Status =  ((*GPIO_pins [ Get_port_index(portname) ]) >>PinIdx) & 1 ;
		//API_Status = *PtrToVal;
	if (API_Status ==0)
	return 0;
	else return 1;

	

}



////////////////////////////////PORTs
uint8_t writeportval(uint8_t portval,uint8_t portname){
	*GPIO_ports[Get_port_index(portname)]= portval;
	return No_error;
}

uint8_t writeportdir(uint8_t portdir,uint8_t portname){
	*GPIO_dirs[Get_port_index(portname)]= portdir;
	return No_error;
}
uint8_t readportval(  uint8_t Port_Name)
{
uint8_t *PtrToVal= 0;

	*PtrToVal =  *GPIO_pins [ Get_port_index(Port_Name) ] ;

	return *PtrToVal;

}

uint8_t readportdir( uint8_t Port_Name)
{
uint8_t	*PtrToDir =0;  
*PtrToDir =*GPIO_dirs[ Get_port_index(Port_Name) ] ;

	return *PtrToDir ;


}

/*#define ISR(vector, ...)\
void vector(void) _attribute_ ((signal,used,externally_visible)) _VA_ARGS_;\
void vector(void)*/



/*uint8_t pin_read (uint8_t port, uint8_t pin)
{
	uint8_t value;
	value =(*((volatile uint8_t*)(port))>>pin )&1;
	if (value ==0)
	return 0;
	else return 1;
}

uint8_t pinread(uint8_t port, uint8_t pin){ 
uint8_t value;
switch (port)
{
case A:
value = ((*myPORTA)>>pin) &1;
if (value ==0)
return 0;
else return 1;
break;
case B:
value = ((*myPORTB)>>pin) &1;
if (value ==0)
return 0;
else return 1;
break;
case C:
value = ((*myPORTC)>>pin) &1;
if (value ==0)
return 0;
else return 1;
break;
case D:
value = ((*myPORTD)>>pin) &1;
if (value ==0)
return 0;
else return 1;
break;

}
}*/