from machine import Pin
import time

# 蜂鸣器实验
beep = Pin(25, Pin.OUT)

if __name__ == '__main__':
    i = 0;
    while True:
        i = not i;
        beep.value(i)
        time.sleep_us(250)