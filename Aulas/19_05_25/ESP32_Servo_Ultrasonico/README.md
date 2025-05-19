# Projeto ESP32 com Sensor Ultrassônico e Servo Motor

Este projeto utiliza um ESP32 para controlar um servo motor baseado nas leituras de um sensor ultrassônico HC-SR04.

## Componentes Necessários

- ESP32
- Sensor Ultrassônico HC-SR04
- Servo Motor
- Jumpers
- Fonte de alimentação (se necessário)

## Ligações

### Sensor Ultrassônico HC-SR04
- VCC do sensor → 5V do ESP32
- GND do sensor → GND do ESP32
- TRIG do sensor → GPIO 4 do ESP32
- ECHO do sensor → GPIO 2 do ESP32

### Servo Motor
- Fio Vermelho (VCC) → 5V do ESP32
- Fio Marrom/Preto (GND) → GND do ESP32
- Fio Laranja/Amarelo (Sinal) → GPIO 26 do ESP32

## Funcionamento

O código faz o seguinte:
1. Mede a distância usando o sensor ultrassônico
2. Se detectar um objeto a menos de 10cm, o servo motor gira para a posição 90 graus
3. Se não houver objeto próximo, o servo motor retorna para a posição -90 graus
4. As leituras de distância são exibidas no Monitor Serial

## Observações

- Certifique-se de que o ESP32 está recebendo alimentação adequada
- O servo motor pode precisar de uma fonte de alimentação externa dependendo do modelo
- As leituras de distância são atualizadas a cada 1 segundo 