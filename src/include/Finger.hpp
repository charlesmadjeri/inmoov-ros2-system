#pragma once

#include "HallSensor.hpp"
#include "ServoCustom.hpp"
#include "Types.hpp"

class Finger {
private:
    ServoCustom _servo;
    HallSensor _sensor;
    const int _defaultAngle;
    const int _minAngle;
    int _maxAngle;

public:
    explicit Finger(ServoType servoType, int servoPin, int sensorPin);

    void setup();
    void setMaxAngle(int angle);

    void setAngle(int angle);
    int getAngle();
};
