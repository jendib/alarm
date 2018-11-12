#ifndef ALARM_H
#define ALARM_H

class Alarm {
public:
    Alarm();
    void trigger();
    void stop();
    void loop();
    
private:
    int relayState;
    long lastDebounceTime;
};

#endif