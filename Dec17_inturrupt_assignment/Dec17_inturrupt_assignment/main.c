/*
 * Dec17_inturrupt_assignment.c
 *
 * Created: 12/17/2017 9:29:07 AM
 * Author : Prio
 */ 
#include<avr/io.h>
#include<util/delay.h>
#include "bcd_lib.h"
#include<avr/interrupt.h>

void init_int0();

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


int main(){

	init_int0();
	ADC_Initialization();

	DDRC = DDRC | 0b11111111;
	DDRD = DDRD | 0b00110011;
	DDRD|=1<<7;
	PORTD&=~(1<<7);
	while(1){

		int sensed_value = Read_ADC()/2;
		BCD_Converter(sensed_value);

	}

}

void init_int0()
{
	sei();
	//SREG | = (1<< 7);
	MCUCR |=  (1 << ISC01) | (1 << ISC00); 
	GICR |= ( 1<<INT0 );
	
	return 0;             
}

ISR(INT0_vect)
{
	PORTD^=(1<<7);
}