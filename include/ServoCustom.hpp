#include <Servo.h>

namespace ServoNS {
    enum class ServoType {
        JX_6225MG,
        HK15298B
    };

    class ServoCustom {
    public:
        ServoCustom(ServoType type, int pin);

        void setAngle(int angle);
        int getAngle();

    private:
        Servo _servo;
        int _pin;
        ServoType _type;
        int _angle;
        int _defaultAngle;
        int _minAngle;
        int _maxAngle;
    };
}
