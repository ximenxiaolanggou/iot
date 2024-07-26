from machine import UART

uart2 = UART(2, baudrate=9600, tx=15, rx=14)


if __name__ == '__main__':
    
    while True:
        if uart2.any():
            print(uart2.any())
            data = uart2.read(1024)
            uart2.write(data)
    