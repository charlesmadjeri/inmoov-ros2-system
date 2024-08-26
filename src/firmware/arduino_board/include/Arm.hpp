#pragma once

#include "Types.hpp"
#include "Wrist.hpp"
#include "Hand.hpp"

class Arm {
private:
    SideType _side;
public:
    explicit Arm(SideType side);
    void setup();

    void greet();

    Wrist wrist;
    Hand hand;
};
