#define F_CPU 1000000UL
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
	UCSRC = (3<<UCSZ0);
	sei();
	
}

int d = 0;


int main(void)
{
	
	DDRB &=0xfe;
	DDRB |=0b00000010;
	US_config();
	
	
	PORTB &= ~(1<<PB1);
	
	while (1)
	{
		
			if(d==1){
			PORTB ^= (1<<PB1);
			UDR=1;
			}
		
		
	}
	
	
	
}
ISR(USART_RXC_vect){
	d = UDR;
}