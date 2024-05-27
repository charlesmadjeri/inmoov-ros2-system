#pragma once

#include <Arduino.h>

class HallSensor {
private:
    int _pin;
public:
    explicit HallSensor(int pin);

    float getVoltage();
private:
    int getValue();
};
