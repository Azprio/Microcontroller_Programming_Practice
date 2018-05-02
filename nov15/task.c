#include<avr/io.h>
#include<util/delay.h>

int main(){
  //1
  DDRB=DDRB | 0b11111111; //define as output
  DDRA=DDRA & 0b11111110; //define as input
  
  while(1){
  //2
  char button1_status = PINA & 0b00000001; //Reading button 2 status
  //3 Update LED Status
  PORTB=PORTB | 0b00000001;
  PORTB=PORTB & 0b01111111;
  
  if(button1_status)
	PORTB=PORTB | 0b00101010; //toggle LED 1
	PORTB=PORTB & 0b10101011;
  else
	PORTB=PORTB | 0b01010100; //toggle LED 1
	PORTB=PORTB & 0b11010101;
  //_delay_ms(270);

}
}