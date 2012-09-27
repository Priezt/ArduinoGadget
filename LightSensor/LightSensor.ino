/*
LightSensor

Voltage: 3.3V~5V
DigitalPin: 9
AnalogPin: 0

This code can also be used on a TemperatureSensor
*/

int din = 10;
int ain = 3;

void setup(){
  Serial.begin(9600);
  pinMode(din, INPUT);
  pinMode(ain, INPUT);
}

void loop(){
  int val = analogRead(ain);
  if(digitalRead(din)){
    Serial.print("Off");
  }else{
    Serial.print("On");
  }
  Serial.print(": ");
  Serial.println(val);
  delay(300);
}

