import serial
import time

ser = serial.Serial('/dev/ttyACM0', 9600)
motorstr = str.encode('f123,b240')


while True:
    ser.write(motorstr)
    print(ser.readline())
    time.sleep(1)
