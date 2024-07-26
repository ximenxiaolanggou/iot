import network
import time
import usocket

ssid = 'Prinfo_Test'
key = 'prinfotest666'

dest_ip = '192.168.222.195'
dest_port = 6666


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
        return True
                

if __name__ == '__main__':
    
    if wifi_connect():
        socket = usocket.socket()
        socket.connect((dest_ip, dest_port))
        socket.send('hello')
        while True:
            text = socket.recv(128)
            if text == None:
                pass
            else:
                print(text)
                socket.send(f"receive ~~ {text.decode("utf-8")}")
                time.sleep_ms(300)
        
        
        
        
        
        
        
        
        
        
