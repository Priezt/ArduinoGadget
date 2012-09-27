int ledR = 8;
int ledG = 9;
int ledB = 10;

void setup(){
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop(){
  lightUp(ledR);
  delay(10);
  lightUp(ledG);
  delay(10);
  lightUp(ledB);
  delay(10);
}

void lightUp(int led){
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, LOW);
  digitalWrite(ledB, LOW);
  digitalWrite(led, HIGH);
}
