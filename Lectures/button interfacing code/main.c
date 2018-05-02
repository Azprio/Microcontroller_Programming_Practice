#include<avr/io.h>
#include<util/delay.h>
char button1_prev_Status=0;
char button2_prev_Status=0;
void main()
{
  //1 define I/O
  DDRA=DDRA | 0b00000011;// define as output
  DDRA=DDRA & 0b11110011;// define as input
  while(1)
  {
  //2 check Button status
  char button1_current_Status=PINA & 0b00000100;// reading button1 status
  char button2_current_Status=PINA & 0b00001000;// reading button2 status
  //3 Update LED Status
  if(button1_current_Status && (button1_current_Status!=button1_prev_Status))
    PORTA=PORTA ^ 0b00000001;// toggle LED1
  if(button2_current_Status && (button2_current_Status!=button2_prev_Status))
    PORTA=PORTA ^ 0b00000010;	// toggle LED2
	//_delay_ms(500);
	button1_prev_Status=button1_current_Status;
	button2_prev_Status=button2_current_Status;
	
  }
  
}