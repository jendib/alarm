#include <Arduino.h>
#include "alarm.h"
#include "pir.h"
#include "battery.h"

// Objects
Alarm* alarm;
Pir* pir;
Battery* battery;

void detectPirMotion() {
    alarm->trigger();
    // TODO Send SMS "Alarm triggered" debounced once every minute
}

void setup() {
    alarm = new Alarm();
    pir = new Pir(detectPirMotion);
    battery = new Battery();

    Serial.begin(9600);
}
 
void loop(){
    alarm->loop();

    if (!battery->isCharged()) {
        // TODO Send SMS "Battery needs charging" debounced once every 24 hours
    }

    // TODO When SMS "Disable" received, disable the alarm
    // TODO When SMS "Pause" received, suspend the alarm for 15 minutes
    // TODO When SMS "Enable" received, enable the alarm
    // TODO When SMS "Status" received, send the battery voltage, the signal quality, the alarm status and the time when the alarm was last triggered

    delay(50);
}
