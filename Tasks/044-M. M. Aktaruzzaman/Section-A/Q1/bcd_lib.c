#include<avr/io.h>
#include<util/delay.h>

void display(unsigned char seg,unsigned char data){
int s[4]={0xfe,0xfd,0xef,0xdf};
PORTD|=0x33;
PORTC=data;
PORTD&=s[seg];  
_delay_ms(10);
}

void BCD_Converter(int given){
int i=3;
int j=1;
int a=0;
while(i>=0){
	if(i==0){
		 a = (given/1000);
		}
	else{
		 a = (given/j)%10;
		}
display(i, a);
i--;
j = j*10;
}
}
