void setup(){
  Serial.begin(9600);
  // Sorties
  pinMode(2, OUTPUT); // rouge
  pinMode(3, OUTPUT); // vert
}

void loop() {
  float temperature = readTemperature();
  Serial.print("reading Temp : ");
  Serial.print(temperature);
  Serial.println(" C");
  
  digitalWrite(2, temperature > 20);
  digitalWrite(2, temperature < 20);
  delay(1000); // Wait for 1000 millisecond(s)
}

float readTemperature() {
  int readingTempBin = analogRead(0);
  
  float tempdiv = readingTempBin * 5;
  tempdiv /= 1024;
  
  Serial.print("read mV : ");
  Serial.println(tempdiv);
  float tempDeg = tempdiv - 0.500;
  tempDeg /= 0.010;
  return tempDeg;
}