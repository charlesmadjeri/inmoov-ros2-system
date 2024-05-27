#include "../include/HallSensor.hpp"

HallSensor::HallSensor(int pin): _pin(pin)
{
    Serial.begin(9600);
}

float
HallSensor::getVoltage()
{
    int sensorValue = analogRead(_pin);
    return sensorValue * (5.0 / 1023.0);
}

int
HallSensor::getValue()
{
    return analogRead(_pin);
}
