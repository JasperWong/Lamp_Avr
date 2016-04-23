#include"twi.h"

//int change[5];

void twi_init(void)
{
	TWCR=0X00;
	TWBR=0X0F;
    TWSR=0X00;
	TWAR=0X00;
	TWCR=(1<<TWEN);
	//DDRC|=0X10;
	//TWCR=0x94;
	/*DDRD|=0X04;
	PORTD|=0X04;
	EICRA=0X02;				//INT0低电平触发
	EIMSK=0X01;				//使能INT0
	EIFR=0X01;
	SREG=0X80;				//使能全局中断
	PORTD&=~0X04;*/
}

uchar twi_write(uchar W_ADDRESS,uchar W_DATA)
{
	START();										//TWI启动
	WAIT();
	if(SATUS()!=_START)
	return TRUE;
	
	TWI_WRITE(W_MPU6050_ADDR);						//写MPU6050地址
	WAIT();
	if(SATUS()!=MT_SLA_ACK)
	return TRUE;
	
	TWI_WRITE(W_ADDRESS);     	                   //写6050相应寄存器地址
    WAIT();
    if(SATUS()!=MT_DATA_ACK) 
	return TRUE;
	
	TWI_WRITE(W_DATA);						        //写数据到 6050相应寄存器
	WAIT();
	if(SATUS()!=MT_DATA_ACK)
	return TRUE;
	
	STOP();											//TWI停止
	delay_nms(10);
	return FALSE;
	
}


uchar twi_read(uchar W_ADDRESS)
{
  	uchar temp;
	START();	   			  	   //TWI启动
	WAIT();
    if (SATUS()!=_START) 
	return TRUE;      
    
    TWI_WRITE(W_MPU6050_ADDR); //写 MPU6050地址和写方式
    WAIT(); 
    if (SATUS()!=MT_SLA_ACK) 
	return TRUE;    
    
   	TWI_WRITE(W_ADDRESS);      //写 MPU6050相应寄存器地址
    WAIT();
    if (SATUS()!=MT_DATA_ACK) 
	return TRUE;
    
    START();            	       //TWI重新启动
    WAIT();
    if (SATUS()!=RE_START)  
	return TRUE;
    
    TWI_WRITE(R_MPU6050_ADDR); //写 MPU6050地址和读方式
    WAIT();
    if(SATUS()!=MR_SLA_ACK)  
	return TRUE;      
    
    TWI_READ();          	   //启动主TWI读方式
    WAIT();
    if(SATUS()!=MR_DATA_NOACK)//读完一个数停止接收数据 ，主机接收到不再接收应答信号 ，如果继续接收到应答信号
	return TRUE;			  //说明主机继续接收数据则为错误	 													 																		 
     
    
    temp=TWDR;        		   //读取 TWI接收数据
    STOP();         		   //TWI停止
    return temp;
}

/*#pragma interrupt_handler intter_flag:2
void intter_flag(void)
{
	lcd_change(change,Get_data(ACCEL_XOUT_H));	 
	LCD_write_string(0,0,change);
	lcd_change(change,Get_data(ACCEL_YOUT_H));	 
	LCD_write_string(5,0,change);
	lcd_change(change,Get_data(ACCEL_ZOUT_H));	 
	LCD_write_string(10,0,change);
	lcd_change(change,Get_data(GYRO_XOUT_H));	 
	LCD_write_string(0,1,change);
	lcd_change(change,Get_data(GYRO_YOUT_H));	 
	LCD_write_string(5,1,change);
	lcd_change(change,twi_read(WHO_AM_I));	 
	LCD_write_string(10,1,change);
	delay_nms(100);
}*/
/*void main(void)
{
	uchar temp;
	uchar read;
	
	twi_init();
	twi_write(24,0);
	read=twi_read(0);
	if(read==24)
	{
		DDRB|=0X01;
		PORTB&=~0X01;
	}
	
	while(1);
}*/

