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
#define UBRR_Value (F_CPU/(BAUD_Rate*16UL))-1

/*
void send_string(char s[])
{
	int i =0;
	
	while (s[i] != 0x00)
	{
		send_char(s[i]);
		i++;
	}
*/	
void US_TX(unsigned char m){
	while(!(UCSR0A & (1<<UDRE0))){
		
	}
	UDR0 = m;
	
}

void send_string(char s[])
{
	int i =0;
	
	while (s[i] != 0x00)
	{
		US_TX(s[i]);
		i++;
	}
}

unsigned char US_RX()
{
	while(!(UCSR0A & (1<<RXC0))){
		
	}
	
	return UDR0;
}


void US_config(){
	UBRR0L = UBRR_Value;
	UBRR0H = UBRR_Value>>8;
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (3<<UCSZ00);
	
}



int main(void)
{
	
	DDRB |=0xff; 
	US_config();
	PORTB &= ~(1<<PB7);
	    
    while (1) 
    {
		char data = US_RX();
		if(data&1){
		PORTB |= (1<<PB7);
		send_string("ON\n");
		}
		else {
			PORTB &= ~(1<<PB7);
			send_string("OFF\n");
		}
		/*
		else if(data&0){
			PORTB &= ~(1<<PB7);
		}
		*/
		
		
    }
	
}



