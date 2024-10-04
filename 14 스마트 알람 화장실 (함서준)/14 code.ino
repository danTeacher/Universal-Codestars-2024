/* -----------------------------------------------------------------
1. 초음파 센서 - 휴지통
 - 일단 거리 측정
 - 만약 거리가 7cm보다 작다면 -> LED 켜기

2. 적외선 센서 - 휴지
 - 상시적으로 측정하고
 - 만약 적외선 센서의 digitalRead값 == 0 -> 부저 울리고 LED켜기

3. 수위센서 - 비누
 - 항상 측정하고
 - 만약 수위가 2cm보다 작다면 -> LED 켜기
----------------------------------------------------------------- */

long duration;
long distance;
long value;
void setup() {
  pinMode(2,OUTPUT);//2번핀 초음파
  pinMode(3,INPUT);//3번핀 초음파
  pinMode(4,INPUT);//4번핀 적외선
  pinMode(5,OUTPUT);//5번핀 LED - 초음파 센서에 따라 바뀐다.
  pinMode(6,OUTPUT);//6번핀 LED - 적외선센서 따라 바뀐다.
  pinMode(7,OUTPUT);//7번핀 LED - 수위센서 따라 바뀐다.
  pinMode(8,OUTPUT);//8번핀 부저 - 적외선센서 따라 울린다.
  Serial.begin (9600);

}

//수위 센서는 A1
//조도 센서는 A0

void loop() {
    
    //초음파

  digitalWrite(e,LOW);
  delayMicroseconds(10);
  digitalWrite(e,HIGH);
  delayMicroseconds(10);
  digitalWrite(e,LOW);

  duration = pulseIn(e, HIGH);

  distance = duration * 0.034 / 2;

    //적외선+LED+부저

  if (digitalRead(4) == LOW) {
      while(digitalRead(4) == LOW){

      digitalWrite(6,HIGH);
      tone(8, 262, 100);
      delay(1000);
      tone(8, 302, 100);
      delay(1000);
      tone(8, 262, 100);
      delay(1000);
    }
    digitalWrite(6,LOW);

  }

value = analogRead(A1);
Serial.println(value);
delay(1000);




}