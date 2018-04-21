import serial

ser = serial.Serial('/dev/ttyACM0', 9600)
motorstr = str.encode('-023,-255,+000,+040')


while True:
    ser.write(motorstr)
    print(ser.readline())