#include<lpc21xx.h>
#include"delay_header.h"
 
#define	SEG_D 0xff
#define	SEG1 1<<8
#define	SEG2 1<<9
#define SEG3 1<<10
#define SEG4 1<<11
typedef unsigned char U8;
typedef unsigned int U32;
U32 i,j;

U8 seg_lut[]={0xc0,0xf9,0xa4,0Xb0,0X99,0X92,0X82,0Xf8,0X80,0X98};
void fourdigdisp(U32,U32);
int main()
{ PINSEL0=0;
IODIR0=SEG_D|SEG1|SEG2|SEG3|SEG4;
while(1)
{  
for(i=0;i<60;i++)
{for (j=0;j<60;j++)
fourdigdisp(i,j);
}
}
}
void fourdigdisp(U32 m, U32 s)
{	 char i;
for(i=0;i<50;i++)
{
   IOCLR0=SEG_D|SEG1|SEG2|SEG3|SEG4;
   IOSET0=seg_lut[m/10];
   IOSET0=SEG1;
   delay_ms(5);

   IOCLR0=SEG_D|SEG1|SEG2|SEG3|SEG4;
   IOSET0=seg_lut[m%10]^0x80;
   IOSET0=SEG2;
   delay_ms(5);

   IOCLR0=SEG_D|SEG1|SEG2|SEG3|SEG4;
   IOSET0=seg_lut[(s/10)%10];
   IOSET0=SEG3;
   delay_ms(5);

   IOCLR0=SEG_D|SEG1|SEG2|SEG3|SEG4;
   IOSET0=seg_lut[s%10];
   IOSET0=SEG4;
   delay_ms(5);
}
}

