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
int mode;
void main(void) {
    TRISD0=0;
    TRISD1=0;
    TRISD2=1;
    lcd_init();
    RD0 = 0;
    RD1 = 0;
    while(1)
    {
        if(RD2 == 0)
        {
            __delay_ms(40);
            if(RD2 == 0)
            {
                mode++;
                if(mode>3)
                    mode=0;
            lcd_cmd(0x01);
            lcd_cmd(0x80);
               
        if(mode == 0)
        {
            RD0=0;
            RD1=0;
            lcd_string("OFF");
            
        }
        else if(mode == 1)
        {
            RD0=1;
            RD1=0;
            lcd_string("RIGHT");
        }
        
        else if(mode == 2)
        {
            RD0=0;
            RD1=1;
            lcd_string("LEFT"); 
        }
        
        else if(mode == 3)
        {
            lcd_string("HAZARD");   
        }
        while(RD2 == 0);
         }
       }
        if(mode == 3)
        {
             RD0=1;
            RD1=1;
            __delay_ms(500);
            RD0=0;
            RD1=0;
            __delay_ms(500);
        }
    }
}
