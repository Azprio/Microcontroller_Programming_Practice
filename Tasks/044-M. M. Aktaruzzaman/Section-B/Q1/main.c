#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

void init_int2();





int main(){

	init_int2();

	DDRC |= 0b00010000;
	while(1){

		

	}

}

void init_int2()
{
	sei();
	MCUCSR|=(1<<ISC2); 
	GICR |= ( 1<<INT2 );
	
	return 0;             
}

ISR(INT2_vect)
{
	PORTC^=(1<<4);
}