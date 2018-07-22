
import MotorControls.motorcontrol as mc
import ultrasonic.hexaultra as hu
import time
import serial
import numpy as np

motorser = serial.Serial('/dev/ttyACM1', 9600)
ultraser = serial.Serial('/dev/ttyACM0', 9600)

motor = mc.RoboDrive(motorser)

ang = 0
time.sleep(1)
while True:
    uray = hu.frontsonic(ultraser)
    print(uray)
    while uray[0] > 5.0 and uray[1] > 5.0 and uray[2] > 5.0:
        uray = hu.frontsonic(ultraser)
        print(uray)
        ang += .1
        degrees = 30*np.sin(ang)
        motor.move(100.0,degrees)
        #print(motor.speedL,motor.speedR)
        #time.sleep(.1)