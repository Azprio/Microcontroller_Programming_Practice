#include<avr/io.h>
#include<util/delay.h>
#define delaya 10
void display(unsigned char seg,unsigned char data){
int s[4]={0xfe,0xfd,0xfb,0x07};
PORTD=0xff;
PORTC=data;
PORTD=s[seg];  
_delay_ms(10);
}

int main(){

DDRC = DDRC | 0b11111111;
DDRD = DDRD | 0b00001111;
int s[4]={0xfe,0xfd,0xfb,0x07};
while(1){




int i=0;
int b=0;
for(b=0;b<5; b++){
display(s[0], 2);
display(s[1], 0);
//PORTC = a[b];
display(s[2], b);
if(b==4){
for(i=0;i<6; i++){
//PORTD = a[i];
display(s[3], i);
i++;
}
}
else{
for(i=0;i<10; i++){
//PORTD = a[i];
display(s[3], i);
i++;
}
}

}

}
}
