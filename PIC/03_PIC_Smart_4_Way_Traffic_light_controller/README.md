PIC16F877A Smart 4-Way Traffic Light Controller

Overview

A smart four-way traffic light control system developed using the PIC16F877A microcontroller and Embedded C. It manages traffic signals across four directions and supports normal, night and emergency operating modes.

Features

- Four-direction traffic light control.
- Automatic green and yellow signal sequencing.
- Night Mode with blinking yellow signals.
- Emergency Mode with all red signals ON.
- Push-button-based mode selection.
- Smart delay function that checks button inputs during signal timing.

Operating Modes

Mode| Description
Normal Mode| Automatic traffic signal sequence
Night Mode| All four yellow lights blink
Emergency Mode| All four red lights remain ON

Hardware Components

- PIC16F877A Microcontroller
- 12 LEDs (Red, Yellow and Green for four directions)
- 3 Push Buttons
- Current-limiting resistors

Pin Configuration

PIC Pins| Connection
RB0–RB2| Direction 1 (R, Y, G)
RB3–RB5| Direction 2 (R, Y, G)
RD0–RD2| Direction 3 (R, Y, G)
RD3–RD5| Direction 4 (R, Y, G)
RC0| Night Mode Button
RC1| Emergency Mode Button
RC2| Normal Mode Button

Signal Timing

- Green Signal: 5 seconds
- Yellow Signal: 2 seconds
- Night Mode blinking interval: 500 ms

Software & Tools

- MPLAB X IDE
- XC8 Compiler
- Embedded C
- Proteus Design Suite

Working Principle

In Normal Mode, opposite traffic directions receive green signals simultaneously while the other directions remain red. Yellow signals appear before the next phase.

Night Mode makes all yellow signals blink, while Emergency Mode turns all red signals ON. Push buttons allow switching between the operating modes.

Simulation & Testing

Successfully built, simulated and tested in Proteus.

Project Structure

- "main.c" – Source code
- "README.md" – Project documentation
