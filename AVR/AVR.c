#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdint.h>

uint16_t ADC_Read(void)
{
    ADCSRA |= (1 << ADSC);

    while (ADCSRA & (1 << ADSC));

    return ADC;
}

int main(void)
{
    // LED on PD6
    DDRD |= (1 << PD6);

    // ADC0 / PC0
    DDRC &= ~(1 << PC0);

    // Disable digital input on ADC0
    DIDR0 |= (1 << ADC0D);

    // AVcc reference + ADC0 channel
    ADMUX = (1 << REFS0);

    // ADC enable + prescaler 128
    ADCSRA = (1 << ADEN) |
             (1 << ADPS2) |
             (1 << ADPS1) |
             (1 << ADPS0);

    // Timer0 Fast PWM, OC0A
    TCCR0A = (1 << COM0A1) |
             (1 << WGM01) |
             (1 << WGM00);

    TCCR0B = (1 << CS01) |
             (1 << CS00);

    while (1)
    {
        uint16_t adc_value = ADC_Read();

        OCR0A = adc_value / 4;
    }
}