#include <Servo.h>

Servo servo;
const int piezo = A0;
const int switchPin = 2;
const int yLed = 3;
const int gLed = 4;
const int rLed = 5;
int knockVal;
int switchVal;
const int quietKnock = 10;
const int loudKnock = 100;
boolean locked = false;
int numberOfKnocks = 0;

void setup() {
  servo.attach(9);
  pinMode(yLed, OUTPUT);
  pinMode(rLed, OUTPUT);
  pinMode(gLed, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
  digitalWrite(gLed, HIGH);
  servo.write(0);
  Serial.println("The box is unlocked.");
}

void loop() {
  if (locked == false) {
    switchVal = digitalRead(switchPin);
    if (switchVal == HIGH) {
      locked = true;
      digitalWrite(gLed, LOW);
      digitalWrite(rLed, HIGH);
      servo.write(90);
      Serial.println("The box is locked.");
      delay(1000);
    }
  }
  if (locked == true) {
    knockVal = analogRead(piezo);
    if (numberOfKnocks < 3 && knockVal > 0) {
      if (checkForKnock(knockVal) == true) {
        numberOfKnocks++;
      }
      Serial.print(3 - numberOfKnocks);
      Serial.println(" more knocks to go");
    }
    if (numberOfKnocks >= 3) {
      locked = false;
      servo.write(0);
      delay(20);
      digitalWrite(gLed, HIGH);
      digitalWrite(rLed, LOW);
      Serial.println("The box is unlocked.");
      numberOfKnocks = 0;
    }
  }
}

boolean checkForKnock(int value) {
  if (value > quietKnock && value < loudKnock) {
    digitalWrite(yLed, HIGH);
    delay(50);
    digitalWrite(yLed, LOW);
    Serial.print("Valid knock of value ");
    Serial.println(value);
    return true;
  }
  else {
    Serial.print("Bad knock value ");
    Serial.println(value);
    return false;
  }
}
