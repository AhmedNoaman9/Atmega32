/*
 * LCD.h
 *
 * Created: 10-Feb-23 
 *  Author: NO3M4Ns
 */ 


#ifndef LCD_H_
#define LCD_H_



typedef enum{
	
	LCD_OK,
	LCD_NOK,
	LCD_BUSY
	
	
	}LCD_enuErrorStatus ;


typedef struct {
	
	DIO_tenuPins LCD_enuDataPins[8];
	DIO_tenuPins LCD_enuCmdPins[3];
	
}LCD_strCfg_t;


/*
		
	

*/


LCD_enuErrorStatus LCD_enuSendData		(u8 Copy_u8Data);
LCD_enuErrorStatus LCD_enuSendCommand	(u8 Copy_u8Command);
LCD_enuErrorStatus LCD_enuGotoXY		(u8 Copy_u8XPos, u8 Copy_u8YPos);
LCD_enuErrorStatus LCD_enuWriteSpecialPattern  (u8* Copy_pu8Pattern, u8 Copy_u8BlockNum);

LCD_enuErrorStatus LCD_enuWriteString (u8* Copy_pchString);
LCD_enuErrorStatus LCD_enuWriteNumber (u16 Copy_u16Number);

void			   LCD_vidInit(void);


void LCD_Clear();

#endif /* LCD_H_ */