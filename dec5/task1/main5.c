#include<avr/io.h>
#include<util/delay.h>
#define delaya 10

void display(unsigned char seg,unsigned char data){
PORTD=0xff;
PORTC=data;
PORTD=seg;  
_delay_ms(10);
}

void calcu(int given){
int a = given%10;
int b = (given/10)%10;
int c = (given/100)%10;
int d = given/1000;

int s[4]={0xfe,0xfd,0xfb,0x07};

display(s[0], d);
display(s[1], c);
display(s[2], b);
display(s[3], a);
}


int main(){

DDRC = DDRC | 0b11111111;
DDRD = DDRD | 0b00001111;
while(1){

calcu(823);



}
}
