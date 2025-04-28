# Monitor de Condições Climáticas com Arduino

Este projeto utiliza um Arduino para monitorar temperatura e umidade do ar, exibindo os valores em um display LCD e utilizando LEDs coloridos e um buzzer para indicar previsões climáticas baseadas em cálculos meteorológicos.

## Componentes Necessários
- Arduino Uno
- Display LCD 16x2
- Sensor DHT22
- Resistor de 10kΩ
- LED Verde (dia bom)
- LED Amarelo (calor intenso)
- LED Azul (chuva)
- Buzzer (alerta de chuva intensa)
- Resistores de 220Ω (um para cada LED)
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

### LEDs
- LED Verde (dia bom) -> Pino 7 (com resistor de 220Ω para GND)
- LED Amarelo (calor intenso) -> Pino 8 (com resistor de 220Ω para GND)
- LED Azul (chuva) -> Pino 9 (com resistor de 220Ω para GND)

### Buzzer
- Terminal positivo -> Pino 10
- Terminal negativo -> GND

## Funcionamento
O código lê a temperatura e umidade a cada 2 segundos e exibe no display LCD. Além disso:

1. Calcula o ponto de orvalho e outras métricas para prever condições climáticas
2. Ativa o LED verde quando as condições são ideais (20-28°C e umidade entre 40-70%)
3. Ativa o LED amarelo quando a temperatura está acima de 32°C (calor intenso)
4. Ativa o LED azul quando há previsão de chuva (baseada na proximidade do ponto de orvalho)
5. Ativa o buzzer quando há previsão de chuva intensa (umidade acima de 85% e ponto de orvalho muito próximo)

## Cálculos Meteorológicos
O projeto utiliza os seguintes cálculos para prever as condições climáticas:

- **Ponto de Orvalho**: Temperatura na qual o ar precisa ser resfriado para ficar saturado de vapor d'água, indicando condensação (chuva)
- **Previsão de Chuva**: Quando a diferença entre a temperatura atual e o ponto de orvalho é menor que 2,5°C
- **Previsão de Chuva Intensa**: Quando a diferença é menor que 1°C e a umidade está acima de 85%
- **Calor Intenso**: Temperatura acima de 32°C
- **Dia Bom**: Temperatura entre 20°C e 28°C com umidade entre 40% e 70%

## Bibliotecas Necessárias
- LiquidCrystal
- DHT sensor library

## Instalação
1. Conecte os componentes conforme o esquema de ligações
2. Instale as bibliotecas necessárias no Arduino IDE
3. Faça upload do código para o Arduino
4. Ajuste o potenciômetro do display para melhor visualização 