const int flexPin = A12; //pino A4 declarado para receber saída analogica

//Variaveis:
int value; //salvar valor analogico


void setup(){
    //Set pin 3 as 'output'
  Serial.begin(9600);    

}

void loop(){
  
  value = analogRead(flexPin);         //ler e salvar valor analogico do potenciometro
  Serial.println(value);               //enviar valor para o serial monitor
  value = map(value, 700, 900, 0, 255);//Mapear valor 0-1023 para 0-255 (PWM)

  delay(100);                          //um delay pequeno para ficar mais facil de ler a medição
}