#include<avr/io.h>
#include<util/delay.h>
#include<lcd.h>

main(){
	DDRD = 0b01111111;
	char msg[] = "Hello MCU-2";
	int len = sizeof(msg);
	for(int i = 0 ; i<len-1 ; i++){
		PORTD = msg[i];
		while(!(PIND&(1<<PD7))){
			
		}
		_delay_ms(1);
	}
	
	PORTD |= 0b01111111;
}