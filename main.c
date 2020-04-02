#include <reg51.h> 
#include "lcd.h"  	 
#include "ds1307.h" 
#include "i2c.h"
#include "delay.h"
 
/* main program */
void main() 
{
   unsigned char sec,min,hour,day,month,year;
 
  /* Initilize the lcd */
    lcd_Init();
 
  /* Initilize the RTC(ds1307)*/
    ds1307_Init();
 
 
  /*set the time and Date only once */
  ds1307_SetTime(0x23,0x59,0x30);  //  
  ds1307_SetDate(0x31,0x12,0x19);  //  
 
  /* Display "time" on first line*/
  lcd_DisplayString("Time: ");
 
   /* Display "date" on Second line*/
  lcd_GoToLineTwo();
  lcd_DisplayString("Date: ");
 
   /* Display the Time and Date continously */ 
   while(1)
    {
	   /* Read the Time from RTC(ds1307) */ 
        ds1307_GetTime(&hour,&min,&sec);        
 
		/* Display the time on firstline 7th position*/
 
         lcd_GoToXY(0,6); 		 
         lcd_DisplayRtcTime(hour,min,sec);
 
 
	    /* Read the Date from RTC(ds1307) */ 
        ds1307_GetDate(&day,&month,&year);        
 
		/* Display the Date on secondline 7th position*/
         lcd_GoToXY(1,6); 		 
         lcd_DisplayRtcDate(day,month,year);
     }
}