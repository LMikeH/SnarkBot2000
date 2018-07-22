import serial
import time
import numpy as np

ser = serial.Serial('/dev/ttyACM1', 9600)
#motorstr = str.encode('f100,b100')

def speedstring(factor):
    """
    Utility function, makes string for serial
    from speed integer. 
    example:
    220 --> '+220'
    """ 
    factor = int(factor)
    if factor >= 0:
        sign = '+'
    else:
        sign = '-'
        factor = - factor

    if abs(factor) < 10:
        return sign +'00'+ '%.0d' % factor
    elif abs(factor) > 99:
        return sign + '%.0d' % factor
    else:
        return sign + '0' + '%.0d' % factor


x = 0
while True:
    x += .1
    left = 200*np.sin(x)
    right = 200*np.cos(x)

    spd = speedstring(left) + ',' + speedstring(right)
    #print(spd.encode())
    ser.write(spd.encode())
    print(ser.readline())
    time.sleep(.1)
