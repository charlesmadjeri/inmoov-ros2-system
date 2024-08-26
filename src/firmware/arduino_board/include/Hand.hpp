#pragma once

#include "Finger.hpp"
#include "Types.hpp"

class Hand {
private:
    SideType _type;
public:
    explicit Hand(SideType type);
    void setup();

    void close();
    void open();
    void count();
    void hold();

    Finger thumb;
    Finger index;
    Finger middle;
    Finger ring;
    Finger pinky;
};
