import ds18x20, time, onewire
from machine import Pin

ow = onewire.OneWire(Pin(13))

ds = ds18x20.DS18X20(ow)


if __name__ == '__main__':
    
    # 扫描出单总线上设备
    roms = ds.scan()
    print(roms)
    while True:
        ds.convert_temp()
        time.sleep(1)
        for rom in roms:
             print(f'温度为: %.2f' %ds.read_temp(rom))

        