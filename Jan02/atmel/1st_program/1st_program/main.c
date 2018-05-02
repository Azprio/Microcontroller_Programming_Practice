/*
 * 1st_program.c
 *
 * Created: 1/2/2018 3:47:28 PM
 * Author : Prio
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRB = 0b10000000;
    while (1) 
    {
		PORTB |= 0b10000000;
		_delay_ms(1000);
		PORTB &= 0b01111111;
		_delay_ms(1000);
    }
}

