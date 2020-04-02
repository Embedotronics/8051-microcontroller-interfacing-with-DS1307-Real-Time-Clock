// the #ifndef prevents the file from being included more than once
#ifndef __LCD_H__   
#define __LCD_H__
 
void lcd_Init();
void lcd_WriteCmd( char cmd);
void lcd_Writedata( char a);
void lcd_DisplayString(char *string_ptr);
void lcd_DisplayNumber(unsigned int num);
void lcd_ScrollMessage(char *msg_ptr);
void lcd_DisplayRtcTime(char hour,char min,char sec);
void lcd_DisplayRtcDate(char day,char month,char year);
void lcd_Clear();
void lcd_GoToLineOne();
void lcd_GoToLineTwo();
void lcd_GoToXY(char row, char col);
 
#endif 