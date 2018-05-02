#include "led.h"


void up_to_down(void)
{
  int i;
  for(i=0;i<=7;i++)
		 {
		   PORTA=(1<<i);
		   _delay_ms(100);
		 }
}


void down_to_up(void)
{
   int i;
  for(i=7;i>=0;i--)
		 {
		   PORTA=(1<<i);
		   _delay_ms(100);
		 }
}