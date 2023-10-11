/********************************************************************************
  LCD_20x04 Library - Namaste

 Demonstrates the use of a 20x4 LCD display. The LCD_20x04
 the library works on a 20x04 LCD display that is compatible with the
 Hitachi HD44780 driver. Many are out there, and you
 can usually tell them by the 16-pin interface.

 This program works on 16 series of PIC microcontrollers,
 And prints "Namaste!" on the LCD.
 **********************************************************************************/



/************************
 * Defines and Macros
 ************************/ 

#define RS  RC5
#define EN  RC3
#define D4  RE4
#define D5  RE5
#define D6  RE6
#define D7  RE7


/************************
 * LCD commands
 ************************/ 

#define LCD_CLEAR_DISPLAY       0x01
#define LCD_RETURN_HOME         0x02
#define LCD_ENTRY_MODE_SET      0x04
#define LCD_DISPLAY_CONTROL     0x08
#define LCD_CURSOR_SHIFT        0x10
#define LCD_FUNCTION_SET        0x20
#define LCD_SET_CGRAM_ADDR      0x40
#define LCD_SET_DDRAM_ADDR      0x80


/************************
 * LCD display control options
 ************************/ 

#define LCD_DISPLAY_ON          0x04
#define LCD_DISPLAY_OFF         0x00
#define LCD_CURSOR_ON           0x02
#define LCD_CURSOR_OFF          0x00
#define LCD_BLINK_ON            0x01
#define LCD_BLINK_OFF           0x00



// Function to delay to the LCD

void LCD20x04_delay_ms(int milliseconds) {


    int cycles = (milliseconds * 1000);
    int i;
 
    for ( i = 0; i < cycles; i++) {
        // This loop will take time, creating a delay_ms
    }
}



// Function to send a 4-bit data/command to the LCD

void LCD20x04_lcd_send_nibble(uint8_t val) {
   
    

    // Set the 4 data bits accordingly
  
        D4 = (bits>>0) & 0x01;
        D5 = (bits>>1) & 0x01;
        D6 = (bits>>2) & 0x01;
        D7 = (bits>>3) & 0x01;
 

        EN=1;  /*High-to-low pulse on Enable pin to latch data*/
        LCD20x04_delay_ms(1);
        EN=0;
        LCD20x04_delay_ms(40);
  
     // Pulse the enable pin

}

// Function to send a command to the LCD

void LCD20x04_lcd_command(uint8_t cmd) {
    // RS = 0 for command mode
    RS=0;

    // Send high nibble
    LCD20x04_lcd_send_nibble(cmd >> 4);

    // Send low nibble
    LCD20x04_lcd_send_nibble(cmd);

    // Some commands require longer delays
    if (cmd == LCD_CLEAR_DISPLAY || cmd == LCD_RETURN_HOME) {
        // Delay for LCD to complete the operation
        // You can use a delay function here

      
    }

    
}

// Function to write a character to the LCD

void LCD20x04_lcd_write_char(uint8_t data) {
    // RS = 1 for data mode
    RS=1;

    // Send high nibble
    LCD20x04_lcd_send_nibble(data >> 4);

    // Send low nibble
    LCD20x04_lcd_send_nibble(data);

    // Delay for LCD to process the data
    // You can use a delay function here
}

// Function to initialize the LCD

void LCD20x04_lcd_init() {

  
    RS=0; // RS = 0 (Command mode)
    EN=0; // EN = 0 (Enable mode)
    LCD20x04_lcd_send_nibble(0x03); 
    LCD20x04_delay_ms(5);
    LCD20x04_lcd_send_nibble(0x03);
    LCD20x04_delay_ms(100);
    LCD20x04_lcd_send_nibble(0x03);
    LCD20x04_lcd_send_nibble(0x02);


    LCD20x04_lcd_command(0x40); // Funtion set

    LCD20x04_lcd_command(0x0C); // Display On/Off: Display ON, Cursor OFF, Blink OFF
 
   


}

void LCD20x04_lcd_clear(){

   LCD20x04_lcd_command(0x01); // Clear Display
   LCD20x04_delay_ms(1);
  
}


void LCD20x04_lcd_print( char *print)    // function to send string to LCD
{
int x;
for(x=0;print[x]!=0;x++)
{
    LCD20x04_lcd_write_char(print[x]);

}
}

void LCD20x04_SetPosition(char row, char col)
{
    switch (row) {
    case 0:
        col |= 0x80;
        break;
    case 1:
        col |= 0x40;
        break;
    case 2:
        col |= 0x14;
        break;
    case 3:
        col |= 0x54;
        break;
    }
    LCD20x04_lcd_command(col);
}





int main() {
  // Initialize PORT
  
    TRISC=0; // Port C
    TRISE=0; // Port E
    
    OSCCON=0b01111100; //for frequency setup as per your need
 


    LCD20x04_lcd_init();


    LCD20x04_lcd_clear();
    LCD20x04_SetPosition(0,0);
    LCD20x04_delay_ms(1000);
    LCD20x04_lcd_print("Namaste!");
    LCD20x04_delay_ms(1000);


}


