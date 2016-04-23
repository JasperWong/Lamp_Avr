#ifndef SENT_H
#define SENT_H

#include"iom16v.h"
#include"twi.h"
#include"delay.h"
#include"MPU_6050.h"

#define  uint  unsigned int
#define  uchar unsigned char

void hc05_init(void);
void sent(uchar data);

#endif

