#define F_CPU 16000000UL
#include <xc.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile unsigned int pulseCount = 0;

unsigned char segmentCode(unsigned char n)
{
    switch(n)
    {
        case 0: return 0x3F;
        case 1: return 0x06;
        case 2: return 0x5B;
        case 3: return 0x4F;
        case 4: return 0x66;
        case 5: return 0x6D;
        case 6: return 0x7D;
        case 7: return 0x07;
        case 8: return 0x7F;
        case 9: return 0x6F;
        default: return 0x00;
    }
}

ISR(INT0_vect)
{
    pulseCount++;
}

void DisplayDigit(unsigned char n, unsigned char pin)
{
    PORTD |= 0x78;  // All digits OFF
    PORTB = (PORTB & 0x80) | segmentCode(n);

    PORTD &= ~(1 << pin); // Selected digit ON
    _delay_ms(2);
    PORTD |= (1 << pin);  // Selected digit OFF
}

void DisplayCount(unsigned int n)
{
    DisplayDigit((n / 1000) % 10, PD3);
    DisplayDigit((n / 100) % 10, PD4);
    DisplayDigit((n / 10) % 10, PD5);
    DisplayDigit(n % 10, PD6);
}

int main(void)
{
    unsigned int countToDisplay;

    DDRB = 0x7F; 
    DDRD = (DDRD & ~(1 << DDD2)) | 0x78;

    PORTD |= 0x78;

    EICRA = (1 << ISC01) | (1 << ISC00); // INT0 rising edge
    EIFR = (1 << INTF0);
    EIMSK = (1 << INT0);

    sei();

    while(1)
    {
        cli();
        countToDisplay = pulseCount;
        sei();

        DisplayCount(countToDisplay);
    }
}
