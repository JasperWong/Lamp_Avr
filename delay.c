#include"delay.h"

void delay_nms(unsigned char i)                       /*������ʱ����*/
{
    unsigned char a,b ;
    for(a=0;a<i;a++)
    for(b=1;b;b++);
}

void delay_nus(uint n)       //N us��ʱ����
  {
   uint i=0;
   for (i=0;i<n;i++)
    asm("nop");
  }