#include <Servo.h>

const int pinoServo = 9;
const int pinoPotenciometro = A1;
const int pinoLDR = A0;
const int pinoLedVerde = 13;
const int pinoLedVermelho = 12;

Servo servoCobertura;

int posicaoAberta = 0;
int posicaoFechada = 90;
int valorLDR = 0;
int valorPotenciometro = 0;
bool coberturaEstendida = false;

int limiteEscuridao = 300;
int limiteChuva = 300;

void setup() {
  Serial.begin(9600);
  servoCobertura.attach(pinoServo);
  pinMode(pinoPotenciometro, INPUT);
  pinMode(pinoLDR, INPUT);
  pinMode(pinoLedVerde, OUTPUT);
  pinMode(pinoLedVermelho, OUTPUT);
  
  servoCobertura.write(posicaoAberta);
  digitalWrite(pinoLedVerde, HIGH);
  digitalWrite(pinoLedVermelho, LOW);
  
  Serial.println("Sistema de Cobertura Inteligente Iniciado!");
  Serial.println("Cobertura em posição inicial (retraída)");
  delay(1000);
}

void loop() {
  valorPotenciometro = analogRead(pinoPotenciometro);
  valorLDR = analogRead(pinoLDR);
  
  Serial.print("Potenciometro (Chuva): ");
  Serial.print(valorPotenciometro < limiteChuva ? "CHUVA DETECTADA" : "SEM CHUVA");
  Serial.print(" | LDR: ");
  Serial.print(valorLDR);
  Serial.print(valorLDR < limiteEscuridao ? " (Escuro)" : " (Claro)");
  Serial.println();
  
  bool deveEstender = false;
  
  if (valorPotenciometro < limiteChuva) {
    deveEstender = true;
    Serial.println("MOTIVO: Chuva detectada!");
  }
  else if (valorLDR < limiteEscuridao) {
    deveEstender = true;
    Serial.println("MOTIVO: Ambiente escuro (proteção noturna)!");
  }
  
  if (deveEstender && !coberturaEstendida) {
    estenderCobertura();
  }
  else if (!deveEstender && coberturaEstendida) {
    retrairCobertura();
  }
  
  delay(2000);
}

void estenderCobertura() {
  Serial.println(">>> ESTENDENDO COBERTURA <<<");
  for (int pos = posicaoAberta; pos <= posicaoFechada; pos++) {
    servoCobertura.write(pos);
    delay(15);
  }
  coberturaEstendida = true;
  digitalWrite(pinoLedVerde, LOW);
  digitalWrite(pinoLedVermelho, HIGH);
  Serial.println("Cobertura ESTENDIDA - Plantas protegidas!");
}

void retrairCobertura() {
  Serial.println(">>> RETRAINDO COBERTURA <<<");
  for (int pos = posicaoFechada; pos >= posicaoAberta; pos--) {
    servoCobertura.write(pos);
    delay(15);
  }
  coberturaEstendida = false;
  digitalWrite(pinoLedVerde, HIGH);
  digitalWrite(pinoLedVermelho, LOW);
  Serial.println("Cobertura RETRAÍDA - Plantas recebendo luz natural!");
} 