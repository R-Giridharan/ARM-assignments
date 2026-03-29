#include<lpc21xx.h>
#include"delay_header.h"
 
#define	SEG_D 0xff
#define	SEG1 1<<8
#define	SEG2 1<<9
#define SEG3 1<<10
#define SEG4 1<<11
typedef unsigned char U8;
typedef unsigned int U32;
U32 temp;
float f=234.7;
void floatdisp(U32);
U8 dp1=0,dp2=0,dp3=0,dp4=0;
U8 seg_lut[]={0xc0,0xf9,0xa4,0Xb0,0X99,0X92,0X82,0Xf8,0X80,0X98};
int main()
{ PINSEL0=0;
IODIR0=SEG_D|SEG1|SEG2|SEG3|SEG4;
	if(f>=0.0&&f<10.0)
	{dp1=0x80;
		temp=f*1000;
	}
	if(f>=10.0&&f<100.0)
	{dp2=0x80;
		temp=f*100;
	}
	if(f>=100.0&&f<1000.0)
	{dp3=0x80;
		temp=f*10;
	}
	if(f>=1000.0&&f<10000.0)
	{dp4=0x80;
		temp=f;
	}
	while(1)
{
	floatdisp(temp);
}
}
void floatdisp(U32 n)
{	 
	U8 i=0;
		for(i=0;i<50;i++)
		{
   IOCLR0=SEG_D;;
   IOSET0=seg_lut[n/1000]^dp1;
   IOSET0=SEG1;
   delay_ms(5);
	 IOCLR0=SEG1;

   IOCLR0=SEG_D;;
   IOSET0=seg_lut[(n/100)%10]^dp2;
   IOSET0=SEG2;
   delay_ms(5);
	 IOCLR0=SEG2;

	 IOCLR0=SEG_D;
   IOSET0=seg_lut[(n/10)%10]^dp3;
   IOSET0=SEG3;
   delay_ms(5);
	 IOCLR0=SEG3;

   IOCLR0=SEG_D;
   IOSET0=seg_lut[n%10]^dp4;
   IOSET0=SEG4;
   delay_ms(5);
	 IOCLR0=SEG4;
  }
}
