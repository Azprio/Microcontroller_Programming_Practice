#include<avr/io.h>
#include<util/delay.h>
#include "led.h"
#include<avr/interrupt.h>
void init_int0(void);
int main(void)
{
    DDRD|=1<<7; 
	PORTD&=~(1<<7);
	init_int0();
   while(1)
   {
     
   }
 return 0;

}

void init_int0(void)
{
    sei();   //intrrupt library function//1.enable global interrupt
    //SREG|=(1<<I);                  //1.enable global interrupt SREG|=(1<<I); is not required for sei();
    MCUCR |=  (1 << ISC01) | (1 << ISC00);  //2.set interrupt sence
    GICR |= ( 1<<INT0 );               //3.enable individual interrupt
}

ISR(INT0_vect)
{
	PORTD^=(1<<7);
}

