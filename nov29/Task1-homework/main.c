#include<avr/io.h>
#include<util/delay.h>

int main(){
DDRC = DDRC | 0b11111111;
DDRD = DDRD | 0b11111111;

while(1){
int a[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int i=0;
int b=0;
for(b=0;b<5; b++){
PORTC = a[b];

if(b==4){
for(i=0;i<6; i++){
PORTD = a[i];
i++;
_delay_ms(500);
}
}
else{
for(i=0;i<10; i++){
PORTD = a[i];
i++;
_delay_ms(500);
}
}

}

}
}
