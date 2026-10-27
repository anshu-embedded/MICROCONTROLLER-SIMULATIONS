#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>
#include<stdint.h>

void SPI_Init(void)
{
    DDRB |=(1<<PB2);
    DDRB |=(1<<PB3);
    DDRB |=(1<<PB5);
    DDRB &=~(1<<PB4);
    
    SPCR |=(1<<SPE) | (1<<MSTR);
}

uint8_t SPI_Transfer(uint8_t data)
{
  SPDR = data;
  while(!(SPSR & (1<<SPIF)));
  return SPDR;  
}

void Latch(void)
{
    PORTB &=~(1<<PB2);
    _delay_us(1);
    PORTB |=(1<<PB2);
}

void main(void) {
    SPI_Init();
    while(1)
    {
    SPI_Transfer(0xAA);
    Latch();
    _delay_ms(1000);
    
    SPI_Transfer(0x55);
    Latch();
    _delay_ms(1000);
    
    SPI_Transfer(0xFF);
    Latch();
    _delay_ms(1000);
    
    SPI_Transfer(0x00);
    Latch();
    _delay_ms(1000);
    }
    
}
