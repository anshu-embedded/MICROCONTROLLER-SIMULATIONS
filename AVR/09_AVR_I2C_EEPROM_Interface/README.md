AVR I2C EEPROM Read/Write Interface

Project Overview

This project demonstrates I2C communication between an AVR microcontroller and an external 24C02 EEPROM. The microcontroller writes a test byte to a specified EEPROM memory address, reads the stored data back, and displays the received value through PORTB outputs.

Features

- I2C/TWI peripheral initialization
- I2C start and stop condition generation
- Serial data transmission and reception
- External 24C02 EEPROM read/write operations
- Memory-address-based data access
- GPIO output for displaying the retrieved data

Hardware Components

- AVR microcontroller 
- 24C02 I2C EEPROM
- LEDs or output indicators connected to PORTB
- Pull-up resistors on SDA and SCL lines
- Proteus Design Suite

Pin Configuration

For an ATmega328P:

Function| Microcontroller Pin
I2C SDA| PC4 (SDA)
I2C SCL| PC5 (SCL)
Data output| PORTB (PB0–PB7)

EEPROM Configuration

- EEPROM IC: 24C02
- I2C write control byte: "0xA0"
- I2C read control byte: "0xA1"
- EEPROM memory address: "0x10"
- Test data: "0xAA"
- Expected read-back value: "0xAA"

The control bytes "0xA0" and "0xA1" assume the 24C02 hardware address pins A0, A1, and A2 are LOW.

Working Principle

1. Initialize the AVR TWI peripheral with an I2C clock of approximately 100 kHz.
2. Generate an I2C START condition.
3. Send the EEPROM write control byte "0xA0".
4. Send memory address "0x10" and data byte "0xAA".
5. Generate a STOP condition and allow time for the EEPROM write cycle.
6. Read data from the same EEPROM address using I2C communication.
7. Output the retrieved byte through PORTB.

Software and Tools

- Embedded C
- AVR-GCC compatible toolchain
- Proteus Design Suite

Concepts Demonstrated

- I2C/TWI communication
- Register-level peripheral configuration
- External EEPROM interfacing
- Serial data transmission and reception
- Non-volatile memory access
- GPIO output control

Project Files

- "AVR_I2C_EEPROM.c" — Embedded C source code
- Proteus project files — Circuit design and simulation

Simulation and Testing

The project uses a 24C02 EEPROM to demonstrate writing and reading a byte over I2C. The expected test value is "0xAA", which is output through PORTB after reading.
