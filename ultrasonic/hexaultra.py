import serial
import time
import numpy as np

ser = serial.Serial('/dev/ttyACM0', 9600)

def frontsonic():

    try:
        frontstr = ser.readline().decode()
        sonray = frontstr.split('\n')[0].split('_')
        return np.array(sonray,dtype=float)
    except ValueError:
        return np.array([999,999,999])

    

    
