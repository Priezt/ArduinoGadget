int led_r = 8;
int led_g = 9;
int led_b = 10;

int interval = 300;
int mode = 0;
int inputByte = 0;

void red(){
  digitalWrite(led_r, LOW);
  digitalWrite(led_g, HIGH);
  digitalWrite(led_b, HIGH);
}

void green(){
  digitalWrite(led_r, HIGH);
  digitalWrite(led_g, LOW);
  digitalWrite(led_b, HIGH);
}

void blue(){
  digitalWrite(led_r, HIGH);
  digitalWrite(led_g, HIGH);
  digitalWrite(led_b, LOW);
}

void yellow(){
  digitalWrite(led_r, LOW);
  digitalWrite(led_g, LOW);
  digitalWrite(led_b, HIGH);
}

void purple(){
  digitalWrite(led_r, LOW);
  digitalWrite(led_g, HIGH);
  digitalWrite(led_b, LOW);
}

void cyan(){
  digitalWrite(led_r, HIGH);
  digitalWrite(led_g, LOW);
  digitalWrite(led_b, LOW);
}

void white(){
  digitalWrite(led_r, LOW);
  digitalWrite(led_g, LOW);
  digitalWrite(led_b, LOW);
}

void off(){
  digitalWrite(led_r, HIGH);
  digitalWrite(led_g, HIGH);
  digitalWrite(led_b, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(led_r, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(led_b, OUTPUT);
  off();
  mode = 0;
  Serial.begin ( 9600 );
}

void blink(){
  switch(mode){
    case 0:{
      off();
      break;
    }
    case 1:{
      red();
      break;
    }
    case 2:{
      green();
      break;
    }
    case 3:{
      blue();
      break;
    }
    case 4:{
      yellow();
      break;
    }
    case 5:{
      purple();
      break;
    }
    case 6:{
      cyan();
      break;
    }
    case 7:{
      white();
      break;
    }
    default:
      off();
  }
  delay(interval);
  off();
  delay(interval);
}

void loop(){
  if(Serial.available() > 0){
    inputByte = Serial.read();
    Serial.print("Received: ");
    Serial.println(inputByte, DEC);
    if(inputByte - 0x30 >= 0 and inputByte - 0x30 <= 7){
      mode = inputByte - 0x30;
    }
  }else{
    blink();
  }
}


