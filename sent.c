#include"sent.h"

void hc05_init(void)
{
	UCSRA=0X02;		//����ģʽ
	UCSRB=0X00;		//��ռĴ���
	UCSRC=(1<<URSEL)|(0<<UPM0)|(3<<UCSZ0);
	//UCSRC=0X06;		//�첽 һλֹͣ ��λ����  ��ֹУ��
	UBRRL=12; 			//������9600			
	UBRRH=0X00;			//��ռĴ���
	UCSRB=(1<<TXEN)|(1<<RXEN)|(1<<RXCIE) ;	//����ʹ��  ����ʹ�� ���ս����ж�ʹ��  UCSRB 0X98  0X90
	SREG=0X80;			//ȫ���ж�ʹ��
	DDRD&=~0X01;		//RX����Ϊ����
	//PORTD|=0X01;		
	DDRD|=0X02;			//TX����Ϊ���
}

void sent(uchar data)
{
	while ( !( UCSRA & (1<<UDRE)) );		//�ȴ����ͻ�����Ϊ��
	UDR=data;
	while ( !( UCSRA & (1<<TXC)) );		//��������Ƿ�����
	UCSRA|=TXC;							//�������
}



