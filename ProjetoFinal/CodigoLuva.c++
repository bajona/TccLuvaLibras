

#define botao1 8 //definindo porta de entrada do botão 1
#define botao2 9 //definindo porta de entrada do botão 2



int flexSensorPin = A12; // definindo porta de entrada para sensor flexível 1
int flexSensorPin1 = A11; // definindo porta de entrada para sensor flexível 2
int flexSensorPin2 = A10; // definindo porta de entrada para sensor flexível 3
int flexSensorPin3 = A9; // definindo porta de entrada para sensor flexível 4
int flexSensorPin4 = A8; // definindo porta de entrada para sensor flexível 5

#include <Wire.h> // Biblioteca utilizada para fazer a comunicação com o I2C
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);


const int MPU=0x68;  
int AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

void setup()
{
  Serial.begin(9600);
    lcd.begin(16, 2);
  lcd.clear(); // Serve para limpar a tela do display
 
  pinMode(botao1, INPUT); // indicador
  pinMode(botao2, INPUT); // dedão

  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
   
  //Inicializa o MPU-6050
  Wire.write(0); 
  Wire.endTransmission(true);
 
}

void loop()
{
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  //Solicita os dados do sensor
  Wire.requestFrom(MPU,14,true);  
  //Armazena o valor dos sensores nas variaveis correspondentes
  AcX=Wire.read()<<8|Wire.read();     
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read();
  GyY=Wire.read()<<8|Wire.read(); 
  GyZ=Wire.read()<<8|Wire.read();
  
  
  
  
  int flexSensorReading = analogRead(flexSensorPin4); 
//Serial.print("Sensor 5 = ");  
//Serial.println(flexSensorReading);

  int flexSensorReading1 = analogRead(flexSensorPin3);
//Serial.print("Sensor 4 = ") ; 
//Serial.println(flexSensorReading1);
  
  int flexSensorReading2 = analogRead(flexSensorPin2);
//Serial.print("Sensor 3 = ") ; 
//Serial.println(flexSensorReading2);
  
  int flexSensorReading3 = analogRead(flexSensorPin1);
//Serial.print("Sensor 2 = ") ; 
//Serial.println(flexSensorReading3);
  
  int flexSensorReading4 = analogRead(flexSensorPin);
Serial.print("Sensor 1 = ") ; 
Serial.println(flexSensorReading4);

 if ((flexSensorReading >=100) && (flexSensorReading1 >=100) && (flexSensorReading2 >=100) && (flexSensorReading3 >=100)&& (flexSensorReading4 <100) && (digitalRead(botao1)) && (AcX > 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 ) && (GyX> -450 && GyX < 450 ))) {
 
   
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: A");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);
  }
else if ((flexSensorReading <100) && (flexSensorReading1 <100) && (flexSensorReading2 <100) && (flexSensorReading3 <100) && (flexSensorReading4 >=100) && (digitalRead(botao1)) && (digitalRead(botao2)) && (AcX > 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 )&& (GyX> -450 && GyX < 450 )) ) {

  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: B");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);
  }

  else if ((flexSensorReading >=100) && (flexSensorReading1 >=100) && (flexSensorReading2 >=100) && (flexSensorReading3 >=100) && (flexSensorReading4 >=100) && (digitalRead(botao2)) && (AcX > 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 ) && (GyX> -450 && GyX < 450 ))){

  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: C");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);
  }

 else if ((flexSensorReading >=100) && (flexSensorReading1 >=100) && (flexSensorReading2 >=100) && (flexSensorReading4 >=100) && (flexSensorReading3 < 100) && (AcX > 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 )&& (GyX> -450 && GyX < 450 ))){

  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: D");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);
 }

  else if ((flexSensorReading >=100) && (flexSensorReading1 >=100) && (flexSensorReading2 >=100) && (flexSensorReading3 >=100) && (flexSensorReading4 >=100)&& (AcX > 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 )&& (GyX> -450 && GyX < 450 ))){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: E");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  }
  else if ((flexSensorReading <100) && (flexSensorReading1 <100) && (flexSensorReading2 <100) && (flexSensorReading3 >=100) && (flexSensorReading4 <100) && (digitalRead(botao2))&& (AcX > 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 )&& (GyX> -450 && GyX < 450 ))){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: F");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  }
  else if ((flexSensorReading >=100) && (flexSensorReading1 >=100) && (flexSensorReading2 >=100) && (flexSensorReading3 <100) && (flexSensorReading4 >=100) && (digitalRead(botao2))&& (AcX > 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 )&& (GyX> -450 && GyX < 450 ))){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: G");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  }
  else if ((flexSensorReading >=100) && (flexSensorReading1 >=100) && (flexSensorReading2 >=100) && (flexSensorReading3 <100) && (flexSensorReading4 <100) && (digitalRead(botao2))&& (AcX > 0) && (( GyZ < -450 || GyZ > 450) || (GyY < -450 || GyY > 450 ) || (GyX < -450 || GyX > 450 ))){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: H");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  }
  else if ((flexSensorReading <100) && (flexSensorReading1 >=100) && (flexSensorReading2 >=100) && (flexSensorReading3 >=100) && (flexSensorReading4 >=100) && (digitalRead(botao2)) && (digitalRead(botao1)) && (AcX > 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 )&& (GyX> -450 && GyX < 450 ))){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: I");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  }
  else if ((flexSensorReading <100) && (flexSensorReading1 >=100) && (flexSensorReading2 >=100) && (flexSensorReading3 >=100) && (flexSensorReading4 >=100) && (digitalRead(botao2)) && (digitalRead(botao1)) && (( GyZ < -450 || GyZ > 450) || (GyY < -450 || GyY > 450 ) || (GyX < -450 || GyX > 450 ))){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: J");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  }
    else if ((flexSensorReading >=100) && (flexSensorReading1 >=100) && (flexSensorReading2 >=100) && (flexSensorReading3 <100) && (flexSensorReading4 <100) && (digitalRead(botao2))&& (AcX > 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 )&& (GyX> -450 && GyX < 450 ))){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: K");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  } 
  else if ((flexSensorReading >=100) && (flexSensorReading1 >=100) && (flexSensorReading2 >=100) && (flexSensorReading3 <100) && (flexSensorReading4 <100) && (AcX > 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 )&& (GyX> -450 && GyX < 450 ))){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: L");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  }
  else if ((flexSensorReading >=100) && (flexSensorReading1 <100) && (flexSensorReading2 <100) && (flexSensorReading3 <100) && (flexSensorReading4 >=100) && (digitalRead(botao2)) && (digitalRead(botao1)) && (AcX < 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 )&& (GyX> -450 && GyX < 450 ))){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: M");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  }
    else if ((flexSensorReading >=100) && (flexSensorReading1 <100) && (flexSensorReading2 <100) && (flexSensorReading3 >=100) && (flexSensorReading4 >=100) && (digitalRead(botao2)) && (digitalRead(botao1)) && (AcX < 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 )&& (GyX> -450 && GyX < 450 ))){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: N");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  }
      else if ((flexSensorReading >=100) && (flexSensorReading1 >=100) && (flexSensorReading2 >=100) && (flexSensorReading3 >=100) && (flexSensorReading4 >=100) && (digitalRead(botao2)) && (digitalRead(botao1)) && (AcX > 0) && (( GyZ < -450 || GyZ > 450) || (GyY < -450 || GyY > 450 ) || (GyX < -450 || GyX > 450 )) ){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: O");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  }
  else if ((flexSensorReading <100) && (flexSensorReading1 <100) && (flexSensorReading2 >=100) && (flexSensorReading3 >=100) && (flexSensorReading4 >=100) && (digitalRead(botao2)) && (AcX < 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 )&& (GyX> -450 && GyX < 450 ))){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: P");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  }   else if ((flexSensorReading <100) && (flexSensorReading1 <100) && (flexSensorReading2 >=100) && (flexSensorReading3 >=100) && (flexSensorReading4 >=100) && (AcX < 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 )&& (GyX> -450 && GyX < 450 ))){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: Q");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  } else if ((flexSensorReading >=100) && (flexSensorReading1 >=100) && (flexSensorReading2 <100) && (flexSensorReading3 >=100) && (flexSensorReading4 >=100) && (digitalRead(botao2)) && (digitalRead(botao1)) && (AcX > 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 )&& (GyX> -450 && GyX < 450 ))){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: R");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  } else if ((flexSensorReading >=100) && (flexSensorReading1 >=100) && (flexSensorReading2 >=100) && (flexSensorReading3 >=100) && (flexSensorReading4 >=100) && (digitalRead(botao2)) && (digitalRead(botao1)) && (AcX > 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 )&& (GyX> -450 && GyX < 450 ))){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: S");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  }
  else if ((flexSensorReading <100) && (flexSensorReading1 >=100) && (flexSensorReading2 <100) && (flexSensorReading3 <100) && (flexSensorReading4 <100) && (AcX > 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 )&& (GyX> -450 && GyX < 450 ))){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: T");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  }
    else if ((flexSensorReading >=100) && (flexSensorReading1 <100) && (flexSensorReading2 <100) && (flexSensorReading3 >=100) && (flexSensorReading4 >=100) && (digitalRead(botao2)) && (digitalRead(botao1)) && (AcX > 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 )&& (GyX> -450 && GyX < 450 ))){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: U");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  }
      else if ((flexSensorReading >=100) && (flexSensorReading1 <100) && (flexSensorReading2 <100) && (flexSensorReading3 >=100) && (flexSensorReading4 >=100) && (digitalRead(botao2)) && (AcX > 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 )&& (GyX> -450 && GyX < 450 ))){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: V");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  }    else if ((flexSensorReading >=100) && (flexSensorReading1 <100) && (flexSensorReading2 <100) && (flexSensorReading3 <100) && (flexSensorReading4 >=100) && (digitalRead(botao2)) && (AcX > 0) && (( GyZ > -450 && GyZ < 450) && (GyY > -450 && GyY < 450 )&& (GyX> -450 && GyX < 450 ))){
  
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: W");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  }  else if ((flexSensorReading >=100) && (flexSensorReading1 >=100) && (flexSensorReading2 >=100) && (flexSensorReading3 >=100) && (flexSensorReading4 >=100)&& (digitalRead(botao2)) && (( GyZ < -450 || GyZ > 450) || (GyY < -450 || GyY > 450 ) || (GyX < -450 || GyX > 450 )) ){
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: X");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  } else if ((flexSensorReading <100) && (flexSensorReading1 >=100) && (flexSensorReading2 >=100) && (flexSensorReading3 >=100) && (flexSensorReading4 <100) && (digitalRead(botao1)) && (( GyZ < -450 || GyZ > 450) || (GyY < -450 || GyY > 450 ) || (GyX < -450 || GyX > 450 ))){
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: Y");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  } else if ((flexSensorReading >=100) && (flexSensorReading1 <100) && (flexSensorReading2 >=100) && (flexSensorReading3 >=100) && (flexSensorReading4 >=100) && (digitalRead(botao2)) && (( GyZ < -450 || GyZ > 450) || (GyY < -450 || GyY > 450 ) || (GyX < -450 || GyX > 450 )) ){
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Letra: Z");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  }
else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Aguardando Entr-");
    lcd.setCursor(0, 1);
    lcd.print("ada de dados");
                }
 if ((flexSensorReading <100) && (flexSensorReading1 <100) && (flexSensorReading2 <100) && (flexSensorReading3 <100) && (flexSensorReading4 <100) && (digitalRead(botao1)) && (( GyZ < -450 || GyZ > 450) || (GyY < -450 || GyY > 450 ) || (GyX < -450 || GyX > 450 )) ){
   lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Espaço");
  lcd.setCursor(0, 1);
  lcd.print("Ins. Prox Letra");
  delay(1000);  
  }            
  delay(1500);
}