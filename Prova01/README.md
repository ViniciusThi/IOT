# Monitor de Temperatura e Umidade com Arduino

Este projeto utiliza um Arduino para monitorar temperatura e umidade do ar, exibindo os valores em um display LCD e acionando um alerta quando os valores ultrapassam os limites estabelecidos.

## Componentes Necessários
- Arduino Uno
- Display LCD 16x2
- Sensor DHT22
- Resistor de 10kΩ
- LED (para alerta)
- Resistor de 220Ω (para o LED)
- Jumpers

## Ligações

### Display LCD
- VSS -> GND
- VDD -> 5V
- V0 -> Potenciômetro (ajuste de contraste)
- RS -> Pino 12
- RW -> GND
- E -> Pino 11
- D4 -> Pino 5
- D5 -> Pino 4
- D6 -> Pino 3
- D7 -> Pino 2
- A -> 5V
- K -> GND

### Sensor DHT22
- VCC -> 5V
- DATA -> Pino 2
- GND -> GND
- Resistor de 10kΩ entre VCC e DATA

### LED de Alerta
- Anodo -> Pino 13
- Catodo -> GND (com resistor de 220Ω)

## Funcionamento
O código lê a temperatura e umidade a cada 2 segundos e exibe no display LCD. Quando a temperatura ultrapassa 30°C ou a umidade ultrapassa 70%, o LED pisca como alerta.

## Bibliotecas Necessárias
- LiquidCrystal
- DHT sensor library

## Instalação
1. Conecte os componentes conforme o esquema de ligações
2. Instale as bibliotecas necessárias no Arduino IDE
3. Faça upload do código para o Arduino
4. Ajuste o potenciômetro do display para melhor visualização 