# AVR PWM LED Brightness Control

## Overview
A mini project demonstrating PWM-based LED brightness control using the ATmega328P and AVR C.

## Components
- ATmega328P
- LED
- Four push buttons
- Proteus simulation

## Working Principle
- Timer/Counter0 is configured for PWM operation.
- Push buttons select different values for the OCR0A register.
- Changing the compare value adjusts the PWM output and LED brightness.

## Concepts Demonstrated
- Timer/Counter0
- PWM generation
- OCR0A compare register
- GPIO input and output configuration
- AVR register-level programming

## Project Files
- AVR C source code
- Proteus simulation file

## Testing
Simulation-based project. Verify the PWM output and LED brightness changes in Proteus.
