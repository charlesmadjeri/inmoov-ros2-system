#include "../include/Finger.hpp"

/**
 * @brief Constructor
 * @param servoType
 * @param servoPin
 * @param sensorPin
 */
Finger::Finger(FingerType fingerType,
               ServoType servoType,
               int servoPin,
               int sensorPin,
               PressureValues values
               ):
    _servo(servoType, servoPin, FINGER_DEFAULT_ANGLE),
    _sensor(sensorPin),
    _type(fingerType),
    _defaultAngle(FINGER_DEFAULT_ANGLE),
    _minAngle(FINGER_MIN_ANGLE),
    _maxAngle(FINGER_MAX_ANGLE),
    _minPressure(values.minPressure),
    _maxPressure(values.maxPressure)
{}

/**
 * @brief Setup function
 */
void
Finger::setup()
{
    _servo.setup();
    _sensor.setup();
}

/**
 * @brief Set the maximum angle of the servo
 * @param angle
 */
void
Finger::setMaxAngle(int angle)
{
    _maxAngle = angle;
}

/**
 * @brief Set the position of the servo using a percentage
 * @param percentage
 */
void
Finger::setPosition(int percentage)
{
    percentage = clampPercentage(percentage);
    int targetAngle = calculateTargetAngle(percentage);
    int currentAngle = _servo.getAngle();
    int direction = calculateDirection(targetAngle, currentAngle);

    if (direction < 0) {
        setAngleWithoutPressureCheck(targetAngle);
    } else {
        graduallySetAngleWithPressureCheck(targetAngle, currentAngle, direction);
    }
}

/**
 * @brief Get the percentage of the current position
 * @return int
 */
int
Finger::getPosition()
{
    int currentAngle = _servo.getAngle();

    // Ensure the current angle is within the defined range
    if (currentAngle < _minAngle) {
        currentAngle = _minAngle;
    } else if (currentAngle > _maxAngle) {
        currentAngle = _maxAngle;
    }

    // Calculate the percentage
    return (currentAngle - _minAngle) * 100 / (_maxAngle - _minAngle);
}

/**
 * @brief Get the percentage of the pressure
 * @return int
 */
int
Finger::getPressure()
{
    int sensorValue = _sensor.getValue();

    // Ensure the sensor value is within the defined range
    if (sensorValue < _minPressure) {
        sensorValue = _minPressure;
    } else if (sensorValue > _maxPressure) {
        sensorValue = _maxPressure;
    }

    // Calculate the percentage
    return (sensorValue - _minPressure) * 100 / (_maxPressure - _minPressure);
}

/**
 * @brief Clamp the percentage value between 0 and 100
 * @param percentage
 * @return int
 */
int
Finger::clampPercentage(int percentage)
{
    return max(0, min(percentage, 100));
}

/**
 * @brief Calculate the target angle based on the percentage
 * @param percentage
 * @return int
 */
int
Finger::calculateTargetAngle(int percentage) const
{
    return _minAngle + (_maxAngle - _minAngle) * percentage / 100;
}

/**
 * @brief Calculate the direction based on the target and current angle
 * @param targetAngle
 * @param currentAngle
 * @return int
 */
int
Finger::calculateDirection(int targetAngle, int currentAngle)
{
    return (targetAngle > currentAngle) ? 1 : -1;
}

/**
 * @brief Set the angle of the servo without checking the pressure
 * @param targetAngle
 */
void
Finger::setAngleWithoutPressureCheck(int targetAngle)
{
    _servo.setAngle(targetAngle);
}

/**
 * @brief Gradually set the angle of the servo while checking the pressure
 * @param targetAngle
 * @param currentAngle
 * @param direction
 */
void
Finger::graduallySetAngleWithPressureCheck(int targetAngle, int currentAngle, int direction)
{
    for (int angle = currentAngle; angle != targetAngle; angle += direction) {
        _servo.setAngle(angle);
        if (_sensor.getValue() >= _maxPressure) {
            break;
        }
    }
}
