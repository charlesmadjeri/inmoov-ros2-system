#pragma once

#include "Types.hpp"
#include "Wrist.hpp"
#include "Hand.hpp"

class Arm {
private:
    SideType _side;
public:
    explicit Arm(SideType side): _side(side), _wrist(side), _hand(side) {}

    Wrist _wrist;
    Hand _hand;
};
