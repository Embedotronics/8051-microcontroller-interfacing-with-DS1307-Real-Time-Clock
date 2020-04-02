// the #ifndef prevents the file from being included more than once
#ifndef __DELAY_H__   
#define __DELAY_H__
 
void delay_us(unsigned int us_count);
void delay_ms(unsigned int ms_count);
void delay_sec(unsigned char sec_count);
 
#endif