#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"



int main(){


DDRA = DDRA & 0b00000000;
DDRD = DDRD | 0b00001111;
LCDInit(0);

	
	LCDClear();
char b = PINA;
char a[0] = b;
	LCDWriteStringXY(2,0,a);
	
	_delay_ms(200);
    

}