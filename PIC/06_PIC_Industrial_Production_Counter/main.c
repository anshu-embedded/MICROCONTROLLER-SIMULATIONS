#define _XTAL_FREQ 4000000
#include <xc.h>
// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)



  char seg[10] =
    {
        0x3F, 
        0x06, 
        0x5B, 
        0x4F, 
        0x66, 
        0x6D, 
        0x7D, 
        0x07, 
        0x7F, 
        0x6F  
    };
  
void interruts(void)
{
    OPTION_REGbits.INTEDG = 1;
    INTCONbits.INTF = 0;
    INTCONbits.INTE = 1;
    INTCONbits.GIE = 1;
}
unsigned char count;

void __interrupt() ISR(void)
{
    if(INTCONbits.INTF == 1)
    {
        count++;
        if(count > 9)
            count = 0;
    }
    INTCONbits.INTF = 0;
}

void main(void) {
    TRISB = 0x03;
    TRISD = 0x00;
    
    PORTB = 0x00;
    PORTD = 0x00;
}
