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
	while(!(UCSRA & (1<<RXC))){
		
	}
	
	return UDR;
}


void US_config(){
	UBRRL = UBRR_Value;
	UBRRH = UBRR_Value>>8;
	UCSRB = (1<<RXEN);
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
	
}



int main(void)
{
	
	DDRC |=0xff; 
	US_config();    
    while (1) 
    {
		PORTC = US_RX();
		
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