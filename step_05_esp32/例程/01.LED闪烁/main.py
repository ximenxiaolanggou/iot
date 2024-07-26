from machine import Pin
import time

"""
定义 16 GPIO口为输出
不是所有口都可以做输入输出
查看上面文档
"""
d1 = Pin(16, Pin.OUT) 

while True:
    d1.on() # 设置高电平
    time.sleep_ms(500)
    d1.off() # 设置低电平
    time.sleep_ms(500)
    
