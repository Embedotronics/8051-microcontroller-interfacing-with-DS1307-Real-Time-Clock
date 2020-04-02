#include<reg51.h>
#include "delay.h"
#include "i2c.h"
 
sbit SCL=P0^0;      //SCL Connected to P0.0
sbit SDA=P0^1;      //SDA Connected to P0.1
 
 
void i2c_Clock(void)
{
    delay_us(50);
    SCL = 1;        
 
    delay_us(50);        
    SCL = 0;        
}
 
  
void i2c_Start()
{
    SCL = 0;        // pull SCL low
 
    SDA = 1;        // pull SDA High
    delay_us(50);
 
    SCL = 1;        //pull SCL high
    delay_us(50);
 
    SDA = 0;        //Now pull SDA LOW, to generate the Start Condition
    delay_us(50);
 
    SCL = 0;        //Finally Clear the SCL to complete the cycle
}

 
void i2c_Stop(void)
{
    SCL = 0;            // pull SCL low
    delay_us(50);
 
    SDA = 0;            // pull SDA  low
    delay_us(50);
 
    SCL = 1;            // pull SCL High
    delay_us(50);
 
    SDA = 1;            // Now pull SDA High, to generate the Stop Condition
}

void i2c_Write(unsigned char dat)
{
    unsigned char i;
 
    for(i=0;i<8;i++)         
     {
        SDA = dat & 0x80;    
        i2c_Clock();         
        dat = dat<<1;
      }
        SDA = 1;                 
}

unsigned char i2c_Read(void)
{
    unsigned char i, dat=0x00;
 
       SDA=1;               
    for(i=0;i<8;i++)       
     {
       delay_us(50);
        SCL = 1;           
        delay_us(50);
 
        dat = dat<<1;       
        dat = dat | SDA;    
 
        SCL = 0;            
       }
   return dat;             
}

void i2c_Ack()
{
    SDA = 0;        
    i2c_Clock();    
    SDA = 1;        
}

void i2c_NoAck()
{
    SDA = 1;        
   i2c_Clock();     
    SCL = 1;     
}
