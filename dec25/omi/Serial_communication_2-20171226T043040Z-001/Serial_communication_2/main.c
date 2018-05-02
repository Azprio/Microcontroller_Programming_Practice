#include<avr/io.h>
#include<util/delay.h>
#include<lcd.h>

main(){
	char c[16];
	DDRA = 0b10000000;
	LCDInit(0);// pass 1 for cursor blinking 
    LCDClear();
	int i = 0;
	while(1){
		c[i] = PINA;
		PORTA |= (1<<7);
		_delay_ms(1);
		PORTA &= ~(1<<7);
		_delay_ms(1);
		i++;
		if(PINA == 0b01111111){break;}
	}
		//c[0] = PINC;
		LCDWriteString(c);
}