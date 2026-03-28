#include<lpc21xx.h>

void delay(unsigned int n)
{unsigned int i;
for(;n>0;n--)
for(i=12000;i>0;i--);
}

int main()
{
int i, count=0;
PINSEL0=0;
IODIR0=0xff;
while(count<20)
{
IOCLR0=0xff;
delay(500);
IOSET0=0xff;
delay(500);
count++;
}
 for(i=0;i<8;i++)
 {	IOCLR0=1<<i;
delay(500);
IOSET0=0xff;
delay(500);
 }
}
