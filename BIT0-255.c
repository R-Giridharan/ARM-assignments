 #include<lpc21xx.h>
 void delay(unsigned int n)
{unsigned int i;

for(;n>0;n--)

for(i=12000;i>0;i--);
}
 int main()
 {
 unsigned char i,count=0;
 IODIR0=0XFF;
 while(count<1)
 {
 for (i=0;i<256;i++)
 {
 IOCLR0=i;

delay(500);

IOSET0=0xff;

delay(500);
 }
 }
 count++;
 }
