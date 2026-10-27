AVR LED Pattern Controller

Project Overview

This project implements an LED Pattern Controller using an AVR microcontroller and Embedded C. A push button is used to switch between four different LED operating modes.

Hardware Components

- AVR microcontroller (ATmega328P, if used)
- 8 LEDs connected to PORTD
- Push button connected to PB0
- External pull-down resistor
- LED current-limiting resistors

Operating Modes

1. Mode 0 – LEDs OFF: All LEDs remain OFF.
2. Mode 1 – LEDs ON: All LEDs turn ON.
3. Mode 2 – LED Blinking: All LEDs blink at regular intervals.
4. Mode 3 – Sequential LED Pattern: LEDs turn ON one by one in sequence.

Each button press advances to the next mode. After Mode 3, the controller returns to Mode 0.

Pin Configuration

Component| Microcontroller Pin
Push button| PB0
LED outputs| PORTD (PD0–PD7)

The push button uses an external pull-down resistor. PB0 reads LOW when the button is released and HIGH when pressed.

Software and Tools

- Embedded C
- AVR-GCC compatible toolchain
- Proteus Design Suite

Concepts Demonstrated

- GPIO input and output configuration
- Push-button interfacing
- Software debouncing
- Bitwise operations
- Delay-based LED patterns
- State-based control logic

Simulation and Testing

The project has been successfully simulated and tested in Proteus.
