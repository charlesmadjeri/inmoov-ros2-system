#pragma once

#include "HallSensor.hpp"
#include "ServoCustom.hpp"
#include "Types.hpp"

class Finger {
private:
    ServoCustom _servo;
    HallSensor _sensor;
    FingerType _type;
    int _defaultAngle;
    int _minAngle;
    int _maxAngle;
    int _minPressure;
    int _maxPressure;

    static int clampPercentage(int percentage);
    int calculateTargetAngle(int percentage) const;
    static int calculateDirection(int targetAngle, int currentAngle);
    void setAngleWithoutPressureCheck(int targetAngle);
    void graduallySetAngleWithPressureCheck(int targetAngle, int currentAngle, int direction);

public:
    // Default constructor
    Finger() : _servo(ServoCustom()),
               _sensor(HallSensor()),
               _type(FingerType::THUMB),
               _defaultAngle(0),
               _minAngle(0),
               _maxAngle(0),
               _minPressure(0),
               _maxPressure(0)
    {}

    // Constructor
    explicit Finger(FingerType fingerType, ServoType servoType, int servoPin, int sensorPin, PressureValues values);

    void setup();
    void setMaxAngle(int angle);

    void setPosition(int angle);
    int getPosition();
    int getPressure();
};
