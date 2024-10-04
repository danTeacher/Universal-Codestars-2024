LedControl lc=LedControl(13,12,11,4);
int num;

void setup() {
  sv1.attach(9);
  sv2.attach(10);
  for(num=0; num<4; num++)
  {
    lc.shutdown(num,false);
    lc.setIntensity(num,5);
    lc.clearDisplay(num);
  }
}

void can()
{
  byte can1[8]={
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  };
  byte can2[8]={
    B00000000,
    B00110001,
    B01001010,
    B01000011,
    B01001010,
    B00110010,
    B00000000,
    B00000000
  };
  byte can3[8]={
    B00000000,
    B00100010,
    B10110010,
    B10101010,
    B10100110,
    B10100010,
    B00000000,
    B00000000
  };
  byte can4[8]={
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  };

  for(int j=0; j<8; j++){
    lc.setRow(3,j,can1[j]);
    lc.setRow(2,j,can2[j]);
    lc.setRow(1,j,can3[j]);
    lc.setRow(0,j,can4[j]);
  }
  delay(1000);
}

void pla()
{
  byte pla1[8]={
    B00000000,
    B00111010,
    B00101010,
    B00111010,
    B00100010,
    B00100011,
    B00000000,
    B00000000
  };
  byte pla2[8]={
    B00000000,
    B00010001,
    B00101010,
    B00111001,
    B00101000,
    B10101011,
    B00000000,
    B00000000
  };
  byte pla3[8]={
    B00000000,
    B11011101,
    B00001000,
    B10001000,
    B01001000,
    B10001001,
    B00000000,
    B00000000
  };
  byte pla4[8]={
    B00000000,
    B11001100,
    B10010000,
    B10010000,
    B10010000,
    B11001100,
    B00000000,
    B00000000
  };

  for(int j=0; j<8; j++){
    lc.setRow(3,j,pla1[j]);
    lc.setRow(2,j,pla2[j]);
    lc.setRow(1,j,pla3[j]);
    lc.setRow(0,j,pla4[j]);
  }
  delay(1000);
}

void pap()
{
  byte pap1[8]={
    B00000000,
    B00000011,
    B00000010,
    B00000011,
    B00000010,
    B00000010,
    B00000000,
    B00000000
  };
  byte pap2[8]={
    B00000000,
    B10010011,
    B10101010,
    B10111011,
    B00101010,
    B00101010,
    B00000000,
    B00000000
  };
  byte pap3[8]={
    B00000000,
    B10111011,
    B10100010,
    B10111011,
    B00100010,
    B00111010,
    B00000000,
    B00000000
  };
  byte pap4[8]={
    B00000000,
    B10000000,
    B01000000,
    B11000000,
    B10000000,
    B01000000,
    B00000000,
    B00000000
  };

  for(int j=0; j<8; j++){
    lc.setRow(3,j,pap1[j]);
    lc.setRow(2,j,pap2[j]);
    lc.setRow(1,j,pap3[j]);
    lc.setRow(0,j,pap4[j]);
  }
  delay(1000);
}

void loop() {
  Serial.begin(9600);
  sv1.write(120);
  sv2.write(90);
  for(num=0; num<4; num++){
    lc.clearDisplay(num);
  };
  delay(1500);
  char c = Serial.read();

  if(c=='3'){
    Serial.end();
    delay(1000);
  }
  else if(c=='0'){
    Serial.end();
    can();
    sv1.write(170);
    delay(1000);
    sv2.write(30);
    delay(1000);
  }
  else if(c=='1'){
    Serial.end();
    pla();
    sv1.write(170);
    delay(1000);
    sv2.write(150);
    delay(1000);
  }
  else if(c=='2'){
    Serial.end();
    pap();
    sv1.write(40);
    delay(1000);
  }
 
}
