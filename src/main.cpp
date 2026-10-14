#include <Arduino.h>
#include <Adafruit_TinyUSB.h>

void setup() {
    // Inicia a comunicacao serial USB
    Serial.begin(115200);

    // Configura o LED integrado como saida
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    // Envia uma mensagem para o computador
    Serial.println("Hello World!");

    // Pisca o LED
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);

    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}