#define F_CPU 1000000UL
#include<avr/io.h>
#include<util/delay.h>
#define D1G  PB0   //direction 1 Green light
#define D1Y  PB1   //direction 1 yellow light
#define D1R  PB2    //direction 1 red light

#define D2G  PD0   //direction 2 Green light
#define D2Y  PD1   //direction 2 yellow light
#define D2R  PD2    //direction 2 red light

#define D3G  PD3   //direction 3 Green light
#define D3Y  PD4   //direction 3 yellow light
#define D3R  PD5    //direction 3 red light

#define D4G  PB3   //direction 4 Green light
#define D4Y  PB4   //direction 4 yellow light
#define D4R  PB5    //direction 4 red light


#define BTN PC6 // reset pin ( We don't need to write extra code for reset pin because it is aldready set as a reset pin,if we click reset the code runs from starting )

void allOff(void)
{
    PORTB = 0;
    PORTD = 0;
}

int main(){
    DDRB = 0x3F;      // PB0-PB5 output
    DDRD = 0x3F;      // PD0-PD5 output
    
    while(1){
        allOff();
        PORTB |=(1<<D1G);
        PORTD |=(1<<D3G);
        
        PORTD |=(1<<D2R);
        PORTB |=(1<<D4R); 
        _delay_ms(5000);
        
        
        allOff();
        PORTB |= (1<<D1Y);
        PORTD |= (1<<D3Y);

        PORTD |= (1<<D2R);
        PORTB |= (1<<D4R);
         _delay_ms(5000);
        
        allOff();
        PORTD |= (1<<D2G);
        PORTB |= (1<<D4G);

        PORTB |= (1<<D1R);
        PORTD |= (1<<D3R);
        _delay_ms(5000);
        
        allOff();
        PORTD |= (1<<D2Y);
        PORTB |= (1<<D4Y);

        PORTB |= (1<<D1R);
        PORTD |= (1<<D3R);
        _delay_ms(2000);
}
}
        
 
