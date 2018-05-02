#include<avr/io.h>
#include<util/delay.h>
 
 int main()
 {
   DDRA=0b11111111;
   while(1)
   {
 PORTA=0b00000001;//0
	_delay_ms(500);
	 PORTA=0b00000010;//1
	_delay_ms(500);
	 PORTA=0b00000100;//2
	_delay_ms(500);
	 PORTA=0b00001000;//3
	_delay_ms(500);
	 PORTA=0b00010000;//4
	_delay_ms(500);
	 PORTA=0b00100000;//5
	_delay_ms(500);
	 PORTA=0b01000000;//6
	_delay_ms(500);
	 PORTA=0b10000000;//7
	_delay_ms(500);	 
   }
 }