const int sensorPin = A0;
const float baselineTemp = 25.0;

void setup() {
  Serial.begin(9600); // open serial port
  for(int pinNumber = 2; pinNumber < 5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  // convert ADC reading to voltage
  float u = (sensorVal/1024.0)*5.0;
  Serial.print(" , Volts: ");
  Serial.print(u);
  Serial.print(" , degrees C: ");
  // convert voltage to temperature  in degrees C
  float t = (u - .5)*100;
  Serial.println(t);
  
  if(t < baselineTemp){
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  } else if(t >= baselineTemp + 2 && t < baselineTemp + 4){
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);  
  } else if(t >= baselineTemp + 4 && t < baselineTemp + 6){
    digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  } else if(t >= baselineTemp + 6){
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  }
  delay(1);
}
