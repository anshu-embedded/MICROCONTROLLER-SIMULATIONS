#define _XTAL_FREQ 4000000
#include <xc.h>

 
#define RS RB0
#define EN RB1
 
void lcd_cmd(unsigned char cmd)
{
    PORTB = (PORTB & 0x0F) | (cmd & 0xF0);
    RS = 0;
    EN = 1;
    __delay_ms(1);
    EN = 0;
    __delay_ms(1);
 
    PORTB = (PORTB & 0x0F) | ((cmd << 4) & 0xF0);
    EN = 1;
    __delay_ms(1);
    EN = 0;
    __delay_ms(2);
}
 
void lcd_data(unsigned char data)
{
    PORTB = (PORTB & 0x0F) | (data & 0xF0);
    RS = 1;
    EN = 1;
    __delay_ms(1);
    EN = 0;
    __delay_ms(1);
 
    PORTB = (PORTB & 0x0F) | ((data << 4) & 0xF0);
    EN = 1;
    __delay_ms(1);
    EN = 0;
    __delay_ms(2);
}
 
void lcd_init(void)
{
    TRISB = 0x00;
    __delay_ms(20);
 
    lcd_cmd(0x02);
    lcd_cmd(0x28);
    lcd_cmd(0x0C);
    lcd_cmd(0x06);
    lcd_cmd(0x01);
}
 
void lcd_string(const char *str)
{
    while (*str)
    {
        lcd_data(*str++);
    }
}
 
void main(void)
{
    lcd_init();
    TRISD0 = 1;   
  
 
    while (1)
    {
         if(RD0 == 1)
        {
            __delay_ms(50);
            if(RD0==1)
            {
                lcd_cmd(0x01);
                lcd_cmd(0x80);
                lcd_string("LIGHT DETECTED");
                while(RD0 == 1);
                  lcd_cmd(0x01); 
            }
        }
        else
        { 
              lcd_cmd(0x80); 
            lcd_string("DARKNESS DETECT");
            __delay_ms(100);
        }
    }
}
