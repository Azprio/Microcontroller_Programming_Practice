/*
 * USART1.c
 *
 * Created: 1/3/2018 2:56:09 PM
 * Author : Prio
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define BAUD_Rate 9600
#define UBRR_Value (F_CPU/(BAUD_Rate*16))-1

void USART_config(){
	UBRRL = UBRR_Value;
	UBRRH = UBRR_Value>>8;
	UCSRB = (1<<TXEN);
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
	
}

void USART_TX(unsigned char m){
	UDR = m;
	while(!(UCSRA & (1<<UDRE))){
		
	}
	
}
int main(void)
{
	USART_config();    
    while (1) 
    {
		for(char i=1; i<=20; i++){
		USART_TX(i);
		_delay_ms(500);
		}
    }
}



/*
unsigned char USART_RX(){
	
	
	return UDR;
}
*/

