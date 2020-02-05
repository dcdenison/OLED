# OLED


![Image of Yaktocat]
(/pixelimage.jpg)

This project started off as a way to learn about OLEDs. Then it kind of grew to include a multiplexer. 

The saga included 6 chapters: 

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

6. Got the U8G2 library working! 

HelloWorld-u8g2.ino

7. Leo updated and commented the brainybitssketch2. It is now LeoSketch3, above.

Now LeoSketch4

8. Started working with the Adafruit "Example" sketch. Making it loop, commenting things out. Got six of them. 

SS1306_128x64_12C_v6.ino

9. Along the way, came across to excellent OLED tutorials. 

lastminuteengineers-oled.ino
randomnerdtutorial-oled.ino

10. And starting investigating whether scrolling is possible. 

InfoTicker1.ino
scrollingtest-u8g.ino

11. Also ordered a new Adafruit multiplexer. So I can compare the u8g multiplexer code, and the Adafruit multiplexer code. 

NEXT STEPS: 
1. Create more OLED sketches and hardware
2. Add new OLEDs to existing multiplexer
3. Try out Adafruit multiplexer
4. Add eInk module
5. Evaluate the collection of old, green and black displays
