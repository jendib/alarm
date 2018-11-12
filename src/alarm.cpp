#include <Arduino.h>
#include "alarm.h"

const byte ALARM_PIN = 4;
const long ALARM_DURATION = 2000;

Alarm::Alarm() {
    relayState = LOW;
    lastDebounceTime = 0;

    pinMode(ALARM_PIN, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);

    // TODO Power the relay from a digital pin
    pinMode(7, OUTPUT);
    digitalWrite(7, HIGH);
    
    this->stop();
}

void Alarm::trigger() {
    if(relayState == LOW) {
        digitalWrite(ALARM_PIN, LOW);
        digitalWrite(LED_BUILTIN, HIGH);
    }
    relayState = HIGH;
    lastDebounceTime = millis();
}

void Alarm::stop() {
    relayState = LOW;
    digitalWrite(ALARM_PIN, HIGH);
    digitalWrite(LED_BUILTIN, LOW);
}

void Alarm::loop() {
    if((millis() - lastDebounceTime) > ALARM_DURATION && relayState == HIGH) {
        this->stop();
    }
}