#ifndef TWI_H
#define TWI_H

#include"iom16v.h"
#include"delay.h"
#include"MPU_6050.h"
#include"sent.h"

#define uint  unsigned int
#define uchar unsigned char

//����ģʽ����״̬��
#define _START              0X08           //����
#define RE_START           0X10           //�������� 

//��������ģʽ״̬��
#define MT_SLA_ACK         0X18           //SLA+W �ѷ���,���յ� ACK    
#define MT_SLA_NOACK       0X20           //SLA+W �ѷ���,���յ� NO ACK    
#define MT_DATA_ACK        0X28           //�����ѷ���,����ACK
#define MT_DATA_NOACK     0X30           //�����ѷ���,����NO ACK

//��������ģʽ״̬��
#define MR_SLA_ACK         0X40           //SLA+R�ѷ���,���յ�ACK
#define MR_SLA_NOACK      0X48           //SLA+R�ѷ���,���յ�NO ACK
#define MR_DATA_ACK        0X50           //�����ѽ���,����ACK
#define MR_DATA_NOACK     0X58           //�����ѽ���,����NO ACK


//����twi����
#define START()   TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN)     //���� START �ź� ������TWINT������start
#define WAIT()    while (!(TWCR & (1<<TWINT)))               //�ȴ�TWINT ��λ ��TWINT ��λ��ʾSTART �ź��ѷ���
#define STOP()    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO)     //����STOP �ź�
#define SATUS()   (TWSR&0xF8)				                 //����״̬��
#define Set_Ack       (TWCR|=(1<<TWEA))                          //���� ACKӦ��
#define Set_NoAck     (TWCR&=~(1<<TWEA))                         //���� Not AckӦ��
#define TWI_READ()   (TWCR=(1<<TWINT)|(1<<TWEN))           		//������TWI����ʽ
#define TWI_WRITE(x) {TWDR=(x); TWCR=(1<<TWINT)|(1<<TWEN);}      //д���ݵ�TWDR

//����TWI����״̬�ļ���
#define FALSE  0
#define TRUE 1


void twi_init(void);
uchar twi_write(uchar W_ADDRESS,uchar W_DATA);
uchar twi_read(uchar W_ADDRESS);


#endif



