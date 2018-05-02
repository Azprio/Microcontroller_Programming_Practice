#include<avr/io.h>
#include<util/delay.h>


int main(){
 DDRC |=0b10101010; 
 
while(1){
	
	for(int i=7; i>=1; i--){
	PORTC |= (1<<i);
	_delay_ms(100);
	PORTC &= ~(1<<i);
	i--;
	}

}

}