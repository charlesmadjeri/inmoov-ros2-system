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
{
    _currentAngle = _defaultAngle;
}

void
Wrist::setup()
{
    _servo.setup();
}

/**
 * @brief Set the position of the servo using a percentage
 * @param percentage
 */
void
Wrist::setPosition(int percentage)
{
    percentage = clampPercentage(percentage);
    int targetAngle = calculateTargetAngle(percentage);

    _servo.setAngle(targetAngle);
    _currentAngle = targetAngle;
}

/**
 * @brief Get the percentage of the current position
 * @return int
 */
int
Wrist::getPosition() const
{
    return (_currentAngle - _minAngle) * 100 / (_maxAngle - _minAngle);
}

/**
 * @brief Clamp the percentage value between 0 and 100
 * @param percentage
 * @return int
 */
int
Wrist::clampPercentage(int percentage)
{
    return max(0, min(percentage, 100));
}

/**
 * @brief Calculate the target angle based on the percentage
 * @param percentage
 * @return int
 */
int
Wrist::calculateTargetAngle(int percentage) const
{
    return _minAngle + (_maxAngle - _minAngle) * percentage / 100;
}
