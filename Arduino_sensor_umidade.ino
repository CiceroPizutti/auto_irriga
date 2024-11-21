#include <Arduino.h>

const int sensorPin = A0;  // Pino onde o sensor de umidade está conectado
const int relayPin = 7;     // Pino onde o relé está conectado

void setup() {
    Serial.begin(9600);
    pinMode(relayPin, OUTPUT);
    digitalWrite(relayPin, LOW); // O relé começa desligado
}

void loop() {
    // Leitura do sensor
    int sensorValue = analogRead(sensorPin);
    int humidityPercentage = map(sensorValue, 0, 1023, 100, 0);
    
    // Envia apenas o valor da umidade pela porta serial
    Serial.println(humidityPercentage); // Enviar o valor sem formatação adicional

    // Verifica se há dados disponíveis na porta serial
    if (Serial.available() > 0) {
        // Recebe o comando para controlar o relé
        char command = Serial.read();
        if (command == '1') {
            digitalWrite(relayPin, HIGH); // Liga o relé
            Serial.println("Relé ligado."); // Mensagem de confirmação
        } else if (command == '0') {
            digitalWrite(relayPin, LOW); // Desliga o relé
            Serial.println("Relé desligado."); // Mensagem de confirmação
        } else {
            Serial.println("Comando inválido. Use '1' para ligar e '0' para desligar."); // Mensagem de erro
        }
    }

    delay(1000); // Atraso para estabilização
}
