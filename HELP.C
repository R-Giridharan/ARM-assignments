#include<lpc21xx.h>
#include"delay_header.h"
 
#define	SEG_D 0xff
#define	SEG1 1<<8
#define	SEG2 1<<9
#define SEG3 1<<10
#define SEG4 1<<11
typedef unsigned char U8;
U8 j;

U8 seg_lut[]={0x89,0x86,0xC7,0X8C};
void disp(void);
int main()
{ PINSEL0=0;
IODIR0=SEG_D|SEG1|SEG2|SEG3|SEG4;
 
for (j=0;j<5;j++)
{
	disp();
	delay_ms(500);}
while(1)
disp();
}


void disp()
{	 U8 i;
for(i=0;i<50;i++)
{
   IOCLR0=SEG_D;;
   IOSET0=seg_lut[0];
   IOSET0=SEG1;
   delay_ms(5);
	IOCLR0=SEG1;

   IOCLR0=SEG_D;;
   IOSET0=seg_lut[1];
   IOSET0=SEG2;
   delay_ms(5);
	IOCLR0=SEG2;

	 IOCLR0=SEG_D;
   IOSET0=seg_lut[2];
   IOSET0=SEG3;
   delay_ms(5);
	IOCLR0=SEG3;

   IOCLR0=SEG_D;
   IOSET0=seg_lut[3];
   IOSET0=SEG4;
   delay_ms(5);
	 IOCLR0=SEG4;
}
}

