#include<lpc21xx.h>
#include"lcd_header.h"

int main()
{ char ch,i,len,shift;
	char s[]="EMBEDDED";
	shift=0;
	len=16;
LCD_INIT();
while(1)
{	 
LCD_CMD(0X80);
	for(i=0;i<16;i++)
	{
		ch=s[(i-shift+len)%len];
LCD_DATA(ch);}
shift++;
if(shift>=len)
	shift=0;
delay_ms(250);
}
}
