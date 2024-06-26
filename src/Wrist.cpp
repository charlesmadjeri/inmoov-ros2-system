#include "../include/Wrist.hpp"

Wrist::Wrist(SideType type):
    _type(type),
    _servo(
        type == SideType::LEFT ? LEFT_WRIST_SERVO_TYPE : RIGHT_WRIST_SERVO_TYPE,
        type == SideType::LEFT ? LEFT_WRIST_SERVO_PIN : RIGHT_WRIST_SERVO_PIN,
        type == SideType::LEFT ? LEFT_WRIST_DEFAULT_ANGLE : RIGHT_WRIST_DEFAULT_ANGLE
    ),
    _defaultAngle(type == SideType::LEFT ? LEFT_WRIST_DEFAULT_ANGLE : RIGHT_WRIST_DEFAULT_ANGLE),
    _minAngle(type == SideType::LEFT ? LEFT_WRIST_MIN_ANGLE : RIGHT_WRIST_MIN_ANGLE),
    _maxAngle(type == SideType::LEFT ? LEFT_WRIST_MAX_ANGLE : RIGHT_WRIST_MAX_ANGLE)
{}

void
Wrist::setup()
{
    _servo.setup();
}

void
Wrist::setAngle(int angle)
{
    if (angle < _minAngle) {
        angle = _minAngle;
    } else if (angle > _maxAngle) {
        angle = _maxAngle;
    }
    _servo.setAngle(angle);
}

int
Wrist::getAngle()
{
    return _servo.getAngle();
}
