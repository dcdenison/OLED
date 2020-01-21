# OLED

Resources for OLED project: 

I started off with the adafruit libraries. 

https://learn.adafruit.com/adafruit-tca9548a-1-to-8-i2c-multiplexer-breakout

Got one running using the Adafruit library. 

File above: 
ssd1306_128x32_i2c.ino

Then tried to move uptown to using a multiplexer. 

I think the one that arrived was this one: 

https://learn.adafruit.com/adafruit-tca9548a-1-to-8-i2c-multiplexer-breakout

Then, moving onto a multiplexer, Leo switched to U8g

Universal 8bit Graphics Library (https://github.com/olikraus/u8g2/)

https://github.com/olikraus/u8g2/

I think because he read this: 

https://www.brainy-bits.com/i2c-multiplexer-tca9548a/

And then he generated this code (above): 

brainybitssketch2.ino
 
Got a few running. 

Just for research, I got 1 running using the U8G library. I tried to get one going with the U8G*2* library, but wasn't able to get it going. 

But here's the U8G library one (above): 

HelloWorld-OLED-u8g.ino

