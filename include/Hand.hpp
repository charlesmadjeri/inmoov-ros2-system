#pragma once

#include "Finger.hpp"
#include "Types.hpp"

class Hand {
private:
    SideType _type;
public:
    explicit Hand(SideType type);

    Finger _thumb;
    Finger _index;
    Finger _middle;
    Finger _ring;
    Finger _pinky;
};
