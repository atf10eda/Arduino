const int switchPin = 8;
unsigned long prevTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 5000;

void setup() {
  for(int i = 2; i < 8; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();
  if(currentTime - prevTime > interval){
    prevTime = currentTime;
    digitalWrite(led, HIGH);
    if(led == 7){
      for(int i = 2; i < 8; i++){
        digitalWrite(i, LOW);
        delay(3000);
        digitalWrite(i, HIGH);
      }
    }
    led++;
  }
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState){
    for(int i = 2; i < 8; i++){
      digitalWrite(i, LOW);
    }
    led = 2;
    prevTime = currentTime;
  }
  prevSwitchState = switchState;
}
