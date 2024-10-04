#include <Servo.h>

Servo myServo;
Servo MYSERVO;
Servo myservo;
Servo Myservo;
int i;
int y;
int l;
int x;
int randomNum;

const int buzzerPin = 8;
const int duration = 1000; // 주파수 변경 간격 (1초)
const int frequencyCount = 5; // 사용할 주파수의 개수

// 짜증나는 음역대 주파수 (Hz)
const int frequencies[frequencyCount] = {2000, 2200, 2400, 2600, 2800};


void setup() {
  myServo.attach(9);
  MYSERVO.attach(10);
  myservo.attach(11);
  Myservo.attach(12);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
x=random(60,180);
 if(digitalRead(2) == HIGH){
    randomNum= random(0,100);
    if(randomNum<100)
    {
    for(y=0;y<20;y++)
    {
    myServo.write(i);
    MYSERVO.write(l);
    myservo.write(i);
    Myservo.write(l);
    delay(500);
    Serial.print("a");
    }
    }
  }
  delay(1000*x);
  for(y=0;y<20;y++)
  {
  i=random(0,180);
  l=random(0,180);
  myServo.write(i);
  MYSERVO.write(l);
  myservo.write(i);
  Myservo.write(l);
  delay(500);
  Serial.print("b");
  }
  for (int i = 0; i < frequencyCount; i++) {
    tone(buzzerPin, frequencies[i]); // 부저에서 주파수 출력
    delay(duration); // 주파수 변경 간격
    noTone(buzzerPin);
  }
  for (int ak = 0; ak < 30; ak++) {
    digitalWrite(7,HIGH);
    delay(100);
    digitalWrite(7,LOW);
    delay(100);
  }
}