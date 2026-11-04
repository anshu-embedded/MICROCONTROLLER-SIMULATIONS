# PIC16F877A LDR Light and Darkness Detector

## Overview
This project implements a light and darkness detection system using the PIC16F877A microcontroller and an LCD display.

A digital-output LDR sensor module is used to detect light conditions. The detected status is displayed on a 16x2 LCD.

## Components Used
- PIC16F877A Microcontroller
- Digital LDR Sensor Module
- 16x2 LCD Display
- Connecting Wires

## Working Principle
1. The LDR sensor module detects the surrounding light conditions.
2. Its digital output is connected to RD0 of the PIC16F877A.
3. The microcontroller reads the sensor output.
4. If RD0 is HIGH, the LCD displays "LIGHT DETECTED".
5. If RD0 is LOW, the LCD displays "DARKNESS DETECT".

## Pin Configuration

| PIC16F877A Pin | Function |
|---|---|
| RD0 | Digital LDR sensor output |
| RB0 | LCD RS |
| RB1 | LCD EN |
| RB4–RB7 | LCD Data (D4–D7) |

## LCD Configuration
- Display: 16x2 LCD
- Communication: 4-bit mode
- Data interface: PORTB

## Simulation
The project was developed and tested in Proteus to demonstrate digital light detection and LCD status display.

## Applications
- Automatic lighting systems
- Light detection and monitoring
- Smart home automation
- Day and night detection systems

## Microcontroller
PIC16F877A

## Programming Language
Embedded C
