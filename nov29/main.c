#include<avr/io.h>
#include<util/delay.h>

int main(){
DDRC = DDRC | 0b11111111;
while(1){
int a[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7c,0x07,0x7f,0x6f};
int i=0;
for(i=0;i<10; i++){
PORTC = a[i];
i++;
_delay_ms(200);


}
}

}