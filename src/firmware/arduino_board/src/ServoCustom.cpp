#include "../include/ServoCustom.hpp"

ServoCustom::ServoCustom(ServoType type, int pin, int defaultAngle):
    _servo(Servo()),
    _type(type),
    _pin(pin),
    _defaultAngle(defaultAngle),
    _angle(defaultAngle)
{
    switch (type) {
        case ServoType::JX_6225MG:
            this->_minAngle = 0;
            this->_maxAngle = 300;
            break;
        case ServoType::HK15298B:
            this->_minAngle = 0;
            this->_maxAngle = 180;
            break;
        default:
            this->_minAngle = 0;
            this->_maxAngle = 0;
            break;
    }
}

void
ServoCustom::setup()
{
    this->_servo.attach(this->_pin);
    this->_servo.write(this->_defaultAngle);
}

void
ServoCustom::setAngle(int angle)
{
    if (angle < this->_minAngle) {
        this->_angle = this->_minAngle;
    } else if (angle > this->_maxAngle) {
        this->_angle = this->_maxAngle;
    } else {
        this->_angle = angle;
    }
    this->_servo.write(this->_angle);
}

int
ServoCustom::getAngle()
{
    // TODO: check if read can go to 300 degrees angle or if limited to 180
    this->_angle = this->_servo.read();
    return this->_angle;
}

