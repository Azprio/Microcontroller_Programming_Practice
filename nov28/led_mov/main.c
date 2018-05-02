#include<avr/io.h>
#include<util/delay.h>
#include<my_lib.h>
int main(){
DDRA = DDRA | 0b11111111;

while(1){
top_to_down();
_delay_ms(500);
down_to_top();
}
}

