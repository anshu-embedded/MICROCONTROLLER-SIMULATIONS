#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>




void main(void) {
    DDRD |= (1<<PD6);
    DDRB &=~(1<<PB0);
    DDRB &=~(1<<PB1);
    DDRB &=~(1<<PB2);
    DDRB &=~(1<<PB3);
    PORTB |=(1<<PB0);
    PORTB |=(1<<PB1);
    PORTB |=(1<<PB2);
    PORTB |=(1<<PB3);
    TCCR0A=0x83;
    TCCR0B=0x03;
    
    
while(1)
  {
    if(!(PINB & (1 << PB0)))
    {
        OCR0A = 64;
    }

    if(!(PINB & (1 << PB1)))
    {
        OCR0A = 128;
    }

    if(!(PINB & (1 << PB2)))
    {
        OCR0A = 192;
    }

    if(!(PINB & (1 << PB3)))
    {
        OCR0A = 249;
    }
  }    
}
