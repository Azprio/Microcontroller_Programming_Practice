#include<avr/io.h>
#include<util/delay.h>
#define delaya 10
void display(unsigned char seg,unsigned char data){
PORTD=0xff;
PORTC=data;
PORTD=seg;  
_delay_ms(10);
}

int main(){

DDRC = DDRC | 0b11111111;
DDRD = DDRD | 0b00001111;
int s[4]={0xfe,0xfd,0xfb,0x07};
while(1){

display(s[0], 2);
display(s[1], 0);
display(s[2], 4);
display(s[3], 4);



}
}
