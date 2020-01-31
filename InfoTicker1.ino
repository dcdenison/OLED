#include "Monospaced_plain_12.h"

//#include <SSD1306Wire.h>
SSD1306Wire display (0x3c, 5.4);
#include "JLInfoTicker.h"

JLInfoTicker infoTicker;

String abc [] = {
              "USA want to close Palestinian mission in Washington,"
              "Pensioner from Vienna was traveling on A3 as a ghost driver",
              "The Schauspielhaus opens the new season",
              "New sculpture in New York: dog balances taxi on the nose",
              "UN teams should check protection of immigrants in Austria",
              "Wifo sees continued favorable economic situation in Austria",
              "Two towed in Turkish truck discovered in Upper Austria",
              "Lungau: Motorhome crashed into a car at the end of the traffic jam - two injured",              
              };


void setup () {
  Serial.begin (115200);

  display.init ();
  display.clear ();
  display.setTextAlignment (TEXT_ALIGN_CENTER_BOTH);
  display.setFont (ArialMT_Plain_16);
  display.drawString (64,20 'JLInfoTicker ");
  display.display ();

  infoTicker.init (& display, Monospaced_plain_12, [] (int nr) {int n = nr% 8; return abc [n];});
}

void loop () {
    infoTicker.tick ();

}
