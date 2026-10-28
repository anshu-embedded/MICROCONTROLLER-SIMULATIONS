AVR ADC Data Logger with I2C EEPROM and OLED

Overview

This project uses an AVR microcontroller to read an analog input from a potentiometer, store the ADC value in an external EEPROM, read it back, and display the results on an SSD1306 OLED.

Both the external EEPROM and OLED communicate with the microcontroller through the I2C (TWI) interface.

Features

- 10-bit ADC input using ADC0
- I2C/TWI communication with external 24C02B EEPROM
- I2C communication with SSD1306 OLED
- Two-byte storage of ADC values (0–1023)
- EEPROM readback and data verification
- OLED display of ADC value, saved value, and verification status

Hardware Components

- ATmega328P AVR microcontroller
- Potentiometer connected to ADC0
- 24C02B I2C EEPROM
- SSD1306 128×32 I2C OLED
- I2C pull-up resistors and suitable power supply

Communication and Peripherals

- ADC: Converts the potentiometer's analog voltage into a 10-bit digital value.
- I2C/TWI: Transfers data between the AVR, EEPROM, and OLED using SDA and SCL.
- EEPROM: Stores the ADC value in two bytes and provides readback for verification.
- OLED: Displays the original ADC reading, EEPROM readback, and verification status.

Working Principle

1. The AVR reads the potentiometer voltage through ADC0.
2. The ADC result is stored in a 16-bit variable.
3. The lower and upper bytes are written to the external EEPROM over I2C.
4. The AVR reads both bytes back and reconstructs the stored value.
5. The original and retrieved values are compared.
6. The OLED displays both values and a verification status.

Testing

The complete firmware and circuit were tested in Proteus simulation.

Result: The ADC acquisition, I2C EEPROM read/write, OLED display, and data comparison were verified in simulation.
