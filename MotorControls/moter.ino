
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
String motorin;

void setup() {
  Serial.begin(9600);
  AFMS.begin();
}

void loop() {

    if (Serial.available()) {

    }
    else {
        motor1->setSpeed(0)
        motor1->run(RELEASE)
    }

}