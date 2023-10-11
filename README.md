/************************
 * File Name: LCD20x04.h
 * Description:	This file is the header	file for the LCD (20x04) module for PIC 
   microcontrollers.
 * Created on: 11-10-2023
 * Author: Krishn Singh Chauhan
 ************************/

Setting up a 20x4 LCD (Liquid Crystal Display) module typically involves connecting it to a microcontroller like Arduino and writing code to control the display. Here's a general guide on how to set up a 20x4 LCD with an Arduino:

Components Needed:

PIC (e.g.,16 series)
20x4 LCD display module with an HD44780 controller.
Potentometer (10k ohms) for contrast adjustment.
Breadboard and jumper wires.
Wiring Connections:

Connect the components as follows:

LCD VSS (Ground) to PIC GND.
LCD VDD (Power) to PIC 5V.
LCD V0 (Contrast) to the center pin of the potentiometer.
LCD RW (Read/Write) to GND (as we're only writing).
LCD RS (Register Select) to PIC's pin.
LCD E (Enable) to  PIC's pin.
LCD D4-D7 to  PIC's pin (e.g., 4, 5, 6, 7).
Ensure that you also connect the outer pins of the potentiometer to 5V and GND to adjust the contrast.

