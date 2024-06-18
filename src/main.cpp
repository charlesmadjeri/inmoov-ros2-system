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
//    rightArm.wrist.setAngle(RIGHT_WRIST_MAX_ANGLE);
    delay(1250);

    for (int z = 0; z < 3; z++) {
        // Move fingers servos counterclockwise
        for (int i = 0; i <= 135; i++) {
            rightArm.hand.thumb.setAngle(i);
//            rightArm.hand.index.setAngle(i);
//            rightArm.hand.middle.setAngle(i);
//            rightArm.hand.ring.setAngle(i);
//            rightArm.hand.pinky.setAngle(i);
            delay(25);
        }
        // Move fingers servos clockwise
        for (int i = 135; i >= 0; i--) {
            rightArm.hand.thumb.setAngle(i);
//            rightArm.hand.index.setAngle(i);
//            rightArm.hand.middle.setAngle(i);
//            rightArm.hand.ring.setAngle(i);
//            rightArm.hand.pinky.setAngle(i);
            delay(25);
        }
    }

    // Set wrist and fingers servos to default angle
    rightArm.wrist.setAngle(RIGHT_WRIST_MIN_ANGLE);
    rightArm.hand.thumb.setAngle(FINGER_DEFAULT_ANGLE);
    rightArm.hand.index.setAngle(FINGER_DEFAULT_ANGLE);
    rightArm.hand.middle.setAngle(FINGER_DEFAULT_ANGLE);
    rightArm.hand.ring.setAngle(FINGER_DEFAULT_ANGLE);
    rightArm.hand.pinky.setAngle(FINGER_DEFAULT_ANGLE);

    delay(1250);
    // Endless loop to not repeat the sequence
    while(true);
}
