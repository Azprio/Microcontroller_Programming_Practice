#include<avr/io.h>
#include<util/delay.h>
#include<lcd.h>

int main(){

DDRA=DDRA & 0b01111111;
DDRC |= 0b11111111;


char Data = 0b11111111;
_delay_ms(102);

for(int i=0; i<=7; i++){

char button1_status = PINA & 0b10000000;

if(button1_status){
Data |= 0xff <<i;

}else{
Data &= ~(0xff<<i);


}
_delay_ms(102);
}

PORTC |= Data;
LCDInit(0);
LCDClear();
LCDByte(Data,8);


}
