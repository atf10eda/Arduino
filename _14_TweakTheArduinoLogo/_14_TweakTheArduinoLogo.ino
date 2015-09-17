void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write(analogRead(a0)/4);
  delay(1);
}
