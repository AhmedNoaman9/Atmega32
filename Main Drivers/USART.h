#ifndef USART_H_
#define USART_H_

#include "GPIO.h"

#define FOSC 1000000  //DEFINE THE MICROCONTROLLER FREQUENCY 

//UCSRA PINS
#define MPCM 0
#define U2X 1
#define PE 2
#define DOR 3
#define FE 4
#define UDRE 5
#define TXC 6
#define RXC 7

//UCSRB PINS
#define TXB8 0
#define RXB8 1
#define UCSZ2 2
#define TXEN 3
#define RXEN 4
#define UDRIE 5
#define TXCIE 6
#define RXCIE 7

//UCSRC PINS
#define UCPOL 0
#define UCSZ0 1
#define UCSZ1 2
#define USBS 3
#define UPM0 4
#define UPM1 5
#define UMSEL 6
#define URSEL 7

#define UBRRH *((volatile uint8 *) (0x40))
#define UBRRL *((volatile uint8 *) (0x29))
#define UDR *((volatile uint8 *) (0x2C))
#define UCSRA *((volatile uint8 *) (0x2B))
#define UCSRB *((volatile uint8 *) (0x2A))
#define UCSRC *((volatile uint8 *) (0x40))

typedef enum SYNCH_MODE
{
	asynchronous,
	synchronous
}SYNCH_MODE;

typedef enum SPEED_MODE
{
	normal_speed,
	double_speed
}SPEED_MODE;

typedef enum TRANSMIT_STATE
{
	disable_transmit,
	enable_transmit
}TRANSMIT_STATE;

typedef enum RECEIVE_STATE
{
	disable_receive,
	enable_receive
}RECEIVE_STATE;

typedef enum CHAR_SIZE
{
	size_5_bits=0,
	size_6_bits=1,
	size_7_bits=2,
	size_8_bits=3,
	size_9_bits=7
}CHAR_SIZE;

typedef enum PARITY_MODE
{
	no_parity=0,
	even_parity=2,
	odd_parity=3
}PARITY_MODE;

typedef enum STOP_BITS
{
	stop_1_bit,
	stop_2_bits
}STOP_BITS;

typedef enum TRANSMIT_INTERRUPT
{
	transmit_interrupt_disable,
	transmit_interrupt_enable
}TRANSMIT_INTERRUPT;

typedef enum RECEIVE_INTERRUPT
{
	reveive_interrupt_disable,
	receive_interrupt_enable
}RECEIVE_INTERRUPT;

void USART_init(uint32 baud_rate, SYNCH_MODE synch_mode, SPEED_MODE speed_mode );
void USART_frame(CHAR_SIZE char_size, PARITY_MODE parity_mode, STOP_BITS stop_bits);
void USART_TX_RX(TRANSMIT_STATE transmit_state, TRANSMIT_INTERRUPT transmit_interrupt, RECEIVE_STATE receive_state, RECEIVE_INTERRUPT receive_interrupt);
void USART_transmit(uint8 data);
uint8 USART_receive();
void transmit_string (char* string_array);
void receive_string(char* string_array);
void credit_card_programming(char* card_holder_name,char* PAN,char* PIN);
#endif /* USART_H_ */