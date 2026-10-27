#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>

void EEPROM_Write(uint16_t address,uint8_t data)
{
    while(EECR & (1 << EEPE));
    EEAR=address;
    EEDR=data;
    
    EECR |=(1<<EEMPE);
    EECR |=(1<< EEPE);
}

uint16_t EEPROM_Read(uint16_t address)
{
    EEAR=address;
    EECR |=(1<<EERE);
    
    return EEDR;
}
int main(void)
{
    DDRB &=~(1<<PB0);
    PORTB |=(1<< PB0);
    DDRB |= (1<<PB1)|
            (1<<PB2)|
            (1<<PB3)|
            (1<<PB4);
    uint8_t counter = EEPROM_Read(100);
    PORTB = (PORTB & 0x01) | ((counter & 0x0F) << 1);
    while(1)
    {
        if(!(PINB & (1<<PB0)))
        {
            _delay_ms(50);
            if(!(PINB & (1<<PB0)))
            {
                counter++;
                EEPROM_Write(100,counter);
                PORTB = (PORTB & 0x01) | ((counter & 0x0F) << 1);
                while(!(PINB & (1<< PB0)));
            }
        }
    }
    
}
