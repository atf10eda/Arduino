#include <Servo.h>

Servo servo;
int const potPin = A0;
int potVal;
int ang;

void setup() {
  servo.attach(9);
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);
  
  ang = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(ang);
  
  servo.write(ang);
  delay(15);
}
