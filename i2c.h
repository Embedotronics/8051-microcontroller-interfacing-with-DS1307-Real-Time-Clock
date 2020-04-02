// the #ifndef prevents the file from being included more than once
#ifndef __I2C_H__   
#define __I2C_H__
 
void i2c_Clock(void);
void i2c_Start();
void i2c_Stop(void);
void i2c_Write(unsigned char );
unsigned char i2c_Read(void);
void i2c_Ack();
void i2c_NoAck();
 
#endif