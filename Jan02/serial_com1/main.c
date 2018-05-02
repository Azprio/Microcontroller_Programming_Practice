#include<avr/io.h>
#include<util/delay.h>




int main(){
DDRD |= 0b00000001;
char a[] = "3";

_delay_ms(100);
int i = 0;
while(i<8){

PORTD = (a[0]>>i);

_delay_ms(100);
i++;

}


}
