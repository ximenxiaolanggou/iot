from machine import Timer,Pin,ADC

adc = ADC(Pin(34))
adc.atten(ADC.ATTN_11DB)

def time0_callback(time0):
    print(adc.read_u16())
    print(adc.read_uv())
    adc_read = adc.read()
    adc_vol = 3.3 * adc_read/4095
    print(f"ADC:{adc_read},电压:{adc_vol}")
    


if __name__ == '__main__':
    time0 = Timer(0)
    time0.init(period=1000, mode=Timer.PERIODIC, callback=time0_callback)
    
    while True:
        pass