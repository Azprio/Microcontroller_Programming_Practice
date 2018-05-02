#include <avr/io.h>
#include <util/delay.h>
int main()
{
	DDRC |= 0xff;
	DDRD &= 0xfe;
	PORTC &= 0x00;
	int count = 0;
	while(1)
	{
		if(PIND & 0x01){
			PORTC &= 0x00;
			count++;
			PORTC |= (0xff>>(7-(count-1)));
			_delay_ms(500);
			
			for(int i=0; i<count; i++){
			PORTC |= (0xff>>(7-(count-1)));
			_delay_ms(200);
			PORTC &= ~(0xff>>(7-(count-1)));
			_delay_ms(200);
			}
			PORTC |= (0xff>>(7-(count-1)));
			
			}
		if(count >= 8){
		count =0;
		}

		}
	}

