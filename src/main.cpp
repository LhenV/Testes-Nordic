#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include <nRF52_PWM.h>

// Pino de saída
const int MOSFET_CTRL = D3;

// PWM por hardware
nRF52_PWM* pwm;

void setup() {
    // Frequência: 31,7 kHz
    // Duty cycle: 5%
    pwm = new nRF52_PWM(MOSFET_CTRL, 31700.0f, 5.0f);

    if (pwm != nullptr) {
        pwm->setPWM();
    }
}

void loop() {
    // O periférico gera o PWM sem precisar atualizar o sinal aqui.
}