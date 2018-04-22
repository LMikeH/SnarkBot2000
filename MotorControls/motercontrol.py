import serial

ser = serial.Serial('/dev/ttyACM0', 9600)
motorstr = str.encode('-023,-255,+000,+040')


class RoboDrive:
    def __init__():
        self.speedfl = 0 # speed front left
        self.speedbl = 0 # speed back left
        self.speedfr = 0 # speed front right
        self.speedbr = 0 # speed back right


    def speed_encode(self):




while True:
    ser.write(motorstr)
    print(ser.readline())