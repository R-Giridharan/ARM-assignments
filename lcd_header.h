#include"delay_header.h"

#define LCD_D 0XFF<<0
#define RS 1<<8
#define E 1<<9

void LCD_INIT(void);
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char); 
void LCD_INTEGER(signed int);
void LCD_STR(unsigned char*);

 void LCD_INIT(void)
	{
	IODIR0= LCD_D|RS|E;
	LCD_CMD(0X01);
	LCD_CMD(0X02);
	LCD_CMD(0X0C);
	LCD_CMD(0X38);

	}
void LCD_CMD(unsigned char cmd)
{
IOCLR0=LCD_D;
IOSET0=cmd;
IOCLR0=RS;
IOSET0=E;
delay_ms(2);
IOCLR0=E;
}
void LCD_DATA(unsigned char data)
{
IOCLR0=LCD_D;
IOSET0=data;
IOSET0=RS;
IOSET0=E;
delay_ms(2);
IOCLR0=E;
}
void LCD_INTEGER(signed int n)
{ 
unsigned char a[20];
signed char i=0;
if (n==0)
	LCD_DATA('0');
else
{ 
	if(n<0)
	{
	LCD_DATA('-');
	n=-n;
	}

while(n>0)
		{  a[i++]=n%10;
			n=n/10;
		}
	for(--i;i>=0;i--)
		LCD_DATA(a[i]+48);
}
}

void LCD_STR(unsigned char*s)
{ while(*s)
LCD_DATA(*s++);
}
