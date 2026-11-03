#define _XTAL_FREQ 1000000
#include <xc.h>

int led[8]={ 0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
int mode=0;
void main(void) {
    TRISB=0x00;
    TRISD=0x01;
    PORTB=0x00;
    
    
    while(1)
    {
      if(RD0==0)
      {
        __delay_ms(50);
        if(RD0==0)
        {
          mode++;
          if(mode>3)
          mode=0;
           while(RD0==0);
           }  
        }
      if(mode==0)
      {
          PORTB=0x00;
      }
      else if(mode==1)
      {
          PORTB=0xFF;
      }
      else if(mode==2)
      {
          PORTB=0xFF;
          __delay_ms(500);
          PORTB=0x00;
          __delay_ms(500);
      }
      else if(mode==3)
      {
        for(int i=0;i<=7;i++){
            PORTB=led[i];
            __delay_ms(300);     
        }      
       }  
    }
}
