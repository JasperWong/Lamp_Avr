#include"iom16v.h"
#include"twi.h"
#include"delay.h"
#include"MPU_6050.h"
#include"sent.h"
#include"usart.h"

void main(void)
{
	int AX;
	int AY;
	twi_init();
	delay_nms(50);
	MPU_6050_init();
	delay_nms(500);
	Usart_init();
	//hc05_init();
	while(1)
	{
		delay_nms(50000);
		AX=Get_data(ACCEL_XOUT_H)/187.62;
		AY=Get_data(ACCEL_YOUT_H)/187.62;
		
		if(AY<86)
		{
			USART_Transmit('1');
			//UCSRB=0X90;        	//�ط���ʹ��
		}
		
		else 
		{
			USART_Transmit('0');
		}
		/*else
		{
			sent('2');
			//UCSRB=0X90;			//�ط���ʹ��
			if(AX<45 || AY<45)
			{
				UCSRB=0X98;		//�򿪷���ʹ��
			}
		}*/
		
	}
	
}