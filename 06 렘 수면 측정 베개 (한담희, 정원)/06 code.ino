int Led = 3;
int FSRsensor3 = A0;
int FSRsensor2 = A1;
int FSRsensor1 = A2;
int btn = 2;
int buzzer = 3;
int value1 = 0;
int value3 = 0;
int value2 = 0;
int now1 = 0;
int now2 = 0;
int now3 = 0;




void setup()
{
  pinMode(FSRsensor3, INPUT);
  pinMode(FSRsensor2, INPUT);
  pinMode(FSRsensor1, INPUT);
  pinMode(btn, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,INPUT);
  Serial.begin(9600);
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Time,S1,S2,S3");




}


void alarm(){
  //버튼이 눌리면 종료됨.
    while(1){
  tone(3, 330, 500);
  delay(500);
  tone(3, 294, 100);
  delay(500);
  tone(3,262,400);
  delay(400);        
  tone(3, 294, 100);
  delay(100);


  if(digitalRead(2)==1){
    Serial.print("버튼 클릭");
      return ;
    }


  tone(3, 330, 100);
  delay(500);
  tone(3, 330, 100);
  delay(500);
  tone(3, 330, 100);
  delay(500);


  if(digitalRead(2)==1){
    Serial.print("버튼 클릭");
      return ;
    }


  tone(3, 294, 100);
  delay(500);
  tone(3, 294, 100);
  delay(500);
  tone(3, 294, 100);
  delay(1000);
  if(digitalRead(2)==1){
    Serial.print("버튼 클릭");
      return ;
    }


  tone(3, 330, 100);
  delay(500);
  tone(3, 330, 100);
  delay(500);
  tone(3, 330, 100);
  delay(500);


  if(digitalRead(2)==1){
    Serial.print("버튼 클릭");
      return ;
    }


   tone(3, 659, 100);
  delay(1000);
  tone(3, 294, 100);
  delay(1000);
  tone(3,262,100);
  delay(1000);        
  tone(3, 294, 100);
  delay(2000);


  if(digitalRead(2)==1){
    Serial.print("버튼 클릭");
      return ;
    }


   tone(3, 330, 100);
  delay(1000);
  tone(3, 330, 100);
  delay(1000);
  tone(3, 330, 100);
  delay(2000);


  if(digitalRead(2)==1){
    Serial.print("버튼 클릭");
      return ;
    }


  tone(3,294,100);
  delay(1000);
  tone(3,294,100);
  delay(1000);
  tone(3,330,100);
  delay(1000);


  if(digitalRead(2)==1){
    Serial.print("버튼 클릭");
      return ;
    }


  tone(3,264,100);
  delay(1000);
  tone(3,262,100);
  delay(1000);
    }


    if(digitalRead(2)==1){
    Serial.print("버튼 클릭");
      return ;
    }


}




void loop()
{
  // 10분에 1번 잰다고 가정 -> 총 10시간 재고 종료
  for (int i=0; i<60*60; i++){  
    value3 = analogRead(FSRsensor3);
    value2 = analogRead(FSRsensor2);
    value1 = analogRead(FSRsensor1);




    Serial.print("DATA,TIME,");
    Serial.print(value1);
    Serial.print(",");
    Serial.print(value2);
    Serial.print(",");
    Serial.println(value3);
    value1 = map(value1,0,1023,0,255);
    value2 = map(value2,0,1023,0,255);
    value3 = map(value3,0,1023,0,255);
    //analogWrite(Led,value);


    //첫 100분동안은 잠이 들고, 110분째의 압력 센서 값을 저장한다.
    if(i==10){ //우선 테스트를 위해 10의 값을 넣어준다.
      now1=value1;
      now2=value2;
      now3=value3;
      Serial.print("100분이 되었습니다. 현재값은 ");
      Serial.print(value1);
      Serial.print(",");
      Serial.print(value2);
      Serial.print(",");
      Serial.println(value3);


    }
    //사용자가 잠들어 있을 때 센서 값을 측정해서 센서 값이 달라지면 알람을 울린다.
    if(i>10){


      //현재 입력된 value 값들과 처음 잠들 때 저장한 now 값들의 차가 ___이상일 때 렘 수면이라고 판단하고 알람을 울린다.
      //여기서 100의 값은 임의 값이며 사용자에 따라 조정해준다.


      //abs() : 절댓값을 계산해줌
      int check1= abs(value1-now1);
      int check2= abs(value2-now2);
      int check3= abs(value3-now3);


      if(check1 > 100 ||check2 > 100 ||check3 > 100){
        Serial.print("알람이 울립니다");
        alarm();
        exit(0);
      }
    }
   


    delay(1000); // 10분
  }


  //10시간이지나면 자동으로 알람 실행
  alarm();




  exit(0);
}
