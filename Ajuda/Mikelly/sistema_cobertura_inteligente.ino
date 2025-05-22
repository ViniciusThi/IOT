/*
  Sistema Inteligente de Cobertura para Plantações
  
  Este sistema controla automaticamente uma cobertura sobre plantações
  usando sensores de chuva e luminosidade (LDR)
  
  Componentes utilizados:
  - Arduino Uno
  - Servo Motor SG90
  - Sensor de Chuva
  - Sensor LDR (Light Dependent Resistor)
  - Resistor 10kΩ
  - LEDs indicadores (opcional)
*/

#include <Servo.h>

// Definindo os pinos
const int pinoServo = 9;        // Pino do servo motor
const int pinoSensorChuva = 2;  // Pino do sensor de chuva (digital)
const int pinoLDR = A0;         // Pino do sensor LDR (analógico)
const int pinoLedVerde = 13;    // LED verde - cobertura retraída
const int pinoLedVermelho = 12; // LED vermelho - cobertura estendida

// Criando objeto servo
Servo servoCobertura;

// Variáveis do sistema
int posicaoAberta = 0;     // Posição da cobertura aberta (retraída)
int posicaoFechada = 90;   // Posição da cobertura fechada (estendida)
int valorLDR = 0;          // Valor lido do sensor LDR
int statusChuva = 0;       // Status do sensor de chuva
bool coberturaEstendida = false; // Estado atual da cobertura

// Configurações de sensibilidade
int limiteEscuridao = 300; // Valor abaixo do qual consideramos escuro

void setup() {
  // Inicializando comunicação serial para debug
  Serial.begin(9600);
  
  // Configurando os pinos
  servoCobertura.attach(pinoServo);
  pinMode(pinoSensorChuva, INPUT);
  pinMode(pinoLDR, INPUT);
  pinMode(pinoLedVerde, OUTPUT);
  pinMode(pinoLedVermelho, OUTPUT);
  
  // Posição inicial - cobertura retraída
  servoCobertura.write(posicaoAberta);
  digitalWrite(pinoLedVerde, HIGH);
  digitalWrite(pinoLedVermelho, LOW);
  
  Serial.println("Sistema de Cobertura Inteligente Iniciado!");
  Serial.println("Cobertura em posição inicial (retraída)");
  
  delay(1000); // Aguarda 1 segundo para estabilizar
}

void loop() {
  // Lendo os sensores
  statusChuva = digitalRead(pinoSensorChuva);
  valorLDR = analogRead(pinoLDR);
  
  // Mostrando valores no monitor serial (para debug)
  Serial.print("Sensor de Chuva: ");
  Serial.print(statusChuva == LOW ? "CHUVA DETECTADA" : "SEM CHUVA");
  Serial.print(" | LDR: ");
  Serial.print(valorLDR);
  Serial.print(statusChuva == LOW ? " (Escuro)" : " (Claro)");
  Serial.println();
  
  // Lógica de decisão do sistema
  bool deveEstender = false;
  
  // Condição 1: Se está chovendo, estende a cobertura
  if (statusChuva == LOW) {
    deveEstender = true;
    Serial.println("MOTIVO: Chuva detectada!");
  }
  
  // Condição 2: Se está muito escuro (noite), estende a cobertura
  else if (valorLDR < limiteEscuridao) {
    deveEstender = true;
    Serial.println("MOTIVO: Ambiente escuro (proteção noturna)!");
  }
  
  // Estendendo ou retraindo a cobertura conforme necessário
  if (deveEstender && !coberturaEstendida) {
    estenderCobertura();
  }
  else if (!deveEstender && coberturaEstendida) {
    retrairCobertura();
  }
  
  delay(2000); // Aguarda 2 segundos antes da próxima leitura
}

void estenderCobertura() {
  Serial.println(">>> ESTENDENDO COBERTURA <<<");
  
  // Move o servo gradualmente para a posição fechada
  for (int pos = posicaoAberta; pos <= posicaoFechada; pos++) {
    servoCobertura.write(pos);
    delay(15); // Movimento suave
  }
  
  // Atualiza o estado e os LEDs
  coberturaEstendida = true;
  digitalWrite(pinoLedVerde, LOW);
  digitalWrite(pinoLedVermelho, HIGH);
  
  Serial.println("Cobertura ESTENDIDA - Plantas protegidas!");
}

void retrairCobertura() {
  Serial.println(">>> RETRAINDO COBERTURA <<<");
  
  // Move o servo gradualmente para a posição aberta
  for (int pos = posicaoFechada; pos >= posicaoAberta; pos--) {
    servoCobertura.write(pos);
    delay(15); // Movimento suave
  }
  
  // Atualiza o estado e os LEDs
  coberturaEstendida = false;
  digitalWrite(pinoLedVerde, HIGH);
  digitalWrite(pinoLedVermelho, LOW);
  
  Serial.println("Cobertura RETRAÍDA - Plantas recebendo luz natural!");
} 