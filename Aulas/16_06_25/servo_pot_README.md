# Projeto Controle de Servo Motor com Potenciômetro - ESP32

Este projeto utiliza um ESP32 para controlar a posição de um servo motor através de um potenciômetro.

## Componentes Necessários

- 1x ESP32 DevKit
- 1x Servo Motor (ex: SG90)
- 1x Potenciômetro (10kΩ)
- Jumpers/fios para conexão

## Conexões

### Servo Motor
- Fio Vermelho (VCC) → 5V do ESP32
- Fio Marrom/Preto (GND) → GND do ESP32
- Fio Amarelo/Laranja (Sinal) → Pino 13 do ESP32

### Potenciômetro
- Terminal 1 → 3.3V do ESP32
- Terminal 2 (meio) → Pino 34 do ESP32 (ADC)
- Terminal 3 → GND do ESP32

## Funcionamento

O sistema realiza as seguintes operações:
1. Lê o valor do potenciômetro (0-4095)
2. Converte o valor do potenciômetro para ângulo do servo (0-180 graus)
3. Atualiza a posição do servo motor

## Observações Importantes

- O servo motor deve ser alimentado com 5V para funcionamento adequado
- O potenciômetro está conectado a um pino ADC (Analógico) do ESP32
- O ESP32 usa PWM para controlar o servo motor
- O pino 34 é um pino de entrada analógica (ADC1_6)
- Certifique-se de que todas as conexões estejam firmes e corretas 