#include <Arduino.h>
#include "include/Arm.hpp"

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
    // Move wrist and fingers servos counterclockwise
    for (int i = 0; i <= 300; i++) {
        rightArm.wrist.setAngle(i);
        rightArm.hand.thumb.setAngle(i);
        rightArm.hand.index.setAngle(i);
        rightArm.hand.middle.setAngle(i);
        rightArm.hand.ring.setAngle(i);
        rightArm.hand.pinky.setAngle(i);

        delay(10);
    }

    // Move wrist and fingers servos clockwise
    for (int i = 300; i >= 0; i--) {
        rightArm.wrist.setAngle(i);
        rightArm.hand.thumb.setAngle(i);
        rightArm.hand.index.setAngle(i);
        rightArm.hand.middle.setAngle(i);
        rightArm.hand.ring.setAngle(i);
        rightArm.hand.pinky.setAngle(i);

        delay(10);
    }

    // Set wrist and fingers servos to default angle
    rightArm.wrist.setAngle(RIGHT_WRIST_DEFAULT_ANGLE);
    rightArm.hand.thumb.setAngle(FINGER_DEFAULT_ANGLE);
    rightArm.hand.index.setAngle(FINGER_DEFAULT_ANGLE);
    rightArm.hand.middle.setAngle(FINGER_DEFAULT_ANGLE);
    rightArm.hand.ring.setAngle(FINGER_DEFAULT_ANGLE);
    rightArm.hand.pinky.setAngle(FINGER_DEFAULT_ANGLE);

    // Endless loop to not repeat the sequence
    while(true);
}
