import time
from machine import Pin, PWM


pwm_led_0 = PWM(Pin(15), freq=5000, duty=0)

# 输出频率
print(pwm_led_0.freq())

# 输出占空比
print(pwm_led_0.duty())



if __name__ == '__main__':
    duty = 0
    step = 10
    while True:
        if duty <= 0:
            step = 10
        if duty >= 1020:
            step = -10
        
        duty += step
        pwm_led_0.duty(duty)
        time.sleep_ms(10)
            
            
        
        
    

