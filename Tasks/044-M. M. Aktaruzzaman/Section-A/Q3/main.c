#include <avr/io.h>
#include <util/delay.h>
#define toggle(PORT,bit_pos) (PORT ^= 1<<bit_pos)
#define check(PORT,pin_pos) (PORT&(1<<pin_pos))


int main(){
	DDRB &= ~(1<<PB1);
	DDRB |= (1<<PB6);
	
	while(1){
				if (check(PINB,1))
				{
					toggle(PORTB,6);
					_delay_ms(230);
				}
		}
	}