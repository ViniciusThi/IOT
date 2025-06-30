# Projeto de Monitoramento de Temperatura e Umidade com ESP32

Este projeto utiliza um ESP32 para monitorar a temperatura e umidade do ambiente, exibindo mensagens em um display LCD de acordo com a temperatura detectada.

## Componentes Necessários

- 1x ESP32 DevKit
- 1x Sensor DHT22 (temperatura e umidade)
- 1x Display LCD 16x2 com módulo I2C
- Jumpers/fios para conexão

## Conexões

### Sensor DHT22
- VCC → 3.3V do ESP32
- GND → GND do ESP32
- DATA → Pino 23 do ESP32

### Display LCD I2C
- VCC → 3.3V do ESP32
- GND → GND do ESP32
- SDA → Pino 21 do ESP32
- SCL → Pino 22 do ESP32

## Funcionamento

O sistema realiza as seguintes operações:
1. Lê a temperatura e umidade do sensor DHT22
2. Exibe no display LCD:
   - Temperatura atual
   - Umidade atual
   - Mensagem "Quente" quando temperatura > 32°C
   - Mensagem "Frio" quando temperatura < 20°C

## Observações Importantes

- Certifique-se de que todas as conexões estejam firmes
- O sensor DHT22 precisa de um tempo mínimo de 2 segundos entre leituras
- O display LCD I2C deve estar configurado corretamente com o endereço I2C apropriado 