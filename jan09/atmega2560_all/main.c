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
	
	UBRR1L = UBRR_Value;
	UBRR1H = UBRR_Value>>8;
	UCSR1B = (1<<RXCIE1)|(1<<TXCIE1)|(1<<RXEN1)|(1<<TXEN1);
	UCSR1C = (3<<UCSZ11);
	
	
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
ISR(USART0_RX_vect){
	unsigned char data0 = UDR0;
	UDR1 = data0;
	
	
}

ISR(USART1_RX_vect){
	unsigned char data1 = UDR1;
	UDR0 = data1;
}




