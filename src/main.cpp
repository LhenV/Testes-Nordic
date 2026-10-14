#include <Arduino.h>
#include <Adafruit_TinyUSB.h>

// Botoes
const int BTN_K1 = D0;
const int BTN_K2 = D1;
const int BTN_K3 = D2;

// Saidas dos reles
const int OUT_K1 = D3;
const int OUT_K2 = D4;
const int OUT_K3 = D5;

// Estado dos reles
bool estadoK1 = false;
bool estadoK2 = false;
bool estadoK3 = false;

// Controle dos botoes
int leituraAnterior[3] = {HIGH, HIGH, HIGH};
int estadoEstavel[3] = {HIGH, HIGH, HIGH};

unsigned long tempoAnterior[3] = {0, 0, 0};
const unsigned long debounce = 40;

const int botoes[3] = {BTN_K1, BTN_K2, BTN_K3};

void atualizarBotao(int i) {
    int leitura = digitalRead(botoes[i]);

    if (leitura != leituraAnterior[i]) {
        tempoAnterior[i] = millis();
        leituraAnterior[i] = leitura;
    }
    // Debouce de software
    if (millis() - tempoAnterior[i] >= debounce) {

        if (leitura != estadoEstavel[i]) {
            estadoEstavel[i] = leitura;

            // Verifica se o botao foi pressionado
            if (estadoEstavel[i] == LOW) {

                if (i == 0) {
                    estadoK1 = !estadoK1;

                    if (estadoK1 == true) {
                        digitalWrite(OUT_K1, HIGH);
                    } else {
                        digitalWrite(OUT_K1, LOW);
                    }
                }

                else if (i == 1) {
                    estadoK2 = !estadoK2;

                    if (estadoK2 == true) {
                        digitalWrite(OUT_K2, HIGH);
                    } else {
                        digitalWrite(OUT_K2, LOW);
                    }
                }

                else if (i == 2) {
                    estadoK3 = !estadoK3;

                    if (estadoK3 == true) {
                        digitalWrite(OUT_K3, HIGH);
                    } else {
                        digitalWrite(OUT_K3, LOW);
                    }
                }
            }
        }
    }
}

void setup() {
    // Configura as saidas
    pinMode(OUT_K1, OUTPUT);
    pinMode(OUT_K2, OUTPUT);
    pinMode(OUT_K3, OUTPUT);

    // Inicia todos os reles desligados
    digitalWrite(OUT_K1, LOW);
    digitalWrite(OUT_K2, LOW);
    digitalWrite(OUT_K3, LOW);

    // Configura os botoes com pull-up interno
    pinMode(BTN_K1, INPUT_PULLUP);
    pinMode(BTN_K2, INPUT_PULLUP);
    pinMode(BTN_K3, INPUT_PULLUP);
}

void loop() {
    atualizarBotao(0);
    atualizarBotao(1);
    atualizarBotao(2);
}