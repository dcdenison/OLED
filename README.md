# OLED

This project started off as a way to learn about OLEDs. Then it kind of grew to include a multiplexer. 

The saga included 5 (five) chapters: 

1. I got started with a bunch of motley OLEDs, from a variety of sources: mostly Chinese. 

2. I started off using the adafruit libraries, and got one running. 

File above: 
ssd1306_128x32_i2c.ino

3. Then tried to move uptown to using a multiplexer, so I could control a bunch of OLEDs with just one Arduino. 

I think the one that arrived was this one: 

https://learn.adafruit.com/adafruit-tca9548a-1-to-8-i2c-multiplexer-breakout

4. When Leo took a look at the project, he switched to U8g

Universal 8bit Graphics Library (https://github.com/olikraus/u8g2/)

https://github.com/olikraus/u8g2/

I think because he read this: 

https://www.brainy-bits.com/i2c-multiplexer-tca9548a/

And then he generated this code (above): 

brainybitssketch2.ino
 
We got a few running, and then got distracted. 

5. To get it restarted, I tried to get one running with the U8G libary. Got it working. 

I tried to get one going with the U8G*2* library, recommended by the creator (the new version 2) but wasn't able to get it going. 

But here's the U8G library one (above), which works: 

HelloWorld-OLED-u8g.ino

NEXT STEPS: 

1. See if we can add more workable OLEDs to the "brainy-bits" multiplexer. 

2. Try out U8G version 2, to see if we can get that running. 

3. Maybe compare the Adafruit library and the U8G library. 

4. Sort out my motley collection of OLEDs. 

Goal: Learn about OLEDs, and turn it into a workshop! 
