#include<avr/io.h>
#include<util/delay.h>

void display(unsigned char seg,unsigned char data){
int s[4]={0xfe,0xfd,0xfb,0x07};
PORTD=0xff;
PORTC=data;
PORTD=s[seg];  
_delay_ms(10);
}
