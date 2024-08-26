#include "../include/Finger.hpp"

/**
 * @brief Default constructor
 */
Finger::Finger() : _servo(ServoCustom()),
           _sensor(HallSensor()),
           _type(FingerType::THUMB),
           _gotSensor(false),
           _defaultAngle(0),
           _minAngle(0),
           _maxAngle(0),
           _minPressure(0),
           _maxPressure(0)
{
    _currentAngle = _defaultAngle;
}

/**
 * @brief Constructor
 * @param servoType
 * @param servoPin
 * @param sensorPin
 */
Finger::Finger(FingerType fingerType,
               bool gotSensor,
               ServoType servoType,
               int servoPin,
               int sensorPin,
               ServoValues angleValues,
               PressureValues pressureValues
               ):
    _servo(servoType, servoPin, angleValues.minAngle),
    _sensor(sensorPin),
    _type(fingerType),
    _gotSensor(gotSensor),
    _defaultAngle(angleValues.minAngle),
    _minAngle(angleValues.minAngle),
    _maxAngle(angleValues.maxAngle),
    _minPressure(pressureValues.minPressure),
    _maxPressure(pressureValues.maxPressure)
{
    _currentAngle = _defaultAngle;
}

/**
 * @brief Setup function
 */
void
Finger::setup()
{
    _servo.setup();
    if (_gotSensor)
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
    int direction = calculateDirection(targetAngle);

    if (direction < 0 || !_gotSensor) {
        setAngleWithoutPressureCheck(targetAngle);
    } else {
        graduallySetAngleWithPressureCheck(targetAngle);
    }
}

/**
 * @brief Get the percentage of the current position
 * @return int
 */
int
Finger::getPosition() const
{
    return (_currentAngle - _minAngle) * 100 / (_maxAngle - _minAngle);
}

/**
 * @brief Get the percentage of the pressure
 * @return int
 */
int
Finger::getPressure()
{
    int sensorValue = _sensor.getValue();

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
 * @return int
 */
int
Finger::calculateDirection(int targetAngle) const
{
    return (targetAngle > _currentAngle) ? 1 : -1;
}

/**
 * @brief Set the angle of the servo without checking the pressure
 * @param targetAngle
 */
void
Finger::setAngleWithoutPressureCheck(int targetAngle)
{
    _servo.setAngle(targetAngle);
    _currentAngle = targetAngle;
}

/**
 * @brief Gradually set the angle of the servo while checking the pressure
 * @param targetAngle
 * @param direction
 */
void
Finger::graduallySetAngleWithPressureCheck(int targetAngle)
{
    for (int angle = _currentAngle; angle < targetAngle; angle++) {
        _servo.setAngle(angle);
        _currentAngle = angle;

        if (_sensor.getValue() >= _maxPressure)
            break;
    }
}
