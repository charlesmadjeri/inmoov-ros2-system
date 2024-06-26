#include <Arduino.h>
#include "../include/Arm.hpp"

// Declare right arm object
Arm rightArm(SideType::RIGHT);

/**
 * @brief Setup function
 */
void setup()
{
    // Call setup method from right arm object
    rightArm.setup();

    // Wait for servos setup
    delay(1250);
}

/**
 * @brief Loop function
 */
void loop(){
    int sensorReading = rightArm.hand.pinky.getPressure();
    Serial.print("\nAnalog reading = ");
    Serial.print(sensorReading);
    delay(1000);
}
