#include<avr/io.h>
#include<util/delay.h>

void top_to_down(){

for(int i=0;i<8; i++){
PORTA= (0b00000001<< i);
_delay_ms(200);
}

}

void down_to_top(){

for(int i=0;i<8; i++){
PORTA= (0b10000000>> i);
_delay_ms(200);
}

}