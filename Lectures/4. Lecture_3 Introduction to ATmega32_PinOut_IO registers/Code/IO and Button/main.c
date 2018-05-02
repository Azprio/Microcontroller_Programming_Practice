#include<avr/io.h>
#include<util/delay.h>
int main()
{
  DDRA=DDRA|0b00000001;//define as output
  DDRA=DDRA&0b11111011;//define as input
  while(1)
  {
    if(PINA & 0b00000100)//Checking whether  button is pressed or released
	  PORTA=PORTA^0b00000001;//toggling
	  _delay_ms(500);
  }

}
