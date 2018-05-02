#include<avr/io.h>
#include<util/delay.h>

  char preiv1 =0;
  char preiv2 =0;
int main(){
  //1
  DDRA=DDRA | 0b00000011; //define as output
  DDRA=DDRA & 0b11110011; //define as input
  
  while(1){
  //2
  char button1_status = PINA & 0b00000100; //Reading button 1 status
  char button2_status = PINA & 0b00001000; //Reading button 2 status
  //3 Update LED Status
  if(button1_status && (button1_status!=preiv1))
	PORTA=PORTA ^ 0b00000001; //toggle LED 1
  if(button2_status && (button2_status!=preiv2))
	PORTA=PORTA ^ 0b00000010; //toggle LED 2
  //_delay_ms(270);

  preiv1 = button1_status ;
  preiv2 = button2_status ;
}
}