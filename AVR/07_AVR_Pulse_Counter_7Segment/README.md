AVR Pulse Counter with 4-Digit Seven-Segment Display

Project Overview

This project implements a pulse counter using an AVR microcontroller and Embedded C. An external interrupt (INT0) detects rising-edge pulses, and the accumulated pulse count is displayed on a four-digit seven-segment display using multiplexing.

Features

- External interrupt-based pulse counting
- Rising-edge detection using INT0
- Four-digit seven-segment display
- Multiplexed display control
- Interrupt-safe access to the pulse counter
- Register-level programming using Embedded C

Hardware Components

- AVR microcontroller (ATmega328P, if used)
- Four-digit seven-segment display
- Pulse input source connected to INT0
- Current-limiting resistors
- Proteus Design Suite for simulation, if applicable

Pin Configuration

Function| Microcontroller Pin
INT0 pulse input| PD2
Seven-segment data outputs| PORTB
Digit select 1| PD3
Digit select 2| PD4
Digit select 3| PD5
Digit select 4| PD6

Working Principle

1. The INT0 interrupt is configured to trigger on a rising edge.
2. Each detected pulse increments the "pulseCount" variable.
3. The main loop safely copies the counter value while interrupts are briefly disabled.
4. The count is converted into individual decimal digits.
5. The four-digit display is refreshed using multiplexing.

Software and Tools

- Embedded C
- AVR-GCC compatible toolchain
- Proteus Design Suite 

Concepts Demonstrated

- External interrupts
- Interrupt Service Routines (ISR)
- Volatile variables and shared data
- Atomic access to a multi-byte counter
- GPIO configuration
- Seven-segment decoding
- Display multiplexing

Project Files

- "AVR_Pulse_Counter.c" — Embedded C source code
- Proteus project and related simulation files, if available

Important Note

This program counts input pulses; it does not currently calculate RPM. An RPM sensor and a defined measurement interval would be required to implement RPM calculation.
