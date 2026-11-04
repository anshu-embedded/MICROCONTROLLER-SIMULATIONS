# PIC16F877A Smart Car Parking Assistant

## Overview
This project implements a smart car parking assistance system using the PIC16F877A microcontroller and an HC-SR04 ultrasonic sensor.

It measures the distance between the vehicle and nearby obstacles and provides visual and audible warnings to assist the driver during parking.

## Components Used
- PIC16F877A Microcontroller
- HC-SR04 Ultrasonic Sensor
- 16x2 LCD Display
- Buzzer
- LED
- Push Button

## Working Principle
1. The HC-SR04 sensor measures the distance to nearby obstacles.
2. The PIC16F877A calculates the distance using the Echo pulse duration.
3. The measured distance is displayed on the LCD.
4. The buzzer and LED provide warnings based on obstacle distance.
5. A push button is used to turn parking assistance mode ON or OFF.

## Distance-Based Warning System

| Distance | Warning |
|---|---|
| Above 40 cm | Slow LED blinking |
| 21–40 cm | LED and buzzer warning |
| 11–20 cm | Faster warning |
| 0–10 cm | Very fast warning |

## Pin Configuration

| PIC16F877A Pin | Component             |

| RB1            | Mode Selection Button |
| RC0            | HC-SR04 Trigger       |
| RC1            | HC-SR04 Echo          |
| RC2            | Buzzer                |
| RC3            | LED                   |
| RB0            | LCD RS                |
| RB1            | LCD EN                |
| RD4–RD7        | LCD Data (D4–D7)      |

## Features
- Ultrasonic distance measurement
- Real-time LCD distance display
- Distance-based warning alerts
- LED and buzzer control
- Parking mode ON/OFF selection
- Timer1-based pulse measurement

## Applications
- Vehicle parking assistance
- Obstacle detection
- Reverse parking warning systems
- Embedded automotive applications

## Microcontroller
PIC16F877A

## Programming Language
Embedded C
