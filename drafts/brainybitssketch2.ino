// Library for OlED display https://github.com/olikraus/u8glib/
// documentation so you can learn how to draw with U8glib https://github.com/olikraus/u8glib/wiki/userreference#drawbox
#include <U8glib.h>   

#include <I2CMux.h>    // Library for TCA9548A by Alvaro Ferran https://github.com/alvaroferran/I2C-multiplexer
#include <Wire.h>

#define I2CMulti_Addr 0x70  // Address of the I2C Multiplexer board

#define WIDTH 128 // OLED display width, in pixels
#define HEIGHT 64 // OLED display height, in pixels

int selected_oled = 2;  // Use to keep track of which I2C channel is selected on the Multiplexer

I2CMux I2CMulti(I2CMulti_Addr);  // Init of the multiplexer library

int target1 = 2;   // Counter variable for OLED #1
int target2 = 7;   // Counter variable for OLED #2


U8GLIB_SSD1306_128X64 First_Oled(U8G_I2C_OPT_FAST);  // Init of the OLED #1 using I2C
U8GLIB_SSD1306_128X64 Second_Oled(U8G_I2C_OPT_FAST);  // Init of the OLED #2 using I2C

void setup() {

  Wire.begin();
  

// Select font to use
  First_Oled.setFont(u8g_font_courR24);
  Second_Oled.setFont(u8g_font_unifont);
  
  I2CMulti.switchToBus(2);  // Switch to multiplexer i2c channel #2
  First_Oled.setContrast(100);  // Set oled contrast at startup

// Put stuff on OLED at startup    
  First_Oled.firstPage(); 
    do {
        // drawing content
        First_Oled.drawStr( 0, 32, "Hello");
      } 
    while( First_Oled.nextPage() );

  I2CMulti.switchToBus(7);
  Second_Oled.setContrast(0);
  
  Second_Oled.firstPage(); 
    do {
        Second_Oled.drawStr( 0, 32, "World");
      }
    while( Second_Oled.nextPage() );

  I2CMulti.switchToBus(2); // Select i2c multiplexer channel to #2            
  
}


void loop() {
  delay(3000);
  
  I2CMulti.switchToBus(target2);  // Switch to multiplexer i2c channel #2
  if (target2 == 7) {
    target2 = 2;
  } else if (target2 == 2) {
    target2 = 7;
  }

// Put stuff on OLED at startup    
  First_Oled.firstPage(); 
    do {
        // drawing content
        
        First_Oled.drawStr( 0, 32, "Hello");

          for(int16_t i=0; i< WIDTH/2; i+=2) {
            First_Oled.drawBox(i, i, WIDTH-2*i, HEIGHT-2*i);
            delay(1);
          }
      } 
    while( First_Oled.nextPage() );

  I2CMulti.switchToBus(target1);
  
  if (target1 == 7) {
    target1 = 2;
  } else if (target1 == 2) {
    target1 = 7;
  }
  
    Second_Oled.firstPage(); 
    do {
        Second_Oled.drawStr( 0, 32, "World");
      }
    while( Second_Oled.nextPage() );


//    // add another oled here
//    I2CMulti.switchToBus(2);  // Switch to multiplexer i2c channel  
//    First_Oled.firstPage(); // draw on oled
//    
//    do {
//        // drawing content 
//        First_Oled.drawStr( 0, 32, "Hello World");
//      } 
//    while( First_Oled.nextPage() );

}
