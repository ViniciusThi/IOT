// Definição dos pinos para o primeiro semáforo
const int verde1 = 23;    // LED verde do primeiro semáforo
const int amarelo1 = 22;  // LED amarelo do primeiro semáforo
const int vermelho1 = 21; // LED vermelho do primeiro semáforo

// Definição dos pinos para o segundo semáforo
const int verde2 = 19;    // LED verde do segundo semáforo
const int amarelo2 = 18;  // LED amarelo do segundo semáforo
const int vermelho2 = 5;  // LED vermelho do segundo semáforo

// Tempos de cada fase do semáforo (em milissegundos)
const int tempoVerde = 5000;    // 5 segundos
const int tempoAmarelo = 2000;  // 2 segundos
const int tempoVermelho = 5000; // 5 segundos

void setup() {
  // Configuração dos pinos como saída
  pinMode(verde1, OUTPUT);
  pinMode(amarelo1, OUTPUT);
  pinMode(vermelho1, OUTPUT);
  pinMode(verde2, OUTPUT);
  pinMode(amarelo2, OUTPUT);
  pinMode(vermelho2, OUTPUT);
}

void loop() {
  // Fase 1: Semáforo 1 Verde, Semáforo 2 Vermelho
  digitalWrite(verde1, HIGH);
  digitalWrite(amarelo1, LOW);
  digitalWrite(vermelho1, LOW);
  digitalWrite(verde2, LOW);
  digitalWrite(amarelo2, LOW);
  digitalWrite(vermelho2, HIGH);
  delay(tempoVerde);

  // Fase 2: Semáforo 1 Amarelo, Semáforo 2 Vermelho
  digitalWrite(verde1, LOW);
  digitalWrite(amarelo1, HIGH);
  digitalWrite(vermelho1, LOW);
  delay(tempoAmarelo);

  // Fase 3: Semáforo 1 Vermelho, Semáforo 2 Verde
  digitalWrite(verde1, LOW);
  digitalWrite(amarelo1, LOW);
  digitalWrite(vermelho1, HIGH);
  digitalWrite(verde2, HIGH);
  digitalWrite(amarelo2, LOW);
  digitalWrite(vermelho2, LOW);
  delay(tempoVerde);

  // Fase 4: Semáforo 1 Vermelho, Semáforo 2 Amarelo
  digitalWrite(verde2, LOW);
  digitalWrite(amarelo2, HIGH);
  digitalWrite(vermelho2, LOW);
  delay(tempoAmarelo);
} 