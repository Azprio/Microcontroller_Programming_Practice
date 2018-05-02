#include<avr/io.h>
#include<util/delay.h>
#define delaya 1
void display(unsigned char seg,unsigned char data){
PORTD=0xff;
PORTC=data;
PORTD=seg;  
_delay_ms(delaya);
}

int main(){

DDRC = DDRC | 0b11111111;
DDRD = DDRD | 0b00001111;
unsigned char data[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7B,0x07,0x7f,0x6f};
unsigned char seg[4]={0xfe,0xfd,0xfb,0x07};
while(1){

display(seg[0], data[2]);
display(seg[1], data[0]);
display(seg[2], data[4]);
display(seg[0], data[4]);

PORTD=0xff;
PORTC=a[0];
PORTD=0xfe;  
_delay_ms(delaya);

PORTD=0xff;
PORTC=a[0]; 
PORTD=0xfd; 
_delay_ms(delaya);

PORTD=0xff;
PORTC=a[4];  
PORTD=0xfb;
_delay_ms(delaya);


PORTD=0xff;
PORTC=a[4];  
PORTD=0x07;
_delay_ms(delaya);


}
}
