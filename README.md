# Octopus
Arduino code for sound-to-light 3D printed octopus

This runs on an Arduino Mega 2560.

There are only 15 PWM ( analog out ) pins so the head and front four tentacles have continuously variable RGB LEDs.

The four remaining tentacles have 8 combinations of digital drive for each RGB LED.

Rather than use linear sound-to-light, the effect is made by prematurely ending a loop-counter. After an LED has been programmed, the new colour can be displayed for n counts, or the count to n can be aborted if the sound comparator is triggered.

Various effects are embedded in the code. 

