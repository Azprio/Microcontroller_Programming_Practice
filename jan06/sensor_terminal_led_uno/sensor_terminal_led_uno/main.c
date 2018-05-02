/*
 * USART1.c
 *
 * Created: 1/3/2018 2:56:09 PM
 * Author : Prio
 */
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define BAUD_Rate 9600
#define UBRR_Value (F_CPU/(BAUD_Rate*16UL))-1

void ADC_Initialization()
{

	ADMUX =(1<<REFS0);
	ADCSRA = (1<<ADPS1) | (1<<ADEN);
	
}

int Read_ADC()
{

	ADMUX |=(1<<MUX1);
	ADCSRA |= (1<<ADSC);

	while (ADCSRA & 0b01000000)
	{
	}

	int value = 0;
	value = ADCL;
	value |=(ADCH << 8);
	return value;

}

void US_TX(unsigned char m){
	while(!(UCSR0A & (1<<UDRE0))){ }
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
	ADC_Initialization();
	DDRB |=0x20; 
	US_config();
	PORTB &= 0x00;
	char b[1]={""};
	    
    while (1) 
    {
		int a = Read_ADC();
		sprintf(b,"%d",a);
		
		if (a>=500){
			PORTB |= 0x20;
		}
		else{
			PORTB &= 0x00;
		}
		
		send_string(b);
		send_string("\r");
		_delay_ms(500);
		
    }
	
}



