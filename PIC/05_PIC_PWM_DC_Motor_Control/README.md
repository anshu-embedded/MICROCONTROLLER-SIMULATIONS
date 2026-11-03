PIC16F877A DC Motor Control using PWM

Overview

A DC motor control project developed using the PIC16F877A microcontroller and Embedded C. Hardware PWM is generated through the CCP1 module and used to drive a DC motor through a BC547 transistor.

Features

- Hardware PWM generation using CCP1.
- DC motor control using PWM.
- Timer2 configuration for PWM operation.
- Approximately 50% PWM duty cycle.
- Continuous motor operation at a fixed PWM duty cycle.

Hardware Components

- PIC16F877A Microcontroller
- DC Motor
- BC547 NPN Transistor
- 1N4007 Diode
- 1 kΩ Base Resistor
- 4 MHz Crystal Oscillator
- 22 pF Capacitors
- 10 kΩ MCLR Pull-up Resistor

Pin Configuration

PIC Pin| Connection
RC2/CCP1| PWM output to transistor base through 1 kΩ resistor

Circuit Working

The PIC16F877A generates a PWM signal on the RC2/CCP1 pin.

The PWM signal drives the base of the BC547 transistor through a 1 kΩ resistor. The transistor acts as a switching device to control current through the DC motor.

A 1N4007 diode is connected across the motor to protect the circuit from back EMF.

PWM Configuration

Parameter| Value
Oscillator Frequency| 4 MHz
PR2| 124
Timer2 Prescaler| 1:1
CCPR1L| 62
PWM Frequency| Approximately 8 kHz
Duty Cycle| Approximately 50%

How to Change Motor Speed

The PWM duty cycle can be changed by modifying the "CCPR1L" value in the "PWM_Init()" function.

Example values:

CCPR1L| Approximate Duty Cycle
31    | 25%
62    | 50%
93    | 75%
124   | Approximately 100%

A higher duty cycle generally increases the average voltage applied to the motor and can increase its speed. Actual speed also depends on motor load and supply voltage.

Note: The current program uses a fixed 50% duty cycle. Variable speed control through a potentiometer or buttons is not implemented.

Software & Tools

- MPLAB X IDE
- XC8 Compiler
- Embedded C
- Proteus Design Suite

Simulation & Testing

The complete circuit was built, simulated and tested successfully in Proteus. The DC motor was observed running with the generated PWM signal.

Project Structure

- "main.c" – PWM initialization and motor control source code
- "README.md" – Project documentation
