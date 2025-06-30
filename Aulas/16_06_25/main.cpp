#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Definição dos pinos
#define DHTPIN 23
#define DHTTYPE DHT22

// Inicialização dos objetos
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Endereço I2C 0x27, display 16x2

void setup() {
  Serial.begin(115200);
  
  // Inicializa o sensor DHT
  dht.begin();
  
  // Inicializa o LCD
  lcd.init();
  lcd.backlight();
  
  // Mensagem inicial
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Iniciando...");
  delay(2000);
}

void loop() {
  // Lê os valores do sensor
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();
  
  // Verifica se a leitura foi bem-sucedida
  if (isnan(temperatura) || isnan(umidade)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Erro no sensor!");
    delay(2000);
    return;
  }
  
  // Limpa o display
  lcd.clear();
  
  // Exibe temperatura e umidade
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura, 1);
  lcd.print("C");
  
  lcd.setCursor(0, 1);
  lcd.print("Umid: ");
  lcd.print(umidade, 1);
  lcd.print("%");
  
  // Aguarda 2 segundos
  delay(2000);
  
  // Exibe mensagem baseada na temperatura
  lcd.clear();
  lcd.setCursor(0, 0);
  if (temperatura > 32) {
    lcd.print("Quente!");
  } else if (temperatura < 20) {
    lcd.print("Frio!");
  } else {
    lcd.print("Temperatura OK");
  }
  
  // Aguarda mais 2 segundos antes de recomeçar
  delay(2000);
} 