#pragma once
#include "System.h"

class World;
class EventBus;

class LifeSystem : public System
{
public:
    LifeSystem(World &world, EventBus &eventBus);

    void update(float deltaTime) override;

private:
    World &world;
    EventBus &eventBus;
    int framesAlive;
};
