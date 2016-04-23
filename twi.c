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
	EICRA=0X02;				//INT0�͵�ƽ����
	EIMSK=0X01;				//ʹ��INT0
	EIFR=0X01;
	SREG=0X80;				//ʹ��ȫ���ж�
	PORTD&=~0X04;*/
}

uchar twi_write(uchar W_ADDRESS,uchar W_DATA)
{
	START();										//TWI����
	WAIT();
	if(SATUS()!=_START)
	return TRUE;
	
	TWI_WRITE(W_MPU6050_ADDR);						//дMPU6050��ַ
	WAIT();
	if(SATUS()!=MT_SLA_ACK)
	return TRUE;
	
	TWI_WRITE(W_ADDRESS);     	                   //д6050��Ӧ�Ĵ�����ַ
    WAIT();
    if(SATUS()!=MT_DATA_ACK) 
	return TRUE;
	
	TWI_WRITE(W_DATA);						        //д���ݵ� 6050��Ӧ�Ĵ���
	WAIT();
	if(SATUS()!=MT_DATA_ACK)
	return TRUE;
	
	STOP();											//TWIֹͣ
	delay_nms(10);
	return FALSE;
	
}


uchar twi_read(uchar W_ADDRESS)
{
  	uchar temp;
	START();	   			  	   //TWI����
	WAIT();
    if (SATUS()!=_START) 
	return TRUE;      
    
    TWI_WRITE(W_MPU6050_ADDR); //д MPU6050��ַ��д��ʽ
    WAIT(); 
    if (SATUS()!=MT_SLA_ACK) 
	return TRUE;    
    
   	TWI_WRITE(W_ADDRESS);      //д MPU6050��Ӧ�Ĵ�����ַ
    WAIT();
    if (SATUS()!=MT_DATA_ACK) 
	return TRUE;
    
    START();            	       //TWI��������
    WAIT();
    if (SATUS()!=RE_START)  
	return TRUE;
    
    TWI_WRITE(R_MPU6050_ADDR); //д MPU6050��ַ�Ͷ���ʽ
    WAIT();
    if(SATUS()!=MR_SLA_ACK)  
	return TRUE;      
    
    TWI_READ();          	   //������TWI����ʽ
    WAIT();
    if(SATUS()!=MR_DATA_NOACK)//����һ����ֹͣ�������� ���������յ����ٽ���Ӧ���ź� ������������յ�Ӧ���ź�
	return TRUE;			  //˵��������������������Ϊ����	 													 																		 
     
    
    temp=TWDR;        		   //��ȡ TWI��������
    STOP();         		   //TWIֹͣ
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

