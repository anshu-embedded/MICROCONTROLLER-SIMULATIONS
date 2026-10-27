AVR SPI Master Communication with 74HC595

Project Overview

This project demonstrates SPI master communication using the ATmega328P microcontroller and a 74HC595 serial-in, parallel-out shift register. The microcontroller transmits 8-bit data patterns through SPI, and the shift register outputs the received bits to LEDs.

Objectives

- Configure the ATmega328P as an SPI master.
- Transmit 8-bit data using the SPI data register.
- Use the 74HC595 to convert serial data into parallel LED outputs.
- Demonstrate different LED patterns at one-second intervals.

Hardware / Components

- ATmega328P microcontroller
- 74HC595 shift register
- LEDs and current-limiting resistors
- Power supply and connecting wires
- Proteus simulation (if used)

SPI Pin Configuration

ATmega328P Pin| Function
PB2 / SS| Configured as output; used as the shift-register latch control in this code
PB3 / MOSI| SPI data output
PB4 / MISO| SPI data input; not used for the 74HC595 data path
PB5 / SCK| SPI clock output

Connect MOSI to the 74HC595 serial data input (DS), SCK to SHCP (shift-register clock), and PB2 to STCP (storage-register/latch clock). Ensure the 74HC595 power, ground, output-enable and reset pins are connected appropriately.

Data Patterns

The firmware repeatedly transmits these hexadecimal values:

- "0xAA" — alternating bit pattern
- "0x55" — inverse alternating bit pattern
- "0xFF" — all bits HIGH
- "0x00" — all bits LOW

Each pattern is sent with an approximately one-second delay before the next pattern.

How It Works

1. Configure MOSI, SCK and the latch-control pin as outputs.
2. Enable SPI and select master mode.
3. Write each byte to "SPDR".
4. Wait until the "SPIF" flag indicates that the transfer has completed.
5. Pulse the latch-control pin to update the 74HC595 parallel outputs.
6. Repeat with the next data pattern.

Software / Tools

- Embedded C
- AVR-GCC-compatible toolchain
- Microchip ATmega328P
- Proteus 

Learning Outcomes

- SPI master configuration and data transfer
- SPI registers and transfer-complete flag
- Serial-to-parallel data conversion
- Shift-register interfacing and LED control

Project Status

Practical learning project. Describe hardware or simulation testing only to the extent actually completed.
