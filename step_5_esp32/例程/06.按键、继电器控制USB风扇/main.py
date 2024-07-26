import time
from machine import Pin

"""
按键 GPIO
14 27 26 25

LED GPIO
15 2  0  4
"""

KEY1 = Pin(14, Pin.IN, Pin.PULL_UP)


LED1 = Pin(15, Pin.OUT)
LED1.off()

# 默认关灯
KEY1_PRESS = 1




# 继电器
rely = Pin(25, Pin.OUT)

# 默认常闭
rely.off()


# 防止一直按下重复触发
press = 0
def scan():
    global press
    if(press == 0 and KEY1.value() == 0):
        time.sleep_ms(20)
        press = 1
        
        if(KEY1.value() == 0):
            return KEY1_PRESS

        
    elif(press == 1 and KEY1.value() == 1):
        press = 0
        
    return 0        
        
    


if __name__ == '__main__':
    
    while True:
        KEY = scan()
        if(KEY == KEY1_PRESS):
            # 亮灯
            LED1.value(not LED1.value())
            # 开风扇
            rely.value(not rely.value())
      
    
    
    
    
    
    
    
    
    
    
    
