#pragma once

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

public:
    explicit Wrist(SideType type);

    void setAngle(int angle);
    int getAngle();
};
