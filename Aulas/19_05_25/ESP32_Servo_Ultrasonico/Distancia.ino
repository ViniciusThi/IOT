#include <ESP32Servo.h>

int cm=0;

long distancia, duracao;

int posicaoA = 90;
int posicaoB = -90;

Servo mtServo;

#define ECHO 2
#define TRIGGER 4

void setup() {
  Serial.begin(9600);  
  pinMode(ECHO, INPUT);
  pinMode(TRIGGER, OUTPUT);
  mtServo.attach(26);
}
void loop() {
  
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

  duracao = pulseIn(ECHO, HIGH);
  distancia = (duracao / 2 ) / 29;

  if(distancia >= 500 || distancia <= 0){
    Serial.println("--------");
  }else{
    Serial.print(distancia);
    Serial.println(" cm ");
    digitalWrite(26, LOW);
  }

  if(distancia <= 10 && distancia >= 1){
    mtServo.write(posicaoA);
    Serial.println("Algo na frente");
  }else{
    mtServo.write(posicaoB);
  }
  delay(1000);
}
