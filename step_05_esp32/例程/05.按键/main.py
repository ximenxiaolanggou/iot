import time
from machine import Pin

"""
按键 GPIO
14 27 26 25

LED GPIO
15 2  0  4
"""

KEY1 = Pin(14, Pin.IN, Pin.PULL_UP)
KEY2 = Pin(27, Pin.IN, Pin.PULL_UP)
KEY3 = Pin(26, Pin.IN, Pin.PULL_UP)
KEY4 = Pin(25, Pin.IN, Pin.PULL_UP)

LED1 = Pin(15, Pin.OUT)
LED2 = Pin(2, Pin.OUT)
LED3 = Pin(0, Pin.OUT)
LED4 = Pin(4, Pin.OUT)

LED1.off()
LED2.off()
LED3.off()
LED4.off()

KEY1_PRESS,KEY2_PRESS,KEY3_PRESS,KEY4_PRESS = 1,2,3,4

# 防止一直按下重复触发
press = 0
def scan():
    global press
    if(press == 0 and (KEY1.value() == 0 or KEY2.value() == 0 or KEY3.value() == 0 or KEY4.value() == 0)):
        time.sleep_ms(20)
        press = 1
        
        if(KEY1.value() == 0):
            return KEY1_PRESS
        if(KEY2.value() == 0):
            return KEY2_PRESS
        if(KEY3.value() == 0):
            return KEY3_PRESS
        if(KEY4.value() == 0):
            return KEY4_PRESS
        
    elif(press == 1 and KEY1.value() == 1 and KEY2.value() == 1 and KEY3.value() == 1 and KEY4.value() == 1):
        press = 0
        
    return 0        
        
    


if __name__ == '__main__':
    
    while True:
        KEY = scan()
        if(KEY == KEY1_PRESS):
            LED1.value(not LED1.value())
        if(KEY == KEY2_PRESS):
            LED2.value(not LED2.value())
        if(KEY == KEY3_PRESS):
            LED3.value(not LED3.value())
        if(KEY == KEY4_PRESS):
            LED4.value(not LED4.value())
    
    
    
    
    
    
    
    
    
    
    