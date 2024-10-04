#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


// 키패드 설정
const byte ROWS = 4; // 4행
const byte COLS = 3; // 3열
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; // 행 핀
byte colPins[COLS] = {6, 7, 8}; // 열 핀
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


// LCD 설정 (I2C 주소, 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);


// 가전제품 목록 및 전류량 (암페어)
const char* devices[] = {
  "Dc Motor",
  "200L Fridge",
  "Side-by-Side Fridge",
  "Kimchi Fridge",
  "25-inch TV",
  "29-inch TV",
  "10kg Washing Machine",
  "5-person Rice Cooker",
  "Hot & Cold Water Dispenser",
  "Air Purifier"
};


int index = -1;


// 전류량 설정 (단위: 암페어)
const float deviceCurrent[] = {
  505.0, // Air Conditioner
  502.0, // 200L Fridge
  2.0, // Side-by-Side Fridge
  2.0, // Kimchi Fridge
  0.5, // 25-inch TV
  0.6, // 29-inch TV
  25.0, // 10kg Washing Machine
  2.0, // 5-person Rice Cooker
  2.0, // Hot & Cold Water Dispenser
  0.5  // Air Purifier
};


void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Select a device");
  Serial.begin(9600); // 디버깅을 위한 시리얼 통신
}


void loop() {
  char key = keypad.getKey();


  if (key) {
    if (key == '*') {
      // * 키가 눌리면 LCD 화면을 초기화하고 "Select a device" 메시지를 표시
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Select a device");
      return; // 나머지 코드 실행 방지
    }
    index = key - '0'; // 숫자를 인덱스로 변환
  }
  if (index == -1) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Select a device");
  }
  else {
    float current = getCurrentForDevice(); // 가전제품의 전류량을 측정합니다.
    const float currentThreshold = deviceCurrent[index];


    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Device: ");
    lcd.setCursor(0, 1);
    lcd.print(devices[index]);
     
    // 전류량이 임계값을 초과하는지 확인
      if (current < currentThreshold) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("WARNING:");
        lcd.setCursor(0, 1);
        lcd.print("Current Exceeded");
        delay(1000); // 경고 메시지 표시
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Device: ");
        lcd.setCursor(0, 1);
        lcd.print(devices[index]);
        delay(1000); // 정상 메시지 표시
      }
     
      Serial.print("Selected device: ");
      Serial.print(devices[index]);
      Serial.print(", Current: ");
      Serial.print(current);
      Serial.print("threshold: ");
      Serial.println(currentThreshold);
  }    


}


float getCurrentForDevice() {
  // 실제 전류 측정 로직을 구현합니다.
  // 이 함수는 전류 센서에서 측정된 값을 반환합니다.
  // 이 예제에서는 가상 값을 반환합니다.
  // 실제 구현 시 전류 센서의 값을 읽어야 합니다.


  // 전류 센서 연결 핀
  int sensorPin = A0; // 예를 들어 아날로그 핀 A0에 연결
  int sensorValue = analogRead(sensorPin); // 센서 값 읽기
  float voltage = sensorValue; //* (1.5 / 1023.0); // 220V 기준으로 전압 변환
  float current = voltage; //* 30.0; // 전압을 암페어로 변환 (센서의 특성에 따라 조정 필요)


  return current;
}