#include<CapacitiveSensor.h>
CapacitiveSensor sensor = CapacitiveSensor(4, 2);
int threshold = 1000;
const int ledPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  long sensVal = sensor.capacitiveSensor(30);
  Serial.println(sensVal);
  if (sensVal > threshold) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  delay(10);
}
