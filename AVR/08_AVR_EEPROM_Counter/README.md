AVR EEPROM-Based Persistent Counter

Project Overview

This project demonstrates an EEPROM-based counter using an AVR microcontroller and Embedded C. A push button increments the counter, and the updated value is stored in the microcontroller's internal EEPROM to retain data across power cycles.

Features

- Internal EEPROM read and write operations
- Push-button interfacing with software debouncing
- Persistent counter storage
- GPIO-based output display
- Register-level programming using Embedded C

Hardware Components

- AVR microcontroller (ATmega328P, if used)
- Push button
- Four output LEDs connected to PB1–PB4
- Pull-up configuration for the push button
- Proteus Design Suite, if used for simulation

Pin Configuration

Function| Microcontroller Pin
Push button| PB0
Output LEDs| PB1–PB4
EEPROM address| 100

Working Principle

1. The program reads the saved counter value from EEPROM address 100 during startup.
2. The counter value is represented through four output pins.
3. When the push button is pressed, the counter increments.
4. The updated value is written to EEPROM.
5. The output pins are updated to represent the lower four bits of the counter.

Software and Tools

- Embedded C
- AVR-GCC compatible toolchain
- Proteus Design Suite, if used for simulation

Concepts Demonstrated

- Internal EEPROM read/write
- Non-volatile data storage
- GPIO input and output configuration
- Push-button debouncing
- Bitwise operations
- Persistent state management

