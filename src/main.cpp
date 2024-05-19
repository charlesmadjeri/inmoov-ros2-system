#include <Arduino.h>
#include <Servo.h>

Servo front, tilt, pan;

void setup() {
    front.attach(14);
    front.write(90);

    tilt.attach(15);
    tilt.write(90);

    pan.attach(16);
    pan.write(90);
}

void loop() {
    for (int pos = 0; pos <= 180; pos++) { // goes from 0 degrees to 180 degrees
        front.write(pos);
        pan.write(pos);
        tilt.write(pos);
        delay(15); // waits 15ms for the servo to reach the position
    }
    for (int pos = 180; pos >= 0; pos--) { // goes from 180 degrees to 0 degrees
        front.write(pos);
        pan.write(pos);
        tilt.write(pos);
        delay(15); // waits 15ms for the servo to reach the position
    }
    front.write(90);
    pan.write(90);
    tilt.write(90);
    while (1);
}
