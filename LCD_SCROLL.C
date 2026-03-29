#include<lpc21xx.h>
#include"lcd_header.h"

int main()
{
LCD_INIT();
while(1)
{	 
LCD_CMD(0X80);
LCD_STR("EMBEDDED");
LCD_CMD(0X1C);
delay_ms(250);
}
}
