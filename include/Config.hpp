#pragma once

#include "Types.hpp"

// ********** FINGER ANGLES **********

#define FINGER_DEFAULT_ANGLE 0
#define FINGER_MIN_ANGLE 0
#define FINGER_MAX_ANGLE 300


// ****************************** RIGHT FOREARM ******************************

// ******************** RIGHT WRIST ********************

#define RIGHT_WRIST_SERVO_PIN 14
#define RIGHT_WRIST_SERVO_TYPE ServoType::JX_6225MG
#define RIGHT_WRIST_DEFAULT_ANGLE 150 // TO DEFINE
#define RIGHT_WRIST_MIN_ANGLE 0 // TO DEFINE
#define RIGHT_WRIST_MAX_ANGLE 300 // TO DEFINE

// ******************** RIGHT HAND ********************

// ********** RIGHT FINGERS **********

// SERVOS
#define RIGHT_THUMB_SERVO_PIN 15
#define RIGHT_THUMB_SERVO_TYPE ServoType::JX_6225MG

#define RIGHT_INDEX_SERVO_PIN 16
#define RIGHT_INDEX_SERVO_TYPE ServoType::JX_6225MG

#define RIGHT_MIDDLE_SERVO_PIN 17
#define RIGHT_MIDDLE_SERVO_TYPE ServoType::JX_6225MG

#define RIGHT_RING_SERVO_PIN 18
#define RIGHT_RING_SERVO_TYPE ServoType::JX_6225MG

#define RIGHT_PINKY_SERVO_PIN 19
#define RIGHT_PINKY_SERVO_TYPE ServoType::JX_6225MG

// SENSOR
#define RIGHT_THUMB_SENSOR_PIN A6
#define RIGHT_INDEX_SENSOR_PIN A7
#define RIGHT_MIDDLE_SENSOR_PIN A8
#define RIGHT_RING_SENSOR_PIN A9
#define RIGHT_PINKY_SENSOR_PIN A10

// ****************************** LEFT FOREARM ******************************

// ******************** LEFT WRIST ********************

#define LEFT_WRIST_SERVO_PIN 53 // TO DEFINE
#define LEFT_WRIST_SERVO_TYPE ServoType::UNDEFINED // TO DEFINE
#define LEFT_WRIST_DEFAULT_ANGLE 150 // TO DEFINE
#define LEFT_WRIST_MIN_ANGLE 0 // TO DEFINE
#define LEFT_WRIST_MAX_ANGLE 300 // TO DEFINE

// ******************** LEFT HAND ********************

// ********** LEFT FINGERS **********

// SERVOS
#define LEFT_THUMB_SERVO_PIN 53
#define LEFT_THUMB_SERVO_TYPE ServoType::UNDEFINED

#define LEFT_INDEX_SERVO_PIN 53
#define LEFT_INDEX_SERVO_TYPE ServoType::UNDEFINED

#define LEFT_MIDDLE_SERVO_PIN 53
#define LEFT_MIDDLE_SERVO_TYPE ServoType::UNDEFINED

#define LEFT_RING_SERVO_PIN 53
#define LEFT_RING_SERVO_TYPE ServoType::UNDEFINED

#define LEFT_PINKY_SERVO_PIN 53
#define LEFT_PINKY_SERVO_TYPE ServoType::UNDEFINED

// SENSOR
#define LEFT_THUMB_SENSOR_PIN 53
#define LEFT_INDEX_SENSOR_PIN 53
#define LEFT_MIDDLE_SENSOR_PIN 53
#define LEFT_RING_SENSOR_PIN 53
#define LEFT_PINKY_SENSOR_PIN 53
