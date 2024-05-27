#include <Arduino.h>
#include "../include/Arm.hpp"

Arm rightArm(SideType::RIGHT);

void setup() {}

void loop() {
    for (int i = 0; i < 300; i++) {
        rightArm._wrist.setAngle(i);
        rightArm._hand._index.setAngle(i);
        rightArm._hand._middle.setAngle(i);
        rightArm._hand._ring.setAngle(i);
        rightArm._hand._pinky.setAngle(i);
        rightArm._hand._thumb.setAngle(i);
        delay(100);
    }
    for (int i = 300; i > 0; i--) {
        rightArm._wrist.setAngle(i);
        rightArm._hand._index.setAngle(i);
        rightArm._hand._middle.setAngle(i);
        rightArm._hand._ring.setAngle(i);
        rightArm._hand._pinky.setAngle(i);
        rightArm._hand._thumb.setAngle(i);
        delay(100);
    }
}
