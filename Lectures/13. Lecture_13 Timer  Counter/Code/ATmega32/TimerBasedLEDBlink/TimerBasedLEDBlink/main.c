/*
 * TimerBasedLEDBlink.c
 *
 * Created: 1/16/2018 12:59:21 AM
 * Author : Abdur Rahman
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

int total_overFlow=0;
int main(void)
{
	DDRC|=1<<0;
	PORTC&=~(1<<0);
	TCCR1B|=1<<CS10;
	sei();
	TIMSK|=1<<TOIE1;
	int c=0,d=0;
    while (1) 
    {
		
    }
}
ISR(TIMER1_OVF_vect)
{
	total_overFlow++;
	if (total_overFlow>=76)
	{
		PORTC^=(1<<0);
		total_overFlow=0;
	}
}

