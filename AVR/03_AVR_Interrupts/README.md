# AVR External Interrupt LED Toggle

## Overview
This mini project demonstrates external interrupt handling using the ATmega328P microcontroller and AVR C.

## Components
- ATmega328P
- Push button
- LED
- Proteus simulation

## Working Principle
- Push button connected to INT0 (PD2).
- INT0 configured for falling-edge triggering.
- The interrupt service routine toggles the LED connected to PB5.
- Global interrupts enabled using `sei()`.

## Concepts Demonstrated
- External Interrupt (INT0)
- GPIO configuration
- DDRB and DDRD registers
- EICRA and EIMSK registers
- Interrupt Service Routine (ISR)

## Project Files
- AVR C source code
- Proteus simulation circuit

## Testing
Simulation-based project. Verify button operation and LED toggling in Proteus.
