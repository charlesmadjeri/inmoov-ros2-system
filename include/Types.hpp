#pragma once

#include "Config.hpp"

// ********** SERVO **********
enum class ServoType {
    JX_6225MG,
    HK15298B
};

// ********** HAND **********
enum class SideType {
    LEFT,
    RIGHT
};

// ********** FINGER **********
enum class FingerType {
    THUMB,
    INDEX,
    MIDDLE,
    RING,
    PINKY
};

struct PressureValues {
    int minPressure;
    int maxPressure;
};

struct ServoValues {
    int minAngle;
    int maxAngle;
};
