
#include <U8glib.h> // Library for OlED display https://github.com/olikraus/u8glib/, documentation so you can learn how to draw with U8glib https://github.com/olikraus/u8glib/wiki/userreference#drawbox
#include <I2CMux.h> // Library for TCA9548A by Alvaro Ferran https://github.com/alvaroferran/I2C-multiplexer
#include <Wire.h>

#define I2CMulti_Addr 0x70  // Address of the I2C Multiplexer board
#define WIDTH 128 // OLED display width, in pixels
#define HEIGHT 64 // OLED display height, in pixels

I2CMux I2CMulti(I2CMulti_Addr);  // Init of the multiplexer library


// Step One: Declare multiplexer channel number
int target1 = 2;   
int target2 = 4;   
int target3 = 7;  

// Step Two: Declare new oled and number it
U8GLIB_SSD1306_128X64 First_Oled(U8G_I2C_OPT_FAST);  // Init of the OLED #1 using I2C
U8GLIB_SSD1306_128X64 Second_Oled(U8G_I2C_OPT_FAST);  // Init of the OLED #2 using I2C
U8GLIB_SSD1306_128X64 Third_Oled(U8G_I2C_OPT_FAST);  // Init of the OLED #2 using I2C


void setup() {
  
  Wire.begin();
  
  
  // Step Three: Set oled settings
  First_Oled.setFont(u8g_font_courR10);
  Second_Oled.setFont(u8g_font_courR10);
  Third_Oled.setFont(u8g_font_courR14);
  
  // Step Four: Switch to multiplexer i2c channel
  I2CMulti.switchToBus(target1);
  // Step Five: draw on oled on that multiplexer channel
  First_Oled.firstPage(); 
  do {
  // drawing content
  First_Oled.drawStr( 0, 10, "This is a test");
  First_Oled.drawStr(0, 25, "to discover");
  First_Oled.drawStr(0, 40, "How much you");
  First_Oled.drawStr(0, 55, "can say on...");
  } 
  while( First_Oled.nextPage() );


  // repeat steps 4 and 5
  I2CMulti.switchToBus(target2);  
  Second_Oled.firstPage(); 
  do {
  Second_Oled.drawStr( 0, 20, "little screens");
  Second_Oled.drawStr( 0, 40, "like this?");
  } 
  while( Second_Oled.nextPage() );

  // repeat steps 4 and 5
  I2CMulti.switchToBus(target3); 
  Third_Oled.firstPage(); 
  do {
  Third_Oled.drawStr( 0, 15, "PARDON");
  Third_Oled.drawStr( 0, 32, "the");
   Third_Oled.drawStr( 0, 55, "INTRUSION");
  } 
  while( Third_Oled.nextPage() );

}


void loop() {}
