#include "../include/HallSensor.hpp"

/**
 * @brief Constructor
 * @param pin
 */
HallSensor::HallSensor(int pin): _pin(pin)
{}

/**
 * @brief Setup function
 */
void
HallSensor::setup()
{
    Serial.begin(9600);
}

/**
 * @brief Get the value of the sensor
 * @return int
 */
int
HallSensor::getValue()
{
    return analogRead(_pin);
}
