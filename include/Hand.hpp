#pragma once

#include "Finger.hpp"
#include "Types.hpp"

class Hand {
private:
    SideType _type;
public:
    explicit Hand(SideType type);

    void setup();

    Finger thumb;
    Finger index;
    Finger middle;
    Finger ring;
    Finger pinky;
};
