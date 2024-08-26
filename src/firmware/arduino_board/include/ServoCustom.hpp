#pragma once

#include <Servo.h>
#include "Types.hpp"

class ServoCustom {
private:
    Servo _servo;
    ServoType _type;
    int _pin;
    int _defaultAngle;
    int _angle;
    int _minAngle;
    int _maxAngle;
public:
    // Default constructor
    ServoCustom() : _servo(Servo()),
                    _type(ServoType::JX_6225MG),
                    _pin(0),
                    _defaultAngle(0),
                    _angle(0),
                    _minAngle(0),
                    _maxAngle(0)
    {}

    // Constructor
    explicit ServoCustom(ServoType type, int pin, int defaultAngle);

    void setup();
    void setAngle(int angle);
    int getAngle();
};
