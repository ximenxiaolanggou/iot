from machine import RTC
import time

week = ('星期一','星期二','星期三','星期四','星期五','星期六','星期日')

rtc = RTC()
rtc.datetime((2024, 7, 24, 1, 12, 48, 0, 0)) # set a specific date and time

if __name__ == '__main__':
    
    while True:
        now = rtc.datetime()
        print(f'{now[0]}-{now[1]}-{now[2]} {now[4]}:{now[5]}:{now[6]} {week[now[3]]}')# get date and time
        time.sleep(1)