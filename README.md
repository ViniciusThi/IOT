# Conceitos Básicos de Eletrônica

## Índice
- [Microcontroladores](#microcontroladores)
- [Corrente Elétrica (AC e DC)](#corrente-elétrica)
- [Resistores](#resistores)

## Microcontroladores

### Arduino
- Plataforma de prototipagem eletrônica
- Modelo mais comum (Arduino UNO) usa o microcontrolador ATmega328P
- Processador de 16MHz
- 2KB de memória RAM
- Sem Wi-Fi ou Bluetooth integrado
- Ideal para projetos iniciantes
- Baixo consumo de energia
- Custo-benefício atrativo

### ESP32
- Microcontrolador avançado
- Processador dual-core de 240MHz
- 520KB de memória RAM
- Wi-Fi e Bluetooth integrados
- Mais GPIOs (pinos de entrada/saída)
- Ideal para projetos IoT
- Conversores ADC de alta resolução
- Recursos avançados (PWM, I2C, SPI)

## Corrente Elétrica

### Corrente Alternada (AC)
- Fluxo de corrente muda direção periodicamente
- No Brasil: 60Hz (60 oscilações por segundo)
- Forma de onda senoidal
- Fácil transformação de voltagem

**Exemplos de uso AC:**
- Tomadas residenciais (127V/220V)
- Linhas de transmissão
- Eletrodomésticos
- Ar condicionado

### Corrente Contínua (DC)
- Fluxo de corrente em direção única
- Voltagem constante
- Ideal para armazenamento de energia

**Exemplos de uso DC:**
- Pilhas e baterias
- Painéis solares
- Carregadores de celular
- LEDs
- Componentes eletrônicos
- Microcontroladores
- Portas USB (5V)

## Resistores

### Como Medir

#### Código de Cores
- Preto: 0
- Marrom: 1
- Vermelho: 2
- Laranja: 3
- Amarelo: 4
- Verde: 5
- Azul: 6
- Violeta: 7
- Cinza: 8
- Branco: 9
- Dourado: ±5% tolerância
- Prata: ±10% tolerância

### Cálculos Importantes

#### Lei de Ohm
```
V = R × I
Onde:
V = Tensão (Volts)
R = Resistência (Ohms)
I = Corrente (Amperes)
```

#### Associação de Resistores
Em Série:
```
R_total = R1 + R2 + R3 + ...
```

Em Paralelo:
```
1/R_total = 1/R1 + 1/R2 + 1/R3 + ...
```

#### Potência
```
P = V × I
P = R × I²
P = V²/R
Onde:
P = Potência (Watts)
```

### Exemplos Práticos de Cálculos

#### Exemplo 1: LED com Resistor
Para ligar um LED vermelho em uma fonte de 5V:
- Tensão típica do LED (Vled) = 2V
- Corrente desejada (I) = 20mA = 0,02A

1. Calculando a resistência necessária:
```
R = (Vfonte - Vled) ÷ I
R = (5V - 2V) ÷ 0,02A
R = 3V ÷ 0,02A
R = 150Ω
```

2. Verificando a potência:
```
P = V × I
P = 3V × 0,02A
P = 0,06W (60mW)
```
Neste caso, um resistor de 150Ω e 1/4W (0,25W) seria adequado.

#### Exemplo 2: Resistores em Série
Calcular a resistência total de três resistores em série:
- R1 = 100Ω
- R2 = 220Ω
- R3 = 330Ω

```
R_total = R1 + R2 + R3
R_total = 100Ω + 220Ω + 330Ω
R_total = 650Ω
```

#### Exemplo 3: Resistores em Paralelo
Calcular a resistência total de dois resistores em paralelo:
- R1 = 100Ω
- R2 = 100Ω

```
R_total = (R1 × R2) ÷ (R1 + R2)
R_total = (100Ω × 100Ω) ÷ (100Ω + 100Ω)
R_total = 10000Ω ÷ 200Ω
R_total = 50Ω
```

#### Exemplo 4: Divisor de Tensão
Para obter 3,3V a partir de uma fonte de 5V:
- Vtotal = 5V
- Vdesejado = 3,3V
- Corrente desejada = 0,01A (10mA)

1. Calculando R2 (resistor inferior):
```
R2 = Vdesejado ÷ I
R2 = 3,3V ÷ 0,01A
R2 = 330Ω
```

2. Calculando R1 (resistor superior):
```
R1 = (Vtotal - Vdesejado) ÷ I
R1 = (5V - 3,3V) ÷ 0,01A
R1 = 170Ω
```

### Dicas Práticas
1. Use sempre resistores com potência superior à calculada
2. Considere a tolerância na escolha
3. Prefira valores ligeiramente maiores em caso de dúvida
4. Utilize multímetro para medições precisas
5. Mantenha estoque variado de valores comuns

---
*Este documento serve como guia básico para estudantes e entusiastas de eletrônica.* 