# Projeto IoT - Monitoramento com ESP

Este projeto implementa um servidor web em um ESP que permite monitorar temperatura, umidade e luminosidade, além de controlar um LED remotamente.

## 🛠 Componentes Necessários

- ESP8266 ou ESP32
- Sensor DHT22 (temperatura e umidade)
- LED
- Resistor 220Ω (para o LED)
- Sensor LDR (fotoresistor)
- Resistor 10kΩ (para o LDR)
- Jumpers
- Protoboard

## 📋 Conexões

### Sensor DHT22
- Pino de dados (DATA) → Pino Digital 2 do ESP
- VCC → 3.3V ou 5V do ESP
- GND → GND do ESP

### LED
- Ânodo (perna maior) → Resistor 220Ω → Pino Digital 8 do ESP
- Cátodo (perna menor) → GND do ESP

### Sensor LDR
- Uma perna do LDR → 5V do ESP
- Outra perna do LDR → Resistor 10kΩ → GND do ESP
- Conexão entre LDR e resistor → Pino Analógico A0 do ESP

## 💻 Endpoints da API

O servidor web disponibiliza os seguintes endpoints:

- `/acender` - Liga o LED
- `/apagar` - Desliga o LED
- `/temperatura` - Retorna a temperatura atual em formato JSON
- `/umidade` - Retorna a umidade atual em formato JSON
- `/luminosidade` - Retorna o nível de luminosidade atual em formato JSON

## 🔧 Configuração

1. Instale as bibliotecas necessárias no Arduino IDE:
   - Ethernet
   - DHT sensor library

2. Configure o endereço MAC e IP no código conforme sua rede:
```cpp
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192.168.1.100);
```

3. Faça o upload do código para o ESP

## 📡 Uso

1. Após fazer o upload do código, abra o Monitor Serial para ver o IP do servidor
2. Use um navegador ou ferramentas como Postman para acessar os endpoints
3. O servidor responderá com dados em formato JSON

## 🔍 Exemplo de Resposta

```json
// GET /temperatura
{
    "temperatura": 25.6
}

// GET /umidade
{
    "umidade": 60.5
}

// GET /luminosidade
{
    "luminosidade": 512
}
```

## ⚡ Diagrama de Conexão

```
ESP           DHT22
D2    ----→   DATA
3.3V  ----→   VCC
GND   ----→   GND

ESP           LED
D8    ----→   220Ω ----→ LED+ 
GND   ----→   LED-

ESP           LDR
5V    ----→   LDR ----→ 10kΩ ----→ GND
A0    ----→   LDR/10kΩ (meio)
``` 