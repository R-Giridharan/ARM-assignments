#include<lpc21xx.h>
#include"delay_header.h"
#define LCD_D 0Xff<<0
#define RS 1<<8
#define E 1<<9
void LCD_INIT(void);
void LCD_COMMAND(unsigned int);	
void LCD_DATA(unsigned int);
void LCD_BINARY(unsigned char);

int main()
{	LCD_INIT();
LCD_COMMAND(0X80);
LCD_BINARY(10);
}	
void LCD_INIT(void)
{
IODIR0=LCD_D|RS|E;
LCD_COMMAND(0X01);
LCD_COMMAND(0X02);
LCD_COMMAND(0X0C);
LCD_COMMAND(0X38);

}

void LCD_COMMAND(unsigned int cmd)
  {	IOCLR0=LCD_D;
  IOSET0=cmd;
  IOCLR0=RS;
  IOSET0=E;
  delay_ms(2); 
  IOCLR0=E;
  }

void LCD_DATA(unsigned int data)
   { IOCLR0=LCD_D;
  IOSET0=data;
  IOSET0=RS;
  IOSET0=E;
  delay_ms(2); 
  IOCLR0=E;
  }

void LCD_BINARY(unsigned char n)
 { int i;
for(i=7;i>=0;i--)
{if((n>>i)&1)
   LCD_DATA(1+48);
   else
   LCD_DATA(0+48);
	}
}


