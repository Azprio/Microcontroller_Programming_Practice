#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

int main()
{
     LCDInit(0);// pass 1 for cursor blinking 
    LCDClear();
   // LCDGotoXY(0,0);
	LCDWriteStringXY(0,0,"A");
	LCDWriteStringXY(15,0,"B");
	LCDWriteStringXY(0,1,"C");
	LCDWriteStringXY(15,1,"D");
	
	//LCDWriteStringXY(x,y,msg);
    //LCDWriteString_sliding(200,"Abdur Rahman");
	//LCDWriteString("hello");
	LCDClear();
	LCDWriteStringXY(0,0,65);
	//LCDWriteString(01011010);
	LCDWriteInt(1023,4);
	_delay_ms(50000);
    while(1)
    {
	 //LCDClear();
      //LCDWriteString_sliding(200,"Abdur Rahman");
	      

    }
	

}
