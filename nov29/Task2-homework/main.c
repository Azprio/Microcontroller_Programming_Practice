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
int d[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7B,0x07,0x7f,0x6f};
int s[4]={0xfe,0xfd,0xfb,0x07};
while(1){

display(s[0], d[2]);
display(s[1], d[0]);
display(s[2], d[4]);
display(s[3], d[4]);



}
}
