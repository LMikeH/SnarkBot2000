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


int leftspd = 0;
int rightspd = 0;
String speedstr;
String leftsign;
String leftstr;
String rightsign;
String rightstr;
int sercount = 0;

void loop() {

    if (Serial.available() > 0) {
        speedstr = Serial.readString();
        leftsign = speedstr.substring(0,1);
        leftstr = speedstr.substring(1,4);
        rightsign = speedstr.substring(5,6);
        rightstr = speedstr.substring(6,9);
        leftspd = leftstr.toInt();
        rightspd = rightstr.toInt();
        sercount = 0;
    }

    
    if (sercount > 10) {
        leftspd = 0;
        rightspd = 0;
    }
    Serial.println("motor");
    
    frontleft_motor->setSpeed(leftspd);
    backleft_motor->setSpeed(leftspd);

    frontright_motor->setSpeed(rightspd);
    backright_motor->setSpeed(rightspd);

    if (leftsign == "-"){
        frontleft_motor->run(FORWARD);
        backleft_motor->run(FORWARD);
    }
    else {
        frontleft_motor->run(BACKWARD);
        backleft_motor->run(BACKWARD);
    }

    if (rightsign == "-"){
        frontright_motor->run(FORWARD);
        backright_motor->run(FORWARD);
    }
    else {
        frontright_motor->run(BACKWARD);
        backright_motor->run(BACKWARD);
    }
        
    sercount += 1;
    delay(50);
}