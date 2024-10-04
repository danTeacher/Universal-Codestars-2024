#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"


SoftwareSerial mySoftwareSerial(11, 12); // 소프트웨어 시리얼 용 핀 지정
DFRobotDFPlayerMini myDFPlayer;              // 객체 생성
void printDetail(uint8_t type, int value);


int level = 0;


void setup()
{
  mySoftwareSerial.begin(9600);          // 소프트웨어 시리얼 통신 개시
  Serial.begin(115200);
 
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
 
  if (!myDFPlayer.begin(mySoftwareSerial), false) {  //객체 초기화
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
 
  myDFPlayer.setTimeOut(500); //시리얼 통신용 타임아웃 시간 지정
 
  myDFPlayer.volume(15);  //0-30사이의 값을 인수로 입력.
 
  myDFPlayer.play(1);
  while (true) { // 전체 재생시 사용
    if (myDFPlayer.available()) {
      if (myDFPlayer.readType() == DFPlayerPlayFinished) {
        break;  // 재생이 끝나면 루프 종료
      }
    }
    delay(100);
  }
}


void loop()
{


  if(level == 0){
    if(digitalRead(9)==LOW && digitalRead(10)==LOW){
      myDFPlayer.play(2);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(4);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(5);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(6);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      level = 1;
    }
  }
  else if(level == 1){
    if(digitalRead(9)==LOW){ // 왼쪽
    myDFPlayer.play(2);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
    myDFPlayer.play(8);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(9);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(10);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      level=2;
    }
    else if(digitalRead(10)==LOW){ // 오른쪽
    myDFPlayer.play(2);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
    myDFPlayer.play(7);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(8);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(9);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(10);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      level=2;
    }
  }
  else if(level==2){
    if(digitalRead(9)==LOW){
      myDFPlayer.play(2);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(11);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(12);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(13);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      level=3;
    }
    else if(digitalRead(10)==LOW){
      myDFPlayer.play(2);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(15);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(16);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(17);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(18);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      level=4;
    }
  }
  else if(level==3){
    if(digitalRead(9)==LOW){
      myDFPlayer.play(2);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(14);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(3);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100000000000000000000000);
      }
      return 0;
    }
    else if(digitalRead(10)==LOW){
      myDFPlayer.play(2);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(15);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(16);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(17);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(18);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      level=4;


    }
  }
  else if(level==4){
    if(digitalRead(9)==LOW){
      myDFPlayer.play(2);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(19);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(20);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(21);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      level=5;
    }
    if(digitalRead(10)==LOW){
      myDFPlayer.play(2);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(24);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(30);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(31);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(32);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
     level=8;
    }
  }
  else if(level==5){
    if(digitalRead(9)==LOW){
      myDFPlayer.play(2);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(22);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(23);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      level=6;
    }
    else if(digitalRead(10)==LOW){
      myDFPlayer.play(2);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(30);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(31);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(32);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      level=8;
    }
  }
  else if(level==6){
    if(digitalRead(9)==LOW){
      myDFPlayer.play(2);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(25);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(26);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(27);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      level=7;
    }
    else if(digitalRead(10)==LOW){
      myDFPlayer.play(2);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(33);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(35);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(36);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(37);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(38);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(39);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(40);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(3);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100000000000000000);
      }
      return 0;
    }
  }
  else if(level==7){
    if(digitalRead(9)==LOW){
      myDFPlayer.play(2);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(28);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(29);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(3);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(1000000000000000);
      }
      return 0;
    }
    else if(digitalRead(10)==LOW){
      myDFPlayer.play(2);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(34);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(35);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(36);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(37);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(38);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(39);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(40);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(3);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(1000000000000000000);
      }
      return 0;
    }
  }
  else if(level==8){
    if(digitalRead(9)==LOW){
      myDFPlayer.play(2);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(34);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(35);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(36);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(37);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(38);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(39);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(40);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(3);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(10000000000000000000000000);
      }
      return 0;
    }
    else if(digitalRead(10)==LOW){
      myDFPlayer.play(2);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(33);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(35);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(36);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(37);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(38);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(39);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(40);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(100);
      }
      myDFPlayer.play(3);
      while (true) { // 전체 재생시 사용
        if (myDFPlayer.available()) {
          if (myDFPlayer.readType() == DFPlayerPlayFinished) {
            break;  // 재생이 끝나면 루프 종료
          }
        }
        delay(1000000000000000);
      }
      return 0;
    }
  }


 
}





