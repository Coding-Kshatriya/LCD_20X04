
/************************
 * File Name: LCD20x04.h
 * Description:	This file is the header	file for LCD (20x04) module
 * Created on: 11-10-2023
 * Author: Krishn Singh Chauhan
 ************************/



#ifndef LCD20x04_H_
#define LCD20x04_H_
#include <inttypes.h>
#include "Print.h"
#include <stdint.h>
#include <stddef.h>


// LCD commands
#define LCD_CLEAR_DISPLAY       0x01
#define LCD_RETURN_HOME         0x02
#define LCD_ENTRY_MODE_SET      0x04
#define LCD_DISPLAY_CONTROL     0x08
#define LCD_CURSOR_SHIFT        0x10
#define LCD_FUNCTION_SET        0x20
#define LCD_SET_CGRAM_ADDR      0x40
#define LCD_SET_DDRAM_ADDR      0x80

// LCD display control options
#define LCD_DISPLAY_ON          0x04
#define LCD_DISPLAY_OFF         0x00
#define LCD_CURSOR_ON           0x02
#define LCD_CURSOR_OFF          0x00
#define LCD_BLINK_ON            0x01
#define LCD_BLINK_OFF           0x00

//LCD 4 line display (20x4)
#define LCD_LINE_0              0x80
#define LCD_LINE_1              0x40
#define LCD_LINE_2              0x14
#define LCD_LINE_3              0x54


/************************
 * Function declarations
 ************************/
void LCD20x04_lcd_init(void);
void LCD20x04_lcd_clear(void);
void LCD20x04_delay_ms(int milliseconds);
void LCD20x04_lcd_send_nibble(uint8_t val);
void LCD20x04_lcd_command(uint8_t cmd);
void LCD20x04_lcd_write_char(uint8_t data);
void LCD20x04_lcd_print( char *print);
void LCD20x04_SetPosition(char row, char col);
#endif /* LCD20X04_H_ */
