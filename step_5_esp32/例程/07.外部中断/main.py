import time
from machine import Pin


LED1 = Pin(15, Pin.OUT)
LED1.off()

KEY1 = Pin(14, Pin.IN, Pin.PULL_UP)

# 函数参数需要指定那个Pin
def key1_irq(KEY1):
    # 延迟10秒LED可能会抖动
    time.sleep_ms(20)
    if not KEY1.value():
        LED1.value(not LED1.value())


if __name__ == '__main__':
    
    KEY1.irq(handler=key1_irq, trigger=Pin.IRQ_FALLING)
    
    while True:
        pass
    