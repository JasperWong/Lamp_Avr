#include <iom16v.h>
#include <macros.h>
#include "usart.h"

#define uchar unsigned char
#define uint  unsigned int

void Usart_init(void)
{
 	UCSRB = 0x00; 					       //关串口
 	UCSRA = 0x02;					       //倍速模式   M16中文P151
 	UCSRC = BIT(URSEL) | 0x06;		       //写UCSRC寄存器,设定8个bit，1停止位，异步
 	UBRR  = 12;	 	  	   		           //设定串口波特率为9600
 	UCSRB = (1<<RXCIE)|(1<<RXEN)|(1<<TXEN);//使能接收结束中断，使能收发
}

/*串口发送*/
void USART_Transmit( uchar data )
{
while ( !( UCSRA & (1<<UDRE)) ) ;  //等待发送缓冲器为空
UDR = data;                        // 将数据放入缓冲器，发送数据 
} 



uchar USART_Receive( void )
{
while ( !(UCSRA & (1<<RXC)) );  // 等待接收数据
return UDR;                     // 从缓冲器中获取并返回数据
} 

void newline(void)   //换行
{
   USART_Transmit(0x0d);  //发送一个回车
   USART_Transmit(0x0a);  //发送一个换行
}

void blank(void)    //空格
{
   USART_Transmit(0x20);  
}


