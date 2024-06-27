# Real-Time-Clock
This project is an Atmega32 that uses its timer2 (Internal Hardware) to count seconds which is displayed on two 7 Segments using Concept of Multiplexing (for more details go to my project of multiplexing two 7 Segments Common Anode) and program can run when timer2 is operating, then when timer2 increased by a value equal to 1 second, timer2 requests an interrupt to change a counter of seconds (Global Varaible) in main program, then after 60 seconds, there are if conditions, these if conditions make counter of seconds equal to zero if it reaches its maximum value (59) and adjust counter of minutes and counter of hours according to value of counter of seconds


## Devices used:

-Atmega32 (where we put our code to do specific functions)

-LCD 16x2 (for displaying Temperature in Celsius)

-7Segments (for displaying numbers)

-Crystal Oscillator 32.768 KHz (as mentioned in datasheet of atmega32 to make timer2 to count seconds accurately)

-18 pf capacitors (as mentioned in datasheet of atmega32)

-Keypad (to set time if 1 is Pressed)

## tools used:

-Proteus 8 Professional

-Atmel Studio 6.0

## note:

-There is a video provided in code folder
