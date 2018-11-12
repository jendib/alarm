#include <Arduino.h>
#include "battery.h"

const byte BATTERY_PIN = A0;
const float BATTERY_DISCHARGED_THRESHOLD = 4.0;

Battery::Battery() {

}

float Battery::getVoltage() {
    int sensorValue = analogRead(BATTERY_PIN);
    return sensorValue * (5.0 / 1023.0);
}

bool Battery::isCharged() {
    return this->getVoltage() > BATTERY_DISCHARGED_THRESHOLD;
}