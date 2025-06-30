# Projeto Sensor de Proximidade com LEDs - ESP32

Este projeto utiliza um ESP32 para detectar proximidade usando o sensor HC-SR04 e controlar dois LEDs (verde e vermelho) baseado na distância detectada.

## Componentes Necessários

- 1x ESP32 DevKit
- 1x Sensor Ultrassônico HC-SR04
- 1x LED Verde
- 1x LED Vermelho
- 2x Resistor 220Ω (para os LEDs)
- Jumpers/fios para conexão

## Conexões

### Sensor HC-SR04
- VCC → 5V do ESP32
- GND → GND do ESP32
- TRIG → Pino 5 do ESP32
- ECHO → Pino 18 do ESP32

### LED Verde
- Ânodo (perna maior) → Pino 26 do ESP32 através do resistor 220Ω
- Cátodo (perna menor) → GND do ESP32

### LED Vermelho
- Ânodo (perna maior) → Pino 27 do ESP32 através do resistor 220Ω
- Cátodo (perna menor) → GND do ESP32

## Funcionamento

O sistema realiza as seguintes operações:
1. Mede constantemente a distância usando o sensor HC-SR04
2. Se algo se aproximar a menos de 30cm:
   - LED Vermelho acende
   - LED Verde apaga
3. Se não houver nada próximo (distância maior que 30cm):
   - LED Verde permanece aceso
   - LED Vermelho apaga

## Observações Importantes

- O sensor HC-SR04 tem alcance de 2cm a 400cm
- Os LEDs precisam dos resistores para limitar a corrente
- O sensor HC-SR04 precisa de 5V para funcionar corretamente
- Certifique-se de que todas as conexões estejam firmes
- O pino ECHO do sensor HC-SR04 opera em 5V, mas o ESP32 opera em 3.3V. No Wokwi isso não é problema, mas em um projeto real seria necessário um divisor de tensão 