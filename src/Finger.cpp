#include "include/Finger.hpp"
#include "include/Config.hpp"

Finger::Finger(ServoType servoType, int servoPin, int sensorPin):
        _servo(servoType, servoPin, FINGER_DEFAULT_ANGLE),
        _sensor(sensorPin),
        _defaultAngle(FINGER_DEFAULT_ANGLE),
        _minAngle(FINGER_MIN_ANGLE),
        _maxAngle(FINGER_MAX_ANGLE)
{}

void
Finger::setup() {
    _servo.setup();
    _sensor.setup();
}

void
Finger::setMaxAngle(int angle) {
    _maxAngle = angle;
}

void
Finger::setAngle(int angle) {
    if (angle < _minAngle) {
        angle = _minAngle;
    } else if (angle > _maxAngle) {
        angle = _maxAngle;
    }
    _servo.setAngle(angle);
}

int
Finger::getAngle() {
    return _servo.getAngle();
}
