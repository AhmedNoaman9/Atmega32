/*
 * Keypad.c
 *
 * Created: 9/1/2020 12:56:54 PM
 *  Author: ahmed
 */ 
#include "GPIO.h"
#include "Keypad.h"
//unsigned char*  GPIO_ports[];

#define C0 0
#define C1 1
#define C2 2
#define C3 3
#define R0 7
#define R1 6
#define R2 5
#define R3 4


void keypad_init(){
 pinMode('A',0,u8_Direction_input);
 pinMode('A',1,u8_Direction_input);
 pinMode('A',2,u8_Direction_input);
 pinMode('A',3,u8_Direction_input);

pinMode('A',4,OUTPUT);
pinMode('A',5,OUTPUT);
pinMode('A',6,OUTPUT);
pinMode('A',7,OUTPUT);
/*GPIO_digitalWrite(0,HIGH,'A');
GPIO_digitalWrite(1,HIGH,'A');
GPIO_digitalWrite(2,HIGH,'A');
GPIO_digitalWrite(3,HIGH,'A');
GPIO_digitalWrite(4,HIGH,'A');
GPIO_digitalWrite(5,HIGH,'A');
GPIO_digitalWrite(6,HIGH,'A');
GPIO_digitalWrite(7,HIGH,'A');*/

writeportval(0xFF,'A');
//*GPIO_ports[Get_port_index('a')]= 0XFF;


//uint8_t col[]= {a,b,c,d};
//uint8_t col[]={
}


uint8 keyPressed(){
int i , j;
uint8 read;	
	
	for( i =4; i< 8; i++){
		//uint8_t x = GPIO_readportval('D');
		digitalWrite('A',R3,HIGH);
		digitalWrite('A',R2,HIGH);
		digitalWrite('A',R1,HIGH);
		digitalWrite('A',R0,HIGH);
		digitalWrite('A',i,LOW);
	//GPIO_digitalWrite(3,LOW,'B');
for(j=0 ; j<4; j++){
	
	read=pinRead(j,'A');
		
	if (read==0){
		while (pinRead(j,'A')==0);
	
			switch(i)
			{
				case 4:
				{
					if (j == 3) return '7';
					else if (j == 2) return '4';
					else if (j == 1) return '1';
					else if (j == 0) return '.';
					break;
				}
				case 5:
				{
					if (j == 3) return '8';
					else if (j == 2) return '5';
					else if (j == 1) return '2';
					else if (j == 0) return '0';
					break;
				}
				case 6:
				{
					if (j == 3) return '9';
					else if (j == 2) return '6';
					else if (j == 1) return '3';
					else if (j == 0) return '=';
					break;
				}
				case 7:
				{
					if (j == 3) return '/';
					else if (j == 2) return '*';
					else if (j == 1) return '-';
					else if (j == 0) return '+';
					break;
				}
			}
			
		}
		
	}
}
	return 0;
}





				