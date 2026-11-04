#define _XTAL_FREQ 4000000

#include <xc.h>

// CONFIGURATION
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config BOREN = ON
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = OFF
#pragma config CP = OFF

// PIN DEFINITIONS

#define BUTTON RB1

#define TRIG RC0
#define ECHO RC1
#define BUZZER RC2
#define LED RC3

#define LCD_RS RD0
#define LCD_EN RD1

unsigned char parkingMode = 0;

// --------------------------------
// LCD FUNCTIONS
// --------------------------------

void LCD_Pulse()
{
    LCD_EN = 1;
    __delay_us(2);

    LCD_EN = 0;
    __delay_us(50);
}

void LCD_Send4(unsigned char data)
{
    PORTD = (PORTD & 0x0F) | (data & 0xF0);
    LCD_Pulse();
}

void LCD_Command(unsigned char cmd)
{
    LCD_RS = 0;

    LCD_Send4(cmd);
    LCD_Send4(cmd << 4);

    if(cmd == 0x01 || cmd == 0x02)
        __delay_ms(2);
}

void LCD_Char(char data)
{
    LCD_RS = 1;

    LCD_Send4(data);
    LCD_Send4(data << 4);
}

void LCD_Text(char *text)
{
    while(*text)
    {
        LCD_Char(*text);
        text++;
    }
}

void LCD_Init()
{
    TRISD = 0x00;
    PORTD = 0x00;

    __delay_ms(20);

    LCD_RS = 0;
    LCD_EN = 0;

    // LCD 4-bit initialization

    LCD_Send4(0x30);
    __delay_ms(5);

    LCD_Send4(0x30);
    __delay_us(150);

    LCD_Send4(0x30);
    LCD_Send4(0x20);

    LCD_Command(0x28);
    LCD_Command(0x0C);
    LCD_Command(0x06);
    LCD_Command(0x01);
}

void LCD_Number(unsigned int number)
{
    char digit[5];
    unsigned char i = 0;

    if(number == 0)
    {
        LCD_Char('0');
        return;
    }

    while(number > 0)
    {
        digit[i] = (number % 10) + '0';
        number = number / 10;
        i++;
    }

    while(i > 0)
    {
        i--;
        LCD_Char(digit[i]);
    }
}

// --------------------------------
// INITIALIZATION
// --------------------------------

void Parking_Init()
{
    TRISBbits.TRISB1 = 1;

    TRISC = 0b00000010;

    TRISD = 0x00;

    PORTC = 0x00;
    PORTD = 0x00;

    // Enable PORTB weak pull-ups too
    OPTION_REGbits.nRBPU = 0;

    // Timer1: internal clock, 1:1 prescaler
    T1CON = 0x01;

    TMR1H = 0;
    TMR1L = 0;

    PIR1bits.TMR1IF = 0;
}

// --------------------------------
// BUTTON CONTROL
// --------------------------------

void Check_Button()
{
    if(BUTTON == 0)
    {
        __delay_ms(30);

        if(BUTTON == 0)
        {
            parkingMode = !parkingMode;

            // Wait for button release
            while(BUTTON == 0)
            {
                __delay_ms(10);
            }

            __delay_ms(30);
        }
    }
}

// --------------------------------
// ULTRASONIC DISTANCE
// --------------------------------

unsigned int Get_Distance()
{
    unsigned int timeout;
    unsigned int ticks;
    unsigned int distance;

    // Send 10 us trigger pulse

    TRIG = 0;
    __delay_us(2);

    TRIG = 1;
    __delay_us(10);

    TRIG = 0;

    // Wait for ECHO HIGH

    timeout = 3000;

    while(ECHO == 0 && timeout > 0)
    {
        __delay_us(10);
        timeout--;
    }

    // No echo received

    if(timeout == 0)
        return 0;

    // Start measuring ECHO HIGH time

    TMR1H = 0;
    TMR1L = 0;

    PIR1bits.TMR1IF = 0;

    while(ECHO == 1)
    {
        // Timer overflow means invalid measurement

        if(PIR1bits.TMR1IF)
            return 0;
    }

    // Read Timer1 value

    ticks = ((unsigned int)TMR1H << 8) | TMR1L;

    // Convert microseconds into centimetres

    distance = (ticks + 29) / 58;

    return distance;
}

// --------------------------------
// LCD DISTANCE DISPLAY
// --------------------------------

void Show_Distance(unsigned int distance)
{
    LCD_Command(0x80);

    LCD_Text("DISTANCE: ");

    if(distance == 0)
    {
        LCD_Text("NO ECHO");
    }
    else
    {
        LCD_Number(distance);
        LCD_Text(" cm");
    }

    // Clear remaining characters on first line
    LCD_Text("    ");

    LCD_Command(0xC0);

    if(parkingMode == 1)
        LCD_Text("MODE: ACTIVE    ");
    else
        LCD_Text("MODE: OFF       ");
}

// --------------------------------
// RESPONSIVE DELAY
// --------------------------------

void Wait_Check(unsigned int time)
{
    unsigned int i;

    for(i = 0; i < time; i += 10)
    {
        __delay_ms(10);

        Check_Button();

        if(parkingMode == 0)
            break;
    }
}

// --------------------------------
// LED AND BUZZER CONTROL
// --------------------------------

void Parking_Alert(unsigned int distance)
{
    unsigned int onTime;
    unsigned int offTime;

    if(distance == 0)
    {
        LED = 0;
        BUZZER = 0;
        Wait_Check(100);
        return;
    }

    if(distance > 40)
    {
        // Far distance: slow LED blink

        onTime = 100;
        offTime = 400;

        LED = 1;
        BUZZER = 0;
    }

    else if(distance > 20)
    {
        // Medium distance

        onTime = 100;
        offTime = 250;

        LED = 1;
        BUZZER = 1;
    }

    else if(distance > 10)
    {
        // Close distance: fast warning

        onTime = 100;
        offTime = 100;

        LED = 1;
        BUZZER = 1;
    }

    else
    {
        // Very close: very fast warning

        onTime = 50;
        offTime = 50;

        LED = 1;
        BUZZER = 1;
    }

    Wait_Check(onTime);

    LED = 0;
    BUZZER = 0;

    Wait_Check(offTime);
}

// --------------------------------
// MAIN PROGRAM
// --------------------------------

void main()
{
    Parking_Init();
    LCD_Init();

    LCD_Command(0x80);
    LCD_Text("CAR PARKING");

    LCD_Command(0xC0);
    LCD_Text("ASSISTANT");

    __delay_ms(1500);

    LCD_Command(0x01);

    while(1)
    {
        Check_Button();

        if(parkingMode == 0)
        {
            LED = 0;
            BUZZER = 0;

            LCD_Command(0x80);
            LCD_Text("PARKING MODE OFF");

            LCD_Command(0xC0);
            LCD_Text("PRESS BUTTON    ");
        }

        else
        {
            unsigned int distance;

            distance = Get_Distance();

            Show_Distance(distance);

            Parking_Alert(distance);
        }
    }
}
