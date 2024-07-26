from machine import Pin
import time

# 继电器实验
rely = Pin(25, Pin.OUT)

if __name__ == '__main__':
    i = 0;
    while True:
        i = not i;
        rely.value(i)
        time.sleep(1)
