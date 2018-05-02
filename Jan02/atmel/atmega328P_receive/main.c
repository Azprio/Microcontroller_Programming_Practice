/*
 * USART1.c
 *
 * Created: 1/3/2018 2:56:09 PM
 * Author : Prio
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define BAUD_Rate 9600
#define UBRR_Value (F_CPU/(BAUD_Rate*16))-1

unsigned char US_RX()
{
	while(!(UCSR0A & (1<<RXC0))){
		
	}
	
	return UDR0;
}


void US_config(){
	UBRR0L = UBRR_Value;
	UBRR0H = UBRR_Value>>8;
	UCSR0B = (1<<RXEN0);
	UCSR0C = (1<<URSEL0)|(3<<UCSZ00);
	
}



int main(void)
{
	
	DDRB |=0xff; 
	US_config();    
    while (1) 
    {
		if(US_RX()&1){
		PORTB ^= (1<<PB7)
		}
		
		_delay_ms(500);
		PORTC = 0x00;
    }
	
}

/*
void USART_TX(unsigned char m){
	while(UCSRA & (1<<UDRE)){
		
	}
	UDR = m;
}

*/