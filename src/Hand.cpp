#include "include/Hand.hpp"
#include "include/Config.hpp"

Hand::Hand(SideType type):
    _type(type),
    thumb(
            type == SideType::LEFT ? LEFT_THUMB_SERVO_TYPE : RIGHT_THUMB_SERVO_TYPE,
            type == SideType::LEFT ? LEFT_THUMB_SERVO_PIN : RIGHT_THUMB_SERVO_PIN,
            type == SideType::LEFT ? LEFT_THUMB_SENSOR_PIN : RIGHT_THUMB_SENSOR_PIN
    ),
    index(
            type == SideType::LEFT ? LEFT_INDEX_SERVO_TYPE : RIGHT_INDEX_SERVO_TYPE,
            type == SideType::LEFT ? LEFT_INDEX_SERVO_PIN : RIGHT_INDEX_SERVO_PIN,
            type == SideType::LEFT ? LEFT_INDEX_SENSOR_PIN : RIGHT_INDEX_SENSOR_PIN
    ),
    middle(
            type == SideType::LEFT ? LEFT_MIDDLE_SERVO_TYPE : RIGHT_MIDDLE_SERVO_TYPE,
            type == SideType::LEFT ? LEFT_MIDDLE_SERVO_PIN : RIGHT_MIDDLE_SERVO_PIN,
            type == SideType::LEFT ? LEFT_MIDDLE_SENSOR_PIN : RIGHT_MIDDLE_SENSOR_PIN
    ),
    ring(
            type == SideType::LEFT ? LEFT_RING_SERVO_TYPE : RIGHT_RING_SERVO_TYPE,
            type == SideType::LEFT ? LEFT_RING_SERVO_PIN : RIGHT_RING_SERVO_PIN,
            type == SideType::LEFT ? LEFT_RING_SENSOR_PIN : RIGHT_RING_SENSOR_PIN
    ),
    pinky(
            type == SideType::LEFT ? LEFT_PINKY_SERVO_TYPE : RIGHT_PINKY_SERVO_TYPE,
            type == SideType::LEFT ? LEFT_PINKY_SERVO_PIN : RIGHT_PINKY_SERVO_PIN,
            type == SideType::LEFT ? LEFT_PINKY_SENSOR_PIN : RIGHT_PINKY_SENSOR_PIN
    )
{
    if (_type == SideType::RIGHT && RIGHT_THUMB_MAX_ANGLE) { // Use custom max angle for the thumb
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
