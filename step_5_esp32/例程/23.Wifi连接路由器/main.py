import network
import time

ssid = 'Prinfo_Test'
key = 'prinfotest666'



def wifi_connect():
    # 创还能wlan对象
    wlan = network.WLAN(network.STA_IF)

    # 设置为激活状态
    wlan.active(True)      

    # 扫描网路
    wlans = wlan.scan()

    print(wlans)
    
    if not wlan.isconnected():
        # 未连接
        print('wifi connecting ~~')
        wlan.connect(ssid, key)
        start_time = time.time()
        while not wlan.isconnected():
            
            if time.time() - start_time > 15:
                print(f'请检查WiFi账户：{ssid}和密码：{key}')
                break
            
    if wlan.isconnected():
        print(wlan.ifconfig())
                

if __name__ == '__main__':
    
    wifi_connect()
    while True:
        pass