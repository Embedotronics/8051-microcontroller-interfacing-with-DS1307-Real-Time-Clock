
 
#include<reg51.h>
#include "delay.h" 
 
void delay_us(unsigned int us_count)
 {  
    while(us_count!=0)
      {
         us_count--;
       }
   }