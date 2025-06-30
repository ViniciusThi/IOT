#include <Ethernet.h>
#include <SPI.h>
#include <DHT22.h>

#define DHTPIN 2

DHT22 dht22(DHTPIN);

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}
//IPAddress ip(192, 168, 1, 100);

EthernetServer server(80);

const int ledPin = 8;
const int ldrpin = A0;

void setup() {
    Serial.begin(9600);
    
    
    Serial.println("Configurando rede via DHCP...");
    if (Ethernet.begin(mac) == 0) {
        Serial.println("Falha ao configurar Ethernet usando DHCP");
        //Ethernet.begin(mac, ip);
        while(true);
    }
    
    server.begin();

    Serial.println("Iniciando servidor...");
    Serial.print("IP obtido via DHCP: ");
    Serial.println(Ethernet.localIP());

    pinMode(ledPin, OUTPUT);
}

void loop() {
    EthernetClient client = server.available();

    if (client) {
        Serial.println("Novo cliente conectado");
        boolean currentLineIsBlank = true;
        String request = "";
        char c;

        while (client.connected()) {
            if (client.available()) {
                c = client.read();
                request += c;

                if (c == '\n' && currentLineIsBlank) {
                    Serial.println("Pedido recebido");
                    Serial.println(request);

                    if (request.indexOf("GET /acender") != -1) {
                        digitalWrite(ledPin, HIGH);
                    } else if (request.indexOf("GET /apagar") != -1) {
                        digitalWrite(ledPin, LOW);
                    } else if (request.indexOf("GET /temperatura") != -1) {
                        float temperatura = dht22.getTemperature();
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: text/html");
                        client.println();
                        client.println("{\"temperatura\":");
                        client.print(temperatura);
                        client.println("}");
                    } else if (request.indexOf("GET /umidade") != -1) {
                        float umidade = dht22.getHumidity();
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: application/json");
                        client.println();
                        client.print("{\"umidade\": ");
                        client.print(umidade);
                        client.println("}");
                    } else if (request.indexOf("GET /luminosidade") != -1) {
                        int luminosidade = analogRead(ldrpin);
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-Type: application/json");
                        client.println();
                        client.println("{\"luminosidade\":");
                        client.print(luminosidade);
                        client.println("}");
                    }
                    break;
                }
                if (c == '\n') {
                    currentLineIsBlank = true;
                } else if (c != '\r') {
                    currentLineIsBlank = false;
                }
            }
        }
        delay(1);
        client.stop();
        Serial.println("Cliente desconectado");
    }
}