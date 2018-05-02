#include<avr/io.h>
#include<util/delay.h>

#define toggle(port,pin) (port ^=pin)

#define toggle1(port) (port = 1<<port)

#define toggle2(port,x) (port = 1<<x)

int main(){
	DDRA = 0b11111111;
	int i = 0;
	while(1){
		toggle2(PORTA,i);
		i++;
		_delay_ms(500);
		PORTA = 0b00000000;
		_delay_ms(500);
		if(i==8){
		i=0;
		}
	}
}