#include "ServoCustom.hpp"

namespace ServoNS
{
    ServoCustom::ServoCustom(ServoType type, int pin) : _pin(pin), _type(type)
    {
        switch (type) {
            case ServoType::JX_6225MG:
                this->_minAngle = 0;
                this->_maxAngle = 150;
                break;
            case ServoType::HK15298B:
                this->_minAngle = 0;
                this->_maxAngle = 300;
                break;
        }
        this->_servo = Servo();
        this->_servo.attach(_pin);
    }

    void ServoCustom::setAngle(int angle)
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

    int ServoCustom::getAngle()
    {
        this->_angle = this->_servo.read();
        return this->_angle;
    }
}
