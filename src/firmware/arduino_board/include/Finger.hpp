#pragma once

#include "HallSensor.hpp"
#include "ServoCustom.hpp"
#include "Types.hpp"

class Finger {
private:
    ServoCustom _servo;
    HallSensor _sensor;

    FingerType _type;
    bool _gotSensor;
    int _defaultAngle;
    int _minAngle;
    int _maxAngle;
    int _minPressure;
    int _maxPressure;

    int _currentAngle;

    static int clampPercentage(int percentage);
    int calculateTargetAngle(int percentage) const;
    int calculateDirection(int targetAngle) const;
    void setAngleWithoutPressureCheck(int targetAngle);
    void graduallySetAngleWithPressureCheck(int targetAngle);

public:
    // Default constructor
    Finger();

    // Constructor
    explicit Finger(FingerType fingerType,
                    bool gotSensor,
                    ServoType servoType,
                    int servoPin,
                    int sensorPin,
                    ServoValues angleValues,
                    PressureValues pressureValues
                    );

    void setup();
    void setMaxAngle(int angle);

    void setPosition(int percentage);
    int getPosition() const;
    int getPressure();
};
