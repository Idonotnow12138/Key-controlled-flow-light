#include <reg51.h>
#include <intrins.h>
sbit key0=P1^0;
unsigned int temp;
unsigned int w; 
unsigned char num,flag;
void delay(unsigned int q)
{
 unsigned int c=0,f=0;
 for(c=0;c<q;c++)		  	
 {
  for(f=0;f<120;f++);
 }
}
void lsd()
{
temp=0xfe;
P0=temp;
delay(500);
  {
  for(w=0;w<7;w++)
     {
        temp=_crol_(temp,1);
        delay(500);
          P0=temp;
     }
    for(w=0;w<7;w++)
     {
        temp=_cror_(temp,1);
        delay(500);
          P0=temp;
     }
  }
}
void key()
{
 if(key0==0)  
  { 
  delay(10); 
  if(key0==1)
  {
  while(1)
   {
   lsd();
   }
  }
 }
} 
void main()
{
while(1)
 {
  key();
 }
}