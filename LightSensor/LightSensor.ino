/*
LightSensor
DigitalPin: 9
AnalogPin: 0
*/

int din = 9;
int ain = 0;

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
