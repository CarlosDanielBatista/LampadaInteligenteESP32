/*Feito por Carlos Daniel Batista e Ariel Vieira de Oliveira para materia de 
Projeto de Sistemas embarcados do segundo semestre de 2020, aulas ministradas 
pelos professores Cesar Albenes Zeferino, Paulo Roberto Valim e Felipe Viel.*/

#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <WiFi.h>
#include<WiFiClient.h>
#include<BlynkSimpleEsp32.h>

char auth[] = "1nhfIAGxBrBy6iuvWSb4mEZm_rHRoEKe";
char ssid[] = "BR7 BATISTA 2.4G";
char pass[] = "deskjetf2050";


#define LDR 4 // Porta do LDR
#define RED 18 // Porta do LED RGB - VERMELHO
#define GREEN 19 // Porta do LED RGB - VERDE
#define BLUE 21 // Porta do LED RGB - AZUL
#define LED 23 // Porta do LED
#define PIR 13 // Porta do PIR

#define R 0
#define G 1
#define B 2

#define Frequencia 5000 // pwm

#define Resolucao 8 //8 bit
BLYNK_WRITE(V0){//Teste LED RGB 
  void RGB_Cor(int i, int j, int k);
  int pinValue = param.asInt();
  if(pinValue == 1){
    RGB_Cor(255,0,0);// Vermelho
    delay(500);//Tempo de 1/2 segundo
    RGB_Cor(0,255,0); //Verde
    delay(500);//Tempo de 1/2 segundo
    RGB_Cor(0,0,255);// Azul
    delay(500);//Tempo de 1/2 segundo
    RGB_Cor(255,255,255); //Todas as cores
    delay(500); //Tempo de 1/2 segundo
    RGB_Cor(0,0,0); //Apagado
    delay(500); //Tempo de 1/2 segundo
  }else{
    RGB_Cor(0,0,0); //Apagado
    delay(500); //Tempo de 1/2 segundo
  }
}

BLYNK_WRITE(V1){//Teste LED
  int pinValue = param.asInt();
  if(pinValue == 1){
  digitalWrite(LED, HIGH); //Acenter Led
  delay(250);//Tempo de 1/4 segundo
  digitalWrite(LED, LOW); //Apagar Led
  delay(250);//Tempo de 1/4 segundo
  digitalWrite(LED, HIGH); //Acenter Led
  delay(250);//Tempo de 1/4 segundo
  digitalWrite(LED, LOW); //Apagar Led
  delay(250);//Tempo de 1/4 segundo
  }else{
    digitalWrite(LED, LOW); //Apagar Led
  delay(250);//Tempo de 1/4 segundo
  }
}

BLYNK_WRITE(V2){ //Desligar LEDs
  void RGB_Cor(int i, int j, int k);
  int pinValue = param.asInt();
   if(pinValue == 1){
    digitalWrite(LED, LOW); //Acenter Led
    delay(250);
    RGB_Cor(0,0,0); //Apagado
    delay(500); //Tempo de 1/2 segundo
  }else{
    RGB_Cor(0,0,0); //Apagado
    delay(500); //Tempo de 1/2 segundo
  }
}
BLYNK_WRITE(V3){// LED com LDR
  void RGB_Cor(int i, int j, int k);
  int pinValue = param.asInt();
  if(pinValue == 1){
  int LDR_val = analogRead(LDR); // Função para leitura do LDR
  Serial.println(LDR_val); //Função para printar o LDR
    if(LDR_val == 0){
      do{
        digitalWrite(LED, HIGH); //Acenter Led
      }while(LDR_val > 0);
    }else{
    RGB_Cor(0,0,0);
    }
  }else{
    RGB_Cor(0,0,0); //Apagado
    delay(500); //Tempo de 1/2 segundo
  }
}

BLYNK_WRITE(V4){ //RGB com LDR
  void RGB_Cor(int i, int j, int k);
  int pinValue = param.asInt();
  if(pinValue == 1){
  int LDR_val = analogRead(LDR); // Função para leitura do LDR
  Serial.println(LDR_val); //Função para printar o LDR
    if(LDR_val == 0){
      do{
        RGB_Cor(255,255,255); //x = vermelho, y = verde e z = azul
      }while(LDR_val > 0);
    }else{
    RGB_Cor(0,0,0);
    }
  }else{
    RGB_Cor(0,0,0); //Apagado
    delay(500); //Tempo de 1/2 segundo
  }
}

BLYNK_WRITE(V5){ //Ligar Leds
  void RGB_Cor(int i, int j, int k);
int pinValue = param.asInt();
   if(pinValue == 1){
    digitalWrite(LED, HIGH); //Acenter Led
    RGB_Cor(255,255,255); //Apagado
    delay(500); //Tempo de 1/2 segundo
  }else{
    delay(500); //Tempo de 1/2 segundo
  }
}
BLYNK_WRITE(V6){ //LIGAR LED RGB VERMELHO
  void RGB_Cor(int i, int j, int k);
  int pinValue = param.asInt();
   if(pinValue == 1){
    RGB_Cor(255,0,0); //RGB Vermelho
    delay(500); //Tempo de 1/2 segundo
  }else{
    delay(5);
  }
}
BLYNK_WRITE(V7){ // LIGAR LED
    int pinValue = param.asInt();
  if(pinValue == 1){
  digitalWrite(LED, HIGH); //Acenter Led
  delay(250);//Tempo de 1/4 segundo
  }else{
  delay(250);//Tempo de 1/4 segundo
  }
}
BLYNK_WRITE(V8){// LED com PIR
  int pinValue = param.asInt();
   if(pinValue == 1){
    int PIR_val = analogRead(PIR); // Função para leitura do PIR analogico
  //int PIR_val = digitalRead(PIR); // Função para leitura do PIR digital
  Serial.println(PIR_val); //Função para printar o LDR
      if(PIR_val != 0){
      do{
        digitalWrite(LED, HIGH); //Função de ligar LED
        delay(30000); //Tempo de 30 segundos
      }while(PIR_val == 0);
      }else{
        digitalWrite(LED, LOW); //Função de desligar LED
      }}else{
    delay(500); //Tempo de 1/2 segundo
  }
}
BLYNK_WRITE(V9){ //RGB com PIR
   int pinValue = param.asInt();
   if(pinValue == 1){
    int PIR_val = analogRead(PIR); // Função para leitura do PIR analogico
  //int PIR_val = digitalRead(PIR); // Função para leitura do PIR digital
  Serial.println(PIR_val); //Função para printar o LDR
      if(PIR_val != 0){
      do{
        RGB_Cor(255,255,255); //Função de ligar LED
        delay(30000); //Tempo de 30 segundos
      }while(PIR_val == 0);
      }else{
        RGB_Cor(0,0,0); //Função de desligar LED
      }}else{
    delay(500); //Tempo de 1/2 segundo
  }
}
void setup(){
  pinMode(LED, OUTPUT); //LED padrão
  ledcAttachPin(RED, R); //LED RGB
  ledcAttachPin(GREEN, G); //LED RGB
  ledcAttachPin(BLUE, B); //LED RGB

  ledcSetup(R, Frequencia, Resolucao); //Configuração led RGB - VERMELHO
  ledcSetup(G, Frequencia, Resolucao); //Configuração led RGB - VERDE
  ledcSetup(B, Frequencia, Resolucao); //Configuração led RGB - AZUL
  Serial.begin(9600); // Taxa de comunicação serial em bits por segundoo
  Blynk.begin(auth, ssid, pass);
}
void RGB_Cor(int i, int j, int k){ //Função para controlar a temperantura\cor do RGB
  ledcWrite(R, k);
  ledcWrite(G, j);
  ledcWrite(B, i);
}
void loop(){
  Blynk.run();
  int x = 255; // Valor minimo = 0 e valor maximo = 255
  int y = 255; // Valor minimo = 0 e valor maximo = 255
  int z = 255; // Valor minimo = 0 e valor maximo = 255
  int func = 2; //Numero da Função
  int LDR_val = analogRead(LDR); // Função para leitura do LDR
  Serial.println(LDR_val); //Função para printar o LDR
  int PIR_val = analogRead(PIR); // Função para leitura do PIR analogico
  //int PIR_val = digitalRead(PIR); // Função para leitura do PIR digital
  Serial.println(PIR_val); //Função para printar o LDR
  switch(func) { // Função para escolher as opções de funcionamento
    case 1: //Modo Manual para acender o led RGB
        RGB_Cor(x,y,z); //x = vermelho, y = verde e z = azul
      break;
    case 2: //Teste LED
      delay(500);
      break;
    case 3: //Teste LED RGB 
      RGB_Cor(255,0,0);// Vermelho
      delay(500);//Tempo de 1/2 segundo
      RGB_Cor(0,255,0); //Verde
      delay(500);//Tempo de 1/2 segundo
      RGB_Cor(0,0,255);// Azul
      delay(500);//Tempo de 1/2 segundo
      RGB_Cor(255,255,255); //Todas as cores
      delay(500); //Tempo de 1/2 segundo
      RGB_Cor(0,0,0); //Apagado
      delay(500); //Tempo de 1/2 segundo
      break;
    case 4: // Desligar LED RGB
      RGB_Cor(0,0,0); //Cores setadas em 0
      break;
    case 5: // Ligar LED
      digitalWrite(LED, HIGH); //Função de ligar LED
      break;
    case 6: // Desligar LED
      digitalWrite(LED, LOW); //Função de desligar LED
      break;
    case 7: // RGB com LDR
      if(LDR_val == 0){
      do{
        RGB_Cor(x,y,z); //x = vermelho, y = verde e z = azul
      }while(LDR_val > 0);
      }else{
        RGB_Cor(0,0,0);
      }
      break;
    case 8: // LED com LDR
      if(LDR_val == 0){
      do{
        digitalWrite(LED, HIGH); //Função de ligar LED
      }while(LDR_val > 0);
      }else{
        digitalWrite(LED, LOW); //Função de desligar LED
      }
      break;
    case 9: // RGB com PIR
      if(PIR_val != 0){
      do{
        RGB_Cor(x,y,z); //x = vermelho, y = verde e z = azul
        delay(30000); //Tempo de 30 segundos
      }while(PIR_val == 0);
      }else{
        RGB_Cor(0,0,0); // RGB apagado
      }
      break;
      case 10: // LED com PIR
      if(PIR_val != 0){
      do{
        digitalWrite(LED, HIGH); //Função de ligar LED
        delay(30000); //Tempo de 30 segundos
      }while(PIR_val == 0);
      }else{
        digitalWrite(LED, LOW); //Função de desligar LED
      }
      break;
      case 11: // Ligar todos os LEDs
      RGB_Cor(255,255,255); //Ligar o RGB em 100%
      digitalWrite(LED, HIGH); //Função de ligar LED
      break;
    default: // Função de erro
      digitalWrite(LED, HIGH); //Função de ligar LED
      delay(500); //Tempo de 1/2 segundo
      digitalWrite(LED, LOW); //Função de desligar LED
      delay(500); //Tempo de 1/2 segundo
      RGB_Cor(255,0,0);// Vermelho
      delay(500);//Tempo de 1/2 segundo
      digitalWrite(LED, HIGH); //Função de ligar LED
      delay(500); //Tempo de 1/2 segundo
      digitalWrite(LED, LOW); //Função de desligar LED
      delay(500); //Tempo de 1/2 segundo
      break;
  }
}
