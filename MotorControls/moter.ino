#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <math.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *frontleft_motor = AFMS.getMotor(1);
Adafruit_DCMotor *backleft_motor = AFMS.getMotor(2);
Adafruit_DCMotor *frontright_motor = AFMS.getMotor(3);
Adafruit_DCMotor *backright_motor = AFMS.getMotor(4);
String motorin;

void setup() {
  Serial.begin(9600);
  AFMS.begin();
}

void loop() {

    int leftspd = 0;
    int rightspd = 0;

    String speedstr;
    speedstr = Serial.readString();
    String leftsign = speedstr.substring(0,1);
    String leftstr = speedstr.substring(1,4);
    String rightsign = speedstr.substring(5,6);
    String rightstr = speedstr.substring(6,9);
    Serial.println(leftsign);

    leftspd = leftstr.toInt();
    rightspd = rightstr.toInt();


    frontleft_motor->setSpeed(leftspd);
    frontleft_motor->run(FORWARD);

    backleft_motor->setSpeed(leftspd);
    backleft_motor->run(FORWARD);

    //if (leftsign == '-') {
    //    Serial.println(leftsign);
    //}

    frontright_motor->setSpeed(rightspd);
    frontright_motor->run(FORWARD);

    backright_motor->setSpeed(rightspd);
    backright_motor->run(FORWARD);

    delay(50);
}