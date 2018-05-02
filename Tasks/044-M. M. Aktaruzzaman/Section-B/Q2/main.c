#include<avr/io.h>
#include<util/delay.h>
#include<bcd_lib.h>

void ADC_Initialization()
{

ADMUX =(1<<REFS0);
ADCSRA = (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0) | (1<<ADEN);
 
}

int Read_ADC()
{

ADMUX |=(1<<MUX1) | (1<<MUX2);
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

DDRC |= 0b11111111;
DDRD |= 0b00001111;
DDRB |=0x10; 

while(1){

int value = Read_ADC();
BCD_Converter(value);
if (value<700){
		PORTB |= (1<<PB4); 
}
else{
		PORTB &= ~(1<<PB4); 
}

}

}