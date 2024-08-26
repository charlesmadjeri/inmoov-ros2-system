#pragma once

#include <Arduino.h>

class HallSensor {
private:
    int _pin;
public:
    // Default constructor
    HallSensor() : _pin(0) {}

    // Constructor
    explicit HallSensor(int pin);
    void setup();

    int getValue();
};
