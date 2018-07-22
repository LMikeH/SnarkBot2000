// sensor1
int trigPin1 = 3;               //Sensor Trig pin connected to Arduino pin 3
int echoPin1 = 2;               //Sensor Echo pin connected to Arduino pin 2
float pingTime1;                //time for ping to travel from sensor to target and return
float distance1;                //Distance to Target in inches

//sensor2
int trigPin2 = 4; 
int echoPin2 = 5;  
float pingTime2;               
float distance2;  

// sensor3
int trigPin3 = 7; 
int echoPin3 = 8;  
float pingTime3;               
float distance3;  
          
float speedOfSound = 776.5;     //Speed of sound in miles per hour when temp is 77 degrees.
char distances[72];             //Concantenate all the distances together

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(trigPin1, LOW);    //Set trigger pin low
  delayMicroseconds(2000);        //Let signal settle
  digitalWrite(trigPin1, HIGH);   //Set trigPin high
  delayMicroseconds(15);          //Delay in high state
  digitalWrite(trigPin1, LOW);    //ping has now been sent
  delayMicroseconds(10);          //Delay in low state
  pingTime1 = pulseIn(echoPin1, HIGH);   //pingTime is presented in microceconds
  pingTime1 = pingTime1/1000000;          //convert pingTime to seconds by dividing by 1000000 (microseconds in a second)
  pingTime1 = pingTime1/3600;             //convert pingtime to hourse by dividing by 3600 (seconds in an hour)
  distance1 = speedOfSound * pingTime1;   //This will be in miles, since speed of sound was miles per hour
  distance1 = distance1/2;                //Remember ping travels to target and back from target, so you must divide by 2 for actual target distance.
  distance1 = distance1*63360;            //Convert miles to inches by multipling by 63360 (inches per mile)
  delayMicroseconds(1000);                    
  
  digitalWrite(trigPin2, LOW);    //Set trigger pin low
  delayMicroseconds(2000);        //Let signal settle
  digitalWrite(trigPin2, HIGH);   //Set trigPin high
  delayMicroseconds(15);          //Delay in high state
  digitalWrite(trigPin2, LOW);    //ping has now been sent
  delayMicroseconds(10);          //Delay in low state
  pingTime2 = pulseIn(echoPin2, HIGH);   //pingTime is presented in microceconds
  pingTime2 = pingTime2/1000000;          //convert pingTime to seconds by dividing by 1000000 (microseconds in a second)
  pingTime2 = pingTime2/3600;             //convert pingtime to hourse by dividing by 3600 (seconds in an hour)
  distance2 = speedOfSound * pingTime2;   //This will be in miles, since speed of sound was miles per hour
  distance2 = distance2/2;                //Remember ping travels to target and back from target, so you must divide by 2 for actual target distance.
  distance2 = distance2*63360;            //Convert miles to inches by multipling by 63360 (inches per mile)
  delayMicroseconds(1000); 

  digitalWrite(trigPin3, LOW);    //Set trigger pin low
  delayMicroseconds(2000);        //Let signal settle
  digitalWrite(trigPin3, HIGH);   //Set trigPin high
  delayMicroseconds(15);          //Delay in high state
  digitalWrite(trigPin3, LOW);    //ping has now been sent
  delayMicroseconds(10);          //Delay in low state
  pingTime3 = pulseIn(echoPin3, HIGH);   //pingTime is presented in microceconds
  pingTime3 = pingTime3/1000000;          //convert pingTime to seconds by dividing by 1000000 (microseconds in a second)
  pingTime3 = pingTime3/3600;             //convert pingtime to hourse by dividing by 3600 (seconds in an hour)
  distance3 = speedOfSound * pingTime3;   //This will be in miles, since speed of sound was miles per hour
  distance3 = distance3/2;                //Remember ping travels to target and back from target, so you must divide by 2 for actual target distance.
  distance3 = distance3*63360;            //Convert miles to inches by multipling by 63360 (inches per mile)

  char str1[12];
  char str2[12];
  char str3[12];
  dtostrf(distance1, 2, 2, str1);
  dtostrf(distance2, 2, 2, str2);
  dtostrf(distance3, 2, 2, str3);
  sprintf(distances, "%s_%s_%s", str1, str2, str3);
  Serial.println(distances);
  memset(&distances[0], 0, sizeof(distances));
  delay(100); //delay tenth of a  second to slow things down a little.
}
