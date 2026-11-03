#define _XTAL_FREQ 1000000UL
#include <xc.h>

/* Direction 1 */
#define D1R PORTBbits.RB0
#define D1Y PORTBbits.RB1
#define D1G PORTBbits.RB2

/* Direction 2 */
#define D2R PORTBbits.RB3
#define D2Y PORTBbits.RB4
#define D2G PORTBbits.RB5

/* Direction 3 */
#define D3R PORTDbits.RD0
#define D3Y PORTDbits.RD1
#define D3G PORTDbits.RD2

/* Direction 4 */
#define D4R PORTDbits.RD3
#define D4Y PORTDbits.RD4
#define D4G PORTDbits.RD5

/* Buttons */
#define BTN1 PORTCbits.RC0
#define BTN2 PORTCbits.RC1
#define BTN3 PORTCbits.RC2

unsigned char mode = 0;



void allOff(void)
{
    PORTB = 0x00;
    PORTD = 0x00;
}

void checkButtons(void)
{
    if(BTN1)
    {
        __delay_ms(20);
        mode = 1;
    }

    if(BTN2)
    {
        __delay_ms(20);
        mode = 2;
    }

    if(BTN3)
    {
        __delay_ms(20);
        mode = 0;
    }
}

void smartDelay(unsigned int ms)
{
    unsigned int i;
    for(i=0;i<ms;i++)
    {
        __delay_ms(1);

        checkButtons();

        if(mode != 0)
        {
            return;
        }
    }
}

void phase13Green(void)
{
    allOff();

    D1G = 1;
    D3G = 1;

    D2R = 1;
    D4R = 1;

    smartDelay(5000);
}

void phase13Yellow(void)
{
    allOff();

    D1Y = 1;
    D3Y = 1;

    D2R = 1;
    D4R = 1;

    smartDelay(2000);
}

void phase24Green(void)
{
    allOff();

    D2G = 1;
    D4G = 1;

    D1R = 1;
    D3R = 1;

    smartDelay(5000);
}

void phase24Yellow(void)
{
    allOff();

    D2Y = 1;
    D4Y = 1;

    D1R = 1;
    D3R = 1;

    smartDelay(2000);
}


void nightMode(void)
{
    while(mode == 1)
    {
        allOff();

        D1Y = 1;
        D2Y = 1;
        D3Y = 1;
        D4Y = 1;

        for(unsigned int i=0;i<500;i++)
        {
            __delay_ms(1);
            checkButtons();
            if(mode != 1)
                return;
        }

        allOff();

        for(unsigned int i=0;i<500;i++)
        {
            __delay_ms(1);
            checkButtons();
            if(mode != 1)
                return;
        }
    }
}


void emergencyMode(void)
{
    while(mode == 2)
    {
        allOff();

        D1R = 1;
        D2R = 1;
        D3R = 1;
        D4R = 1;

        checkButtons();
    }
}


void main(void)
{
    TRISB = 0x00;
    TRISD = 0x00;
    TRISC = 0x07;

    PORTB = 0x00;
    PORTD = 0x00;

    while(1)
    {
        checkButtons();

        switch(mode)
        {
            case 0:

                phase13Green();
                if(mode != 0) break;

                phase13Yellow();
                if(mode != 0) break;

                phase24Green();
                if(mode != 0) break;

                phase24Yellow();
                break;

            case 1:
                nightMode();
                break;

            case 2:
                emergencyMode();
                break;
        }
    }
}
