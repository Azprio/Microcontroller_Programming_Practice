/*
 * Usart_Intrrupt.c
 *
 * Created: 1/8/2018 11:30:44 AM
 * Author : Prio
 */ 

#define F_CPU 8000000UL
#define BAUD_Rate 9600
#define UBRR_Value (F_CPU/(BAUD_Rate*16UL))-1

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>




void US_config(){
	UBRR0L = UBRR_Value;
	UBRR0H = UBRR_Value>>8;
	UCSR0B = (1<<RXCIE0)|(1<<TXCIE0)|(1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (3<<UCSZ00);
	sei();
	
}




int main(void)
{
	
	DDRB |=0x80;
	US_config();
	PORTB &= ~(1<<PB7);
	
	while (1)
	{
		
			PORTB ^= 0x80;
			_delay_ms(500);
		
		
	}
	
	
	
}
ISR(USART0_RX_vect){
	unsigned char data = UDR0;
	UDR0 = data;
}





