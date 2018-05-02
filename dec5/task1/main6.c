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
int s[4]={0xfe,0xfd,0xfb,0x07};
display(s[i], a);
i--;
j = j*10;
}
}


int main(){

DDRC = DDRC | 0b11111111;
DDRD = DDRD | 0b00001111;
while(1){

calcu(823);



}
}
