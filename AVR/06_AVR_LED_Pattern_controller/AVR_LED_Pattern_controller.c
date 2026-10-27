#define F_CPU 1000000UL
#include<avr/io.h>
#include<util/delay.h>
#define BTN PB0

int mode=0;
int main(){
    DDRD=0xFF;
    DDRB &=~(1<<BTN);
    while(1){
     if(PINB &(1<<BTN)){
        _delay_ms(50);
        if(PINB &(1<<BTN)){
           mode++;
           if(mode>3)mode=0;
           while(PINB &(1<<BTN));
        }
     }
      if(mode==0){
          PORTD=0x00;
      }
      
      else if(mode==1){
          PORTD=0xFF;
      }
      else if(mode==2){
          PORTD=0xFF;
          _delay_ms(150);
          PORTD=0x00;
          _delay_ms(150);
      }
        
      else if (mode==3){
          for(int i=0;i<=7;i++){
              PORTD=(1<<i);
              _delay_ms(100);
          }
       }    
    }
}
