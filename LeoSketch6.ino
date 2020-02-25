
#include <U8g2lib.h> // Library for OlED display https://github.com/olikraus/u8glib/, documentation so you can learn how to draw with U8glib https://github.com/olikraus/u8glib/wiki/userreference#drawbox
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
int target4 = 5;

// Step Two: Declare new oled and number it
U8G2_SSD1306_128X64_NONAME_F_HW_I2C First_Oled(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
U8G2_SSD1306_128X64_NONAME_F_HW_I2C Second_Oled(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
U8G2_SSD1306_128X64_NONAME_F_HW_I2C Third_Oled(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
U8G2_SSD1306_128X64_NONAME_F_HW_I2C Fourth_Oled(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  
  Wire.begin();
First_Oled.begin();
 Second_Oled.begin();
 Third_Oled.begin();
 Fourth_Oled.begin();
 
  
  
  // Step Three: Set oled settings
 First_Oled.setFont(u8g2_font_unifont_tr);
 Second_Oled.setFont(u8g2_font_tenthinguys_tr);
 Third_Oled.setFont(u8g2_font_tenfatguys_tr);
 Fourth_Oled.setFont(u8g2_font_courB14_tf);
  
 

}


void loop() {
  // Step Four: Switch to multiplexer i2c channel
  I2CMulti.switchToBus(target1);
  // Step Five: draw on oled on that multiplexer channel
  
//  First_Oled.clearBuffer(); 
//
//  // drawing content
//  First_Oled.drawStr( 0, 10, "This is a test");
//  First_Oled.drawStr(0, 25, "to discover");
//  First_Oled.drawStr(0, 40, "How much you");
//  First_Oled.drawStr(0, 55, "can say on...");
//  First_Oled.sendBuffer();
//  delay(2000);

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
//  Second_Oled.clearBuffer(); 
//  Second_Oled.drawStr( 0, 20, "little screens");
//  Second_Oled.drawStr( 0, 40, "like this.");
//  Second_Oled.sendBuffer();
//  delay(2000);

    Second_Oled.firstPage(); 
  do {
  Second_Oled.drawStr( 0, 20, "little screens");
  Second_Oled.drawStr( 0, 40, "like this.");
  } 
  while( Second_Oled.nextPage() );

  // repeat steps 4 and 5
  I2CMulti.switchToBus(target3); 
//  Third_Oled.clearBuffer(); 
//  Third_Oled.drawStr( 0, 15, "PARDON");
//  Third_Oled.drawStr( 0, 32, "the");
//   Third_Oled.drawStr( 0, 55, "INTRUSION");
//  Third_Oled.sendBuffer();
//  delay(2000);
  Third_Oled.firstPage(); 
  do {
  Third_Oled.drawStr( 0, 15, "PARDON");
  Third_Oled.drawStr( 0, 32, "the");
   Third_Oled.drawStr( 0, 55, "INTRUSION");
  } 
  while( Third_Oled.nextPage() );

// Step Four: Switch to multiplexer i2c channel
  I2CMulti.switchToBus(target4);
  // Step Five: draw on oled on that multiplexer channel
// Fourth_Oled.clearBuffer(); 
//
//  // drawing content
//  Fourth_Oled.drawStr( 0, 10, "How about");
//  Fourth_Oled.drawStr(0, 30, "a");
//  Fourth_Oled.drawStr(0, 50, "workshop??");
//  //Fourth_Oled.drawStr(0, 55, "you can say");
//  Fourth_Oled.sendBuffer();
//   delay(2000);
 Fourth_Oled.firstPage(); 
  do {
  // drawing content
  Fourth_Oled.drawStr( 0, 10, "How about");
  Fourth_Oled.drawStr(0, 30, "a");
  Fourth_Oled.drawStr(0, 50, "workshop?");
  //Fourth_Oled.drawStr(0, 55, "you can say");
  } 
  while( Fourth_Oled.nextPage() );
  
}
