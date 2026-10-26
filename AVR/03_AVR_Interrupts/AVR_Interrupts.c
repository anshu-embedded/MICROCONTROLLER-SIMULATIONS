#define F_CPU 16000000UL
#include <avr/io.h>
#include<avr/interrupt.h>

ISR(INT0_vect)
{
    PORTB ^= (1<<PB5);
}

void main(void) {
    DDRB |=(1<<PB5);
    DDRD &=~(1<<PD2);
    PORTD |= (1<<PD2);
    
    EICRA=0b00000010;
    EIMSK |=(1<<INT0);
    sei();
    while(1);   
}
