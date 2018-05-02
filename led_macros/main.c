#include<avr/io.h>
#include<util/delay.h>
#define setbit(p, n) (p |= 1<< n)
#define clearbit(p, n) (p &= ~(1<< n))

int main(){
	//setbit(DDRA, 1);
	
	DDRA = 0b11111111;
	
	void topToDown(){
		for(int i=0; i<=7; i++)
		{
			PORTA = 0b00000001 <<i;
			_delay_ms(500);
		}
	}
	
	void bottomToTop(){
		for(int i=0; i<=7; i++)
		{
			PORTA = 0b10000000 >>i;
			_delay_ms(500);
		}
	}
	
	while(1){
		//setbit(PORTA, 1);
		//_delay_ms(200);
		//clearbit(PORTA, 1);
		//_delay_ms(200);
		
		topToDown();
		_delay_ms(200);
		bottomToTop();
	}
}