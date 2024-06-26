#include "../include/Hand.hpp"

/**
 * @brief Constructor
 * @param type
 * @details Initialize the hand with the type of side
 */
Hand::Hand(SideType type):
    _type(type)
{
    ServoValues leftThumbAngleValues = { LEFT_THUMB_MIN_ANGLE, LEFT_THUMB_MAX_ANGLE };
    ServoValues rightThumbAngleValues = { RIGHT_THUMB_MIN_ANGLE, RIGHT_THUMB_MAX_ANGLE };
    ServoValues leftIndexAngleValues = { LEFT_INDEX_MIN_ANGLE, LEFT_INDEX_MAX_ANGLE };
    ServoValues rightIndexAngleValues = { RIGHT_INDEX_MIN_ANGLE, RIGHT_INDEX_MAX_ANGLE };
    ServoValues leftMiddleAngleValues = { LEFT_MIDDLE_MIN_ANGLE, LEFT_MIDDLE_MAX_ANGLE };
    ServoValues rightMiddleAngleValues = { RIGHT_MIDDLE_MIN_ANGLE, RIGHT_MIDDLE_MAX_ANGLE };
    ServoValues leftRingAngleValues = { LEFT_RING_MIN_ANGLE, LEFT_RING_MAX_ANGLE };
    ServoValues rightRingAngleValues = { RIGHT_RING_MIN_ANGLE, RIGHT_RING_MAX_ANGLE };
    ServoValues leftPinkyAngleValues = { LEFT_PINKY_MIN_ANGLE, LEFT_PINKY_MAX_ANGLE };
    ServoValues rightPinkyAngleValues = { RIGHT_PINKY_MIN_ANGLE, RIGHT_PINKY_MAX_ANGLE };

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
            type == SideType::LEFT ? LEFT_THUMB_GOT_SENSOR : RIGHT_THUMB_GOT_SENSOR,
            type == SideType::LEFT ? LEFT_THUMB_SERVO_TYPE : RIGHT_THUMB_SERVO_TYPE,
            type == SideType::LEFT ? LEFT_THUMB_SERVO_PIN : RIGHT_THUMB_SERVO_PIN,
            type == SideType::LEFT ? LEFT_THUMB_SENSOR_PIN : RIGHT_THUMB_SENSOR_PIN,
            type == SideType::LEFT ? leftThumbAngleValues : rightThumbAngleValues,
            type == SideType::LEFT ? leftThumbPressureValues : rightThumbPressureValues
    );
    index  = Finger(
            FingerType::INDEX,
            type == SideType::LEFT ? LEFT_INDEX_GOT_SENSOR : RIGHT_INDEX_GOT_SENSOR,
            type == SideType::LEFT ? LEFT_INDEX_SERVO_TYPE : RIGHT_INDEX_SERVO_TYPE,
            type == SideType::LEFT ? LEFT_INDEX_SERVO_PIN : RIGHT_INDEX_SERVO_PIN,
            type == SideType::LEFT ? LEFT_INDEX_SENSOR_PIN : RIGHT_INDEX_SENSOR_PIN,
            type == SideType::LEFT ? leftIndexAngleValues : rightIndexAngleValues,
            type == SideType::LEFT ? leftIndexPressureValues : rightIndexPressureValues
    );
    middle = Finger(
            FingerType::MIDDLE,
            type == SideType::LEFT ? LEFT_MIDDLE_GOT_SENSOR : RIGHT_MIDDLE_GOT_SENSOR,
            type == SideType::LEFT ? LEFT_MIDDLE_SERVO_TYPE : RIGHT_MIDDLE_SERVO_TYPE,
            type == SideType::LEFT ? LEFT_MIDDLE_SERVO_PIN : RIGHT_MIDDLE_SERVO_PIN,
            type == SideType::LEFT ? LEFT_MIDDLE_SENSOR_PIN : RIGHT_MIDDLE_SENSOR_PIN,
            type == SideType::LEFT ? leftMiddleAngleValues : rightMiddleAngleValues,
            type == SideType::LEFT ? leftMiddlePressureValues : rightMiddlePressureValues
    );
    ring   = Finger(
            FingerType::RING,
            type == SideType::LEFT ? LEFT_RING_GOT_SENSOR : RIGHT_RING_GOT_SENSOR,
            type == SideType::LEFT ? LEFT_RING_SERVO_TYPE : RIGHT_RING_SERVO_TYPE,
            type == SideType::LEFT ? LEFT_RING_SERVO_PIN : RIGHT_RING_SERVO_PIN,
            type == SideType::LEFT ? LEFT_RING_SENSOR_PIN : RIGHT_RING_SENSOR_PIN,
            type == SideType::LEFT ? leftRingAngleValues : rightRingAngleValues,
            type == SideType::LEFT ? leftRingPressureValues : rightRingPressureValues
    );
    pinky  = Finger(
            FingerType::PINKY,
            type == SideType::LEFT ? LEFT_PINKY_GOT_SENSOR : RIGHT_PINKY_GOT_SENSOR,
            type == SideType::LEFT ? LEFT_PINKY_SERVO_TYPE : RIGHT_PINKY_SERVO_TYPE,
            type == SideType::LEFT ? LEFT_PINKY_SERVO_PIN : RIGHT_PINKY_SERVO_PIN,
            type == SideType::LEFT ? LEFT_PINKY_SENSOR_PIN : RIGHT_PINKY_SENSOR_PIN,
            type == SideType::LEFT ? leftPinkyAngleValues : rightPinkyAngleValues,
            type == SideType::LEFT ? leftPinkyPressureValues : rightPinkyPressureValues
    );
}

/**
 * @brief Setup
 * @details Setup each finger of the hand
 */
void
Hand::setup()
{
    thumb.setup();
    index.setup();
    middle.setup();
    ring.setup();
    pinky.setup();
}

/**
 * @brief Close the hand
 * @details Close each finger of the hand
 */
void
Hand::close()
{
    thumb.setPosition(100);
    index.setPosition(100);
    middle.setPosition(100);
    ring.setPosition(100);
    pinky.setPosition(100);

    delay(SERVO_DELAY_PER_DEGREE * 175);
}

/**
 * @brief Open the hand
 * @details Open each finger of the hand
 */
void
Hand::open()
{
    thumb.setPosition(0);
    index.setPosition(0);
    middle.setPosition(0);
    ring.setPosition(0);
    pinky.setPosition(0);

    delay(SERVO_DELAY_PER_DEGREE * 175);
}

/**
 * @brief Count
 * @details Count with the fingers
 */
void Hand::count()
{
    index.setPosition(100);
    middle.setPosition(100);
    ring.setPosition(100);
    pinky.setPosition(100);
    delay(SERVO_DELAY_PER_DEGREE * 175);
    thumb.setPosition(100);
    delay(SERVO_DELAY_PER_DEGREE * 175);

    thumb.setPosition(0);
    delay(SERVO_DELAY_PER_DEGREE * 175);
    index.setPosition(0);
    delay(SERVO_DELAY_PER_DEGREE * 175);
    middle.setPosition(0);
    delay(SERVO_DELAY_PER_DEGREE * 175);
    ring.setPosition(0);
    delay(SERVO_DELAY_PER_DEGREE * 175);
    pinky.setPosition(0);
    delay(SERVO_DELAY_PER_DEGREE * 175);
    open();
}

/**
 * @brief Hold
 * @details Hold something 3 seconds then release
 */
void Hand::hold()
{
    close();
    delay(SERVO_DELAY_PER_DEGREE * 175);
    delay(3000);
    open();
}
