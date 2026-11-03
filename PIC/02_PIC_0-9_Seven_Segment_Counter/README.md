PIC16F877A 0–9 Seven Segment Counter

Overview

A digital counter developed using the PIC16F877A microcontroller and Embedded C. It displays numbers from 0 to 9 on a seven-segment display using a push button.

Features

- Displays digits from 0 to 9.
- Increments the count with each button press.
- Automatically resets to 0 after 9.
- Uses a lookup table for seven-segment digit patterns.
- Includes software button debouncing.

Hardware Components

- PIC16F877A Microcontroller
- Seven Segment Display (Common Cathode)
- Push Button
- Current-limiting resistors

Pin Configuration

PIC Pin| Connection
RB0–RB7| Seven-segment display segments
RD0| Push Button

Software & Tools

- MPLAB X IDE
- XC8 Compiler
- Embedded C
- Proteus Design Suite

Working Principle

The push button connected to RD0 is used to increment the counter. Each button press increases the displayed digit by one. After reaching 9, the counter resets to 0.

Simulation & Testing

Successfully built, simulated and tested in Proteus.

Project Structure

- "main.c" – Source code
- "README.md" – Project documentation
