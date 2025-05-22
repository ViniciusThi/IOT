# Sistema Inteligente de Cobertura para Plantações 🌱

Um sistema automatizado que protege suas plantas da chuva e durante a noite, usando Arduino e sensores.

## 📋 Descrição do Projeto

Este projeto cria um sistema inteligente que:
- **Estende automaticamente** uma cobertura quando detecta chuva
- **Protege as plantas** durante a noite (ambiente escuro)
- **Retrai a cobertura** quando há sol e não está chovendo
- **Indica o status** através de LEDs coloridos

## 🔧 Componentes Necessários

### Componentes Principais:
- **1x Arduino Uno R3**
- **1x Servo Motor SG90** (micro servo 9g)
- **1x Sensor de Chuva** (Rain Sensor Module)
- **1x Sensor LDR** (Light Dependent Resistor)
- **1x Resistor 10kΩ**

### Componentes Opcionais (indicadores visuais):
- **1x LED Verde** (5mm)
- **1x LED Vermelho** (5mm) 
- **2x Resistor 220Ω** (para os LEDs)

### Materiais de Conexão:
- **Protoboard** (400 pontos)
- **Jumpers macho-macho** (pelo menos 15 unidades)
- **Jumpers macho-fêmea** (para sensores)
- **Cabo USB A-B** (para programar o Arduino)

## 🔌 Esquema de Ligações

### Servo Motor SG90:
```
Servo SG90    →    Arduino Uno
VCC (Vermelho) →   5V
GND (Marrom)   →   GND
Signal (Laranja) → Pino 9
```

### Sensor de Chuva:
```
Sensor Chuva  →    Arduino Uno
VCC           →    5V
GND           →    GND
DO (Digital)  →    Pino 2
```

### Sensor LDR:
```
LDR + Resistor →   Arduino Uno
LDR pino 1    →    5V
LDR pino 2    →    Pino A0 + Resistor 10kΩ
Resistor 10kΩ →    GND
```

### LEDs Indicadores (Opcional):
```
LED Verde     →    Arduino Uno
Ânodo (+)     →    Pino 13 + Resistor 220Ω
Cátodo (-)    →    GND

LED Vermelho  →    Arduino Uno
Ânodo (+)     →    Pino 12 + Resistor 220Ω
Cátodo (-)    →    GND
```

## 📐 Diagrama de Montagem

```
Arduino Uno
    |
    ├─ Pino 2    ←→  Sensor de Chuva (DO)
    ├─ Pino 9    ←→  Servo Motor (Signal)
    ├─ Pino 12   ←→  LED Vermelho (+ Resistor 220Ω)
    ├─ Pino 13   ←→  LED Verde (+ Resistor 220Ω)
    ├─ Pino A0   ←→  LDR (+ Resistor 10kΩ para GND)
    ├─ 5V        ←→  VCC dos sensores e servo
    └─ GND       ←→  GND comum
```

## 🚀 Como Usar

### 1. Montagem Física:
1. Monte o circuito conforme o diagrama acima
2. Fixe o servo motor na estrutura da cobertura
3. Conecte a cobertura ao eixo do servo motor
4. Posicione os sensores em local adequado

### 2. Programação:
1. Abra o Arduino IDE
2. Carregue o arquivo `sistema_cobertura_inteligente.ino`
3. Selecione a placa "Arduino Uno"
4. Selecione a porta COM correta
5. Clique em "Upload" para enviar o código

### 3. Configuração:
- Ajuste a variável `limiteEscuridao` conforme o ambiente (linha 35)
- Modifique `posicaoAberta` e `posicaoFechada` conforme sua montagem

## ⚙️ Como Funciona

### Lógica do Sistema:
1. **Sensor de Chuva**: Quando detecta umidade, o sistema estende a cobertura
2. **Sensor LDR**: Quando escurece (noite), o sistema protege as plantas
3. **Servo Motor**: Move a cobertura suavemente entre as posições
4. **LEDs**: Indicam o status atual do sistema

### Estados do Sistema:
- 🟢 **LED Verde**: Cobertura retraída (plantas recebendo luz)
- 🔴 **LED Vermelho**: Cobertura estendida (plantas protegidas)

## 🔍 Monitoramento

Abra o **Monitor Serial** (Ctrl+Shift+M) para acompanhar:
- Status dos sensores em tempo real
- Motivo das ações do sistema
- Valores de luminosidade
- Estado atual da cobertura

## 🛠️ Solução de Problemas

### Problemas Comuns:

**Servo não se move:**
- Verifique a alimentação (5V e GND)
- Confirme a conexão no pino 9
- Teste com outro servo motor

**Sensor de chuva sempre ativo:**
- Ajuste o potenciômetro no módulo sensor
- Verifique se não há umidade no sensor
- Limpe os contatos do sensor

**LDR não funciona:**
- Confirme o resistor de 10kΩ
- Verifique a conexão no pino A0
- Ajuste a variável `limiteEscuridao`

**LEDs não acendem:**
- Verifique a polaridade (+ e -)
- Confirme os resistores de 220Ω
- Teste os LEDs separadamente

## 📚 Para Aprender Mais

### Conceitos Utilizados:
- **Programação Arduino**: loops, condições, funções
- **Sensores Analógicos**: leitura do LDR
- **Sensores Digitais**: detecção de chuva
- **Controle de Servo**: movimento suave e posicionamento
- **Debugging**: uso do monitor serial

### Melhorias Possíveis:
- Adicionar sensor de temperatura
- Incluir controle por aplicativo móvel
- Implementar horários programados
- Adicionar sensor de vento
- Criar interface web

## 📜 Licença

Este projeto é livre para uso educacional e pessoal.

---

**Desenvolvido para aprendizado de Arduino e automação residencial** 🏠🤖

*Dica: Teste sempre em pequena escala antes de implementar em uma estufa real!* 