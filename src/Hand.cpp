#include "../include/Hand.hpp"

Hand::Hand(SideType type):
    _type(type)
{
    PressureValues leftThumbPressureValues = { LEFT_THUMB_SENSOR_MIN, LEFT_THUMB_SENSOR_MAX };
    PressureValues rightThumbPressureValues = { RIGHT_THUMB_SENSOR_MIN, RIGHT_THUMB_SENSOR_MAX };
    PressureValues leftIndexPressureValues = { LEFT_INDEX_SENSOR_MIN, LEFT_INDEX_SENSOR_MAX };
    PressureValues rightIndexPressureValues = { RIGHT_INDEX_SENSOR_MIN, RIGHT_INDEX_SENSOR_MAX };
    PressureValues leftMiddlePressureValues = { LEFT_MIDDLE_SENSOR_MIN, LEFT_MIDDLE_SENSOR_MAX };
    PressureValues rightMiddlePressureValues = { RIGHT_MIDDLE_SENSOR_MIN, RIGHT_MIDDLE_SENSOR_MAX };
    PressureValues leftRingPressureValues = { LEFT_RING_SENSOR_MIN, LEFT_RING_SENSOR_MAX };
    PressureValues rightRingPressureValues = { RIGHT_RING_SENSOR_MIN, RIGHT_RING_SENSOR_MAX };
    PressureValues leftPinkyPressureValues = { LEFT_PINKY_SENSOR_MIN, LEFT_PINKY_SENSOR_MAX };
    PressureValues rightPinkyPressureValues = { RIGHT_PINKY_SENSOR_MIN, RIGHT_PINKY_SENSOR_MAX };

    thumb = Finger(
            FingerType::THUMB,
            type == SideType::LEFT ? LEFT_THUMB_SERVO_TYPE : RIGHT_THUMB_SERVO_TYPE,
            type == SideType::LEFT ? LEFT_THUMB_SERVO_PIN : RIGHT_THUMB_SERVO_PIN,
            type == SideType::LEFT ? LEFT_THUMB_SENSOR_PIN : RIGHT_THUMB_SENSOR_PIN,
            type == SideType::LEFT ? leftThumbPressureValues : rightThumbPressureValues
    );
    index  = Finger(
            FingerType::INDEX,
            type == SideType::LEFT ? LEFT_INDEX_SERVO_TYPE : RIGHT_INDEX_SERVO_TYPE,
            type == SideType::LEFT ? LEFT_INDEX_SERVO_PIN : RIGHT_INDEX_SERVO_PIN,
            type == SideType::LEFT ? LEFT_INDEX_SENSOR_PIN : RIGHT_INDEX_SENSOR_PIN,
            type == SideType::LEFT ? leftIndexPressureValues : rightIndexPressureValues
    );
    middle = Finger(
            FingerType::MIDDLE,
            type == SideType::LEFT ? LEFT_MIDDLE_SERVO_TYPE : RIGHT_MIDDLE_SERVO_TYPE,
            type == SideType::LEFT ? LEFT_MIDDLE_SERVO_PIN : RIGHT_MIDDLE_SERVO_PIN,
            type == SideType::LEFT ? LEFT_MIDDLE_SENSOR_PIN : RIGHT_MIDDLE_SENSOR_PIN,
            type == SideType::LEFT ? leftMiddlePressureValues : rightMiddlePressureValues
    );
    ring   = Finger(
            FingerType::RING,
            type == SideType::LEFT ? LEFT_RING_SERVO_TYPE : RIGHT_RING_SERVO_TYPE,
            type == SideType::LEFT ? LEFT_RING_SERVO_PIN : RIGHT_RING_SERVO_PIN,
            type == SideType::LEFT ? LEFT_RING_SENSOR_PIN : RIGHT_RING_SENSOR_PIN,
            type == SideType::LEFT ? leftRingPressureValues : rightRingPressureValues
    );
    pinky  = Finger(
            FingerType::PINKY,
            type == SideType::LEFT ? LEFT_PINKY_SERVO_TYPE : RIGHT_PINKY_SERVO_TYPE,
            type == SideType::LEFT ? LEFT_PINKY_SERVO_PIN : RIGHT_PINKY_SERVO_PIN,
            type == SideType::LEFT ? LEFT_PINKY_SENSOR_PIN : RIGHT_PINKY_SENSOR_PIN,
            type == SideType::LEFT ? leftPinkyPressureValues : rightPinkyPressureValues
    );

    // Use custom max angle for the thumb
    if (_type == SideType::RIGHT && RIGHT_THUMB_MAX_ANGLE) {
        thumb.setMaxAngle(RIGHT_THUMB_MAX_ANGLE);
    }
}

void
Hand::setup()
{
    thumb.setup();
    index.setup();
    middle.setup();
    ring.setup();
    pinky.setup();
}
