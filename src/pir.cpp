#include <Arduino.h>
#include "pir.h"

const byte PIR_PIN = 3;

Pir::Pir(void (*callback)(void)) {
    pinMode(PIR_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(PIR_PIN),
                    callback,
                    RISING);
}