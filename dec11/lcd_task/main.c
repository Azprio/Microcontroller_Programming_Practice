#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

void ADC_Initialization()
{

ADMUX =(1<<REFS0);
ADCSRA = (1<<ADPS1) | (1<<ADEN);
 
}

int Read_ADC()
{

ADMUX |=(1<<MUX2);
ADCSRA |= (1<<ADSC);

while (ADCSRA & 0b01000000)
{
}

int value = 0;
value = ADCL; 
value |=(ADCH << 8);
return value;

}


int main(){
ADC_Initialization();

DDRC = DDRC | 0b11111111;
DDRD = DDRD | 0b00001111;
LCDInit(0);
while(1){

	int sensed_value = Read_ADC();
	
	LCDClear();
char a[] = "Aktaruzzaman";
	LCDWriteStringXY(2,0,a);
	LCDWriteStringXY(1,1,"ADC value=");
	LCDWriteInt(sensed_value,4);
	_delay_ms(200);
    
}

}