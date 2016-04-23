#include"sent.h"

void hc05_init(void)
{
	UCSRA=0X02;		//倍速模式
	UCSRB=0X00;		//清空寄存器
	UCSRC=(1<<URSEL)|(0<<UPM0)|(3<<UCSZ0);
	//UCSRC=0X06;		//异步 一位停止 八位数据  禁止校验
	UBRRL=12; 			//波特率9600			
	UBRRH=0X00;			//清空寄存器
	UCSRB=(1<<TXEN)|(1<<RXEN)|(1<<RXCIE) ;	//发送使能  接收使能 接收结束中断使能  UCSRB 0X98  0X90
	SREG=0X80;			//全局中断使能
	DDRD&=~0X01;		//RX设置为输入
	//PORTD|=0X01;		
	DDRD|=0X02;			//TX设置为输出
}

void sent(uchar data)
{
	while ( !( UCSRA & (1<<UDRE)) );		//等待发送缓冲器为空
	UDR=data;
	while ( !( UCSRA & (1<<TXC)) );		//检测数据是否清零
	UCSRA|=TXC;							//清空数据
}



