/*
 * LCD.c
 *
 * Created: 9/3/2020 1:49:59 PM
 *  Author: ahmed
 */ 
#include "lcd.h"

#include "GPIO.h"


void lcd_init(){
	(*(volatile uint8*) (data_pin+1))=0xFF;
	(*(volatile uint8*)(command_pin+1))=0x0F;
	(*(volatile uint8*) (data_pin+2))=0x00;
	(*(volatile uint8*) (command_pin+2))&=~(1<<E);
	if (mod==8)
	{
		_delay_ms(2000);
		lcd_command(0x38);
	}
	else if (mod == 4)
	{
		lcd_command(0x33);
		lcd_command(0x32);
		lcd_command(0x28);
	}
	lcd_command(0x0e);
	lcd_command(0x01);
	_delay_ms(2000);
	lcd_command(0x06);
	lcd_command(LCD_DISP_ON_CURSOR);
}

void lcd_command(uint8 cmd){
	
	if (mod ==8)
	{
	
	(*(volatile uint8* )(command_pin+2))&=~(1<<Rs);
	}
	
	 else if (mod==4)
	{
		(*(volatile uint8* )(data_pin+2)) =cmd & 0xf0; 
		(*(volatile uint8* )(command_pin+2))|=(1<<E);
		_delay_ms(1);
		(*(volatile uint8* )(command_pin+2))&=~(1<<E);
		_delay_us(100);
		(*(volatile uint8* )(data_pin+2))= cmd<<4;
	}
	(*(volatile uint8* )(command_pin+2))|=(1<<E);
	_delay_ms(1);
	(*(volatile uint8* )(command_pin+2))&=~(1<<E);
	_delay_us(100);
}


void lcdout(uint8 value){
	(*(volatile uint8*)(command_pin+2))|= (1<<Rs);
	if (mod==8)
	{
		(*(volatile uint8*)(data_pin+2))=value;
	}
	 else if(mod==4){
		(*(volatile uint8*)(data_pin+2))=value&0xf0;
		(*(volatile uint8*)(command_pin+2))|=(1<<Rs);
		(*(volatile uint8*)(command_pin+2))|=(1<<E);
		_delay_ms(1);
		(*(volatile uint8*)(command_pin+2))&=~(1<<E);
		_delay_us(100);
		(*(volatile uint8*)(data_pin+2))=(value<<4);
	}
(*(volatile uint8*)(command_pin+2))|=(1<<E);
_delay_us(1);
(*(volatile uint8*)(command_pin+2))&=~(1<<E);
_delay_us(100);

}


void lcdprint(uint8 *str){
	uint8 i=0;
	while (str[i]!=0)
	{
		lcdout(str[i]);
		i++;
	}
}