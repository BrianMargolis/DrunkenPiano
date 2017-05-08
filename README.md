# DrunkenPiano
Ever wondered what a function sounds like?

This is a Max program that performs a drunk walk through a domain of a given function and interprets the resultant y-values in the context of a pre-defined scale. A drunk walk is a type of random walk where the range `r` and step size `ss` are set such that the walk will make random jumps in the range `[0, r)` with a step size `<= ss`. The scale is pre-defined by indicating which numbers 1-12, corresponding to a chromatic scale, are to be included in playback. An additional parameter for the number of octaves gives additional expressivity.

The hardware is an Arduino Uno with 3 rotary potentiometers (dials) and 3 linear potentiometers (sliders). The Arduino program `encoder.ino` reads in from the sensors and writes it to serial output; Max than reads that serial output in and uses it to control several parameters, currently:

1. Tempo
2. Range of drunk walk
3. Step size of drunk walk
4. Additive pitch scaling factor (key shifter)
5. Note duration
6. MIDI velocity

To run the code, you need [Max](https://cycling74.com/products/max/), which has a 30-day free trial for new users. It can play without the Arduino set-up, just with less fine-tune and convenient control of those 6 parameters.

This was built over a weekend at Northwestern's 2017 Physical Computing for Interactive Music workshop. Thank you to Professor Michael Gurevich of the University of Michigan for running the workshop, and to Professor Bryan Pardo of Northwestern for hosting it.
