#ifndef delay_H
#define delay_H

#include"iom16v.h"
#include"twi.h"
#include"MPU_6050.h"
#include"sent.h"

#define   uint   unsigned int
#define   uchar  unsigned char 

void delay_nms(unsigned char i); 
void delay_nus(uint n);

#endif