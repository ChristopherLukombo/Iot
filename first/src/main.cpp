#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial = SoftwareSerial(2,3);

const int SERIAL_BEGIN = 9600;
const int LOOP_DELAY = 3000;
const int ANALOG_PIN = 0;

float readTemperature();

// capteur de temperature
void setup()
{
  mySerial.begin(SERIAL_BEGIN);
  Serial.begin(SERIAL_BEGIN);
}

void loop()
{
  delay(LOOP_DELAY);
  float temperature = readTemperature();
  mySerial.println(temperature);
}

float readTemperature() {
  int readingTempBin = analogRead(ANALOG_PIN);

  float tempdiv = readingTempBin * 5;
  tempdiv /= 1024;
  float tempDeg = tempdiv - 0.500;
  tempDeg /= 0.010;
  return tempDeg;
}