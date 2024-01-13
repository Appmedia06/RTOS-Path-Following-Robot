/*
*========================================================================================================
*
* File    : 4B_LCD.h
* Version : V3.0
* Modified
* On	  : 20220223
* By      : Kuo-Yang Tu
*
*========================================================================================================
*/
#ifndef _4B_LCD_H_
#define _4B_LCD_H_

#include <inttypes.h>

void OpenLCD(void);

void WriteCmdLCD( uint8_t LCD_CMD);

void WriteDataLCD( uint8_t LCD_CMD);

void putcLCD(uint8_t LCD_Char);

void LCD_CMD_W_Timing( void );

void LCD_DAT_W_Timing( void );

void LCD_Set_Cursor(uint8_t CurY, uint8_t CurX);

//void putrsLCD( const rom char *Str );

void putsLCD(const char *Str);

void puthexLCD(uint16_t HEX_Val);

void LCD_L_Delay(void);

void LCD_S_Delay(void);

void LCD_CLR(void);

void putsi(int val,uint8_t field_length);

#endif	/* _4B_LCD_H_ */
