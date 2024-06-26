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
void loop()
{
    Serial.println("---------------------------- DEMO STARTED ! ----------------------------");

    Serial.println("DEMO 1: close and reopen the hand");
    delay(5000);
    rightArm.hand.close();
    rightArm.hand.open();

    Serial.println("DEMO 2: greet");
    delay(5000);
    rightArm.greet();

    Serial.println("DEMO 3: count");
    delay(5000);
    rightArm.hand.count();

    Serial.println("DEMO 4: hold");
    delay(5000);
    rightArm.hand.hold();

    Serial.println("---------------------------- DEMO FINISHED ! ----------------------------");
    while(1);
}
