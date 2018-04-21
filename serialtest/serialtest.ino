

String inp;
char question[50] = "Please tell me speed\n";
const int speed_len = 20;
char speeds[speed_len]; 

void setup() {
  Serial.begin(9600);
  Serial.println(question);
}

void loop() {

    if (Serial.available()) {
      inp = Serial.readString();
      String stuff = inp.substring(4,8+1);
      


      Serial.println(stuff);
      //stuff.toInt()
    }
    //Serial.println("Hello! This is a test");
}
