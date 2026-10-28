#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

/* I2C addresses: 7-bit */
#define EEPROM_ADDR 0x50
#define OLED_ADDR   0x3C

/* ---------- I2C / TWI ---------- */

void I2C_init(void)
{
    TWSR = 0x00;
    TWBR = 72;
    TWCR = (1 << TWEN);
}

void I2C_start(uint8_t address)
{
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));

    TWDR = address;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

void I2C_write(uint8_t data)
{
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

uint8_t I2C_read_ACK(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

uint8_t I2C_read_NACK(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

void I2C_stop(void)
{
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

/* ---------- ADC ---------- */

void ADC_init(void)
{
    ADMUX = (1 << REFS0);  // AVCC reference, ADC0
    ADCSRA = (1 << ADEN) |
             (1 << ADPS2) |
             (1 << ADPS1) |
             (1 << ADPS0); // Prescaler 128
}

uint16_t ADC_read(void)
{
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    return ADC;
}

/* ---------- 24C02B EEPROM ---------- */

/* Write one byte and wait for write cycle */
void EEPROM_write(uint8_t address, uint8_t data)
{
    I2C_start((EEPROM_ADDR << 1) | 0);
    I2C_write(address);
    I2C_write(data);
    I2C_stop();

    _delay_ms(10);
}

/* Read one byte */
uint8_t EEPROM_read(uint8_t address)
{
    uint8_t data;

    I2C_start((EEPROM_ADDR << 1) | 0);
    I2C_write(address);

    I2C_start((EEPROM_ADDR << 1) | 1);
    data = I2C_read_NACK();
    I2C_stop();

    return data;
}

/* ---------- OLED SSD1306 128x32 ---------- */

void OLED_command(uint8_t cmd)
{
    I2C_start((OLED_ADDR << 1) | 0);
    I2C_write(0x00);
    I2C_write(cmd);
    I2C_stop();
}

void OLED_data(uint8_t data)
{
    I2C_start((OLED_ADDR << 1) | 0);
    I2C_write(0x40);
    I2C_write(data);
    I2C_stop();
}

void OLED_init(void)
{
    _delay_ms(100);

    OLED_command(0xAE);
    OLED_command(0xD5);
    OLED_command(0x80);
    OLED_command(0xA8);
    OLED_command(0x1F);
    OLED_command(0xD3);
    OLED_command(0x00);
    OLED_command(0x40);
    OLED_command(0x8D);
    OLED_command(0x14);
    OLED_command(0x20);
    OLED_command(0x02);
    OLED_command(0xA1);
    OLED_command(0xC8);
    OLED_command(0xDA);
    OLED_command(0x02);
    OLED_command(0x81);
    OLED_command(0x7F);
    OLED_command(0xD9);
    OLED_command(0xF1);
    OLED_command(0xDB);
    OLED_command(0x40);
    OLED_command(0xA4);
    OLED_command(0xA6);
    OLED_command(0xAF);
}

void OLED_position(uint8_t page)
{
    OLED_command(0xB0 | page);
    OLED_command(0x00);
    OLED_command(0x10);
}

/* Numeric font: 0-9 */
const uint8_t digit_font[10][5] = {
    {0x3E,0x51,0x49,0x45,0x3E},
    {0x00,0x42,0x7F,0x40,0x00},
    {0x42,0x61,0x51,0x49,0x46},
    {0x21,0x41,0x45,0x4B,0x31},
    {0x18,0x14,0x12,0x7F,0x10},
    {0x27,0x45,0x45,0x45,0x39},
    {0x3C,0x4A,0x49,0x49,0x30},
    {0x01,0x71,0x09,0x05,0x03},
    {0x36,0x49,0x49,0x49,0x36},
    {0x06,0x49,0x49,0x29,0x1E}
};

void OLED_digit(uint8_t digit)
{
    uint8_t i;

    if (digit > 9)
        digit = 0;

    for (i = 0; i < 5; i++)
        OLED_data(digit_font[digit][i]);

    OLED_data(0x00);
}

/* Display all four digits: 0000-1023 */
void OLED_number(uint8_t page, uint16_t number)
{
    OLED_position(page);

    OLED_digit((number / 1000) % 10);
    OLED_digit((number / 100) % 10);
    OLED_digit((number / 10) % 10);
    OLED_digit(number % 10);
}

/* 111 = verified, 000 = mismatch */
void OLED_status(uint8_t match)
{
    uint8_t i;

    OLED_position(2);

    for (i = 0; i < 3; i++)
        OLED_digit(match ? 1 : 0);
}

/* ---------- Debug variables ---------- */

volatile uint16_t adc_value = 0;
volatile uint16_t saved_value = 0;
volatile uint8_t verify_ok = 0;

/* ---------- Main ---------- */

int main(void)
{
    uint16_t value;
    uint16_t readback;

    I2C_init();
    ADC_init();
    OLED_init();

    while (1)
    {
        /* Read potentiometer on ADC0 / PC0 */
        value = ADC_read();
        adc_value = value;

        /* Save 10-bit ADC value in two EEPROM bytes */
        EEPROM_write(0, (uint8_t)(value & 0xFF));
        EEPROM_write(1, (uint8_t)(value >> 8));

        /* Read back and reconstruct the value */
        readback = EEPROM_read(0);
        readback |= ((uint16_t)EEPROM_read(1) << 8);

        saved_value = readback;
        verify_ok = (readback == value);

        /* OLED page 0: ADC value
           OLED page 1: EEPROM readback
           OLED page 2: verification status */

        OLED_number(0, value);
        OLED_number(1, readback);
        OLED_status(verify_ok);

        _delay_ms(1000);
    }
}
