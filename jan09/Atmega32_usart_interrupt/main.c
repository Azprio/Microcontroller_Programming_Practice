/*
 * Usart_Intrrupt.c
 *
 * Created: 1/8/2018 11:30:44 AM
 * Author : Prio
 */ 

#define F_CPU 4000000UL
#define BAUD_Rate 9600
#define UBRR_Value (F_CPU/(BAUD_Rate*16UL))-1

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>




void US_config(){
	UBRRL = UBRR_Value;
	UBRRH = UBRR_Value>>8;
	UCSRB = (1<<RXCIE)|(1<<TXCIE)|(1<<RXEN)|(1<<TXEN);
	UCSRC = (3<<UCSZ0)|(1<<URSEL);
	sei();
	
}




int main(void)
{
	
	DDRA |=0x80;
	US_config();
	PORTA &= ~(1<<PB7);
	
	while (1)
	{
		
			PORTA ^= 0x80;
			_delay_ms(500);
		
		
	}
	
	
	
}
ISR(USART_RXC_vect){
	unsigned char data = UDR;
	UDR = data;
}





