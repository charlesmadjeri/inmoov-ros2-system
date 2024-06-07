#pragma once

#include <Arduino.h>

class HallSensor {
private:
    int _pin;
public:
    explicit HallSensor(int pin);

    void setup();

    float getVoltage();
private:
    int getValue();
};
