import DS1302
from machine import Pin
import time

week = ('星期一','星期二','星期三','星期四','星期五','星期六','星期日')

ds1302 = DS1302.DS1302(clk=Pin(18), dio=Pin(19),cs=Pin(23))




if __name__ == '__main__':
    now = ds1302.DateTime()
    if now[0] != 2024:
        ds1302.DateTime([2024, 7, 24, 1, 12, 48, 0])
    
    while True:
        now = ds1302.DateTime()
        print(f'{now[0]}-{now[1]}-{now[2]} {now[4]}:{now[5]}:{now[6]} {week[now[3]]}')# get date and time
        time.sleep(1)
