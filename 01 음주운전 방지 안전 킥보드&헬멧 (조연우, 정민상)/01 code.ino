#include <SPI.h>
#include <MFRC522.h>

int REC = 8;
int PLAYE = 4;
int alcohol;

char input;

int num = 0;
int state = 0;

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN); // RFID 리더기 인스턴스

void setup() {
  Serial.begin(9600);
  pinMode(REC, INPUT);
  pinMode(PLAYE, OUTPUT);
  Serial.begin(9600);   // 시리얼 통신 시작
  SPI.begin();          // SPI 버스 초기화
  rfid.PCD_Init();      // RFID 리더기 초기화
  pinMode(5,OUTPUT);
}

void loop() {
   if (rfid.PICC_ReadCardSerial() || rfid.PICC_IsNewCardPresent()){
    if(state==0){
      state=1;
      Serial.println("시동 ON");
      digitalWrite(5,HIGH);
    }
    else if(state==1){
      state=0;
      Serial.println("시동 OFF");
      digitalWrite(5,LOW);
    }
    delay(500);
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }

    if(Serial.available())
  {
    input = Serial.read();
   
    if(input == '1') // 녹음
    {
      digitalWrite(REC,HIGH);
      delay(3000);
      digitalWrite(REC,LOW);
      Serial.println("REC...");
    }
    else if(input == '2') // 재생
  {
      digitalWrite(PLAYE,HIGH);
      Serial.println("PLAYE...");
      delay(10);
      digitalWrite(PLAYE,LOW);
  }
}

if(state==1){
  alcohol = analogRead(A0);
  Serial.println(alcohol);

  if(alcohol>400)
  {
    num++;
    if(num%500 == 0){
      digitalWrite(PLAYE,HIGH);
      Serial.println("PLAYE...");
      delay(10);
      digitalWrite(PLAYE,LOW);
    }
    if(num/500 > 3){
      state=0;
      Serial.println("시동 OFF");
      digitalWrite(5,LOW);
    }
  }
  else{
    num = 0;
  }
}

}


