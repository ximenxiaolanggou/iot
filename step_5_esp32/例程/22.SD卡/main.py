from machine import Pin, SPI
import os
import sdcard
import time

spi = SPI(2, sck=Pin(18), mosi=Pin(23), miso=Pin(19))


if __name__ == '__main__':
    sd = sdcard.SDCard(spi, Pin(4))
    os.mount(sd, '/sd')
    print(os.listdir('/sd'))
    while True:
        print(os.stat('/sd/a.txt'))
       
        
        time.sleep(1)
        
        pass
