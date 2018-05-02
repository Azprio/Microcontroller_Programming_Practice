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

void ADC_Initialization()
{

	ADMUX =(1<<REFS0);
	ADCSRA = (1<<ADPS1) | (1<<ADEN);
	
}

int Read_ADC()
{

	ADMUX |=(1<<MUX2);
	ADCSRA |= (1<<ADSC);

	while (ADCSRA & 0b00000001)
	{
	}

	int value = 0;
	value = ADCL;
	value |=(ADCH << 8);
	return value;

}


void US_TX(unsigned char m){
	UDR = m;
	while(!(UCSRA & (1<<UDRE))){ }
	
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
	while(!(UCSRA & (1<<RXC))){
		
	}
	
	return UDR;
}


void US_config(){
	UBRRL = UBRR_Value;
	UBRRH = UBRR_Value>>8;
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
	
}



int main(void)
{
	ADC_Initialization();
	DDRB |=0x10; 
	US_config();
	PORTB &= ~(1<<PB5);
	    
    while (1) 
    {
		
		
		//char sensed_value= Read_ADC();
		//send_string(sensed_value);
		
		send_string("OFF\n");
		
		_delay_ms(500);
		
		}
		
		
    }
	



