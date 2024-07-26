from machine import Pin
import time

"""
LED流水灯

GPIO 16、17、18
LED  D1、D2、D3
"""
led_Gpios = [16,17,18]

led_Pins = []

for led_Gpio in led_Gpios:
    led_Pins.append(Pin(led_Gpio, Pin.OUT))

while True:
    for led_Pin in led_Pins:
        led_Pin.on()
        time.sleep_ms(500)
        
    for led_Pin in led_Pins[::-1]: # 倒序遍历
        led_Pin.off()
        time.sleep_ms(500)    

