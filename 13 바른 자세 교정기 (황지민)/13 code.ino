const int backSensorPin = A0; 
const int waistSensorPin = A1;
const int spineSensorPin = A2;
const int buzzerPin = 9;
const int redLEDPin = 10; 
const int yellowLEDPin = 11; 
const int greenLEDPin = 12;


const int threshold = 900; 


void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  int backValue = analogRead(backSensorPin);
  int waistValue = analogRead(waistSensorPin);
  int spineValue = analogRead(spineSensorPin);


  Serial.print("Back: ");
  Serial.print(backValue);
  Serial.print(", Waist: ");
  Serial.print(waistValue);
  Serial.print(", Spine: ");
  Serial.println(spineValue);


  bool buzzerOn = false; 




  if (backValue < threshold) {
    digitalWrite(redLEDPin, LOW);
    buzzerOn = true; 
  } else {
    digitalWrite(redLEDPin, HIGH); 
  }


  if (waistValue < threshold) {
    digitalWrite(yellowLEDPin, LOW); 
    buzzerOn = true; 
  } else {
    digitalWrite(yellowLEDPin, HIGH); 
  }


  if (spineValue < threshold) {
    digitalWrite(greenLEDPin, LOW); 
    buzzerOn = true; 
  } else {
    digitalWrite(greenLEDPin, HIGH); 
  }


  if (buzzerOn) {
    digitalWrite(buzzerPin, HIGH); 
  } else {
    digitalWrite(buzzerPin, LOW); 
  }
  delay(500);
}
