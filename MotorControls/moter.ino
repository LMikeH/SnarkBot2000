
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *frontleft_motor = AFMS.getMotor(1);
Adafruid_DCMotor *backleft_motor = AFMS.getMotor(2);
Adafruid_DCMotor *frontright_motor = AFMS.getMotor(3);
Adafruid_DCMotor *backright_motor = AFMS.getMotor(4);
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