# Monitor de Condições Climáticas com Arduino

Este projeto utiliza um Arduino para monitorar temperatura e umidade do ar, exibindo os valores em um display LCD e utilizando LEDs coloridos e um buzzer para indicar previsões climáticas baseadas em cálculos meteorológicos científicos.

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
- SDA -> Pino 6
- NC -> Não conectar
- GND -> GND
- Resistor de 10kΩ entre VCC e SDA

### LEDs
- LED Verde (dia bom) -> Pino 7 (com resistor de 220Ω para GND)
- LED Amarelo (calor intenso) -> Pino 8 (com resistor de 220Ω para GND)
- LED Azul (chuva) -> Pino 9 (com resistor de 220Ω para GND)

### Buzzer
- Terminal positivo -> Pino 10
- Terminal negativo -> GND

## Funcionamento
O código lê a temperatura e umidade a cada ciclo e exibe no display LCD, alternando entre diferentes telas com informações. Além disso:

1. Calcula o ponto de orvalho usando a fórmula de Magnus-Tetens
2. Determina condições climáticas com base em cálculos meteorológicos precisos
3. Ativa o LED verde quando as condições são ideais (20-28°C e umidade entre 40-70%)
4. Ativa o LED amarelo quando a temperatura está acima de 32°C (calor intenso)
5. Ativa o LED azul quando há previsão de chuva (baseada na proximidade do ponto de orvalho)
6. Ativa o buzzer quando há previsão de chuva intensa (umidade acima de 85% e ponto de orvalho muito próximo)
7. Exibe o status atual no LCD (Dia agradável, Calor intenso, Possível chuva, Chuva intensa)

## Base Científica para os Cálculos

### Ponto de Orvalho
O projeto utiliza a fórmula de Magnus-Tetens para calcular com precisão o ponto de orvalho, que é a temperatura na qual o vapor de água presente no ar condensa, formando orvalho. Esta é uma medida fundamental na meteorologia para prever condições climáticas.

### Previsão de Chuva
A previsão de chuva é baseada na diferença entre a temperatura ambiente e o ponto de orvalho:
- Quando essa diferença é menor que 2,5°C, há possibilidade de chuva
- Quando a diferença é menor que 1°C e a umidade está acima de 85%, há risco de chuva intensa

### Conforto Térmico
O projeto define como "dia bom" as condições consideradas ideais para conforto humano segundo estudos de conforto térmico:
- Temperatura entre 20°C e 28°C
- Umidade relativa entre 40% e 70%

## Exibição de Informações
O display LCD alterna entre três telas:
1. Temperatura e umidade atuais
2. Ponto de orvalho calculado
3. Status das condições climáticas

## Bibliotecas Necessárias
- LiquidCrystal
- DHT

## Instalação
1. Conecte os componentes conforme o esquema de ligações
2. Instale as bibliotecas necessárias no Arduino IDE
3. Faça upload do código para o Arduino
4. Ajuste o potenciômetro do display para melhor visualização 