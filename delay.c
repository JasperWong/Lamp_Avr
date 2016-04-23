#include"delay.h"

void delay_nms(unsigned char i)                       /*定义延时函数*/
{
    unsigned char a,b ;
    for(a=0;a<i;a++)
    for(b=1;b;b++);
}

void delay_nus(uint n)       //N us延时函数
  {
   uint i=0;
   for (i=0;i<n;i++)
    asm("nop");
  }