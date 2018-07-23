
import MotorControls.motorcontrol as mc
import ultrasonic.hexaultra as hu
import time
import serial
import numpy as np

motorser = serial.Serial('/dev/ttyACM1', 9600)
ultraser = serial.Serial('/dev/ttyACM0', 9600)

motor = mc.RoboDrive(motorser)
motorser.flushInput()
ultraser.flushInput()

ang = 0
#time.sleep(1)
flush_count = 0
while True:
    uray = hu.frontsonic(ultraser)
    print(uray)
    ang += .1
    degrees = 30*np.sin(ang)
    print(motorser.readline())
    if uray[0] > 20.0 and uray[1] > 20.0 and uray[2] > 20.0:
        motor.move(100.0,degrees)
    else:
        motor.move(0.0,degrees)
    motorser.flushInput()
    ultraser.flushInput()
    motorser.flushOutput()
    #time.sleep(.1)