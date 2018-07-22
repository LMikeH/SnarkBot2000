import serial
import numpy as np

#ser = serial.Serial('/dev/ttyACM0', 9600)
#motorstr = str.encode('-023,-255,+000,+040')


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

class RoboDrive:
    """
    This class defines a robot drive train object.
    """
    def __init__(self,ser):
        self.speedL = 0
        self.speedR = 0
        self.ser = ser

    def speed_encode(self):
        Lstr = speedstring(self.speedL)
        Rstr = speedstring(self.speedR)
        motorstr = '{},{}'.format(Lstr,Rstr)
        print(motorstr)
        self.ser.write(motorstr.encode())

    def move(self,speed,angle):
        turn_adjustment = np.cos(np.pi*angle/180.0)
        if angle >= 0:
            left_factor = 1
            right_factor = (turn_adjustment)
        elif angle <=0:
            left_factor = (turn_adjustment)
            right_factor = 1

        self.speedL = int(speed*left_factor)
        self.speedR = int(speed*right_factor)
        self.speed_encode()