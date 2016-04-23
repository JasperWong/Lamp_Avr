#ifndef TWI_H
#define TWI_H

#include"iom16v.h"
#include"delay.h"
#include"MPU_6050.h"
#include"sent.h"

#define uint  unsigned int
#define uchar unsigned char

//主机模式启动状态码
#define _START              0X08           //启动
#define RE_START           0X10           //重新启动 

//主机发送模式状态码
#define MT_SLA_ACK         0X18           //SLA+W 已发送,接收到 ACK    
#define MT_SLA_NOACK       0X20           //SLA+W 已发送,接收到 NO ACK    
#define MT_DATA_ACK        0X28           //数据已发送,返回ACK
#define MT_DATA_NOACK     0X30           //数据已发送,返回NO ACK

//主机接收模式状态码
#define MR_SLA_ACK         0X40           //SLA+R已发送,接收到ACK
#define MR_SLA_NOACK      0X48           //SLA+R已发送,接收到NO ACK
#define MR_DATA_ACK        0X50           //数据已接受,返回ACK
#define MR_DATA_NOACK     0X58           //数据已接受,返回NO ACK


//常用twi操作
#define START()   TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN)     //发出 START 信号 ，清零TWINT、清零start
#define WAIT()    while (!(TWCR & (1<<TWINT)))               //等待TWINT 置位 ，TWINT 置位表示START 信号已发出
#define STOP()    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO)     //发送STOP 信号
#define SATUS()   (TWSR&0xF8)				                 //检验状态码
#define Set_Ack       (TWCR|=(1<<TWEA))                          //做出 ACK应答
#define Set_NoAck     (TWCR&=~(1<<TWEA))                         //做出 Not Ack应答
#define TWI_READ()   (TWCR=(1<<TWINT)|(1<<TWEN))           		//启动主TWI读方式
#define TWI_WRITE(x) {TWDR=(x); TWCR=(1<<TWINT)|(1<<TWEN);}      //写数据到TWDR

//定义TWI运行状态的极性
#define FALSE  0
#define TRUE 1


void twi_init(void);
uchar twi_write(uchar W_ADDRESS,uchar W_DATA);
uchar twi_read(uchar W_ADDRESS);


#endif



