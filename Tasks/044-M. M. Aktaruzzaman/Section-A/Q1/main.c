
#include<avr/io.h>
#include<util/delay.h>
#include "bcd_lib.h"
#include<avr/interrupt.h>

void init_int0();
int total_pulse_counter = 0;
int total_cost = 0;

void seg1(unsigned char data){
int s[1]={0x7f};
PORTA&=0x00;
PORTA=data;
PORTA&=s[0];  
_delay_ms(10);
}



int main(){

	init_int0();
	

	DDRC |= 0b11111111;
	DDRD |= 0b00110011;
	DDRA |= 0b11111111;
	
	
	while(1){

		total_cost = 5*total_pulse_counter;
		BCD_Converter(total_cost);
		
		
		seg1(total_pulse_counter);
		if(total_pulse_counter>9){
				total_pulse_counter=0;
		}

	}

}

void init_int0()
{
	sei();
	MCUCR |=  (1 << ISC01); 
	GICR |= ( 1<<INT0 );
	
	return 0;             
}

ISR(INT0_vect)
{
	total_pulse_counter ++;
}