# PIC16F877A Automotive LED Indicator with Hazard Control

## Overview
This project implements an automotive turn indicator and hazard warning system using the PIC16F877A microcontroller, Embedded C, and a 16x2 LCD.

A push button is used to cycle through four operating modes: OFF, RIGHT, LEFT, and HAZARD.

## Components Used
- PIC16F877A Microcontroller
- 16x2 LCD Display
- LEDs for Left and Right Indicators
- Push Button
- Connecting Wires

## Working Principle
1. The push button connected to RD2 selects the operating mode.
2. In OFF mode, both indicators remain OFF.
3. In RIGHT mode, the right indicator turns ON.
4. In LEFT mode, the left indicator turns ON.
5. In HAZARD mode, both indicators blink simultaneously at 500 ms intervals.
6. The selected mode is displayed on the LCD.

## Pin Configuration

| PIC16F877A Pin | Function                   |
| RD0            | Right Indicator Output     |
| RD1            | Left Indicator Output      |
| RD2            | Mode Selection Push Button |
| RB0            | LCD RS                     |
| RB1            | LCD EN                     |
| RB4–RB7        | LCD Data Pins (D4–D7)      |

## Features
- Four operating modes
- Push-button mode selection
- Hazard warning functionality
- LCD-based mode indication
- Software button debounce

## Simulation
Developed and tested using Proteus simulation.

## Applications
- Automotive indicator systems
- Vehicle hazard warning systems
- Embedded control applications

## Microcontroller
PIC16F877A

## Programming Language
Embedded C
