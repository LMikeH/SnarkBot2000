#include <Wire.h>
#include <Adafruit_MotorShield.h>"
//#include "utility/Adafruit_MotorShield.h"
//#include <Adafruit_MS_PWMServoDriver.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *frontleft_motor = AFMS.getMotor(1);
//Adafruit_DCMotor *backleft_motor = AFMS.getMotor(2);
//Adafruit_DCMotor *frontright_motor = AFMS.getMotor(3);
//Adafruit_DCMotor *backright_motor = AFMS.getMotor(4);
String motorin;

void setup() {
  //Serial.begin(9600);
  AFMS.begin();
}

void loop() {
    frontleft_motor->setSpeed(255);
    frontleft_motor->run(FORWARD);

    //backleft_motor->setSpeed(255);
    //backleft_motor->run(FORWARD);

    //frontright_motor->setSpeed(255);
    //frontright_motor->run(FORWARD);

    //backright_motor->setSpeed(255);
    //backright_motor->run(FORWARD);

    delay(5000);
}
