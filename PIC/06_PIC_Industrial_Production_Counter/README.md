# PIC16F877A Industrial Production Counter

## Overview
This project implements a digital production counter using the PIC16F877A microcontroller and a 7-segment display.

It counts incoming pulses through the external interrupt pin (RB0/INT0) and displays the production count from 0 to 9.

The project demonstrates how external interrupts can be used in industrial product-counting applications.

## Components Used
- PIC16F877A Microcontroller
- 7-Segment Display (Common Cathode)
- Clock / Pulse Generator (Proteus simulation)
- Connecting wires

## Working Principle
1. A pulse is applied to the RB0/INT0 pin.
2. The PIC16F877A detects the rising edge using an external interrupt.
3. The interrupt service routine (ISR) increments the counter.
4. The updated count is displayed on the 7-segment display.
5. After reaching 9, the counter resets to 0.

## Pin Configuration

| PIC Pin         | Function                 |
| RB0 / INT0      | External pulse input     |
| PORTD (RD0–RD7) | 7-segment display output |

## Interrupt Configuration
- External Interrupt: INT0
- Interrupt Edge: Rising Edge
- Global Interrupt: Enabled
- External Interrupt: Enabled

## Simulation
The project was developed and tested in Proteus using a clock/pulse generator to simulate incoming product-detection pulses.

## Future Hardware Implementation
For real-world production counting, an IR object detection sensor or IR break-beam sensor can be connected to RB0/INT0.

When a product passes through the sensor, it generates a pulse that can be counted by the microcontroller.

## Applications
- Conveyor belt product counting
- Industrial production monitoring
- Automated object counting systems
- Manufacturing line monitoring

## Microcontroller
PIC16F877A

## Programming Language
Embedded C
