/*
 * LCD.c
 *
 * Created: 10-Feb-23
 *  Author: NO3M4N
 */ 


#include "../../LIB/Std_types.h"
#include "../../LIB/Bit_math.h"

#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/Delay.h"

#include "LCD.h"
#include "LCD_Cfg.h"


LCD_enuErrorStatus LCD_enuSendCommand(u8 Copy_u8Command )
{
	//u8 Loc_u8Counter;
	DIO_enuWritePort(LCD_Data_Port,Copy_u8Command);
// 	for(Loc_u8Counter =0; Loc_u8Counter < 8; Loc_u8Counter++)
// 	{
// 		
// 		
// 	}
	DIO_enuClearPin(LCD_CfgStr[LCD1].LCD_enuCmdPins[RS]);	//LCD_Command_Port &= ~(1<<RS);	/* RS=0 command reg. */
	DIO_enuClearPin(LCD_CfgStr[LCD1].LCD_enuCmdPins[RW]);	//LCD_Command_Port &= ~(1<<RW);	/* RW=0 Write operation */
	DIO_enuSetPin(LCD_CfgStr[LCD1].LCD_enuCmdPins[EN]);		//LCD_Command_Port |= (1<<EN);	/* Enable pulse */
	Delay_ms(1);
	DIO_enuClearPin(LCD_CfgStr[LCD1].LCD_enuCmdPins[EN]);	//LCD_Command_Port &= ~(1<<EN);
	Delay_ms(2);
	
	return LCD_OK;
}


LCD_enuErrorStatus LCD_enuSendData(u8 Copy_u8Data)
{
	DIO_enuWritePort(LCD_Data_Port,Copy_u8Data);	//LCD_Data_Port= char_data;
	DIO_enuSetPin(LCD_CfgStr[LCD1].LCD_enuCmdPins[RS]);	//LCD_Command_Port |= (1<<RS);	/* RS=1 Data reg. */
	DIO_enuClearPin(LCD_CfgStr[LCD1].LCD_enuCmdPins[RW]);	//LCD_Command_Port &= ~(1<<RW);	/* RW=0 write operation */
	DIO_enuSetPin(LCD_CfgStr[LCD1].LCD_enuCmdPins[EN]);	//LCD_Command_Port |= (1<<EN);	/* Enable Pulse */
	Delay_ms(1);
	DIO_enuClearPin(LCD_CfgStr[LCD1].LCD_enuCmdPins[EN]); //LCD_Command_Port &= ~(1<<EN);
	Delay_ms(2);			/* Data write delay */

	return LCD_OK;	
}



LCD_enuErrorStatus	LCD_enuGotoXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	LCD_enuErrorStatus Loc_ErrorStatus = LCD_OK;
	if (Copy_u8YPos== 0 && Copy_u8XPos<16)
	{
		LCD_enuSendCommand((Copy_u8XPos & 0x0F)|0x80);	/* Command of first row and required position<16 */
	}
	else if (Copy_u8YPos == 1 && Copy_u8XPos<16)
	{
		LCD_enuSendCommand((Copy_u8XPos & 0x0F)|0xC0);	/* Command of first row and required position<16 */		
	}
	else{
		Loc_ErrorStatus = LCD_NOK;
	}
	return Loc_ErrorStatus;
	
}

LCD_enuErrorStatus LCD_enuWriteString (u8* Copy_pchString)
{
	u8 Loc_u8Counter;
	for(Loc_u8Counter=0; Copy_pchString[Loc_u8Counter]!=0 ; Loc_u8Counter++)		/* Send each char of string till the NULL */
	{
		LCD_enuSendData(Copy_pchString[Loc_u8Counter]);
	}
	return LCD_OK;
}


LCD_enuErrorStatus LCD_enuWriteNumber (u16 Copy_u16Number)
{
	u8	Loc_u8Int2Str[5];
	u16 Loc_u16NumCheck;	
	u8	Loc_u8Remainder;
	u8	Loc_u8NumCounter =0 ;
	u8	Loc_u8LoopCounter =0 ;
	
	// Count Digits
	Loc_u16NumCheck = Copy_u16Number;
	while(Loc_u16NumCheck != 0){
		Loc_u8NumCounter++;
		Loc_u16NumCheck /= 10;
	}
	for(Loc_u8LoopCounter = 0 ; Loc_u8LoopCounter < Loc_u8NumCounter; Loc_u8LoopCounter++)
	{
		Loc_u8Remainder = Copy_u16Number % 10;
		Loc_u8Int2Str[Loc_u8NumCounter - ( 1+ Loc_u8LoopCounter)] = Loc_u8Remainder +'0';
		Copy_u16Number /= 10;
		
	}
	Loc_u8Int2Str[Loc_u8NumCounter] = '\0';
	
	LCD_enuWriteString(Loc_u8Int2Str);
	return LCD_OK;
}



LCD_enuErrorStatus LCD_enuWriteSpecialPattern  (u8* Copy_pu8Pattern, u8 Copy_u8BlockNum)
{
	u8 Loc_Counter;
	//LCD_enuGotoXY(Copy_u8XPos,Copy_u8YPos);
	if(Copy_u8BlockNum<8)
	{
		LCD_enuSendCommand(0x40 + (Copy_u8BlockNum*8));	/* Command 0x40 and onwards forces the device to point CGRAM address */
		for(Loc_Counter=0; Loc_Counter < 8; Loc_Counter++)	/* Write 8 byte for generation of 1 character */
			LCD_enuSendData(Copy_pu8Pattern[Loc_Counter]);
	}
	
		return LCD_OK;
	
}

void LCD_vidInit(){
	
	LCD_enuSendCommand (0x38);		/* Initialization of 16X2 LCD in 8bit mode */
	LCD_enuSendCommand (0x0C);		/* Display ON Cursor OFF */
	LCD_enuSendCommand (0x06);		/* Auto Increment cursor */
	LCD_enuSendCommand (0x01);		/* clear display */
	Delay_ms(2);			/* Clear display command delay> 1.63 ms */
	LCD_enuSendCommand (0x80);		/* Cursor at home position */
	
	
}


void LCD_Clear()
{
	LCD_enuSendCommand (0x01);		/* clear display */
	LCD_enuSendCommand (0x80);		/* cursor at home position */
}