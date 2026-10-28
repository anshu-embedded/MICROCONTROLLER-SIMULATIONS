#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<avr/eeprom.h>
#include<string.h>
#include<stdint.h>

#define RS PB0
#define EN PB1
#define PASSWORD_ADDR 0
#define FLAG_ADDR 10

char password[5];
char entered[5];
char new_password[5];

void lcd_cmd(unsigned char cmd)
{
    PORTB =(PORTB & 0x0F) |(cmd & 0xF0);
    PORTB &= ~(1<<RS);
    PORTB |= (1<<EN);
    _delay_ms(1);
    PORTB &= ~(1<<EN);
    _delay_ms(1);
    
    PORTB =(PORTB & 0x0F) |(cmd << 4);
    PORTB &= ~(1<<RS);
    PORTB |= (1<<EN);
    _delay_ms(1);
    PORTB &= ~(1<<EN);
    _delay_ms(2);   
}

void lcd_data(unsigned char data)
{
    PORTB =(PORTB & 0x0F) |(data & 0xF0);
    PORTB |= (1<<RS);
    PORTB |= (1<<EN);
    _delay_ms(1);
    PORTB &= ~(1<<EN);
    _delay_ms(1);
    
    PORTB =(PORTB & 0x0F) |(data << 4);
    PORTB |= (1<<RS);
    PORTB |= (1<<EN);
    _delay_ms(1);
    PORTB &= ~(1<<EN);
    _delay_ms(2);   
}

void lcd_init(void)
{
    DDRB = 0xFF;
    _delay_ms(20);
    lcd_cmd(0x02);
    lcd_cmd(0x28);
    lcd_cmd(0x0C);
    lcd_cmd(0x06);
    lcd_cmd(0x01);
    _delay_ms(2);
}
void lcd_string(const char *str)
{
    while(*str)
    {
        lcd_data(*str++);
    }
}

void keypad_init(void)
{
    
DDRD |= (1 << PD0) | (1 << PD1) |(1 << PD2) |(1 << PD3);   
DDRD &= ~ (1<<PD4);
DDRD &= ~ (1<<PD5);
DDRD &= ~ (1<<PD6);
PORTD |=(1 << PD4) |(1 << PD5) |(1 << PD6);
}

char keypad_scan(void)
{
    // Row 1
    PORTD = (PORTD & 0xF0) | 0x0F;
    PORTD &= ~(1 << PD0);
    _delay_us(5);

    if (!(PIND & (1 << PD4))) return '1';
    if (!(PIND & (1 << PD5))) return '2';
    if (!(PIND & (1 << PD6))) return '3';

    // Row 2
    PORTD = (PORTD & 0xF0) | 0x0F;
    PORTD &= ~(1 << PD1);
    _delay_us(5);

    if (!(PIND & (1 << PD4))) return '4';
    if (!(PIND & (1 << PD5))) return '5';
    if (!(PIND & (1 << PD6))) return '6';

    // Row 3
    PORTD = (PORTD & 0xF0) | 0x0F;
    PORTD &= ~(1 << PD2);
    _delay_us(5);

    if (!(PIND & (1 << PD4))) return '7';
    if (!(PIND & (1 << PD5))) return '8';
    if (!(PIND & (1 << PD6))) return '9';

    // Row 4
    PORTD = (PORTD & 0xF0) | 0x0F;
    PORTD &= ~(1 << PD3);
    _delay_us(5);

    if (!(PIND & (1 << PD4))) return '*';
    if (!(PIND & (1 << PD5))) return '0';
    if (!(PIND & (1 << PD6))) return '#';

    return '\0';
}

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

void password_init(void)
{
    if(EEPROM_Read(FLAG_ADDR) != 0xA5)
    {
        EEPROM_Write(PASSWORD_ADDR ,'1');
        EEPROM_Write(PASSWORD_ADDR + 1,'2');
        EEPROM_Write(PASSWORD_ADDR + 2,'3');
        EEPROM_Write(PASSWORD_ADDR + 3,'4');
        EEPROM_Write(PASSWORD_ADDR + 4,'\0');
        EEPROM_Write(FLAG_ADDR, 0xA5);
    }
    for(uint8_t i=0; i<5; i++)
    {
        password[i]=EEPROM_Read(PASSWORD_ADDR + i);
    }
}

void change_password(char *new_password)
{
    for(uint8_t i=0; i<5; i++)
    {
        EEPROM_Write(PASSWORD_ADDR + i, new_password[i]);
        password[i] = new_password[i];
    }
}

void enter_password(char *buffer)
{
    uint8_t i = 0;
    char key;

    buffer[0] = '\0';

    lcd_cmd(0x01);
    lcd_string("Enter Password:");

    lcd_cmd(0xC0);

    while (i < 4)
    {
        key = keypad_scan();

        if (key >= '0' && key <= '9')
        {
            buffer[i++] = key;
            lcd_data('*');

            while (keypad_scan() != '\0');
            _delay_ms(30);
        }
        else if (key == '*')
        {
            i = 0;
            lcd_cmd(0xC0);
            lcd_string("                ");
            lcd_cmd(0xC0);

            while (keypad_scan() != '\0');
            _delay_ms(30);
        }
    }

    buffer[4] = '\0';

    while (keypad_scan() != '\0');
}



int main(void)
{
    char entered[5];
    char new_password[5];
    char confirm_password[5];
    char key;

    lcd_init();
    keypad_init();

    lcd_cmd(0x01);
    _delay_ms(5);
    lcd_cmd(0x80);
    lcd_string("DIGITAL DOOR LOCK");
    _delay_ms(1000);

    password_init();

    while (1)
    {
        lcd_cmd(0x01);
        _delay_ms(2);

        lcd_cmd(0x80);
        lcd_string("1: Unlock");

        lcd_cmd(0xC0);
        lcd_string("2: Change Pass");

        do
        {
            key = keypad_scan();
        } while (key != '1' && key != '2');

        while (keypad_scan() != '\0');
        _delay_ms(30);

        if (key == '1')
        {
            enter_password(entered);

            if (strcmp(entered, password) == 0)
            {
                lcd_cmd(0x01);
                lcd_string("ACCESS GRANTED");

                /* Actual lock output baad mein add karenge. */
            }
            else
            {
                lcd_cmd(0x01);
                lcd_string("ACCESS DENIED");
            }

            _delay_ms(1500);
        }
        else if (key == '2')
        {
            enter_password(entered);

            if (strcmp(entered, password) == 0)
            {
                enter_password(new_password);
                enter_password(confirm_password);

                if (strcmp(new_password, confirm_password) == 0)
                {
                    change_password(new_password);

                    lcd_cmd(0x01);
                    lcd_string("Password Saved");
                }
                else
                {
                    lcd_cmd(0x01);
                    lcd_string("Mismatch!");
                }
            }
            else
            {
                lcd_cmd(0x01);
                lcd_string("Wrong Password");
            }

            _delay_ms(1500);
        }
    }
}
