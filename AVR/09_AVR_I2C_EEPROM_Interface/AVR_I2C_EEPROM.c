
#define F_CPU 16000000UL
#include <avr/io.h>
#include<stdint.h>
#include<util/delay.h>

void I2C_Init(void)
{
    TWSR = 0x00;
    TWBR = 72;
    TWCR = (1<<TWEN);
}

void I2C_Start(void)
{
    TWCR |= (1<<TWINT) |
            (1<<TWSTA) |
            (1<<TWEN);
    
    while(!(TWCR & (1<<TWINT)));
}

void I2C_Stop(void)
{
    TWCR |= (1<<TWINT) |
            (1<<TWSTO) |
            (1<<TWEN);
}

void I2C_Write(uint8_t data)
{
    TWDR = data;
    TWCR = (1 << TWINT) |
           (1 << TWEN);
    while(!(TWCR & (1<<TWINT)));
}

uint8_t I2C_ReadNACK(void)
{
    TWCR =(1<<TWINT) |
          (1<<TWEN);
    while(!(TWCR & (1<<TWINT)));
    return TWDR;
}

void EEPROM_Write(uint16_t address,uint8_t data)
{
    I2C_Start();
    I2C_Write(0xA0);
    I2C_Write(address);
    I2C_Write(data);
    I2C_Stop();
    _delay_ms(10);
}

uint8_t EEPROM_Read(uint16_t address)
{
    uint8_t data;
    I2C_Start();
    I2C_Write(0xA0);
    I2C_Write(address);
    I2C_Start();
    I2C_Write(0xA1);
    data=I2C_ReadNACK();
    I2C_Stop();
    return data;
}

void main(void) {
    uint8_t data;
    DDRB = 0xFF;
    I2C_Init();
    EEPROM_Write(0x10,0xAA);
    data=EEPROM_Read(0x10);
    while(1)
    {
        PORTB=data;
    }
}
