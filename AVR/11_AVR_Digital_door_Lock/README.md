AVR Digital Door Lock System

Overview

A password-based digital door lock system developed using an AVR microcontroller, a 4×3 keypad, a 16×2 LCD, and internal EEPROM.

Features

- Four-digit password entry through a keypad
- Password masking on the LCD
- Password verification for access
- Change-password option
- Password stored in internal EEPROM
- Password retained after power cycling
- Password confirmation before saving a new password

Hardware and Tools

- ATmega328P-compatible AVR microcontroller
- 4×3 matrix keypad
- 16×2 LCD in 4-bit mode
- MPLAB X/AVR toolchain as applicable
- Proteus simulation

Working Principle

1. The system loads the stored password from EEPROM.
2. The user selects Unlock or Change Password.
3. The entered password is checked against the saved password.
4. Correct credentials grant access; incorrect credentials are denied.
5. Password changes require the current password and confirmation of the new password.

Tested and verified  in proteus.
