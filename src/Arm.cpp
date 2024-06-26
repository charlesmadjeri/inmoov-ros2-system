#include "../include/Arm.hpp"

Arm::Arm(SideType side): _side(side), wrist(side), hand(side) {}

void
Arm::setup()
{
    wrist.setup();
    hand.setup();
}
