
// CONFIG
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config BOREN = ON
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = OFF
#pragma config CP = OFF

#define _XTAL_FREQ 4000000
#include <xc.h>

void PWM_Init()
{
    TRISC=0;
    PR2=249;
    CCP1CON=0x0C;
    CCPR1L=128;
    T2CON=0x05;
}

void main(void)
{
    PWM_Init();
}
