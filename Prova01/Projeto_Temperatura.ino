#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 2
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
  float a = 17.27;
  float b = 237.7;
  float alpha = ((a * t) / (b + t)) + log(h/100.0);
  float pontoOrvalho = (b * alpha) / (a - alpha);
  return pontoOrvalho;
}

bool preveChuva(float t, float h) {
  float pontoOrvalho = calculaPontoOrvalho(t, h);
  float diferencaTemp = t - pontoOrvalho;
  return diferencaTemp < 2.5;
}

bool preveChuvaIntensa(float t, float h) {
  float pontoOrvalho = calculaPontoOrvalho(t, h);
  float diferencaTemp = t - pontoOrvalho;
  return diferencaTemp < 1.0 && h > 85;
}

bool preveCalorIntenso(float t) {
  return t > 32;
}

bool preveDiaBom(float t, float h) {
  return t >= 20 && t <= 28 && h >= 40 && h <= 70;
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("C");
  
  lcd.setCursor(0, 1);
  lcd.print("Umid: ");
  lcd.print(h);
  lcd.print("%");
  
  bool chuva = preveChuva(t, h);
  bool chuvaIntensa = preveChuvaIntensa(t, h);
  bool calorIntenso = preveCalorIntenso(t);
  bool diaBom = preveDiaBom(t, h);
  
  digitalWrite(LED_VERDE, diaBom ? HIGH : LOW);
  digitalWrite(LED_AMARELO, calorIntenso ? HIGH : LOW);
  digitalWrite(LED_AZUL, chuva ? HIGH : LOW);
  
  if (chuvaIntensa) {
    tone(BUZZER, 1000, 200);
    delay(400);
    tone(BUZZER, 1000, 200);
  } else {
    noTone(BUZZER);
  }
  
  delay(2000);
} 