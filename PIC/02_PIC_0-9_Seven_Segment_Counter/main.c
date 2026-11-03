#define _XTAL_FREQ 1000000
#include <xc.h>


void main()
{
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

    int count = 0;

    TRISB = 0x00;   
    TRISD = 0x01;  

    PORTB = seg[count];

    while(1)
    {
       
        if(RD0 == 1)
        {
            __delay_ms(200);   

            count++;

            if(count > 9)
            {
                count = 0;
            }
          while(RD0 == 1);
        }
            PORTB = seg[count];

            __delay_ms(200);
        
    }
}

