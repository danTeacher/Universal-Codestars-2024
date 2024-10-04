int mino1;//도로1
int mino2;//도로2
int mino3;//도로3
int mino4;//도로4
int ir1pin = 2;
int ir2pin = 3;
int ir3pin = 4;
int ir4pin = 5;
int ir5pin = 6;
int ir6pin = 7;
int ir7pin = 8;
int ir8pin = 9;


void setup() {
 Serial.begin(9600);
pinMode(13,OUTPUT);
pinMode(12,INPUT);
pinMode(ir1pin, INPUT);
pinMode(ir2pin, INPUT);
pinMode(ir3pin, INPUT);
pinMode(ir4pin, INPUT);
pinMode(ir5pin, INPUT);
pinMode(ir6pin, INPUT);
pinMode(ir7pin, INPUT);
pinMode(ir8pin, INPUT);
}


void loop() {
  int ir1 = digitalRead(ir1pin);
  Serial.print(ir1);
    int ir2 = digitalRead(ir2pin);
  Serial.print(ir2);
    int ir3 = digitalRead(ir3pin);
  Serial.print(ir3);
    int ir4 = digitalRead(ir4pin);
  Serial.print(ir4);
    int ir5 = digitalRead(ir5pin);
  Serial.print(ir5);
    int ir6 = digitalRead(ir6pin);
  Serial.print(ir6);
    int ir7 = digitalRead(ir7pin);
  Serial.print(ir7);
    int ir8 = digitalRead(ir8pin);
  Serial.println(ir8);


 


  if(ir1 == 1 && ir2 == 1) {
    Serial.println("차 없음");
    mino1 = 0;
  }
  else if(ir1 == 1 && ir2 == 0) {
    Serial.println("차 조금");
    mino1 = 1;
  }
  else if(ir1 == 0 && ir2 == 0) {
    Serial.println("차 많음");
    mino1 = 2;
  }
  if(ir3 == 1 && ir4 == 1) {
    Serial.println("차 없음");
    mino2 = 0;
  }
  else if(ir3 == 1 && ir4 == 0) {
    Serial.println("차 조금");
      mino2 = 1;
  }
  else if(ir3 == 0 && ir4 == 0) {
    Serial.println("차 많음");
      mino2 = 2;
  }
  if(ir5 == 1 && ir6 == 1) {
    Serial.println("차 없음");
      mino3 = 0;
  }
  else if(ir5 == 1 && ir6 == 0) {
    Serial.println("차 조금");
    mino3 = 1;
  }
  else if(ir5 == 0 && ir6 == 0) {
    Serial.println("차 많음");
    mino3 = 2;
  }
  if(ir7 == 1 && ir8 == 1) {
    Serial.println("차 없음");
    mino4 = 0;
  }
  else if(ir7 == 1 && ir8 == 0) {
    Serial.println("차 조금");
      mino4 = 1;
  }
  else if(ir7 == 0 && ir8 == 0) {
    Serial.println("차 많음");
      mino4 = 2;
  }
  if(mino1+mino3>mino2+mino4){
    digitalWrite(13,HIGH);
    Serial.println("1번도로 많음");
  }
  else {
    digitalWrite(13,LOW);
    Serial.println("2번도로 많음");
  }


 
  delay(1000);


}
