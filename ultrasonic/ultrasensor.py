
from gpiozero import DistanceSensor

ultrasonic = DistanceSensor(echo=18,trigger=4)
print(ultrasonic.distance)