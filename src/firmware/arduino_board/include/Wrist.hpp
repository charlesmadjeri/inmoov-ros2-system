#pragma once

#include <Arduino.h>
#include "ServoCustom.hpp"
#include "Types.hpp"
#include "Config.hpp"

class Wrist {
private:
    SideType _type;
    ServoCustom _servo;
    const int _defaultAngle;
    const int _minAngle;
    const int _maxAngle;

    int _currentAngle;

public:
    explicit Wrist(SideType type);
    void setup();

    void setPosition(int angle);
    int getPosition() const;

    int calculateTargetAngle(int percentage) const;
    static int clampPercentage(int percentage);
};
