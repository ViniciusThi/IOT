#define TRIGGER_PIN 5
#define ECHO_PIN 18
#define LED_VERDE 26
#define LED_VERMELHO 27

// Constantes
const float VELOCIDADE_SOM = 0.034; // cm/microsegundo
const int DISTANCIA_LIMITE = 30;    // cm

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(115200);
  
  // Configura os pinos
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  
  // Inicializa o trigger como LOW
  digitalWrite(TRIGGER_PIN, LOW);
  
  // Inicialmente, liga o LED verde e desliga o vermelho
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_VERMELHO, LOW);
  
  Serial.println("Sistema iniciado!");
}

float medirDistancia() {
  // Gera o pulso de trigger
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  // Mede o tempo de resposta do ECHO
  long duracao = pulseIn(ECHO_PIN, HIGH);
  
  // Calcula a distância em cm
  float distancia = (duracao * VELOCIDADE_SOM) / 2;
  
  return distancia;
}

void loop() {
  // Mede a distância
  float distancia = medirDistancia();
  
  // Exibe a distância no monitor serial
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  // Verifica se há objeto próximo
  if (distancia < DISTANCIA_LIMITE && distancia > 0) {
    // Objeto próximo detectado
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_VERDE, LOW);
  } else {
    // Nenhum objeto próximo
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_VERDE, HIGH);
  }
  
  // Pequeno delay para estabilidade
  delay(100);
} 