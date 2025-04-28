#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 6  // Pino para o sensor DHT22
#define DHTTYPE DHT22
#define LED_VERDE 7
#define LED_AMARELO 8 
#define LED_AZUL 9
#define BUZZER 10

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

float calculaPontoOrvalho(float t, float h) {
  // Fórmula de Magnus-Tetens para um cálculo mais preciso do ponto de orvalho
  float a = 17.27;
  float b = 237.7;
  float alpha = ((a * t) / (b + t)) + log(h/100.0);
  float pontoOrvalho = (b * alpha) / (a - alpha);
  return pontoOrvalho;
}

bool preveChuva(float t, float h) {
  float pontoOrvalho = calculaPontoOrvalho(t, h);
  float diferencaTemp = t - pontoOrvalho;
  // Quanto menor a diferença entre temp. ambiente e ponto de orvalho, maior a chance de chuva
  return diferencaTemp < 2.5;
}

bool preveChuvaIntensa(float t, float h) {
  float pontoOrvalho = calculaPontoOrvalho(t, h);
  float diferencaTemp = t - pontoOrvalho;
  // Quando o ponto de orvalho está muito próximo da temperatura e a umidade é alta
  return diferencaTemp < 1.0 && h > 85;
}

bool preveCalorIntenso(float t) {
  // Acima de 32°C é considerado calor intenso pela pesquisa
  return t > 32;
}

bool preveDiaBom(float t, float h) {
  // Dia considerado confortável para humanos e plantas:
  // Temp entre 20-28°C (conforto térmico) e umidade entre 40-70% (ideal para conforto)
  return t >= 20 && t <= 28 && h >= 40 && h <= 70;
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  // Verificar se as leituras são válidas
  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Erro no sensor!");
    delay(2000);
    return;
  }
  
  // Calcular o ponto de orvalho
  float pontoOrvalho = calculaPontoOrvalho(t, h);
  
  // Mostrar a temperatura e umidade no LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("C");
  
  lcd.setCursor(0, 1);
  lcd.print("Umid: ");
  lcd.print(h);
  lcd.print("%");
  
  delay(2000);
  
  // Mostrar o ponto de orvalho
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pt Orvalho:");
  lcd.setCursor(0, 1);
  lcd.print(pontoOrvalho);
  lcd.print("C");
  
  delay(2000);
  
  // Verificar as condições climáticas
  bool chuva = preveChuva(t, h);
  bool chuvaIntensa = preveChuvaIntensa(t, h);
  bool calorIntenso = preveCalorIntenso(t);
  bool diaBom = preveDiaBom(t, h);
  
  // Atualizar os LEDs de acordo com as condições
  digitalWrite(LED_VERDE, diaBom ? HIGH : LOW);
  digitalWrite(LED_AMARELO, calorIntenso ? HIGH : LOW);
  digitalWrite(LED_AZUL, chuva ? HIGH : LOW);
  
  // Exibir o status no LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Status:");
  lcd.setCursor(0, 1);
  
  if (chuvaIntensa) {
    lcd.print("Chuva intensa!");
    // Ativar o alarme para chuva intensa
    tone(BUZZER, 1000, 200);
    delay(400);
    tone(BUZZER, 1000, 200);
  } else if (chuva) {
    lcd.print("Possivel chuva");
  } else if (calorIntenso) {
    lcd.print("Calor intenso!");
  } else if (diaBom) {
    lcd.print("Dia agradavel!");
  } else {
    lcd.print("Normal");
  }
  
  delay(2000);
  
  // Desligar o buzzer se estiver ativo
  noTone(BUZZER);
} 