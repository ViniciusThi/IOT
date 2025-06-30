#include <ESP32Servo.h>

// Definição dos pinos
#define SERVO_PIN 13
#define POT_PIN 34

// Criação do objeto servo
Servo meuServo;

// Variáveis para armazenar valores
int valorPot;      // Valor bruto do potenciômetro (0-4095)
int anguloServo;   // Ângulo calculado para o servo (0-180)

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(115200);
  
  // Configura o pino do potenciômetro como entrada
  pinMode(POT_PIN, INPUT);
  
  // Anexa o servo ao pino e define seus limites
  ESP32PWM::allocateTimer(0);
  meuServo.setPeriodHertz(50);    // Frequência padrão para servos
  meuServo.attach(SERVO_PIN, 500, 2400); // Ajuste estes valores de acordo com seu servo
  
  Serial.println("Sistema iniciado!");
}

void loop() {
  // Lê o valor do potenciômetro
  valorPot = analogRead(POT_PIN);
  
  // Converte o valor do potenciômetro (0-4095) para ângulo do servo (0-180)
  anguloServo = map(valorPot, 0, 4095, 0, 180);
  
  // Move o servo para a posição calculada
  meuServo.write(anguloServo);
  
  // Exibe os valores no monitor serial
  Serial.print("Valor Potenciômetro: ");
  Serial.print(valorPot);
  Serial.print(" | Ângulo Servo: ");
  Serial.println(anguloServo);
  
  // Pequeno delay para estabilidade
  delay(15);
} 