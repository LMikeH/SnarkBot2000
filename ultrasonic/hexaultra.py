import serial
import time
import numpy as np

#ser = serial.Serial('/dev/ttyACM0', 9600)

def frontsonic(ser):
    try:
        frontstr = ser.readline().decode()
        sonray = frontstr.split('\n')[0].split('_')
        if len(sonray) == 3:
            return [float(sonray[0]),float(sonray[1]),float(sonray[2])]
        else:
            return [999,999,999]
    except ValueError:
        return [999,999,999]

    
#ser = serial.Serial('/dev/ttyACM0', 9600)
#while True:
#    print(frontsonic(ser))
