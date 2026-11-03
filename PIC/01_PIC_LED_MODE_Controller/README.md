PIC16F877A LED Mode Controller

Overview

A multi-mode LED control project developed using the PIC16F877A microcontroller and Embedded C. The operating mode is selected using a push button.

Features

- Four LED operating modes:
  - Mode 0: All LEDs OFF
  - Mode 1: All LEDs ON
  - Mode 2: All LEDs Blink
  - Mode 3: Running LED Pattern
- Push-button-based mode selection
- Software button debouncing
- Eight LEDs controlled through PORTB

Hardware Components

- PIC16F877A Microcontroller
- 8 LEDs
- Current-limiting resistors
- Push button
- External pull-down resistor

Pin Configuration

PIC Pin| Connection
RB0–RB7| 8 LEDs
RD0| Push Button

Software & Tools

- MPLAB X IDE
- XC8 Compiler
- Embedded C
- Proteus Design Suite

Working Principle

The push button connected to RD0 selects the operating mode. Each valid press increments the mode. After Mode 3, the controller returns to Mode 0.

The LEDs connected to PORTB operate according to the selected mode.

Simulation & Testing

Successfully built, simulated and tested in Proteus.
