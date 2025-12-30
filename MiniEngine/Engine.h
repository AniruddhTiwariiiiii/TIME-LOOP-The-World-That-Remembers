#pragma once
#include "World.h"
#include "EventBus.h"

class Engine
{
public:
    Engine();
    void run();

private:
    bool running;
    World world;
    EventBus eventBus;
};
