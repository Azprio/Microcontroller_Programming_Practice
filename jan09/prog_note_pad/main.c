#define F_CPU 8000000UL
#define BAUD_Rate 9600
#define UBRR_Value (F_CPU/(BAUD_Rate*16UL))-1

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

void US_TX(unsigned char m){
	while(!(UCSRA & (1<<UDRE))){ }
	UDR = m;
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

void send_strin(char *s)
{
	while (*s != 0x00)
	{
		US_TX(*s++);
	}
}

unsigned char US_RX()
{
	while(!(UCSRA & (1<<RXC))){
		
	}
	
	return UDR;
}


void US_config(){
	UBRRL = UBRR_Value;
	UBRRH = UBRR_Value>>8;
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (3<<UCSZ0)|(1<<URSEL);
	
}


int main(void)
{
	US_config();
	
	char b;
	
	while (1)
	{
		b = US_RX();
		//sprintf(b,"%d",a);
		send_strin(b);
		send_strin("\r");
		
	}
	
}



