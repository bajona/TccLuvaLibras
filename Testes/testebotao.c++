int buttonPin = 8;
//Definindo a saida do pino para maior clareza ( LED Verde)

//Variavel para fazer a checagem
int buttonState;

void setup()
{
  
  // Define o pino do botao como entrada
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  // Define o pino do Led Verde como Saida
}

void loop() 
{
  // Verifica se o estado do botao foi alterado
  buttonState = digitalRead(buttonPin);
  //Se o botao foi apertado
  if (buttonState == LOW) 
  {
   // Liga o LED    
    Serial.println("nao pressionado");  
  } 
  else 
  {
    // Apaga o LED
    Serial.println("pressionado"); 
  }
}
