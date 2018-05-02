#define F_CPU 1000000UL

#include <avr/io.h>


int main(void)
{
	TCCR0 |= (1<<CS00)|(1<<CS02);
	float i = 0;
	DDRC |=0x01;
	while (1)
	{
		
		if(TCNT0>=97){
		//i=i + 0.25 ;
		//TCNT0 = 0;
		//}
		//if(i >= 1000){
		
		PORTC ^=0x01;
		TCNT0 = 0;
		//i=0;

		}
		
		
	}
	
}



