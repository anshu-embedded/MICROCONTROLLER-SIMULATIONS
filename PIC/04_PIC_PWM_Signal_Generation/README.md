PIC16F877A PWM Signal Generation

Overview

A PWM signal generation project developed using the PIC16F877A microcontroller and Embedded C. The CCP1 module and Timer2 generate a hardware PWM signal.

Features

- Hardware PWM generation using CCP1.
- Timer2 configuration for PWM operation.
- Adjustable PWM duty cycle through register values.
- PWM output available on RC2/CCP1.

Pin Configuration

PIC Pin| Function
RC2/CCP1| PWM Output

PWM Configuration

Register| Value| Purpose
PR2| 249| Sets PWM period
CCP1CON| 0x0C| Enables PWM mode
CCPR1L| 128| Sets duty cycle
T2CON| 0x05| Timer2 with 1:4 prescaler

- Oscillator Frequency: 4 MHz
- PWM Frequency: Approximately 1 kHz
- Duty Cycle: Approximately 50%

How to Change PWM Duty Cycle

To change the PWM duty cycle, modify the "CCPR1L" and "CCP1CON" register values.

Example:

CCPR1L| Approximate Duty Cycle
64| 25%
128| 50%
192| 75%
249| 100% (approximately)

Example code:

CCPR1L = 64;   // Approximately 25%
CCPR1L = 128;  // Approximately 50%
CCPR1L = 192;  // Approximately 75%

Note: These examples assume the two least significant duty-cycle bits in CCP1CON remain zero, as in the original code. For finer adjustment, use CCP1CON bits 5:4 along with CCPR1L. Keep the duty-cycle value within the valid range for the selected PR2 setting.

Software & Tools

- MPLAB X IDE
- XC8 Compiler
- Embedded C
- Proteus Design Suite

Working Principle

The CCP1 module operates in PWM mode using Timer2 as its time base. PR2 determines the PWM period, while CCPR1L and CCP1CON determine the duty cycle.

Simulation & Testing

Successfully built, simulated and tested in Proteus.

Project Structure

- "main.c" – Source code
- "README.md" – Project documentation
