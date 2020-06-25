#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial = SoftwareSerial(2, 3);

const int SERIAL_BEGIN = 9600;
const int LOOP_DELAY = 2000;
const float DANGER_LIMIT = 50.00;
const float WARNING_LIMIT = 30.00;
const int R = 4;
const int G = 5;
const int B = 6;
const int BUZZER = 13;
int red;
int green;
int blue;

void setup(){
  
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  
  mySerial.begin(SERIAL_BEGIN);
  Serial.begin(SERIAL_BEGIN);
 
  Serial.println("Initialize...");
}

void loop() {
  
  delay(LOOP_DELAY);
  
  float temperature = mySerial.readString().toFloat();
  Serial.println(temperature);
  
  digitalWrite(BUZZER, LOW);
  
  if(temperature < WARNING_LIMIT) {
    correct_status();
  } else if(temperature > WARNING_LIMIT && temperature < DANGER_LIMIT) {
      warning_status();
  } else {
    danger_status();
    digitalWrite(BUZZER, HIGH);         
      tone(12, 10000, 200);
  }
  analogWrite(R, red);
  analogWrite(G, green);
  analogWrite(B, blue);
}

void correct_status() {
  red = 0;
  green = 182;
  blue = 0;
}

void warning_status() {
  red = 255;
  green = 255;
  blue = 0;
}

void danger_status() {
  red = 255;
  green = 0;
  blue = 0;
}