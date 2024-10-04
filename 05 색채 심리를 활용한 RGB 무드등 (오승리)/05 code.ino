#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <IRremote.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int c = 1;
int a = 0;

void change(){
  if(c == 1){
    analogWrite(9,a);
    analogWrite(10,0);
    analogWrite(6,0);
  }
  if(c == 2){
    analogWrite(9,0);
    analogWrite(10,a);
    analogWrite(6,0);
  }
  if(c == 3){
    analogWrite(9,0);
    analogWrite(10,0);
    analogWrite(6,a);
  }

  lcd.clear();
        
  lcd.setCursor(0, 0);                            // 커서를 첫번째 문자 첫번째 라인으로 설정
  lcd.print("color: ");                           // "     " 안에 원하는 문자를 출력
  if(c == 1){
    lcd.print("RED");
  }
  if(c == 2){
    lcd.print("GREEN");
  }
  if(c == 3){
    lcd.print("BLUE");
  }
  
  lcd.setCursor(0, 1);                            // 커서를 첫번째 문자 두번째 라인으로 설정
  lcd.print("analog: ");                          // "      " 안에 원하는 문자를 출력
  lcd.print(a);
}

void setup() {

  pinMode(9,OUTPUT);  // 빨
  pinMode(10,OUTPUT); // 초
  pinMode(11,OUTPUT); // 파

  lcd.init();                                     // lcd 초기화
  lcd.backlight();                                // lcd 백라이트를 켠다
  lcd.setCursor(0, 0);                            // 커서를 첫번째 문자 첫번째 라인으로 설정
  lcd.print("color: ");                           // "     " 안에 원하는 문자를 출력
  lcd.print("RED");

  lcd.setCursor(0, 1);                            // 커서를 첫번째 문자 두번째 라인으로 설정
  lcd.print("analog: ");                          // "      " 안에 원하는 문자를 출력
  lcd.print(0);

  IrReceiver.begin(2, ENABLE_LED_FEEDBACK);
  Serial.begin(9600);
}

void loop(){
  if (IrReceiver.decode()) // 적외선 송신기로부터 수신 받은 신호가 있으면 실행
  {
    Serial.print("Command of the button in hexadecimal: ");
    Serial.println(IrReceiver.decodedIRData.command, HEX);

    switch(IrReceiver.decodedIRData.command)
    {
      case 0x45:
        Serial.println("1번 버튼");
        c = 1;
        change();
        break;
      case 0x46:
        Serial.println("2번 버튼"); 
        c = 2;
        change();
        break;
      case 0x47:
        Serial.println("3번 버튼"); 
        c = 3;
        change();  
        break;
      case 0x18:
        Serial.println("위 버튼");
        a = ( a < 255 ) ? a+85 : 255;
        change();  
        break;
      case 0x52:
        Serial.println("아래 버튼");
        a = ( a > 0 ) ? a-85 : 0;
        change();  
        break;
    }    
    IrReceiver.resume(); // 적외선 송신기로부터 다음 신호를 받을 수 있도록 대기
  }
}