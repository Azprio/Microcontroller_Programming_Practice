#include<avr/io.h>
#include<util/delay.h>
#define setBit(p,n) (p|=255<<n)
#define clearBit(p,n) (p&=~(255<<n))

int main()
{
setBit(DDRA,1);
while(1)
{
	setBit(PORTA,1);
	_delay_ms(200);
	clearBit(PORTA,1);
	_delay_ms(200);
}
}