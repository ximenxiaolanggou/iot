import time
from machine import Pin
from machine import Timer

LED1 = Pin(15, Pin.OUT)
LED1.off()

def time0_callback(arg):
    print(arg)
    LED1.value(not LED1.value())


if __name__ == '__main__':
    time0 = Timer(0)
    time0.init(period=2000, mode=Timer.PERIODIC, callback=time0_callback)
    
    while True:
        pass