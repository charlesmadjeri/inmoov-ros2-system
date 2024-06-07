#pragma once

#include <Servo.h>
#include "Types.hpp"

class ServoCustom {
public:
    explicit ServoCustom(ServoType type, int pin, int defaultAngle);

    void setup();
    void setAngle(int angle);
    int getAngle();

private:
    Servo _servo;
    ServoType _type;
    int _pin;
    int _defaultAngle;
    int _angle;
    int _minAngle;
    int _maxAngle;
};
