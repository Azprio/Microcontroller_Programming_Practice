#include<avr/io.h>
#include<avr/interrupt.h>

volatile int ov_count = 0;

void Time_config(){
	TCCR0 |= (1<<CS00)|(1<<CS02);
	TIMSK |= (1<<TOIE0);
	sei();
}

int main()
{
	
	Time_config();
	DDRC |=0x01;
	while (1)
	{
		
		if(ov_count == 12 && TCNT0>=52){
		
		PORTC ^=0x01;
		TCNT0 = 0;
		ov_count = 0;

		}
		
		
	}
	
}

ISR(TIMER0_OVF_vect){
	ov_count++;
	}
