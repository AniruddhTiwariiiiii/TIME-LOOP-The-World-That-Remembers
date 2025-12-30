#pragma once
#include "Event.h"

struct MoveEvent : public Event
{
    float dx;
    float dy;

    MoveEvent(float dx, float dy)
        : dx(dx), dy(dy) {}
};
