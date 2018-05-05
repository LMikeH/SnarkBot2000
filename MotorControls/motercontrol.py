import serial
import numpy as np

ser = serial.Serial('/dev/ttyACM0', 9600)
motorstr = str.encode('-023,-255,+000,+040')


def speedstring(factor):
    """
    Utility function, makes string for serial
    from speed integer. 
    example:
    220 --> '+220'
    """ 
    if factor >= 0:
        sign = '+'
    else:
        sign = '-'

    if abs(factor) < 10:
        return sign +'00'+str(factor)
    elif abs(factor) > 99:
        return sign + str(factor)
    else:
        return sign + '0' + str(factor)

class RoboDrive:
    """
    This class defines a robot drive train object.
    """
    def __init__():
        self.speedfl = 0 # speed front left
        self.speedbl = 0 # speed back left
        self.speedfr = 0 # speed front right
        self.speedbr = 0 # speed back right

    def speed_encode(self):
        flstr = speedstring(self.speedfl)
        blstr = speedstring(self.speedbl)
        frstr = speedstring(self.speedfr)
        brstr = speedstring(self.speedbr)
        motorstr = '{},{},{},{}'.format(flstr,blstr,frstr,brstr)
        return motorstr

    def arcturn(self,speed,angle): #WRONG WAY!!!!!!!!!!!
        turn_adjustment = np.cos(np.pi*angle/180.0)
        if angle >= 0:
            left_factor = 1
            right_factor = int(turn_adjustment)
        elif angle <=0:left_factor = 1
            left_factor = int(turn_adjustment)
            right_factor = 1

        self.speedfl = speed*left_factor
        self.speedbl = speed*left_factor
        self.speedfr = speed*right_factor
        self.speedbr = speed*right_factor

##############################
while True:
    ser.write(motorstr)
    print(ser.readline())