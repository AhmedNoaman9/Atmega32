#include "USART.h"

//// THIS USART CONFIGURATION WORKS FOR CHARACTER SIZE OF 8 BITS
//// SPECIFICLLY MADE FOR THE ATM APPLICATION 

uint8* ptr_to_val=0;

// first part of initialization :enter baud rate, and choose asynchronous or not and the speed mode from their enums 
void USART_init(uint32 baud_rate, SYNCH_MODE synch_mode, SPEED_MODE speed_mode )  
{
	UCSRC|=(1<<URSEL);
	UCSRC|= (synch_mode<<UMSEL);
	UCSRA|= (speed_mode<<U2X);
	
	uint32 UBRR_value=0;
	if(synch_mode==synchronous)
	{
		UBRR_value= (uint32) ((FOSC/(2UL*baud_rate))-1);
	}
	else if(synch_mode==asynchronous && speed_mode==normal_speed)
	{
		UBRR_value= (uint32) ((FOSC/(16UL*baud_rate))-1);
	}
	else if(synch_mode==asynchronous && speed_mode==double_speed)
	{
		UBRR_value= (uint32) ((FOSC/(8UL*baud_rate))-1);
	}
	
	UCSRC|=(0<<URSEL);
	UBRRH|=(uint8) (UBRR_value>>8);
	UBRRL|=(uint8) (UBRR_value);
}

// Second part of initialization : make 1st argument (size_8_bits), choose parity and number of stop bits from their enums
void USART_frame(CHAR_SIZE char_size, PARITY_MODE parity_mode, STOP_BITS stop_bits)
{
	UCSRC|= (1<<URSEL);
	UCSRC|= parity_mode<<UPM0;
	UCSRC|= stop_bits<<USBS;
	if(char_size != size_9_bits)
	{
		UCSRC|= (char_size<<UCSZ0);
	}
	else if(char_size == size_9_bits)
	{
		UCSRC|= ((char_size<<UCSZ0) & (~(1<<3)));
		UCSRB|= (1<<UCSZ2);
	}
}

// Third part of initialization
void USART_TX_RX(TRANSMIT_STATE transmit_state, TRANSMIT_INTERRUPT transmit_interrupt, RECEIVE_STATE receive_state, RECEIVE_INTERRUPT receive_interrupt)
{
	UCSRB|=(transmit_state<<TXEN);
	UCSRB|=(transmit_interrupt<<TXCIE);
	UCSRB|=(receive_state<<RXEN);
	UCSRB|=(receive_interrupt<<RXCIE);
}

void USART_transmit(uint8 data)
{
	while( !(UCSRA &(1<<UDRE)));
	UDR=  data;
}

uint8 USART_receive()
{
	while(!(UCSRA &(1<<RXC)));
	
	if( (UCSRA&(1<<PE)) ==0)
	{
		*ptr_to_val= UDR;
	}
	return *ptr_to_val;
}

void transmit_string (char* string_array)
{
	uint8 counter=0;
	while(string_array[counter] != 0)
	{
		USART_transmit(string_array[counter]);
		counter++;
	}
	
}

void receive_string(char* string_array)
{
	uint8 counter=0;
	while(USART_receive() != 0xD)
	{
		string_array[counter]= *ptr_to_val;
		counter++;
	}
	string_array[counter]=0;
}

void credit_card_programming(char* card_holder_name,char* PAN,char* PIN) //declare and define 3 arrays before using it in the main code, use them later to get the data
{
	volatile uint8 error =1;
	char admin_pass[6];
	while(error ==1)
	{
		receive_string(admin_pass); //Write on terminal "ADMIN" to exit this loop and start the card programming
		if((admin_pass[0] != 'A') |(admin_pass[1] != 'D') |(admin_pass[2] != 'M') |(admin_pass[3] != 'I') |(admin_pass[4] != 'N'))
		{
			transmit_string("Enter correct password for card programming ");
		}
		else {error =0;}
	}
	transmit_string("Card holder name: ");
	receive_string(card_holder_name);
	transmit_string("PAN: ");
	receive_string(PAN);
	transmit_string("PIN: ");
	receive_string(PIN);
}

